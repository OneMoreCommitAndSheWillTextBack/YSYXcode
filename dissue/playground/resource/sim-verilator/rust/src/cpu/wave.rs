use crate::config::WaveMode;
use std::path::PathBuf;

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct WaveConfig {
    pub enabled: bool,
    pub opened: bool,
    pub path: Option<PathBuf>,
    pub mode: WaveMode,
}

impl From<&crate::config::WaveConfig> for WaveConfig {
    fn from(config: &crate::config::WaveConfig) -> Self {
        Self {
            path: config.path.clone(),
            mode: config.mode,
            ..Self::default()
        }
    }
}
