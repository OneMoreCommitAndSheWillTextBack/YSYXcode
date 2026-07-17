#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct PerfCounters {
    frontend_events: [u64; Self::FRONTEND_EVENT_COUNT],
    iq_sample_cycles: u64,
    iq_issue_count: u64,
    iq_dual_issue_cycles: u64,
    iq_block_ready_cycles: u64,
    iq_block_operand_cycles: u64,
    iq_occupancy_sum: u64,
    div_operations: u64,
    div_cycles: u64,
    div_special_operations: u64,
    bpu_predictions: u64,
    bpu_correct_predictions: u64,
    mem_events: [u64; Self::MEM_EVENT_COUNT],
    mem_sample_cycles: u64,
    mshr_occupancy_sum: u64,
    store_queue_occupancy_sum: u64,
    load_txn_occupancy_sum: u64,
}

impl PerfCounters {
    pub const DCACHE_ACCESS: usize = 0;
    pub const DCACHE_HIT: usize = 1;
    pub const DCACHE_MISS: usize = 2;
    pub const DCACHE_BYPASS: usize = 3;
    pub const MSHR_ALLOC: usize = 4;
    pub const MSHR_MERGE: usize = 5;
    pub const MSHR_FULL_STALL_CYCLE: usize = 6;
    pub const HIT_UNDER_MISS: usize = 7;
    pub const QUEUED_MISS: usize = 8;
    pub const REFILL_START: usize = 9;
    pub const REFILL_COMPLETE: usize = 10;
    pub const REFILL_FAULT: usize = 11;
    pub const LOAD_TXN_FULL_STALL_CYCLE: usize = 12;
    pub const STORE_QUEUE_ALLOC: usize = 13;
    pub const STORE_QUEUE_FULL_STALL_CYCLE: usize = 14;
    pub const FORWARD_FULL: usize = 15;
    pub const FORWARD_PARTIAL: usize = 16;
    pub const FORWARD_UNRESOLVED_STALL_CYCLE: usize = 17;
    pub const STORE_DRAIN: usize = 18;
    pub const MEM_EVENT_COUNT: usize = 19;

    pub const ICACHE_REQUEST: usize = 0;
    pub const ICACHE_HIT: usize = 1;
    pub const ICACHE_MISS: usize = 2;
    pub const ICACHE_MISS_WAIT_CYCLE: usize = 3;
    pub const BACKEND_REDIRECT: usize = 4;
    pub const ICACHE_INVALIDATE: usize = 5;
    pub const FRONTEND_EMPTY: usize = 6;
    pub const AXI_REQUEST_WAIT: usize = 7;
    pub const FRONTEND_EVENT_COUNT: usize = 8;

    pub fn frontend_perf(&mut self, events: u32) {
        for index in 0..Self::FRONTEND_EVENT_COUNT {
            if (events & (1_u32 << index)) != 0 {
                self.frontend_events[index] += 1;
            }
        }
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

    pub fn bpu_prediction(&mut self, correct: bool) {
        self.bpu_predictions += 1;
        self.bpu_correct_predictions += if correct { 1 } else { 0 };
    }

    pub fn mem_perf(
        &mut self,
        events: u32,
        mshr_occupancy: u32,
        store_queue_occupancy: u32,
        load_txn_occupancy: u32,
    ) {
        self.mem_sample_cycles += 1;
        self.mshr_occupancy_sum += u64::from(mshr_occupancy);
        self.store_queue_occupancy_sum += u64::from(store_queue_occupancy);
        self.load_txn_occupancy_sum += u64::from(load_txn_occupancy);

        for index in 0..Self::MEM_EVENT_COUNT {
            if (events & (1_u32 << index)) != 0 {
                self.mem_events[index] += 1;
            }
        }
    }

    pub fn icache_hit_rate(&self) -> f64 {
        let requests = self.frontend_event(Self::ICACHE_REQUEST);
        if requests == 0 {
            0.0
        } else {
            self.frontend_event(Self::ICACHE_HIT) as f64 / requests as f64
        }
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

    pub fn bpu_predictions(&self) -> u64 {
        self.bpu_predictions
    }

    pub fn bpu_correct_predictions(&self) -> u64 {
        self.bpu_correct_predictions
    }

    pub fn bpu_accuracy(&self) -> f64 {
        if self.bpu_predictions == 0 {
            0.0
        } else {
            self.bpu_correct_predictions as f64 / self.bpu_predictions as f64
        }
    }

    pub fn mem_event(&self, index: usize) -> u64 {
        self.mem_events[index]
    }

    pub fn frontend_event(&self, index: usize) -> u64 {
        self.frontend_events[index]
    }

    pub fn dcache_hit_rate(&self) -> f64 {
        let requests = self.mem_event(Self::DCACHE_HIT) + self.mem_event(Self::DCACHE_MISS);
        if requests == 0 {
            0.0
        } else {
            self.mem_event(Self::DCACHE_HIT) as f64 / requests as f64
        }
    }

    pub fn average_mshr_occupancy(&self) -> f64 {
        self.average_occupancy(self.mshr_occupancy_sum)
    }

    pub fn average_store_queue_occupancy(&self) -> f64 {
        self.average_occupancy(self.store_queue_occupancy_sum)
    }

    pub fn average_load_txn_occupancy(&self) -> f64 {
        self.average_occupancy(self.load_txn_occupancy_sum)
    }

    fn average_occupancy(&self, sum: u64) -> f64 {
        if self.mem_sample_cycles == 0 {
            0.0
        } else {
            sum as f64 / self.mem_sample_cycles as f64
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
