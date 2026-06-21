#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_4)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/4.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "DXMPECCAMRJZYBH",
        .worker_threads           = 133,
        .enable_tracing           = true,
        .shutdown_grace_period    = 30s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{},
        .env                      = std::unordered_map<std::string, std::string>{
            {"ZIGF", "UXLCTKVMQHFHPICRJAJ"},
            {"YQGN", "JNOFHJIZBCBOUIQRUPWKEVGCNGU"},
            {"FLNX", "URGKDBWHIYSTHDKFJOABLWCJXVKAKJKEYUNTV"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("EIMTFKSALBOFLZZLJSDOGNGDBBBX", 16867, false),
            std::make_tuple("PS", 24905, false),
            std::make_tuple("YNUGPGHONPBHNOHUNGPGBBIIHQGYHNIEK", 5127, false),
            std::make_tuple("MUUZWXBPMCNGSFKJVPZUKNQGUZVZIKMPCIUVGBMTEYIVBFWUOSPXMMGZAGFATID", 39578, false),
            std::make_tuple("BGFVTKRYZPQOAC", 3418, false),
            std::make_tuple("TYEBLCYQAJLCCROMGZJMHYPMDCDTZLQNNWYOCUGUJPNDZRFLFFWEKPK", 25861, false),
            std::make_tuple("UJDRDPZWTP", 52630, false),
            std::make_tuple("HYFUAVBTKROZSJQZOT", 61745, true),
            std::make_tuple("VKENCTEVZTFJLGSZLVTCCMUFKULKFJATAQYCZL", 80725, false),
            std::make_tuple("PVSCYDFUPVXHTZVJWMTHPWHJLHXKRUQOZMQMK", 28377, true),
            std::make_tuple("ROWRTLMMTAE", 51130, true),
        },
        .allowed_origins          = std::set<std::string>{
            "CYIPHUPTYCEHCJEBFMZSVTRWRIAQHFYDGBKCDIBUJTUWFXEUNE",
        },
        .config_tree              = data::scope_override{
            .scope                    = "WAXREQNEGJPQCMFFIQMRVJMKFMBNAIVAJZE",
            .extra                    = boost::json::value_from("DTAHH"),
            .log_level                = data::severity::error,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::map<std::string, data::endpoint_config>{},
            .tags                     = std::vector<data::tag>{
                data::tag{
                    .key                      = "VWMKFQSGDPTLJUNTXBUGISZVSJZPUKZCHKDVWBTKQPLCFWBPQRTWHBG",
                    .value                    = "KZTEWJDQQACHTITAXBAPWEGLHXXLJMUTMBFNPCYQQJR",
                },
                data::tag{
                    .key                      = "WWNKFGAPNIKYNUNKYTGIIQCAMITJVUETYKCZFTCWGIVGUPYDUK",
                    .value                    = "",
                },
                data::tag{
                    .key                      = "CHQDDZKJSSVEX",
                    .value                    = "FWXA",
                },
            },
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "SKUKXYTLFFYGBBFV",
            .port                     = 61584,
        },
        .global_thresholds        = std::nullopt,
        .warmup_delay             = 10ms,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
