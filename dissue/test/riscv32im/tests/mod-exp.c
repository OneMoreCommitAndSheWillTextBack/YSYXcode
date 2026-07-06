#include "test.h"

static volatile u32 bases[] = {5u, 7u, 11u, 12345u, 65535u};
static volatile u32 exponents[] = {117u, 128u, 19u, 13u, 5u};
static volatile u32 moduli[] = {19u, 13u, 97u, 65521u, 257u};

static const u32 expected[] = {1u, 3u, 25u, 58824u, 0u};

static u32 mul_mod(u32 a, u32 b, u32 mod) {
  return (a * b) % mod;
}

static u32 pow_mod(u32 base, u32 exponent, u32 mod) {
  u32 result = 1u % mod;
  base %= mod;

  while (exponent != 0u) {
    if ((exponent & 1u) != 0u) {
      result = mul_mod(result, base, mod);
    }
    exponent >>= 1;
    base = mul_mod(base, base, mod);
  }

  return result;
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    int check = expect_u32(
        pow_mod(bases[i], exponents[i], moduli[i]), expected[i], i + 1);
    if (check) return check;
  }

  return 0;
}
