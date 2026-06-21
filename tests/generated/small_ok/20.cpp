#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_20)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/20.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VZYEIVUDKSFANNCDEKPSONGGKUVK",
        .worker_threads           = 10,
        .enable_tracing           = true,
        .shutdown_grace_period    = 10s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "YJJWIFTD",
            .extra                    = boost::json::value_from("IWHHSHBAZUTJIEWUKTXOEUIRNFFM"),
            .log_level                = std::nullopt,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
