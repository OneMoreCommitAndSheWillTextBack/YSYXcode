#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  li t0, 7
  li t1, -3
  mul t2, t0, t1
  li t3, -21
  bne t2, t3, fail_mul

  li t0, -1
  li t1, 2
  mulh t2, t0, t1
  li t3, -1
  bne t2, t3, fail_mulh

  mulhsu t2, t0, t1
  li t3, -1
  bne t2, t3, fail_mulhsu

  li t0, -1
  li t1, 2
  mulhu t2, t0, t1
  li t3, 1
  bne t2, t3, fail_mulhu

  li t0, -7
  li t1, 3
  div t2, t0, t1
  li t3, -2
  bne t2, t3, fail_div

  rem t2, t0, t1
  li t3, -1
  bne t2, t3, fail_rem

  li t0, 7
  li t1, 3
  divu t2, t0, t1
  li t3, 2
  bne t2, t3, fail_divu

  remu t2, t0, t1
  li t3, 1
  bne t2, t3, fail_remu

  li t1, 0
  div t2, t0, t1
  li t3, -1
  bne t2, t3, fail_div_zero

  divu t2, t0, t1
  li t3, -1
  bne t2, t3, fail_divu_zero

  rem t2, t0, t1
  bne t2, t0, fail_rem_zero

  remu t2, t0, t1
  bne t2, t0, fail_remu_zero

  li t0, 0x80000000
  li t1, -1
  div t2, t0, t1
  bne t2, t0, fail_div_overflow

  rem t2, t0, t1
  bnez t2, fail_rem_overflow

  TEST_PASS

fail_mul:
  TEST_FAIL 1
fail_mulh:
  TEST_FAIL 2
fail_mulhsu:
  TEST_FAIL 3
fail_mulhu:
  TEST_FAIL 4
fail_div:
  TEST_FAIL 5
fail_rem:
  TEST_FAIL 6
fail_divu:
  TEST_FAIL 7
fail_remu:
  TEST_FAIL 8
fail_div_zero:
  TEST_FAIL 9
fail_divu_zero:
  TEST_FAIL 10
fail_rem_zero:
  TEST_FAIL 11
fail_remu_zero:
  TEST_FAIL 12
fail_div_overflow:
  TEST_FAIL 13
fail_rem_overflow:
  TEST_FAIL 14
