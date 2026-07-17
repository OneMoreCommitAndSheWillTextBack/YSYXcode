//! Correctness checking and execution observability.

mod detailed_trace;
mod difftest;
mod event;
mod itrace;
mod perf;
mod report;
mod statistics;

use crate::{
    common::CpuContext,
    config::CheckerConfig,
    machine::{Machine, MachineError},
};
use detailed_trace::{CycleSample, DetailedTrace};
use difftest::{DiffTest, DifftestError};
use event::AsyncInterrupt;
use itrace::Itrace;
use perf::{Perf, PerfCounters};
use statistics::Statistics;
use std::{fmt, io, mem, path::PathBuf};

const DIFFTEST_SYNC_CHUNK_SIZE: usize = 1024 * 1024;

pub(crate) use event::CommitGroup;

/// Error raised by checking, tracing, or retirement validation.
#[derive(Debug)]
pub(crate) enum CheckerError {
    Machine(MachineError),
    Difftest(DifftestError),
    ItraceIo {
        path: PathBuf,
        source: io::Error,
    },
    DetailedTraceIo {
        path: PathBuf,
        source: io::Error,
    },
    ContextUnavailable,
    MultipleAsyncInterrupts {
        count: usize,
        total_commits: u64,
    },
    NonTerminalAsyncInterrupt {
        cause: u32,
        epc: u32,
        commits_at_interrupt: u64,
        total_commits: u64,
    },
}

impl fmt::Display for CheckerError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Machine(error) => write!(formatter, "machine error while checking: {error}"),
            Self::Difftest(error) => write!(formatter, "difftest error: {error}"),
            Self::ItraceIo { path, source } => {
                write!(formatter, "failed to write itrace `{}`: {source}", path.display())
            }
            Self::DetailedTraceIo { path, source } => write!(
                formatter,
                "failed to write detailed trace `{}`: {source}",
                path.display()
            ),
            Self::ContextUnavailable => write!(formatter, "DUT context is unavailable"),
            Self::MultipleAsyncInterrupts {
                count,
                total_commits,
            } => write!(
                formatter,
                "{count} asynchronous interrupts were attached to {total_commits} committed instructions"
            ),
            Self::NonTerminalAsyncInterrupt {
                cause,
                epc,
                commits_at_interrupt,
                total_commits,
            } => write!(
                formatter,
                "interrupt 0x{cause:08x} at EPC 0x{epc:08x} occurred after {commits_at_interrupt} of {total_commits} committed instructions"
            ),
        }
    }
}

impl std::error::Error for CheckerError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Machine(error) => Some(error),
            Self::Difftest(error) => Some(error),
            Self::ItraceIo { source, .. } | Self::DetailedTraceIo { source, .. } => Some(source),
            Self::ContextUnavailable
            | Self::MultipleAsyncInterrupts { .. }
            | Self::NonTerminalAsyncInterrupt { .. } => None,
        }
    }
}

impl From<MachineError> for CheckerError {
    fn from(value: MachineError) -> Self {
        Self::Machine(value)
    }
}

impl From<DifftestError> for CheckerError {
    fn from(value: DifftestError) -> Self {
        Self::Difftest(value)
    }
}

/// Terminal state inferred from a completed retire batch.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) enum CheckerOutcome {
    Continue,
    End,
    Abort,
}

#[derive(Debug, Clone, Copy)]
struct PendingAsyncInterrupt {
    event: AsyncInterrupt,
    commits_at_interrupt: u64,
}

/// Retire state accumulated only until the current driver step completes.
#[derive(Default)]
struct PendingRetireBatch {
    commit_count: u64,
    finish: bool,
    sync_prefix: Option<u64>,
    async_interrupts: Vec<PendingAsyncInterrupt>,
    commit_groups: Vec<CommitGroup>,
}

