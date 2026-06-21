#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_8)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/8.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "MEGWBCEHZQGMUA",
        .worker_threads           = 118,
        .enable_tracing           = true,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{
            {"WI", data::routing_rule{
                .pattern                  = "PMXDVIDCMTMDVBKHWCPUQGSZETCRBPWGE",
                .backend_names            = std::nullopt,
                .timeout_override         = 200ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"EFYTD", "KWLUPQTGJELQJQVCZQWRHLHAJKHIBNIMJW"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("VAGYFJDAZY", 38045, false),
            std::make_tuple("ENSONNCSCJWDBCVDYQQLEZQPWETCGAEKMVSDXJLKLAUPGBTBYZSFFKNOD", 8335, false),
            std::make_tuple("EMDDSXOUEXOQXCWPSMLOHBGBODDGXA", 70832, false),
            std::make_tuple("NQCXYTQWSGQHKQMXQUGAJTJ", 90885, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "RNXLZXKQJULZJUDGPL",
            .extra                    = boost::json::value_from("SJGJMTMVQWXLVTSLVNGPQQCI"),
            .log_level                = data::severity::error,
            .retry                    = data::retry_policy{
                .max_attempts             = 27,
                .base_delay               = 10ms,
                .backoff_multiplier       = 6586.6664,
                .deadline                 = 5s,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "NHLHHZQXOHHZTQGLPYDZDMCUFYSNBZEATGVICDOOVJSCETLUCKZBCEUZ",
                    .value                    = "CHXBTZKHJXLKCQDXTLNFFIM",
                },
                data::tag{
                    .key                      = "CDRHCJFKXGDBBRZXFFRUKJHXQPDSWCEXEHKGNFFEYOBWOS",
                    .value                    = "JNNSVXLWSWPLXYQFJIVPEIPUQRZQJZGSQMYEPUPDJM",
                },
                data::tag{
                    .key                      = "QJLMWATEWACFOSEYNSUSDLQBTWULLDKUDPFUHPLSLLYZNLXUVBXEWVU",
                    .value                    = "BHQLPLPRFJEUIZAZOXJS",
                },
                data::tag{
                    .key                      = "JJMPOVUCPUOKESXDLWTVOLPSMGRQW",
                    .value                    = "ZEQBCRZVYJGEUMIZGDABOWGKKAAXAXESJUJAB",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "NHAVDQQGPYWNDNQECEVWYZVWLTNVBINWVGAJCYPKWFHBMWJIJQITAM",
                .extra                    = boost::json::value_from("WWWWGGDZYUYPEWKHUCNLQRVPOTLTETFPDHQZKTFRHHNXVTGKWE"),
                .log_level                = data::severity::warning,
                .retry                    = data::retry_policy{
                    .max_attempts             = 33,
                    .base_delay               = 50ms,
                    .backoff_multiplier       = 4399.3195,
                    .deadline                 = 5s,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_40", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "MVVONTA",
                            .port                     = 31945,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 88,
                            .base_delay               = 1min,
                            .backoff_multiplier       = 5101.5827,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "PSDTFDBOICRAGHUCBKLMWKP",
                                .value                    = "PXZIUBPOSYHZRVZWBQYQUMOQPZVFDSTQZWFKXJ",
                            },
                            data::tag{
                                .key                      = "TDORFJFXZLLQBVMTICHRWWPOJWGPRCUCUJCFMDRDFFWPKSHWGOHYMAQLJDQQ",
                                .value                    = "BSDOXLIKDDGPNSODWEALEMOKVQWNTDZ",
                            },
                            data::tag{
                                .key                      = "UNEYCXFHOGITRVEGQAKLCZFQKRNXJEHMASDEHCYFUEPJRMCOWJCMOPNKPXHJB",
                                .value                    = "SVDARTLUWNAXIWLBUUFTCRPBQABXDKEHLLZQVRLCHUGQHIDUNAGADYNKEQ",
                            },
                            data::tag{
                                .key                      = "KLQMYQFTKZYUUWJFAWIXAQBTTZJREJRTGAEWBXQYTELIOXVILWJWVELOOTWHYQ",
                                .value                    = "UZRKCRISYVAJKQDIAASOWMUWSQGAWAEZURBKKRUHYMRSGPOYJMXZQSNP",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    }},
                },
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "RMTVBRZYVGZHRFMNKHIRKZQAJHNMRIPKBPTHSFLFXFYHGBVUMSQHS",
                        .value                    = "DEVIJBEWPCLDTWQQIYUDXSVEVWBUDLJLXIEZVSBUUWFYMAAOOLMHVBLSVOK",
                    },
                    data::tag{
                        .key                      = "EINCCHKGXQMBOJHJKINBAANYBUGHRDZCPTT",
                        .value                    = "FOPWVCZARIJBRLCILQJORHHBCHOJBDNRINXVDE",
                    },
                    data::tag{
                        .key                      = "NVXLZPMPVPQCMKMKNJJP",
                        .value                    = "XHCICURSBZEBADTGQPOJGCJRKJPE",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "JFMYJAXWDAXHWNRGSEETDFIOOFSHVMJNTNWAFTAYWODELXODNIDBC",
                    .extra                    = boost::json::value_from("ZFYNKBNKBQASEPUEXV"),
                    .log_level                = data::severity::warning,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 75,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -3593.9053,
                        .deadline                 = 5s,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                        {"ep_24", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "JBFPI",
                                .port                     = 38235,
                            },
                            .connect_timeout          = 50ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 45,
                                .base_delay               = 1min,
                                .backoff_multiplier       = -6072.3914,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "SWNQYZFZOCTGYCADEIRVZGVBNEPVYYLS",
                                    .value                    = "GAMNNQZJANHLOICODBT",
                                },
                                data::tag{
                                    .key                      = "QFKGKWEELIWVZFCAQKZOCQTXBLBEPFUEWMUFZWRLZELLBRKCGSPPKQFXYESWTYT",
                                    .value                    = "MPHRWVMATTKLEDUQRDXUNWDGBVFEMFJDSKAWWRBZPEJSZAVDOTFNJIPUNT",
                                },
                                data::tag{
                                    .key                      = "RPEL",
                                    .value                    = "MNREBCZOMUHMQKQFXBEERDJBTLCQFROGLBURYZHHHTUQJLHWFMCLFQLDV",
                                },
                                data::tag{
                                    .key                      = "NCH",
                                    .value                    = "VIZXELYTYFMNCDUVIRUMPWVWWZTHERSLFAJIASPPMDWWIWOEQFS",
                                },
                                data::tag{
                                    .key                      = "IEHESJCZXCRZAPJPQXMFOUKGQWNPLVPTVAZXEIYJTJQEWTVJZJXR",
                                    .value                    = "HZVGFJNZRSIWDCVFTPMBFMDSHCHQNFEOYYGIAKIZBKXPIRU",
                                },
                                data::tag{
                                    .key                      = "BARJGWJHKWCWGSWJYWEVAQS",
                                    .value                    = "WMFGWHELOKXCXAOTWCTMBJWDNATUORLSJORUHWIXD",
                                },
                                data::tag{
                                    .key                      = "JSFYCIGUQVYNYZZNNEDCHEXVQSEHYASRPIB",
                                    .value                    = "RHMQTYVLKXRNMKUIYVDCBZGVCFFAQQRAWUEHQG",
                                },
                                data::tag{
                                    .key                      = "CQVLRBJRWCRRNDJIZNEQLJYXO",
                                    .value                    = "JXX",
                                },
                                data::tag{
                                    .key                      = "PDYHPCAZMXOCYQZAGTUQTBYH",
                                    .value                    = "KQHLH",
                                },
                            },
                            .tls_cert_path            = std::nullopt,
                        }},
                        {"ep_27", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "EKITOCLCINFIEMGFEYA",
                                .port                     = 6243,
                            },
                            .connect_timeout          = 50ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 33,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = -9667.8589,
                                .deadline                 = std::nullopt,
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "EAHIKLNRJNWQXYICCLGHXNBLSHMYACBMXNGYEUCPYYKFYGVAAOZK",
                                    .value                    = "JCERDQQNFAMRYWKIJFKHYDKCROSWPOVLCDWLWXKKJYKWC",
                                },
                                data::tag{
                                    .key                      = "XTRWTNJPHJXPHERHDLZXRQIMGSNXHGBPWSSRRRSLGVHQQGHHI",
                                    .value                    = "WHFCPSQDDHCUJLHBVKSGIPXZ",
                                },
                                data::tag{
                                    .key                      = "QGCC",
                                    .value                    = "GPTMVRJZUNCSZRSAFUYYUWQSDHNRIJQZDXDV",
                                },
                            },
                            .tls_cert_path            = "TAMYTRFESVCBSBBKWZPIBHZDODJSKUUPXPBEFQUOCZGERVNJUC",
                        }},
                        {"ep_38", data::endpoint_config{
                            .address                  = data::network_address{
                                .host                     = "EHWMIQXEAKXNBOBQSLIYQQIIOQVPNAAFTUWJTYAWMUAVSSVPCVMYZMQDS",
                                .port                     = 33588,
                            },
                            .connect_timeout          = 10ms,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 51,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = 5s,
                            },
                            .tags                     = std::vector<data::tag>{},
                            .tls_cert_path            = std::nullopt,
                        }},
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "JQVNNABXDOFKIRHWRSDJXJUEIIIKPAWAZEEXRI",
                            .value                    = "",
                        },
                        data::tag{
                            .key                      = "OALFPWMDZBCDIMWD",
                            .value                    = "INIPGYSADMFMJIAJKGOPYAELCTPS",
                        },
                        data::tag{
                            .key                      = "CRKESRGTXBRNWYACQYDU",
                            .value                    = "IPUPWXGXJRJSJTPZQMJEITVZYQIIV",
                        },
                    },
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "E",
                        .extra                    = boost::json::value_from("BJDUJYDMJHNSOSDS"),
                        .log_level                = data::severity::warning,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 89,
                            .base_delay               = 100ms,
                            .backoff_multiplier       = 5637.641,
                            .deadline                 = 5s,
                        },
                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                            {"ep_7", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "HLLCFHCIFBKOCLIJGMBQEIAEU",
                                    .port                     = 57933,
                                },
                                .connect_timeout          = 10s,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 44,
                                    .base_delay               = 500ms,
                                    .backoff_multiplier       = 8208.6591,
                                    .deadline                 = std::nullopt,
                                },
                                .tags                     = std::nullopt,
                                .tls_cert_path            = std::nullopt,
                            }},
                            {"ep_82", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "POV",
                                    .port                     = 27021,
                                },
                                .connect_timeout          = 10ms,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 4,
                                    .base_delay               = 10ms,
                                    .backoff_multiplier       = std::nullopt,
                                    .deadline                 = 5s,
                                },
                                .tags                     = std::vector<data::tag>{},
                                .tls_cert_path            = std::nullopt,
                            }},
                            {"ep_65", data::endpoint_config{
                                .address                  = data::network_address{
                                    .host                     = "YJCSTNWNNLSPKWCCNVHJRRWSUNC",
                                    .port                     = 11292,
                                },
                                .connect_timeout          = 10ms,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 33,
                                    .base_delay               = 1s,
                                    .backoff_multiplier       = -3505.3231,
                                    .deadline                 = 5s,
                                },
                                .tags                     = std::nullopt,
                                .tls_cert_path            = "FVUSELHOBBPOLSXPPNIXMEAGCXUZPDESVSXHAL",
                            }},
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "ZDCZL",
                                .value                    = "MWUEKVZAOFXFQRVQNHKJPHZRRKGUELRHKJ",
                            },
                        },
                        .nested                   = common::box<data::scope_override>{data::scope_override{
                            .scope                    = "ZRYLMPCEVPPXRRFEIRXABUAXI",
                            .extra                    = boost::json::value_from("IGXHUKCPOIUXINLZOZTHOQTWMKPDGQVIDQEAEFTYZKJBEVNGYJ"),
                            .log_level                = std::nullopt,
                            .retry                    = data::retry_policy{
                                .max_attempts             = 83,
                                .base_delay               = 10ms,
                                .backoff_multiplier       = std::nullopt,
                                .deadline                 = 5s,
                            },
                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                {"ep_32", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "XTFLDZHXLUXAPRRCQFNUV",
                                        .port                     = 47388,
                                    },
                                    .connect_timeout          = 1min,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 45,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -4079.4919,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "NFJRJQBXLOHDMOAPDZOGMZYVZHYUFYUYJERCKN",
                                }},
                                {"ep_53", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "DHDUOFJARWOCJIXUEMZPRPLLBNEKLEJSWNCNYJLTBHZFZPWWMLFL",
                                        .port                     = 9276,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 79,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -7210.6074,
                                        .deadline                 = 15s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_13", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "FCBJLUBEGNGHYKSNRQNUGXMKWFEIRMTMMDSLVYFFBJKXJGMBHLEQZQKCNYJHJQ",
                                        .port                     = 64754,
                                    },
                                    .connect_timeout          = 200ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 43,
                                        .base_delay               = 500ms,
                                        .backoff_multiplier       = 7670.2869,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{},
                                    .tls_cert_path            = "IQLCSGNISHSTSWELESUUCVBZ",
                                }},
                                {"ep_76", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "VIKLDEWS",
                                        .port                     = 62578,
                                    },
                                    .connect_timeout          = 50ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 52,
                                        .base_delay               = 1min,
                                        .backoff_multiplier       = 9137.5211,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "MHFGXOTSAUXHFMAXAMRTQSHHEHTEPNUIYCUWJEDGRTCHCRELWRJYUONFQSL",
                                            .value                    = "GGEHI",
                                        },
                                        data::tag{
                                            .key                      = "RAKFCVEHBLOLOIMETNTACXPGKILRGIRJUFJWTGFKVPLRTSR",
                                            .value                    = "BOLPYBZFLCCKFPCGVAARYMGXRXXUGLEOEEHIMYQRVFHUWTTNUNRFJAEOFM",
                                        },
                                    },
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_23", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "QJXJYMPJCRAIBQXGSFHHFKOTXRVGX",
                                        .port                     = 22347,
                                    },
                                    .connect_timeout          = 500ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 77,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 4183.5642,
                                        .deadline                 = 30s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "C",
                                }},
                                {"ep_98", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "FMPZIXSRHCGR",
                                        .port                     = 61194,
                                    },
                                    .connect_timeout          = 2s,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 62,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 5984.4798,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{},
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_50", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "KPHWZXBARTNQPTTSMP",
                                        .port                     = 29897,
                                    },
                                    .connect_timeout          = 50ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 91,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = std::nullopt,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "MNSKPZECNDPFWZDUTMALTIXTAHZTOIEUYJOYVLDTVIDGIMOFJFPVM",
                                            .value                    = "ZAYVBNXNMMCKTYFAHMHVLSODJBQOY",
                                        },
                                    },
                                    .tls_cert_path            = "AFIFUAMHDZAGSOUROVJUJGSAFKAPUYBM",
                                }},
                                {"ep_73", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "IIBCMKMITBJZWNFZDFHQJIYXMJCVHFLYLFF",
                                        .port                     = 19477,
                                    },
                                    .connect_timeout          = 1min,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 21,
                                        .base_delay               = 1min,
                                        .backoff_multiplier       = -9558.1159,
                                        .deadline                 = std::nullopt,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "UQIKTOJKZZOSJSJEBOFWSIRQXOUTCSYMFQRSEBRATIBUDHVTHVWLHUMTDXPRBG",
                                            .value                    = "QWGNSLCIVPMVXSBUJHUWLHWSHANEPKEZUQ",
                                        },
                                        data::tag{
                                            .key                      = "YLXZFVTUTAULGRPXRDFXSJSBZPFTMNEUAJW",
                                            .value                    = "WZHLOVDRXJGMZYTREAMNBUXHSOMRAFFFIBQBXVPNKTWMAVUNLAOPYI",
                                        },
                                        data::tag{
                                            .key                      = "MGHYWWPRJWMMCLROCVBWDTICEPGUGXRRPBYBUUBVTALTGNGHSDIQHR",
                                            .value                    = "SFEGMETAMFAJZHXWADEUAVLDVRHJSXPR",
                                        },
                                    },
                                    .tls_cert_path            = "SXKUJLYQOMOQDYHHZCUNFUWOSCULTFSNXHWYSLCYEXCVVGLCO",
                                }},
                                {"ep_12", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "GGKJPUEZSTCULRTIIHVPKFJILKGVESXCTLABKNEMTBMAWTZBQOZSHVJ",
                                        .port                     = 34028,
                                    },
                                    .connect_timeout          = 10s,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 93,
                                        .base_delay               = 25ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "QDOZVXATWFXMUXYSCVWFDZAFVAKEOOX",
                                }},
                                {"ep_97", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "FAHULYRT",
                                        .port                     = 54882,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 75,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 6770.3979,
                                        .deadline                 = 10s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "WGEGJNDODEROGGKFAVCSZBGFGQKIQZUNVPNVAPBTNWDGZLWSRYIRCGVX",
                                            .value                    = "IQQBOGXFIKCVPDIFAIIFJGKZBUIZCDVOYC",
                                        },
                                    },
                                    .tls_cert_path            = "YLYGFNBQYZFHYJMKESOJSWEKEBVDBGIUOE",
                                }},
                                {"ep_87", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "NFHQNTNSJQ",
                                        .port                     = 51355,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 81,
                                        .base_delay               = 25ms,
                                        .backoff_multiplier       = 1001.143,
                                        .deadline                 = 10s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "JBAVWETNWQRMFRGMKRAN",
                                }},
                                {"ep_45", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "OIPROOQIAVSBHHFFDKIMZMTZPPYOQEQBBE",
                                        .port                     = 38430,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 88,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -4227.5074,
                                        .deadline                 = 1min,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "MX",
                                }},
                                {"ep_18", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "YZEHLYHCCODVASTZUFTXKXCLNBHIUNKSRJFRWAXWMRHEIDVVDXCFN",
                                        .port                     = 6492,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 62,
                                        .base_delay               = 1s,
                                        .backoff_multiplier       = 4318.0882,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "GPUBFGUROQFNBJCVOUYZWALZQOANGZUJIXVAAZJ",
                                            .value                    = "FAEHDPJIQHRKCERCPWZEGYTPBBPJXLVYSRWHEEECGOSPFGYPBLAPIL",
                                        },
                                        data::tag{
                                            .key                      = "DMOAWQDZJTNKONSPMTYADJEITLLHVGRWGLEWBUFCJZVLSFB",
                                            .value                    = "GJUGRCSPWASYEQMEUHDZJAUCHDJJCDM",
                                        },
                                        data::tag{
                                            .key                      = "QQYPZQLLOPTDECOMBRXPWIMDBRXTXHCRPA",
                                            .value                    = "NVDWOAW",
                                        },
                                        data::tag{
                                            .key                      = "GVNQGZTPOEMQCWFLZTBZGOMPTZXKLGUSUYG",
                                            .value                    = "CPATJAQAOOZWLWWNCZGHCKOUMPZIWQYUDDCFUOEDVZKFHBFHBZNL",
                                        },
                                    },
                                    .tls_cert_path            = "BLEKPOKVMMZESKUTJDULDPJRVHSBMKOIBVRUXVEKMAPLSBCSWMFMKFQUDHTHYAM",
                                }},
                                {"ep_54", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "YGZRULBBGEJXDYPRAEUHWZBAFKAKLKHXYLZZOEFT",
                                        .port                     = 16980,
                                    },
                                    .connect_timeout          = 1min,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 71,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 9441.7522,
                                        .deadline                 = 10s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "RNDGAFISRTYRIUTTRASYZTQDSTSEZUUSVPMCRQLP",
                                            .value                    = "JJTRDFSCXXWPNTJZQFVNZCVKBRAQSGPMHEXAXXZEB",
                                        },
                                    },
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_55", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "GPMTPBXQX",
                                        .port                     = 17105,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 94,
                                        .base_delay               = 100ms,
                                        .backoff_multiplier       = std::nullopt,
                                        .deadline                 = 30s,
                                    },
                                    .tags                     = std::vector<data::tag>{},
                                    .tls_cert_path            = "SRJGIZWWOPHNAPNKXXPWJBNVQLZDNFNAKSQIORBFKAGLRRVWKZLCVZKSZ",
                                }},
                                {"ep_94", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "GMJSBDTMFFIURFJKBMUBROWRWSDOGHWKHWNM",
                                        .port                     = 46607,
                                    },
                                    .connect_timeout          = 50ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 11,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 4637.9325,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "PPTAEPGKUYBCHXQGDNQYMQCEWYURNGARWYPMUXJLXLTREDMV",
                                            .value                    = "DWKKSTDTWVCBZCOMBO",
                                        },
                                    },
                                    .tls_cert_path            = "XIYDSWJNQTEKXMKLIVJXBHACCYSLMKPXBGFNCYEUDVYTCMYZTJYONUADDHWRW",
                                }},
                                {"ep_78", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "CVEVREAXOPGTHXBSHRM",
                                        .port                     = 36705,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 92,
                                        .base_delay               = 500ms,
                                        .backoff_multiplier       = -3773.1592,
                                        .deadline                 = 5s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "JOVCNYTWQBORWH",
                                            .value                    = "URGSDDEGQYPZTTRYKPCCIWWXQCBCSLLPUUNPKNZGYUEWFWYV",
                                        },
                                    },
                                    .tls_cert_path            = "DXKHDADNQDS",
                                }},
                                {"ep_41", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "RDVEHJVEVFRSZXYULARYAEICRVRMCYFXX",
                                        .port                     = 25145,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 79,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -7538.7369,
                                        .deadline                 = 30s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "QXOOXFSNEPACQJRRMACMQMTTECTQHUSFFLMYXLVFKPJEKZCMVLHMJQKWREJCY",
                                }},
                                {"ep_81", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "",
                                        .port                     = 9880,
                                    },
                                    .connect_timeout          = 2s,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 46,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 3874.6617,
                                        .deadline                 = 5min,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = std::nullopt,
                                }},
                                {"ep_9", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "WXICGSAGKQISKUS",
                                        .port                     = 18423,
                                    },
                                    .connect_timeout          = 10ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 9,
                                        .base_delay               = 25ms,
                                        .backoff_multiplier       = 3453.5903,
                                        .deadline                 = 5min,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "FFLSSRWFUVDBEFUT",
                                            .value                    = "UKCIDEHCXFMREHXSBSBIBFLLNBFV",
                                        },
                                        data::tag{
                                            .key                      = "XAVKKQPEICCOSRMVXIOMLUARET",
                                            .value                    = "EGEUFEGDARXX",
                                        },
                                    },
                                    .tls_cert_path            = "LQCUJQMIJETJTBBWOEKZKWKZGPWVZUVKDRIEUZQKLETSBVXKFNELDUPLGFOUC",
                                }},
                                {"ep_44", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "LWRXOMPFOFDXJRYETGNJNQGNMSCBQLOAHVYCKNFAJPVCKYKOQYKDFHSLY",
                                        .port                     = 35520,
                                    },
                                    .connect_timeout          = 200ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 69,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 2910.8182,
                                        .deadline                 = 10s,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "HVMCVTZSQABTNZMVAG",
                                }},
                                {"ep_10", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "LBPN",
                                        .port                     = 65413,
                                    },
                                    .connect_timeout          = 1min,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 51,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = -695.0623,
                                        .deadline                 = std::nullopt,
                                    },
                                    .tags                     = std::nullopt,
                                    .tls_cert_path            = "VLIDDPLVSFASLSTYOLDTVDKAKGVTQHOUQKGVEOKUCHYENMBMPWOBPRWA",
                                }},
                            },
                            .tags                     = std::nullopt,
                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                .scope                    = "DQDJBKMZEBLMGEIRYUNALYWYPJXVI",
                                .extra                    = boost::json::value_from("PPCFHKYLTNHIHLXVCOELXRIKJGRTRFEWFAMKMXO"),
                                .log_level                = data::severity::critical,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 31,
                                    .base_delay               = 25ms,
                                    .backoff_multiplier       = std::nullopt,
                                    .deadline                 = 1min,
                                },
                                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                    {"ep_14", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "VO",
                                            .port                     = 13197,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 75,
                                            .base_delay               = 2s,
                                            .backoff_multiplier       = -1645.1446,
                                            .deadline                 = 5s,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = "UHGNANQCYYFVGIFQ",
                                    }},
                                    {"ep_84", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "ENLDQONZZHOSOMUBLMJIVSLODPDLUKLUUPYQQEFASZMXBOOVDWYLH",
                                            .port                     = 47804,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 34,
                                            .base_delay               = 200ms,
                                            .backoff_multiplier       = 7504.5433,
                                            .deadline                 = 5s,
                                        },
                                        .tags                     = std::vector<data::tag>{
                                            data::tag{
                                                .key                      = "JQCVPLQPLLLUBJKSHJHXPPFTSHEPGNTTUKWHEJJQIHZJTSFJ",
                                                .value                    = "REOZQSAIMXEXRINHUDLKGENDGPDFHXZEYMWSJBKBZPHVUKUJIHMYWLSJUVDMKR",
                                            },
                                            data::tag{
                                                .key                      = "OTZFQRPFHFPFPIMVZDTBFCSAHWPSQOWXZZKSUOITLWHTBNHTF",
                                                .value                    = "LXALAV",
                                            },
                                            data::tag{
                                                .key                      = "JPZBEWJA",
                                                .value                    = "DUBVCRAOEDTR",
                                            },
                                        },
                                        .tls_cert_path            = "UROJZCASTBXDJAHCKDLJLBRFQYIQ",
                                    }},
                                    {"ep_46", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "QQAVUMY",
                                            .port                     = 60197,
                                        },
                                        .connect_timeout          = 50ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 81,
                                            .base_delay               = 10ms,
                                            .backoff_multiplier       = -8846.7972,
                                            .deadline                 = std::nullopt,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = "EZPJDSQSBXNAJGMTRSYYJJGAEPUDWEPYZIFDSEMGMBBKWKD",
                                    }},
                                },
                                .tags                     = std::nullopt,
                                .nested                   = common::box<data::scope_override>{data::scope_override{
                                    .scope                    = "EMFFXNVTUAIVFQW",
                                    .extra                    = boost::json::value_from("EEXPCQTUJMPRJGPRVWAKKHV"),
                                    .log_level                = data::severity::debug,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 69,
                                        .base_delay               = 1s,
                                        .backoff_multiplier       = 6389.0146,
                                        .deadline                 = 5min,
                                    },
                                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                                    .tags                     = std::nullopt,
                                    .nested                   = common::box<data::scope_override>{data::scope_override{
                                        .scope                    = "OSGBRBXVLJSGOASZKNINLAWOBJTYAMZBVAWMDXZOAUUFMXLNCGEWMP",
                                        .extra                    = boost::json::value_from("VBCRSSNVPUOTLDKFJSOJSUMTTPBWLOTUSGGJXYYINJTTISOVLPOICSZZQUUECM"),
                                        .log_level                = data::severity::debug,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 92,
                                            .base_delay               = 10ms,
                                            .backoff_multiplier       = 6533.4433,
                                            .deadline                 = 10s,
                                        },
                                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                            {"ep_10", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "SDFYGFEGQNGNHYSVRPMBZWTEGXZLOLBIROSWLVQSSKTFDCEVMJG",
                                                    .port                     = 19310,
                                                },
                                                .connect_timeout          = 10ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 91,
                                                    .base_delay               = 200ms,
                                                    .backoff_multiplier       = -329.8822,
                                                    .deadline                 = std::nullopt,
                                                },
                                                .tags                     = std::vector<data::tag>{
                                                    data::tag{
                                                        .key                      = "ONMMAMHODNFXQETUWRKNRAPNSWCKPBNJUHGFZBM",
                                                        .value                    = "PTYHOCZQFOVPDTQCDLABLSCODGXCTCFURDXBCJLPYJRZTGKXTLDBFLFWBKDY",
                                                    },
                                                    data::tag{
                                                        .key                      = "VYQMBELUDDREESR",
                                                        .value                    = "ZZUDAQPEYXKXTKJBHE",
                                                    },
                                                    data::tag{
                                                        .key                      = "KCTERFJBRSFLBYVSGBIPMOOTRYIVFNPJ",
                                                        .value                    = "AYDILUWWQVIMFFJAICVPVNMCISSSVBUC",
                                                    },
                                                    data::tag{
                                                        .key                      = "UPOVFNNAF",
                                                        .value                    = "SBJTAVPYSQFSYGACDFROYQHBABIKGXZSJYFFDJIWFTJIVKFGKNKRQDAMZFTQO",
                                                    },
                                                },
                                                .tls_cert_path            = "GWDJCLLNZYAMSIAUKBDJAMYSSIIDCOLAVEPMBMBSYZUGMAFAXFN",
                                            }},
                                            {"ep_48", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "ZLWIDFYKIZMBMQSBNYMU",
                                                    .port                     = 44035,
                                                },
                                                .connect_timeout          = 50ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 23,
                                                    .base_delay               = 50ms,
                                                    .backoff_multiplier       = -5714.2956,
                                                    .deadline                 = std::nullopt,
                                                },
                                                .tags                     = std::nullopt,
                                                .tls_cert_path            = std::nullopt,
                                            }},
                                            {"ep_65", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "WUISABOPMLSLQNNGJLTSLGDPCLXEUPKWDWTSXPIWROQIZGHVHXPDHDICKIJU",
                                                    .port                     = 52516,
                                                },
                                                .connect_timeout          = 100ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 18,
                                                    .base_delay               = 100ms,
                                                    .backoff_multiplier       = 4092.4711,
                                                    .deadline                 = 5s,
                                                },
                                                .tags                     = std::vector<data::tag>{},
                                                .tls_cert_path            = "JSMIHOOJCYUHWSNXNMJFIII",
                                            }},
                                            {"ep_3", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "IXZODMRFXRAEYKUUEBKMXOK",
                                                    .port                     = 53395,
                                                },
                                                .connect_timeout          = 100ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 12,
                                                    .base_delay               = 200ms,
                                                    .backoff_multiplier       = std::nullopt,
                                                    .deadline                 = 10s,
                                                },
                                                .tags                     = std::vector<data::tag>{
                                                    data::tag{
                                                        .key                      = "WGUCRQJSOHPGPARUXHKKHR",
                                                        .value                    = "CDKOPEBNNBCTWOCVEGMWE",
                                                    },
                                                    data::tag{
                                                        .key                      = "PAOTPAFTQFKKFLJPESBNCTDVDRRTCYJAIFKVDKGLHZEZKWRWXFVSLUAHFQFDI",
                                                        .value                    = "APNPHGBZGMDWIPTDLRJUCLFY",
                                                    },
                                                    data::tag{
                                                        .key                      = "QIDZBFXZOZOZIPIZEOZPNVGSHKOABWDQLSNCIZX",
                                                        .value                    = "VHCQKZLRGKPOZZZBTTWGNWUWOVLCJRVWVOZZZY",
                                                    },
                                                },
                                                .tls_cert_path            = "SRVQSLCZVNNDTVZQKMOEQW",
                                            }},
                                            {"ep_5", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "ZYFLNTFXLAZLBYFEAD",
                                                    .port                     = 63383,
                                                },
                                                .connect_timeout          = 5s,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 10,
                                                    .base_delay               = 10ms,
                                                    .backoff_multiplier       = -8188.2456,
                                                    .deadline                 = 2min,
                                                },
                                                .tags                     = std::vector<data::tag>{
                                                    data::tag{
                                                        .key                      = "MXCKGKJGVPBJZOQRDPZZVJMKCEEICBAFVBYWDGHNKTDMIKPFL",
                                                        .value                    = "LSUIMNWCFSKKEBEKFVWUQOFPZMLETPUDCAHA",
                                                    },
                                                    data::tag{
                                                        .key                      = "OBSPRAOVDWRAVUHQDMSQMXRCJWTHWAMBDHUQA",
                                                        .value                    = "RGKKLRMGXWICQVEDZWXCBHZBRMZONN",
                                                    },
                                                    data::tag{
                                                        .key                      = "XMHXXWNWWRWIANIBAWAQYUXRBWKKXDESZGSMSG",
                                                        .value                    = "LMTXGMUBKGWJMZGHTMZCMAKMTUFDBGFJDLVQUCBRDSUGTKXFABOSQDYPOAYUONE",
                                                    },
                                                },
                                                .tls_cert_path            = "YGNZOXHTAPQGGUIG",
                                            }},
                                            {"ep_84", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "CAXOEZFCYVHWPSINNR",
                                                    .port                     = 42345,
                                                },
                                                .connect_timeout          = 50ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 53,
                                                    .base_delay               = 10s,
                                                    .backoff_multiplier       = 5247.473,
                                                    .deadline                 = 5s,
                                                },
                                                .tags                     = std::vector<data::tag>{},
                                                .tls_cert_path            = "KOPWSZRJRWVYSHVUAMDLKYKFYTJSBFJDRIHNIYDSLMKSYFHKGDNIHEHX",
                                            }},
                                            {"ep_14", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "XAUZILV",
                                                    .port                     = 46329,
                                                },
                                                .connect_timeout          = 10ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 42,
                                                    .base_delay               = 10ms,
                                                    .backoff_multiplier       = 8850.6876,
                                                    .deadline                 = std::nullopt,
                                                },
                                                .tags                     = std::vector<data::tag>{
                                                    data::tag{
                                                        .key                      = "S",
                                                        .value                    = "MRRXZJGXEHNIBJ",
                                                    },
                                                    data::tag{
                                                        .key                      = "WDIVXPETRWRADVDPJYTAPVDHSJKWF",
                                                        .value                    = "UEADMDVDUGTZDTFMFQ",
                                                    },
                                                    data::tag{
                                                        .key                      = "LIEWBLYXLJFAUGYJHTRXFTTHYHITHCVS",
                                                        .value                    = "RZQKNHXVA",
                                                    },
                                                    data::tag{
                                                        .key                      = "RGYNIPMGKBOCBMCYCGVMOWCCEKVPLDBMO",
                                                        .value                    = "DAVLZASWXISIHGYKGYQWETPNHOMSJROFKPLXNBBAWUPUNTFLWICLMPTGCGRG",
                                                    },
                                                    data::tag{
                                                        .key                      = "EXBJYJYIVYEUSWFDSQZUEQYSDZDDUXKXTNCVNEFZNEHEAHSPPEB",
                                                        .value                    = "UH",
                                                    },
                                                    data::tag{
                                                        .key                      = "BKNTYOUTC",
                                                        .value                    = "KTPTZYSVTMTGIXWNAIRJLQMSTBRFED",
                                                    },
                                                    data::tag{
                                                        .key                      = "ZTBKHEBKZAQWOQJXJTEDVPILBESGZRIKZGLMREAVSWJIINEZNYFZTY",
                                                        .value                    = "MTJAZWSTBPRNKLFZMQRLQUNAIQQBGQBYDFLPMWCXAIHZHLNWVGXRZV",
                                                    },
                                                },
                                                .tls_cert_path            = "RDLAFMARSXTDTOWGPCOUDGXQ",
                                            }},
                                            {"ep_43", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "IGFGKDIGXCJYWJOJFMDRLMYQUFCAZBZ",
                                                    .port                     = 10464,
                                                },
                                                .connect_timeout          = 100ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 35,
                                                    .base_delay               = 10ms,
                                                    .backoff_multiplier       = 1573.1522,
                                                    .deadline                 = 30s,
                                                },
                                                .tags                     = std::nullopt,
                                                .tls_cert_path            = "CAILUMDATD",
                                            }},
                                            {"ep_61", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "NTJQLXGY",
                                                    .port                     = 3847,
                                                },
                                                .connect_timeout          = 10ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 37,
                                                    .base_delay               = 5s,
                                                    .backoff_multiplier       = 4703.7036,
                                                    .deadline                 = 5s,
                                                },
                                                .tags                     = std::vector<data::tag>{},
                                                .tls_cert_path            = std::nullopt,
                                            }},
                                        },
                                        .tags                     = std::vector<data::tag>{
                                            data::tag{
                                                .key                      = "SLWDZDKNVDSCLYCJJIQXWEKZUIQXWYGDKDAQPKRTMQOPQS",
                                                .value                    = "RPDRADJHDMKENNJWBPXLKNTRNRMKTEIRFNYGAYAXEVKZVBREPMQRWFZXBPCW",
                                            },
                                        },
                                        .nested                   = common::box<data::scope_override>{data::scope_override{
                                            .scope                    = "OGHBDPFVXBQRXLWSFIBBQCOJKXULUNQWKWSVYPYXEUANRVSWE",
                                            .extra                    = boost::json::value_from("N"),
                                            .log_level                = data::severity::error,
                                            .retry                    = data::retry_policy{
                                                .max_attempts             = 46,
                                                .base_delay               = 100ms,
                                                .backoff_multiplier       = std::nullopt,
                                                .deadline                 = 5s,
                                            },
                                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                                {"ep_19", data::endpoint_config{
                                                    .address                  = data::network_address{
                                                        .host                     = "BUNAUJTSPOHAHFEKJJJGEXLYQVZYOHYDOTLDHAVQUNFGQYBOLS",
                                                        .port                     = 44928,
                                                    },
                                                    .connect_timeout          = 10ms,
                                                    .retry                    = data::retry_policy{
                                                        .max_attempts             = 61,
                                                        .base_delay               = 25ms,
                                                        .backoff_multiplier       = -1011.3764,
                                                        .deadline                 = std::nullopt,
                                                    },
                                                    .tags                     = std::vector<data::tag>{},
                                                    .tls_cert_path            = std::nullopt,
                                                }},
                                            },
                                            .tags                     = std::vector<data::tag>{
                                                data::tag{
                                                    .key                      = "THQEDZUWEBGDFPVKQHVHHDZUMGSH",
                                                    .value                    = "ASPFYUDWFQDHWBPGUQKLMHHKEZHYBXCEGYHCPJVMBZQQIKJJE",
                                                },
                                                data::tag{
                                                    .key                      = "NEDSFWIASMFLNHKGXFWASSCLISRKKHVSZQSMYMFHKA",
                                                    .value                    = "WOXVJKAETSEBUQBQQZMRCZNVXPXJHPCOFLCNKAZRDOOEGPQYPTAASWFEFIFAK",
                                                },
                                                data::tag{
                                                    .key                      = "QINGHDJTQWYUNLHBWFKADODDTUJZRTSVPMVPSZJDDUIVPSDVWSPZ",
                                                    .value                    = "AURUTUSIFCWBYOEF",
                                                },
                                                data::tag{
                                                    .key                      = "BSKPBHXYD",
                                                    .value                    = "BMDAAZPLP",
                                                },
                                                data::tag{
                                                    .key                      = "IVSALDULEJYLSFDLBZOEKVHZUICNEYJWWOEB",
                                                    .value                    = "QFVGDVYFRWPZGBBNNAMOTJDYHDS",
                                                },
                                                data::tag{
                                                    .key                      = "AYTGVJZQNGGKHF",
                                                    .value                    = "OVNWMWYOZMYIUGOBCPSKJCZMBTOPWXLXIGI",
                                                },
                                            },
                                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                                .scope                    = "QTNMROBCCZYPMRTIPS",
                                                .extra                    = boost::json::value_from("GEMSBHTIHQSJLMDK"),
                                                .log_level                = data::severity::error,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 80,
                                                    .base_delay               = 1s,
                                                    .backoff_multiplier       = -4490.6281,
                                                    .deadline                 = std::nullopt,
                                                },
                                                .endpoint_overrides       = std::nullopt,
                                                .tags                     = std::nullopt,
                                                .nested                   = common::box<data::scope_override>{},
                                            }},
                                        }},
                                    }},
                                }},
                            }},
                        }},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "",
            .port                     = 52163,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
