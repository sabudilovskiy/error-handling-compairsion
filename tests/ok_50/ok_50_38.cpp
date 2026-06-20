#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, ok_50_38)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("ok_50_38.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = {
        .service_name          = "my-service",
        .worker_threads        = 16u,
        .enable_tracing        = true,
        .backends              = std::vector<data::backend_group>{
            data::backend_group{
                .name      = "primary",
                .endpoints = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address         = data::network_address{.host = "primary.local", .port = 2688},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 500ms,
                            .backoff_multiplier = 1.75,
                            .deadline           = 30s,
                        },
                        .tls_cert_path   = "/etc/certs/primary.pem",
                        .tags            = std::vector<data::tag>{
                            data::tag{.key = "env",    .value = "prod"},
                            data::tag{.key = "region", .value = "eu-west"},
                        },
                    },
                },
                .alerts        = std::map<std::string, data::threshold_rule>{
                    {"cpu", data::threshold_rule{
                        .metric_name       = "cpu_usage",
                        .warn_at           = 67.7,
                        .crit_at           = 89.6,
                        .evaluation_window = 2min,
                    }},
                },
                .min_log_level = data::severity::info,
                .fallback_retry= data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.31,
                    .deadline           = std::nullopt,
                },
            },
        },
        .routes                = std::map<std::string, data::routing_rule>{
            {"api", data::routing_rule{
                .pattern          = "/api/*",
                .backend_names    = std::vector<std::string>{"primary"},
                .timeout_override = 3s,
            }},
            {"health", data::routing_rule{
                .pattern          = "/health",
                .backend_names    = std::vector<std::string>{"primary"},
                .timeout_override = std::nullopt,
            }},
        },
        .env                   = std::unordered_map<std::string, std::string>{
            {"LOG_LEVEL", "info"},
            {"MAX_CONN",  "500"},
        },
        .rate_limits           = std::vector<data::rate_limit_entry>{
            data::rate_limit_entry{"user", 1000u, true},
            data::rate_limit_entry{"anon",  200u, false},
        },
        .allowed_origins       = std::set<std::string>{
            "https://app.example.com",
            "https://example.com",
        },
        .config_tree           = data::scope_override{
                .scope              = "level_50",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 2.73,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_50", data::endpoint_config{
                        .address         = data::network_address{.host = "host50.local", .port = 18266},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.15,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_50", .value = "val_2875"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "50"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_49",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 8u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 1.23,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_49", data::endpoint_config{
                        .address         = data::network_address{.host = "host49.local", .port = 14805},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.68,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_49", .value = "val_7860"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "49"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_48",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 5u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 1.87,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_48", data::endpoint_config{
                        .address         = data::network_address{.host = "host48.local", .port = 12686},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.36,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_48", .value = "val_5064"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "48"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_47",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_47", data::endpoint_config{
                        .address         = data::network_address{.host = "host47.local", .port = 13921},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.38,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_47", .value = "val_9607"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "47"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_46",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_46", data::endpoint_config{
                        .address         = data::network_address{.host = "host46.local", .port = 16192},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.24,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_46", .value = "val_1763"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "46"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_45",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 1u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 1.75,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_45", data::endpoint_config{
                        .address         = data::network_address{.host = "host45.local", .port = 19617},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.05,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_45", .value = "val_5132"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "45"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_44",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_44", data::endpoint_config{
                        .address         = data::network_address{.host = "host44.local", .port = 13414},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.63,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_44", .value = "val_1338"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "44"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_43",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 4u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 1.08,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_43", data::endpoint_config{
                        .address         = data::network_address{.host = "host43.local", .port = 19034},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.92,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_43", .value = "val_5673"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "43"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_42",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_42", data::endpoint_config{
                        .address         = data::network_address{.host = "host42.local", .port = 17739},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.32,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_42", .value = "val_2762"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "42"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_41",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_41", data::endpoint_config{
                        .address         = data::network_address{.host = "host41.local", .port = 19468},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.47,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_41", .value = "val_3887"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "41"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_40",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 1u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 1.92,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_40", data::endpoint_config{
                        .address         = data::network_address{.host = "host40.local", .port = 16584},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.34,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_40", .value = "val_6789"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "40"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_39",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 2.80,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_39", data::endpoint_config{
                        .address         = data::network_address{.host = "host39.local", .port = 11671},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.38,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_39", .value = "val_9302"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "39"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_38",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 100ms,
                    .backoff_multiplier = 2.27,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_38", data::endpoint_config{
                        .address         = data::network_address{.host = "host38.local", .port = 12041},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.41,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_38", .value = "val_8330"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "38"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_37",
                .log_level          = data::severity::debug,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 2.71,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_37", data::endpoint_config{
                        .address         = data::network_address{.host = "host37.local", .port = 14324},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.44,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_37", .value = "val_2910"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "37"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_36",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_36", data::endpoint_config{
                        .address         = data::network_address{.host = "host36.local", .port = 19274},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.00,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_36", .value = "val_1078"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "36"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_35",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_35", data::endpoint_config{
                        .address         = data::network_address{.host = "host35.local", .port = 18080},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.11,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_35", .value = "val_2102"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "35"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_34",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_34", data::endpoint_config{
                        .address         = data::network_address{.host = "host34.local", .port = 12649},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.32,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_34", .value = "val_3009"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "34"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_33",
                .log_level          = data::severity::debug,
                .retry              = data::retry_policy{
                    .max_attempts       = 7u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 3.00,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_33", data::endpoint_config{
                        .address         = data::network_address{.host = "host33.local", .port = 18822},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.30,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_33", .value = "val_9382"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "33"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_32",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 1u,
                    .base_delay         = 100ms,
                    .backoff_multiplier = 2.92,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_32", data::endpoint_config{
                        .address         = data::network_address{.host = "host32.local", .port = 19531},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.02,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_32", .value = "val_5335"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "32"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_31",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 1.15,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_31", data::endpoint_config{
                        .address         = data::network_address{.host = "host31.local", .port = 17006},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.66,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_31", .value = "val_5824"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "31"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_30",
                .log_level          = data::severity::debug,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.57,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_30", data::endpoint_config{
                        .address         = data::network_address{.host = "host30.local", .port = 16453},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.11,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_30", .value = "val_5606"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "30"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_29",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 2.88,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_29", data::endpoint_config{
                        .address         = data::network_address{.host = "host29.local", .port = 18832},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 2.36,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_29", .value = "val_6555"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "29"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_28",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_28", data::endpoint_config{
                        .address         = data::network_address{.host = "host28.local", .port = 15582},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.49,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_28", .value = "val_6938"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "28"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_27",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 1.41,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_27", data::endpoint_config{
                        .address         = data::network_address{.host = "host27.local", .port = 12246},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.75,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_27", .value = "val_1411"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "27"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_26",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_26", data::endpoint_config{
                        .address         = data::network_address{.host = "host26.local", .port = 13033},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.74,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_26", .value = "val_5651"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "26"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_25",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 2.94,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_25", data::endpoint_config{
                        .address         = data::network_address{.host = "host25.local", .port = 12362},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.94,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_25", .value = "val_5059"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "25"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_24",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 1u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 3.00,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_24", data::endpoint_config{
                        .address         = data::network_address{.host = "host24.local", .port = 13997},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.28,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_24", .value = "val_8747"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "24"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_23",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_23", data::endpoint_config{
                        .address         = data::network_address{.host = "host23.local", .port = 19289},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.37,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_23", .value = "val_9385"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "23"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_22",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_22", data::endpoint_config{
                        .address         = data::network_address{.host = "host22.local", .port = 10697},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.19,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_22", .value = "val_8279"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "22"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_21",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 1.84,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_21", data::endpoint_config{
                        .address         = data::network_address{.host = "host21.local", .port = 15996},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.51,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_21", .value = "val_5875"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "21"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_20",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 2.95,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_20", data::endpoint_config{
                        .address         = data::network_address{.host = "host20.local", .port = 10065},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.00,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_20", .value = "val_2400"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "20"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_19",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 5u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 1.67,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_19", data::endpoint_config{
                        .address         = data::network_address{.host = "host19.local", .port = 18438},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.32,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_19", .value = "val_7038"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "19"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_18",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_18", data::endpoint_config{
                        .address         = data::network_address{.host = "host18.local", .port = 13129},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.37,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_18", .value = "val_9721"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "18"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_17",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_17", data::endpoint_config{
                        .address         = data::network_address{.host = "host17.local", .port = 18167},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.55,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_17", .value = "val_2156"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "17"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_16",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_16", data::endpoint_config{
                        .address         = data::network_address{.host = "host16.local", .port = 19498},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.13,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_16", .value = "val_7654"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "16"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_15",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 2.59,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_15", data::endpoint_config{
                        .address         = data::network_address{.host = "host15.local", .port = 17994},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.19,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_15", .value = "val_7568"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "15"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_14",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_14", data::endpoint_config{
                        .address         = data::network_address{.host = "host14.local", .port = 19301},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 2.30,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_14", .value = "val_8514"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "14"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_13",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_13", data::endpoint_config{
                        .address         = data::network_address{.host = "host13.local", .port = 14126},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.03,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_13", .value = "val_8142"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "13"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_12",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_12", data::endpoint_config{
                        .address         = data::network_address{.host = "host12.local", .port = 13422},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.94,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_12", .value = "val_7665"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "12"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_11",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_11", data::endpoint_config{
                        .address         = data::network_address{.host = "host11.local", .port = 19066},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.40,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_11", .value = "val_9612"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "11"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_10",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 2.91,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_10", data::endpoint_config{
                        .address         = data::network_address{.host = "host10.local", .port = 19880},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.72,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_10", .value = "val_9464"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "10"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_9",
                .log_level          = data::severity::debug,
                .retry              = data::retry_policy{
                    .max_attempts       = 4u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 1.61,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_9", data::endpoint_config{
                        .address         = data::network_address{.host = "host9.local", .port = 13161},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.78,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_9", .value = "val_9687"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "9"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_8",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_8", data::endpoint_config{
                        .address         = data::network_address{.host = "host8.local", .port = 12380},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.46,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_8", .value = "val_7020"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "8"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_7",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 2.67,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_7", data::endpoint_config{
                        .address         = data::network_address{.host = "host7.local", .port = 17326},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 2.42,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_7", .value = "val_8641"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "7"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_6",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 2.81,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_6", data::endpoint_config{
                        .address         = data::network_address{.host = "host6.local", .port = 14908},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.76,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_6", .value = "val_1721"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "6"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_5",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 2.85,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_5", data::endpoint_config{
                        .address         = data::network_address{.host = "host5.local", .port = 19934},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.49,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_5", .value = "val_7968"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "5"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_4",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 1u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 2.83,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_4", data::endpoint_config{
                        .address         = data::network_address{.host = "host4.local", .port = 16564},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.17,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_4", .value = "val_5891"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "4"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_3",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.26,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_3", data::endpoint_config{
                        .address         = data::network_address{.host = "host3.local", .port = 15935},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.31,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_3", .value = "val_7234"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "3"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_2",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 2.44,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_2", data::endpoint_config{
                        .address         = data::network_address{.host = "host2.local", .port = 11458},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.45,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_2", .value = "val_1983"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "2"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_1",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_1", data::endpoint_config{
                        .address         = data::network_address{.host = "host1.local", .port = 13922},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.97,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_1", .value = "val_6248"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "1"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                .scope              = "leaf",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = {},
                .tags               = {},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{},
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            }
            }},
            },
        .admin_endpoint        = data::network_address{.host = "admin.local", .port = 8086},
        .global_thresholds     = std::map<std::string, std::vector<data::threshold_rule>>{
            {"memory", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name       = "mem_usage",
                    .warn_at           = 70.6,
                    .crit_at           = 87.0,
                    .evaluation_window = 5min,
                },
            }},
        },
        .shutdown_grace_period = 10s,
        .warmup_delay          = std::nullopt,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
