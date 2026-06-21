#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_1)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/1.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ZYCIDPYO",
        .worker_threads           = 121,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{
            {"WO", data::routing_rule{
                .pattern                  = "ZHSDKAAAURAMVGNXA",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = std::nullopt,
            }},
            {"HVHY", data::routing_rule{
                .pattern                  = "JANRUDFUXJDXKXWQNQVGJJSPQMSBP",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 10ms,
            }},
            {"COVQ", data::routing_rule{
                .pattern                  = "FQMLPX",
                .backend_names            = std::vector<std::string>{
                    "TSSMUFFQHAYGRRHMQLSLOIVRTXAMZXQZEQYRGNBPLSRGQ",
                    "NLARRTZTKOTAZHUFRSFCZRZIBVCCAOAYYIHIDZTFLJCFFIQFVIUW",
                    "PPDAJMKNZGIDIXQGTNAHAMEBXFOWQVNRHUZWQOHQUAMV",
                    "UNBXJEGBJCCJJXFNSIEA",
                    "SGSOFYWTQBMGLDGSVNSGPDVMJQPAKTMJAFGKZSZEKNGIVDMRLVRPYR",
                    "CEFFRGIYKTQILKKDJHTYWPESRYDKBNCMZEEKDTSZMCSRHS",
                    "JSRDOIDZBJATVACND",
                },
                .timeout_override         = std::nullopt,
            }},
            {"NFDOFV", data::routing_rule{
                .pattern                  = "XDNMZRJRIWPKDGU",
                .backend_names            = std::vector<std::string>{
                    "JXTKOMKMCCKTODIGZTYRWPVLIFRGJGHLCICYOCUSUKHMJBKFKZ",
                },
                .timeout_override         = std::nullopt,
            }},
            {"DRTS", data::routing_rule{
                .pattern                  = "CHHAZHMCIRCXCAUAJYZLPPEDQYZKCQVFFYEEKJDWQTJEGERXBYK",
                .backend_names            = std::nullopt,
                .timeout_override         = 100ms,
            }},
            {"FJN", data::routing_rule{
                .pattern                  = "BWVHIYCVOZNRIROROAMKFIPAZUNSABWLSE",
                .backend_names            = std::vector<std::string>{
                    "IMSMFTCHPAFQKQUOVUXHHKPVPHWNKRTXUIUHBCYQULFQYZGJJWJRLFWWXOTCDT",
                },
                .timeout_override         = 10ms,
            }},
            {"SXY", data::routing_rule{
                .pattern                  = "PVMWULMQFRXBQCZIUDIXCEYTVVWCOHMZNMFKOETPGDNTRNDVJI",
                .backend_names            = std::vector<std::string>{
                    "",
                    "AAUTHIGFJERGIJSYIVOZZFRLPNDY",
                    "GJZDZADSXARJVYXUECQLSZJNQVLYQKADOWOLJRMKZXVSPDUMMGRAIUTX",
                },
                .timeout_override         = std::nullopt,
            }},
            {"TQNXW", data::routing_rule{
                .pattern                  = "JWFOTVQGLQAVMSNMKTSXWXCPXHUUJUANXUEUYMZIFYCYTALIZWNVRJEOIPFOQBI",
                .backend_names            = std::vector<std::string>{
                    "LCVOAFQWFWCMUWITJGQGHKICCWQ",
                    "RXBFJUXWRILTXHMRMFPZITKWHITWH",
                },
                .timeout_override         = 5s,
            }},
            {"NYHZ", data::routing_rule{
                .pattern                  = "CUXFSOSXETIOQFEYE",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
            {"WG", data::routing_rule{
                .pattern                  = "JCDHMKPDFBBZTAYGVBPWQXTOKVIDTWFDHMHPOMYFHHJOR",
                .backend_names            = std::vector<std::string>{
                    "KPSDGCBAZAPKMSJGMFYUEZAAMEVRBSMIECOUJABRBQEBI",
                },
                .timeout_override         = 10ms,
            }},
            {"XIV", data::routing_rule{
                .pattern                  = "GVOMKUIIUUHHBSZSFLNTWRUQBLRNRGWRNVCWIXTXYCIFDEBGNBBU",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"VEMYW", "OAXQICIZKCJBMBXIKXEIZMZDVJDNHQRGKKQZMSPDEUOQRXSWQRAJXFGLM"},
            {"NL", "CBJZURKN"},
            {"IKXX", "AQDEKXKZKSCOIPOLXMCSZBEBQPSIZHWSX"},
            {"MJOT", "RQFAEIVHSEDFYNXTBZDRVIWDGICUSQUCCZGUFQNASLPWZJHGTPHNOVLRGZPXCI"},
            {"XR", "QPCMTQZSSNBLOAGJWWUARDJQXKYRUSRJQNRQNTUSJOJEQOSER"},
        },
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{
            "",
            "BRGRNLBUDXRVNVXDIVIFPZZWBZGVUCMDVOJVQPM",
            "DEMTWGFQINXRJPUZRGZYTKPDAYXVLWIBRUOJYDHQIIWHNEEIGNRUTB",
            "EEWIHCURWBSFVDHSGQSVJ",
            "ENIIPWJIPGPLTPHKFTYFXSWOREBQKQWEUYZGKT",
            "EVSBLCCXDJKHIQBLACEMLXUWHDVKIAQKDLZZUXETIMCVSTXQPSNRMJHUJ",
            "IRAIRIQIPEMWDXLCURLRRZXQVSATJOVEECSEVGPZYKLJFEZMOMDTEIJVV",
            "LENEAFI",
            "QDF",
            "THCXHIVUKITXQMADKLE",
            "VSBLNMJVYVACCAMIOIZZLUXPYKM",
            "YPGWPMWNCCEGEHXADIEPYDMUXFA",
            "ZJNIQJXN",
        },
        .config_tree              = data::scope_override{
            .scope                    = "",
            .extra                    = boost::json::value_from("UEMXRDOAYNTVNILNMTOBDPYBUWWAZBDSEQQYLRIZSULZPWHZTHDRLFDYBWKN"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 66,
                .base_delay               = 1min,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_44", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "WHUTQEBKVDQFRUUPKYWDSAPGMUFM",
                        .port                     = 46962,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 34,
                        .base_delay               = 1min,
                        .backoff_multiplier       = 5690.4752,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{},
                    .tls_cert_path            = "OMRDSPIEEAMN",
                }},
                {"ep_4", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "FOYMVQZJEEQDIAOMZUWXZHRWMARZHNFVFKVHCYRRF",
                        .port                     = 11509,
                    },
                    .connect_timeout          = 50ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 51,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "URCHMYODSUBMCRDUPBQHYAAJOIXNFTERWKYRUOQZNRFW",
                            .value                    = "MZGPILEISIFYXTCXLKEIIILMI",
                        },
                        data::tag{
                            .key                      = "",
                            .value                    = "IHGCZSRTGRNWHSEROMWGCUCEZVBAXMMNVESTEVRRCHMEJGVXMLXFHJWELPRJC",
                        },
                        data::tag{
                            .key                      = "WOAJZZTSDTLYOITBBZK",
                            .value                    = "EUDDNUSHXG",
                        },
                        data::tag{
                            .key                      = "WGMVQEWSIXAWDZGYSMVPRTHIB",
                            .value                    = "VVRQHNIYVNMIPDVEFRAOYBPGMXRKHDCVXBNOGFTQ",
                        },
                        data::tag{
                            .key                      = "QLGHLVSYYCKBOBTFEJPBSQCSMCMZQSUJ",
                            .value                    = "LPBRPANJSXKZETSRICTZZYLNM",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_15", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "QA",
                        .port                     = 6614,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 93,
                        .base_delay               = 200ms,
                        .backoff_multiplier       = -2596.8442,
                        .deadline                 = 2min,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "ZRAFKLGESESDMKQNLKITL",
                            .value                    = "CY",
                        },
                        data::tag{
                            .key                      = "IYMRJSZTCCWFINCEJRXUIHGDIXPBXQJZZGRCRKKJQEBOLZXBAKNX",
                            .value                    = "RBWSWVUQNF",
                        },
                    },
                    .tls_cert_path            = "ESQDXIO",
                }},
                {"ep_8", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "OKTXLHUAAPBFIRBAHYCQFBQ",
                        .port                     = 13124,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 25,
                        .base_delay               = 25ms,
                        .backoff_multiplier       = 8888.9692,
                        .deadline                 = 10s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "SNTPLAPADVUSVTNWSKKCUNGWQZPTSVRQPTVXSYOTPFIVQJSYZMTRIIJATYBZO",
                            .value                    = "LHQOGWPKWUEMNBUDLZAIYRXBJMAKK",
                        },
                        data::tag{
                            .key                      = "BGWCKDVUCEYWJNTKHAUWWFYYYQXSULJJMNQOZCGNHTBTHUHHWMMGTEXJ",
                            .value                    = "LAWWVJOPFVEALNRKZQPKTDSUJZRVINAJYCUPDQHTXUXINLZ",
                        },
                        data::tag{
                            .key                      = "QQQFEJ",
                            .value                    = "CGAVBNXWACBABRKKZATARGPGIJSRQIHFGMBHRWOBKKNDASFQUCYFGHFJZDB",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_57", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "BXJLBSCOG",
                        .port                     = 51999,
                    },
                    .connect_timeout          = 100ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 12,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -7681.2972,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "IQNHXBXIYGKLLOYVTM",
                }},
            },
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "PKFTUDHCYZNIRJK",
                    .value                    = "LNOLLKMPQALEJFJSERWXEFOUUEEFCTIHLUKFIPJCNERLODEV",
                },
                data::tag{
                    .key                      = "PRBBXGULXLQLZQUZVLKUDFMBITWZGBHJKSMHLYBHJWS",
                    .value                    = "",
                },
                data::tag{
                    .key                      = "LQIEFHCJ",
                    .value                    = "QRTRZNOSQPFQLGNZCIGHYEEYGAFPLFBZLCTH",
                },
                data::tag{
                    .key                      = "COUUGTKFSWVWAGKPRBBLPRLEPCQKVXSVJTKZSCPKNCICVUKAFKHKIIJ",
                    .value                    = "NAJFUJBDNNTGILYUXSPSJTIVFKELDMLQXSWGMOEPWHBXUHCXCBQQPSPWKQZF",
                },
                data::tag{
                    .key                      = "AMRXRXOFSSLBXLLOHWUVRJCOYLGFEOB",
                    .value                    = "SKZFSPPASHTBOUFQGMODKIEFKEFZXTQJHRWNOOQRJFQTQJSZGJVEVAKDNMWUQ",
                },
                data::tag{
                    .key                      = "OOROLGBCXDDRMEOMFPOQSBSGSOPMJLYYFTIFYAR",
                    .value                    = "VCR",
                },
                data::tag{
                    .key                      = "OKXDMBXOINOKQDFMRNTXPQEKELETGHZZGOUEDWDNBOELRKIMAMPWOJ",
                    .value                    = "JUSMKYJFDPFOEODRDRKKPVRUKXSKRSZOKPWMRGFHRGTHBYK",
                },
            },
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "LLLTTVNGZJHKMWMVYFAMULTZYTHHCTKMGWJDNAZLCZNEDRZXFYKEMNKRUWQI",
            .port                     = 61747,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"FEDOSQ", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "KTZXWVKT",
                    .warn_at                  = -7258.237,
                    .crit_at                  = -2827.4666,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "PBUCERPSEGLWEIXLCMPAQOGXHGWZAXW",
                    .warn_at                  = -3919.4231,
                    .crit_at                  = -4660.5736,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "ZYDMKD",
                    .warn_at                  = -1092.2978,
                    .crit_at                  = 8608.5263,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "IENLULYMNNLRGGCEHHAHVMOZTOSDBF",
                    .warn_at                  = 6301.5151,
                    .crit_at                  = 6377.4479,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "NEHWYVLNYKSXBQOEWQLSBLDHUUDNEZALEEJAPUAPCYZSNCPRTQ",
                    .warn_at                  = -8062.6231,
                    .crit_at                  = 773.679,
                    .evaluation_window        = 15s,
                },
            }},
            {"NHQMPX", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "GSTWLDD",
                    .warn_at                  = -2901.6983,
                    .crit_at                  = 7660.4482,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "AQNHCJPTBSNRJMUBVTAITPOHIKYPORBIQFXWO",
                    .warn_at                  = -889.1266,
                    .crit_at                  = 1703.3724,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "YVWNVRTMPYUHJACEPDLIJZRJEDQEOBOPXSKRLEWARG",
                    .warn_at                  = 5392.5316,
                    .crit_at                  = 2450.239,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "",
                    .warn_at                  = -4681.9994,
                    .crit_at                  = 9230.7173,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "VKTTUWW",
                    .warn_at                  = 1456.5234,
                    .crit_at                  = 7747.6338,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "VBGFBTDZBDRQJYZGFREHG",
                    .warn_at                  = -8206.5765,
                    .crit_at                  = -2942.3186,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "EJSZHCTIBANTJPNNZ",
                    .warn_at                  = -8642.077,
                    .crit_at                  = -5704.287,
                    .evaluation_window        = 15s,
                },
            }},
        },
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
