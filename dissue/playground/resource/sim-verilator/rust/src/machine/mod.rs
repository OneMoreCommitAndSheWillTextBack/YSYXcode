//! Host-owned machine state.
//!
//! The RTL reaches this module only through a short-lived evaluation host.
//! No checker or driver owns physical memory.

mod memory;
mod time;

pub(crate) use memory::{Memory, MemoryError};

use crate::config::MachineConfig;
use std::{fmt, fs, io, path::PathBuf};

const DEFAULT_IMAGE: [u32; 5] = [
    0x0000_0297,
    0x0002_8823,
    0x0102_c503,
    0x0010_0073,
    0xdead_beef,
];

/// Errors raised while servicing the host-side machine.
#[derive(Debug)]
pub(crate) enum MachineError {
    Memory(MemoryError),
    ImageIo { path: PathBuf, source: io::Error },
    InvalidDpiAccessSize { addr: u32, len: u32 },
}

impl fmt::Display for MachineError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Memory(error) => write!(formatter, "memory error: {error}"),
            Self::ImageIo { path, source } => {
                write!(
                    formatter,
                    "failed to read image `{}`: {source}",
                    path.display()
                )
            }
            Self::InvalidDpiAccessSize { addr, len } => {
                write!(
                    formatter,
                    "invalid DPI memory access at 0x{addr:08x} with length {len}"
                )
            }
        }
    }
}

impl std::error::Error for MachineError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Memory(error) => Some(error),
            Self::ImageIo { source, .. } => Some(source),
            Self::InvalidDpiAccessSize { .. } => None,
        }
    }
}

impl From<MemoryError> for MachineError {
    fn from(value: MemoryError) -> Self {
        Self::Memory(value)
    }
}

/// Mutable platform state directly visible to the simulated design.
#[derive(Debug)]
pub(crate) struct Machine {
    config: MachineConfig,
    memory: Memory,
    timer: Option<time::SimTimer>,
}

impl Machine {
    /// Allocates the configured physical memory region.
    pub(crate) fn new(config: MachineConfig) -> Result<Self, MachineError> {
        let mut memory = Memory::new();
        memory.register_ram("pmem", config.pmem_base, config.pmem_size)?;

        Ok(Self {
            config,
            memory,
            timer: None,
        })
    }

    /// Loads the selected image or the built-in smoke image into physical RAM.
    pub(crate) fn load_image(&mut self) -> Result<usize, MachineError> {
        let image = match self.config.image.as_ref() {
            Some(path) => {
                crate::Log!("Image Path is {}", path.display());
                fs::read(path).map_err(|source| MachineError::ImageIo {
                    path: path.clone(),
                    source,
                })?
            }
            None => {
                crate::Log!("No Image Path Specific, Using Default Image");
                default_image_bytes()
            }
        };

        self.memory.write(self.ram_base(), &image)?;
        crate::Log!("Image Load finished");
        Ok(image.len())
    }

    /// Starts the host wall-clock used by the legacy DPI time callback.
    pub(crate) fn reset_time(&mut self) {
        self.timer = Some(time::SimTimer::new());
    }

    /// Returns elapsed host microseconds for the legacy DPI time callback.
    pub(crate) fn time_read(&self) -> u64 {
        self.timer
            .as_ref()
            .map_or(0, time::SimTimer::elapsed_micros)
    }

    /// Reads a little-endian 1-, 2-, or 4-byte value for the RTL memory DPI.
    pub(crate) fn dpi_read_word(&self, addr: u32, len: u32) -> Result<u32, MachineError> {
        let len = dpi_access_len(addr, len)?;
        let mut data = [0_u8; 4];
        self.read(addr, &mut data[..len])?;
        Ok(u32::from_le_bytes(data))
    }

    /// Writes a little-endian 1-, 2-, or 4-byte value for the RTL memory DPI.
    pub(crate) fn dpi_write_word(
        &mut self,
        addr: u32,
        len: u32,
        data: u32,
    ) -> Result<(), MachineError> {
        let len = dpi_access_len(addr, len)?;
        self.write(addr, &data.to_le_bytes()[..len])
    }

    /// Reads an arbitrary physical-memory range for image and difftest sync.
    pub(crate) fn read(&self, addr: u32, data: &mut [u8]) -> Result<(), MachineError> {
        self.memory.read(addr, data).map_err(Into::into)
    }

    /// Writes an arbitrary physical-memory range for image loading.
    pub(crate) fn write(&mut self, addr: u32, data: &[u8]) -> Result<(), MachineError> {
        self.memory.write(addr, data).map_err(Into::into)
    }

    /// Returns whether a complete range belongs to physical RAM.
    pub(crate) fn contains_ram_range(&self, addr: u32, len: usize) -> bool {
        self.memory
            .find_region(addr, len)
            .is_ok_and(|region| region.base() == self.ram_base())
    }

    pub(crate) fn ram_base(&self) -> u32 {
        self.config.pmem_base
    }

    pub(crate) fn ram_size(&self) -> usize {
        self.config.pmem_size
    }

    /// Formats a callback memory failure with the latest available DUT PC.
    pub(crate) fn report_dpi_access_error(&self, error: &MachineError, pc: Option<u32>) {
        let pc_suffix = pc
            .map(|pc| format!(" at pc = 0x{pc:08x}"))
            .unwrap_or_default();

        match error {
            MachineError::Memory(MemoryError::Unmapped { addr, len })
            | MachineError::Memory(MemoryError::OutOfBounds { addr, len, .. }) => {
                let ram_end = self
                    .ram_base()
                    .saturating_add(self.ram_size() as u32)
                    .saturating_sub(1);
                eprintln!(
                    "address = 0x{addr:08x} len = {len} is out of bound of pmem [0x{:08x}, 0x{ram_end:08x}]{pc_suffix}",
                    self.ram_base()
                );
            }
            _ => eprintln!("pmem access error: {error}{pc_suffix}"),
        }
    }
}

fn default_image_bytes() -> Vec<u8> {
    let mut image = Vec::with_capacity(DEFAULT_IMAGE.len() * size_of::<u32>());
    for instruction in DEFAULT_IMAGE {
        image.extend_from_slice(&instruction.to_le_bytes());
    }
    image
}

fn dpi_access_len(addr: u32, len: u32) -> Result<usize, MachineError> {
    match len {
        1 | 2 | 4 => Ok(len as usize),
        _ => Err(MachineError::InvalidDpiAccessSize { addr, len }),
    }
}
