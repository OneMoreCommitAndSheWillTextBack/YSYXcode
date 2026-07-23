#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  mv s0, ra
  call warm_target
  mv ra, s0
  la t0, branch_value
  lw t0, 0(t0)
  li t1, 0

.balign 8
taken_branch:
  beq t0, zero, redirect_target

fallthrough:
.rept 96
  addi t1, t1, 1
.endr
  TEST_FAIL 1

check_target:
  li t2, 17
  bne a0, t2, fail_target
  TEST_PASS

fail_target:
  TEST_FAIL 2

.balign 8
warm_target:
  ret
  nop

redirect_target:
  li a0, 17
  j check_target

.section .data
.balign 4
branch_value:
  .word 0
