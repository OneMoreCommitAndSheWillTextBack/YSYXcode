# Regression for a younger store entering the single LSU before an older load.
#
# The older load's address depends on a DIV result and is therefore not ready
# when the younger store issues. The store targets a different page and has to
# start a page-table walk. If the walk is gated on the store reaching the ROB
# head, the older load can never enter the LSU: the store waits for the load to
# retire, and the load waits for the LSU. The test must complete (or the
# harness times out) with both memory operations having retired.
#
# Deliberately no branch sits between the load and the store: a branch there
# would trigger the legacy unresolved-CFI LSU gate and hide the bug.

#include "riscv-test.h"

.option arch, +zicsr

.equ PRV_M, 3
.equ PRV_S, 1

.equ CAUSE_ECALL_S, 9

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
  la t0, result
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
  MAP_LABEL result, PTE_RWXAD
  MAP_LABEL old_data, PTE_RWXAD
  MAP_LABEL young_data, PTE_RWXAD

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

m_after_s:
  csrw satp, zero
  sfence.vma zero, zero
  la t0, result
  lw t1, 0(t0)
  li t2, 1
  beq t1, t2, 1f
  TEST_FAIL 1
1:
  TEST_PASS

s_entry:
  # Older load: its address depends on a 32-cycle DIV result.
  la a0, old_data
  li a1, 12288
  li a2, 3
  div a1, a1, a2
  sub a1, a0, a1
  li a5, 4096
  add a1, a1, a5
  lw t1, 0(a1)

  # Younger store: independent operands and a different page, so it can enter
  # the LSU first and has to walk the page table.
  la t0, young_data
  li t2, 0x55aa55aa
  sw t2, 0(t0)

  # This branch is younger than the store and cannot open the legacy CFI gate.
  li t3, 0x12345678
  bne t1, t3, s_fail
  lw t4, 0(t0)
  bne t4, t2, s_fail

  la t0, result
  li t1, 1
  sw t1, 0(t0)
  ecall

s_fail:
  la t0, result
  li t1, 2
  sw t1, 0(t0)
  ecall

.align 2
trap_handler:
  csrr t0, mcause
  li t1, CAUSE_ECALL_S
  beq t0, t1, 1f
  TEST_FAIL 20
1:
  la t0, m_after_s
  csrw mepc, t0
  SET_MPP PRV_M
  mret

.section .data
.align 2
result:
  .word 0

.align 12
old_data:
  .word 0x12345678

.align 12
young_data:
  .word 0

.section .bss
.align 12
root_pt:
  .space 4096
.align 12
l0_pt:
  .space 4096
