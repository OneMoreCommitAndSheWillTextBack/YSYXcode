#include "am_cpu_test.h"

#define STR "The quick brown fox jumps over the lazy dog"
#define STRLEN (sizeof(STR) - 1)

static uint32_t rc_crc32(uint32_t crc, const char *buf, size_t len) {
  static uint32_t table[256];
  static int have_table = 0;
  uint32_t rem;
  uint8_t octet;
  const char *p;
  const char *q;

  if (have_table == 0) {
    for (int i = 0; i < 256; i++) {
      rem = (uint32_t)i;
      for (int j = 0; j < 8; j++) {
        if ((rem & 1u) != 0) {
          rem >>= 1;
          rem ^= 0xedb88320u;
        } else {
          rem >>= 1;
        }
      }
      table[i] = rem;
    }
    have_table = 1;
  }

  crc = ~crc;
  q = buf + len;
  for (p = buf; p < q; p++) {
    octet = (uint8_t)*p;
    crc = (crc >> 8) ^ table[(crc & 0xffu) ^ octet];
  }
  return ~crc;
}

int main(void) {
  uint32_t res = rc_crc32(0, STR, STRLEN);
  check(res == 0x414fa339u);
  return 0;
}
