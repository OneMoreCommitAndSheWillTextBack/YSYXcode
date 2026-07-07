#include "riscv-test.h"

.option arch, +zicsr

.equ PLIC_BASE,       0x0c000000
.equ PLIC_PRIORITY_1, 0x0c000004
.equ PLIC_PENDING_0,  0x0c001000
.equ PLIC_ENABLE_M0,  0x0c002000
.equ PLIC_THRESH_M0,  0x0c200000
.equ PLIC_CLAIM_M0,   0x0c200004

.section .text
.globl main
.type main, @function
main:
  li t0, PLIC_PRIORITY_1
  li t1, 5
  sw t1, 0(t0)
  lw t2, 0(t0)
  beq t1, t2, 1f
  TEST_FAIL 1

1:
  li t0, PLIC_ENABLE_M0
  li t1, 2
  sw t1, 0(t0)
  lw t2, 0(t0)
  beq t1, t2, 2f
  TEST_FAIL 2

2:
  li t0, PLIC_THRESH_M0
  li t1, 3
  sw t1, 0(t0)
  lw t2, 0(t0)
  beq t1, t2, 3f
  TEST_FAIL 3

3:
  li t0, PLIC_PENDING_0
  lw t1, 0(t0)
  beqz t1, 4f
  TEST_FAIL 4

4:
  li t0, PLIC_CLAIM_M0
  lw t1, 0(t0)
  beqz t1, 5f
  TEST_FAIL 5

5:
  li t0, PLIC_BASE
  lw t1, 0(t0)
  beqz t1, 6f
  TEST_FAIL 6

6:
  TEST_PASS
