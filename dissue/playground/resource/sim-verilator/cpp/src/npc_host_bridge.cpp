#include "npc_host_bridge.h"
#include <cstdint>

namespace {
thread_local NpcHostBridge *current_bridge = nullptr;
thread_local void *current_opaque = nullptr;
} // namespace

NpcHostBridge::NpcHostBridge(const NpcDpiCallbacks *callbacks)
    : callbacks_(callbacks == nullptr ? NpcDpiCallbacks{} : *callbacks) {}

NpcHostBridge::EvaluationScope::EvaluationScope(NpcHostBridge &bridge,
                                                void *opaque)
    : previous_bridge_(current_bridge), previous_opaque_(current_opaque) {
  current_bridge = &bridge;
  current_opaque = opaque;
}

NpcHostBridge::EvaluationScope::~EvaluationScope() {
  current_bridge = previous_bridge_;
  current_opaque = previous_opaque_;
}

NpcHostBridge *NpcHostBridge::active_bridge() { return current_bridge; }

void *NpcHostBridge::active_opaque() { return current_opaque; }

void *NpcHostBridge::configured_opaque() const { return callbacks_.opaque; }

void NpcHostBridge::difftest_commit(const NpcCommitGroupEvent &event) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.on_difftest_commit == nullptr) {
    return;
  }

  bridge->callbacks_.on_difftest_commit(active_opaque(), &event);
}

void NpcHostBridge::difftest_context(const NpcCpuContext *context) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.on_difftest_context == nullptr ||
      context == nullptr) {
    return;
  }

  bridge->callbacks_.on_difftest_context(active_opaque(), context);
}

uint32_t NpcHostBridge::pmem_read(uint32_t addr, uint32_t len) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.pmem_read == nullptr) {
    return 0;
  }

  return bridge->callbacks_.pmem_read(active_opaque(), addr, len);
}

void NpcHostBridge::pmem_write(uint32_t addr, uint32_t len, uint32_t data) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.pmem_write == nullptr) {
    return;
  }

  bridge->callbacks_.pmem_write(active_opaque(), addr, len, data);
}

uint64_t NpcHostBridge::time_read() {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.time_read == nullptr) {
    return 0;
  }

  return bridge->callbacks_.time_read(active_opaque());
}

void NpcHostBridge::frontend_perf(uint32_t events,
                                  uint32_t ifu_correction,
                                  uint32_t fetch_queue_occupancy,
                                  uint32_t fetch_queue_enqueue_width,
                                  uint32_t fetch_queue_dequeue_width,
                                  uint32_t icache_lookup_valid,
                                  uint32_t icache_block_valid_mask,
                                  uint32_t icache_miss_mask,
                                  uint32_t icache_block_addr0,
                                  uint32_t icache_block_addr1) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.frontend_perf == nullptr) {
    return;
  }
  bridge->callbacks_.frontend_perf(active_opaque(), events, ifu_correction,
                                   fetch_queue_occupancy,
                                   fetch_queue_enqueue_width,
                                   fetch_queue_dequeue_width,
                                   icache_lookup_valid,
                                   icache_block_valid_mask, icache_miss_mask,
                                   icache_block_addr0, icache_block_addr1);
}

void NpcHostBridge::issue_queue_perf(uint8_t issue_count, uint8_t occupancy,
                                     uint8_t block_ready,
                                     uint8_t block_operand) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.issue_queue_perf == nullptr) {
    return;
  }
  bridge->callbacks_.issue_queue_perf(active_opaque(), issue_count, occupancy,
                                      block_ready, block_operand);
}

void NpcHostBridge::div_perf(uint32_t cycles, uint8_t special) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.div_perf == nullptr) {
    return;
  }
  bridge->callbacks_.div_perf(active_opaque(), cycles, special);
}

void NpcHostBridge::bpu_perf(uint8_t cfi_class, uint8_t pred_hit,
                             uint8_t pred_taken, uint8_t actual_taken,
                             uint8_t correct) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.bpu_perf == nullptr) {
    return;
  }
  bridge->callbacks_.bpu_perf(active_opaque(), cfi_class, pred_hit,
                               pred_taken, actual_taken, correct);
}

void NpcHostBridge::mem_perf(uint32_t events, uint32_t mshr_occupancy,
                             uint32_t store_queue_occupancy,
                             uint32_t load_txn_occupancy) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.mem_perf == nullptr) {
    return;
  }
  bridge->callbacks_.mem_perf(active_opaque(), events, mshr_occupancy,
                              store_queue_occupancy, load_txn_occupancy);
}

void NpcHostBridge::pipeline_trace(
    uint32_t kind, uint32_t flags, uint32_t slot, uint32_t rob_idx,
    uint32_t producer0, uint32_t producer1, uint32_t pc, uint32_t inst,
    uint32_t raw_inst, uint32_t sequence, uint32_t epoch, uint32_t resource,
    uint32_t txn_id) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.pipeline_trace == nullptr) {
    return;
  }

  NpcPipelineEvent event = {
      kind,       flags,    slot,     rob_idx, producer0,
      producer1,  pc,       inst,     raw_inst, sequence,
      epoch,      resource, txn_id,
  };
  bridge->callbacks_.pipeline_trace(active_opaque(), &event);
}
