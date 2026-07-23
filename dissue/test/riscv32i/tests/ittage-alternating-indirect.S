#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  # Keep the crt0 return address while the test uses ra for every indirect call.
  mv s0, ra
  li s1, 0
  li s4, 0
  li s5, 0

  # Both targets are reached through the single jalr at indirect_call.  The
  # alternating result is correlated with the preceding indirect-path history,
  # so repeated iterations warm and reuse the same ITTAGE lookup site.
loop:
  andi t1, s1, 1
  beq t1, zero, select_target_a

select_target_b:
  la t0, indirect_target_b
  addi s5, s5, 3
  j indirect_call

select_target_a:
  la t0, indirect_target_a
  addi s5, s5, 1

indirect_call:
  jalr ra, 0(t0)
after_indirect_call:
  la t2, after_indirect_call
  bne ra, t2, fail_return_link
  bne s4, s5, fail_result

  addi s1, s1, 1
  li t3, 64
  blt s1, t3, loop

  li t4, 128
  bne s4, t4, fail_final_sum
  mv ra, s0
  TEST_PASS

indirect_target_a:
  addi s4, s4, 1
  jalr zero, 0(ra)

indirect_target_b:
  addi s4, s4, 3
  jalr zero, 0(ra)

fail_return_link:
  mv ra, s0
  TEST_FAIL 1

fail_result:
  mv ra, s0
  TEST_FAIL 2

fail_final_sum:
  mv ra, s0
  TEST_FAIL 3
