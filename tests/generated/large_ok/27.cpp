#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_27)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/27.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "WIJGCCIRKILMFHHPCXUSUCTNYNXBVOLAUPIETKTUH",
        .worker_threads           = 180,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "BYVQCFOWEIRBFUAOYELSSNCJOOLALFZIFPLQBQHFGYXPRCK",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "KUD",
                            .port                     = 19790,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 69,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -4304.6898,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "VDASBLZGJWTDBRNNXOXAFLXATGHMGXKMCL",
                    },
                },
                .min_log_level            = data::severity::debug,
                .alerts                   = std::map<std::string, data::threshold_rule>{},
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 14,
                    .base_delay               = 25ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 10s,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"ROGN", data::routing_rule{
                .pattern                  = "VGQZEWWKSWBHDPTTTWCHNKJBEDMCLGFYRXWAFOBSTQOTBHIRGDR",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 10ms,
            }},
            {"WGFAL", data::routing_rule{
                .pattern                  = "GXKMPKCHTCSYXBW",
                .backend_names            = std::nullopt,
                .timeout_override         = 1s,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"JVS", "WKWQRMKTCPLLXPJZPGTZUHQXTRHHXLDJWJUFYMPINIAFDQORBYBOHZ"},
            {"DE", "JRZWSNTIIRBFUBYOXDCYHZRKVUEDXYAXHARIPKXANUCRALJVD"},
            {"ZEFARJ", "UXBLWSDPUEKOKIXXGSKIGYNQORECNUN"},
            {"MKNNFC", "VNYGYXE"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("KXFIKCDCPFNAQRAAUUFIQWPAJVZZPDPRWNRMSMKKRHAXIAVTVOANFYVQMBH", 72155, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "GTEEQWPGAYPROPGCTMFGXPXIHJOTQNBPMOS",
            .extra                    = boost::json::value_from("GDJIXQZTEWBDDLONRRPMHNEVJCWOUINZPWVWBQBRYW"),
            .log_level                = data::severity::debug,
            .retry                    = data::retry_policy{
                .max_attempts             = 77,
                .base_delay               = 10ms,
                .backoff_multiplier       = 1789.8392,
                .deadline                 = 10s,
            },
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "NZVTRWVDOUHPANGTBSXMRKWCZQISWUYJTPLHNXDLGGM",
                    .value                    = "PBHZBXKPZB",
                },
                data::tag{
                    .key                      = "EDPNBYDHNLMQPOVURVAYWQMDJVWUYSMAOJVYGZVHKDRPXDKCDNOOGZFECV",
                    .value                    = "RSWXHAETHYIQUTUQYEGKCDCIECDFXVFQGJSBKCFXDARYFH",
                },
                data::tag{
                    .key                      = "D",
                    .value                    = "KUJZMMEPYLNMIMUMHMTXWBAOIHTEFSDPWVXFXXCLYVKAZOICQ",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "OHUZQVJHOHSHQQQEXUHOFQESDNTYHNFL",
                .extra                    = boost::json::value_from("QEAAARJCFPMXGJQGJYJIDMKTTWSWGTO"),
                .log_level                = data::severity::debug,
                .retry                    = data::retry_policy{
                    .max_attempts             = 91,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = -800.004,
                    .deadline                 = 5s,
                },
                .endpoint_overrides       = std::nullopt,
                .tags                     = std::vector<data::tag>{},
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "AABSRENSGKHTHGTFFDUWHSCZW",
                    .extra                    = boost::json::value_from("PR"),
                    .log_level                = data::severity::error,
                    .retry                    = std::nullopt,
                    .endpoint_overrides       = std::nullopt,
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "EEXYXBQVNNXZRNGUYRHSGRSEUPUHVCWLTGJNVCXGPCXMQZNKDXPSQTNYZ",
                            .value                    = "RMSUGGHKIY",
                        },
                        data::tag{
                            .key                      = "BLRFYQSKVVXNDORBEOXJJXNNACURJLD",
                            .value                    = "LEJASOYPPCBFNE",
                        },
                    },
                    .nested                   = common::box<data::scope_override>{data::scope_override{
                        .scope                    = "CRHQBBAHNHQXI",
                        .extra                    = boost::json::value_from(""),
                        .log_level                = std::nullopt,
                        .retry                    = std::nullopt,
                        .endpoint_overrides       = std::nullopt,
                        .tags                     = std::nullopt,
                        .nested                   = common::box<data::scope_override>{data::scope_override{
                            .scope                    = "WDSIHIYOQHPEHFPZCLZPURXWUAKRASHMYGLZXXTIBZFLEZGJC",
                            .extra                    = boost::json::value_from("VDXCDGEKAFHJJPZSFUEYXDDXMKSVORAZHVVCKLQRTEEBWZTXAPHYCUCR"),
                            .log_level                = std::nullopt,
                            .retry                    = std::nullopt,
                            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                {"ep_68", data::endpoint_config{
                                    .address                  = data::network_address{
                                        .host                     = "DIJMWUFFMMTFZXYLSSRBPZNFSILOEWOQOGHOPG",
                                        .port                     = 27223,
                                    },
                                    .connect_timeout          = 50ms,
                                    .retry                    = data::retry_policy{
                                        .max_attempts             = 94,
                                        .base_delay               = 10ms,
                                        .backoff_multiplier       = 9039.9947,
                                        .deadline                 = 30s,
                                    },
                                    .tags                     = std::vector<data::tag>{
                                        data::tag{
                                            .key                      = "CWPVACKLLTZHKWHWLBCROBJZEUACRAZEGHTVVVNJZLBGOERL",
                                            .value                    = "AKNFTCBUZNQMVRXO",
                                        },
                                    },
                                    .tls_cert_path            = "GWFOEXOHCQFNPEITWXVCSOEZOZJDZVOLKFCOBYONFFKEMUX",
                                }},
                            },
                            .tags                     = std::vector<data::tag>{
                                data::tag{
                                    .key                      = "LYAOQJMTJWQDGEU",
                                    .value                    = "ROY",
                                },
                                data::tag{
                                    .key                      = "GEDBFLLLCGMPWFUVJOEODBLBHOLGEIVWFCOQTXKNTZOZNKKKMGMUYZIPHNKPA",
                                    .value                    = "UTYIENHRCWFEMEZHAHYSFEZPGRANZKHKJGDIDBEXSMVQXUCXHZTJQFXMSDNT",
                                },
                                data::tag{
                                    .key                      = "TVLWRONSBPLNYPHPOBDKZJGRYPPNPVOFWTMLKHXGDMEIWUXMJLNSWURY",
                                    .value                    = "IMAJNEYOUXJAIHONFPUUIMVHTFSDA",
                                },
                                data::tag{
                                    .key                      = "EXVPAPUJUZGYRVXSXLC",
                                    .value                    = "KDWMCCJLHAHKBKPXQTZOFUSLUXRJVCCGIAKJZSNUVVGTROHXBAUHJBPUM",
                                },
                            },
                            .nested                   = common::box<data::scope_override>{data::scope_override{
                                .scope                    = "KLHRBGGLQJA",
                                .extra                    = boost::json::value_from("NOEHGYQJPLKLBCNUMSAHZCZXHLS"),
                                .log_level                = data::severity::critical,
                                .retry                    = data::retry_policy{
                                    .max_attempts             = 2,
                                    .base_delay               = 25ms,
                                    .backoff_multiplier       = std::nullopt,
                                    .deadline                 = std::nullopt,
                                },
                                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                    {"ep_57", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "EMARXPZXQUVZVZBUIJQIOROQKFSCGKXNXKFLENQDKBUBWELTWRXZHNOXOXLND",
                                            .port                     = 45838,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 39,
                                            .base_delay               = 10ms,
                                            .backoff_multiplier       = -9914.71,
                                            .deadline                 = 30s,
                                        },
                                        .tags                     = std::vector<data::tag>{
                                            data::tag{
                                                .key                      = "KPHFJAQWSNHMJXWASGKCISMXMPPSQPUADGRCTIMPLQHYTCCECJZOULTSDDESP",
                                                .value                    = "PIZYXWCHINSWUKKXGQPCEATGQBUSGSLHQSCVAO",
                                            },
                                            data::tag{
                                                .key                      = "FWXSULZXMCANFKO",
                                                .value                    = "TPVIWMVYWDTRHBAJRMCNFLRXONTCNMZEAXP",
                                            },
                                            data::tag{
                                                .key                      = "YTAUIZEWHTQGVDZORIIQI",
                                                .value                    = "HVNDCZFQ",
                                            },
                                        },
                                        .tls_cert_path            = std::nullopt,
                                    }},
                                    {"ep_73", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "QLRBMDRNVULEAGHIDOOCBOKTNRVTDORFZMAKCV",
                                            .port                     = 41558,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 93,
                                            .base_delay               = 500ms,
                                            .backoff_multiplier       = 7448.9606,
                                            .deadline                 = 2min,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = "HBSBEDISZDKBIHVFZACIHUDSLGGUNGPCXJAISWKWAUMUKKYAN",
                                    }},
                                    {"ep_39", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "HZUNHPHGBKOICUKAYLBCZVTZUEGXVI",
                                            .port                     = 32498,
                                        },
                                        .connect_timeout          = 2s,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 61,
                                            .base_delay               = 2s,
                                            .backoff_multiplier       = 2118.5545,
                                            .deadline                 = 1min,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = "FJXAICTTUWUTTLRLTPUCPSUUFQWGLQPQATBCOLUXOYVANJGUBMGEOPH",
                                    }},
                                    {"ep_13", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "RHFAPSPQYVWY",
                                            .port                     = 29779,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 90,
                                            .base_delay               = 1min,
                                            .backoff_multiplier       = -8519.7158,
                                            .deadline                 = 5s,
                                        },
                                        .tags                     = std::vector<data::tag>{
                                            data::tag{
                                                .key                      = "TYUQYXWWIZNBWCBISVHQFOEFIPOACJNZGHTRY",
                                                .value                    = "P",
                                            },
                                            data::tag{
                                                .key                      = "AHFXNFCESDDIDLGUCWSLDNFNVVQM",
                                                .value                    = "",
                                            },
                                            data::tag{
                                                .key                      = "OGBQXTLXMBTAIDGBOZXYTTGOAEJWWYYZJXCTALCMG",
                                                .value                    = "QVCHHWJT",
                                            },
                                            data::tag{
                                                .key                      = "LQILLQOQDYMCJUFCHXFRZZWOOMILYLMBSAZICIHQGYZSIDIRXTZIPON",
                                                .value                    = "KNOLPCUZVFNKOYAFGWPUAAFOHBJ",
                                            },
                                            data::tag{
                                                .key                      = "EVXZXYJCQUNCXMKCTJVHDBIIJLPWPJMTNPFHLPMOCUE",
                                                .value                    = "ETIGD",
                                            },
                                            data::tag{
                                                .key                      = "KWXUBGHRGQEYSLLUDJPPLZGERJDXYHXFNGLKZRZHRNPQGYICOGDBFXLADPFH",
                                                .value                    = "JOXROHZZCRKKAGDAZHPHZQPUQWGUGTAFV",
                                            },
                                        },
                                        .tls_cert_path            = "PNIUZKTRCUZIBHYRJZTVSQXOCPAKSUSADSPTSCZUHYEROKVZBSXZWHARZ",
                                    }},
                                    {"ep_94", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "GTDLFGBJWTANDLTWGVXWKNFKOCYFXVLG",
                                            .port                     = 52717,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 78,
                                            .base_delay               = 10s,
                                            .backoff_multiplier       = 1819.8626,
                                            .deadline                 = 30s,
                                        },
                                        .tags                     = std::nullopt,
                                        .tls_cert_path            = "WWVTAQGOOJRXNTBRTRFVZYIHJHRGWQEMDZAXYDGSGTFGMWDKAFC",
                                    }},
                                    {"ep_2", data::endpoint_config{
                                        .address                  = data::network_address{
                                            .host                     = "IQPWWUCQCQYYNMXKWXQGJOJELCGOWYNMCKWUGOEP",
                                            .port                     = 36783,
                                        },
                                        .connect_timeout          = 10ms,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 29,
                                            .base_delay               = 200ms,
                                            .backoff_multiplier       = std::nullopt,
                                            .deadline                 = 2min,
                                        },
                                        .tags                     = std::vector<data::tag>{},
                                        .tls_cert_path            = "GBWEXKAUAJCIKNBZROTOHZVOHLUBXPJJBKDRJSKKJPYHZFAWWQZMPEYHRTCUBT",
                                    }},
                                },
                                .tags                     = std::nullopt,
                                .nested                   = common::box<data::scope_override>{data::scope_override{
                                    .scope                    = "UCMUTRLIXVNEJALPRJINSNE",
                                    .extra                    = boost::json::value_from("OHNYKIJXVAUNTPJGIRDHRASTYSJDKCZEBGLNQ"),
                                    .log_level                = data::severity::error,
                                    .retry                    = std::nullopt,
                                    .endpoint_overrides       = std::nullopt,
                                    .tags                     = std::nullopt,
                                    .nested                   = common::box<data::scope_override>{data::scope_override{
                                        .scope                    = "CJWXLXJCUEVJCPDKKXUXGRUBWMKK",
                                        .extra                    = boost::json::value_from("YJXAQQCKQKM"),
                                        .log_level                = data::severity::debug,
                                        .retry                    = data::retry_policy{
                                            .max_attempts             = 9,
                                            .base_delay               = 25ms,
                                            .backoff_multiplier       = -3888.7128,
                                            .deadline                 = 10s,
                                        },
                                        .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                                            {"ep_43", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "LLCPVDXEOEVIQKVALJLUKFXBVCOLWD",
                                                    .port                     = 18978,
                                                },
                                                .connect_timeout          = 10ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 21,
                                                    .base_delay               = 1s,
                                                    .backoff_multiplier       = -4082.716,
                                                    .deadline                 = 5s,
                                                },
                                                .tags                     = std::vector<data::tag>{
                                                    data::tag{
                                                        .key                      = "RSQTSBKXXGDWWNVHZEITOPR",
                                                        .value                    = "CAJRJDDETRYBEFBR",
                                                    },
                                                    data::tag{
                                                        .key                      = "HCTFTZPEHTD",
                                                        .value                    = "FRUSNYSKPPT",
                                                    },
                                                    data::tag{
                                                        .key                      = "SZHYSXE",
                                                        .value                    = "QOFICDAKWQHHSYVWJFTPMBHBPRFPAAXTNKOJLJLGKKEX",
                                                    },
                                                    data::tag{
                                                        .key                      = "QRVGXGOUTOWCWQTEANICUSJCLRFXOMUDPY",
                                                        .value                    = "RQGLRKOKLWSD",
                                                    },
                                                    data::tag{
                                                        .key                      = "KMFZN",
                                                        .value                    = "FOSWT",
                                                    },
                                                    data::tag{
                                                        .key                      = "YHESKOEKBFEZOBZMCJARXOLCRZCJID",
                                                        .value                    = "POLMDJFXLEFHLVDPWIIGPQRUMSDCIPGLWCMXXUOMEPDAK",
                                                    },
                                                    data::tag{
                                                        .key                      = "XSLKKDODWTOVSYSMN",
                                                        .value                    = "YIWONXVPSCONQVJFCTLNU",
                                                    },
                                                    data::tag{
                                                        .key                      = "NX",
                                                        .value                    = "DYYXDGAVZDVHTKQRPURWZYXW",
                                                    },
                                                    data::tag{
                                                        .key                      = "EFCVRYXUWOGHYZAIADFJIIKLJCG",
                                                        .value                    = "RSRSNAOIJZUYMQDSZEBAKFYVYKMAUNTJRAPTECZVJUDOZEUG",
                                                    },
                                                    data::tag{
                                                        .key                      = "PXNHOSGRHOZOXCFBOTLOXWUZFFFDOACZUDVYVHVHHCZOKHLWXGDSZJQYIQD",
                                                        .value                    = "NYLOMRHTIYBSHHFDYIKOHPIXRTFQVNQPIXBRISAVEJP",
                                                    },
                                                    data::tag{
                                                        .key                      = "GXCIXOHDLCFGUNUEDXVZKOQZ",
                                                        .value                    = "IUFDRO",
                                                    },
                                                    data::tag{
                                                        .key                      = "UMAATZRABCKFUNJNJRBPQLIQUTCCE",
                                                        .value                    = "UDAAPJTO",
                                                    },
                                                },
                                                .tls_cert_path            = "ZYC",
                                            }},
                                            {"ep_78", data::endpoint_config{
                                                .address                  = data::network_address{
                                                    .host                     = "ECSSOJHZGIJYYCPYTDDVOTGYXORLPPCB",
                                                    .port                     = 42362,
                                                },
                                                .connect_timeout          = 10ms,
                                                .retry                    = data::retry_policy{
                                                    .max_attempts             = 3,
                                                    .base_delay               = 10ms,
                                                    .backoff_multiplier       = -3248.2555,
                                                    .deadline                 = 2min,
                                                },
                                                .tags                     = std::vector<data::tag>{
                                                    data::tag{
                                                        .key                      = "XAERUZHUMSCMEUHTZNSVHOQZQXCLSFORYGWSFEYGQN",
                                                        .value                    = "QXZRMNKVFUVWUJPQHOAZAEBIMBNKNJC",
                                                    },
                                                    data::tag{
                                                        .key                      = "JPQZJHKKFODZMXESFSMKKCIBMUTKXOMADWWHDGRYVHEAQASAPPFXHIMSMOCROG",
                                                        .value                    = "UQGSQBJL",
                                                    },
                                                    data::tag{
                                                        .key                      = "DNFIGG",
                                                        .value                    = "J",
                                                    },
                                                    data::tag{
                                                        .key                      = "CBLVVGPETFPWMLXBOPRDYQQMLCRFGKOUAZXVF",
                                                        .value                    = "FONHZWVHO",
                                                    },
                                                    data::tag{
                                                        .key                      = "CQGVWOSMFAUHCZFLIRFZWJNQVEMGPLHTRNPADIJNTGAWYAWAWRY",
                                                        .value                    = "GKJGWEQGKRKJFJJDZZSYNBKHAXCLOOPRWVDKZOSJAZO",
                                                    },
                                                    data::tag{
                                                        .key                      = "CZWXE",
                                                        .value                    = "",
                                                    },
                                                    data::tag{
                                                        .key                      = "PRQGUPYAFGYYGANQXRLXNZAVRTCSGIXTBVTGZBMRCIDNICKSSLSNSEZXOVEI",
                                                        .value                    = "NYEAKDTNBLDRZKYNWVNGHSPXEMDJ",
                                                    },
                                                    data::tag{
                                                        .key                      = "TIJJOPD",
                                                        .value                    = "SJOMPMAEHRNRXCEGUKIPOFPAMDBMRTNXRSWEOUNWNWUZMXOAWIU",
                                                    },
                                                    data::tag{
                                                        .key                      = "IQSRWLHMKHBKYOKHXLLMCXGBH",
                                                        .value                    = "LWYUNGIOQRSZ",
                                                    },
                                                    data::tag{
                                                        .key                      = "JOFHSNSLUGFGSQDDTBB",
                                                        .value                    = "",
                                                    },
                                                    data::tag{
                                                        .key                      = "WLCIFCSSQDDAQUQNAMDAGICQYGFW",
                                                        .value                    = "TENTIZLAPLIWHSATQOTYPAKNEKXMPXFCBGWNVCQUMCQQNUHQYILADTUWKJBE",
                                                    },
                                                    data::tag{
                                                        .key                      = "FDNMUEA",
                                                        .value                    = "GVNYDCVONMFBMYRRDMFKHEUXPKDBVWCPEMPRQYERTMNEJW",
                                                    },
                                                    data::tag{
                                                        .key                      = "XSGWYFILNW",
                                                        .value                    = "LDEILKIZUIOGLXDWBKCY",
                                                    },
                                                    data::tag{
                                                        .key                      = "YPCNAGVIAMBAIWTEKTGJFFHRDQPGLOCJAGEAEVBMTCYYKQSANIYMPZCIZJ",
                                                        .value                    = "XSHEUTUIMOGYYYPWNFCHAFCIOT",
                                                    },
                                                    data::tag{
                                                        .key                      = "XRIEYUDXHCZECWTFHMXIESLMRCEUDCJUZQFGJOWCAMFAMRQNIXBPXBOC",
                                                        .value                    = "KFGNRCAKVVAKLMGKFJDYDBUGHQAFGAV",
                                                    },
                                                },
                                                .tls_cert_path            = std::nullopt,
                                            }},
                                        },
                                        .tags                     = std::vector<data::tag>{
                                            data::tag{
                                                .key                      = "FVP",
                                                .value                    = "APBMNLIZSCUPLOWYHGSFXGQHVYWUSBSORPRMFKXIGKAWPPQUOVYIWOUNNKWMGRP",
                                            },
                                            data::tag{
                                                .key                      = "NYMOHPJTSFBEQSIHXBSDEVBPAAGCYSSCOOZWXJNZPXPXTKZTDBDKXLUEH",
                                                .value                    = "YOVOJSMXWJMNDJTYPVVUGPUVZJRUVFIKRCPFUHWKYWMFEZCSF",
                                            },
                                            data::tag{
                                                .key                      = "BOYUNIPZMLRFURRGUGDPDSJEZPHCDBPBWLUCUXVFKXXCWUNKKYDTOZWJXEA",
                                                .value                    = "NCNMZYQOKNRVVYSWPZQUKSPMIDH",
                                            },
                                            data::tag{
                                                .key                      = "UHJVNWQNJPUHXTVXPXXVWLRZBPDNLKT",
                                                .value                    = "KJRMYEKQEQNEUSI",
                                            },
                                        },
                                        .nested                   = common::box<data::scope_override>{},
                                    }},
                                }},
                            }},
                        }},
                    }},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "OKHODTWRRKKFPBSTINEUMELJUPYZOEJIKCMDUYNSELYIMRUGISFCSWGUIPVDC",
            .port                     = 44279,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
