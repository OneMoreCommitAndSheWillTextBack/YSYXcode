#include "am_cpu_test.h"

static long long sub_ll(long long a, long long b) {
  return a - b;
}

static long long test_data[] = {
    0, 1, 2, 0x7fffffffffffffffLL, 0x8000000000000000LL, 0x8000000000000001LL,
    0xfffffffffffffffeLL, 0xffffffffffffffffLL};

static long long ans[] = {
    0LL, 0xffffffffffffffffLL, 0xfffffffffffffffeLL, 0x8000000000000001LL, 0x8000000000000000LL, 0x7fffffffffffffffLL, 0x2LL, 0x1LL,
    0x1LL, 0LL, 0xffffffffffffffffLL, 0x8000000000000002LL, 0x8000000000000001LL, 0x8000000000000000LL, 0x3LL, 0x2LL,
    0x2LL, 0x1LL, 0LL, 0x8000000000000003LL, 0x8000000000000002LL, 0x8000000000000001LL, 0x4LL, 0x3LL,
    0x7fffffffffffffffLL, 0x7ffffffffffffffeLL, 0x7ffffffffffffffdLL, 0LL, 0xffffffffffffffffLL, 0xfffffffffffffffeLL, 0x8000000000000001LL, 0x8000000000000000LL,
    0x8000000000000000LL, 0x7fffffffffffffffLL, 0x7ffffffffffffffeLL, 0x1LL, 0LL, 0xffffffffffffffffLL, 0x8000000000000002LL, 0x8000000000000001LL,
    0x8000000000000001LL, 0x8000000000000000LL, 0x7fffffffffffffffLL, 0x2LL, 0x1LL, 0LL, 0x8000000000000003LL, 0x8000000000000002LL,
    0xfffffffffffffffeLL, 0xfffffffffffffffdLL, 0xfffffffffffffffcLL, 0x7fffffffffffffffLL, 0x7ffffffffffffffeLL, 0x7ffffffffffffffdLL, 0LL, 0xffffffffffffffffLL,
    0xffffffffffffffffLL, 0xfffffffffffffffeLL, 0xfffffffffffffffdLL, 0x8000000000000000LL, 0x7fffffffffffffffLL, 0x7ffffffffffffffeLL, 0x1LL, 0LL};

int main(void) {
  int ans_idx = 0;

  for (int i = 0; i < LENGTH(test_data); i++) {
    for (int j = 0; j < LENGTH(test_data); j++) {
      check(sub_ll(test_data[i], test_data[j]) == ans[ans_idx++]);
    }
  }

  return 0;
}
