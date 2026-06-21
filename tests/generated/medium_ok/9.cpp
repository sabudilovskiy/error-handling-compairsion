#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_9)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/9.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "LIEFVAKQOTCKRT",
        .worker_threads           = 179,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("SCYW", 38366, false),
            std::make_tuple("VHXZNCYIG", 39654, true),
            std::make_tuple("ANBMPEAHNXDTADYSGGKACE", 53976, true),
            std::make_tuple("GNCMGUYCWSEFTXB", 5417, false),
        },
        .allowed_origins          = std::set<std::string>{
            "BDWMHFTQBXLVQSSYWCLDSLOGMGSXAMZ",
        },
        .config_tree              = data::scope_override{
            .scope                    = "HOI",
            .extra                    = boost::json::value_from("CJUJDQZBAM"),
            .log_level                = std::nullopt,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "NUHDYMQLRLEVJFWIABZFIFD",
                .extra                    = boost::json::value_from("ABBOGZMJTAZLJEPRIEC"),
                .log_level                = std::nullopt,
                .retry                    = data::retry_policy{
                    .max_attempts             = 12,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 1238.5097,
                    .deadline                 = std::nullopt,
                },
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "TPLDBIQEFZUCFYZHAGF",
            .port                     = 31040,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
