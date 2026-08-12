#include "npc_dpi.h"
#include "npc_host_bridge.h"
#include "npc_sim_types.h"

#include <cstdint>

namespace {

uint32_t dpi_word(const svBitVecVal *bits, uint32_t index) {
  return bits == nullptr ? 0 : static_cast<uint32_t>(bits[index]);
}

} // namespace

extern "C" void npc_difftest_commit(int valid_mask, int finish_mask,
                                    int mem_valid_mask, int mem_write_mask,
                                    int pc0, int inst0, int raw_inst0,
                                    int inst_len0, int next_pc0, int mem_addr0,
                                    int mem_size0, int pc1, int inst1,
                                    int raw_inst1, int inst_len1, int next_pc1,
                                    int mem_addr1, int mem_size1,
                                    int async_intr_valid, int async_intr_cause,
                                    int async_intr_epc) {
  const NpcCommitGroupEvent event = {
      static_cast<uint32_t>(valid_mask),
      static_cast<uint32_t>(finish_mask),
      static_cast<uint32_t>(mem_valid_mask),
      static_cast<uint32_t>(mem_write_mask),
      {static_cast<uint32_t>(pc0), static_cast<uint32_t>(pc1)},
      {static_cast<uint32_t>(inst0), static_cast<uint32_t>(inst1)},
      {static_cast<uint32_t>(raw_inst0), static_cast<uint32_t>(raw_inst1)},
      {static_cast<uint32_t>(inst_len0), static_cast<uint32_t>(inst_len1)},
      {static_cast<uint32_t>(next_pc0), static_cast<uint32_t>(next_pc1)},
      {static_cast<uint32_t>(mem_addr0), static_cast<uint32_t>(mem_addr1)},
      {static_cast<uint32_t>(mem_size0), static_cast<uint32_t>(mem_size1)},
      static_cast<uint32_t>(async_intr_valid),
      static_cast<uint32_t>(async_intr_cause),
      static_cast<uint32_t>(async_intr_epc),
  };
  NpcHostBridge::difftest_commit(event);
}

extern "C" void npc_difftest_context(int valid, int pc, int priv,
                                     const svBitVecVal *csr,
                                     const svBitVecVal *gpr) {
  NpcCpuContext context{};

  context.valid = valid != 0 ? 1 : 0;
  context.pc = static_cast<uint32_t>(pc);
  context.priv_ = static_cast<uint8_t>(priv & 0x3);

#define NPC_CSR_FIELD(name, dpi_index)                                      \
  context.csr.name = dpi_word(csr, dpi_index);
  NPC_FOR_EACH_CSR_FIELD(NPC_CSR_FIELD)
#undef NPC_CSR_FIELD

  for (uint32_t idx = 0; idx < NPC_GPR_COUNT; ++idx) {
    context.gpr.x[idx] = dpi_word(gpr, idx);
  }

  NpcHostBridge::difftest_context(&context);
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

extern "C" uint64_t npc_time_read() { return NpcHostBridge::time_read(); }

extern "C" void npc_frontend_perf(int events, int stall_events,
                                   char ifu_correction,
                                   int fetch_queue_occupancy,
                                   int fetch_queue_enqueue_width,
                                   int fetch_queue_dequeue_width,
                                   char icache_lookup_valid,
                                   int icache_block_valid_mask,
                                   int icache_miss_mask, int icache_block_addr0,
                                   int icache_block_addr1) {
  NpcHostBridge::frontend_perf(
      static_cast<uint32_t>(events),
      static_cast<uint32_t>(stall_events),
      static_cast<uint32_t>(ifu_correction != 0),
      static_cast<uint32_t>(fetch_queue_occupancy),
      static_cast<uint32_t>(fetch_queue_enqueue_width),
      static_cast<uint32_t>(fetch_queue_dequeue_width),
      static_cast<uint32_t>(icache_lookup_valid != 0),
      static_cast<uint32_t>(icache_block_valid_mask),
      static_cast<uint32_t>(icache_miss_mask),
      static_cast<uint32_t>(icache_block_addr0),
      static_cast<uint32_t>(icache_block_addr1));
}

extern "C" void npc_issue_queue_perf(int issue_count, int occupancy,
                                     char block_ready, char block_operand) {
  NpcHostBridge::issue_queue_perf(
      static_cast<uint8_t>(issue_count), static_cast<uint8_t>(occupancy),
      static_cast<uint8_t>(block_ready), static_cast<uint8_t>(block_operand));
}

extern "C" void npc_div_perf(int cycles, char special) {
  NpcHostBridge::div_perf(static_cast<uint32_t>(cycles),
                          static_cast<uint8_t>(special));
}

extern "C" void npc_bpu_perf(int cfi_class, char pred_hit, char pred_taken,
                              char actual_taken, char correct) {
  NpcHostBridge::bpu_perf(
      static_cast<uint8_t>(cfi_class), static_cast<uint8_t>(pred_hit),
      static_cast<uint8_t>(pred_taken), static_cast<uint8_t>(actual_taken),
      static_cast<uint8_t>(correct));
}

extern "C" void npc_mem_perf(int events, int mshr_occupancy,
                             int store_queue_occupancy,
                             int load_txn_occupancy) {
  NpcHostBridge::mem_perf(
      static_cast<uint32_t>(events), static_cast<uint32_t>(mshr_occupancy),
      static_cast<uint32_t>(store_queue_occupancy),
      static_cast<uint32_t>(load_txn_occupancy));
}

extern "C" void npc_pipeline_trace(int kind, int flags, int slot, int rob_idx,
                                    int producer0, int producer1, int pc,
                                    int inst, int raw_inst, int sequence,
                                    int epoch, int resource, int txn_id) {
  NpcHostBridge::pipeline_trace(
      static_cast<uint32_t>(kind), static_cast<uint32_t>(flags),
      static_cast<uint32_t>(slot), static_cast<uint32_t>(rob_idx),
      static_cast<uint32_t>(producer0), static_cast<uint32_t>(producer1),
      static_cast<uint32_t>(pc), static_cast<uint32_t>(inst),
      static_cast<uint32_t>(raw_inst), static_cast<uint32_t>(sequence),
      static_cast<uint32_t>(epoch), static_cast<uint32_t>(resource),
      static_cast<uint32_t>(txn_id));
}
