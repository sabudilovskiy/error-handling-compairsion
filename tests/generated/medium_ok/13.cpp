#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_13)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/13.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VVZFUHVE",
        .worker_threads           = 222,
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
            .port                     = 39681,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"RHSHG", std::vector<data::threshold_rule>{}},
            {"UUOMA", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
