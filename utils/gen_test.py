"""
gen_test.py — генератор GTest-файлов для service_config парсера.

--out задаёт имя теста, которое используется везде:
  - TEST(service_config_parse, <name>)
  - <name>.cpp  /  <name>.json
  - load_file("<name>.json")

--seed задаёт начальное состояние генератора; одинаковые аргументы → одинаковый вывод.
--quantity N запускает генерацию N раз с сидами 1..N, добавляя суффикс _{seed} к --out.
  Несовместимо с явным --seed.

Примеры:
  python gen_test.py ok  --depth 50 --seed 1 --out ServiceConfig50Ok_s1
  python gen_test.py bad --depth 50 --seed 1 --error missing_field --at 20 --out ServiceConfig50Bad_s1
  python gen_test.py bad --depth 50 --seed 1 --error wrong_type    --at 35 --out ServiceConfig50Bad_wt_s1

  python gen_test.py ok  --quantity 50 --depth 50 --out ok_50
  python gen_test.py bad --quantity 10 --depth 50 --error missing_field --at 20 --out bad_50
"""

import argparse
import random
from dataclasses import dataclass
from pathlib import Path

# ── constants ─────────────────────────────────────────────────────────────────

LOG_LEVELS_JSON = ["null", '"debug"', '"info"', '"warning"', '"error"', '"critical"']
LOG_LEVELS_CPP  = [
    "std::nullopt",
    "data::severity::debug",
    "data::severity::info",
    "data::severity::warning",
    "data::severity::error",
    "data::severity::critical",
]

ERROR_KINDS = ("missing_field", "wrong_type")

HEADER = """\
#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

"""

# ── chrono helpers ────────────────────────────────────────────────────────────

def _chrono_ms(ms: int, min_suffix: str) -> str:
    if ms % 3_600_000 == 0:
        return f"{ms // 3_600_000}h"
    if ms % 60_000 == 0:
        return f"{ms // 60_000}{min_suffix}"
    if ms % 1_000 == 0:
        return f"{ms // 1_000}s"
    return f"{ms}ms"

def _chrono_s(s: int, min_suffix: str) -> str:
    if s % 3600 == 0:
        return f"{s // 3600}h"
    if s % 60 == 0:
        return f"{s // 60}{min_suffix}"
    return f"{s}s"

def ms_literal(ms: int) -> str:
    return _chrono_ms(ms, "min")

def s_literal(s: int) -> str:
    return _chrono_s(s, "min")

def ms_json(ms: int) -> str:
    return f'"{_chrono_ms(ms, "m")}"'

def s_json(s: int) -> str:
    return f'"{_chrono_s(s, "m")}"'

# ── per-level data ─────────────────────────────────────────────────────────────

@dataclass
class LevelData:
    d:                   int
    ll_idx:              int
    has_retry:           bool
    retry_max_attempts:  int
    retry_base_delay_ms: int
    retry_backoff:       float
    retry_deadline_s:    int
    port:                int
    connect_timeout_ms:  int
    ep_retry_max:        int
    ep_retry_delay_ms:   int
    ep_retry_backoff:    float
    tag_value:           str

    @property
    def ep_key(self) -> str:
        return f"ep_{self.d}"

    @property
    def tag_key(self) -> str:
        return f"k_{self.d}"


def make_level_data(d: int, rng: random.Random) -> LevelData:
    ll_idx     = rng.randrange(6)
    has_retry  = rng.random() < 0.5

    r_max      = rng.randint(1, 10)
    r_delay    = rng.choice([10, 50, 100, 200, 500, 1000])
    r_backoff  = round(rng.uniform(1.0, 3.0), 2)
    r_deadline = rng.choice([0, 0, 30, 60, 120, 300])

    port              = rng.randint(10001, 19999)
    connect_timeout   = rng.choice([100, 200, 500, 1000, 2000, 5000])
    ep_retry_max      = rng.randint(1, 5)
    ep_retry_delay    = rng.choice([10, 25, 50, 100, 200])
    ep_retry_backoff  = round(rng.uniform(1.0, 2.5), 2)
    tag_value         = f"val_{rng.randint(1000, 9999)}"

    return LevelData(
        d                  = d,
        ll_idx             = ll_idx,
        has_retry          = has_retry,
        retry_max_attempts = r_max,
        retry_base_delay_ms= r_delay,
        retry_backoff      = r_backoff,
        retry_deadline_s   = r_deadline,
        port               = port,
        connect_timeout_ms = connect_timeout,
        ep_retry_max       = ep_retry_max,
        ep_retry_delay_ms  = ep_retry_delay,
        ep_retry_backoff   = ep_retry_backoff,
        tag_value          = tag_value,
    )


