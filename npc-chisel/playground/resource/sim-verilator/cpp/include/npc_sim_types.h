#ifndef NPC_SIM_TYPES_H
#define NPC_SIM_TYPES_H

#include <cstdint>

#define NPC_GPR_COUNT 32

typedef struct NpcCommitEvent {
  uint8_t valid;
  uint8_t finish;
  uint32_t pc;
  uint32_t inst;
} NpcCommitEvent;

typedef struct NpcPcEvent {
  uint32_t pc;
} NpcPcEvent;

typedef struct NpcDpiCallbacks {
  void (*on_commit)(const NpcCommitEvent *event);
  void (*on_current_pc)(const NpcPcEvent *event);
  uint32_t (*pmem_read)(uint32_t addr, uint32_t len);
  void (*pmem_write)(uint32_t addr, uint32_t len, uint32_t data);
  void (*report_invalid_inst)(uint32_t pc, uint32_t inst);
} NpcDpiCallbacks;

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

#endif
