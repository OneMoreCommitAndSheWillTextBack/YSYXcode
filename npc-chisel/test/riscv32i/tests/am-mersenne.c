#include "am_cpu_test.h"

static int is_prime(int n) {
  int d = 5;

  if (am_mod_s32(n, 2) == 0) return n == 2;
  if (am_mod_s32(n, 3) == 0) return n == 3;

  while (am_mul_s32(d, d) <= n) {
    if (am_mod_s32(n, d) == 0) return 0;
    d += 2;
    if (am_mod_s32(n, d) == 0) return 0;
    d += 4;
  }

  return 1;
}

int main(void) {
  int d;
  int q = 929;
  uint32_t r;

  if (!is_prime(q)) {
    return 1;
  }

  r = (uint32_t)q;
  while ((s32)r > 0) {
    r <<= 1;
  }

  d = q + q + 1;
  do {
    int i = 1;
    for (uint32_t p = r; p != 0; p <<= 1) {
      i = (int)am_mul_mod_u32((uint32_t)i, (uint32_t)i, (uint32_t)d);
      if ((p & 0x80000000u) != 0) {
        i += i;
        if (i >= d) {
          i -= d;
        }
      }
    }
    if (i != 1) {
      d += q + q;
    } else {
      break;
    }
  } while (1);

  check(d == 13007);
  return 0;
}
