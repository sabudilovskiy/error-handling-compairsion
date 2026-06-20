#pragma once

#include <type_traits>
#include <utility>
#include <variant>

namespace common
{

/*
 * Helper to combine multiple function objects into a single overload set.
 *
 * Commonly used for `std::visit`:
 *   std::visit(matcher{
 *       [](int) { ... },
 *       [](std::string_view) { ... },
 *   }, variant);
 *
 * Usage:
 *   matcher<Foo, Bar> m;
 *   m(some_value); // Calls the matching `operator()` from Foo or Bar
 */
template <typename... Foos>
struct matcher : Foos...
{
    using Foos::operator()...;
};

template <typename... Foos>
matcher(Foos...) -> matcher<Foos...>;

// Like 'matcher', but forces all branches to return the same type (`Ret`).
// Useful when return types differ but should be unified (e.g. `const char*` vs `std::string`).
//
// Example:
// std::visit(matcher_r<std::string>(
//     [](int i) { return std::to_string(i); },
//     [](std::monostate) { return ""; }  // const char* — not the same type!
// ), v);
//
// Without matcher_r, you'd get a compile error due to inconsistent return types.
template <typename Ret, typename... Foos>
constexpr auto matcher_r(Foos&&... foos) noexcept(
    (... && std::is_nothrow_constructible_v<std::remove_cvref_t<Foos>, Foos&&>) )
{
    return [m = matcher { std::forward<Foos>(foos)... }](auto&&... args) -> Ret {
        // - uses RVO, no move
        // - does not use std::invoke for better compilation speed/errors
        // and no one literaly needed to pass member pointers here
        return static_cast<Ret>(m(std::forward<decltype(args)>(args)...));
    };
}

// Shorthand for std::visit with matcher.
// Saves you from writing matcher(...) manually every time.
//
// Example:
// visit(v,
//     [](int) { ... },
//     [](std::string_view) { ... }
// );
template <typename V, typename... F>
decltype(auto) visit(V&& v, F&&... f)
{
    return std::visit(matcher(std::forward<F>(f)...), std::forward<V>(v));
}

// Same as visit, but forces return type to R (via matcher_r).
// Useful when lambdas return mixed types (e.g. "" vs std::string).
//
// Example:
// visit_r<std::string>(v,
//     [](int i) { return std::to_string(i); },
//     [](std::monostate) { return ""; }
// );
template <typename R, typename V, typename... F>
R visit_r(V&& v, F&&... f)
{
    return std::visit(matcher_r<R>(std::forward<F>(f)...), std::forward<V>(v));
}

} // common