#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_18)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/18.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VOKHG",
        .worker_threads           = 243,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "LSQGZV",
            .port                     = 58441,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
