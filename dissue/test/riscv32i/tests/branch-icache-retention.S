#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  li t0, 0
  li t1, 256
1:
  addi t0, t0, 1
  blt t0, t1, 1b

  li t2, 256
  bne t0, t2, 2f
  TEST_PASS
2:
  TEST_FAIL 1
