#include "test.h"

static volatile u32 input_a[] = {462u, 81u, 221u, 1024u};
static volatile u32 input_b[] = {1071u, 153u, 391u, 768u};

static const u32 expected_gcd[] = {21u, 9u, 17u, 256u};
static const u32 expected_lcm[] = {23562u, 1377u, 5083u, 3072u};

static u32 gcd_u32(u32 a, u32 b) {
  while (b != 0u) {
    u32 r = a % b;
    a = b;
    b = r;
  }

  return a;
}

static u32 lcm_u32(u32 a, u32 b) {
  u32 g = gcd_u32(a, b);
  return (a / g) * b;
}

int main(void) {
  for (int i = 0; i < 4; i++) {
    u32 a = input_a[i];
    u32 b = input_b[i];

    int check = expect_u32(gcd_u32(a, b), expected_gcd[i], i + 1);
    if (check) return check;

    check = expect_u32(lcm_u32(a, b), expected_lcm[i], i + 11);
    if (check) return check;
  }

  return 0;
}
