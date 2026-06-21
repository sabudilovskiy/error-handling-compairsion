"""
gen_test.py — генератор GTest-файлов для service_config парсера.

Схема типов описывается декларативно. Из схемы генерируются и JSON и C++ expected.

Пример полного конфига (все поля опциональны, незаданные берут defaults):

  {
    "expand_chance":  0.7,   // вероятность сгенерировать следующий элемент массива
    "nesting_chance": 0.7,   // вероятность сгенерировать optional-поле если оно добавляет глубину
                             // (объект, box; для optional над примитивом — expand_chance)
    "max_nesting":    16,    // жёсткий потолок глубины вложенности

    "array_max_size": 8,     // максимальный размер массива (элементы добавляются по expand_chance)

    "int_min":   0,          // диапазон int-значений
    "int_max":   100000,
    "int_bias":  "small",    // "small" — смещено к min, "uniform" — плоское, "large" — к max

    "float_min":  -1000.0,   // диапазон float-значений
    "float_max":  1000.0,
    "float_bias": "uniform",

    "str_min_len": 0,        // диапазон длины строк
    "str_max_len": 32,
    "str_bias":    "small"
  }

  bias: степенная функция x^k от uniform[0,1]:
    "small"   k=3   — большинство значений у нижней границы
    "uniform" k=1   — равномерное
    "large"   k=1/3 — большинство значений у верхней границы

Примеры:
  python gen_test.py ok  --seed 1 --group ok_small
  python gen_test.py ok  --quantity 50 --group ok_small

  python gen_test.py bad --seed 1 --error missing_field --at 20 --group bad_mf
  python gen_test.py bad --seed 1 --error wrong_type    --at 20 --group bad_wt
  python gen_test.py bad --quantity 10 --error wrong_type --at 20 --group bad_wt

  python gen_test.py --config myconfig.json ok --seed 1 --group ok_custom

  # Явно задать директории:
  python gen_test.py ok --seed 1 --group ok_small --tests-dir /tmp/tests --resources-dir /tmp/res
"""

from __future__ import annotations

import argparse
import json
import random
from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

# Sentinel: OptionalNode/BoxNode возвращают это когда значение отсутствует.
# _struct_to_json и to_json списков фильтруют его из вывода.
_ABSENT = object()

# ── GenConfig ────────────────────────────────────────────────────────────────

BIAS_KINDS = ("small", "uniform", "large")

def _biased(rng: random.Random, lo: float, hi: float, bias: str) -> float:
    """Map uniform[0,1] to [lo, hi] with power-law bias.
    small   k=3   — most values near lo
    uniform k=1   — flat
    large   k=1/3 — most values near hi
    """
    u = rng.random()
    if bias == "small":
        t = u ** 3
    elif bias == "large":
        t = u ** (1 / 3)
    else:
        t = u
    return lo + (hi - lo) * t


@dataclass
class GenConfig:
    # expand_chance  — вероятность сгенерировать следующий элемент массива
    # nesting_chance — вероятность сгенерировать optional-поле, если оно добавляет глубину
    #                  (объекты, box; для optional над примитивом используется expand_chance)
    expand_chance:  float = 0.7
    nesting_chance: float = 0.7
    max_nesting:    int   = 16

    array_max_size: int = 8

    int_min:  int   = 0
    int_max:  int   = 100_000
    int_bias: str   = "small"

    float_min:  float = -1000.0
    float_max:  float =  1000.0
    float_bias: str   = "uniform"

    str_min_len: int = 0
    str_max_len: int = 32
    str_bias:    str = "small"

    def validate(self) -> None:
        for fname in ("int_bias", "float_bias", "str_bias"):
            v = getattr(self, fname)
            if v not in BIAS_KINDS:
                raise SystemExit(f"--config: {fname} must be one of {BIAS_KINDS}, got {v!r}")


# ── value nodes (JSON + C++ in one place) ────────────────────────────────────

class Node(ABC):
    """A generated value: knows how to render itself as JSON and as C++."""

    @abstractmethod
    def to_json(self) -> Any:
        """Return a value suitable for json.dumps."""

    @abstractmethod
    def to_cpp(self, indent: int = 0) -> str:
        """Return a C++ expression for this value."""


@dataclass
class NullNode(Node):
    def to_json(self): return None
    def to_cpp(self, indent=0): return "std::nullopt"


@dataclass
class BoolNode(Node):
    value: bool
    def to_json(self): return self.value
    def to_cpp(self, indent=0): return "true" if self.value else "false"


@dataclass
class IntNode(Node):
    value: int
    def to_json(self): return self.value
    def to_cpp(self, indent=0): return str(self.value)


@dataclass
class FloatNode(Node):
    value: float
    def to_json(self): return self.value
    def to_cpp(self, indent=0): return f"{self.value}"


@dataclass
class StrNode(Node):
    value: str
    def to_json(self): return self.value
    def to_cpp(self, indent=0): return f'"{self.value}"'


# ── chrono nodes ─────────────────────────────────────────────────────────────

def _fmt_ms_json(ms: int) -> str:
    if ms % 3_600_000 == 0: return f"{ms // 3_600_000}h"
    if ms % 60_000    == 0: return f"{ms // 60_000}m"
    if ms % 1_000     == 0: return f"{ms // 1_000}s"
    return f"{ms}ms"

def _fmt_ms_cpp(ms: int) -> str:
    if ms % 3_600_000 == 0: return f"{ms // 3_600_000}h"
    if ms % 60_000    == 0: return f"{ms // 60_000}min"
    if ms % 1_000     == 0: return f"{ms // 1_000}s"
    return f"{ms}ms"

def _fmt_s_json(s: int) -> str:
    if s % 3600 == 0: return f"{s // 3600}h"
    if s % 60   == 0: return f"{s // 60}m"
    return f"{s}s"

def _fmt_s_cpp(s: int) -> str:
    if s % 3600 == 0: return f"{s // 3600}h"
    if s % 60   == 0: return f"{s // 60}min"
    return f"{s}s"


@dataclass
class DurationMsNode(Node):
    ms: int
    def to_json(self): return _fmt_ms_json(self.ms)
    def to_cpp(self, indent=0): return _fmt_ms_cpp(self.ms)


@dataclass
class DurationSNode(Node):
    s: int
    def to_json(self): return _fmt_s_json(self.s)
    def to_cpp(self, indent=0): return _fmt_s_cpp(self.s)


