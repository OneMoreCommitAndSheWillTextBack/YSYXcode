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

  # When the second AMO retires, the third AMO becomes the ROB head on the
  # next edge. A younger load must not use that one-cycle issue opportunity to
  # read the cache before the third AMO has completed its uncached RMW.
  li t1, -129
  amoand.w zero, t1, (t0)
  li t1, -257
  amoand.w zero, t1, (t0)
  li t1, -1025
  amoand.w zero, t1, (t0)
  li a1, 0
  lw a0, 0(t0)

  CHECK_EQ a0, 0xfffffa7f, 1
  TEST_PASS

.section .data
.align 2
word:
  .word 0
