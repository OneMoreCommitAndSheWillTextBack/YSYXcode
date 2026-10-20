#!/usr/bin/env python3
"""
Checkpoint suite: plans -> NEMU snapshots -> self-restoring images -> runs.

For every plan (a point list plus the guest it applies to) this does three
phases:

  prep   NEMU runs the guest with its debug server attached; ckpt_gen.py steps
         to each point and writes a snapshot.
  pack   pack turns each snapshot into an image that restores itself, so the
         simulator only ever needs its ordinary --image path.
  run    every image is executed on NEMU and on the DUT. The two runs have to
         agree on the verdict, on the client output and on how many
         instructions they executed: a wrong restore sends the guest down a
         different path and the counts stop matching.

Artifacts live under --artifacts (tmpfs by default) and are always regenerable
from the plans.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import socket
import subprocess
import sys
from pathlib import Path

ANSI = re.compile(r"\x1b\[[0-9;]*m")
NEMU_INSTRUCTIONS = re.compile(r"total guest instructions = ([\d,]+)")
DUT_COMMITS = re.compile(r"total commits: (\d+)")

# Lines the simulators print about themselves, as opposed to lines the guest
# produced. Guest output has to survive this filter so the two runs can be
# compared byte for byte.
SIM_LINE = re.compile(
    r"^(\[src/|\[Error\]|\[Warning\]|-> 0x|0x[0-9a-f]{8}:|trace:|Welcome to|For help"
    r"|HIT (GOOD|BAD) TRAP|simulation (aborted|finished))"
)


class Failure(Exception):
    pass


def clean(text: str) -> str:
    return ANSI.sub("", text)


def guest_output(log: str) -> list[str]:
    return [line for line in clean(log).splitlines() if line and not SIM_LINE.match(line)]


def verdict_of(log: str) -> str:
    text = clean(log)
    if "HIT GOOD TRAP" in text:
        return "GOOD"
    if "HIT BAD TRAP" in text:
        return "BAD"
    return "NONE"


def parse_plan(path: Path) -> dict:
    guest = None
    reserved = "0x9fff0000"
    enabled = True
    points: list[tuple[str, int]] = []
    for raw in path.read_text().splitlines():
        stripped = raw.strip()
        if not stripped:
            continue
        if stripped.startswith("#"):
            key, _, value = stripped[1:].strip().partition(":")
            key, value = key.strip(), value.strip()
            if key == "guest":
                guest = value
            elif key == "reserved":
                reserved = value
            elif key == "enabled":
                enabled = value.lower() not in ("false", "0", "no", "off")
            continue
        line = stripped.split("#", 1)[0].strip()
        if not line:
            continue
        fields = line.split()
        if len(fields) == 1:
            label, count = f"point{len(points):03d}", fields[0]
        else:
            label, count = fields[0], fields[1]
        points.append((label, int(count, 0)))

    if guest is None:
        raise Failure(f"{path}: no '# guest:' line")
    if not points:
        raise Failure(f"{path}: no points")

    guest_path = Path(guest)
    if not guest_path.is_absolute():
        guest_path = (path.parent / guest_path).resolve()
    return {
        "name": path.stem,
        "path": path.resolve(),
        "guest": guest_path,
        "reserved": reserved,
        "points": points,
        "enabled": enabled,
    }


def free_port() -> int:
    with socket.socket() as probe:
        probe.bind(("127.0.0.1", 0))
        return probe.getsockname()[1]


def run(cmd: list[str], log_path: Path, timeout: int, cwd: Path | None = None) -> subprocess.CompletedProcess:
    with log_path.open("wb") as log:
        return subprocess.run(
            cmd, stdout=log, stderr=subprocess.STDOUT, timeout=timeout, cwd=cwd, check=False
        )


def phase_prep(plan: dict, args) -> None:
    out = args.artifacts / plan["name"]
    out.mkdir(parents=True, exist_ok=True)
    manifest = out / "manifest.json"
    port = free_port()
    log_path = out / "prep.log"

    with log_path.open("wb") as log:
        # -k keeps the spike reference detached: stepping from the debug server
        # leaves the machine paused for milliseconds at a time, and NEMU's
        # host-time driven timer then raises interrupts the reference model
        # never sees. Detaching also makes the boot itself much faster.
        nemu = subprocess.Popen(
            [
                str(args.nemu), "--dbg-port", str(port), "--diff", str(args.ref), "-k",
                str(plan["guest"]),
            ],
            stdout=log,
            stderr=subprocess.STDOUT,
            cwd=str(args.nemu.parent.parent),
        )
    try:
        # NEMU blocks in accept() until the client shows up, so there is no race
        # to lose here; the retry only covers a slow process start.
        for attempt in range(20):
            done = subprocess.run(
                [
                    sys.executable, str(args.ckpt_gen),
                    "--port", str(port),
                    "--points", str(plan["path"].resolve()),
                    "--out-dir", str(out),
                    "--manifest", str(manifest),
                ],
                cwd=str(args.ckpt_gen.parent),
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True,
                check=False,
            )
            if done.returncode == 0:
                break
            if "Connection refused" not in done.stdout and "ConnectionRefusedError" not in done.stdout:
                raise Failure(f"ckpt_gen failed for {plan['name']}:\n{done.stdout}")
            import time as _time

            _time.sleep(0.5)
        else:
            raise Failure(f"ckpt_gen never connected for {plan['name']}")
    finally:
        nemu.terminate()
        try:
            nemu.wait(timeout=10)
        except subprocess.TimeoutExpired:
            nemu.kill()

    if not (out / "manifest.tsv").exists():
        raise Failure(f"{plan['name']}: no manifest.tsv produced")


def phase_pack(plan: dict, args) -> list[dict]:
    out = args.artifacts / plan["name"]
    cases = args.artifacts / "cases" / plan["name"]
    if cases.exists():
        shutil.rmtree(cases)
    cmd = [
        str(args.pack),
        "--manifest", str(out / "manifest.tsv"),
        "--out-dir", str(cases),
        "--restore-blob", str(args.restorer),
        "--reserve-check", f"{plan['reserved']}:0x1000",
        "--report",
    ]
    done = run(cmd, out / "pack.log", timeout=600)
    if done.returncode != 0:
        raise Failure(f"pack failed for {plan['name']}, see {out / 'pack.log'}")

    metas = []
    for meta_path in sorted(cases.glob("*.json")):
        metas.append(json.loads(meta_path.read_text()) | {"meta_path": meta_path})
    if not metas:
        raise Failure(f"{plan['name']}: pack produced no cases")
    return metas


def phase_run(plan: dict, metas: list[dict], args) -> list[dict]:
    out = args.artifacts / plan["name"] / "run"
    out.mkdir(parents=True, exist_ok=True)
    results = []
    for meta in metas:
        label = f"{meta['index']:03d}-{meta['label']}"
        image = meta["image"]
        nemu_log = out / f"{label}.nemu.log"
        dut_log = out / f"{label}.dut.log"

        # -k again: the reference only has to produce the guest's own output,
        # and locking it to spike would abort the run on the same spurious
        # host-timer interrupt the prep phase hits.
        run([str(args.nemu), "--batch", "--diff", str(args.ref), "-k", image], nemu_log, args.timeout)
        run([str(args.sim), "--batch", "--image", image], dut_log, args.timeout)

        nemu_text = nemu_log.read_text(errors="replace")
        dut_text = dut_log.read_text(errors="replace")
        nemu_count = NEMU_INSTRUCTIONS.search(clean(nemu_text))
        dut_count = DUT_COMMITS.search(clean(dut_text))
        results.append(
            {
                "case": label,
                "label": meta["label"],
                "snap_inst": meta["snap_inst"],
                "window_inst": meta["window_inst"],
                "nemu_verdict": verdict_of(nemu_text),
                "dut_verdict": verdict_of(dut_text),
                "nemu_inst": int(nemu_count.group(1).replace(",", "")) if nemu_count else None,
                "dut_inst": int(dut_count.group(1)) if dut_count else None,
                "uart_match": guest_output(nemu_text) == guest_output(dut_text),
            }
        )
    return results


def main() -> int:
    ap = argparse.ArgumentParser(description="Run the dissue checkpoint suite")
    ap.add_argument("--plans", default="plans", help="directory of plan files")
    ap.add_argument("--artifacts", default="/dev/shm/dissue-checkpoint")
    ap.add_argument("--nemu", required=True)
    ap.add_argument("--ref", required=True, help="difftest reference NEMU is built against")
    ap.add_argument("--ckpt-gen", required=True)
    ap.add_argument("--pack", required=True)
    ap.add_argument("--restorer", required=True)
    ap.add_argument("--sim", required=True, help="the dissue simulator")
    ap.add_argument("--timeout", type=int, default=600, help="seconds per simulator run")
    ap.add_argument("--skip-prep", action="store_true")
    ap.add_argument("--skip-run", action="store_true")
    args = ap.parse_args()

    args.artifacts = Path(args.artifacts)
    args.nemu = Path(args.nemu).resolve()
    args.ref = Path(args.ref).resolve()
    args.ckpt_gen = Path(args.ckpt_gen).resolve()
    args.pack = Path(args.pack).resolve()
    args.restorer = Path(args.restorer).resolve()
    args.sim = Path(args.sim).resolve()
    args.artifacts.mkdir(parents=True, exist_ok=True)

    plans = [parse_plan(p) for p in sorted(Path(args.plans).glob("*.txt"))]
    if not plans:
        print(f"no plans under {args.plans}", file=sys.stderr)
        return 1

    rows: list[dict] = []
    failed = 0
    for plan in plans:
        if not plan["enabled"]:
            print(f"== {plan['name']}: skipped (disabled in the plan)")
            continue
        print(f"== {plan['name']}: guest {plan['guest'].name}, {len(plan['points'])} points")
        try:
            if not args.skip_prep:
                phase_prep(plan, args)
            metas = phase_pack(plan, args)
            if not args.skip_run:
                for row in phase_run(plan, metas, args):
                    row["plan"] = plan["name"]
                    rows.append(row)
        except (Failure, subprocess.TimeoutExpired) as exc:
            print(f"   FAILED: {exc}", file=sys.stderr)
            failed += 1

    if rows:
        print()
        print(f"{'plan':<16} {'case':<14} {'inst':>6} {'win':>6} {'verdict':<8} "
              f"{'nemu':>7} {'dut':>7} {'d':>3} {'uart':<5} result")
        result_path = args.artifacts / "result.txt"
        with result_path.open("w") as out:
            for row in rows:
                nemu_inst, dut_inst = row["nemu_inst"], row["dut_inst"]
                # dissue commits one instruction more than NEMU executes: its
                # harness notices the halt one commit after the ebreak.
                # Everything before that matches instruction for instruction
                # (checked by diffing the two itraces), so 0 or +1 both pass.
                counts_ok = nemu_inst is not None and dut_inst in (nemu_inst, nemu_inst + 1)
                ok = (
                    row["nemu_verdict"] == "GOOD"
                    and row["dut_verdict"] == "GOOD"
                    and counts_ok
                    and row["uart_match"]
                )
                failed += 0 if ok else 1
                delta = "?" if None in (nemu_inst, dut_inst) else f"{dut_inst - nemu_inst:+d}"
                line = (
                    f"{row['plan']:<16} {row['case']:<14} {row['snap_inst']:>6} "
                    f"{row['window_inst']:>6} {row['dut_verdict']:<8} "
                    f"{nemu_inst or 0:>7} {dut_inst or 0:>7} {delta:>3} "
                    f"{'==' if row['uart_match'] else '!=':<5} {'PASS' if ok else 'FAIL'}"
                )
                print(line)
                out.write(line + "\n")
        print(f"\nreport: {result_path}")

    print(f"\n{len(rows)} case(s), {failed} failure(s)")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
