#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_18)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/18.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VOKHG",
        .worker_threads           = 220,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "ZHFHGXLSQGZVYPGWJIAKMHYXMRLSSQ",
            .extra                    = boost::json::value_from("ITWJRDJP"),
            .log_level                = std::nullopt,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "ZNENQPSDWGSIRKZZVRPC",
            .port                     = 7790,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
