use crate::config::WaveMode;
use std::path::PathBuf;

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct WaveSession {
    pub enabled: bool,
    pub opened: bool,
    pub path: Option<PathBuf>,
    pub mode: WaveMode,
}

impl From<&crate::config::WaveConfig> for WaveSession {
    fn from(config: &crate::config::WaveConfig) -> Self {
        Self {
            path: config.path.clone(),
            mode: config.mode,
            ..Self::default()
        }
    }
}
