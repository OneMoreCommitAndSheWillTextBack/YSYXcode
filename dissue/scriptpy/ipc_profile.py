#!/usr/bin/env python3
"""Summarize IPC from the fixed test log directory."""

from __future__ import annotations

import re
import sys
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Optional


REPO_ROOT = Path(__file__).resolve().parent.parent
TEST_BUILD_DIR = REPO_ROOT / "test" / "build"
OUTPUT_DIR = REPO_ROOT / "run" / "ipc-log"

# Whole-program logs do not expose a cycle-by-cycle warmup boundary. Keep only
# sufficiently long samples in the headline IPC, then aggregate as commits/cycles.
MIN_STEADY_COMMITS = 4096
MIN_STEADY_CYCLES = 4096

ANSI_ESCAPE_RE = re.compile(r"\x1B\[[0-?]*[ -/]*[@-~]")
RESULT_RE = re.compile(r"^\[(?P<name>[^\]]+)\]\s+(?P<status>PASS|\*\*\*FAIL\*\*\*)\s*$")
CYCLES_RE = re.compile(
    r"cycles:\s*(?P<cycles>\d+),\s*total commits:\s*(?P<commits>\d+),\s*ipc:\s*(?P<ipc>[0-9.]+)"
)
ICACHE_RATE_RE = re.compile(r"Icache hit rate:\s*(?P<rate>[0-9.]+)")
BPU_RE = re.compile(
    r"BPU:\s*predictions:\s*(?P<predictions>\d+),\s*correct:\s*(?P<correct>\d+),\s*accuracy:\s*[0-9.]+%"
)
DCACHE_RE = re.compile(
    r"DCache:\s*access:\s*(?P<access>\d+),\s*hit:\s*(?P<hit>\d+),\s*miss:\s*(?P<miss>\d+),"
    r"\s*bypass:\s*(?P<bypass>\d+),\s*hit rate:\s*[0-9.]+%"
)


@dataclass(frozen=True)
class TestProfile:
    extension: str
    test: str
    log_path: Path
    status: str = "PASS"
    commits: Optional[int] = None
    cycles: Optional[int] = None
    icache_rate: Optional[float] = None
    bpu_rate: Optional[float] = None
    dcache_rate: Optional[float] = None
    error: Optional[str] = None

    @property
    def valid(self) -> bool:
        return self.status == "PASS" and self.commits is not None and self.cycles is not None and self.cycles > 0

    @property
    def ipc(self) -> Optional[float]:
        if not self.valid:
            return None
        return self.commits / self.cycles

    @property
    def steady(self) -> bool:
        return self.valid and (self.commits >= MIN_STEADY_COMMITS or self.cycles >= MIN_STEADY_CYCLES)


def cycles_per_second() -> str:
    # The backend performance tool does not report elapsed wall-clock time yet.
    return "-"


def strip_ansi(text: str) -> str:
    return ANSI_ESCAPE_RE.sub("", text)


def last_match(pattern: re.Pattern[str], text: str) -> Optional[re.Match[str]]:
    matches = list(pattern.finditer(text))
    return matches[-1] if matches else None


def reported_tests(result_path: Path) -> list[tuple[str, str]]:
    results: dict[str, str] = {}
    for line in strip_ansi(result_path.read_text(encoding="utf-8", errors="replace")).splitlines():
        match = RESULT_RE.match(line.strip())
        if match:
            name = match.group("name").strip()
            results[name] = "PASS" if match.group("status") == "PASS" else "FAIL"
    return list(results.items())


def parse_log(extension: str, test: str, log_path: Path) -> TestProfile:
    if not log_path.is_file():
        return TestProfile(extension, test, log_path, error="missing log")

    text = strip_ansi(log_path.read_text(encoding="utf-8", errors="replace"))
    cycles_match = last_match(CYCLES_RE, text)
    if cycles_match is None:
        return TestProfile(extension, test, log_path, error="missing cycles/commits report")

    cycles = int(cycles_match.group("cycles"))
    commits = int(cycles_match.group("commits"))
    if cycles == 0:
        return TestProfile(extension, test, log_path, error="zero cycles")

    icache_match = last_match(ICACHE_RATE_RE, text)
    bpu_match = last_match(BPU_RE, text)
    dcache_match = last_match(DCACHE_RE, text)

    icache_rate = float(icache_match.group("rate")) if icache_match else None
    bpu_rate = None
    if bpu_match:
        predictions = int(bpu_match.group("predictions"))
        correct = int(bpu_match.group("correct"))
        if predictions:
            bpu_rate = correct / predictions

    dcache_rate = None
    if dcache_match:
        hits = int(dcache_match.group("hit"))
        misses = int(dcache_match.group("miss"))
        if hits + misses:
            dcache_rate = hits / (hits + misses)

    return TestProfile(
        extension=extension,
        test=test,
        log_path=log_path,
        commits=commits,
        cycles=cycles,
        icache_rate=icache_rate,
        bpu_rate=bpu_rate,
        dcache_rate=dcache_rate,
    )


