#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub(super) struct Statistics {
    cycle_nocommit: u32,
    cycle: u64,
    total_commits: u64,
}

impl Statistics {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn on_cycle(&mut self) {
        self.cycle += 1;
        self.cycle_nocommit += 1;
    }

    pub fn on_commits(&mut self, commit_count: u64) {
        if commit_count == 0 {
            return;
        }

        self.cycle_nocommit = 0;
        self.total_commits += commit_count;
    }

    pub fn exceeds_no_commit_limit(&self, limit: u32) -> bool {
        self.cycle_nocommit > limit
    }

    pub fn cycle(&self) -> u64 {
        self.cycle
    }

    pub fn total_commits(&self) -> u64 {
        self.total_commits
    }
}
