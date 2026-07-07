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

#[derive(Debug, Clone)]
pub struct SimulatorConfig {
    pub batch: bool,
    pub image: Option<PathBuf>,
    pub reset_cycles: u32,
    pub enable_wave: bool,
    pub wave_path: Option<PathBuf>,
    pub itrace_path: Option<PathBuf>,
    pub difftest_on: bool,
    pub difftest_ref: Option<DifftestRef>,
}

impl Default for SimulatorConfig {
    fn default() -> Self {
        Self {
            batch: false,
            image: None,
            reset_cycles: 30,
            enable_wave: false,
            wave_path: None,
            itrace_path: None,
            difftest_on: false,
            difftest_ref: None,
        }
    }
}

impl SimulatorConfig {
    pub fn from_env() -> Self {
        let mut config = Self::default();
        let mut args = env::args().skip(1);

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
                    config.enable_wave = true;
                }
                "--wave-path" => {
                    config.enable_wave = true;
                    config.wave_path = args.next().map(PathBuf::from);
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

        config
    }
}
