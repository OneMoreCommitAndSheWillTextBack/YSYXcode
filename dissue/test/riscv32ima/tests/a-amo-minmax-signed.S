#include "riscv-test.h"

.option arch, +a

.macro CHECK_EQ reg, imm, code
  li t6, \imm
  beq \reg, t6, 1f
  TEST_FAIL \code
1:
.endm

.section .text
.globl main
.type main, @function
main:
  la t0, word
  li t1, 10
  sw t1, 0(t0)

  li t2, -1
  amomin.w t3, t2, (t0)
  CHECK_EQ t3, 10, 1
  lw t4, 0(t0)
  CHECK_EQ t4, -1, 2

  li t2, 5
  amomax.w t3, t2, (t0)
  CHECK_EQ t3, -1, 3
  lw t4, 0(t0)
  CHECK_EQ t4, 5, 4

  li t2, -7
  amomax.w t3, t2, (t0)
  CHECK_EQ t3, 5, 5
  lw t4, 0(t0)
  CHECK_EQ t4, 5, 6

  li t2, 3
  amomin.w t3, t2, (t0)
  CHECK_EQ t3, 5, 7
  lw t4, 0(t0)
  CHECK_EQ t4, 3, 8

  TEST_PASS

.section .data
.align 2
word:
  .word 0
