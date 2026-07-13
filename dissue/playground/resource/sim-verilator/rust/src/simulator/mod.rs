mod callbacks;
mod difftest_events;
mod event;
mod itrace;
mod pmem;
mod report;
mod statistics;
mod timer;

use event::AsyncInterruptEvent;
pub use event::CommitGroupEvent;

use itrace::Itrace;
use statistics::Statistics;

use crate::{
    config::{SimulatorConfig, WaveMode},
    cpu::{Cpu, CpuContext, CpuError, CsrContext, WaveConfig as CpuWaveConfig},
    difftest::{DiffTest, DifftestError},
    memory::{Memory, MemoryError},
    perf::{Perf, PerfCounters},
    sdb::SdbError,
    sim_log,
    simulator::SimulatorState::Running,
    SimulatorResult,
};
use chrono::Local;
use std::{fmt, io, path::PathBuf};

const MBASE: u32 = 0x8000_0000;
const PMEM_SIZE: usize = 512 * 1024 * 1024;
const MAX_NO_COMMIT_CYCLES: u32 = 20000;
const ANSI_RESET: &str = "\x1b[0m";
const ANSI_FG_BLUE: &str = "\x1b[34m";
const ANSI_FG_GREEN: &str = "\x1b[32m";
const ANSI_FG_RED: &str = "\x1b[31m";

#[derive(Debug)]
pub enum SimulatorError {
    Memory(MemoryError),
    Sdb(SdbError),
    Cpu(CpuError),
    Difftest(DifftestError),
    ImageIo {
        path: PathBuf,
        source: io::Error,
    },
    ItraceIo {
        path: PathBuf,
        source: io::Error,
    },
    CpuNotConnected,
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
    SimulateAbort,
    ReachMaxNoCommitCyc,
}

impl SimulatorError {
    pub fn display(&self) -> impl fmt::Display + '_ {
        self
    }
}

impl fmt::Display for SimulatorError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Memory(error) => write!(formatter, "memory error: {error}"),
            Self::Sdb(error) => write!(formatter, "SDB error: {error}"),
            Self::Cpu(error) => write!(formatter, "CPU error: {error}"),
            Self::Difftest(error) => write!(formatter, "difftest error: {error}"),
            Self::ImageIo { path, source } => {
                write!(formatter, "failed to read image `{}`: {source}", path.display())
            }
            Self::ItraceIo { path, source } => {
                write!(formatter, "failed to write itrace `{}`: {source}", path.display())
            }
            Self::CpuNotConnected => write!(formatter, "CPU is not connected"),
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
            Self::SimulateAbort => write!(formatter, "simulation aborted"),
            Self::ReachMaxNoCommitCyc => write!(formatter, "maximum no-commit cycle limit reached"),
        }
    }
}

impl std::error::Error for SimulatorError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Memory(error) => Some(error),
            Self::Sdb(error) => Some(error),
            Self::Cpu(error) => Some(error),
            Self::Difftest(error) => Some(error),
            Self::ImageIo { source, .. } | Self::ItraceIo { source, .. } => Some(source),
            Self::CpuNotConnected
            | Self::MultipleAsyncInterrupts { .. }
            | Self::NonTerminalAsyncInterrupt { .. }
            | Self::SimulateAbort
            | Self::ReachMaxNoCommitCyc => None,
        }
    }
}

pub enum SimulatorState {
    Running,
    Stop,
    Abort,
    End,
}

#[derive(Debug, Clone, Copy)]
struct PendingAsyncInterrupt {
    event: AsyncInterruptEvent,
    commits_at_interrupt: u64,
}

#[derive(Default)]
struct PendingDifftestEvents {
    commit_count: u64,
    finish: bool,
    sync_prefix: Option<u64>,
    async_interrupts: Vec<PendingAsyncInterrupt>,
    commit_events: Vec<CommitGroupEvent>,
}

