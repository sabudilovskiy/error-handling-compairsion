#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_29)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/29.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "LTTJCQLMNABDOUHZL",
        .worker_threads           = 1,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5min,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
