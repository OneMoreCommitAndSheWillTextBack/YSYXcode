# Frontend vNext Implementation Record

This file records the evidence captured at each independently buildable refactor phase. The architectural requirements
remain in `doc/frontend-vnext-refactor-prompt.md`.

## Phase 0: baseline and observation semantics

Baseline date: 2026-08-10 (Asia/Shanghai)

Baseline revision: `f71b3963` (`dissue: refactor LSU and store subsystem, add trace infrastructure`)

Initial worktree state:

- `playground/src/core/frontend/IFetch.scala` contained an unfinished user edit that duplicated the local `req` wire.
- sibling submodules `../yosys-sta` and `../ysyxSoC` were already dirty and were left untouched.
- the first `mill -i playground.compile` failed at `IFetch.scala:559` with `req is already defined as value req`.
- the duplicate block was removed while retaining and completing the user's response-queue FIXME. No functional logic
  changed.

### Baseline commands and results

```text
mill -i playground.compile
  SUCCESS

./build/verilator-exec --batch --difftest-ref nemu --image <test image>
  asm-branch:                       PASS, 31 commits / 157 cycles, IPC 0.197
  branch-icache-retention:          PASS, 529 / 872, IPC 0.607
  ittage-alternating-indirect:      PASS, 1012 / 1303, IPC 0.777
  icache-mshr-redirect-cancel:      PASS, 27 / 188, IPC 0.144
  rvc-crossblock-redirect-fence:    PASS, 53 / 398, IPC 0.133
  fence-i-self-modify:              PASS, 36 / 357, IPC 0.101
  am-prime:                         PASS, 289545 / 296284, IPC 0.977
  am-matrix-mul:                    PASS, 58432 / 54207, IPC 1.078
```

The existing 2026-08-07 regression manifests contain 123 passing tests: 70 RV32I, 15 RV32IM, and 38 RV32IMA.
`run/ipc-log/profile-202608071546.txt` reports weighted headline IPC 0.936276 over 30 long samples. These historical
manifests are retained as broad baseline evidence; the tests listed above were rerun against the current simulator.

### Performance anchors

| test | ICache hit | BPU accuracy | FQ starvation | stale drops | late overrides |
| --- | ---: | ---: | ---: | ---: | ---: |
| `am-prime` | 99.92% | 97.30% | 84,793 | 84,026 | 3,580 |
| `am-matrix-mul` | 99.79% | 81.29% | 8,232 | 13,157 | 3,441 |
| `ittage-alternating-indirect` | 86.38% | 97.15% | 183 | 200 | 42 |
| `branch-icache-retention` | 49.15% | 98.08% | 340 | 3 | 1 |

These counters expose the current design problem: an epoch change makes buffered responses stale on every predicted
redirect, so stale-drop counts can be large even with a high ICache hit rate.

### Existing event semantics and ownership

The current 32-bit `FrontendPerfEvent` ABI is defined in `core/bundle/CoreBundle.scala` and sampled by
`sim/FrontendPerfBridge.scala`. Events 0-16 are assembled in `Frontend.scala` from ICache, IFetch, refill-MMU, redirect,
and FetchQueue boundary signals. Events 17-31 are assembled there from BPU/TAGE/ITTAGE `perf` outputs. Queue occupancy
and accepted enqueue/dequeue widths are sampled every active cycle.

Pipeline visualization events are defined and built in `core/trace/PipelineTrace.scala`. Before Phase 1:

- `IFetch` instantiates `FrontendPipelineTrace` at the FetchQueue enqueue boundary and exposes event payloads in its
  functional IO.
- `Backend` instantiates `BackendPipelineTrace` and exposes event payloads in its functional IO.
- `Core` concatenates those event vectors and instantiates the DPI-facing `PipelineTraceBridge`.
- `Frontend` directly instantiates `FrontendPerfBridge`; `RetireUnit` directly instantiates per-lane `BpuPerfBridge`.

The Phase 1 migration must preserve these handshake semantics while moving observers out of the functional modules.

### Stage plan

1. Move passive trace observers to composition boundaries and add an elaboration-time trace enable without changing
   functional handshakes.
2. Introduce stable FTQ tags, generation, stream epoch, structured recovery, and compatibility adapters.
3. Replace the ICache queued-miss/out-of-order response behavior with a one-group blocking miss path and explicit R0/R1
   replay behavior.
