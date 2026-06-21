#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, medium_ok_20)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("medium_ok/20.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "VZYEIVUDKSFANNCDEKPSONGGKUVK",
        .worker_threads           = 84,
        .enable_tracing           = true,
        .shutdown_grace_period    = 10s,
        .backends                 = std::nullopt,
        .routes                   = std::nullopt,
        .env                      = std::unordered_map<std::string, std::string>{
            {"DCG", "YJJWIFTD"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("SHBAZUTJIEWUKTXOEUIRNFFMWD", 68980, false),
        },
        .allowed_origins          = std::set<std::string>{
            "QGNFFCDZJAZUZKVXMOQ",
        },
        .config_tree              = std::nullopt,
        .admin_endpoint           = std::nullopt,
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{},
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
