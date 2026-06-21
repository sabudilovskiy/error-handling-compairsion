#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_21)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/21.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WNUJPGZPZQ",
        .worker_threads           = 47,
        .enable_tracing           = false,
        .shutdown_grace_period    = 30s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{
            {"HWB", data::routing_rule{
                .pattern                  = "XYNTOBKRPWDULAEXCDZAOFRXKMP",
                .backend_names            = std::vector<std::string>{
                    "HCYGGVZVYYSXCDRPRMGKERNJLOQMKP",
                    "C",
                    "PAPCRTXQHSTKRTDFVFULKLYTJHDFCFYNLFVBVQVHNFXSA",
                },
                .timeout_override         = 10ms,
            }},
            {"FRC", data::routing_rule{
                .pattern                  = "NYXPBJBIVJBNHFMCKUEEXXPBIEUQ",
                .backend_names            = std::nullopt,
                .timeout_override         = 10s,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"TYNP", "PJERSIEYXAMVEWAISKUHSNIVMYZEEEDMDFAUO"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("JRKMPHTFFFMGWXRYBT", 71087, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "CMYSFWHIWTKXBHMEJXJQZRPSDRTBQ",
            .extra                    = boost::json::value_from("KQJJWTQYRGCTKGLCKVNDCUCUZYOQTAVUWOPQQM"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 3,
                .base_delay               = 100ms,
                .backoff_multiplier       = -4488.3529,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "UCBPFPLWTGYOUU",
                    .value                    = "VXTWVIHPPMJTMQWAFKGJMWECRFCQJTMXXODFWNGVKLUSVGIC",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "EVQGHTWIWMFMOMNO",
                .extra                    = boost::json::value_from("IVFVMTIDGGBLZUWLACQSBMTOWOHAREDJGOLALFE"),
                .log_level                = data::severity::error,
                .retry                    = data::retry_policy{
                    .max_attempts             = 5,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 1037.9719,
                    .deadline                 = 1min,
                },
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "CNXYVGEBPQTRTPPVZVKEIELJJUUAZCVCFQDVG",
            .port                     = 23605,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"PIVZUM", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "LRINGW",
                    .warn_at                  = -6129.3067,
                    .crit_at                  = 9080.1222,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "QBXLTRUUUFAWLP",
                    .warn_at                  = -430.199,
                    .crit_at                  = 7283.9004,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "BGVYUTRTDJMGOWZLA",
                    .warn_at                  = 8264.1212,
                    .crit_at                  = -6532.9779,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "XFFRQNGHQRJYOXYLCHMTFLRV",
                    .warn_at                  = 6299.4931,
                    .crit_at                  = -2755.6113,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "SYAVXGXDGRQLQJDFHVNTUOYPYGU",
                    .warn_at                  = -5756.0162,
                    .crit_at                  = -6312.1613,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "BROGBZKSOZJXEXHFMEMBAYVSJSOGPH",
                    .warn_at                  = 7397.4028,
                    .crit_at                  = 1066.7157,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "E",
                    .warn_at                  = -3.314,
                    .crit_at                  = -770.1221,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "WCIYDLUIXZOZDGTKCXJHUEEYIDVTJUGQGEPYWP",
                    .warn_at                  = -5642.7203,
                    .crit_at                  = 3728.1595,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "GEJBIWNBDYTUQAXHTWOPQRR",
                    .warn_at                  = -2522.0268,
                    .crit_at                  = 2724.2768,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "YOUUOXQSHOZHAUOHYSSXCL",
                    .warn_at                  = -197.791,
                    .crit_at                  = -6698.54,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "GBOFGEATFEHRDFRUDUMDY",
                    .warn_at                  = -7521.1273,
                    .crit_at                  = 4008.7044,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "HTSDHGNSZQWVAMJKZVLZNBSPBMYZSPFBUCYIYPXIQFJKLVPUI",
                    .warn_at                  = -2213.7372,
                    .crit_at                  = 6024.1542,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "KZEYX",
                    .warn_at                  = -7012.5705,
                    .crit_at                  = -3832.1691,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "HBLXNQWDUPGRLXGBPUJTKNFYANQG",
                    .warn_at                  = -6745.497,
                    .crit_at                  = -5646.8007,
                    .evaluation_window        = 5s,
                },
            }},
            {"UOH", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "MGIWTFWLPEKLUEJVYYWVXCBHXJKRMZFXM",
                    .warn_at                  = -9444.2818,
                    .crit_at                  = 1557.7582,
                    .evaluation_window        = 5min,
                },
                data::threshold_rule{
                    .metric_name              = "YXHZDAGMGPUWVQGFUNMVJYEQMBEWAYCFODYPBCUKDFQSJUOWJNYMXRDILAWNZIO",
                    .warn_at                  = 2503.9759,
                    .crit_at                  = -3747.5629,
                    .evaluation_window        = 15s,
                },
            }},
            {"UULG", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "IZZFAKBFZLWGQABZAFKSVRHEKTWFTYGDFXJNIKGXMMZZJXXBHJKH",
                    .warn_at                  = -3915.5332,
                    .crit_at                  = -1333.1852,
                    .evaluation_window        = 2min,
                },
            }},
            {"OWWZF", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "BMPCWRPFRDTZAXYAJQEXUAUCOCSNLTMZOPXIFSJ",
                    .warn_at                  = 2787.4215,
                    .crit_at                  = 9443.2333,
                    .evaluation_window        = 5s,
                },
            }},
            {"UKRIY", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "DLRQBCUGHOKPJQHVRPIYGVSKKTSXPRNYHU",
                    .warn_at                  = 7957.221,
                    .crit_at                  = 7400.1921,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "FDXFIYPNTRIHQICTUZUDJSCGRFWAQYRQZZ",
                    .warn_at                  = 2742.1277,
                    .crit_at                  = 2809.4614,
                    .evaluation_window        = 15s,
                },
            }},
        },
        .warmup_delay             = 50ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
