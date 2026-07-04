use super::{SdbCommand, SdbResult};

#[derive(Debug, Default)]
pub struct SdbRepl {
    last_command: Option<SdbCommand>,
}

impl SdbRepl {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn run(&mut self) -> SdbResult<()> {
        self.last_command = Some(SdbCommand::Empty);
        Ok(())
    }
}
