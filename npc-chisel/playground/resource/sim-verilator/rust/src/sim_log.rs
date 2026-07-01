use crate::config::SimulatorConfig;
use std::fmt;

const ANSI_RESET: &str = "\x1b[0m";
const ANSI_BOLD: &str = "\x1b[1m";
const ANSI_DIM: &str = "\x1b[2m";
const ANSI_FG_BLUE: &str = "\x1b[34m";
const ANSI_FG_GREEN: &str = "\x1b[32m";
const ANSI_FG_RED: &str = "\x1b[31m";

pub fn log(file: &str, line: u32, func: &str, args: fmt::Arguments<'_>) {
    println!(
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
            format!("{}OPEN{}", ANSI_FG_GREEN, ANSI_RESET)
        } else {
            format!("{}CLOSED{}", ANSI_FG_RED, ANSI_RESET)
        }
    };

    println!(
        "{}+---------------------- trace status ----------------------+{}",
        ANSI_BOLD, ANSI_RESET
    );
    println!("  {:<12}  {:<18}  {}", "trace", "state", "detail");
    println!(
        "  {}",
        "----------------------------------------------------------"
    );

    println!(
        "  {:<12}  {:<18}  {}",
        "wave",
        state(config.enable_wave),
        format!(
            "path: {}",
            config
                .wave_path
                .as_deref()
                .map(|path| path.display().to_string())
                .unwrap_or_else(|| "wave.vcd".to_string())
        ),
    );
    println!(
        "  {:<12}  {:<18}  {}",
        "difftest",
        state(config.difftest_on),
        config
            .difftest_ref
            .as_ref()
            .map(|reference| format!("ref: {}", reference.path().display()))
            .unwrap_or_else(|| "reference disabled".to_string()),
    );

    println!(
        "{}+----------------------------------------------------------+{}",
        ANSI_DIM, ANSI_RESET
    );
}
