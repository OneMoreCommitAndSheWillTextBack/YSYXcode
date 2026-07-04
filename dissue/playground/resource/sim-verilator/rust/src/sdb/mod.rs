mod command;
mod repl;

pub use command::SdbCommand;
pub use repl::SdbRepl;

#[derive(Debug)]
pub enum SdbError {
    Exit,
}

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
