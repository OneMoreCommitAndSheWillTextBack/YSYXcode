#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct PerfCounters {
    cache_req_time: u64,
    cache_hit_time: u64,
    iq_sample_cycles: u64,
    iq_issue_count: u64,
    iq_dual_issue_cycles: u64,
    iq_block_ready_cycles: u64,
    iq_block_operand_cycles: u64,
    iq_occupancy_sum: u64,
    div_operations: u64,
    div_cycles: u64,
    div_special_operations: u64,
}

impl PerfCounters {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn cache_hit(&mut self, hit: bool) {
        self.cache_req_time += 1;
        self.cache_hit_time += if hit { 1 } else { 0 };
    }

    pub fn issue_queue_perf(
        &mut self,
        issue_count: u8,
        occupancy: u8,
        block_ready: bool,
        block_operand: bool,
    ) {
        self.iq_sample_cycles += 1;
        self.iq_issue_count += u64::from(issue_count);
        self.iq_occupancy_sum += u64::from(occupancy);

        if issue_count >= 2 {
            self.iq_dual_issue_cycles += 1;
        }

        if block_ready {
            self.iq_block_ready_cycles += 1;
        } else if block_operand {
            self.iq_block_operand_cycles += 1;
        }
    }

    pub fn div_perf(&mut self, cycles: u32, special: bool) {
        self.div_operations += 1;
        self.div_cycles += u64::from(cycles);

        if special {
            self.div_special_operations += 1;
        }
    }

    pub fn cache_hit_rate(&mut self) -> f64 {
        let rate = if self.cache_req_time == 0 {
            0.0
        } else {
            self.cache_hit_time as f64 / self.cache_req_time as f64
        };

        rate
    }

    pub fn issue_queue_sample_cycles(&self) -> u64 {
        self.iq_sample_cycles
    }

    pub fn issue_queue_issue_count(&self) -> u64 {
        self.iq_issue_count
    }

    pub fn issue_queue_dual_issue_cycles(&self) -> u64 {
        self.iq_dual_issue_cycles
    }

    pub fn issue_queue_block_ready_cycles(&self) -> u64 {
        self.iq_block_ready_cycles
    }

    pub fn issue_queue_block_operand_cycles(&self) -> u64 {
        self.iq_block_operand_cycles
    }

    pub fn issue_queue_average_occupancy(&self) -> f64 {
        if self.iq_sample_cycles == 0 {
            0.0
        } else {
            self.iq_occupancy_sum as f64 / self.iq_sample_cycles as f64
        }
    }

    pub fn issue_queue_issue_rate(&self) -> f64 {
        if self.iq_sample_cycles == 0 {
            0.0
        } else {
            self.iq_issue_count as f64 / self.iq_sample_cycles as f64
        }
    }

    pub fn div_operations(&self) -> u64 {
        self.div_operations
    }

    pub fn div_cycles(&self) -> u64 {
        self.div_cycles
    }

    pub fn div_special_operations(&self) -> u64 {
        self.div_special_operations
    }

    pub fn div_average_cycles(&self) -> f64 {
        if self.div_operations == 0 {
            0.0
        } else {
            self.div_cycles as f64 / self.div_operations as f64
        }
    }

    pub fn calc_dpi(commits: u64, cycles: u64) -> f64 {
        let ipc = if cycles == 0 {
            0.0
        } else {
            commits as f64 / cycles as f64
        };

        ipc
    }
}
