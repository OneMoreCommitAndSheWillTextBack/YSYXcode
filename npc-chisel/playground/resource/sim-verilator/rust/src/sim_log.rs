use crate::config::SimulatorConfig;
use std::fmt;

const ANSI_RESET: &str = "\x1b[0m";
const ANSI_FG_BLUE: &str = "\x1b[34m";
const ANSI_FG_GREEN: &str = "\x1b[32m";
const ANSI_FG_RED: &str = "\x1b[31m";

pub fn log(file: &str, line: u32, func: &str, args: fmt::Arguments<'_>) {
    eprintln!(
        "{}[{}:{} {}] {}{}",
        ANSI_FG_BLUE, file, line, func, args, ANSI_RESET
    );
}

#[doc(hidden)]
#[macro_export]
macro_rules! Log {
    ($($arg:tt)*) => {{
        fn __npc_log_func_marker() {}
        let full_name = std::any::type_name_of_val(&__npc_log_func_marker);
        let func_name = full_name
            .strip_suffix("::__npc_log_func_marker")
            .unwrap_or(full_name);

        $crate::sim_log::log(
            file!(),
            line!(),
            func_name,
            format_args!($($arg)*),
        );
    }};
}

pub fn show_trace(config: &SimulatorConfig) {
    crate::Log!("trace show");
    let state = |enabled| {
        if enabled {
            format!("{}ON{}", ANSI_FG_GREEN, ANSI_RESET)
        } else {
            format!("{}OFF{}", ANSI_FG_RED, ANSI_RESET)
        }
    };

    eprintln!(
        "{}trace: wave={}{} {}difftest={}{}",
        ANSI_FG_BLUE,
        ANSI_RESET,
        state(config.enable_wave),
        ANSI_FG_BLUE,
        ANSI_RESET,
        state(config.difftest_on),
    );
}