4. Move allocation to BPU S0, implement fixed-latency S1/S3 prediction, and establish FTQ reserve/fetch/commit pointers.
5. Replace `SharedInstAssembler` with align, predecode, checker, and queue pipeline stages.
6. Change backend resolve/retire to tag plus instruction ordinal and make FTQ own training metadata and release counts.
7. Run focused unit tests, full ISA regressions, trace-on/off equivalence, IPC comparison, and an acceptance audit.

## Phase 1: passive trace boundaries

Phase 1 moves the existing observers without changing frontend or backend handshakes:

- `FetchQueue` now lives at the `Frontend` composition boundary, so `IfuTrace` observes accepted enqueue transfers
  without a trace-specific IFetch port.
- IFetch no longer imports trace types or instantiates `FrontendPipelineTrace`.
- Backend exposes a read-only semantic monitor snapshot; `BackendPipelineTrace` and all DPI bridges are instantiated by
  `Core` only when `enableTrace` is true.
- frontend performance ABI construction is owned by `BpuTrace`, `ICacheTrace`, and `FrontendTrace`; DPI remains a host
  adapter in `sim`.
- `Elaborate --disable-trace` removes observers and DPI bridges at elaboration time. The Make build supports the same
  mode with `ELABORATE_ARGS=--disable-trace`, and that value participates in the Chisel build signature.

Structural elaboration results:

```text
trace enabled:  67 SystemVerilog source files
trace disabled: 59 SystemVerilog source files

present only when enabled:
  IfuTrace, FrontendTrace, BpuTrace, ICacheTrace, BackendPipelineTrace,
  PipelineTraceBridge, FrontendPerfBridge, BpuPerfBridge
```

The trace-enabled RTL was rebuilt through Verilator. All eight Phase 0 representatives reached a good trap under NEMU
difftest. Cycles, commits, IPC, and every displayed frontend/predictor/cache counter exactly matched the baseline:

| test | commits | cycles | IPC |
| --- | ---: | ---: | ---: |
| `asm-branch` | 31 | 157 | 0.197 |
| `branch-icache-retention` | 529 | 872 | 0.607 |
| `ittage-alternating-indirect` | 1,012 | 1,303 | 0.777 |
| `icache-mshr-redirect-cancel` | 27 | 188 | 0.144 |
| `rvc-crossblock-redirect-fence` | 53 | 398 | 0.133 |
| `fence-i-self-modify` | 36 | 357 | 0.101 |
| `am-prime` | 289,545 | 296,284 | 0.977 |
| `am-matrix-mul` | 58,432 | 54,207 | 1.078 |

The trace-disabled RTL contains none of the observer or frontend/backend DPI modules and was built through the normal
Make path with `ELABORATE_ARGS=--disable-trace`. Trace-enabled and trace-disabled simulations both passed difftest with
identical cycle/commit totals. Their raw architectural retirement traces compare byte-for-byte equal for:

```text
asm-branch: 31 / 31 retirement records equal
am-prime:   289,545 / 289,545 retirement records equal
```

## Phase 2: stable identity and recovery contracts

Phase 2 adds the new contracts without changing request timing:

- `FrontendConfig` now owns the fetch-group, FTQ generation/sequence/epoch, candidate-count, stage-count, and maximum
  instruction-count derived values. A 16-byte group derives `maxInstsPerFtqEntry=8` and `ftqInstCountBits=4`.
- `FetchTargetTag(index, generation)`, `FetchToken(tag, streamEpoch)`, candidate-indexed `PredictionSummary`, a narrow
  `FtqPredictionView`, `PredictorTrainMeta`, and structured `FrontendRecovery` are defined in one contract file.
- `FrontendRecoveryArbiter` is a stateless helper with fixed backend > IFU > BPU priority.
- named compatibility constructors translate the legacy `PredictionMeta` boundary; new code does not duplicate anonymous
  field-by-field conversions.
- the compatibility FTQ is the sole owner of per-slot generation, sequence, and control-stream epoch. Generation is
  incremented on each reserve and checked on checkpoint lookup, response-queue matching, IFetch response acceptance, and
  FTQ release. A redirect changes the stream epoch without resetting generation history.
- `Core` explicitly passes backend configuration into `Frontend`; the frontend no longer constructs an implicit backend
  configuration to recover width-dependent types.

Focused verification:

```text
mill -i playground.test.runMain top.core.frontend.FrontendContractsSpec
  PASS: max RVC count width, slot generation reuse, stream epoch, recovery priority

mill -i playground.compile
  SUCCESS
```

