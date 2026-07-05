use std::path::PathBuf;

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct WaveConfig {
    pub enabled: bool,
    pub opened: bool,
    pub path: Option<PathBuf>,
}
