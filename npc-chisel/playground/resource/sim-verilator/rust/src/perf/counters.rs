use crate::simulator::CommitGroupEvent;

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct PerfCounters {
    cycles: u64,
    committed_insts: u64,
}

impl PerfCounters {
    pub fn on_cycle(&mut self) {
        self.cycles += 1;
    }

    pub fn on_commit_group(&mut self, event: &CommitGroupEvent) {
        self.committed_insts += event.valid_count();
    }

    pub fn cycles(&self) -> u64 {
        self.cycles
    }

    pub fn committed_insts(&self) -> u64 {
        self.committed_insts
    }
}
