#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  la t0, retained_value
  li t1, 0x00022750

  # The older load must survive recovery. The first encounter of this branch
  # has no BPU entry, so execution initially follows the fall-through path.
  lw t2, 0(t0)
  beq zero, zero, recovered_path

  # This address is outside PMEM. It is legal only if this wrong-path load is
  # removed before it can enter the memory hierarchy.
  lw t3, 0(t1)
  TEST_FAIL 1

recovered_path:
  li t4, 0x4d2
  bne t2, t4, load_lost
  TEST_PASS

load_lost:
  TEST_FAIL 2

.section .rodata
.balign 4
retained_value:
  .word 0x000004d2
