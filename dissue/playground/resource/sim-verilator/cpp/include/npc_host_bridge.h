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
                              uint32_t mem_valid_mask, uint32_t mem_write_mask,
                              uint32_t pc0, uint32_t inst0, uint32_t raw_inst0,
                              uint32_t inst_len0, uint32_t next_pc0,
                              uint32_t mem_addr0, uint32_t mem_size0,
                              uint32_t pc1, uint32_t inst1, uint32_t raw_inst1,
                              uint32_t inst_len1, uint32_t next_pc1,
                              uint32_t mem_addr1, uint32_t mem_size1,
                              uint32_t async_intr_valid,
                              uint32_t async_intr_cause,
                              uint32_t async_intr_epc);
  static void difftest_context(const NpcCpuContext *context);
  static uint32_t pmem_read(uint32_t addr, uint32_t len);
  static void pmem_write(uint32_t addr, uint32_t len, uint32_t data);
  static uint64_t time_read();
  static void cache_hit(uint8_t hit);
  static void issue_queue_perf(uint8_t issue_count, uint8_t occupancy,
                               uint8_t block_ready, uint8_t block_operand);
  static void div_perf(uint32_t cycles, uint8_t special);
  static void bpu_perf(uint8_t correct);

private:
  NpcDpiCallbacks callbacks_{};
};

#endif
