#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_14)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/14.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WYU",
        .worker_threads           = 38,
        .enable_tracing           = true,
        .shutdown_grace_period    = 30s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