impl PendingRetireBatch {
    fn clear(&mut self) {
        self.commit_count = 0;
        self.finish = false;
        self.sync_prefix = None;
        self.async_interrupts.clear();
        self.commit_groups.clear();
    }

    fn record(&mut self, group: CommitGroup, sync_prefix: Option<u64>) {
        let previous_commit_count = self.commit_count;
        self.commit_count += group.valid_count();
        self.finish |= group.has_finish();

        if let Some(event) = group.async_interrupt() {
            self.async_interrupts.push(PendingAsyncInterrupt {
                event,
                commits_at_interrupt: self.commit_count,
            });
        }

        if self.sync_prefix.is_none() {
            self.sync_prefix = sync_prefix.map(|count| previous_commit_count + count);
        }

        self.commit_groups.push(group);
    }
}

/// All checking state for one simulation session.
pub(crate) struct Checker {
    difftest: DiffTest,
    itrace: Option<Itrace>,
    detailed_trace: Option<DetailedTrace>,
    perf: Perf,
    statistics: Statistics,
    latest_context: Option<CpuContext>,
    pending_retire: PendingRetireBatch,
    cycle_sample: CycleSample,
}

impl Checker {
    pub(crate) fn new(config: &CheckerConfig) -> Result<Self, CheckerError> {
        let difftest = DiffTest::new(config.difftest_ref.clone(), config.difftest_port)?;
        let itrace = match config.itrace_path.as_ref() {
            Some(path) => Some(
                Itrace::create(path).map_err(|source| CheckerError::ItraceIo {
                    path: path.clone(),
                    source,
                })?,
            ),
            None => None,
        };
        let detailed_trace = match config.detailed_trace_path.as_ref() {
            Some(path) => Some(DetailedTrace::create(path).map_err(|source| {
                CheckerError::DetailedTraceIo {
                    path: path.clone(),
                    source,
                }
            })?),
            None => None,
        };

        Ok(Self {
            difftest,
            itrace,
            detailed_trace,
            perf: Perf::new(),
            statistics: Statistics::new(),
            latest_context: None,
            pending_retire: PendingRetireBatch::default(),
            cycle_sample: CycleSample::default(),
        })
    }

    /// Copies the initial host RAM image into an enabled reference model.
    pub(crate) fn sync_initial_memory(&mut self, machine: &Machine) -> Result<(), CheckerError> {
        if !self.difftest.needs_attach_context() {
            return Ok(());
        }

        let mut buffer = vec![0; DIFFTEST_SYNC_CHUNK_SIZE];
        let mut offset = 0;
        while offset < machine.ram_size() {
            let len = (machine.ram_size() - offset).min(buffer.len());
            let addr = machine.ram_base() + offset as u32;
            machine.read(addr, &mut buffer[..len])?;
            self.difftest.sync_memory(addr, &buffer[..len])?;
            offset += len;
        }
        Ok(())
    }

    /// Clears reset-scoped RTL observations before the driver evaluates reset.
    pub(crate) fn reset_observations(&mut self) {
        self.latest_context = None;
        self.pending_retire.clear();
        self.cycle_sample.clear();
    }

    /// Attaches the reference after reset supplied the first valid DUT context.
    pub(crate) fn attach_after_reset(&mut self) -> Result<(), CheckerError> {
        if self.difftest.needs_attach_context() {
            let context = self.context()?;
            self.difftest.attach(&context)?;
        }
        Ok(())
    }

    pub(crate) fn on_context(&mut self, context: CpuContext) {
        if context.is_valid() {
            self.latest_context = Some(context);
        }
    }

    pub(crate) fn on_commit(&mut self, machine: &Machine, group: CommitGroup) {
        if group.valid_count() == 0 {
            return;
        }

        let sync_prefix =
            group.difftest_sync_prefix_count(|addr, len| machine.contains_ram_range(addr, len));
        self.pending_retire.record(group, sync_prefix);
    }

