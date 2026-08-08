#include "riscv-test.h"

.option arch, +m

.equ PLIC_PRIORITY_1, 0x0c000004
.equ PLIC_PENDING_0,  0x0c001000

.section .text
.globl main
.type main, @function
main:
  li t0, 0x7fffffff
  li t1, 3
  li s0, PLIC_PRIORITY_1
  li s1, PLIC_PENDING_0

  /*
   * Keep retirement behind both device operations.  The younger load may
   * execute after the store resolves, but it must not occupy the outbound
   * head in a way that prevents the older serialized store from draining.
   */
  div s2, t0, t1
  sw t1, 0(s0)
  lw s3, 0(s1)

  li t2, 0x2aaaaaaa
  bne s2, t2, fail_div

  /* The test also checks that making forward progress did not lose the store. */
  lw t3, 0(s0)
  bne t3, t1, fail_store
  TEST_PASS

fail_div:
  TEST_FAIL 1
fail_store:
  TEST_FAIL 2
