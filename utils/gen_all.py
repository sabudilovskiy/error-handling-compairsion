"""
gen_all.py — batch runner для gen_test.py.

Читает gen_all.jsonc и последовательно вызывает gen_test.py для каждой записи.

Формат gen_all.jsonc — массив объектов:
  [
    {
      "cmd":           "ok",                // "ok" | "bad"        (обязательно)
      "group":         "ok_large",          // --group             (обязательно)
      "quantity":      10,                  // --quantity          (или "seed", не вместе)
      "seed":          1,                   // --seed              (или "quantity", не вместе)
      "config":        "config/large.jsonc",// --config            (опционально)
      "tests_dir":     "../tests",          // --tests-dir         (опционально)
      "resources_dir": "../resources",      // --resources-dir     (опционально)
      // только для cmd == "bad":
      "error": "wrong_type",               // --error             (обязательно для bad)
      "at":    3                            // --at                (обязательно для bad)
    },
    ...
  ]

Примеры:
  python gen_all.py
  python gen_all.py gen_all.jsonc
  python gen_all.py my_suite.json
"""

import json
import subprocess
import sys
from pathlib import Path

# ── JSONC: strip // and /* */ comments before parsing ────────────────────────

def _strip_comments(text: str) -> str:
    import re
    # block comments
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.DOTALL)
    # line comments (not inside strings — good enough for config files)
    text = re.sub(r'//[^\n]*', '', text)
    return text


def load_jsonc(path: Path) -> object:
    raw = path.read_text(encoding="utf-8")
    return json.loads(_strip_comments(raw))


# ── validation ────────────────────────────────────────────────────────────────

_REQUIRED     = {"cmd", "group"}
_BAD_REQUIRED = {"error", "at"}
_KNOWN        = {"cmd", "group", "quantity", "seed", "config",
                 "tests_dir", "resources_dir", "clean", "error", "at"}
_CMDS         = ("ok", "bad")
_ERRORS       = ("missing_field", "wrong_type")


def _validate(entry: object, idx: int) -> None:
    if not isinstance(entry, dict):
        raise SystemExit(f"entry #{idx}: expected object, got {type(entry).__name__}")

    unknown = set(entry) - _KNOWN
    if unknown:
        raise SystemExit(f"entry #{idx}: unknown fields: {', '.join(sorted(unknown))}")

    missing = _REQUIRED - set(entry)
    if missing:
        raise SystemExit(f"entry #{idx}: missing required fields: {', '.join(sorted(missing))}")

    if entry["cmd"] not in _CMDS:
        raise SystemExit(f"entry #{idx}: cmd must be one of {_CMDS}, got {entry['cmd']!r}")

    if entry["cmd"] == "bad":
        missing_bad = _BAD_REQUIRED - set(entry)
        if missing_bad:
            raise SystemExit(f"entry #{idx}: bad cmd requires: {', '.join(sorted(missing_bad))}")
        if entry["error"] not in _ERRORS:
            raise SystemExit(f"entry #{idx}: error must be one of {_ERRORS}, got {entry['error']!r}")

    if "quantity" in entry and "seed" in entry:
        raise SystemExit(f"entry #{idx}: 'quantity' and 'seed' are mutually exclusive")


# ── build argv for gen_test.py ────────────────────────────────────────────────

def _build_argv(entry: dict, gen_test: Path) -> list[str]:
    argv = [sys.executable, str(gen_test)]

    # global flags first (before subcommand)
    argv += ["--group", entry["group"]]

    if "seed" in entry:
        argv += ["--seed", str(entry["seed"])]
    elif "quantity" in entry:
        argv += ["--quantity", str(entry["quantity"])]

    if "config" in entry:
        argv += ["--config", str(entry["config"])]

    if "tests_dir" in entry:
        argv += ["--tests-dir", str(entry["tests_dir"])]

    if "resources_dir" in entry:
        argv += ["--resources-dir", str(entry["resources_dir"])]

    if entry.get("clean"):
        argv.append("--clean")

    # subcommand
    argv.append(entry["cmd"])

    if entry["cmd"] == "bad":
        argv += ["--error", entry["error"]]
        argv += ["--at",    str(entry["at"])]

    return argv


# ── main ──────────────────────────────────────────────────────────────────────

def main() -> None:
    suite_path = Path(sys.argv[1]) if len(sys.argv) > 1 else Path("gen_all.jsonc")
    gen_test   = Path(__file__).with_name("gen_test.py")

    if not suite_path.exists():
        raise SystemExit(f"suite file not found: {suite_path}")
    if not gen_test.exists():
        raise SystemExit(f"gen_test.py not found next to gen_all.py: {gen_test}")

    entries = load_jsonc(suite_path)
    if not isinstance(entries, list):
        raise SystemExit(f"{suite_path}: expected a JSON array at top level")

    for idx, entry in enumerate(entries):
        _validate(entry, idx)

    total = len(entries)
    print(f"gen_all: {suite_path} — {total} entr{'y' if total == 1 else 'ies'}\n")

    for idx, entry in enumerate(entries):
        argv = _build_argv(entry, gen_test)
        print(f"[{idx + 1}/{total}] {' '.join(argv[2:])}")  # skip python + script path
        result = subprocess.run(argv)
        if result.returncode != 0:
            raise SystemExit(f"\nentry #{idx} failed (exit {result.returncode}), aborting.")
        print()

    print(f"gen_all: done ({total} entr{'y' if total == 1 else 'ies'})")


if __name__ == "__main__":
    main()