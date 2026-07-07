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
  la t0, amo_word

  li t1, 5
  sw t1, 0(t0)

  lr.w t2, (t0)
  CHECK_EQ t2, 5, 1

  li t3, 7
  sc.w t4, t3, (t0)
  CHECK_EQ t4, 0, 2
  lw t5, 0(t0)
  CHECK_EQ t5, 7, 3

  li t3, 9
  sc.w t4, t3, (t0)
  CHECK_EQ t4, 1, 4
  lw t5, 0(t0)
  CHECK_EQ t5, 7, 5

  li t3, 3
  amoadd.w t4, t3, (t0)
  CHECK_EQ t4, 7, 6
  lw t5, 0(t0)
  CHECK_EQ t5, 10, 7

  li t3, 0x55
  amoswap.w t4, t3, (t0)
  CHECK_EQ t4, 10, 8
  lw t5, 0(t0)
  CHECK_EQ t5, 0x55, 9

  li t3, 0x0f
  amoand.w t4, t3, (t0)
  CHECK_EQ t4, 0x55, 10
  lw t5, 0(t0)
  CHECK_EQ t5, 0x05, 11

  li t3, 0xf0
  amoor.w t4, t3, (t0)
  CHECK_EQ t4, 0x05, 12
  lw t5, 0(t0)
  CHECK_EQ t5, 0xf5, 13

  li t3, 0xff
  amoxor.w t4, t3, (t0)
  CHECK_EQ t4, 0xf5, 14
  lw t5, 0(t0)
  CHECK_EQ t5, 0x0a, 15

  li t3, -1
  amomin.w t4, t3, (t0)
  CHECK_EQ t4, 0x0a, 16
  lw t5, 0(t0)
  CHECK_EQ t5, -1, 17

  li t3, 1
  amomaxu.w t4, t3, (t0)
  CHECK_EQ t4, -1, 18
  lw t5, 0(t0)
  CHECK_EQ t5, -1, 19

  TEST_PASS

.section .data
.align 2
amo_word:
  .word 0
