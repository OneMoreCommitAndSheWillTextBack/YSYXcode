use super::{MBASE, PMEM_SIZE};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct CommitEvent {
    valid: bool,
    finish: bool,
    pc: u32,
    inst: u32,
    raw_inst: u32,
    inst_len: u32,
    next_pc: u32,
    mem_valid: bool,
    mem_write: bool,
    mem_addr: u32,
    mem_size: u32,
}

impl CommitEvent {
    pub fn new(
        valid: bool,
        finish: bool,
        pc: u32,
        inst: u32,
        raw_inst: u32,
        inst_len: u32,
        next_pc: u32,
        mem_valid: bool,
        mem_write: bool,
        mem_addr: u32,
        mem_size: u32,
    ) -> Self {
        Self {
            valid,
            finish,
            pc,
            inst,
            raw_inst,
            inst_len,
            next_pc,
            mem_valid,
            mem_write,
            mem_addr,
            mem_size,
        }
    }

    fn needs_difftest_sync(self) -> bool {
        self.valid
            && (instruction_needs_difftest_sync(self.inst)
                || memory_access_needs_difftest_sync(self.mem_valid, self.mem_addr, self.mem_size))
    }
}

pub const COMMIT_GROUP_WIDTH: usize = 2;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct CommitGroupEvent {
    lanes: [CommitEvent; COMMIT_GROUP_WIDTH],
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct CommitTraceEntry {
    pub pc: u32,
    pub inst: u32,
    pub raw_inst: u32,
    pub inst_len: u32,
    pub next_pc: u32,
    pub mem_valid: bool,
    pub mem_write: bool,
    pub mem_addr: u32,
    pub mem_size: u32,
}

impl CommitGroupEvent {
    pub fn new(
        valid_mask: u32,
        finish_mask: u32,
        mem_valid_mask: u32,
        mem_write_mask: u32,
        pc: [u32; COMMIT_GROUP_WIDTH],
        inst: [u32; COMMIT_GROUP_WIDTH],
        raw_inst: [u32; COMMIT_GROUP_WIDTH],
        inst_len: [u32; COMMIT_GROUP_WIDTH],
        next_pc: [u32; COMMIT_GROUP_WIDTH],
        mem_addr: [u32; COMMIT_GROUP_WIDTH],
        mem_size: [u32; COMMIT_GROUP_WIDTH],
    ) -> Self {
        let lanes = std::array::from_fn(|idx| {
            CommitEvent::new(
                ((valid_mask >> idx) & 1) != 0,
                ((finish_mask >> idx) & 1) != 0,
                pc[idx],
                inst[idx],
                raw_inst[idx],
                inst_len[idx],
                next_pc[idx],
                ((mem_valid_mask >> idx) & 1) != 0,
                ((mem_write_mask >> idx) & 1) != 0,
                mem_addr[idx],
                mem_size[idx],
            )
        });

        Self { lanes }
    }

    pub fn valid_count(&self) -> u64 {
        self.lanes.iter().filter(|event| event.valid).count() as u64
    }

    pub fn valid_insts(&self) -> impl Iterator<Item = u32> + '_ {
        self.lanes
            .iter()
            .filter(|event| event.valid)
            .map(|event| event.inst)
    }

    pub fn valid_inst_pc(&self) -> impl Iterator<Item = (u32, u32)> + '_ {
        self.lanes
            .iter()
            .filter(|event| event.valid)
            .map(|event| (event.pc, event.inst))
    }

    pub fn trace_entries(&self) -> impl Iterator<Item = CommitTraceEntry> + '_ {
        self.lanes
            .iter()
            .filter(|event| event.valid)
            .map(|event| CommitTraceEntry {
                pc: event.pc,
                inst: event.inst,
                raw_inst: event.raw_inst,
                inst_len: event.inst_len,
                next_pc: event.next_pc,
                mem_valid: event.mem_valid,
                mem_write: event.mem_write,
                mem_addr: event.mem_addr,
                mem_size: event.mem_size,
            })
    }

    pub fn has_finish(&self) -> bool {
        self.lanes.iter().any(|event| event.valid && event.finish)
    }

    pub fn needs_difftest_sync(&self) -> bool {
        self.difftest_sync_prefix_count().is_some()
    }

    pub fn difftest_sync_prefix_count(&self) -> Option<u64> {
        let mut count = 0;
        for event in self.lanes {
            if !event.valid {
                continue;
            }
            if event.needs_difftest_sync() {
                return Some(count);
            }
            count += 1;
        }

        None
    }
}

