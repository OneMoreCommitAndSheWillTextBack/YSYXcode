#include "riscv-test.h"

.option arch, +zicsr

.equ CAUSE_LOAD_PAGE_FAULT, 13
.equ MSTATUS_MPRV, (1 << 17)
.equ PTE_V, 0x001
.equ PTE_R, 0x002
.equ PTE_W, 0x004
.equ PTE_X, 0x008
.equ PTE_A, 0x040
.equ PTE_D, 0x080
.equ PTE_RWXAD, (PTE_V | PTE_R | PTE_W | PTE_X | PTE_A | PTE_D)

.macro MAP_LABEL label, flags
  la t0, l0_pt
  la t1, \label
  srli t2, t1, 12
  andi t3, t2, 1023
  slli t4, t3, 2
  slli t2, t2, 10
  li t3, \flags
  or t2, t2, t3
  add t0, t0, t4
  sw t2, 0(t0)
.endm

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0
  csrw medeleg, zero
  la t0, seen
  sw zero, 0(t0)

  la t0, root_pt
  la t1, l0_pt
  srli t2, t1, 12
  slli t2, t2, 10
  ori t2, t2, PTE_V
  li t3, 0x80000000
  srli t4, t3, 22
  slli t4, t4, 2
  add t5, t0, t4
  sw t2, 0(t5)

  MAP_LABEL sup_data, PTE_RWXAD

  la t0, root_pt
  srli t0, t0, 12
  li t1, 0x80000000
  or t0, t0, t1
  csrw satp, t0
  sfence.vma zero, zero

  csrr t0, mstatus
  li t1, 0x1800
  not t1, t1
  and t0, t0, t1
  li t1, MSTATUS_MPRV
  or t0, t0, t1
  csrw mstatus, t0

  lla t0, sup_data
  lw t1, 0(t0)
  TEST_FAIL 2

after_fault:
  la t0, seen
  lw t1, 0(t0)
  li t2, 1
  beq t1, t2, 1f
  TEST_FAIL 1
1:
  TEST_PASS

.align 2
trap_handler:
  csrr t0, mcause
  li t1, CAUSE_LOAD_PAGE_FAULT
  beq t0, t1, 1f
  TEST_FAIL 20
1:
  csrr t0, mtval
  lla t1, sup_data
  beq t0, t1, 2f
  TEST_FAIL 21
2:
  csrr t0, mstatus
  li t1, MSTATUS_MPRV
  not t1, t1
  and t0, t0, t1
  csrw mstatus, t0
  csrw satp, zero
  sfence.vma zero, zero
  la t0, seen
  li t1, 1
  sw t1, 0(t0)
  la t0, after_fault
  csrw mepc, t0
  mret

.section .data
.align 2
seen:
  .word 0

.align 12
sup_data:
  .word 0x12345678

.section .bss
.align 12
root_pt:
  .space 4096
.align 12
l0_pt:
  .space 4096
