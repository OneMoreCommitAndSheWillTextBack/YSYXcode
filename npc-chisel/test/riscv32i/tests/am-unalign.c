#include "am_cpu_test.h"

static volatile unsigned x = 0xffffffffu;
static volatile unsigned char buf[16];

int main(void) {
  for (int i = 0; i < 4; i++) {
    am_store_u32_unaligned(buf + 3, 0xaabbccddu);

    x = am_load_u32_unaligned(buf + 3);
    check(x == 0xaabbccddu);

    buf[0] = 0;
    buf[1] = 0;
  }

  return 0;
}
