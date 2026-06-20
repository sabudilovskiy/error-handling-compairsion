#pragma once

#include <format>
#include <optional>
#include <variant>

#include <boost/json.hpp>

#ifndef __cpp_lib_format_ranges
#include <ranges>
#include <tuple>
#include <utility>
#endif

#ifndef __cpp_lib_format_path
#include <filesystem>
#endif

#include <boost/pfr/core_name.hpp>
#include <magic_enum/magic_enum.hpp>

#include "common/box.hpp"
#include "common/name_type.hpp"
#include "common/traits.hpp"

namespace common::details
{

template <typename T>
struct range_formatter_helper
{
    constexpr static auto first_elem_fmt = "{}";
    constexpr static auto other_elems_fmt = ", {}";
};

template <typename Rng>
    requires range_with_value<Rng, std::string> || range_with_value<Rng, std::string_view>
struct range_formatter_helper<Rng>
{
    constexpr static auto first_elem_fmt = R"("{}")";
    constexpr static auto other_elems_fmt = R"(, "{}")";
};

}

namespace std
{

template <common::aggregate T>
struct formatter<T> : formatter<std::string_view>
{
    auto format(const T& t, auto& ctx) const -> decltype(ctx.out())
    {
        auto out = ctx.out();
        *out++ = '(';
        boost::pfr::for_each_field_with_name(t, [&]<typename F>(std::string_view name, const F& field, std::size_t i) {
            out = std::format_to(out, "`{}`: {}", name, field);
            if (i + 1 != boost::pfr::tuple_size_v<T>) {
                *out++ = ',';
                *out++ = ' ';
            }
        });
        *out++ = ')';
        return out;
    }
};

template <typename... Ts>
struct formatter<std::variant<Ts...>> : formatter<std::string_view>
{
    auto format(const std::variant<Ts...>& t, auto& ctx) const -> decltype(ctx.out())
    {
        auto out = ctx.out();
        auto visiter = [&]<typename U>(const U& value) {
            out = std::format_to(out, "(`{}`: {})", common::name_of_type_v<U>, value);
        };
        std::visit(visiter, t);
        return out;
    }
};

template <common::is_scoped_enum T>
struct formatter<T> : formatter<std::string_view>
{
    auto format(T t, auto& ctx) const -> decltype(ctx.out())
    {
        return std::format_to(ctx.out(), "{}", magic_enum::enum_name(t));
    }
};

template <typename T>
struct formatter<std::optional<T>> : formatter<std::string_view>
{
    auto format(const std::optional<T>& t, auto& ctx) const -> decltype(ctx.out())
    {
        if (t.has_value()) {
            return std::format_to(ctx.out(), "{}", *t);
        } else {
            return std::format_to(ctx.out(), "(null)");
        }
    }
};

template <typename T>
struct formatter<common::box<T>> : formatter<std::string_view>
{
    auto format(const common::box<T>& t, auto& ctx) const -> decltype(ctx.out())
    {
        if (t.has_value()) {
            return std::format_to(ctx.out(), "{}", *t);
        } else {
            return std::format_to(ctx.out(), "(null)");
        }
    }
};

template <>
struct formatter<boost::json::value> : formatter<std::string_view>
{
    auto format(const boost::json::value& t, auto& ctx) const -> decltype(ctx.out())
    {
        return std::format_to(ctx.out(), "{}", boost::json::serialize(t));
    }
};

#ifndef __cpp_lib_format_path
template <>
struct formatter<std::filesystem::path> : formatter<std::string_view>
{
    auto format(const filesystem::path& p, auto& ctx) const -> decltype(ctx.out())
    {
        return std::format_to(ctx.out(), "{}", p.c_str());
    }
};
#endif

#ifndef __cpp_lib_format_ranges

template <common::array_like R>
struct formatter<R> : formatter<std::string_view>
{
    constexpr static auto first_elem_fmt = common::details::range_formatter_helper<R>::first_elem_fmt;
    constexpr static auto other_elems_fmt = common::details::range_formatter_helper<R>::other_elems_fmt;

    template <typename Rng>
    auto fmt(Rng&& r, auto& ctx) const -> decltype(ctx.out())
    {
        auto out = ctx.out();
        *out++ = '[';

        auto it = std::ranges::begin(std::forward<Rng>(r));
        auto end = std::ranges::end(std::forward<Rng>(r));

        if (it != end) {
            out = std::format_to(out, first_elem_fmt, *it);
            ++it;
        }

        for (; it != end; it++) {
            out = std::format_to(out, other_elems_fmt, *it);
        }

        *out++ = ']';

        return out;
    }

    auto format(const R& r, auto& ctx) const -> decltype(ctx.out())
        requires std::ranges::range<const R>
    {
        return fmt(r, ctx);
    }

    auto format(R& r, auto& ctx) const -> decltype(ctx.out())
        requires(!std::ranges::range<const R>)
    {
        return fmt(r, ctx);
    }
};

template <typename L, typename R>
struct formatter<pair<const L, R>> : formatter<std::string_view> // detecting pair from map/unordered_map
{
    auto format(const pair<const L, R>& p, auto& ctx) const -> decltype(ctx.out())
    {
        return std::format_to(ctx.out(), "({} : {})", p.first, p.second);
    }
};

template <typename L, typename R>
struct formatter<pair<L, R>> : formatter<std::string_view>
{
    auto format(const pair<const L, R>& p, auto& ctx) const -> decltype(ctx.out())
    {
        return std::format_to(ctx.out(), "({}, {})", p.first, p.second);
    }
};

template <typename T, typename... Args>
struct formatter<std::tuple<T, Args...>> : formatter<std::string_view>
{
    auto format(const std::tuple<T, Args...>& t, auto& ctx) const -> decltype(ctx.out())
    {
        auto out = ctx.out();
        *out++ = '(';
        auto helper = [&](const auto& first, const auto&... elements) {
            out = std::format_to(out, "{}", first);
            ((out = std::format_to(out, ", {}", elements)), ...);
        };
        std::apply(helper, t);
        out++ = ')';
        return out;
    }
};

#endif

}