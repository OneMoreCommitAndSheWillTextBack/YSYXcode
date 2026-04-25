#ifndef CSR_TABLE__H_
#define CSR_TABLE__H_

#include "csr-xmacro.h"
#include <cpu/cpu.h>

#define CSR_CASE(name, idx)                                                    \
  case idx:                                                                    \
    return &cpu.csr.name;                                                      \
    break;

static inline uint32_t *get_raw_csr(uint32_t csr_num) {
  switch (csr_num) {
    // Use X macro to generate all cases
    EACH_RAW_CSR(CSR_CASE)

  default:
    return NULL;
  }
}

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

#define VIRT_CSR_CASE(name, idx)                                               \
  case idx:                                                                    \
    return &cpu.virt_csr.name;                                                 \
    break;

static inline virt_csr_entry_t *get_virt_csr(uint32_t csr_num) {
  switch (csr_num) {
    EACH_VIRTUAL_CSR(VIRT_CSR_CASE)

  default:
    return NULL;
  }
}

#endif