    pub(crate) fn on_frontend_perf(&mut self, events: u32) {
        self.perf.frontend_perf(events);
        if self.detailed_trace.is_some() {
            self.cycle_sample.record_frontend(events);
        }
    }

    pub(crate) fn on_issue_queue_perf(
        &mut self,
        issue_count: u8,
        occupancy: u8,
        block_ready: bool,
        block_operand: bool,
    ) {
        self.perf
            .issue_queue_perf(issue_count, occupancy, block_ready, block_operand);
        if self.detailed_trace.is_some() {
            self.cycle_sample.record_issue_queue(
                issue_count,
                occupancy,
                block_ready,
                block_operand,
            );
        }
    }

    pub(crate) fn on_div_perf(&mut self, cycles: u32, special: bool) {
        self.perf.div_perf(cycles, special);
        if self.detailed_trace.is_some() {
            self.cycle_sample.record_div_completion(cycles, special);
        }
    }

    pub(crate) fn on_bpu_prediction(&mut self, correct: bool) {
        self.perf.bpu_prediction(correct);
        if self.detailed_trace.is_some() {
            self.cycle_sample.record_bpu_prediction(correct);
        }
    }

    pub(crate) fn on_memory_perf(
        &mut self,
        events: u32,
        mshr_occupancy: u32,
        store_queue_occupancy: u32,
        load_txn_occupancy: u32,
    ) {
        self.perf.mem_perf(
            events,
            mshr_occupancy,
            store_queue_occupancy,
            load_txn_occupancy,
        );
        if self.detailed_trace.is_some() {
            self.cycle_sample.record_memory(
                events,
                mshr_occupancy,
                store_queue_occupancy,
                load_txn_occupancy,
            );
        }
    }

    /// Completes checking for callbacks emitted by the most recent driver step.
    pub(crate) fn finish_step(
        &mut self,
        machine: &Machine,
    ) -> Result<CheckerOutcome, CheckerError> {
        let pending = mem::take(&mut self.pending_retire);
        if let Some(detailed_trace) = self.detailed_trace.as_mut() {
            let path = detailed_trace.path().to_path_buf();
            let sample = mem::take(&mut self.cycle_sample);
            detailed_trace
                .write_cycle(
                    self.statistics.cycle() + 1,
                    pending.commit_count,
                    &pending.commit_groups,
                    &sample,
                )
                .map_err(|source| CheckerError::DetailedTraceIo { path, source })?;
        }

        if pending.commit_count == 0 {
            return Ok(CheckerOutcome::Continue);
        }

        let interrupt = terminal_async_interrupt(&pending.async_interrupts, pending.commit_count)
            .map_err(|error| {
            report::print_difftest_report(&error);
            error
        })?;

        self.statistics.on_commits(pending.commit_count);
        if let Some(itrace) = self.itrace.as_mut() {
            let path = itrace.path().to_path_buf();
            for group in &pending.commit_groups {
                itrace
                    .write_commit_group(group)
                    .map_err(|source| CheckerError::ItraceIo {
                        path: path.clone(),
                        source,
                    })?;
            }
        }

        let store_conditional_gpr_mask = pending
            .commit_groups
            .iter()
            .fold(0, |mask, group| mask | group.store_conditional_gpr_mask());
        let has_store_conditional = store_conditional_gpr_mask != 0;

        if self.difftest.needs_check_context() {
            let context = self.context()?;
            let check_result = if let Some(prefix) = pending.sync_prefix {
                self.difftest.step_and_sync(prefix, &context)
            } else if has_store_conditional {
                match interrupt {
                    Some(interrupt) => self
                        .difftest
                        .step_raise_interrupt_and_check_except_gprs_and_sync(
                            pending.commit_count,
                            interrupt.cause(),
                            interrupt.epc(),
                            &context,
                            store_conditional_gpr_mask,
                        ),
                    None => self.difftest.step_and_check_except_gprs_and_sync(
                        pending.commit_count,
                        &context,
                        store_conditional_gpr_mask,
                    ),
                }
            } else if let Some(interrupt) = interrupt {
                self.difftest.step_raise_interrupt_and_check(
                    pending.commit_count,
                    interrupt.cause(),
                    interrupt.epc(),
                    &context,
                )
            } else {
                self.difftest.step_and_check(pending.commit_count, &context)
            };

            if let Err(error) = check_result {
                let error = CheckerError::Difftest(error);
                report::print_difftest_report(&error);
                return Err(error);
            }

            if has_store_conditional {
                self.sync_store_conditionals(machine, &pending.commit_groups)?;
            }
        }

        if pending.finish {
            return Ok(if self.context()?.gpr[10] == 0 {
                CheckerOutcome::End
            } else {
                CheckerOutcome::Abort
            });
        }

        Ok(CheckerOutcome::Continue)
    }

