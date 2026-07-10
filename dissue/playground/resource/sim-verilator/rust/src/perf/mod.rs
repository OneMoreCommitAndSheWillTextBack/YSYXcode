mod counters;

pub use counters::PerfCounters;

#[derive(Debug, Default)]
pub struct Perf {
    counters: PerfCounters,
}

impl Perf {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn cachehit(&mut self, hit: bool) {
        self.counters.cache_hit(hit);
    }

    pub fn issue_queue_perf(
        &mut self,
        issue_count: u8,
        occupancy: u8,
        block_ready: bool,
        block_operand: bool,
    ) {
        self.counters
            .issue_queue_perf(issue_count, occupancy, block_ready, block_operand);
    }

    pub fn div_perf(&mut self, cycles: u32, special: bool) {
        self.counters.div_perf(cycles, special);
    }

    pub fn bpu_prediction(&mut self, correct: bool) {
        self.counters.bpu_prediction(correct);
    }

    pub fn cacherate(&mut self) -> f64 {
        self.counters.cache_hit_rate()
    }

    pub fn issue_queue_sample_cycles(&self) -> u64 {
        self.counters.issue_queue_sample_cycles()
    }

    pub fn issue_queue_issue_count(&self) -> u64 {
        self.counters.issue_queue_issue_count()
    }

    pub fn issue_queue_issue_rate(&self) -> f64 {
        self.counters.issue_queue_issue_rate()
    }

    pub fn issue_queue_dual_issue_cycles(&self) -> u64 {
        self.counters.issue_queue_dual_issue_cycles()
    }

    pub fn issue_queue_block_ready_cycles(&self) -> u64 {
        self.counters.issue_queue_block_ready_cycles()
    }

    pub fn issue_queue_block_operand_cycles(&self) -> u64 {
        self.counters.issue_queue_block_operand_cycles()
    }

    pub fn issue_queue_average_occupancy(&self) -> f64 {
        self.counters.issue_queue_average_occupancy()
    }

    pub fn div_operations(&self) -> u64 {
        self.counters.div_operations()
    }

    pub fn div_cycles(&self) -> u64 {
        self.counters.div_cycles()
    }

    pub fn div_special_operations(&self) -> u64 {
        self.counters.div_special_operations()
    }

    pub fn div_average_cycles(&self) -> f64 {
        self.counters.div_average_cycles()
    }

    pub fn bpu_predictions(&self) -> u64 {
        self.counters.bpu_predictions()
    }

    pub fn bpu_correct_predictions(&self) -> u64 {
        self.counters.bpu_correct_predictions()
    }

    pub fn bpu_accuracy(&self) -> f64 {
        self.counters.bpu_accuracy()
    }

    pub fn on_cycle(&mut self) {}
}