The rebuilt simulator passed all eight Phase 0 representatives. Every displayed cycle, commit, cache, queue, redirect,
and predictor counter remained equal to baseline. The 31-record branch trace and 289,545-record prime trace remained
byte-identical to their Phase 1 versions.

## Phase 3: strict blocking ICache

Phase 3 replaces the legacy queued-miss/cache-response-reordering path with a token-only blocking cache:

- `ICache` accepts and returns `FetchToken` identity only; `PredictionMeta` is not present in its source or generated
  module. A temporary `LegacyICacheAdapter` owns the metadata queue needed by the Phase 3 IFetch boundary.
- lookup is an explicit registered R0/R1 pipeline with one response register. Warm hits can be accepted and returned at
  one fetch group per cycle after pipeline fill.
- one miss group retains already-hit lanes and refills missing lanes in deterministic increasing lane order. One younger
  R0 request may be retained for replay when the older R1 request discovers a miss.
- recovery cancels an unissued refill immediately. An already accepted bus refill is allowed to complete and warm the
  cache, but its functional response is suppressed. Invalidation generation prevents an older refill from repopulating
  an invalidated line.
- `FetchResponseQueue` was removed. IFetch consumes the strict ordered response directly, and cache trace events are
  reconstructed by the passive `ICacheTrace` observer.

Focused cache verification covers two-block lane-order refill, a same-cycle younger replay, response ordering,
pipelined warm hits, recovery suppression with cache warming, and invalidation-generation rejection:

```text
mill -i playground.test.runMain top.core.frontend.ICacheSpec
  PASS

mill -i playground.test.runMain top.core.frontend.FrontendContractsSpec
mill -i playground.test.runMain top.core.mem.RecoverableDmemQueueSpec
mill -i playground.test.runMain top.core.backend.lsu.LSUDeviceLoadSpec
mill -i playground.test.runMain top.core.backend.lsu.LoadTxnQueueSpec
mill -i playground.test.runMain top.core.backend.lsu.StoreDrainEngineSpec
mill -i playground.test.runMain top.core.backend.lsu.StoreQueueSpec
  PASS
```

Trace-enabled and trace-disabled elaboration both pass. The trace-disabled RTL has the tokenized ICache and adapter but
no frontend observer or DPI modules. The rebuilt trace-enabled simulator reaches a good trap under NEMU difftest on all
eight representatives:

| test | commits | baseline cycles | Phase 3 cycles | baseline IPC | Phase 3 IPC |
| --- | ---: | ---: | ---: | ---: | ---: |
| `asm-branch` | 31 | 157 | 169 | 0.197 | 0.183 |
| `branch-icache-retention` | 529 | 872 | 1,133 | 0.607 | 0.467 |
| `ittage-alternating-indirect` | 1,012 | 1,303 | 1,355 | 0.777 | 0.747 |
| `icache-mshr-redirect-cancel` | 27 | 188 | 196 | 0.144 | 0.138 |
| `rvc-crossblock-redirect-fence` | 53 | 398 | 416 | 0.133 | 0.127 |
| `fence-i-self-modify` | 36 | 357 | 370 | 0.101 | 0.097 |
| `am-prime` | 289,545 | 296,284 | 376,673 | 0.977 | 0.769 |
| `am-matrix-mul` | 58,432 | 54,207 | 61,461 | 1.078 | 0.951 |

### Phase 3 performance attribution

The functional result is correct, but the strict R0/R1 timing exposes a legacy PC-control dependency that must be
removed in Phase 4. The old PC generator advances when a request enters R0, while IFetch turns even a correct fast-taken
prediction into a frontend redirect. That redirect flushes requests which have been accepted but have not yet reached
the registered lookup. Consequently Phase 3 cache requests do not always become hit/miss lookup events, and FetchQueue
starvation rises sharply on branch-dense workloads.

| test | old hit-under-miss | old queued-behind-miss | extra cycles | extra FQ-starvation cycles |
| --- | ---: | ---: | ---: | ---: |
| `am-prime` | 3 | 16 | 80,389 | 80,603 |
| `am-matrix-mul` | 11 | 37 | 7,254 | 8,409 |

The tiny old hit-under-miss counts cannot account for either regression, and miss-wait cycles remain near their baseline
level (`prime`: 328 in Phase 3). No speculative concurrency feature is added to the blocking cache. Phase 4 instead
makes the fast BTB/BHT result drive next-PC selection directly, so a correct fast-taken prediction no longer creates a
recovery flush or discards the registered lookup pipeline. Final IPC acceptance remains open until that ownership change
and the later frontend phases are complete.