def collect_profiles() -> tuple[list[TestProfile], list[str]]:
    profiles: list[TestProfile] = []
    warnings: list[str] = []
    result_paths = sorted(TEST_BUILD_DIR.glob("*/result.txt"))
    if not result_paths:
        return profiles, [f"no result manifests found under {TEST_BUILD_DIR}"]

    for result_path in result_paths:
        extension = result_path.parent.name
        tests = reported_tests(result_path)
        if not tests:
            warnings.append(f"{extension}: no test results in {result_path.name}")
            continue
        for test, status in tests:
            log_path = result_path.parent / "logs" / f"{test}.log"
            profile = (
                parse_log(extension, test, log_path)
                if status == "PASS"
                else TestProfile(extension, test, log_path, status=status, error="test failed")
            )
            profiles.append(profile)
            if profile.error:
                warnings.append(f"{extension}/{test}: {profile.error}")

    return sorted(profiles, key=lambda profile: (profile.extension, profile.test)), warnings


def aggregate_ipc(profiles: list[TestProfile]) -> float:
    commits = sum(profile.commits for profile in profiles if profile.valid)
    cycles = sum(profile.cycles for profile in profiles if profile.valid)
    return commits / cycles


def format_rate(rate: Optional[float]) -> str:
    return "-" if rate is None else f"{rate * 100:.2f}%"


def format_count(value: Optional[int]) -> str:
    return "-" if value is None else str(value)


def profile_path(output_dir: Path, timestamp: str) -> Path:
    candidate = output_dir / f"profile-{timestamp}.txt"
    index = 1
    while candidate.exists():
        candidate = output_dir / f"profile-{timestamp}-{index:02d}.txt"
        index += 1
    return candidate


def render_profile(
    now: datetime,
    profiles: list[TestProfile],
    steady_profiles: list[TestProfile],
    all_ipc: float,
    headline_ipc: float,
    filter_description: str,
    warnings: list[str],
) -> str:
    extension_width = max(len("extension"), *(len(profile.extension) for profile in profiles))
    test_width = max(len("test"), *(len(profile.test) for profile in profiles))
    header = (
        f"{'extension':<{extension_width}}  {'test':<{test_width}}  {'status':<6}  {'commits':>12}  {'cycles':>12}  "
        f"{'ipc':>8}  {'icache':>9}  {'bpu':>9}  {'dcache':>9}"
    )
    separator = "-" * len(header)
    lines = [
        "IPC profile",
        f"generated: {now.strftime('%Y-%m-%d %H:%M:%S %z')}",
        "headline ipc: {:.6f}".format(headline_ipc),
        f"headline filter: {filter_description}",
        f"headline samples: {len(steady_profiles)}",
        f"all valid samples ipc: {all_ipc:.6f}",
        f"cycles per second: {cycles_per_second()}",
        "",
        header,
        separator,
    ]

    for profile in profiles:
        ipc = "-" if profile.ipc is None else f"{profile.ipc:.6f}"
        lines.append(
            f"{profile.extension:<{extension_width}}  {profile.test:<{test_width}}  {profile.status:<6}  "
            f"{format_count(profile.commits):>12}  {format_count(profile.cycles):>12}  {ipc:>8}  "
            f"{format_rate(profile.icache_rate):>9}  {format_rate(profile.bpu_rate):>9}  "
            f"{format_rate(profile.dcache_rate):>9}"
        )

    if warnings:
        lines.extend(["", "warnings:"])
        lines.extend(f"- {warning}" for warning in warnings)

    return "\n".join(lines) + "\n"


def main() -> int:
    profiles, warnings = collect_profiles()
    valid_profiles = [profile for profile in profiles if profile.valid]
    if not valid_profiles:
        print("ipc profile: no valid cycles/commits reports found", file=sys.stderr)
        for warning in warnings:
            print(f"warning: {warning}", file=sys.stderr)
        return 1

    steady_profiles = [profile for profile in valid_profiles if profile.steady]
    filter_description = (
        f"commits >= {MIN_STEADY_COMMITS} or cycles >= {MIN_STEADY_CYCLES}; weighted commits/cycles"
    )
    if not steady_profiles:
        steady_profiles = valid_profiles
        filter_description = "no long samples available; all valid samples, weighted commits/cycles"

    all_ipc = aggregate_ipc(valid_profiles)
    headline_ipc = aggregate_ipc(steady_profiles)
    headline_commits = sum(profile.commits for profile in steady_profiles)
    headline_cycles = sum(profile.cycles for profile in steady_profiles)

    now = datetime.now().astimezone()
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    profile_output = profile_path(OUTPUT_DIR, now.strftime("%Y%m%d%H%M"))
    profile_output.write_text(
        render_profile(now, profiles, steady_profiles, all_ipc, headline_ipc, filter_description, warnings),
        encoding="utf-8",
    )

    history_path = OUTPUT_DIR / "ipc-history.txt"
    with history_path.open("a", encoding="utf-8") as history_file:
        history_file.write(
            f"{now.strftime('%Y-%m-%d %H:%M:%S %z')} | ipc={headline_ipc:.6f} | "
            f"cycles/s={cycles_per_second()} | tests={len(steady_profiles)} | commits={headline_commits} | "
            f"cycles={headline_cycles} | filter={filter_description}\n"
        )

    print(f"ipc profile: {profile_output.relative_to(REPO_ROOT)}")
    print(f"ipc history: {history_path.relative_to(REPO_ROOT)}")
    print(f"headline ipc: {headline_ipc:.6f} ({len(steady_profiles)} long samples)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
