#ifndef NPC_CSR_LIST_H
#define NPC_CSR_LIST_H

/*
 * Single source of truth for the CSRs carried in a checkpoint.
 *
 * The order below is part of the contract between the packer, the restorer's
 * state table and the DUT-side state dump: all three walk this list in this
 * order, so a field may only be appended at the end or the numbering has to be
 * bumped everywhere at once.
 *
 * mip is deliberately absent. NEMU keeps it as a projection of CLINT/PLIC
 * state rather than a register, so it can neither be checkpointed nor
 * meaningfully compared.
 */
#define NPC_CSR_LIST(X) \
  X(satp)               \
  X(mstatus)            \
  X(mstatush)           \
  X(mie)                \
  X(mtvec)              \
  X(mscratch)           \
  X(mepc)               \
  X(mcause)             \
  X(mtval)              \
  X(medeleg)            \
  X(mideleg)            \
  X(mcounteren)         \
  X(scounteren)         \
  X(stvec)              \
  X(sscratch)           \
  X(sepc)               \
  X(scause)             \
  X(stval)

#define NPC_CSR_COUNT_ONE(name) +1
#define NPC_CSR_COUNT (0 NPC_CSR_LIST(NPC_CSR_COUNT_ONE))

/* Indices into the flat CSR array, e.g. NPC_CSR_IDX_mstatus. */
#define NPC_CSR_ENUM(name) NPC_CSR_IDX_##name,
enum { NPC_CSR_LIST(NPC_CSR_ENUM) NPC_CSR_IDX_COUNT };
#undef NPC_CSR_ENUM

#endif