## Phase 4: BPU S0-S3 and FTQ lifetime ownership

Phase 4 moves control-flow allocation ahead of the cache and makes the FTQ the sole lifetime owner for each fetch
group:

- `FetchAddressGenerator`, `Bpu`, and FTQ reserve form one atomic S0 join. The direct-mapped BTB/BHT produces an S1
  fast result that immediately selects the next PC, while independent TAGE and ITTAGE queries return a fixed-latency
  S3 final result. The pipeline accepts one request per cycle after fill and explicitly bypasses S1 speculative
  history/path/RAS state to the following S0 request.
- FTQ entries progress through reserved, fast-ready, final-ready, fetch-issued, data-ready, and resident phases. Separate
  write, fetch, and commit pointers enforce allocation, FinalReady-only cache issue, and retirement-based release.
  Every asynchronous write checks index, generation, and, for functional data, stream epoch.
- An S3 override atomically finalizes its anchor, refreshes that entry's data epoch, restores final speculative state,
  and removes only younger entries. Older cache data, completions, emissions, and unbackpressured retire notifications
  remain live across the override.
- The compatibility adapter translates one FTQ group into the Phase 3 legacy IFU metadata format. ICache remains
  token-only and strictly ordered; this adapter is intentionally removed by Phase 5/6 rather than becoming permanent.
- Multi-CFI summary metadata is indexed by block and CFI offset. Dense per-entry instruction ordinals are attached at
  IFU emission, and FTQ release requires `emissionDone && retiredInsts == expectedRetireInsts`.

The FTQ assertions cover capacity, non-reuse of a valid write slot, generation change, stream identity, monotonic
sequence allocation within a stream, FinalReady-only issue, matching recovery anchors, dense emission ordinals, and
`retiredInsts <= expectedRetireInsts <= emittedInsts`. Its public status includes occupancy, full, and empty.

### Phase 4 recovery races found by integration

Waveform-guided prime and RVC debugging exposed three same-cycle ownership cases that are now directed regressions:

1. A younger S3 override can coincide with two retirement lanes for an older entry. Retirement accounting is now
   independent of recovery control updates, so the older entry releases normally.
2. An older cache response can complete on the same cycle as a younger S3 override. The retained completion now advances
   to data-ready instead of leaving a permanently unaccounted entry.
3. A predicted-taken instruction can share the halfword buffer with an already-returned target FTQ entry. The legacy
   assembler now dequeues only the contiguous parcels owned by the taken entry, preserving the target entry's data.

Focused verification:

```text
mill -i playground.test.runMain top.core.frontend.FrontendContractsSpec
mill -i playground.test.runMain top.core.frontend.BpuPipelineSpec
mill -i playground.test.runMain top.core.frontend.FetchTargetQueueSpec
mill -i playground.test.runMain top.core.frontend.ICacheSpec
mill -i playground.test.runMain top.core.frontend.SharedInstAssemblerSpec
  PASS

mill -i playground.compile
  SUCCESS
```

`FetchTargetQueueSpec` covers ring reuse/full backpressure, old-generation and old-stream S3 rejection, multi-CFI
metadata, backend truncation, trap release, simultaneous reserve/finalize/retire, retirement during S3 recovery, cache
completion during S3 recovery, and refreshed-anchor fetch. `BpuPipelineSpec` covers BTB miss, block 0 taken, block 1
taken, both not-taken, no-change S3, conditional direction override, indirect target override, and fixed token latency.
`SharedInstAssemblerSpec` captures the cross-entry predicted-taken buffer case above.

All eight representative binaries reach a good trap under NEMU difftest:

| test | commits | baseline cycles | Phase 4 cycles | baseline IPC | Phase 4 IPC |
| --- | ---: | ---: | ---: | ---: | ---: |
| `asm-branch` | 31 | 157 | 185 | 0.197 | 0.168 |
| `branch-icache-retention` | 529 | 872 | 585 | 0.607 | 0.904 |
| `ittage-alternating-indirect` | 1,012 | 1,303 | 2,118 | 0.777 | 0.478 |
| `icache-mshr-redirect-cancel` | 27 | 188 | 225 | 0.144 | 0.120 |
| `rvc-crossblock-redirect-fence` | 53 | 398 | 445 | 0.133 | 0.119 |
| `fence-i-self-modify` | 36 | 357 | 386 | 0.101 | 0.093 |
| `am-prime` | 289,545 | 296,284 | 244,772 | 0.977 | 1.183 |
| `am-matrix-mul` | 58,432 | 54,207 | 67,347 | 1.078 | 0.868 |

