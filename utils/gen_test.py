"""
gen_test.py — генератор GTest-файлов для service_config парсера.

Режимы:
  ok   — валидный JSON + C++ expected + ASSERT_DEEP_EQ
  bad  — JSON с намеренной ошибкой на заданной глубине + EXPECT_ANY_THROW

Примеры:
  python gen_test.py ok  --depth 50 --out ok50_test.cpp
  python gen_test.py ok  --depth 10 25 50 --out multi_test.cpp
  python gen_test.py bad --depth 30 --error missing_field --at 15 --out bad_test.cpp
  python gen_test.py bad --depth 30 --error wrong_type    --at 15 --out bad_test.cpp
  python gen_test.py bad --depth 30 --error missing_field wrong_type --at 15 20 --out bad_test.cpp
"""

import argparse
import sys
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
#include "deep_equal.hpp"
#include "gtest_formatter.hpp"
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

# C++ literals: minutes postfix is `min`
def ms_literal(ms: int) -> str:
    return _chrono_ms(ms, "min")

def s_literal(s: int) -> str:
    return _chrono_s(s, "min")

# JSON strings: minutes postfix is `m`
def ms_json(ms: int) -> str:
    return f'"{_chrono_ms(ms, "m")}"'

def s_json(s: int) -> str:
    return f'"{_chrono_s(s, "m")}"'

# ── JSON builders ─────────────────────────────────────────────────────────────

def _scope_json(depth: int, inner: str, *, corrupt: str | None = None) -> str:
    ll        = LOG_LEVELS_JSON[depth % 6]
    has_retry = (depth % 3 == 0)

    retry_block = ""
    if has_retry:
        retry_block = (
            f'"retry":{{'
            f'"max_attempts":{depth},'
            f'"base_delay":{ms_json(depth * 10)},'
            f'"backoff_multiplier":{1.0 + depth * 0.1:.2f},'
            f'"deadline":{s_json(depth * 5)}'
            f'}},'
        )

    ep = f"ep_{depth}"
    tk = f"k{depth}"
    tv = f"v{depth}"

    port_val = f'"bad_port_{depth}"' if corrupt == "wrong_type" else str(10000 + depth)

    ep_block = (
        f'"{ep}":{{'
        f'"address":{{"host":"host{depth}.local","port":{port_val}}},'
        f'"connect_timeout":{ms_json(depth * 100)},'
        f'"retry":{{"max_attempts":{depth+1},"base_delay":{ms_json(depth*5)},'
        f'"backoff_multiplier":{1.5+depth*0.05:.2f},"deadline":null}},'
        f'"tls_cert_path":null,'
        f'"tags":[{{"key":"{tk}","value":"{tv}"}}]'
        f'}}'
    )

    if corrupt == "missing_field":
        return (
            f'{{'
            f'"log_level":{ll},{retry_block}'
            f'"endpoint_overrides":{{{ep_block}}},'
            f'"tags":[{{"key":"depth","value":"{depth}"}}],'
            f'"extra":null,'
            f'"nested":{inner}'
            f'}}'
        )

    return (
        f'{{'
        f'"scope":"level_{depth}",'
        f'"log_level":{ll},{retry_block}'
        f'"endpoint_overrides":{{{ep_block}}},'
        f'"tags":[{{"key":"depth","value":"{depth}"}}],'
        f'"extra":null,'
        f'"nested":{inner}'
        f'}}'
    )


