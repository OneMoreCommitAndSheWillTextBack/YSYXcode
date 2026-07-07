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
  li t1, 0x12345678
  sw t1, 0(t0)

  li t2, 0xdeadbeef
  sc.w t3, t2, (t0)
  CHECK_EQ t3, 1, 1

  lw t4, 0(t0)
  CHECK_EQ t4, 0x12345678, 2

  TEST_PASS

.section .data
.align 2
word:
  .word 0
