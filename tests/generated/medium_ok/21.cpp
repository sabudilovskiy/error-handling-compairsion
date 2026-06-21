#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_21)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/21.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WNUJP",
        .worker_threads           = 216,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "HWBNXYNTOBKRPWDULAEXCDZA",
            .extra                    = boost::json::value_from("RXKMPEFVBPHCYG"),
            .log_level                = data::severity::critical,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "ERNJLOQMKP",
                .extra                    = boost::json::value_from("ACFWWPAPCRTX"),
                .log_level                = std::nullopt,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                .tags                     = std::vector<data::tag>{},
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
