# Sv32 4MB data superpage regression.
#
# The root page table entry is a leaf mapping the whole 0x80000000..0x803fffff
# region. The S-mode load/store must walk that leaf, fill a level-1 DTLB entry,
# and hit it afterwards. This covers the translator's pte/level/fill response and
# the DTLB's superpage address merge, not just the 4KB path.

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

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0
  csrw medeleg, zero
  la t0, result
  sw zero, 0(t0)

  # Root PTE for VPN[1] = 0x80000000 >> 22: a 4MB leaf mapping the same PA.
  la t0, root_pt
  li t1, 0x80000000
  srli t2, t1, 12
  slli t2, t2, 10
  li t3, PTE_RWXAD
  or t2, t2, t3
  li t4, 0x80000000
  srli t4, t4, 22
  slli t4, t4, 2
  add t5, t0, t4
  sw t2, 0(t5)

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
  la t0, super_data
  lw t1, 0(t0)
  li t2, 0x2468ace0
  bne t1, t2, s_fail
  li t3, 0x13579bdf
  sw t3, 0(t0)
  lw t4, 0(t0)
  bne t4, t3, s_fail

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

.align 2
super_data:
  .word 0x2468ace0

.section .bss
.align 12
root_pt:
  .space 4096
