//! Verilator-backed DUT driver.

mod trace;

use crate::{config::TraceConfig, ffi};
use std::{
    ffi::{c_void, CString},
    fmt,
    ptr::NonNull,
};
use trace::TraceSession;

/// Native-driver construction and waveform errors.
#[derive(Debug)]
pub(crate) enum DriverError {
    CreateFailed,
    InvalidTracePath,
}

impl fmt::Display for DriverError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::CreateFailed => write!(formatter, "failed to create the Verilator driver"),
            Self::InvalidTracePath => write!(formatter, "trace path contains a NUL byte"),
        }
    }
}

impl std::error::Error for DriverError {}

/// Owns one native NpcSim instance and its waveform backend.
pub(crate) struct NpcDriver {
    raw: NonNull<ffi::NpcSim>,
    trace: TraceSession,
}

impl NpcDriver {
    pub(crate) fn new(callbacks: &ffi::NpcDpiCallbacks) -> Result<Self, DriverError> {
        let raw = NonNull::new(unsafe { ffi::npc_sim_new(callbacks) })
            .ok_or(DriverError::CreateFailed)?;
        Ok(Self {
            raw,
            trace: TraceSession::default(),
        })
    }

    /// Evaluates the RTL reset sequence while `opaque` names the active host.
    pub(crate) fn reset(&mut self, opaque: *mut c_void, cycles: u32) {
        unsafe { ffi::npc_sim_reset_with_opaque(self.raw.as_ptr(), opaque, cycles) };
    }

    /// Evaluates one RTL clock step while `opaque` names the active host.
    pub(crate) fn step(&mut self, opaque: *mut c_void) {
        unsafe { ffi::npc_sim_step_with_opaque(self.raw.as_ptr(), opaque) };
    }

    /// Initializes the native trace object before simulation starts.
    pub(crate) fn init_trace(&mut self, config: &TraceConfig) -> Result<(), DriverError> {
        let trace = TraceSession::from(config);
        let path = trace
            .path
            .as_ref()
            .map(|path| CString::new(path.to_string_lossy().as_bytes()))
            .transpose()
            .map_err(|_| DriverError::InvalidTracePath)?;

        unsafe {
            ffi::npc_sim_init_wave(
                self.raw.as_ptr(),
                path.as_ref().map_or(std::ptr::null(), |path| path.as_ptr()),
            );
        }

        self.trace = trace;
        self.trace.opened = true;
        Ok(())
    }

    pub(crate) fn enable_trace(&mut self) {
        if self.trace.enabled {
            return;
        }
        unsafe { ffi::npc_sim_enable_wave(self.raw.as_ptr()) };
        self.trace.enabled = true;
    }

    pub(crate) fn trace_enabled(&self) -> bool {
        self.trace.enabled
    }

    pub(crate) fn close_trace(&mut self) {
        if !self.trace.opened {
            return;
        }

        if self.trace.enabled {
            match self.trace.path.as_ref() {
                Some(path) => crate::Log!("save trace to {}", path.display()),
                None => crate::Log!("save trace to the native default path"),
            }
        }

        unsafe { ffi::npc_sim_close_wave(self.raw.as_ptr()) };
        self.trace.enabled = false;
        self.trace.opened = false;
    }

    /// Leaves trace ownership to a LightSSS recovery child without closing it.
    pub(crate) fn abandon_trace(&mut self) {
        unsafe { ffi::npc_sim_abandon_wave(self.raw.as_ptr()) };
        self.trace.enabled = false;
        self.trace.opened = false;
    }
}

impl Drop for NpcDriver {
    fn drop(&mut self) {
        unsafe { ffi::npc_sim_delete(self.raw.as_ptr()) };
    }
}
