//! Retire observations emitted by the RTL DPI bridge.

const CSR_SIP: u32 = 0x144;
const CSR_MIP: u32 = 0x344;

pub(crate) const COMMIT_GROUP_WIDTH: usize = 2;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct CommitLane {
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

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) struct AsyncInterrupt {
    cause: u32,
    epc: u32,
}

impl AsyncInterrupt {
    fn from_raw(valid: u32, cause: u32, epc: u32) -> Option<Self> {
        (valid != 0).then_some(Self { cause, epc })
    }

    pub(crate) fn cause(self) -> u32 {
        self.cause
    }

    pub(crate) fn epc(self) -> u32 {
        self.epc
    }
}

/// All retire lanes observed in one DUT cycle.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) struct CommitGroup {
    lanes: [CommitLane; COMMIT_GROUP_WIDTH],
    async_interrupt: Option<AsyncInterrupt>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) struct CommitTraceEntry {
    pub finish: bool,
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

impl CommitGroup {
    pub(crate) fn new(
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
        async_intr_valid: u32,
        async_intr_cause: u32,
        async_intr_epc: u32,
    ) -> Self {
        let lanes = std::array::from_fn(|index| CommitLane {
            valid: ((valid_mask >> index) & 1) != 0,
            finish: ((finish_mask >> index) & 1) != 0,
            pc: pc[index],
            inst: inst[index],
            raw_inst: raw_inst[index],
            inst_len: inst_len[index],
            next_pc: next_pc[index],
            mem_valid: ((mem_valid_mask >> index) & 1) != 0,
            mem_write: ((mem_write_mask >> index) & 1) != 0,
            mem_addr: mem_addr[index],
            mem_size: mem_size[index],
        });

        Self {
            lanes,
            async_interrupt: AsyncInterrupt::from_raw(
                async_intr_valid,
                async_intr_cause,
                async_intr_epc,
            ),
        }
    }

    pub(crate) fn valid_count(self) -> u64 {
        self.lanes.iter().filter(|lane| lane.valid).count() as u64
    }

    pub(crate) fn has_finish(self) -> bool {
        self.lanes.iter().any(|lane| lane.valid && lane.finish)
    }

    pub(crate) fn async_interrupt(self) -> Option<AsyncInterrupt> {
        self.async_interrupt
    }

    pub(crate) fn trace_entries(self) -> impl Iterator<Item = CommitTraceEntry> {
        self.trace_lanes().map(|(_, entry)| entry)
    }

    pub(crate) fn trace_lanes(self) -> impl Iterator<Item = (usize, CommitTraceEntry)> {
        self.lanes
            .into_iter()
            .enumerate()
            .filter_map(|(index, lane)| {
                lane.valid.then_some((
                    index,
                    CommitTraceEntry {
                        finish: lane.finish,
                        pc: lane.pc,
                        inst: lane.inst,
                        raw_inst: lane.raw_inst,
                        inst_len: lane.inst_len,
                        next_pc: lane.next_pc,
                        mem_valid: lane.mem_valid,
                        mem_write: lane.mem_write,
                        mem_addr: lane.mem_addr,
                        mem_size: lane.mem_size,
                    },
                ))
            })
    }

    pub(crate) fn store_conditional_gpr_mask(self) -> u32 {
        self.lanes
            .into_iter()
            .filter(|lane| lane.valid && is_store_conditional(lane.inst))
            .fold(0, |mask, lane| mask | (1 << ((lane.inst >> 7) & 0x1f)))
    }

    pub(crate) fn store_conditional_memory_regions(self) -> impl Iterator<Item = (u32, usize)> {
        self.lanes.into_iter().filter_map(|lane| {
            (lane.valid && lane.mem_valid && is_store_conditional(lane.inst))
                .then_some((lane.mem_addr, memory_access_len(lane.mem_size)))
        })
    }

    /// Returns the number of instructions that may execute in the reference
    /// before the first event requiring a full reference-context sync.
    pub(crate) fn difftest_sync_prefix_count(
        self,
        contains_ram: impl Fn(u32, usize) -> bool,
    ) -> Option<u64> {
        let mut count = 0;
        for lane in self.lanes {
            if !lane.valid {
                continue;
            }

            let needs_sync = instruction_needs_difftest_sync(lane.inst)
                || (lane.mem_valid
                    && !contains_ram(lane.mem_addr, memory_access_len(lane.mem_size)));
            if needs_sync {
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
    is_csr_access(funct3) && (is_interrupt_pending_csr(csr) || (is_counter_csr(csr) && rd != 0))
}

fn is_store_conditional(inst: u32) -> bool {
    const OPCODE_AMO: u32 = 0b0101111;
    const FUNCT3_WORD: u32 = 0b010;
    const FUNCT5_SC: u32 = 0b00011;
    (inst & 0x7f) == OPCODE_AMO
        && ((inst >> 12) & 0x7) == FUNCT3_WORD
        && ((inst >> 27) & 0x1f) == FUNCT5_SC
}

fn is_csr_access(funct3: u32) -> bool {
    matches!(funct3, 0b001 | 0b010 | 0b011 | 0b101 | 0b110 | 0b111)
}

fn is_interrupt_pending_csr(csr: u32) -> bool {
    matches!(csr, CSR_SIP | CSR_MIP)
}

fn is_counter_csr(csr: u32) -> bool {
    matches!(
        csr,
        0xc00 | 0xc01 | 0xc02 | 0xc80 | 0xc81 | 0xc82 | 0xb00 | 0xb02 | 0xb80 | 0xb82
    )
}

pub(crate) fn memory_access_len(size: u32) -> usize {
    match size {
        0 => 1,
        1 => 2,
        _ => 4,
    }
}
