#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_24)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/24.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "SFGFGFVVCWYEZWJXYAOOXU",
        .worker_threads           = 1,
        .enable_tracing           = false,
        .shutdown_grace_period    = 10min,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "JCRULVBGKK",
            .port                     = 46948,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"ZEPJIR", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = 25ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
