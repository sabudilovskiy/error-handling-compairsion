#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_3)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/3.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "RELTPUSCTAPIRHG",
        .worker_threads           = 254,
        .enable_tracing           = true,
        .shutdown_grace_period    = 1min,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "UEQMXAVYC",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "BJYAIPTXMWZNMXZSOELDBEPGIVNYUJNQMSLRSNSHKVAITVWFWKRSSDWUGUSIJ",
                            .port                     = 8155,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 64,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -8667.7597,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "DBTTYBMWSKRIQHBJACDTRBGNJT",
                                .value                    = "WBKKLEMMOQMUTVRD",
                            },
                            data::tag{
                                .key                      = "QINUXWHJNIQJRKAZNSKAMTSUEBUUKOLVLTWIXPASBVALIUOJSTKFLFKYLTIJ",
                                .value                    = "DYASVXEJQHUZIHKFVNUWDDTKKVHOZFCKXUGSOIHZDBQGKZSFIK",
                            },
                        },
                        .tls_cert_path            = "LSENJQZIOLUNJNSNBNEGAPTQNRWHBXOYVXQJRKHCSJDZHBBZWQG",
                    },
                },
                .min_log_level            = data::severity::error,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"FQ", data::threshold_rule{
                        .metric_name              = "VAQRNBTDKEIRPZZBLHG",
                        .warn_at                  = -7555.5795,
                        .crit_at                  = 7752.7523,
                        .evaluation_window        = 5s,
                    }},
                    {"ZEAP", data::threshold_rule{
                        .metric_name              = "MBYIHITQQNBPKYABYEBDBCPBWCQQPKFKCLMUMSJL",
                        .warn_at                  = -4701.3907,
                        .crit_at                  = 9760.4551,
                        .evaluation_window        = 5s,
                    }},
                    {"WX", data::threshold_rule{
                        .metric_name              = "CSFBLOTUZRMUZBTNBLUPYWKN",
                        .warn_at                  = 9005.7806,
                        .crit_at                  = -1634.1419,
                        .evaluation_window        = 5s,
                    }},
                    {"WSCZ", data::threshold_rule{
                        .metric_name              = "NEAKLRZIDOWDXVQZMVDXKSRDZSW",
                        .warn_at                  = -9901.9744,
                        .crit_at                  = -7129.6328,
                        .evaluation_window        = 30s,
                    }},
                    {"SD", data::threshold_rule{
                        .metric_name              = "MFAKDADVPWJSJZCBYSQQWHDRXDRBRKSFCHFUHOTWYM",
                        .warn_at                  = -4942.0793,
                        .crit_at                  = 1989.0707,
                        .evaluation_window        = 5min,
                    }},
                    {"MQ", data::threshold_rule{
                        .metric_name              = "NXFNWSYSVQVPEUM",
                        .warn_at                  = 7948.0259,
                        .crit_at                  = -7013.452,
                        .evaluation_window        = 5s,
                    }},
                    {"OSXFEI", data::threshold_rule{
                        .metric_name              = "ESQKHWRYJVWNTSSIGJAIPZMGFSLHKPYENWPWTGOSURAPXCMZ",
                        .warn_at                  = 4671.7688,
                        .crit_at                  = 9205.1774,
                        .evaluation_window        = 5s,
                    }},
                    {"UWY", data::threshold_rule{
                        .metric_name              = "GIHGYIEFTWVBIFBKFNCXZCDCIJBLOSXVKAAKKNMPCGU",
                        .warn_at                  = 1702.1079,
                        .crit_at                  = 9106.7461,
                        .evaluation_window        = 5s,
                    }},
                    {"IC", data::threshold_rule{
                        .metric_name              = "DOQIDQWLVYLYOJVVVUZIDYKVSRQDVPQLBWJVXSXFUU",
                        .warn_at                  = 4603.9894,
                        .crit_at                  = -7009.1617,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 11,
                    .base_delay               = 25ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 15s,
                },
            },
            data::backend_group{
                .name                     = "FOPJZFWCDWFYRRSXMLD",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "EBPQIHWYQLKMORZYCLPDEISD",
                            .port                     = 44661,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 91,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 1341.8353,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "MZGRQFSFGILZJAZONMKRSJUPQVWJVPATGXUADY",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"GGZQG", data::threshold_rule{
                        .metric_name              = "QU",
                        .warn_at                  = 8934.6109,
                        .crit_at                  = -7768.5281,
                        .evaluation_window        = 5s,
                    }},
                    {"EOZ", data::threshold_rule{
                        .metric_name              = "BALTH",
                        .warn_at                  = 119.0779,
                        .crit_at                  = -28.0357,
                        .evaluation_window        = 5s,
                    }},
                    {"LWWE", data::threshold_rule{
                        .metric_name              = "TYBWC",
                        .warn_at                  = 4794.393,
                        .crit_at                  = -3128.1427,
                        .evaluation_window        = 1min,
                    }},
                },
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "PKDZBNCGWFMPPWCRNGUPJAOOYWMOFOBXILLOQLTMHAZGIZLE",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"SMQ", data::threshold_rule{
                        .metric_name              = "AEDTFOPFBA",
                        .warn_at                  = -1937.8457,
                        .crit_at                  = -3642.871,
                        .evaluation_window        = 5s,
                    }},
                    {"MBM", data::threshold_rule{
                        .metric_name              = "HHDMPGFKTDLDTBZXJIZOZJPHRIAKULK",
                        .warn_at                  = -8125.6825,
                        .crit_at                  = 3647.9727,
                        .evaluation_window        = 10min,
                    }},
                    {"DA", data::threshold_rule{
                        .metric_name              = "AFQBPBGUQKGYPKZPLVBMJYTUMCJFNDQMRKRVYMFXXMR",
                        .warn_at                  = -2815.2719,
                        .crit_at                  = -6321.4291,
                        .evaluation_window        = 1min,
                    }},
                    {"YWPLI", data::threshold_rule{
                        .metric_name              = "QXYTWWMPBEFWYAOCYWVVDKHTZUBTBOOXUKLACGMZDKSJDOCUGHWB",
                        .warn_at                  = 9552.8975,
                        .crit_at                  = 8708.9826,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 29,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 10s,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::nullopt,
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("ZD", 59815, false),
            std::make_tuple("ICDOMHVTDUPYVWLMTVOYDJTOMGDRAOJXUCKLGPYCRVXLNZUCTQGHLBKHNOCI", 21788, true),
        },
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "RNLGTNPYNPSBJAFDAXEJQQBUPBGXGIPNBLOXGXZJEDOJNOCGEPYZWJMZULF",
            .port                     = 28265,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 1min,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
