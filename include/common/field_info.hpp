#pragma once

#include "common/constexpr_string.hpp"

namespace common
{

template <size_t Index, ce_string Name>
struct field_info
{
    static constexpr auto index = Index;
    static constexpr auto name = Name;
};

}