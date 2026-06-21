#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_28)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/28.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ERTWFHE",
        .worker_threads           = 163,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "TGGANHCDNKWEFQQWXVZITHVOEGAYJUVICQRIXDSNFGLCBNYZPLFMZIMQVVFHF",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "XWRNAHGBKLVWYMDPEXPQGRZOSNFVNHOJOHHBA",
                            .port                     = 28541,
                        },
                        .connect_timeout          = 100ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 25,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "CHMGRDTEDVUJQTUOCEYYGFZQCOQKQPXZWMMYMWCKHZQ",
                                .value                    = "SQLQCKYDUYMJMOEXXCMHB",
                            },
                            data::tag{
                                .key                      = "UGAVYETSPAOAHCDNBBXIPKKMLGYBZY",
                                .value                    = "LWSYGAKQDDLCCTGSFRIVOMUPXQFHLMSIGMBIPQHLKUJISLQENKBRKWZH",
                            },
                            data::tag{
                                .key                      = "FKRFLTPAWMABQKQDPJIYVTINIDMCPFCOXJKVY",
                                .value                    = "OYUFOITMCQNPMZRTIGDDNOYGGTFIISEHX",
                            },
                        },
                        .tls_cert_path            = "QFHZPMYYNKXUSTHCZJLNAIMDMIZVFBXHJPUHBH",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "GKYMIDDR",
                            .port                     = 14737,
                        },
                        .connect_timeout          = 1s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 19,
                            .base_delay               = 1s,
                            .backoff_multiplier       = -3265.3199,
                            .deadline                 = 2min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "IWPUVSMIWLRPEIWCKIABUDCUYENRFAOJGAMRLGKMRJXLGDKTKY",
                                .value                    = "BWURAAVWBRQWUURFMQVRCAIUZOMMRYWRHD",
                            },
                            data::tag{
                                .key                      = "LWUEMKBCWYDBDUETVJDQYVUHVMPWNWSVDXKEIEWGINEAGIDKRIB",
                                .value                    = "DCZDGQVEZYSAPAZSUL",
                            },
                            data::tag{
                                .key                      = "",
                                .value                    = "GENFDPSKSYVKDBOZRYCYFACLAQBLZJZDC",
                            },
                            data::tag{
                                .key                      = "",
                                .value                    = "FMQFSMEJACAYCLHQEDYBSNTNIRYUIHGAKNJKIEFBSJCZLEHHFODHLAUV",
                            },
                            data::tag{
                                .key                      = "QGLAJPNQSWALJGTLCST",
                                .value                    = "CLYYKBISKPWCUAZBKKFHPGEBDJDXFPDUXTSHTUBVOOPTOM",
                            },
                        },
                        .tls_cert_path            = "CZULLQTPSNTMWPHQFWEYVLFTKJFOMGBGJRWYUOGHIJRWDMKJEYQMOQWW",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YVXVDLWGYVUIPBISMCEHOPYYTFKAJOQAYYKNYOFYXZF",
                            .port                     = 21380,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 47,
                            .base_delay               = 1min,
                            .backoff_multiplier       = 958.8387,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "PGIYRKOOOCERYQJVYYJDWTUPIVVZOFKHXYBPIYRDIEYXOATZHHPUNFIPKBOEQI",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"BPJ", data::threshold_rule{
                        .metric_name              = "NCNFUWPTOZREDIXTXMVYWADLLKBKWHQREBFEBLSBFKEFJYES",
                        .warn_at                  = 1531.3448,
                        .crit_at                  = -5505.0782,
                        .evaluation_window        = 5s,
                    }},
                    {"DPCER", data::threshold_rule{
                        .metric_name              = "QLLUIFZDAFPDAGIVWLRSOPWMCJNGVIAMHUVAIOHIFWAPUXJHXBKSTXXIZDVXOFZ",
                        .warn_at                  = 3670.175,
                        .crit_at                  = -29.3933,
                        .evaluation_window        = 15s,
                    }},
                    {"BJWYI", data::threshold_rule{
                        .metric_name              = "MVLEOVHOIEFYPHCZYRUZEOTQUZWRKRZSTLFMWFWQSJJKQHR",
                        .warn_at                  = -3500.3049,
                        .crit_at                  = 8878.6266,
                        .evaluation_window        = 15s,
                    }},
                    {"YLFLEU", data::threshold_rule{
                        .metric_name              = "ODPHZDUARBOYIAQMNIKNDTNKFNSQZUTDIOONRKRKGHIPZOWESQGLZSZ",
                        .warn_at                  = 5096.6777,
                        .crit_at                  = 1604.6365,
                        .evaluation_window        = 5s,
                    }},
                    {"HLQBTR", data::threshold_rule{
                        .metric_name              = "URGRXPCNHMCFGVFZHMSTBEANMDNHDEXXMXYCSFPCIBPPVFODAGNFDKTKRHLPEP",
                        .warn_at                  = -7604.1122,
                        .crit_at                  = -8002.0684,
                        .evaluation_window        = 5s,
                    }},
                    {"QOGQ", data::threshold_rule{
                        .metric_name              = "NORAVVFUTDFPRSLEKJFYRUDZMCADTGHSQMIVJDIWSYNKAQN",
                        .warn_at                  = -1194.3086,
                        .crit_at                  = -7150.4938,
                        .evaluation_window        = 10min,
                    }},
                    {"ALHGV", data::threshold_rule{
                        .metric_name              = "LSHQQLYI",
                        .warn_at                  = 8333.1833,
                        .crit_at                  = 6315.734,
                        .evaluation_window        = 1min,
                    }},
                },
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "WYIDLNYRRYATKVVUIOHMOYNY",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "KTNLXKVTSLYDERXJWGOKSJIZIZKBQWFCNGIFBJVMKMOURYSXWJST",
                            .port                     = 38225,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 61,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = 2183.5221,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "HWPJEVNTIXTGICLEASJELOZUANBIWAQQWWTTCCIARK",
                                .value                    = "AVWLTTKLCRTQOUKECFWLVLDS",
                            },
                            data::tag{
                                .key                      = "JLLWTUFNKCGAZQIYIKME",
                                .value                    = "GDRZGDFPL",
                            },
                        },
                        .tls_cert_path            = "PTLXPMGYTPWXEXZRUPLVQQYMKWHICAPVVZD",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "RRKXMPE",
                            .port                     = 9907,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 51,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 2min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "LVGRSZEBXUDVFOIFGJJWIZJHLSSP",
                                .value                    = "JDQKPSFDNYWTWLIVUDRYSNXWWUQDHHUDNVGWWLAPTCNXSISX",
                            },
                            data::tag{
                                .key                      = "GZS",
                                .value                    = "AFIIIUERYDMJEAACNPBOTPDSBZYVFSZLYVVODXHYUUYTDKSCUULPPHBLOUCY",
                            },
                            data::tag{
                                .key                      = "SSRPBGXYLVL",
                                .value                    = "KBLOKYANYBSMXYFLBLZEKRJRZVUUEQVLMQIDTOESBCCVTTVBAHGGHBYVUCDPL",
                            },
                            data::tag{
                                .key                      = "APRKDPRZYWF",
                                .value                    = "HSPRWEIXOEJBYOTFMQQWMOYBMSTODIWIRSRIZEK",
                            },
                            data::tag{
                                .key                      = "QYHWMQIZNMVZJJQXDUISWP",
                                .value                    = "SYUICGCVAUJJPPTNTDVGNLYXQRGXHUWWDZMPADYBLZ",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "QYVFYPUYJUGYFFHWBCRWQNFMTAMAHZZIHRKVIPVNWXSWRWDLV",
                            .port                     = 33320,
                        },
                        .connect_timeout          = 100ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 64,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 1min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "OEJRJEXDAYEPGCCAHAZFCDDSDXCTT",
                                .value                    = "BGMAEFZGLDHIVYTURCQIOHFLSVYWRWJRPUMPVJAQLNMQQCSZGEHNIUR",
                            },
                        },
                        .tls_cert_path            = "WGGCEHVESBLATFTAEAJIHZFCFZEVPXBCBXZVSXDKYQCBBADEC",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "FTHUTTVXYBOIOCWHIUBFHXVJITOJVCXDERLDQBGAVPMF",
                            .port                     = 28575,
                        },
                        .connect_timeout          = 5s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 60,
                            .base_delay               = 1s,
                            .backoff_multiplier       = -7619.4985,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 18,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 10s,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::unordered_map<std::string, std::string>{
            {"LETTCW", "UCSZNPZTGAZNWJGIDHLONYKASRMABW"},
            {"DBWAM", "XWIKBHXPAIYGGRNMKMVUZ"},
            {"OHWMQ", "QND"},
        },
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{
            "XUEWEWKLFWZLGMIIPKDTUGMADYFTAQFWTMBDIVEQUGSSCRGQYUV",
            "YUYZAQPEXOCUQGNUWMZJTCSEPPCRMKBCEPHBLVPAZHXUXEYTAVLXIXHCEGOJ",
        },
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "UTVAZZZTZZNXGVOVNMWETBULPMQHMFG",
            .port                     = 11983,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"QY", std::vector<data::threshold_rule>{}},
            {"EOO", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = 500ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
