#include "riscv-test.h"

.option arch, +zicsr

.equ PRV_M, 3
.equ PRV_S, 1
.equ CAUSE_LOAD_PAGE_FAULT, 13
.equ CAUSE_STORE_PAGE_FAULT, 15
.equ CAUSE_ECALL_S, 9
.equ PTE_V, 0x001
.equ PTE_R, 0x002
.equ PTE_W, 0x004
.equ PTE_X, 0x008
.equ PTE_A, 0x040
.equ PTE_D, 0x080
.equ PTE_RWXAD, (PTE_V | PTE_R | PTE_W | PTE_X | PTE_A | PTE_D)
.equ PTE_RWD_NOA, (PTE_V | PTE_R | PTE_W | PTE_D)
.equ PTE_RWA_NOD, (PTE_V | PTE_R | PTE_W | PTE_A)

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
  la t0, phase
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
  MAP_LABEL s_entry, PTE_RWXAD
  MAP_LABEL phase, PTE_RWXAD
  MAP_LABEL no_a_data, PTE_RWD_NOA
  MAP_LABEL no_d_data, PTE_RWA_NOD

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

after_s:
  csrw satp, zero
  sfence.vma zero, zero
  la t0, phase
  lw t1, 0(t0)
  li t2, 2
  beq t1, t2, 1f
  TEST_FAIL 1
1:
  TEST_PASS

s_entry:
  lla t0, phase
  li t1, 1
  sw t1, 0(t0)
  lla t0, no_a_data
  lw t1, 0(t0)
  TEST_FAIL 2
after_no_a:
  lla t0, phase
  li t1, 2
  sw t1, 0(t0)
  lla t0, no_d_data
  li t1, 0x33333333
  sw t1, 0(t0)
  TEST_FAIL 3
after_no_d:
  ecall

.align 2
trap_handler:
  csrr t0, mcause
  li t1, CAUSE_LOAD_PAGE_FAULT
  beq t0, t1, load_fault
  li t1, CAUSE_STORE_PAGE_FAULT
  beq t0, t1, store_fault
  li t1, CAUSE_ECALL_S
  beq t0, t1, s_ecall
  TEST_FAIL 20

load_fault:
  csrr t0, mtval
  la t1, no_a_data
  beq t0, t1, 1f
  TEST_FAIL 21
1:
  la t0, after_no_a
  csrw mepc, t0
  SET_MPP PRV_S
  mret

store_fault:
  csrr t0, mtval
  la t1, no_d_data
  beq t0, t1, 1f
  TEST_FAIL 22
1:
  la t0, after_no_d
  csrw mepc, t0
  SET_MPP PRV_S
  mret

s_ecall:
  la t0, after_s
  csrw mepc, t0
  SET_MPP PRV_M
  mret

.section .data
.align 2
phase:
  .word 0

.align 12
no_a_data:
  .word 0x11111111

.align 12
no_d_data:
  .word 0x22222222

.section .bss
.align 12
root_pt:
  .space 4096
.align 12
l0_pt:
  .space 4096
