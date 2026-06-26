mod event;

pub use event::CommitEvent;

use crate::{
    config::SimulatorConfig,
    cpu::{Cpu, CpuContext, CpuError, CsrContext},
    difftest::{DiffTest, DifftestError},
    ffi,
    memory::{Memory, MemoryError},
    perf::Perf,
    sdb::SdbError,
    SimulatorResult, ACTIVE_SIMULATOR,
};
use std::{fs, io, path::PathBuf};

const MBASE: u32 = 0x8000_0000;
const PMEM_SIZE: usize = 128 * 1024 * 1024;
const DEFAULT_IMAGE: [u32; 13] = [
    0x00000413, 0x00009117, 0xffc10113, 0x00c000ef, 0x00000513, 0x00008067, 0xff410113, 0x00000517,
    0x01450513, 0x00112423, 0xfe9ff0ef, 0x00050513, 0x00100073,
];

#[derive(Debug)]
pub enum SimulatorError {
    Memory(MemoryError),
    Sdb(SdbError),
    Cpu(CpuError),
    Difftest(DifftestError),
    ImageIo { path: PathBuf, source: io::Error },
    CpuNotConnected,
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
        });
        let callbacks = ffi::NpcDpiCallbacks {
            on_commit: None,
            on_current_pc: None,
            pmem_read: Some(simulator_pmem_read),
            pmem_write: Some(simulator_pmem_write),
        };
        simulator.cpu = Some(Cpu::connect(&callbacks)?);
        set_active_simulator(&mut *simulator as *mut Self);

        simulator.memory.register_ram("pmem", MBASE, PMEM_SIZE)?;
        simulator.load_image()?;

        let wave_path = simulator.config.wave_path.as_deref();
        simulator
            .cpu
            .as_mut()
            .ok_or(SimulatorError::CpuNotConnected)?
            .init_wave(wave_path)?;

        Ok(simulator)
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
        let context = {
            let Some(cpu) = self.cpu.as_mut() else {
                return Err(SimulatorError::CpuNotConnected);
            };

            cpu.step();

            if self.difftest.needs_check_context() {
                Some(cpu.context()?)
            } else {
                None
            }
        };

        self.perf.on_cycle();
        if let Some(context) = context {
            self.difftest.step_and_check(&context)?;
        }

        Ok(())
    }

    pub fn execute(&mut self, times: u64) -> SimulatorResult<()> {
        for _ in 0..times {
            self.execute_once()?;
        }

        Ok(())
    }

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

    pub fn difftest_step_and_check(&mut self) -> SimulatorResult<()> {
        let context = self.cpu_context()?;
        Ok(self.difftest.step_and_check(&context)?)
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
        println!("\x1b[0m\x1b[1;32mfinish load memory\x1b[0m");
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
