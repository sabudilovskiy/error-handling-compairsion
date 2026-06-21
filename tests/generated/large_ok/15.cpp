#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_15)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/15.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "AQXBFHABZVEWLHDKOWLIMILHGLZKHJXQNHSONPCOSZLOSKWUOMYZCPAGERFTZ",
        .worker_threads           = 177,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{
            {"CO", data::routing_rule{
                .pattern                  = "RJMQHFRQLCHJJFUKMPKOZCYZIPEDVPMMAIXCJCBOBIFPSP",
                .backend_names            = std::nullopt,
                .timeout_override         = 25ms,
            }},
            {"SO", data::routing_rule{
                .pattern                  = "YSOWXIVCTABKYU",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"AZNMAV", "TMQAEIHPQKKHVSKPKATLWHKBFUQXDXSMKEKDKKOXTRTPSDMZSADZEWUOFU"},
            {"RTYKLM", "RUQUDQXOSFWVYK"},
            {"SVNAIK", "ILFBOWSZ"},
            {"UI", "VCZXORFHKFTBL"},
            {"XFLYS", "FPPOOTFNC"},
            {"XHVAO", "UFBVSATVOOAKOOTZIMOZO"},
            {"YDFVKO", "KWSOQCGHFYRQMVDWMVKKOIFINDJWWHIFSIJEOVQHEPQDUHZGMNHTJNWUPU"},
            {"XZPYH", "MLKMKVKDYEPHVXHSVCFW"},
            {"IGHP", "PFHZPLFQUVGRRTYU"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("BIYBHBLMKQJSUSKKLNURUMYAPXSUHNWCVFNEDBTCBUMXTRZNLEG", 53602, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "IQQBOQAEASOZPHWEVFQTMHZXHWNKUZPBD",
            .extra                    = boost::json::value_from("RFMSJKYYZUDIEQAHIOEYMJUCTQMHVXBXPTLFFGDDJLVFHESJN"),
            .log_level                = std::nullopt,
            .retry                    = data::retry_policy{
                .max_attempts             = 25,
                .base_delay               = 10ms,
                .backoff_multiplier       = 8037.5224,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "TFUWLZRBXUOBPVKTTFYHMWLOSMVYLM",
                .extra                    = boost::json::value_from("IVTH"),
                .log_level                = data::severity::debug,
                .retry                    = data::retry_policy{
                    .max_attempts             = 99,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -2829.3751,
                    .deadline                 = 30s,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_93", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "SZUAYAECDPKFQNWOWRBDWDMEZZ",
                            .port                     = 58316,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 29,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -849.5583,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    }},
                    {"ep_43", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "PUNIQFJOJHALMVHMLUICAGCLYBVJQHVZJA",
                            .port                     = 524,
                        },
                        .connect_timeout          = 200ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 74,
                            .base_delay               = 5s,
                            .backoff_multiplier       = 3379.2562,
                            .deadline                 = 2min,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    }},
                },
                .tags                     = std::vector<data::tag>{},
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "EZQBHTQUAFDTIGWGNJEQHETAXKSYZQYBEARIECRYKRSERGLXDMFCBQSFH",
                    .extra                    = boost::json::value_from("YSQFSUYGKFQYBUBNDZFMRSUTPCWSOHWPKHHMEJISDJITRWHYPLPLNRPT"),
                    .log_level                = data::severity::error,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 22,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -4937.5701,
                        .deadline                 = 5s,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_78", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "XUTOQCEAMLZXZBZOHVIRUPVNGOKHHZCYEVXZGTKTKMBFQPDPYSKUXWFZO",
                                .port                     = 1545,
                            },
                            .connect_timeout          = 2s,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 23,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{},
                            .tls_cert_path            = "RCFENEDRAMKTHAAOQZBBNXQOEPLVSZIZJQICCBIT",
                        }},
                        {"ep_82", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "RBICWWAIOYFHPUI",
                                .port                     = 42179,
                            },
                            .connect_timeout          = 1min,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 35,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "ILMISWXXQDYMPQVJICLIDNZUNFGMSFGZEUJKNJQA",
                                    .value                    = "MHIWAXOQTRVTAAOVNCPHYAFBEOOGDRTVLAYZPGZTTGBLGYNGBB",
                                },
                                data::tag{
                                    .key                      = "EGVZNQYGRIXHTOQECAMABIJRGQD",
                                    .value                    = "KENRR",
                                },
                            },
                            .tls_cert_path            = "PW",
                        }},
                        {"ep_29", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "OQSPCHEPORH",
                                .port                     = 64644,
                            },
                            .connect_timeout          = 2s,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 76,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -3498.8928,
                                .deadline                 = 30s,
                            },
                            .tags                     = std::nullopt,
                            .tls_cert_path            = std::nullopt,
                        }},
                    },
                    .tags                     = std::nullopt,
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "MVQMPDPJASYMDK",
                        .extra                    = boost::json::value_from("MMYYWDQRBBQAZJIZUYXQN"),
                        .log_level                = data::severity::info,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 87,
                            .base_delay               = 10s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                        .tags                     = std::nullopt,
                        .nested                   = common::box<data::scope_override>{data::scope_override{
                            .scope                    = "EYXWVHIELVCKJGXGMFOIAXRBTWHCUILWDNBURJWYOFIGHXLVURUDIIVHQ",
                            .extra                    = boost::json::value_from("MNKCJGZBKIDUAQKEFLXEE"),
                            .log_level                = data::severity::warning,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 9,
                                .base_delay               = 200ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = 10min,
                            },
                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                {"ep_38", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "RUNPX",
                                        .port                     = 35693,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 88,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -3951.3607,
                                        .deadline                 = 5min,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "TLQQLNDGXPEHEZRGBYWWDNYUEKKTHJEAYYZUGJ",
                                }},
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "ZYPOV",
                                    .value                    = "EA",
                                },
                                data::tag{
                                    .key                      = "HRKBGVKOOEMISZIYA",
                                    .value                    = "EFSQIAOMCDPCCZAKHDIDI",
                                },
                                data::tag{
                                    .key                      = "NVQMRWB",
                                    .value                    = "IBUXXVVPFVLLMIVUPSPXNWDPQGYQDAFPYRVZBIZXXWTSGIPSMTXITGNJXPHH",
                                },
                                data::tag{
                                    .key                      = "RTZQRGOIBUUGIGTXEWXJDNURGVIJWRIZQGYKQCTFSLULWWGIQDQNR",
                                    .value                    = "STVJAOTHKHNHLOHIEVCZCBVTLRLGMQIHIKVQB",
                                },
                            },
                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                .scope                    = "GXIGXFJDPKNGPCBFBHABNWOWTOLBSOLPAMDZPIQILHTLQKCHCFJ",
                                .extra                    = boost::json::value_from("ZISGJMTURIHVHAVUKANCULJBGLIQCBIFOWXWTMZSOYJNBNYIQIDOKSEC"),
                                .log_level                = data::severity::info,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 45,
                                    .base_delay               = 10ms,
                                    .backoff_multiplier       = -1893.4768,
                                    .deadline                 = 5s,
                                },
                                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                    {"ep_35", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "EOQNKKLKCZAOBENGOLTPSXMJAVLBRSVUKWYUANMLC",
                                            .port                     = 24126,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 77,
                                            .base_delay               = 10ms,
                                            .backoff_multiplier       = 9753.8532,
                                            .deadline                 = 5s,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = std::nullopt,
                                    }},
                                },
                                .tags                     = std::nullopt,
                                .nested                   = common::box<data::scope_override>{data::scope_override{
                                    .scope                    = "CFUIHTDYMVLJXNYAVQIMRLOHDGJNADRRXSBFWXDGIOEKBJTEZMVO",
                                    .extra                    = boost::json::value_from("DYUPNYEPRKUCONPDFHIKPNVN"),
                                    .log_level                = std::nullopt,
                                    .retry                    = std::nullopt,
                                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                        {"ep_46", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "NWAJHKPTHORYATFUMQVHCKGFTFZZESLQHMDTRE",
                                                .port                     = 27832,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 61,
                                                .base_delay               = 25ms,
                                                .backoff_multiplier       = -4881.8871,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::nullopt,
                                            .tls_cert_path            = "EKHLORUPRFWIPUUZVVUFUHJP",
                                        }},
                                        {"ep_96", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "YDQGZMIFAMQXENHYZDJ",
                                                .port                     = 15668,
                                            },
                                            .connect_timeout          = 50ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 96,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = -6417.8396,
                                                .deadline                 = 5s,
                                            },
                                            .tags                     = std::nullopt,
                                            .tls_cert_path            = "MRZNAUQGB",
                                        }},
                                        {"ep_51", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "MNDCSMWUZUTELRHVXEWHPZDUNBSNUMWTUHTFQOYRPJGBUKMNOAQNT",
                                                .port                     = 15219,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 20,
                                                .base_delay               = 200ms,
                                                .backoff_multiplier       = 6390.3553,
                                                .deadline                 = 30s,
                                            },
                                            .tags                     = std::vector<data::tag>{},
                                            .tls_cert_path            = "ULRVSKCAXIPSBPAKSGUNAAOPKLLPJEZPNUBECCQTEKKG",
                                        }},
                                        {"ep_98", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "RFPIYIJVBVYMLESXKKQCBAIGUOZQYARPDIHFDNKGWJT",
                                                .port                     = 17322,
                                            },
                                            .connect_timeout          = 500ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 79,
                                                .base_delay               = 200ms,
                                                .backoff_multiplier       = -7753.9698,
                                                .deadline                 = 5s,
                                            },
                                            .tags                     = std::nullopt,
                                            .tls_cert_path            = "XEFAEQQKZPVGINSSAYAMRICFPEBRC",
                                        }},
                                        {"ep_53", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "DQRURPPIHFFRKEQWLHFHGUFRULBQXBYVQQQKR",
                                                .port                     = 25272,
                                            },
                                            .connect_timeout          = 100ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 76,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = -7525.5017,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::nullopt,
                                            .tls_cert_path            = "NRGKKOODWJ",
                                        }},
                                        {"ep_8", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "UBWVXPVVHGGEMMDWMFQISGTGINDFYGAHXGW",
                                                .port                     = 27269,
                                            },
                                            .connect_timeout          = 10s,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 5,
                                                .base_delay               = 1s,
                                                .backoff_multiplier       = std::nullopt,
                                                .deadline                 = 5s,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "GIBIYUSR",
                                                    .value                    = "SQRTJRTUMKGGKQQBFILGGJOMSLPSEIPJBBNJOXIWXMWBOI",
                                                },
                                            },
                                            .tls_cert_path            = std::nullopt,
                                        }},
                                        {"ep_3", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "AKHLSSZC",
                                                .port                     = 21294,
                                            },
                                            .connect_timeout          = 25ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 78,
                                                .base_delay               = 500ms,
                                                .backoff_multiplier       = 2156.2805,
                                                .deadline                 = 5s,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "CGYFU",
                                                    .value                    = "GDFQVEYGWEJSCFZPNDNSLFBPZGGFWJIJXHEZ",
                                                },
                                                data::tag{
                                                    .key                      = "SKAQWJARRWKIBPG",
                                                    .value                    = "YWZFCOQYQPGTFWQJEVNCYMZBOCBWGYJVRXCDNMENKTHLQJOAHDFIQZSHMQUDCH",
                                                },
                                                data::tag{
                                                    .key                      = "TYUCZBKNMFMJZOTAIKTJSXYIFBYMBASMNWHGQBXSHWFGNAI",
                                                    .value                    = "VHQJIRKIGIBENIPKKTLEAFJVBKIBWFXONHYGXBBUPWIZXMJWZCMMSDA",
                                                },
                                                data::tag{
                                                    .key                      = "JVFKNXLXSSEOKFZEQXMNDXTMGILPKPHPFQVHZTGPN",
                                                    .value                    = "JMIDJRBWDOLLZYHKORROTLSFIFNLWXRHNB",
                                                },
                                                data::tag{
                                                    .key                      = "GZGTSSSCHPEQIFE",
                                                    .value                    = "EWOWDHVGVSKQDYIGSZYVUFGHIDFARSMT",
                                                },
                                                data::tag{
                                                    .key                      = "XCCQUIKJSBMMSQFAHBHDDZCFMYZGLHE",
                                                    .value                    = "SQMJHTHUPTKLEAGCVJSTKQLGXNIJVIMM",
                                                },
                                                data::tag{
                                                    .key                      = "NGMCNWPFYHBJMMNSACZQKNXVQSPACGJZYVNJNUEMLNEHEDWEBIMF",
                                                    .value                    = "NLHEXJFBGTOAQFMABEUNMMMQDEENYLPMMBCTTKMJEACVHKLFHVKJLRRO",
                                                },
                                            },
                                            .tls_cert_path            = "MZTLMFYWOZLNRWFUZWZJMAGLLGNGBZZMWAGFQSBENSOEYYVU",
                                        }},
                                        {"ep_29", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "QWQHPZYKBWXC",
                                                .port                     = 56836,
                                            },
                                            .connect_timeout          = 200ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 46,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = 5730.0462,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "BKGOABPYVERSMQGQGPQYWNUPHYLLDAQGMZUWKAA",
                                                    .value                    = "MORIUJLMXMXHYPQJKYDQFXWGJFSCD",
                                                },
                                                data::tag{
                                                    .key                      = "ZCRYDBMIZGGUKGIEUEMXIMHMWCQHEFJHGHYOO",
                                                    .value                    = "MHMNJPYHWQJDGUCLQAESYWAAYZEYJCGMITAEDVPP",
                                                },
                                                data::tag{
                                                    .key                      = "WVLXFDOSOGDNNLGVWXRECAZCLORIVVPWWYMKMSDGHFUEYBMKXMRMY",
                                                    .value                    = "PLGTGCEEAZWQ",
                                                },
                                                data::tag{
                                                    .key                      = "UNHENBBHTBFAMRMFSNRUUNHWHOZPWQVLKNSZMDHJSKTANTJMBBPURY",
                                                    .value                    = "",
                                                },
                                                data::tag{
                                                    .key                      = "MNMOEZDCSSCXDDQCLKZHJHWNNAUETMTDTEZRJNDRFBSZJUBDNVULPCLANT",
                                                    .value                    = "JXEOXNMTS",
                                                },
                                                data::tag{
                                                    .key                      = "OTVDKU",
                                                    .value                    = "RTSGXKMVRHWXDPRUGHVJD",
                                                },
                                            },
                                            .tls_cert_path            = "WRMVUDIZKFXTRVJA",
                                        }},
                                        {"ep_44", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "KPHEOARIUXATYZUMDAVLFODIFGEGILGZNJNHKIQURDZWHMGBAOGWDMQ",
                                                .port                     = 57792,
                                            },
                                            .connect_timeout          = 50ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 30,
                                                .base_delay               = 100ms,
                                                .backoff_multiplier       = std::nullopt,
                                                .deadline                 = 5s,
                                            },
                                            .tags                     = std::nullopt,
                                            .tls_cert_path            = std::nullopt,
                                        }},
                                        {"ep_30", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "VN",
                                                .port                     = 19966,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 94,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = -8921.0266,
                                                .deadline                 = 10min,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "TCYCFTFQLMYOTJKNVUTERKQOHVKJP",
                                                    .value                    = "KBKLGAFAYDMRQPNEDNLMLFIAV",
                                                },
                                                data::tag{
                                                    .key                      = "OQSIBPWTGZPZEVOCZXRRWKPOK",
                                                    .value                    = "BJHMBJXZMWPWLBBCKWXSK",
                                                },
                                            },
                                            .tls_cert_path            = "GTKLKVKXAIFBWZKIJCYNDYQVQLNZJI",
                                        }},
                                        {"ep_88", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "FVHKJUGOBVJCVLGSMCTCXFKNY",
                                                .port                     = 27231,
                                            },
                                            .connect_timeout          = 50ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 76,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = 5772.2301,
                                                .deadline                 = 5s,
                                            },
                                            .tags                     = std::vector<data::tag>{},
                                            .tls_cert_path            = "CDKJUJFCKLTXINFMSFFBJGOYJVR",
                                        }},
                                        {"ep_43", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "XHWHLJAHUDEZEFVWPRNDQSHOTDWZPHLIKOZRMFWGJTZRKVOUPIWCRLDVUFY",
                                                .port                     = 41490,
                                            },
                                            .connect_timeout          = 25ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 6,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = 3555.2987,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "SCTIKYGRWPOCUXPMMEAIELIIHFYXQWDIYXMTNKYMUBIQNSDQCVROLQFBZZHFHOU",
                                                    .value                    = "",
                                                },
                                            },
                                            .tls_cert_path            = std::nullopt,
                                        }},
                                        {"ep_38", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "RNRMKISVDCFZIEHQLUOWLOQVYTUTWXSKBWAELJMYU",
                                                .port                     = 64742,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 33,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = 3137.8429,
                                                .deadline                 = 2min,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "JPMDTTKDCUIMHFPQMOKZYFHIDIVDEC",
                                                    .value                    = "FOOEONMGCPXMKESNQDDDNE",
                                                },
                                                data::tag{
                                                    .key                      = "",
                                                    .value                    = "NCTONDBQXWTTBEVUIGNXR",
                                                },
                                                data::tag{
                                                    .key                      = "ALPNIVGPWBZYYAWPTGDNWXWDLUKKTRIFHKG",
                                                    .value                    = "MKYKFNKCGHZPARWLIZNRHAZIMJMXF",
                                                },
                                                data::tag{
                                                    .key                      = "K",
                                                    .value                    = "TNXXWEZTHS",
                                                },
                                                data::tag{
                                                    .key                      = "NSY",
                                                    .value                    = "JQJDTLMOTGGWKCFGTBJQTYMXNFZGATZ",
                                                },
                                                data::tag{
                                                    .key                      = "NBZGYAMTMPJHEHJEFBEAYMNXSTXBFYDXAGYTDYDSXILRJOJYBVNAKZXGHLHN",
                                                    .value                    = "DCXHVALKTHQSGHGULBXQKMXFH",
                                                },
                                                data::tag{
                                                    .key                      = "BJXFFALBXBOIEERXHLUVIMRDHX",
                                                    .value                    = "XBKULFFKMWVYTTKRDKQMVYQFQNBCWZIJPZHSD",
                                                },
                                                data::tag{
                                                    .key                      = "FLGFXVCSJTVIWIRMZJRVXJIRTZSGTWDKHGTFFMKPWSNOZXEGCYGNWKFRQVDBO",
                                                    .value                    = "IUENGNCQUJBGEGUBAKPOKIPVLSPZEFQAIDCS",
                                                },
                                                data::tag{
                                                    .key                      = "QCVWVRWUDSVOXSVXYN",
                                                    .value                    = "SRLVBNVKELPDYBIPJIUKMGJLILUZJ",
                                                },
                                                data::tag{
                                                    .key                      = "TM",
                                                    .value                    = "RZUJPIHYGHXRZVYDPFHX",
                                                },
                                                data::tag{
                                                    .key                      = "AOV",
                                                    .value                    = "GGWBBCMQZNWKKZGIRISHQOFYPNCKCHTGOFFZVLI",
                                                },
                                            },
                                            .tls_cert_path            = "YNQTQBYGHBGIWVWGLMLVHJUSIANWNS",
                                        }},
                                        {"ep_69", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "NTHOQYHQINCZJKFSFTDYRMIVXDI",
                                                .port                     = 37349,
                                            },
                                            .connect_timeout          = 25ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 25,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = std::nullopt,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::vector<data::tag>{},
                                            .tls_cert_path            = "IDXDPSQFGDMWHJGHBV",
                                        }},
                                        {"ep_40", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "DISJJWCFAWYFESMTJADGLIUYAATBTKFOFOK",
                                                .port                     = 1937,
                                            },
                                            .connect_timeout          = 100ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 32,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = std::nullopt,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "ILFRAHEDDQQEWBXHPSJAJXMTWVGKVNLGN",
                                                    .value                    = "SYLXV",
                                                },
                                                data::tag{
                                                    .key                      = "",
                                                    .value                    = "MQZTMCKFUWDOKDTGFKZWQYHIASPARTYJSPHUMROLAIZCWUEENN",
                                                },
                                                data::tag{
                                                    .key                      = "ESTUSDZBKPLAELGJOAQKTPVNTBTHCAGNLVGZEADJR",
                                                    .value                    = "OFGHX",
                                                },
                                            },
                                            .tls_cert_path            = "DERPZBYCCFDJNTRXYMYTIOXFHUVXTAIEITLAEXFFFVHGNFRLQBFFPOQD",
                                        }},
                                        {"ep_65", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "SINNSYQLRCFQLCVGSKSGCHXBJOOINWNKLPRCXYJPEZLCINDJTGQQQPGRR",
                                                .port                     = 32483,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 41,
                                                .base_delay               = 100ms,
                                                .backoff_multiplier       = 8449.3286,
                                                .deadline                 = 2min,
                                            },
                                            .tags                     = std::nullopt,
                                            .tls_cert_path            = "IBO",
                                        }},
                                        {"ep_1", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "QFSMSJSZEVGRARIWIZWJUKBQONJOPBRCSXCIUOQLIBLKYASSZQTCW",
                                                .port                     = 58276,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 35,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = 231.7304,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::nullopt,
                                            .tls_cert_path            = "BC",
                                        }},
                                        {"ep_95", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "DFGILHYVPFETUQNFDKLIAV",
                                                .port                     = 58770,
                                            },
                                            .connect_timeout          = 2s,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 8,
                                                .base_delay               = 10ms,
                                                .backoff_multiplier       = std::nullopt,
                                                .deadline                 = 5s,
                                            },
                                            .tags                     = std::vector<data::tag>{},
                                            .tls_cert_path            = std::nullopt,
                                        }},
                                        {"ep_48", data::endpoint_config{
                                            .address                  = data::network_address{
                                                .host                     = "GWONHCFOEKKXVYDNAZUZSNJQPPEK",
                                                .port                     = 25441,
                                            },
                                            .connect_timeout          = 10ms,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 37,
                                                .base_delay               = 500ms,
                                                .backoff_multiplier       = 3296.1069,
                                                .deadline                 = std::nullopt,
                                            },
                                            .tags                     = std::vector<data::tag>{},
                                            .tls_cert_path            = std::nullopt,
                                        }},
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "XFWVCBILEZLTSXVIZRQRCIHZYKHNXDHXOIXPKOWMPJYWRQDKESQFQNFLW",
                                            .value                    = "HMEUQUUCPRZTKGMDDNXBGVKJTFAH",
                                        },
                                        data::tag{
                                            .key                      = "YOOAQBORNCRSCXZDGEQEZYCSNMDRWZGRUIPLZKK",
                                            .value                    = "DRHNM",
                                        },
                                        data::tag{
                                            .key                      = "KNSTCFYNAALSQMYKFRVKHDNWHRBCCSOERXATKZPZC",
                                            .value                    = "ONWXDYPCBXDVOMXLRBRXIMQVHXVREMZNNULBEZHMMMIFA",
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
            .host                     = "JWNURCEJYQJAMEQNNUUFAWJHKRIVJVONVRNFFEHHMOHBQEE",
            .port                     = 52544,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"MPA", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "XKAUKZKAEEZAHGSJMBPYKHBUDOFPMWURJAJIN",
                    .warn_at                  = -9343.7466,
                    .crit_at                  = 5225.0449,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "FDTOVXPCVNVSMJTJBSSXVSKPVNKSSHMAJGYJYLODYNWEUJEFFWGFSJCTP",
                    .warn_at                  = -565.5934,
                    .crit_at                  = 4063.1793,
                    .evaluation_window        = 5min,
                },
                data::threshold_rule{
                    .metric_name              = "VLJDLIYLABBSDVKLJEP",
                    .warn_at                  = 4111.2483,
                    .crit_at                  = -3697.742,
                    .evaluation_window        = 5s,
                },
            }},
            {"QESHG", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "DJLBRJ",
                    .warn_at                  = 8675.5248,
                    .crit_at                  = 1375.0886,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "NCEYBFJDC",
                    .warn_at                  = 6297.5888,
                    .crit_at                  = 2985.5237,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "JQPDLWWKUCZQDRKGTMJOXBXSGGTUEWRVNCNBFJBYXGKXB",
                    .warn_at                  = 1420.8298,
                    .crit_at                  = -7633.5474,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "MRMI",
                    .warn_at                  = -907.5665,
                    .crit_at                  = 5124.8271,
                    .evaluation_window        = 5min,
                },
            }},
            {"PIXTTE", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "DTGTIBXFBODYVFNFCQSKCVSBRAZNPQTDRYZTNXETZQEXKHEQVLO",
                    .warn_at                  = -8163.521,
                    .crit_at                  = -6801.5214,
                    .evaluation_window        = 5s,
                },
            }},
            {"FK", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "SRPCRSFTHTKMBWCWBRUJHKT",
                    .warn_at                  = -1408.9701,
                    .crit_at                  = -9239.5229,
                    .evaluation_window        = 10s,
                },
            }},
            {"QZSKWA", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "DBQABWYIMDWYPBZDIZDX",
                    .warn_at                  = -5866.743,
                    .crit_at                  = 482.839,
                    .evaluation_window        = 10s,
                },
            }},
            {"TTHYG", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "NOXXYGVZXKYWGFBZHVFVASGAVWAZEKLTOQYGXZVHBKVRIXUYOYLXKOZSDWE",
                    .warn_at                  = 2024.1999,
                    .crit_at                  = -9593.1245,
                    .evaluation_window        = 30s,
                },
            }},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
