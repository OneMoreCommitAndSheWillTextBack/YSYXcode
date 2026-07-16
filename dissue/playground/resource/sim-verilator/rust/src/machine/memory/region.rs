use super::MemoryBlock;
use std::fmt;

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum MemoryError {
    ZeroLength { name: String },
    AddressOverflow { name: String },
    Overlap { name: String, existing: String },
    Unmapped { addr: u32, len: usize },
    OutOfBounds { name: String, addr: u32, len: usize },
}

impl fmt::Display for MemoryError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::ZeroLength { name } => {
                write!(formatter, "memory region `{name}` has zero length")
            }
            Self::AddressOverflow { name } => {
                write!(
                    formatter,
                    "memory region `{name}` exceeds the address space"
                )
            }
            Self::Overlap { name, existing } => {
                write!(formatter, "memory region `{name}` overlaps `{existing}`")
            }
            Self::Unmapped { addr, len } => {
                write!(
                    formatter,
                    "unmapped memory access at 0x{addr:08x} (length {len})"
                )
            }
            Self::OutOfBounds { name, addr, len } => write!(
                formatter,
                "memory access at 0x{addr:08x} (length {len}) is outside region `{name}`"
            ),
        }
    }
}

impl std::error::Error for MemoryError {}

#[derive(Debug)]
pub struct MemoryRegion {
    name: String,
    base: u32,
    len: u32,
    block: MemoryBlock,
}

impl MemoryRegion {
    pub fn new_ram(name: String, base: u32, len: usize) -> Result<Self, MemoryError> {
        if len == 0 {
            return Err(MemoryError::ZeroLength { name });
        }

        let len_u32 = len as u32;
        if base.checked_add(len_u32).is_none() {
            return Err(MemoryError::AddressOverflow { name });
        }

        Ok(Self {
            name,
            base,
            len: len_u32,
            block: MemoryBlock::new(len),
        })
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn base(&self) -> u32 {
        self.base
    }

    pub fn end(&self) -> u32 {
        self.base + self.len
    }

    pub fn overlaps(&self, other: &Self) -> bool {
        self.base < other.end() && other.base < self.end()
    }

    pub fn contains_range(&self, addr: u32, len: usize) -> bool {
        let Some(end) = addr.checked_add(len as u32) else {
            return false;
        };

        addr >= self.base && end <= self.end()
    }

    pub fn read(&self, addr: u32, buf: &mut [u8]) -> Result<(), MemoryError> {
        if !self.contains_range(addr, buf.len()) {
            return Err(MemoryError::OutOfBounds {
                name: self.name.clone(),
                addr,
                len: buf.len(),
            });
        }

        self.block.read((addr - self.base) as usize, buf);
        Ok(())
    }

    pub fn write(&mut self, addr: u32, data: &[u8]) -> Result<(), MemoryError> {
        if !self.contains_range(addr, data.len()) {
            return Err(MemoryError::OutOfBounds {
                name: self.name.clone(),
                addr,
                len: data.len(),
            });
        }

        self.block.write((addr - self.base) as usize, data);
        Ok(())
    }
}