fn instruction_needs_difftest_sync(inst: u32) -> bool {
    const OPCODE_SYSTEM: u32 = 0b1110011;

    if (inst & 0x7f) != OPCODE_SYSTEM {
        return false;
    }

    let csr = (inst >> 20) & 0xfff;
    let funct3 = (inst >> 12) & 0x7;
    let rd = (inst >> 7) & 0x1f;

    is_counter_csr(csr) && csr_read_writes_rd(funct3, rd)
}

fn csr_read_writes_rd(funct3: u32, rd: u32) -> bool {
    rd != 0 && matches!(funct3, 0b001 | 0b010 | 0b011 | 0b101 | 0b110 | 0b111)
}

fn is_counter_csr(csr: u32) -> bool {
    matches!(
        csr,
        0xc00 | 0xc01 | 0xc02 | 0xc80 | 0xc81 | 0xc82 | 0xb00 | 0xb02 | 0xb80 | 0xb82
    )
}

fn memory_access_needs_difftest_sync(valid: bool, addr: u32, size: u32) -> bool {
    valid && !pmem_contains(addr, mem_access_len(size))
}

fn mem_access_len(size: u32) -> u32 {
    match size {
        0 => 1,
        1 => 2,
        _ => 4,
    }
}

fn pmem_contains(addr: u32, len: u32) -> bool {
    let Ok(pmem_size) = u32::try_from(PMEM_SIZE) else {
        return false;
    };
    let Some(end) = addr.checked_add(len.saturating_sub(1)) else {
        return false;
    };
    addr >= MBASE && end < MBASE + pmem_size
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn counter_csr_read_requests_difftest_sync() {
        let rdcycle_a0 = 0xc000_2573;
        let event = CommitGroupEvent::new(
            0b01,
            0,
            0,
            0,
            [0x8000_0000, 0],
            [rdcycle_a0, 0],
            [rdcycle_a0, 0],
            [4, 0],
            [0x8000_0004, 0],
            [0, 0],
            [0, 0],
        );

        assert!(event.needs_difftest_sync());
    }

    #[test]
    fn normal_load_does_not_request_difftest_sync() {
        let lw_a0_zero_a1 = 0x0005_2503;
        let event = CommitGroupEvent::new(
            0b01,
            0,
            0b01,
            0,
            [0x8000_0000, 0],
            [lw_a0_zero_a1, 0],
            [lw_a0_zero_a1, 0],
            [4, 0],
            [0x8000_0004, 0],
            [MBASE, 0],
            [2, 0],
        );

        assert!(!event.needs_difftest_sync());
    }

    #[test]
    fn discarded_counter_read_does_not_request_difftest_sync() {
        let rdcycle_x0 = 0xc000_2073;
        let event = CommitGroupEvent::new(
            0b01,
            0,
            0,
            0,
            [0x8000_0000, 0],
            [rdcycle_x0, 0],
            [rdcycle_x0, 0],
            [4, 0],
            [0x8000_0004, 0],
            [0, 0],
            [0, 0],
        );

        assert!(!event.needs_difftest_sync());
    }

    #[test]
    fn mmio_store_requests_difftest_sync() {
        let sb_a7_zero_a5 = 0x0117_8023;
        let event = CommitGroupEvent::new(
            0b01,
            0,
            0b01,
            0b01,
            [0x8001_c00c, 0],
            [sb_a7_zero_a5, 0],
            [sb_a7_zero_a5, 0],
            [4, 0],
            [0x8001_c010, 0],
            [0x0900_0001, 0],
            [0, 0],
        );

        assert!(event.needs_difftest_sync());
    }
}
