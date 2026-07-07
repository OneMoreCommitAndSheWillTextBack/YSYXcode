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
  lw t2, 0(t0)
  bltu t2, t1, 1f

  li t0, RTC_TIME_LO
  lw t3, 0(t0)
  lw t4, 4(t0)
  or t3, t3, t4
  TEST_PASS

1:
  TEST_FAIL 1