The fast-PC ownership change removes the Phase 3 branch-retention regression and raises prime IPC by 21.1% over the
original baseline. Prime FetchQueue starvation falls from 84,793 to 59,692 cycles, and displayed stale-response drops
fall from 84,026 to 7. Matrix remains 19.5% below baseline: its ICache hit rate falls from 99.79% to 96.63% and
FetchQueue starvation rises from 8,232 to 23,293 cycles. The Phase 4 FinalReady-only issue policy is retained as
specified; Phase 5 first removes the legacy IFU bubbles, and Phase 7 must close the remaining cache-capacity and
headline-IPC acceptance gap with measured A/B changes.

Trace-enabled and trace-disabled simulators have identical cycle and commit totals. Raw architectural retirement traces
compare byte-for-byte for `asm-branch` (31 records) and `am-prime` (289,545 records). The disabled RTL contains no
frontend trace observers or DPI bridges.

## Phase 5: split IFU data path

Phase 5 removes the prediction-aware shared assembler and gives each IFU stage one data-path responsibility:

- `FetchBlockBuffer` buffers strictly ordered `FetchToken + block data + exception` groups and drops a dead head through
  an FTQ token lookup. It contains no prediction metadata or response reordering.
- `InstructionAligner` owns the halfword ring, non-aligned group start, 16/32-bit framing, block/group boundary joins,
  exception merging, and dense per-entry instruction ordinals. A 32-bit instruction spanning two FTQ groups retains the
  low halfword's token and consumes the continuation halfword from the following group.
- A registered align boundary separates the dynamic halfword reads from `PredecodeStage` and `PredictionChecker`.
  Predecode expands RVC and computes structured branch/JAL/JALR, direct-target, call/return, and RAS information without
  reading prediction state.
- `PredictionChecker` reads the final FTQ view, masks lanes after the first taken prediction, exception, or static
  correction, and emits structured correction reasons for false hit, offset/type mismatch, direct-target mismatch, and
  BTB-missed CFI. JAL correction uses the decoded immediate; conditional outcomes and JALR targets remain backend-owned.
- A single `LegacyFetchAdapter` translates the checked result into the existing backend `PredictionMeta` payload. No new
  IFU module uses that legacy type; Phase 6 removes this one compatibility boundary.
- IFU correction waits for the older FetchQueue to drain. Recovery flushes raw younger data while preserving the
  registered correcting packet, and the FTQ keeps its anchor emission-open until that packet is accepted in the next
  cycle. Backend recovery retains its existing already-emitted truncation semantics.

Focused verification:

```text
mill -i playground.test.runMain top.core.frontend.FetchBlockBufferSpec
mill -i playground.test.runMain top.core.frontend.InstructionAlignerSpec
mill -i playground.test.runMain top.core.frontend.PredecodePredictionCheckerSpec
mill -i playground.test.runMain top.core.frontend.FetchTargetQueueSpec
mill -i playground.test.runMain top.core.frontend.FrontendContractsSpec
mill -i playground.test.runMain top.core.frontend.ICacheSpec
mill -i playground.test.runMain top.core.frontend.BpuPipelineSpec
  PASS

mill -i playground.compile
mill -i playground.test.compile
mill -i playground.runMain Elaborate --target-dir /tmp/dissue-phase5-elab
  SUCCESS
```

The directed aligner test covers an unaligned start, a 32-bit block crossing, an exception on the high halfword, and a
32-bit fetch-group crossing with low-halfword token ownership. The checker test covers RVC expansion, branch/JAL/JALR,
call/return/RAS classification, offset/type/direct-target correction, predicted-taken masking, exception masking,
BTB-missed JAL correction, and the absence of static JALR target comparison. The FTQ test holds a correcting packet
across recovery and proves that emission and retirement accounting release the anchor exactly once.

All eight representative binaries reach a good trap under NEMU difftest:

| test | commits | baseline cycles | Phase 4 cycles | Phase 5 cycles | Phase 5 IPC |
| --- | ---: | ---: | ---: | ---: | ---: |
| `asm-branch` | 31 | 157 | 185 | 199 | 0.156 |
| `branch-icache-retention` | 529 | 872 | 585 | 668 | 0.792 |
| `ittage-alternating-indirect` | 1,012 | 1,303 | 2,118 | 3,349 | 0.302 |
| `icache-mshr-redirect-cancel` | 27 | 188 | 225 | 232 | 0.116 |
| `rvc-crossblock-redirect-fence` | 53 | 398 | 445 | 487 | 0.109 |
| `fence-i-self-modify` | 36 | 357 | 386 | 412 | 0.087 |
| `am-prime` | 289,545 | 296,284 | 244,772 | 285,197 | 1.015 |
| `am-matrix-mul` | 58,432 | 54,207 | 67,347 | 78,967 | 0.740 |

