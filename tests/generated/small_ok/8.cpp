#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_8)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/8.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "MEGWBCE",
        .worker_threads           = 4,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "AWIQNPM",
            .extra                    = boost::json::value_from("VIDCMTMDVBKHWCPUQGSZETC"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 35,
                .base_delay               = 10ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 50ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
