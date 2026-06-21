#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_7)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/7.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "EMUBCRDLSB",
        .worker_threads           = 232,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "BHBREJNERDSJRVFDSS",
            .port                     = 41871,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