# ── container nodes ───────────────────────────────────────────────────────────

@dataclass
class OptionalNode(Node):
    inner: Node | None          # None → nullopt
    cpp_type: str = ""          # если нужен явный тип для nullopt

    def to_json(self):
        return _ABSENT if self.inner is None else self.inner.to_json()

    def to_cpp(self, indent=0):
        if self.inner is None:
            return "std::nullopt"
        return self.inner.to_cpp(indent)


@dataclass
class BoxNode(Node):
    """common::box<T>{...} wrapper for recursive types."""
    inner: Node | None
    cpp_type: str               # T in common::box<T>

    def to_json(self):
        return _ABSENT if self.inner is None else self.inner.to_json()

    def to_cpp(self, indent=0):
        if self.inner is None:
            return f"common::box<{self.cpp_type}>{{}}"
        return f"common::box<{self.cpp_type}>{{{self.inner.to_cpp(indent)}}}"


@dataclass
class VecNode(Node):
    items: list[Node]
    cpp_elem_type: str

    def to_json(self):
        return [v for i in self.items if (v := i.to_json()) is not _ABSENT]

    def to_cpp(self, indent=0):
        ind = " " * indent
        ind4 = " " * (indent + 4)
        if not self.items:
            return f"std::vector<{self.cpp_elem_type}>{{}}"
        inner = f",\n{ind4}".join(i.to_cpp(indent + 4) for i in self.items)
        return f"std::vector<{self.cpp_elem_type}>{{\n{ind4}{inner},\n{ind}}}"


@dataclass
class SetNode(Node):
    items: list[Node]           # already sorted
    cpp_elem_type: str

    def to_json(self):
        return [v for i in self.items if (v := i.to_json()) is not _ABSENT]

    def to_cpp(self, indent=0):
        ind = " " * indent
        ind4 = " " * (indent + 4)
        if not self.items:
            return f"std::set<{self.cpp_elem_type}>{{}}"
        inner = f",\n{ind4}".join(i.to_cpp(indent + 4) for i in self.items)
        return f"std::set<{self.cpp_elem_type}>{{\n{ind4}{inner},\n{ind}}}"


@dataclass
class MapNode(Node):
    items: list[tuple[str, Node]]   # ordered
    cpp_key_type: str
    cpp_val_type: str

    def to_json(self):
        return {k: val for k, v in self.items if (val := v.to_json()) is not _ABSENT}

    def to_cpp(self, indent=0):
        ind = " " * indent
        ind4 = " " * (indent + 4)
        cpp_t = f"std::map<{self.cpp_key_type}, {self.cpp_val_type}>"
        if not self.items:
            return f"{cpp_t}{{}}"
        rows = []
        for k, v in self.items:
            row = '{"'  + k + '", ' + v.to_cpp(indent + 4) + '}'
            rows.append(row)
        inner = f",\n{ind4}".join(rows)
        return f"{cpp_t}{{\n{ind4}{inner},\n{ind}}}"


@dataclass
class UnorderedMapNode(Node):
    items: list[tuple[str, Node]]
    cpp_key_type: str
    cpp_val_type: str

    def to_json(self):
        return {k: val for k, v in self.items if (val := v.to_json()) is not _ABSENT}

    def to_cpp(self, indent=0):
        ind = " " * indent
        ind4 = " " * (indent + 4)
        cpp_t = f"std::unordered_map<{self.cpp_key_type}, {self.cpp_val_type}>"
        if not self.items:
            return f"{cpp_t}{{}}"
        rows = []
        for k, v in self.items:
            row = '{"'  + k + '", ' + v.to_cpp(indent + 4) + '}'
            rows.append(row)
        inner = f",\n{ind4}".join(rows)
        return f"{cpp_t}{{\n{ind4}{inner},\n{ind}}}"


@dataclass
class StructNode(Node):
    cpp_type: str
    fields: list[tuple[str, Node]]  # (field_name, node)

    def to_json(self):
        return {k: v.to_json() for k, v in self.fields}

    def to_cpp(self, indent=0):
        ind = " " * indent
        ind4 = " " * (indent + 4)
        if not self.fields:
            return f"{self.cpp_type}{{}}"
        rows = []
        for name, node in self.fields:
            rows.append(f".{name:<24} = {node.to_cpp(indent + 4)},")
        inner = f"\n{ind4}".join(rows)
        return f"{self.cpp_type}{{\n{ind4}{inner}\n{ind}}}"


# ── type descriptors (schema) ─────────────────────────────────────────────────

class TypeDesc(ABC):
    # Subclasses that wrap complex/nested types should set is_nesting = True.
    # TOptional uses this to pick nesting_chance vs expand_chance.
    is_nesting: bool = False

    # corruptible = False means corrupt_json will never pick this field as a
    # wrong_type target (e.g. boost::json::value accepts any JSON type).
    corruptible: bool = True

    @abstractmethod
    def generate(self, rng: random.Random, cfg: GenConfig, depth: int) -> Node:
        pass

    # for corrupt: enumerate all (json_path, TypeDesc, Node) leaf-or-field pairs
    # reachable from this type given a generated node.
    # depth in the returned path list == len(path).
    def collect_paths(self, node: Node, path: list) -> list[tuple[list, TypeDesc, Node]]:
        return []


@dataclass
class TBool(TypeDesc):
    def generate(self, rng, cfg, depth):
        return BoolNode(rng.random() < 0.5)
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class TInt(TypeDesc):
    # если заданы — используются вместо cfg.int_min/int_max
    min_val: int | None = None
    max_val: int | None = None

    def generate(self, rng, cfg, depth):
        lo = self.min_val if self.min_val is not None else cfg.int_min
        hi = self.max_val if self.max_val is not None else cfg.int_max
        val = int(_biased(rng, lo, hi, cfg.int_bias))
        return IntNode(val)
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class TFloat(TypeDesc):
    def generate(self, rng, cfg, depth):
        val = _biased(rng, cfg.float_min, cfg.float_max, cfg.float_bias)
        return FloatNode(round(val, 4))
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class TStr(TypeDesc):
    def generate(self, rng, cfg, depth):
        length = int(_biased(rng, cfg.str_min_len, cfg.str_max_len, cfg.str_bias))
        chars = [chr(rng.randint(ord('A'), ord('Z'))) for _ in range(length)]
        return StrNode("".join(chars))
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class TDurationMs(TypeDesc):
    nice_ms: list[int] = field(default_factory=lambda: [
        10, 25, 50, 100, 200, 500, 1_000, 2_000, 5_000, 10_000, 60_000, 3_600_000
    ])
    def generate(self, rng, cfg, depth):
        idx = int(_biased(rng, 0, len(self.nice_ms) - 1, "small"))
        return DurationMsNode(self.nice_ms[idx])
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class TDurationS(TypeDesc):
    nice_s: list[int] = field(default_factory=lambda: [
        5, 10, 15, 30, 60, 120, 300, 600, 3600
    ])
    def generate(self, rng, cfg, depth):
        idx = int(_biased(rng, 0, len(self.nice_s) - 1, "small"))
        return DurationSNode(self.nice_s[idx])
    def collect_paths(self, node, path): return [(list(path), self, node)]



