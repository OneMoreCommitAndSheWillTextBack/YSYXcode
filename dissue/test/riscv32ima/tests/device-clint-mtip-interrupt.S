#include "riscv-test.h"

.option arch, +zicsr

.equ CLINT_MTIMECMP, 0x02004000
.equ MSTATUS_MIE, (1 << 3)
.equ MIE_MTIE, (1 << 7)
.equ MCAUSE_MTI, 0x80000007

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0
  la t0, seen
  sw zero, 0(t0)

  li t0, CLINT_MTIMECMP
  sw zero, 4(t0)
  sw zero, 0(t0)

  li t0, MIE_MTIE
  csrw mie, t0
  csrr t0, mstatus
  li t1, MSTATUS_MIE
  or t0, t0, t1
  csrw mstatus, t0

  nop
  nop
  TEST_FAIL 1

after_interrupt:
  la t0, seen
  lw t1, 0(t0)
  li t2, 1
  beq t1, t2, 1f
  TEST_FAIL 2
1:
  TEST_PASS

.align 2
trap_handler:
  csrr t0, mcause
  li t1, MCAUSE_MTI
  beq t0, t1, 1f
  TEST_FAIL 20
1:
  li t0, CLINT_MTIMECMP
  li t1, -1
  sw t1, 0(t0)
  sw t1, 4(t0)
  csrw mie, zero
  csrr t0, mstatus
  li t1, MSTATUS_MIE
  not t1, t1
  and t0, t0, t1
  csrw mstatus, t0
  la t0, seen
  li t1, 1
  sw t1, 0(t0)
  la t0, after_interrupt
  csrw mepc, t0
  mret

.section .data
.align 2
seen:
  .word 0
