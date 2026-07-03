#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct PerfCounters {
    cache_req_time: u64,
    cache_hit_time: u64,
}

impl PerfCounters {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn cache_hit(&mut self, hit: bool) {
        self.cache_req_time += 1;
        self.cache_hit_time += if hit { 1 } else { 0 };
    }

    pub fn cache_hit_rate(&mut self) -> f64 {
        let rate = if self.cache_req_time == 0 {
            0.0
        } else {
            self.cache_hit_time as f64 / self.cache_req_time as f64
        };

        rate
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