# ── domain-specific leaf types ────────────────────────────────────────────────

_SEVERITY_VALS = ["debug", "info", "warning", "error", "critical"]
_SEVERITY_CPP  = [
    "data::severity::debug", "data::severity::info", "data::severity::warning",
    "data::severity::error", "data::severity::critical",
]

@dataclass
class TLogLevelEnum(TypeDesc):
    """optional<severity> in scope_override.log_level — generates a severity string in JSON,
    data::severity::xxx in C++."""
    def generate(self, rng, cfg, depth):
        idx = rng.randrange(len(_SEVERITY_VALS))
        return _SeverityNode(idx)
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class _SeverityNode(Node):
    idx: int
    def to_json(self): return _SEVERITY_VALS[self.idx]
    def to_cpp(self, indent=0): return _SEVERITY_CPP[self.idx]


@dataclass
class TLogLevelStr(TypeDesc):
    """severity as mandatory string field (backend_group.min_log_level)."""
    def generate(self, rng, cfg, depth):
        idx = rng.randrange(len(_SEVERITY_VALS))
        return _SeverityNode(idx)
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class TBoostJson(TypeDesc):
    """boost::json::value extra — always generates a simple string value.
    Not corruptible: boost::json::value accepts any JSON type, so wrong_type
    would never actually trigger a parse error."""
    corruptible: bool = False

    def generate(self, rng, cfg, depth):
        length = int(_biased(rng, cfg.str_min_len, cfg.str_max_len, cfg.str_bias))
        chars = [chr(rng.randint(ord('A'), ord('Z'))) for _ in range(length)]
        return _BoostJsonNode(StrNode("".join(chars)))
    def collect_paths(self, node, path): return [(list(path), self, node)]


@dataclass
class _BoostJsonNode(Node):
    """Wraps any node as a boost::json::value."""
    inner: Node
    def to_json(self): return self.inner.to_json()
    def to_cpp(self, indent=0):
        return f"boost::json::value_from({self.inner.to_cpp(indent)})"


@dataclass
class TDynMap(TypeDesc):
    """Map with randomly generated keys (unlike TMap which has fixed keys)."""
    cpp_key_type: str
    val_desc: TypeDesc
    cpp_val_type: str
    is_nesting: bool = True

    def generate(self, rng, cfg, depth):
        items = []
        seen = set()
        while len(items) < cfg.array_max_size and rng.random() < cfg.expand_chance:
            key = "".join(chr(rng.randint(ord('A'), ord('Z'))) for _ in range(rng.randint(2, 6)))
            if key not in seen:
                seen.add(key)
                items.append((key, self.val_desc.generate(rng, cfg, depth)))
        return MapNode(items, self.cpp_key_type, self.cpp_val_type)

    def collect_paths(self, node: MapNode, path):
        result = [(list(path), self, node)]
        for k, v in node.items:
            result.extend(self.val_desc.collect_paths(v, path + [k]))
        return result


@dataclass
class TDynUnorderedMap(TypeDesc):
    """UnorderedMap with randomly generated keys."""
    cpp_key_type: str
    val_desc: TypeDesc
    cpp_val_type: str
    is_nesting: bool = True

    def generate(self, rng, cfg, depth):
        items = []
        seen = set()
        while len(items) < cfg.array_max_size and rng.random() < cfg.expand_chance:
            key = "".join(chr(rng.randint(ord('A'), ord('Z'))) for _ in range(rng.randint(2, 6)))
            if key not in seen:
                seen.add(key)
                items.append((key, self.val_desc.generate(rng, cfg, depth)))
        return UnorderedMapNode(items, self.cpp_key_type, self.cpp_val_type)


@dataclass
class TOptional(TypeDesc):
    inner: TypeDesc
    always_present: bool = False    # если True — никогда не nullopt

    @property
    def is_nesting(self) -> bool:
        return self.inner.is_nesting

    def generate(self, rng, cfg, depth):
        if self.always_present:
            return OptionalNode(self.inner.generate(rng, cfg, depth))
        chance = cfg.nesting_chance if self.inner.is_nesting else cfg.expand_chance
        if rng.random() < chance:
            return OptionalNode(self.inner.generate(rng, cfg, depth))
        return OptionalNode(None)

    def collect_paths(self, node, path):
        if node.inner is not None:
            return self.inner.collect_paths(node.inner, path)
        return []


@dataclass
class TBox(TypeDesc):
    inner: TypeDesc
    cpp_type: str
    is_nesting: bool = True

    def generate(self, rng, cfg, depth):
        if depth >= cfg.max_nesting or rng.random() >= cfg.nesting_chance:
            return BoxNode(None, self.cpp_type)
        return BoxNode(self.inner.generate(rng, cfg, depth + 1), self.cpp_type)

    def collect_paths(self, node, path):
        if node.inner is not None:
            return self.inner.collect_paths(node.inner, path)
        return []


@dataclass
class TVec(TypeDesc):
    inner: TypeDesc
    cpp_elem_type: str
    is_nesting: bool = True

    def generate(self, rng, cfg, depth):
        items = []
        while len(items) < cfg.array_max_size and rng.random() < cfg.expand_chance:
            items.append(self.inner.generate(rng, cfg, depth))
        return VecNode(items, self.cpp_elem_type)

    def collect_paths(self, node, path):
        result = []
        for i, item in enumerate(node.items):
            result.extend(self.inner.collect_paths(item, path + [i]))
        return result


