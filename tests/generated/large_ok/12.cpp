#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_12)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/12.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VQVLEMALPIUZOWTHRAVTEOLFKGBSGC",
        .worker_threads           = 131,
        .enable_tracing           = false,
        .shutdown_grace_period    = 15s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("NODVNERKTRFWBRFQCMTNVTPPTMRAUXCGZVILLWMVJDIHKLLQSZYQFAMNBQAHVNB", 38824, false),
            std::make_tuple("FCWIBNIPLTUXBQOLGKJOPWPHFORLFGYXHTA", 94769, false),
        },
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "DLRQEAKZVIUDHZQ",
            .extra                    = boost::json::value_from("PULIVOXFOJTBIKQUWOWZGXJQIAVAWAER"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 24,
                .base_delay               = 10ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = 10s,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "MZGSRLLUXMSFAWWEAZBCNRGZMZDWLGJIZWVRP",
            .port                     = 40770,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"SHCNL", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "EVCXJJWFYVVUNLFAGPTOPFBVTKOHKDHALLIGWNJHQEQ",
                    .warn_at                  = 8053.7238,
                    .crit_at                  = -3349.7041,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "WHOOZBYHNRWYZMQVOVBDRSVJLYXAKYPL",
                    .warn_at                  = 2650.6868,
                    .crit_at                  = -6592.8773,
                    .evaluation_window        = 5s,
                },
            }},
            {"BNZLJ", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "JMZTKEEIUBVTZZMNNTVIKNYMPMMZFFZGIDIQBUXW",
                    .warn_at                  = -2824.1156,
                    .crit_at                  = 4692.9735,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "GXARJBAZFGFGWZJGFYJRATDLVPRGODQAUEZMQPUJOLUMNQAWIAEPYLW",
                    .warn_at                  = -7939.3415,
                    .crit_at                  = 6865.6957,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "LYCELBHDNCZBAHADVVSTXUXASHSZPUGOYKNURKZHMCUTKBZYVLEJDPTEVIAGH",
                    .warn_at                  = -7535.5878,
                    .crit_at                  = -1281.4585,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "TMYZPKGTURTLCHKMITSE",
                    .warn_at                  = 6769.5399,
                    .crit_at                  = 3324.513,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "DDXSUPFLRETTSIMKJLLKQ",
                    .warn_at                  = 1965.9042,
                    .crit_at                  = -8576.5584,
                    .evaluation_window        = 10s,
                },
            }},
        },
        .warmup_delay             = 50ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
