#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_16)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/16.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "PJNHOANVWIH",
        .worker_threads           = 162,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "JAZHTIAEZTVUAOOTUWJHZJL",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LPNQUFSJSBJCZAQLHPEJJKOOC",
                            .port                     = 10765,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 85,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 1min,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "CPUAEWHMLBRBVUMTKPQVZVUCHK",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "DH",
                            .port                     = 599,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 91,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "IHFSAHQHDDUEIMNBMOXO",
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "MDZGDNUDJDONEMHEEMNQHMFLVPFNGV",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::debug,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
        },
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "GSOQEPRCYUVDXVKBOCZP",
            .extra                    = boost::json::value_from("BQKRFDWLMJMCHGOGWAUAHKM"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 27,
                .base_delay               = 50ms,
                .backoff_multiplier       = -8846.8089,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "URVUXXIQATTZZQGPSPLEWOXWF",
                .extra                    = boost::json::value_from("ACL"),
                .log_level                = std::nullopt,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "TWYWD",
                    .extra                    = boost::json::value_from("YHLGSNCFCOCBSEEVXYFYGNB"),
                    .log_level                = std::nullopt,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 86,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -2335.0379,
                        .deadline                 = 30s,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_25", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "GMNZBSGNYXVRKBQMLAUENHKFMB",
                                .port                     = 24650,
                            },
                            .connect_timeout          = 2s,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 64,
                                .base_delay               = 200ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = 2min,
                            },
                            .tags                     = std::vector<data::tag>{},
                            .tls_cert_path            = std::nullopt,
                        }},
                    },
                    .tags                     = std::vector<data::tag>{},
                    .nested                   = common::box<data::scope_override>{},
                }},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"RAEKTT", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "OETNJSTZNRCWYETBJ",
                    .warn_at                  = -4748.5721,
                    .crit_at                  = 3055.0568,
                    .evaluation_window        = 15s,
                },
            }},
            {"MJUS", std::vector<data::threshold_rule>{}},
            {"KM", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "JZGIAPWAXGCZNESHKNSYDXIZYAK",
                    .warn_at                  = 9462.6956,
                    .crit_at                  = -2527.6364,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "UGZXQB",
                    .warn_at                  = 657.5139,
                    .crit_at                  = -4432.6137,
                    .evaluation_window        = 15s,
                },
            }},
        },
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
