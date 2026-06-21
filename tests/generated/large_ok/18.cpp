#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_18)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/18.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VOKHGPUPFPJ",
        .worker_threads           = 117,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "ZFZHFHGXLSQGZVYPGWJIAKMHYXMRLSSQIITWJRDJPSQ",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "UZFGGUVZNENQPSDWGSIRKZZVRPCPEPEPCHUCRLGZUMZ",
                            .port                     = 37934,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 76,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "MFMNEIWMVWLEKKXTJENWRASNE",
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"AQRRO", data::threshold_rule{
                        .metric_name              = "AYTYINXMPTRPNZEHFZFLXUJPBYCLYRXFQEG",
                        .warn_at                  = -4754.8571,
                        .crit_at                  = -8472.0081,
                        .evaluation_window        = 1min,
                    }},
                    {"EJD", data::threshold_rule{
                        .metric_name              = "CLKCTILXFMWNQNXQWAINZXBSIMICGJFLEWVUO",
                        .warn_at                  = -8212.4659,
                        .crit_at                  = 5135.1078,
                        .evaluation_window        = 5s,
                    }},
                    {"YOQSCH", data::threshold_rule{
                        .metric_name              = "OYKFYXCHLRUPQYQYMMVJOYAQUGVGACMVYLWCSAIGHREWU",
                        .warn_at                  = -3719.4902,
                        .crit_at                  = 8895.5333,
                        .evaluation_window        = 5s,
                    }},
                    {"AQNV", data::threshold_rule{
                        .metric_name              = "QFINEPTHTIPBQTWZLQBTOJZWJWTAGVUQSGAFJHGNCRFAORUHOCXWPPGGYOK",
                        .warn_at                  = 2771.7106,
                        .crit_at                  = -1334.3645,
                        .evaluation_window        = 5s,
                    }},
                    {"XWVR", data::threshold_rule{
                        .metric_name              = "LGBVUXCTEMCCPILGPCCLEKKANLGBJGHFTE",
                        .warn_at                  = -3098.5004,
                        .crit_at                  = 2619.8288,
                        .evaluation_window        = 5s,
                    }},
                    {"ZZKEBH", data::threshold_rule{
                        .metric_name              = "XFKJWRKYSKQSKIJLHPLNNLZRZDIOEVGPLHOJZGPEIJ",
                        .warn_at                  = 7796.2402,
                        .crit_at                  = 3814.1248,
                        .evaluation_window        = 5s,
                    }},
                    {"JGJSA", data::threshold_rule{
                        .metric_name              = "VHYYVWMBQTDVLBYYMYNYCNTWVLPLRGVNZJRMSHWZYQCH",
                        .warn_at                  = -8596.0046,
                        .crit_at                  = 5073.3519,
                        .evaluation_window        = 10s,
                    }},
                    {"NLVK", data::threshold_rule{
                        .metric_name              = "LSLWSVFJFBKAWGMYHKRPDPJKEUCJHIHWNN",
                        .warn_at                  = -5873.2186,
                        .crit_at                  = -7564.6337,
                        .evaluation_window        = 5s,
                    }},
                    {"GXACZT", data::threshold_rule{
                        .metric_name              = "RTSFFVAAREMQDSEQTGNMHKEVSMNBRMGPWKOVTOBNCBQ",
                        .warn_at                  = 1888.0879,
                        .crit_at                  = -6872.644,
                        .evaluation_window        = 15s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 88,
                    .base_delay               = 100ms,
                    .backoff_multiplier       = 2692.1305,
                    .deadline                 = 1min,
                },
            },
            data::backend_group{
                .name                     = "IJOREKMJXCCHQTNCEIV",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "BAQYTYOUDMKCQNV",
                            .port                     = 7795,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 68,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "HWBEQLLIWQFTMOQGLHUKTPXMLPHNRMYEPALFRUG",
                            .port                     = 32555,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 95,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "TNCVMQLBRWYJBKFLHRDVEVZTSSYFHF",
                                .value                    = "BNSIMEPGULEECIZZNSFTL",
                            },
                        },
                        .tls_cert_path            = "BGCIWPRQJZYONSONOFVPRVPXQLRBFYRTFWLIWRBP",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "BFZHWCYIFCAKHVTPHYPAFEYJMSAAMNBGLUSRQZSJNDGQJINNIYIKDVBDBRV",
                            .port                     = 53030,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 58,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = -3394.5641,
                            .deadline                 = 30s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "OOCDFOATNLNGREZNSVUNLGXHSJAEZQRTLGOUNSX",
                            .port                     = 49572,
                        },
                        .connect_timeout          = 2s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 72,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "ZDMFQTAADKJAXCNDVT",
                                .value                    = "OBWADXHWSMARCECUUOKKEMRDQUMUSCOMFULQQNCTGFHQBBEIN",
                            },
                            data::tag{
                                .key                      = "BDGBPETQXAJCPLPEKU",
                                .value                    = "ZIKTTJBNMQCCVRJBKGJTJLBZJEGBVYHCPOAJMF",
                            },
                            data::tag{
                                .key                      = "MNHUABDVLUUEYB",
                                .value                    = "",
                            },
                            data::tag{
                                .key                      = "AWMNZAQQUIZJYRFVCQQGOWVRCAJYVCWOGEXPOTUKJSIIWSXLQ",
                                .value                    = "XGEYZKLGWRPXVTKTERJYC",
                            },
                            data::tag{
                                .key                      = "ONLGZCVJTWQXHIJNDQKOMGUIZFT",
                                .value                    = "OJAKJCSVBQJNDZNUVGSVECSGDMCDDWENHWX",
                            },
                            data::tag{
                                .key                      = "VYTXZOZAMSDPYTSYGVCFIOEZEDDFAUGXKBARZLVCREWEZYXJJNYLTP",
                                .value                    = "TXYMTSLTJNYEXKZOORC",
                            },
                            data::tag{
                                .key                      = "KLBVSOVKDCWECEHSTJMAHVRJYTXVXT",
                                .value                    = "KTGIDNASYYGEZJUBWNYLQIKHLOP",
                            },
                        },
                        .tls_cert_path            = "KRTEODACXLR",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "ZUADCAHECQNBBBIJHN",
                            .port                     = 18690,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 4,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 1551.4902,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "LOBIBXGURDMFRGTTLJUMQAJMAJLQKQQ",
                                .value                    = "LQQCRJCKSMUVGSUQIVBEWQVXOOMKXSWKCYLKMQVOIOQJ",
                            },
                            data::tag{
                                .key                      = "QGBXWHDSUIYHR",
                                .value                    = "HPFKMDGUIJKJ",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WUHBGEIBZEWHROWOTDETXDIL",
                            .port                     = 25179,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 45,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 2min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "RIBBGHMYIBHTNPSLTWTNBHNBXJKYZWSJHGQWWMWMUDZBPRDHTUVIBOFVUWUEPWF",
                                .value                    = "EOPFIAYZSQJXSWTAPBXTSJYQGKLLCPTZEMISGMJ",
                            },
                            data::tag{
                                .key                      = "UKJMFDMGWORGJZQKKBBUHMQVSDZTMEBJIPSXCKOFXQTXNUAKQYCTTMODYAE",
                                .value                    = "CGISFZZURGGJYJSMURCNSAA",
                            },
                            data::tag{
                                .key                      = "ZZEXXALUMQOQVYMKDBTTERXQUWYWTQDXNPZBSYPKEYSGXKEIQRQFLLPBGG",
                                .value                    = "OLEHLMLCXSXMFWTVCO",
                            },
                            data::tag{
                                .key                      = "HNGIAVCSDWWJBOBALCGLWXHHJXQPSONUUPOBNUUOLNQLTYGKWSXUJFWZIK",
                                .value                    = "CXWQHWEAULBQPOQMAVMBCTJSTEXOYKCNRZCWMWYELMIEAG",
                            },
                            data::tag{
                                .key                      = "CQAIIOEQHLGPNSKKNLJHZDHL",
                                .value                    = "XACVRZJDUPTJLKJGQAMVFZWXLNQPPPPYNQEHSSTYLEIFNLHCYQPDFDRATE",
                            },
                            data::tag{
                                .key                      = "EVSWLANTCKQHKYPOWSXVIKZBUFQQEMHMWLCGVCCJGHRSYZATGBPDWMDCWFTUDX",
                                .value                    = "TLDGYPEPWJZJKLVWQQMSIZGLJV",
                            },
                        },
                        .tls_cert_path            = "BYSTFPOCPDC",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YGNNHPFGILGPBRCDIIKFLEZMCUWTSIGERKNCUIJJOBT",
                            .port                     = 42743,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 34,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "WMVWLYDOOSSPHPJZUUFOKYLLXNSFNWKDXCZJHAC",
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"RVL", data::threshold_rule{
                        .metric_name              = "LNFLUF",
                        .warn_at                  = -4260.4935,
                        .crit_at                  = 3003.4974,
                        .evaluation_window        = 5s,
                    }},
                    {"NTQMH", data::threshold_rule{
                        .metric_name              = "OYADDVZGEEURYCT",
                        .warn_at                  = 6314.3699,
                        .crit_at                  = 177.8736,
                        .evaluation_window        = 15s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 36,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 15s,
                },
            },
            data::backend_group{
                .name                     = "TRUSXOYNQZMIWDEWCSHFUALTOKJYZD",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 1,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "HJXJJDDTTYLXGHQBS",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "JUPAXZLVLSQMFNBUDESJAIDCGSTIE",
                            .port                     = 6158,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 66,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -505.8065,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "IFBUQUORZYHKIQONJSTPDIXXQXSXLSCCFUVTSI",
                                .value                    = "ELJBPSESFXXXQEXOXFQUUGZOCGPMVIACDMVIZVQXNXZBNTC",
                            },
                            data::tag{
                                .key                      = "QCTJZPWGEDQTRTKNTIJRBFKGHRJD",
                                .value                    = "OODXCIJLHYLSXZYWQIOCZQVXZRG",
                            },
                        },
                        .tls_cert_path            = "OPOETVEOBJUFJAOLQQJCGGXTDSKOXXWIQXCG",
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"QLHWD", data::threshold_rule{
                        .metric_name              = "AEIUYHLPGSPDGRPGARRUBK",
                        .warn_at                  = 2872.9333,
                        .crit_at                  = 4248.7871,
                        .evaluation_window        = 10s,
                    }},
                    {"HYOAMY", data::threshold_rule{
                        .metric_name              = "MNRVFOETK",
                        .warn_at                  = -5575.6053,
                        .crit_at                  = 4942.8754,
                        .evaluation_window        = 1min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 87,
                    .base_delay               = 2s,
                    .backoff_multiplier       = 8937.7382,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "CK",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "MGVWTGAPQBWHMEVVOEVIJHIWFDWLJAAOKQTQOHIIYWFQQJFKFGVXVF",
                            .port                     = 32948,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 20,
                            .base_delay               = 5s,
                            .backoff_multiplier       = 4251.9941,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "VZLLIXOTDIMJKCVTQAMJEQOJVXAXZMCNL",
                                .value                    = "TYUJEOXKTZFDOCRHPRM",
                            },
                        },
                        .tls_cert_path            = "SFQALRQTDRNRLAWCGRNPYURPDYCQNJGVWNXHHEBDYNTANVOZKVXAASBCWUHVCXM",
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::nullopt,
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 29,
                    .base_delay               = 25ms,
                    .backoff_multiplier       = -1557.2919,
                    .deadline                 = std::nullopt,
                },
            },
            data::backend_group{
                .name                     = "TTVHJTXBEUKXICLVKCLVBYVYWIT",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "PAIYWMERBFJFELKOWYICXFUDDNHMIPRZAOMVSEFQUMTOIFYDVOANLBHL",
                            .port                     = 371,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 13,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "QVDCWSHPAIBBQXBICKDLULUURAMAHOZSUARLRDEQGONBAMZUPSLRMXCI",
                                .value                    = "EJERSUIFKAMANDTQGJKMYCZXKIOHJSGC",
                            },
                        },
                        .tls_cert_path            = "HWDORDXTVGWVDSTC",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "JTOHHAABJYLQACQDHJMGGKGWIIMECQEQTIUGGBFLFGZNBLIYZLFQYGH",
                            .port                     = 32658,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 63,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = -7212.4432,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "UUOKLWAEQCADIQYRYJUCXYOVGFBXPJHEMITAZVIEIJWHKWALRFBBLSUQ",
                                .value                    = "PRHZJDDZIBAQEZDKHLSEZHHSBRJSJBLMNDRHWZJABDZIKEFEUCK",
                            },
                            data::tag{
                                .key                      = "LVFZZDPQHJSSBNMOEMYLJSVHULMXEOOJ",
                                .value                    = "YRAQSPXCYJDJCLULEDQTLMKYNLDIHVSGPANCWILTLXQPABGBZQXRUQ",
                            },
                        },
                        .tls_cert_path            = "VDJGTZICHOEAFBZW",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WANKIDLHNYHDRVARSMDJP",
                            .port                     = 24130,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 4,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 4298.1649,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "ATXWFRX",
                                .value                    = "HCASXZBCVBNRFBYJUXJDMQMKOYTP",
                            },
                            data::tag{
                                .key                      = "KPNMOLFOYXKFTIXFXGGVKHCPFISGGTMKHRKBM",
                                .value                    = "DTXSJVHJGNDZXBAWIGCTYDOTBDFBNGPI",
                            },
                            data::tag{
                                .key                      = "CVBQSONPWBTGGNPBCPAQPE",
                                .value                    = "NJZSIAYJLORNNIZHWKEKPQSK",
                            },
                            data::tag{
                                .key                      = "XNLOPTKJZJKVLFCMDSYIHKAIWBFSOEADQCNVLM",
                                .value                    = "QMLDWDHCUNXQHMJVEAFINFXIFTKCSIBJJQSQYXQALCTUEZMORBYJRAKAIXFZ",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::warning,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"NEK", data::threshold_rule{
                        .metric_name              = "MGPXFODADLXPUHBSFWZDWIKYBHYOQLWLFQKAXFAZHNSXQGGE",
                        .warn_at                  = -2645.2556,
                        .crit_at                  = 4087.5921,
                        .evaluation_window        = 5s,
                    }},
                    {"SK", data::threshold_rule{
                        .metric_name              = "VQWZXNQSXCVQKTHRGRURAHRSVYZOBKHRGVZXQVIDZPPYKOQKX",
                        .warn_at                  = -8052.1707,
                        .crit_at                  = 2817.5938,
                        .evaluation_window        = 5s,
                    }},
                    {"MAY", data::threshold_rule{
                        .metric_name              = "YWBKDPRMLKWHFOACZ",
                        .warn_at                  = -8120.7428,
                        .crit_at                  = -1112.5935,
                        .evaluation_window        = 10s,
                    }},
                    {"ABDET", data::threshold_rule{
                        .metric_name              = "BDARWKWQTCANHTZIHPZLXDUJVZZLKBVEULKFIYBTWK",
                        .warn_at                  = 1612.785,
                        .crit_at                  = -5568.8676,
                        .evaluation_window        = 10s,
                    }},
                    {"CRYOK", data::threshold_rule{
                        .metric_name              = "BLHEK",
                        .warn_at                  = 3282.1507,
                        .crit_at                  = 7898.8705,
                        .evaluation_window        = 5s,
                    }},
                    {"WOLG", data::threshold_rule{
                        .metric_name              = "PQJOBBDWSOYPIMBBVWOFJLNQTWORRJKLXB",
                        .warn_at                  = 36.9541,
                        .crit_at                  = 2575.4625,
                        .evaluation_window        = 2min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 63,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 4870.1075,
                    .deadline                 = std::nullopt,
                },
            },
            data::backend_group{
                .name                     = "MSSVPKZBUOGNUJIXFAAQNVYOSPIR",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "VIUNKVOCBHVUBHRBRXOLKHAFIREFHJD",
                            .port                     = 14780,
                        },
                        .connect_timeout          = 2s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 5,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = 8649.0236,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "TINQRUTQOKRKTFGIDAATZUSXUREMXIJOUMPGYW",
                            .port                     = 32434,
                        },
                        .connect_timeout          = 2s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 95,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 5434.1995,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "GPMIDOGMVPVRSTADKBJWXVV",
                                .value                    = "ZAKRMQGVHPHBFBUM",
                            },
                            data::tag{
                                .key                      = "TYDBOMORSJE",
                                .value                    = "NHJIJHDLSDKXKJDCKWPAGRXOCCAKXGKI",
                            },
                            data::tag{
                                .key                      = "GIFDITRTOF",
                                .value                    = "EOLJJMUYIRDMBXWDQK",
                            },
                        },
                        .tls_cert_path            = "QPIXERGMAHJTJPYPRHIOAPXSJYTGJJCZTLUJMNAVEXCFYTJYSXDPEOVZTHNJU",
                    },
                },
                .min_log_level            = data::severity::critical,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"AEHOL", data::threshold_rule{
                        .metric_name              = "LRLXCW",
                        .warn_at                  = 5030.4861,
                        .crit_at                  = 2460.8481,
                        .evaluation_window        = 10s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 96,
                    .base_delay               = 10s,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 2min,
                },
            },
            data::backend_group{
                .name                     = "PUMJYLQJLREFSMSSJGWKZQCPVNKZXHBEXBT",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"EKU", data::threshold_rule{
                        .metric_name              = "MAAFENINBZTNPTEAFEOAIZTCW",
                        .warn_at                  = -296.0961,
                        .crit_at                  = 7135.891,
                        .evaluation_window        = 30s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 77,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 9368.032,
                    .deadline                 = 5s,
                },
            },
            data::backend_group{
                .name                     = "ZMGTKSDREEZHS",
                .endpoints                = std::vector<data::endpoint_config>{},
                .min_log_level            = data::severity::error,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = std::nullopt,
            },
            data::backend_group{
                .name                     = "GR",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "NZJOTAYSEIWIRFQAMZYBJDELSVPM",
                            .port                     = 15212,
                        },
                        .connect_timeout          = 100ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 46,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 30s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "DC",
                                .value                    = "OBYOLWQFAVRSFZBUGVTWIIS",
                            },
                            data::tag{
                                .key                      = "VCAIQPRAXOTUYOCWTBSQTHMFVOPNQJMNJNQLBMGLCOISU",
                                .value                    = "MBSMALVBYTLYZNHWXZVUBINXRK",
                            },
                            data::tag{
                                .key                      = "FSLTFALCEFBHVNYSGEFDISTDSDZBUMCRFYJDNRDAEPTKXRMCKHKLQAMVRNOG",
                                .value                    = "GYLESNXMCVWAJNEPBVZOVGCTCLIPTZOBDCLOPPRXQADEFTFSIGZYHPVDXXLJIT",
                            },
                            data::tag{
                                .key                      = "VHLBJOJNLVNXXMDKPUWTDMMDZG",
                                .value                    = "THMUOVCIUTNYC",
                            },
                        },
                        .tls_cert_path            = "WANIBRSIUNUCVDOFCIVYKLNDKOOGRGKQSUIGLCZMUEOGNJXRZ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "GLYSIVQHTYSHKNXFCYLBPTEVPSGWSMABVYKTGBVCXLKTQRR",
                            .port                     = 11475,
                        },
                        .connect_timeout          = 10s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 72,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "MWHBZXUXVUOQTMBGJJWLGBYCNUUAOGVMVFLDXVPXETOL",
                                .value                    = "EAOMABNSEVLUENZWTGADURNZNIGYIFHQYGZBOIKNRILPCPUOWDDBVR",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                },
                .min_log_level            = data::severity::info,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"NYRFT", data::threshold_rule{
                        .metric_name              = "XNYMQBZITUHRELLSGCCR",
                        .warn_at                  = -4493.3633,
                        .crit_at                  = -8046.7274,
                        .evaluation_window        = 1min,
                    }},
                    {"EI", data::threshold_rule{
                        .metric_name              = "UV",
                        .warn_at                  = 6264.4674,
                        .crit_at                  = -6414.1457,
                        .evaluation_window        = 5s,
                    }},
                    {"EBPQ", data::threshold_rule{
                        .metric_name              = "RVGDEGPPBSUKQHDDHQOVYUOLSOOBDJJQULXRJNZTLFLHZRWNK",
                        .warn_at                  = -3141.2764,
                        .crit_at                  = -5680.9177,
                        .evaluation_window        = 2min,
                    }},
                    {"JACCE", data::threshold_rule{
                        .metric_name              = "IYOB",
                        .warn_at                  = 616.6363,
                        .crit_at                  = 5094.5762,
                        .evaluation_window        = 10min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 26,
                    .base_delay               = 50ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 5s,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"KXDNRO", data::routing_rule{
                .pattern                  = "TTXHRD",
                .backend_names            = std::vector<std::string>{
                    "MONFJNESPFQNUETUFDQVEQPTAACVYUSPBCZPVXSBQIKWE",
                    "EKBUOMDVKIRIBV",
                    "FZLUOHZZCWRQVNGVTXZUIVGWZNHMFBZHN",
                    "IJADOYBSHXIQZHUPCJVMABMQBTSFOGWATWIFFPFUSFUXAIINUMTWKQNEP",
                    "LMGIBYSVXZKXVBIYIUYYXEXGFFEGICZAYMADMRHTSYEUBM",
                    "LUQQTSOCQJMQGLQSDMYDEYAOMCESKXSTCLZJMTJHCSNJAFUDPWDS",
                    "KY",
                    "TPDSVUQMRQUPC",
                    "PYRRFWEHLZDNUIWCNQWXYDHMENMBFB",
                    "REVJWPSGBHEZMKMWSHMRONKBZBPEIA",
                    "LHJBYRLEBRURZDUBXEEDHUNPSXYPWEEGQNLMGUUGG",
                },
                .timeout_override         = std::nullopt,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"QJ", "JN"},
            {"ASY", "EZARQDSLYCQMS"},
            {"ABRWFN", "JQMDWRRDGGKRIQSNMFPZNDGRPBX"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("VD", 60277, false),
            std::make_tuple("BEAHKJVDOGGTEYS", 22149, true),
            std::make_tuple("ZBQOAYCMYBVICUDRJQERHDXFCNLPYNZZPRDQGMEMEQPW", 51431, true),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "FZTQPRFLVSPXRNLRGFCXFEDTDSQUXKNLMWZOZLIUWOIHKPSCKAR",
            .extra                    = boost::json::value_from("WEDGVVBTNEPHUGEZZFYRKUOZGWYKKJFMYZVOWAHETCES"),
            .log_level                = data::severity::warning,
            .retry                    = data::retry_policy{
                .max_attempts             = 59,
                .base_delay               = 500ms,
                .backoff_multiplier       = std::nullopt,
                .deadline                 = 10s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "NPESUSRXLIUMDHFKQIFVTSNLGRACEHPFOUSDHSTOYZPPIIVTRSAZNVQ",
                    .value                    = "VGBPQUTNEKNWAKAEHEWXGZPIUTTWRDK",
                },
                data::tag{
                    .key                      = "OQCMSQCZFWCBZCHADNMZODFYBCKEG",
                    .value                    = "ZKJTVEDWWJCZBUPMPEY",
                },
                data::tag{
                    .key                      = "KZAKYXGQHLRZLXTNGTJYBZGLVDWDLIACJEYQI",
                    .value                    = "PASI",
                },
                data::tag{
                    .key                      = "NMGHNYWTHIDUNSMLGNDLRFXOHLZBVW",
                    .value                    = "TERKJPZWXPJMVUGVZFSBRAMUU",
                },
                data::tag{
                    .key                      = "UIDZTZXRTHSQVGZMGMMBBPWYMTXWDZVDHVIWSAGHWOHYHNL",
                    .value                    = "JOWKOTVUJA",
                },
                data::tag{
                    .key                      = "LRCCVASZRWLWPTFDWNYOHRFKTUDUHNOHZFCOQAMHEC",
                    .value                    = "OURHRNEBCWRAWOSVHWVJKLSUJMCIBKYENT",
                },
                data::tag{
                    .key                      = "CMKJMKFMBFNWTQCWPNOCJWCAAMOVMQZMAOQAUGIPPIQAQOQJYLTQS",
                    .value                    = "SZMERJPNBYGHWTKSUWJLGRMICETGDDVWVITSRMUTW",
                },
            },
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "KLYWZFUKYJCKTQMWNOSNBMVGPDIQKVKGPXYXYMNIDAIZ",
            .port                     = 48951,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"DZY", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "UJECGQPOMKJYICIMSWL",
                    .warn_at                  = -4823.3028,
                    .crit_at                  = 2412.7193,
                    .evaluation_window        = 5min,
                },
                data::threshold_rule{
                    .metric_name              = "GMELAWIPBBYRJ",
                    .warn_at                  = -8473.7982,
                    .crit_at                  = -5934.9832,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "QOBKWYLQYKZNKVVNUOFMTDRRZSQYTJURAUP",
                    .warn_at                  = 4038.2752,
                    .crit_at                  = 6744.2216,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "WDNSZEXTMPA",
                    .warn_at                  = -7814.253,
                    .crit_at                  = 7377.2235,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "NCAOFVTHREVCUXFEEFGPCHPGNNMQR",
                    .warn_at                  = 24.865,
                    .crit_at                  = 923.8236,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "YNZVHAZJNHMSAVCEJV",
                    .warn_at                  = 6508.2688,
                    .crit_at                  = -8755.1759,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "XYYSBIEVCWLMNMRQLFJCAYXXQHXRZXDYWOIXWYGFMTNSWL",
                    .warn_at                  = -8326.7741,
                    .crit_at                  = 5084.5636,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "QRNCAGMEQKBABNACNBQIHKVZLYPCBFUJOSMWRMYHYVHFHXJBRRLCIKAZYQ",
                    .warn_at                  = -7929.5617,
                    .crit_at                  = 5427.5853,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "OSFNQFYJKXROTZIDSHNXPZWNHVNULWPPHCILLBBNSZEFFULBIOHBRJCUAEK",
                    .warn_at                  = -8158.5676,
                    .crit_at                  = -7744.4795,
                    .evaluation_window        = 10s,
                },
            }},
        },
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
