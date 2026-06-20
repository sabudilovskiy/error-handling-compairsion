#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, bad_50_10_missing_field_3)
{
    const std::string json = load_file("bad_50_10_missing_field_3.json");
    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)
    {
        json::path_value_t exp { "config_tree" };
        add_nested(exp, 10);
        EXPECT_EQ(ex.path(), exp);
    };
}
