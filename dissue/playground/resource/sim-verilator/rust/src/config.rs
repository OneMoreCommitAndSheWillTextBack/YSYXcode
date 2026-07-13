use std::{
    env,
    path::{Path, PathBuf},
};

const DEFAULT_NEMU_REF: &str = concat!(env!("CARGO_MANIFEST_DIR"), "/../../difftest/nemu/ref.so");
const DEFAULT_SPIKE_REF: &str = concat!(env!("CARGO_MANIFEST_DIR"), "/../../difftest/spike/ref.so");

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum DifftestRef {
    Nemu,
    Spike,
    Custom(PathBuf),
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct DifftestRefParseError {
    input: String,
}

impl DifftestRef {
    pub fn from_arg(arg: &str) -> Result<Self, DifftestRefParseError> {
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
            input: arg.to_string(),
        })
    }

    pub fn path(&self) -> PathBuf {
        match self {
            Self::Nemu => PathBuf::from(DEFAULT_NEMU_REF),
            Self::Spike => PathBuf::from(DEFAULT_SPIKE_REF),
            Self::Custom(path) => path.clone(),
        }
    }
}

impl DifftestRefParseError {
    pub fn input(&self) -> &str {
        &self.input
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

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum WaveMode {
    Disabled,
    Immediate,
    After { cycle: u64 },
    Lightsss { gap: u64, max_checkpoints: usize },
}

impl Default for WaveMode {
    fn default() -> Self {
        Self::Disabled
    }
}

#[derive(Debug, Clone, Default)]
pub struct WaveConfig {
    pub path: Option<PathBuf>,
    pub mode: WaveMode,
}

#[derive(Debug, Clone)]
pub struct SimulatorConfig {
    pub batch: bool,
    pub image: Option<PathBuf>,
    pub reset_cycles: u32,
    pub itrace_path: Option<PathBuf>,
    pub difftest_on: bool,
    pub difftest_ref: Option<DifftestRef>,
    pub wave_config: WaveConfig,
}

impl Default for SimulatorConfig {
    fn default() -> Self {
        Self {
            batch: false,
            image: None,
            reset_cycles: 30,
            itrace_path: None,
            difftest_on: false,
            difftest_ref: None,
            wave_config: WaveConfig::default(),
        }
    }
}

impl SimulatorConfig {
    pub fn from_env() -> Self {
        let mut config = Self::default();
        let mut args = env::args().skip(1);
        let mut explicit_wave = false;
        let mut wave_after = None;
        let mut lightsss_gap = None;
        let mut lightsss_max_checkpoints = None;

        while let Some(arg) = args.next() {
            match arg.as_str() {
                "-b" | "--batch" => config.batch = true,
                "-f" | "--file" | "--image" => {
                    config.image = args.next().map(PathBuf::from);
                }
                "--reset-cycles" => {
                    if let Some(value) = args.next() {
                        config.reset_cycles = value.parse().unwrap_or(config.reset_cycles);
                    }
                }
                "--wave" => {
                    explicit_wave = true;
                }
                "--wave-after" => match args.next() {
                    Some(value) => match value.parse::<u64>() {
                        Ok(after_cycle) if after_cycle > 0 => {
                            wave_after = Some(after_cycle);
                        }
                        _ => {
                            eprintln!(
                                "[Error] --wave-after expects a positive integer, got `{}`.",
                                value
                            );
                        }
                    },
                    None => {
                        eprintln!("[Error] Missing value after {}", arg);
                    }
                },
                "--lightsss-gap" => match args.next() {
                    Some(value) => match value.parse::<u64>() {
                        Ok(gap) if gap > 0 => {
                            lightsss_gap = Some(gap);
                        }
                        _ => {
                            eprintln!(
                                "[Error] --lightsss-gap expects a positive integer, got `{}`.",
                                value
                            );
                        }
                    },
                    None => {
                        eprintln!("[Error] Missing value after {}", arg);
                    }
                },
                "--lightsss-max-checkpoints" => match args.next() {
                    Some(value) => match value.parse::<usize>() {
                        Ok(max_checkpoints) if max_checkpoints > 0 => {
                            lightsss_max_checkpoints = Some(max_checkpoints);
                        }
                        _ => {
                            eprintln!(
                                "[Error] --lightsss-max-checkpoints expects a positive integer, got `{}`.",
                                value
                            );
                        }
                    },
                    None => {
                        eprintln!("[Error] Missing value after {}", arg);
                    }
                },
                "--wave-path" => {
                    config.wave_config.path = args.next().map(PathBuf::from);
                }
                "--itrace-path" => {
                    config.itrace_path = args.next().map(PathBuf::from);
                }
                "--diff" | "--difftest-ref" => {
                    if let Some(value) = args.next() {
                        match DifftestRef::from_arg(&value) {
                            Ok(reference) => {
                                config.difftest_on = true;
                                config.difftest_ref = Some(reference);
                            }
                            Err(error) => {
                                eprintln!(
                                    "[Error] Unknown difftest reference `{}`. Use `nemu`, `spike`, or a reference model path.",
                                    error.input()
                                );
                            }
                        }
                    } else {
                        eprintln!("[Error] Missing value after {}", arg);
                    }
                }
                _ => {
                    eprintln!("[Error] Unknown args {}", arg.as_str());
                }
            }
        }

        config.wave_config.mode = resolve_wave_mode(
            explicit_wave,
            config.wave_config.path.is_some(),
            wave_after,
            lightsss_gap,
            lightsss_max_checkpoints,
        );

        config
    }
}

fn resolve_wave_mode(
    explicit_wave: bool,
    has_wave_path: bool,
    wave_after: Option<u64>,
    lightsss_gap: Option<u64>,
    lightsss_max_checkpoints: Option<usize>,
) -> WaveMode {
    let lightsss_requested = lightsss_gap.is_some() || lightsss_max_checkpoints.is_some();

    if explicit_wave {
        if wave_after.is_some() || lightsss_requested {
            eprintln!("[Error] --wave cannot be combined with another wave mode.");
            return WaveMode::Disabled;
        }
        return WaveMode::Immediate;
    }

    if wave_after.is_some() && lightsss_requested {
        eprintln!("[Error] Cannot use --wave-after and lightsss at the same time.");
        return WaveMode::Disabled;
    }

    if let Some(cycle) = wave_after {
        return WaveMode::After { cycle };
    }

    if lightsss_requested {
        return match (lightsss_gap, lightsss_max_checkpoints) {
            (Some(gap), Some(max_checkpoints)) => WaveMode::Lightsss {
                gap,
                max_checkpoints,
            },
            (Some(_), None) => {
                eprintln!("[Error] --lightsss-gap requires --lightsss-max-checkpoints.");
                WaveMode::Disabled
            }
            (None, Some(_)) => {
                eprintln!("[Error] --lightsss-max-checkpoints requires --lightsss-gap.");
                WaveMode::Disabled
            }
            (None, None) => WaveMode::Disabled,
        };
    }

    if has_wave_path {
        WaveMode::Immediate
    } else {
        WaveMode::Disabled
    }
}
