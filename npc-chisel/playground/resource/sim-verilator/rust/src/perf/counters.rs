use crate::simulator::CommitEvent;

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct PerfCounters {
    cycles: u64,
    committed_insts: u64,
}

impl PerfCounters {
    pub fn on_cycle(&mut self) {
        self.cycles += 1;
    }

    pub fn on_commit(&mut self, event: &CommitEvent) {
        if event.valid {
            self.committed_insts += 1;
        }
    }

    pub fn cycles(&self) -> u64 {
        self.cycles
    }

    pub fn committed_insts(&self) -> u64 {
        self.committed_insts
    }
}
