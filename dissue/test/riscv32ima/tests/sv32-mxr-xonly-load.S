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
.equ PTE_XAD, (PTE_V | PTE_X | PTE_A | PTE_D)
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
  la t0, fail_code
  sw zero, 0(t0)

  MAP_FIRST_PAGES 16
  MAP_LABEL xonly_data, PTE_XAD

  csrr t0, mstatus
  li t1, (1 << 19)
  or t0, t0, t1
  csrw mstatus, t0

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

after_s_return:
  csrw satp, zero
  sfence.vma zero, zero
  la t0, fail_code
  lw t1, 0(t0)
  beqz t1, 1f
  mv a0, t1
  ret
1:
  TEST_PASS

s_entry:
  la t0, xonly_data
  lw t1, 0(t0)
  li t2, 0x2468ace0
  beq t1, t2, 1f
  la t0, fail_code
  li t1, 2
  sw t1, 0(t0)
1:
  ecall

.align 2
trap_handler:
  csrr t0, mcause
  li t1, CAUSE_ECALL_S
  beq t0, t1, 1f
  li a0, 20
  ret
1:
  la t0, after_s_return
  csrw mepc, t0
  SET_MPP PRV_M
  mret

.section .data
.align 2
fail_code:
  .word 0

.align 12
xonly_data:
  .word 0x2468ace0

.section .bss
.align 12
root_pt:
  .space 4096
.align 12
l0_pt:
  .space 4096
