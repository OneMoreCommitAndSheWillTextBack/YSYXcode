#ifndef ARCH_H__
#define ARCH_H__

#include <stdint.h>
#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context {
  uintptr_t gpr[NR_REGS];
  uintptr_t mcause;
  uintptr_t mstatus;
  uintptr_t mepc;
  void *pdir;
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#define SPI_BASE 0x10001000
#define SPI(x) (int *)(SPI_BASE + (x))
#define TX 0x0
#define CTRL 0x10
#define SS 0x18
#define DIVIDER 0x14

#endif