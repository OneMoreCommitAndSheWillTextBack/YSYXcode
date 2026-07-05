#![allow(dead_code)]

mod config;
mod cpu;
mod difftest;
mod ffi;
mod memory;
mod perf;
mod sdb;
mod sim_log;
mod simulator;

use config::SimulatorConfig;
use sdb::Sdb;
use simulator::{Simulator, SimulatorError};

pub type SimulatorResult<T> = Result<T, SimulatorError>;
static mut ACTIVE_SIMULATOR: *mut Simulator = std::ptr::null_mut();

fn main() {
    let config = SimulatorConfig::from_env();

    if let Err(error) = run_simulator(config) {
        eprintln!("{error:?}");
        std::process::exit(1);
    }
}

fn run_simulator(config: SimulatorConfig) -> SimulatorResult<()> {
    let batch = config.batch;
    let mut simulator = Simulator::new(config)?;

    simulator.reset()?;

    let res = if batch {
        simulator.execute(u64::MAX)
    } else {
        Sdb::new().run()?;
        Ok(())
    };

    simulator.generat_report();
    return res;
}
