#include "test.h"

static volatile int input_n = 15;

static s32 triangle(int n) {
  if (n <= 0) {
    return 0;
  }

  return n + triangle(n - 1);
}

int main(void) {
  return expect_s32(triangle(input_n), 120, 1);
}
