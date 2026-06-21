#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_17)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/17.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ZJLJFYWWRVIDAHMXNIQZKUVXMERBEZGEW",
        .worker_threads           = 136,
        .enable_tracing           = false,
        .shutdown_grace_period    = 15s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "CJNCQPUTEVZNQKANLSBYXLBPLSYAMHDRGHQLBICZIGXTR",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "IVJLKFKDSSZIKABYLAOXIPUBXGJICXWPATSQVEMPXSMFGIEVDGBRJZKZK",
                            .port                     = 3241,
                        },
                        .connect_timeout          = 5s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 10,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "HHRISFZJBXPSMPHRNQUOCOYGHPKGLTAXSSQNBKSF",
                                .value                    = "RHTKLFYGJNLOSCQDQAGSWRYFOOOQERRPOAJIFAOKYKGBIDQVWAADPWJTGYD",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::error,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 65,
                    .base_delay               = 1s,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "RIILLRSNMAQY",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::debug,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "JKKDKERHPJODIHCVNJVGPLEGQZSEZJCNOQMYQTYEVREFSR",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::error,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"WEY", data::routing_rule{
                .pattern                  = "RKRYOYQZEJHPIQG",
                .backend_names            = std::vector<std::string>{
                    "CNCQMHFCJCJKYOKEEXIJM",
                },
                .timeout_override         = std::nullopt,
            }},
            {"NDY", data::routing_rule{
                .pattern                  = "UUYZIHGGRLXNMICJMUGKABSSBLVUPMNTIWJOYFYNGGGLXWGHYUMCOVGL",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = std::nullopt,
            }},
            {"UCEHN", data::routing_rule{
                .pattern                  = "HVMMPKWZHKMGFPAPDNUPDFPAIPEGFIEBDJOBCJTUIRJUMQIZS",
                .backend_names            = std::vector<std::string>{
                    "JRTCWBIJTLPGYQDBLLPOKZYPLHATZZDLQZEMDTRCBWMDV",
                    "GRZOBVIAS",
                    "PHJZUJ",
                    "ANCMAUODKRYKXOYBPCRUO",
                    "XSVEYCVKVBESVGJXNZCDYMZBPQNNZYVISHSQXMTEYXHKHVKPKZGTDGYQOGO",
                    "TBGDHAIBIWLNMWBRRQYAAURYKWSKZZVFZLSTVKTHISOODEAEOQEW",
                    "AFMMVWMDIGGEWATOKEPHNWLIWXOPCFDHPHJDI",
                    "KOIQMAOZIXFQGGDBLDWBGLYKHGQFFSTTAPBWY",
                },
                .timeout_override         = 10ms,
            }},
            {"SBACC", data::routing_rule{
                .pattern                  = "JYSZMUBEJFZKXFXKKPHSOJUXUWNGFSTNJORJUBW",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"ZDCL", "QGCZYLFPTPKEOPGTHZNAZHZRGYQUCNSHPISJR"},
            {"EVKYI", "XPIOMZVAQYFNVKAGU"},
            {"JDTZU", "IQLWJWHBHAPCYNBMUXLTHYTUIIQJSRBAIUZLAWSX"},
            {"VOB", "KZCTYTLBGJQZIRXGQALNDIYXVXSIURQRMRSGTEJBSWFOTUJDFCBGGZHLQJP"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("SWWVFDUYKPMWQAQNOGTZADAIKTZGFVZSTG", 38664, false),
            std::make_tuple("VGGIELRVEQJCCUPJU", 55035, false),
        },
        .allowed_origins          = std::set<std::string>{
            "BKCHAAUASESCKUGKRXABPTEFEYNYCQBXVKZHKG",
            "FSTLLIBANPQUFAVKHETCFUQYBN",
            "HHJIMJFGTMURKHIYAGKQYLVJOLMQMIUF",
            "JMUXIBUISPJRFQWWHQCZBSSQILUPNNFBHZPYBPIBCJRRMFUJB",
            "NLLHGKEWPNBBFNVBBSCK",
            "OGXCQQNIKALLPURYWAZJNMTZJDFIXQHHMQKEEKCCKFVEKQJNTVGUGMTYVD",
            "QANFZFEYZF",
            "SSNLHFKRZPBHFGVGDDQNKWVBHEQELIAGLNSWUCY",
            "YUZRVUGRWGHOEENOPMDVWYDUMFWUTVYIJDVB",
        },
        .config_tree              = data::scope_override{
            .scope                    = "ORIWMPEYMJPKBJHGUYURSZBCNNNIRGYIMHNGRHTQSNEUKGFVOGBPVLVFJU",
            .extra                    = boost::json::value_from("SKGOVBFSMOYJEHQKPNGAIVMYJYANEJHULZGCZZTISVOJXYWVVGQNNAUJD"),
            .log_level                = data::severity::debug,
            .retry                    = data::retry_policy{
                .max_attempts             = 14,
                .base_delay               = 10ms,
                .backoff_multiplier       = -4212.9614,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_11", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "LNYOC",
                        .port                     = 38093,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 47,
                        .base_delay               = 1min,
                        .backoff_multiplier       = 1028.4326,
                        .deadline                 = 5min,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "IKDBZUJQQAEOORANOAVFQHHKRIVSZLSYQHPNKKMFJAWRBNPTWZIIOVHMIKCNC",
                            .value                    = "ZKRHGITQNSTJDYXQHXMBPZAQWVDMALUOSFAHUYJANPNSXUBPSNVPXZC",
                        },
                        data::tag{
                            .key                      = "ANEVQLLWNSTYNJBBVTOAJHHDCHADBRPNAZMZINZFJJ",
                            .value                    = "CRSGCDFCOFGNMMKYABBNTVVTUCRSLZTJHUFGWPMCPXQWRX",
                        },
                        data::tag{
                            .key                      = "ZEELH",
                            .value                    = "TIJVYR",
                        },
                        data::tag{
                            .key                      = "PQNCFJKVOMFXDYSZAZSUOHSDFEOWWHITPUETCKHOHJTRJPNYVVNVRGXRG",
                            .value                    = "LSAHMWUPXIAHSQGDLRRQZOSZZMGZZHZYFOKNMYFNLJAQMCSF",
                        },
                        data::tag{
                            .key                      = "REPIZXNJVGMAYQEENZFYETEQUWBPALLYV",
                            .value                    = "JXNJQTMWFUSEAYJOVFPNXLMCBESDIQUCFYOYQXCMLQFLOJWBZLXYIC",
                        },
                        data::tag{
                            .key                      = "ELUPLGGFKVAYXFVKZGHQVLCKGUQLBLHTKXVPMXTLWQJPHDTAUHNIY",
                            .value                    = "KSDENG",
                        },
                        data::tag{
                            .key                      = "RWGLIAIYEEAKHHPQAATLWORNMACXRJHWGWTUZSTWYCUOPXG",
                            .value                    = "TBDRAWDUJNIPTQNELCVRTCRQMPGRXWAFPCVKLUNTWAHSQXVC",
                        },
                        data::tag{
                            .key                      = "IBFCUUCFOS",
                            .value                    = "DEOUZHZJSUDLLUJUMPEQOAJBPGVBCNMNGRIBSXVNSFDRZWHWZ",
                        },
                        data::tag{
                            .key                      = "EFXMXGCUNGNAVORXJEAWTIOWSFAXYEDRVBHAZHTXHXCBBKBEDWAYLHHOE",
                            .value                    = "FXGRPSBJZHFVOPPXDJWPHAZHWOCWPAOWRXMZJAJXWXZEP",
                        },
                        data::tag{
                            .key                      = "NPSPSDUKDONBMFCKBMETTEBTXRFLMPZUNRMSDQZDF",
                            .value                    = "DQVXIMVNCVJFWAXMFIERVRYORNFFK",
                        },
                        data::tag{
                            .key                      = "GBGIPXJXKFVBHIIXHDGXMJPLJCTWJVKJMWJWXVHFUWTGLCNWJAI",
                            .value                    = "BYFXZWETKSBAPBRDGDXDAWRAFSTHOUQVZFBURCPHHLMCDDXHBJPQY",
                        },
                        data::tag{
                            .key                      = "ZBFUUWXFHARMPRKYCUBWSJFO",
                            .value                    = "TCLXMYJBRKZZADJSZWFHELYDBIZHYZC",
                        },
                        data::tag{
                            .key                      = "MYJBBOXUE",
                            .value                    = "LUCILGMJLLHHFXNZAQQ",
                        },
                        data::tag{
                            .key                      = "RERPJQ",
                            .value                    = "SNTDCFMVUUXDIIWDVBQSWR",
                        },
                        data::tag{
                            .key                      = "AUMGNWOUEVVJZGYAIPUEGRABEDVKUDIRWFMFGDRTAJDPFMWCCIURSSGI",
                            .value                    = "BXTGWWXPIWBPI",
                        },
                        data::tag{
                            .key                      = "TUOHYEDWVQJMXXXPPIDXKZQJRNRSOKLPQKVFQLGX",
                            .value                    = "PVKDMEESJWIGNXLARUOYALGMZUIHRBGBZFJTZCHSTCLRUSOSDWJNNISWVL",
                        },
                        data::tag{
                            .key                      = "ZK",
                            .value                    = "ZLFPSGYHLTUPQHPSJEGNIIPNRPQIZVHSDSRRODZAISKUDUFVFZZI",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_75", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "ARWGI",
                        .port                     = 3506,
                    },
                    .connect_timeout          = 25ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 34,
                        .base_delay               = 50ms,
                        .backoff_multiplier       = 3435.819,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "KNPMZDWRJUGZGOLJRKIUINSXCISSQKZJSVQWSGCZBGKOVVRXBMT",
                }},
                {"ep_41", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "VXQGFDCLUCKGGBZGEPMDXYNETYYDHZYIKDDACPHUXVVMQR",
                        .port                     = 41995,
                    },
                    .connect_timeout          = 2s,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 2,
                        .base_delay               = 25ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "LKGJXYSLOGETSLDYEVHTJYIKMAPERTYNYHHHIMKKEDBZAZCANUIAXTOXBACNHZ",
                            .value                    = "NPYSS",
                        },
                        data::tag{
                            .key                      = "WOZKOXRVZKHCBQCNFATQUYXLMBPOCYJUNIPFQPNJIUHL",
                            .value                    = "ERZQOJATLNNPEEJPZXOPKLMVMJFVCQOFSDMFNIYQGBNVBFTXYOGKQPMR",
                        },
                        data::tag{
                            .key                      = "HLBZSTAMCMCDHWMFCKWZWNNXYOLVITQ",
                            .value                    = "OOVSKHMULRDDZGWXJAPFYCNQDJF",
                        },
                        data::tag{
                            .key                      = "AXVGZXAMYVWA",
                            .value                    = "OCVRCQDUFXVTSAKUQVRLDVALBTVQWZGQTSGJHLZKFXHXGV",
                        },
                    },
                    .tls_cert_path            = "LGTHSYUJTMOEODHSWKAYVOJBBREURZDKVVBBVXYLFKBDMHMOQKIKYQJOWIKUGTT",
                }},
                {"ep_76", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "HXEPIEDXSVFEPRYJIGFNFYKIXIO",
                        .port                     = 35423,
                    },
                    .connect_timeout          = 1min,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 42,
                        .base_delay               = 500ms,
                        .backoff_multiplier       = -8457.1881,
                        .deadline                 = 1min,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "XUHZDCGPTWDITKTP",
                }},
                {"ep_1", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "QYZFGQQJOPLAXDHZUTNRLTITFRHHGMWCFIAATYCXJNLIXE",
                        .port                     = 58952,
                    },
                    .connect_timeout          = 1s,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 55,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = 9850.5093,
                        .deadline                 = 2min,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "TERHOQXIYAHMCRJBWLOLVZAPZFFPRZVXJNJORJXNCNCXY",
                            .value                    = "XYKEKMFCZFYHWCZKVCNOSZOVWDUQHUQHRWWX",
                        },
                        data::tag{
                            .key                      = "HYAGPWBRAJYGAMGXVEKYKSWEZDQOTIJ",
                            .value                    = "UTXGNUOQC",
                        },
                        data::tag{
                            .key                      = "UGCRJTECNBYTFQ",
                            .value                    = "CMSEONLYFFJMRZBSIXCDTBIFMKTHXBYJZZGXTVIZSQXIMCOZRRNVTD",
                        },
                        data::tag{
                            .key                      = "VTATJRUZZVWUAXAHWYD",
                            .value                    = "STYFSHJITJWVTLTLTFKWYLEWDDEPMTGORERJZACCOOAGWFKTAXUSCTUXPRWLTZG",
                        },
                        data::tag{
                            .key                      = "UUBNPDFJVYST",
                            .value                    = "OVTBMBVNUHZLXFLZVTQHOMRJPHDAJBLJHHLBNOLSPJT",
                        },
                    },
                    .tls_cert_path            = "ESFSDCDGMR",
                }},
                {"ep_62", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "IFYQAFHFRCTYGEDZGTSMBQJKOCTSVAMDLJALFBOFRDIHA",
                        .port                     = 53526,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 9,
                        .base_delay               = 500ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "RCCKQWCAQRJWNZQZFWGDBPEZSRUHHAIRVTBXGKSZWDQ",
                }},
            },
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "WDPXXZWLOTKQETZFLSD",
                    .value                    = "WXQTOFQAZVVMMKZOCBCNXMC",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "FLUSSTARDPSBZEYIYZDJWORGHEALYUWGXNERRHXNETO",
                .extra                    = boost::json::value_from("BUORSJRNHILWLYKFL"),
                .log_level                = std::nullopt,
                .retry                    = data::retry_policy{
                    .max_attempts             = 19,
                    .base_delay               = 2s,
                    .backoff_multiplier       = 2586.2184,
                    .deadline                 = 5s,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_58", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "EGWNNIKNODFHYSKWSEHRWOGFXOWYWEWLPOFNFZBITQSJTPIMIFSIBXPZS",
                            .port                     = 7297,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 21,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 6570.5038,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "SIRMDPCJRADZKZYROQSPSFEUSYTMTLDUYQAXHCWSZYESWPLDOFYGFGQOQUMZDBP",
                                .value                    = "DHYMGUONFHUDFVGLKSUBXONENNOQMLNQNCQPDZCOIBON",
                            },
                            data::tag{
                                .key                      = "YBXMEELDGCOYGWWVLEJAGUKWJODJOQPEMSSVASJQEHZQMJL",
                                .value                    = "OBOHJTYNYSODTYWUSJNBTZOMNCVPBHSHYH",
                            },
                            data::tag{
                                .key                      = "RQCKCQNFKJC",
                                .value                    = "LBWWKIZD",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    }},
                },
                .tags                     = std::vector<data::tag>{},
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "QVRLXHLHEODJIZMZQQLXXNSNEJOKSQPKPCWGUNP",
                    .extra                    = boost::json::value_from("QXXPHSQXYPICFLOOLQRYZEFMDFZCLPYHUCJZZCCGEEMETNPXCYNET"),
                    .log_level                = data::severity::debug,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 44,
                        .base_delay               = 25ms,
                        .backoff_multiplier       = -6999.0796,
                        .deadline                 = std::nullopt,
                    },
                    .endpoint_overrides       = std::nullopt,
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "TYSBYKGDUVLJQLBMFZBGEWHCIZCETWORIPDVU",
                            .value                    = "YVHXIPRBJMPQJTBMDQPWGINNMVWBALHKFHWETNNDOBKPWKFFBTYQJ",
                        },
                    },
                    .nested                   = common::box<data::scope_override>{},
                }},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
