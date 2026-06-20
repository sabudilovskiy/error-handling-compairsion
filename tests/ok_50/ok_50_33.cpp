#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

TEST(service_config_parse, ok_50_33)
{
    using namespace std::chrono_literals;

    const std::string json = load_file("ok_50_33.json");
    const auto parsed = json::exceptions::as<data::service_config>(json);

    const data::service_config expected = {
        .service_name          = "my-service",
        .worker_threads        = 4u,
        .enable_tracing        = false,
        .backends              = std::vector<data::backend_group>{
            data::backend_group{
                .name      = "primary",
                .endpoints = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address         = data::network_address{.host = "primary.local", .port = 5567},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.96,
                            .deadline           = 1min,
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
                        .warn_at           = 79.0,
                        .crit_at           = 92.4,
                        .evaluation_window = 5min,
                    }},
                },
                .min_log_level = data::severity::info,
                .fallback_retry= data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.64,
                    .deadline           = std::nullopt,
                },
            },
        },
        .routes                = std::map<std::string, data::routing_rule>{
            {"api", data::routing_rule{
                .pattern          = "/api/*",
                .backend_names    = std::vector<std::string>{"primary"},
                .timeout_override = 1500ms,
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
            data::rate_limit_entry{"user", 2000u, true},
            data::rate_limit_entry{"anon",  200u, false},
        },
        .allowed_origins       = std::set<std::string>{
            "https://app.example.com",
            "https://example.com",
        },
        .config_tree           = data::scope_override{
                .scope              = "level_50",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_50", data::endpoint_config{
                        .address         = data::network_address{.host = "host50.local", .port = 14661},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.18,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_50", .value = "val_6270"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "50"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_49",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_49", data::endpoint_config{
                        .address         = data::network_address{.host = "host49.local", .port = 14987},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.28,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_49", .value = "val_2803"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "49"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_48",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 1.13,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_48", data::endpoint_config{
                        .address         = data::network_address{.host = "host48.local", .port = 11961},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.61,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_48", .value = "val_6704"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "48"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_47",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_47", data::endpoint_config{
                        .address         = data::network_address{.host = "host47.local", .port = 19661},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.73,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_47", .value = "val_1158"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "47"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_46",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 2.34,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_46", data::endpoint_config{
                        .address         = data::network_address{.host = "host46.local", .port = 10243},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 2.31,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_46", .value = "val_3674"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "46"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_45",
                .log_level          = data::severity::warning,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_45", data::endpoint_config{
                        .address         = data::network_address{.host = "host45.local", .port = 14616},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.42,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_45", .value = "val_7658"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "45"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_44",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 10u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 1.78,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_44", data::endpoint_config{
                        .address         = data::network_address{.host = "host44.local", .port = 15204},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.44,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_44", .value = "val_6238"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "44"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_43",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_43", data::endpoint_config{
                        .address         = data::network_address{.host = "host43.local", .port = 17014},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 2.13,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_43", .value = "val_9379"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "43"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_42",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_42", data::endpoint_config{
                        .address         = data::network_address{.host = "host42.local", .port = 19558},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.30,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_42", .value = "val_4090"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "42"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_41",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_41", data::endpoint_config{
                        .address         = data::network_address{.host = "host41.local", .port = 19399},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.01,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_41", .value = "val_3550"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "41"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_40",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 1.91,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_40", data::endpoint_config{
                        .address         = data::network_address{.host = "host40.local", .port = 19636},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.01,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_40", .value = "val_6481"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "40"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_39",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 8u,
                    .base_delay         = 100ms,
                    .backoff_multiplier = 2.94,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_39", data::endpoint_config{
                        .address         = data::network_address{.host = "host39.local", .port = 10269},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.93,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_39", .value = "val_6354"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "39"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_38",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 1.68,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_38", data::endpoint_config{
                        .address         = data::network_address{.host = "host38.local", .port = 17371},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.79,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_38", .value = "val_3101"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "38"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_37",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 7u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.26,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_37", data::endpoint_config{
                        .address         = data::network_address{.host = "host37.local", .port = 18926},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.96,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_37", .value = "val_4848"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "37"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_36",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 1.67,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_36", data::endpoint_config{
                        .address         = data::network_address{.host = "host36.local", .port = 14139},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 2.25,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_36", .value = "val_1141"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "36"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_35",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 7u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.56,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_35", data::endpoint_config{
                        .address         = data::network_address{.host = "host35.local", .port = 14411},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.24,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_35", .value = "val_1441"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "35"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_34",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 4u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 2.89,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_34", data::endpoint_config{
                        .address         = data::network_address{.host = "host34.local", .port = 15430},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.28,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_34", .value = "val_3115"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "34"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_33",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 7u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 2.75,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_33", data::endpoint_config{
                        .address         = data::network_address{.host = "host33.local", .port = 18157},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.29,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_33", .value = "val_5652"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "33"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_32",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_32", data::endpoint_config{
                        .address         = data::network_address{.host = "host32.local", .port = 16203},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.45,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_32", .value = "val_7044"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "32"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_31",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 4u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 1.21,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_31", data::endpoint_config{
                        .address         = data::network_address{.host = "host31.local", .port = 16288},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.25,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_31", .value = "val_3155"}},
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
                    .backoff_multiplier = 1.83,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_30", data::endpoint_config{
                        .address         = data::network_address{.host = "host30.local", .port = 19325},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.49,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_30", .value = "val_9698"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "30"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_29",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 10u,
                    .base_delay         = 10ms,
                    .backoff_multiplier = 2.58,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_29", data::endpoint_config{
                        .address         = data::network_address{.host = "host29.local", .port = 18087},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.27,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_29", .value = "val_9907"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "29"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_28",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 8u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 1.47,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_28", data::endpoint_config{
                        .address         = data::network_address{.host = "host28.local", .port = 10230},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.45,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_28", .value = "val_1237"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "28"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_27",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_27", data::endpoint_config{
                        .address         = data::network_address{.host = "host27.local", .port = 14129},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 2.40,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_27", .value = "val_6744"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "27"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_26",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 1u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 1.63,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_26", data::endpoint_config{
                        .address         = data::network_address{.host = "host26.local", .port = 14595},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.49,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_26", .value = "val_5299"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "26"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_25",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 2.58,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_25", data::endpoint_config{
                        .address         = data::network_address{.host = "host25.local", .port = 10511},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.24,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_25", .value = "val_9486"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "25"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_24",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 2.67,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_24", data::endpoint_config{
                        .address         = data::network_address{.host = "host24.local", .port = 15833},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.44,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_24", .value = "val_1235"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "24"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_23",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_23", data::endpoint_config{
                        .address         = data::network_address{.host = "host23.local", .port = 11292},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.50,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_23", .value = "val_3938"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "23"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_22",
                .log_level          = data::severity::warning,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_22", data::endpoint_config{
                        .address         = data::network_address{.host = "host22.local", .port = 16104},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.43,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_22", .value = "val_1018"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "22"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_21",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 2.07,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_21", data::endpoint_config{
                        .address         = data::network_address{.host = "host21.local", .port = 15240},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.99,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_21", .value = "val_7744"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "21"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_20",
                .log_level          = data::severity::debug,
                .retry              = data::retry_policy{
                    .max_attempts       = 5u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.33,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_20", data::endpoint_config{
                        .address         = data::network_address{.host = "host20.local", .port = 13280},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.02,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_20", .value = "val_4137"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "20"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_19",
                .log_level          = data::severity::debug,
                .retry              = data::retry_policy{
                    .max_attempts       = 5u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 1.63,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_19", data::endpoint_config{
                        .address         = data::network_address{.host = "host19.local", .port = 15683},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.07,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_19", .value = "val_2357"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "19"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_18",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_18", data::endpoint_config{
                        .address         = data::network_address{.host = "host18.local", .port = 16555},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.92,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_18", .value = "val_1302"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "18"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_17",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_17", data::endpoint_config{
                        .address         = data::network_address{.host = "host17.local", .port = 17065},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.55,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_17", .value = "val_8368"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "17"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_16",
                .log_level          = std::nullopt,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_16", data::endpoint_config{
                        .address         = data::network_address{.host = "host16.local", .port = 14728},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 2.11,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_16", .value = "val_9475"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "16"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_15",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_15", data::endpoint_config{
                        .address         = data::network_address{.host = "host15.local", .port = 15274},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.07,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_15", .value = "val_4427"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "15"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_14",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_14", data::endpoint_config{
                        .address         = data::network_address{.host = "host14.local", .port = 15892},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.78,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_14", .value = "val_1032"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "14"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_13",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 2.31,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_13", data::endpoint_config{
                        .address         = data::network_address{.host = "host13.local", .port = 13991},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 1.62,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_13", .value = "val_9933"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "13"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_12",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 2.23,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_12", data::endpoint_config{
                        .address         = data::network_address{.host = "host12.local", .port = 10500},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 1.51,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_12", .value = "val_6978"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "12"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_11",
                .log_level          = data::severity::warning,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_11", data::endpoint_config{
                        .address         = data::network_address{.host = "host11.local", .port = 16227},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.05,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_11", .value = "val_6047"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "11"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_10",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 50ms,
                    .backoff_multiplier = 2.14,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_10", data::endpoint_config{
                        .address         = data::network_address{.host = "host10.local", .port = 17283},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.05,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_10", .value = "val_4226"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "10"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_9",
                .log_level          = data::severity::warning,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_9", data::endpoint_config{
                        .address         = data::network_address{.host = "host9.local", .port = 16233},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.39,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_9", .value = "val_3871"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "9"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_8",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 7u,
                    .base_delay         = 100ms,
                    .backoff_multiplier = 2.24,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_8", data::endpoint_config{
                        .address         = data::network_address{.host = "host8.local", .port = 15079},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 2.15,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_8", .value = "val_4035"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "8"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_7",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_7", data::endpoint_config{
                        .address         = data::network_address{.host = "host7.local", .port = 13619},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.12,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_7", .value = "val_4615"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "7"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_6",
                .log_level          = data::severity::error,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 500ms,
                    .backoff_multiplier = 2.02,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_6", data::endpoint_config{
                        .address         = data::network_address{.host = "host6.local", .port = 14815},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 2.46,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_6", .value = "val_1334"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "6"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_5",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 10u,
                    .base_delay         = 100ms,
                    .backoff_multiplier = 1.81,
                    .deadline           = std::nullopt,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_5", data::endpoint_config{
                        .address         = data::network_address{.host = "host5.local", .port = 16991},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 2.46,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_5", .value = "val_3217"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "5"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_4",
                .log_level          = data::severity::info,
                .retry              = data::retry_policy{
                    .max_attempts       = 4u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 2.55,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_4", data::endpoint_config{
                        .address         = data::network_address{.host = "host4.local", .port = 19639},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 1u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.03,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_4", .value = "val_8970"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "4"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_3",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_3", data::endpoint_config{
                        .address         = data::network_address{.host = "host3.local", .port = 12170},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.08,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_3", .value = "val_9185"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "3"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_2",
                .log_level          = data::severity::critical,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 100ms,
                    .backoff_multiplier = 2.77,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_2", data::endpoint_config{
                        .address         = data::network_address{.host = "host2.local", .port = 11316},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 1.18,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_2", .value = "val_3663"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "2"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_1",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 2u,
                    .base_delay         = 1s,
                    .backoff_multiplier = 1.66,
                    .deadline           = 5min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_1", data::endpoint_config{
                        .address         = data::network_address{.host = "host1.local", .port = 15401},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.69,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k_1", .value = "val_1968"}},
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
        .admin_endpoint        = data::network_address{.host = "admin.local", .port = 8508},
        .global_thresholds     = std::map<std::string, std::vector<data::threshold_rule>>{
            {"memory", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name       = "mem_usage",
                    .warn_at           = 78.0,
                    .crit_at           = 95.4,
                    .evaluation_window = 5min,
                },
            }},
        },
        .shutdown_grace_period = 30s,
        .warmup_delay          = 1s,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
