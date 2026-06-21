#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_25)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/25.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "AGJUPBYIBJSNDSDSVXGQZTKF",
        .worker_threads           = 140,
        .enable_tracing           = false,
        .shutdown_grace_period    = 10s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{
            {"NLGV", "OCCMSCQUEX"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("HYNRONZPTQUPOBPJFBNMUOAPHNTSLCEDCHVFUYEHEYLGFUSTZRQO", 36927, true),
            std::make_tuple("NOMLQDYINKZAWSZTHSAFXTIQDXZIS", 78739, true),
        },
        .allowed_origins          = std::set<std::string>{
            "",
            "EKPBHPOLQBJOKJYELNCHBUDESMQAEEVCWUKJRZBCLDDRTBD",
            "FTKCDNVTWUERLEICSCWSGRWUFCCTAKWFQZHICWCWDJAOTJZZLJIIBFINB",
            "XPBZZCZCGCPFYMYTIXXVFMWLRDBCJXQRRGFCQMDXOCTUYHMF",
        },
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "NWGCOMEJHLFFNYBKPZ",
            .port                     = 45887,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"TOLBG", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "BQAVDDRMIZZTEUZALNNIKBCNPOHBRY",
                    .warn_at                  = -4654.8943,
                    .crit_at                  = 7756.1146,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "BYADBPBSDDUUQ",
                    .warn_at                  = 8635.7593,
                    .crit_at                  = 8736.0529,
                    .evaluation_window        = 10min,
                },
                data::threshold_rule{
                    .metric_name              = "NQEYTSFQTBIAMNBQLXYWEYDPKIABISR",
                    .warn_at                  = -1195.1082,
                    .crit_at                  = -4420.5781,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "RBQDSDFHTZRKYWQWBEJEKSQIIWNUPDVORRTXGLWZYAENTZAHLYJWDMZL",
                    .warn_at                  = 8712.9518,
                    .crit_at                  = -3742.6755,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "WZSWCBTNPSZSGSEARFSZATRUROLJHJBHAONRNPQSSCKPNSIOKXJIHMVAYZKFIB",
                    .warn_at                  = 9170.278,
                    .crit_at                  = 9779.7335,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "ZAWCCDDYYTPVLCPZCPHTL",
                    .warn_at                  = 5757.9942,
                    .crit_at                  = -4663.6224,
                    .evaluation_window        = 2min,
                },
            }},
            {"FFR", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "HGYVSWYCIDKMNVPUPSSAUJJOUHH",
                    .warn_at                  = -9555.9923,
                    .crit_at                  = 4022.0471,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "WDNNB",
                    .warn_at                  = 3202.2821,
                    .crit_at                  = 469.9185,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "THDGHKKEU",
                    .warn_at                  = -8466.156,
                    .crit_at                  = 9465.3845,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "EDSTYGLSKRSCMEOOYMFRURERZGKKCM",
                    .warn_at                  = -8221.5219,
                    .crit_at                  = -6333.5332,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "QIQLPTBGCAVLTFX",
                    .warn_at                  = 834.9104,
                    .crit_at                  = -9191.9936,
                    .evaluation_window        = 15s,
                },
            }},
            {"HJVJFZ", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "TH",
                    .warn_at                  = 6524.563,
                    .crit_at                  = 1431.0266,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "KLRFWJNTSCZYJHYZELULPTHRZWWEMVRMNIYMBDBGSTCUKKHXFRCZQRDAHNPVO",
                    .warn_at                  = -4229.7551,
                    .crit_at                  = 7484.5708,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "JKFAV",
                    .warn_at                  = 2457.3815,
                    .crit_at                  = -9489.5316,
                    .evaluation_window        = 10s,
                },
            }},
            {"GYSY", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "DLHPVYTSLCBKMOCYMAFAMPKCXKVTGZFVLUMFQYKKUCGHQKMVEAFWOGLQMKAJ",
                    .warn_at                  = -6933.2008,
                    .crit_at                  = -2272.5817,
                    .evaluation_window        = 1min,
                },
                data::threshold_rule{
                    .metric_name              = "QAWQZ",
                    .warn_at                  = 9076.3339,
                    .crit_at                  = -5049.5945,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "KIWXJQXWLSZOFZLRRRNEWSRQZENUETQPRN",
                    .warn_at                  = -3565.1761,
                    .crit_at                  = 1795.2409,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "AMAWQITNWEE",
                    .warn_at                  = -4221.5212,
                    .crit_at                  = 722.7658,
                    .evaluation_window        = 5s,
                },
            }},
            {"CR", std::vector<data::threshold_rule>{}},
            {"NS", std::vector<data::threshold_rule>{}},
            {"VEL", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "JTHGIO",
                    .warn_at                  = -6364.6781,
                    .crit_at                  = 4370.5997,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "TZRYARFWCMIIYNWKPLMJ",
                    .warn_at                  = -2429.7566,
                    .crit_at                  = -3924.6739,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "VGLTHBRZFQJBFP",
                    .warn_at                  = -1746.6096,
                    .crit_at                  = 9552.2861,
                    .evaluation_window        = 15s,
                },
                data::threshold_rule{
                    .metric_name              = "CIEXLEJGHDQYOWGHKOKXEGPUYKXUKWVNPXLE",
                    .warn_at                  = 4922.3741,
                    .crit_at                  = 2113.7449,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "JBTIGWIGEOMDCTGGHAZECHQMDLWURTYEQCORHNBDK",
                    .warn_at                  = -3128.4735,
                    .crit_at                  = -1192.6829,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "UHDDFBDMDDLVRFQSSYKAGWEZXBDSTKEKRTGOXGLFQRJTJNFDZYOYCC",
                    .warn_at                  = 830.5035,
                    .crit_at                  = -6408.5913,
                    .evaluation_window        = 5s,
                },
            }},
            {"WEQIC", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "VBLDZBQLPEPL",
                    .warn_at                  = -4995.1227,
                    .crit_at                  = -8510.6963,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "P",
                    .warn_at                  = -1053.1909,
                    .crit_at                  = 9623.3509,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "IZPHAU",
                    .warn_at                  = -7097.1263,
                    .crit_at                  = 7198.9214,
                    .evaluation_window        = 30s,
                },
                data::threshold_rule{
                    .metric_name              = "MQBEGNPMQENTAXXUPMIVXYWFLTFTBZXYRGHVBEDLSHGXGPEMOJD",
                    .warn_at                  = 8852.0038,
                    .crit_at                  = 5164.3061,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "JJUSCG",
                    .warn_at                  = -2370.9655,
                    .crit_at                  = -2051.316,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "BOEE",
                    .warn_at                  = -3707.7252,
                    .crit_at                  = -9008.2999,
                    .evaluation_window        = 5min,
                },
                data::threshold_rule{
                    .metric_name              = "Z",
                    .warn_at                  = -8032.0356,
                    .crit_at                  = 4429.9554,
                    .evaluation_window        = 5s,
                },
            }},
            {"WVU", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name              = "XEOBPMNYYVKITAYCQZYVLUFMYQMUQDVMHWHRAMCKDPILVCCXDSYTFWWHTZEYUPO",
                    .warn_at                  = -436.989,
                    .crit_at                  = -7845.8997,
                    .evaluation_window        = 5s,
                },
                data::threshold_rule{
                    .metric_name              = "NHPNAYPGRWMFOGCOXXODULLOMQNNBRBZSCCTEGZBL",
                    .warn_at                  = 5168.4349,
                    .crit_at                  = -3300.8742,
                    .evaluation_window        = 2min,
                },
                data::threshold_rule{
                    .metric_name              = "BZLXGJQMMZSMRGTCAULANCEPFDCQMDUXQZJQVADWTRYPULRABW",
                    .warn_at                  = 5021.6135,
                    .crit_at                  = 59.6198,
                    .evaluation_window        = 10s,
                },
                data::threshold_rule{
                    .metric_name              = "NIGONWJUVUBLUTLTFPBDKLYGFKSOJBBEVJDYHYJLJKHPPLV",
                    .warn_at                  = -4633.7944,
                    .crit_at                  = 9678.224,
                    .evaluation_window        = 5s,
                },
            }},
        },
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
