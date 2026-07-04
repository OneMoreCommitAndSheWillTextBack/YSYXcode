#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  addi t0, zero, 12
  addi t1, zero, 30
  add t2, t0, t1
  li t3, 42
  bne t2, t3, 1f

  addi t4, zero, -1
  addi t4, t4, 1
  bnez t4, 2f

  TEST_PASS

1:
  TEST_FAIL 1
2:
  TEST_FAIL 2