    /// Advances per-cycle statistics after a completed driver evaluation.
    pub(crate) fn on_cycle(&mut self) {
        self.statistics.on_cycle();
    }

    pub(crate) fn exceeds_no_commit_limit(&self, limit: u32) -> bool {
        self.statistics.exceeds_no_commit_limit(limit)
    }

    pub(crate) fn cycle(&self) -> u64 {
        self.statistics.cycle()
    }

    pub(crate) fn context(&self) -> Result<CpuContext, CheckerError> {
        self.latest_context.ok_or(CheckerError::ContextUnavailable)
    }

    pub(crate) fn print_report(&mut self) {
        crate::Log!("Icache hit rate: {}", self.perf.icache_hit_rate());
        crate::Log!(
            "Icache: requests: {}, hit: {}, miss: {}, miss wait cycles: {}",
            self.perf.frontend_event(PerfCounters::ICACHE_REQUEST),
            self.perf.frontend_event(PerfCounters::ICACHE_HIT),
            self.perf.frontend_event(PerfCounters::ICACHE_MISS),
            self.perf
                .frontend_event(PerfCounters::ICACHE_MISS_WAIT_CYCLE)
        );
        crate::Log!(
            "Frontend: redirects: {}, invalidates: {}, empty while backend ready: {}, AXI request wait cycles: {}",
            self.perf.frontend_event(PerfCounters::BACKEND_REDIRECT),
            self.perf.frontend_event(PerfCounters::ICACHE_INVALIDATE),
            self.perf.frontend_event(PerfCounters::FRONTEND_EMPTY),
            self.perf.frontend_event(PerfCounters::AXI_REQUEST_WAIT)
        );
        crate::Log!(
            "cycles: {}, total commits: {}, ipc: {:.3}",
            self.statistics.cycle(),
            self.statistics.total_commits(),
            PerfCounters::calc_dpi(self.statistics.total_commits(), self.statistics.cycle())
        );
        crate::Log!(
            "IssueQueue: samples: {}, issue count: {}, issue/cycle: {:.3}, dual issue cycles: {}",
            self.perf.issue_queue_sample_cycles(),
            self.perf.issue_queue_issue_count(),
            self.perf.issue_queue_issue_rate(),
            self.perf.issue_queue_dual_issue_cycles()
        );
        crate::Log!(
            "IssueQueue: block ready cycles: {}, block operand cycles: {}, avg occupancy: {:.3}",
            self.perf.issue_queue_block_ready_cycles(),
            self.perf.issue_queue_block_operand_cycles(),
            self.perf.issue_queue_average_occupancy()
        );
        crate::Log!(
            "DIV: operations: {}, cycles: {}, avg cycles/op: {:.3}, special operations: {}",
            self.perf.div_operations(),
            self.perf.div_cycles(),
            self.perf.div_average_cycles(),
            self.perf.div_special_operations()
        );
        crate::Log!(
            "BPU: predictions: {}, correct: {}, accuracy: {:.2}%",
            self.perf.bpu_predictions(),
            self.perf.bpu_correct_predictions(),
            self.perf.bpu_accuracy() * 100.0
        );
        crate::Log!(
            "DCache: access: {}, hit: {}, miss: {}, bypass: {}, hit rate: {:.2}%",
            self.perf.mem_event(PerfCounters::DCACHE_ACCESS),
            self.perf.mem_event(PerfCounters::DCACHE_HIT),
            self.perf.mem_event(PerfCounters::DCACHE_MISS),
            self.perf.mem_event(PerfCounters::DCACHE_BYPASS),
            self.perf.dcache_hit_rate() * 100.0
        );
        crate::Log!(
            "DCache: MSHR alloc: {}, merge: {}, full stall cycles: {}, hit-under-miss: {}, queued miss: {}, avg occupancy: {:.3}",
            self.perf.mem_event(PerfCounters::MSHR_ALLOC),
            self.perf.mem_event(PerfCounters::MSHR_MERGE),
            self.perf.mem_event(PerfCounters::MSHR_FULL_STALL_CYCLE),
            self.perf.mem_event(PerfCounters::HIT_UNDER_MISS),
            self.perf.mem_event(PerfCounters::QUEUED_MISS),
            self.perf.average_mshr_occupancy()
        );
        crate::Log!(
            "DCache: refill start: {}, complete: {}, fault: {}",
            self.perf.mem_event(PerfCounters::REFILL_START),
            self.perf.mem_event(PerfCounters::REFILL_COMPLETE),
            self.perf.mem_event(PerfCounters::REFILL_FAULT)
        );
        crate::Log!(
            "StoreQueue: alloc: {}, full stall cycles: {}, drain: {}, avg occupancy: {:.3}",
            self.perf.mem_event(PerfCounters::STORE_QUEUE_ALLOC),
            self.perf
                .mem_event(PerfCounters::STORE_QUEUE_FULL_STALL_CYCLE),
            self.perf.mem_event(PerfCounters::STORE_DRAIN),
            self.perf.average_store_queue_occupancy()
        );
        crate::Log!(
            "Store forwarding: full: {}, partial: {}, unresolved-store stall cycles: {}, LoadTxn full stall cycles: {}, avg occupancy: {:.3}",
            self.perf.mem_event(PerfCounters::FORWARD_FULL),
            self.perf.mem_event(PerfCounters::FORWARD_PARTIAL),
            self.perf.mem_event(PerfCounters::FORWARD_UNRESOLVED_STALL_CYCLE),
            self.perf.mem_event(PerfCounters::LOAD_TXN_FULL_STALL_CYCLE),
            self.perf.average_load_txn_occupancy()
        );
    }

