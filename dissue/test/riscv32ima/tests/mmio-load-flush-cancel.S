#include "riscv-test.h"

.option arch, +m
.option arch, +zicsr

.equ MCAUSE_ECALL_M, 11
.equ PLIC_CLAIM_M0,  0x0c200004

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0
  li t0, 0x7fffffff
  li t1, 3
  li s0, PLIC_CLAIM_M0

  /*
   * DIV delays the ECALL trap long enough for the younger MMIO load to reach
   * the outbound head.  The padding keeps its old ROB index well beyond the
   * handler's RAM load, so a retained stale request cannot make progress by
   * accidental ROB-index reuse.
   */
  div s1, t0, t1
  ecall
  nop
  nop
  nop
  nop
  lw s2, 0(s0)
  TEST_FAIL 1

.balign 4
trap_handler:
  csrr t0, mcause
  li t1, MCAUSE_ECALL_M
  bne t0, t1, fail_cause

  /* This load must not sit behind the flushed MMIO transaction forever. */
  la t0, ram_word
  lw t1, 0(t0)
  li t2, 0x12345678
  bne t1, t2, fail_handler_load
  TEST_PASS

fail_cause:
  TEST_FAIL 2
fail_handler_load:
  TEST_FAIL 3

.section .data
.balign 4
ram_word:
  .word 0x12345678
