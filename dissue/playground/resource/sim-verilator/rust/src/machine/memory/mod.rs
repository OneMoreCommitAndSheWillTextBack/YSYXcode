mod memory;
mod region;

pub use memory::MemoryBlock;
pub use region::{MemoryError, MemoryRegion};

#[derive(Debug, Default)]
pub struct Memory {
    regions: Vec<MemoryRegion>,
}

impl Memory {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn register_ram(
        &mut self,
        name: impl Into<String>,
        base: u32,
        len: usize,
    ) -> Result<&MemoryRegion, MemoryError> {
        let name = name.into();
        let region = MemoryRegion::new_ram(name, base, len)?;

        for existing in &self.regions {
            if region.overlaps(existing) {
                return Err(MemoryError::Overlap {
                    name: region.name().to_owned(),
                    existing: existing.name().to_owned(),
                });
            }
        }

        self.regions.push(region);
        Ok(self.regions.last().expect("region was just inserted"))
    }

    pub fn read(&self, addr: u32, buf: &mut [u8]) -> Result<(), MemoryError> {
        let region = self.find_region(addr, buf.len())?;
        region.read(addr, buf)
    }

    pub fn write(&mut self, addr: u32, data: &[u8]) -> Result<(), MemoryError> {
        let region = self.find_region_mut(addr, data.len())?;
        region.write(addr, data)
    }

    pub fn find_region(&self, addr: u32, len: usize) -> Result<&MemoryRegion, MemoryError> {
        self.regions
            .iter()
            .find(|region| region.contains_range(addr, len))
            .ok_or(MemoryError::Unmapped { addr, len })
    }

    pub fn find_region_mut(
        &mut self,
        addr: u32,
        len: usize,
    ) -> Result<&mut MemoryRegion, MemoryError> {
        self.regions
            .iter_mut()
            .find(|region| region.contains_range(addr, len))
            .ok_or(MemoryError::Unmapped { addr, len })
    }
}
