#include "riscv-test.h"

.option arch, +zicsr

.equ CLINT_MTIMECMP, 0x02004000
.equ MSTATUS_MRET_TO_S, 0x00000880
.equ MIE_MTIE, (1 << 7)
.equ MCAUSE_MTI, 0x80000007

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0

  la s0, word
  sw zero, 0(s0)
  li a3, 0
  li a4, 1
  lr.w a5, (s0)
  bnez a5, fail_lr

  /* Make MTIP pending while MIE is clear. */
  li t0, CLINT_MTIMECMP
  li t1, 0
  sw t1, 4(t0)
  sw zero, 0(t0)
  li t0, MIE_MTIE
  csrw mie, t0

  /* Enter S-mode; M-mode timer interrupts are globally enabled below M-mode. */
  li t0, MSTATUS_MRET_TO_S
  csrw mstatus, t0
  la t0, before_sc
  csrw mepc, t0
  mret

before_sc:
  addi t6, t6, 0
sc_site:
  sc.w a3, a4, (s0)
  TEST_FAIL 1

after_interrupt:
  bnez a3, fail_a3
  la t0, seen
  lw t1, 0(t0)
  li t2, 1
  bne t1, t2, fail_seen
  lw t0, 0(s0)
  bnez t0, fail_store
  TEST_PASS

fail_lr:
  TEST_FAIL 10
fail_a3:
  TEST_FAIL 11
fail_seen:
  TEST_FAIL 12
fail_store:
  TEST_FAIL 13

.align 2
trap_handler:
  addi sp, sp, -160
  sw ra, 4(sp)
  sw gp, 12(sp)
  sw tp, 16(sp)
  sw t1, 24(sp)
  sw t2, 28(sp)
  sw s0, 32(sp)
  sw s1, 36(sp)
  sw a0, 40(sp)
  sw a1, 44(sp)
  sw a2, 48(sp)
  sw a3, 52(sp)
  sw a4, 56(sp)
  sw a5, 60(sp)
  sw a6, 64(sp)
  sw a7, 68(sp)
  sw s2, 72(sp)
  sw s3, 76(sp)
  sw s4, 80(sp)
  sw s5, 84(sp)
  sw s6, 88(sp)
  sw s7, 92(sp)
  sw s8, 96(sp)
  sw s9, 100(sp)
  sw s10, 104(sp)
  sw s11, 108(sp)
  sw t3, 112(sp)
  sw t4, 116(sp)
  sw t5, 120(sp)
  sw t6, 124(sp)

  csrr t0, mcause
  li t1, MCAUSE_MTI
  bne t0, t1, fail_cause
  csrr t0, mepc
  la t1, sc_site
  bne t0, t1, fail_epc

  li t0, CLINT_MTIMECMP
  li t1, -1
  sw t1, 4(t0)
  sw t1, 0(t0)
  csrw mie, zero

  la t0, seen
  li t1, 1
  sw t1, 0(t0)
  lw a3, 52(sp)
  addi sp, sp, 160
  la t0, after_interrupt
  csrw mepc, t0
  mret

fail_cause:
  li a0, 20
  ret
fail_epc:
  li a0, 21
  ret

.section .data
.align 2
word:
  .word 0
seen:
  .word 0
