mod event;
mod report;

pub use event::CommitGroupEvent;

use crate::{
    config::SimulatorConfig,
    cpu::{Cpu, CpuContext, CpuError, CsrContext},
    difftest::{DiffTest, DifftestError},
    ffi,
    memory::{Memory, MemoryError},
    perf::Perf,
    sdb::SdbError,
    sim_log,
    simulator::SimulatorState::Running,
    SimulatorResult, ACTIVE_SIMULATOR,
};
use chrono::Local;
use std::{fs, io, path::PathBuf};

const MBASE: u32 = 0x8000_0000;
const PMEM_SIZE: usize = 128 * 1024 * 1024;
// const DEFAULT_IMAGE: [u32; 13] = [
//     0x00000413, 0x00009117, 0xffc10113, 0x00c000ef, 0x00000513, 0x00008067, 0xff410113, 0x00000517,
//     0x01450513, 0x00112423, 0xfe9ff0ef, 0x00050513, 0x00100073,
// ];

const DEFAULT_IMAGE: [u32; 5] = [
    0x00000297, // auipc t0,0
    0x00028823, // sb  zero,16(t0)
    0x0102c503, // lbu a0,16(t0)
    0x00100073, // ebreak (used as nemu_trap)
    0xdeadbeef, // some data
];

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
    ImageIo { path: PathBuf, source: io::Error },
    CpuNotConnected,
    SimulateAbort,
    ReachMaxNoCommitCyc,
}

pub enum SimulatorState {
    Running,
    Stop,
    Abort,
    End,
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

    cycle_nocommit: u32,
    cycle: u64,
    total_commits: u64,
}

