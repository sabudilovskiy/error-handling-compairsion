#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_27)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/27.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WIJGCCIRKILMFHHPCXUS",
        .worker_threads           = 167,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "TUHWQEDMYJXZBYVQCFOWEIRBFUAOYE",
            .extra                    = boost::json::value_from("SSNCJOOLALF"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 36,
                .base_delay               = 25ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = 30s,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "K",
                    .value                    = "JIZRWWCJOOJQDSAJGYPR",
                },
            },
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "LZGJWTDBRNNXOXAFLX",
            .port                     = 953,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"MCLB", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "JHEOTPDHTLIAVPFJROGNZJVGQZE",
                    .warn_at                  = 4373.7523,
                    .crit_at                  = -3358.8368,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "PTTTWCH",
                    .warn_at                  = -1325.4672,
                    .crit_at                  = -3876.5591,
                    .evaluation_window        = 5s,
                },
            }},
            {"FYR", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
