#pragma once

#include <format>
#include <iterator>

#include "common/formatters.hpp"

namespace std
{

template <formattable<char> T>
void PrintTo(const T& t, std::ostream* os)
{
    std::format_to(std::ostreambuf_iterator(*os), "{}", t);
}
} // namespace std