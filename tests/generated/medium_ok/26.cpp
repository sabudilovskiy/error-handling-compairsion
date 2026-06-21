#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_26)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/26.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "GVGNTRBEYYPBXVTQFUNHXNW",
        .worker_threads           = 216,
        .enable_tracing           = false,
        .shutdown_grace_period    = 10min,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{
            {"PYMLHS", data::routing_rule{
                .pattern                  = "",
                .backend_names            = std::nullopt,
                .timeout_override         = 25ms,
            }},
            {"UA", data::routing_rule{
                .pattern                  = "VRKKVNNWGBIGTM",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"CE", data::routing_rule{
                .pattern                  = "WYBBNGLTYCRKDNZBN",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"VH", data::routing_rule{
                .pattern                  = "EVILZYTYVWNLQPTMWBBESAQDT",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"TBW", data::routing_rule{
                .pattern                  = "",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
            {"DCT", data::routing_rule{
                .pattern                  = "AVNRAZIPKUURXMADDGOHJHETQMM",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"AE", "KCGIKNPGVPHA"},
        },
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{
            "DERXEB",
        },
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"BBMPRD", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