def build_config_tree_json(depth: int, corrupt_at: dict | None = None) -> str:
    corrupt_at = corrupt_at or {}
    # build as a list of fragments to avoid O(N²) string growth:
    # represent the JSON as prefix-parts + suffix-parts, assembled once at end
    #
    # each level wraps the previous: PREFIX_d + PREFIX_{d-1} + ... + LEAF + ... + SUFFIX_{d-1} + SUFFIX_d
    # we collect prefixes and suffixes separately, join once

    prefixes = []
    suffixes = []

    def level_parts(d: int, corrupt: str | None):
        ll        = LOG_LEVELS_JSON[d % 6]
        has_retry = (d % 3 == 0)

        retry_block = ""
        if has_retry:
            retry_block = (
                f'"retry":{{'
                f'"max_attempts":{d},'
                f'"base_delay":{ms_json(d * 10)},'
                f'"backoff_multiplier":{1.0 + d * 0.1:.2f},'
                f'"deadline":{s_json(d * 5)}'
                f'}},'
            )

        ep = f"ep_{d}"
        tk = f"k{d}"
        tv = f"v{d}"
        port_val = f'"bad_port_{d}"' if corrupt == "wrong_type" else str(10000 + d)

        ep_block = (
            f'"{ep}":{{'
            f'"address":{{"host":"host{d}.local","port":{port_val}}},'
            f'"connect_timeout":{ms_json(d * 100)},'
            f'"retry":{{"max_attempts":{d+1},"base_delay":{ms_json(d*5)},'
            f'"backoff_multiplier":{1.5+d*0.05:.2f},"deadline":null}},'
            f'"tls_cert_path":null,'
            f'"tags":[{{"key":"{tk}","value":"{tv}"}}]'
            f'}}'
        )

        if corrupt == "missing_field":
            prefix = (
                f'{{'
                f'"log_level":{ll},{retry_block}'
                f'"endpoint_overrides":{{{ep_block}}},'
                f'"tags":[{{"key":"depth","value":"{d}"}}],'
                f'"extra":null,'
                f'"nested":'
            )
        else:
            prefix = (
                f'{{'
                f'"scope":"level_{d}",'
                f'"log_level":{ll},{retry_block}'
                f'"endpoint_overrides":{{{ep_block}}},'
                f'"tags":[{{"key":"depth","value":"{d}"}}],'
                f'"extra":null,'
                f'"nested":'
            )
        suffix = f'}}'
        return prefix, suffix

    leaf = '{"scope":"leaf","log_level":null,"endpoint_overrides":{},"tags":[],"extra":null,"nested":null}'

    for d in range(depth, 0, -1):
        pre, suf = level_parts(d, corrupt_at.get(d))
        prefixes.append(pre)
        suffixes.append(suf)

    # prefixes[0] = outermost, prefixes[-1] = depth=1 (wraps leaf)
    return "".join(prefixes) + leaf + "".join(reversed(suffixes))


def build_outer_json(depth: int, corrupt_at: dict | None = None) -> str:
    config_tree = build_config_tree_json(depth, corrupt_at)
    return (
        f'{{\n'
        f'  "service_name": "my-service",\n'
        f'  "worker_threads": 8,\n'
        f'  "enable_tracing": true,\n'
        f'  "backends": [{{\n'
        f'    "name": "primary",\n'
        f'    "endpoints": [{{\n'
        f'      "address": {{"host": "primary.local", "port": 9000}},\n'
        f'      "connect_timeout": "500ms",\n'
        f'      "retry": {{"max_attempts": 3, "base_delay": "100ms", "backoff_multiplier": 2.0, "deadline": "30s"}},\n'
        f'      "tls_cert_path": "/etc/certs/primary.pem",\n'
        f'      "tags": [{{"key": "env", "value": "prod"}}, {{"key": "region", "value": "eu-west"}}]\n'
        f'    }}],\n'
        f'    "alerts": {{\n'
        f'      "cpu": {{"metric_name": "cpu_usage", "warn_at": 70.0, "crit_at": 90.0, "evaluation_window": "60s"}}\n'
        f'    }},\n'
        f'    "min_log_level": "info",\n'
        f'    "fallback_retry": {{"max_attempts": 1, "base_delay": "200ms", "backoff_multiplier": 1.0, "deadline": null}}\n'
        f'  }}],\n'
        f'  "routes": {{\n'
        f'    "api":    {{"pattern": "/api/*", "backend_names": ["primary"], "timeout_override": "1500ms"}},\n'
        f'    "health": {{"pattern": "/health", "backend_names": ["primary"], "timeout_override": null}}\n'
        f'  }},\n'
        f'  "env": {{"LOG_LEVEL": "info", "MAX_CONN": "100"}},\n'
        f'  "rate_limits": [["user", 1000, true], ["anon", 100, false]],\n'
        f'  "allowed_origins": ["https://example.com", "https://app.example.com"],\n'
        f'  "config_tree": {config_tree},\n'
        f'  "admin_endpoint": {{"host": "admin.local", "port": 8080}},\n'
        f'  "global_thresholds": {{\n'
        f'    "memory": [{{"metric_name": "mem_usage", "warn_at": 75.0, "crit_at": 95.0, "evaluation_window": {s_json(120)}}}]\n'
        f'  }},\n'
        f'  "shutdown_grace_period": "15s",\n'
        f'  "warmup_delay": "2s"\n'
        f'}}'
    )


