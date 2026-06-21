#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_7)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/7.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "EMUBCRDLSB",
        .worker_threads           = 192,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
