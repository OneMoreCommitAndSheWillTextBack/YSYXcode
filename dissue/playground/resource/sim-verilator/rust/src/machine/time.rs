use std::time::Instant;

/// Host clock origin for the legacy time DPI service.
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

    pub(super) fn elapsed_micros(&self) -> u64 {
        self.boot_time.elapsed().as_micros() as u64
    }
}
