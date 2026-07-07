#include "riscv-test.h"

.option arch, +a
.option arch, +zicsr

.equ CAUSE_LOAD_MISALIGNED, 4
.equ CAUSE_STORE_MISALIGNED, 6

.macro CHECK_EQ reg, imm, code
  li t6, \imm
  beq \reg, t6, 1f
  TEST_FAIL \code
1:
.endm

.section .text
.globl main
.type main, @function
main:
  la t0, trap_handler
  csrw mtvec, t0

  la t0, phase
  li t1, 1
  sw t1, 0(t0)
  la t0, word
  addi t0, t0, 1
  lr.w t1, (t0)
  TEST_FAIL 1
after_lr:
  la t0, phase
  li t1, 2
  sw t1, 0(t0)
  la t0, word
  addi t0, t0, 1
  li t2, 0x22222222
  sc.w t1, t2, (t0)
  TEST_FAIL 2
after_sc:
  la t0, phase
  li t1, 3
  sw t1, 0(t0)
  la t0, word
  addi t0, t0, 1
  li t2, 1
  amoadd.w t1, t2, (t0)
  TEST_FAIL 3
after_amo:
  la t0, word
  lw t1, 0(t0)
  CHECK_EQ t1, 0x11111111, 4
  TEST_PASS

.align 2
trap_handler:
  csrr t0, mcause
  csrr t1, mtval
  la t2, word
  addi t2, t2, 1
  beq t1, t2, 1f
  TEST_FAIL 10
1:
  la t2, phase
  lw t2, 0(t2)
  li t3, 1
  beq t2, t3, trap_lr
  li t3, 2
  beq t2, t3, trap_sc
  li t3, 3
  beq t2, t3, trap_amo
  TEST_FAIL 11

trap_lr:
  CHECK_EQ t0, CAUSE_LOAD_MISALIGNED, 12
  la t4, after_lr
  csrw mepc, t4
  mret

trap_sc:
  CHECK_EQ t0, CAUSE_STORE_MISALIGNED, 13
  la t4, after_sc
  csrw mepc, t4
  mret

trap_amo:
  CHECK_EQ t0, CAUSE_STORE_MISALIGNED, 14
  la t4, after_amo
  csrw mepc, t4
  mret

.section .data
.align 2
phase:
  .word 0
word:
  .word 0x11111111