impl From<MemoryError> for SimulatorError {
    fn from(value: MemoryError) -> Self {
        Self::Memory(value)
    }
}

impl From<SdbError> for SimulatorError {
    fn from(value: SdbError) -> Self {
        Self::Sdb(value)
    }
}

impl From<CpuError> for SimulatorError {
    fn from(value: CpuError) -> Self {
        Self::Cpu(value)
    }
}

impl From<DifftestError> for SimulatorError {
    fn from(value: DifftestError) -> Self {
        Self::Difftest(value)
    }
}

pub struct Simulator {
    config: SimulatorConfig,
    memory: Memory,
    cpu: Option<Cpu>,
    perf: Perf,
    difftest: DiffTest,
    state: SimulatorState,
    statistics: Statistics,
    latest_context: Option<CpuContext>,
    itrace: Option<Itrace>,
    pending_difftest_events: PendingDifftestEvents,
    pending_memory_error: Option<MemoryError>,
    timer: Option<timer::SimTimer>,
}

impl Simulator {
    pub fn new(config: SimulatorConfig) -> SimulatorResult<Box<Self>> {
        let difftest_ref = config.difftest_ref.clone();
        let difftest = DiffTest::new(difftest_ref)?;

        let itrace = match config.itrace_path.as_ref() {
            Some(path) => {
                Some(
                    Itrace::create(path).map_err(|source| SimulatorError::ItraceIo {
                        path: path.clone(),
                        source,
                    })?,
                )
            }
            None => None,
        };

        let wave_config = CpuWaveConfig::from(&config.wave_config);
        let mut simulator = Box::new(Self {
            config,
            memory: Memory::new(),
            cpu: None,
            perf: Perf::new(),
            difftest,
            state: Running,
            statistics: Statistics::new(),
            latest_context: None,
            itrace,
            pending_difftest_events: PendingDifftestEvents::default(),
            pending_memory_error: None,
            timer: None,
        });
        let callbacks = callbacks::build_callbacks();
        simulator.cpu = Some(Cpu::connect(&callbacks)?);
        callbacks::set_active_simulator(&mut *simulator as *mut Self);
        crate::Log!("Init Cpu Successful");

        simulator.memory.register_ram("pmem", MBASE, PMEM_SIZE)?;
        simulator.load_image()?;
        simulator.sync_pmem_to_difftest()?;
        crate::Log!("Finish sync the pmem");

        simulator
            .cpu
            .as_mut()
            .ok_or(SimulatorError::CpuNotConnected)?
            .init_wave(wave_config)?;

        simulator.finish_config();
        crate::Log!("Finish Simulator Config");

        Ok(simulator)
    }

    pub fn finish_config(&mut self) {
        if matches!(self.config.wave_config.mode, WaveMode::Immediate) {
            if let Some(cpu) = self.cpu.as_mut() {
                cpu.enable_wave();
            }
        }

        sim_log::show_trace(&self.config);
        let now = Local::now();
        crate::Log!("run simulator at {}", now.format("%a %b %e %T %Y"));
    }

    pub fn reset(&mut self) -> SimulatorResult<()> {
        if !matches!(self.state, SimulatorState::Running) {
            eprintln!(
                "{}PROGRAM IS OVER, PLEASE RESTART{}",
                ANSI_FG_RED, ANSI_RESET
            );
        }

        self.timer = Some(timer::SimTimer::new());
        self.latest_context = None;
        self.pending_difftest_events.clear();
        self.pending_memory_error = None;

        {
            let Some(cpu) = self.cpu.as_mut() else {
                return Err(SimulatorError::CpuNotConnected);
            };

            cpu.reset(self.config.reset_cycles);
        }

        if self.difftest.needs_attach_context() {
            let context = self.cpu_context()?;
            self.difftest.attach(&context)?;
        }

        Ok(())
    }

