#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_2)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/2.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "BCCLFXZVJITGTBSVFNUMZXQLROQIBALOKMNQFRFHHAFKFEQQLQVRFOZNXQYLZ",
        .worker_threads           = 152,
        .enable_tracing           = true,
        .shutdown_grace_period    = 2min,
        .backends                 = std::vector<data::backend_group>{},
        .routes                   = std::map<std::string, data::routing_rule>{
            {"HPIPQQ", data::routing_rule{
                .pattern                  = "LVOOLSXRXOPVHKWFTIYPJJZWQRQQUTSNJXGPQLVTCZKXAGXDBSUBI",
                .backend_names            = std::vector<std::string>{
                    "YQEIHGBNWYBBLLFHVACDCABXALIEFXFQWAMSBZHEBALTUXXDJKPAJORYTX",
                    "MTWEPHCVVKDAOZEQ",
                    "QKEKIITNUAWREVBIBEFFDOUHQ",
                },
                .timeout_override         = 10ms,
            }},
            {"CICSH", data::routing_rule{
                .pattern                  = "ZTWLIVNIQYAEBMNFDQXCHDDAFYHDGAQVOOJRUMG",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = 500ms,
            }},
            {"SS", data::routing_rule{
                .pattern                  = "NQS",
                .backend_names            = std::vector<std::string>{
                    "LAQDTLJWLJAVNDDJGYVAZOBNUPOGSTCAJALJXCHYPGDSLMWOEYL",
                    "DDCTKUM",
                },
                .timeout_override         = 10ms,
            }},
            {"XW", data::routing_rule{
                .pattern                  = "LOEZLIPQPXXZNPVJMHFPTIRNWVWCSXS",
                .backend_names            = std::vector<std::string>{
                    "EZNCZCVZUBEJMHWVVKOFQJDERYNDKQHWQIFFOWHMLZYSXEOOXAZTMXFMQBPIMIW",
                    "UPLRKWXVCYXHRTGMVMUAKOQWOU",
                    "MGXSTM",
                },
                .timeout_override         = std::nullopt,
            }},
            {"YZGIXS", data::routing_rule{
                .pattern                  = "PZTEATVNPIQSFOWGYCLAPRVVCYSPVKOIQOACT",
                .backend_names            = std::nullopt,
                .timeout_override         = 200ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"BFP", "OVJEAJROALBRMSOGVJPUEPWR"},
            {"CIKJ", "ZJUUMQCQUGMTQEZQUCJBH"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("DDV", 81861, true),
            std::make_tuple("CKOLFPOJOEWOUGIKFDHP", 18954, false),
            std::make_tuple("ZEHIZRUMMZXKIXTQSWXKXM", 75100, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = std::nullopt,
        .admin_endpoint           = data::network_address{
            .host                     = "VCLJMPFILOPCFKMEADLFLCXYUNARKHTMRJPUELK",
            .port                     = 13247,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
