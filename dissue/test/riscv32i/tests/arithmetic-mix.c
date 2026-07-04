#include "test.h"

static volatile u32 seed_a = 1000u;
static volatile u32 seed_b = 257u;
static volatile u32 seed_c = 13u;

int main(void) {
  u32 x = seed_a;
  u32 y = seed_b;
  u32 z = seed_c;

  u32 r = x + y;
  r -= z;
  r += z << 5;
  r -= y >> 2;

  int check = expect_u32(r, 1596u, 1);
  if (check) return check;

  u32 wrapped = 0xfffffff0u + (z << 1);
  check = expect_u32(wrapped, 10u, 2);
  if (check) return check;

  s32 signed_value = (s32)z - 40;
  signed_value += 12;
  return expect_s32(signed_value, -15, 3);
}
