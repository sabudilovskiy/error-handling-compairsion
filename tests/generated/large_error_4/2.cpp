#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_error_4_2)
{
    const std::string json = load_file("large_error_4/2.json");
    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)
    {
        json::path_value_t exp { "routes" };
        exp.emplace_back("XW");
        exp.emplace_back("backend_names");
        exp.emplace_back(0ull);
        EXPECT_EQ(ex.path(), exp);
    };
}