@dataclass
class TSet(TypeDesc):
    inner: TypeDesc
    cpp_elem_type: str
    is_nesting: bool = True

    def generate(self, rng, cfg, depth):
        seen = set()
        items = []
        while len(items) < cfg.array_max_size and rng.random() < cfg.expand_chance:
            n = self.inner.generate(rng, cfg, depth)
            v = n.to_json()
            if v not in seen:
                seen.add(v)
                items.append(n)
        items.sort(key=lambda n: n.to_json())
        return SetNode(items, self.cpp_elem_type)


@dataclass
class TMap(TypeDesc):
    """Map with fixed keys and typed values."""
    key_type: str
    val_desc: TypeDesc
    cpp_val_type: str
    keys: list[str]             # fixed key set

    def generate(self, rng, cfg, depth):
        items = [(k, self.val_desc.generate(rng, cfg, depth)) for k in self.keys]
        return MapNode(items, self.key_type, self.cpp_val_type)

    def collect_paths(self, node, path):
        result = []
        for k, v in node.items:
            result.extend(self.val_desc.collect_paths(v, path + [k]))
        return result


@dataclass
class TUnorderedMap(TypeDesc):
    key_type: str
    val_desc: TypeDesc
    cpp_val_type: str
    keys: list[str]

    def generate(self, rng, cfg, depth):
        items = [(k, self.val_desc.generate(rng, cfg, depth)) for k in self.keys]
        return UnorderedMapNode(items, self.key_type, self.cpp_val_type)


@dataclass
class FieldDesc:
    name: str
    json_key: str
    type_desc: TypeDesc
    mandatory: bool = True


@dataclass
class TStruct(TypeDesc):
    cpp_type: str
    fields: list[FieldDesc]
    is_nesting: bool = True

    @property
    def mandatory_json_keys(self) -> list[str]:
        return [f.json_key for f in self.fields if f.mandatory]

    def generate(self, rng, cfg, depth):
        result = []
        for f in self.fields:
            node = f.type_desc.generate(rng, cfg, depth)
            result.append((f.json_key, f.name, node))
        return StructNode(self.cpp_type, [(name, node) for _, name, node in result],
                          _json_fields=[(jk, node) for jk, _, node in result])

    def collect_paths(self, node: StructNode, path):
        result = [(list(path), self, node)]
        for fd in self.fields:
            # find the node for this field
            for fname, fnode in node.fields:
                if fname == fd.name:
                    result.extend(fd.type_desc.collect_paths(fnode, path + [fd.json_key]))
                    break
        return result


# StructNode needs to store json keys separately from cpp names
# Patch StructNode to carry both:
_orig_struct_init = StructNode.__init__

def _struct_init(self, cpp_type, fields, _json_fields=None):
    self.cpp_type = cpp_type
    self.fields = fields                        # [(cpp_name, Node)]
    self.json_fields = _json_fields or fields   # [(json_key, Node)]

StructNode.__init__ = _struct_init

def _struct_to_json(self):
    result = {}
    for k, v in self.json_fields:
        val = v.to_json()
        if val is not _ABSENT:
            result[k] = val
    return result

StructNode.to_json = _struct_to_json


# ── concrete schema ───────────────────────────────────────────────────────────

def _tag_type() -> TStruct:
    return TStruct("data::tag", [
        FieldDesc("key",   "key",   TStr(), mandatory=True),
        FieldDesc("value", "value", TStr(), mandatory=True),
    ])

def _network_address_type() -> TStruct:
    return TStruct("data::network_address", [
        FieldDesc("host", "host", TStr(),                          mandatory=True),
        FieldDesc("port", "port", TInt(min_val=1, max_val=65535),  mandatory=True),
    ])

def _retry_policy_type() -> TStruct:
    return TStruct("data::retry_policy", [
        FieldDesc("max_attempts",       "max_attempts",       TInt(min_val=1, max_val=100), mandatory=True),
        FieldDesc("base_delay",         "base_delay",         TDurationMs(), mandatory=True),
        FieldDesc("backoff_multiplier", "backoff_multiplier", TOptional(TFloat()), mandatory=False),
        FieldDesc("deadline",           "deadline",           TOptional(TDurationS()), mandatory=False),
    ])

def _endpoint_config_type() -> TStruct:
    return TStruct("data::endpoint_config", [
        FieldDesc("address",         "address",         _network_address_type(), mandatory=True),
        FieldDesc("connect_timeout", "connect_timeout", TDurationMs(),           mandatory=True),
        FieldDesc("retry",           "retry",           _retry_policy_type(),    mandatory=True),
        FieldDesc("tags",            "tags",
                  TOptional(TVec(_tag_type(), "data::tag")),                     mandatory=False),
        FieldDesc("tls_cert_path",   "tls_cert_path",   TOptional(TStr()),       mandatory=False),
    ])

def _threshold_rule_type() -> TStruct:
    return TStruct("data::threshold_rule", [
        FieldDesc("metric_name",       "metric_name",       TStr(),        mandatory=True),
        FieldDesc("warn_at",           "warn_at",           TFloat(),      mandatory=True),
        FieldDesc("crit_at",           "crit_at",           TFloat(),      mandatory=True),
        FieldDesc("evaluation_window", "evaluation_window", TDurationS(),  mandatory=True),
    ])

def _backend_group_type() -> TStruct:
    return TStruct("data::backend_group", [
        FieldDesc("name",           "name",      TStr(),    mandatory=True),
        FieldDesc("endpoints",      "endpoints",
                  TVec(_endpoint_config_type(), "data::endpoint_config"), mandatory=True),
        FieldDesc("min_log_level",  "min_log_level", TLogLevelStr(), mandatory=True),
        FieldDesc("alerts",         "alerts",
                  TOptional(TDynMap("std::string", _threshold_rule_type(),
                                    "data::threshold_rule")),            mandatory=False),
        FieldDesc("fallback_retry", "fallback_retry",
                  TOptional(_retry_policy_type()),                        mandatory=False),
    ])

def _routing_rule_type() -> TStruct:
    return TStruct("data::routing_rule", [
        FieldDesc("pattern",          "pattern",       TStr(), mandatory=True),
        FieldDesc("backend_names",    "backend_names",
                  TOptional(TVec(TStr(), "std::string")),       mandatory=False),
        FieldDesc("timeout_override", "timeout_override",
                  TOptional(TDurationMs()),                     mandatory=False),
    ])

