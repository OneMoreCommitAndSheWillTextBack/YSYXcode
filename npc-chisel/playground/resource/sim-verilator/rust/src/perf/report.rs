use super::PerfCounters;

#[derive(Debug, Clone, Copy, Default, PartialEq)]
pub struct PerfSnapshot {
    pub cycles: u64,
    pub committed_insts: u64,
    pub ipc: f64,
}

impl PerfSnapshot {
    pub fn from_counters(counters: &PerfCounters) -> Self {
        let cycles = counters.cycles();
        let committed_insts = counters.committed_insts();
        let ipc = if cycles == 0 {
            0.0
        } else {
            committed_insts as f64 / cycles as f64
        };

        Self {
            cycles,
            committed_insts,
            ipc,
        }
    }
}
