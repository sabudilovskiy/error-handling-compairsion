#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_5)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/5.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "XLZWXUQAOYHUBFDLPHM",
        .worker_threads           = 139,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "YMFYZCETTOEEAAGYGFFJKGRVUGFWG",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::error,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"EIC", data::threshold_rule{
                        .metric_name              = "TSATVWKCJL",
                        .warn_at                  = 6370.3615,
                        .crit_at                  = -385.0963,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "AXLMARZNLMSAOBWFTGDYHOLQLQIYODS",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::warning,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 94,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 2216.5508,
                    .deadline                 = std::nullopt,
                },
            },
            data::backend_group{
                .name                     = "RCJVKJFZCUEXWJPFXBCTRMBHXTLIO",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 49,
                    .base_delay               = 1s,
                    .backoff_multiplier       = 4633.2885,
                    .deadline                 = std::nullopt,
                },
            },
        },
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