def _rate_limit_entry_type() -> TStruct:
    # serialised as JSON array [name, limit, flag]
    # C++ type is std::tuple<std::string, std::uint32_t, bool>
    return TStruct("data::rate_limit_entry", [
        FieldDesc("name",  "0", TStr(),  mandatory=True),
        FieldDesc("limit", "1", TInt(),  mandatory=True),
        FieldDesc("flag",  "2", TBool(), mandatory=True),
    ])

# rate_limit_entry serialises as JSON array, special handling
class TRateLimitEntry(TypeDesc):
    def generate(self, rng, cfg, depth):
        node = _rate_limit_entry_type().generate(rng, cfg, depth)
        node._as_array = True
        return node
    def collect_paths(self, node, path):
        return _rate_limit_entry_type().collect_paths(node, path)

# patch StructNode.to_json to handle array-serialised structs
_orig_to_json = StructNode.to_json
def _patched_to_json(self):
    if getattr(self, "_as_array", False):
        return [val for _, v in self.json_fields if (val := v.to_json()) is not _ABSENT]
    result = {}
    for k, v in self.json_fields:
        val = v.to_json()
        if val is not _ABSENT:
            result[k] = val
    return result
StructNode.to_json = _patched_to_json

# C++ for rate_limit_entry: data::rate_limit_entry{"name", limit, flag}
_orig_to_cpp = StructNode.to_cpp
def _patched_to_cpp(self, indent=0):
    if getattr(self, "_as_array", False):
        vals = ", ".join(v.to_cpp(indent) for _, v in self.fields)
        return f"std::make_tuple({vals})"
    return _orig_to_cpp(self, indent)
StructNode.to_cpp = _patched_to_cpp


def _scope_override_type(depth_left: int) -> TStruct:
    """Recursive type; depth_left controls how deep we'll go."""
    LOG_LEVEL_TYPE = TOptional(TStr())  # null | "debug" | "info" | ...

    nested_type: TypeDesc
    if depth_left <= 0:
        nested_type = TBox(  # always empty box at leaf
            _scope_override_type(0), "data::scope_override"
        )
    else:
        nested_type = TBox(
            _scope_override_type(depth_left - 1), "data::scope_override"
        )

    return TStruct("data::scope_override", [
        FieldDesc("scope",              "scope",              TStr(),        mandatory=True),
        FieldDesc("log_level",          "log_level",          LOG_LEVEL_TYPE, mandatory=True),
        FieldDesc("retry",              "retry",
                  TOptional(_retry_policy_type()), mandatory=True),
        FieldDesc("endpoint_overrides", "endpoint_overrides",
                  TMap("std::string", _endpoint_config_type(), "data::endpoint_config",
                       keys=[]), mandatory=True),   # keys generated per-instance below
        FieldDesc("tags",               "tags",
                  TVec(_tag_type(), "data::tag"), mandatory=True),
        FieldDesc("extra",              "extra",
                  TOptional(TStr()), mandatory=True),
        FieldDesc("nested",             "nested",             nested_type,   mandatory=True),
    ])


# endpoint_overrides keys are dynamic — override TMap for scope_override
class TEndpointOverridesMap(TypeDesc):
    """Generates a map<string, endpoint_config> with randomly-named keys."""
    is_nesting = True

    def generate(self, rng, cfg, depth):
        ep_type = _endpoint_config_type()
        items = []
        seen_keys = set()
        while len(items) < cfg.array_max_size and rng.random() < cfg.expand_chance:
            key = f"ep_{rng.randint(1, 99)}"
            if key not in seen_keys:
                seen_keys.add(key)
                items.append((key, ep_type.generate(rng, cfg, depth)))
        return MapNode(items, "std::string", "data::endpoint_config")

    def collect_paths(self, node: MapNode, path):
        result = [(list(path), self, node)]
        ep_type = _endpoint_config_type()
        for k, v in node.items:
            result.extend(ep_type.collect_paths(v, path + [k]))
        return result


def _make_scope_override_type() -> TStruct:
    """scope_override with dynamic endpoint_overrides (no depth recursion here,
    handled by TBox depth limit in cfg)."""
    LOG_LEVEL_VALS = [None, "debug", "info", "warning", "error", "critical"]

    class TLogLevel(TypeDesc):
        def generate(self, rng, cfg, depth):
            v = LOG_LEVEL_VALS[int(abs(rng.gauss(0, 2))) % len(LOG_LEVEL_VALS)]
            return OptionalNode(StrNode(v) if v else None)
        def collect_paths(self, node, path):
            return [(list(path), self, node)]

    return TStruct("data::scope_override", [
        FieldDesc("scope",              "scope",     TStr(),              mandatory=True),
        FieldDesc("log_level",          "log_level", TLogLevel(),         mandatory=True),
        FieldDesc("retry",              "retry",     TOptional(_retry_policy_type()), mandatory=True),
        FieldDesc("endpoint_overrides", "endpoint_overrides",
                  TEndpointOverridesMap(), mandatory=True),
        FieldDesc("tags",               "tags",
                  TVec(_tag_type(), "data::tag"), mandatory=True),
        FieldDesc("extra",              "extra",     TOptional(TStr()),   mandatory=True),
        FieldDesc("nested",             "nested",
                  TBox(_make_scope_override_inner(), "data::scope_override"), mandatory=True),
    ])

# Forward declaration trick for recursive type
_SCOPE_DESC: TStruct | None = None

class TBoxScopeOverride(TypeDesc):
    cpp_type = "data::scope_override"
    is_nesting = True
    def generate(self, rng, cfg, depth):
        if depth >= cfg.max_nesting or rng.random() >= cfg.nesting_chance:
            return BoxNode(None, self.cpp_type)
        return BoxNode(_get_scope_desc().generate(rng, cfg, depth + 1), self.cpp_type)
    def collect_paths(self, node: BoxNode, path):
        if node.inner is None:
            return []
        return _get_scope_desc().collect_paths(node.inner, path)

def _get_scope_desc() -> TStruct:
    global _SCOPE_DESC
    if _SCOPE_DESC is None:
        _SCOPE_DESC = _build_scope_desc()
    return _SCOPE_DESC

def _build_scope_desc() -> TStruct:
    return TStruct("data::scope_override", [
        FieldDesc("scope",              "scope",     TStr(),              mandatory=True),
        FieldDesc("extra",              "extra",     TBoostJson(),        mandatory=True),
        FieldDesc("log_level",          "log_level", TOptional(TLogLevelEnum()), mandatory=False),
        FieldDesc("retry",              "retry",     TOptional(_retry_policy_type()), mandatory=False),
        FieldDesc("endpoint_overrides", "endpoint_overrides",
                  TOptional(TEndpointOverridesMap()),                    mandatory=False),
        FieldDesc("tags",               "tags",
                  TOptional(TVec(_tag_type(), "data::tag")),             mandatory=False),
        FieldDesc("nested",             "nested",    TBoxScopeOverride(), mandatory=True),
    ])


