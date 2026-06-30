#include "npc_dpi.h"
#include "npc_host_bridge.h"

#include <cstdint>

extern "C" void npc_commit(int valid, int pc, int inst) {
  NpcHostBridge::commit(valid, static_cast<uint32_t>(pc),
                        static_cast<uint32_t>(inst));
}

extern "C" void npc_get_current_pc(int pc) {
  NpcHostBridge::current_pc(static_cast<uint32_t>(pc));
}

extern "C" void npc_pmem_read(int addr, int len, int *data) {
  if (data == nullptr) {
    return;
  }

  *data = static_cast<int>(NpcHostBridge::pmem_read(
      static_cast<uint32_t>(addr), static_cast<uint32_t>(len)));
}

extern "C" void npc_pmem_write(int addr, int len, int data) {
  NpcHostBridge::pmem_write(static_cast<uint32_t>(addr),
                            static_cast<uint32_t>(len),
                            static_cast<uint32_t>(data));
}
