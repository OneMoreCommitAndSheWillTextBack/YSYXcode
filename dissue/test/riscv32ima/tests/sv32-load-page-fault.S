#include "riscv-test.h"

.option arch, +zicsr

.equ PRV_M, 3
.equ PRV_S, 1
.equ CAUSE_LOAD_PAGE_FAULT, 13
.equ BAD_ADDR, 0x80020000
.equ PTE_V, 0x001
.equ PTE_R, 0x002
.equ PTE_W, 0x004
.equ PTE_X, 0x008
.equ PTE_A, 0x040
.equ PTE_D, 0x080
.equ PTE_RWXAD, (PTE_V | PTE_R | PTE_W | PTE_X | PTE_A | PTE_D)

.macro SET_MPP mode
  csrr t5, mstatus
  li t6, 0x1800
  not t6, t6
  and t5, t5, t6
  li t6, ((\mode) << 11)
  or t5, t5, t6
  csrw mstatus, t5
.endm

.macro MAP_FIRST_PAGES count
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

  la t0, l0_pt
  li t1, 0
  li t6, \count
1:
  li t2, 0x80000000
  srli t2, t2, 12
  add t2, t2, t1
  slli t2, t2, 10
  li t3, PTE_RWXAD
  or t2, t2, t3
  slli t3, t1, 2
  add t4, t0, t3
  sw t2, 0(t4)
  addi t1, t1, 1
  blt t1, t6, 1b
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

  MAP_FIRST_PAGES 16

  la t0, root_pt
  srli t0, t0, 12
  li t1, 0x80000000
  or t0, t0, t1
  csrw satp, t0
  sfence.vma zero, zero

  la t0, s_entry
  csrw mepc, t0
  SET_MPP PRV_S
  mret

after_fault:
  la t0, seen
  lw t1, 0(t0)
  li t2, 1
  beq t1, t2, 1f
  TEST_FAIL 1
1:
  TEST_PASS

s_entry:
  li t0, BAD_ADDR
  lw t1, 0(t0)
  TEST_FAIL 2

.align 2
trap_handler:
  csrr t0, mcause
  li t1, CAUSE_LOAD_PAGE_FAULT
  beq t0, t1, 1f
  TEST_FAIL 20
1:
  csrr t0, mtval
  li t1, BAD_ADDR
  beq t0, t1, 2f
  TEST_FAIL 21
2:
  csrw satp, zero
  sfence.vma zero, zero
  la t0, seen
  li t1, 1
  sw t1, 0(t0)
  la t0, after_fault
  csrw mepc, t0
  SET_MPP PRV_M
  mret

.section .data
.align 2
seen:
  .word 0

.section .bss
.align 12
root_pt:
  .space 4096
.align 12
l0_pt:
  .space 4096
