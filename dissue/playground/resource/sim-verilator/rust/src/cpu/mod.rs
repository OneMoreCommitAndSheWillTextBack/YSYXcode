mod context;
mod wave;

pub use context::{CpuContext, CsrContext, NpcCpuContext, PrivMode};
pub use wave::WaveConfig;

use crate::ffi;
use std::{
    ffi::CString,
    path::{self, Path},
    ptr::NonNull,
};

#[derive(Debug)]
pub enum CpuError {
    CreateFailed,
    InvalidWavePath,
    ContextUnavailable,
}

pub struct Cpu {
    raw: NonNull<ffi::NpcSim>,
    wave: WaveConfig,
}

impl Cpu {
    pub fn connect(callbacks: &ffi::NpcDpiCallbacks) -> Result<Self, CpuError> {
        let raw =
            NonNull::new(unsafe { ffi::npc_sim_new(callbacks) }).ok_or(CpuError::CreateFailed)?;

        Ok(Self {
            raw,
            wave: WaveConfig::default(),
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

    pub fn init_wave(&mut self, path: Option<&Path>) -> Result<(), CpuError> {
        let path_buf = path.map(Path::to_path_buf);
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

        self.wave.path = path_buf;
        Ok(())
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
        if !self.wave.enabled {
            return;
        }

        match self.wave.path.as_ref() {
            Some(pathbuf) => {
                crate::Log!("save to path {}", pathbuf.display());
            }
            None => {
                crate::Log!("save to current path");
            }
        }

        unsafe { ffi::npc_sim_close_wave(self.raw.as_ptr()) };
        self.wave.enabled = false;
    }
}

impl Drop for Cpu {
    fn drop(&mut self) {
        unsafe { ffi::npc_sim_delete(self.raw.as_ptr()) };
    }
}
