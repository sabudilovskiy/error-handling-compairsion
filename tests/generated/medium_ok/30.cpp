#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_30)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/30.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "JTATUGIBMMUECOAQH",
        .worker_threads           = 7,
        .enable_tracing           = false,
        .shutdown_grace_period    = 2min,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "IYNSDVIURDTPJEJJIQ",
            .port                     = 5266,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"NX", std::vector<data::threshold_rule>{}},
            {"PUK", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