# ── C++ builders ──────────────────────────────────────────────────────────────
#
# To avoid O(N²) string growth we write directly to a list[str] (the file
# buffer), building the nested structure with explicit open/close fragments
# rather than wrapping one big string inside another.
#
# The nesting in C++ looks like:
#
#   data::scope_override{          ← level 50 (outermost)
#       ...
#       .nested = common::box<...>{data::scope_override{   ← level 49
#           ...
#           .nested = common::box<...>{data::scope_override{  ← level 48
#               ...
#               .nested = <leaf>,
#           }},
#       }},
#   }
#
# We emit level 50 open, level 49 open, ..., level 1 open, leaf, then
# close in reverse order.

def _scope_cpp_open(depth: int, buf: list) -> None:
    """Append the opening fragment of scope_override for `depth` to buf."""
    ll_cpp    = LOG_LEVELS_CPP[depth % 6]
    has_retry = (depth % 3 == 0)
    ep = f"ep_{depth}"
    tk = f"k{depth}"
    tv = f"v{depth}"

    if has_retry:
        retry_lines = (
            f"data::retry_policy{{\n"
            f"                    .max_attempts       = {depth}u,\n"
            f"                    .base_delay         = {ms_literal(depth*10)},\n"
            f"                    .backoff_multiplier = {1.0+depth*0.1:.2f},\n"
            f"                    .deadline           = {s_literal(depth*5)},\n"
            f"                }}"
        )
    else:
        retry_lines = "std::nullopt"

    buf.append(
        f"data::scope_override{{\n"
        f"                .scope              = \"level_{depth}\",\n"
        f"                .log_level          = {ll_cpp},\n"
        f"                .retry              = {retry_lines},\n"
        f"                .endpoint_overrides = std::map<std::string, data::endpoint_config>{{\n"
        f"                    {{\"{ep}\", data::endpoint_config{{\n"
        f"                        .address         = data::network_address{{.host = \"host{depth}.local\", .port = {10000+depth}}},\n"
        f"                        .connect_timeout = {ms_literal(depth*100)},\n"
        f"                        .retry           = data::retry_policy{{\n"
        f"                            .max_attempts       = {depth+1}u,\n"
        f"                            .base_delay         = {ms_literal(depth*5)},\n"
        f"                            .backoff_multiplier = {1.5+depth*0.05:.2f},\n"
        f"                            .deadline           = std::nullopt,\n"
        f"                        }},\n"
        f"                        .tls_cert_path   = std::nullopt,\n"
        f"                        .tags            = std::vector<data::tag>{{data::tag{{.key = \"{tk}\", .value = \"{tv}\"}}}},\n"
        f"                    }}}},\n"
        f"                }},\n"
        f"                .tags               = std::vector<data::tag>{{data::tag{{.key = \"depth\", .value = \"{depth}\"}}}},\n"
        f"                .extra              = boost::json::value{{}},\n"
        f"                .nested             = "  # next fragment continues here
    )


def _scope_cpp_close(buf: list) -> None:
    """Append the closing fragment (closes .nested = ... and the struct)."""
    buf.append(",\n            }")


def build_config_tree_cpp(depth: int) -> str:
    buf = []

    # outermost level down to level 1, each opens a box + scope_override
    for d in range(depth, 0, -1):
        if d < depth:
            # wrap in box before opening the scope
            buf.append("common::box<data::scope_override>{data::scope_override{\n                ")
        _scope_cpp_open(d, buf)

    # leaf (innermost)
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

    # close level 1 .nested = ...
    _scope_cpp_close(buf)

    # close levels 2..depth: close .nested + close box + close scope + close outer box
    for _ in range(1, depth):
        buf.append("\n            }}")   # closes data::scope_override{ of the box
        buf.append(",\n            }")   # closes .nested = ... of the parent level

    return "".join(buf)


