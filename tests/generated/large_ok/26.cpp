#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_26)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/26.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "GVGNTRBEYYPBXVTQFUNHXNWGZWAVHEEGTPYMLHSAAXJRRDQ",
        .worker_threads           = 12,
        .enable_tracing           = true,
        .shutdown_grace_period    = 10s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "QEBDCERRWYBBNGLTYCRKDNZBNWO",
            .extra                    = boost::json::value_from("BLDVHZCEVILZYTYVWNLQPTMWBBESAQDTWPBSF"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 2,
                .base_delay               = 10ms,
                .backoff_multiplier       = -1438.1222,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_5", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "VNRAZIPKUURXMADDGOHJHETQMMTZKWCQUCXEWBAEMHKCGIKNPGVPHAQW",
                        .port                     = 6571,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 21,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -7313.559,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "FQBBMPRDNX",
                }},
                {"ep_44", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "BRAJINGVQO",
                        .port                     = 53705,
                    },
                    .connect_timeout          = 200ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 33,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 15s,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "BIMBYBTZJFTJHHSIQWNWTATWKYGOJD",
                }},
            },
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "BXVTYSZZCEMVUWCYWWLDPMPYUGYNITIYDUZPUCLOHIEWDJYRHXVSL",
                .extra                    = boost::json::value_from("PBSYTODOPJHWOXOPGFCICTHSXVZGYBDIYVUHSODFZLSNONQGIGVDWTYERMJPUCO"),
                .log_level                = std::nullopt,
                .retry                    = data::retry_policy{
                    .max_attempts             = 4,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 7107.2926,
                    .deadline                 = std::nullopt,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "WSVAVKXYNWAXALFXLLHSEQBXSQLNRCYEXAHQWTPPFZESRDZYMMIBWJN",
                        .value                    = "PSMSGBOIFYUHEZELSALRPTDFLLZYKUMPIJNKN",
                    },
                },
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "URIMIPPLWJVSBLMSIZVFVHTGPVGCCTLEGPKBWWPI",
            .port                     = 53437,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"RVB", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "RBXWKKGLMNTJBCCVKLSZCOQAIARUIDIYOLJOJOKJIUFJIPTATLDCZLBCWBWYM",
                    .warn_at                  = -5301.3187,
                    .crit_at                  = 4183.0368,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "YSQRVHPJPDZJSFCAUDAJESVETV",
                    .warn_at                  = -3248.1201,
                    .crit_at                  = 9874.6844,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "BQJVVORHGQG",
                    .warn_at                  = 1185.4475,
                    .crit_at                  = -6329.9912,
                    .evaluation_window        = 15s,
                },
            }},
            {"NS", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "NLF",
                    .warn_at                  = -4798.6909,
                    .crit_at                  = 5757.5427,
                    .evaluation_window        = 5s,
                },
            }},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
