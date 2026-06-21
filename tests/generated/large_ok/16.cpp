#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_16)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/16.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "PJNHOANVWIHUHAJJKVEXTJA",
        .worker_threads           = 202,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{
            {"TUWJH", "LINZCLPNQUFSJSBJCZAQLHPEJJKOOCFWPXAOPAPWZDOTCPUAEW"},
            {"LBRBV", "TKPQVZVUCHKDWCRDHAMUBDXVBYMEUWIHFSAHQHDDU"},
            {"NBMOX", "IBBAWGNVIQMDZGDNUDJDONEMHEEMN"},
            {"FLVPF", "GVNAPJSJDCYZJXPHRUPGSOQEPRCYUVDXVKBOCZPXYBQKRFDWLMJMCHG"},
            {"UA", "MTTGBIUAMUBEVR"},
            {"GQZ", "RVUXXIQATTZZQGPSPLEWOXWFDGACLXJUUDEBFTWYWDXYHLGSNCFCOC"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("FYGNBYLDVMNIDTMTGLXOLNALGCGMNZBSGNYXVRKBQMLAUE", 41694, false),
            std::make_tuple("BMU", 84824, true),
        },
        .allowed_origins          = std::set<std::string>{},
        .config_tree              = data::scope_override{
            .scope                    = "GVSJTVSNABDQRAEKTTCSRJOETNJSTZNRCWYETBJIJUWOXKCUIMJUSZPA",
            .extra                    = boost::json::value_from("KMIOJZG"),
            .log_level                = data::severity::debug,
            .retry                    = data::retry_policy{
                .max_attempts             = 1,
                .base_delay               = 10ms,
                .backoff_multiplier       = -1624.4472,
                .deadline                 = std::nullopt,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "XIZYAKFLNSJLYGFUGZXQBRCIAWARDXIGDDPPLAACWIVNDKNTP",
                .extra                    = boost::json::value_from("HTGJFHVFFMXLCEAUGYEYZUNC"),
                .log_level                = data::severity::warning,
                .retry                    = std::nullopt,
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                .tags                     = std::nullopt,
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "OARALAORNQNSCQEWHRHAF",
                    .extra                    = boost::json::value_from("IH"),
                    .log_level                = data::severity::debug,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 13,
                        .base_delay               = 1s,
                        .backoff_multiplier       = -1581.4465,
                        .deadline                 = 15s,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_2", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "NAGUUNUEAGTTVEASDQGTHMIAOBKXJKWKYHHBQJEWIKLDHCPBJUHIMQEXJQBLMA",
                                .port                     = 14324,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 32,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -5077.6581,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "CSENRFXRTEGTFZGWXYTOQHGENTJBDHZZWZULRZ",
                                    .value                    = "UZVBSDACVVDFEBMNLJ",
                                },
                                data::tag{
                                    .key                      = "KWLUTMYXSN",
                                    .value                    = "HRJNWELWDNMPLEMHNSZNSYZUFGNRCYTMRN",
                                },
                                data::tag{
                                    .key                      = "HOVKLZOCTYRWFJCDTLYKTQITBYGNDINHV",
                                    .value                    = "CNOHQLILQKOQCHZKXAHCTVOJQLFVLVTUYC",
                                },
                            },
                            .tls_cert_path            = "EEVDLVQMJTGBZKJSZIFLRYJUJUZENNMZAIWTJJX",
                        }},
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "JRKKZSJBYYOFPRLNGACKPAIBVPZXPULMHSJUMYKMIWKIGCGLJFDQAYNJXYPLLGG",
                            .value                    = "WFMJWCJPYGUOSBJURHOBRMYXBSDQKCGGMYTOYODTVODAYYZWCLT",
                        },
                        data::tag{
                            .key                      = "YDPICHYNGEPBBJXUSAFAFRDFMMELDRQECACBYTVBAOMAOL",
                            .value                    = "",
                        },
                        data::tag{
                            .key                      = "RVGBSMZ",
                            .value                    = "FSYATJXICSLAATXQB",
                        },
                    },
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "EVTUSHNOIQVOYMJOJQWAFHQKOVIVIURVEMQDDPOWNFLQHMFCIXVL",
                        .extra                    = boost::json::value_from("POBYJQLSFP"),
                        .log_level                = std::nullopt,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 46,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 30s,
                        },
                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "VDZQXWLUUBROLES",
                                .value                    = "WGYYCQTHBPPEKAEZXCJDOVJBKPSJGGWKDLHAWHRHA",
                            },
                            data::tag{
                                .key                      = "VISTGGTGLSKYXOETHOQFXFJZYVZLFXXTG",
                                .value                    = "DRNZWKPZKRSLNLUUKTZFOCOPYVCJYGETRDIX",
                            },
                            data::tag{
                                .key                      = "BDXHAJRNUTEAPSBTDJMTNIASXELGW",
                                .value                    = "CZKDZTZNRRXBIEOKSNOUMNLZVKVNMFJYSWUHPUGGJQLIOXPWCMH",
                            },
                            data::tag{
                                .key                      = "XWTOQQCPILXPBQJOMSNCVQFRODBZLGTOHYSCQAFVFEPNIIA",
                                .value                    = "BCBLUXF",
                            },
                            data::tag{
                                .key                      = "OEUOVEJCABSMIJJJNNQYOCJAMFTYPWPAMUOQUCAZBFBQMXQAH",
                                .value                    = "ALIH",
                            },
                            data::tag{
                                .key                      = "NQFSECLPRNPLDWBCNUIYUTVRBLWHQBCNEGGLLLHPU",
                                .value                    = "SZNTPTOQWVXCCMZUINJAHRZECTQSTXCNGRK",
                            },
                            data::tag{
                                .key                      = "G",
                                .value                    = "EWFSHBZIILFHARXP",
                            },
                        },
                        .nested                   = common::box<data::scope_override>{},
                    }},
                }},
            }},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"LNPRSL", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "VLSPPHEOPSBNLQIUEEODGEZIPVFXNWBL",
                    .warn_at                  = 6884.2147,
                    .crit_at                  = 7736.3411,
                    .evaluation_window        = 2min,
                },
            }},
            {"BJLFS", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "PEPVNYSQHOXPCXGPABKTOKWOHCZRKDIXHSSMFRSCWSRQJUTXBIHHUOSVU",
                    .warn_at                  = -6674.7041,
                    .crit_at                  = -2657.1444,
                    .evaluation_window        = 5s,
                },
            }},
            {"VSDZTY", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "RMQHGYADRHVIHOJWHYWZUMJKRHJVUOTLDJSHYSHFIUDXNTTSBZECVLFD",
                    .warn_at                  = -8253.0381,
                    .crit_at                  = 5508.5525,
                    .evaluation_window        = 10min,
                },
                data::threshold_rule{
                    .metric_name              = "OQRJITGXLRJEAAXTHKHCULOIDCWKAOKXVOTBPJQJSERVWAPNUPXQZMOXVLBBVAR",
                    .warn_at                  = 9192.1898,
                    .crit_at                  = -2780.4115,
                    .evaluation_window        = 5s,
                },
            }},
            {"MYZP", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "DYP",
                    .warn_at                  = -6948.3507,
                    .crit_at                  = -304.7592,
                    .evaluation_window        = 5s,
                },
            }},
            {"GNZO", std::vector<data::threshold_rule>{}},
            {"CNAN", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "TMJHOWIGKUD",
                    .warn_at                  = 4277.0627,
                    .crit_at                  = -4475.6726,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "SFOEZVUIOQSUYLKOPGEMAHATBXBKYJBBMRRKSLQOTRFISNWGSXYGKGSTR",
                    .warn_at                  = 9065.5645,
                    .crit_at                  = -1353.5929,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "ZJVRFHXMZJJTBNZUUXYUKDCXGCUSWXSIDJBVASDYGNVR",
                    .warn_at                  = 2973.9016,
                    .crit_at                  = -383.7157,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "NCTKQIANYDLSNZGELYHWLWERUZAZSKPXYOCKGRZSBTGVWDODUCACSQQOUCZWI",
                    .warn_at                  = 7355.8878,
                    .crit_at                  = -8523.8256,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "CRWZXAVBOFBGWDBLBZFOCRZMNJYYDYZ",
                    .warn_at                  = -6432.6718,
                    .crit_at                  = 6656.3059,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "YEISKVEAWMMSNLBHODAELARWBNZCRQLVFHQMRHBUDUGIILSMEGWIDFO",
                    .warn_at                  = 8220.7028,
                    .crit_at                  = -766.1547,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "CLFOZDJMDHKDAMVQIDTFAJVH",
                    .warn_at                  = 851.4113,
                    .crit_at                  = 7038.6817,
                    .evaluation_window        = 5s,
                },
            }},
            {"BP", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "UHYHEUVHUYTM",
                    .warn_at                  = 7598.9487,
                    .crit_at                  = -9825.0314,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "VMNFHPMFK",
                    .warn_at                  = -1114.6127,
                    .crit_at                  = -8180.4394,
                    .evaluation_window        = 10min,
                },
                data::threshold_rule{
                    .metric_name              = "OKRMBQRUZQYOZMSULLYCKQPXTSCSPSEKRUHKKBAFOSIUP",
                    .warn_at                  = -7288.3083,
                    .crit_at                  = 8469.3609,
                    .evaluation_window        = 5s,
                },
            }},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
