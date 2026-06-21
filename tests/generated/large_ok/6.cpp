#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, large_ok_6)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("large_ok/6.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = data::service_config{
        .service_name             = "CPYIBAEVSPYXLKYAIPZGXNRRVDGSRWZXIVZTVCNKCLZNZIOWDY",
        .worker_threads           = 51,
        .enable_tracing           = false,
        .shutdown_grace_period    = 5s,
        .backends                 = std::nullopt,
        .routes                   = std::map<std::string, data::routing_rule>{
            {"PGQS", data::routing_rule{
                .pattern                  = "WZQAULHTNJLSDCQVQGDTVIJXGMPHETGWQAGYFAUKR",
                .backend_names            = std::nullopt,
                .timeout_override         = 10ms,
            }},
            {"JEVPB", data::routing_rule{
                .pattern                  = "TXMDOHZCTVO",
                .backend_names            = std::vector<std::string>{},
                .timeout_override         = std::nullopt,
            }},
            {"JWNCG", data::routing_rule{
                .pattern                  = "IOPXZFAARDISZLGIQOKQINNTPITPVPPEXMPJUZOKLVFTMWT",
                .backend_names            = std::vector<std::string>{
                    "XZFJRATOBFATYSDVWLLPSBGEITANZZZQPCPHDLLEVUHTKEBUVDWDBUPOXCUAWR",
                    "CFTUIUOPWAZUEGOPYOORIPWSCZJLJLBCQIIIPNOLBWCHTUHRXBXFK",
                    "XYY",
                },
                .timeout_override         = 10ms,
            }},
            {"MR", data::routing_rule{
                .pattern                  = "XPUCECLQ",
                .backend_names            = std::nullopt,
                .timeout_override         = 100ms,
            }},
            {"QSM", data::routing_rule{
                .pattern                  = "HWSWENWFYKHRSAZZSMGYKMQOAMQRVEWHURZXLIVFEFWUEMCBAB",
                .backend_names            = std::vector<std::string>{
                    "RDVLTBBRHZNHYSWJCPCXSBFVODDWFBVAYVXNUWJIO",
                    "UYRZUGISAIQZXXWVKYQCSTUBLLWDHYALWKNVBLEAAKCPAOICVSTI",
                    "RFHVMTNS",
                    "IIEJBGYODZFSDZAQFDESMPPQYWRZZPGUMEYOAKNIKEJLSVLHAYJFC",
                    "HUCGMNEYEQBQQYPLKWSMIUVZCIEBDSTTXEQQDZW",
                },
                .timeout_override         = std::nullopt,
            }},
            {"GL", data::routing_rule{
                .pattern                  = "XHFFHUEPXOTDXTEOZGSLX",
                .backend_names            = std::vector<std::string>{
                    "CIYABUAPUOKBAIXD",
                    "DXLEYELVYPXMZAREDOLAEVRPICPDMWGZRFOKIZR",
                },
                .timeout_override         = 100ms,
            }},
            {"WYBQXH", data::routing_rule{
                .pattern                  = "TAQPRRIFBKAGSJGEIBIXJWLGWXFTACLSFLFPUHPMRT",
                .backend_names            = std::vector<std::string>{
                    "NBSTG",
                    "UBPVUQQIQIULJZNXL",
                    "NUFIBUQKVQBCVDBONRCFVILACIWJLMMSWWCXDJZPOXIJHYAB",
                },
                .timeout_override         = 10ms,
            }},
            {"UUXA", data::routing_rule{
                .pattern                  = "ZERDAM",
                .backend_names            = std::vector<std::string>{
                    "YFEEDAZGTKNWPTSPOKTOGZFRDHVEMHSLOSYUISTGSHXANH",
                    "DUBKLZPUINMJLQWSLSBNUSFJJSVPHDOSFLSN",
                    "KCONPADTCPNUBUAXQQLLFFPRCMSTD",
                    "HTXRITQZIZMLWATLNJFPZLBARZGAYBAPUDRNPKPGGLEDGBHINHLP",
                    "YUXIGXRBQGGMQBVNUAUCXCD",
                    "GQYDQSSPKVFOGYYAHKGRSJETAAJDMQGVGXNRTRUYTP",
                    "TRFEVTGUWJNJWMVBOGGJHXNLYBUKLXLMNLQNJZETUTIUGTOQFURAECH",
                    "AGRJBRBPMDLKEJRASIZYEIUKCXUQT",
                    "TAHJTGG",
                    "ATLZKGSYNMZSXBBFURTHQHJFIFTLLJSYHFCESZROBDCRBLLOMIQYHNSSNKUOMZ",
                    "HBXCNVQMDTQOKSTVFDWCDGGPVXHZRALUFBBMAJ",
                },
                .timeout_override         = 100ms,
            }},
        },
        .env                      = std::unordered_map<std::string, std::string>{
            {"AAP", "VLHEOMNRHKWUGYDZUMOXVBGJSSUIRXDSIHUYKYTLJI"},
            {"OLGD", "ZICHLQWBCXDFAQKANBEGADIFGHYDSGWUAWXKU"},
        },
        .rate_limits              = std::vector<std::tuple<std::string, std::uint32_t, bool>>{
            std::make_tuple("VFOETYNIBSSMJZTPUUTYZZW", 63107, false),
        },
        .allowed_origins          = std::nullopt,
        .config_tree              = data::scope_override{
            .scope                    = "EAGJDEUASZXLLDWXRGL",
            .extra                    = boost::json::value_from("KYXDGIZDOSNDKLVHANIWDFABVAAKCOBEIIXJHHHK"),
            .log_level                = data::severity::warning,
            .retry                    = std::nullopt,
            .endpoint_overrides       = std::nullopt,
            .tags                     = std::nullopt,
            .nested                   = common::box<data::scope_override>{},
        },
        .admin_endpoint           = data::network_address{
            .host                     = "QMRPMKEQCEIHBHXKAMLUKWFOGZDKX",
            .port                     = 51486,
        },
        .global_thresholds        = std::map<std::string, std::vector<data::threshold_rule>>{
            {"FP", std::vector<data::threshold_rule>{}},
            {"AOOXRV", std::vector<data::threshold_rule>{}},
        },
        .warmup_delay             = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
