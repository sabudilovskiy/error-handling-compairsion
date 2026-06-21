#pragma once

#include <chrono>

#include "common/meta.hpp"

namespace common
{

enum struct duration_postfix
{
    ns,
    us,
    ms,
    s,
    m,
    h
};

template <typename T>
struct minimum_postfix
{
};

template <typename T>
inline constexpr duration_postfix minimum_postfix_v = minimum_postfix<T>::value;

template <typename T>
concept has_duration_postfix = requires {
    { minimum_postfix<T>::value } -> std::convertible_to<duration_postfix>;
};

template <>
struct minimum_postfix<std::chrono::nanoseconds> : value_holder<duration_postfix::ns>
{
};

template <>
struct minimum_postfix<std::chrono::microseconds> : value_holder<duration_postfix::us>
{
};

template <>
struct minimum_postfix<std::chrono::milliseconds> : value_holder<duration_postfix::ms>
{
};

template <>
struct minimum_postfix<std::chrono::seconds> : value_holder<duration_postfix::s>
{
};

template <>
struct minimum_postfix<std::chrono::minutes> : value_holder<duration_postfix::m>
{
};

template <>
struct minimum_postfix<std::chrono::hours> : value_holder<duration_postfix::h>
{
};
}