#ifndef CSR_TABLE__H_
#define CSR_TABLE__H_

#include <cpu/cpu.h>

#define CSR(name, idx)                                                         \
  case idx:                                                                    \
    return &cpu.csr.name;                                                      \
    break;

static inline uint32_t *get_csr(uint32_t csr_num) {
  switch (csr_num) {
  case 0x300:
    return &cpu.csr.mstatus;
    break;
  case 0x302:
    return &cpu.csr.medeleg;
    break;
  case 0x303:
    return &cpu.csr.mideleg;
    break;
  case 0x305:
    return &cpu.csr.mtvec;
    break;
  case 0x340:
    return &cpu.csr.mscratch;
    break;
  case 0x341:
    return &cpu.csr.mepc;
    break;
  case 0x342:
    return &cpu.csr.mcause;
    break;
  case 0x180:
    return &cpu.csr.satp;
    break;
  case 0x104:
    return &cpu.csr.sie;
    break;
  case 0x144:
    return &cpu.csr.sip;
    break;
  case 0xf14:
    return &cpu.csr.mhartid;
    break;
  default:
    // printf("[error] a undefined csr num %d\n", csr_num);
    panic("[error] a undefined csr num %x\n", csr_num);
  }
}

#endif