@dataclass
class OuterData:
    worker_threads:       int
    enable_tracing:       bool
    ep_port:              int
    ep_connect_ms:        int
    retry_max:            int
    retry_delay_ms:       int
    retry_backoff:        float
    retry_deadline_s:     int
    warn_at:              float
    crit_at:              float
    eval_window_s:        int
    fallback_max:         int
    fallback_delay_ms:    int
    fallback_backoff:     float
    timeout_override_ms:  int
    max_conn:             int
    rate_user_limit:      int
    rate_anon_limit:      int
    admin_port:           int
    mem_warn:             float
    mem_crit:             float
    mem_eval_s:           int
    shutdown_grace_s:     int
    warmup_ms:            int


def make_outer_data(rng: random.Random) -> OuterData:
    return OuterData(
        worker_threads      = rng.choice([2, 4, 8, 16]),
        enable_tracing      = rng.random() < 0.5,
        ep_port             = rng.randint(1024, 9999),
        ep_connect_ms       = rng.choice([100, 200, 500, 1000, 2000]),
        retry_max           = rng.randint(1, 5),
        retry_delay_ms      = rng.choice([50, 100, 200, 500]),
        retry_backoff       = round(rng.uniform(1.0, 3.0), 2),
        retry_deadline_s    = rng.choice([10, 30, 60, 120]),
        warn_at             = round(rng.uniform(50.0, 80.0), 1),
        crit_at             = round(rng.uniform(85.0, 99.0), 1),
        eval_window_s       = rng.choice([30, 60, 120, 300]),
        fallback_max        = rng.randint(1, 3),
        fallback_delay_ms   = rng.choice([100, 200, 500]),
        fallback_backoff    = round(rng.uniform(1.0, 2.0), 2),
        timeout_override_ms = rng.choice([500, 1000, 1500, 2000, 3000]),
        max_conn            = rng.choice([50, 100, 200, 500]),
        rate_user_limit     = rng.choice([500, 1000, 2000, 5000]),
        rate_anon_limit     = rng.choice([50, 100, 200]),
        admin_port          = rng.randint(8000, 8999),
        mem_warn            = round(rng.uniform(60.0, 80.0), 1),
        mem_crit            = round(rng.uniform(85.0, 99.0), 1),
        mem_eval_s          = rng.choice([60, 120, 300]),
        shutdown_grace_s    = rng.choice([5, 10, 15, 30]),
        warmup_ms           = rng.choice([0, 500, 1000, 2000]),
    )


# ── JSON builders ─────────────────────────────────────────────────────────────

def build_config_tree_json(
    levels: list[LevelData],
    corrupt_at: dict | None = None,
) -> str:
    corrupt_at = corrupt_at or {}

    def prefix_suffix(ld: LevelData, corrupt: str | None):
        ll = LOG_LEVELS_JSON[ld.ll_idx]

        retry_block = ""
        if ld.has_retry:
            deadline_val = s_json(ld.retry_deadline_s) if ld.retry_deadline_s else "null"
            retry_block = (
                f'"retry":{{'
                f'"max_attempts":{ld.retry_max_attempts},'
                f'"base_delay":{ms_json(ld.retry_base_delay_ms)},'
                f'"backoff_multiplier":{ld.retry_backoff:.2f},'
                f'"deadline":{deadline_val}'
                f'}},'
            )

        port_val = f'"bad_port_{ld.d}"' if corrupt == "wrong_type" else str(ld.port)

        ep_block = (
            f'"{ld.ep_key}":{{'
            f'"address":{{"host":"host{ld.d}.local","port":{port_val}}},'
            f'"connect_timeout":{ms_json(ld.connect_timeout_ms)},'
            f'"retry":{{"max_attempts":{ld.ep_retry_max},"base_delay":{ms_json(ld.ep_retry_delay_ms)},'
            f'"backoff_multiplier":{ld.ep_retry_backoff:.2f},"deadline":null}},'
            f'"tls_cert_path":null,'
            f'"tags":[{{"key":"{ld.tag_key}","value":"{ld.tag_value}"}}]'
            f'}}'
        )

        if corrupt == "missing_field":
            pre = (
                f'{{'
                f'"log_level":{ll},{retry_block}'
                f'"endpoint_overrides":{{{ep_block}}},'
                f'"tags":[{{"key":"depth","value":"{ld.d}"}}],'
                f'"extra":null,'
                f'"nested":'
            )
        else:
            pre = (
                f'{{'
                f'"scope":"level_{ld.d}",'
                f'"log_level":{ll},{retry_block}'
                f'"endpoint_overrides":{{{ep_block}}},'
                f'"tags":[{{"key":"depth","value":"{ld.d}"}}],'
                f'"extra":null,'
                f'"nested":'
            )
        return pre, '}'

    prefixes, suffixes = [], []
    for ld in levels:
        pre, suf = prefix_suffix(ld, corrupt_at.get(ld.d))
        prefixes.append(pre)
        suffixes.append(suf)

    leaf = '{"scope":"leaf","log_level":null,"endpoint_overrides":{},"tags":[],"extra":null,"nested":null}'
    return "".join(prefixes) + leaf + "".join(reversed(suffixes))


