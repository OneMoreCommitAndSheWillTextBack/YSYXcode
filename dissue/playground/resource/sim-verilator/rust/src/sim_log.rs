use crate::config::{SimulationConfig, TraceMode};
use std::fmt;
use std::panic::Location;

pub(crate) const ANSI_RESET: &str = "\x1b[0m";
const ANSI_FG_BLUE: &str = "\x1b[34m";
pub(crate) const ANSI_FG_GREEN: &str = "\x1b[32m";
pub(crate) const ANSI_FG_RED: &str = "\x1b[31m";
const ANSI_FG_ORANGE: &str = "\x1b[38;5;208m";

#[track_caller]
pub fn log(args: fmt::Arguments<'_>) {
    let caller = Location::caller();
    eprintln!(
        "{}[{}:{}] {}{}",
        ANSI_FG_BLUE,
        caller.file(),
        caller.line(),
        args,
        ANSI_RESET
    );
}

#[track_caller]
pub fn log_error(args: fmt::Arguments<'_>) {
    let caller = Location::caller();
    eprintln!(
        "{}[{}:{}] {}{}",
        ANSI_FG_ORANGE,
        caller.file(),
        caller.line(),
        args,
        ANSI_RESET
    );
}

#[doc(hidden)]
#[macro_export]
macro_rules! Log {
    ($($arg:tt)*) => {{
        $crate::sim_log::log(format_args!($($arg)*));
    }};
}

#[doc(hidden)]
#[macro_export]
macro_rules! LogError {
    ($($arg:tt)*) => {{
        $crate::sim_log::log_error(format_args!($($arg)*));
    }};
}

pub fn show_trace(config: &SimulationConfig) {
    crate::Log!("trace show");
    let state = |enabled| {
        if enabled {
            format!("{}ON{}", ANSI_FG_GREEN, ANSI_RESET)
        } else {
            format!("{}OFF{}", ANSI_FG_RED, ANSI_RESET)
        }
    };
    let wave_state = match config.trace.mode {
        TraceMode::Disabled => state(false),
        TraceMode::Immediate => state(true),
        TraceMode::After { cycle } => format!("{}AFTER({cycle}){}", ANSI_FG_GREEN, ANSI_RESET),
        TraceMode::Lightsss {
            gap,
            max_checkpoints,
        } => format!(
            "{}LIGHTSSS(gap={gap}, checkpoints={max_checkpoints}){}",
            ANSI_FG_GREEN, ANSI_RESET
        ),
    };
    let detailed_state = config
        .checker
        .detailed_trace_path
        .as_ref()
        .map(|path| format!("{}{}{}", ANSI_FG_GREEN, path.display(), ANSI_RESET))
        .unwrap_or_else(|| state(false));
    let kanata_state = config
        .checker
        .kanata_path
        .as_ref()
        .map(|path| format!("{}{}{}", ANSI_FG_GREEN, path.display(), ANSI_RESET))
        .unwrap_or_else(|| state(false));

    eprintln!(
        "{}trace: wave={}{} {}itrace={}{} {}detailed={}{} {}kanata={}{} {}difftest={}{}",
        ANSI_FG_BLUE,
        ANSI_RESET,
        wave_state,
        ANSI_FG_BLUE,
        ANSI_RESET,
        state(config.checker.itrace_path.is_some()),
        ANSI_FG_BLUE,
        ANSI_RESET,
        detailed_state,
        ANSI_FG_BLUE,
        ANSI_RESET,
        kanata_state,
        ANSI_FG_BLUE,
        ANSI_RESET,
        state(config.checker.difftest_enabled()),
    );
}
