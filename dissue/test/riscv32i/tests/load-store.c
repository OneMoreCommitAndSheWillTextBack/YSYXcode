#include "test.h"

static u32 data_words[4] = {
    0x11223344u,
    0x55667788u,
    0x99aabbccu,
    0xddeeff00u,
};

static u32 bss_words[4];

int main(void) {
  for (int i = 0; i < 4; i++) {
    if (bss_words[i] != 0) {
      return i + 1;
    }
  }

  bss_words[0] = data_words[3];
  bss_words[1] = data_words[2];
  bss_words[2] = data_words[1];
  bss_words[3] = data_words[0];

  int check = expect_u32(bss_words[0], 0xddeeff00u, 10);
  if (check) return check;
  check = expect_u32(bss_words[1], 0x99aabbccu, 11);
  if (check) return check;
  check = expect_u32(bss_words[2], 0x55667788u, 12);
  if (check) return check;
  check = expect_u32(bss_words[3], 0x11223344u, 13);
  if (check) return check;

  volatile u8 *bytes = (volatile u8 *)&bss_words[3];
  bytes[0] = 0xaa;
  bytes[1] = 0xbb;
  bytes[2] = 0xcc;
  bytes[3] = 0xdd;

  return expect_u32(bss_words[3], 0xddccbbaau, 20);
}
