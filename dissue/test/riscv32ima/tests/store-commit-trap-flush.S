#include "riscv-test.h"

.option arch, +zicsr

.equ MCAUSE_ECALL_M, 11

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0
  la s0, committed_word
  li s1, 0x6c737521
  li s2, 0

  /* Pairing these lets the store commit on the cycle that the trap flushes. */
.balign 8
commit_and_trap:
  sw s1, 0(s0)
  ecall

after_trap:
  li t0, 1
  bne s2, t0, fail_handler
  fence rw, rw
  lw t1, 0(s0)
  bne t1, s1, fail_store
  TEST_PASS

fail_handler:
  TEST_FAIL 1
fail_store:
  TEST_FAIL 2

.align 2
trap_handler:
  csrr t0, mcause
  li t1, MCAUSE_ECALL_M
  bne t0, t1, fail_cause
  csrr t0, mepc
  la t1, commit_and_trap
  addi t1, t1, 4
  bne t0, t1, fail_epc
  addi t0, t0, 4
  csrw mepc, t0
  li s2, 1
  mret

fail_cause:
  TEST_FAIL 3
fail_epc:
  TEST_FAIL 4

.section .data
.align 2
committed_word:
  .word 0x10203040
