#include "riscv-test.h"

.option arch, +zicsr

.equ PRV_M, 3
.equ PRV_S, 1
.equ CAUSE_ECALL_S, 9
.equ TARGET_VA, 0x80040000

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

.macro MAKE_PTE target, flags
  la t2, \target
  srli t2, t2, 12
  slli t2, t2, 10
  li t3, \flags
  or t2, t2, t3
.endm

.section .text
.globl main
.type main, @function
main:
  mv s0, ra
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

  la t0, l0_pt
  li t1, 0
  li t6, 32
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

  la t0, l0_pt
  li t1, 64
  slli t1, t1, 2
  add t0, t0, t1
  MAKE_PTE target_a, PTE_RWXAD
  sw t2, 0(t0)

  la t0, root_pt
  srli t0, t0, 12
  li t1, 0x80000000
  or t0, t0, t1
  csrw satp, t0
  sfence.vma zero, zero

  la t0, s_mode_entry
  csrw mepc, t0
  SET_MPP PRV_S
  mret

m_after_s_return:
  csrw satp, zero
  sfence.vma zero, zero
  la t0, result
  lw t1, 0(t0)
  li t2, 3
  beq t1, t2, 2f
  mv ra, s0
  TEST_FAIL 1
2:
  mv ra, s0
  TEST_PASS

s_mode_entry:
  li t0, TARGET_VA
  jalr ra, t0, 0
  li t1, 1
  bne a0, t1, s_fail

  la t0, l0_pt
  li t1, 64
  slli t1, t1, 2
  add t0, t0, t1
  MAKE_PTE target_b, PTE_RWXAD
  sw t2, 0(t0)
  sfence.vma zero, zero

  li t0, TARGET_VA
  jalr ra, t0, 0
  li t1, 2
  bne a0, t1, s_fail

  la t0, result
  li t1, 3
  sw t1, 0(t0)
  ecall

s_fail:
  la t0, result
  li t1, 4
  sw t1, 0(t0)
  ecall

.align 2
trap_handler:
  csrr t0, mcause
  li t1, CAUSE_ECALL_S
  beq t0, t1, 3f
  TEST_FAIL 20
3:
  la t0, m_after_s_return
  csrw mepc, t0
  SET_MPP PRV_M
  mret

.align 12
target_a:
  li a0, 1
  ret

.align 12
target_b:
  li a0, 2
  ret

.section .data
.align 2
result:
  .word 0

.section .bss
.align 12
root_pt:
  .space 4096
.align 12
l0_pt:
  .space 4096
