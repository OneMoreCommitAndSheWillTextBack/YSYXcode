use crate::common::CpuContext;
use std::ffi::c_void;

#[repr(C)]
pub struct NpcSim {
    _private: [u8; 0],
}

#[repr(C)]
pub struct NpcCommitGroupEvent {
    pub valid_mask: u32,
    pub finish_mask: u32,
    pub mem_valid_mask: u32,
    pub mem_write_mask: u32,
    pub pc: [u32; 2],
    pub inst: [u32; 2],
    pub raw_inst: [u32; 2],
    pub inst_len: [u32; 2],
    pub next_pc: [u32; 2],
    pub mem_addr: [u32; 2],
    pub mem_size: [u32; 2],
    pub async_intr_valid: u32,
    pub async_intr_cause: u32,
    pub async_intr_epc: u32,
}

#[repr(C)]
pub struct NpcDpiCallbacks {
    pub opaque: *mut c_void,
    pub on_difftest_commit: Option<extern "C" fn(*mut c_void, *const NpcCommitGroupEvent)>,
    pub on_difftest_context: Option<extern "C" fn(*mut c_void, *const CpuContext)>,
    pub pmem_read: Option<extern "C" fn(*mut c_void, u32, u32) -> u32>,
    pub pmem_write: Option<extern "C" fn(*mut c_void, addr: u32, len: u32, data: u32)>,
    pub time_read: Option<extern "C" fn(*mut c_void) -> u64>,
    pub cache_hit: Option<extern "C" fn(*mut c_void, hit: u8)>,
    pub issue_queue_perf: Option<
        extern "C" fn(
            *mut c_void,
            issue_count: u8,
            occupancy: u8,
            block_ready: u8,
            block_operand: u8,
        ),
    >,
    pub div_perf: Option<extern "C" fn(*mut c_void, cycles: u32, special: u8)>,
    pub bpu_perf: Option<extern "C" fn(*mut c_void, correct: u8)>,
    pub mem_perf: Option<
        extern "C" fn(
            *mut c_void,
            events: u32,
            mshr_occupancy: u32,
            store_queue_occupancy: u32,
            load_txn_occupancy: u32,
        ),
    >,
}

unsafe extern "C" {
    pub fn npc_sim_new(callbacks: *const NpcDpiCallbacks) -> *mut NpcSim;
    pub fn npc_sim_delete(sim: *mut NpcSim);
    pub fn npc_sim_reset_with_opaque(sim: *mut NpcSim, opaque: *mut c_void, cycles: u32);
    pub fn npc_sim_step_with_opaque(sim: *mut NpcSim, opaque: *mut c_void);
    pub fn npc_sim_init_wave(sim: *mut NpcSim, path: *const core::ffi::c_char);
    pub fn npc_sim_enable_wave(sim: *mut NpcSim);
    pub fn npc_sim_close_wave(sim: *mut NpcSim);
    pub fn npc_sim_abandon_wave(sim: *mut NpcSim);
}
