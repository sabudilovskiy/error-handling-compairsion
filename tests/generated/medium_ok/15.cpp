#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_15)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/15.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "AQXBFHABZVEWLHDKOWLIMILHGLZKHJ",
        .worker_threads           = 236,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