# ── test body builders ────────────────────────────────────────────────────────

def ok_test(depth: int) -> str:
    json_body       = build_outer_json(depth)
    config_tree_cpp = build_config_tree_cpp(depth)
    name            = f"ServiceConfig{depth}Ok"

    return (
        f"// {'─' * 77}\n\n"
        f"namespace\n{{\n\n"
        f"std::string_view json_{depth} = R\"json(\n{json_body}\n)json\";\n\n"
        f"}} // namespace\n\n"
        f"// {'─' * 77}\n\n"
        f"TEST(service_config_parse, {name})\n{{\n"
        f"    using namespace std::chrono_literals;\n\n"
        f"    const auto parsed = json::exceptions::as<data::service_config>(json_{depth});\n\n"
        f"    const data::service_config expected = {{\n"
        f"        .service_name          = \"my-service\",\n"
        f"        .worker_threads        = 8u,\n"
        f"        .enable_tracing        = true,\n"
        f"        .backends              = std::vector<data::backend_group>{{\n"
        f"            data::backend_group{{\n"
        f"                .name      = \"primary\",\n"
        f"                .endpoints = std::vector<data::endpoint_config>{{\n"
        f"                    data::endpoint_config{{\n"
        f"                        .address         = data::network_address{{.host = \"primary.local\", .port = 9000}},\n"
        f"                        .connect_timeout = 500ms,\n"
        f"                        .retry           = data::retry_policy{{\n"
        f"                            .max_attempts       = 3u,\n"
        f"                            .base_delay         = 100ms,\n"
        f"                            .backoff_multiplier = 2.0,\n"
        f"                            .deadline           = 30s,\n"
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
        f"                        .warn_at           = 70.0,\n"
        f"                        .crit_at           = 90.0,\n"
        f"                        .evaluation_window = {s_literal(60)},\n"
        f"                    }}}},\n"
        f"                }},\n"
        f"                .min_log_level = data::severity::info,\n"
        f"                .fallback_retry= data::retry_policy{{\n"
        f"                    .max_attempts       = 1u,\n"
        f"                    .base_delay         = 200ms,\n"
        f"                    .backoff_multiplier = 1.0,\n"
        f"                    .deadline           = std::nullopt,\n"
        f"                }},\n"
        f"            }},\n"
        f"        }},\n"
        f"        .routes                = std::map<std::string, data::routing_rule>{{\n"
        f"            {{\"api\", data::routing_rule{{\n"
        f"                .pattern          = \"/api/*\",\n"
        f"                .backend_names    = std::vector<std::string>{{\"primary\"}},\n"
        f"                .timeout_override = 1500ms,\n"
        f"            }}}},\n"
        f"            {{\"health\", data::routing_rule{{\n"
        f"                .pattern          = \"/health\",\n"
        f"                .backend_names    = std::vector<std::string>{{\"primary\"}},\n"
        f"                .timeout_override = std::nullopt,\n"
        f"            }}}},\n"
        f"        }},\n"
        f"        .env                   = std::unordered_map<std::string, std::string>{{\n"
        f"            {{\"LOG_LEVEL\", \"info\"}},\n"
        f"            {{\"MAX_CONN\",  \"100\"}},\n"
        f"        }},\n"
        f"        .rate_limits           = std::vector<data::rate_limit_entry>{{\n"
        f"            data::rate_limit_entry{{\"user\", 1000u, true}},\n"
        f"            data::rate_limit_entry{{\"anon\",  100u, false}},\n"
        f"        }},\n"
        f"        .allowed_origins       = std::set<std::string>{{\n"
        f"            \"https://app.example.com\",\n"
        f"            \"https://example.com\",\n"
        f"        }},\n"
        f"        .config_tree           = {config_tree_cpp},\n"
        f"        .admin_endpoint        = data::network_address{{.host = \"admin.local\", .port = 8080}},\n"
        f"        .global_thresholds     = std::map<std::string, std::vector<data::threshold_rule>>{{\n"
        f"            {{\"memory\", std::vector<data::threshold_rule>{{\n"
        f"                data::threshold_rule{{\n"
        f"                    .metric_name       = \"mem_usage\",\n"
        f"                    .warn_at           = 75.0,\n"
        f"                    .crit_at           = 95.0,\n"
        f"                    .evaluation_window = {s_literal(120)},\n"
        f"                }},\n"
        f"            }}}},\n"
        f"        }},\n"
        f"        .shutdown_grace_period = 15s,\n"
        f"        .warmup_delay          = 2s,\n"
        f"    }};\n\n"
        f"    ASSERT_DEEP_EQ(parsed, expected);\n"
        f"}}\n"
    )