    fn sync_store_conditionals(
        &mut self,
        machine: &Machine,
        groups: &[CommitGroup],
    ) -> Result<(), CheckerError> {
        for group in groups {
            for (addr, len) in group.store_conditional_memory_regions() {
                if !machine.contains_ram_range(addr, len) {
                    continue;
                }
                let mut data = [0; 4];
                machine.read(addr, &mut data[..len])?;
                self.difftest.sync_memory(addr, &data[..len])?;
            }
        }
        Ok(())
    }
}

fn terminal_async_interrupt(
    interrupts: &[PendingAsyncInterrupt],
    total_commits: u64,
) -> Result<Option<AsyncInterrupt>, CheckerError> {
    let [interrupt] = interrupts else {
        return if interrupts.is_empty() {
            Ok(None)
        } else {
            Err(CheckerError::MultipleAsyncInterrupts {
                count: interrupts.len(),
                total_commits,
            })
        };
    };

    if interrupt.commits_at_interrupt != total_commits {
        return Err(CheckerError::NonTerminalAsyncInterrupt {
            cause: interrupt.event.cause(),
            epc: interrupt.event.epc(),
            commits_at_interrupt: interrupt.commits_at_interrupt,
            total_commits,
        });
    }
    Ok(Some(interrupt.event))
}
