#include "riscv-test.h"

.option arch, +zicsr

.equ PRV_M, 3
.equ PRV_S, 1
.equ CAUSE_INSTR_PAGE_FAULT, 12
.equ MSTATUS_SUM, (1 << 18)
.equ PTE_V, 0x001
.equ PTE_R, 0x002
.equ PTE_W, 0x004
.equ PTE_X, 0x008
.equ PTE_U, 0x010
.equ PTE_A, 0x040
.equ PTE_D, 0x080
.equ PTE_RWXAD, (PTE_V | PTE_R | PTE_W | PTE_X | PTE_A | PTE_D)
.equ PTE_URWXAD, (PTE_RWXAD | PTE_U)

.macro SET_MPP mode
  csrr t5, mstatus
  li t6, 0x1800
  not t6, t6
  and t5, t5, t6
  li t6, ((\mode) << 11)
  or t5, t5, t6
  csrw mstatus, t5
.endm

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

  MAP_LABEL main, PTE_RWXAD
  MAP_LABEL trap_handler, PTE_RWXAD
  MAP_LABEL user_target, PTE_URWXAD

  csrr t0, mstatus
  li t1, MSTATUS_SUM
  or t0, t0, t1
  csrw mstatus, t0

  la t0, root_pt
  srli t0, t0, 12
  li t1, 0x80000000
  or t0, t0, t1
  csrw satp, t0
  sfence.vma zero, zero

  la t0, user_target
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

.align 2
trap_handler:
  csrr t0, mcause
  li t1, CAUSE_INSTR_PAGE_FAULT
  beq t0, t1, 1f
  TEST_FAIL 20
1:
  csrr t0, mtval
  la t1, user_target
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

.align 12
user_target:
  TEST_FAIL 2

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
