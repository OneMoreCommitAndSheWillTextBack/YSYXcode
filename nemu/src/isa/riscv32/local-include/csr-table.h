#ifndef CSR_TABLE__H_
#define CSR_TABLE__H_

#include "csr-xmacro.h"
#include <cpu/cpu.h>

#define CSR_CASE(name, idx)                                                    \
  case idx:                                                                    \
    return &cpu.csr.name;                                                      \
    break;

static inline uint32_t *get_csr(uint32_t csr_num) {
  switch (csr_num) {
    // Use X macro to generate all cases
    EACH_CSR(CSR_CASE)

  default:
    panic("[error] a undefined csr num %x\n", csr_num);
  }
}

#endif
