#include "am_cpu_test.h"

static long long mul_ll(int a, int b) {
  return am_mul_s32_to_s64(a, b);
}

static int test_data[] = {0xaeb1c2aa, 0x4500ff2b, 0x877190af, 0x11f42438};
static long long ans[] = {
    0x19d29ab9db1a18e4LL, 0xea15986d3ac3088eLL, 0x2649e980fc0db236LL, 0xfa4c43da0a4a7d30LL,
    0x1299898e2c56b139LL, 0xdf8123d50a319e65LL, 0x4d6dfa84c15dd68LL, 0x38c5d79b9e4357a1LL,
    0xf78b91cb1efc4248LL, 0x14255a47fdfcc40LL};

int main(void) {
  int ans_idx = 0;

  for (int i = 0; i < LENGTH(test_data); i++) {
    for (int j = i; j < LENGTH(test_data); j++) {
      check(ans[ans_idx++] == mul_ll(test_data[i], test_data[j]));
    }
  }

  return 0;
}
