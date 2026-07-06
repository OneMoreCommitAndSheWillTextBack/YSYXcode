#include "test.h"

static volatile u32 values[] = {84u, 360u, 1024u, 1729u, 9973u};
static const u32 expected[] = {61604u, 59167907u, 1311859008u, 7149u, 9973u};

static u32 factor_checksum(u32 value) {
  u32 factor = 2u;
  u32 checksum = 0u;

  while (factor * factor <= value) {
    while (value % factor == 0u) {
      checksum = checksum * 31u + factor;
      value /= factor;
    }

    factor = factor == 2u ? 3u : factor + 2u;
  }

  if (value > 1u) {
    checksum = checksum * 31u + value;
  }

  return checksum;
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    int check = expect_u32(factor_checksum(values[i]), expected[i], i + 1);
    if (check) return check;
  }

  return 0;
}