def _get_scope_override_opt() -> TypeDesc:
    """TypeDesc для optional<scope_override> (не box — просто структура).
    Переиспользует тот же _get_scope_desc()."""
    return _get_scope_desc()


def _service_config_type() -> TStruct:
    return TStruct("data::service_config", [
        FieldDesc("service_name",         "service_name",    TStr(),    mandatory=True),
        FieldDesc("worker_threads",       "worker_threads",  TInt(min_val=1, max_val=256), mandatory=True),
        FieldDesc("enable_tracing",       "enable_tracing",  TBool(),   mandatory=True),
        FieldDesc("shutdown_grace_period","shutdown_grace_period", TDurationS(), mandatory=True),
        FieldDesc("backends",             "backends",
                  TOptional(TVec(_backend_group_type(), "data::backend_group")), mandatory=False),
        FieldDesc("routes",               "routes",
                  TOptional(TDynMap("std::string", _routing_rule_type(),
                                    "data::routing_rule")),              mandatory=False),
        FieldDesc("env",                  "env",
                  TOptional(TDynUnorderedMap("std::string", TStr(), "std::string")),
                                                                         mandatory=False),
        FieldDesc("rate_limits",          "rate_limits",
                  TOptional(TVec(TRateLimitEntry(),
                                 "std::tuple<std::string, std::uint32_t, bool>")),
                                                                         mandatory=False),
        FieldDesc("allowed_origins",      "allowed_origins",
                  TOptional(TSet(TStr(), "std::string")),                mandatory=False),
        FieldDesc("config_tree",          "config_tree",
                  TOptional(_get_scope_override_opt()),                  mandatory=False),
        FieldDesc("admin_endpoint",       "admin_endpoint",
                  TOptional(_network_address_type()),                    mandatory=False),
        FieldDesc("global_thresholds",    "global_thresholds",
                  TOptional(TDynMap("std::string",
                                    TVec(_threshold_rule_type(), "data::threshold_rule"),
                                    "std::vector<data::threshold_rule>")), mandatory=False),
        FieldDesc("warmup_delay",         "warmup_delay",
                  TOptional(TDurationMs()),                              mandatory=False),
    ])


# ── corrupt ───────────────────────────────────────────────────────────────────

def _json_depth(obj: Any) -> int:
    if isinstance(obj, dict):
        if not obj:
            return 1
        return 1 + max(_json_depth(v) for v in obj.values())
    if isinstance(obj, list):
        if not obj:
            return 1
        return 1 + max(_json_depth(v) for v in obj)
    return 0


def _collect_at_depth(obj: Any, target: int, cur: int, path: list) -> list[tuple[list, Any, str | int]]:
    """
    Collect (path_to_parent, parent_obj, key) for every node at depth==target.
    parent_obj[key] is the node itself.
    """
    results = []
    if cur == target:
        return results  # we want nodes AT target, collected from parent
    if isinstance(obj, dict):
        for k, v in obj.items():
            if cur + 1 == target:
                results.append((list(path), obj, k))
            else:
                results.extend(_collect_at_depth(v, target, cur + 1, path + [k]))
    elif isinstance(obj, list):
        for i, v in enumerate(obj):
            if cur + 1 == target:
                results.append((list(path), obj, i))
            else:
                results.extend(_collect_at_depth(v, target, cur + 1, path + [i]))
    return results


def _wrong_type_value(original: Any, rng: random.Random) -> Any:
    """Return a value of a different type than original."""
    candidates = []
    if not isinstance(original, str):
        candidates.append(f"bad_value_{rng.randint(1000,9999)}")
    if not isinstance(original, (int, float)):
        candidates.append(rng.randint(0, 9999))
    if not isinstance(original, list):
        candidates.append([])
    if not isinstance(original, bool):
        candidates.append(rng.random() < 0.5)
    if original is not None:
        candidates.append(None)
    return rng.choice(candidates)


def _min_scope_override(scope_name: str) -> dict:
    """Минимальный валидный scope_override — только обязательные поля."""
    return {"scope": scope_name, "extra": ""}


def _pad_to_depth(raw_json: Any, target: int, rng: random.Random) -> Any:
    """Гарантирует что в JSON есть узел на глубине target."""
    import copy
    obj = copy.deepcopy(raw_json)

    if "config_tree" not in obj or not isinstance(obj.get("config_tree"), dict):
        obj["config_tree"] = _min_scope_override("_pad_root")

    node = obj["config_tree"]
    cur_depth = 1

    while "nested" in node and isinstance(node["nested"], dict):
        node = node["nested"]
        cur_depth += 1

    while cur_depth < target - 1:
        node["nested"] = _min_scope_override(f"_pad_{cur_depth}")
        node = node["nested"]
        cur_depth += 1

    return obj


def _corrupt_raw_json(
    obj: Any,
    error_kind: str,
    at: int,
    rng: random.Random,
) -> tuple[Any, list]:
    """Raw-JSON fallback for padded nodes that have no schema counterpart.
    Excludes keys named 'extra' from wrong_type candidates since those map to
    boost::json::value which accepts any JSON type."""
    import copy
    obj = copy.deepcopy(obj)

    candidates = _collect_at_depth(obj, at, 0, [])
    if not candidates:
        raise ValueError(f"_corrupt_raw_json: no nodes at depth {at}")

    if error_kind == "wrong_type":
        # exclude 'extra' keys — they map to boost::json::value
        filtered = [(p, par, k) for p, par, k in candidates if k != "extra"]
        if not filtered:
            filtered = candidates  # last resort
        path, parent, key = rng.choice(filtered)
        original = parent[key]
        parent[key] = _wrong_type_value(original, rng)
        return obj, path + [key]
    else:  # missing_field
        # Pad nodes are minimal scope_override structs — 'scope' is always mandatory.
        # Prefer deleting 'scope'; fall back to any key that is not 'extra' (boost::json::value).
        obj_candidates = [(p, par, k) for p, par, k in candidates
                          if isinstance(par[k], dict) and par[k]]
        if not obj_candidates:
            raise ValueError(f"_corrupt_raw_json: no dict nodes at depth {at}")
        path, parent, key = rng.choice(obj_candidates)
        target_dict = parent[key]
        mandatory_candidates = [k for k in target_dict if k != "extra"]
        del_key = rng.choice(mandatory_candidates if mandatory_candidates else list(target_dict.keys()))
        del target_dict[del_key]
        return obj, path + [key]


