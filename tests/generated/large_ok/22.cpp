#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_22)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/22.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "EHATOFWDXULZCHIBKTFRVXNWBSASIJNGFDSQXYSBWKTKIFMJYUQEIIVWFNBKR",
        .worker_threads           = 230,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::unordered_map<std::string, std::string>{
            {"SAJST", "QNYVQNCCOLDNYMBGQHMADOGFARMLFKLUGOB"},
            {"ZYU", "UWDBGNDESOBDPWQESJVXPPXCUWLZDZTIDAFQLUCKDFUWTNW"},
            {"CG", "DGRIPCFAIYDSPTGMLDXQFB"},
            {"BGGYPU", "YWWNOIHHDICVSFFUKBAPFTIB"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("GUZOVHORNELKIWAWMTUDFZTRULIQIGIIQFLZQPWPERGPMKYCM", 66600, false),
            std::make_tuple("MKHBQ", 52441, false),
            std::make_tuple("TAQKYYADQVBZUCDSCFIQJKN", 57500, false),
            std::make_tuple("VZXBHZQUKVJAHHBDKJAK", 11273, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "MLEMJHRHTLBOIQRGCE",
            .extra                    = boost::json::value_from("YJREOBIHEDRPKZFQMCVKGMEVSONURBMVOZVOLGJWACDEOYYCGSPZ"),
            .log_level                = data::severity::info,
            .retry                    = data::retry_policy{
                .max_attempts             = 92,
                .base_delay               = 50ms,
                .backoff_multiplier       = -5213.6841,
                .deadline                 = 5min,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_72", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "YMVORZNIYGZHHUQIVJSBTHTRHLOZZLDSXHLNLEXEBRTQJ",
                        .port                     = 42685,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 80,
                        .base_delay               = 25ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "",
                            .value                    = "ZKFPFQTFWD",
                        },
                        data::tag{
                            .key                      = "FFWCWQV",
                            .value                    = "OROKWZSKHFXUBTDL",
                        },
                        data::tag{
                            .key                      = "RNUKNYXDHZNIBSKTRIEXKMQDAWLRCFOAOVMNCLTAPMGJDTRZFJUD",
                            .value                    = "GK",
                        },
                        data::tag{
                            .key                      = "HFCADGINYUZ",
                            .value                    = "IJTVLXILJCRPHEGNMECZYIYLXAZZOQT",
                        },
                    },
                    .tls_cert_path            = "E",
                }},
                {"ep_6", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "PDRLHDUHLNFEIVHZTPVNDYLEIEDYJHXVLLWITCVJVMRHGUGEEKIECV",
                        .port                     = 14914,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 49,
                        .base_delay               = 50ms,
                        .backoff_multiplier       = -1637.3716,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "ZTPYONQVEYQYHFKIBKFCBYROHZRQQLHEITKVWBQCSVA",
                            .value                    = "Z",
                        },
                        data::tag{
                            .key                      = "LNQQDLDPTLMGHTYEDJBTXMKI",
                            .value                    = "XDIKYLICIXLKZJNRXFYZXDPFHYFHWNUCLOUPOQYOCZLPDPJVIEZRT",
                        },
                        data::tag{
                            .key                      = "OTTMMNHYPLPDXPJWSDLAXVLYYXYBPVIZMA",
                            .value                    = "MLOGBMFGLGBQIBLCACYXNTYXQVESZZEQCSQDRJBMKGCXBCWZGRQFRQX",
                        },
                        data::tag{
                            .key                      = "FJJFIO",
                            .value                    = "BRNLMHJLTMVIHJHBJJVCU",
                        },
                        data::tag{
                            .key                      = "SVEMLQUXJQQCTPEUZROGJBFQXADSQTXRSHICYAMJINDFYSIOJRSCKXEZIUB",
                            .value                    = "MBDSQZPXWCXZKYUUJWQFUVEU",
                        },
                        data::tag{
                            .key                      = "UYTGPBPNDSNTWNFKQDHPWMJROHUJRQZXHNFXPY",
                            .value                    = "WNMHPPZ",
                        },
                    },
                    .tls_cert_path            = "NSRDHCUWHKQNMETNRGKOBJWQVHPGYKBFUXZFBHM",
                }},
                {"ep_71", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "QCMIANLXPLSMJBNQWFUFQIYYQQKULUEV",
                        .port                     = 42250,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 99,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = 2878.9753,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "YQPQGBYEFSSFAILALALVDWUBHXVZOGTXMCEZIYDJQAVDYQCHHMRCVUU",
                            .value                    = "FTZZEXKPDYRCRSAAVAPJEAEIZVBLATWIJOUOWSBYBGANWPTKLHOUBV",
                        },
                        data::tag{
                            .key                      = "JCLFOPUV",
                            .value                    = "QIKXGHFMABKIZHEBGAMQJTABPGMZDYEZV",
                        },
                        data::tag{
                            .key                      = "IAWIOLYOGXDYAVYBKNUZIEHEXCXWFQDRLTJKVTIEWSQRYQXCBRAEKQVFWWACRCF",
                            .value                    = "ZPSP",
                        },
                        data::tag{
                            .key                      = "IPHTGUPFPZZLWDYZEACJDUJAGWREOKFOEP",
                            .value                    = "NKBPARUHQNXOLBUDSNJMREGMUOBAAYJMERWCYVAGZNQORTTZO",
                        },
                    },
                    .tls_cert_path            = "CKLNUBRCOGOUARMDDUBETSXNGCUVHUVRCZKHZLNVRVUKJ",
                }},
                {"ep_2", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "MVYOKZBNSYGOQHNARINUNEWRGUDILMVDG",
                        .port                     = 45292,
                    },
                    .connect_timeout          = 25ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 81,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -7122.2719,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = std::nullopt,
                }},
            },
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "IFJCSDLDVAJAYTHSSNYXJ",
                    .value                    = "HAUFFZOALMVBZQNWPUBREVIIPTUDOLEEDEUMJDAMPHSOTMNMIIVKGCNF",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "PFURPMKBSWGNJDMXSSMZIIJXOXIWIEURRXPPCQLUYUWFXBUIQBAJBKDV",
                .extra                    = boost::json::value_from("PWWNXDRTDNNIVVDNNWXJUVAALDNAQKXGHVPZQNVSJWDNESWKFFTMJM"),
                .log_level                = data::severity::error,
                .retry                    = data::retry_policy{
                    .max_attempts             = 87,
                    .base_delay               = 2s,
                    .backoff_multiplier       = 1144.1298,
                    .deadline                 = 5s,
                },
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "HXUIDKHWQLAMIBOGVEMLAWGHJLCSNXSTUUYRTWY",
                        .value                    = "AABRPYQYZODBUDPYAHBOWLTWVGCXWASFKHHTNBOZBOCFCABKTAQ",
                    },
                    data::tag{
                        .key                      = "RKNDYCCQIU",
                        .value                    = "ZFAKXREKRROCUTJWFXNKVOSXNCOPPNZXRIINEURNXURKLQVCVAPM",
                    },
                    data::tag{
                        .key                      = "PVCAPNW",
                        .value                    = "DDCNHGCW",
                    },
                    data::tag{
                        .key                      = "VBOVJT",
                        .value                    = "OSISJKVICRTYJLAMNKUPWVGMGXERN",
                    },
                    data::tag{
                        .key                      = "UYRNIKOBTUKOMJWLXWJGJBJPHP",
                        .value                    = "PFYDCGNEJUJJTYHBRXLPXAYIJR",
                    },
                    data::tag{
                        .key                      = "PZMPVMXIRYZBXVYBBU",
                        .value                    = "BUBUFVIVBWFVGXLVGMBLBQRBUDDOPKVFESOAHSTFBLUKDYIYIHGW",
                    },
                    data::tag{
                        .key                      = "ODWNNMFKSCRKODUSDNTEFHVPVJOETYCGNKNVQXEUYEAYVNXYTMQS",
                        .value                    = "FVCQDQBBXZJTMQSCBFRTSNSSACOFERDSLTRSI",
                    },
                    data::tag{
                        .key                      = "FZFHXIOSQCIUAGTAUMHOTIIISLMHOXAVZTEXSJDXBRQVLMJKPVCAC",
                        .value                    = "WYUXIKUSXREOYXTCSFUGTXEBEFAPKWGFTQDZEZQGZY",
                    },
                    data::tag{
                        .key                      = "YRD",
                        .value                    = "YAITXVQVSXDFWPDHVTTNQCHNZARFOOOGUJSAYQSOZBQOTMXDDFXPAPKJQF",
                    },
                    data::tag{
                        .key                      = "GXXY",
                        .value                    = "RLDYVOYOGZOJSBW",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "JEBJTJFNYQOLEEKAZYPVJYUQVHJNHKAT",
                    .extra                    = boost::json::value_from("OIUIFBCEEXQLGRYJKBDWVWHUQB"),
                    .log_level                = data::severity::warning,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 85,
                        .base_delay               = 10s,
                        .backoff_multiplier       = 8228.8983,
                        .deadline                 = 30s,
                    },
                    .endpoint_overrides       = std::nullopt,
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "R",
                            .value                    = "MPCGUGVNHWEJM",
                        },
                        data::tag{
                            .key                      = "SWIEVBCRDUSFUEIFDDZMRUTINLBHOQV",
                            .value                    = "TJQDTNINNZXDWBBTPZCVAEULUGMXBYNIDJTNPITFWJTQXYPADSBQFQJVUPGRXU",
                        },
                        data::tag{
                            .key                      = "ULIFVUUJVRBGGTCDZURZCWZRPFIDELHQMCY",
                            .value                    = "JVYAUMBWCJSMZGIKKCVMRZHFSGZXLRHPFOBIIXROCTSIXFZLEIHBGAFNDOGQKZ",
                        },
                        data::tag{
                            .key                      = "MV",
                            .value                    = "AA",
                        },
                        data::tag{
                            .key                      = "NJOCBT",
                            .value                    = "AGXKQFFGUSUJPYOSJYSDEGPIXKNO",
                        },
                    },
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "EKJGOMIBFQVXFPPYNDUXMSRZDLWSGRGZTLKYSD",
                        .extra                    = boost::json::value_from("ZHOULYEPTECPJYEPHZWVKWMMEEIHSVVMFZBNTATGJETJUKQMPVTGTSJIL"),
                        .log_level                = data::severity::error,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 93,
                            .base_delay               = 1s,
                            .backoff_multiplier       = 7839.3649,
                            .deadline                 = 5s,
                        },
                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                            {"ep_24", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "XBMZJSJVPEISCWRXNPUBFVTXTPGDGAEMHEBUKRXQMVKNDJSFS",
                                    .port                     = 31327,
                                },
                                .connect_timeout          = 1min,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 46,
                                    .base_delay               = 10ms,
                                    .backoff_multiplier       = 7002.1099,
                                    .deadline                 = 5s,
                                },
                                .tags                     = std::nullopt,
                                .tls_cert_path            = "YYPJG",
                            }},
                        },
                        .tags                     = std::vector<data::tag>{},
                        .nested                   = common::box<data::scope_override>{data::scope_override{
                            .scope                    = "TMKTZOJRBYBRVYRCFROTFZSQUPELLPMWUPSXJMHTYNKRYPDLBJGHIEKSGOT",
                            .extra                    = boost::json::value_from("YADOMZHIYUAELXWJKMFAJRJQXPQZ"),
                            .log_level                = data::severity::critical,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 55,
                                .base_delay               = 5s,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = 5s,
                            },
                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                {"ep_70", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "IGPFTRBHSOABKLTFPEFSGKKWJPCCN",
                                        .port                     = 44423,
                                    },
                                    .connect_timeout          = 1s,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 1,
                                        .base_delay               = 200ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = 30s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "QZYKITDFYXJBBLHNWLIFOKBABFKPLSTPNRKYLTHKEPCHZQPMVGNVBG",
                                            .value                    = "PEMOMHHTCZOLYBCUIJJEQU",
                                        },
                                        data::tag{
                                            .key                      = "HSMPMUIXPHBTHLZBSG",
                                            .value                    = "BVPCKNNZZJMOIRXBDRIIUGHNMV",
                                        },
                                    },
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_88", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "SFWVWOFDREQIJE",
                                        .port                     = 54534,
                                    },
                                    .connect_timeout          = 25ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 19,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -56.5802,
                                        .deadline                 = std::nullopt,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_82", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "HEDLYMCCI",
                                        .port                     = 21344,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 90,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 7074.7291,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{},
                                    .tls_cert_path            = "FPJUWTKJTJGDCPZCWMKTUWNGVASBBOKNCGMWGRHDGTWQCTACRPOBTWSWNSZH",
                                }},
                                {"ep_68", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "HMOPXQF",
                                        .port                     = 7829,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 24,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_9", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "KZJBOHK",
                                        .port                     = 30424,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 75,
                                        .base_delay               = 200ms,
                                        .backoff_multiplier       = 6345.5709,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "JTAVCWAMJO",
                                            .value                    = "IACSTCEHRNQJDSLZFPSUXDYSKUTXQSLIABFDLN",
                                        },
                                        data::tag{
                                            .key                      = "EFZRBDTOEJGXNNAWIJSLLXVBORCUJQDMNLMLGVLXNOLZDKBGLQNBPCGHEP",
                                            .value                    = "SKRODKOLUNVNDPWVPJFNZ",
                                        },
                                    },
                                    .tls_cert_path            = "XGJHXODGHKHFKCGDSREZYSUGMJKPBCTPQQZLNPGNNFRNHGKPZRSIWUAM",
                                }},
                                {"ep_48", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "TYWMGRXIXLWUDPCGBJSYUT",
                                        .port                     = 3863,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 33,
                                        .base_delay               = 25ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{},
                                    .tls_cert_path            = "AMOBNRYHUVRXDPSIK",
                                }},
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "CWZKZDKGYNCVWPPRBOMJGPGCROPWSJYFESVLDEFRD",
                                    .value                    = "YALXFQXDRRVTLVVEIJMQBYPWVTRSMDLGOXASNZBGFBQELNEOJFK",
                                },
                            },
                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                .scope                    = "YRVMIOSGHAZWJKGR",
                                .extra                    = boost::json::value_from("PYEOHQWSICOQQHIUOUBITOSXTCNLYO"),
                                .log_level                = data::severity::info,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 91,
                                    .base_delay               = 10ms,
                                    .backoff_multiplier       = -5745.4433,
                                    .deadline                 = 5s,
                                },
                                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                                .tags                     = std::vector<data::tag>{
                                    data::tag{
                                        .key                      = "DPJFOKWIDFUDQFAPBVBAOGPZYGILLGVGKMVPW",
                                        .value                    = "HJTXNCUUKPOLWVEGWNYOETYKOHXDMSQTLCLLUKCFTVASXFQWOOWHQYVNZZENG",
                                    },
                                    data::tag{
                                        .key                      = "GNXWSEXOAMAXJWAFBDMVTSWBSRGUDSBHPYMEIRAYEEIJHYW",
                                        .value                    = "CGEJPRAPHMBBGPN",
                                    },
                                    data::tag{
                                        .key                      = "ILMUPMTOCVWQYFRSDASTJJVZCDTKNZAWQDJHGANMUY",
                                        .value                    = "WUJTAKCOOVJTATWTHEEBSISNUMWUKQZKC",
                                    },
                                    data::tag{
                                        .key                      = "NOKJVXKGZYTGKQQNZORQHJYZDHECVVUB",
                                        .value                    = "OMKKJWCFNPMQZBCXAPSKNEDUMUBNQOYXHUFIWZGLDTRCOEQBXSXTRV",
                                    },
                                    data::tag{
                                        .key                      = "QXEIREBVAOTMBXUYCDBQHEKQIBISX",
                                        .value                    = "BGXQBMPTFBYWYLKOTJFYWZKWALASLVUOBTZXH",
                                    },
                                    data::tag{
                                        .key                      = "ZTMZFLVZ",
                                        .value                    = "CQYBIAK",
                                    },
                                    data::tag{
                                        .key                      = "OXOBBTZLJKTRVXPICMSQVQPKGDQRSXJWWFZOKPFWHYMEGI",
                                        .value                    = "XBJVFLZBOFMSS",
                                    },
                                    data::tag{
                                        .key                      = "FKNNYOQXK",
                                        .value                    = "WSZKVOFATGWPKFLGSYKZPEGSUWCSPSBIWZOLFISJKBSGOZQKPCXRKYYENHJLT",
                                    },
                                    data::tag{
                                        .key                      = "QJQUTVPA",
                                        .value                    = "VWQOISHQKKOVJFQNFUCQCWMWFMIUGIMBVXACJOBBWDKNYUISOVKRSYBLYFOA",
                                    },
                                    data::tag{
                                        .key                      = "LVDMVOBUHF",
                                        .value                    = "UNUCEJZJXFBZCWWVQAZJZLXRJJTSVWNWMZKFNOQNFDINMGBHJVQTHO",
                                    },
                                    data::tag{
                                        .key                      = "BZGXVYZROOCOPNGGFGXPO",
                                        .value                    = "MXXIHZAKEFESZMNIUCBUQYKSUFIKCVHXDDKXQXCZLARHRNP",
                                    },
                                    data::tag{
                                        .key                      = "VHUEPBWLFAUTHNUII",
                                        .value                    = "N",
                                    },
                                    data::tag{
                                        .key                      = "PGFKQ",
                                        .value                    = "",
                                    },
                                },
                                .nested                   = common::box<data::scope_override>{data::scope_override{
                                    .scope                    = "MTDEPCXOVRXYNGFOZQUANBZGJNZXHCTPSUDEREJJQKJTMBDDBIFTZTJ",
                                    .extra                    = boost::json::value_from("IVAECQVOLZRXUQMQSKOTBRSKIBDOTYKPWYIKRFXQC"),
                                    .log_level                = data::severity::critical,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 63,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = std::nullopt,
                                    },
                                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                        {"ep_73", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "WYVTHTCSOBZZBBJSMXZBBWRJ",
                                                .port                     = 39681,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 34,
                                                .base_delay               = 2s,
                                                .backoff_multiplier       = std::nullopt,
                                                .deadline                 = 15s,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "CQAWTPKJJGYGAPHBAGPODHICJYQZOJTBFRMVULVVNYCWXBLBGDGD",
                                                    .value                    = "KXETUONZPJNBAKQOYURQZKLXTXTZDONKBSVTQPZGWLRPGWVBURCROQJXYNDN",
                                                },
                                                data::tag{
                                                    .key                      = "BJPXPZOLFHXRXUIDNVKGXTCDPMAIRHZTMDTVIY",
                                                    .value                    = "QAOZTAMJHLIQHR",
                                                },
                                                data::tag{
                                                    .key                      = "RSYQOWLRODRGVEKAAKKYUTHDUCO",
                                                    .value                    = "KKFJASAZIKCKDSHLPBDHOUHPJSAWHROJZFADRVHXNNPRBSHURXGLGHKCC",
                                                },
                                                data::tag{
                                                    .key                      = "UGLUJEBRCPCP",
                                                    .value                    = "JHRJTPBDKQNDKPFMJRBZCMZGUTPXWQSJTZBLTNDZRE",
                                                },
                                                data::tag{
                                                    .key                      = "EBXJSXWXIIHXGGQHEELXLPBCXAORZJSXS",
                                                    .value                    = "AHALGZJDVTRPTIUJYIJMNYWYJFWMUV",
                                                },
                                                data::tag{
                                                    .key                      = "PFGPWQYXOYD",
                                                    .value                    = "NJCNHLEAFMHGHSYPNRYVQHTUBNODIURIHENOEK",
                                                },
                                                data::tag{
                                                    .key                      = "HRDTBFXPOPXKDRIUCAQADRKUCFMHOMFOKWCZXSMV",
                                                    .value                    = "GXQJZGNLAFUUGNFAOWQOXLHWYKQ",
                                                },
                                                data::tag{
                                                    .key                      = "OCFFUYCGDWRPISSHSAEEODQ",
                                                    .value                    = "OMLOWTQYHSYMCVPVAQNANXECGWYVSIWOYRBXUSBYU",
                                                },
                                                data::tag{
                                                    .key                      = "SEFXVGRZNBUXZKEGDHHRDQHCMGUPRBQRATUDGNKYRRAHXCOFVGR",
                                                    .value                    = "QUMTEATRVSZHASFSEIKNXMHLGMBWUZZDDOZYQNOXYRCUEWYADQTW",
                                                },
                                                data::tag{
                                                    .key                      = "HSSKBBDIQMVEVNQEBXPRNQRNX",
                                                    .value                    = "FKOQLGIZSFTAAKTRFJUNDVD",
                                                },
                                                data::tag{
                                                    .key                      = "ARRZSUMZKTPDSRSSKIMQSLGOFTLNLRXMKJDT",
                                                    .value                    = "CZNGVWKZSXJFQLZQ",
                                                },
                                            },
                                            .tls_cert_path            = "YQBHFZBTWWJEGNMMXEFLEISLNEVXZZCKGPUJANR",
                                        }},
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "GAZHKFCYNZGWKDH",
                                            .value                    = "FVOVHTVWVIZXIHUXAOEGPWHDDDHWWVEQMXXYH",
                                        },
                                        data::tag{
                                            .key                      = "MYFRNXEOOQEKXYOFOSVSYBGTOKOETXIELIIXEBMEHONOHOYJBUD",
                                            .value                    = "VARKHHDEOUNZEXVAEHIAIKWRAHQKXHSITHYHCBEJOXZYJ",
                                        },
                                        data::tag{
                                            .key                      = "SHVJSKOYGLNRFSSYPPFZBIIBORBPQWWJR",
                                            .value                    = "FAORGGDWJKDZFSRJDTRPXSUW",
                                        },
                                        data::tag{
                                            .key                      = "FJHEIOPQNQBCOCRUGOGGLDWJIBNESPSEUYQZPDMTCDRLXEHPBFPRXOPVXJJ",
                                            .value                    = "YSQWAXWSNCPGWMPFYRFXZPGEXVTAXMDHJSTXXXSJLCRCGDQVVBMJLORVIRAHI",
                                        },
                                        data::tag{
                                            .key                      = "KIQIACWSQHJJWDDWUQAKHLGQC",
                                            .value                    = "ZRILJWKPUNLJRZLDXRKUFDYJLAQYHFFSJUIHEWRRFFWDXRHJIRNA",
                                        },
                                        data::tag{
                                            .key                      = "AHBAZGWFQICHGCHLWVGPCFGXH",
                                            .value                    = "ARWAFITJLBZ",
                                        },
                                        data::tag{
                                            .key                      = "AWVJHGJSSSHVXPNATYDJBJHEMEMPIKTLLLUXJHTUQCVABZKWDUCHXSAWGS",
                                            .value                    = "GRHRYKTCDRWHEROZGNYGJIMM",
                                        },
                                        data::tag{
                                            .key                      = "GNUYPYXTRVSJCODTZPOIUUKAHARIKRFNKCHDGICPF",
                                            .value                    = "KIEDH",
                                        },
                                        data::tag{
                                            .key                      = "PHLFFHUHCLFZAFMZPGQFIV",
                                            .value                    = "VMKOKOBJJPBXURVGIUMMZZIDJBQLKBQJWCDTUTJOITMEGW",
                                        },
                                    },
                                    .nested                   = common::box<data::scope_override>{},
                                }},
                            }},
                        }},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "AJGALQHHEWUGZACKIRHXMDVYEBPSMDCJTHJIGOCOUCWFVZJSPOTSBSPWJZNPBY",
            .port                     = 46879,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"XJCS", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "UHSNRCCKLYECMVARZKLCDOJMHMPVMSCPRHIIB",
                    .warn_at                  = 8768.49,
                    .crit_at                  = -4387.8211,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "P",
                    .warn_at                  = -4309.1119,
                    .crit_at                  = -3579.5613,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "ALMCKGAYCCXZRTQSBQGKWJTBWRDGFCDVPTF",
                    .warn_at                  = 75.8298,
                    .crit_at                  = 7635.9178,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "PADOIYTOTDSMBOSHFPGXGLYYHUGIPLSWHFNHSOUDGBTDHJQLJ",
                    .warn_at                  = -5.9791,
                    .crit_at                  = 9630.9591,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "RFXVY",
                    .warn_at                  = -1047.6907,
                    .crit_at                  = 985.0406,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "ZAKZZHVFOZZOLULYQYYBPGJFRIXU",
                    .warn_at                  = -8562.8118,
                    .crit_at                  = 7962.8356,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "RJREYNZ",
                    .warn_at                  = 1835.9859,
                    .crit_at                  = -3642.9173,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "OATBAPQTXMXTKVCHYKDJUPRFARCEMYT",
                    .warn_at                  = 7073.1968,
                    .crit_at                  = -4249.4642,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "BWVNTBDUJGIRLRVDWXOPNDKMMZMBZKJLCWZTAQKEENZECMPMZJSC",
                    .warn_at                  = -6674.152,
                    .crit_at                  = 6701.1611,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "",
                    .warn_at                  = 247.6322,
                    .crit_at                  = 3682.0598,
                    .evaluation_window        = 5s,
                },
            }},
        },
        .warmup_delay             = 25ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
