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

    pub fn cacherate(&mut self) -> f64 {
        self.counters.cache_hit_rate()
    }

    pub fn on_cycle(&mut self) {}
}