def corrupt_json(
    root_node: Node,
    root_schema: TypeDesc,
    error_kind: str,   # "missing_field" | "wrong_type"
    at: int,           # target depth (== len(path))
    rng: random.Random,
) -> tuple[Any, list]:
    """
    Build a corrupted JSON from root_node using schema-aware path collection.

    collect_paths gives us (path, TypeDesc, Node) for every reachable value.
    We filter to depth==at and apply the corruption on the JSON representation.

    wrong_type   → replace value at path with a wrong-typed value.
                   Skips non-corruptible types (e.g. TBoostJson).
    missing_field → find a dict-typed node at depth==at, delete one of its keys.
                   Uses the JSON object at that path, not the TypeDesc.
    """
    import copy

    all_paths = root_schema.collect_paths(root_node, [])

    if error_kind == "wrong_type":
        candidates = [
            (path, td, node)
            for path, td, node in all_paths
            if len(path) == at and td.corruptible
        ]
        if not candidates:
            raise ValueError(
                f"No corruptible nodes at depth {at} "
                f"(schema paths at that depth: "
                f"{[p for p, _, _ in all_paths if len(p) == at]})"
            )

        path, td, node = rng.choice(candidates)

        # Build corrupted JSON: deep-copy root JSON, navigate to parent, replace
        raw = root_node.to_json()
        obj = copy.deepcopy(raw)
        parent = obj
        for key in path[:-1]:
            parent = parent[key]
        original = parent[path[-1]]
        parent[path[-1]] = _wrong_type_value(original, rng)
        return obj, path

    else:  # missing_field
        # Only TStruct nodes have a well-defined set of mandatory fields.
        # Maps (TDynMap etc.) have no mandatory keys, so we skip them.
        candidates = [
            (path, td, node)
            for path, td, node in all_paths
            if len(path) == at
            and isinstance(td, TStruct)
            and td.mandatory_json_keys
        ]
        if not candidates:
            raise ValueError(
                f"No TStruct nodes with mandatory fields at depth {at} for missing_field"
            )

        raw = root_node.to_json()

        # Filter to those whose JSON value is actually present (optional structs
        # may be absent) and pick a mandatory key that exists in the rendered JSON.
        obj_candidates = []
        for path, td, node in candidates:
            val = raw
            try:
                for key in path:
                    val = val[key]
            except (KeyError, IndexError, TypeError):
                continue
            if not isinstance(val, dict):
                continue
            # Only keys that are both mandatory in schema AND present in the JSON
            deletable = [k for k in td.mandatory_json_keys if k in val]
            if deletable:
                obj_candidates.append((path, val, deletable))

        if not obj_candidates:
            raise ValueError(
                f"No TStruct nodes with deletable mandatory fields at depth {at}"
            )

        path, target_dict, deletable_keys = rng.choice(obj_candidates)
        del_key = rng.choice(deletable_keys)

        obj = copy.deepcopy(raw)
        parent = obj
        for key in path[:-1]:
            parent = parent[key]
        del parent[path[-1]][del_key]
        return obj, path


# ── C++ path rendering ────────────────────────────────────────────────────────

def render_cpp_path(error_path: list) -> str:
    """Render error_path as C++ path_value_t initialisation.
    Integer segments (array indices) are emitted as ull literals to
    avoid ambiguous overload between int and string variants."""

    def _seg(v) -> str:
        if isinstance(v, int):
            return f"{v}ull"
        return json.dumps(v)  # string → quoted

    if not error_path:
        return '        json::path_value_t exp {};'

    lines = []
    lines.append(f'        json::path_value_t exp {{ {_seg(error_path[0])} }};')
    for segment in error_path[1:]:
        lines.append(f'        exp.emplace_back({_seg(segment)});')
    return "\n".join(lines)


# ── test builders ─────────────────────────────────────────────────────────────

HEADER = """\
#include <gtest/gtest.h>

#include "common/box.hpp"
#include "data/types.hpp"
#include "helpers.hpp"
#include "json/exceptions.hpp"

"""


def ok_test(group: str, seed: int, root: StructNode) -> tuple[str, str]:
    json_body = json.dumps(root.to_json(), indent=2)
    cpp_expected = root.to_cpp(indent=4)
    json_filename = f"{group}/{seed}.json"
    test_name = f"{group}_{seed}"

    cpp = (
        f"TEST(service_config_parse, {test_name})\n{{\n"
        f"    using namespace std::chrono_literals;\n\n"
        f"    const std::string json = load_file(\"{json_filename}\");\n"
        f"    const auto parsed = json::exceptions::as<data::service_config>(json);\n\n"
        f"    const data::service_config expected = {cpp_expected};\n\n"
        f"    ASSERT_DEEP_EQ(parsed, expected);\n"
        f"}}\n"
    )
    return cpp, json_body


def bad_test(
    group: str,
    seed: int,
    root: StructNode,
    schema: TypeDesc,
    error_kind: str,
    at: int,
    rng: random.Random,
) -> tuple[str, str]:
    json_filename = f"{group}/{seed}.json"
    test_name = f"{group}_{seed}"
    corrupted, error_path = corrupt_json(root, schema, error_kind, at, rng)
    json_body = json.dumps(corrupted, indent=2)
    path_lines = render_cpp_path(error_path)

    cpp = (
        f"TEST(service_config_parse, {test_name})\n{{\n"
        f"    const std::string json = load_file(\"{json_filename}\");\n"
        f"    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)\n"
        f"    {{\n"
        f"{path_lines}\n"
        f"        EXPECT_EQ(ex.path(), exp);\n"
        f"    }};\n"
        f"}}\n"
    )
    return cpp, json_body


# ── single run ────────────────────────────────────────────────────────────────

# Directory containing this script — used to resolve default output paths.
_SCRIPT_DIR = Path(__file__).resolve().parent


