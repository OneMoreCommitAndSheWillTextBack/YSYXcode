#include "npc_host_bridge.h"

#include <cstdint>

namespace {
NpcHostBridge *g_active_bridge = nullptr;

NpcHostBridge &active_bridge() { return *g_active_bridge; }
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

void NpcHostBridge::commit(int valid, uint32_t pc, uint32_t inst) {
  NpcHostBridge &bridge = active_bridge();

  if (bridge.callbacks_.on_commit == nullptr) {
    return;
  }

  NpcCommitEvent event = {
      static_cast<uint8_t>(valid != 0),
      pc,
      inst,
  };
  bridge.callbacks_.on_commit(&event);
}

void NpcHostBridge::current_pc(uint32_t pc) {
  NpcHostBridge &bridge = active_bridge();

  if (bridge.callbacks_.on_current_pc == nullptr) {
    return;
  }

  NpcPcEvent event = {pc};
  bridge.callbacks_.on_current_pc(&event);
}

uint32_t NpcHostBridge::pmem_read(uint32_t addr, uint32_t len) {
  NpcHostBridge &bridge = active_bridge();

  if (bridge.callbacks_.pmem_read == nullptr) {
    return 0;
  }

  return bridge.callbacks_.pmem_read(addr, len);
}

void NpcHostBridge::pmem_write(uint32_t addr, uint32_t len, uint32_t data) {
  NpcHostBridge &bridge = active_bridge();

  if (bridge.callbacks_.pmem_write == nullptr) {
    return;
  }

  bridge.callbacks_.pmem_write(addr, len, data);
}
