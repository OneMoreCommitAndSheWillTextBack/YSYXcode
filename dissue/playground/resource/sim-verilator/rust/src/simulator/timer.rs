use super::Simulator;
use std::time::Instant;

#[derive(Debug)]
pub(super) struct SimTimer {
    boot_time: Instant,
}

impl SimTimer {
    pub(super) fn new() -> Self {
        Self {
            boot_time: Instant::now(),
        }
    }

    fn elapsed_micros(&self) -> u64 {
        self.boot_time.elapsed().as_micros() as u64
    }
}

impl Simulator {
    pub(super) fn time_read(&self) -> u64 {
        self.timer.as_ref().map_or(0, SimTimer::elapsed_micros)
    }
}
