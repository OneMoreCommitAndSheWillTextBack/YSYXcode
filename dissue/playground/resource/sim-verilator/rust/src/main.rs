mod checker;
mod common;
mod config;
mod driver;
mod ffi;
mod machine;
mod sdb;
mod session;
mod sim_log;
mod wave;

use config::SimulationConfig;
use sdb::Sdb;
use session::{SimulationResult, SimulationSession};

fn main() {
    let config = SimulationConfig::from_env();

    if let Err(error) = run_simulator(config) {
        eprintln!("[Error] {}", error.display());
        std::process::exit(1);
    }
}

fn run_simulator(config: SimulationConfig) -> SimulationResult<()> {
    let batch = config.run.batch;
    let mut session = SimulationSession::new(config)?;

    session.reset()?;

    let res = if batch {
        session.execute(u64::MAX)
    } else {
        Sdb::new().run(&mut session);
        Ok(())
    };

    session.print_report();
    session.shutdown();
    res
}