def build_outer_json(od: OuterData, levels: list[LevelData], corrupt_at: dict | None = None) -> str:
    config_tree = build_config_tree_json(levels, corrupt_at)
    warmup      = f'"{ms_literal(od.warmup_ms)}"' if od.warmup_ms else "null"
    return (
        f'{{\n'
        f'  "service_name": "my-service",\n'
        f'  "worker_threads": {od.worker_threads},\n'
        f'  "enable_tracing": {"true" if od.enable_tracing else "false"},\n'
        f'  "backends": [{{\n'
        f'    "name": "primary",\n'
        f'    "endpoints": [{{\n'
        f'      "address": {{"host": "primary.local", "port": {od.ep_port}}},\n'
        f'      "connect_timeout": {ms_json(od.ep_connect_ms)},\n'
        f'      "retry": {{"max_attempts": {od.retry_max}, "base_delay": {ms_json(od.retry_delay_ms)}, "backoff_multiplier": {od.retry_backoff:.2f}, "deadline": {s_json(od.retry_deadline_s)}}},\n'
        f'      "tls_cert_path": "/etc/certs/primary.pem",\n'
        f'      "tags": [{{"key": "env", "value": "prod"}}, {{"key": "region", "value": "eu-west"}}]\n'
        f'    }}],\n'
        f'    "alerts": {{\n'
        f'      "cpu": {{"metric_name": "cpu_usage", "warn_at": {od.warn_at}, "crit_at": {od.crit_at}, "evaluation_window": {s_json(od.eval_window_s)}}}\n'
        f'    }},\n'
        f'    "min_log_level": "info",\n'
        f'    "fallback_retry": {{"max_attempts": {od.fallback_max}, "base_delay": {ms_json(od.fallback_delay_ms)}, "backoff_multiplier": {od.fallback_backoff:.2f}, "deadline": null}}\n'
        f'  }}],\n'
        f'  "routes": {{\n'
        f'    "api":    {{"pattern": "/api/*", "backend_names": ["primary"], "timeout_override": {ms_json(od.timeout_override_ms)}}},\n'
        f'    "health": {{"pattern": "/health", "backend_names": ["primary"], "timeout_override": null}}\n'
        f'  }},\n'
        f'  "env": {{"LOG_LEVEL": "info", "MAX_CONN": "{od.max_conn}"}},\n'
        f'  "rate_limits": [["user", {od.rate_user_limit}, true], ["anon", {od.rate_anon_limit}, false]],\n'
        f'  "allowed_origins": ["https://example.com", "https://app.example.com"],\n'
        f'  "config_tree": {config_tree},\n'
        f'  "admin_endpoint": {{"host": "admin.local", "port": {od.admin_port}}},\n'
        f'  "global_thresholds": {{\n'
        f'    "memory": [{{"metric_name": "mem_usage", "warn_at": {od.mem_warn}, "crit_at": {od.mem_crit}, "evaluation_window": {s_json(od.mem_eval_s)}}}]\n'
        f'  }},\n'
        f'  "shutdown_grace_period": {s_json(od.shutdown_grace_s)},\n'
        f'  "warmup_delay": {warmup}\n'
        f'}}'
    )


# ── C++ builders ──────────────────────────────────────────────────────────────

