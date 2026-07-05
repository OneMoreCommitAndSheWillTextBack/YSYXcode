#ifndef NPC_HOST_BRIDGE_H
#define NPC_HOST_BRIDGE_H

#include "npc_sim_types.h"
#include <cstdint>

class NpcHostBridge {
public:
  explicit NpcHostBridge(const NpcDpiCallbacks *callbacks);
  ~NpcHostBridge();

  NpcHostBridge(const NpcHostBridge &) = delete;
  NpcHostBridge &operator=(const NpcHostBridge &) = delete;

  static void difftest_commit(uint32_t valid_mask, uint32_t finish_mask,
                              uint32_t pc0, uint32_t inst0, uint32_t pc1,
                              uint32_t inst1);
  static void difftest_context(const NpcCpuContext *context);
  static uint32_t pmem_read(uint32_t addr, uint32_t len);
  static void pmem_write(uint32_t addr, uint32_t len, uint32_t data);
  static void cache_hit(uint8_t hit);
  static void issue_queue_perf(uint8_t issue_count, uint8_t occupancy,
                               uint8_t block_ready, uint8_t block_operand);

private:
  NpcDpiCallbacks callbacks_{};
};

#endif
