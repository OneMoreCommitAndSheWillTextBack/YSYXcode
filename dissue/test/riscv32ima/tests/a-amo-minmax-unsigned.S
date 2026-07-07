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
  li t1, -1
  sw t1, 0(t0)

  li t2, 1
  amominu.w t3, t2, (t0)
  CHECK_EQ t3, -1, 1
  lw t4, 0(t0)
  CHECK_EQ t4, 1, 2

  li t2, 0xfffffffe
  amomaxu.w t3, t2, (t0)
  CHECK_EQ t3, 1, 3
  lw t4, 0(t0)
  CHECK_EQ t4, 0xfffffffe, 4

  li t2, 0x7fffffff
  amominu.w t3, t2, (t0)
  CHECK_EQ t3, 0xfffffffe, 5
  lw t4, 0(t0)
  CHECK_EQ t4, 0x7fffffff, 6

  TEST_PASS

.section .data
.align 2
word:
  .word 0
