#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  /* A cold older load holds retirement while independent stores resolve. */
  la s0, cold_gate
  lw s1, 0(s0)
  li t0, 0x31415926
  bne s1, t0, fail_gate

  la s2, store_line
  la s3, miss_lines
  li t0, 0x13579bdf
  li t1, 0x2468ace0

  /* Independent cold lines hold all DCache MSHRs and the store transaction slots. */
.set miss_offset, 0
.rept 16
  sw t0, miss_offset(s3)
  .set miss_offset, miss_offset + 64
.endr
.set miss_offset, 0
.rept 16
  sw t1, miss_offset(s3)
  .set miss_offset, miss_offset + 64
.endr

  /* More stores than either the ROB or SQ force backpressure and sqIdx reuse. */
.rept 48
  sw t0, 0(s2)
  sw t1, 4(s2)
.endr

  li t2, 0xdeadbeef
  li t3, 0xc001d00d
  sw t2, 0(s2)
  sw t3, 4(s2)

  /* Youngest-older forwarding is selected independently for each byte. */
  li t0, 0xaa
  sb t0, 1(s2)
  li t1, 0xbbbb
  sh t1, 2(s2)

  lw t4, 0(s2)
  li t5, 0xbbbbaaef
  bne t4, t5, fail_forward_word
  lw t4, 4(s2)
  bne t4, t3, fail_forward_pair

  /* Fence completion proves every committed store response was observed. */
  fence rw, rw
  lw t4, 0(s2)
  li t5, 0xbbbbaaef
  bne t4, t5, fail_drain_word
  lw t4, 4(s2)
  bne t4, t3, fail_drain_pair
  lw t4, 0(s3)
  li t5, 0x2468ace0
  bne t4, t5, fail_miss_first
  lw t4, 960(s3)
  bne t4, t5, fail_miss_last
  TEST_PASS

fail_gate:
  TEST_FAIL 1
fail_forward_word:
  TEST_FAIL 2
fail_forward_pair:
  TEST_FAIL 3
fail_drain_word:
  TEST_FAIL 4
fail_drain_pair:
  TEST_FAIL 5
fail_miss_first:
  TEST_FAIL 6
fail_miss_last:
  TEST_FAIL 7

.section .data
.balign 64
cold_gate:
  .word 0x31415926
.balign 64
store_line:
  .word 0
  .word 0
.balign 64
miss_lines:
  .space 1024
