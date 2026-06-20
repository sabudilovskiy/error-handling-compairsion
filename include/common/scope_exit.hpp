#pragma once

#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-attributes"
#endif

#include <type_traits>
#include <utility>

#if __cplusplus >= 202002L
#define LOGIC_GUARDS_CONSTEXPR_DCTOR constexpr
#else
#define LOGIC_GUARDS_CONSTEXPR_DCTOR
#endif

// both scope_exit and scope_failure use precondition,
// that invoking 'fn' do not dellocates memory where 'scope_exit/failure' exists
// or atleast do not touch memory after deleting(including lambda capture/references to other objects)

namespace common
{

// SCOPE EXIT
// invokes 'Foo' when destroyed
// if scope ended with exception and 'Foo' throws exception terminate is called
template <typename Foo>
struct [[nodiscard("Ignored scope_exit: cleanup will run immediately, not at scope exit")]] scope_exit
{
    [[no_unique_address]] Foo fn;

    LOGIC_GUARDS_CONSTEXPR_DCTOR
    ~scope_exit() noexcept(noexcept(fn()))
    {
        (void) fn();
    }
};
template <typename T>
scope_exit(T&&) -> scope_exit<std::decay_t<T>>;

// ON SCOPE FAILURE
// invokes 'Foo' when destroyed and success point not reached
// success point set by invoking .no_longer_needed()
template <typename Foo>
struct [[nodiscard("Ignored scope_failure: cleanup will run immediately, not at scope exit")]] scope_failure
{
    [[no_unique_address]] Foo fn;
    bool failed = true;

    void operator=(scope_failure&&) = delete;

    LOGIC_GUARDS_CONSTEXPR_DCTOR
    ~scope_failure() noexcept(noexcept(fn()))
    {
        if (failed) {
            (void) fn();
        }
    }
    // should be called where the 'fn' call is no longer needed
    constexpr void no_longer_needed() noexcept
    {
        failed = false;
    }
    constexpr void use_and_forget() noexcept(noexcept(fn()))
    {
        failed = false;
        (void) fn();
    }
};
template <typename T>
scope_failure(T&&) -> scope_failure<std::decay_t<T>>;

} // namespace common

// MACROS on_scope_exit / on_scope_failure(NAME) for easy usage

namespace common::details
{

// used only in macro
struct maker
{
    template <typename T>
    constexpr auto operator+(T&& fn) const noexcept(std::is_nothrow_constructible_v<std::decay_t<T>, T&&>)
    {
        return scope_exit { std::forward<T>(fn) };
    }
    template <typename T>
    constexpr auto operator-(T&& fn) const noexcept(std::is_nothrow_constructible_v<std::decay_t<T>, T&&>)
    {
        return scope_failure { std::forward<T>(fn) };
    }
};

} // namespace common::details

#define COMMON_LOGIC_GUARDS_CONCAT_IMPL_EXPAND(a, b, c) a##_##b##_##c
#define COMMON_LOGIC_GUARDS_CONCAT_IMPL(a, b, c) COMMON_LOGIC_GUARDS_CONCAT_IMPL_EXPAND(a, b, c)
#define COMMON_LOGIC_GUARDS_CONCAT(a, b, c) COMMON_LOGIC_GUARDS_CONCAT_IMPL(a, b, c)

// COMMON_ON_SCOPE_EXIT and COMMON_ON_SCOPE_FAILURE macros
//
// These macros simplify the usage of `scope_exit` and `scope_failure`
// by automatically generating unique variable names and capturing the local scope.
//
// Usage:
//
//   COMMON_ON_SCOPE_EXIT {
//       ... cleanup code ...
//   };
//
//   COMMON_ON_SCOPE_FAILURE(my_cleanup) {
//       ... rollback code ...
//   };
//   ...
//   my_cleanup.no_longer_needed(); // disables the failure handler
//
// Example:
//
//   void example(bool fail)
//   {
//       COMMON_ON_SCOPE_EXIT {
//           std::cout << "Cleanup at scope exit\n";
//       };
//
//       COMMON_ON_SCOPE_FAILURE(failure_handler) {
//           std::cout << "Rollback on failure\n";
//       };
//
//       if (fail) {
//           throw std::runtime_error("something went wrong");
//       }
//
//       failure_handler.no_longer_needed(); // disables rollback
//   }
//
// Notes:
//   - Both macros capture the surrounding scope by reference.
//   - `COMMON_ON_SCOPE_FAILURE(NAME)` defines a named variable you can control.
//   - `COMMON_ON_SCOPE_EXIT` is unnamed and always executes at scope end.
#define COMMON_ON_SCOPE_EXIT \
    [[maybe_unused]] const auto COMMON_LOGIC_GUARDS_CONCAT(scope_exit, __LINE__, __COUNTER__) = ::common::details::maker {} + [&]()
#define COMMON_ON_SCOPE_FAILURE(NAME) auto NAME = ::common::details::maker {} - [&]()

#if __clang__
#pragma clang diagnostic pop
#endif