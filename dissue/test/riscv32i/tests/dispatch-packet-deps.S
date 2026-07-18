#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  addi a0, zero, 7
  addi a1, zero, 11
  addi a2, zero, 13

  .balign 8
raw_pair:
  add t0, a0, a1
  add t1, t0, a2

  addi t2, zero, 31
  bne t1, t2, fail_raw

  .balign 8
waw_pair:
  addi t3, zero, 1
  addi t3, zero, 2

  addi t4, t3, 3
  addi t5, zero, 5
  bne t4, t5, fail_waw
  TEST_PASS

fail_raw:
  TEST_FAIL 1

fail_waw:
  TEST_FAIL 2
