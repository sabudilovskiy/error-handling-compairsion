#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_30)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/30.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "JTATUGIBMMUECOAQHACFTQMULRCMAHZSVI",
        .worker_threads           = 195,
        .enable_tracing           = false,
        .shutdown_grace_period    = 15s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{
            {"EJJI", data::routing_rule{
                .pattern                  = "EHWKDYANXQJFQUFPUKQOVKQKCAUDPPIP",
                .backend_names            = std::vector<std::string>{
                    "VFVFFQJNVHGPLNXTJQMVUMJZZUWPLJQEXFJQKAWGDYKR",
                    "IMXZURBWOVAETPTLIOQEEMQCXKAGNSPAENC",
                    "YJYTAKKAPYOUDLPYPSXFDHKPMDGGPXDDMDFFWQLAVVSFYYXL",
                    "TLESHGWTTEEODTHKUQE",
                    "GJAXZNXJAMIYWDPIDNX",
                },
                .timeout_override         = 25ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"TGSAE", "TYIARYC"},
            {"OKXZYP", "NCGXCFATTACDKUFJATOWLWRMGBRQAZUUDTZNJIDM"},
            {"DV", "VEQSLLNCBTTFPALFOUKYMVFQ"},
            {"QLU", "IAAUVCEAQKTWPU"},
            {"EETEHC", "WDKRBYYHBQBKQNDQHIFZYIZDKFAGLPWFZBHHTTEW"},
            {"XTGVKW", "SQSRCHPGTJMSPKUWADOBHWPPPTFSYSJDPUXNFEFCAVJ"},
            {"RVG", "EQB"},
            {"ODA", "TILFWNCFNIMJJOKLEVCJZNHEVBUDNZKUMKZZFOV"},
            {"UUDNNP", "MYWP"},
            {"XMHZ", "KDDQMYVNXAARPCQNFBXMGDBZLWFPKQTVKNAMKPWPNCEETCUX"},
            {"HG", "SXDANPXYKRVHCKQUXDYLZMHQOGHHMLLZIDDBMDUDWQIYNBNCJACOSVORTJAPCU"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("U", 74474, true),
            std::make_tuple("UCGVEDTSZPZJLITNDVNSYOYPENMJCGRPIWKMHJZTKAGWJTBANL", 14907, true),
            std::make_tuple("UIZQVFLZCZWFFUWV", 38175, false),
            std::make_tuple("JLICTAGOUWUHIAZKUIPITYUAADPMZRESFEQSRBIF", 75061, true),
            std::make_tuple("ODIBGXIYDOQYBNOZAKUOCK", 56795, true),
            std::make_tuple("GDAGT", 95051, true),
            std::make_tuple("CCUHJBMOUQYPLO", 53056, true),
            std::make_tuple("KXIODGJGDDYVFGQTWPEHNYMMRA", 57094, true),
            std::make_tuple("KW", 57261, true),
            std::make_tuple("YU", 46719, false),
        },
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "QR",
            .extra                    = boost::json::value_from("SUZETFJXVYIEAKUAWREKGCSLWHOYVRSWGMZFPLUJRJAAWKVPUDKJDH"),
            .log_level                = data::severity::error,
            .retry                    = data::retry_policy{
                .max_attempts             = 33,
                .base_delay               = 25ms,
                .backoff_multiplier       = 9021.9638,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "VPDSVQECCUIFGAQPMDKTPA",
                    .value                    = "JHTKQWNSQGRVMULIFZBPZMSPZLV",
                },
                data::tag{
                    .key                      = "JDAPDASJSLIXVN",
                    .value                    = "YKWURFLAWHDKGUWTZEAMGXQSJIVBDBWOMLSBKFEECIYIQLGKPBTFALKPJGE",
                },
                data::tag{
                    .key                      = "YBSTTESCQEFHJOIHY",
                    .value                    = "ICOMQOOCNDEWPENSEW",
                },
                data::tag{
                    .key                      = "CXLZKFPHPXZKPWSEEOWTMROEGYOZBSWZQCEHAFMBLXN",
                    .value                    = "HTNBHPKQZFXGLKUGMEXKOJEELDJMTQPFXZMNOKCQFKPLXFFDKOMJFCNLZY",
                },
                data::tag{
                    .key                      = "CS",
                    .value                    = "BWZKIOQPTDUTCXRKGDTRSGNVTFMSSWHBFA",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "YRUECYDDTFTOQUUEZYFDVYMDKSQU",
                .extra                    = boost::json::value_from("NSPNFJUNDSWLSIXGCGGDBMHKJVABESGMGLRNIHDWPYNLQAJSOFYWHAGVYFUAJ"),
                .log_level                = std::nullopt,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "LJKZOZXYBFPGEZQRSZXOJATVPCHEDHFUFB",
                        .value                    = "WUKDKXYXMOTOYLYHEPEXITIISJ",
                    },
                    data::tag{
                        .key                      = "ZMTJBERKZYRTACQGEJVXBIAFVBSEDHEJRDFBSN",
                        .value                    = "BIXLJJUSCBZRMJYQLPTKECWFJBLJTMELEWAOUWNUZCUDDLIFMCSRYQYB",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "ZNSGNNUFONFJVUUXDUZZJVRWWRKNVRRABQQVCQJISNTGBYHBEHKWWKBZ",
                    .extra                    = boost::json::value_from("ZJCWLUVSXIZUWTDOIKWFDMRKUPOAOKSY"),
                    .log_level                = data::severity::error,
                    .retry                    = std::nullopt,
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_38", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "STIKYXUYSWFGXGKC",
                                .port                     = 46490,
                            },
                            .connect_timeout          = 100ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 3,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = 4184.1561,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::nullopt,
                            .tls_cert_path            = std::nullopt,
                        }},
                        {"ep_50", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "ZOHTYKLLLWAUVYUPJILZYPFGSDZCWAIHESTILKJTUKTBIJMP",
                                .port                     = 47514,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 35,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -9007.9767,
                                .deadline                 = 1min,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "WSVXYNKRKKLBOLRVIGCQDGMKUMOMPULCEXWYCXKOXT",
                                    .value                    = "RNVTSWOHOKO",
                                },
                                data::tag{
                                    .key                      = "HJIDMPSRMJWBJQEWBB",
                                    .value                    = "OUPTLAEVNKIBSLAEQNUGETSLPRVKFFRSJKFVMNOXI",
                                },
                                data::tag{
                                    .key                      = "",
                                    .value                    = "XUJDMKZIWHLUXCHKEXFSGKLXTNFG",
                                },
                            },
                            .tls_cert_path            = "RZFSOYDSYIUFFMTABOZ",
                        }},
                        {"ep_17", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "YGHIHVHWSPLGXFVVRKFCPDHNSJZWGCWVJPXCZXCBWXXUCJNCIIOVXHWGRPA",
                                .port                     = 55708,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 67,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -6581.3208,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "FZRSVBLHQCUWCHPSRLNJBVBM",
                                    .value                    = "ZKLILNAEVWBKBHAYGQOMIBHGWUUSTZYXYON",
                                },
                                data::tag{
                                    .key                      = "WMHHRHQBLLZPZTMWUUW",
                                    .value                    = "CLPIKKHAYZXLITYMFQHXTZIDOMIWDYMFQLATYGVKIZKR",
                                },
                                data::tag{
                                    .key                      = "OIHHEOYBCDDFDJEJTMJBRQWSEGSAGZLFSWYGUYPDUWW",
                                    .value                    = "ZOCXTVBCGJYBUOOFTWAZMHOIZUKTKPTBGCCDKOJXYAE",
                                },
                            },
                            .tls_cert_path            = std::nullopt,
                        }},
                        {"ep_97", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "LQXHGLFJWPTCNSFXUCRJ",
                                .port                     = 602,
                            },
                            .connect_timeout          = 25ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 1,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = 6725.0691,
                                .deadline                 = 30s,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "ABFAFCNFOTKVTGACPVISXDDMZSWOFNMH",
                                    .value                    = "PZGZJRGPAOXPRUUOROIONINJBGN",
                                },
                                data::tag{
                                    .key                      = "IKIZEYWJIFTXQHJGOBXVZARBNXBLKQYFGMXVMIFEHUHBZUEV",
                                    .value                    = "QADBKNMIVCFNYBCQSDMEAJCGYGTG",
                                },
                                data::tag{
                                    .key                      = "PLUFVOHNLGTYZTIROVOLTIJMTDTGNIQ",
                                    .value                    = "LCERAUOUOQSIS",
                                },
                                data::tag{
                                    .key                      = "CPYNZBEXACCXQORFULOTMEWCLDIUWZYHWXWC",
                                    .value                    = "EOULFJCUDATVXDCMKKEYWWRMFOEYDFVYHRSFGJXNXPAHTIFIYPOOE",
                                },
                                data::tag{
                                    .key                      = "EXFNADNBMLXPWVGIHLEPUX",
                                    .value                    = "KTZZQUUWUYXIKVQTCCHFQVYWQJUFJEFPDMNMZFZ",
                                },
                                data::tag{
                                    .key                      = "GBWYQPYIBEQFPJYIANOECJCTELDXVPJRGHIXSCIKANACBEEPCBBN",
                                    .value                    = "BXBTKQWASJVIYATCUXYDX",
                                },
                                data::tag{
                                    .key                      = "PXYHAVBALKEWKUHZKUAVSOMUXUJKTGFNCDRHEIOH",
                                    .value                    = "BNZIQPWEKPOTDEGVIGNIYQVYUXFQNHWUZVSDNBQVDIKVDPVWQFXQVCZYDHJJU",
                                },
                                data::tag{
                                    .key                      = "CCPZWGDP",
                                    .value                    = "FTXJFZVARDGWPCBMBFNGYQK",
                                },
                                data::tag{
                                    .key                      = "QTLFQUBLZBMQFCXTCTIOBTPMBEOTFVPNKCTFOERBHVEXQIH",
                                    .value                    = "PGGQOSXIXZJNPIJDNKWQOEGOXBDDWY",
                                },
                            },
                            .tls_cert_path            = "YMQDNQVNSEZUIGBVOKBOTFVXECAMUXTOZQGIHLLFBMUUOLOCMRZ",
                        }},
                        {"ep_61", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "HBCYNQXRGSYWUZJ",
                                .port                     = 25227,
                            },
                            .connect_timeout          = 1s,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 50,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -5165.2577,
                                .deadline                 = 10s,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "HYR",
                                    .value                    = "KNDBSXFNSSVRSU",
                                },
                                data::tag{
                                    .key                      = "OBTAARKQAXFTBGHGMBOOZWJZCZNIBXSCBIPDK",
                                    .value                    = "YOSEBITCALPNVP",
                                },
                                data::tag{
                                    .key                      = "LFSJDNHOZSUHMJKQYUUZUWXRAYUMT",
                                    .value                    = "KDEJEMWUDIIKFXIRGNDHARAWVJFSIIDNSUBW",
                                },
                            },
                            .tls_cert_path            = "ZOTIYKVLCUDIKY",
                        }},
                        {"ep_87", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "DEJOBQLNANXFIUSSO",
                                .port                     = 33378,
                            },
                            .connect_timeout          = 25ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 29,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -6289.6932,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::nullopt,
                            .tls_cert_path            = "HDZEE",
                        }},
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "ISAMMMQJVUMAQJYYLYKH",
                            .value                    = "QNP",
                        },
                        data::tag{
                            .key                      = "IEVKZTVHPWRVJEKOUHNCEZBWJGGNXPYODGMNYYZVUETLWXGKJFTGTDUGIWQ",
                            .value                    = "RNJHIDXCUQDDUVVCMAVUMSZUZTFMCEYPGDUJWYQOLEMSJIJVVMXEOOEGOSXMA",
                        },
                        data::tag{
                            .key                      = "FIZIJOWHUEWPVXBSDEAFAPVYNNKFKTACSQIGHVFRASZCOFGQNVYIMKWRMQPIICF",
                            .value                    = "GW",
                        },
                        data::tag{
                            .key                      = "OFSDD",
                            .value                    = "LLORTGEWIFGQQRJPQENJWWCHSAGZTPH",
                        },
                        data::tag{
                            .key                      = "OTHZEGKVSCQUMTZHPRKFXWMFNWZ",
                            .value                    = "IEN",
                        },
                        data::tag{
                            .key                      = "WEPUHEPWLHNXCGOJIEDCLZMMPIJEZPFBLCVTDWQOICKDISDUHHMUP",
                            .value                    = "XPWSMOYWKONVYOZNNOFXHHDY",
                        },
                        data::tag{
                            .key                      = "RATXKCZSGHAMSFYYVKTKPBFLKKEQJLDF",
                            .value                    = "BOGMHXILCEFQVRNCOKQEM",
                        },
                    },
                    .nested                   = common::box<data::scope_override>{},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "OBPWWGJDBXYSBUNNIQEWODVWFVWWXLXTQJQLHENSDQYFOXHVMOEDIHJFR",
            .port                     = 44221,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"LPDWN", std::vector<data::threshold_rule>{}},
            {"STANSM", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "UVHVQIREBEUXZZBGVUJIFNTISIUTEB",
                    .warn_at                  = -3927.7186,
                    .crit_at                  = 6096.4633,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "LRFGEWIOEHTYKSAOBECFABKUIYFRMDOWNLJJDXLDGCTIOEAXY",
                    .warn_at                  = -9206.1113,
                    .crit_at                  = 3961.562,
                    .evaluation_window        = 5s,
                },
            }},
            {"OAHL", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "JRNAILOAIOAMNELVSPTVFEPZTBTPVPNJRZGTKGIW",
                    .warn_at                  = -2142.8824,
                    .crit_at                  = 3320.8539,
                    .evaluation_window        = 10min,
                },
                data::threshold_rule{
                    .metric_name              = "WAODWPUKSSVMIDKI",
                    .warn_at                  = -5466.798,
                    .crit_at                  = -4078.2068,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "CCUS",
                    .warn_at                  = -6643.036,
                    .crit_at                  = 4410.2407,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "VMXYUQNCSPPFSSZIEGFNIRRJGIHUCBJGUMCCWFTOVWIAUYJQBAYLRTHTUZRTW",
                    .warn_at                  = -6848.0476,
                    .crit_at                  = 2218.4376,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "NRTIXLQSDXFGKXNRLMGDDICNLD",
                    .warn_at                  = 8511.3686,
                    .crit_at                  = 6731.9238,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "OTTVTGMADYXCIKHGUEKMFWBH",
                    .warn_at                  = 7525.4901,
                    .crit_at                  = -3772.5565,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "EJWUCLTSJZQBLRKPSFVDCBFAXPQAINPNHERZMKDWIWHAIOBBO",
                    .warn_at                  = 2345.6572,
                    .crit_at                  = 7896.6211,
                    .evaluation_window        = 5s,
                },
            }},
            {"PIFB", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "HCYAOPUPQCBQNDKVSQOWLFTTMSNVSKTCBMGXSSFOXLHYNAJYATU",
                    .warn_at                  = 6934.2405,
                    .crit_at                  = 6555.6239,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "QBSMZWTJWLGBDCDJDTJHUJADJPFBWRVCUVAOSECWXMPNJYMHHHYFWMYAA",
                    .warn_at                  = -1379.1024,
                    .crit_at                  = -2970.9376,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "KIIMSXCGJKOIULILZKOESUMIYJKGATBTRBSGUVKCGXPMNICLILEKIZDYZHGKVJ",
                    .warn_at                  = -3272.7532,
                    .crit_at                  = -4126.0054,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "YOPKTLZSEWHVCZOILCZVIKONYAOSVQJDUEOFDRGCOJWI",
                    .warn_at                  = -7158.9474,
                    .crit_at                  = 9199.4823,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "SNS",
                    .warn_at                  = 8534.3244,
                    .crit_at                  = 1074.8809,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "ZEJBCFAFGAZGGJOVUKQGNGGPBTDMYKXUBBS",
                    .warn_at                  = -4199.4946,
                    .crit_at                  = 2390.16,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "GZAHYRNKJFISIBMVEFYHTIEBGDZDWNRNKYSZLJC",
                    .warn_at                  = 8831.4309,
                    .crit_at                  = -8213.1046,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "TMZAWLPEIZKUJVNSVZUAUTVIJOZJEKTQDRYKVJETVIJKFHCWD",
                    .warn_at                  = 6831.9027,
                    .crit_at                  = 7089.5722,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "CUOAOGAFKAAUDXJMYJFDVSHDJQG",
                    .warn_at                  = -7614.7117,
                    .crit_at                  = -1879.8956,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "EZHLASBSTFPTPBKBJ",
                    .warn_at                  = 3662.7723,
                    .crit_at                  = -4434.6172,
                    .evaluation_window        = 10s,
                },
            }},
            {"AB", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "C",
                    .warn_at                  = -3228.4496,
                    .crit_at                  = 3381.9964,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "JKAULJYERPQVJSVK",
                    .warn_at                  = -7383.2868,
                    .crit_at                  = 9513.9544,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "CKQAADLKINEQOEGRUWMFSINDLHFSYICTRGIJPZPRUKLNREXPJYIVBYYM",
                    .warn_at                  = 1948.203,
                    .crit_at                  = -8871.1159,
                    .evaluation_window        = 10min,
                },
            }},
            {"DR", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "GOQNATFOBKFFXYGJOVDVJJMQUIATDTXBFLOXWSFOOVJUR",
                    .warn_at                  = -9304.889,
                    .crit_at                  = 4917.4188,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "MWQEMBIMOAXCMSPYCSVPGDNNUBZQKGJURSRMONAMUENXGWHZZKIBV",
                    .warn_at                  = 967.8576,
                    .crit_at                  = -5994.3796,
                    .evaluation_window        = 30s,
                },
            }},
            {"HAHIUO", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
