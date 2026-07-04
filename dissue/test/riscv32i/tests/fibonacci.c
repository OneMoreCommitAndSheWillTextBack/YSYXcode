#include "test.h"

static volatile int fib_n = 12;

static s32 fibonacci(int n) {
  s32 a = 0;
  s32 b = 1;

  for (int i = 0; i < n; i++) {
    s32 next = a + b;
    a = b;
    b = next;
  }

  return a;
}

int main(void) {
  return expect_s32(fibonacci(fib_n), 144, 1);
}
