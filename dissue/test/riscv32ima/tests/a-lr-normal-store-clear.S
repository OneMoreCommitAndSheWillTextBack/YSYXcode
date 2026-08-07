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
  li t1, 0x11223344
  sw t1, 0(t0)

  lr.w t2, (t0)
  CHECK_EQ t2, 0x11223344, 1

  li t3, 0x55667788
  sw t3, 0(t0)
  li t4, 0xaabbccdd
  sc.w t5, t4, (t0)
  beqz t5, fail_sc

  lw t2, 0(t0)
  CHECK_EQ t2, 0x55667788, 3
  TEST_PASS

fail_sc:
  TEST_FAIL 2

.section .data
.align 2
word:
  .word 0