def generate_one(args, seed: int, cfg: GenConfig) -> None:
    global _SCOPE_DESC
    _SCOPE_DESC = None  # reset cached recursive type per run

    rng = random.Random(seed)

    schema = _service_config_type()
    root: StructNode = schema.generate(rng, cfg, depth=0)

    group = args.group

    if args.cmd == "ok":
        print(f"  ok max_nesting={cfg.max_nesting} seed={seed} -> {group}/{seed}", flush=True)
        cpp, json_body = ok_test(group, seed, root)
    else:
        _MAX_RETRIES = 20
        attempt = 0
        best_root = root
        best_depth = _json_depth(root.to_json())
        while True:
            attempt += 1
            try:
                cpp, json_body = bad_test(group, seed, root, schema, args.error, args.at, rng)
                if attempt > 1:
                    print(f"  bad max_nesting={cfg.max_nesting} seed={seed} error={args.error} at={args.at} -> {group}/{seed} (attempt {attempt})", flush=True)
                else:
                    print(f"  bad max_nesting={cfg.max_nesting} seed={seed} error={args.error} at={args.at} -> {group}/{seed}", flush=True)
                break
            except ValueError as e:
                if attempt >= _MAX_RETRIES:
                    print(f"  padded after {attempt} retries: padding to depth {args.at}", flush=True)
                    pad_target = args.at if args.error == "wrong_type" else args.at + 1
                    padded_json = _pad_to_depth(best_root.to_json(), pad_target, rng)
                    # corrupt_json now needs a Node+schema; for padded JSON we fall back
                    # to the raw-JSON path since the pad nodes have no schema counterpart
                    corrupted, error_path = _corrupt_raw_json(padded_json, args.error, args.at, rng)
                    json_body = json.dumps(corrupted, indent=2)
                    path_lines = render_cpp_path(error_path)
                    json_filename = f"{group}/{seed}.json"
                    test_name = f"{group}_{seed}"
                    cpp = (
                        f"TEST(service_config_parse, {test_name})\n{{\n"
                        f"    const std::string json = load_file(\"{json_filename}\");\n"
                        f"    EXPECT_THROW_THAT(json::exceptions::as<data::service_config>(json), json::exceptions::parse_error)\n"
                        f"    {{\n"
                        f"{path_lines}\n"
                        f"        EXPECT_EQ(ex.path(), exp);\n"
                        f"    }};\n"
                        f"}}\n"
                    )
                    print(f"  bad max_nesting={cfg.max_nesting} seed={seed} error={args.error} at={args.at} -> {group}/{seed} (padded)", flush=True)
                    break
                print(f"  retry #{attempt}: {e} — regenerating with seed {seed + attempt}", flush=True)
                _SCOPE_DESC = None
                rng = random.Random(seed + attempt)
                schema = _service_config_type()
                root = schema.generate(rng, cfg, depth=0)
                d = _json_depth(root.to_json())
                if d > best_depth:
                    best_depth = d
                    best_root = root

    tests_dir     = Path(args.tests_dir)
    resources_dir = Path(args.resources_dir)

    cpp_path  = tests_dir     / group / f"{seed}.cpp"
    json_path = resources_dir / group / f"{seed}.json"

    cpp_path.parent.mkdir(parents=True, exist_ok=True)
    json_path.parent.mkdir(parents=True, exist_ok=True)

    cpp_path.write_text(HEADER + cpp, encoding="utf-8")
    json_path.write_text(json_body, encoding="utf-8")

    print(f"written -> {cpp_path}  ({cpp_path.stat().st_size // 1024} KB)")
    print(f"         + {json_path}  ({json_path.stat().st_size // 1024} KB)")


# ── CLI ───────────────────────────────────────────────────────────────────────

ERROR_KINDS = ("missing_field", "wrong_type")


def _load_config(path: str | None) -> GenConfig:
    base = GenConfig(
        nesting_chance=0.85,
        expand_chance=0.7,
    )
    if not path:
        return base

    try:
        raw = Path(path).read_text(encoding="utf-8")
        overrides = json.loads(raw)
    except FileNotFoundError:
        raise SystemExit(f"--config: file not found: {path}")
    except json.JSONDecodeError as e:
        raise SystemExit(f"--config: invalid JSON in {path}: {e}")

    if not isinstance(overrides, dict):
        raise SystemExit("--config: expected a JSON object at top level")

    valid_fields = set(GenConfig.__dataclass_fields__)
    unknown = set(overrides) - valid_fields
    if unknown:
        raise SystemExit(f"--config: unknown fields: {', '.join(sorted(unknown))}")

    for k, v in overrides.items():
        setattr(base, k, v)

    base.validate()
    return base


def _default_tests_dir() -> str:
    return str(_SCRIPT_DIR.parent / "tests/generated")

def _default_resources_dir() -> str:
    return str(_SCRIPT_DIR.parent / "resources")


def parse_args():
    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    seed_group = p.add_mutually_exclusive_group()
    seed_group.add_argument("--seed",     type=int, default=0, metavar="N")
    seed_group.add_argument("--quantity", type=int,            metavar="N",
                            help="generate N files with seeds 1..N")
    p.add_argument("--group", required=True, metavar="GROUP",
                   help="group name; files go to <tests-dir>/<group>/<seed>.cpp")
    p.add_argument("--config", metavar="FILE", default=None,
                   help="path to a JSON file with GenConfig overrides; unset fields keep defaults")
    p.add_argument("--tests-dir",     metavar="DIR", default=None,
                   help="root for .cpp output (default: <repo>/tests)")
    p.add_argument("--resources-dir", metavar="DIR", default=None,
                   help="root for .json output (default: <repo>/resources)")

    sub = p.add_subparsers(dest="cmd", required=True)

    sub.add_parser("ok")

    bad_p = sub.add_parser("bad")
    bad_p.add_argument("--error", required=True, choices=ERROR_KINDS)
    bad_p.add_argument("--at",    type=int, required=True, metavar="DEPTH",
                       help="JSON depth at which to corrupt")

    args = p.parse_args()

    # Resolve defaults here so _SCRIPT_DIR is available
    if args.tests_dir is None:
        args.tests_dir = _default_tests_dir()
    if args.resources_dir is None:
        args.resources_dir = _default_resources_dir()

    return args


def main():
    args = parse_args()
    cfg = _load_config(args.config)
    if args.quantity is not None:
        for seed in range(1, args.quantity + 1):
            generate_one(args, seed, cfg)
    else:
        generate_one(args, args.seed, cfg)


if __name__ == "__main__":
    main()