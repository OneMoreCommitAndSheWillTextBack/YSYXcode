#include "riscv-test.h"

.option arch, +zicsr

.equ CLINT_MTIME_LO, 0x0200bff8
.equ RTC_TIME_LO,    0xa0000048

.section .text
.globl main
.type main, @function
main:
  li t0, CLINT_MTIME_LO
  lw t1, 0(t0)

  li t3, 2048
1:
  addi t3, t3, -1
  bnez t3, 1b

  lw t2, 0(t0)
  bgtu t2, t1, 2f
  TEST_FAIL 1

2:
  li t0, RTC_TIME_LO
  lw t3, 0(t0)
  lw t4, 4(t0)
  or t3, t3, t4
  TEST_PASS
