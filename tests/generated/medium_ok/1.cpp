#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_1)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/1.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ZYCI",
        .worker_threads           = 31,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "MNTYYAWOIXZHSDK",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "",
                            .port                     = 35481,
                        },
                        .connect_timeout          = 10s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 38,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "HYOJANR",
                            .port                     = 60435,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 63,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = 4862.9332,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "PQMSBPHXZMNVFLRWYV",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::debug,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
        },
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("TSSMUFFQHAYGRRHMQLSLOI", 65921, false),
        },
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 500ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
