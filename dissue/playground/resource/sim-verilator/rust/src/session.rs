//! Simulation lifecycle and the narrow DPI host boundary.

use crate::{
    checker::{Checker, CheckerError, CheckerOutcome, CommitGroup},
    common::CpuContext,
    config::SimulationConfig,
    driver::{DriverError, NpcDriver},
    ffi,
    machine::{Machine, MachineError},
    sim_log,
    wave::WaveController,
};
use chrono::Local;
use std::{ffi::c_void, fmt};

const ANSI_RESET: &str = "\x1b[0m";
const ANSI_FG_GREEN: &str = "\x1b[32m";
const ANSI_FG_RED: &str = "\x1b[31m";

pub(crate) type SimulationResult<T> = Result<T, SimulationError>;

/// Error returned after a complete session operation.
#[derive(Debug)]
pub(crate) enum SimulationError {
    Machine(MachineError),
    Driver(DriverError),
    Checker(CheckerError),
    SimulateAbort,
    ReachMaxNoCommitCycles,
}

impl SimulationError {
    pub(crate) fn display(&self) -> impl fmt::Display + '_ {
        self
    }
}

impl fmt::Display for SimulationError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Machine(error) => write!(formatter, "{error}"),
            Self::Driver(error) => write!(formatter, "driver error: {error}"),
            Self::Checker(error) => write!(formatter, "checker error: {error}"),
            Self::SimulateAbort => write!(formatter, "simulation aborted"),
            Self::ReachMaxNoCommitCycles => {
                write!(formatter, "maximum no-commit cycle limit reached")
            }
        }
    }
}

impl std::error::Error for SimulationError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Machine(error) => Some(error),
            Self::Driver(error) => Some(error),
            Self::Checker(error) => Some(error),
            Self::SimulateAbort | Self::ReachMaxNoCommitCycles => None,
        }
    }
}

impl From<MachineError> for SimulationError {
    fn from(value: MachineError) -> Self {
        Self::Machine(value)
    }
}

impl From<DriverError> for SimulationError {
    fn from(value: DriverError) -> Self {
        Self::Driver(value)
    }
}

