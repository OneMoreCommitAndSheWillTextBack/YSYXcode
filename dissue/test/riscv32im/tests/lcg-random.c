#include "test.h"

static volatile u32 seeds[] = {1u, 12345u, 0xdeadbeefu, 42u};
static volatile u32 rounds[] = {5u, 8u, 4u, 16u};
static volatile u32 limits[] = {97u, 1009u, 65521u, 4093u};
static volatile u32 multiplier = 1664525u;
static volatile u32 increment = 1013904223u;

static const u32 expected[] = {45u, 156u, 29517u, 750u};

static u32 lcg_mod(u32 seed, u32 count, u32 limit) {
  u32 value = seed;

  for (u32 i = 0u; i < count; i++) {
    value = value * multiplier + increment;
  }

  return value % limit;
}

int main(void) {
  for (int i = 0; i < 4; i++) {
    int check = expect_u32(lcg_mod(seeds[i], rounds[i], limits[i]),
                           expected[i], i + 1);
    if (check) return check;
  }

  return 0;
}
