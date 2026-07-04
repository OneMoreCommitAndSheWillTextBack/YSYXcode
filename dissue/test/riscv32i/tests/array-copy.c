#include "test.h"

static volatile u32 source[8] = {1u, 3u, 5u, 7u, 9u, 11u, 13u, 15u};
static u32 dest[8];

int main(void) {
  for (int i = 0; i < 8; i++) {
    dest[i] = source[7 - i];
  }

  int check = expect_u32(dest[0], 15u, 1);
  if (check) return check;
  check = expect_u32(dest[7], 1u, 2);
  if (check) return check;

  u32 sum = 0;
  for (int i = 0; i < 8; i++) {
    sum += dest[i];
  }

  return expect_u32(sum, 64u, 3);
}
