#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct CommitSignals {
    pub valid: bool,
    pub pc: u32,
    pub inst: u32,
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct CpuSignals {
    pub reset: bool,
    pub interrupt: bool,
    pub current_pc: u32,
    pub commit: CommitSignals,
}
