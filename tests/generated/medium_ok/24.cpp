#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_24)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/24.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "SFGFGFVVCWYEZWJXYAOOXU",
        .worker_threads           = 30,
        .enable_tracing           = false,
        .shutdown_grace_period    = 10min,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "JCRULVBGKK",
            .extra                    = boost::json::value_from("CJDHVTZEPJIRXIGCSPZEUEKPGVTZ"),
            .log_level                = data::severity::critical,
            .retry                    = data::retry_policy{
                .max_attempts             = 51,
                .base_delay               = 10ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "CPLKIYFXS",
                    .value                    = "KHLBBOWKOOZYCBCKWNZMRPSQNM",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "EKXCZSUZAIR",
                .extra                    = boost::json::value_from(""),
                .log_level                = std::nullopt,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_58", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YLKXAMAPOZCF",
                            .port                     = 51426,
                        },
                        .connect_timeout          = 1s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 53,
                            .base_delay               = 5s,
                            .backoff_multiplier       = -1085.674,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "RWPBFKZJDFDEYQYCTZQPQWJIVUOOU",
                    }},
                    {"ep_85", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "EKCGQEFEOKJHUTEHDJXUTTHIOCG",
                            .port                     = 14026,
                        },
                        .connect_timeout          = 1min,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 56,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = 5194.2434,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "GXHAH",
                                .value                    = "PVTXSHKI",
                            },
                            data::tag{
                                .key                      = "RJAHLUTSJHLHZZQMKCCLOOLOPSNHBD",
                                .value                    = "AYYJU",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    }},
                },
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "VTGLEDUQGQITUWLFIQOJFJ",
                        .value                    = "EMTACHPAHQYPYPERXHTLDTUUDKU",
                    },
                },
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = 50ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
