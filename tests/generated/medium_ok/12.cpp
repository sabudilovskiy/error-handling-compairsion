#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_12)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/12.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VQVLEMALPIUZOWT",
        .worker_threads           = 59,
        .enable_tracing           = true,
        .shutdown_grace_period    = 10s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{
            {"BSG", data::routing_rule{
                .pattern                  = "VK",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"VQ", data::routing_rule{
                .pattern                  = "NODVNER",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 100ms,
            }},
            {"QCM", data::routing_rule{
                .pattern                  = "VTPPTMRAUXCGZVILLWM",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
            {"SZYQFA", data::routing_rule{
                .pattern                  = "NBQAHVNBMGYT",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 100ms,
            }},
            {"PLTU", data::routing_rule{
                .pattern                  = "QOLGKJOPWPHFORLFGYXHTAI",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"QB", data::routing_rule{
                .pattern                  = "DLRQEAK",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"HZ", data::routing_rule{
                .pattern                  = "PPULIVOXFOJTBIKQ",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
        },
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{
            "",
        },
        .config_tree              = data::scope_override{
            .scope                    = "GNPB",
            .extra                    = boost::json::value_from("TXIYBNNSCMZGSRLLU"),
            .log_level                = std::nullopt,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
