#include "test.h"

static volatile u8 pattern = 0x5au;
static u8 area[16];
static u8 copy[16];

static void fill(u8 *dst, int count, u8 value) {
  for (int i = 0; i < count; i++) {
    dst[i] = value;
  }
}

static void copy_bytes(u8 *dst, const u8 *src, int count) {
  for (int i = 0; i < count; i++) {
    dst[i] = src[i];
  }
}

int main(void) {
  u8 expected_pattern = pattern;

  fill(area, 16, expected_pattern);
  area[3] = 0xc3u;
  area[10] = 0x7eu;
  copy_bytes(copy, area, 16);

  int check = expect_u32(copy[0], 0x5au, 1);
  if (check) return check;
  check = expect_u32(copy[3], 0xc3u, 2);
  if (check) return check;
  check = expect_u32(copy[10], 0x7eu, 3);
  if (check) return check;

  u32 count_pattern = 0;
  for (int i = 0; i < 16; i++) {
    if (copy[i] == expected_pattern) {
      count_pattern++;
    }
  }

  return expect_u32(count_pattern, 14u, 4);
}
