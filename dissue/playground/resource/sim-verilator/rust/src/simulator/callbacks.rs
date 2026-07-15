use super::{CommitGroupEvent, Simulator};
use crate::{cpu::NpcCpuContext, ffi, ACTIVE_SIMULATOR};

pub(super) fn build_callbacks() -> ffi::NpcDpiCallbacks {
    ffi::NpcDpiCallbacks {
        on_difftest_commit: Some(simulator_on_difftest_commit),
        on_difftest_context: Some(simulator_on_difftest_context),
        pmem_read: Some(simulator_pmem_read),
        pmem_write: Some(simulator_pmem_write),
        time_read: Some(simulator_time_read),
        cache_hit: Some(simulator_cache_hit),
        issue_queue_perf: Some(simulator_issue_queue_perf),
        div_perf: Some(simulator_div_perf),
        bpu_perf: Some(simulator_bpu_perf),
        mem_perf: Some(simulator_mem_perf),
    }
}

pub(super) fn set_active_simulator(simulator: *mut Simulator) {
    unsafe { ACTIVE_SIMULATOR = simulator };
}

fn active_simulator() -> *mut Simulator {
    unsafe { ACTIVE_SIMULATOR }
}

extern "C" fn simulator_pmem_read(addr: u32, len: u32) -> u32 {
    let simulator = active_simulator();
    if simulator.is_null() {
        return 0;
    }

    let simulator = unsafe { &mut *simulator };
    match simulator.pmem_read(addr, len) {
        Ok(data) => data,
        Err(error) => {
            simulator.abort_memory_access(error);
            0
        }
    }
}

extern "C" fn simulator_pmem_write(addr: u32, len: u32, data: u32) {
    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }

    let simulator = unsafe { &mut *simulator };
    if let Err(error) = simulator.pmem_write(addr, len, data) {
        simulator.abort_memory_access(error);
    }
}

extern "C" fn simulator_time_read() -> u64 {
    let simulator = active_simulator();
    if simulator.is_null() {
        return 0;
    }

    let simulator = unsafe { &*simulator };
    simulator.time_read()
}

extern "C" fn simulator_on_difftest_commit(event: *const ffi::NpcCommitGroupEvent) {
    if event.is_null() {
        return;
    }

    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }

    let event = unsafe { &*event };
    let simulator = unsafe { &mut *simulator };
    simulator.on_difftest_commit(CommitGroupEvent::new(
        event.valid_mask,
        event.finish_mask,
        event.mem_valid_mask,
        event.mem_write_mask,
        event.pc,
        event.inst,
        event.raw_inst,
        event.inst_len,
        event.next_pc,
        event.mem_addr,
        event.mem_size,
        event.async_intr_valid,
        event.async_intr_cause,
        event.async_intr_epc,
    ));
}

extern "C" fn simulator_on_difftest_context(context: *const NpcCpuContext) {
    if context.is_null() {
        return;
    }

    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }

    let context = unsafe { *context };
    let simulator = unsafe { &mut *simulator };
    simulator.on_difftest_context(context);
}

extern "C" fn simulator_cache_hit(hit: u8) {
    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }
    let simulator = unsafe { &mut *simulator };

    simulator.perf.cachehit(hit != 0);
}

extern "C" fn simulator_issue_queue_perf(
    issue_count: u8,
    occupancy: u8,
    block_ready: u8,
    block_operand: u8,
) {
    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }
    let simulator = unsafe { &mut *simulator };

    simulator
        .perf
        .issue_queue_perf(issue_count, occupancy, block_ready != 0, block_operand != 0);
}

extern "C" fn simulator_div_perf(cycles: u32, special: u8) {
    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }
    let simulator = unsafe { &mut *simulator };

    simulator.perf.div_perf(cycles, special != 0);
}

extern "C" fn simulator_bpu_perf(correct: u8) {
    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }
    let simulator = unsafe { &mut *simulator };

    simulator.perf.bpu_prediction(correct != 0);
}

extern "C" fn simulator_mem_perf(
    events: u32,
    mshr_occupancy: u32,
    store_queue_occupancy: u32,
    load_txn_occupancy: u32,
) {
    let simulator = active_simulator();
    if simulator.is_null() {
        return;
    }
    let simulator = unsafe { &mut *simulator };

    simulator.perf.mem_perf(
        events,
        mshr_occupancy,
        store_queue_occupancy,
        load_txn_occupancy,
    );
}
