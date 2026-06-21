#pragma once

#include <format>
#include <stdexcept>
#include <utility>

namespace common
{

/*
 * Small helper for readable exceptions with `std::format`.
 *
 * Usage:
 *   throw error("invalid value: {}", value);
 *
 * Tip:
 *   You can inherit from it for custom exception types:
 *     struct my_error : error {
 *         using error::error;
 *     };
 */
struct error : std::runtime_error
{
    using std::runtime_error::runtime_error;

    template <typename... Args>
    error(std::format_string<Args...> fmt, Args&&... args)
        : std::runtime_error(std::format(fmt, std::forward<Args>(args)...)) // -V1067
    {
    }
};

} // common