#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_3)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/3.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "RELTPUS",
        .worker_threads           = 17,
        .enable_tracing           = true,
        .shutdown_grace_period    = 1min,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "PRRPMUEHUEQMXAVYCFYSBJYAIPTXMWZ",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::error,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"EP", data::routing_rule{
                .pattern                  = "VNYUJN",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