def bad_test(depth: int, error_kind: str, at: int) -> str:
    assert 1 <= at <= depth, f"--at {at} must be in [1, {depth}]"
    assert error_kind in ERROR_KINDS, f"unknown error kind: {error_kind}"

    json_body = build_outer_json(depth, corrupt_at={at: error_kind})
    name      = f"ServiceConfig{depth}Bad_{error_kind}_at{at}"
    desc      = {
        "missing_field": f'missing required "scope" field at nesting level {at}',
        "wrong_type":    f'"port" is a string instead of int at nesting level {at}',
    }[error_kind]

    var = f"json_{depth}_{error_kind}_at{at}"
    return (
        f"// {'─' * 77}\n"
        f"// Error: {desc}\n\n"
        f"namespace\n{{\n\n"
        f"std::string_view {var} = R\"json(\n{json_body}\n)json\";\n\n"
        f"}} // namespace\n\n"
        f"// {'─' * 77}\n\n"
        f"TEST(service_config_parse, {name})\n{{\n"
        f"    EXPECT_ANY_THROW(\n"
        f"        json::exceptions::as<data::service_config>({var})\n"
        f"    );\n"
        f"}}\n"
    )


# ── CLI ───────────────────────────────────────────────────────────────────────

def parse_args():
    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    sub = p.add_subparsers(dest="cmd", required=True)

    ok_p = sub.add_parser("ok", help="generate valid test(s)")
    ok_p.add_argument("--depth", type=int, nargs="+", required=True,
                      metavar="N", help="nesting depth(s), e.g. --depth 10 25 50")
    ok_p.add_argument("--out", required=True, metavar="FILE", help="output .cpp file")

    bad_p = sub.add_parser("bad", help="generate error test(s)")
    bad_p.add_argument("--depth", type=int, required=True,
                       metavar="N", help="total nesting depth of the JSON")
    bad_p.add_argument("--error", nargs="+", required=True,
                       choices=ERROR_KINDS,
                       help="error kind(s): missing_field, wrong_type")
    bad_p.add_argument("--at", type=int, nargs="+", required=True,
                       metavar="LEVEL",
                       help="nesting level(s) where the error is injected")
    bad_p.add_argument("--out", required=True, metavar="FILE", help="output .cpp file")

    return p.parse_args()


def main():
    args = parse_args()
    parts = [HEADER]

    if args.cmd == "ok":
        for d in args.depth:
            print(f"  generating ok depth={d} ...", flush=True)
            parts.append(ok_test(d))

    elif args.cmd == "bad":
        errors = args.error
        levels = args.at
        if len(errors) == 1:
            errors = errors * len(levels)
        if len(levels) == 1:
            levels = levels * len(errors)
        if len(errors) != len(levels):
            sys.exit("--error and --at must have the same count (or one of them can be a single value)")

        for kind, at in zip(errors, levels):
            print(f"  generating bad depth={args.depth} error={kind} at={at} ...", flush=True)
            parts.append(bad_test(args.depth, kind, at))

    out = Path(args.out)
    out.write_text("".join(parts), encoding="utf-8")
    lines = sum(p.count("\n") for p in parts)
    print(f"written -> {out}  ({out.stat().st_size // 1024} KB, {lines} lines)")


if __name__ == "__main__":
    main()