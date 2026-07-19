#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum BpuCfiClass {
    Branch = 0,
    Jal = 1,
    Jalr = 2,
    Return = 3,
}

impl BpuCfiClass {
    pub const COUNT: usize = 4;

    pub const fn label(self) -> &'static str {
        match self {
            Self::Branch => "branch",
            Self::Jal => "jal",
            Self::Jalr => "jalr",
            Self::Return => "return-like",
        }
    }

    pub fn from_dpi(value: u8) -> Option<Self> {
        match value {
            0 => Some(Self::Branch),
            1 => Some(Self::Jal),
            2 => Some(Self::Jalr),
            3 => Some(Self::Return),
            _ => None,
        }
    }

    const fn index(self) -> usize {
        self as usize
    }
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct BpuCfiCounters {
    total: u64,
    correct: u64,
    pred_hit: u64,
    no_prediction: u64,
    taken_no_prediction: u64,
    direction_miss: u64,
    target_miss: u64,
}

impl BpuCfiCounters {
    pub fn total(self) -> u64 {
        self.total
    }

    pub fn correct(self) -> u64 {
        self.correct
    }

    pub fn misses(self) -> u64 {
        self.total - self.correct
    }

    pub fn accuracy(self) -> f64 {
        if self.total == 0 {
            0.0
        } else {
            self.correct as f64 / self.total as f64
        }
    }

    pub fn pred_hit(self) -> u64 {
        self.pred_hit
    }

    pub fn no_prediction(self) -> u64 {
        self.no_prediction
    }

    pub fn taken_no_prediction(self) -> u64 {
        self.taken_no_prediction
    }

    pub fn direction_miss(self) -> u64 {
        self.direction_miss
    }

