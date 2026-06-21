#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_23)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/23.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "JCASJNMQLEXGIOAHTOADCWPNAQUXN",
        .worker_threads           = 92,
        .enable_tracing           = true,
        .shutdown_grace_period    = 30s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "VKSCPFWPSZOVUFFZFR",
            .extra                    = boost::json::value_from("QGSDCDNBSI"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 59,
                .base_delay               = 10ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "TZDW",
                .extra                    = boost::json::value_from("PHKREXSDMFOBBUNMAFZHVAHZX"),
                .log_level                = std::nullopt,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "MPGBCIORGYOJGCDRQUFWRRHIDNFAOYK",
                    .extra                    = boost::json::value_from("NFTWZNCWUXHRJNNJYRTRB"),
                    .log_level                = std::nullopt,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 63,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = std::nullopt,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                    .tags                     = std::vector<data::tag>{},
                    .nested                   = common::box<data::scope_override>{},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "PZOWIAKMAZEXMGZVA",
            .port                     = 11349,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
