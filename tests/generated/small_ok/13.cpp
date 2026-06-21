#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_13)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/13.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VVZFUHVE",
        .worker_threads           = 168,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{
            {"AIECZZ", "IOXNEZILHPYRSNVLNUKUDLTZUIWO"},
        },
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "QLILOI",
            .port                     = 14549,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 25ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
