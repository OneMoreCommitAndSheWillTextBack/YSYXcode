#ifndef NPC_SIM_TYPES_H
#define NPC_SIM_TYPES_H

#include <cstdint>

#define NPC_GPR_COUNT 32

typedef struct NpcCommitGroupEvent {
  uint32_t valid_mask;
  uint32_t finish_mask;
  uint32_t pc[2];
  uint32_t inst[2];
} NpcCommitGroupEvent;

typedef struct NpcGprContext {
  uint32_t x[NPC_GPR_COUNT];
} NpcGprContext;

typedef struct NpcCsrContext {
  uint32_t mstatus;
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mcause;
  uint32_t mtval;
  uint32_t mie;
  uint32_t mip;
  uint32_t mscratch;
  uint32_t mcycle;
  uint32_t minstret;
} NpcCsrContext;

typedef struct NpcCpuContext {
  uint8_t valid;
  uint32_t pc;
  uint8_t priv_;
  NpcGprContext gpr;
  NpcCsrContext csr;
} NpcCpuContext;

typedef struct NpcDpiCallbacks {
  void (*on_difftest_commit)(const NpcCommitGroupEvent *event);
  void (*on_difftest_context)(const NpcCpuContext *context);
  uint32_t (*pmem_read)(uint32_t addr, uint32_t len);
  void (*pmem_write)(uint32_t addr, uint32_t len, uint32_t data);
  void (*cache_hit)(uint8_t hit);
  void (*issue_queue_perf)(uint8_t issue_count, uint8_t occupancy,
                           uint8_t block_ready, uint8_t block_operand);
} NpcDpiCallbacks;

#endif
