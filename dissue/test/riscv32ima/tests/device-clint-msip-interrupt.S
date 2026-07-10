#include "riscv-test.h"

.option arch, +zicsr

.equ CLINT_MSIP, 0x02000000
.equ MSTATUS_MIE, (1 << 3)
.equ MIE_MSIE, (1 << 3)
.equ MCAUSE_MSI, 0x80000003

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0
  la t0, seen
  sw zero, 0(t0)

  li t0, CLINT_MSIP
  li t1, 1
  sw t1, 0(t0)
  fence iorw, iorw

  csrr t2, mip
  andi t2, t2, MIE_MSIE
  bnez t2, 1f
  TEST_FAIL 3
1:

  li t0, MIE_MSIE
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
  li t1, MCAUSE_MSI
  beq t0, t1, 1f
  TEST_FAIL 20
1:
  li t0, CLINT_MSIP
  sw zero, 0(t0)
  fence iorw, iorw
  csrr t2, mip
  andi t2, t2, MIE_MSIE
  beqz t2, 2f
  TEST_FAIL 21
2:
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
