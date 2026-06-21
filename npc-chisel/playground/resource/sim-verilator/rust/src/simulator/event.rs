#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct CommitEvent {
    pub valid: bool,
    pub pc: u32,
    pub inst: u32,
}

impl CommitEvent {
    pub fn new(valid: bool, pc: u32, inst: u32) -> Self {
        Self { valid, pc, inst }
    }
}
