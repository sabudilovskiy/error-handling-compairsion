#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_19)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/19.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ZQDQGMLQJSETIDINKIDYK",
        .worker_threads           = 229,
        .enable_tracing           = true,
        .shutdown_grace_period    = 10s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{
            "",
        },
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
