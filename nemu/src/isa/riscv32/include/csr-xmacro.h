#ifndef CSR_XMACRO__H_
#define CSR_XMACRO__H_

// 定义 CSR 表格
#define EACH_CSR(_)                                                            \
  _(mepc, 0x341)                                                               \
  _(mstatus, 0x300)                                                            \
  _(mcause, 0x342)                                                             \
  _(mtvec, 0x305)                                                              \
  _(mscratch, 0x340)                                                           \
  _(satp, 0x180)                                                               \
  _(sie, 0x104)                                                                \
  _(sip, 0x144)                                                                \
  _(medeleg, 0x302)                                                            \
  _(mideleg, 0x303)                                                            \
  _(mhartid, 0xf14)                                                            \
  _(pmpaddr0, 0x3b0)                                                           \
  _(pmpaddr1, 0x3b1)                                                           \
  _(pmpcfg0, 0x3a0)                                                            \
  _(mie, 0x304)                                                                \
  _(mip, 0x344)

#endif
