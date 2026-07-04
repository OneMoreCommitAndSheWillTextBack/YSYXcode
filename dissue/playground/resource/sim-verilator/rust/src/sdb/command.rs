#[derive(Debug, Clone, PartialEq, Eq)]
pub enum SdbCommand {
    Continue,
    Step(u64),
    InfoRegisters,
    Examine { addr: u64, len: usize },
    Quit,
    Empty,
}
