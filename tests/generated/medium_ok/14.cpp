#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_14)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/14.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WYU",
        .worker_threads           = 135,
        .enable_tracing           = true,
        .shutdown_grace_period    = 30s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "OVMMYDIHKLZILZ",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "DTKACIGMMSOTDUVDSSUU",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "XPQVGIOTGPZJQIDDCIIDAFXNDVQ",
                            .port                     = 38400,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 97,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -3809.5077,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "OTPCSEPWISOA",
                            .port                     = 54089,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 98,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "ZIDMDBGJAASQJQZLI",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YGAHIQIFHGTVKJXYLBRTXZYFQUGLPM",
                            .port                     = 16048,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 55,
                            .base_delay               = 5s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"BWE", data::threshold_rule{
                        .metric_name              = "POERMB",
                        .warn_at                  = 5701.8936,
                        .crit_at                  = -4864.377,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 23,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 15s,
                },
            },
            data::backend_group{
                .name                     = "VLTVRWBSNOIPKCLBVUUR",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::debug,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
        },
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{
            "SEAOOZPWQAJC",
        },
        .config_tree              = data::scope_override{
            .scope                    = "UQARZHXALDDMMOJLXKAIE",
            .extra                    = boost::json::value_from("SZYWJGQSO"),
            .log_level                = data::severity::debug,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_77", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "VYNGZAMWPHMQD",
                        .port                     = 49819,
                    },
                    .connect_timeout          = 1s,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 20,
                        .base_delay               = 1s,
                        .backoff_multiplier       = 5827.167,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "ZVTUJY",
                }},
            },
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "WF",
            .port                     = 47057,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
