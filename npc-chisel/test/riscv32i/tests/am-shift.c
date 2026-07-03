#include "am_cpu_test.h"

static unsigned test[] = {
    0x12345678u, 0x98765432u, 0x0u, 0xeffa1000u, 0x7fffffffu, 0x80000000u, 0x33u, 0xffffffffu};

static unsigned srl_ans[] = {
    0x2468acu, 0x130eca8u, 0x0u, 0x1dff420u, 0xffffffu, 0x1000000u, 0x0u, 0x1ffffffu};

static unsigned srlv_ans[] = {
    0x1234567u, 0x4c3b2a1u, 0x0u, 0x1dff420u, 0x7fffffu, 0x400000u, 0x0u, 0x1fffffu};

static unsigned srav_ans[] = {
    0x1234567u, 0xfcc3b2a1u, 0x0u, 0xffdff420u, 0x7fffffu, 0xffc00000u, 0x0u, 0xffffffffu};

int main(void) {
  for (int i = 0; i < LENGTH(test); i++) {
    check((test[i] >> 7) == srl_ans[i]);
  }

  for (int i = 0; i < LENGTH(test); i++) {
    check((unsigned)((int)test[i] >> (i + 4)) == srav_ans[i]);
  }

  for (int i = 0; i < LENGTH(test); i++) {
    check((test[i] >> (i + 4)) == srlv_ans[i]);
  }

  return 0;
}