Prime remains 3.9% above the original IPC baseline, with a 98.42% ICache hit rate, 179 miss-wait cycles, 96,509 true
FetchQueue-starvation cycles, 11 stale-drop cycles, and 3,621 late overrides. Matrix remains below acceptance at 0.740
IPC, with a 95.24% hit rate, 398 miss-wait cycles, 33,910 starvation cycles, 18 stale drops, and 4,024 late overrides.
The explicit align/predecode register and conservative correction drain explain part of the Phase 4-to-5 latency; the
later capacity/physical optimization phase must use measured A/B changes rather than weakening lifecycle correctness.

Trace-enabled and trace-disabled builds contain 93 and 85 generated source files respectively. The disabled file list
contains none of the eight observer/DPI modules. Both builds pass difftest with identical cycle and commit totals, and
their raw retirement traces compare byte-for-byte:

```text
asm-branch: 31 records, SHA-256 a167b4758f1e0d57e6d1022d76290189b74897eddcc604caf448b595e56a80c5
am-prime:   289,545 records, SHA-256 4d395e4ec5d43d7ef494235528bad543643f038d981f66c7a003b186cd3ac5e2
```

## Phase 6: narrow backend metadata and FTQ-owned training

Phase 6 removes predictor implementation state from every fetched instruction and makes the FTQ the sole bridge from
retired CFI outcomes to predictor training:

- `FrontendPayloadConfig` is shared explicitly by frontend and backend configuration. `FetchInstPayload` now contains
  the instruction, the four execution-validation prediction fields, `FetchTargetTag`, dense FTQ instruction ordinal,
  and fetch exception only.
- execute-stage `BranchResolve` and `CfiRecoveryPayload` return tag plus ordinal and actual CFI information. The FTQ
  resolves a live tag back to its current stream token and checkpoint; trap/barrier recovery remains tokenless.
- retirement returns tag plus ordinal, normal/trap accounting, and the actual CFI outcome. The FTQ validates the tag,
  uniquely selects per-block/per-offset `PredictorTrainMeta`, combines it with the actual outcome into `BpuUpdate`, and
  suppresses stale-generation training.
- predictor table context (`provider`, alternate, late result/target, and history/path checkpoints) lives only in FTQ
  entries. A BTB-missed CFI uses the entry checkpoint fallback while still training BTB/BHT.
- entry release continues to require `emissionDone && retiredInsts == expectedRetireInsts`; no last-instruction bit is
  carried through the backend.
- `LegacyFetchAdapter`, `PredictionMeta`, `PredictorRecovery`, their conversion helpers, and the unused legacy fetch and
  cache bundles were deleted. Structural scans find none of those symbols in source or tests.

New directed coverage proves oldest-mispredict tag/ordinal selection and FTQ training-context lookup, stale-generation
drop, live-tag recovery lookup, and retire-count release:

```text
mill -i playground.test.runMain top.core.backend.BackendCfiContractSpec
mill -i playground.test.runMain top.core.frontend.FtqTrainingSpec
mill -i playground.test.runMain top.core.frontend.FrontendContractsSpec
mill -i playground.test.runMain top.core.frontend.FetchBlockBufferSpec
mill -i playground.test.runMain top.core.frontend.InstructionAlignerSpec
mill -i playground.test.runMain top.core.frontend.PredecodePredictionCheckerSpec
mill -i playground.test.runMain top.core.frontend.FetchTargetQueueSpec
mill -i playground.test.runMain top.core.frontend.ICacheSpec
mill -i playground.test.runMain top.core.frontend.BpuPipelineSpec
  PASS

mill -i playground.compile
mill -i playground.test.compile
mill -i playground.runMain Elaborate --target-dir /tmp/dissue-phase6-contract-elab
  SUCCESS
```

The trace-enabled and trace-disabled simulators both reach a good trap on all eight representatives. Cycle and commit
totals, IPC, cache counters, FTQ counters, and predictor counters are exactly equal to Phase 5:

