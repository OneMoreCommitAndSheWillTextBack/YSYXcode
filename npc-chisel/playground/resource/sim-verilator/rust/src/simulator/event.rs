#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct CommitEvent {
    valid: bool,
    finish: bool,
    pc: u32,
    inst: u32,
}

impl CommitEvent {
    pub fn new(valid: bool, finish: bool, pc: u32, inst: u32) -> Self {
        Self {
            valid,
            finish,
            pc,
            inst,
        }
    }
}

pub const COMMIT_GROUP_WIDTH: usize = 2;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct CommitGroupEvent {
    lanes: [CommitEvent; COMMIT_GROUP_WIDTH],
}

impl CommitGroupEvent {
    pub fn new(
        valid_mask: u32,
        finish_mask: u32,
        pc: [u32; COMMIT_GROUP_WIDTH],
        inst: [u32; COMMIT_GROUP_WIDTH],
    ) -> Self {
        let lanes = std::array::from_fn(|idx| {
            CommitEvent::new(
                ((valid_mask >> idx) & 1) != 0,
                ((finish_mask >> idx) & 1) != 0,
                pc[idx],
                inst[idx],
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

    pub fn has_finish(&self) -> bool {
        self.lanes.iter().any(|event| event.valid && event.finish)
    }
}
