#include "test.h"

typedef unsigned short u16;

union Lane {
  u32 word;
  u16 half[2];
  u8 byte[4];
};

static volatile union Lane data;

int main(void) {
  data.word = 0;
  data.byte[0] = 0x11u;
  data.byte[1] = 0x22u;
  data.byte[2] = 0x33u;
  data.byte[3] = 0x44u;

  int check = expect_u32(data.word, 0x44332211u, 1);
  if (check) return check;

  data.half[1] = 0xabcdu;
  check = expect_u32(data.word, 0xabcd2211u, 2);
  if (check) return check;

  data.half[0] = 0x8001u;
  check = expect_u32(data.word, 0xabcd8001u, 3);
  if (check) return check;

  u32 low_half = data.half[0];
  return expect_u32(low_half, 0x8001u, 4);
}
