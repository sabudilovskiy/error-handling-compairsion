#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_13)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/13.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VVZFUHVEHUXFECRG",
        .worker_threads           = 190,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::nullopt,
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "NEZILHPYRSNVLNUKUDLTZUIWORTX",
            .extra                    = boost::json::value_from("OVXORFJGFQLILOITIMESPRHSHGWLECNUUOMAXNBHEPZWOUIFXNXIYZLGWULQWVE"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 24,
                .base_delay               = 25ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = 15s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_73", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "JGFZVRDHFCNUTRZRWBOKU",
                        .port                     = 6073,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 99,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -4621.1136,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "AKKEPRRQPHVGJZBMQWFXEINVGINSHLYHSJNGULNBKMOCCYBTAUYJG",
                            .value                    = "RMKBJQNEEBDLFGJJTMJBLEDLPOSS",
                        },
                    },
                    .tls_cert_path            = "EZBKFRXEAHVECPLCLIZGBWHVHQZYOGSMTB",
                }},
            },
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "RYZLRMJE",
                .extra                    = boost::json::value_from("JICLBAFXADQWICKZUNFTVWWJYBDDJMMPMIEZEOJAQARIIKHHLNFYZPNIEOSRO"),
                .log_level                = data::severity::error,
                .retry                    = data::retry_policy{
                    .max_attempts             = 83,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 10s,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_18", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "PSQXBGWXUWNARAYVEJT",
                            .port                     = 10076,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 50,
                            .base_delay               = 5s,
                            .backoff_multiplier       = -270.3729,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "YKUHTBQWNHQXADLEOLEVLXHVJSCI",
                                .value                    = "EXFTDBRUETXQAYOLMSSPZSQNCOQIKMVDGVKMSCYPNJZAW",
                            },
                            data::tag{
                                .key                      = "SXBCIGAERKJQGNRJAGUCXDUECR",
                                .value                    = "GKFAFWFBBHNSFVYWNWCZPQED",
                            },
                            data::tag{
                                .key                      = "QQYZXFCWYNJNJHIJZSWRNJIXWGDUCFBDYIEZHTJ",
                                .value                    = "POTDBW",
                            },
                        },
                        .tls_cert_path            = "PHPKLDAW",
                    }},
                },
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "IOANEWAUQEHLENNALLKYLXGDEXFSFUNBZTNYDPNRGETMZAMZMKN",
                        .value                    = "CRHMFTYRBZOODRYQXOXEYRBRX",
                    },
                    data::tag{
                        .key                      = "NBPINBYLGXOMTFO",
                        .value                    = "NYSMBMMHZVXGSNGBBWAOQXVTMMQEOCPPSUOCRQWQABWZPUFHX",
                    },
                    data::tag{
                        .key                      = "RGOPBNBGIXZPQEEEZXAFSCJFWP",
                        .value                    = "VPATWHCOYDCXTCMQWFGSBXAMTGXOVZKEOUTUYFEHSQZWWZSWCQXNQZFMTNHYJ",
                    },
                    data::tag{
                        .key                      = "ADYOOHWVZFIAXYOGRITRZWTAVZSENKHOAWMIDEBKOACCDLCTY",
                        .value                    = "FXSPSOSWAOQWATKRXLCNYNCTGKEDSECMSJVPJXZVNG",
                    },
                    data::tag{
                        .key                      = "RMJBCJ",
                        .value                    = "GPAVBNQCPTJGUDTTWVKAJPAUFQKB",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "NANEVNBLEFYLYVMHJXQPGADKFBHHJLZTMQUJAAXGYICRXXH",
                    .extra                    = boost::json::value_from("NMOJKRIC"),
                    .log_level                = data::severity::warning,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 86,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 5s,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_12", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "LMHGSQKDCVKNOWNMMCLSNQFIJZWMPRCRECLUWTAUKLNSNXQMFDUGXMUQDTWGDV",
                                .port                     = 55569,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 49,
                                .base_delay               = 25ms,
                                .backoff_multiplier       = 1327.5834,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "GJPIFLVJXKYIFBKCYEHYUIJ",
                                    .value                    = "LAPCFSMONLNDAIFHZCAADNHFGOYXFWKDRZNQCDNSTMZBOJCUSJIGDPT",
                                },
                                data::tag{
                                    .key                      = "JX",
                                    .value                    = "FLPYGTIOQNXKIMEKURBCPGNZRYJLNTGMSUBYPNQS",
                                },
                            },
                            .tls_cert_path            = std::nullopt,
                        }},
                        {"ep_40", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "NCRB",
                                .port                     = 19992,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 78,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -9601.1032,
                                .deadline                 = 10min,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "BQEJJBXZSVOWODJMHBAPIZUPQFEFDAVKRQABIFIKUUTMLHGJRHKKCMFBE",
                                    .value                    = "GVTOPVIBCBTVWCVIPDPUWTLIPSAYSEKQJFJMILNORMFGCFYOHQNEUTEBK",
                                },
                                data::tag{
                                    .key                      = "ZDWRSWQOKQSLAGASQXNQJMEIQBBSNWHKFDBDTXPWF",
                                    .value                    = "NFNSIWGWXQQYUABNHVOWXHYOIVQJGVPBNUWIQDVLVKU",
                                },
                                data::tag{
                                    .key                      = "EKWYHUIYGKMFKRK",
                                    .value                    = "UBOMZLWMSDTPBDDQRWPDHBCUOCONR",
                                },
                                data::tag{
                                    .key                      = "R",
                                    .value                    = "KPUBRJWKDZTIFSERRMGEFSXWFIQSRQPGKIOTDLDLBHKHAVSDKGAQZRUZAJBDHFB",
                                },
                            },
                            .tls_cert_path            = "CRWCXUZMKSGRKNFRBJLWH",
                        }},
                        {"ep_1", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "BEODUCCIGLVPPJEKUQZEYVULRDOVDOUDLRBOSPIXSVAHIBPXPOWJHZIQXBJO",
                                .port                     = 9851,
                            },
                            .connect_timeout          = 50ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 35,
                                .base_delay               = 50ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::nullopt,
                            .tls_cert_path            = std::nullopt,
                        }},
                    },
                    .tags                     = std::vector<data::tag>{},
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "QDDITRZGXCRPI",
                        .extra                    = boost::json::value_from("JENMTWMJEDKCIAFRPTRDPGQGMELHXFZDPAMLP"),
                        .log_level                = data::severity::critical,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 26,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = -5616.0985,
                            .deadline                 = 15s,
                        },
                        .endpoint_overrides       = std::nullopt,
                        .tags                     = std::nullopt,
                        .nested                   = common::box<data::scope_override>{data::scope_override{
                            .scope                    = "XQHOIRYEEZZJJSRCCFQETIJTIUJYQXPQMEZBTYLCORLNEJS",
                            .extra                    = boost::json::value_from("MKQQMXVDOJUYUTOVSOHATTAFTCIWFXEEFVYCBGBMSOVKLMAG"),
                            .log_level                = data::severity::critical,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 86,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = 15s,
                            },
                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                {"ep_55", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "QSEHGNKCDYJXBHQSTBCGTIATFSMRVFQXMPLKOB",
                                        .port                     = 45445,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 80,
                                        .base_delay               = 50ms,
                                        .backoff_multiplier       = 3532.9048,
                                        .deadline                 = std::nullopt,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = std::nullopt,
                                }},
                            },
                            .tags                     = std::nullopt,
                            .nested                   = common::box<data::scope_override>{},
                        }},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "MNSZDJOKQYQONSLQBYJHZSKKVQFPNASKTGHELPAOE",
            .port                     = 17514,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = 25ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
