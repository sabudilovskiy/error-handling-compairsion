#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, bad_50_10_wrong_type_3)
{
    const std::string json = load_file("bad_50_10_wrong_type_3.json");
    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)
    {
        json::path_value_t exp { "config_tree" };
        add_nested(exp, 10);
        exp.emplace_back("endpoint_overrides");
        exp.emplace_back("ep_41");
        exp.emplace_back("address");
        exp.emplace_back("port");
        EXPECT_EQ(ex.path(), exp);
    };
}
