#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_24)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/24.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "SFGFGFVVCWYEZWJXYAOOXUDAQFPXOVJPCVYITFVKJCRUL",
        .worker_threads           = 169,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "HVTZEPJIRXIGCSPZEUE",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "TZEPQIQYHRZH",
                            .port                     = 5540,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 32,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -5868.9927,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "XSNKHLBBOWKOOZYCBCKWNZMRPSQNMHJJLJEKXCZSUZAIRAWUN",
                                .value                    = "MJIOMVYLKXAMAPOZCFZHEQUSG",
                            },
                        },
                        .tls_cert_path            = "DCBHARWPBFKZJDFDEYQYCTZQPQWJIVUOOUMNVXEKCGQEFEOKJHUT",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "XUTTHI",
                            .port                     = 30252,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 38,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 10min,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 23,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 3585.0633,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "PRJAHLUTSJHLHZZ",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "CLOOLOPSNHBDFQAYYJUZR",
                            .port                     = 54521,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 36,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 3727.9178,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WLFIQOJFJSEMTACHPAHQYPYPERXHTLDTUUDKUXF",
                            .port                     = 43367,
                        },
                        .connect_timeout          = 1min,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 23,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = 2012.0,
                            .deadline                 = 30s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LJGPXZVXHUFRYAIVERCQQQXTHXOYU",
                            .port                     = 59414,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 17,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "UINGUDHNTJ",
                                .value                    = "YWGPHGINEQSXZTHXZQDIDXAELXSZNEQALUFNRJVEICGDYNZJETKXDHMHFTZPD",
                            },
                            data::tag{
                                .key                      = "INNQPD",
                                .value                    = "XTTNMMFEJDPAYEASZY",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 18,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -2531.2111,
                    .deadline                 = 30s,
                },
            },
            data::backend_group{
                .name                     = "XQKYIVZUSWRLVKEVRHEEXHNMNSDNIMBJMGMDIEGOU",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "SAGXFSKUCVFDRRYSHVHGXLQSOHUOYHPJVSGRZMABVKEEGZMFG",
                            .port                     = 18594,
                        },
                        .connect_timeout          = 1min,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 35,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -8371.7108,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "KEREYJBMCMMNDFHTAIIFDVECEJAZGCPTCUHXWXZNFUINI",
                                .value                    = "DDBEULJFOPVEZUDLIBKFIKY",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "DJAAWICXOWFXGUWCHTZEAFTYA",
                            .port                     = 29354,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 70,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = 1721.1796,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "M",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "DLFNADUHNABIKSYZKXRECFN",
                            .port                     = 12471,
                        },
                        .connect_timeout          = 1s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 21,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "TMQYPMELIOZVSFIFFMUTDQ",
                                .value                    = "TWJKCVYROKUEODXUSMCUKCPZTTNOELCNJRJLCJX",
                            },
                            data::tag{
                                .key                      = "QFBTNNBXCGIKLSTXGFBZIDUYVKRJXPUFBTKAVFQIRWJVFPWMVV",
                                .value                    = "CUPGHJKSRSIRYDNYGWLMECDHSDMSIHHEAWHIYQFAEMNL",
                            },
                            data::tag{
                                .key                      = "DKOWROIYCTJCPVDIHJMUJQSWZLJZSBJPAEIENUBB",
                                .value                    = "FJOEEYMSABOPTTXYZTPKECNBDLNYMMEQPEVXWADDWX",
                            },
                            data::tag{
                                .key                      = "IWIYDGDJFAKNWUKUWVRBEPXSWOJTFAALUSVQIJUITOJCPRJZYPFNMN",
                                .value                    = "GQBZCKX",
                            },
                            data::tag{
                                .key                      = "MPVIRVLPHGTIIQNHXPNLGCENZPFZBWRY",
                                .value                    = "IVJLMQZAJKRXRDWAKBZBBXPILZTWOCHOIHGCXYPXOCHBOFYCPIOLCAFXJZWMGPL",
                            },
                            data::tag{
                                .key                      = "YGGARWJHHTOFPZAQLMQFVMMOCIOISLEPOIKKOZSBIQYJMSAQSQXIYDUNNXNCDIJ",
                                .value                    = "ENAQLUY",
                            },
                        },
                        .tls_cert_path            = "TSZQENTOPU",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 84,
                    .base_delay               = 100ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "OAGSTXWAZCQTFLKAWJYTVKQZLKOVGAITSGRPHDNPEUZNILVUWINGBHMWDZA",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"BO", data::threshold_rule{
                        .metric_name              = "FYOSHWGNAHKPFLOYMMDLXDVJRZAHIGMIRXJJBRXBDIVFPHBHMXOZ",
                        .warn_at                  = 928.0543,
                        .crit_at                  = -1248.9806,
                        .evaluation_window        = 5s,
                    }},
                    {"QLJQ", data::threshold_rule{
                        .metric_name              = "XEMHTWVIQBLWXWFCIQPQSHMNCTA",
                        .warn_at                  = -7861.2719,
                        .crit_at                  = -6654.3797,
                        .evaluation_window        = 10min,
                    }},
                    {"OZLCL", data::threshold_rule{
                        .metric_name              = "NHWRRNWCZHOJTWTRYGDJWUNVCLJQSSQCSCFE",
                        .warn_at                  = -259.743,
                        .crit_at                  = -289.0311,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "AXLVXIMEUDITHJGZERELURUOMEWMFHSJSBJZCQXDTAPFLQPEJLS",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::warning,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 77,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 9917.5115,
                    .deadline                 = 30s,
                },
            },
            data::backend_group{
                .name                     = "IAGGETSFQEYENUNOCENDEUIVO",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"EK", data::threshold_rule{
                        .metric_name              = "CVOGVRRSQLCXBMXOFWLSMQYQYTYMGKSHYNZXXZIOJBXDPHQJQLXNNKWPAMK",
                        .warn_at                  = -5605.7611,
                        .crit_at                  = 934.336,
                        .evaluation_window        = 2min,
                    }},
                    {"UMCW", data::threshold_rule{
                        .metric_name              = "SBHVIQAOPVRCHSWNBCITUHBUOE",
                        .warn_at                  = 4682.8323,
                        .crit_at                  = -640.5232,
                        .evaluation_window        = 30s,
                    }},
                    {"SF", data::threshold_rule{
                        .metric_name              = "IIDUEFLFGBANCSQSZFVAOOLDMC",
                        .warn_at                  = 9358.0182,
                        .crit_at                  = 100.5003,
                        .evaluation_window        = 30s,
                    }},
                    {"CUX", data::threshold_rule{
                        .metric_name              = "WKWHS",
                        .warn_at                  = -8683.0827,
                        .crit_at                  = 5941.0633,
                        .evaluation_window        = 10min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 61,
                    .base_delay               = 1s,
                    .backoff_multiplier       = -4390.4585,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "CNTAC",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "TRPFQSXVLIZIIMOCOHAAAIOSRQAQQRGXEPCPHTJWZSXKPVABCPRNX",
                            .port                     = 43464,
                        },
                        .connect_timeout          = 1s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 79,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 4327.1663,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "PPXQLTGGSYWZWFRUAHGTMIZYUCDPWSAM",
                            .port                     = 6706,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 79,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = 8039.1563,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "JLNLIIBTGVRHHEJRDEWOPDRYRGPJWDKBNSGKOGPMOOKKRBVVFNAXJWIMCIFG",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "ECCFHAKXFOFYBMPOUPQKLSO",
                            .port                     = 59018,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 81,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "BNJZYNVZETJOSDDMRYTZJAJ",
                            .port                     = 39526,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 6,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = 6237.1355,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "JGTZMGTUOIGYZROPNBGINXSWCTNHOLANNSGXMFUOHHMW",
                                .value                    = "WXHKPJFDWWSQYJSBWD",
                            },
                            data::tag{
                                .key                      = "URFAFTI",
                                .value                    = "I",
                            },
                        },
                        .tls_cert_path            = "YUCAMTDUCAKNJDSNJYRSEHP",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "COKQWVOMEYIJNRBVNEDE",
                            .port                     = 26305,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 37,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -3173.992,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "FRZQLUVAEGPWCNKCQIRZRZWTKUAXRQOMMPESHUNNKULFF",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "P",
                            .port                     = 35434,
                        },
                        .connect_timeout          = 200ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 95,
                            .base_delay               = 1s,
                            .backoff_multiplier       = 1635.6218,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "AGFLSUKVCBXMNSARIVDPMRURMBSBZGFBMVCRXPCTMQROQPSBNLAMLNK",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "VPYRIVSPRTADVELCSCPUJPGFB",
                            .port                     = 36276,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 7,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = -5349.4841,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "EIQCRSOBYNHKIEHSNQTLDDXXDNDQYZSCOKUYIEZWXOHUBSKOK",
                                .value                    = "MFLFLZKHHRRNLDRXPYBZFYSJHIY",
                            },
                            data::tag{
                                .key                      = "JHZYKVHRRVRXCPUNHGSQESLQAUGWURNMZB",
                                .value                    = "RXPNCSJXNJXRTPJOFWLEBPBEVYIDTEZNY",
                            },
                            data::tag{
                                .key                      = "ARSVOJFXRTNZKHPLGZKVXTQXMSLIPCBVCCPCXJZRVEIGVMNW",
                                .value                    = "JUFRJJNOKEYTJWQPEUPY",
                            },
                        },
                        .tls_cert_path            = "UUPEWRTOIBENSQFECZ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "HWSVPHPCPOAATKKEIEQOWABZQSKEDEYHQUR",
                            .port                     = 49703,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 44,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "JQUVNOUIXRCDHEKVLISKCIULUDNEDYDOWZFPAXXWSZBGTUQAVTWHGOVITAJIMF",
                                .value                    = "ZUBWBURAKIMMEWNEFUGONKAGLMPUAAZTCSIOPEWQSWRQZUEJKTXKRNHKTFJOTRL",
                            },
                            data::tag{
                                .key                      = "WRTWWFITMINCOMCOKJKRCNHRRACUNNRAHYHXXOBNAMDZMJXQICZCZT",
                                .value                    = "ZIZRDTGDRKWFQEVWAH",
                            },
                            data::tag{
                                .key                      = "PHLQYBLKDLQRY",
                                .value                    = "ATRERNIGVCFJLYBHCMGBNLHOBMRIXKUGPRDREUSGSSRDDBYIFJFCNGRKI",
                            },
                            data::tag{
                                .key                      = "TVCBXPSSRHEOYRAPMMNOTXPYDMHLETXVIVHMOX",
                                .value                    = "ZQVCWDYIHVAECEVOAQCNCXQATXWIL",
                            },
                            data::tag{
                                .key                      = "YLVPFPGXHXYTZRBBOYJZPYELQHKZIEWDASLSNXPPSXZSIGCUOA",
                                .value                    = "WGYZFXGPXIQVEPSYSQUCKZDTMNVAIIOOKJ",
                            },
                        },
                        .tls_cert_path            = "RDRXQMEATYDQEGMEVPIJYRXMJPJGWCHKNPAPGPRFQXHXD",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LRCGVPAYNYADEWWTGUORUDXHCYCE",
                            .port                     = 21487,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 70,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "KRNYJEIAM",
                                .value                    = "ENFTMOOEGQCCPOGBUZVZNTVXPMKNEHJCSVQTCWKCJHGXAOOKSXDEH",
                            },
                            data::tag{
                                .key                      = "XPWRCBPSIZTUNQPLWMGIVFAJTSCCOEDVUJSELOGSDHGFOHWWLOOSBMLKDRGLCC",
                                .value                    = "SWLXITXAKSMSORAVJCYNSPUIXULFFVOVRHQFUNJGGGAFLFEYNJLOF",
                            },
                            data::tag{
                                .key                      = "JNLYXGIRLYLNPAXRKBEIJQQBGTFGNXJALUM",
                                .value                    = "TPUZBYFQVIUQSOAEOTCLEYOQOKTNCVAPNITQJELVLOHVNDFDAHMNQJ",
                            },
                            data::tag{
                                .key                      = "CGGVEUCHKJOYCJIJS",
                                .value                    = "RJFSQDJHGRKLIXEYJCMJHIRUDOZYWNLSSBRLWINDCRUSKPGAIVLDUYNGGRER",
                            },
                            data::tag{
                                .key                      = "MMUSABJBLBSBBQRUUZVJNZWEUNSKSUIZONIGQJCXXDTZOGPSTYDOJJ",
                                .value                    = "JUNPPBZLAGFLSUUHCTGFJHFCAKXSXDQKTNKAN",
                            },
                            data::tag{
                                .key                      = "YRLHTNNWQLHQCFPMNPBWVWALINXBIKWSTNT",
                                .value                    = "MWPLZSMQDWTRM",
                            },
                        },
                        .tls_cert_path            = "MZK",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "QDCXNQYPSAVTJYEVLQPCRARIWSQT",
                            .port                     = 42474,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 72,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 8593.0542,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "OGBJUVGJWLJYEZBSBOFRQUKVLNYDWYFJVCPYAAP",
                                .value                    = "FOWRGOFIZJKYGJKAYCWFXLGDOEMLCSXG",
                            },
                            data::tag{
                                .key                      = "WBXHWIRHAZDLNFCICOFCPEKMMFNRVPJQKAKAFQAZHVDJTTGGFJMIUWMXORIA",
                                .value                    = "RYW",
                            },
                            data::tag{
                                .key                      = "YBAHUDYAY",
                                .value                    = "VLZJXPWH",
                            },
                            data::tag{
                                .key                      = "HOQNZMBEJKOSHHGHIKKNHTVACXBSQQIPSQSJVVVXUQGWPI",
                                .value                    = "VTLWNSNVDJXJNZJKSPMMHXRSZZFQXZJKQFZZIJFFIK",
                            },
                            data::tag{
                                .key                      = "DMBSPINQENDMOXPQTAYUEHLNFEIZSAAJAPHZGMG",
                                .value                    = "FYEBAKJDYXIFQHNKEPR",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"HH", data::threshold_rule{
                        .metric_name              = "XZXIJNJPNBLVCELWMA",
                        .warn_at                  = -6339.5527,
                        .crit_at                  = 7679.9516,
                        .evaluation_window        = 10s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 69,
                    .base_delay               = 100ms,
                    .backoff_multiplier       = 7340.2137,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "WNCLAZWKYGUJBPWEXAXPWBBPGNLOGSXJOIVDWPUFSGINTYN",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "HQODSNSGVIEHJYWFJD",
                            .port                     = 44398,
                        },
                        .connect_timeout          = 100ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 42,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 15s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "USRTAIXKQCVFEOEHJCSHSOFUIFOVTVMTNMASPBXOCAZZGKSF",
                                .value                    = "TVJTZBZNEXNQW",
                            },
                            data::tag{
                                .key                      = "USOFJLBONVPFUENMXKXKSFKTCNKJIAGJPOUTSHXQFFPFD",
                                .value                    = "OVCEJPD",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "IQOAQWUZACODIIPSPVECTKKYHQUTASGYVAASEIWOZUVJPPEYRGZW",
                            .port                     = 15899,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 69,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = -6516.5345,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "DGFRVASEHCNAPEDWVEFSXPAWCO",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "VTWMAMYGXQECPVQIGKUYZHK",
                            .port                     = 33444,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 64,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = 1001.8742,
                            .deadline                 = 1min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "GXDNRDVKXYXBWDYJLLKXMJFUZSTBRRNLICKJHZCEJEHKENAATXDAKSJVKHSK",
                                .value                    = "KQEUSALHRAEYBZVHOEOCQMFVPSWQGZJFBQOGSBXHSQICMBUBTTWWTTTKNERVERL",
                            },
                            data::tag{
                                .key                      = "YQZKRQQXROXYVIEEBWPGIRSRTYVLHNTCDEFFFOEQW",
                                .value                    = "XIJSGXMQKPIOVTMGI",
                            },
                            data::tag{
                                .key                      = "KHSJPXGPHEFOEZSNDXZQHTPXQMPTXSDQEKCSMYKUVVYJRLLNBAIKZSH",
                                .value                    = "AYBUPWHTDRVBVJNAQNIDFKYIMOZGZJGTOZQSTUPROAPNSASCDTMSYSFJFOM",
                            },
                            data::tag{
                                .key                      = "ZVOUHEGGGLFCJOJCWOKCGZWTORCTXYTSKSNUCZWVOIMJSIBPIPRIU",
                                .value                    = "QPNHS",
                            },
                            data::tag{
                                .key                      = "RPR",
                                .value                    = "BAPLXTHBWWBFLHVLWPSJUDTBBNBRARCNLIGIWHVQVIGOGOAHPUQGSBG",
                            },
                        },
                        .tls_cert_path            = "OXMNBQPVKNBEJKEXCQHQXZAPYQBDNKHWDYHLCRPUSETAFS",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "FBISKRPICKEVSUDCD",
                            .port                     = 51366,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 56,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::error,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "SWSHKWLWIJVWMDOCSFPH",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WVUETMBZDCWGDDFZDBXXTTHHDWUTYSZWCLZCVHLRNNGCPVH",
                            .port                     = 58980,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 79,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = 4401.025,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "CNOOYJPLYMEDXVCZYISYHEXA",
                                .value                    = "POGFRNMMKGCXJFILWVVMGDDSTGBTAAGSWYG",
                            },
                            data::tag{
                                .key                      = "RCJUTSWUGDVNCYFQASBRFLYGACBQUXFGBGHWNNFLATCRDFA",
                                .value                    = "WTPPOQHTNQQYMPLXQYCCFGMG",
                            },
                            data::tag{
                                .key                      = "VJINCIUPKBUILYELKLHPCHPKFEJGAKSUOEFAYUVEKQXQ",
                                .value                    = "IISZAKCAELVJDFNKCKGODDYFZVDBOAOZLIVPQBUUONGXMQSVGEQSBFQYFXDJ",
                            },
                            data::tag{
                                .key                      = "AMNURQWUEVYNNVXLTRKEFFQKLFTWRMHBKXVHFUT",
                                .value                    = "LUDNOZXOCCZQWTQNXGXNAJWWNDMZHKYHDAHOUOEXUQTTNOWLPTDHYG",
                            },
                        },
                        .tls_cert_path            = "JFCGVTWCCIIFOUFUYAPZIGDULIKCASAVUOZUVPM",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "DJLJCUCUPWVMMSCMDIJ",
                            .port                     = 65334,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 29,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -2815.8091,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "VMXWANRQZDBTUNGRJXKPXHM",
                                .value                    = "SNOKQYMPKYLANZRVTUDHB",
                            },
                        },
                        .tls_cert_path            = "ZCXRGSKQTSMKKVSNVWFNTJARZMEEATWHNY",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "NBPKEXZSOTSEFRWKUUFNIBUMORIKZLW",
                            .port                     = 58356,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 56,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -6659.4837,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "CHPZUMEASDLDOZGEZVQTAMRTGMSVROPGGULKYHFECBEAPKEUESWGENYEAL",
                                .value                    = "XZQFKQGDHZQRULFQWVKQPVEVJLPNOWSGVZCRWNSTJQMBFYVJBCOFZW",
                            },
                            data::tag{
                                .key                      = "EMPZPTSFLSHXNQWUIETMYQWTNBTEHKWXIJRIBD",
                                .value                    = "OXTEXYRURMSIBQKCRWXXSJJNPXSQSSESNHMNJECBVTTRONOHHZV",
                            },
                            data::tag{
                                .key                      = "FLBFGZUYDEMZTYVVBUF",
                                .value                    = "DVRXPRILGRCCJJPH",
                            },
                            data::tag{
                                .key                      = "MADIAHYLYYLVBELBQDUYDBUSRFEDLHJGZTNKWXXSACIJGKGEVTX",
                                .value                    = "JXLODZSNORAYJNDVIQDZSAKJPRUHCSZHPMYAXYYLSZOUPHXJONDMCKO",
                            },
                            data::tag{
                                .key                      = "DTEGDJAJFIVRQTHZZUKRSQNXCOOVDKIBYNWJSZFZBJDCBTVNCWFXGUTKKUYVS",
                                .value                    = "VZCYPZPLKBXPFEBC",
                            },
                        },
                        .tls_cert_path            = "SKQQKAUMQCBBADZWQKMWBMHCFUGVCQKSF",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WPNOMEJBOXKNNZIENQMEXGTQEAXCTIYVHYVUZIQKSL",
                            .port                     = 19208,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 10,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = -2194.7388,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "QCSTELFXAXIHKDXFESZAWJFOACNGPSKT",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LJYHHJRTCTPXRRWPDTDCFRDTMUGCLCOFZLCEJZLJOOEACSRTE",
                            .port                     = 55267,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 92,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = -3131.7864,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "GKPOAWVSVKFUYVZLXDQYDICKDVLGTOQDGZXSCJILFHOTWZBLOIBF",
                                .value                    = "WOMZDIZPYDLDLSDGZDZINVOZNVXNUGWWUSFUVZPJWHIVUKNP",
                            },
                            data::tag{
                                .key                      = "EDJEDLHJVBSDEOJQKRYMEDYHOLLFDUBWSDMLGTLYTFVBRTXLB",
                                .value                    = "IHJIAJSJBEGGEVHHHQUUMTGEKFVLDLIYVXONNZLWWXVWUBVQXKVKCWFISUV",
                            },
                            data::tag{
                                .key                      = "EHWILQKFNSOHWOAALZDYTEL",
                                .value                    = "JRMYUI",
                            },
                            data::tag{
                                .key                      = "DVMXOYF",
                                .value                    = "GNDQRKALVGIWCFELWMCYJWDTPXKRRKSYCQMMSYMKCPAXGEEBPJPZJ",
                            },
                        },
                        .tls_cert_path            = "DZNBXUMSPIOHXTOSRDYUXXNRIVVRMMJVOQWEVSEKLPSWMPAXCQ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YTVNJKRTOXPIEESPKZLVNLSSCGGJACFHQCHCZRJWWX",
                            .port                     = 13834,
                        },
                        .connect_timeout          = 2s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 96,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -4396.3735,
                            .deadline                 = 1min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "IDMBXLZNDCWDP",
                                .value                    = "PVD",
                            },
                            data::tag{
                                .key                      = "RIN",
                                .value                    = "ESL",
                            },
                        },
                        .tls_cert_path            = "JFDMBMKMIATETQ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "JMWFDEBMLBBTBWTFXKZKXOOACHBCNOBJKLVPEKOXQTUTQSYJMTYCZ",
                            .port                     = 49593,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 32,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "YADZAYSAEPC",
                                .value                    = "ZPVZBGIMD",
                            },
                        },
                        .tls_cert_path            = "DAMENGKORWBUFQOBMSCXLQYCGZTYNAWCATCJTXSRFRBHYPFQCQBXZNA",
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"RLQXTC", data::threshold_rule{
                        .metric_name              = "VHNLXZYWWMNKEPFXOJBDNHWVKQYUCKQDKMVCROMNXTNIUMIGCXMZNKGBLQND",
                        .warn_at                  = -3407.7628,
                        .crit_at                  = -6024.0283,
                        .evaluation_window        = 5s,
                    }},
                    {"WS", data::threshold_rule{
                        .metric_name              = "PMLXYCQNBGJHXUOPHJNWXOFATGLSRBJJNCAPAZRUPLXPUSLKDYOSORSVP",
                        .warn_at                  = 9671.5212,
                        .crit_at                  = -2927.0147,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 76,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 6697.2321,
                    .deadline                 = 10s,
                },
            },
            data::backend_group{
                .name                     = "ESJZZXHVTSHVXLLLANQYUVUDOQTXCAAQMCA",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "KIJHIIGACSKPTBJTCGNNLRULM",
                            .port                     = 25735,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 20,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 9847.8136,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "TEAIHCZCZCWMGQPKISHUIONDTMNHRAMSFFUCRAPORZGGGOIUEUSTCDROPNPIT",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "UOXNABMDBHJA",
                            .port                     = 25757,
                        },
                        .connect_timeout          = 200ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 42,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 7477.9091,
                            .deadline                 = 15s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "JTSLWRMTH",
                                .value                    = "HJWMD",
                            },
                            data::tag{
                                .key                      = "UQVZM",
                                .value                    = "TTGFZLFJKPLWPKUYOTQQQNCCNBFZAZ",
                            },
                            data::tag{
                                .key                      = "CTWBZRMMKMDGOPQHUFXLXGEI",
                                .value                    = "EGLFHCQFNRYXCOAKBNXOOIHQRMBMULPXQNNQOTSVG",
                            },
                            data::tag{
                                .key                      = "MRDKWDLSVBTGJZTWCJPZHDESXVFQSD",
                                .value                    = "OPXNLTSCX",
                            },
                            data::tag{
                                .key                      = "KVJDUBDQ",
                                .value                    = "CUDZBSCXIIKNBOJVTNPCSLFGZYRLRJAXYERXFG",
                            },
                            data::tag{
                                .key                      = "CHPLHISITCEVRBPDWYCLDJHYNLQDZLMFLXKEIFQRQNIREWYJKNQ",
                                .value                    = "ZNVTWHKRZWQDKUVKNXYLH",
                            },
                            data::tag{
                                .key                      = "JLVXZLMQAAJGDFNYDDNKEUCIOVJZNRRPREVEEYGTTASUVEVZLTW",
                                .value                    = "HLHZ",
                            },
                            data::tag{
                                .key                      = "NJZVGKQLKEMECPXHUHCZI",
                                .value                    = "PRZPZTYAPSBAIFMGOZVPZFXIOFSQECVPYACQYGSCWBHWCGOBIAQOCTHFBJEFHTQ",
                            },
                            data::tag{
                                .key                      = "VNWHWEGOGUFKSJLUPJJXTUEJVGKXLLPM",
                                .value                    = "BLTRYVTGTDHQMOBZTYEUVFBMFHZMQASDSRRO",
                            },
                        },
                        .tls_cert_path            = "GERTNZHGDKRHERTQTBKKHQPL",
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"UR", data::threshold_rule{
                        .metric_name              = "BDTZIXQZMSOINKKFLEMZKLGQAMWDLGUOGINCQKPJMGPMTDUNJDYKPPYXLEXEWPM",
                        .warn_at                  = -1157.5382,
                        .crit_at                  = 5719.1781,
                        .evaluation_window        = 5s,
                    }},
                    {"MO", data::threshold_rule{
                        .metric_name              = "MVABTSDIQAEFXRGIKKWTUIRLSTGZMKFELNBRMAWKWSHFHLBEYI",
                        .warn_at                  = -225.6411,
                        .crit_at                  = -9319.3283,
                        .evaluation_window        = 15s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 37,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 7316.3611,
                    .deadline                 = 5s,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"JOXI", data::routing_rule{
                .pattern                  = "RHNUURUIRF",
                .backend_names            = std::vector<std::string>{
                    "SHZKEZBWBNODZURUXENBSQBFEVXJNVLUSJZJJSXWCJWCVGQCELQ",
                },
                .timeout_override         = 10ms,
            }},
            {"AKNNGT", data::routing_rule{
                .pattern                  = "TAHTDUDRCWBBMJVBBLEIV",
                .backend_names            = std::vector<std::string>{
                    "SLZPOEGHWZGRRKPIJBWDOMZTFUSUQUIGRQHE",
                    "FIVZMPFKNZHBINAOQLCACSMTMFHEAUHBIEEG",
                    "VKZUMPSKABXWWWEGROBGRYOJDGFIVKDZKLPLHL",
                    "QDPOWQXKZ",
                    "WKCUAQEDMIFAXVENOPVNSBDPUMUB",
                    "BUTCRHRHUDCSUDJVJHGDUEBMUVQOAIHGRKVDXQUXUATUY",
                    "AMAKAOHYOMHQXJSHTOSCERVXKJVVZWSFLSQ",
                    "WAOSZARXNHEQKWPNPYJYFIGNKXLGWUDPVZGHHCIGMZFTWRBYIAOIKJOPN",
                    "X",
                    "QBICHJKDMWARNRWEDVAMRSBBYDQV",
                },
                .timeout_override         = 1s,
            }},
            {"XSJE", data::routing_rule{
                .pattern                  = "QPHAZYW",
                .backend_names            = std::vector<std::string>{
                    "AEHEEERSQIESDJSMOHWIBMDCEUZBJJPAGEI",
                },
                .timeout_override         = std::nullopt,
            }},
            {"PRWU", data::routing_rule{
                .pattern                  = "HKHMG",
                .backend_names            = std::vector<std::string>{
                    "RTXSOJPJOMXLHLWNXMOFB",
                    "BTFBMDVXALQVDPYQBCKUSHMCB",
                    "BGLDZKLTAIKJEEZVJMYFLDLYYYZARGWIGKMEGZLMPEZFSUR",
                    "VWCRYMQWCIAPJGKJCBJADZVPMKFNVXCK",
                },
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"VLBU", ""},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{
            "BUWLMRMYQOETBFCYYJCAGGOUFDRHLWZRRKU",
            "HORZPKLGUGYVRHOLUXNEJDVCVPBEZUYNYGPNQJSEMJBYMV",
            "IWNNROJBDVMBUEBWILCGZYJNKQIDGOSLOHJZ",
            "LHKUGCOU",
            "PVVABGCMRSCUREECXZJNPRBVJVONOQBUWYVWZBECYKSXICGSQJFEUDZQLPVOFGQ",
            "VHRBDUMFOPVOEIFBJYCFFPLWFUHYOBATNPPOQCRWSUPBJMC",
            "ZTCENTTRAGWNPOPPQKTCUAFMVKGEA",
        },
        .config_tree              = data::scope_override{
            .scope                    = "XXAOEUYQBNMMJVMYBKAEGKRUC",
            .extra                    = boost::json::value_from("LQBSLSMDJQBYEBXKGECXXVHYPLAVOKQNWBBMSFJO"),
            .log_level                = data::severity::critical,
            .retry                    = data::retry_policy{
                .max_attempts             = 23,
                .base_delay               = 5s,
                .backoff_multiplier       = -4359.3199,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "BDYFPXMC",
            .port                     = 38646,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
