#include "riscv-test.h"

.option arch, +zicsr
.option arch, +zifencei

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
  la t0, m_trap_handler
  csrw mtvec, t0
  csrw medeleg, zero

  la t0, fail_code
  sw zero, 0(t0)
  la t0, s_mode_done
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
  li t6, 4
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

  la t0, fail_code
  lw t1, 0(t0)
  beqz t1, 2f
  mv a0, t1
  ret
2:
  la t0, s_mode_done
  lw t1, 0(t0)
  li t2, 0x13572468
  beq t1, t2, 3f
  TEST_FAIL 10
3:
  TEST_PASS

s_mode_entry:
  sfence.vma zero, zero
  la t0, s_mode_done
  li t1, 0x13572468
  sw t1, 0(t0)
  lw t2, 0(t0)
  beq t1, t2, 4f
  li t3, 2
  la t0, fail_code
  sw t3, 0(t0)
4:
  # Keep a younger store ready while an older load waits on a division result.
  # The following branch depends on that load, so the store must not occupy the
  # single LSU and block its own speculative page-table walk behind the branch.
  la a0, s_mode_done
  li a1, 12288
  li a2, 3
  li a4, 0x2468ace1
  li a5, 4096
  div a1, a1, a2
  sub a1, a0, a1
  add a1, a1, a5
  lw a3, 0(a1)
  beq a3, zero, sv32_liveness_fail
  sw a4, 4(a0)
  lw a5, 4(a0)
  bne a4, a5, sv32_liveness_fail
  j sv32_liveness_done

sv32_liveness_fail:
  li t3, 3
  la t0, fail_code
  sw t3, 0(t0)
sv32_liveness_done:
  fence
  fence.i
  ecall

.align 2
m_trap_handler:
  csrr t0, mcause
  li t1, CAUSE_ECALL_S
  beq t0, t1, 5f
  li a0, 20
  ret
5:
  la t0, m_after_s_return
  csrw mepc, t0
  SET_MPP PRV_M
  mret

.section .data
.align 2
fail_code:
  .word 0
s_mode_done:
  .word 0

.section .bss
.align 12
root_pt:
  .space 4096
.align 12
l0_pt:
  .space 4096
