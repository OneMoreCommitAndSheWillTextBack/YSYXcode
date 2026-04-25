#ifndef CSR_XMACRO__H_
#define CSR_XMACRO__H_

#include "debug.h"
#include "stdint.h"

// clang-format off
// Master CSR list. Raw CSRs have dedicated backing storage; virtual CSRs are
// views/projections that will be handled by semantic read/write logic later.
#define CSR_LIST(raw, virt)                                                    \
  raw(mepc, 0x341)                                                             \
  raw(mstatus, 0x300)                                                          \
  raw(mcause, 0x342)                                                           \
  raw(mtvec, 0x305)                                                            \
  raw(mscratch, 0x340)                                                         \
  raw(satp, 0x180)                                                             \
  raw(medeleg, 0x302)                                                          \
  raw(mideleg, 0x303)                                                          \
  raw(mhartid, 0xf14)                                                          \
  raw(pmpaddr0, 0x3b0)                                                         \
  raw(pmpaddr1, 0x3b1)                                                         \
  raw(pmpcfg0, 0x3a0)                                                          \
  raw(mie, 0x304)                                                              \
  virt(sie, 0x104)                                                             \
  virt(sip, 0x144)                                                             \
  virt(mip, 0x344)
// clang-format on

#define IGNORE_CSR(name, idx)

#define EACH_RAW_CSR(_) CSR_LIST(_, IGNORE_CSR)
#define EACH_VIRTUAL_CSR(_) CSR_LIST(IGNORE_CSR, _)

// Compatibility macro: keep current users working until the rest of the CSR
// code is migrated to the raw/virtual split.
#define EACH_CSR(_) CSR_LIST(_, _)

#define DECLARE_VIRTUAL_CSR_HANDLER(name, idx)                                 \
  uint32_t virt_csr_##name##_read(void);                                       \
  void virt_csr_##name##_write(uint32_t data);

EACH_VIRTUAL_CSR(DECLARE_VIRTUAL_CSR_HANDLER)

#define DEFINE_VIRTUAL_CSR_DEFAULT(name, idx)                                  \
  __attribute__((weak)) uint32_t virt_csr_##name##_read(void) {                \
    panic("virtual csr 0x%03x (%s) read is not implemented", idx, #name);      \
    return 0;                                                                  \
  }                                                                            \
  __attribute__((weak)) void virt_csr_##name##_write(uint32_t data) {          \
    panic("virtual csr 0x%03x (%s) write is not implemented: 0x%08x", idx,     \
          #name, data);                                                        \
  }

EACH_VIRTUAL_CSR(DEFINE_VIRTUAL_CSR_DEFAULT)

#endif
