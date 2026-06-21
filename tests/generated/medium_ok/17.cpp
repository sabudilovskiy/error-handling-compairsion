#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_17)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/17.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ZJLJFYWWRVIDAHMX",
        .worker_threads           = 107,
        .enable_tracing           = false,
        .shutdown_grace_period    = 1min,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "RRZVGKRDWUCJNCQPUTEVZNQKANLS",
            .extra                    = boost::json::value_from("Y"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 48,
                .base_delay               = 50ms,
                .backoff_multiplier       = -1890.8414,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "XTRRREIV",
                    .value                    = "LKFKDSSZI",
                },
                data::tag{
                    .key                      = "L",
                    .value                    = "",
                },
            },
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "ICXWPA",
            .port                     = 40701,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 25ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
