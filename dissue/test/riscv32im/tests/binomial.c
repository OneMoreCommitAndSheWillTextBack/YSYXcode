#include "test.h"

static volatile u32 ns[] = {10u, 12u, 16u, 20u, 21u};
static volatile u32 ks[] = {3u, 5u, 8u, 2u, 6u};
static const u32 expected[] = {120u, 792u, 12870u, 190u, 54264u};

static u32 binomial(u32 n, u32 k) {
  if (k > n - k) {
    k = n - k;
  }

  u32 result = 1u;
  for (u32 i = 1u; i <= k; i++) {
    result = (result * (n - k + i)) / i;
  }

  return result;
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    int check = expect_u32(binomial(ns[i], ks[i]), expected[i], i + 1);
    if (check) return check;
  }

  return 0;
}
