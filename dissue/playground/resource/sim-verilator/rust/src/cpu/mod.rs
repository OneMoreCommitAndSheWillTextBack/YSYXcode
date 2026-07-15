mod context;
mod lightsss_controller;
mod wave;

pub use context::{CpuContext, CsrContext, NpcCpuContext, PrivMode};
pub use wave::WaveSession;

use crate::{
    config::WaveMode,
    cpu::lightsss_controller::{CheckpointRole, LightsssController},
    ffi,
};
use std::{ffi::CString, fmt, ptr::NonNull};

#[derive(Debug)]
pub enum CpuError {
    CreateFailed,
    InvalidWavePath,
    ContextUnavailable,
}

impl fmt::Display for CpuError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::CreateFailed => write!(formatter, "failed to create the CPU simulator"),
            Self::InvalidWavePath => write!(formatter, "wave path contains a NUL byte"),
            Self::ContextUnavailable => write!(formatter, "CPU context is unavailable"),
        }
    }
}

impl std::error::Error for CpuError {}

pub struct Cpu {
    raw: NonNull<ffi::NpcSim>,
    wave: WaveSession,
    lightsss: LightsssController,
}

impl Cpu {
    pub fn connect(callbacks: &ffi::NpcDpiCallbacks) -> Result<Self, CpuError> {
        let raw =
            NonNull::new(unsafe { ffi::npc_sim_new(callbacks) }).ok_or(CpuError::CreateFailed)?;

        Ok(Self {
            raw,
            wave: WaveSession::default(),
            lightsss: LightsssController::new(),
        })
    }

    pub fn reset(&mut self, cycles: u32) {
        unsafe { ffi::npc_sim_reset(self.raw.as_ptr(), cycles) };
    }

    pub fn step(&mut self) {
        unsafe { ffi::npc_sim_step(self.raw.as_ptr()) };
    }

    pub(crate) fn raw(&self) -> *mut ffi::NpcSim {
        self.raw.as_ptr()
    }

    pub fn init_wave(&mut self, session: WaveSession) -> Result<(), CpuError> {
        let path_buf = session.path.clone();
        let path = match path_buf.as_ref() {
            Some(path) => Some(
                CString::new(path.to_string_lossy().as_bytes())
                    .map_err(|_| CpuError::InvalidWavePath)?,
            ),
            None => None,
        };

        unsafe {
            ffi::npc_sim_init_wave(
                self.raw.as_ptr(),
                path.as_ref().map_or(std::ptr::null(), |path| path.as_ptr()),
            )
        };

        self.wave = session;
        self.wave.path = path_buf;
        self.wave.opened = true;
        if let WaveMode::Lightsss {
            max_checkpoints, ..
        } = self.wave.mode
        {
            self.lightsss.set_max_checkpoints(max_checkpoints);
        }
        Ok(())
    }

    pub fn wave_update(&mut self, cycle: u64) {
        if self.wave.enabled {
            return;
        }

        match self.wave.mode {
            WaveMode::After { cycle: after } => {
                if cycle > after {
                    self.enable_wave();
                }
            }
            WaveMode::Lightsss { gap, .. } => {
                if cycle != 0 && cycle % gap == 0 {
                    match self.lightsss.add_checkpoints(cycle) {
                        Ok(CheckpointRole::Parent) => {}
                        Ok(CheckpointRole::RecoveryChild { result_tx: _ }) => {
                            self.enable_wave();
                        }
                        Err(error) => {
                            crate::LogError!(
                                "failed to create lightsss checkpoint at cycle {}: {}",
                                cycle,
                                error
                            );
                        }
                    }
                }
            }
            WaveMode::Disabled | WaveMode::Immediate => {}
        }
    }

    pub fn enable_wave(&mut self) {
        unsafe { ffi::npc_sim_enable_wave(self.raw.as_ptr()) };
        self.wave.enabled = true;
    }

    pub fn disable_wave(&mut self) {
        unsafe { ffi::npc_sim_disable_wave(self.raw.as_ptr()) };
        self.wave.enabled = false;
    }

    pub fn isenable_wave(&mut self) -> bool {
        self.wave.enabled
    }

    pub fn close_wave(&mut self) {
        if !self.wave.opened {
            return;
        }

        if self.wave.enabled {
            match self.wave.path.as_ref() {
                Some(pathbuf) => {
                    crate::Log!("save to path {}", pathbuf.display());
                }
                None => {
                    crate::Log!("save to current path");
                }
            }
        }

        unsafe { ffi::npc_sim_close_wave(self.raw.as_ptr()) };
        self.wave.enabled = false;
        self.wave.opened = false;
    }

    pub fn terminal(&mut self) {
        if matches!(self.wave.mode, WaveMode::Lightsss { .. }) {
            match self.lightsss.wake() {
                Ok(Some(_)) => {
                    crate::Log!("Wake up lightsss subthread");
                    self.handoff_wave_to_checkpoint();
                    return;
                }
                Ok(None) => {}
                Err(error) => {
                    crate::LogError!("failed to wake lightsss checkpoint: {}", error);
                }
            }
        }

        self.shutdown_lightsss();
        self.close_wave();
    }

    pub fn shutdown_lightsss(&mut self) {
        if let Err(error) = self.lightsss.shutdown() {
            crate::LogError!("failed to shut down lightsss checkpoints: {}", error);
        }
    }

    fn handoff_wave_to_checkpoint(&mut self) {
        unsafe { ffi::npc_sim_abandon_wave(self.raw.as_ptr()) };
        self.wave.enabled = false;
        self.wave.opened = false;
    }
}

impl Drop for Cpu {
    fn drop(&mut self) {
        self.shutdown_lightsss();
        unsafe { ffi::npc_sim_delete(self.raw.as_ptr()) };
    }
}
