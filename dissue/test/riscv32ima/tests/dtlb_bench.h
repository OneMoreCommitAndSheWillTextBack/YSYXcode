#ifndef DTLB_BENCH_H
#define DTLB_BENCH_H

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

# 1 MiB data array: 256 4 KiB pages, or one 4 MiB superpage.
.equ ARRAY_WORDS, 262144
.equ ARRAY_BYTES, (ARRAY_WORDS * 4)
.equ PAGE_WORDS, 1024
.equ PAGE_COUNT, 256
.equ STRIDED_N, 1048576
.equ RANDOM_N, 1048576

#ifndef BENCH_MODE
#define BENCH_MODE 0
#endif
#ifndef SUPERPAGE
#define SUPERPAGE 0
#endif
#ifndef BENCH_N
#define BENCH_N ARRAY_WORDS
#endif

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
  la t0, bench_result
  sw zero, 0(t0)

#if SUPERPAGE
  # One 4 MiB leaf: 0x80000000..0x803fffff, identity-mapped.
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
#else
  # Second-level table: 1024 4 KiB leaves for the same 4 MiB window.
  la t0, l0_pt
  li t1, 0
  li t2, 1024
1:
  li t3, 0x80000000
  srli t3, t3, 12
  add t3, t3, t1
  slli t3, t3, 10
  li t4, PTE_RWXAD
  or t3, t3, t4
  slli t4, t1, 2
  add t4, t0, t4
  sw t3, 0(t4)
  addi t1, t1, 1
  blt t1, t2, 1b

  la t0, root_pt
  la t1, l0_pt
  srli t1, t1, 12
  slli t1, t1, 10
  ori t1, t1, PTE_V
  li t2, 0x80000000
  srli t2, t2, 22
  slli t2, t2, 2
  add t3, t0, t2
  sw t1, 0(t3)
#endif

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
  la t0, bench_result
  lw t1, 0(t0)
#if BENCH_MODE == 3
  li t2, 1
#else
  li t2, BENCH_N
#endif
  beq t1, t2, 1f
  TEST_FAIL 1
1:
  TEST_PASS

s_entry:
  la sp, bench_stack_top
  sfence.vma zero, zero
  la t0, bench_array
  li t1, 0
  li t2, 0
  li t3, BENCH_N
#if BENCH_MODE == 0
1:
  lw t4, 0(t0)
  add t1, t1, t4
  addi t0, t0, 4
  addi t2, t2, 1
  blt t2, t3, 1b
#elif BENCH_MODE == 1
1:
  andi t4, t2, 0xFF
  slli t4, t4, 10
  add t4, t4, t0
  lw t4, 0(t4)
  add t1, t1, t4
  addi t2, t2, 1
  blt t2, t3, 1b
#elif BENCH_MODE == 2
  li t5, 1
  li t6, 1103515245
  li a1, 12345
1:
  mul t5, t5, t6
  add t5, t5, a1
  srli t4, t5, 8
  andi t4, t4, 0xFF
  slli t4, t4, 10
  add t4, t4, t0
  lw t4, 0(t4)
  add t1, t1, t4
  addi t2, t2, 1
  blt t2, t3, 1b
#elif BENCH_MODE == 3
  li t1, 1
1:
  sw t1, 0(t0)
  addi t0, t0, 4
  addi t2, t2, 1
  blt t2, t3, 1b
#endif

  la t0, bench_result
  sw t1, 0(t0)
  ecall

.align 2
m_trap_handler:
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
bench_result:
  .word 0

.align 4
bench_array:
  .rept ARRAY_WORDS
  .word 1
  .endr

.section .bss
.align 4
bench_stack:
  .space 4096
bench_stack_top:

.align 12
root_pt:
  .space 4096

#if !SUPERPAGE
.align 12
l0_pt:
  .space 4096
#endif

#endif
