#!/usr/bin/env python3
"""Classify direct-mapped ICache misses with a same-capacity set-associative shadow."""

from __future__ import annotations

import argparse
import re
from collections import OrderedDict
from dataclasses import dataclass
from pathlib import Path


LOOKUP_RE = re.compile(
    r"icache_lookup=\{valid=0x(?P<valid>[0-9a-fA-F]+),miss=0x(?P<miss>[0-9a-fA-F]+),"
    r"addr=\[0x(?P<addr0>[0-9a-fA-F]+),0x(?P<addr1>[0-9a-fA-F]+)\]\}"
)


class SetAssociativeCache:
    def __init__(self, capacity_bytes: int, line_bytes: int, ways: int) -> None:
        denominator = line_bytes * ways
        if capacity_bytes <= 0 or capacity_bytes % denominator:
            raise ValueError("capacity must be a positive multiple of line_bytes * ways")
        self.line_bytes = line_bytes
        self.ways = ways
        self.sets = capacity_bytes // denominator
        if self.sets & (self.sets - 1):
            raise ValueError("derived set count must be a power of two")
        self.entries = [OrderedDict() for _ in range(self.sets)]

    def clear(self) -> None:
        for cache_set in self.entries:
            cache_set.clear()

    def access(self, address: int) -> bool:
        line_number = address // self.line_bytes
        set_index = line_number & (self.sets - 1)
        tag = line_number // self.sets
        cache_set = self.entries[set_index]
        hit = tag in cache_set
        if hit:
            cache_set.move_to_end(tag)
        else:
            if len(cache_set) == self.ways:
                cache_set.popitem(last=False)
            cache_set[tag] = None
        return hit


@dataclass
class Results:
    cycles: int = 0
    invalidations: int = 0
    lookup_groups: int = 0
    actual_miss_groups: int = 0
    block_accesses: int = 0
    line_accesses: int = 0
    actual_misses: int = 0
    shadow_misses: int = 0
    conflict_misses: int = 0
    compulsory_misses: int = 0
    other_misses: int = 0
    shadow_only_misses: int = 0


def analyze(path: Path, capacity_bytes: int, line_bytes: int, shadow_ways: int) -> Results:
    shadow = SetAssociativeCache(capacity_bytes, line_bytes, shadow_ways)
    seen_lines: set[int] = set()
    results = Results()

    for text in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if text.startswith("#"):
            continue
        results.cycles += 1
        if "icache_invalidate" in text:
            shadow.clear()
            results.invalidations += 1

        match = LOOKUP_RE.search(text)
        if match is None:
            continue

        valid_mask = int(match.group("valid"), 16)
        miss_mask = int(match.group("miss"), 16)
        addresses = [int(match.group("addr0"), 16), int(match.group("addr1"), 16)]
        results.lookup_groups += 1

        line_misses: dict[int, bool] = {}
        for lane, address in enumerate(addresses):
            if not valid_mask & (1 << lane):
                continue
            results.block_accesses += 1
            line_address = address & ~(line_bytes - 1)
            line_misses[line_address] = line_misses.get(line_address, False) or bool(miss_mask & (1 << lane))

        if any(line_misses.values()):
            results.actual_miss_groups += 1

        for line_address, actual_miss in line_misses.items():
            results.line_accesses += 1
            shadow_hit = shadow.access(line_address)
            previously_seen = line_address in seen_lines
            seen_lines.add(line_address)

            if actual_miss:
                results.actual_misses += 1
                if shadow_hit:
                    results.conflict_misses += 1
                elif not previously_seen:
                    results.compulsory_misses += 1
                else:
                    results.other_misses += 1
            elif not shadow_hit:
                results.shadow_only_misses += 1

            if not shadow_hit:
                results.shadow_misses += 1

    return results


def ratio(numerator: int, denominator: int) -> str:
    return "0.000000" if denominator == 0 else f"{numerator / denominator:.6f}"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("trace", type=Path, help="simulator --detailed-trace-path output")
    parser.add_argument("--capacity-bytes", type=int, required=True)
    parser.add_argument("--line-bytes", type=int, required=True)
    parser.add_argument("--shadow-ways", type=int, default=2)
    args = parser.parse_args()

    if args.line_bytes <= 0 or args.line_bytes & (args.line_bytes - 1):
        parser.error("--line-bytes must be a power of two")
    if args.shadow_ways <= 0:
        parser.error("--shadow-ways must be positive")
    if not args.trace.is_file():
        parser.error(f"trace does not exist: {args.trace}")

    results = analyze(args.trace, args.capacity_bytes, args.line_bytes, args.shadow_ways)
    print("ICache shadow profile")
    print(f"trace: {args.trace}")
    print(
        f"geometry: capacity={args.capacity_bytes} line={args.line_bytes} "
        f"shadow_ways={args.shadow_ways}"
    )
    print(
        f"samples: cycles={results.cycles} invalidations={results.invalidations} "
        f"groups={results.lookup_groups} miss_groups={results.actual_miss_groups} "
        f"blocks={results.block_accesses} lines={results.line_accesses}"
    )
    print(
        f"actual: line_misses={results.actual_misses} "
        f"line_miss_rate={ratio(results.actual_misses, results.line_accesses)}"
    )
    print(
        f"shadow: misses={results.shadow_misses} miss_rate={ratio(results.shadow_misses, results.line_accesses)} "
        f"shadow_only={results.shadow_only_misses}"
    )
    print(
        f"classification: conflict={results.conflict_misses} compulsory={results.compulsory_misses} "
        f"other={results.other_misses}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
