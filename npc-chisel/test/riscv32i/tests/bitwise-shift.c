#include "test.h"

static volatile u32 seed = 0x00ff00f0u;

int main(void) {
  u32 x = seed;

  int check = expect_u32(x & 0x0000ffffu, 0x000000f0u, 1);
  if (check) return check;
  check = expect_u32(x | 0xf000000fu, 0xf0ff00ffu, 2);
  if (check) return check;
  check = expect_u32(x ^ 0x0f0f0f0fu, 0x0ff00fffu, 3);
  if (check) return check;

  u32 mixed = ((x & 0xffu) << 8) | (x >> 12);
  check = expect_u32(mixed, 0x0000fff0u, 4);
  if (check) return check;

  s32 arithmetic = (s32)0xf0000000u >> 4;
  return expect_u32((u32)arithmetic, 0xff000000u, 5);
}
