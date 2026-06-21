#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_11)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/11.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "RYOOQSGFZQPUTZFDOJECRZWUBTMO",
        .worker_threads           = 167,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "GHT",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "OSGQHUJPAVCOUINRCWIKYHQJACSYD",
                            .port                     = 26240,
                        },
                        .connect_timeout          = 1s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 39,
                            .base_delay               = 10s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "MNCSUGYVIKCJKANYDEHWDABOZPFVRGOQGXYENUMDMNGAIZSJAGFMTUSDBEGOIA",
                    },
                },
                .min_log_level            = data::severity::warning,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 8,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -9689.8185,
                    .deadline                 = 10s,
                },
            },
            data::backend_group{
                .name                     = "SEMFUEJHTHXGFXURGVMPTCNBDDBQIHXWMINTP",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "XCEHPRUTTCI",
                            .port                     = 13920,
                        },
                        .connect_timeout          = 5s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 75,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -5018.7194,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "OKVXWQSE",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "PLWJBATUCPCXJKECCORLXBXXWEZKLCVPCNZAPSATVMMSATCCCUDINXKMXWS",
                            .port                     = 29999,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 54,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -3795.3002,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "VPIALJEVTGQFYKVOPHKMVIGUNZZYGGMHSKGEEPLBWCIFDOPIG",
                    },
                },
                .min_log_level            = data::severity::error,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"WTOK", data::threshold_rule{
                        .metric_name              = "BITB",
                        .warn_at                  = 3565.0943,
                        .crit_at                  = -4378.593,
                        .evaluation_window        = 5s,
                    }},
                    {"AUEMOG", data::threshold_rule{
                        .metric_name              = "I",
                        .warn_at                  = -5251.8198,
                        .crit_at                  = -7182.5095,
                        .evaluation_window        = 5s,
                    }},
                    {"DURUU", data::threshold_rule{
                        .metric_name              = "CVGGPIFWAYPRWBFHIYLRWQQTYFMZWHCNXMEOOGUAMRSUQZKOKUG",
                        .warn_at                  = -8020.7071,
                        .crit_at                  = 7323.1671,
                        .evaluation_window        = 1min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 24,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -3802.8479,
                    .deadline                 = std::nullopt,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"LQ", data::routing_rule{
                .pattern                  = "OKRNY",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 2s,
            }},
            {"FR", data::routing_rule{
                .pattern                  = "ZEPEQXQVWOPSWCYHOQRJX",
                .backend_names            = std::vector<std::string>{
                    "RIJVMTGJERQISPGNRDQATMARBQMRZSDP",
                    "RONZMIHPPE",
                    "PQKDGNTAIEWYABGEHAVJKXLHTPDPXSDQTIWGWQNAMUNQTFRGURUGQGRTS",
                },
                .timeout_override         = 200ms,
            }},
        },
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("GYGDEHEXCIMDNNRZWEGMUVZADGSVLLDWQUYKQVGZCPDABYRTQSPEGFDGFFJ", 92689, true),
            std::make_tuple("OCYDKMONQLNGTLAUWBGFNOLXLMGTFDQZAKCZWUMSTGQSKZYIIDXXYFMEKRWL", 76726, false),
            std::make_tuple("CZKJPDALUTBHIVJKGVMSFRCMQPUGWDYMSADTDXHIOMQBYG", 64800, true),
            std::make_tuple("KRRQNQSDUOZUCRTVY", 95534, true),
        },
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "NPNJQMTJLQJPUIRJVWXJAAYHSBUFNYVMBKXMBS",
            .port                     = 64799,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 5s,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
