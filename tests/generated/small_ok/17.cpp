#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, small_ok_17)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("small_ok/17.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ZJLJFYWWRVIDAHMX",
        .worker_threads           = 19,
        .enable_tracing           = false,
        .shutdown_grace_period    = 1min,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "RRZVGKRDWUCJNCQPUTEVZNQKANLS",
            .extra                    = boost::json::value_from("Y"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 11,
                .base_delay               = 50ms,
                .backoff_multiplier       = -866.6886,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "IG",
                .extra                    = boost::json::value_from("RRREIVJLKFKDSSZIKABYLAO"),
                .log_level                = std::nullopt,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_34", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WP",
                            .port                     = 1,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 32,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    }},
                    {"ep_33", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "VDGBRJZKZKBFNCWYJIVMPCRCRUHHRI",
                            .port                     = 12523,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 1,
                            .base_delay               = 2s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    }},
                },
                .tags                     = std::vector<data::tag>{},
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::nullopt,
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