    fn execute_once(&mut self) -> SimulatorResult<()> {
        let Some(cpu) = self.cpu.as_mut() else {
            return Err(SimulatorError::CpuNotConnected);
        };

        match self.state {
            SimulatorState::Running | SimulatorState::Stop => {}
            SimulatorState::End => return Ok(()),
            SimulatorState::Abort => return Err(SimulatorError::SimulateAbort),
        }

        cpu.step();
        self.perf.on_cycle();
        if let Some(error) = self.pending_memory_error.take() {
            self.state = SimulatorState::Abort;
            return Err(SimulatorError::Memory(error));
        }
        self.process_difftest_events()?;
        Ok(())
    }

    fn update_wave(&mut self) {
        let cycle = self.statistics.cycle();
        if let Some(cpu) = self.cpu.as_mut() {
            cpu.wave_update(cycle);
        }
    }

    pub fn execute(&mut self, times: u64) -> SimulatorResult<()> {
        for _ in 0..times {
            match self.state {
                SimulatorState::Running | SimulatorState::Stop => {}
                SimulatorState::End => return self.terminal(Ok(())),
                SimulatorState::Abort => {
                    return self.terminal(Err(SimulatorError::SimulateAbort));
                }
            }

            match self.execute_once() {
                Ok(()) => {}
                Err(error) => {
                    eprintln!("[Error] {}", error.display());
                }
            }

            self.statistics.on_cycle();

            match self.state {
                SimulatorState::Abort => {
                    eprintln!("{}HIT BAD TRAP{}", ANSI_FG_RED, ANSI_RESET);
                    return self.terminal(Err(SimulatorError::SimulateAbort));
                }
                SimulatorState::End => {
                    eprintln!("{}HIT GOOD TRAP{}", ANSI_FG_GREEN, ANSI_RESET);
                    return self.terminal(Ok(()));
                }
                SimulatorState::Running | SimulatorState::Stop => {
                    if self
                        .statistics
                        .exceeds_no_commit_limit(MAX_NO_COMMIT_CYCLES)
                    {
                        eprintln!(
                            "{}HIT BAD TRAP, REACH MAX NO COMMIT CYCLES{}",
                            ANSI_FG_RED, ANSI_RESET
                        );
                        self.state = SimulatorState::Abort;
                        return self.terminal(Err(SimulatorError::ReachMaxNoCommitCyc));
                    }
                }
            }

            self.update_wave();
        }

        Ok(())
    }

    fn terminal(&mut self, result: SimulatorResult<()>) -> SimulatorResult<()> {
        if let Some(cpu) = self.cpu.as_mut() {
            cpu.terminal();
        }

        result
    }

    pub fn generat_report(&mut self) {
        // icache hit rate
        crate::Log!("Icache hit rate: {}", self.perf.cacherate());

        // ipc
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
    }

    pub fn shutdown(&mut self) {
        self.shutdown_lightsss();
    }

    fn shutdown_lightsss(&mut self) {
        if let Some(cpu) = self.cpu.as_mut() {
            cpu.shutdown_lightsss();
        }
    }

    pub fn cpu_gpr(&mut self) -> SimulatorResult<[u32; 32]> {
        Ok(self.cpu_context()?.gpr)
    }

    pub fn cpu_csr(&mut self) -> SimulatorResult<CsrContext> {
        Ok(self.cpu_context()?.csr)
    }

    pub fn cpu_context(&mut self) -> SimulatorResult<CpuContext> {
        self.latest_context
            .ok_or(SimulatorError::Cpu(CpuError::ContextUnavailable))
    }

    pub fn difftest_attach(&mut self) -> SimulatorResult<()> {
        let context = self.cpu_context()?;
        Ok(self.difftest.attach(&context)?)
    }

    pub fn difftest_detach(&mut self) {
        self.difftest.detach();
    }
}

impl Drop for Simulator {
    fn drop(&mut self) {
        self.cpu.take();
        callbacks::set_active_simulator(std::ptr::null_mut());
    }
}
