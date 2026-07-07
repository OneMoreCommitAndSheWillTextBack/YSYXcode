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
  li t1, 0x01020304
  sw t1, 0(t0)

  li t2, 0xa5a55a5a
  amoswap.w t3, t2, (t0)
  CHECK_EQ t3, 0x01020304, 1
  lw t4, 0(t0)
  CHECK_EQ t4, 0xa5a55a5a, 2

  li t2, -1
  amoswap.w t3, t2, (t0)
  CHECK_EQ t3, 0xa5a55a5a, 3
  lw t4, 0(t0)
  CHECK_EQ t4, -1, 4

  TEST_PASS

.section .data
.align 2
word:
  .word 0
