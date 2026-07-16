//! Command-line configuration and all simulator defaults.
//!
//! Runtime components receive their typed configuration from this module and
//! never inspect process arguments or environment variables themselves.

use std::{
    env,
    path::{Path, PathBuf},
};

const DEFAULT_NEMU_REF: &str = concat!(env!("CARGO_MANIFEST_DIR"), "/../../difftest/nemu/ref.so");
const DEFAULT_SPIKE_REF: &str = concat!(env!("CARGO_MANIFEST_DIR"), "/../../difftest/spike/ref.so");
const DEFAULT_PMEM_BASE: u32 = 0x8000_0000;
const DEFAULT_PMEM_SIZE: usize = 512 * 1024 * 1024;
const DEFAULT_RESET_CYCLES: u32 = 30;
const DEFAULT_NO_COMMIT_CYCLES: u32 = 20_000;
const DEFAULT_DIFFTEST_PORT: i32 = 1234;

/// Complete simulator configuration assembled before runtime construction.
#[derive(Debug, Clone)]
pub(crate) struct SimulationConfig {
    pub run: RunConfig,
    pub machine: MachineConfig,
    pub driver: DriverConfig,
    pub checker: CheckerConfig,
    pub trace: TraceConfig,
}

impl Default for SimulationConfig {
    fn default() -> Self {
        Self {
            run: RunConfig::default(),
            machine: MachineConfig::default(),
            driver: DriverConfig::default(),
            checker: CheckerConfig::default(),
            trace: TraceConfig::default(),
        }
    }
}

/// Selects batch execution or the interactive runner.
#[derive(Debug, Clone, Copy, Default)]
pub(crate) struct RunConfig {
    pub batch: bool,
}

/// Host-owned platform state configuration.
#[derive(Debug, Clone)]
pub(crate) struct MachineConfig {
    pub image: Option<PathBuf>,
    pub pmem_base: u32,
    pub pmem_size: usize,
}

impl Default for MachineConfig {
    fn default() -> Self {
        Self {
            image: None,
            pmem_base: DEFAULT_PMEM_BASE,
            pmem_size: DEFAULT_PMEM_SIZE,
        }
    }
}

/// Verilator driver configuration.
#[derive(Debug, Clone, Copy)]
pub(crate) struct DriverConfig {
    pub reset_cycles: u32,
}

impl Default for DriverConfig {
    fn default() -> Self {
        Self {
            reset_cycles: DEFAULT_RESET_CYCLES,
        }
    }
}

/// Correctness checking and execution-progress configuration.
#[derive(Debug, Clone)]
pub(crate) struct CheckerConfig {
    pub difftest_ref: Option<DifftestRef>,
    pub difftest_port: i32,
    pub itrace_path: Option<PathBuf>,
    pub max_no_commit_cycles: u32,
}

impl Default for CheckerConfig {
    fn default() -> Self {
        Self {
            difftest_ref: None,
            difftest_port: DEFAULT_DIFFTEST_PORT,
            itrace_path: None,
            max_no_commit_cycles: DEFAULT_NO_COMMIT_CYCLES,
        }
    }
}

impl CheckerConfig {
    pub(crate) fn difftest_enabled(&self) -> bool {
        self.difftest_ref.is_some()
    }
}

/// Trace file configuration and tracing policy.
#[derive(Debug, Clone, Default)]
pub(crate) struct TraceConfig {
    pub path: Option<PathBuf>,
    pub mode: TraceMode,
}

/// The point at which waveform tracing becomes active.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub(crate) enum TraceMode {
    #[default]
    Disabled,
    Immediate,
    After {
        cycle: u64,
    },
    Lightsss {
        gap: u64,
        max_checkpoints: usize,
    },
}

/// Reference implementation selected for differential testing.
#[derive(Debug, Clone, PartialEq, Eq)]
pub(crate) enum DifftestRef {
    Nemu,
    Spike,
    Custom(PathBuf),
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub(crate) struct DifftestRefParseError {
    input: String,
}

impl DifftestRef {
    fn from_arg(arg: &str) -> Result<Self, DifftestRefParseError> {
        if arg.eq_ignore_ascii_case("nemu") {
            return Ok(Self::Nemu);
        }
        if arg.eq_ignore_ascii_case("spike") {
            return Ok(Self::Spike);
        }
        if looks_like_path(arg) {
            return Ok(Self::Custom(PathBuf::from(arg)));
        }

        Err(DifftestRefParseError {
            input: arg.to_owned(),
        })
    }

