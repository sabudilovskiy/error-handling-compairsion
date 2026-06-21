#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_23)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/23.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "JCASJNMQLEXGIOAHTOADCWPNAQUXNLYBGZBSLVFTGXLSYLSJVKSCPFWPSZO",
        .worker_threads           = 173,
        .enable_tracing           = true,
        .shutdown_grace_period    = 1min,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "SDCDNBSISISKDLJRJYORGIEDTZDWZPHKR",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "DMFOBBUNMAFZHVAHZXBROXCLAZMPGBCIORGYOJGCDRQUFWR",
                            .port                     = 36568,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 10,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 5238.4791,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "CWUXHRJNNJYRTRBJDAUEKRXNHFVCKRWRDHRPZOWIAKMAZEXMGZV",
                                .value                    = "U",
                            },
                            data::tag{
                                .key                      = "CNWIPTWRXRFQRJICHBPMYAVOTNJ",
                                .value                    = "NLZJIKFMBNVPYRIRIWCMGIEQLDTODISYOABIZDHYSUP",
                            },
                            data::tag{
                                .key                      = "IGLSETYCFXQMTVLJCTWUTFBDXFAETVEXJPWJSZYBBTYSDKAELCF",
                                .value                    = "GNKYTHRSNVLRUHXRXJOVUELMYJBPMLXGYURFGKNNBBKXNPFSNLHKBV",
                            },
                            data::tag{
                                .key                      = "MLSPARTUNTFOGVYNCOAMUMIBXBNMLXVWVIXFETCYSZQORYDCNPVE",
                                .value                    = "ZJDTAYQTGRUGLZJIWJNPRZRJKXAHZVSZRECWYEVDWJIDSCCZBXPUBQIIRSNUUA",
                            },
                        },
                        .tls_cert_path            = "XVCVEFGPBXVEIATZMYBSYSNZBUAEEZALUSQRNAPCOKJVWTB",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 16,
                    .base_delay               = 1s,
                    .backoff_multiplier       = -7780.9683,
                    .deadline                 = std::nullopt,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"USTZGC", data::routing_rule{
                .pattern                  = "TDSWZYEDQNLCGVQMK",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
            {"OGFRR", data::routing_rule{
                .pattern                  = "KBSSDYEXECRLUBYBOBFILXGOWYVKJCZNPZZDMRVMMUXAFSUCAB",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"XV", data::routing_rule{
                .pattern                  = "UKMUWENJEQIQRTUZTSTUQMVXFTIMXKXEAKZJRCPPLWBYNVYCI",
                .backend_names            = std::vector<std::string>{
                    "LNHTCUQWIIGGVFREPXKXYXNKLRHSNXBXMKSZXDC",
                    "DNJELFD",
                },
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::nullopt,
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "MTXTJQBYUZFXUBORMUUBEPAXLZUOYHREVWGW",
            .extra                    = boost::json::value_from("ZS"),
            .log_level                = data::severity::warning,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "FTNNZGDWGMANDXIFIHGHAUVJQGNCFNGGB",
                .extra                    = boost::json::value_from("GCXAAFLBXSAQNWKSPUYCHIBYEADBGDCHECWOQIPPQWZZBBRVFAK"),
                .log_level                = data::severity::critical,
                .retry                    = data::retry_policy{
                    .max_attempts             = 82,
                    .base_delay               = 50ms,
                    .backoff_multiplier       = 2165.8834,
                    .deadline                 = 5s,
                },
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::vector<data::tag>{},
                .nested                   = common::box<data::scope_override>{},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "FPLCGZJWKUVTXJJZYHNHUBBCKMUSMWNHSCQFHGNWDRCOSVBPICMDQZHBKZF",
            .port                     = 34958,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"IFGKEE", std::vector<data::threshold_rule>{}},
            {"XWPF", std::vector<data::threshold_rule>{}},
            {"GR", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "LEOASRTXPGHZYROYROCDOLUZRNKCYHKFVJKG",
                    .warn_at                  = -9674.7197,
                    .crit_at                  = 1350.2557,
                    .evaluation_window        = 5s,
                },
            }},
            {"CFT", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "ZLCHCRCGMQDKHKTWDHLKESHOEWJYIDKWPHFSXXNRSIQGTFVT",
                    .warn_at                  = 4286.3183,
                    .crit_at                  = 2471.8091,
                    .evaluation_window        = 5s,
                },
            }},
            {"MAP", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "CTXZCAJTFANEPXKMJVSYZULYMIWLYGWMEUNKMHEDWXNE",
                    .warn_at                  = 3789.8489,
                    .crit_at                  = 8356.1285,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "WZYZFWAOICHSAEUSSJLDXSHPIDPHZNPOX",
                    .warn_at                  = -9921.6418,
                    .crit_at                  = -6183.4382,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "HNWE",
                    .warn_at                  = 3643.9301,
                    .crit_at                  = -2926.9498,
                    .evaluation_window        = 1min,
                },
            }},
            {"VWUA", std::vector<data::threshold_rule>{}},
            {"XGSLGP", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "KEZHWLSAHJMAOWZQHFAU",
                    .warn_at                  = -7598.675,
                    .crit_at                  = 6761.6721,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "VEQMNJVVOCKHSBUBRLDMQOGGEHFODJQIIP",
                    .warn_at                  = 9737.5904,
                    .crit_at                  = 6056.5782,
                    .evaluation_window        = 5s,
                },
            }},
            {"USLLT", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "BVGYZRMOWCATNNBCRQOKFSZUEWJPCAAKJBPPLLAXOAJSHRZKCBXC",
                    .warn_at                  = 9433.287,
                    .crit_at                  = -5262.4432,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "RIMIWOOBBHDYEKT",
                    .warn_at                  = 9933.6884,
                    .crit_at                  = -3422.6676,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "OAZEMTLXZSHEYNIFZCZENCJHNQIUTYBKKQNKHJAGIBQHPYFBQTXZODEWF",
                    .warn_at                  = -9617.086,
                    .crit_at                  = 8533.3065,
                    .evaluation_window        = 1min,
                },
            }},
        },
        .warmup_delay             = 50ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
