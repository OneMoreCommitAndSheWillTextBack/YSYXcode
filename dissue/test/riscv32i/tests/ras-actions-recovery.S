#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  mv s0, ra

  # JAL x1: Push, followed by the canonical x1 return Pop.
  jal ra, jal_x1_target

  # JAL x5: Push, followed by the canonical x5 return Pop.
  jal t0, jal_x5_target

  # JAL x0 must not change the link state.
  mv t4, ra
  jal zero, jal_x0_target
jal_x0_after:
  bne ra, t4, fail_jal_x0

  # JALR rd !link, rs1 !link: None.
  la t1, jalr_none_after
  jalr zero, 0(t1)
  j fail_jalr_none
jalr_none_after:

  # JALR rd !link, rs1 link: Pop.
  jal ra, jalr_pop_target

  # JALR rd link, rs1 !link: Push.
  la t1, jalr_push_target
  jalr ra, 0(t1)

  # JALR distinct link registers: PopThenPush.
  la t0, jalr_pop_then_push_target
  jalr ra, 0(t0)

  # JALR matching link registers: Push.
  la ra, jalr_same_link_target
  jalr ra, 0(ra)

  # Nested x1/x5 calls preserve both return paths.
  jal ra, nested_x1_target

  # An execute redirect must discard any younger fetch checkpoint state.
  li t2, 0
  beq t2, zero, redirect_target
  jal ra, redirect_wrong_path

redirect_target:
  jal ra, redirect_call_target
  mv ra, s0
  TEST_PASS

jal_x1_target:
  jalr zero, 0(ra)

jal_x5_target:
  jalr zero, 0(t0)

jal_x0_target:
  jal zero, jal_x0_after

jalr_pop_target:
  jalr zero, 0(ra)

jalr_push_target:
  jalr zero, 0(ra)

jalr_pop_then_push_target:
  jalr zero, 0(ra)

jalr_same_link_target:
  jalr zero, 0(ra)

nested_x1_target:
  jal t0, nested_x5_target
  jalr zero, 0(ra)

nested_x5_target:
  jalr zero, 0(t0)

redirect_wrong_path:
  mv ra, s0
  TEST_FAIL 1

redirect_call_target:
  jalr zero, 0(ra)

fail_jal_x0:
  mv ra, s0
  TEST_FAIL 2

fail_jalr_none:
  mv ra, s0
  TEST_FAIL 3
