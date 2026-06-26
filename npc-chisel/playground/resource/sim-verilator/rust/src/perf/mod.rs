mod counters;
mod report;

pub use counters::PerfCounters;
pub use report::PerfSnapshot;

use crate::simulator::CommitEvent;

#[derive(Debug, Default)]
pub struct Perf {
    counters: PerfCounters,
}

impl Perf {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn on_cycle(&mut self) {
        self.counters.on_cycle();
    }

    pub fn on_commit(&mut self, event: &CommitEvent) {
        self.counters.on_commit(event);
    }

    pub fn counters(&self) -> &PerfCounters {
        &self.counters
    }

    pub fn snapshot(&self) -> PerfSnapshot {
        PerfSnapshot::from_counters(&self.counters)
    }
}