def _scope_cpp_open(ld: LevelData, buf: list) -> None:
    ll_cpp = LOG_LEVELS_CPP[ld.ll_idx]

    if ld.has_retry:
        deadline_cpp = s_literal(ld.retry_deadline_s) if ld.retry_deadline_s else "std::nullopt"
        retry_cpp = (
            f"data::retry_policy{{\n"
            f"                    .max_attempts       = {ld.retry_max_attempts}u,\n"
            f"                    .base_delay         = {ms_literal(ld.retry_base_delay_ms)},\n"
            f"                    .backoff_multiplier = {ld.retry_backoff:.2f},\n"
            f"                    .deadline           = {deadline_cpp},\n"
            f"                }}"
        )
    else:
        retry_cpp = "std::nullopt"

    buf.append(
        f"data::scope_override{{\n"
        f"                .scope              = \"level_{ld.d}\",\n"
        f"                .log_level          = {ll_cpp},\n"
        f"                .retry              = {retry_cpp},\n"
        f"                .endpoint_overrides = std::map<std::string, data::endpoint_config>{{\n"
        f"                    {{\"{ld.ep_key}\", data::endpoint_config{{\n"
        f"                        .address         = data::network_address{{.host = \"host{ld.d}.local\", .port = {ld.port}}},\n"
        f"                        .connect_timeout = {ms_literal(ld.connect_timeout_ms)},\n"
        f"                        .retry           = data::retry_policy{{\n"
        f"                            .max_attempts       = {ld.ep_retry_max}u,\n"
        f"                            .base_delay         = {ms_literal(ld.ep_retry_delay_ms)},\n"
        f"                            .backoff_multiplier = {ld.ep_retry_backoff:.2f},\n"
        f"                            .deadline           = std::nullopt,\n"
        f"                        }},\n"
        f"                        .tls_cert_path   = std::nullopt,\n"
        f"                        .tags            = std::vector<data::tag>{{data::tag{{.key = \"{ld.tag_key}\", .value = \"{ld.tag_value}\"}}}},\n"
        f"                    }}}},\n"
        f"                }},\n"
        f"                .tags               = std::vector<data::tag>{{data::tag{{.key = \"depth\", .value = \"{ld.d}\"}}}},\n"
        f"                .extra              = boost::json::value{{}},\n"
        f"                .nested             = "
    )


def build_config_tree_cpp(levels: list[LevelData]) -> str:
    buf = []

    for i, ld in enumerate(levels):
        if i > 0:
            buf.append("common::box<data::scope_override>{data::scope_override{\n                ")
        _scope_cpp_open(ld, buf)

    buf.append(
        "common::box<data::scope_override>{data::scope_override{\n"
        "                .scope              = \"leaf\",\n"
        "                .log_level          = std::nullopt,\n"
        "                .retry              = std::nullopt,\n"
        "                .endpoint_overrides = {},\n"
        "                .tags               = {},\n"
        "                .extra              = boost::json::value{},\n"
        "                .nested             = common::box<data::scope_override>{},\n"
        "            }}"
    )

    buf.append(",\n            }")

    for _ in range(1, len(levels)):
        buf.append("\n            }}")
        buf.append(",\n            }")

    return "".join(buf)


# ── test body builders ────────────────────────────────────────────────────────

