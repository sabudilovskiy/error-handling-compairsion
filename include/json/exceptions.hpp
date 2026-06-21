#pragma once

#include <map>
#include <optional>
#include <print>
#include <set>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <boost/json.hpp>
#include <magic_enum/magic_enum.hpp>

#include "common/box.hpp"
#include "common/duration_utils.hpp"
#include "common/error.hpp"
#include "common/formatters.hpp"
#include "common/pfr_extension.hpp"
#include "common/traits.hpp"
#include "common/visit_index.hpp"
#include "path.hpp"

namespace json::exceptions
{

// ---------------------------------------------------------------------------
// Aliases for boost::json types used throughout
// ---------------------------------------------------------------------------

using value = boost::json::value;
using cref = const boost::json::value&;
using ref = boost::json::value&;

// ---------------------------------------------------------------------------
// Exceptions
// ---------------------------------------------------------------------------

struct parse_error : common::error
{
    path_t::value_type path_elems_;

    template <typename... Args>
    parse_error(std::format_string<Args...> fmt_str, Args&&... args)
        : common::error(fmt_str, std::forward<Args>(args)...)
    {
        auto try_extract_path = common::matcher {
            [&](auto&) {},
            [&](const path_t& p) {
                path_elems_ = *p.elems_;
            }
        };

        (try_extract_path(args), ...);
    }

    const path_t::value_type& path() const
    {
        return path_elems_;
    }

    std::string path_str() const
    {
        return path_to_str(path_elems_);
    }
};

struct type_error : parse_error
{
    using parse_error::parse_error;
};

struct validate_error : parse_error
{
    using parse_error::parse_error;
};

struct missing_field_error : parse_error
{
    using parse_error::parse_error;
};

struct duplicate_error : parse_error
{
    using parse_error::parse_error;
};

// In the exceptions strategy, result<T> is just T — errors are thrown.
template <typename T>
using result = T;

// ---------------------------------------------------------------------------
// Primary template — undefined; specialize per type
// ---------------------------------------------------------------------------

/*
Customization point for JSON deserialization of type T.

Specialize this struct to define how T should be parsed from a boost::json::value.
The static `read()` method returns `result<T>` (i.e. T), throwing one of the
exceptions above on failure.

Optional field handling:
Define `using is_optional = void;` in your specialization to mark T as optional
when used as an aggregate field.  If the JSON field is absent, the field is left
default-initialized rather than throwing missing_field_error.

Example:
    template <>
    struct reader<std::optional<int>> {
        using is_optional = void;

        static result<std::optional<int>> read(cref json, const path_t& p) {
            // ...
        }
    };
*/
template <typename T>
struct reader
{ /* specialize me */
};

// ---------------------------------------------------------------------------
// Concepts
// ---------------------------------------------------------------------------

template <typename T>
concept has_reader = requires(cref json, const path_t& p) {
    { reader<T>::read(json, p) } -> std::same_as<result<T>>;
};

template <typename T>
concept has_non_static_reader = requires(reader<T> r, cref json, const path_t& p) {
    { r.read(json, p) } -> std::same_as<result<T>>;
};

template <typename T>
concept has_reader_const_qualifier_loss = requires(reader<T> r, ref json, path_t& p) {
    { r.read(json, p) } -> std::same_as<result<T>>;
};

template <typename T>
concept optional_reader = requires {
    typename reader<T>::is_optional;
};

// ---------------------------------------------------------------------------
// Central dispatch
// ---------------------------------------------------------------------------

template <typename T>
result<T> read_from(cref v, const path_t& p)
{
    if constexpr (has_reader<T>) {
        return reader<T>::read(v, p);
    } else if constexpr (has_non_static_reader<T>) {
        static_assert(has_reader<T>, "reader<T>::read must be declared as static.");
    } else if constexpr (has_reader_const_qualifier_loss<T>) {
        static_assert(has_reader<T>, "reader<T>::read must preserve const qualifiers.");
    } else {
        return reader<T>::read(v, p);
    }
}

// ---------------------------------------------------------------------------
// Entry point
// ---------------------------------------------------------------------------

template <typename T>
result<T> as(cref v)
{
    path_t::value_type root;
    return read_from<T>(v, path_t { root });
}

template <typename T>
result<T> as(std::string_view json_str)
{
    path_t::value_type root;
    value v = boost::json::parse(
        json_str,
        boost::json::storage_ptr {},
        boost::json::parse_options {
            .max_depth = 60,
        } //
    );
    return read_from<T>(v, path_t { root });
}

// ---------------------------------------------------------------------------
// Specializations
// ---------------------------------------------------------------------------

template <>
struct reader<boost::json::value>
{
    static result<boost::json::value> read(cref json, const path_t& p)
    {
        return json;
    }
};

template <>
struct reader<std::string>
{
    static result<std::string> read(cref json, const path_t& p)
    {
        if (!json.is_string()) {
            throw type_error("expected string at {}", p);
        }
        return std::string(json.get_string());
    }
};

template <std::integral T>
struct reader<T>
{
    static result<T> read(cref json, const path_t& p)
    {
        if (json.is_int64()) {
            const std::int64_t from = json.get_int64();
            if (!std::in_range<T>(from)) {
                throw validate_error("integer out of range at {}", p);
            }
            return static_cast<T>(from);
        } else if (json.is_uint64()) {
            const std::uint64_t from = json.get_uint64();
            if (!std::in_range<T>(from)) {
                throw validate_error("integer out of range at {}", p);
            }
            return static_cast<T>(from);
        } else {
            throw type_error("expected {} at {}",
                std::unsigned_integral<T> ? "uint64" : "int64",
                p);
        }
    }
};

template <>
struct reader<double>
{
    static result<double> read(cref json, const path_t& p)
    {
        if (!json.is_double()) {
            throw type_error("expected floating-point at {}", p);
        }
        return json.get_double();
    }
};

template <>
struct reader<bool>
{
    static result<bool> read(cref json, const path_t& p)
    {
        if (!json.is_bool()) {
            throw type_error("expected boolean at {}", p);
        }
        return json.get_bool();
    }
};

template <typename T>
struct reader<std::optional<T>>
{
    using is_optional = void;

