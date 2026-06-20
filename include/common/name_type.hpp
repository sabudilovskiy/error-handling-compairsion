#pragma once

#include <string_view>

namespace common
{

namespace details
{

    template <typename T>
    constexpr std::string_view name_of_type()
    {
        std::string_view res = "";
#if defined(__GNUC__) && !defined(__clang__)
        res = __PRETTY_FUNCTION__;
        res.remove_prefix(
            sizeof("consteval std::string_view common::details::name_of_type() [with T ="));
        auto idx = res.find(";");
        res.remove_suffix(res.size() - idx);
#elif defined(__clang__)
        res = __PRETTY_FUNCTION__;
        res.remove_prefix(sizeof("std::string_view common::details::name_of_type() [T ="));
        res.remove_suffix(1);
#else
#error Unknown compiler
#endif
        return res;
    }

} // common::details

// Returns human-readable name of type T (compiler-dependent).
// Used for diagnostics, logging, debugging, or reflection helpers.
//
// Relies on `__PRETTY_FUNCTION__`, so formatting varies by compiler.
// Not stable across versions or suitable for ABI — use only for tooling/debug.
//
// Example:
// static_assert(name_of_type_v<int> == "int");
template <typename T>
constexpr std::string_view name_of_type_v = details::name_of_type<T>();

} // common