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
    config::SimulatorConfig,
    cpu::{Cpu, CpuContext, CpuError, CsrContext},
    difftest::{DiffTest, DifftestError},
    memory::{Memory, MemoryError},
    perf::{Perf, PerfCounters},
    sdb::SdbError,
    sim_log,
    simulator::SimulatorState::Running,
    SimulatorResult,
};
use chrono::Local;
use std::{io, path::PathBuf};

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
    pending_commit_count: u64,
    pending_finish: bool,
    pending_difftest_sync: bool,
    pending_difftest_sync_prefix: u64,
    pending_async_interrupts: Vec<PendingAsyncInterrupt>,
    pending_commit_events: Vec<CommitGroupEvent>,
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
            pending_commit_count: 0,
            pending_finish: false,
            pending_difftest_sync: false,
            pending_difftest_sync_prefix: 0,
            pending_async_interrupts: Vec::new(),
            pending_commit_events: Vec::new(),
            pending_memory_error: None,
            timer: None,
        });
        let callbacks = callbacks::build_callbacks();
        simulator.cpu = Some(Cpu::connect(&callbacks)?);
        callbacks::set_active_simulator(&mut *simulator as *mut Self);
        crate::Log!("Init Cpu Successful");

        simulator.memory.register_ram("pmem", MBASE, PMEM_SIZE)?;
        simulator.load_image()?;

        let wave_path = simulator.config.wave_path.as_deref();
        simulator
            .cpu
            .as_mut()
            .ok_or(SimulatorError::CpuNotConnected)?
            .init_wave(wave_path)?;

        simulator.finish_config();
        crate::Log!("Finish Simulator Config");

        Ok(simulator)
    }

    pub fn finish_config(&mut self) {
        if self.config.enable_wave {
            if let Some(cpu) = self.cpu.as_mut() {
                cpu.enable_wave();
            }
        }

        sim_log::show_trace(&self.config);
        let now = Local::now();
        crate::Log!("run simulator at {}", now.format("%a %b %e %T %Y"));
    }

    pub fn reset(&mut self) -> SimulatorResult<()> {
        self.timer = Some(timer::SimTimer::new());
        self.latest_context = None;
        self.pending_commit_count = 0;
        self.pending_finish = false;
        self.pending_difftest_sync = false;
        self.pending_difftest_sync_prefix = 0;
        self.pending_async_interrupts.clear();
        self.pending_commit_events.clear();
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

    fn enable_wave_after_threshold(&mut self) {
        if self.config.enable_wave {
            return;
        }

        let Some(wave_after) = self.config.wave_after else {
            return;
        };

        let cycle = self.statistics.cycle();
        if cycle <= wave_after {
            return;
        }

        if let Some(cpu) = self.cpu.as_mut() {
            cpu.enable_wave();
            self.config.enable_wave = true;
            crate::Log!("enable wave at cycle {}", cycle);
        }
    }

    pub fn execute(&mut self, times: u64) -> SimulatorResult<()> {
        for _ in 0..times {
            match self.state {
                SimulatorState::Running | SimulatorState::Stop => {}
                SimulatorState::End => return Ok(()),
                SimulatorState::Abort => return Err(SimulatorError::SimulateAbort),
            }

            self.enable_wave_after_threshold();

            if self
                .statistics
                .exceeds_no_commit_limit(MAX_NO_COMMIT_CYCLES)
            {
                eprintln!(
                    "{}HIT BAD TRAP, REACH MAX NO COMMIT CYCLES{}",
                    ANSI_FG_RED, ANSI_RESET
                );
                return Err(SimulatorError::ReachMaxNoCommitCyc);
            }

            self.execute_once()?;
            self.statistics.on_cycle();
        }

        Ok(())
    }

    pub fn wave_close(&mut self) {
        if let Some(cpu) = self.cpu.as_mut() {
            cpu.close_wave();
        }
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
