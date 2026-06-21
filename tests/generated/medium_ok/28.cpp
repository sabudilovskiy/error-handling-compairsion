#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_28)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/28.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ERT",
        .worker_threads           = 182,
        .enable_tracing           = true,
        .shutdown_grace_period    = 15s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{
            {"ETG", data::routing_rule{
                .pattern                  = "NHCDNK",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"QWXVZI", data::routing_rule{
                .pattern                  = "VOEGAYJUVICQRIXDSNF",
                .backend_names            = std::vector<std::string>{
                    "ZPLFMZIMQVVFH",
                    "GXWRNAHGBKLVWYMDPEXPQGRZ",
                },
                .timeout_override         = std::nullopt,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("ANNVRIOEVQQAUOLVLCHMGRDTEDVUJQ", 60691, true),
            std::make_tuple("FZQCOQKQPXZWMMYMWCKHZQKS", 57585, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
