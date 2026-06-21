#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_29)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/29.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "LTTJCQLMNABDOUHZLCPKTRNXGOFHNZNVZVS",
        .worker_threads           = 134,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("JSWUPMTYDXLEIEWKZCR", 39786, true),
            std::make_tuple("TVEKXWUXXVGVIAYAMNRENEJABXBYU", 30785, true),
            std::make_tuple("BQYAEFWOLHCAXGIPAEGDXFBUZMHGGURHKHYATDZWSIKHVNZBKNJSFJNV", 11616, true),
            std::make_tuple("AVKMEEFLTPMUQCKGPBOHSHOFUQUKFFBUOBURXOWJBDJHKHDGWT", 16461, true),
        },
        .allowed_origins          = std::set<std::string>{
            "FDVLZHDGSQTJAJNQRXRQBWNCHXKEEALOHTABXT",
            "FFBNKNJBEJULPPUVIMLOKRMBWCYRBIRJOWXZQXIAKBXLFO",
            "GHNHUIIRK",
            "GVDXFYSSCUICZZDYHGEBIYYLYVKXC",
            "ITHZGAMFLIQDISXWAHYO",
            "K",
            "MTSJCHCVZBDTJFFMZVYKEROFDLEABQMFNACQVMWNY",
            "QEHCYURDIJHAWCKSKGKCLHUPZHGEMFAJIV",
            "TKERWHALYQBXJCBFUVGOHVXEVBYYELGHALVDUNJBSBKPBBVRKKNBD",
            "TVWKGDXIXIXAUSCKUICYWASIRRRYVZEOXVGKLVZH",
            "VLJDTWR",
            "VSYIIUKYLCKVQEAWWHTHPZXAFULHAANZLAUH",
            "ZWFQAOHKGYNWYGGMOMRQTBGHOWLKQJQRGIQXHHWGHHUGPUJYBVDNYEAIXS",
            "ZWKZXX",
        },
        .config_tree              = data::scope_override{
            .scope                    = "OEOMTQJACQMW",
            .extra                    = boost::json::value_from("XVFLYRZYLYGXRYYVWLEWRRAZQAGJBZRRZBSVHISVKZ"),
            .log_level                = data::severity::warning,
            .retry                    = data::retry_policy{
                .max_attempts             = 91,
                .base_delay               = 5s,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_72", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "KKBWLWNIMUHBPRISGMZBPKRYTEK",
                        .port                     = 57082,
                    },
                    .connect_timeout          = 50ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 88,
                        .base_delay               = 10s,
                        .backoff_multiplier       = 1445.5261,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "LNSJBYMACEXLAETODHJJ",
                            .value                    = "QFPIRCTQSUCKHILSFLNGVKTEVDXJIJMHIOWABPEE",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_8", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "TVIAVAYGCVAJGAAORTDIGOVHBSFWGXMIVCLDYYXMNPHOVFL",
                        .port                     = 10808,
                    },
                    .connect_timeout          = 25ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 59,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -864.3482,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "JNMNVIKPWGUIMENEHEV",
                            .value                    = "PFULRNIZFDSAVVWJLWGZHBMHCHH",
                        },
                        data::tag{
                            .key                      = "UOLNKBLDKYNSFAKXVBKKWWLDBKTQOQHMTENYSROFNCMZQUBHO",
                            .value                    = "EHNVYRYTQOU",
                        },
                        data::tag{
                            .key                      = "ZJICOKRYOBZGCFKNSUVWAXRAFUTJMMCYAAHEWOEGAWEOMZCVBKBCYDSTV",
                            .value                    = "FZEWBSRRJP",
                        },
                    },
                    .tls_cert_path            = "PKCKKFRAIJPOLSLQIDPXPDZDYRJKXWVUJ",
                }},
                {"ep_52", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "DXIYVACFZUNRBHJFI",
                        .port                     = 50448,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 44,
                        .base_delay               = 25ms,
                        .backoff_multiplier       = -1483.228,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "WLROCHVRWXORQWAKWOGBNIBMPAMTVWE",
                            .value                    = "NQDYOCHUIXASKIGNJABWFZJTEHNIRWWLPCQZRWQABQSROYULOJTS",
                        },
                        data::tag{
                            .key                      = "APRYGTRCDYCJYIHIGSAXLSUSQAPTEWRXEQXHEYFBFLYHPHDHADRJXTNMX",
                            .value                    = "HNQECVZDSHZFHPTDEOEXINHBMZQ",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_67", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "IFVLEAJXFAXRYZ",
                        .port                     = 51953,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 26,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -7053.6169,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "NQMXRRKJYSWWEJOLKVLBPPEL",
                            .value                    = "ZJXEXKFJZDIKVBDCOEWLQ",
                        },
                        data::tag{
                            .key                      = "URGSWVQOBJXIJETPO",
                            .value                    = "MQSZEIMVNBOAKLPMAODTRVSKZSJVWMCBQXTIJNCOWUAOPUGSVQEKGBDON",
                        },
                        data::tag{
                            .key                      = "EPZGGCXCSVXLTASPKSSVEBYIGAADTVYYSGOECRUGTGPDSCGJM",
                            .value                    = "QQXBRMJPYVOLTVHXRQLCVHNBPRGZMKIWXFEBXKPZVVRVLPOTDDRIR",
                        },
                        data::tag{
                            .key                      = "VQBKXFDKCJOM",
                            .value                    = "YXVVSVBSAZNQPWUEFIRRYFFUS",
                        },
                        data::tag{
                            .key                      = "RLRYKXBQ",
                            .value                    = "RLMQNTXGWSYNBJGHKCTQTDUESOPJDFFKOFYEMXUPKGQECVJLVJYIIVREKDYD",
                        },
                        data::tag{
                            .key                      = "FMYYYCOQKXJAYHKGUUKSHCHTQZKPSDLDQGIBGFWRRVEIGBAETDGCUMZSF",
                            .value                    = "YHLUCGPEDQWMMYUCILZFTZFMWYGBXFCOGQKJQQFGCVPACTLHIRJWEQXU",
                        },
                    },
                    .tls_cert_path            = "QLJZRPZAIUMWDIWKHGVAEIBCXBLFGITLDWDRGJLNZPMHAGVCARRRLMDHWEWZR",
                }},
                {"ep_89", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "PWTUTZBEJCBXGDGYTJFSBVTKAMKAEMGVNWZCHJCWQVXHXLWFAMRMWNRMYTCSWNJ",
                        .port                     = 9182,
                    },
                    .connect_timeout          = 25ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 43,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -4256.4374,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "NAXYECSGRNPUETRCEEZKBSSTMDLSRCHIFPXYNTASIPMCEFPIDDNMHYONWL",
                            .value                    = "FMYPCNPVZXCSGKTMBXROBVK",
                        },
                        data::tag{
                            .key                      = "PNUYVKZNXZWQHNZUKPVIGDQXRFKSKOIJJLIQFFZQO",
                            .value                    = "YRHOLTQPDWLRUVYHDCQHBGLCAKTGGKEQZI",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_13", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "RWGOOET",
                        .port                     = 27603,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 80,
                        .base_delay               = 1s,
                        .backoff_multiplier       = 137.2346,
                        .deadline                 = 10s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "MMBVJXCDYGDCUMCVIVBGRGNRPTPLLEJYHMZRZRFQOMKSSBPSXTFSLS",
                            .value                    = "XZMBRICUP",
                        },
                        data::tag{
                            .key                      = "GNCRHG",
                            .value                    = "BFGRAYXGBUXMIXQOJUJVVNRSJGLP",
                        },
                        data::tag{
                            .key                      = "CGUMKOLPVLTKJNOSCIXTUNVIUPEKCPCMKFVDMBANQVSAZGMLQAEEVQEY",
                            .value                    = "FYVGYBCOQRHRRXE",
                        },
                        data::tag{
                            .key                      = "ABYHYMTMDHMNITWGVGOAQXKJHRAXRTAWOTGKJJAYRANUKDYLHAKDPY",
                            .value                    = "COSFPYQPSJDCFTSXRHBOISNWFINWFGYXGMISCCDSUCFOYGAQYWIP",
                        },
                        data::tag{
                            .key                      = "GBYTXFVMPWMWSUVWECVFSWHQCONCITPBEJHLZVDPGSSTJMIKQVZALMWMHKRN",
                            .value                    = "SZTROPGIEBUJLOWBOUQLBLQJRVNLCHLUTSWVHIEDNRZLLMFC",
                        },
                        data::tag{
                            .key                      = "YUBPXNVLWLDFWPDNXBDITN",
                            .value                    = "LBMBSBTJYNOEFDWTT",
                        },
                    },
                    .tls_cert_path            = "TMDJGOBUUCGWCOMWKMJFWLDWSYUGWANXX",
                }},
            },
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "TAAUXGPWLVXVAEZUUCBRNEED",
                    .value                    = "LSNVOYXESHDWZIEIXRNMGZ",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "VA",
                .extra                    = boost::json::value_from("UZYWSPENPAZE"),
                .log_level                = data::severity::debug,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_33", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "F",
                            .port                     = 50755,
                        },
                        .connect_timeout          = 2s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 92,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = 4383.4306,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "HEQXTQDZIFBEXUJEQNHO",
                                .value                    = "UBXRVHWENXGLRGKTHVHRHSLUFYXWHFSSJRGNRKRZDYVGQWGDTMVVBSVFPMTH",
                            },
                        },
                        .tls_cert_path            = "TPNHQAHDLPPKGORNCQMLKSMJIEDZUGOHAGULBIABTTWXWAL",
                    }},
                },
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "RZUNSUQJLFRKFHKGNABRJGKWJDLDEVENOGFTRKFM",
                    .extra                    = boost::json::value_from("P"),
                    .log_level                = data::severity::info,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 67,
                        .base_delay               = 25ms,
                        .backoff_multiplier       = 6833.0735,
                        .deadline                 = 1min,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_74", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "FDHCRNKXMVWXKYMNNHRXCCWSRSELBYAQFHNWZVBCGXSHMSSOINGD",
                                .port                     = 34881,
                            },
                            .connect_timeout          = 200ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 85,
                                .base_delay               = 2s,
                                .backoff_multiplier       = -2311.7636,
                                .deadline                 = 1min,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "NMMNNOFUYJMXUXUIOYRFUPWZRYIMETQFJIJHTUFZXFTIFPCSGC",
                                    .value                    = "IOYZTUYBUACYUJFJOTSPZSYCRXYHPXAKFGPGHTCI",
                                },
                                data::tag{
                                    .key                      = "GCWTKZVJWQ",
                                    .value                    = "OQLJLMLFTTQSCLQGFMWIVZPEDYKKLSVVQNVNBNYYHNVPDYRNBXRHCK",
                                },
                            },
                            .tls_cert_path            = "LRXETMTOTROELAEOAVLKCFI",
                        }},
                        {"ep_20", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "BBCGJMZNJZVRZCXWQDPKLYCPCBLWNOBLPTFXVZEHRKWWQVY",
                                .port                     = 19865,
                            },
                            .connect_timeout          = 1min,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 23,
                                .base_delay               = 10s,
                                .backoff_multiplier       = 9907.8057,
                                .deadline                 = 1min,
                            },
                            .tags                     = std::nullopt,
                            .tls_cert_path            = "JH",
                        }},
                        {"ep_26", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "EFTFUNDNPLSNLD",
                                .port                     = 4961,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 20,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -2276.6224,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "PAIGYQBHHTYSALSSIDDPNQ",
                                    .value                    = "VUKJCO",
                                },
                                data::tag{
                                    .key                      = "GUVAATIQIOPPHFQCLOJECSFGPOJ",
                                    .value                    = "ZKFBHKASYBGMEJOXWTJILYEIVIRAIMCCFIX",
                                },
                            },
                            .tls_cert_path            = "GLWVIPYFIZYQCMCBBYSGIYYTPSNBQZADVQPD",
                        }},
                        {"ep_15", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "RTYDEDCLLDYQGCKEDTTLMYIHCYH",
                                .port                     = 63486,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 14,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = 3030.5773,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::nullopt,
                            .tls_cert_path            = "VYRZHZEZLNSMUONAYJHWYLSROYSEYIXAPGLOHTVICTLYDWOQ",
                        }},
                        {"ep_94", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "RYOGWPVNHLCZRYYPTIZILZUZWNHBKOAW",
                                .port                     = 53303,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 88,
                                .base_delay               = 25ms,
                                .backoff_multiplier       = 3527.3801,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{},
                            .tls_cert_path            = std::nullopt,
                        }},
                        {"ep_52", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "PTHYRPYXNLDYGIUFPQFDSWDNFPIFHTNNFFRFMJLDJCNQAHUZGDECAFDOKB",
                                .port                     = 430,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 89,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "HQJURFTRTT",
                                    .value                    = "YJXQRYPM",
                                },
                                data::tag{
                                    .key                      = "DYJPXVSVOJUWT",
                                    .value                    = "NKBIQNOGVFAYCIKGTLQUQGWIJZGF",
                                },
                                data::tag{
                                    .key                      = "NBSOFSLSJMFWPXXWPXDHPIIRSPENVMFENAXBMEQESSMNLFXUHKGAESRYSVCA",
                                    .value                    = "TVI",
                                },
                                data::tag{
                                    .key                      = "MRJREWVZPUYOQUTNDNNWOFWZINIIMCXMHYGSREUYJOZPERDEKDMWWQLZECMXC",
                                    .value                    = "LUJTIEKZNBSGJJAXPFUXLXRWRUSPFCSAJUILJK",
                                },
                            },
                            .tls_cert_path            = "IONWVYLJCU",
                        }},
                        {"ep_11", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "JQKVPAKYDKNZRBOVCHBZOMP",
                                .port                     = 40337,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 73,
                                .base_delay               = 500ms,
                                .backoff_multiplier       = -251.4071,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "HFBQNVTKPBJVKSCEMGIVOCK",
                                    .value                    = "TDW",
                                },
                                data::tag{
                                    .key                      = "ENCPMPSIREZINSPSJULGAGIKOKXZYFTPOVKFKQQLNFRYTFNAWEVKGNJPMD",
                                    .value                    = "IXMNLQ",
                                },
                                data::tag{
                                    .key                      = "FVBIBEIUMJLJHHOFAMOLSUDALYQTXFWOJPDIQWECVYKNVJFPX",
                                    .value                    = "VHEDFZFZRRIFWFYZHMVLCLPKU",
                                },
                                data::tag{
                                    .key                      = "RMBGBACDCQQZKCIZRUTOTTAUDYNEGWNMJMBYERVEGDSUNAFTGXTTQHOAZK",
                                    .value                    = "ACGWBXXKMEVDNNRUDRYAVYSZIXC",
                                },
                            },
                            .tls_cert_path            = "RZQCQKTXHXIIAHMGEZSJJXWGCA",
                        }},
                        {"ep_97", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "CCBAMFSDRPYXQBGNGNAICUROIEDHNJHLRDBKJBAAAGIVPZGELWDZPTUXSHWC",
                                .port                     = 56390,
                            },
                            .connect_timeout          = 1s,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 77,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = 3163.3263,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "UONIJBGEAUHOUOGEWSQZCRBIAWZWAPGADWJVZJWZAJOUQYMWQYDK",
                                    .value                    = "DTYIJZHQWNNKACCZYFKSYBUCVSBPKQN",
                                },
                            },
                            .tls_cert_path            = "IXIVFNNYQR",
                        }},
                        {"ep_28", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "YEGKQRKCGHCBPPXOURAXPBFROFWNPQAKGZFCDXHFTTMMK",
                                .port                     = 29451,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 33,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -5047.1837,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{},
                            .tls_cert_path            = "HMGWZCQZUMI",
                        }},
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "OTGWYTBWDBYMTTDPUUEKHLOPBOKYON",
                            .value                    = "HJTLWVCXQMZHIRQRGBGLEZTMBBQRZIGX",
                        },
                        data::tag{
                            .key                      = "KBLGLPZDPEILYRJQKKWAQQZIIDIFECQKJSMJVSAQWCVCHQP",
                            .value                    = "NESL",
                        },
                        data::tag{
                            .key                      = "VZHRBHU",
                            .value                    = "",
                        },
                        data::tag{
                            .key                      = "ENYWAZLJKHBNTMTJHBTERQRPMXSLEDCLOMEIXXSBXTQNNMDOBJGKCPL",
                            .value                    = "AIDG",
                        },
                        data::tag{
                            .key                      = "WCMUXTMDCLT",
                            .value                    = "RGCOATVWCTHNXMRSTAOBUPSAWRMLJOWESITGADXACASLBAVGEHAUGCVYYDM",
                        },
                        data::tag{
                            .key                      = "ABRXUROUQWCRNEXUXKWRAEJEJPERDVIWVHHIEDKVZFFYZMZNMWCSHWUNLG",
                            .value                    = "WDGJRULYOYTTPJWFQPFHYVBMPZBDPIZ",
                        },
                    },
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "RF",
                        .extra                    = boost::json::value_from("OQYLWJKQHLNQDXBGVLQAKZZPQZENQ"),
                        .log_level                = std::nullopt,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 70,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = 470.9368,
                            .deadline                 = 5s,
                        },
                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                            {"ep_95", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "FZMTCYJSCEIBTJXPK",
                                    .port                     = 61903,
                                },
                                .connect_timeout          = 10ms,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 35,
                                    .base_delay               = 5s,
                                    .backoff_multiplier       = -4826.2125,
                                    .deadline                 = 30s,
                                },
                                .tags                     = std::vector<data::tag>{
                                    data::tag{
                                        .key                      = "ERTMCQRBFEYTGCBT",
                                        .value                    = "WALUIOBVTMMXIJTJTH",
                                    },
                                    data::tag{
                                        .key                      = "G",
                                        .value                    = "TYJLWDFPQSOUSOHDFEPELMSMEWEFIZJMQUQRXHUMWOKUCSZTBMROEGQT",
                                    },
                                    data::tag{
                                        .key                      = "RLAHIBJNZKXKLOSBHFNDPYURSPWOIBV",
                                        .value                    = "NLQOKLSNAWXOWVTEERZOFJPBPOQWPPMENEUERPAUGEBXNFMC",
                                    },
                                },
                                .tls_cert_path            = "CZUUOXBPZOZDZYGIXNEJAJLXKUAXCSLYPJQZRDRGUQFZNPIWIILAWDATNHHYA",
                            }},
                            {"ep_8", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "NLNQQZXROPYWOACURGKLIAWKSMRMWYJHOVPCCDNSUKJVFSDHAHEWJPXCMIHEUO",
                                    .port                     = 44995,
                                },
                                .connect_timeout          = 10ms,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 11,
                                    .base_delay               = 10ms,
                                    .backoff_multiplier       = std::nullopt,
                                    .deadline                 = 1min,
                                },
                                .tags                     = std::vector<data::tag>{
                                    data::tag{
                                        .key                      = "OSBCBZINCLTRSISJFQOQOOELOVQPTHPUYSDCNB",
                                        .value                    = "TSLFDEPIEHRLVIXVCEMLFKWONLUIUOTZGDFVQRQ",
                                    },
                                    data::tag{
                                        .key                      = "AHLFDWNBNUYLGITQERHCUWL",
                                        .value                    = "LOKEJHVBYNICBPTHHHP",
                                    },
                                    data::tag{
                                        .key                      = "RTAQJURBYZKKSNCTWFFOJJJNNK",
                                        .value                    = "KABLBSHBLGQPHYJGLAXOLYRSFVDQNTZWCGZQHEJWKHXJMD",
                                    },
                                    data::tag{
                                        .key                      = "VEFTOQGHGNSYNNAJMBEVOYDOSNNKTPZLIRHRULFCVSHW",
                                        .value                    = "LRECFGCMGRMCTGLGQTWQQEVUEWHQFOWUS",
                                    },
                                },
                                .tls_cert_path            = "DVYUQLMWAKOGGLGFBIWGMXQEPJXFHUFJTXHIFEXCJL",
                            }},
                            {"ep_24", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "NUBZPJZRDKRRNUMMETUEYOTUM",
                                    .port                     = 1835,
                                },
                                .connect_timeout          = 50ms,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 3,
                                    .base_delay               = 25ms,
                                    .backoff_multiplier       = 6156.1016,
                                    .deadline                 = 5s,
                                },
                                .tags                     = std::vector<data::tag>{
                                    data::tag{
                                        .key                      = "LTKYMIUWBDQMBTEKOULRPMFWKSAPBWMQDJMCAQUKJWSRMPRQDSVJVWCCKVT",
                                        .value                    = "IKHQMLBYVQUIFXPXXVOBKZGGNBAOQSNCHUVLYMQDXTCRFDPRKFEHEEE",
                                    },
                                    data::tag{
                                        .key                      = "LRPFBLKHNJHXJQTTLUEDMFGPZNSHZKCVDEGOTKEHLDZDAJTTCSBVYEPOP",
                                        .value                    = "KKNAMBNREHZQQQXKRYZRZHMTSTOAPXDYYOHAFHI",
                                    },
                                    data::tag{
                                        .key                      = "NQRYICZSEWMNDRMADEWYYAIVPRQMGK",
                                        .value                    = "ZWFXRAM",
                                    },
                                },
                                .tls_cert_path            = "EKW",
                            }},
                        },
                        .tags                     = std::vector<data::tag>{},
                        .nested                   = common::box<data::scope_override>{data::scope_override{
                            .scope                    = "GCLZWREVUZCOIOFIHIWWOUWSFDMLKJGEIBLKFXMQEUJMQNYAIONWLA",
                            .extra                    = boost::json::value_from("OGHFIPNFUAY"),
                            .log_level                = data::severity::error,
                            .retry                    = std::nullopt,
                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                {"ep_78", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "HAKGGWKEGXASNRUAVWOAWEJPIXWHMZ",
                                        .port                     = 56308,
                                    },
                                    .connect_timeout          = 25ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 54,
                                        .base_delay               = 2s,
                                        .backoff_multiplier       = 719.0275,
                                        .deadline                 = 10s,
                                    },
                                    .tags                     = std::vector<data::tag>{},
                                    .tls_cert_path            = "BPYTXTYFHUTNHTBQYSAJAISXJOJPWQSBGQPSTAKIGLBKCERUGU",
                                }},
                                {"ep_39", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "YDVWCFWPVQLAWYLYOONNKOVJEAOXJFZHFBNKWXXDY",
                                        .port                     = 28543,
                                    },
                                    .connect_timeout          = 2s,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 98,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -8903.511,
                                        .deadline                 = 5min,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "VKEZDEYUBKSCASJOPRSNWERRMWHMZGGXCFUWWQVSWMBSDBDBXSDVLDHYUUFSKCP",
                                            .value                    = "SPKNNMONBHZQGDSXADUJCTHWKTRYUGXAEHXCJQHKFZTFMMKOF",
                                        },
                                        data::tag{
                                            .key                      = "EBCRZRCNGXCDIUPSTIICSYIHNNJYNKFSVRLOHHGRLEPEINMXBMPJKJAXJMQ",
                                            .value                    = "IXTTRNWJWGZYAUKNSBIITREGDS",
                                        },
                                    },
                                    .tls_cert_path            = std::nullopt,
                                }},
                            },
                            .tags                     = std::nullopt,
                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                .scope                    = "ACURTZQQPWNFINOCVSRRCPFONTTKN",
                                .extra                    = boost::json::value_from("IAGHUZALDTMJFHXRCMZYEQMKMZESKH"),
                                .log_level                = data::severity::debug,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 46,
                                    .base_delay               = 10ms,
                                    .backoff_multiplier       = 5068.1725,
                                    .deadline                 = 5s,
                                },
                                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                    {"ep_27", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "AUA",
                                            .port                     = 20843,
                                        },
                                        .connect_timeout          = 1min,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 98,
                                            .base_delay               = 10ms,
                                            .backoff_multiplier       = std::nullopt,
                                            .deadline                 = 10s,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = "DGGBKXJFRYAZHQYIYQWFSGFWQSDVAWQPGQAPBRULFGAHBHOJIEQF",
                                    }},
                                    {"ep_99", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "UXAMCOZIWISTZUAOHFDCLHXIFANQNJKTRI",
                                            .port                     = 29275,
                                        },
                                        .connect_timeout          = 100ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 53,
                                            .base_delay               = 1s,
                                            .backoff_multiplier       = std::nullopt,
                                            .deadline                 = 10s,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = std::nullopt,
                                    }},
                                    {"ep_18", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "WCQGQNAORVPLZUMZAPUWTTPTPEE",
                                            .port                     = 5187,
                                        },
                                        .connect_timeout          = 5s,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 87,
                                            .base_delay               = 5s,
                                            .backoff_multiplier       = 9141.5268,
                                            .deadline                 = 5s,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = "KZCUIUUGCEOMWPPIUM",
                                    }},
                                    {"ep_94", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "RLYUWMFOHFXXZWCUSOHEXEJKZZGPWSNAKMUUSBEAJJUFILXQY",
                                            .port                     = 30492,
                                        },
                                        .connect_timeout          = 200ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 68,
                                            .base_delay               = 100ms,
                                            .backoff_multiplier       = 6581.1569,
                                            .deadline                 = 5s,
                                        },
                                        .tags                     = std::vector<data::tag>{
                                            data::tag{
                                                .key                      = "PSMRXCJLHGVRROYWNCNQZAOWCVZPOAINZFKREBWXTUZPJTZQUDAJVNFHLMIYCIS",
                                                .value                    = "GWNHFRIBJZHHK",
                                            },
                                            data::tag{
                                                .key                      = "LWOFFW",
                                                .value                    = "EFNPIB",
                                            },
                                            data::tag{
                                                .key                      = "LSVOW",
                                                .value                    = "BTLIZNQDWFFTWIRL",
                                            },
                                            data::tag{
                                                .key                      = "KVPGXDQKVIXJZEEMVJNPFWILNNYJEXTPEPMSDEDRIDIMMULXPM",
                                                .value                    = "PMXAYZDQPOKVFTOIYAZAEADDYGSAMHEFNWIAKICLSKYHEVOQFIWVYGWB",
                                            },
                                            data::tag{
                                                .key                      = "ATMDYIOPJNFKJKZVMUOESOEMYKNUBDBCENKNPUVTMSPXGJTVTMA",
                                                .value                    = "PAQPLIGVZKWZHPFWAFGHOJRZXCJKGFGTNYFQPWVTB",
                                            },
                                            data::tag{
                                                .key                      = "HFUJMKMMC",
                                                .value                    = "HGPKNJRUSRYSSHIMRMQEVONQYNFNKTCDZJQQJYEQUPPZZTKDHK",
                                            },
                                            data::tag{
                                                .key                      = "GTFGYFHDHQRQ",
                                                .value                    = "KBDUBLJQNYVVQTAMLOAUOZDSMFZPQDVXKSZUHEUHILWKCG",
                                            },
                                            data::tag{
                                                .key                      = "FMJUEKDUCACSCZVAVKGLSVEPIJWAODOVTZGVBWWHRDQE",
                                                .value                    = "HAVSCWNGBBSUUIQETPUMIGIPELEWOPHFTDDXBSKJLMNJUKI",
                                            },
                                            data::tag{
                                                .key                      = "NZLELZWIRLDGDLHTLMMPBDBWDYCUB",
                                                .value                    = "VMBKCYYEHHDDAAZHUOIYPSYOIZPQRIOTFDENAOHYJWZYCTVQQVCXKZKNN",
                                            },
                                        },
                                        .tls_cert_path            = "ODCEOOEORWDEBGWJVXCMZIQGGTKYMJANACKJVOORPBLHTQOYNFOYIFARIKWI",
                                    }},
                                    {"ep_83", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "",
                                            .port                     = 54362,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 99,
                                            .base_delay               = 10ms,
                                            .backoff_multiplier       = -6200.7036,
                                            .deadline                 = 5s,
                                        },
                                        .tags                     = std::vector<data::tag>{},
                                        .tls_cert_path            = "LUWKVOGZZXRQMCHVMDXGOWWEVAZJJZHAEJFZS",
                                    }},
                                },
                                .tags                     = std::nullopt,
                                .nested                   = common::box<data::scope_override>{data::scope_override{
                                    .scope                    = "LVCGBYZYQHESSOXHRTOURZ",
                                    .extra                    = boost::json::value_from("XLXEHEHJJBHCTGCZERAIPNYQESEEPOOKLOMVLEWDLYXXJLTBJPZEFDONBXGPPTU"),
                                    .log_level                = data::severity::debug,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 67,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -8007.0112,
                                        .deadline                 = 10s,
                                    },
                                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "QLTLSRFUSI",
                                            .value                    = "SJFFMKKXPYWGVYUDLNLNNFHKSFCFRWHZGZGFRUELNPBU",
                                        },
                                        data::tag{
                                            .key                      = "AYIYGLGPXEWZUPSWMKIZEOVAQXXV",
                                            .value                    = "RIDCFAPDXBRIOLLZMFLCEEWMFSZWIXWCU",
                                        },
                                        data::tag{
                                            .key                      = "",
                                            .value                    = "XOBYIZGODZQLXBEDZLZSNMSXNJGJWEQWRKWNYLYAJHPBCCKYRYEJFCEYMO",
                                        },
                                        data::tag{
                                            .key                      = "DXCBNJHEGAJOHJCZSDHRTVNPGLIVKZXEZLEKAVEJOS",
                                            .value                    = "JQAHNRPQMXMPSBCGANJGWS",
                                        },
                                        data::tag{
                                            .key                      = "Y",
                                            .value                    = "ACBCWZCIRPMAHFCHFPGJQIELKVXXFUNPHOPYVOGNESHNEZH",
                                        },
                                        data::tag{
                                            .key                      = "XLADJE",
                                            .value                    = "DZRKSQQRLBGDI",
                                        },
                                    },
                                    .nested                   = common::box<data::scope_override>{data::scope_override{
                                        .scope                    = "WTXQMZEHBLHXOBFKNVMJRANAIICSRTOCFCFFYPVGJUZTMJCSGPCKZRSTH",
                                        .extra                    = boost::json::value_from("SCEMLWRVUWRKWLESCPKRVQOADLAMERZRKKZ"),
                                        .log_level                = data::severity::info,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 85,
                                            .base_delay               = 10ms,
                                            .backoff_multiplier       = std::nullopt,
                                            .deadline                 = 10s,
                                        },
                                        .endpoint_overrides       = std::nullopt,
                                        .tags                     = std::vector<data::tag>{
                                            data::tag{
                                                .key                      = "WTJUYYIARAYBSGDFDJVHANSVO",
                                                .value                    = "IKEZRCDFRVUORVLAWP",
                                            },
                                            data::tag{
                                                .key                      = "HIPNMKEHJDLFOYHAOFAIGJXBKUWPMOJGSMXVNJIYZZEPCM",
                                                .value                    = "AMYIUVKWZAR",
                                            },
                                            data::tag{
                                                .key                      = "QVOUCBDBQRDRSXGBVVEL",
                                                .value                    = "CDIYDHGXJEZC",
                                            },
                                            data::tag{
                                                .key                      = "NZRSLZRGCBDDNKGRDZGJEZYPXHEOIJZRQFHDDOUXVZVCBSKRACIGAI",
                                                .value                    = "KIUYDLWJCGELKGYJ",
                                            },
                                            data::tag{
                                                .key                      = "TGWWHUFDIUALYFMTNPMRJEYCHSGVOXNUYNVMZJJEGODKMHR",
                                                .value                    = "XHVSOFCAAQQAGLQALYLIIQRSOUXVBBWJANYFMFDEJYICUNJ",
                                            },
                                            data::tag{
                                                .key                      = "MTVTOQJTHYMEJUUOOKWNFXMNTULBDWPFQATUGDYIMBMDXYNWQPHCP",
                                                .value                    = "ILSVKZJDSCZNHNJCEUQSJDHAYXXTXKJLAXUFEVWCUMOXCZARGGTKKT",
                                            },
                                            data::tag{
                                                .key                      = "FPTK",
                                                .value                    = "NPXVRCGHULODLFOTGKJX",
                                            },
                                        },
                                        .nested                   = common::box<data::scope_override>{data::scope_override{
                                            .scope                    = "GKLTEPVQFPKTMIILWKVAXEWTQCLDCVS",
                                            .extra                    = boost::json::value_from("DHGYICYWPGL"),
                                            .log_level                = data::severity::info,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 43,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = 8100.4416,
                                                .deadline                 = 5s,
                                            },
                                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                                {"ep_27", data::endpoint_config{
                                                    .address                  = data::network_address{
                                                        .host                     = "UXYAPURQFJEWISDDITCDIWPUXZYORQLUODJUOPPFLAXKTDVUPUSLTUQZWAPX",
                                                        .port                     = 26697,
                                                    },
                                                    .connect_timeout          = 5s,
                                                    .retry                    = data::retry_policy{
                                                        .max_attempts             = 74,
                                                        .base_delay               = 10s,
                                                        .backoff_multiplier       = -2311.1461,
                                                        .deadline                 = 5s,
                                                    },
                                                    .tags                     = std::vector<data::tag>{
                                                        data::tag{
                                                            .key                      = "ETXGZHKCSYDCKQOBJTHMTPXRQUNQZTWJURWTGTCLULJNPSOKOEUXSUVSEQMFUTK",
                                                            .value                    = "DTCNGZGITA",
                                                        },
                                                        data::tag{
                                                            .key                      = "WLHWHEZFVHMEKGOTXKZQAIPKHOBMSZZINPRBRNRADRPHNINBQGJLVJ",
                                                            .value                    = "SMAACTYRGTNOOWPV",
                                                        },
                                                        data::tag{
                                                            .key                      = "YHZMFOIACCDWOBME",
                                                            .value                    = "HBCRMBAWVWLXXIDAESCJAGBBWSAMDQGFOBGTGCJMMCWSEZJQGTEM",
                                                        },
                                                    },
                                                    .tls_cert_path            = "WQIQRRDATZWLBOSNJEZJEXHWAOSTTTRHNE",
                                                }},
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "EIJBIRYBNFELIWSTBRDOYB",
                                                    .value                    = "JUBSSQPEKNHHLKS",
                                                },
                                                data::tag{
                                                    .key                      = "DMHSZMIFAQPHYGXRCVYQUKBBTBMRFWCIFU",
                                                    .value                    = "IUNHETSCUJGJTPILOHPHXNNNNZPRSZQHECHICMODWUSJLLABKHCODLSSRPDRGAZ",
                                                },
                                                data::tag{
                                                    .key                      = "SJNGLXXLIOFMDOQRIWHYLGFZHTGHUQB",
                                                    .value                    = "WGCBHHFDTGQGJPXXBYSXPCLLXAHUDXROXNPKQLBXDFZELVACRKFC",
                                                },
                                                data::tag{
                                                    .key                      = "TKUBYMZQXRLWJLRRCBNORGU",
                                                    .value                    = "GCMMKKSUTFFOZCSLTZKMVZXSHOCBZTSRLFRIGDCYXNRHGV",
                                                },
                                                data::tag{
                                                    .key                      = "PEFWPQNMJJYLEARBRYRCFSBADLTMFFFZHQOGDBELCSHYPYU",
                                                    .value                    = "CLLRYE",
                                                },
                                                data::tag{
                                                    .key                      = "FQPGLNJXWMSCDO",
                                                    .value                    = "ZEKBPSPDTJGMDSWRDWFKBDJRFVXUFTEOWMJWD",
                                                },
                                            },
                                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                                .scope                    = "RRRHSQGGVYFLQTQPITNLYOXEM",
                                                .extra                    = boost::json::value_from("DZ"),
                                                .log_level                = data::severity::debug,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 14,
                                                    .base_delay               = 500ms,
                                                    .backoff_multiplier       = std::nullopt,
                                                    .deadline                 = 5s,
                                                },
                                                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                                                .tags                     = std::vector<data::tag>{
                                                    data::tag{
                                                        .key                      = "HYQROENVFKQHMTUOCGVHFQNAGAVTJ",
                                                        .value                    = "SNVFPDPIFWSNCYHSSUIIS",
                                                    },
                                                    data::tag{
                                                        .key                      = "XKBISQSMJDIBAWEAELXQCQSFIWQXEDYKUBIYSHOCMUR",
                                                        .value                    = "DCETNZZEOPZFROTXQOEWUZIIPCRACYMNUXJGNWEZBDZBZJJUJQYXZLBESNNGFUT",
                                                    },
                                                },
                                                .nested                   = common::box<data::scope_override>{},
                                            }},
                                        }},
                                    }},
                                }},
                            }},
                        }},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "JRCTRYAARXAPQCLN",
            .port                     = 9353,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
