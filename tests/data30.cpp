#include <gtest/gtest.h>

#include "data/types.hpp"
#include "deep_equal.hpp"
#include "gtest_formatter.hpp"
#include "json/exceptions.hpp"

constexpr std::string_view json_30 = R"(
{
  "service_name": "api-gateway",
  "worker_threads": 8,
  "enable_tracing": true,
  "backends": [
    {
      "name": "primary",
      "endpoints": [
        {
          "address": { "host": "10.0.1.10", "port": 8080 },
          "connect_timeout": "250ms",
          "retry": {
            "max_attempts": 3,
            "base_delay": "50ms",
            "backoff_multiplier": 2.0,
            "deadline": "10s"
          },
          "tls_cert_path": "/etc/certs/primary.pem",
          "tags": [
            { "key": "region", "value": "eu-west-1" },
            { "key": "tier",   "value": "primary" }
          ]
        },
        {
          "address": { "host": "10.0.1.11", "port": 8080 },
          "connect_timeout": "250ms",
          "retry": {
            "max_attempts": 3,
            "base_delay": "50ms",
            "backoff_multiplier": 2.0
          },
          "tags": []
        }
      ],
      "alerts": {
        "latency_p99": {
          "metric_name": "http.latency.p99",
          "warn_at": 0.5,
          "crit_at": 1.0,
          "evaluation_window": "1m"
        },
        "error_rate": {
          "metric_name": "http.errors.rate",
          "warn_at": 0.01,
          "crit_at": 0.05,
          "evaluation_window": "5m"
        }
      },
      "min_log_level": "warning",
      "fallback_retry": {
        "max_attempts": 1,
        "base_delay": "1s",
        "backoff_multiplier": 1.0
      }
    },
    {
      "name": "canary",
      "endpoints": [
        {
          "address": { "host": "10.0.2.5", "port": 9090 },
          "connect_timeout": "500ms",
          "retry": {
            "max_attempts": 2,
            "base_delay": "100ms",
            "backoff_multiplier": 1.5,
            "deadline": "5s"
          },
          "tags": [
            { "key": "tier", "value": "canary" }
          ]
        }
      ],
      "alerts": {},
      "min_log_level": "debug"
    }
  ],
  "routes": {
    "/api/v1": {
      "pattern": "^/api/v1/.*",
      "backend_names": ["primary", "canary"],
      "timeout_override": "2s"
    },
    "/health": {
      "pattern": "^/health$",
      "backend_names": ["primary"]
    }
  },
  "env": {
    "DATACENTER": "eu-west-1",
    "DEPLOY_ENV": "production"
  },
  "rate_limits": [
    ["anonymous",     100,  true],
    ["authenticated", 5000, true],
    ["internal",      0,    false]
  ],
  "allowed_origins": [
    "https://app.example.com",
    "https://admin.example.com"
  ],
  "config_tree": {
    "scope": "datacenter:eu-west-1",
    "log_level": "info",
    "endpoint_overrides": {},
    "tags": [{ "key": "dc", "value": "eu-west-1" }],
    "extra": { "provider": "aws" },
    "nested": {
      "scope": "region:eu-west-1a",
      "endpoint_overrides": {},
      "tags": [{ "key": "az", "value": "eu-west-1a" }],
      "extra": {},
      "nested": {
        "scope": "region:eu-west-1b",
        "endpoint_overrides": {},
        "tags": [{ "key": "az", "value": "eu-west-1b" }],
        "extra": {},
        "nested": {
          "scope": "cluster:prod-1",
          "log_level": "warning",
          "endpoint_overrides": {},
          "tags": [{ "key": "cluster", "value": "prod-1" }],
          "extra": { "k8s_version": "1.29" },
          "nested": {
            "scope": "cluster:prod-2",
            "endpoint_overrides": {},
            "tags": [{ "key": "cluster", "value": "prod-2" }],
            "extra": {},
            "nested": {
              "scope": "cluster:prod-3",
              "endpoint_overrides": {},
              "tags": [{ "key": "cluster", "value": "prod-3" }],
              "extra": {},
              "nested": {
                "scope": "namespace:payments",
                "log_level": "debug",
                "retry": {
                  "max_attempts": 5,
                  "base_delay": "100ms",
                  "backoff_multiplier": 2.0,
                  "deadline": "30s"
                },
                "endpoint_overrides": {
                  "payments-db": {
                    "address": { "host": "db.payments.svc", "port": 5432 },
                    "connect_timeout": "1s",
                    "retry": {
                      "max_attempts": 3,
                      "base_delay": "200ms",
                      "backoff_multiplier": 1.5,
                      "deadline": "10s"
                    },
                    "tls_cert_path": "/etc/certs/payments-db.pem",
                    "tags": [{ "key": "service", "value": "payments-db" }]
                  }
                },
                "tags": [{ "key": "namespace", "value": "payments" }],
                "extra": { "billing": true },
                "nested": {
                  "scope": "namespace:auth",
                  "endpoint_overrides": {},
                  "tags": [{ "key": "namespace", "value": "auth" }],
                  "extra": {},
                  "nested": {
                    "scope": "namespace:search",
                    "endpoint_overrides": {},
                    "tags": [{ "key": "namespace", "value": "search" }],
                    "extra": {},
                    "nested": {
                      "scope": "deployment:api-gateway",
                      "log_level": "error",
                      "endpoint_overrides": {},
                      "tags": [{ "key": "app", "value": "api-gateway" }],
                      "extra": { "replicas": 3 },
                      "nested": {
                        "scope": "deployment:worker",
                        "endpoint_overrides": {},
                        "tags": [{ "key": "app", "value": "worker" }],
                        "extra": {},
                        "nested": {
                          "scope": "deployment:scheduler",
                          "endpoint_overrides": {},
                          "tags": [{ "key": "app", "value": "scheduler" }],
                          "extra": {},
                          "nested": {
                            "scope": "replicaset:api-gateway-7d9f",
                            "endpoint_overrides": {},
                            "tags": [{ "key": "replicaset", "value": "api-gateway-7d9f" }],
                            "extra": {},
                            "nested": {
                              "scope": "replicaset:worker-3a1c",
                              "endpoint_overrides": {},
                              "tags": [{ "key": "replicaset", "value": "worker-3a1c" }],
                              "extra": {},
                              "nested": {
                                "scope": "pod:api-gateway-7d9f-xk2p9",
                                "log_level": "critical",
                                "retry": {
                                  "max_attempts": 1,
                                  "base_delay": "500ms",
                                  "backoff_multiplier": 1.0,
                                  "deadline": "5s"
                                },
                                "endpoint_overrides": {
                                  "local-cache": {
                                    "address": { "host": "127.0.0.1", "port": 6379 },
                                    "connect_timeout": "10ms",
                                    "retry": {
                                      "max_attempts": 2,
                                      "base_delay": "5ms",
                                      "backoff_multiplier": 1.0
                                    },
                                    "tags": [{ "key": "type", "value": "cache" }]
                                  }
                                },
                                "tags": [{ "key": "pod", "value": "api-gateway-7d9f-xk2p9" }],
                                "extra": { "node": "ip-10-0-1-42" },
                                "nested": {
                                  "scope": "pod:api-gateway-7d9f-mn3q1",
                                  "endpoint_overrides": {},
                                  "tags": [{ "key": "pod", "value": "api-gateway-7d9f-mn3q1" }],
                                  "extra": {},
                                  "nested": {
                                    "scope": "pod:worker-3a1c-pp7rz",
                                    "endpoint_overrides": {},
                                    "tags": [{ "key": "pod", "value": "worker-3a1c-pp7rz" }],
                                    "extra": {},
                                    "nested": {
                                      "scope": "container:api",
                                      "endpoint_overrides": {},
                                      "tags": [{ "key": "container", "value": "api" }],
                                      "extra": { "image": "api-gateway:v2.4.1" },
                                      "nested": {
                                        "scope": "container:sidecar-proxy",
                                        "log_level": "error",
                                        "endpoint_overrides": {},
                                        "tags": [{ "key": "container", "value": "sidecar-proxy" }],
                                        "extra": {},
                                        "nested": {
                                          "scope": "container:log-collector",
                                          "endpoint_overrides": {},
                                          "tags": [{ "key": "container", "value": "log-collector" }],
                                          "extra": {},
                                          "nested": {
                                            "scope": "thread-pool:io",
                                            "endpoint_overrides": {},
                                            "tags": [{ "key": "pool", "value": "io" }],
                                            "extra": { "size": 16 },
                                            "nested": {
                                              "scope": "thread-pool:cpu",
                                              "endpoint_overrides": {},
                                              "tags": [{ "key": "pool", "value": "cpu" }],
                                              "extra": { "size": 8 },
                                              "nested": {
                                                "scope": "thread-pool:background",
                                                "endpoint_overrides": {},
                                                "tags": [{ "key": "pool", "value": "background" }],
                                                "extra": { "size": 4 },
                                                "nested": {
                                                  "scope": "goroutine-group:request-handlers",
                                                  "endpoint_overrides": {},
                                                  "tags": [{ "key": "group", "value": "request-handlers" }],
                                                  "extra": {},
                                                  "nested": {
                                                    "scope": "goroutine-group:background-jobs",
                                                    "endpoint_overrides": {},
                                                    "tags": [{ "key": "group", "value": "background-jobs" }],
                                                    "extra": {},
                                                    "nested": {
                                                      "scope": "goroutine-group:health-checks",
                                                      "log_level": "warning",
                                                      "retry": {
                                                        "max_attempts": 2,
                                                        "base_delay": "1s",
                                                        "backoff_multiplier": 1.0,
                                                        "deadline": "10s"
                                                      },
                                                      "endpoint_overrides": {},
                                                      "tags": [{ "key": "group", "value": "health-checks" }],
                                                      "extra": { "interval": "15s" }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  },
  "admin_endpoint": { "host": "127.0.0.1", "port": 9999 },
  "global_thresholds": {
    "cpu": [
      {
        "metric_name": "sys.cpu.usage",
        "warn_at": 0.7,
        "crit_at": 0.9,
        "evaluation_window": "1m"
      }
    ],
    "memory": [
      {
        "metric_name": "sys.mem.usage",
        "warn_at": 0.75,
        "crit_at": 0.95,
        "evaluation_window": "2m"
      }
    ]
  },
  "shutdown_grace_period": "30s",
  "warmup_delay": "500ms"
}
)";

using namespace std::chrono_literals;

TEST(service_config_parse, ServiceConfig30Ok)
{
    const auto got = json::exceptions::as<data::service_config>(json_30);

    const data::service_config expected = {
        .service_name = "api-gateway",
        .worker_threads = 8u,
        .enable_tracing = true,
        .backends = std::vector<data::backend_group> {
            data::backend_group {
                .name = "primary",
                .endpoints = std::vector<data::endpoint_config> {
                    data::endpoint_config {
                        .address = data::network_address {
                            .host = "10.0.1.10",
                            .port = 8080,
                        },
                        .connect_timeout = 250ms,
                        .retry = data::retry_policy {
                            .max_attempts = 3u,
                            .base_delay = 50ms,
                            .backoff_multiplier = 2.0,
                            .deadline = 10s,
                        },
                        .tls_cert_path = "/etc/certs/primary.pem",
                        .tags = std::vector<data::tag> {
                            data::tag {
                                .key = "region",
                                .value = "eu-west-1",
                            },
                            data::tag {
                                .key = "tier",
                                .value = "primary",
                            },
                        },
                    },
                    data::endpoint_config {
                        .address = data::network_address {
                            .host = "10.0.1.11",
                            .port = 8080,
                        },
                        .connect_timeout = 250ms,
                        .retry = data::retry_policy {
                            .max_attempts = 3u,
                            .base_delay = 50ms,
                            .backoff_multiplier = 2.0,
                        },
                        .tags = std::vector<data::tag> {},
                    },
                },
                .alerts = std::map<std::string, data::threshold_rule> {
                    {
                        "latency_p99",
                        data::threshold_rule {
                            .metric_name = "http.latency.p99",
                            .warn_at = 0.5,
                            .crit_at = 1.0,
                            .evaluation_window = 60s,
                        },
                    },
                    {
                        "error_rate",
                        data::threshold_rule {
                            .metric_name = "http.errors.rate",
                            .warn_at = 0.01,
                            .crit_at = 0.05,
                            .evaluation_window = 300s,
                        },
                    },
                },
                .min_log_level = data::severity::warning,
                .fallback_retry = data::retry_policy {
                    .max_attempts = 1u,
                    .base_delay = 1000ms,
                    .backoff_multiplier = 1.0,
                },
            },
            data::backend_group {
                .name = "canary",
                .endpoints = std::vector<data::endpoint_config> {
                    data::endpoint_config {
                        .address = data::network_address {
                            .host = "10.0.2.5",
                            .port = 9090,
                        },
                        .connect_timeout = 500ms,
                        .retry = data::retry_policy {
                            .max_attempts = 2u,
                            .base_delay = 100ms,
                            .backoff_multiplier = 1.5,
                            .deadline = 5s,
                        },
                        .tags = std::vector<data::tag> {
                            data::tag {
                                .key = "tier",
                                .value = "canary",
                            },
                        },
                    },
                },
                .alerts = std::map<std::string, data::threshold_rule> {},
                .min_log_level = data::severity::debug,
            },
        },
        .routes = std::map<std::string, data::routing_rule> {
            {
                "/api/v1",
                data::routing_rule {
                    .pattern = "^/api/v1/.*",
                    .backend_names = std::vector<std::string> {
                        "primary",
                        "canary",
                    },
                    .timeout_override = 2000ms,
                },
            },
            {
                "/health",
                data::routing_rule {
                    .pattern = "^/health$",
                    .backend_names = std::vector<std::string> {
                        "primary",
                    },
                },
            },
        },
        .env = std::unordered_map<std::string, std::string> {
            {
                "DATACENTER",
                "eu-west-1",
            },
            {
                "DEPLOY_ENV",
                "production",
            },
        },
        .rate_limits = std::vector<data::rate_limit_entry> {
            data::rate_limit_entry {
                "anonymous",
                100u,
                true,
            },
            data::rate_limit_entry {
                "authenticated",
                5000u,
                true,
            },
            data::rate_limit_entry {
                "internal",
                0u,
                false,
            },
        },
        .allowed_origins = std::set<std::string> {
            "https://app.example.com",
            "https://admin.example.com",
        },
        .config_tree = data::scope_override {
            .scope = "datacenter:eu-west-1",
            .log_level = data::severity::info,
            .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
            .tags = std::vector<data::tag> {
                data::tag {
                    .key = "dc",
                    .value = "eu-west-1",
                },
            },
            .extra = boost::json::value { { "provider", "aws" } },
            .nested = data::scope_override {
                .scope = "region:eu-west-1a",
                .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                .tags = std::vector<data::tag> {
                    data::tag {
                        .key = "az",
                        .value = "eu-west-1a",
                    },
                },
                .extra = boost::json::object {},
                .nested = data::scope_override {
                    .scope = "region:eu-west-1b",
                    .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                    .tags = std::vector<data::tag> {
                        data::tag {
                            .key = "az",
                            .value = "eu-west-1b",
                        },
                    },
                    .extra = boost::json::object {},
                    .nested = data::scope_override {
                        .scope = "cluster:prod-1",
                        .log_level = data::severity::warning,
                        .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                        .tags = std::vector<data::tag> {
                            data::tag {
                                .key = "cluster",
                                .value = "prod-1",
                            },
                        },
                        .extra = boost::json::value { { "k8s_version", "1.29" } },
                        .nested = data::scope_override {
                            .scope = "cluster:prod-2",
                            .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                            .tags = std::vector<data::tag> {
                                data::tag {
                                    .key = "cluster",
                                    .value = "prod-2",
                                },
                            },
                            .extra = boost::json::object {},
                            .nested = data::scope_override {
                                .scope = "cluster:prod-3",
                                .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                .tags = std::vector<data::tag> {
                                    data::tag {
                                        .key = "cluster",
                                        .value = "prod-3",
                                    },
                                },
                                .extra = boost::json::object {},
                                .nested = data::scope_override {
                                    .scope = "namespace:payments",
                                    .log_level = data::severity::debug,
                                    .retry = data::retry_policy {
                                        .max_attempts = 5u,
                                        .base_delay = 100ms,
                                        .backoff_multiplier = 2.0,
                                        .deadline = 30s,
                                    },
                                    .endpoint_overrides = std::map<std::string, data::endpoint_config> {
                                        {
                                            "payments-db",
                                            data::endpoint_config {
                                                .address = data::network_address {
                                                    .host = "db.payments.svc",
                                                    .port = 5432,
                                                },
                                                .connect_timeout = 1000ms,
                                                .retry = data::retry_policy {
                                                    .max_attempts = 3u,
                                                    .base_delay = 200ms,
                                                    .backoff_multiplier = 1.5,
                                                    .deadline = 10s,
                                                },
                                                .tls_cert_path = "/etc/certs/payments-db.pem",
                                                .tags = std::vector<data::tag> {
                                                    data::tag {
                                                        .key = "service",
                                                        .value = "payments-db",
                                                    },
                                                },
                                            },
                                        },
                                    },
                                    .tags = std::vector<data::tag> {
                                        data::tag {
                                            .key = "namespace",
                                            .value = "payments",
                                        },
                                    },
                                    .extra = boost::json::value { { "billing", true } },
                                    .nested = data::scope_override {
                                        .scope = "namespace:auth",
                                        .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                        .tags = std::vector<data::tag> {
                                            data::tag {
                                                .key = "namespace",
                                                .value = "auth",
                                            },
                                        },
                                        .extra = boost::json::object {},
                                        .nested = data::scope_override {
                                            .scope = "namespace:search",
                                            .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                            .tags = std::vector<data::tag> {
                                                data::tag {
                                                    .key = "namespace",
                                                    .value = "search",
                                                },
                                            },
                                            .extra = boost::json::object {},
                                            .nested = data::scope_override {
                                                .scope = "deployment:api-gateway",
                                                .log_level = data::severity::error,
                                                .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                .tags = std::vector<data::tag> {
                                                    data::tag {
                                                        .key = "app",
                                                        .value = "api-gateway",
                                                    },
                                                },
                                                .extra = boost::json::value { { "replicas", 3 } },
                                                .nested = data::scope_override {
                                                    .scope = "deployment:worker",
                                                    .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                    .tags = std::vector<data::tag> {
                                                        data::tag {
                                                            .key = "app",
                                                            .value = "worker",
                                                        },
                                                    },
                                                    .extra = boost::json::object {},
                                                    .nested = data::scope_override {
                                                        .scope = "deployment:scheduler",
                                                        .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                        .tags = std::vector<data::tag> {
                                                            data::tag {
                                                                .key = "app",
                                                                .value = "scheduler",
                                                            },
                                                        },
                                                        .extra = boost::json::object {},
                                                        .nested = data::scope_override {
                                                            .scope = "replicaset:api-gateway-7d9f",
                                                            .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                            .tags = std::vector<data::tag> {
                                                                data::tag {
                                                                    .key = "replicaset",
                                                                    .value = "api-gateway-7d9f",
                                                                },
                                                            },
                                                            .extra = boost::json::object {},
                                                            .nested = data::scope_override {
                                                                .scope = "replicaset:worker-3a1c",
                                                                .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                .tags = std::vector<data::tag> {
                                                                    data::tag {
                                                                        .key = "replicaset",
                                                                        .value = "worker-3a1c",
                                                                    },
                                                                },
                                                                .extra = boost::json::object {},
                                                                .nested = data::scope_override {
                                                                    .scope = "pod:api-gateway-7d9f-xk2p9",
                                                                    .log_level = data::severity::critical,
                                                                    .retry = data::retry_policy {
                                                                        .max_attempts = 1u,
                                                                        .base_delay = 500ms,
                                                                        .backoff_multiplier = 1.0,
                                                                        .deadline = 5s,
                                                                    },
                                                                    .endpoint_overrides = std::map<std::string, data::endpoint_config> {
                                                                        {
                                                                            "local-cache",
                                                                            data::endpoint_config {
                                                                                .address = data::network_address {
                                                                                    .host = "127.0.0.1",
                                                                                    .port = 6379,
                                                                                },
                                                                                .connect_timeout = 10ms,
                                                                                .retry = data::retry_policy {
                                                                                    .max_attempts = 2u,
                                                                                    .base_delay = 5ms,
                                                                                    .backoff_multiplier = 1.0,
                                                                                },
                                                                                .tags = std::vector<data::tag> {
                                                                                    data::tag {
                                                                                        .key = "type",
                                                                                        .value = "cache",
                                                                                    },
                                                                                },
                                                                            },
                                                                        },
                                                                    },
                                                                    .tags = std::vector<data::tag> {
                                                                        data::tag {
                                                                            .key = "pod",
                                                                            .value = "api-gateway-7d9f-xk2p9",
                                                                        },
                                                                    },
                                                                    .extra = boost::json::value { { "node", "ip-10-0-1-42" } },
                                                                    .nested = data::scope_override {
                                                                        .scope = "pod:api-gateway-7d9f-mn3q1",
                                                                        .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                        .tags = std::vector<data::tag> {
                                                                            data::tag {
                                                                                .key = "pod",
                                                                                .value = "api-gateway-7d9f-mn3q1",
                                                                            },
                                                                        },
                                                                        .extra = boost::json::object {},
                                                                        .nested = data::scope_override {
                                                                            .scope = "pod:worker-3a1c-pp7rz",
                                                                            .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                            .tags = std::vector<data::tag> {
                                                                                data::tag {
                                                                                    .key = "pod",
                                                                                    .value = "worker-3a1c-pp7rz",
                                                                                },
                                                                            },
                                                                            .extra = boost::json::object {},
                                                                            .nested = data::scope_override {
                                                                                .scope = "container:api",
                                                                                .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                .tags = std::vector<data::tag> {
                                                                                    data::tag {
                                                                                        .key = "container",
                                                                                        .value = "api",
                                                                                    },
                                                                                },
                                                                                .extra = boost::json::value { { "image", "api-gateway:v2.4.1" } },
                                                                                .nested = data::scope_override {
                                                                                    .scope = "container:sidecar-proxy",
                                                                                    .log_level = data::severity::error,
                                                                                    .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                    .tags = std::vector<data::tag> {
                                                                                        data::tag {
                                                                                            .key = "container",
                                                                                            .value = "sidecar-proxy",
                                                                                        },
                                                                                    },
                                                                                    .extra = boost::json::object {},
                                                                                    .nested = data::scope_override {
                                                                                        .scope = "container:log-collector",
                                                                                        .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                        .tags = std::vector<data::tag> {
                                                                                            data::tag {
                                                                                                .key = "container",
                                                                                                .value = "log-collector",
                                                                                            },
                                                                                        },
                                                                                        .extra = boost::json::object {},
                                                                                        .nested = data::scope_override {
                                                                                            .scope = "thread-pool:io",
                                                                                            .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                            .tags = std::vector<data::tag> {
                                                                                                data::tag {
                                                                                                    .key = "pool",
                                                                                                    .value = "io",
                                                                                                },
                                                                                            },
                                                                                            .extra = boost::json::value { { "size", 16 } },
                                                                                            .nested = data::scope_override {
                                                                                                .scope = "thread-pool:cpu",
                                                                                                .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                                .tags = std::vector<data::tag> {
                                                                                                    data::tag {
                                                                                                        .key = "pool",
                                                                                                        .value = "cpu",
                                                                                                    },
                                                                                                },
                                                                                                .extra = boost::json::value { { "size", 8 } },
                                                                                                .nested = data::scope_override {
                                                                                                    .scope = "thread-pool:background",
                                                                                                    .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                                    .tags = std::vector<data::tag> {
                                                                                                        data::tag {
                                                                                                            .key = "pool",
                                                                                                            .value = "background",
                                                                                                        },
                                                                                                    },
                                                                                                    .extra = boost::json::value { { "size", 4 } },
                                                                                                    .nested = data::scope_override {
                                                                                                        .scope = "goroutine-group:request-handlers",
                                                                                                        .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                                        .tags = std::vector<data::tag> {
                                                                                                            data::tag {
                                                                                                                .key = "group",
                                                                                                                .value = "request-handlers",
                                                                                                            },
                                                                                                        },
                                                                                                        .extra = boost::json::object {},
                                                                                                        .nested = data::scope_override {
                                                                                                            .scope = "goroutine-group:background-jobs",
                                                                                                            .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                                            .tags = std::vector<data::tag> {
                                                                                                                data::tag {
                                                                                                                    .key = "group",
                                                                                                                    .value = "background-jobs",
                                                                                                                },
                                                                                                            },
                                                                                                            .extra = boost::json::object {},
                                                                                                            .nested = data::scope_override {
                                                                                                                .scope = "goroutine-group:health-checks",
                                                                                                                .log_level = data::severity::warning,
                                                                                                                .retry = data::retry_policy {
                                                                                                                    .max_attempts = 2u,
                                                                                                                    .base_delay = 1000ms,
                                                                                                                    .backoff_multiplier = 1.0,
                                                                                                                    .deadline = 10s,
                                                                                                                },
                                                                                                                .endpoint_overrides = std::map<std::string, data::endpoint_config> {},
                                                                                                                .tags = std::vector<data::tag> {
                                                                                                                    data::tag {
                                                                                                                        .key = "group",
                                                                                                                        .value = "health-checks",
                                                                                                                    },
                                                                                                                },
                                                                                                                .extra = boost::json::value { { "interval", "15s" } },
                                                                                                            },
                                                                                                        },
                                                                                                    },
                                                                                                },
                                                                                            },
                                                                                        },
                                                                                    },
                                                                                },
                                                                            },
                                                                        },
                                                                    },
                                                                },
                                                            },
                                                        },
                                                    },
                                                },
                                            },
                                        },
                                    },
                                },
                            },
                        },
                    },
                },
            },
        },
        .admin_endpoint = data::network_address {
            .host = "127.0.0.1",
            .port = 9999,
        },
        .global_thresholds = std::map<std::string, std::vector<data::threshold_rule>> {
            {
                "cpu",
                std::vector<data::threshold_rule> {
                    data::threshold_rule {
                        .metric_name = "sys.cpu.usage",
                        .warn_at = 0.7,
                        .crit_at = 0.9,
                        .evaluation_window = 60s,
                    },
                },
            },
            {
                "memory",
                std::vector<data::threshold_rule> {
                    data::threshold_rule {
                        .metric_name = "sys.mem.usage",
                        .warn_at = 0.75,
                        .crit_at = 0.95,
                        .evaluation_window = 120s,
                    },
                },
            },
        },
        .shutdown_grace_period = 30s,
        .warmup_delay = 500ms,
    };

    ASSERT_DEEP_EQ(expected, got);
}