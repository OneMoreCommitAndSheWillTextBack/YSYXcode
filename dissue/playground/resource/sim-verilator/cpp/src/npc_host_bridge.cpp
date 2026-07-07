#include "npc_host_bridge.h"
#include "npc_sim_types.h"
#include <cstddef>
#include <cstdint>

namespace {
NpcHostBridge *g_active_bridge = nullptr;

NpcHostBridge *active_bridge() { return g_active_bridge; }
} // namespace

NpcHostBridge::NpcHostBridge(const NpcDpiCallbacks *callbacks)
    : callbacks_(callbacks == nullptr ? NpcDpiCallbacks{} : *callbacks) {
  g_active_bridge = this;
}

NpcHostBridge::~NpcHostBridge() {
  if (g_active_bridge == this) {
    g_active_bridge = nullptr;
  }
}

void NpcHostBridge::difftest_commit(uint32_t valid_mask, uint32_t finish_mask,
                                    uint32_t mem_valid_mask,
                                    uint32_t mem_write_mask, uint32_t pc0,
                                    uint32_t inst0, uint32_t mem_addr0,
                                    uint32_t mem_size0, uint32_t pc1,
                                    uint32_t inst1, uint32_t mem_addr1,
                                    uint32_t mem_size1) {
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
      {mem_addr0, mem_addr1},
      {mem_size0, mem_size1},
  };
  bridge->callbacks_.on_difftest_commit(&event);
}

void NpcHostBridge::difftest_context(const NpcCpuContext *context) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.on_difftest_context == nullptr ||
      context == nullptr) {
    return;
  }

  bridge->callbacks_.on_difftest_context(context);
}

uint32_t NpcHostBridge::pmem_read(uint32_t addr, uint32_t len) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.pmem_read == nullptr) {
    return 0;
  }

  return bridge->callbacks_.pmem_read(addr, len);
}

void NpcHostBridge::pmem_write(uint32_t addr, uint32_t len, uint32_t data) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.pmem_write == nullptr) {
    return;
  }

  bridge->callbacks_.pmem_write(addr, len, data);
}

uint64_t NpcHostBridge::time_read() {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.time_read == nullptr) {
    return 0;
  }

  return bridge->callbacks_.time_read();
}

void NpcHostBridge::cache_hit(uint8_t hit) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.cache_hit == nullptr) {
    return;
  }
  bridge->callbacks_.cache_hit(hit);
}

void NpcHostBridge::issue_queue_perf(uint8_t issue_count, uint8_t occupancy,
                                     uint8_t block_ready,
                                     uint8_t block_operand) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.issue_queue_perf == nullptr) {
    return;
  }
  bridge->callbacks_.issue_queue_perf(issue_count, occupancy, block_ready,
                                      block_operand);
}

void NpcHostBridge::div_perf(uint32_t cycles, uint8_t special) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.div_perf == nullptr) {
    return;
  }
  bridge->callbacks_.div_perf(cycles, special);
}
