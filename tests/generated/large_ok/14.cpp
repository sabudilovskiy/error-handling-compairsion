#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_14)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/14.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WYUQHI",
        .worker_threads           = 188,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "MYDIHKLZILZUUQEFRVVIFAUCDTKACIGMMSOTDUVDSSUULFDXPQVGIOT",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "QIDDCIIDAFXNDVQSCNPVFRMOJPONNTDIPMHOTPCSEPWISOAWMNA",
                            .port                     = 22773,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 93,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -6225.7883,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "JA",
                                .value                    = "SQJQZLIDBEYGAHIQIFHGTVKJXYLBRTXZYFQUGLPMHMRRYKPTBHUNPYKCIZDEGB",
                            },
                            data::tag{
                                .key                      = "IPOERMBZD",
                                .value                    = "LRNNEOHCEZXFEAVH",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"SN", data::threshold_rule{
                        .metric_name              = "PKCLBVUURDCNDBUFCAZVJBEMSEAOO",
                        .warn_at                  = 5685.2332,
                        .crit_at                  = -94.1626,
                        .evaluation_window        = 10s,
                    }},
                    {"HJVS", data::threshold_rule{
                        .metric_name              = "ARZHXALDDMMOJLXKAIEJSZYWJGQSOAUCOKSMZTNIV",
                        .warn_at                  = 5267.8272,
                        .crit_at                  = 9524.2032,
                        .evaluation_window        = 10min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 71,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = std::nullopt,
                },
            },
        },
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{},
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{},
        .allowed_origins          = std::set<std::string>{
            "EOG",
            "GQSUJDPUMAPRKNKJRKRCZUAKCHFGOIOPWMYMAMSHW",
            "GVZ",
            "J",
            "LVXFEZAGQYCESHJMSPTZLFLHRULKQNDABJIFJGZZ",
            "PDCYXCRSHHDEPRPKMQCUVLDQKIFOPWYDULBROKAYBRMGHRDLQWZFINBFYCNUKPG",
            "TSGYV",
            "WNEYRRYWNJWHZJGFWUDIHQUBGEGMIDHHAGXVVYJBIRHHKEHBZIFARNUQIPOY",
            "XHMJTODMYDOYTYZCWRHBSRGRRYSMGRCE",
            "YNOHXCUCWWFWLOWGMDTLPGYVLKPRJBFTUOEIPJRBE",
            "ZNWZOKLMSPWXIMILFAEXJDPXUPVBHP",
        },
        .config_tree              = data::scope_override{
            .scope                    = "YFTGWFMBGJEBKKCQGADXCRYAYH",
            .extra                    = boost::json::value_from("EBKKSTZNTNTAURPABADWNGTTAZUEDJKABRX"),
            .log_level                = data::severity::error,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_35", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "PNGPVXZGQFZTPHIPFBCVMKPFFZSQNKUJNYRKABLBRQZHARABKCQY",
                        .port                     = 52219,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 34,
                        .base_delay               = 25ms,
                        .backoff_multiplier       = 1460.5069,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{},
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_26", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "WLUCTJUQIVRJOHBXTUO",
                        .port                     = 7215,
                    },
                    .connect_timeout          = 2s,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 38,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 15s,
                    },
                    .tags                     = std::vector<data::tag>{},
                    .tls_cert_path            = "PWOYBI",
                }},
                {"ep_71", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "REKRWJIVPCDOPYIAJU",
                        .port                     = 61617,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 86,
                        .base_delay               = 200ms,
                        .backoff_multiplier       = -8288.2419,
                        .deadline                 = 2min,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = std::nullopt,
                }},
            },
            .tags                     = std::vector<data::tag>{},
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "MIMNKDDRQPKDHNFMOASXZXVYIZYLTWJPNXMIIOZMFJXYGONXMVR",
                .extra                    = boost::json::value_from("IFBPJEDQHBYAXFSDSEDRHPWGSFWGBPKEASZW"),
                .log_level                = data::severity::critical,
                .retry                    = data::retry_policy{
                    .max_attempts             = 10,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -5941.7866,
                    .deadline                 = 5s,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_63", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "QYHNJYHILQQVQCBG",
                            .port                     = 28817,
                        },
                        .connect_timeout          = 1s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 29,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = 9706.5187,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "XHGCLNQVAEKWMJSJZNYBABMBBOHBREBSIOEIDEVIR",
                    }},
                    {"ep_31", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "CFTNYMRYOAJQXSNVDSRZJCXAFZTKWXTBODXNCRESEYNCSSVCBVHLRHHEUCH",
                            .port                     = 14547,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 18,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "IXODZM",
                                .value                    = "KALYHQBXELKANGQMAQYIEBBGHDDYQHG",
                            },
                        },
                        .tls_cert_path            = "HKTUXGWVSYOCOPUDCXKDADRAAWABPMSFPWTAZMXF",
                    }},
                    {"ep_99", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "VFONLRIZUTDZPD",
                            .port                     = 48346,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 54,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 2min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "GRZRKOAJXSBYQDSLMVRDCFZRWJCQWPZUCAHVVKYFOLPZGOBMQYESWEVVFJT",
                                .value                    = "ENHVCFXXVPVZWXPMIGPYREMPHLSMUU",
                            },
                            data::tag{
                                .key                      = "YGXZYXRM",
                                .value                    = "ZOFDFECJXSTHVYLUXYNJBXSWGFOYYENHVQTZEVWMLPFYIUDG",
                            },
                            data::tag{
                                .key                      = "LSMCFT",
                                .value                    = "OVZJWDDBIERKGAWJCPOOPQRGAVYTG",
                            },
                            data::tag{
                                .key                      = "EKXBBCRKOWGZVJMQZGQFEDYRIXIQGVZHJFIGMIIMHQVIBLJZIZIWSDUQTI",
                                .value                    = "YTXIXEPYYYX",
                            },
                            data::tag{
                                .key                      = "FBOKIMLDJQQBRFQDWZSLOIVTRDWX",
                                .value                    = "ALGAEKZXYKUCMXNRPJYLPLJOGOLGOBUUVBKVOOUWOS",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    }},
                    {"ep_25", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LCNXVJWBWUNMIPYXGQIWCBQQXNAJORZLNGBPHLXJIMFRGUCKSRLGDBVJ",
                            .port                     = 21996,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 98,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = -5779.8317,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "RDHFZAAFPECRAUQEUESYBAGVVGQMGV",
                    }},
                    {"ep_95", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "BCHVVXEVZIZWAEJCJDXLMPEAIOOVLVRZXKTOAYMQCNQGIS",
                            .port                     = 45607,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 62,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "YXSAAZAUYDBJPEQKPEZXEFOBEMFIKRUIXGLLMSFAXBL",
                                .value                    = "YIXGWGPMOPBXVLUILREU",
                            },
                            data::tag{
                                .key                      = "CFTLYWXBLWVPGPIUDJQCVOBBYZZPBDVWSRHFLKGMAMWMDRCTZCC",
                                .value                    = "OVESKU",
                            },
                            data::tag{
                                .key                      = "KOQWLGYFOJFHEOMZLD",
                                .value                    = "VOBCWCZTDVQIWKYHWBCMMDZXRZYHSIHLSGNKVEJANMYWUVVJOGFYIDDATDFVVF",
                            },
                            data::tag{
                                .key                      = "HAFOXHPZCURORHYTUNORDOUZMYGAKCGDZBLQPKOHOVNTZG",
                                .value                    = "X",
                            },
                        },
                        .tls_cert_path            = "JONHMJGATCJHGANZLNRMJMYPHYUIU",
                    }},
                    {"ep_13", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "IUWIILFHVVSNEYFZTMOJHWIJBFUPCGFGILDVYFFFDLDCRZNPHXFIXABYQFNWRA",
                            .port                     = 23113,
                        },
                        .connect_timeout          = 5s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 6,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = -8917.2972,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "EHZTJAYYVJQ",
                                .value                    = "SAHAMQQGCGJYDIXEHXEJTTFWALKMJBFPRUGREURMEYPEUFFBKZMFDOSPXC",
                            },
                            data::tag{
                                .key                      = "MNR",
                                .value                    = "SHVNNRPEIVDYOJ",
                            },
                        },
                        .tls_cert_path            = "UZBNEEVWBWXVPDCEVIAMHPZOUHEWTE",
                    }},
                    {"ep_64", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YSBDNMYLNGGSGVFHXMGRRQ",
                            .port                     = 58933,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 77,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -1489.4745,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "IFGWJNNPVXUDBPGHIXOBONWJUDSWIFZRGFIQUASNOCCPHRJULTWIKSVBJREJC",
                                .value                    = "ANMCQXRSRXPXYAARQTIJMRFDTRZHVAPDUIHJMEEIPSHPMOIAGEZJOWUIZFBTNIP",
                            },
                            data::tag{
                                .key                      = "XPEWIFOKUTAWVYSJHYBZ",
                                .value                    = "UAZJBSSUKDAXURIJAXXNOFVKRKGOBEDJJTVOTKMUCUJMSSTTGXNIQMRBMRJ",
                            },
                        },
                        .tls_cert_path            = "LD",
                    }},
                },
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "RUKTMLEZSIKQGLSMIVWPQBOESLEBZSDFZEVZG",
                        .value                    = "MCAWNBMFQADGARTRUNZEVXZCZVOLPLLRJKIEFXJBDZCHSGCLFSZZZTZMZKR",
                    },
                    data::tag{
                        .key                      = "NBJKPZVXYJFXVFEYDZESUDKYZVUGXCHTTIAJSDXTOMMIURVEOOLUKTJY",
                        .value                    = "IBZHAQPUDXKTBGJTDTHYCTWBZNMWTWUBXSFQSZJBFYZLLBWPEG",
                    },
                    data::tag{
                        .key                      = "QURKUTZZPWKXDNBAESPGSSEY",
                        .value                    = "ZORWEDNVYBCONCQRSBNOUBWSYFI",
                    },
                    data::tag{
                        .key                      = "HNYGDPLVAKLO",
                        .value                    = "UOYGOFYFHXCAVBPBEKKF",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "COYB",
                    .extra                    = boost::json::value_from("HHTCMKBIQJRXHLAPHRFJQF"),
                    .log_level                = data::severity::warning,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 75,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = 7659.9248,
                        .deadline                 = 10min,
                    },
                    .endpoint_overrides       = std::nullopt,
                    .tags                     = std::nullopt,
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "MIDP",
                        .extra                    = boost::json::value_from("QHNNOHBGZWXYCJEWVVVTNYHMDNIDVNNFJKPRZSQESOFJPZPKFFUKFPIYCQK"),
                        .log_level                = data::severity::warning,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 26,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -535.906,
                            .deadline                 = 5s,
                        },
                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                            {"ep_61", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "QAWQBBGISIEFQFHXAKHAHLNCMFUHFVMAXJFZSPVBDUVGNPMDQI",
                                    .port                     = 22342,
                                },
                                .connect_timeout          = 25ms,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 43,
                                    .base_delay               = 10ms,
                                    .backoff_multiplier       = -6783.4858,
                                    .deadline                 = 5s,
                                },
                                .tags                     = std::nullopt,
                                .tls_cert_path            = "ELWEQQG",
                            }},
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "MPS",
                                .value                    = "MOEUNRNEMRAAFFEMHBZNKMLEJNVMJDPNVZMQYNZAAQSWXOLQ",
                            },
                        },
                        .nested                   = common::box<data::scope_override>{},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "VLYNPGTFDSYYFBKYIJT",
            .port                     = 46705,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 5s,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
