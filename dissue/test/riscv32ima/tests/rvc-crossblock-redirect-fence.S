#include "riscv-test.h"

.option arch, +c, +zifencei
.option rvc

.section .text
.globl main
.type main, @function
main:
  addi sp, sp, -16
  sw ra, 12(sp)
  li t0, 0
  call cross_redirect
  li t1, 17
  bne a0, t1, fail_redirect

  call patch_target
  li t1, 1
  bne a0, t1, fail_initial

  la t0, patch_instruction
  addi t0, t0, 2
  li t1, 0x0020
  sh t1, 0(t0)
  fence.i

  call patch_target
  li t1, 2
  bne a0, t1, fail_fence
  li a0, 0
  j done

fail_redirect:
  li a0, 1
  j done
fail_initial:
  li a0, 2
  j done
fail_fence:
  li a0, 3

done:
  lw ra, 12(sp)
  addi sp, sp, 16
  ret

.balign 8
cross_redirect:
  c.nop
  c.nop
  c.nop
.option norvc
cross_redirect_branch:
  beq t0, zero, cross_redirect_target
.option rvc
  c.li a0, 7
  c.jr ra

cross_redirect_target:
  c.li a0, 17
  c.jr ra

.balign 8
patch_target:
  c.nop
  c.nop
  c.nop
.option norvc
patch_instruction:
  addi a0, zero, 1
.option rvc
  c.jr ra