def ok_test(name: str, od: OuterData, levels: list[LevelData]) -> tuple[str, str]:
    json_body       = build_outer_json(od, levels)
    config_tree_cpp = build_config_tree_cpp(levels)
    json_filename   = f"{name}.json"
    warmup_cpp      = ms_literal(od.warmup_ms) if od.warmup_ms else "std::nullopt"

    cpp = (
        f"TEST(service_config_parse, {name})\n{{\n"
        f"    using namespace std::chrono_literals;\n\n"
        f"    const std::string json = load_file(\"{json_filename}\");\n"
        f"    const auto parsed = json::exceptions::as<data::service_config>(json);\n\n"
        f"    const data::service_config expected = {{\n"
        f"        .service_name          = \"my-service\",\n"
        f"        .worker_threads        = {od.worker_threads}u,\n"
        f"        .enable_tracing        = {'true' if od.enable_tracing else 'false'},\n"
        f"        .backends              = std::vector<data::backend_group>{{\n"
        f"            data::backend_group{{\n"
        f"                .name      = \"primary\",\n"
        f"                .endpoints = std::vector<data::endpoint_config>{{\n"
        f"                    data::endpoint_config{{\n"
        f"                        .address         = data::network_address{{.host = \"primary.local\", .port = {od.ep_port}}},\n"
        f"                        .connect_timeout = {ms_literal(od.ep_connect_ms)},\n"
        f"                        .retry           = data::retry_policy{{\n"
        f"                            .max_attempts       = {od.retry_max}u,\n"
        f"                            .base_delay         = {ms_literal(od.retry_delay_ms)},\n"
        f"                            .backoff_multiplier = {od.retry_backoff:.2f},\n"
        f"                            .deadline           = {s_literal(od.retry_deadline_s)},\n"
        f"                        }},\n"
        f"                        .tls_cert_path   = \"/etc/certs/primary.pem\",\n"
        f"                        .tags            = std::vector<data::tag>{{\n"
        f"                            data::tag{{.key = \"env\",    .value = \"prod\"}},\n"
        f"                            data::tag{{.key = \"region\", .value = \"eu-west\"}},\n"
        f"                        }},\n"
        f"                    }},\n"
        f"                }},\n"
        f"                .alerts        = std::map<std::string, data::threshold_rule>{{\n"
        f"                    {{\"cpu\", data::threshold_rule{{\n"
        f"                        .metric_name       = \"cpu_usage\",\n"
        f"                        .warn_at           = {od.warn_at},\n"
        f"                        .crit_at           = {od.crit_at},\n"
        f"                        .evaluation_window = {s_literal(od.eval_window_s)},\n"
        f"                    }}}},\n"
        f"                }},\n"
        f"                .min_log_level = data::severity::info,\n"
        f"                .fallback_retry= data::retry_policy{{\n"
        f"                    .max_attempts       = {od.fallback_max}u,\n"
        f"                    .base_delay         = {ms_literal(od.fallback_delay_ms)},\n"
        f"                    .backoff_multiplier = {od.fallback_backoff:.2f},\n"
        f"                    .deadline           = std::nullopt,\n"
        f"                }},\n"
        f"            }},\n"
        f"        }},\n"
        f"        .routes                = std::map<std::string, data::routing_rule>{{\n"
        f"            {{\"api\", data::routing_rule{{\n"
        f"                .pattern          = \"/api/*\",\n"
        f"                .backend_names    = std::vector<std::string>{{\"primary\"}},\n"
        f"                .timeout_override = {ms_literal(od.timeout_override_ms)},\n"
        f"            }}}},\n"
        f"            {{\"health\", data::routing_rule{{\n"
        f"                .pattern          = \"/health\",\n"
        f"                .backend_names    = std::vector<std::string>{{\"primary\"}},\n"
        f"                .timeout_override = std::nullopt,\n"
        f"            }}}},\n"
        f"        }},\n"
        f"        .env                   = std::unordered_map<std::string, std::string>{{\n"
        f"            {{\"LOG_LEVEL\", \"info\"}},\n"
        f"            {{\"MAX_CONN\",  \"{od.max_conn}\"}},\n"
        f"        }},\n"
        f"        .rate_limits           = std::vector<data::rate_limit_entry>{{\n"
        f"            data::rate_limit_entry{{\"user\", {od.rate_user_limit}u, true}},\n"
        f"            data::rate_limit_entry{{\"anon\",  {od.rate_anon_limit}u, false}},\n"
        f"        }},\n"
        f"        .allowed_origins       = std::set<std::string>{{\n"
        f"            \"https://app.example.com\",\n"
        f"            \"https://example.com\",\n"
        f"        }},\n"
        f"        .config_tree           = {config_tree_cpp},\n"
        f"        .admin_endpoint        = data::network_address{{.host = \"admin.local\", .port = {od.admin_port}}},\n"
        f"        .global_thresholds     = std::map<std::string, std::vector<data::threshold_rule>>{{\n"
        f"            {{\"memory\", std::vector<data::threshold_rule>{{\n"
        f"                data::threshold_rule{{\n"
        f"                    .metric_name       = \"mem_usage\",\n"
        f"                    .warn_at           = {od.mem_warn},\n"
        f"                    .crit_at           = {od.mem_crit},\n"
        f"                    .evaluation_window = {s_literal(od.mem_eval_s)},\n"
        f"                }},\n"
        f"            }}}},\n"
        f"        }},\n"
        f"        .shutdown_grace_period = {s_literal(od.shutdown_grace_s)},\n"
        f"        .warmup_delay          = {warmup_cpp},\n"
        f"    }};\n\n"
        f"    ASSERT_DEEP_EQ(parsed, expected);\n"
        f"}}\n"
    )
    return cpp, json_body


