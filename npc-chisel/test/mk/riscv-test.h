#ifndef NPC_TEST_RISCV_TEST_H
#define NPC_TEST_RISCV_TEST_H

.macro TEST_PASS
  li a0, 0
  ret
.endm

.macro TEST_FAIL code
  li a0, \code
  ret
.endm

#endif
