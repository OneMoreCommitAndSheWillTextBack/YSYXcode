#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  la s0, wrong_path_line
  la t0, branch_value
  lw t1, 0(t0)
  li t2, 0x55667788
  li t3, 0x99aabbcc

  /* The cold-load-dependent taken branch is initially predicted not-taken. */
.balign 8
recovery_branch:
  beq t1, zero, recovered
.rept 12
  sw t2, 0(s0)
  sw t3, 4(s0)
.endr
  TEST_FAIL 1

recovered:
  lw t4, 0(s0)
  li t5, 0x11223344
  bne t4, t5, fail_wrong_word
  lw t4, 4(s0)
  li t5, 0xa5a5a5a5
  bne t4, t5, fail_wrong_pair

  /* Reusing the reclaimed entries proves recovery did not leak SQ capacity. */
.rept 24
  sw t2, 0(s0)
  sw t3, 4(s0)
.endr
  fence rw, rw
  lw t4, 0(s0)
  bne t4, t2, fail_reuse_word
  lw t4, 4(s0)
  bne t4, t3, fail_reuse_pair
  TEST_PASS

fail_wrong_word:
  TEST_FAIL 2
fail_wrong_pair:
  TEST_FAIL 3
fail_reuse_word:
  TEST_FAIL 4
fail_reuse_pair:
  TEST_FAIL 5

.section .data
.balign 64
branch_value:
  .word 0
.balign 64
wrong_path_line:
  .word 0x11223344
  .word 0xa5a5a5a5
