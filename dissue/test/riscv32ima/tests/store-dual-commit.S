#include "riscv-test.h"

.option arch, +m

.section .text
.globl main
.type main, @function
main:
  la s0, store_line
  li t0, 0x7fffffff
  li t1, 3
  li t2, 0x13579bdf
  li t3, 0x2468ace0

  /* The older iterative divide lets independent younger stores all resolve. */
  div s1, t0, t1
.rept 12
  sw t2, 0(s0)
  sw t3, 4(s0)
.endr

  li t4, 0x2aaaaaaa
  bne s1, t4, fail_div
  fence rw, rw
  lw t4, 0(s0)
  bne t4, t2, fail_word
  lw t4, 4(s0)
  bne t4, t3, fail_pair
  TEST_PASS

fail_div:
  TEST_FAIL 1
fail_word:
  TEST_FAIL 2
fail_pair:
  TEST_FAIL 3

.section .data
.balign 64
store_line:
  .word 0
  .word 0
