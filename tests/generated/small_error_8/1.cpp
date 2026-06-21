#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_error_8_1)
{
    const std::string json = load_file("small_error_8/1.json");
    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)
    {
        json::path_value_t exp { "config_tree" };
        exp.emplace_back("nested");
        exp.emplace_back("endpoint_overrides");
        exp.emplace_back("ep_34");
        exp.emplace_back("address");
        exp.emplace_back("host");
        EXPECT_EQ(ex.path(), exp);
    };
}
