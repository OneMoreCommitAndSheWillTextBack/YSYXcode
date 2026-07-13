mod command;
mod repl;

use std::fmt;

pub use command::SdbCommand;
pub use repl::SdbRepl;

#[derive(Debug)]
pub enum SdbError {
    Exit,
}

impl fmt::Display for SdbError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Exit => write!(formatter, "SDB exited"),
        }
    }
}

impl std::error::Error for SdbError {}

pub type SdbResult<T> = Result<T, SdbError>;

#[derive(Debug)]
pub struct Sdb {
    repl: SdbRepl,
}

impl Sdb {
    pub fn new() -> Self {
        Self {
            repl: SdbRepl::new(),
        }
    }

    pub fn run(&mut self) -> SdbResult<()> {
        self.repl.run()
    }
}
