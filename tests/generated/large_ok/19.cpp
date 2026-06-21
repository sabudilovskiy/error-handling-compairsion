#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_19)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/19.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "ZQDQGMLQJSETIDINKIDYKJASTGCGDROMXCZDNADSXNY",
        .worker_threads           = 218,
        .enable_tracing           = true,
        .shutdown_grace_period    = 10min,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "UNHYRSXDZG",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "UPDRWOAO",
                            .port                     = 59368,
                        },
                        .connect_timeout          = 50ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 52,
                            .base_delay               = 1s,
                            .backoff_multiplier       = -1433.9972,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "ODVWUIEPJOMJXFOOJJVYBCGJVYNDO",
                                .value                    = "QOVA",
                            },
                            data::tag{
                                .key                      = "CCEFNJODGTPVZCNUUEAMTUJUBSRSLIGIQKBAYIUGC",
                                .value                    = "QOYQEKZQZIRW",
                            },
                            data::tag{
                                .key                      = "UXVQJUQSNPBHEBODQSDIWOWMVKKLFOKXDUVVQONTBLCKNLOSXLBJIICHMBFFP",
                                .value                    = "RDWTQCBSNBWVETKHRXRBIGEHJDSOECWOJRMSHLXZDV",
                            },
                            data::tag{
                                .key                      = "ORHROJBS",
                                .value                    = "ODGTCPEMQIPLOBQNASHVJRHDZMNUEWRHEOFWTPCIYMOSCSVAXHCIHP",
                            },
                            data::tag{
                                .key                      = "IONZAEDFNZAITZPTKHJFYCRJADCBVYCRO",
                                .value                    = "BCMW",
                            },
                            data::tag{
                                .key                      = "KIEDTBBLFDUKPLIWUODRUZS",
                                .value                    = "TFIYSMKAGRPZC",
                            },
                            data::tag{
                                .key                      = "PHVTFFFUMFWRCZGIDFUPQQNGRCTQNLTGKQEUVSGABWIJWN",
                                .value                    = "WWRCWUMQASTUVOSIQVSIYOMYSKDPE",
                            },
                        },
                        .tls_cert_path            = "MEBWYMTGHZDXCLVEPMLUDQSPBERAVPFKPO",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "ZJKJQPMJTMMVAZHRX",
                            .port                     = 13235,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 19,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = -9314.3517,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "LRMNOPZYCCYSLZLEGJELIQMPKFKLSQ",
                                .value                    = "OI",
                            },
                            data::tag{
                                .key                      = "UCOCKPBQETSGLERTMOIVKFRZWZRHPVAFYXZOSGKIYYTJALNEKQEVFRDOXBIL",
                                .value                    = "JWIIVERCLTQLZAZV",
                            },
                            data::tag{
                                .key                      = "OFPOHKPJBQHLDLOCVHOOXTEDIZXNMVYXNSFYDDKDGKYQEZZVET",
                                .value                    = "RPJKYHVEOPPUYARZDTUENUYNQBQVCQCRGKRRKWSZLFNHGVFMROFZTP",
                            },
                            data::tag{
                                .key                      = "OWSTHXODUAPHUXQEVLLLAOJFPTKO",
                                .value                    = "GJDZHOPQRNLLKSEQXDTPHPLAFSGCZMMNALFCVBLVZHSPMLQDJ",
                            },
                            data::tag{
                                .key                      = "WAVOI",
                                .value                    = "DKXJECIXGJXDRDRPJRQXCRP",
                            },
                            data::tag{
                                .key                      = "T",
                                .value                    = "GZVYVTUJNZWPWDBXGA",
                            },
                            data::tag{
                                .key                      = "ZJJOLVRJLIGCMONWECGTNUGOPDTLANMSXESJFD",
                                .value                    = "EQJZOEYEEGMPKPIJVLHVQWHUYMWHUHKFKULLMSNGSDUJEJYKKFHDTGHRN",
                            },
                            data::tag{
                                .key                      = "GYSWKBSBXUKRSQLJJGPFXELAWOH",
                                .value                    = "ZKYUESVJXMXLVTEMNIAIRZTXIQSDCCGBRRORKMUUFGLEFINTUVDK",
                            },
                        },
                        .tls_cert_path            = "CAPPTVGPFOFOQFUSMWRLRGZNOHFYUGEJOAIQWEPICVEJWN",
                    },
                },
                .min_log_level            = data::severity::warning,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"MRSGZH", data::threshold_rule{
                        .metric_name              = "VZQMFHWFFGJYVYEIELVJCQKOOFFXXQIY",
                        .warn_at                  = -5778.4288,
                        .crit_at                  = 6981.073,
                        .evaluation_window        = 5min,
                    }},
                    {"RHV", data::threshold_rule{
                        .metric_name              = "QTMUAACPFJZMJBEIVNDEXNNKUQLRDAPJXEIHLJONODOFUFVARHQIGNDAOUOOM",
                        .warn_at                  = -8651.9748,
                        .crit_at                  = -4663.56,
                        .evaluation_window        = 10s,
                    }},
                    {"OC", data::threshold_rule{
                        .metric_name              = "OXZXHKFSYOGGAIWUEWLEH",
                        .warn_at                  = 2769.5875,
                        .crit_at                  = -200.4017,
                        .evaluation_window        = 5s,
                    }},
                    {"NSGF", data::threshold_rule{
                        .metric_name              = "RMZRKWQNDSKTSKOMOEEPATZNCQXB",
                        .warn_at                  = 6680.4693,
                        .crit_at                  = 7119.2655,
                        .evaluation_window        = 5s,
                    }},
                    {"JD", data::threshold_rule{
                        .metric_name              = "K",
                        .warn_at                  = -741.6489,
                        .crit_at                  = -2610.2251,
                        .evaluation_window        = 5s,
                    }},
                    {"KVWHKK", data::threshold_rule{
                        .metric_name              = "WPDKQJWHALQXANPBJANOLYFEMTRHIKZTZEBRSWAPPAOUTCYBKW",
                        .warn_at                  = 3359.9152,
                        .crit_at                  = 9736.2739,
                        .evaluation_window        = 5min,
                    }},
                    {"TND", data::threshold_rule{
                        .metric_name              = "RXUFJIWFXZTGEHMDIOHFNUQHWZQPPIOWEFHIJRFFUNYYK",
                        .warn_at                  = 4145.2737,
                        .crit_at                  = -7149.4489,
                        .evaluation_window        = 5s,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 53,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = std::nullopt,
                    .deadline                 = 10s,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"MYSN", data::routing_rule{
                .pattern                  = "N",
                .backend_names            = std::vector<std::string>{
                    "CDELUERCOKYWDAPRQQOXFNWQBPGWILYVLSIYTYSJBNZUUGJCQJVJDNYUO",
                    "IXJWTWNMFBUDRAGSXEK",
                    "GXETBXL",
                    "EEURLNDDDQOZIKHYKZMWQNINSSZEMJCWUQPFPXDYZZNTSAMNPUGQCTLZXSZQQFK",
                    "IFEHDSUUSYPAPZRJFXGZAJZTPYVYJ",
                },
                .timeout_override         = std::nullopt,
            }},
            {"JSUXUN", data::routing_rule{
                .pattern                  = "UNEYBAWYWSURIXOEUHSWXFDXNWHFNACNY",
                .backend_names            = std::vector<std::string>{
                    "USUEMRHS",
                },
                .timeout_override         = 100ms,
            }},
            {"TI", data::routing_rule{
                .pattern                  = "BJITSQXGGNYWOVZNEGJPXXPNULHNRTSFCBEASSZRKNYWNLIYAOXEJNTYS",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 500ms,
            }},
            {"DJ", data::routing_rule{
                .pattern                  = "HKDJSVWCHSMIBYYVHJALSIJBGPXNCZSAAIFY",
                .backend_names            = std::nullopt,
                .timeout_override         = std::nullopt,
            }},
            {"KZERA", data::routing_rule{
                .pattern                  = "IOAKISSFIYHOJAWKYFRVRSSBSVDMFLVQENSNWGNOPYJPQWU",
                .backend_names            = std::vector<std::string>{
                    "BWOYOVJHAZZXISCWMRBWTFFBLGIZLN",
                },
                .timeout_override         = 10ms,
            }},
            {"LMYM", data::routing_rule{
                .pattern                  = "EQ",
                .backend_names            = std::vector<std::string>{
                    "S",
                    "USWUBUYUIUOZVCDOBKCQ",
                    "MBKKOOCXCONZEEWZZDJXPCZOEPN",
                },
                .timeout_override         = 10ms,
            }},
            {"IEUTSY", data::routing_rule{
                .pattern                  = "PCEFZPUFJEFBPPRDZUWJCRLVYHIVEYCJMEORXVDVGFYPWGOOIBGDJEPMOW",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 50ms,
            }},
            {"DLASB", data::routing_rule{
                .pattern                  = "XXSWZEDRPDXRGQCNOFRDWFHDACZCQCBE",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 10s,
            }},
            {"YEI", data::routing_rule{
                .pattern                  = "VNLHRBHRQVFFCEGWEPCMLSHJSMPFUOBSTQERFXWLNJTXXYB",
                .backend_names            = std::vector<std::string>{
                    "YXPTFVZRTSQBONIRNUFFOZTTECHVDGFYFVNDIAXQJIHCJO",
                    "CDRKYLIWCFZASXICHXYRYFUWHOKDTIGOFEZJBEKWVMADGJTNNOWPCMOZSITSJFH",
                    "UPBJCVASHRYPIEKQUBTWPLQHZVGYWEZNFETSD",
                    "GNTMWOENREHQYXDMZFGKGWVLCIEEZIAKXUUGNNKJLHZTZYYIGTHPRVJ",
                    "UWGKADTFZRPOFLUJDVNHBDATNUVSCAWZEYENUS",
                    "RMKHKOVRKYFQNIEGJYIBEGJKRFGGCQZQVTZFLF",
                },
                .timeout_override         = 25ms,
            }},
            {"PU", data::routing_rule{
                .pattern                  = "LUBIRECGDHJU",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = std::nullopt,
            }},
            {"YQIKU", data::routing_rule{
                .pattern                  = "BFLYEHALNQDYUGILXXAOIRZLVLLNETYKEHERKIEGKFPSLYWPKLETNTQITYTMPM",
                .backend_names            = std::vector<std::string>{
                    "PIPREBD",
                    "TLMOFGQAZFR",
                    "RUSPSZW",
                    "ILLMWUCSGAKPFEHFTFKKOJFCKMGJOTGCRQVNWUOGTDYSJLTYCDIFEZWAMWFXYJ",
                    "NDOTZVUZXGXQSOJMMJJWCHXRGIPPRTTBQSFAPXUNUMJWITQHPWSTER",
                    "AEZPGUBVBWNAFCAJLLVYWZVRDMZCEONVZVECHFTHD",
                    "HRONF",
                    "FBJIMFTLUTPXOAWCYSDRNUXVKULODWNKIDFNIZCPVPENQQWWJHUGG",
                },
                .timeout_override         = 10ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"XADC", "RBKQZYXLNWHKFTGSYWIDUKVYMJHLQRNMRAJDSEDUAGJ"},
            {"QGXHG", "WWFVBENDQLXZRYMJRVGLKARBUEUXQEIBFXTPJMSSKLGKAQEDOLYUUHEHHBBH"},
            {"XMSYXN", "WQW"},
            {"ZK", "OGGRRMKZJEKVJFHDGLGKGIV"},
            {"JFFIQ", "WZZNYICHZLDMMFWKCRMOU"},
            {"WC", "HFSVGYKOKILHLHIGWWVWDJZYTGERLCHSGRMXQ"},
            {"MOXE", "CIPOXEOEMSCFFSGDXSZGPCDH"},
            {"ZBQTWU", "XOM"},
            {"IMDXD", "VIIDDNRAYURDQAN"},
            {"UXFMG", "BKZRQZHJEWBJZNKXCXPVDVVPDDQNCBX"},
            {"DAAU", "EDHNRFVZSI"},
            {"FIY", "HFPACPQPWDHOSLWMBJOSBWICKAEI"},
        },
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "WTMLVPPLVHNAOIYBZTWCOGSBAYGWECTCGUIKBDBLPNFI",
            .extra                    = boost::json::value_from("KXBIFF"),
            .log_level                = std::nullopt,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_7", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "BCBJKFSJQUXXUDAOKQTQRUCSTNEKICAHBOOAW",
                        .port                     = 5545,
                    },
                    .connect_timeout          = 10ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 72,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -6581.2693,
                        .deadline                 = 30s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "MYJYSDOANYLCTYDBVTLOAPBEEAMNBDRUZYYDDSSHHUGFKOTIAPAGWYCKN",
                            .value                    = "MNQKFVJGSPXZCAMAYIWKCWTYIPTWAEHVKQJILQPMVNRYXEMAONZSEY",
                        },
                    },
                    .tls_cert_path            = "DHZWSCUFQAHYXNRCFFJODITXKHQNYIVBYVPSKKREJX",
                }},
                {"ep_35", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "YWTYSUJELDOUPIIWYULVXLTSALQQHBOVTT",
                        .port                     = 53001,
                    },
                    .connect_timeout          = 25ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 87,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = -14.2593,
                        .deadline                 = 5s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "MHF",
                            .value                    = "JBTCGBOWNGWAOZCCCW",
                        },
                        data::tag{
                            .key                      = "JCPVPFGIBPDAXYKBXGQWRUKVPMSPWAAZDFITFESVEIRYZPLOKV",
                            .value                    = "CBNVLQXNUTSKLRRAYLWJPOUYALYZI",
                        },
                        data::tag{
                            .key                      = "UBOSJLNLUSDDAX",
                            .value                    = "YTJTNXFPTFZPGOLWJSPNPYGMFUUNKTBYWUYYBZHWFAAKCVHWBBCGGGXNADXNSD",
                        },
                        data::tag{
                            .key                      = "HKKLUHHESVRWSLPGLPBTCNJULCZQWDTSCJJVISXIIJEBPYPSXOY",
                            .value                    = "FTRRTZGTVXFNOVMYPQLGVIRTQM",
                        },
                        data::tag{
                            .key                      = "OKBGWFMVYQAKHDXJLEZXQKNUEKZOYVOMXGGNWEHUAYCQAYRSJIBLAYCDWMJD",
                            .value                    = "ESNLUHVUIYOIUKETJYZHWTIOZRNLCPTS",
                        },
                        data::tag{
                            .key                      = "KWBABDPWSKVRRGDFGYECDCETWW",
                            .value                    = "AETR",
                        },
                        data::tag{
                            .key                      = "IMQCV",
                            .value                    = "AOJIFBH",
                        },
                        data::tag{
                            .key                      = "KBDZUNNUTTRC",
                            .value                    = "KJDVYDXNHTCYCBWGIZIZZAEWJU",
                        },
                        data::tag{
                            .key                      = "KMFDLGGZNENJMYRYHFLZMHCZNUQLACWLFRSCJN",
                            .value                    = "MWKDWMDWSARQCYEJBPBXAMFBXCQMOXILPUGEDYCZBFZWXU",
                        },
                        data::tag{
                            .key                      = "VWKTEJSZPCJRJHEHDLYIVICMFDLAO",
                            .value                    = "LRJLTSZEVYMIXFFPXNSYMWADJZWKFNFDWSAGJQSYOPTDIZSGRID",
                        },
                        data::tag{
                            .key                      = "MFPHHXWTICZCMVVSEFMSVE",
                            .value                    = "GVODHHRUVEACKQZBMMLHVAMODYAA",
                        },
                        data::tag{
                            .key                      = "UMYTEQDCOBSIGKABPETVYQQYDEREEKLZHVFHOMWOPFWBIFJTEZ",
                            .value                    = "PDBGPKZFNFLUGVXYKLHHLYVPQXXGEKGYCXDFXNZMODPAWZJHM",
                        },
                        data::tag{
                            .key                      = "HCNKIYCTLTEYIFKYI",
                            .value                    = "DREIKTVVNGKYMMAKPGKZEPTGBHNEXGQDVBABFLLXH",
                        },
                        data::tag{
                            .key                      = "GKXDJWHZGDBXEFLRIDXATHZJAPKWXCPYXJAEJZJMAWO",
                            .value                    = "GMHUZUOGAYHRVYBJLVMIWNTLUFRAIIDCCQJDPAFQZYLJFYUMCSCLEXKHDVUJNFL",
                        },
                        data::tag{
                            .key                      = "WTFNMKGWMAOCMUNSZRWKOIRQPVTOYKDO",
                            .value                    = "GXIZBIAIBSMCVWDZCQJZHBXYVJJDP",
                        },
                        data::tag{
                            .key                      = "",
                            .value                    = "XENVKFPPRKUEASZADMISZFFOKPKHSAFAGQTUPHCJRXSUDLBVSLBOCLC",
                        },
                        data::tag{
                            .key                      = "PBTEMKWTRUTDXWMRWWUBUEMCTBJUXLPLKGKRXORPLMKQ",
                            .value                    = "NOGXOCFWJHVMGBYGOXQJCBWYGCDYSAGCQRBUVQOKLKPFVDL",
                        },
                        data::tag{
                            .key                      = "CMSI",
                            .value                    = "HOTYFXGICJOA",
                        },
                        data::tag{
                            .key                      = "DNDWQNZECIOVTWLSICPNCCRIIUGBUAV",
                            .value                    = "NPGRUCZSJGNYKYVBLAGXMFHFQHPSPBMJR",
                        },
                        data::tag{
                            .key                      = "PNGFAFPBBOQFOKPXRZBWXTYMQTNKAQGCWUVBHHFIGXDYTACGQHLGM",
                            .value                    = "AYEIWCWBZXIRFDZWZWVIXUNJHZKZRLVYKSXBRFGIYUPOLVCOVUHIDLRZD",
                        },
                    },
                    .tls_cert_path            = "XRIFELESMKTHRWITPLFQPNMNCQMBYFANHKJNJFZLTPVEQACSYTVHKBWAAOBCY",
                }},
            },
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"ESAAH", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "UCGJHAACXSGFFMCFIFZDYGYIHL",
                    .warn_at                  = -943.1889,
                    .crit_at                  = 7381.1566,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "IHQXVJYZEMEYMTRURORRIXJWCHYINYI",
                    .warn_at                  = 5785.9354,
                    .crit_at                  = -1604.2077,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "VGCTRDNJXFDWCURPGMXJVZDIAOJUQHBSAJOSHMHLTFUBWYACTXUOFTCCIFNF",
                    .warn_at                  = -4017.4573,
                    .crit_at                  = 7620.9532,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "RIUMLAWLZCIHGWZUSXDHMWHMMFVETTOFWCHKBCOUTGIRJHGIULLBQHFYQP",
                    .warn_at                  = 6768.0646,
                    .crit_at                  = 3814.5503,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "WWWIHDDPVPITFAZJXAOHZXXFOGWKDZKZFFJLTPSQHRRCDGBLHYJFONEQQMSVM",
                    .warn_at                  = 8431.253,
                    .crit_at                  = 41.3905,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "",
                    .warn_at                  = -6590.0794,
                    .crit_at                  = 9603.2417,
                    .evaluation_window        = 10min,
                },
                data::threshold_rule{
                    .metric_name              = "YFIN",
                    .warn_at                  = 7574.0298,
                    .crit_at                  = -2452.5078,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "XAYFLEPFMSKIKCCDCYHOKMCHMMWOHDHLWSN",
                    .warn_at                  = -5694.9023,
                    .crit_at                  = 8285.531,
                    .evaluation_window        = 2min,
                },
            }},
            {"FKCJ", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "SXPCROIEISKBDMMXZXUPWYDNREVDRDKWNSFPTY",
                    .warn_at                  = -9860.4504,
                    .crit_at                  = 2422.8325,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "JCGDPROUVEIETXRHXCVOSBYKTNZRTI",
                    .warn_at                  = 3765.4984,
                    .crit_at                  = 3456.2219,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "XXNPA",
                    .warn_at                  = -3941.8373,
                    .crit_at                  = -8949.4558,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "EHCTTVTSXABQDCXXDOFNUWYYGFLXINDKFBXPPKJIFDRUXPUKGHCW",
                    .warn_at                  = 7380.7188,
                    .crit_at                  = 5651.0058,
                    .evaluation_window        = 5s,
                },
            }},
            {"CW", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "TAJZRHCXLCJRUWHEZNO",
                    .warn_at                  = 6575.7109,
                    .crit_at                  = -7569.1233,
                    .evaluation_window        = 10min,
                },
            }},
        },
        .warmup_delay             = 50ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
