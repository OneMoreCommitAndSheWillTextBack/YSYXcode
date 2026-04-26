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

#define VIRT_CSR_CASE(name, idx)                                               \
  case idx:                                                                    \
    return &cpu.virt_csr.name;                                                 \
    break;

#define VIRT_CSR_INIT_ENTRY(name, idx)                                         \
  cpu.virt_csr.name = (virt_csr_entry_t){                                      \
      .csr_num = idx, .read = virt_csr_##name##_read,                          \
      .write = virt_csr_##name##_write};

#define VIRT_CSR_INIT_TABLE()                                                  \
  do {                                                                         \
    EACH_VIRTUAL_CSR(VIRT_CSR_INIT_ENTRY)                                      \
  } while (0)

static inline virt_csr_entry_t *get_virt_csr(uint32_t csr_num) {
  switch (csr_num) {
    EACH_VIRTUAL_CSR(VIRT_CSR_CASE)

  default:
    return NULL;
  }
}

#endif
