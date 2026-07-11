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

  li t0, CLINT_MSIP
  li t1, 1
  sw t1, 0(t0)
  fence iorw, iorw

  li t0, MIE_MSIE
  csrw mie, t0
  csrr t0, mstatus
  ori t0, t0, MSTATUS_MIE
  csrw mstatus, t0

sync_read:
  csrr t2, mip
after_sync_read:
  /* Keep the younger instruction unresolved so the mip read retires alone. */
  div t4, t2, t1
  TEST_FAIL 1

after_interrupt:
  TEST_PASS

.align 2
trap_handler:
  csrr t0, mcause
  li t1, MCAUSE_MSI
  beq t0, t1, 1f
  TEST_FAIL 20
1:
  csrr t0, mepc
  la t1, after_sync_read
  beq t0, t1, 2f
  TEST_FAIL 21
2:
  andi t2, t2, MIE_MSIE
  bnez t2, 3f
  TEST_FAIL 22
3:
  li t0, CLINT_MSIP
  sw zero, 0(t0)
  fence iorw, iorw
  csrw mie, zero
  la t0, after_interrupt
  csrw mepc, t0
  mret
