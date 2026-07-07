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
  li t1, 0x55aa00ff
  sw t1, 0(t0)

  li t2, 0x0f0ffff0
  amoand.w t3, t2, (t0)
  CHECK_EQ t3, 0x55aa00ff, 1
  lw t4, 0(t0)
  CHECK_EQ t4, 0x050a00f0, 2

  li t2, 0xf000000f
  amoor.w t3, t2, (t0)
  CHECK_EQ t3, 0x050a00f0, 3
  lw t4, 0(t0)
  CHECK_EQ t4, 0xf50a00ff, 4

  li t2, 0xffffffff
  amoxor.w t3, t2, (t0)
  CHECK_EQ t3, 0xf50a00ff, 5
  lw t4, 0(t0)
  CHECK_EQ t4, 0x0af5ff00, 6

  TEST_PASS

.section .data
.align 2
word:
  .word 0