def _build_path(at: int, error_kind: str, levels: list[LevelData]) -> str:
    ld = levels[at - 1]
    lines = []
    lines.append('        json::path_value_t exp { "config_tree" };')
    lines.append(f'        add_nested(exp, {at});')
    if error_kind == "wrong_type":
        lines.append(f'        exp.emplace_back("endpoint_overrides");')
        lines.append(f'        exp.emplace_back("{ld.ep_key}");')
        lines.append(f'        exp.emplace_back("address");')
        lines.append(f'        exp.emplace_back("port");')
    return "\n".join(lines)


def bad_test(
    name: str,
    od: OuterData,
    levels: list[LevelData],
    error_kind: str,
    at: int,
) -> tuple[str, str]:
    json_filename = f"{name}.json"
    corrupt_at    = {levels[at - 1].d: error_kind}
    json_body     = build_outer_json(od, levels, corrupt_at)
    path_lines    = _build_path(at, error_kind, levels)

    cpp = (
        f"TEST(service_config_parse, {name})\n{{\n"
        f"    const std::string json = load_file(\"{json_filename}\");\n"
        f"    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)\n"
        f"    {{\n"
        f"{path_lines}\n"
        f"        EXPECT_EQ(ex.path(), exp);\n"
        f"    }};\n"
        f"}}\n"
    )
    return cpp, json_body


# ── generation (single run) ───────────────────────────────────────────────────

def generate_one(args, seed: int, name: str) -> None:
    rng    = random.Random(seed)
    od     = make_outer_data(rng)
    levels = [make_level_data(args.depth - i, rng) for i in range(args.depth)]

    if args.cmd == "ok":
        print(f"  ok depth={args.depth} seed={seed} -> {name}", flush=True)
        cpp, json_body = ok_test(name, od, levels)
    else:
        assert 1 <= args.at <= args.depth, f"--at must be in [1, {args.depth}]"
        print(f"  bad depth={args.depth} seed={seed} error={args.error} at={args.at} -> {name}", flush=True)
        cpp, json_body = bad_test(name, od, levels, args.error, args.at)

    base      = Path(name)
    cpp_path  = base.with_suffix(".cpp")
    json_path = base.with_suffix(".json")

    cpp_path.write_text(HEADER + cpp, encoding="utf-8")
    json_path.write_text(json_body, encoding="utf-8")

    print(f"written -> {cpp_path}  ({cpp_path.stat().st_size // 1024} KB)")
    print(f"         + {json_path.name}  ({json_path.stat().st_size // 1024} KB)")


# ── CLI ───────────────────────────────────────────────────────────────────────

def parse_args():
    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )

    # --seed и --quantity взаимоисключающие
    seed_group = p.add_mutually_exclusive_group()
    seed_group.add_argument(
        "--seed", type=int, default=0, metavar="N",
        help="RNG seed for a single run (default: 0); incompatible with --quantity",
    )
    seed_group.add_argument(
        "--quantity", type=int, metavar="N",
        help="generate N files using seeds 1..N; appends _{seed} to --out",
    )

    sub = p.add_subparsers(dest="cmd", required=True)

    ok_p = sub.add_parser("ok", help="generate valid test")
    ok_p.add_argument("--depth", type=int, required=True, metavar="N")
    ok_p.add_argument("--out", required=True, metavar="NAME")

    bad_p = sub.add_parser("bad", help="generate error test")
    bad_p.add_argument("--depth", type=int, required=True, metavar="N")
    bad_p.add_argument("--error", required=True, choices=ERROR_KINDS)
    bad_p.add_argument("--at", type=int, required=True, metavar="LEVEL",
                       help="nesting level from root (1 = outermost)")
    bad_p.add_argument("--out", required=True, metavar="NAME")

    return p.parse_args()


def main():
    args = parse_args()

    if args.quantity is not None:
        # batch mode: seeds 1..N, имя файла = <out>_<seed>
        for seed in range(1, args.quantity + 1):
            name = f"{args.out}_{seed}"
            generate_one(args, seed, name)
    else:
        # single mode: обычное поведение, имя файла = <out>
        generate_one(args, args.seed, args.out)


if __name__ == "__main__":
    main()