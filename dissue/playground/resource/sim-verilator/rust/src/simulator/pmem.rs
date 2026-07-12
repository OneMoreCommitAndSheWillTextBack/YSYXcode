use super::{Simulator, SimulatorError, SimulatorState, ANSI_FG_RED, ANSI_RESET, MBASE, PMEM_SIZE};
use crate::memory::MemoryError;
use std::fs;

const DEFAULT_IMAGE: [u32; 5] = [
    0x00000297, // auipc t0,0
    0x00028823, // sb  zero,16(t0)
    0x0102c503, // lbu a0,16(t0)
    0x00100073, // ebreak (used as nemu_trap)
    0xdeadbeef, // some data
];
const DIFFTEST_SYNC_CHUNK_SIZE: usize = 1024 * 1024;

impl Simulator {
    pub(super) fn load_image(&mut self) -> Result<usize, SimulatorError> {
        let image = match self.config.image.as_ref() {
            Some(path) => {
                crate::Log!("Image Path is {}", path.display());
                fs::read(path).map_err(|source| SimulatorError::ImageIo {
                    path: path.clone(),
                    source,
                })?
            }
            None => {
                crate::Log!("No Image Path Specific, Using Default Image");
                default_image_bytes()
            }
        };

        self.memory.write(MBASE, &image)?;
        crate::Log!("Image Load finished",);
        Ok(image.len())
    }

    pub(super) fn sync_pmem_to_difftest(&mut self) -> Result<(), SimulatorError> {
        if !self.difftest.needs_attach_context() {
            return Ok(());
        }

        let mut buffer = vec![0; DIFFTEST_SYNC_CHUNK_SIZE];
        let mut offset = 0;

        while offset < PMEM_SIZE {
            let len = (PMEM_SIZE - offset).min(buffer.len());
            let addr = MBASE + offset as u32;
            self.memory.read(addr, &mut buffer[..len])?;
            self.difftest.sync_memory(addr, &buffer[..len])?;
            offset += len;
        }

        Ok(())
    }

    pub(super) fn pmem_read(&self, addr: u32, len: u32) -> Result<u32, MemoryError> {
        let len = dpi_memory_len(addr, len)?;

        let mut data = [0_u8; 4];
        self.memory.read(addr, &mut data[..len])?;
        Ok(u32::from_le_bytes(data))
    }

    pub(super) fn pmem_write(&mut self, addr: u32, len: u32, data: u32) -> Result<(), MemoryError> {
        let len = dpi_memory_len(addr, len)?;
        self.memory.write(addr, &data.to_le_bytes()[..len])
    }

    pub(super) fn abort_memory_access(&mut self, error: MemoryError) {
        if self.pending_memory_error.is_some() {
            return;
        }

        print_pmem_access_error(&error, self.latest_context.map(|context| context.pc));
        self.pending_memory_error = Some(error);
        self.state = SimulatorState::Abort;
    }
}

fn default_image_bytes() -> Vec<u8> {
    let mut image = Vec::with_capacity(DEFAULT_IMAGE.len() * size_of::<u32>());

    for inst in DEFAULT_IMAGE {
        image.extend_from_slice(&inst.to_le_bytes());
    }

    image
}

fn dpi_memory_len(addr: u32, len: u32) -> Result<usize, MemoryError> {
    match len {
        1 | 2 | 4 => Ok(len as usize),
        _ => Err(MemoryError::Unmapped {
            addr,
            len: len as usize,
        }),
    }
}

fn print_pmem_access_error(error: &MemoryError, pc: Option<u32>) {
    let pc_suffix = pc
        .map(|pc| format!(" at pc = 0x{pc:08x}"))
        .unwrap_or_default();

    match error {
        MemoryError::Unmapped { addr, len } | MemoryError::OutOfBounds { addr, len, .. } => {
            let pmem_end = MBASE + PMEM_SIZE as u32 - 1;
            eprintln!(
                "{}address = 0x{addr:08x} len = {len} is out of bound of pmem [0x{MBASE:08x}, 0x{pmem_end:08x}]{pc_suffix}{}",
                ANSI_FG_RED, ANSI_RESET
            );
        }
        _ => {
            eprintln!(
                "{}pmem access error: {error:?}{pc_suffix}{}",
                ANSI_FG_RED, ANSI_RESET
            );
        }
    }
}
