#pragma once

#include <concepts>
#include <ranges>
#include <string_view>
#include <type_traits>

namespace common
{

namespace details
{
    struct scoped_enum_checker
    {
        static void test_conversion(...); // selected when Enum is complete and scoped
        static void test_conversion(int) = delete; // selected when Enum is complete and unscoped
    };

} // namespace details

template <typename T, typename... Types>
concept any_of = (std::same_as<T, Types> || ...);

template <typename T>
concept aggregate = std::is_aggregate_v<std::remove_cvref_t<T>> && !std::ranges::range<T>;

template <typename T>
concept char_type_like = any_of<T, char, signed char, unsigned char, char8_t, char16_t, char32_t, wchar_t>;

template <typename T>
concept string_like = std::convertible_to<T, std::string_view>;

template <typename T>
concept array_like = std::ranges::range<T> && !string_like<T>;

template <typename T>
concept tuple_like = requires { typename std::tuple_size<T>::type; } && !array_like<T>;

template <typename R, typename V>
concept range_with_value = std::ranges::range<R> && std::same_as<std::remove_cvref_t<std::ranges::range_value_t<R>>, V>;

template <class E>
concept is_scoped_enum = std::is_enum_v<E> && // checked first
    requires { details::scoped_enum_checker::test_conversion(E {}); }; // ill-formed before overload resolution
                                                                       // when E is incomplete

}