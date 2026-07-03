#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  li t0, 0
  li t1, 5
1:
  addi t0, t0, 1
  blt t0, t1, 1b

  li t2, 5
  bne t0, t2, 2f

  jal t3, 3f
4:
  TEST_FAIL 2
3:
  la t4, 4b
  bne t3, t4, 5f
  TEST_PASS

2:
  TEST_FAIL 1
5:
  TEST_FAIL 3
