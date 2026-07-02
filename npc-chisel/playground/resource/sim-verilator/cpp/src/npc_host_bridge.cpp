#include "npc_host_bridge.h"
#include "npc_sim_types.h"
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

void NpcHostBridge::commit_group(uint32_t valid_mask, uint32_t finish_mask,
                                 uint32_t pc0, uint32_t inst0, uint32_t pc1,
                                 uint32_t inst1) {
  NpcHostBridge *bridge = active_bridge();

  if (bridge == nullptr || bridge->callbacks_.on_commit_group == nullptr) {
    return;
  }

  NpcCommitGroupEvent event = {
      valid_mask,
      finish_mask,
      {pc0, pc1},
      {inst0, inst1},
  };
  bridge->callbacks_.on_commit_group(&event);
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
