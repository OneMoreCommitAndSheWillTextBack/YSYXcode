#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  # Preserve the crt0 return address while exercising indirect calls through
  # ordinary integer registers rather than a return-address register.
  mv s0, ra
  li s1, 0

  la t0, indirect_target_one
  jalr ra, 0(t0)
after_target_one:
  la t1, after_target_one
  bne ra, t1, fail_link_one
  li t1, 1
  bne s1, t1, fail_result_one

  la t0, indirect_target_two
  jalr ra, 0(t0)
after_target_two:
  la t1, after_target_two
  bne ra, t1, fail_link_two
  li t1, 3
  bne s1, t1, fail_result_two

  # A third distinct target makes the source register and target vary across
  # the calls.  The callee returns with the canonical JALR x0, 0(x1) form.
  la t2, indirect_target_three
  jalr ra, 0(t2)
after_target_three:
  la t1, after_target_three
  bne ra, t1, fail_link_three
  li t1, 6
  bne s1, t1, fail_result_three

  mv ra, s0
  TEST_PASS

indirect_target_one:
  addi s1, s1, 1
  jalr zero, 0(ra)

indirect_target_two:
  addi s1, s1, 2
  jalr zero, 0(ra)

indirect_target_three:
  addi s1, s1, 3
  jalr zero, 0(ra)

fail_link_one:
  mv ra, s0
  TEST_FAIL 1

fail_result_one:
  mv ra, s0
  TEST_FAIL 2

fail_link_two:
  mv ra, s0
  TEST_FAIL 3

fail_result_two:
  mv ra, s0
  TEST_FAIL 4

fail_link_three:
  mv ra, s0
  TEST_FAIL 5

fail_result_three:
  mv ra, s0
  TEST_FAIL 6
