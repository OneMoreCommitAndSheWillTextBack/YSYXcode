use crate::config::{TraceConfig, TraceMode};
use std::path::PathBuf;

/// Driver-local state for the native waveform backend.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub(crate) struct TraceSession {
    pub enabled: bool,
    pub opened: bool,
    pub path: Option<PathBuf>,
    pub mode: TraceMode,
}

impl From<&TraceConfig> for TraceSession {
    fn from(config: &TraceConfig) -> Self {
        Self {
            path: config.path.clone(),
            mode: config.mode,
            ..Self::default()
        }
    }
}
