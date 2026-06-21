#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_error_10_3)
{
    const std::string json = load_file("large_error_10/3.json");
    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)
    {
        json::path_value_t exp { "config_tree" };
        exp.emplace_back("nested");
        exp.emplace_back("nested");
        exp.emplace_back("nested");
        exp.emplace_back("nested");
        exp.emplace_back("nested");
        exp.emplace_back("nested");
        exp.emplace_back("nested");
        exp.emplace_back("retry");
        exp.emplace_back("deadline");
        EXPECT_EQ(ex.path(), exp);
    };
}
