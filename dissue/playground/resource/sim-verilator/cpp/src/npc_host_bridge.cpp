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

void NpcHostBridge::difftest_commit(
    uint32_t valid_mask, uint32_t finish_mask, uint32_t mem_valid_mask,
    uint32_t mem_write_mask, uint32_t pc0, uint32_t inst0, uint32_t raw_inst0,
    uint32_t inst_len0, uint32_t next_pc0, uint32_t mem_addr0,
    uint32_t mem_size0, uint32_t pc1, uint32_t inst1, uint32_t raw_inst1,
    uint32_t inst_len1, uint32_t next_pc1, uint32_t mem_addr1,
    uint32_t mem_size1, uint32_t async_intr_valid,
    uint32_t async_intr_cause, uint32_t async_intr_epc) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.on_difftest_commit == nullptr) {
    return;
  }

  NpcCommitGroupEvent event = {
      valid_mask,
      finish_mask,
      mem_valid_mask,
      mem_write_mask,
      {pc0, pc1},
      {inst0, inst1},
      {raw_inst0, raw_inst1},
      {inst_len0, inst_len1},
      {next_pc0, next_pc1},
      {mem_addr0, mem_addr1},
      {mem_size0, mem_size1},
      async_intr_valid,
      async_intr_cause,
      async_intr_epc,
  };
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

void NpcHostBridge::frontend_perf(uint32_t events) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.frontend_perf == nullptr) {
    return;
  }
  bridge->callbacks_.frontend_perf(active_opaque(), events);
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

void NpcHostBridge::bpu_perf(uint8_t correct) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.bpu_perf == nullptr) {
    return;
  }
  bridge->callbacks_.bpu_perf(active_opaque(), correct);
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
