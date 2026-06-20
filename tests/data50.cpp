#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "deep_equal.hpp"
#include "gtest_formatter.hpp"
#include "json/exceptions.hpp"

// ─────────────────────────────────────────────────────────────────────────────

namespace
{

std::string_view json_50 = R"json(
{
  "service_name": "my-service",
  "worker_threads": 8,
  "enable_tracing": true,
  "backends": [{
    "name": "primary",
    "endpoints": [{
      "address": {"host": "primary.local", "port": 9000},
      "connect_timeout": "500ms",
      "retry": {"max_attempts": 3, "base_delay": "100ms", "backoff_multiplier": 2.0, "deadline": "30s"},
      "tls_cert_path": "/etc/certs/primary.pem",
      "tags": [{"key": "env", "value": "prod"}, {"key": "region", "value": "eu-west"}]
    }],
    "alerts": {
      "cpu": {"metric_name": "cpu_usage", "warn_at": 70.0, "crit_at": 90.0, "evaluation_window": "60s"}
    },
    "min_log_level": "info",
    "fallback_retry": {"max_attempts": 1, "base_delay": "200ms", "backoff_multiplier": 1.0, "deadline": null}
  }],
  "routes": {
    "api":    {"pattern": "/api/*", "backend_names": ["primary"], "timeout_override": "1500ms"},
    "health": {"pattern": "/health", "backend_names": ["primary"], "timeout_override": null}
  },
  "env": {"LOG_LEVEL": "info", "MAX_CONN": "100"},
  "rate_limits": [["user", 1000, true], ["anon", 100, false]],
  "allowed_origins": ["https://example.com", "https://app.example.com"],
  "config_tree": {"scope":"level_50","log_level":"info","endpoint_overrides":{"ep_50":{"address":{"host":"host50.local","port":10050},"connect_timeout":"5s","retry":{"max_attempts":51,"base_delay":"250ms","backoff_multiplier":4.00,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k50","value":"v50"}]}},"tags":[{"key":"depth","value":"50"}],"extra":null,"nested":{"scope":"level_49","log_level":"debug","endpoint_overrides":{"ep_49":{"address":{"host":"host49.local","port":10049},"connect_timeout":"4900ms","retry":{"max_attempts":50,"base_delay":"245ms","backoff_multiplier":3.95,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k49","value":"v49"}]}},"tags":[{"key":"depth","value":"49"}],"extra":null,"nested":{"scope":"level_48","log_level":null,"retry":{"max_attempts":48,"base_delay":"480ms","backoff_multiplier":5.80,"deadline":"4m"},"endpoint_overrides":{"ep_48":{"address":{"host":"host48.local","port":10048},"connect_timeout":"4800ms","retry":{"max_attempts":49,"base_delay":"240ms","backoff_multiplier":3.90,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k48","value":"v48"}]}},"tags":[{"key":"depth","value":"48"}],"extra":null,"nested":{"scope":"level_47","log_level":"critical","endpoint_overrides":{"ep_47":{"address":{"host":"host47.local","port":10047},"connect_timeout":"4700ms","retry":{"max_attempts":48,"base_delay":"235ms","backoff_multiplier":3.85,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k47","value":"v47"}]}},"tags":[{"key":"depth","value":"47"}],"extra":null,"nested":{"scope":"level_46","log_level":"error","endpoint_overrides":{"ep_46":{"address":{"host":"host46.local","port":10046},"connect_timeout":"4600ms","retry":{"max_attempts":47,"base_delay":"230ms","backoff_multiplier":3.80,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k46","value":"v46"}]}},"tags":[{"key":"depth","value":"46"}],"extra":null,"nested":{"scope":"level_45","log_level":"warning","retry":{"max_attempts":45,"base_delay":"450ms","backoff_multiplier":5.50,"deadline":"225s"},"endpoint_overrides":{"ep_45":{"address":{"host":"host45.local","port":10045},"connect_timeout":"4500ms","retry":{"max_attempts":46,"base_delay":"225ms","backoff_multiplier":3.75,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k45","value":"v45"}]}},"tags":[{"key":"depth","value":"45"}],"extra":null,"nested":{"scope":"level_44","log_level":"info","endpoint_overrides":{"ep_44":{"address":{"host":"host44.local","port":10044},"connect_timeout":"4400ms","retry":{"max_attempts":45,"base_delay":"220ms","backoff_multiplier":3.70,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k44","value":"v44"}]}},"tags":[{"key":"depth","value":"44"}],"extra":null,"nested":{"scope":"level_43","log_level":"debug","endpoint_overrides":{"ep_43":{"address":{"host":"host43.local","port":10043},"connect_timeout":"4300ms","retry":{"max_attempts":44,"base_delay":"215ms","backoff_multiplier":3.65,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k43","value":"v43"}]}},"tags":[{"key":"depth","value":"43"}],"extra":null,"nested":{"scope":"level_42","log_level":null,"retry":{"max_attempts":42,"base_delay":"420ms","backoff_multiplier":5.20,"deadline":"210s"},"endpoint_overrides":{"ep_42":{"address":{"host":"host42.local","port":10042},"connect_timeout":"4200ms","retry":{"max_attempts":43,"base_delay":"210ms","backoff_multiplier":3.60,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k42","value":"v42"}]}},"tags":[{"key":"depth","value":"42"}],"extra":null,"nested":{"scope":"level_41","log_level":"critical","endpoint_overrides":{"ep_41":{"address":{"host":"host41.local","port":10041},"connect_timeout":"4100ms","retry":{"max_attempts":42,"base_delay":"205ms","backoff_multiplier":3.55,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k41","value":"v41"}]}},"tags":[{"key":"depth","value":"41"}],"extra":null,"nested":{"scope":"level_40","log_level":"error","endpoint_overrides":{"ep_40":{"address":{"host":"host40.local","port":10040},"connect_timeout":"4s","retry":{"max_attempts":41,"base_delay":"200ms","backoff_multiplier":3.50,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k40","value":"v40"}]}},"tags":[{"key":"depth","value":"40"}],"extra":null,"nested":{"scope":"level_39","log_level":"warning","retry":{"max_attempts":39,"base_delay":"390ms","backoff_multiplier":4.90,"deadline":"195s"},"endpoint_overrides":{"ep_39":{"address":{"host":"host39.local","port":10039},"connect_timeout":"3900ms","retry":{"max_attempts":40,"base_delay":"195ms","backoff_multiplier":3.45,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k39","value":"v39"}]}},"tags":[{"key":"depth","value":"39"}],"extra":null,"nested":{"scope":"level_38","log_level":"info","endpoint_overrides":{"ep_38":{"address":{"host":"host38.local","port":10038},"connect_timeout":"3800ms","retry":{"max_attempts":39,"base_delay":"190ms","backoff_multiplier":3.40,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k38","value":"v38"}]}},"tags":[{"key":"depth","value":"38"}],"extra":null,"nested":{"scope":"level_37","log_level":"debug","endpoint_overrides":{"ep_37":{"address":{"host":"host37.local","port":10037},"connect_timeout":"3700ms","retry":{"max_attempts":38,"base_delay":"185ms","backoff_multiplier":3.35,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k37","value":"v37"}]}},"tags":[{"key":"depth","value":"37"}],"extra":null,"nested":{"scope":"level_36","log_level":null,"retry":{"max_attempts":36,"base_delay":"360ms","backoff_multiplier":4.60,"deadline":"3m"},"endpoint_overrides":{"ep_36":{"address":{"host":"host36.local","port":10036},"connect_timeout":"3600ms","retry":{"max_attempts":37,"base_delay":"180ms","backoff_multiplier":3.30,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k36","value":"v36"}]}},"tags":[{"key":"depth","value":"36"}],"extra":null,"nested":{"scope":"level_35","log_level":"critical","endpoint_overrides":{"ep_35":{"address":{"host":"host35.local","port":10035},"connect_timeout":"3500ms","retry":{"max_attempts":36,"base_delay":"175ms","backoff_multiplier":3.25,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k35","value":"v35"}]}},"tags":[{"key":"depth","value":"35"}],"extra":null,"nested":{"scope":"level_34","log_level":"error","endpoint_overrides":{"ep_34":{"address":{"host":"host34.local","port":10034},"connect_timeout":"3400ms","retry":{"max_attempts":35,"base_delay":"170ms","backoff_multiplier":3.20,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k34","value":"v34"}]}},"tags":[{"key":"depth","value":"34"}],"extra":null,"nested":{"scope":"level_33","log_level":"warning","retry":{"max_attempts":33,"base_delay":"330ms","backoff_multiplier":4.30,"deadline":"165s"},"endpoint_overrides":{"ep_33":{"address":{"host":"host33.local","port":10033},"connect_timeout":"3300ms","retry":{"max_attempts":34,"base_delay":"165ms","backoff_multiplier":3.15,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k33","value":"v33"}]}},"tags":[{"key":"depth","value":"33"}],"extra":null,"nested":{"scope":"level_32","log_level":"info","endpoint_overrides":{"ep_32":{"address":{"host":"host32.local","port":10032},"connect_timeout":"3200ms","retry":{"max_attempts":33,"base_delay":"160ms","backoff_multiplier":3.10,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k32","value":"v32"}]}},"tags":[{"key":"depth","value":"32"}],"extra":null,"nested":{"scope":"level_31","log_level":"debug","endpoint_overrides":{"ep_31":{"address":{"host":"host31.local","port":10031},"connect_timeout":"3100ms","retry":{"max_attempts":32,"base_delay":"155ms","backoff_multiplier":3.05,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k31","value":"v31"}]}},"tags":[{"key":"depth","value":"31"}],"extra":null,"nested":{"scope":"level_30","log_level":null,"retry":{"max_attempts":30,"base_delay":"300ms","backoff_multiplier":4.00,"deadline":"150s"},"endpoint_overrides":{"ep_30":{"address":{"host":"host30.local","port":10030},"connect_timeout":"3s","retry":{"max_attempts":31,"base_delay":"150ms","backoff_multiplier":3.00,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k30","value":"v30"}]}},"tags":[{"key":"depth","value":"30"}],"extra":null,"nested":{"scope":"level_29","log_level":"critical","endpoint_overrides":{"ep_29":{"address":{"host":"host29.local","port":10029},"connect_timeout":"2900ms","retry":{"max_attempts":30,"base_delay":"145ms","backoff_multiplier":2.95,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k29","value":"v29"}]}},"tags":[{"key":"depth","value":"29"}],"extra":null,"nested":{"scope":"level_28","log_level":"error","endpoint_overrides":{"ep_28":{"address":{"host":"host28.local","port":10028},"connect_timeout":"2800ms","retry":{"max_attempts":29,"base_delay":"140ms","backoff_multiplier":2.90,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k28","value":"v28"}]}},"tags":[{"key":"depth","value":"28"}],"extra":null,"nested":{"scope":"level_27","log_level":"warning","retry":{"max_attempts":27,"base_delay":"270ms","backoff_multiplier":3.70,"deadline":"135s"},"endpoint_overrides":{"ep_27":{"address":{"host":"host27.local","port":10027},"connect_timeout":"2700ms","retry":{"max_attempts":28,"base_delay":"135ms","backoff_multiplier":2.85,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k27","value":"v27"}]}},"tags":[{"key":"depth","value":"27"}],"extra":null,"nested":{"scope":"level_26","log_level":"info","endpoint_overrides":{"ep_26":{"address":{"host":"host26.local","port":10026},"connect_timeout":"2600ms","retry":{"max_attempts":27,"base_delay":"130ms","backoff_multiplier":2.80,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k26","value":"v26"}]}},"tags":[{"key":"depth","value":"26"}],"extra":null,"nested":{"scope":"level_25","log_level":"debug","endpoint_overrides":{"ep_25":{"address":{"host":"host25.local","port":10025},"connect_timeout":"2500ms","retry":{"max_attempts":26,"base_delay":"125ms","backoff_multiplier":2.75,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k25","value":"v25"}]}},"tags":[{"key":"depth","value":"25"}],"extra":null,"nested":{"scope":"level_24","log_level":null,"retry":{"max_attempts":24,"base_delay":"240ms","backoff_multiplier":3.40,"deadline":"2m"},"endpoint_overrides":{"ep_24":{"address":{"host":"host24.local","port":10024},"connect_timeout":"2400ms","retry":{"max_attempts":25,"base_delay":"120ms","backoff_multiplier":2.70,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k24","value":"v24"}]}},"tags":[{"key":"depth","value":"24"}],"extra":null,"nested":{"scope":"level_23","log_level":"critical","endpoint_overrides":{"ep_23":{"address":{"host":"host23.local","port":10023},"connect_timeout":"2300ms","retry":{"max_attempts":24,"base_delay":"115ms","backoff_multiplier":2.65,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k23","value":"v23"}]}},"tags":[{"key":"depth","value":"23"}],"extra":null,"nested":{"scope":"level_22","log_level":"error","endpoint_overrides":{"ep_22":{"address":{"host":"host22.local","port":10022},"connect_timeout":"2200ms","retry":{"max_attempts":23,"base_delay":"110ms","backoff_multiplier":2.60,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k22","value":"v22"}]}},"tags":[{"key":"depth","value":"22"}],"extra":null,"nested":{"scope":"level_21","log_level":"warning","retry":{"max_attempts":21,"base_delay":"210ms","backoff_multiplier":3.10,"deadline":"105s"},"endpoint_overrides":{"ep_21":{"address":{"host":"host21.local","port":10021},"connect_timeout":"2100ms","retry":{"max_attempts":22,"base_delay":"105ms","backoff_multiplier":2.55,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k21","value":"v21"}]}},"tags":[{"key":"depth","value":"21"}],"extra":null,"nested":{"scope":"level_20","log_level":"info","endpoint_overrides":{"ep_20":{"address":{"host":"host20.local","port":10020},"connect_timeout":"2s","retry":{"max_attempts":21,"base_delay":"100ms","backoff_multiplier":2.50,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k20","value":"v20"}]}},"tags":[{"key":"depth","value":"20"}],"extra":null,"nested":{"scope":"level_19","log_level":"debug","endpoint_overrides":{"ep_19":{"address":{"host":"host19.local","port":10019},"connect_timeout":"1900ms","retry":{"max_attempts":20,"base_delay":"95ms","backoff_multiplier":2.45,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k19","value":"v19"}]}},"tags":[{"key":"depth","value":"19"}],"extra":null,"nested":{"scope":"level_18","log_level":null,"retry":{"max_attempts":18,"base_delay":"180ms","backoff_multiplier":2.80,"deadline":"90s"},"endpoint_overrides":{"ep_18":{"address":{"host":"host18.local","port":10018},"connect_timeout":"1800ms","retry":{"max_attempts":19,"base_delay":"90ms","backoff_multiplier":2.40,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k18","value":"v18"}]}},"tags":[{"key":"depth","value":"18"}],"extra":null,"nested":{"scope":"level_17","log_level":"critical","endpoint_overrides":{"ep_17":{"address":{"host":"host17.local","port":10017},"connect_timeout":"1700ms","retry":{"max_attempts":18,"base_delay":"85ms","backoff_multiplier":2.35,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k17","value":"v17"}]}},"tags":[{"key":"depth","value":"17"}],"extra":null,"nested":{"scope":"level_16","log_level":"error","endpoint_overrides":{"ep_16":{"address":{"host":"host16.local","port":10016},"connect_timeout":"1600ms","retry":{"max_attempts":17,"base_delay":"80ms","backoff_multiplier":2.30,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k16","value":"v16"}]}},"tags":[{"key":"depth","value":"16"}],"extra":null,"nested":{"scope":"level_15","log_level":"warning","retry":{"max_attempts":15,"base_delay":"150ms","backoff_multiplier":2.50,"deadline":"75s"},"endpoint_overrides":{"ep_15":{"address":{"host":"host15.local","port":10015},"connect_timeout":"1500ms","retry":{"max_attempts":16,"base_delay":"75ms","backoff_multiplier":2.25,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k15","value":"v15"}]}},"tags":[{"key":"depth","value":"15"}],"extra":null,"nested":{"scope":"level_14","log_level":"info","endpoint_overrides":{"ep_14":{"address":{"host":"host14.local","port":10014},"connect_timeout":"1400ms","retry":{"max_attempts":15,"base_delay":"70ms","backoff_multiplier":2.20,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k14","value":"v14"}]}},"tags":[{"key":"depth","value":"14"}],"extra":null,"nested":{"scope":"level_13","log_level":"debug","endpoint_overrides":{"ep_13":{"address":{"host":"host13.local","port":10013},"connect_timeout":"1300ms","retry":{"max_attempts":14,"base_delay":"65ms","backoff_multiplier":2.15,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k13","value":"v13"}]}},"tags":[{"key":"depth","value":"13"}],"extra":null,"nested":{"scope":"level_12","log_level":null,"retry":{"max_attempts":12,"base_delay":"120ms","backoff_multiplier":2.20,"deadline":"1m"},"endpoint_overrides":{"ep_12":{"address":{"host":"host12.local","port":10012},"connect_timeout":"1200ms","retry":{"max_attempts":13,"base_delay":"60ms","backoff_multiplier":2.10,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k12","value":"v12"}]}},"tags":[{"key":"depth","value":"12"}],"extra":null,"nested":{"scope":"level_11","log_level":"critical","endpoint_overrides":{"ep_11":{"address":{"host":"host11.local","port":10011},"connect_timeout":"1100ms","retry":{"max_attempts":12,"base_delay":"55ms","backoff_multiplier":2.05,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k11","value":"v11"}]}},"tags":[{"key":"depth","value":"11"}],"extra":null,"nested":{"scope":"level_10","log_level":"error","endpoint_overrides":{"ep_10":{"address":{"host":"host10.local","port":10010},"connect_timeout":"1s","retry":{"max_attempts":11,"base_delay":"50ms","backoff_multiplier":2.00,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k10","value":"v10"}]}},"tags":[{"key":"depth","value":"10"}],"extra":null,"nested":{"scope":"level_9","log_level":"warning","retry":{"max_attempts":9,"base_delay":"90ms","backoff_multiplier":1.90,"deadline":"45s"},"endpoint_overrides":{"ep_9":{"address":{"host":"host9.local","port":10009},"connect_timeout":"900ms","retry":{"max_attempts":10,"base_delay":"45ms","backoff_multiplier":1.95,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k9","value":"v9"}]}},"tags":[{"key":"depth","value":"9"}],"extra":null,"nested":{"scope":"level_8","log_level":"info","endpoint_overrides":{"ep_8":{"address":{"host":"host8.local","port":10008},"connect_timeout":"800ms","retry":{"max_attempts":9,"base_delay":"40ms","backoff_multiplier":1.90,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k8","value":"v8"}]}},"tags":[{"key":"depth","value":"8"}],"extra":null,"nested":{"scope":"level_7","log_level":"debug","endpoint_overrides":{"ep_7":{"address":{"host":"host7.local","port":10007},"connect_timeout":"700ms","retry":{"max_attempts":8,"base_delay":"35ms","backoff_multiplier":1.85,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k7","value":"v7"}]}},"tags":[{"key":"depth","value":"7"}],"extra":null,"nested":{"scope":"level_6","log_level":null,"retry":{"max_attempts":6,"base_delay":"60ms","backoff_multiplier":1.60,"deadline":"30s"},"endpoint_overrides":{"ep_6":{"address":{"host":"host6.local","port":10006},"connect_timeout":"600ms","retry":{"max_attempts":7,"base_delay":"30ms","backoff_multiplier":1.80,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k6","value":"v6"}]}},"tags":[{"key":"depth","value":"6"}],"extra":null,"nested":{"scope":"level_5","log_level":"critical","endpoint_overrides":{"ep_5":{"address":{"host":"host5.local","port":10005},"connect_timeout":"500ms","retry":{"max_attempts":6,"base_delay":"25ms","backoff_multiplier":1.75,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k5","value":"v5"}]}},"tags":[{"key":"depth","value":"5"}],"extra":null,"nested":{"scope":"level_4","log_level":"error","endpoint_overrides":{"ep_4":{"address":{"host":"host4.local","port":10004},"connect_timeout":"400ms","retry":{"max_attempts":5,"base_delay":"20ms","backoff_multiplier":1.70,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k4","value":"v4"}]}},"tags":[{"key":"depth","value":"4"}],"extra":null,"nested":{"scope":"level_3","log_level":"warning","retry":{"max_attempts":3,"base_delay":"30ms","backoff_multiplier":1.30,"deadline":"15s"},"endpoint_overrides":{"ep_3":{"address":{"host":"host3.local","port":10003},"connect_timeout":"300ms","retry":{"max_attempts":4,"base_delay":"15ms","backoff_multiplier":1.65,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k3","value":"v3"}]}},"tags":[{"key":"depth","value":"3"}],"extra":null,"nested":{"scope":"level_2","log_level":"info","endpoint_overrides":{"ep_2":{"address":{"host":"host2.local","port":10002},"connect_timeout":"200ms","retry":{"max_attempts":3,"base_delay":"10ms","backoff_multiplier":1.60,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k2","value":"v2"}]}},"tags":[{"key":"depth","value":"2"}],"extra":null,"nested":{"scope":"level_1","log_level":"debug","endpoint_overrides":{"ep_1":{"address":{"host":"host1.local","port":10001},"connect_timeout":"100ms","retry":{"max_attempts":2,"base_delay":"5ms","backoff_multiplier":1.55,"deadline":null},"tls_cert_path":null,"tags":[{"key":"k1","value":"v1"}]}},"tags":[{"key":"depth","value":"1"}],"extra":null,"nested":{"scope":"leaf","log_level":null,"endpoint_overrides":{},"tags":[],"extra":null,"nested":null}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}},
  "admin_endpoint": {"host": "admin.local", "port": 8080},
  "global_thresholds": {
    "memory": [{"metric_name": "mem_usage", "warn_at": 75.0, "crit_at": 95.0, "evaluation_window": "2m"}]
  },
  "shutdown_grace_period": "15s",
  "warmup_delay": "2s"
}
)json";

} // namespace

// ─────────────────────────────────────────────────────────────────────────────

TEST(service_config_parse, ServiceConfig50Ok)
{
    using namespace std::chrono_literals;

    const auto parsed = json::exceptions::as<data::service_config>(json_50);

    const data::service_config expected = {
        .service_name          = "my-service",
        .worker_threads        = 8u,
        .enable_tracing        = true,
        .backends              = std::vector<data::backend_group>{
            data::backend_group{
                .name      = "primary",
                .endpoints = std::vector<data::endpoint_config>{
                    data::endpoint_config{
                        .address         = data::network_address{.host = "primary.local", .port = 9000},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.0,
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
                        .warn_at           = 70.0,
                        .crit_at           = 90.0,
                        .evaluation_window = 1min,
                    }},
                },
                .min_log_level = data::severity::info,
                .fallback_retry= data::retry_policy{
                    .max_attempts       = 1u,
                    .base_delay         = 200ms,
                    .backoff_multiplier = 1.0,
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
            {"MAX_CONN",  "100"},
        },
        .rate_limits           = std::vector<data::rate_limit_entry>{
            data::rate_limit_entry{"user", 1000u, true},
            data::rate_limit_entry{"anon",  100u, false},
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
                        .address         = data::network_address{.host = "host50.local", .port = 10050},
                        .connect_timeout = 5s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 51u,
                            .base_delay         = 250ms,
                            .backoff_multiplier = 4.00,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k50", .value = "v50"}},
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
                        .address         = data::network_address{.host = "host49.local", .port = 10049},
                        .connect_timeout = 4900ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 50u,
                            .base_delay         = 245ms,
                            .backoff_multiplier = 3.95,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k49", .value = "v49"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "49"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_48",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 48u,
                    .base_delay         = 480ms,
                    .backoff_multiplier = 5.80,
                    .deadline           = 4min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_48", data::endpoint_config{
                        .address         = data::network_address{.host = "host48.local", .port = 10048},
                        .connect_timeout = 4800ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 49u,
                            .base_delay         = 240ms,
                            .backoff_multiplier = 3.90,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k48", .value = "v48"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "48"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_47",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_47", data::endpoint_config{
                        .address         = data::network_address{.host = "host47.local", .port = 10047},
                        .connect_timeout = 4700ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 48u,
                            .base_delay         = 235ms,
                            .backoff_multiplier = 3.85,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k47", .value = "v47"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "47"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_46",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_46", data::endpoint_config{
                        .address         = data::network_address{.host = "host46.local", .port = 10046},
                        .connect_timeout = 4600ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 47u,
                            .base_delay         = 230ms,
                            .backoff_multiplier = 3.80,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k46", .value = "v46"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "46"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_45",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 45u,
                    .base_delay         = 450ms,
                    .backoff_multiplier = 5.50,
                    .deadline           = 225s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_45", data::endpoint_config{
                        .address         = data::network_address{.host = "host45.local", .port = 10045},
                        .connect_timeout = 4500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 46u,
                            .base_delay         = 225ms,
                            .backoff_multiplier = 3.75,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k45", .value = "v45"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "45"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_44",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_44", data::endpoint_config{
                        .address         = data::network_address{.host = "host44.local", .port = 10044},
                        .connect_timeout = 4400ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 45u,
                            .base_delay         = 220ms,
                            .backoff_multiplier = 3.70,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k44", .value = "v44"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "44"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_43",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_43", data::endpoint_config{
                        .address         = data::network_address{.host = "host43.local", .port = 10043},
                        .connect_timeout = 4300ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 44u,
                            .base_delay         = 215ms,
                            .backoff_multiplier = 3.65,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k43", .value = "v43"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "43"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_42",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 42u,
                    .base_delay         = 420ms,
                    .backoff_multiplier = 5.20,
                    .deadline           = 210s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_42", data::endpoint_config{
                        .address         = data::network_address{.host = "host42.local", .port = 10042},
                        .connect_timeout = 4200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 43u,
                            .base_delay         = 210ms,
                            .backoff_multiplier = 3.60,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k42", .value = "v42"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "42"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_41",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_41", data::endpoint_config{
                        .address         = data::network_address{.host = "host41.local", .port = 10041},
                        .connect_timeout = 4100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 42u,
                            .base_delay         = 205ms,
                            .backoff_multiplier = 3.55,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k41", .value = "v41"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "41"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_40",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_40", data::endpoint_config{
                        .address         = data::network_address{.host = "host40.local", .port = 10040},
                        .connect_timeout = 4s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 41u,
                            .base_delay         = 200ms,
                            .backoff_multiplier = 3.50,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k40", .value = "v40"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "40"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_39",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 39u,
                    .base_delay         = 390ms,
                    .backoff_multiplier = 4.90,
                    .deadline           = 195s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_39", data::endpoint_config{
                        .address         = data::network_address{.host = "host39.local", .port = 10039},
                        .connect_timeout = 3900ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 40u,
                            .base_delay         = 195ms,
                            .backoff_multiplier = 3.45,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k39", .value = "v39"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "39"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_38",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_38", data::endpoint_config{
                        .address         = data::network_address{.host = "host38.local", .port = 10038},
                        .connect_timeout = 3800ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 39u,
                            .base_delay         = 190ms,
                            .backoff_multiplier = 3.40,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k38", .value = "v38"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "38"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_37",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_37", data::endpoint_config{
                        .address         = data::network_address{.host = "host37.local", .port = 10037},
                        .connect_timeout = 3700ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 38u,
                            .base_delay         = 185ms,
                            .backoff_multiplier = 3.35,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k37", .value = "v37"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "37"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_36",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 36u,
                    .base_delay         = 360ms,
                    .backoff_multiplier = 4.60,
                    .deadline           = 3min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_36", data::endpoint_config{
                        .address         = data::network_address{.host = "host36.local", .port = 10036},
                        .connect_timeout = 3600ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 37u,
                            .base_delay         = 180ms,
                            .backoff_multiplier = 3.30,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k36", .value = "v36"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "36"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_35",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_35", data::endpoint_config{
                        .address         = data::network_address{.host = "host35.local", .port = 10035},
                        .connect_timeout = 3500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 36u,
                            .base_delay         = 175ms,
                            .backoff_multiplier = 3.25,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k35", .value = "v35"}},
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
                        .address         = data::network_address{.host = "host34.local", .port = 10034},
                        .connect_timeout = 3400ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 35u,
                            .base_delay         = 170ms,
                            .backoff_multiplier = 3.20,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k34", .value = "v34"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "34"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_33",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 33u,
                    .base_delay         = 330ms,
                    .backoff_multiplier = 4.30,
                    .deadline           = 165s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_33", data::endpoint_config{
                        .address         = data::network_address{.host = "host33.local", .port = 10033},
                        .connect_timeout = 3300ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 34u,
                            .base_delay         = 165ms,
                            .backoff_multiplier = 3.15,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k33", .value = "v33"}},
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
                        .address         = data::network_address{.host = "host32.local", .port = 10032},
                        .connect_timeout = 3200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 33u,
                            .base_delay         = 160ms,
                            .backoff_multiplier = 3.10,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k32", .value = "v32"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "32"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_31",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_31", data::endpoint_config{
                        .address         = data::network_address{.host = "host31.local", .port = 10031},
                        .connect_timeout = 3100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 32u,
                            .base_delay         = 155ms,
                            .backoff_multiplier = 3.05,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k31", .value = "v31"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "31"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_30",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 30u,
                    .base_delay         = 300ms,
                    .backoff_multiplier = 4.00,
                    .deadline           = 150s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_30", data::endpoint_config{
                        .address         = data::network_address{.host = "host30.local", .port = 10030},
                        .connect_timeout = 3s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 31u,
                            .base_delay         = 150ms,
                            .backoff_multiplier = 3.00,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k30", .value = "v30"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "30"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_29",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_29", data::endpoint_config{
                        .address         = data::network_address{.host = "host29.local", .port = 10029},
                        .connect_timeout = 2900ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 30u,
                            .base_delay         = 145ms,
                            .backoff_multiplier = 2.95,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k29", .value = "v29"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "29"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_28",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_28", data::endpoint_config{
                        .address         = data::network_address{.host = "host28.local", .port = 10028},
                        .connect_timeout = 2800ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 29u,
                            .base_delay         = 140ms,
                            .backoff_multiplier = 2.90,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k28", .value = "v28"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "28"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_27",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 27u,
                    .base_delay         = 270ms,
                    .backoff_multiplier = 3.70,
                    .deadline           = 135s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_27", data::endpoint_config{
                        .address         = data::network_address{.host = "host27.local", .port = 10027},
                        .connect_timeout = 2700ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 28u,
                            .base_delay         = 135ms,
                            .backoff_multiplier = 2.85,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k27", .value = "v27"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "27"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_26",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_26", data::endpoint_config{
                        .address         = data::network_address{.host = "host26.local", .port = 10026},
                        .connect_timeout = 2600ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 27u,
                            .base_delay         = 130ms,
                            .backoff_multiplier = 2.80,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k26", .value = "v26"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "26"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_25",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_25", data::endpoint_config{
                        .address         = data::network_address{.host = "host25.local", .port = 10025},
                        .connect_timeout = 2500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 26u,
                            .base_delay         = 125ms,
                            .backoff_multiplier = 2.75,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k25", .value = "v25"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "25"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_24",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 24u,
                    .base_delay         = 240ms,
                    .backoff_multiplier = 3.40,
                    .deadline           = 2min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_24", data::endpoint_config{
                        .address         = data::network_address{.host = "host24.local", .port = 10024},
                        .connect_timeout = 2400ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 25u,
                            .base_delay         = 120ms,
                            .backoff_multiplier = 2.70,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k24", .value = "v24"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "24"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_23",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_23", data::endpoint_config{
                        .address         = data::network_address{.host = "host23.local", .port = 10023},
                        .connect_timeout = 2300ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 24u,
                            .base_delay         = 115ms,
                            .backoff_multiplier = 2.65,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k23", .value = "v23"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "23"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_22",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_22", data::endpoint_config{
                        .address         = data::network_address{.host = "host22.local", .port = 10022},
                        .connect_timeout = 2200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 23u,
                            .base_delay         = 110ms,
                            .backoff_multiplier = 2.60,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k22", .value = "v22"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "22"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_21",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 21u,
                    .base_delay         = 210ms,
                    .backoff_multiplier = 3.10,
                    .deadline           = 105s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_21", data::endpoint_config{
                        .address         = data::network_address{.host = "host21.local", .port = 10021},
                        .connect_timeout = 2100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 22u,
                            .base_delay         = 105ms,
                            .backoff_multiplier = 2.55,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k21", .value = "v21"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "21"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_20",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_20", data::endpoint_config{
                        .address         = data::network_address{.host = "host20.local", .port = 10020},
                        .connect_timeout = 2s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 21u,
                            .base_delay         = 100ms,
                            .backoff_multiplier = 2.50,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k20", .value = "v20"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "20"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_19",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_19", data::endpoint_config{
                        .address         = data::network_address{.host = "host19.local", .port = 10019},
                        .connect_timeout = 1900ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 20u,
                            .base_delay         = 95ms,
                            .backoff_multiplier = 2.45,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k19", .value = "v19"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "19"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_18",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 18u,
                    .base_delay         = 180ms,
                    .backoff_multiplier = 2.80,
                    .deadline           = 90s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_18", data::endpoint_config{
                        .address         = data::network_address{.host = "host18.local", .port = 10018},
                        .connect_timeout = 1800ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 19u,
                            .base_delay         = 90ms,
                            .backoff_multiplier = 2.40,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k18", .value = "v18"}},
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
                        .address         = data::network_address{.host = "host17.local", .port = 10017},
                        .connect_timeout = 1700ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 18u,
                            .base_delay         = 85ms,
                            .backoff_multiplier = 2.35,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k17", .value = "v17"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "17"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_16",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_16", data::endpoint_config{
                        .address         = data::network_address{.host = "host16.local", .port = 10016},
                        .connect_timeout = 1600ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 17u,
                            .base_delay         = 80ms,
                            .backoff_multiplier = 2.30,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k16", .value = "v16"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "16"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_15",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 15u,
                    .base_delay         = 150ms,
                    .backoff_multiplier = 2.50,
                    .deadline           = 75s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_15", data::endpoint_config{
                        .address         = data::network_address{.host = "host15.local", .port = 10015},
                        .connect_timeout = 1500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 16u,
                            .base_delay         = 75ms,
                            .backoff_multiplier = 2.25,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k15", .value = "v15"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "15"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_14",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_14", data::endpoint_config{
                        .address         = data::network_address{.host = "host14.local", .port = 10014},
                        .connect_timeout = 1400ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 15u,
                            .base_delay         = 70ms,
                            .backoff_multiplier = 2.20,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k14", .value = "v14"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "14"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_13",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_13", data::endpoint_config{
                        .address         = data::network_address{.host = "host13.local", .port = 10013},
                        .connect_timeout = 1300ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 14u,
                            .base_delay         = 65ms,
                            .backoff_multiplier = 2.15,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k13", .value = "v13"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "13"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_12",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 12u,
                    .base_delay         = 120ms,
                    .backoff_multiplier = 2.20,
                    .deadline           = 1min,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_12", data::endpoint_config{
                        .address         = data::network_address{.host = "host12.local", .port = 10012},
                        .connect_timeout = 1200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 13u,
                            .base_delay         = 60ms,
                            .backoff_multiplier = 2.10,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k12", .value = "v12"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "12"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_11",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_11", data::endpoint_config{
                        .address         = data::network_address{.host = "host11.local", .port = 10011},
                        .connect_timeout = 1100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 12u,
                            .base_delay         = 55ms,
                            .backoff_multiplier = 2.05,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k11", .value = "v11"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "11"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_10",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_10", data::endpoint_config{
                        .address         = data::network_address{.host = "host10.local", .port = 10010},
                        .connect_timeout = 1s,
                        .retry           = data::retry_policy{
                            .max_attempts       = 11u,
                            .base_delay         = 50ms,
                            .backoff_multiplier = 2.00,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k10", .value = "v10"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "10"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_9",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 9u,
                    .base_delay         = 90ms,
                    .backoff_multiplier = 1.90,
                    .deadline           = 45s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_9", data::endpoint_config{
                        .address         = data::network_address{.host = "host9.local", .port = 10009},
                        .connect_timeout = 900ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 10u,
                            .base_delay         = 45ms,
                            .backoff_multiplier = 1.95,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k9", .value = "v9"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "9"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_8",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_8", data::endpoint_config{
                        .address         = data::network_address{.host = "host8.local", .port = 10008},
                        .connect_timeout = 800ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 9u,
                            .base_delay         = 40ms,
                            .backoff_multiplier = 1.90,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k8", .value = "v8"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "8"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_7",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_7", data::endpoint_config{
                        .address         = data::network_address{.host = "host7.local", .port = 10007},
                        .connect_timeout = 700ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 8u,
                            .base_delay         = 35ms,
                            .backoff_multiplier = 1.85,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k7", .value = "v7"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "7"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_6",
                .log_level          = std::nullopt,
                .retry              = data::retry_policy{
                    .max_attempts       = 6u,
                    .base_delay         = 60ms,
                    .backoff_multiplier = 1.60,
                    .deadline           = 30s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_6", data::endpoint_config{
                        .address         = data::network_address{.host = "host6.local", .port = 10006},
                        .connect_timeout = 600ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 7u,
                            .base_delay         = 30ms,
                            .backoff_multiplier = 1.80,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k6", .value = "v6"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "6"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_5",
                .log_level          = data::severity::critical,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_5", data::endpoint_config{
                        .address         = data::network_address{.host = "host5.local", .port = 10005},
                        .connect_timeout = 500ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 6u,
                            .base_delay         = 25ms,
                            .backoff_multiplier = 1.75,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k5", .value = "v5"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "5"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_4",
                .log_level          = data::severity::error,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_4", data::endpoint_config{
                        .address         = data::network_address{.host = "host4.local", .port = 10004},
                        .connect_timeout = 400ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 5u,
                            .base_delay         = 20ms,
                            .backoff_multiplier = 1.70,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k4", .value = "v4"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "4"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_3",
                .log_level          = data::severity::warning,
                .retry              = data::retry_policy{
                    .max_attempts       = 3u,
                    .base_delay         = 30ms,
                    .backoff_multiplier = 1.30,
                    .deadline           = 15s,
                },
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_3", data::endpoint_config{
                        .address         = data::network_address{.host = "host3.local", .port = 10003},
                        .connect_timeout = 300ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 4u,
                            .base_delay         = 15ms,
                            .backoff_multiplier = 1.65,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k3", .value = "v3"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "3"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_2",
                .log_level          = data::severity::info,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_2", data::endpoint_config{
                        .address         = data::network_address{.host = "host2.local", .port = 10002},
                        .connect_timeout = 200ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 3u,
                            .base_delay         = 10ms,
                            .backoff_multiplier = 1.60,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k2", .value = "v2"}},
                    }},
                },
                .tags               = std::vector<data::tag>{data::tag{.key = "depth", .value = "2"}},
                .extra              = boost::json::value{},
                .nested             = common::box<data::scope_override>{data::scope_override{
                data::scope_override{
                .scope              = "level_1",
                .log_level          = data::severity::debug,
                .retry              = std::nullopt,
                .endpoint_overrides = std::map<std::string, data::endpoint_config>{
                    {"ep_1", data::endpoint_config{
                        .address         = data::network_address{.host = "host1.local", .port = 10001},
                        .connect_timeout = 100ms,
                        .retry           = data::retry_policy{
                            .max_attempts       = 2u,
                            .base_delay         = 5ms,
                            .backoff_multiplier = 1.55,
                            .deadline           = std::nullopt,
                        },
                        .tls_cert_path   = std::nullopt,
                        .tags            = std::vector<data::tag>{data::tag{.key = "k1", .value = "v1"}},
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
        .admin_endpoint        = data::network_address{.host = "admin.local", .port = 8080},
        .global_thresholds     = std::map<std::string, std::vector<data::threshold_rule>>{
            {"memory", std::vector<data::threshold_rule>{
                data::threshold_rule{
                    .metric_name       = "mem_usage",
                    .warn_at           = 75.0,
                    .crit_at           = 95.0,
                    .evaluation_window = 2min,
                },
            }},
        },
        .shutdown_grace_period = 15s,
        .warmup_delay          = 2s,
    };

    ASSERT_DEEP_EQ(parsed, expected);
}
