#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_error_4_1)
{
    const std::string json = load_file("large_error_4/1.json");
    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)
    {
        json::path_value_t exp { "global_thresholds" };
        exp.emplace_back("FEDOSQ");
        exp.emplace_back(1ull);
        exp.emplace_back("crit_at");
        EXPECT_EQ(ex.path(), exp);
    };
}
