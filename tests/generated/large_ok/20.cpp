#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_20)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/20.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VZYEIVUDKSFANNCDEKPSONGGKUVKKNCUQZPMCGSHBGDCGIWYJJWIFTDAI",
        .worker_threads           = 180,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "JIEWUKTXOEUIRNFFMWDWEYSNLHDTBQGNFFCDZJAZU",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::error,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 76,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -7649.083,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "CKIUCVYJVBZAGHQQWAFAVXQEJENIDMDGHGHDJERMEUCOPAF",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "MDJGLTJEVXDAIBMLXJMOZDCSPGAWXQCYRTKWAFIJ",
                            .port                     = 39923,
                        },
                        .connect_timeout          = 10s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 1,
                            .base_delay               = 1min,
                            .backoff_multiplier       = -5860.6521,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "ZJOBZUETMRMMIAZYOCSPKHYGJOKMGTBLECXLAYDPHREJYXAEVLLQEA",
                                .value                    = "QOHMMWRWJQTUWJ",
                            },
                            data::tag{
                                .key                      = "UPILXEOVXHPELKUREUXWXVVRYDXIUBQGLMGRQWJPUFEEIASVC",
                                .value                    = "FKIHYVKCEIIDEJCPBQBPPMWQXVDUEWJQRNFOOVYQPEFGGJDGOMOCYYJU",
                            },
                            data::tag{
                                .key                      = "XGXJGQJNPDLQHXZFRSLJEAKZMEJQXEQCFTQQBDINSCRGTVOONWB",
                                .value                    = "FFZDPWTSXUJFHIHDDRWRSONKZHRXFQBOCQAJAIYLIJRMU",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LABSXYFFHUCXONBATYGMRRZOCJYOWVYQJKDOGETUDXB",
                            .port                     = 56260,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 21,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -8957.1816,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "TKUYTREKBACQQQPFEGRLEEYJZDFRJOGCDEATEQYLJL",
                                .value                    = "AIWAOAKZJWPOZJBABCAQJNIOTICUNWCAMYAIXAYVQSCVAKXDPNDKQAXAVDSVU",
                            },
                            data::tag{
                                .key                      = "OHLLRCWQDWCHISOOPBBZZZYUOCFFSQTGRTZTSHG",
                                .value                    = "BELSXXTOXKOPAJT",
                            },
                            data::tag{
                                .key                      = "JYETSWSXQFBZHIFQBYQAUYDGDPOQIHBNHJZYKJHLPNVCGGG",
                                .value                    = "POUKEOVRMCAYEPGSSXQBPWIADQOBHDVZAECHMQARKGIUXRIKGWHNBIURTXAQH",
                            },
                            data::tag{
                                .key                      = "KXLCCTMPFIECWEBEXHDSA",
                                .value                    = "KHBPHEWMDOIZR",
                            },
                            data::tag{
                                .key                      = "MCN",
                                .value                    = "NRDUXHSWUXQTWHKDRAGAQBKFZVNK",
                            },
                            data::tag{
                                .key                      = "JPVTZJDKC",
                                .value                    = "SOTQHJAVUGMRDG",
                            },
                            data::tag{
                                .key                      = "PTQNGECQEMPVSQQRWRBSOHCMKCCT",
                                .value                    = "EGBBHEADVEIPNRSIFYYOYFEBGDQLOPKXBKKYMDZAWYOFCUQYOR",
                            },
                            data::tag{
                                .key                      = "XUVNTGXXVFLBVRSEUJWL",
                                .value                    = "WTICURHMPBTAAVWWPTUZQRLRVHMCWZQPKSGVQOVDMCTWDZSRYFNMEXJESSWXJZV",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "FNLKVIGHKDAJPEKPGSXRLXSJHSKJZOUSUCEI",
                            .port                     = 57220,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 49,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 3545.4096,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "BBZTJ",
                                .value                    = "BQFKUVBUIVAINVPBU",
                            },
                            data::tag{
                                .key                      = "BREXVZFW",
                                .value                    = "AMIUDHBFBDIJEQDJTTRNDHDCFXBNWWMAWBMLMXFSEYVAZIKAJPVOYIRTYJ",
                            },
                            data::tag{
                                .key                      = "DFICHIW",
                                .value                    = "UJVJHCIBJCJSFSOINCCVLZPHCEPVJLXXCWIMGONWXYKVJMALSPFXLQAOORP",
                            },
                            data::tag{
                                .key                      = "OPKZLXZJSBDZUSKACPQUWLEROFEESDAPUIJIUJEEGTPUVKVURFTCPNNVZZHNARW",
                                .value                    = "IMSXVRLBZYCOFDOIJKGUZYBTSWAGXKCBPKEARHUOPNACJOMQCXQJGWKHZODJVW",
                            },
                            data::tag{
                                .key                      = "NRORZLZBKCCPMTTKFUQYLNJI",
                                .value                    = "OYMTGBBNZBSIQBSYQZFXDQHEAOD",
                            },
                            data::tag{
                                .key                      = "LQFSGBQIOIVAMDOQENLQFDYLLQWJYLOSJZPWZHNPZNJCCAFRCLN",
                                .value                    = "UTULBDGUZMFNUDIYEILDVHVJVTZGRUWGQMUPWTQPNNBFODBGHGWS",
                            },
                            data::tag{
                                .key                      = "WFSVXUQFHMZCSUYGJAVHDJUPEKXFNEBSXAKZWZXX",
                                .value                    = "PLFPVCNWVLAZDYVXSCIQTRDJGGJBAHFHXRJXNH",
                            },
                            data::tag{
                                .key                      = "EFJDVZCYRTYXLBCWDMMJC",
                                .value                    = "R",
                            },
                            data::tag{
                                .key                      = "MQEFUFEZWXHOOVUJXWMXMBPDUWWMCDRQWWBWHHH",
                                .value                    = "BMAHTPKGJWALHFJHVBOLWPNQ",
                            },
                        },
                        .tls_cert_path            = "IUTMLDZJXQFWIFNECRSTTVSHWYERILUULLAT",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "MOXECSEUZJ",
                            .port                     = 28165,
                        },
                        .connect_timeout          = 200ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 40,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = -7908.4127,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "KHGUNUYGTRGJAQHMDCBMMVIREJNDOZXWFMPYOHIXDIYY",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YFIOARZRGYJYEDBEXALJATYPZGIVFVPOFLAHAQTXAIBHAIBJDECYSEPQHRNPD",
                            .port                     = 30895,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 57,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 4171.1901,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "DPIRGMPNDLMFUXVAQVYTNKLVITHMZKNHWWB",
                            .port                     = 48076,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 35,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 4436.0293,
                            .deadline                 = 1min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "ZXKPIOLSRWKNJQIOTGTXJDDZXFVPO",
                                .value                    = "OIETAQKUAUYDCTJLNKJZGDZPSEHUFZXW",
                            },
                            data::tag{
                                .key                      = "JCJUGWSAHZFYFPCQJPCCKZAZTCEET",
                                .value                    = "OWMPHPPOVFDVX",
                            },
                            data::tag{
                                .key                      = "QVHOQPPDURFYEEPGWTOXBIPHHVDLVDSSPKDAUFEYANWERESJAA",
                                .value                    = "CJEIADVVSCIYHFYNWAVMOHECARFXRNEGYRILWT",
                            },
                            data::tag{
                                .key                      = "CLQ",
                                .value                    = "SJJFIUHG",
                            },
                            data::tag{
                                .key                      = "TPENWWQKBWCRTMLZIUZKZUFGEQBEIJYHFPXSJJNU",
                                .value                    = "CLMAWBEEJZSUFQXOGKDXDNDMOOYCWNGOTKUDRNBGXNEMSTIQMBJIVCLZW",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::warning,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 17,
                    .base_delay               = 1s,
                    .backoff_multiplier       = -9164.0676,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "ARNC",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"DTSO", data::threshold_rule{
                        .metric_name              = "PIZHUJNHIAQLYKNUWTFWTOCXZPAH",
                        .warn_at                  = -7683.5219,
                        .crit_at                  = -9949.6507,
                        .evaluation_window        = 2min,
                    }},
                    {"WC", data::threshold_rule{
                        .metric_name              = "FKFZMRAGFDWQFFAOXXWZENEVKYBMANHLIEFKOQC",
                        .warn_at                  = 8735.6402,
                        .crit_at                  = -9156.7823,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 65,
                    .base_delay               = 2s,
                    .backoff_multiplier       = 5290.43,
                    .deadline                 = std::nullopt,
                },
            },
            data::backend_group{
                .name                     = "QVTKWPCHIXATJFOZAICKIWQJAXPGFJDZKRBLFYCJHV",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "KB",
                            .port                     = 30041,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 27,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 2839.2511,
                            .deadline                 = 15s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "ZNVHNIG",
                                .value                    = "EGTVOBTSRYLZYRJXBKWELEDGALBXDDNJQPOVPHSB",
                            },
                        },
                        .tls_cert_path            = "AIZFLWBUIGVGSIZCSPF",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 23,
                    .base_delay               = 500ms,
                    .backoff_multiplier       = 9005.5352,
                    .deadline                 = 10s,
                },
            },
            data::backend_group{
                .name                     = "DYSBJJHZRFGGDNHZWGVMVDFYEMFCMJMGJLWFPOIIPE",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "HUFBZDHDNATVUIGDJAYHDWDP",
                            .port                     = 52137,
                        },
                        .connect_timeout          = 1s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 18,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -1126.1778,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "TGTRNSMEJHPWRMLKOJPP",
                                .value                    = "XSEZQVAVXZIEIVACVBSRBMYTOKTIXFKTNZRXNKQINUROJEEOAEIDMEBTZISTDQ",
                            },
                            data::tag{
                                .key                      = "AUW",
                                .value                    = "S",
                            },
                            data::tag{
                                .key                      = "QSUFQPPKYYKFDUIWYSKPOSJAFEICOAWGEBUAIPECPUDLBQZBLICQ",
                                .value                    = "UXVRTCTHOOBRWCFQMGFYAARSLTKMXB",
                            },
                            data::tag{
                                .key                      = "T",
                                .value                    = "NRFZWYUPNEVCNJIICILK",
                            },
                            data::tag{
                                .key                      = "",
                                .value                    = "NEXUIOKAP",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"ZZ", data::threshold_rule{
                        .metric_name              = "AHGPIMEMWOAVKOLCBFOQVSOOSCZFUSGYYSSGBROHIUADQALIJOSNURKJR",
                        .warn_at                  = 8761.2931,
                        .crit_at                  = 3539.4682,
                        .evaluation_window        = 30s,
                    }},
                    {"FMPAEE", data::threshold_rule{
                        .metric_name              = "ACULFRXLEIXZWBDKZADOHEVEAMB",
                        .warn_at                  = -295.514,
                        .crit_at                  = -891.501,
                        .evaluation_window        = 5s,
                    }},
                    {"XDIZ", data::threshold_rule{
                        .metric_name              = "EDZYUIXCSXVBPWUEKBIBBAVVUUOMUWTJCBKGQJPEPKXUNXBQ",
                        .warn_at                  = 8358.7052,
                        .crit_at                  = 9669.9248,
                        .evaluation_window        = 5s,
                    }},
                    {"MNTNJ", data::threshold_rule{
                        .metric_name              = "PXCQJPPTMHJZLSQJDQAWMQVWNSHZJNHJEJXLFKUDTIZBZWSKYD",
                        .warn_at                  = 8542.2896,
                        .crit_at                  = -8442.2393,
                        .evaluation_window        = 10s,
                    }},
                    {"QTNODG", data::threshold_rule{
                        .metric_name              = "SHQMAKBIFHEHEKSTYXQBMAPBQ",
                        .warn_at                  = 9007.4772,
                        .crit_at                  = -9453.033,
                        .evaluation_window        = 5min,
                    }},
                    {"HKEQXS", data::threshold_rule{
                        .metric_name              = "RHMDYNDKJRQOTCVETERGKHMJ",
                        .warn_at                  = -3526.6719,
                        .crit_at                  = 2830.5095,
                        .evaluation_window        = 5s,
                    }},
                    {"YKHHKV", data::threshold_rule{
                        .metric_name              = "KKQ",
                        .warn_at                  = 448.0042,
                        .crit_at                  = -5151.0228,
                        .evaluation_window        = 2min,
                    }},
                    {"NYUX", data::threshold_rule{
                        .metric_name              = "GTWYZU",
                        .warn_at                  = 4368.3167,
                        .crit_at                  = -5737.3667,
                        .evaluation_window        = 5s,
                    }},
                    {"MYA", data::threshold_rule{
                        .metric_name              = "MPTBBOMOIBRHIIMKAACBJNCMXSMWPZMMZJIOUXUOUYECBCTSYR",
                        .warn_at                  = -2491.1816,
                        .crit_at                  = -6595.8836,
                        .evaluation_window        = 5s,
                    }},
                    {"QLG", data::threshold_rule{
                        .metric_name              = "QMULKV",
                        .warn_at                  = -8051.0405,
                        .crit_at                  = 342.4922,
                        .evaluation_window        = 10s,
                    }},
                    {"YNZZD", data::threshold_rule{
                        .metric_name              = "",
                        .warn_at                  = 8533.4678,
                        .crit_at                  = -1042.4806,
                        .evaluation_window        = 5s,
                    }},
                    {"FJUVZ", data::threshold_rule{
                        .metric_name              = "MFVURZQBPXHTKZ",
                        .warn_at                  = 5243.1811,
                        .crit_at                  = 4953.7673,
                        .evaluation_window        = 5s,
                    }},
                    {"SWMAH", data::threshold_rule{
                        .metric_name              = "PYRGNSWFBAVBBAMDUCITNCSOGGWHIG",
                        .warn_at                  = -7550.1926,
                        .crit_at                  = -8978.9391,
                        .evaluation_window        = 15s,
                    }},
                    {"CEP", data::threshold_rule{
                        .metric_name              = "",
                        .warn_at                  = -6116.0276,
                        .crit_at                  = -4094.7136,
                        .evaluation_window        = 10s,
                    }},
                    {"QFRAXC", data::threshold_rule{
                        .metric_name              = "DUIJRGKWRFCTDHYIIHAM",
                        .warn_at                  = -8579.9391,
                        .crit_at                  = 320.2704,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "MNFNNOE",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "LIDQOUCTMJEEFGIKIGLGEGSWAYNJZ",
                            .port                     = 45270,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 2,
                            .base_delay               = 1s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "UBBBBUKCOWKVODKYPMDSLEPDB",
                                .value                    = "YTTMOBOPCFUEUOYRZVJXOGLQN",
                            },
                            data::tag{
                                .key                      = "WHEAJRPNWGWSUXNIEKDPUMLYLIZLPQBIIKGFPCYBYWVCAQ",
                                .value                    = "K",
                            },
                            data::tag{
                                .key                      = "HFPZMGWLSLKXMSNQXSNHVNPSMEVELP",
                                .value                    = "RWZBJOMJCJPOLJRYVABVAIUPQNLTZLHIELCMXSSSPFFXIWXFYEVIZDCC",
                            },
                            data::tag{
                                .key                      = "CRMYIPGSNLBLSVVYK",
                                .value                    = "KOKNGHTCEWZSZNMODUZCEYVMXPANIQLCGOJSKZYGTUYCXMGOYAZETKKZ",
                            },
                            data::tag{
                                .key                      = "RGD",
                                .value                    = "NTBS",
                            },
                        },
                        .tls_cert_path            = "DUWONCKOVXXCR",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "ZDRCHVVHSIVCUVBQSXUHAMJAXYCTIRMVYSLXNDFAZYBQLDOUNLDDGZL",
                            .port                     = 812,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 70,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = 2199.843,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 12,
                    .base_delay               = 2s,
                    .backoff_multiplier       = -5219.4823,
                    .deadline                 = std::nullopt,
                },
            },
            data::backend_group{
                .name                     = "DISCTBDC",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "GTDUNGKCKMGPOTMHCGHLUHJALMCJYOSQYYMYRGTFYYPAGH",
                            .port                     = 30714,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 64,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = 3747.5622,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "GSV",
                                .value                    = "WQLKXDOUXIHIPAA",
                            },
                            data::tag{
                                .key                      = "YPFKOUXYOGYBONRAFTWUGAVLWOTRYFPKCMV",
                                .value                    = "VXADVWWPUIIMLCIRDGEMTXVCWHEOKORVOA",
                            },
                            data::tag{
                                .key                      = "PZVKXKIYVXFRUSPMYIUVZFGOI",
                                .value                    = "WZFRRADJBFPCWPCCTMWBQCISSPZIISAUBAHRAA",
                            },
                            data::tag{
                                .key                      = "OPNHXMMRDKCYKIEPJHUOAZQHIQWRCVWCV",
                                .value                    = "DXDXQKFDNBORSWMXGHWLBWBNZATYCHRDQBJQKHQP",
                            },
                            data::tag{
                                .key                      = "TPMISNQZPZRGSCRIZCFGJFUQCRLURQDBCBWEXFMDWWRWC",
                                .value                    = "LKRXWLEKVWXXGCWWAXUATHJKDDJYAAFTCPPSGDEKWQFTURPPOLNANSFGJJNMRPF",
                            },
                            data::tag{
                                .key                      = "MOUDKOAYHZDXPFQLXGLCEOQZWHDILXCJKG",
                                .value                    = "CJXLBNLGLTGCZHYIRSEVGMTJEWULMUXAPSONMSBRNFFLJWYMQIOEIGRGNWM",
                            },
                            data::tag{
                                .key                      = "TNLGMIXCVMKJIBNXIQGDHOXKVOIGXJYRTXWHAIPGCETKVTSLF",
                                .value                    = "GFWFVLOHZKGARX",
                            },
                            data::tag{
                                .key                      = "NSSPQNPGPM",
                                .value                    = "ZYCASZANAJQKPODLISDPP",
                            },
                            data::tag{
                                .key                      = "HOKYYNIJWSKFRDNTCCJOEMURFSWKXGHSSLTCAIXTSFKUCHUXBHULYGRSAGE",
                                .value                    = "ILOVWQWQASDHARXPKDUBSV",
                            },
                        },
                        .tls_cert_path            = "NQZHKCODIFUZYVKIKTHVEGKHUDIAOJITAHQSATCFVH",
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"WZGAA", data::threshold_rule{
                        .metric_name              = "LKAZMKJSSIFHCSCCDZLTRTZSMONYEPWAWDMMODRA",
                        .warn_at                  = -3283.0709,
                        .crit_at                  = -7543.5675,
                        .evaluation_window        = 5min,
                    }},
                    {"MK", data::threshold_rule{
                        .metric_name              = "YTFZPRJTIOQZVRLMFZQJC",
                        .warn_at                  = -508.485,
                        .crit_at                  = -1545.6172,
                        .evaluation_window        = 10min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 64,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "KRYSNQUDWOXXK",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "EBFZVHSZMDC",
                            .port                     = 3409,
                        },
                        .connect_timeout          = 5s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 49,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 7496.8592,
                            .deadline                 = 15s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "NBGMWYJJXVTEQJKPU",
                            .port                     = 16962,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 83,
                            .base_delay               = 5s,
                            .backoff_multiplier       = -6772.0161,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "PCORNPHTDUUIXRKWTFDMXZVSTNFPXUZAYXAOOYDNCLXQTTEHZFK",
                    },
                },
                .min_log_level            = data::severity::warning,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"EAC", data::threshold_rule{
                        .metric_name              = "DVAUSMKZDQITLNSZUJICKVBAJZHXUCVDWIWSLAFBIJORXWWHOGBQJTJK",
                        .warn_at                  = 8799.7636,
                        .crit_at                  = -3520.6268,
                        .evaluation_window        = 5s,
                    }},
                    {"ROFAX", data::threshold_rule{
                        .metric_name              = "WRRHSIALRFMOHVXAQBASZ",
                        .warn_at                  = -7961.6212,
                        .crit_at                  = -3734.5746,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 12,
                    .base_delay               = 25ms,
                    .backoff_multiplier       = 5810.3575,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "QQLSZUCPJSG",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::warning,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"IDIW", data::threshold_rule{
                        .metric_name              = "",
                        .warn_at                  = -1678.3964,
                        .crit_at                  = 8277.9096,
                        .evaluation_window        = 1min,
                    }},
                    {"AT", data::threshold_rule{
                        .metric_name              = "JDFUIONHPVMBYLLX",
                        .warn_at                  = 4471.8472,
                        .crit_at                  = -8687.2543,
                        .evaluation_window        = 5s,
                    }},
                    {"AGCX", data::threshold_rule{
                        .metric_name              = "DFUDAZBEPVIOROAWGHCROOPH",
                        .warn_at                  = -6759.5772,
                        .crit_at                  = -1292.1663,
                        .evaluation_window        = 30s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 7,
                    .base_delay               = 25ms,
                    .backoff_multiplier       = 5952.7583,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "QPGIIPVPBSWALMGWWCDMVRRLEQCHAPKMJECQCFMVSPYYFIKPC",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::error,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 39,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "PCUJYD",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "JNLYECJMTTSTKFETWKIQMKLSGGWRSNHUWWJHFAAVVRQHJMILQUA",
                            .port                     = 61165,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 85,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = -2917.4415,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"OUN", data::threshold_rule{
                        .metric_name              = "BCQIRBRKEVHBKV",
                        .warn_at                  = -5729.6012,
                        .crit_at                  = 8797.9963,
                        .evaluation_window        = 5s,
                    }},
                    {"KRKUGF", data::threshold_rule{
                        .metric_name              = "QJ",
                        .warn_at                  = 3249.6246,
                        .crit_at                  = -7628.2839,
                        .evaluation_window        = 30s,
                    }},
                    {"LUXIGP", data::threshold_rule{
                        .metric_name              = "TEZSYDXNNIJYOKRYNKJTRSBBCPZ",
                        .warn_at                  = -9149.0901,
                        .crit_at                  = 6731.8807,
                        .evaluation_window        = 5s,
                    }},
                    {"ZKLKUA", data::threshold_rule{
                        .metric_name              = "NNYSWHJUIFZMNNASYBNTKUYLWFQ",
                        .warn_at                  = 3025.5779,
                        .crit_at                  = -4479.5131,
                        .evaluation_window        = 10s,
                    }},
                    {"QKJD", data::threshold_rule{
                        .metric_name              = "VAERMEWXMTTLCBJTSLOGNJJMJNFYHNMCNFLWCCTXFDHDJGGZQ",
                        .warn_at                  = 438.2393,
                        .crit_at                  = 5200.9737,
                        .evaluation_window        = 5s,
                    }},
                    {"JWD", data::threshold_rule{
                        .metric_name              = "MPXEISDTXIGLDAHXTBCUDTEONEFXECAEPWWCHNMOBS",
                        .warn_at                  = -7981.7133,
                        .crit_at                  = 9508.1954,
                        .evaluation_window        = 5s,
                    }},
                    {"WZ", data::threshold_rule{
                        .metric_name              = "FKHBOXAMZVZTARVLKOKSHDOWIRLTO",
                        .warn_at                  = 3957.157,
                        .crit_at                  = -741.6168,
                        .evaluation_window        = 5s,
                    }},
                    {"XBD", data::threshold_rule{
                        .metric_name              = "QBZALGQAAYTGUJJXTNCAYEZHHNKYDEJZZCGICZTSHPRSLZOYQS",
                        .warn_at                  = -5325.2556,
                        .crit_at                  = -5922.3581,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 63,
                    .base_delay               = 500ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 1min,
                },
            },
            data::backend_group{
                .name                     = "TYSQAVRBFYTQOQRIKKTCPIZHTQBSDFDLTGRWVWEBTMC",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "SRMMNJNRESHFJGJNTWNSBCNNZJPWFADWWC",
                            .port                     = 65102,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 43,
                            .base_delay               = 10s,
                            .backoff_multiplier       = 3915.1308,
                            .deadline                 = 1min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "DQOUSEKXDRXSSHXCVQGMVTGIIPHFJRWWENGJTUNCJOXXCWTSXNIQBQZJ",
                                .value                    = "OCZTPFXVFDENSCYVTWQPHTSFMRDA",
                            },
                            data::tag{
                                .key                      = "ZTBFAECEINUIYCBZXOKRHKIUSKWHQBYS",
                                .value                    = "GQ",
                            },
                        },
                        .tls_cert_path            = "MWSOHHOFJGVVWLSCTYHIRUFCQLRMRKDIENMHZAOBARKL",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "QFOWHAJSJXFKMQMXYLBMWZFUNIEUGCUSEWSSLEHKIF",
                            .port                     = 31423,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 13,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = -7127.5135,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "RRMPBEFPXTXANCWBKGH",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::nullopt,
                .fallback_retry           = std::nullopt,
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"WD", data::routing_rule{
                .pattern                  = "PRWPDOCVYFNLSUOIDEGTZSOELISKBIQNECOZEOLTZXFVNJVVNXHAKVUJKUGHLH",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
            {"RVOQ", data::routing_rule{
                .pattern                  = "NNUZUEFRJKSNAQAUWUCLJOX",
                .backend_names            = std::vector<std::string>{
                    "ICWMANYYKLEKUTYXVEMGHSCGYUODREXUOV",
                    "QTH",
                    "YZIUJBVBDMRE",
                    "BTRCDPDZBJVNLKDRPIRMPSCFJLYREAHNHDLCKMRHHAZEIDEMGUZEO",
                    "CSCIJLEDAKQCDIRPFOXEBNXSDQEM",
                    "NRLZARGFWPXVEYDKEIG",
                    "UQOZWEEGSXAJDAIX",
                    "WQYNBIXLIUCVBEZZIDHVSEPOHEOOFUFQATL",
                    "HWYBWZEJVXBQRUNMENWKNTVEOPELWFQGGSXOKMDAXTKNNUEUBBCDJU",
                    "ARFPVDWFHJANSVHEOJQAWJICYOTABKBBGSEJ",
                },
                .timeout_override         = 1min,
            }},
            {"GEAUK", data::routing_rule{
                .pattern                  = "PVJRVQFRNCTPHRBWBQVMSVIF",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 500ms,
            }},
            {"SS", data::routing_rule{
                .pattern                  = "DAULSJDQLXRFGXXGXTEYXWOGJHZBPNAKKKWOTRMRPCDMREFTXANFHSCBMXWHOH",
                .backend_names            = std::vector<std::string>{
                    "DTKCISEMDXTWTDPHOVDMPTZUQHYGXWYXNFIQGZUXAYWPGTQZNCLFKUGFIZHZB",
                    "ZWUDBRGZTNLUYAFTHQU",
                    "VJGEJBLYGHLXMRITKCWFYLFKHGLQLKGVWER",
                    "KCXBBVJFZHEYBXYCKNNQBGWDXXRZDDTWUQXRGPSGBLRGYDJXDDVFZIPFDB",
                    "RFXURJXBDQEYPDAITFBSRWRFPXKU",
                    "PAFGHSSGWLFHOEVFWQJVRCRJOWYXDJILWRPRJYVMCOCLOYNFIIXQQTUBDFLJI",
                    "ITXHIJIOBVNUQBUQGMDKVRHVBZNRYTEZCTHSALBZGEFOIUJFKAFJO",
                    "NV",
                    "VBDTGBFXESZTNKVVXQQWGBRCNIJIVQCTOEFDGIUSXESBNMDQBNGVY",
                    "RFOZQCPMS",
                },
                .timeout_override         = 25ms,
            }},
            {"KTXG", data::routing_rule{
                .pattern                  = "JOMJDXBNJQWDLLVEDYFYNMNLWFKMA",
                .backend_names            = std::nullopt,
                .timeout_override         = 500ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"VEYCH", "BYATBSOTYKYYNSNFSMQQUIQFEJNGD"},
            {"YCMUP", "WFUXTTCJLBAKXWQTBKOULNXSNGKLEBGI"},
            {"LTYUW", "TCVPCOGNNLWQXW"},
            {"EIJ", "EKYXUXVUOZQEEHRUEVIFOLDDE"},
            {"BNJLDI", "WSYROIXTKGABSASXWCIZSSJAQMOMUSCTEWWVYIJAEAMYHA"},
            {"LYQU", "VILQDIOPQOVDOIUJERRZCQLZJTERQJZJRZSXHEYDVKVKWDQZMESLETGBXVXBM"},
            {"ASHZWF", "BKNZTXKOKMWBDKISBUPJZAYTGZMURZ"},
            {"HV", "DEGGDBXUPUFHDDXPSMOVEIYHWUXYBUTOHNQDARGQCCAMVNKHIABMK"},
            {"OPS", "ROCSVZTSAEBMSREMRERBWDQSLMXRVCZXAYBUBJEUVQ"},
            {"WIZA", "UWKFSHPHLRDICVFMYVKSAXCSZHIDNQXNLGKLUFZQFUAUQ"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("NQGCZNHXRRMWRLLZIW", 72612, true),
        },
        .allowed_origins          = std::set<std::string>{
            "ADQLQHWHXCGMDOQIICJNMMLMIXQWAWQKXIJZX",
            "LKVEBJHLKSPXUVEWVWZQZSXJXFNKHUIPIWNUQIVFUSZZTJVNEBNQDPQXC",
            "PDIRTBOUKNKNZIQIOZDMAREXVBXUJUNWRQEMQTOYNBSEWPCFXOBMPQWQLUIOIAC",
            "XIYZURQDGCXDXKMOQTHEYKSOHPPJSIEQWLTZHJKVWGQXAXCIOQ",
        },
        .config_tree              = data::scope_override{
            .scope                    = "BBGENVZUANISAZQYDZUTGKADOOZQKMWRJVQGZBDTKOBFEVHAJ",
            .extra                    = boost::json::value_from("FTXEYNVBIAFZSDKHVDVXHXOKARMOKGVYEWXLEQFZNGFWASUOBRFVOVLABWVAZXS"),
            .log_level                = data::severity::debug,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_74", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "RWJXOWKVGSUZAZUPDVNNDKWBXUOJAWFFRJJPZNCBYPFS",
                        .port                     = 49340,
                    },
                    .connect_timeout          = 5s,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 85,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 10s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "RKSNGOLUTNWLHDBQFQCEFMJZOCTWWVADZFRHNLDU",
                            .value                    = "G",
                        },
                        data::tag{
                            .key                      = "CHVLHQUSLC",
                            .value                    = "UIMIJCNLCJXREQRVYRMRGUPHCPQSTBDWBHUV",
                        },
                        data::tag{
                            .key                      = "JYBGNXL",
                            .value                    = "HPMZTWUNGIWXURCGUJSPESZQQTWCWBEEDBFJTNMMFLTQSXGPCAK",
                        },
                        data::tag{
                            .key                      = "NBYVVUCMINHUSWDSQAZQSUGZFKTZAMD",
                            .value                    = "L",
                        },
                        data::tag{
                            .key                      = "GYCUIKWKPEBBZY",
                            .value                    = "ZKPBIENZJXBVDCGWPHTIQA",
                        },
                        data::tag{
                            .key                      = "PUNBNTQVZ",
                            .value                    = "YGMMZBDOLPKYM",
                        },
                    },
                    .tls_cert_path            = "STENEJCG",
                }},
                {"ep_63", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "BFFCNEXMSDGXSBCQSRUDMAFTZTKHMM",
                        .port                     = 3795,
                    },
                    .connect_timeout          = 25ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 38,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = 3542.8101,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "LEAVRQTOUTENTSLGZOMRYD",
                            .value                    = "WFABQEIZNYWSXXSKRIDQRFDSDOLTPNTAQNCXSZXFRDCXY",
                        },
                        data::tag{
                            .key                      = "KCSDGBHYQJQUVEMVLKMEQMUZFEYXNLEPIUJUFVV",
                            .value                    = "SLXWEXTNAGPGGDAYGPPXIUZLPAQICBD",
                        },
                        data::tag{
                            .key                      = "UVAQCHHFOQXDVWVTIKWZ",
                            .value                    = "WFFQUDLFUYRCOTPT",
                        },
                        data::tag{
                            .key                      = "IKRRSTJOFVHASRRB",
                            .value                    = "UFPBTAOFQFEMRUPYKGONPZCLCWQKXEFXBXKGSTOEPMKBBAHEZATYGTYQHUWO",
                        },
                    },
                    .tls_cert_path            = "VJCGANYVUWREWNEQODMYXCTVMHYQKOOC",
                }},
                {"ep_77", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "CXBKDRXYGYHIHJEXDAKHXNVFSQIQGAKEACNIYJDCZUAQDXABCMWAS",
                        .port                     = 46687,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 15,
                        .base_delay               = 2s,
                        .backoff_multiplier       = 1023.4787,
                        .deadline                 = 5min,
                    },
                    .tags                     = std::vector<data::tag>{},
                    .tls_cert_path            = std::nullopt,
                }},
                {"ep_1", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "AGVBLTSRZDTYZSCQYT",
                        .port                     = 49043,
                    },
                    .connect_timeout          = 100ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 61,
                        .base_delay               = 1s,
                        .backoff_multiplier       = 2055.8381,
                        .deadline                 = 10s,
                    },
                    .tags                     = std::nullopt,
                    .tls_cert_path            = "CAUHCOMQMHJLRLWNSUXPJCHIYMHEJSAVAFUYIUJSPDHCB",
                }},
            },
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "TDUVWBYSODHGORVADQHGQQDD",
                .extra                    = boost::json::value_from("SKWAFVRMXADQDTPZPZSOZUBWQKANKZFAZXJPSMCRVGS"),
                .log_level                = std::nullopt,
                .retry                    = data::retry_policy{
                    .max_attempts             = 80,
                    .base_delay               = 25ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 10min,
                },
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "MIJOLTUWECTVPOXMXWHZHQOD",
                        .value                    = "HPEIVGYCVZQSKPCIAMSRJDX",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "YMRANHTCNYZOXDUBMGRXRMLMHUAQMJHCGAVRIPWAHFYNVZKDZETUHEDVZLGTSIF",
                    .extra                    = boost::json::value_from("CNDHFCZGFPSYYQKKMSEV"),
                    .log_level                = std::nullopt,
                    .retry                    = std::nullopt,
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_17", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "ZUZNQCVSNSNZZQTCPYOTWC",
                                .port                     = 61118,
                            },
                            .connect_timeout          = 50ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 36,
                                .base_delay               = 25ms,
                                .backoff_multiplier       = -2148.2644,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "GQILNLWSGNGXDQPWYNMQEGABPXYBBISCH",
                                    .value                    = "YKAY",
                                },
                                data::tag{
                                    .key                      = "GYKBPWPJVQBWCHKHQTUBJUEXRGCPCAOS",
                                    .value                    = "IJQCHMIFUUCNMBAWDQ",
                                },
                                data::tag{
                                    .key                      = "UNLNAPPSEZEHDQOFYFRP",
                                    .value                    = "CPYVCYCDFWETRB",
                                },
                                data::tag{
                                    .key                      = "QJXNRPWNMOCLRT",
                                    .value                    = "GEZNAIQNQPWXUBRHHFYCVMTHLKZRQFBNBSYMI",
                                },
                                data::tag{
                                    .key                      = "GHVIGPZDJUSGALGRCPIPBHJBTDCXUB",
                                    .value                    = "MEVSHWPTSRAPDUMEFNDZBIKPPKEPFIEXQWOFVK",
                                },
                                data::tag{
                                    .key                      = "SUBWGFEBHAMYPEMRXRJRZONVGKXXQSAVMUHGCBCJVUFATVXZQDTUMNZJPUV",
                                    .value                    = "CVJXYHDKZUPNVZPHSZGE",
                                },
                                data::tag{
                                    .key                      = "",
                                    .value                    = "BDMPRBZKQCBNIRSWTXXTNFLPDW",
                                },
                            },
                            .tls_cert_path            = std::nullopt,
                        }},
                        {"ep_4", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "QQFWWOYQWLOEAQQ",
                                .port                     = 51243,
                            },
                            .connect_timeout          = 25ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 90,
                                .base_delay               = 25ms,
                                .backoff_multiplier       = -2193.7335,
                                .deadline                 = 15s,
                            },
                            .tags                     = std::nullopt,
                            .tls_cert_path            = std::nullopt,
                        }},
                        {"ep_97", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "RASHGIQQBBOLJQBNOAWPPT",
                                .port                     = 11334,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 11,
                                .base_delay               = 200ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "JNWGMIRTAHUMHRSVXXVJRBSWLYNOYMLWHRCFPYIIGNCHLWSUWSCPXC",
                                    .value                    = "",
                                },
                            },
                            .tls_cert_path            = "QMWUPIKFHEZLIANRAMCFCHXUXGMCXFNTVIG",
                        }},
                        {"ep_28", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "YBDGECAF",
                                .port                     = 3189,
                            },
                            .connect_timeout          = 100ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 97,
                                .base_delay               = 2s,
                                .backoff_multiplier       = 6967.8078,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "FUUQWNRT",
                                    .value                    = "LVPUMVSSCVFUTSGVXPQPSHHCYHJYEXKMGV",
                                },
                                data::tag{
                                    .key                      = "OTEXACUOJXFCPVCQUALXQXS",
                                    .value                    = "QEOCYRXIWYZXCXSGRZJQLNETJISJCMSAUZENIIRSTHEWVYRG",
                                },
                                data::tag{
                                    .key                      = "GENKPYKNCOAQSVBTFT",
                                    .value                    = "OWTAIMDEGIOQJTBBJPZANATYBAHTVCFIYYFII",
                                },
                                data::tag{
                                    .key                      = "NKXSH",
                                    .value                    = "PYSXDPJNUPZKFDASJHKSIRHAS",
                                },
                            },
                            .tls_cert_path            = "ZMXQYXQQHYQSKWFVFU",
                        }},
                    },
                    .tags                     = std::nullopt,
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "HDXVVZSUZRMGLDYCYTOGZCXTLPLYPLSARCIVJSOOUHNHJ",
                        .extra                    = boost::json::value_from("OPMGEXYBLCZTMAGPFUWHQMIFUM"),
                        .log_level                = data::severity::debug,
                        .retry                    = std::nullopt,
                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                            {"ep_94", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "UKMXUPN",
                                    .port                     = 18899,
                                },
                                .connect_timeout          = 10ms,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 2,
                                    .base_delay               = 25ms,
                                    .backoff_multiplier       = 6354.7273,
                                    .deadline                 = 5s,
                                },
                                .tags                     = std::vector<data::tag>{},
                                .tls_cert_path            = "WIMJOYISOEPVVWMZJLDZ",
                            }},
                        },
                        .tags                     = std::nullopt,
                        .nested                   = common::box<data::scope_override>{data::scope_override{
                            .scope                    = "GWZKX",
                            .extra                    = boost::json::value_from("KTIQDBADCRHERIGQMDGQKNMRSMFEEXSVFVHXUPNAKKY"),
                            .log_level                = data::severity::critical,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 36,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = 349.6254,
                                .deadline                 = 15s,
                            },
                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                {"ep_16", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "FCSYXTEGGZJMWVACBROF",
                                        .port                     = 24955,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 76,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = 30s,
                                    },
                                    .tags                     = std::vector<data::tag>{},
                                    .tls_cert_path            = "DPDGWUNVNHCGGA",
                                }},
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "DAWVNHSLUXBIZDVSMWWKXESSPPVLZREWVJSXSPEVWKOPOUOIRIQCNARZNVGH",
                                    .value                    = "BSLMKCQQUTTLXQOMD",
                                },
                                data::tag{
                                    .key                      = "GMXPRAUEYAIZYYBBCU",
                                    .value                    = "CNOBBAYDEZSZSKHMTIYHOUFNHIPTMTPNUDLLAWG",
                                },
                            },
                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                .scope                    = "FGZFABIGWZTLHENKAYF",
                                .extra                    = boost::json::value_from("ZHTDFIXMHPPJMSMYDJHMVXEHFGYJXZWRDNQGWCDWFKPNN"),
                                .log_level                = std::nullopt,
                                .retry                    = std::nullopt,
                                .endpoint_overrides       = std::nullopt,
                                .tags                     = std::vector<data::tag>{
                                    data::tag{
                                        .key                      = "CVUGZUAEBNMWCKTBTWHGTUSTCYPYFBAMOUBMURPZPIWP",
                                        .value                    = "MMGKIJDIHEWPSVOWWZXVXHKFCVJLIBOBJFFTFSCXNIFA",
                                    },
                                    data::tag{
                                        .key                      = "MHXVEBZWWXIZAXYIBABMTZWUETZV",
                                        .value                    = "TMBYMDUGQNZRIUASAIBNPYQZA",
                                    },
                                    data::tag{
                                        .key                      = "QYGKHIMAQCPENKSIULOKJHOXKBCJSHOLIALANXEGSYVAOTYJNEEYJUXABW",
                                        .value                    = "XJIUVXDIHBPYFHCTNIFBUXNLCDGGHAQHNUD",
                                    },
                                    data::tag{
                                        .key                      = "IATFTMKUCTVLYCRVNPXLTNIRNPVVFBLCGAWWBCZVS",
                                        .value                    = "FKULWIKQQWNFOTBYWBTNTANEBEZNBIVPAFGTWFJQMIFWVXHLKDJ",
                                    },
                                    data::tag{
                                        .key                      = "IYIHANIJMWDZCGJZMFJIXRVNQHN",
                                        .value                    = "YNCWTCLKPBUDUFXJVFWHBLZOAYDJKCELHZHJTDETPDQACXYFPFJADONREFQ",
                                    },
                                    data::tag{
                                        .key                      = "PXFHJCDAEAVUSGCREDZHHATZDZVONLCYQIZTLIUBBGZVTVUMNQN",
                                        .value                    = "GLJJ",
                                    },
                                    data::tag{
                                        .key                      = "RKZZAWVJHPJBEKTWZWZFDWJAQN",
                                        .value                    = "ZEHFCXYNIJCRRTPWAXMHCFAGZVXDDBQOHPRIZOMVSPAYDDROJDSWHIJGX",
                                    },
                                    data::tag{
                                        .key                      = "CQXUDIGDDBWNIKHJCWSNSVBYAXHOUEOOYDRFYMFEXJPDIWDQB",
                                        .value                    = "YWMHPAUTPSQYWQUVLRYGFCCGERXZGPUEIDCDWFQBUPLAX",
                                    },
                                    data::tag{
                                        .key                      = "M",
                                        .value                    = "IKJUFHMXMZLSSZILCZNVVFQYT",
                                    },
                                },
                                .nested                   = common::box<data::scope_override>{},
                            }},
                        }},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "IKSAFWVXXSDVXHGNJBJMFFBIJXOCGTSKTIZZQV",
            .port                     = 58914,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"DG", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "NSBAFIEIVNWWZMRNCUCJQSCMKCLQQZVIGNHMK",
                    .warn_at                  = -3618.5372,
                    .crit_at                  = -472.9703,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "DBAHMFXDTFKEBDLXUPVTBMDZSHOAXUJWEHSLEBNWOWOE",
                    .warn_at                  = -4085.7239,
                    .crit_at                  = -9296.1673,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "ZYFDMVUGKCZFDQLDDPKHLGUAZQWNRDMDWBUHUITCFTMGDSE",
                    .warn_at                  = 1194.2659,
                    .crit_at                  = -1317.9043,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "SGYOQSBHOKVOSYXEKPVQJFI",
                    .warn_at                  = -5751.3469,
                    .crit_at                  = 4325.7606,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "JEYVNPFXQXNYGFNTTNJFLHTDMSHCRGTVDOPOVHCXJQU",
                    .warn_at                  = -2621.2952,
                    .crit_at                  = 1465.4155,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "SNALIXPSGISQ",
                    .warn_at                  = 9220.9544,
                    .crit_at                  = -8017.9054,
                    .evaluation_window        = 30s,
                },
            }},
            {"RAKXC", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "UEXSRZWLTWXARMNVYLPDKFEMPBGA",
                    .warn_at                  = 9245.7671,
                    .crit_at                  = 4289.1415,
                    .evaluation_window        = 10min,
                },
                data::threshold_rule{
                    .metric_name              = "VROLVMRUGIMOUKPRQHHWBGZHQUYZHVYQDNYGMMMIEVVPFVUWTHGQZKEZP",
                    .warn_at                  = -1970.7655,
                    .crit_at                  = 2744.4278,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "UAUEWXRGVVOTGYKNSG",
                    .warn_at                  = 971.3193,
                    .crit_at                  = -326.7448,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "IMYNCMDLSIVFUEAOKECTGMBIRURMPHJAXOYQEPWTCQSQXHOS",
                    .warn_at                  = -4682.3344,
                    .crit_at                  = -6050.0692,
                    .evaluation_window        = 5s,
                },
            }},
            {"PS", std::vector<data::threshold_rule>{}},
            {"VPUKVE", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "SNQMFKQZCTYYTEFWTBMJUUTIFMAUOHX",
                    .warn_at                  = -3625.1159,
                    .crit_at                  = -127.6391,
                    .evaluation_window        = 2min,
                },
            }},
            {"QIVARW", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "BKXECEIJDBQVKHHVBJ",
                    .warn_at                  = 5722.98,
                    .crit_at                  = 609.9277,
                    .evaluation_window        = 10min,
                },
                data::threshold_rule{
                    .metric_name              = "YZACIMLYGZJFZVLZAAJURLLSFELY",
                    .warn_at                  = 2020.3308,
                    .crit_at                  = -4171.6367,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "HHEPPJOYRSAFAJFIQHMIKCZJNYUNUSJNASEULCMDTCIEBOQALNPOQFPGXHYU",
                    .warn_at                  = -4988.1621,
                    .crit_at                  = 6377.4803,
                    .evaluation_window        = 5min,
                },
            }},
            {"QEN", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "HBLIEQFNRQVVGVHFNRKMLGNIBNLLRZLJUXTEIAPECHFCXAIN",
                    .warn_at                  = -3658.1057,
                    .crit_at                  = -1081.5747,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "OEQHAVWXGH",
                    .warn_at                  = -2579.5296,
                    .crit_at                  = -9649.6027,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "VULGCBKPKQJDPKIUFEJLCGC",
                    .warn_at                  = -2239.3945,
                    .crit_at                  = 1436.141,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "MLOVNEYDBPFOFUGYLKUBMSJAW",
                    .warn_at                  = -576.0351,
                    .crit_at                  = 6262.6205,
                    .evaluation_window        = 10s,
                },
            }},
        },
        .warmup_delay             = 2s,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
