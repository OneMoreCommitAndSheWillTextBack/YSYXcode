#include "am_cpu_test.h"

static int is_prime(int n) {
  if (n < 2) {
    return 0;
  }

  for (int i = 2; i < n; i++) {
    if (am_mod_s32(n, i) == 0) {
      return 0;
    }
  }

  return 1;
}

static int goldbach(int n) {
  for (int i = 2; i < n; i++) {
    if (is_prime(i) && is_prime(n - i)) {
      return 1;
    }
  }

  return 0;
}

int main(void) {
  for (int n = 4; n <= 30; n += 2) {
    check(goldbach(n) == 1);
  }

  return 0;
}
