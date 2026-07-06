#include "test.h"

static volatile u32 values[] = {0u, 1u, 2u, 15u, 65535u, 1048576u,
                                2147395600u};
static const u32 expected[] = {0u, 1u, 1u, 3u, 255u, 1024u, 46340u};

static u32 integer_sqrt(u32 value) {
  if (value <= 1u) {
    return value;
  }

  u32 x = value;
  for (;;) {
    u32 next = (x + value / x) / 2u;
    if (next >= x) {
      return x;
    }
    x = next;
  }
}

int main(void) {
  for (int i = 0; i < 7; i++) {
    int check = expect_u32(integer_sqrt(values[i]), expected[i], i + 1);
    if (check) return check;
  }

  return 0;
}