    static result<std::optional<T>> read(cref json, const path_t& p)
    {
        if (json.is_null()) {
            return std::nullopt;
        }
        return read_from<T>(json, p);
    }
};

template <typename T>
struct reader<common::box<T>>
{
    using is_optional = void;

    static result<common::box<T>> read(cref json, const path_t& p)
    {
        if (json.is_null()) {
            return {};
        }
        return read_from<T>(json, p);
    }
};

template <typename T>
struct reader<std::vector<T>>
{
    static result<std::vector<T>> read(cref json, const path_t& p)
    {
        if (!json.is_array()) {
            throw type_error("expected array at {}", p);
        }
        const auto& arr = json.get_array();
        std::vector<T> out;
        out.reserve(arr.size());
        for (std::size_t i = 0; i < arr.size(); ++i) {
            out.emplace_back(read_from<T>(arr[i], p[i]));
        }
        return out;
    }
};

template <common::tuple_like T>
struct reader<T>
{
    static constexpr std::size_t Size = std::tuple_size_v<T>;

    static result<T> read(cref json, const path_t& p)
    {
        if (!json.is_array()) {
            throw type_error("expected array at {}", p);
        }
        const auto& arr = json.get_array();
        if (arr.size() != Size) {
            throw validate_error("expected array of size {}, got {} at {}",
                Size, arr.size(), p);
        }
        T out;
        common::for_each_index<Size>([&]<std::size_t I>() {
            std::get<I>(out) = read_from<std::tuple_element_t<I, T>>(arr[I], p[I]);
        });
        return out;
    }
};

template <typename T>
struct reader<std::set<T>>
{
    static result<std::set<T>> read(cref json, const path_t& p)
    {
        if (!json.is_array()) {
            throw type_error("expected array at {}", p);
        }
        const auto& arr = json.get_array();
        std::set<T> out;
        for (std::size_t i = 0; i < arr.size(); ++i) {
            if (!out.emplace(read_from<T>(arr[i], p[i])).second) {
                throw duplicate_error("duplicate element at {}", p[i].to_string());
            }
        }
        return out;
    }
};

template <typename T>
struct reader<std::unordered_set<T>>
{
    static result<std::unordered_set<T>> read(cref json, const path_t& p)
    {
        if (!json.is_array()) {
            throw type_error("expected array at {}", p);
        }
        const auto& arr = json.get_array();
        std::unordered_set<T> out;
        for (std::size_t i = 0; i < arr.size(); ++i) {
            if (!out.emplace(read_from<T>(arr[i], p[i])).second) {
                throw duplicate_error("duplicate element at {}", p[i].to_string());
            }
        }
        return out;
    }
};

template <typename T>
struct reader<std::map<std::string, T>>
{
    static result<std::map<std::string, T>> read(cref json, const path_t& p)
    {
        if (!json.is_object()) {
            throw type_error("expected object at {}", p);
        }
        std::map<std::string, T> out;
        for (const auto& kv : json.get_object()) {
            const std::string_view key = kv.key();
            out[std::string(key)] = read_from<T>(kv.value(), p[key]);
        }
        return out;
    }
};

template <typename T>
struct reader<std::unordered_map<std::string, T>>
{
    static result<std::unordered_map<std::string, T>> read(cref json, const path_t& p)
    {
        if (!json.is_object()) {
            throw type_error("expected object at {}", p);
        }
        std::unordered_map<std::string, T> out;
        for (const auto& kv : json.get_object()) {
            const std::string_view key = kv.key();
            out[std::string(key)] = read_from<T>(kv.value(), p[key]);
        }
        return out;
    }
};

// Aggregate structs via common::visit_object (wraps boost::pfr)
template <common::aggregate T>
struct reader<T>
{
    static result<T> read(cref json, const path_t& p)
    {
        if (!json.is_object()) {
            throw type_error("expected object at {}", p);
        }
        const auto& obj = json.get_object();

        T out;
        common::visit_object(out, [&]<typename Info>(auto& field_out) {
            using F = std::remove_reference_t<decltype(field_out)>;
            constexpr std::string_view name = Info::name.as_string_view();

            const boost::json::value* found = obj.if_contains(name);
            if (found && !found->is_null()) {
                field_out = read_from<F>(*found, p[name]);
            } else if (optional_reader<F>) {
                // leave field_out default-initialized — is_optional suppresses the error
            } else if (found) {
                // key present but explicitly null and field is not optional
                field_out = read_from<F>(*found, p[name]);
            } else {
                throw missing_field_error("missing field '{}' at {}", name, p);
            }
        });

        return out;
    }
};

template <typename T>
    requires common::has_duration_postfix<T>
struct reader<T>
{
    static result<T> read(cref json, const path_t& p)
    {
        if (!json.is_string()) {
            throw type_error("expected string (duration) at {}", p);
        }
        const std::string_view str = json.get_string();
        std::optional parsed = common::parse_duration<T>(str);
        if (!parsed) {
            throw validate_error("invalid duration format at {}. Value: `{}`", p, json);
        }
        return *parsed;
    }
};

template <typename E>
    requires magic_enum::is_scoped_enum_v<E>
struct reader<E>
{
    static result<E> read(cref json, const path_t& p)
    {
        if (!json.is_string()) {
            throw type_error("expected string (duration) at {}", p);
        }
        const std::string_view str = json.get_string();
        std::optional parsed = magic_enum::enum_cast<E>(str);
        if (!parsed) {
            throw validate_error("invalid duration format at {}", p);
        }
        return *parsed;
    }
};

} // namespace json::exceptions