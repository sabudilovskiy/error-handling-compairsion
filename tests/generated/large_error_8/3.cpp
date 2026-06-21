#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_error_8_3)
{
    const std::string json = load_file("large_error_8/3.json");
    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)
    {
        json::path_value_t exp { "backends" };
        exp.emplace_back(0ull);
        exp.emplace_back("endpoints");
        exp.emplace_back(0ull);
        exp.emplace_back("retry");
        exp.emplace_back("base_delay");
        EXPECT_EQ(ex.path(), exp);
    };
}
