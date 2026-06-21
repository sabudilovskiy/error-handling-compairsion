#pragma once

namespace common
{

template <typename T>
struct type_holder
{
    using type = T;
};

template <typename T>
inline constexpr type_holder<T> type_v {};

template <auto V>
struct value_holder
{
    static constexpr auto value = V;
};

}