#include "test.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;

static volatile s8 signed_bytes[3] = {-1, -128, 127};
static volatile u8 unsigned_bytes[3] = {0xffu, 0x80u, 0x7fu};
static volatile s16 signed_halves[3] = {-1, -32768, 32767};
static volatile u16 unsigned_halves[3] = {0xffffu, 0x8000u, 0x7fffu};

int main(void) {
  s32 byte_sum = 0;
  u32 unsigned_byte_sum = 0;
  s32 half_sum = 0;
  u32 unsigned_half_sum = 0;

  for (int i = 0; i < 3; i++) {
    byte_sum += signed_bytes[i];
    unsigned_byte_sum += unsigned_bytes[i];
    half_sum += signed_halves[i];
    unsigned_half_sum += unsigned_halves[i];
  }

  int check = expect_s32(byte_sum, -2, 1);
  if (check) return check;
  check = expect_u32(unsigned_byte_sum, 510u, 2);
  if (check) return check;
  check = expect_s32(half_sum, -2, 3);
  if (check) return check;
  return expect_u32(unsigned_half_sum, 131070u, 4);
}
