#pragma once

#include <expected>
#include <format>
#include <map>
#include <optional>
#include <set>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <boost/json.hpp>

#include "common/box.hpp"
#include "common/duration_utils.hpp"
#include "common/pfr_extension.hpp"
#include "common/traits.hpp"
#include "common/visit_index.hpp"
#include "path.hpp"

namespace json::expected
{

// ---------------------------------------------------------------------------
// Aliases for boost::json types used throughout
// ---------------------------------------------------------------------------

using value = boost::json::value;
using cref = const boost::json::value&;
using ref = boost::json::value&;

// ---------------------------------------------------------------------------
// Error type
// ---------------------------------------------------------------------------

enum class error_kind : std::uint8_t
{
    type_error,
    validate_error,
    missing_field_error,
    duplicate_error,
};

struct parse_error
{
    error_kind kind;
    std::string message;

    template <typename... Args>
    static parse_error make(error_kind k, std::format_string<Args...> fmt, Args&&... args)
    {
        return { k, std::format(fmt, std::forward<Args>(args)...) };
    }
};

// Convenience factories — mirror the exception names from json::exceptions

template <typename... Args>
parse_error type_error(std::format_string<Args...> fmt, Args&&... args)
{
    return parse_error::make(error_kind::type_error, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
parse_error validate_error(std::format_string<Args...> fmt, Args&&... args)
{
    return parse_error::make(error_kind::validate_error, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
parse_error missing_field_error(std::format_string<Args...> fmt, Args&&... args)
{
    return parse_error::make(error_kind::missing_field_error, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
parse_error duplicate_error(std::format_string<Args...> fmt, Args&&... args)
{
    return parse_error::make(error_kind::duplicate_error, fmt, std::forward<Args>(args)...);
}

// ---------------------------------------------------------------------------
// Result alias
// ---------------------------------------------------------------------------

template <typename T>
using result = std::expected<T, parse_error>;

// ---------------------------------------------------------------------------
// TRY — for result<T>: unwraps the value or propagates the error.
//
// Usage:  auto val = TRY(read_from<U>(...));
// ---------------------------------------------------------------------------

#define TRY(expr)                               \
    ({                                          \
        auto _r = (expr);                       \
        if (!_r) [[unlikely]]                   \
            return std::unexpected(_r.error()); \
        std::move(*_r);                         \
    })

// ---------------------------------------------------------------------------
// Primary template — undefined; specialize per type
// ---------------------------------------------------------------------------

/*
Customization point for JSON deserialization of type T.

Specialize this struct to define how T should be parsed from a boost::json::value.
The static `read()` method returns `result<T>` (std::expected<T, parse_error>);
on success the value is returned, on failure an unexpected parse_error is returned.

Optional field handling:
Define `using is_optional = void;` in your specialization to mark T as optional
when used as an aggregate field.  If the JSON field is absent, the field is left
default-initialized rather than returning missing_field_error.

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
result<T> as(ref v)
{
    return as<T>(static_cast<cref>(v));
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
            return std::unexpected(type_error("expected string at {}", p.to_string()));
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
                return std::unexpected(validate_error("integer out of range at {}", p.to_string()));
            }
            return static_cast<T>(from);
        } else if (json.is_uint64()) {
            const std::uint64_t from = json.get_uint64();
            if (!std::in_range<T>(from)) {
                return std::unexpected(validate_error("integer out of range at {}", p.to_string()));
            }
            return static_cast<T>(from);
        } else {
            return std::unexpected(type_error("expected {} at {}",
                std::unsigned_integral<T> ? "uint64" : "int64",
                p.to_string()));
        }
    }
};

template <>
struct reader<double>
{
    static result<double> read(cref json, const path_t& p)
    {
        if (!json.is_double()) {
            return std::unexpected(type_error("expected floating-point at {}", p.to_string()));
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
            return std::unexpected(type_error("expected boolean at {}", p.to_string()));
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
            return nullptr;
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
            return std::unexpected(type_error("expected array at {}", p.to_string()));
        }
        const auto& arr = json.get_array();
        std::vector<T> out;
        out.reserve(arr.size());
        for (std::size_t i = 0; i < arr.size(); ++i) {
            out.emplace_back(TRY(read_from<T>(arr[i], p[i])));
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
            return std::unexpected(type_error("expected array at {}", p.to_string()));
        }
        const auto& arr = json.get_array();
        if (arr.size() != Size) {
            return std::unexpected(validate_error("expected array of size {}, got {} at {}",
                Size, arr.size(), p.to_string()));
        }

        // for_each_index drives the loop — collect first error via optional.
        T out;
        std::optional<parse_error> err;
        common::for_each_index<Size>([&]<std::size_t I>() {
            if (err) {
                return;
            }
            auto r = read_from<std::tuple_element_t<I, T>>(arr[I], p[I]);
            if (!r) {
                err = std::move(r.error());
                return;
            }
            std::get<I>(out) = std::move(*r);
        });
        if (err) {
            return std::unexpected(std::move(*err));
        }
        return out;
    }
};

template <typename T>
struct reader<std::set<T>>
{
    static result<std::set<T>> read(cref json, const path_t& p)
    {
        if (!json.is_array()) {
            return std::unexpected(type_error("expected array at {}", p.to_string()));
        }
        const auto& arr = json.get_array();
        std::set<T> out;
        for (std::size_t i = 0; i < arr.size(); ++i) {
            if (!out.emplace(TRY(read_from<T>(arr[i], p[i]))).second) {
                return std::unexpected(duplicate_error("duplicate element at {}", p[i].to_string()));
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
            return std::unexpected(type_error("expected array at {}", p.to_string()));
        }
        const auto& arr = json.get_array();
        std::unordered_set<T> out;
        for (std::size_t i = 0; i < arr.size(); ++i) {
            if (!out.emplace(TRY(read_from<T>(arr[i], p[i]))).second) {
                return std::unexpected(duplicate_error("duplicate element at {}", p[i].to_string()));
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
            return std::unexpected(type_error("expected object at {}", p.to_string()));
        }
        std::map<std::string, T> out;
        for (const auto& kv : json.get_object()) {
            const std::string_view key = kv.key();
            out[std::string(key)] = TRY(read_from<T>(kv.value(), p[key]));
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
            return std::unexpected(type_error("expected object at {}", p.to_string()));
        }
        std::unordered_map<std::string, T> out;
        for (const auto& kv : json.get_object()) {
            const std::string_view key = kv.key();
            out[std::string(key)] = TRY(read_from<T>(kv.value(), p[key]));
        }
        return out;
    }
};

// Aggregate structs via common::visit_object (wraps boost::pfr)
//
// visit_object drives the loop internally, so we can't return early from it.
// First error is collected into std::optional<parse_error>; subsequent fields
// are skipped via the early `if (err) return` guard.
template <common::aggregate T>
struct reader<T>
{
    static result<T> read(cref json, const path_t& p)
    {
        if (!json.is_object()) {
            return std::unexpected(type_error("expected object at {}", p.to_string()));
        }
        const auto& obj = json.get_object();

        T out;
        std::optional<parse_error> err;
        common::visit_object(out, [&]<typename Info, typename F>(F& field_out) {
            if (err) {
                return;
            }
            constexpr std::string_view name = Info::name.as_string_view();

            const boost::json::value* found = obj.if_contains(name);
            if (found && !found->is_null()) {
                auto r = read_from<F>(*found, p[name]);
                if (!r) {
                    err = std::move(r.error());
                    return;
                }
                field_out = std::move(*r);
            } else if (optional_reader<F>) {
                // leave field_out default-initialized — is_optional suppresses the error
            } else if (found) {
                // key present but explicitly null and field is not optional
                auto r = read_from<F>(*found, p[name]);
                if (!r) {
                    err = std::move(r.error());
                    return;
                }
                field_out = std::move(*r);
            } else {
                err = missing_field_error("missing field '{}' at {}", name, p.to_string());
            }
        });

        if (err) {
            return std::unexpected(std::move(*err));
        }
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
            return std::unexpected(type_error("expected string (duration) at {}", p.to_string()));
        }
        const std::string_view str = json.get_string();
        std::optional parsed = common::parse_duration<T>(str);
        if (!parsed) {
            return std::unexpected(validate_error("invalid duration format at {}", p.to_string()));
        }
        return *parsed;
    }
};

#undef TRY

} // namespace json::expected