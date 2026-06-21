#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_7)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/7.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "EMUBCRDLSBQGBCNNCHCR",
        .worker_threads           = 109,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::vector<data::backend_group>{
            data::backend_group{
                .name                     = "SSMBHBREJNERDSJRVFDSSUGLDRWCSBTGPVRNYKOSOLJHZFWYHCSJQPKXOJTC",
                .endpoints                = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "YKEPNBVCYRSZKKWLTPSZOCCIPW",
                            .port                     = 43525,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 70,
                            .base_delay               = 50ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "AOLFTDPBGYJEXHMMPCFOMRIENRIWNLVMHECFEHVHAP",
                                .value                    = "FIJAENRLTSKEWQTUVXBOYVZRMMMMDPUMBGCGOFDKTBDASERDLTACG",
                            },
                            data::tag{
                                .key                      = "ILTLPDDPO",
                                .value                    = "JCEDXKXIPWFQAGQLEWRAYQJUCWIQLF",
                            },
                            data::tag{
                                .key                      = "RYQKUHTZZYGZHM",
                                .value                    = "HGQPLXAAZIPIGWTLOZXLLCHDHPGKGPTTAPULZUCVDMZWYGP",
                            },
                        },
                        .tls_cert_path            = "CZXMOMXCXFFEAESOZUETTPVLERREAAZXUDQXENGG",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "QHYSKIRNEBXLO",
                            .port                     = 43415,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 52,
                            .base_delay               = 1s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "EFEPTXDRBKVQQRPZYDRBHGIBYDQORAYCOKTQTQGWIOQRZPQHW",
                            .port                     = 34289,
                        },
                        .connect_timeout          = 2s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 92,
                            .base_delay               = 5s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "VHNCGVJZDYEWUVLEIEOH",
                                .value                    = "DMPFVHFWNQMKNGLKCXLAKROOWAMKQTJQCDZHDCIIBYFIYEN",
                            },
                        },
                        .tls_cert_path            = "MERQSPWKCIBZWFNCIAUCZICTHCIDOAKRNITEBQWHDFIBFGJUJQYGJOQVFILZ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "AAXQRGQPHODVUNVP",
                            .port                     = 35776,
                        },
                        .connect_timeout          = 2s,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 97,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -5408.675,
                            .deadline                 = 2min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "BEACUXINFBCVMQVJTHWJBOFFIOAILKRKHBJGLFAKMCPIQUGHQYACICEMSBMAJJU",
                                .value                    = "SQYEVWZTMYKXPE",
                            },
                            data::tag{
                                .key                      = "EBWQUNXWZQEQYQSZAVSZWVWUHCABEULDMORBUAU",
                                .value                    = "HPIAOZCXQRCVQCXXPIZCIHXYGHXUOPMCPV",
                            },
                            data::tag{
                                .key                      = "UU",
                                .value                    = "TEKIUXWJTSEA",
                            },
                            data::tag{
                                .key                      = "VDWGVPJWQJOOOYDRGJCPAJOCQOIMGGC",
                                .value                    = "EXQILETUQIDWLHPPMAFAPVOMJXENLMKDKAKYK",
                            },
                        },
                        .tls_cert_path            = "WAXJILCMMSCLNYIBIDBVJUEHINQKGYLZNAZYUMRRGXCBXNOTYEUJPBREFPN",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "XXUIMUHJPRVMDFUFCGQ",
                            .port                     = 59372,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 22,
                            .base_delay               = 5s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "CKHLIZSGAXNMNXQGMIKYB",
                                .value                    = "SLEVQQUZGCIHMMUONJAEBNWYZPSPACM",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "OHZDHEEQVDXWUYOCRYBAZEHSBUWJE",
                            .port                     = 41056,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 44,
                            .base_delay               = 200ms,
                            .backoff_multiplier       = -3993.0143,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "AARJOIKUHPQHRHANWUJBAGPVUNCIHVNLHPBWKWNLVMGAZJXQCG",
                                .value                    = "GJYGHOHIYJDTPTFHPNVBTEMBGATENBW",
                            },
                            data::tag{
                                .key                      = "WKXDCFKGFUQXOBJVXMLKOFDAC",
                                .value                    = "LNDRYGMLYJZNCBWPG",
                            },
                            data::tag{
                                .key                      = "GKLXPAUNHZUYMBMBOCZBIGXCTKLIKTBIXWWKIJAXYTZUCAHDPWOYMZINPE",
                                .value                    = "FAZXJWYETHKKOLZZTCQGMYFHNCUBPRRKFNDCITCGDNPWOFHENOTVHXRYVYD",
                            },
                        },
                        .tls_cert_path            = "ILIXIGOHFHHEJSGKC",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "QQHUZDUOBDAPHOLBJHDBGTSGCLQFOTIYYVADUTWTLGBLKEBGIBTXUGAKNVLFTJC",
                            .port                     = 13331,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 55,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -2094.0657,
                            .deadline                 = 15s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "NJVJNBJXSLNNAYZLUGMXMGANFNDCMSLOYFEABREUZMCS",
                                .value                    = "LXQFELJFQFCDMPYZZZGJEBPKBTUMCWTWFUZHTMT",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "MQFMLDEHXGBRY",
                            .port                     = 44056,
                        },
                        .connect_timeout          = 100ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 33,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 6980.1926,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "MVLOQOFAATPOHOY",
                                .value                    = "OFZPMDCELNLCZOQQVBBUECXKYXQCBYQMUZEACTX",
                            },
                            data::tag{
                                .key                      = "EPJZZFV",
                                .value                    = "HCLTYIFKTIOEIQPGSITQHKLBGFMFUIVKMFZZIDYQBULORQSWDI",
                            },
                        },
                        .tls_cert_path            = "ZLIMLSELKYCOHFTXBJQIJUSVK",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "HEJTUNNQLBEPHTUBABASLJDQLRHNSJSEGLTPFEAZHWEODCU",
                            .port                     = 9483,
                        },
                        .connect_timeout          = 100ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 27,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 1min,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "TQXPHFABBRAMFHFBYDATRVGENGQTUQUUNTFQJ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "XZPWRAMNXOCXUOFHDIHUBDKXWIWBIURVNVZQIJUG",
                            .port                     = 5598,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 17,
                            .base_delay               = 5s,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "THMUWVRPPQWAANXHSJZGMTSC",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "BADDTFLEWA",
                            .port                     = 2024,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 64,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = -9066.2186,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "RVCYWMDHGGDBBZYUCYUUJPDEDZYUGJKKNIALIJBWYLKYTQPJTXAZNANQYDLPW",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WCSJFNAQGJYYBALPDPWZFPSLQISFJGWHPFDU",
                            .port                     = 50253,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 99,
                            .base_delay               = 25ms,
                            .backoff_multiplier       = -3467.1157,
                            .deadline                 = 5min,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "UALGJINRQFMUHOERTYWYTUBLSKQ",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "VRXKFOOWYISHEKOUWHQGIJYWTEXEHXKTQLFHKGIXDFVDGMEEZJXJN",
                            .port                     = 17945,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 91,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = "UJOAEITXMAXHNW",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "NHVXUYUWSHVFUDONKIUWDNHZMWWUFINPOATNQVVFUKYAMPD",
                            .port                     = 2500,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 16,
                            .base_delay               = 500ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "QAUZLQKNXOGVFMQYDXTLUBIIMMBACNNUWVLSIDHJXMQHZ",
                                .value                    = "OGFEYCZZUGPURXHELVUZNOJYRUEYPLZHIWMVINVFPAZXZILHUJKPPNTUCVLEJ",
                            },
                        },
                        .tls_cert_path            = "KZEQLUSAVAGCUJITDSEHFYOLZEGMZRFTWTZCVRZUJGPWGQCXOVDR",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "EPPRBPOEWPHPFRTXAFKOWSPVJO",
                            .port                     = 24573,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 96,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 2722.5226,
                            .deadline                 = 10s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "QPPYEBGWNUEKDVLKPYQRYGJNKNIRBJJLPMKQIQLGUPZDKGKWJESUCZBMXRMRSB",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "BGPTYV",
                            .port                     = 3942,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 54,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 3474.0071,
                            .deadline                 = 2min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "UYFDVFBNYDUALEZJRWIJFNBKANSUSBPSQBDYZNSW",
                                .value                    = "OCAVMTSVEPYNRDCUPGEUANAAVVDCGDEPAIXSHOXXFBLYXWWEXYCJURWPOV",
                            },
                        },
                        .tls_cert_path            = "WBABAUVTCMJJXTFPTBKLSXOPVFEZDLUFUZNPMYZOIZYSKJIBTUWZTKTXAETJS",
                    },
                    data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "MMVMTYHZOJWAKIINFSYZBJEZSEIZZRVYPLRCRRPZMGZYXHJTBVMOWGIS",
                            .port                     = 49225,
                        },
                        .connect_timeout          = 500ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 46,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "QKPQSGGGGCFZWJLSSLMYQEHBPLDLUOZCEKTALIQTADBGSPSSGIYINDOYS",
                                .value                    = "EIBKGFMCABBRLWOPCTUMDWCIKSHUCVQMFOFLHXHFBILBRABIZQWX",
                            },
                            data::tag{
                                .key                      = "BDEKYAGVXJSSOYUDPKLIMDLPMFOHZEVAOWGZBFHCTLXEYODMAUCOKKHPDULEKHX",
                                .value                    = "WOR",
                            },
                        },
                        .tls_cert_path            = "NNHEAISJK",
                    },
                },
                .min_log_level            = data::severity::warning,
                .alerts                   = std::map<std::string, data::threshold_rule>{
                    {"DEQBU", data::threshold_rule{
                        .metric_name              = "VGRPJDIYGLNIHHDMJNFBXJEUAOZQKQEOAZQJFLNBNGISFEFQYHWFGTCCT",
                        .warn_at                  = 4616.9873,
                        .crit_at                  = 5225.5932,
                        .evaluation_window        = 5s,
                    }},
                    {"SJG", data::threshold_rule{
                        .metric_name              = "",
                        .warn_at                  = 3844.8596,
                        .crit_at                  = 391.2397,
                        .evaluation_window        = 1min,
                    }},
                },
                .fallback_retry           = data::retry_policy{
                    .max_attempts             = 35,
                    .base_delay               = 10ms,
                    .backoff_multiplier       = 8912.8494,
                    .deadline                 = 5s,
                },
            },
        },
        .routes                   = std::map<std::string, data::routing_rule>{
            {"FSL", data::routing_rule{
                .pattern                  = "WL",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 5s,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"KYW", "SYBJDXPOQAQZREAHCHTFFDJIRAADWXGIATUSOQHWODLDWFBIDOPSQYI"},
            {"ME", "HHEVSOXMFAUMWNTTQBMBYLKMHKWNSZKMRB"},
            {"VLH", "VUALDQFCKNGQVAHENMYOUBZBBUTIVTIURZBTDIDQANHBJDJLUFDBTQI"},
            {"REODQE", "NSJIHXCXRJOTWSHUMGRWLORJTPPJAHKHGQRMSMALFHKRKPIJGJBYAFRC"},
            {"OVBQ", "OLXYDQHVXENKVLEVGTTIQDXX"},
        },
        .rate_limits              = std::nullopt,
        .allowed_origins          = std::set<std::string>{
            "PJRYJRTNQQXVNMOLBTVLOAVCQHDNLQMURSEG",
            "RJZENSMSHCKKTHKGNAA",
            "WENDANYRSDPMSENZITTDMOWOJXLJLMQRTMUKAZXP",
        },
        .config_tree              = data::scope_override{
            .scope                    = "TSKWQXCFLKLCJQFDUJWKQNUFQJQG",
            .extra                    = boost::json::value_from("GNFBUSTDLSUUXBWNAZAJWWRAJMDSAVAG"),
            .log_level                = data::severity::critical,
            .retry                    = data::retry_policy{
                .max_attempts             = 87,
                .base_delay               = 2s,
                .backoff_multiplier       = -7125.6497,
                .deadline                 = 10s,
            },
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                {"ep_66", data::endpoint_config{
                    .address                  = data::network_address{
                        .host                     = "DCFQPO",
                        .port                     = 40173,
                    },
                    .connect_timeout          = 500ms,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 7,
                        .base_delay               = 10ms,
                        .backoff_multiplier       = std::nullopt,
                        .deadline                 = 15s,
                    },
                    .tags                     = std::vector<data::tag>{
                        data::tag{
                            .key                      = "DSCLGOTMABHMSYBOB",
                            .value                    = "HHBFSFKAOJNTIPCHVMVWSHNJMWPAZHCFFLMFAJM",
                        },
                        data::tag{
                            .key                      = "RMKMUCD",
                            .value                    = "LRHMGOJLHNBIVAKZEHWECGIRZER",
                        },
                        data::tag{
                            .key                      = "ZHFLLGXMMUSGJPQGHOVEWITOSLRHMTQGEYDVQCRIXYYMAVWSEJAMW",
                            .value                    = "FYHKG",
                        },
                        data::tag{
                            .key                      = "RLZQYJ",
                            .value                    = "WJCHJEWMJLMO",
                        },
                    },
                    .tls_cert_path            = std::nullopt,
                }},
            },
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "V",
                    .value                    = "WLNAVWWOHMLUDFJDITXHWVBMBTFNGYJEMXBRJUUFSHSPWQINVVS",
                },
                data::tag{
                    .key                      = "",
                    .value                    = "YUJBSTWBHVDBZKGYLXCNWXMXTHIQCLNOKWQXWUUOQBVWGNVQYEPYG",
                },
                data::tag{
                    .key                      = "ZRIFRFYUHRIHBFLLNCGUJEEVWPVPHWHAQWOEULWJEWES",
                    .value                    = "KUDRNYFVVETOYMGDWJALPGBBIJGDWJODFKOO",
                },
                data::tag{
                    .key                      = "RCBAOYPCXWKXSIDUPN",
                    .value                    = "ZRKALCUJUTXUWIUHCEXAAYMEJLFUQVF",
                },
                data::tag{
                    .key                      = "JXTKMFULKHLERLIHBBDSZUWMBGPNPXFJTSUCEWHFEOUMCB",
                    .value                    = "PGGXLABTZQNEJCVBQWNKCOAVFXFMJAOZSVLSGPCRKQONRUEMTTCZZB",
                },
                data::tag{
                    .key                      = "VJSSNLPVUEJKQUAGHVXOW",
                    .value                    = "VSLRS",
                },
            },
            .nested                   = common::box<data::scope_override>{data::scope_override{
                .scope                    = "OMIDHFGRXDHIUDG",
                .extra                    = boost::json::value_from("IWPHROHRSWDXQSSCNVCZOEQRQWYDUXQDO"),
                .log_level                = std::nullopt,
                .retry                    = data::retry_policy{
                    .max_attempts             = 17,
                    .base_delay               = 10s,
                    .backoff_multiplier       = 5499.6,
                    .deadline                 = 30s,
                },
                .endpoint_overrides       = std::map<std::string, data::endpoint_config>{
                    {"ep_48", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WT",
                            .port                     = 62627,
                        },
                        .connect_timeout          = 25ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 12,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 10min,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "LFLXKZYXVAIDHLQXQLXPBTLDLRKZTDBVHILGWOASODZAPD",
                                .value                    = "IFER",
                            },
                        },
                        .tls_cert_path            = std::nullopt,
                    }},
                    {"ep_19", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "IRWYZIOAAKEPQPBZBCFTUVTMPFWOMHTQCLKQG",
                            .port                     = 20398,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 62,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = std::nullopt,
                            .deadline                 = 5s,
                        },
                        .tags                     = std::vector<data::tag>{},
                        .tls_cert_path            = "PKHAHOTBUEXVEIMICQILS",
                    }},
                    {"ep_75", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WBRYDGYNUSUDLZJZZHZEVCJYKXLQUHLRWMKBWKVKZPQLHZHLEEGAVOMOMSYJF",
                            .port                     = 38455,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 72,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 3177.1925,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::vector<data::tag>{
                            data::tag{
                                .key                      = "SFJSLOLYWNXCPKFIIRAYFUIHWAGBMOGTJQUDGHXBETBCCZSKXEAGIRUAUKA",
                                .value                    = "KXAUPMTVZKFBN",
                            },
                        },
                        .tls_cert_path            = "YPTMIOAAKSUKBNTWXKFCAEGEQYCLLNLRVSREVTS",
                    }},
                    {"ep_95", data::endpoint_config{
                        .address                  = data::network_address{
                            .host                     = "WPYBYUJUYRWORILQQIEIARPDUZYLEUHMYCATEDB",
                            .port                     = 35603,
                        },
                        .connect_timeout          = 10ms,
                        .retry                    = data::retry_policy{
                            .max_attempts             = 77,
                            .base_delay               = 10ms,
                            .backoff_multiplier       = 4751.932,
                            .deadline                 = std::nullopt,
                        },
                        .tags                     = std::nullopt,
                        .tls_cert_path            = std::nullopt,
                    }},
                },
                .tags                     = std::vector<data::tag>{
                    data::tag{
                        .key                      = "OPGULZMOGKZADVXACZUMVLBHSMNMVUHAIAIWNHHLGKYNU",
                        .value                    = "PGSZFPYIYEJJCKAPH",
                    },
                    data::tag{
                        .key                      = "TOGSBZGXLBYYOFNEJVAZDEAEJEQXLDYFOVMCNKUVWMK",
                        .value                    = "BSHGZUWABEQTHSNWDXABKCDDPEQNAFHVREUXRQDQLPCLGHXCIWFAIICBGQBNZR",
                    },
                },
                .nested                   = common::box<data::scope_override>{data::scope_override{
                    .scope                    = "BUORJRKWNXWIMNKRNMEM",
                    .extra                    = boost::json::value_from("NZEUAHTQIWTXMHGVDCTZBWBMWRKVUORVKOSAPXUPQKSRMHUZ"),
                    .log_level                = data::severity::error,
                    .retry                    = data::retry_policy{
                        .max_attempts             = 7,
                        .base_delay               = 1min,
                        .backoff_multiplier       = 3192.0193,
                        .deadline                 = std::nullopt,
                    },
                    .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
                    .tags                     = std::vector<data::tag>{},
                    .nested                   = common::box<data::scope_override>{},
                }},
            }},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "XLQSPSHECYQLQGQFLHVFEVOFUUBKMLNDNEWIMDLLVZQQJOVCIMJOW",
            .port                     = 7327,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"YQE", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "PQVHTLQK",
                    .warn_at                  = 6031.1373,
                    .crit_at                  = -4942.6764,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "SFJWRIKIHIOCQUPC",
                    .warn_at                  = -5966.3412,
                    .crit_at                  = -1537.0868,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "BWOMLBWYJNNUTZILHMSETGW",
                    .warn_at                  = 1604.2805,
                    .crit_at                  = -8732.8755,
                    .evaluation_window        = 5s,
                },
            }},
            {"MMQNP", std::vector<data::threshold_rule>{}},
            {"DS", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "WNNPFCOMPEQYAVHXGMRBVJRKYMYODCHCSADPCYGSOBVGWKPBRWXNSENBUEK",
                    .warn_at                  = -3313.282,
                    .crit_at                  = 364.3827,
                    .evaluation_window        = 5s,
                },
            }},
            {"CKMI", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "MQNVBJJHMZNRIJGEBGR",
                    .warn_at                  = 3045.0583,
                    .crit_at                  = 8649.0161,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "ZKGOWRVBX",
                    .warn_at                  = -3714.668,
                    .crit_at                  = 661.5794,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "IHZOJGWGZSTOMXOGGBFN",
                    .warn_at                  = 7162.4763,
                    .crit_at                  = -7510.7318,
                    .evaluation_window        = 5s,
                },
            }},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
