#pragma once

#include <cassert>
#include <cstddef>
#include <utility>

#include "common/unreachable.hpp"

namespace common
{

/**
 * Invokes a templated callable `cb.template operator()<I>()` for each index I in [0, N).
 *
 * Expands the call over a parameter pack of indices using a fold expression,
 * enabling compile-time iteration over indices.
 *
 * Requirements:
 *  - `cb` must support templated calls of the form `[]<size_t I>() { ... }`.
 *  - `N` must be a constant expression.
 *
 * Example:
 *   for_each_index<3>(
 *     []<size_t I>() {
 *       std::cout << "I = " << I << "\n";
 *     }
 *   ); // prints I = 0\nI = 1\nI = 2
 */
template <size_t N>
constexpr void for_each_index(auto&& cb)
{
    [&]<size_t... I>(std::index_sequence<I...>) {
        (cb.template operator()<I>(), ...);
    }(std::make_index_sequence<N> {});
}

/**
 * Calls a templated callable `cb.template operator()<I...>()` with a full pack of indices [0, N).
 *
 * Useful for passing the entire sequence of compile-time indices as template parameters
 * to a callable object.
 *
 * Requirements:
 *  - `cb` must support a templated call with a full parameter pack, e.g., `[]<size_t... I>() { ... }`.
 *  - `N` must be a constant expression.
 *
 * Returns:
 *   The result of `cb.template operator()<0, 1, ..., N-1>()`.
 *
 * Example:
 *   call_on_indexes<3>(
 *     []<size_t... I>() {
 *       return ((I + 1) + ...); // 1 + 2 + 3 = 6
 *     }
 *   );
 */
template <size_t N>
constexpr decltype(auto) call_on_indexes(auto&& cb)
{
    return [&]<size_t... I>(std::index_sequence<I...>) {
        return cb.template operator()<I...>();
    }(std::make_index_sequence<N> {});
}

constexpr std::size_t VISIT_INDEX_MAX = 1024 - 1;

/* Calls `f.template operator()<I>()` based on the runtime index `i` (0 ≤ i ≤ Max).
 *
 * Generates a large switch (up to 1024 cases) that compilers typically optimize into
 * jump tables or efficient branching. Useful for low‑overhead runtime dispatch
 * into template instantiations.
 *
 * Requirements:
 *  - `Max` must be ≤ VISIT_INDEX_MAX — enforced at compile time.
 *  - `i` must be ≤ VISIT_INDEX_MAX — asserted at runtime.
 *  - Undefined behavior if `i > Max` (calls unreachable()).
 *  - `f` must support a templated call of the form:
 *      `[]<size_t I>() { ... }`
 *
 * Example:
 *   visit_index<3>(
 *     []<size_t I>() {
 *       std::cout << "I = " << I << "\n";
 *     },
 *     2
 *   ); // prints "I = 2"
 */
template <size_t Max>
constexpr decltype(auto) visit_index(auto&& f, size_t i)
{
    static_assert(Max <= VISIT_INDEX_MAX);
    assert(i <= VISIT_INDEX_MAX);
    switch (i) {
#define COMMON_SWITCH_CASE(INDEX)                  \
    case INDEX: {                                  \
        if constexpr (INDEX <= Max) {              \
            return f.template operator()<INDEX>(); \
        } else {                                   \
            unreachable();                         \
        }                                          \
    }
#define COMMON_SWITCH_CASE4(I) \
    COMMON_SWITCH_CASE(I)      \
    COMMON_SWITCH_CASE(I + 1)  \
    COMMON_SWITCH_CASE(I + 2)  \
    COMMON_SWITCH_CASE(I + 3)
#define COMMON_SWITCH_CASE8(I) COMMON_SWITCH_CASE4(I) COMMON_SWITCH_CASE4(I + 4)
#define COMMON_SWITCH_CASE16(I) COMMON_SWITCH_CASE8(I) COMMON_SWITCH_CASE8(I + 8)
#define COMMON_SWITCH_CASE32(I) COMMON_SWITCH_CASE16(I) COMMON_SWITCH_CASE16(I + 16)
#define COMMON_SWITCH_CASE64(I) COMMON_SWITCH_CASE32(I) COMMON_SWITCH_CASE32(I + 32)
#define COMMON_SWITCH_CASE128(I) COMMON_SWITCH_CASE64(I) COMMON_SWITCH_CASE64(I + 64)
#define COMMON_SWITCH_CASE256(I) COMMON_SWITCH_CASE128(I) COMMON_SWITCH_CASE128(I + 128)
#define COMMON_SWITCH_CASE512(I) COMMON_SWITCH_CASE256(I) COMMON_SWITCH_CASE256(I + 256)
#define COMMON_SWITCH_CASE1024(I) COMMON_SWITCH_CASE512(I) COMMON_SWITCH_CASE512(I + 512)
        COMMON_SWITCH_CASE1024(0);
    } // end switch
    unreachable();
#undef COMMON_SWITCH_CASE
#undef COMMON_SWITCH_CASE4
#undef COMMON_SWITCH_CASE8
#undef COMMON_SWITCH_CASE16
#undef COMMON_SWITCH_CASE32
#undef COMMON_SWITCH_CASE64
#undef COMMON_SWITCH_CASE128
#undef COMMON_SWITCH_CASE256
#undef COMMON_SWITCH_CASE512
#undef COMMON_SWITCH_CASE1024
}

}