    pub fn target_miss(self) -> u64 {
        self.target_miss
    }
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct PerfCounters {
    frontend_events: [u64; Self::FRONTEND_EVENT_COUNT],
    fetch_queue_sample_cycles: u64,
    fetch_queue_occupancy_sum: u64,
    fetch_queue_enqueue_width_total: u64,
    fetch_queue_dequeue_width_total: u64,
    fetch_queue_miss_start_samples: u64,
    fetch_queue_miss_start_occupancy_sum: u64,
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
    bpu_cfi: [BpuCfiCounters; BpuCfiClass::COUNT],
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
    pub const FETCH_QUEUE_EMPTY_WITH_BACKEND_READY: usize = 8;
    pub const FETCH_QUEUE_FULL: usize = 9;
    pub const ICACHE_MSHR_ACTIVE_CYCLE: usize = 10;
    pub const ICACHE_HIT_UNDER_MISS: usize = 11;
    pub const ICACHE_SAME_LINE_WAIT_CYCLE: usize = 12;
    pub const ICACHE_QUEUED_MISS: usize = 13;
    pub const REDIRECT_DURING_MSHR: usize = 14;
    pub const REDIRECT_DURING_MSHR_TARGET_HIT: usize = 15;
    pub const STALE_RESPONSE_DROP: usize = 16;
    pub const RAS_PUSH: usize = 17;
    pub const RAS_POP: usize = 18;
    pub const RAS_POP_THEN_PUSH: usize = 19;
    pub const RAS_USE: usize = 20;
    pub const RAS_HIT: usize = 21;
    pub const RAS_MISS: usize = 22;
    pub const RAS_UNDERFLOW: usize = 23;
    pub const RAS_OVERFLOW: usize = 24;
    pub const RAS_CHECKPOINT_RESTORE: usize = 25;
    pub const RAS_RECOVERY_DISCARD: usize = 26;
    pub const FRONTEND_EVENT_COUNT: usize = 27;

    pub fn frontend_perf(
        &mut self,
        events: u32,
        fetch_queue_occupancy: u32,
        fetch_queue_enqueue_width: u32,
        fetch_queue_dequeue_width: u32,
    ) {
        self.fetch_queue_sample_cycles += 1;
        self.fetch_queue_occupancy_sum += u64::from(fetch_queue_occupancy);
        self.fetch_queue_enqueue_width_total += u64::from(fetch_queue_enqueue_width);
        self.fetch_queue_dequeue_width_total += u64::from(fetch_queue_dequeue_width);

        if (events & (1_u32 << Self::ICACHE_MISS)) != 0 {
            self.fetch_queue_miss_start_samples += 1;
            self.fetch_queue_miss_start_occupancy_sum += u64::from(fetch_queue_occupancy);
        }

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

    pub fn bpu_prediction(
        &mut self,
        cfi_class: u8,
        pred_hit: bool,
        pred_taken: bool,
        actual_taken: bool,
        correct: bool,
    ) {
        self.bpu_predictions += 1;
        self.bpu_correct_predictions += if correct { 1 } else { 0 };

        let Some(cfi_class) = BpuCfiClass::from_dpi(cfi_class) else {
            return;
        };
        let counters = &mut self.bpu_cfi[cfi_class.index()];
        counters.total += 1;
        counters.correct += if correct { 1 } else { 0 };
        counters.pred_hit += if pred_hit { 1 } else { 0 };
        counters.no_prediction += if pred_hit { 0 } else { 1 };
        counters.taken_no_prediction += if !pred_hit && actual_taken { 1 } else { 0 };

        if cfi_class == BpuCfiClass::Branch {
            counters.direction_miss += if pred_hit && pred_taken != actual_taken {
                1
            } else {
                0
            };
            counters.target_miss += if pred_hit && pred_taken && actual_taken && !correct {
                1
            } else {
                0
            };
        } else {
            counters.target_miss += if pred_hit && !correct { 1 } else { 0 };
        }
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

    pub fn bpu_cfi(&self, class: BpuCfiClass) -> BpuCfiCounters {
        self.bpu_cfi[class.index()]
    }

    pub fn mem_event(&self, index: usize) -> u64 {
        self.mem_events[index]
    }

    pub fn frontend_event(&self, index: usize) -> u64 {
        self.frontend_events[index]
    }

    pub fn fetch_queue_sample_cycles(&self) -> u64 {
        self.fetch_queue_sample_cycles
    }

    pub fn fetch_queue_average_occupancy(&self) -> f64 {
        if self.fetch_queue_sample_cycles == 0 {
            0.0
        } else {
            self.fetch_queue_occupancy_sum as f64 / self.fetch_queue_sample_cycles as f64
        }
    }

    pub fn fetch_queue_true_starvation_cycles(&self) -> u64 {
        self.frontend_event(Self::FETCH_QUEUE_EMPTY_WITH_BACKEND_READY)
    }

    pub fn fetch_queue_full_cycles(&self) -> u64 {
        self.frontend_event(Self::FETCH_QUEUE_FULL)
    }

    pub fn fetch_queue_enqueue_width_total(&self) -> u64 {
        self.fetch_queue_enqueue_width_total
    }

    pub fn fetch_queue_dequeue_width_total(&self) -> u64 {
        self.fetch_queue_dequeue_width_total
    }

    pub fn fetch_queue_average_miss_start_occupancy(&self) -> f64 {
        if self.fetch_queue_miss_start_samples == 0 {
            0.0
        } else {
            self.fetch_queue_miss_start_occupancy_sum as f64
                / self.fetch_queue_miss_start_samples as f64
        }
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

#[cfg(test)]
mod tests {
    use super::{BpuCfiClass, PerfCounters};

    #[test]
    fn bpu_cfi_breakdown_tracks_prediction_causes() {
        let mut counters = PerfCounters::default();

        counters.bpu_prediction(BpuCfiClass::Branch as u8, true, false, true, false);
        counters.bpu_prediction(BpuCfiClass::Branch as u8, false, false, true, false);
        counters.bpu_prediction(BpuCfiClass::Branch as u8, true, true, true, false);
        counters.bpu_prediction(BpuCfiClass::Jal as u8, false, false, true, false);
        counters.bpu_prediction(BpuCfiClass::Jalr as u8, true, true, true, false);
        counters.bpu_prediction(BpuCfiClass::Return as u8, true, true, true, true);

        let branch = counters.bpu_cfi(BpuCfiClass::Branch);
        assert_eq!(branch.total(), 3);
        assert_eq!(branch.direction_miss(), 1);
        assert_eq!(branch.taken_no_prediction(), 1);
        assert_eq!(branch.target_miss(), 1);
        assert_eq!(branch.misses(), 3);

        let jal = counters.bpu_cfi(BpuCfiClass::Jal);
        assert_eq!(jal.total(), 1);
        assert_eq!(jal.taken_no_prediction(), 1);

        let jalr = counters.bpu_cfi(BpuCfiClass::Jalr);
        assert_eq!(jalr.total(), 1);
        assert_eq!(jalr.target_miss(), 1);

        let ret = counters.bpu_cfi(BpuCfiClass::Return);
        assert_eq!(ret.total(), 1);
        assert_eq!(ret.correct(), 1);

        assert_eq!(counters.bpu_predictions(), 6);
        assert_eq!(counters.bpu_correct_predictions(), 1);
    }
}
