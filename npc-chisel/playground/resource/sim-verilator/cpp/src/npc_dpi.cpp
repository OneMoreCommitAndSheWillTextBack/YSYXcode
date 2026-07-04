#include "npc_dpi.h"
#include "npc_host_bridge.h"

#include <cstdint>

extern "C" void npc_commit_group(int valid_mask, int finish_mask, int pc0,
                                 int inst0, int pc1, int inst1) {
  NpcHostBridge::commit_group(
      static_cast<uint32_t>(valid_mask), static_cast<uint32_t>(finish_mask),
      static_cast<uint32_t>(pc0), static_cast<uint32_t>(inst0),
      static_cast<uint32_t>(pc1), static_cast<uint32_t>(inst1));
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

extern "C" void npc_cache_hit(char hit) {
  NpcHostBridge::cache_hit(static_cast<uint8_t>(hit));
}

extern "C" void npc_issue_queue_perf(int issue_count, int occupancy,
                                     char block_ready, char block_operand) {
  NpcHostBridge::issue_queue_perf(
      static_cast<uint8_t>(issue_count), static_cast<uint8_t>(occupancy),
      static_cast<uint8_t>(block_ready), static_cast<uint8_t>(block_operand));
}