| test | commits | Phase 5 cycles | Phase 6 cycles | Phase 6 IPC |
| --- | ---: | ---: | ---: | ---: |
| `asm-branch` | 31 | 199 | 199 | 0.156 |
| `branch-icache-retention` | 529 | 668 | 668 | 0.792 |
| `ittage-alternating-indirect` | 1,012 | 3,349 | 3,349 | 0.302 |
| `icache-mshr-redirect-cancel` | 27 | 232 | 232 | 0.116 |
| `rvc-crossblock-redirect-fence` | 53 | 487 | 487 | 0.109 |
| `fence-i-self-modify` | 36 | 412 | 412 | 0.087 |
| `am-prime` | 289,545 | 285,197 | 285,197 | 1.015 |
| `am-matrix-mul` | 58,432 | 78,967 | 78,967 | 0.740 |

The enabled and disabled generated file lists contain 92 and 84 sources respectively, and the disabled list contains
no observer or DPI module. Raw architectural retirement traces remain byte-identical between builds and unchanged from
Phase 5:

```text
asm-branch: 31 records, SHA-256 a167b4758f1e0d57e6d1022d76290189b74897eddcc604caf448b595e56a80c5
am-prime:   289,545 records, SHA-256 4d395e4ec5d43d7ef494235528bad543643f038d981f66c7a003b186cd3ac5e2
```

## Phase 7: cache geometry, predictor storage, and final acceptance

Phase 7 makes cache geometry an elaboration-time choice and removes the predictor tables' asynchronous dynamic reads:

- `--icache-size-bytes`, `--icache-line-bytes`, and `--icache-ways` are parsed by `Elaborate`; all three values are part
  of the Make input signature. `fetchBytes` and `lineBytes` are now independent, and refill data is line-sized while
  each functional response still returns fetch-sized blocks.
- `ICache` supports direct-mapped and two-way organizations with the same strict blocking-miss protocol. The R0/R1 hit
  pipeline, one-group miss ownership, response ordering, token validation, recovery cancellation, and invalidate
  generation rules are unchanged. `ICacheGeometrySpec` covers a 32-byte line shared by both fetch blocks and two-way
  replacement independently of the original cache tests.
- `ICacheTrace` exports semantic lookup, valid-mask, miss-mask, and block-address samples. The host detailed trace keeps
  these as semantic fields, and `scriptpy/icache_shadow.py` replays them through a same-capacity LRU shadow cache.
- TAGE and ITTAGE tagged entries now use `SyncReadMem` tables with a registered read result. Query lanes remain
  independent and the fixed S0-S3 external latency is preserved; table writes use the memories' write ports rather
  than an asynchronous `Reg(Vec)` array.

### Cache A/B and default selection

At one controlled pre-final checkpoint, 8-byte-line direct-mapped 512 B, 1 KiB, and 2 KiB builds produced identical
cycles on both long representatives (`am-prime`: 285,506; `am-matrix-mul`: 80,084). Capacity therefore did not explain
the remaining regression. Semantic traces from the 512 B direct-mapped build were classified against a same-capacity
two-way shadow:

| test | actual line misses | two-way shadow misses | conflict | compulsory | shadow-only |
| --- | ---: | ---: | ---: | ---: | ---: |
| `am-prime` | 31 | 25 | 6 | 25 | 0 |
| `am-matrix-mul` | 66 | 51 | 15 | 51 | 0 |

The conflict component is small compared with total runtime, and a two-way RTL A/B did not provide a material
representative improvement. A final 32-byte-line direct-mapped build reduced `am-prime` by 64 cycles (276,247 to
276,183) and `am-matrix-mul` by 129 cycles (74,536 to 74,407), but `sv32-basic` stopped making progress at 8,316
commits/34,616 cycles while the 8-byte-line build passed at 8,350/16,372. The default therefore remains the robust
512 B, 8-byte-line, direct-mapped geometry. The configurable 32-byte-line path remains experimental rather than being
selected on the strength of two small benchmark gains.

### Static checker correction found by profiling

Detailed tracing showed repeated IFU recoveries when an unpredicted conditional appeared before a later predicted JAL
in the same block. The checker had interpreted the earlier branch's offset as a mismatch against the later CFI. The
static correction rule now treats an unpredicted conditional as the normal not-taken fallback and applies an immediate
offset/BTB-miss correction only to JAL, whose target is statically known. A directed multi-CFI test locks this behavior.

This removed the recovery loop without manufacturing conditional outcomes in the IFU. `sv32-basic` changed from 29,223
to 16,372 cycles, and `am-matrix-mul` changed from 80,084 to 74,536 cycles at the controlled checkpoints. A direct
passive `IFU corrections` trace field was added without renumbering the existing 32-bit event ABI; final samples report
2 corrections for `am-prime`, 10 for `am-matrix-mul`, 5 for `sv32-basic`, and 3 for `asm-branch`.

