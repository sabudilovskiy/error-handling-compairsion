#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_5)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/5.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "XLZWXUQAOYHUBFDLPHMRDSHAXGNIFYMFYZCETTO",
        .worker_threads           = 33,
        .enable_tracing           = true,
        .shutdown_grace_period    = 2min,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "FJKGRVUGFWGMJALNFEICKJTSATVWKCJLJPWKFPPWFBIAXLMARZNLMSAOBWFTGD",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::error,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"IYODSX", data::threshold_rule{
                        .metric_name              = "LJBNCGKQTLEKIWRCJVKJFZCUEXWJPFXBCTRMBHXTLIOUNEBUB",
                        .warn_at                  = 6033.2886,
                        .crit_at                  = -3316.2941,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 14,
                    .base_delay               = 2s,
                    .backoff_multiplier       = -6623.5828,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "TFQOPWXKP",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "EDMRFUPKFCPIQZRQLCZZYLWSVBYJLR",
                            .port                     = 46167,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 49,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = -4122.9591,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "",
                                .value                    = "IKVIOJQUVZLLIULXNLFWOLKQEQFGLPJWCXV",
                            },
                            data::tag{
                                .key                      = "YSQVNJTRYU",
                                .value                    = "AGFSOTUFHYVFUWBPH",
                            },
                            data::tag{
                                .key                      = "DKFPGRBNOLMVTCSGHWLALMINDWRLBRTJDJRQKSJLENNSURLOEFTMSPGET",
                                .value                    = "VAMDK",
                            },
                            data::tag{
                                .key                      = "EKUSMNNHPJPWMMFTTIXJPINAKJPJEPADVTOHJBZ",
                                .value                    = "MAPRRIHP",
                            },
                        },
                        .tls_cert_path            = "EXJJPTPQUTXDAYEJJ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "JXQAOLLVXSEBAIROVDVRG",
                            .port                     = 955,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 43,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = 2644.7069,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "GJOYCJAWYNSJUYPJEFPWRPKRENSRZBCXHICZCVAKXNCMWPBDDHTUDW",
                                .value                    = "JWOEFTFNZFCTGBRDVMXCIBSSDXMTEANCKVTPPLULBEWJESUVQJRRTHICR",
                            },
                            data::tag{
                                .key                      = "JQEZHLOXMFEWAUKCSVBCDQTOHMOPKDZQARXMBENVZHXDCVPGEWTML",
                                .value                    = "JKTWLZMMEXLUJZUNLQBSSGXFMCDBBFGGBPPVYLANPJTNKOODGEUFC",
                            },
                            data::tag{
                                .key                      = "PERIDIFYJVHBPBLYLKBWAVOP",
                                .value                    = "EDZVKJOVHXFBGWASHVCTMWLVJFOLJCXWOFYHFVGBUTNXIAOBOYVNFB",
                            },
                            data::tag{
                                .key                      = "QSLDWCHZPCPBVHUBPMZBBINOJUBBGFWQUMGRHCKZDCRFTCXGTAORL",
                                .value                    = "SYMQUEXAYJWOHRDEJPCYYIMKEERCPHW",
                            },
                            data::tag{
                                .key                      = "SVHIBPWHBWGZJLDCNYKMYYRAJUY",
                                .value                    = "AOEWUZAX",
                            },
                            data::tag{
                                .key                      = "DZZMREKCJFEIPVKJBCRYXRAADBE",
                                .value                    = "NITAHQNELGKLAFSTFXDIQTFUWEOYNZNDKKOHOTNFOBYVFRPPTADE",
                            },
                        },
                        .tls_cert_path            = "ABS",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LMOGGIGJRQLYYZHLLZHVBTPMLEEHPMBDFMDYWJGZZYKPV",
                            .port                     = 30811,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 10,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -7929.2334,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "TJQMQPRWWMOZSWRVBREZNLSAVYQGJJCACYLTSYWNJAI",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 95,
                    .base_delay               = 2s,
                    .backoff_multiplier       = 6765.0922,
                    .deadline                 = 10s,
                },
            },
            data::backend_group{
                .name                     = "DHKZRNMAVMMFYUQGVTKMKDWRWWLHDGJJZ",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "FCUNYFHUCSSUURXNNHNPQTHJNICTKFNAEDJSRTS",
                            .port                     = 12051,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 59,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = 4578.471,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "UMHWTZPDAGVFDCKELTYDSYOXKYZFWRSUDLDCGGKLFOVXYCHMROMADT",
                            .port                     = 63051,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 1,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 4848.5214,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "LYXGKMEJPUWYZCSDJNKCQNBHNHIVXCEIDRPNFRMHCOLEZCAYELZ",
                                .value                    = "I",
                            },
                            data::tag{
                                .key                      = "QCBGGZOAPQCITVPQABFMYYQNSVUTUSBGANYXNZNMAYFKEJYGNCLGMNGIEPLJA",
                                .value                    = "DYFYOCCVMBNEGUAXPKTOEOHCLTAAFZNCIEYULKYGEJ",
                            },
                            data::tag{
                                .key                      = "WRCJDDUMLJLPRSOHSEIARAXMEHPVWBAAYGNHQWTHZJBZQHBWMLYARJOODUDLSQ",
                                .value                    = "STMMJFSVCUOBXGQTM",
                            },
                            data::tag{
                                .key                      = "RLNEOLCPASSGSOBBXCDKELKIIPZEXDII",
                                .value                    = "UIMFUZHWISOFTESBXLRDAOBWTPVUBASNDNXQTOTSHRWDWCXVSCBCW",
                            },
                            data::tag{
                                .key                      = "RXCUVIDMYJIOJJAYKQVPOMEUGIKTGOCELCUNOTQUM",
                                .value                    = "EPFVQOSLAEN",
                            },
                            data::tag{
                                .key                      = "RGRHVFNRZIKJTDGINLQIPUWUCDWYDKD",
                                .value                    = "UJYSFB",
                            },
                        },
                        .tls_cert_path            = "KXYIDNKDJCJ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "NCCJCFBDZXQNDONCHNASRJUDVQ",
                            .port                     = 21187,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 8,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -5079.1953,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "DIJRONBGQEMVUFGKZWQCEJBU",
                                .value                    = "ORZSUQIJFXUIOPMYWTDETGOWXYDOH",
                            },
                            data::tag{
                                .key                      = "CXOITOVFZW",
                                .value                    = "JSIULWBRXRDGYAKSSPUPQTJTKBJEQN",
                            },
                            data::tag{
                                .key                      = "YEJUGYXBAPFJNVJNSVOKXQQ",
                                .value                    = "WTZZAFSPUARZPYOLBHRA",
                            },
                            data::tag{
                                .key                      = "GFFQHVM",
                                .value                    = "MNUHUIAGVHSCXQLNSJHXDLRTRYZOZVXBIQAENBOAG",
                            },
                        },
                        .tls_cert_path            = "OZPPJQCAYZWYTTOTTTWTGAUOQGCWK",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "CFHMABNBJGXMMFYDMWGGEMOENAIOQYGWWV",
                            .port                     = 17478,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 24,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "XOXGGKSIWVYBGRFLUDWTNLEUJFAREWNDXAWROKXCPELABXTLYPIZ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "KTRNFMNROAHPJDQCYRPHCVUTKDCXKNFKLYYBJUVYDQCYUVUCBPQPGOJE",
                            .port                     = 27800,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 57,
                            .base_delay               = 1min,
                            .backoff_multiplier       = 7620.038,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "NDFLUNCKGLVDOKDPKBVOWBTH",
                                .value                    = "JIOQQLQQCQSONVGTXMNDECOKBJZLNTSDFAOEXJBSDSYWBCCJUJJNVHBN",
                            },
                            data::tag{
                                .key                      = "KQWQSMOTOB",
                                .value                    = "PKTCDOILZKU",
                            },
                        },
                        .tls_cert_path            = "IEEXZXROLIFFNAVMKIGTENTQODJMBGGVMHWPSVQADYRJDKKTLFABGP",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "GBHKZKHLOABWDYGDWJDHCUDYXSLZKI",
                            .port                     = 26922,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 31,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 9262.7039,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "BXXXYRGMVSDJPB",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "",
                            .port                     = 9657,
                        },
                        .connect_timeout          = 200ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 92,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 2289.6164,
                            .deadline                 = 15s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "IUGZSJOEVASSGHASJCHHGM",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "JXEGYFDTSTWXTPHOUJWICTFSOZRUDVXULSPQA",
                            .port                     = 19800,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 60,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = -4418.0064,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "RUGXDTAPFJRAGIWFIMICULJWDTHA",
                                .value                    = "IZMOZICPMPEMVXPRBYMTTBGQYVIKQVFLNTZTVV",
                            },
                            data::tag{
                                .key                      = "WWHSTZTVBJYHNPPQXFYZOPPO",
                                .value                    = "HHKWWHECDYOUORUZAVEAPWTVWEDZBYCNOFDYAKZY",
                            },
                            data::tag{
                                .key                      = "QUYKWHFPQPVRKBYSKAPBGGRIIJHZVHOVCSPPHKNIGLNAKDZEHKJYHLYHJDURPID",
                                .value                    = "UIBEVZDDOJYERHKKFBNUNMADIQWMXCZDAK",
                            },
                            data::tag{
                                .key                      = "XUELRJICNNQAOPJXPDJQYCHNDDSHU",
                                .value                    = "TMQGVVVPQQLGEWAADTMNAVOKRHKPIGHPPICICTSRJWNBVOBVFBHNQSEGLHVCYQN",
                            },
                            data::tag{
                                .key                      = "UPSZEOFLPDOJCOKVLTXHCQIVULJV",
                                .value                    = "XLLLZFHMQNLTINNHTFYWAKBDYGXNYQTPV",
                            },
                            data::tag{
                                .key                      = "GLHMDSBMKHLFNKIZJPKFHBYOKHC",
                                .value                    = "LJCJETKQWPYVFPGMOZIUTSAZZWTGDNYFQAWVSKWI",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"WQ", data::threshold_rule{
                        .metric_name              = "YFWSUKJWGTMWFE",
                        .warn_at                  = 2104.0007,
                        .crit_at                  = -322.1947,
                        .evaluation_window        = 10min,
                    }},
                    {"KWIKK", data::threshold_rule{
                        .metric_name              = "JV",
                        .warn_at                  = -2072.3716,
                        .crit_at                  = 2169.5288,
                        .evaluation_window        = 30s,
                    }},
                    {"ZD", data::threshold_rule{
                        .metric_name              = "DTNUT",
                        .warn_at                  = -7865.2929,
                        .crit_at                  = -2805.3992,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 60,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -4855.3228,
                    .deadline                 = std::nullopt,
                },
            },
        },
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{
            {"WDPEXC", "EUTXHYBMDEOYCGVOWCIXAD"},
            {"STV", "XNQSPJDHERPTLU"},
            {"AUEUN", "EVBMYBNFLSVOUPPNHKLPYVNDXARXWAGVZXROEKKV"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("CDCVCCVQECGPNYLMH", 59879, true),
        },
        .allowed_origins          = std::set<std::string>{
            "JIBXNZSMHTKESTEAGOUGBAVLZIPPPCORCVKFSZQBZSCUASKDDPARHTOAWHMLDB",
        },
        .config_tree              = data::scope_override{
            .scope                    = "IHLSOSGHGFGDXSMUPAVITPGAHARXNE",
            .extra                    = boost::json::value_from("IFKRDWKIG"),
            .log_level                = data::severity::critical,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_56", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "PHZKBFVQRJIZEDOCDQEIXYLIBOHVPYHOFRFIYVLUGWVNAB",
                        .port                     = 17603,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 37,
                        .base_delay               = 50ms,
                        .backoff_multiplier       = -648.9703,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "TDKZZOWPMYRCTXJVSPGNIBCLKNLRIGDIYEIEXCGCFLT",
                }},
                {"ep_72", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "IXSXIUNDMJMONHZUCEGSLZHQHIMFOLNMTEIWLCQKF",
                        .port                     = 43698,
                    },
                    .connect_timeout          = 1s,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 69,
                        .base_delay               = 50ms,
                        .backoff_multiplier       = 7254.0621,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "U",
                }},
                {"ep_26", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "P",
                        .port                     = 54797,
                    },
                    .connect_timeout          = 50ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 33,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = 1055.5513,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "LRERVIHUHFEWVFINPUOWHFNQBEFXZLSGAYJGWMTTTYVAEUOIWECWOKUF",
                            .value                    = "WZGZ",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_88", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "POCSEXIWCZECDCVINOHHYZVXPNPCMOJKHPAZZEAVILTSCOURMHOCRRTUPHK",
                        .port                     = 52224,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 19,
                        .base_delay               = 500ms,
                        .backoff_multiplier       = -5491.4726,
                        .deadline                 = std::nullopt,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "KURNRJERIXWLILVTSLGVBMEYVMSJFAKKEEKNYHKMHHSJPEQGUMVDZEWTQJNVBVC",
                            .value                    = "YSKEZNGWYAWPYKEQL",
                        },
                        data::tag{
                            .key                      = "FJJOCAFSDCABKTXNORUIQSLMNBZIXDFGMZZQLXAYGESCGIEYXYRJMXJ",
                            .value                    = "FEJ",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
            },
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "FHUSTSPZPQWEHHSZZEXYTYJRQHKR",
                    .value                    = "QFBUFTUJPZOBUITIPJUBZAXCXHGGPIGFYHGKFMOALFDUFWULWTMFNVHZUZS",
                },
                data::tag{
                    .key                      = "OIHNWCYCETVWRGWEUNGMNYOEFOUTKAWIIWXJRNSDBRYRYLJKXCDERLPJGCBNG",
                    .value                    = "FKYDAACWBLINJDA",
                },
                data::tag{
                    .key                      = "BTRUAAJLWXFNLTKLDRHZLFVNGTGQPIKO",
                    .value                    = "TNIWIQJZJQTGYVZIGZMGPUBJLSQPLU",
                },
                data::tag{
                    .key                      = "QMZSWIRVQNRWJLUGWPVPLABEIOUYZMDZSJGDEZENZUGK",
                    .value                    = "EOMGVHLTUWBRSAQVRRQW",
                },
            },
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"AGUPC", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "XLWXKXUHDRPFQGQVPUXBQZSXOQHLZZDBGBFPYCMODKSHVYGSIFGHM",
                    .warn_at                  = 9913.6944,
                    .crit_at                  = 907.3113,
                    .evaluation_window        = 5min,
                },
            }},
            {"GUWCVN", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "BXMMCGPXTJNIQIKVXUVSSXPYCEDSRTKDESDTATX",
                    .warn_at                  = -8358.3198,
                    .crit_at                  = 5463.0378,
                    .evaluation_window        = 2min,
                },
            }},
            {"IS", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "I",
                    .warn_at                  = 8819.7169,
                    .crit_at                  = 4434.0623,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "ERJJYROJWAESPDLFWISIIYMYBRMFMC",
                    .warn_at                  = -675.0563,
                    .crit_at                  = -6644.1312,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "YCJKCUBXBLLLZQQNCEGJLSHD",
                    .warn_at                  = 3247.6279,
                    .crit_at                  = 9370.2216,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "LBBLCDALECEZFXJOHGBAY",
                    .warn_at                  = -761.9264,
                    .crit_at                  = 5513.5001,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "ZTBRFEWC",
                    .warn_at                  = 2838.899,
                    .crit_at                  = -6563.9494,
                    .evaluation_window        = 5min,
                },
            }},
        },
        .warmup_delay             = 100ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
