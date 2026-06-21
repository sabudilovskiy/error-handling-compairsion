#pragma once

#include <cassert>
#if defined(__cpp_lib_unreachable)
#include <utility>
#endif

namespace common
{

#ifdef PVS_STUDIO
#pragma pvs(push)
#pragma pvs(disable : 779)
#endif
// Marks unreachable code path — both for debug-time asserts and optimizer hints.
//
// Use when the code should be provably unreachable (e.g. exhaustive match, defensive check).
//
// In debug builds: triggers assert(false)
// In release: emits compiler-specific unreachable hint for better codegen
//
// Example:
// switch (kind) {
//   case A: ...; break;
//   case B: ...; break;
//   default: unreachable();
// }
[[noreturn]] inline void unreachable() noexcept
{
    assert(false);
#if defined(__cpp_lib_unreachable)
    std::unreachable();
#elif defined(__GNUC__) || defined(__clang__)
    __builtin_unreachable();
#elif defined(_MSC_VER)
    __assume(false);
#endif
    unreachable();
}

#ifdef PVS_STUDIO
#pragma pvs(pop)
#endif

}