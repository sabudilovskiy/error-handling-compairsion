#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_9)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/9.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "LIEFVAKQOTCKRTWBXMFWOXNFFHBDE",
        .worker_threads           = 130,
        .enable_tracing           = false,
        .shutdown_grace_period    = 10s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{
            {"JG", data::routing_rule{
                .pattern                  = "XZNCYIGMIKZBGWANBMPEAHNXDTADYSGGKACERAQCSPR",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
            {"WS", data::routing_rule{
                .pattern                  = "TXBBIRVTE",
                .backend_names            = std::vector<std::string>{
                    "BDWMHFTQBXLVQSSYWCLDSLOGMGSXAMZTKAND",
                    "KCJUJDQZBAMYRZNPLWYHSXCNUHDY",
                    "RLEVJFWIABZFIFDTEABBOGZ",
                    "ZLJEPRIECXRJWDCNOEWRYZMSZFVWIYTTPLDBIQE",
                    "CFYZHAGFPOSRRMCFRPSIRCUASSNRJQQRUZCUSRJC",
                    "DDWPOBPUXBVTALHOHLXSTPHBTTCTBVNNSCCGBTYFCCALTP",
                    "WYCKCZKAOOSEMPEDLVHOYEGHDDBDCU",
                },
                .timeout_override         = 200ms,
            }},
            {"GLUCHA", data::routing_rule{
                .pattern                  = "QVGAOITADQZNBIPK",
                .backend_names            = std::vector<std::string>{
                    "IEJ",
                    "LZMAJDAKOHN",
                    "LMNGCIJOOTSOOMFKMBKCFKRAGGWLVEU",
                    "TTYVXMGWRYKCAVRNPHXKYZQQDOWAJRGCHAKBCEKFWDQZMUMMSQEQWLLIGKMSFZ",
                    "SFAJVAIPQYVNYCIJEQOPVHFKEXVLXTBRILASFRYVYDOEKGXRENGQGVS",
                    "BYWLPLBLZZMONUXGRDFSCLIHYPQFYQAVRKVHFABWSSGVKJWEKJMBCM",
                },
                .timeout_override         = 25ms,
            }},
            {"FESW", data::routing_rule{
                .pattern                  = "VZQSMYZQEMBM",
                .backend_names            = std::vector<std::string>{
                    "VUTDQPQIILTYLRAGXBUQOJDGAGOXDIJJHAFVUNILULKRFRV",
                    "GCBGAIWOLLRYWCDWNWNFBHSEQSNLWVGULXQQNBFRKIOJJNZ",
                },
                .timeout_override         = 200ms,
            }},
            {"XVVH", data::routing_rule{
                .pattern                  = "LOLCZNQXFCUDZWUKNPAJNCMIGS",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"HJ", data::routing_rule{
                .pattern                  = "QDSSAGOTDMQIWFCQQVJEXNFGJPJUXPZYQUKVQYOBSRUWP",
                .backend_names            = std::nullopt,
                .timeout_override         = 200ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "PDSQAWJOWSCSWIYRFIAKQXOQYL",
            .extra                    = boost::json::value_from("FFWKWWKKPCZKWJDSIJZB"),
            .log_level                = data::severity::error,
            .retry                    = data::retry_policy{
                .max_attempts             = 41,
                .base_delay               = 25ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "YVJAP",
                .extra                    = boost::json::value_from("YBOXFFCIDDYFIULIHGWWVXGPSRGNWVIOHMWCIIEXXFYATTMEOPDTDZTM"),
                .log_level                = data::severity::warning,
                .retry                    = data::retry_policy{
                    .max_attempts             = 34,
                    .base_delay               = 500ms,
                    .backoff_multiplier       = 8607.0869,
                    .deadline                 = 5s,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_48", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "VORUAUOIVSKFLCJZGITFMDAHSEZAVWFTCUMENWWWI",
                            .port                     = 38544,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 42,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -6986.2368,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "UDAHZPRXFQVLIGFVKVAXHCGAYMWAXPAWVBXXGJZUJ",
                    }},
                    {"ep_56", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "ZGVQGCDCGKBOVFWSVISLDZRIYXIEBBLWCEY",
                            .port                     = 21534,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 27,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = -9485.5597,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "EUXSWORO",
                                .value                    = "XTOSPHGPIOBPSGEOFPDN",
                            },
                            data::tag{
                                .key                      = "OTDVBECLCIQ",
                                .value                    = "DQIONGZMGJUMQKLEGCBBKXSCZONULWTVAXKFYXOIBBYIOHAIMBGND",
                            },
                            data::tag{
                                .key                      = "DNTCQJLHAWPFNFBYLNMLJRRXAUWWNKUPAKGHDMLWM",
                                .value                    = "CLNPVVGLMHSLDJCNSJJOSGMGQVKNSLRKFYBCYB",
                            },
                        },
                        .tls_cert_path            = "DZTHSELVHSYT",
                    }},
                },
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "QEAAGQHYUVUMHBJDMB",
                        .value                    = "IYHQZOHFLLIYBAKJCUUTADDFJHVQXAYOXUULODMHEQSKVA",
                    },
                    data::tag{
                        .key                      = "BURQATBDYWKCKBDBUFVRBMTXGSTIXVRWXAHBFHGOCYRAGQ",
                        .value                    = "NCAJCAACIKRWMHMXCATTDMYFDDXYSFC",
                    },
                    data::tag{
                        .key                      = "GBKCGPSAGQLJKWPNXLWCLDKVLFJZVSEOEPOQLSG",
                        .value                    = "XCIPAFRDZ",
                    },
                    data::tag{
                        .key                      = "C",
                        .value                    = "HGQDXCYGONBAYSJKSUVECWBCPWUVPNRSLVWPRL",
                    },
                    data::tag{
                        .key                      = "RWYEYQPYOGEUQXNBCWUFUYEAXOZHEEIRQAQNFWEZNHNSUSGRB",
                        .value                    = "",
                    },
                    data::tag{
                        .key                      = "WDGKSOBBWVHETDJCUMJAVCLYCWZMGHMGKUZDPOLNKQTXRLXMYRWQHT",
                        .value                    = "KIENZSXFOIDBMSFSSKLAISCEOUQANGBNHYYYQOOHEVHVTZZTSVOLOVHCFYTKN",
                    },
                    data::tag{
                        .key                      = "TMTQMMOVUTCRJWQOFBCPVFGNQVUWURYRLAKGDMTH",
                        .value                    = "TDKBVHDOVXROMVNSUZG",
                    },
                    data::tag{
                        .key                      = "AUROCDIZOFLIGHNDR",
                        .value                    = "QGUINWBZKTBPRVKKUCCNEBNJTTYDKXSNA",
                    },
                    data::tag{
                        .key                      = "VUCMYQMIRCUZHVVUWMVSHLXWQ",
                        .value                    = "JNXZDVCVGJNQMMSBFXHDJMOWOPSSBTTBMFEJSQQXCBNANPHUWDBXIJHB",
                    },
                    data::tag{
                        .key                      = "RWAUJBMN",
                        .value                    = "TZFVMYIBJBUDRR",
                    },
                    data::tag{
                        .key                      = "HBTOIHFXDLUOPRXQMBDEPLXKUGCWTLPVODHDCNZRYYMWIFSODHYEPBRC",
                        .value                    = "KZXVYOIYPRMQFMHISXFZHXPJWAGDLHUYYZLSPW",
                    },
                    data::tag{
                        .key                      = "SEOKMFPYJIQCYPNOMMLHYYWBVYMNYWLPVCAROXIFETUIADBYMCHUFGKK",
                        .value                    = "QYSDXHDMVZXCKFMRFQDHHLIUYZZKSBIPYRJTSERUYQVLUNAEWO",
                    },
                    data::tag{
                        .key                      = "SYSFGEIBQRVSKXEUEHYBKZCRBCUHGTDAIHMLDDJ",
                        .value                    = "LPLUDCTTVKXYLTLPHUCWZUPDXIAUYXIXM",
                    },
                    data::tag{
                        .key                      = "XSLWKXVSNWEGPKCJAPRLSFLRWKZICMWQKAZXPWQUBQDGZHCV",
                        .value                    = "JRWQXUCFQUVRJZZQJORGFNLGPUOWYFRHHQBWZGFPSOMIKEWHIXAZDVC",
                    },
                    data::tag{
                        .key                      = "EXDBUAQLNRIEUGSW",
                        .value                    = "OKILXHVQMBMMKKVLGLPJGJAGOZFHXUSTONB",
                    },
                    data::tag{
                        .key                      = "ZYAQ",
                        .value                    = "FLSDLJSLPRUAOB",
                    },
                    data::tag{
                        .key                      = "ZOZXTVOGMWQPXNKITCKSWVFZXMPPRSAYAEHZJHJWFZNNOITFEFRJEGNTA",
                        .value                    = "QJSHPOFNQFWZYODMFTKOGKOPAWLXVKDJFHIWCTUMESQHHBLJ",
                    },
                    data::tag{
                        .key                      = "DVCSNMMMWJYOVWXXHBKERYEREWLMEWTHPLOSPRL",
                        .value                    = "QFKLLLSAWGQPWXOWYANOXKCXBUXGBIVVBFTOXWCNKQRUQBSNY",
                    },
                    data::tag{
                        .key                      = "",
                        .value                    = "QFWQEVZUXKUAZVUMXUITPSZONZRSBFYBH",
                    },
                    data::tag{
                        .key                      = "GQJSUGCCQLWIXWQNHPGEKSXLIEFKLBOXOMBBSSDRKJWXOMBIESL",
                        .value                    = "ZKJNMWPOIVLQHPLBVUOHBETCRBZFNZILPJS",
                    },
                    data::tag{
                        .key                      = "WWWKPWYGQOMZSXSRONCDHUQTDBZKKJTDZBJBJOLLDVHCIJFAVZBZBXYHLWT",
                        .value                    = "Q",
                    },
                    data::tag{
                        .key                      = "JWYHXXLFVLQVFUGQIWMCASEMCFCOXPWYUPMBLJLPBLQHUGRYR",
                        .value                    = "YOJOBUDIYZUCAVPTGKLRGIACBOAMQO",
                    },
                    data::tag{
                        .key                      = "YSEHXVXPJNERHGQETDUPCYIRVQOUVI",
                        .value                    = "UWXMSIZQZDXJMFUZACWUVSOQDVWNRQJYQUMOVRXDTYSUYPNQOBBMKDXFVZ",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "BNNYYSFQRJFHITHOXUHDBWXJIAAYRN",
                    .extra                    = boost::json::value_from("AJZFZJXFAJ"),
                    .log_level                = std::nullopt,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 97,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -667.4371,
                        .deadline                 = 5s,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_77", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "WOSJMCLEZDKKNCQZYBLTQQFNVMNLGTVDMHD",
                                .port                     = 57631,
                            },
                            .connect_timeout          = 1s,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 94,
                                .base_delay               = 5s,
                                .backoff_multiplier       = -8146.4663,
                                .deadline                 = 2min,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "HQJCIIDBBEPJOVQHBIJQCZIMPWSTITZNYMKGOSUDYVTFOXLJFIHKB",
                                    .value                    = "HITMSFYRRFDCCAZJTGZDNNOABQVTYTYSKACNVHOXOWINPMBAQORB",
                                },
                                data::tag{
                                    .key                      = "PYKSMSHOHMKEWRGESUFDYFSWDDX",
                                    .value                    = "DWPPHJUJCPOBMYNNOFQSXSLXXXCOHUJKTQC",
                                },
                                data::tag{
                                    .key                      = "QEMLFVSXDNMAYERJTNBPACXJYIRZBU",
                                    .value                    = "FNKWNJQAENAJCLMJFJERKXEOORRWF",
                                },
                            },
                            .tls_cert_path            = "CWLFQXJUAMFGZ",
                        }},
                    },
                    .tags                     = std::nullopt,
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "DKGSSMQACFXDQPBDKZZLYMSFJIKGYTQYLTPEL",
                        .extra                    = boost::json::value_from("JMJDUOZWMWREOTYARXHCUTJHMWYWSPSIREPRT"),
                        .log_level                = data::severity::error,
                        .retry                    = std::nullopt,
                        .endpoint_overrides       = std::nullopt,
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "PEFZLUUWQFR",
                                .value                    = "LRSMNDVQPWJLEVWCIQRPOHUGICXRADYSR",
                            },
                            data::tag{
                                .key                      = "VZIFBHGIBFDXDBSQZRGIVJSWCAGRD",
                                .value                    = "RBZOEYKOKRFFHIVDDFCGXTCKTQRSHPZRPQFCLLHCJRISFEG",
                            },
                            data::tag{
                                .key                      = "NYTKFNBOYVRKWSFIM",
                                .value                    = "",
                            },
                            data::tag{
                                .key                      = "XVIREJBKWUDKYXHOCXJDAZDEVTCETNEQJTOERIHOGMYD",
                                .value                    = "WCAJBLQOGAPQBEDVPJVTYFJPNMQNIRIQXLSLBXTSIAFKTZJTAJIKFFPQQUE",
                            },
                        },
                        .nested                   = common::box<data::scope_override>{},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "LOJVKA",
            .port                     = 39930,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"FYRBXI", std::vector<data::threshold_rule>{}},
            {"JJGM", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "",
                    .warn_at                  = -3763.0384,
                    .crit_at                  = -3317.1072,
                    .evaluation_window        = 2min,
                },
            }},
            {"BZWBXF", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "WXQKUQRVAXSJLBNBKXYJKXNZYQILESDAZSBAOWGNDWREUUSZBDHHVQNDV",
                    .warn_at                  = 4073.1241,
                    .crit_at                  = 5942.8003,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "XAOFFMSQEQITIQYCI",
                    .warn_at                  = 2994.8814,
                    .crit_at                  = 1000.3797,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "EOEFLOCVJTEKODHCFULMGBMUBMEZRYALAPZ",
                    .warn_at                  = -7092.9301,
                    .crit_at                  = -855.5279,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "WREKFLYRB",
                    .warn_at                  = -4280.8962,
                    .crit_at                  = 6001.4401,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "AXQRMKH",
                    .warn_at                  = 4347.5643,
                    .crit_at                  = -3756.6261,
                    .evaluation_window        = 1min,
                },
            }},
            {"XJ", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "CPNMRIAVCDAFAEWGHEKQBDPIBQVMQFUIOWTCBLTMNJGLOSAOSQOPNO",
                    .warn_at                  = -1771.2148,
                    .crit_at                  = -3182.8603,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "EUMCKVKCMEVSTPUYNYRPXUDFLLOVSALUKEIKOKESCARDLEBHHFMDJJR",
                    .warn_at                  = -6076.3218,
                    .crit_at                  = -5456.6925,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "FSADQLYDHLOUUYBRDGXQQGMLNL",
                    .warn_at                  = 3482.4623,
                    .crit_at                  = -2581.6659,
                    .evaluation_window        = 10s,
                },
            }},
            {"MMXQY", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "TGMKOZZTJJAPOQWENZDSQFWSFYBHZYIWTHGIOXVEXVSLFFYUWV",
                    .warn_at                  = -4121.8549,
                    .crit_at                  = 8995.0476,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "BFKEMYB",
                    .warn_at                  = 3923.7515,
                    .crit_at                  = -9764.0524,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "ZHXTHTMCJVYBOUJEGQ",
                    .warn_at                  = -480.3994,
                    .crit_at                  = -8558.3078,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "AGFCDTRCHIRXJVRXNMSWAGYOCOKCNVKKJMKNBMIGBNDBXBPGA",
                    .warn_at                  = -3890.8655,
                    .crit_at                  = 7405.0367,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "NUQGJL",
                    .warn_at                  = -1288.9255,
                    .crit_at                  = 6763.4932,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "UIMICXRWWR",
                    .warn_at                  = -6796.0975,
                    .crit_at                  = -1337.6636,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "PFPWEUAADSBYWYAEUWTTDYZDCRSIZIMUSFMABPDBLMRVAHFITL",
                    .warn_at                  = -3529.6574,
                    .crit_at                  = -7783.234,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "IPHPHTXZJOVNKGFPIUQR",
                    .warn_at                  = -2900.037,
                    .crit_at                  = 7893.3933,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "SPITNOZCNCJ",
                    .warn_at                  = 2490.3078,
                    .crit_at                  = -8099.756,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "RR",
                    .warn_at                  = 5799.0984,
                    .crit_at                  = -1850.1021,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "KKTPVWUCQGEMPQEHNGJNPKYFTTLUMHA",
                    .warn_at                  = -3056.1474,
                    .crit_at                  = 7459.7901,
                    .evaluation_window        = 5s,
                },
            }},
            {"FFK", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "PFUBZNLUSGKXJUBZSNZBCUCIVKZQDBOOBWXBTSNRWOXBPIEWMIKYUJQGVZIXICZ",
                    .warn_at                  = -4558.6171,
                    .crit_at                  = 5758.3325,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "JWTVYNWCUYIUNLYXPHQDJYSWUOTMYGOPUYCBOF",
                    .warn_at                  = 2388.145,
                    .crit_at                  = 7907.0494,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "JT",
                    .warn_at                  = 3894.0165,
                    .crit_at                  = 8692.3976,
                    .evaluation_window        = 5s,
                },
            }},
        },
        .warmup_delay             = 100ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