    pub(crate) fn path(&self) -> PathBuf {
        match self {
            Self::Nemu => PathBuf::from(DEFAULT_NEMU_REF),
            Self::Spike => PathBuf::from(DEFAULT_SPIKE_REF),
            Self::Custom(path) => path.clone(),
        }
    }
}

impl DifftestRefParseError {
    fn input(&self) -> &str {
        &self.input
    }
}

impl SimulationConfig {
    /// Parses the simulator command line once at process startup.
    pub(crate) fn from_env() -> Self {
        let mut config = Self::default();
        let mut args = env::args().skip(1);
        let mut explicit_wave = false;
        let mut wave_after = None;
        let mut lightsss_gap = None;
        let mut lightsss_max_checkpoints = None;

        while let Some(arg) = args.next() {
            match arg.as_str() {
                "-b" | "--batch" => config.run.batch = true,
                "-f" | "--file" | "--image" => {
                    config.machine.image = args.next().map(PathBuf::from);
                }
                "--reset-cycles" => {
                    config.driver.reset_cycles =
                        parse_or_keep(args.next(), config.driver.reset_cycles, "--reset-cycles");
                }
                "--max-no-commit-cycles" => {
                    config.checker.max_no_commit_cycles = parse_or_keep(
                        args.next(),
                        config.checker.max_no_commit_cycles,
                        "--max-no-commit-cycles",
                    );
                }
                "--difftest-port" => {
                    config.checker.difftest_port =
                        parse_or_keep(args.next(), config.checker.difftest_port, "--difftest-port");
                }
                "--wave" => explicit_wave = true,
                "--wave-after" => {
                    wave_after = parse_positive(args.next(), "--wave-after");
                }
                "--lightsss-gap" => {
                    lightsss_gap = parse_positive(args.next(), "--lightsss-gap");
                }
                "--lightsss-max-checkpoints" => {
                    lightsss_max_checkpoints =
                        parse_positive(args.next(), "--lightsss-max-checkpoints");
                }
                "--wave-path" => config.trace.path = args.next().map(PathBuf::from),
                "--itrace-path" => config.checker.itrace_path = args.next().map(PathBuf::from),
                "--diff" | "--difftest-ref" => {
                    parse_difftest_reference(&mut config, args.next());
                }
                _ => eprintln!("[Error] Unknown args {arg}"),
            }
        }

        config.trace.mode = resolve_trace_mode(
            explicit_wave,
            config.trace.path.is_some(),
            wave_after,
            lightsss_gap,
            lightsss_max_checkpoints,
        );
        config
    }
}

fn parse_or_keep<T>(value: Option<String>, fallback: T, option: &str) -> T
where
    T: std::str::FromStr + Copy,
{
    match value {
        Some(value) => match value.parse() {
            Ok(parsed) => parsed,
            Err(_) => {
                eprintln!("[Error] {option} expects a valid value, got `{value}`.");
                fallback
            }
        },
        None => {
            eprintln!("[Error] Missing value after {option}.");
            fallback
        }
    }
}

fn parse_positive<T>(value: Option<String>, option: &str) -> Option<T>
where
    T: std::str::FromStr + PartialOrd + From<u8> + std::fmt::Display,
{
    match value {
        Some(value) => match value.parse::<T>() {
            Ok(parsed) if parsed > T::from(0) => Some(parsed),
            _ => {
                eprintln!("[Error] {option} expects a positive integer, got `{value}`.");
                None
            }
        },
        None => {
            eprintln!("[Error] Missing value after {option}.");
            None
        }
    }
}

fn parse_difftest_reference(config: &mut SimulationConfig, value: Option<String>) {
    let Some(value) = value else {
        eprintln!("[Error] Missing value after --difftest-ref.");
        return;
    };

    match DifftestRef::from_arg(&value) {
        Ok(reference) => config.checker.difftest_ref = Some(reference),
        Err(error) => eprintln!(
            "[Error] Unknown difftest reference `{}`. Use `nemu`, `spike`, or a reference model path.",
            error.input()
        ),
    }
}

fn resolve_trace_mode(
    explicit_wave: bool,
    has_wave_path: bool,
    wave_after: Option<u64>,
    lightsss_gap: Option<u64>,
    lightsss_max_checkpoints: Option<usize>,
) -> TraceMode {
    let lightsss_requested = lightsss_gap.is_some() || lightsss_max_checkpoints.is_some();

    if explicit_wave {
        if wave_after.is_some() || lightsss_requested {
            eprintln!("[Error] --wave cannot be combined with another wave mode.");
            return TraceMode::Disabled;
        }
        return TraceMode::Immediate;
    }

    if wave_after.is_some() && lightsss_requested {
        eprintln!("[Error] Cannot use --wave-after and LightSSS at the same time.");
        return TraceMode::Disabled;
    }

    if let Some(cycle) = wave_after {
        return TraceMode::After { cycle };
    }

    if lightsss_requested {
        return match (lightsss_gap, lightsss_max_checkpoints) {
            (Some(gap), Some(max_checkpoints)) => TraceMode::Lightsss {
                gap,
                max_checkpoints,
            },
            (Some(_), None) => {
                eprintln!("[Error] --lightsss-gap requires --lightsss-max-checkpoints.");
                TraceMode::Disabled
            }
            (None, Some(_)) => {
                eprintln!("[Error] --lightsss-max-checkpoints requires --lightsss-gap.");
                TraceMode::Disabled
            }
            (None, None) => TraceMode::Disabled,
        };
    }

    if has_wave_path {
        TraceMode::Immediate
    } else {
        TraceMode::Disabled
    }
}

fn looks_like_path(arg: &str) -> bool {
    let path = Path::new(arg);
    path.is_absolute()
        || arg.starts_with("./")
        || arg.starts_with("../")
        || arg.contains('/')
        || arg.ends_with(".so")
}
