#include "test.h"

static volatile s32 signal[] = {3, -2, 5, 7, -4, 1};
static volatile s32 kernel[] = {2, -3, 4};
static const s32 expected[] = {32, 9, -27, 30};

static s32 convolve_at(int offset) {
  s32 sum = 0;

  for (int i = 0; i < 3; i++) {
    sum += signal[offset + i] * kernel[i];
  }

  return sum;
}

int main(void) {
  for (int i = 0; i < 4; i++) {
    int check = expect_s32(convolve_at(i), expected[i], i + 1);
    if (check) return check;
  }

  return 0;
}
