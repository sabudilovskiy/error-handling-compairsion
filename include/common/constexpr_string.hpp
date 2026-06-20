#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>
#include <string_view>

namespace common
{

/*
 * A fixed-capacity, constexpr-compatible string type used as a non-type template parameter (NTTP).
 *
 * We use this form because it can be constructed from constexpr values
 * (e.g. `std::string_view`, config, macros, etc.).
 *
 * In contrast, alternative NTTP string types (e.g. `template <size_t N> struct`)
 * only work with literals and cannot be constructed from values.
 *
 * All fields are public to satisfy NTTP requirements.
 *
 * Example:
 *   template <ce_string Name>
 *   void f();
 *
 *   f<"field_name">();
 */
struct ce_string
{
    constexpr ce_string() noexcept = default;

    constexpr ce_string(const char* c_str)
        : ce_string(std::string_view { c_str })
    {
    }

    template <size_t Size>
    constexpr ce_string(const char (&str)[Size]) noexcept
        : len(Size - 1)
    {
        static_assert(Size <= Capacity);
        std::copy_n(str, Size, data_.begin());
    }

    constexpr ce_string(std::string_view sv)
    {
        if (sv.size() > Capacity) {
            throw std::runtime_error("string_view too big");
        }
        std::copy_n(sv.data(), sv.size(), data_.begin());
        len = sv.length();
    }

    constexpr std::string_view as_string_view() const
    {
        return std::string_view { data_.data(), len };
    }

    constexpr std::string as_string() const
    {
        return std::string { data_.data(), len };
    }

    constexpr operator std::string_view() const
    {
        return as_string_view();
    }

    friend constexpr bool operator==(const ce_string& string, const char* rhs)
    {
        std::string_view right { rhs };
        return string.as_string_view() == right;
    }

    friend constexpr bool operator==(const char* lhs, const ce_string& string)
    {
        return string == lhs;
    }

    constexpr size_t size() const
    {
        return len;
    }

    constexpr bool empty() const
    {
        return len == 0;
    }

    constexpr const char* data() const
    {
        return data_.data();
    }

public:
    static constexpr std::size_t Capacity = 64;

    size_t len = 0;
    std::array<char, Capacity> data_ {};
};

} // namespace common