impl From<CheckerError> for SimulationError {
    fn from(value: CheckerError) -> Self {
        Self::Checker(value)
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum SessionState {
    Running,
    Abort,
    End,
}

/// Coordinates independent runtime owners without becoming a callback owner.
pub(crate) struct SimulationSession {
    config: SimulationConfig,
    machine: Machine,
    driver: NpcDriver,
    checker: Checker,
    wave: WaveController,
    state: SessionState,
}

impl SimulationSession {
    pub(crate) fn new(config: SimulationConfig) -> SimulationResult<Self> {
        let callbacks = build_dpi_callbacks();
        let mut driver = NpcDriver::new(&callbacks)?;
        driver.init_trace(&config.trace)?;

        let mut machine = Machine::new(config.machine.clone())?;
        let mut checker = Checker::new(&config.checker)?;
        machine.load_image()?;
        checker.sync_initial_memory(&machine)?;
        crate::Log!("Finish sync the pmem");

        let mut wave = WaveController::new(config.trace.mode);
        wave.initialize(&mut driver);
        sim_log::show_trace(&config);
        crate::Log!("run simulator at {}", Local::now().format("%a %b %e %T %Y"));

        Ok(Self {
            config,
            machine,
            driver,
            checker,
            wave,
            state: SessionState::Running,
        })
    }

    pub(crate) fn reset(&mut self) -> SimulationResult<()> {
        if !matches!(self.state, SessionState::Running) {
            eprintln!("{ANSI_FG_RED}PROGRAM IS OVER, PLEASE RESTART{ANSI_RESET}");
        }

        self.machine.reset_time();
        self.checker.reset_observations();
        self.evaluate_reset()?;
        self.checker.attach_after_reset()?;
        Ok(())
    }

    pub(crate) fn execute(&mut self, times: u64) -> SimulationResult<()> {
        for _ in 0..times {
            match self.state {
                SessionState::Running => {}
                SessionState::End => return Ok(()),
                SessionState::Abort => return Err(SimulationError::SimulateAbort),
            }

            if let Err(error) = self.execute_once() {
                eprintln!("[Error] {}", error.display());
                self.state = SessionState::Abort;
            }

            self.checker.on_cycle();
            match self.state {
                SessionState::Abort => {
                    eprintln!("{ANSI_FG_RED}HIT BAD TRAP{ANSI_RESET}");
                    return self.terminal(Err(SimulationError::SimulateAbort));
                }
                SessionState::End => {
                    eprintln!("{ANSI_FG_GREEN}HIT GOOD TRAP{ANSI_RESET}");
                    return self.terminal(Ok(()));
                }
                SessionState::Running => {
                    if self
                        .checker
                        .exceeds_no_commit_limit(self.config.checker.max_no_commit_cycles)
                    {
                        eprintln!(
                            "{ANSI_FG_RED}HIT BAD TRAP, REACH MAX NO COMMIT CYCLES{ANSI_RESET}"
                        );
                        self.state = SessionState::Abort;
                        return self.terminal(Err(SimulationError::ReachMaxNoCommitCycles));
                    }
                }
            }

            self.wave
                .after_cycle(&mut self.driver, self.checker.cycle());
        }
        Ok(())
    }

    pub(crate) fn print_report(&mut self) {
        self.checker.print_report();
    }

    pub(crate) fn shutdown(&mut self) {
        self.wave.shutdown();
        self.driver.close_trace();
    }

    fn evaluate_reset(&mut self) -> SimulationResult<()> {
        let mut status = CallbackStatus::default();
        {
            let mut host = EvalHost::new(&mut self.machine, &mut self.checker, &mut status);
            self.driver
                .reset(host.as_opaque(), self.config.driver.reset_cycles);
        }
        self.finish_callback_status(status)
    }

    fn execute_once(&mut self) -> SimulationResult<()> {
        match self.state {
            SessionState::Running => {}
            SessionState::End => return Ok(()),
            SessionState::Abort => return Err(SimulationError::SimulateAbort),
        }

        let mut status = CallbackStatus::default();
        {
            let mut host = EvalHost::new(&mut self.machine, &mut self.checker, &mut status);
            self.driver.step(host.as_opaque());
        }
        self.finish_callback_status(status)?;

        match self.checker.finish_step(&self.machine)? {
            CheckerOutcome::Continue => {}
            CheckerOutcome::End => self.state = SessionState::End,
            CheckerOutcome::Abort => self.state = SessionState::Abort,
        }
        Ok(())
    }

    /// Some DPI access operations can cause side effects such as memory access panics.
    /// This method preserves a unified exit interface by storing error states in the checker,
    /// which are then consumed when `exec_once` finishes.
    fn finish_callback_status(&self, status: CallbackStatus) -> SimulationResult<()> {
        if let Some(error) = status.machine_error {
            let pc = self.checker.context().ok().map(|context| context.pc);
            self.machine.report_dpi_access_error(&error, pc);
            return Err(error.into());
        }
        Ok(())
    }

    fn terminal(&mut self, result: SimulationResult<()>) -> SimulationResult<()> {
        self.wave.terminal(&mut self.driver);
        result
    }
}

#[derive(Default)]
struct CallbackStatus {
    machine_error: Option<MachineError>,
}

impl CallbackStatus {
    fn record_machine_error(&mut self, error: MachineError) {
        if self.machine_error.is_none() {
            self.machine_error = Some(error);
        }
    }
}

/// The only Rust object reachable from a native DPI callback.
///
/// It is created on the caller's stack, passed through the C ABI only for one
/// `NpcDriver::reset` or `NpcDriver::step` call, and destroyed immediately
/// after that call returns.
struct EvalHost<'a> {
    machine: &'a mut Machine,
    checker: &'a mut Checker,
    status: &'a mut CallbackStatus,
}

impl<'a> EvalHost<'a> {
    fn new(
        machine: &'a mut Machine,
        checker: &'a mut Checker,
        status: &'a mut CallbackStatus,
    ) -> Self {
        Self {
            machine,
            checker,
            status,
        }
    }

