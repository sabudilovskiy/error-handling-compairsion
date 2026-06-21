#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_4)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/4.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "DXMPECC",
        .worker_threads           = 6,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "IZIGFJJUXLCTKVMQHFHP",
            .extra                    = boost::json::value_from("RJAJSWJY"),
            .log_level                = std::nullopt,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "ZBCBOUIQR",
                .extra                    = boost::json::value_from("WKEVGCNGUUOIFLNXSKUR"),
                .log_level                = data::severity::warning,
                .retry                    = data::retry_policy{
                    .max_attempts             = 7,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = std::nullopt,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_23", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "ABLWCJXVK",
                            .port                     = 1192,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 96,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    }},
                    {"ep_25", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "JEIMTFKSALBOFLZZLJSDOGNGDBBB",
                            .port                     = 48307,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 97,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "JYNUGPGHONPBHNOHUNGPGBBIIH",
                                .value                    = "YHNIEKBKSDSMUUZW",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    }},
                    {"ep_27", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "SFKJVPZUKNQGUZVZIKMPCIUVGBMTE",
                            .port                     = 50253,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 85,
                            .base_delay               = 2s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    }},
                    {"ep_1", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "FATIDM",
                            .port                     = 53075,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 87,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 15s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    }},
                },
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "T",
                    .extra                    = boost::json::value_from("RIT"),
                    .log_level                = std::nullopt,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 8,
                        .base_delay               = 2s,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 5s,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                    .tags                     = std::nullopt,
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "MHYPMDCDTZLQNNWYOCUGUJPNDZRFLFF",
                        .extra                    = boost::json::value_from("KPKIRAWFAUJDRDPZWTPQCQ"),
                        .log_level                = data::severity::warning,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 76,
                            .base_delay               = 1min,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .endpoint_overrides       = std::nullopt,
                        .tags                     = std::vector<data::tag>{},
                        .nested                   = common::box<data::scope_override>{},
                    }},
                }},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
