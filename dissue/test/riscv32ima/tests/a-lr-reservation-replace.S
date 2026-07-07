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
  la t0, words
  li t1, 11
  sw t1, 0(t0)
  li t1, 22
  sw t1, 4(t0)

  lr.w t2, (t0)
  CHECK_EQ t2, 11, 1

  addi t3, t0, 4
  lr.w t4, (t3)
  CHECK_EQ t4, 22, 2

  li t5, 33
  sc.w t4, t5, (t3)
  CHECK_EQ t4, 0, 3

  lw t1, 0(t0)
  CHECK_EQ t1, 11, 4
  lw t1, 4(t0)
  CHECK_EQ t1, 33, 5

  TEST_PASS

.section .data
.align 2
words:
  .word 0
  .word 0