    fn as_opaque(&mut self) -> *mut c_void {
        (self as *mut Self).cast()
    }
}

fn build_dpi_callbacks() -> ffi::NpcDpiCallbacks {
    ffi::NpcDpiCallbacks {
        opaque: std::ptr::null_mut(),
        on_difftest_commit: Some(on_difftest_commit),
        on_difftest_context: Some(on_difftest_context),
        pmem_read: Some(pmem_read),
        pmem_write: Some(pmem_write),
        time_read: Some(time_read),
        cache_hit: Some(cache_hit),
        issue_queue_perf: Some(issue_queue_perf),
        div_perf: Some(div_perf),
        bpu_perf: Some(bpu_perf),
        mem_perf: Some(mem_perf),
    }
}

unsafe fn host_from_opaque<'a>(opaque: *mut c_void) -> Option<&'a mut EvalHost<'a>> {
    unsafe { (opaque as *mut EvalHost<'a>).as_mut() }
}

extern "C" fn pmem_read(opaque: *mut c_void, addr: u32, len: u32) -> u32 {
    let Some(host) = (unsafe { host_from_opaque(opaque) }) else {
        return 0;
    };
    match host.machine.dpi_read_word(addr, len) {
        Ok(data) => data,
        Err(error) => {
            host.status.record_machine_error(error);
            0
        }
    }
}

extern "C" fn pmem_write(opaque: *mut c_void, addr: u32, len: u32, data: u32) {
    let Some(host) = (unsafe { host_from_opaque(opaque) }) else {
        return;
    };
    if let Err(error) = host.machine.dpi_write_word(addr, len, data) {
        host.status.record_machine_error(error);
    }
}

extern "C" fn time_read(opaque: *mut c_void) -> u64 {
    let Some(host) = (unsafe { host_from_opaque(opaque) }) else {
        return 0;
    };
    host.machine.time_read()
}

extern "C" fn on_difftest_context(opaque: *mut c_void, context: *const CpuContext) {
    let Some(host) = (unsafe { host_from_opaque(opaque) }) else {
        return;
    };
    let Some(context) = (unsafe { context.as_ref() }) else {
        return;
    };
    host.checker.on_context(*context);
}

extern "C" fn on_difftest_commit(opaque: *mut c_void, raw: *const ffi::NpcCommitGroupEvent) {
    let Some(host) = (unsafe { host_from_opaque(opaque) }) else {
        return;
    };
    let Some(raw) = (unsafe { raw.as_ref() }) else {
        return;
    };
    let group = CommitGroup::new(
        raw.valid_mask,
        raw.finish_mask,
        raw.mem_valid_mask,
        raw.mem_write_mask,
        raw.pc,
        raw.inst,
        raw.raw_inst,
        raw.inst_len,
        raw.next_pc,
        raw.mem_addr,
        raw.mem_size,
        raw.async_intr_valid,
        raw.async_intr_cause,
        raw.async_intr_epc,
    );
    host.checker.on_commit(host.machine, group);
}

extern "C" fn cache_hit(opaque: *mut c_void, hit: u8) {
    if let Some(host) = unsafe { host_from_opaque(opaque) } {
        host.checker.on_cache_hit(hit != 0);
    }
}

extern "C" fn issue_queue_perf(
    opaque: *mut c_void,
    issue_count: u8,
    occupancy: u8,
    block_ready: u8,
    block_operand: u8,
) {
    if let Some(host) = unsafe { host_from_opaque(opaque) } {
        host.checker.on_issue_queue_perf(
            issue_count,
            occupancy,
            block_ready != 0,
            block_operand != 0,
        );
    }
}

extern "C" fn div_perf(opaque: *mut c_void, cycles: u32, special: u8) {
    if let Some(host) = unsafe { host_from_opaque(opaque) } {
        host.checker.on_div_perf(cycles, special != 0);
    }
}

extern "C" fn bpu_perf(opaque: *mut c_void, correct: u8) {
    if let Some(host) = unsafe { host_from_opaque(opaque) } {
        host.checker.on_bpu_prediction(correct != 0);
    }
}

extern "C" fn mem_perf(
    opaque: *mut c_void,
    events: u32,
    mshr_occupancy: u32,
    store_queue_occupancy: u32,
    load_txn_occupancy: u32,
) {
    if let Some(host) = unsafe { host_from_opaque(opaque) } {
        host.checker.on_memory_perf(
            events,
            mshr_occupancy,
            store_queue_occupancy,
            load_txn_occupancy,
        );
    }
}
