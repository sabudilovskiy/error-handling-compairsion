#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_6)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/6.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "CPYIBAEVSPYXLKYAIPZGXNRRV",
        .worker_threads           = 25,
        .enable_tracing           = false,
        .shutdown_grace_period    = 15s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "IOWDYGWUZJDBS",
            .extra                    = boost::json::value_from("ULPGQSUWZQAULHTNJLSDCQVQGDTV"),
            .log_level                = data::severity::info,
            .retry                    = data::retry_policy{
                .max_attempts             = 23,
                .base_delay               = 50ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "RVTTJLMQMJEVPBFNTXMD",
                    .value                    = "HZCTVOOZMZCQNPJWNCGXVIOPXZFAARD",
                },
                data::tag{
                    .key                      = "GIQOKQINNTPITPVPPEXMPJUZO",
                    .value                    = "VFTMWTIKUM",
                },
            },
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "RATOBFATYSDVWLLPSBGEITANZZ",
            .port                     = 52438,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
