#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_10)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/10.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "NPSAGOPIUZFBQPKCHX",
        .worker_threads           = 255,
        .enable_tracing           = true,
        .shutdown_grace_period    = 2min,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{
            {"OFVJ", data::routing_rule{
                .pattern                  = "EOYHOTMBSAHEGJRLYHKVR",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "J",
            .extra                    = boost::json::value_from("VCRCEMSLTEDYYDOFZGLNNOHVIE"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 12,
                .base_delay               = 25ms,
                .backoff_multiplier       = 2974.4966,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "ARWBKKHCIOMSF",
                .extra                    = boost::json::value_from("PVHXQIQPTPCF"),
                .log_level                = std::nullopt,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
