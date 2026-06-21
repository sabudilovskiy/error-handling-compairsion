#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_error_10_1)
{
    const std::string json = load_file("medium_error_10/1.json");
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
        exp.emplace_back("nested");
        exp.emplace_back("scope");
        EXPECT_EQ(ex.path(), exp);
    };
}
