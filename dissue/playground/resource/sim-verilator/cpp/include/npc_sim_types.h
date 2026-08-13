#ifndef NPC_SIM_TYPES_H
#define NPC_SIM_TYPES_H

#include <cstdint>

#define NPC_GPR_COUNT 32

// X(field_name, dpi_word_index)
// Keep declaration order stable: NpcCsrContext is part of the C ABI.
#define NPC_FOR_EACH_CSR_FIELD(X)                                           \
  X(mstatus, 3)                                                             \
  X(mtvec, 7)                                                               \
  X(mepc, 0)                                                                \
  X(mcause, 5)                                                              \
  X(mtval, 6)                                                               \
  X(mie, 30)                                                                \
  X(mip, 34)                                                                \
  X(mscratch, 8)                                                            \
  X(mcycle, 35)                                                             \
  X(minstret, 36)                                                           \
  X(sepc, 1)                                                                \
  X(misa, 2)                                                                \
  X(mstatush, 4)                                                            \
  X(satp, 9)                                                                \
  X(medeleg, 10)                                                            \
  X(mideleg, 11)                                                            \
  X(mvendorid, 12)                                                          \
  X(marchid, 13)                                                            \
  X(mhartid, 14)                                                            \
  X(mimpid, 15)                                                             \
  X(pmpaddr0, 16)                                                           \
  X(pmpaddr1, 17)                                                           \
  X(pmpaddr2, 18)                                                           \
  X(pmpaddr3, 19)                                                           \
  X(pmpaddr4, 20)                                                           \
  X(pmpaddr5, 21)                                                           \
  X(pmpaddr6, 22)                                                           \
  X(pmpaddr7, 23)                                                           \
  X(pmpcfg0, 24)                                                            \
  X(pmpcfg1, 25)                                                            \
  X(scause, 26)                                                             \
  X(stval, 27)                                                              \
  X(sscratch, 28)                                                           \
  X(stvec, 29)                                                              \
  X(mcounteren, 31)                                                         \
  X(scounteren, 32)                                                         \
  X(mcountinhibit, 33)

typedef struct NpcCommitGroupEvent {
  uint32_t valid_mask;
  uint32_t finish_mask;
  uint32_t mem_valid_mask;
  uint32_t mem_write_mask;
  uint32_t pc[2];
  uint32_t inst[2];
  uint32_t raw_inst[2];
  uint32_t inst_len[2];
  uint32_t next_pc[2];
  uint32_t mem_addr[2];
  uint32_t mem_size[2];
  uint32_t async_intr_valid;
  uint32_t async_intr_cause;
  uint32_t async_intr_epc;
} NpcCommitGroupEvent;

typedef struct NpcGprContext {
  uint32_t x[NPC_GPR_COUNT];
} NpcGprContext;

typedef struct NpcCsrContext {
#define NPC_CSR_FIELD(name, dpi_index) uint32_t name;
  NPC_FOR_EACH_CSR_FIELD(NPC_CSR_FIELD)
#undef NPC_CSR_FIELD
} NpcCsrContext;

typedef struct NpcCpuContext {
  uint8_t valid;
  uint32_t pc;
  uint8_t priv_;
  NpcGprContext gpr;
  NpcCsrContext csr;
} NpcCpuContext;

typedef struct NpcPipelineEvent {
  uint32_t kind;
  uint32_t flags;
  uint32_t slot;
  uint32_t rob_idx;
  uint32_t producer0;
  uint32_t producer1;
  uint32_t pc;
  uint32_t inst;
  uint32_t raw_inst;
  uint32_t sequence;
  uint32_t epoch;
  uint32_t resource;
  uint32_t txn_id;
} NpcPipelineEvent;

typedef struct NpcDpiCallbacks {
  // Used by the compatibility reset and step entry points.
  void *opaque;
  void (*on_difftest_commit)(void *opaque,
                             const NpcCommitGroupEvent *event);
  void (*on_difftest_context)(void *opaque, const NpcCpuContext *context);
  uint32_t (*pmem_read)(void *opaque, uint32_t addr, uint32_t len);
  void (*pmem_write)(void *opaque, uint32_t addr, uint32_t len,
                     uint32_t data);
  uint64_t (*time_read)(void *opaque);
  void (*frontend_perf)(void *opaque, uint32_t events,
                        uint32_t stall_events,
                        uint32_t ifu_correction,
                        uint32_t fetch_queue_occupancy,
                        uint32_t fetch_queue_enqueue_width,
                        uint32_t fetch_queue_dequeue_width,
                        uint32_t icache_lookup_valid,
                        uint32_t icache_block_valid_mask,
                        uint32_t icache_miss_mask,
                        uint32_t icache_block_addr0,
                        uint32_t icache_block_addr1);
  void (*issue_queue_perf)(void *opaque, uint8_t issue_count,
                           uint8_t occupancy, uint8_t block_ready,
                           uint8_t block_operand, uint8_t block_reason,
                           uint8_t rob_done_operand_count);
  void (*div_perf)(void *opaque, uint32_t cycles, uint8_t special);
  void (*bpu_perf)(void *opaque, uint8_t cfi_class, uint8_t pred_hit,
                   uint8_t pred_taken, uint8_t actual_taken, uint8_t correct);
  void (*mem_perf)(void *opaque, uint32_t events, uint32_t mshr_occupancy,
                   uint32_t store_queue_occupancy,
                   uint32_t load_txn_occupancy);
  void (*pipeline_trace)(void *opaque, const NpcPipelineEvent *event);
} NpcDpiCallbacks;

#endif