impl Simulator {
    pub fn new(config: SimulatorConfig) -> SimulatorResult<Box<Self>> {
        let difftest_ref = config.difftest_ref.clone();
        let difftest = DiffTest::new(difftest_ref)?;

        let mut simulator = Box::new(Self {
            config,
            memory: Memory::new(),
            cpu: None,
            perf: Perf::new(),
            difftest,
            state: Running,
            cycle_nocommit: 0,
            cycle: 0,
            total_commits: 0,
        });
        let callbacks = ffi::NpcDpiCallbacks {
            on_commit_group: Some(simulator_on_commit_group),
            pmem_read: Some(simulator_pmem_read),
            pmem_write: Some(simulator_pmem_write),
        };
        simulator.cpu = Some(Cpu::connect(&callbacks)?);
        set_active_simulator(&mut *simulator as *mut Self);
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
        let context = {
            let Some(cpu) = self.cpu.as_mut() else {
                return Err(SimulatorError::CpuNotConnected);
            };

            cpu.reset(self.config.reset_cycles);

            if self.difftest.needs_attach_context() {
                Some(cpu.context()?)
            } else {
                None
            }
        };

        if let Some(context) = context {
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
        Ok(())
    }

    pub fn execute(&mut self, times: u64) -> SimulatorResult<()> {
        for _ in 0..times {
            match self.state {
                SimulatorState::Running | SimulatorState::Stop => {}
                SimulatorState::End => return Ok(()),
                SimulatorState::Abort => return Err(SimulatorError::SimulateAbort),
            }

            if self.cycle_nocommit > 20000 {
                return Err(SimulatorError::ReachMaxNoCommitCyc);
            }

            self.execute_once()?;
            self.cycle_nocommit += 1;
        }

        Ok(())
    }

    pub fn do_difftest(&mut self, steps: u64) -> SimulatorResult<()> {
        let context = {
            let Some(cpu) = self.cpu.as_mut() else {
                return Err(SimulatorError::CpuNotConnected);
            };

            if self.difftest.needs_check_context() {
                Some(cpu.context()?)
            } else {
                None
            }
        };

        if let Some(context) = context {
            self.difftest.step_and_check(steps, &context)?;
        }

        Ok(())
    }

    fn on_commit_group(&mut self, event: CommitGroupEvent) {
        self.perf.on_commit_group(&event);

        let commit_count = event.valid_count();

        if commit_count == 0 {
            return;
        }

        if !matches!(self.state, SimulatorState::Running | SimulatorState::Stop) {
            return;
        }

        self.cycle_nocommit = 0;
        for inst in event.valid_insts() {
            println!("commit inst 0x{inst:08x}");
        }

        if let Err(error) = self.do_difftest(commit_count) {
            eprintln!("[Error] commit handling failed: {error:?}");
            report::print_difftest_report(&error);
            self.state = SimulatorState::Abort;
            return;
        }

        if event.has_finish() {
            let context = match self.cpu.as_mut().and_then(|cpu| cpu.context().ok()) {
                Some(context) => context,
                None => {
                    panic!("should not reach here");
                }
            };

            self.state = if context.gpr[10] == 0 {
                eprintln!("{}HIT GOOD TRAP{}", ANSI_FG_GREEN, ANSI_RESET);
                SimulatorState::End
            } else {
                eprintln!("{}HIT BAD TRAP{}", ANSI_FG_RED, ANSI_RESET);
                SimulatorState::Abort
            };
        }
    }

    pub fn generat_report(&mut self) {}

    pub fn cpu_gpr(&mut self) -> SimulatorResult<[u32; 32]> {
        let cpu = self.cpu.as_mut().ok_or(SimulatorError::CpuNotConnected)?;
        Ok(cpu.gpr()?)
    }

    pub fn cpu_csr(&mut self) -> SimulatorResult<CsrContext> {
        let cpu = self.cpu.as_mut().ok_or(SimulatorError::CpuNotConnected)?;
        Ok(cpu.csr()?)
    }

    pub fn cpu_context(&mut self) -> SimulatorResult<CpuContext> {
        let cpu = self.cpu.as_mut().ok_or(SimulatorError::CpuNotConnected)?;
        Ok(cpu.context()?)
    }

    pub fn difftest_attach(&mut self) -> SimulatorResult<()> {
        let context = self.cpu_context()?;
        Ok(self.difftest.attach(&context)?)
    }

    pub fn difftest_detach(&mut self) {
        self.difftest.detach();
    }

    fn load_image(&mut self) -> SimulatorResult<usize> {
        let image = match self.config.image.as_ref() {
            Some(path) => fs::read(path).map_err(|source| SimulatorError::ImageIo {
                path: path.clone(),
                source,
            })?,
            None => default_image_bytes(),
        };

        self.memory.write(MBASE, &image)?;
        self.difftest.sync_memory(MBASE, &image)?;
        crate::Log!(
            "Image Load finished, Image Path is {}",
            self.config.image.as_ref().unwrap().display()
        );
        Ok(image.len())
    }

    fn pmem_read(&self, addr: u32, len: u32) -> Result<u32, MemoryError> {
        let len = dpi_memory_len(addr, len)?;

        let mut data = [0_u8; 4];
        self.memory.read(addr, &mut data[..len])?;
        Ok(u32::from_le_bytes(data))
    }

    fn pmem_write(&mut self, addr: u32, len: u32, data: u32) -> Result<(), MemoryError> {
        let len = dpi_memory_len(addr, len)?;
        self.memory.write(addr, &data.to_le_bytes()[..len])
    }
}

fn default_image_bytes() -> Vec<u8> {
    let mut image = Vec::with_capacity(DEFAULT_IMAGE.len() * size_of::<u32>());

    for inst in DEFAULT_IMAGE {
        image.extend_from_slice(&inst.to_le_bytes());
    }

    image
}

impl Drop for Simulator {
    fn drop(&mut self) {
        self.cpu.take();
        set_active_simulator(std::ptr::null_mut());
    }
}

fn dpi_memory_len(addr: u32, len: u32) -> Result<usize, MemoryError> {
    match len {
        1 | 2 | 4 => Ok(len as usize),
        _ => Err(MemoryError::Unmapped {
            addr: addr,
            len: len as usize,
        }),
    }
}

fn set_active_simulator(simulator: *mut Simulator) {
    unsafe { ACTIVE_SIMULATOR = simulator };
}

fn active_simulator() -> *mut Simulator {
    unsafe { ACTIVE_SIMULATOR }
}

extern "C" fn simulator_pmem_read(addr: u32, len: u32) -> u32 {
    let simulator = unsafe { &*active_simulator() };
    simulator.pmem_read(addr, len).unwrap_or(0)
}

extern "C" fn simulator_pmem_write(addr: u32, len: u32, data: u32) {
    let simulator = unsafe { &mut *active_simulator() };
    let _ = simulator.pmem_write(addr, len, data);
}

extern "C" fn simulator_on_commit_group(event: *const ffi::NpcCommitGroupEvent) {
    if event.is_null() {
        return;
    }

    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }

    let event = unsafe { &*event };
    let simulator = unsafe { &mut *simulator };
    simulator.on_commit_group(CommitGroupEvent::new(
        event.valid_mask,
        event.finish_mask,
        event.pc,
        event.inst,
    ));
}
