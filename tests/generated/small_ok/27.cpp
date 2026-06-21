#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_27)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/27.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WIJGCCIRKILMFHHPCXUS",
        .worker_threads           = 72,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "TUHWQEDMYJXZBYVQCFOWEIRBFUAOYE",
            .port                     = 2723,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