### Final functional and performance evidence

Focused frontend/backend tests and compilation:

```text
mill -i playground.test.runMain top.core.frontend.FrontendContractsSpec
mill -i playground.test.runMain top.core.frontend.BpuPipelineSpec
mill -i playground.test.runMain top.core.frontend.FetchTargetQueueSpec
mill -i playground.test.runMain top.core.frontend.ICacheSpec
mill -i playground.test.runMain top.core.frontend.ICacheGeometrySpec
mill -i playground.test.runMain top.core.frontend.FetchBlockBufferSpec
mill -i playground.test.runMain top.core.frontend.InstructionAlignerSpec
mill -i playground.test.runMain top.core.frontend.PredecodePredictionCheckerSpec
mill -i playground.test.runMain top.core.frontend.FtqTrainingSpec
mill -i playground.test.runMain top.core.backend.BackendCfiContractSpec
mill -i playground.compile
mill -i playground.test.compile
  PASS
```

The final default simulator passes the complete suite under NEMU difftest with no mismatch:

```text
RV32I:   70 passed, 0 failed
RV32IM:  15 passed, 0 failed
RV32IMA: 40 passed, 0 failed
total:  125 passed, 0 failed
```

`run/ipc-log/profile-202608101505.txt` reports headline IPC 0.942740 over 32 long samples, compared with the recorded
baseline 0.936276 over 30 samples (+0.690%). Restricting the new profile to the baseline's exact 30-test cohort gives
1,222,241 commits / 1,290,889 cycles = 0.946821 IPC (+1.126%), so the acceptance result is not caused by the two added
Sv32 tests.

| test | commits | cycles | IPC |
| --- | ---: | ---: | ---: |
| `asm-branch` | 31 | 186 | 0.166667 |
| `branch-icache-retention` | 529 | 653 | 0.810107 |
| `ittage-alternating-indirect` | 1,012 | 2,263 | 0.447194 |
| `icache-mshr-redirect-cancel` | 27 | 235 | 0.114894 |
| `rvc-crossblock-redirect-fence` | 53 | 472 | 0.112288 |
| `fence-i-self-modify` | 36 | 394 | 0.091371 |
| `am-prime` | 289,545 | 276,247 | 1.048138 |
| `am-matrix-mul` | 58,432 | 74,536 | 0.783943 |
| `sv32-basic` | 8,350 | 16,372 | 0.510017 |

The final passive-observer counters for the two long frontend representatives are:

| test | ICache hit | miss-wait | FQ starvation | avg enq/deq | BPU accuracy | S3 override | IFU correction | stale drop |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `am-prime` | 99.06% | 185 | 83,555 | 1.086 / 1.067 | 97.20% | 2,977 | 2 | 5 |
| `am-matrix-mul` | 97.46% | 428 | 28,652 | 1.067 / 0.925 | 79.69% | 3,815 | 10 | 10 |

Prime's FetchQueue starvation falls from the Phase 0 baseline 84,793 to 83,555 cycles, while its stale-drop count falls
from 84,026 to 5. Correct fast-taken predictions advance the PC through the normal S1 path and do not create recovery.

### Final trace equivalence and physical-evidence boundary

The final trace-enabled and freshly rebuilt trace-disabled file lists contain 94 and 86 sources. None of `IfuTrace`,
`FrontendTrace`, `BpuTrace`, `ICacheTrace`, `BackendPipelineTrace`, `PipelineTraceBridge`, `FrontendPerfBridge`, or
`BpuPerfBridge` appears in the disabled list. Both binaries pass difftest with identical cycle/commit totals, and their
architectural retirement traces compare byte-for-byte:

```text
asm-branch: 31 records, SHA-256 a167b4758f1e0d57e6d1022d76290189b74897eddcc604caf448b595e56a80c5
am-prime:   289,545 records, SHA-256 4d395e4ec5d43d7ef494235528bad543643f038d981f66c7a003b186cd3ac5e2
```

Synthesis and STA were not run, at the user's direction. Consequently this record makes no Fmax, area, or post-synthesis
critical-path claim. The registered align/predecode boundary and synchronous predictor reads remove the original RTL
combination of align, RVC expansion, predictor-table lookup, and recovery selection, but physical timing remains an
explicitly unmeasured acceptance item.
