#include "test.h"

static volatile s32 a[3][3] = {
    {2, -3, 4},
    {5, 0, -1},
    {-2, 7, 3},
};

static volatile s32 b[3][3] = {
    {1, 6, -2},
    {-4, 3, 5},
    {7, -1, 2},
};

static const s32 expected[3][3] = {
    {42, -1, -11},
    {-2, 31, -12},
    {-9, 6, 45},
};

int main(void) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      s32 sum = 0;
      for (int k = 0; k < 3; k++) {
        sum += a[row][k] * b[k][col];
      }

      int code = row * 3 + col + 1;
      int check = expect_s32(sum, expected[row][col], code);
      if (check) return check;
    }
  }

  return 0;
}
