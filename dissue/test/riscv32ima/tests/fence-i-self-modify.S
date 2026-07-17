#include "riscv-test.h"

.option arch, +zifencei

.section .text
.globl main
.type main, @function
main:
  addi sp, sp, -16
  sw ra, 12(sp)

  call patch_target
  li t0, 1
  bne a0, t0, 1f

  la t0, patch_target
  li t1, 0x00200513
  sw t1, 0(t0)
  fence.i

  call patch_target
  li t0, 2
  bne a0, t0, 2f
  li a0, 0
  j 3f

1:
  li a0, 1
  j 3f
2:
  li a0, 2
3:
  lw ra, 12(sp)
  addi sp, sp, 16
  ret

.align 2
patch_target:
  li a0, 1
  ret
