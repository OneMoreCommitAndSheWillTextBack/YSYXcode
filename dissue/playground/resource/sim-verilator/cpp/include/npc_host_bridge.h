#ifndef NPC_HOST_BRIDGE_H
#define NPC_HOST_BRIDGE_H

#include "npc_sim_types.h"
#include <cstdint>

class NpcHostBridge {
public:
  // SystemVerilog DPI imports have no simulator receiver. This scope binds
  // calls on the current thread to one synchronous NpcSim evaluation.
  class EvaluationScope {
  public:
    EvaluationScope(NpcHostBridge &bridge, void *opaque);
    ~EvaluationScope();

    EvaluationScope(const EvaluationScope &) = delete;
    EvaluationScope &operator=(const EvaluationScope &) = delete;

  private:
    NpcHostBridge *previous_bridge_ = nullptr;
    void *previous_opaque_ = nullptr;
  };

  explicit NpcHostBridge(const NpcDpiCallbacks *callbacks);
  ~NpcHostBridge() = default;

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
  static void frontend_perf(uint32_t events, uint32_t fetch_queue_occupancy,
                            uint32_t fetch_queue_enqueue_width,
                            uint32_t fetch_queue_dequeue_width);
  static void issue_queue_perf(uint8_t issue_count, uint8_t occupancy,
                               uint8_t block_ready, uint8_t block_operand);
  static void div_perf(uint32_t cycles, uint8_t special);
  static void bpu_perf(uint8_t cfi_class, uint8_t pred_hit,
                       uint8_t pred_taken, uint8_t actual_taken,
                       uint8_t correct);
  static void mem_perf(uint32_t events, uint32_t mshr_occupancy,
                       uint32_t store_queue_occupancy,
                       uint32_t load_txn_occupancy);
  static void pipeline_trace(uint32_t kind, uint32_t flags, uint32_t slot,
                             uint32_t rob_idx, uint32_t producer0,
                             uint32_t producer1, uint32_t pc, uint32_t inst,
                             uint32_t raw_inst, uint32_t sequence,
                             uint32_t epoch, uint32_t resource,
                             uint32_t txn_id);

  void *configured_opaque() const;

private:
  static NpcHostBridge *active_bridge();
  static void *active_opaque();

  NpcDpiCallbacks callbacks_{};
};

#endif
