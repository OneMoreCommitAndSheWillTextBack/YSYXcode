#include "riscv-test.h"

.section .text
.globl main
.type main, @function
main:
  wfi
  TEST_PASS
