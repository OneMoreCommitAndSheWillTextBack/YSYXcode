#[allow(dead_code)]
#[repr(C)]
pub struct NpcSim {
    _private: [u8; 0],
}

#[allow(dead_code)]
#[repr(C)]
pub struct NpcCommitGroupEvent {
    pub valid_mask: u32,
    pub finish_mask: u32,
    pub pc: [u32; 2],
    pub inst: [u32; 2],
}

#[allow(dead_code)]
#[repr(C)]
pub struct NpcDpiCallbacks {
    pub on_commit_group: Option<extern "C" fn(*const NpcCommitGroupEvent)>,
    pub pmem_read: Option<extern "C" fn(u32, u32) -> u32>,
    pub pmem_write: Option<extern "C" fn(addr: u32, len: u32, data: u32)>,
}

#[allow(dead_code)]
#[cfg(not(test))]
unsafe extern "C" {
    pub fn npc_sim_new(callbacks: *const NpcDpiCallbacks) -> *mut NpcSim;
    pub fn npc_sim_delete(sim: *mut NpcSim);
    pub fn npc_sim_reset(sim: *mut NpcSim, cycles: u32);
    pub fn npc_sim_step(sim: *mut NpcSim);
    pub fn npc_sim_get_gpr(sim: *mut NpcSim, out: *mut crate::cpu::NpcGprContext) -> u8;
    pub fn npc_sim_get_csr(sim: *mut NpcSim, out: *mut crate::cpu::NpcCsrContext) -> u8;
    pub fn npc_sim_get_context(sim: *mut NpcSim, out: *mut crate::cpu::NpcCpuContext) -> u8;
    pub fn npc_sim_init_wave(sim: *mut NpcSim, path: *const core::ffi::c_char);
    pub fn npc_sim_enable_wave(sim: *mut NpcSim);
    pub fn npc_sim_disable_wave(sim: *mut NpcSim);
    pub fn npc_sim_close_wave(sim: *mut NpcSim);
}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_new(_callbacks: *const NpcDpiCallbacks) -> *mut NpcSim {
    std::ptr::NonNull::<NpcSim>::dangling().as_ptr()
}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_delete(_sim: *mut NpcSim) {}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_reset(_sim: *mut NpcSim, _cycles: u32) {}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_step(_sim: *mut NpcSim) {}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_get_gpr(_sim: *mut NpcSim, _out: *mut crate::cpu::NpcGprContext) -> u8 {
    0
}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_get_csr(_sim: *mut NpcSim, _out: *mut crate::cpu::NpcCsrContext) -> u8 {
    0
}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_get_context(_sim: *mut NpcSim, _out: *mut crate::cpu::NpcCpuContext) -> u8 {
    0
}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_init_wave(_sim: *mut NpcSim, _path: *const core::ffi::c_char) {}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_enable_wave(_sim: *mut NpcSim) {}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_disable_wave(_sim: *mut NpcSim) {}

#[allow(dead_code)]
#[cfg(test)]
pub unsafe fn npc_sim_close_wave(_sim: *mut NpcSim) {}
