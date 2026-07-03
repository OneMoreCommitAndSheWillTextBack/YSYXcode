#include "test.h"

static volatile s32 a[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {-1, -2, -3, -4},
    {9, 10, 11, 12},
};

static volatile s32 b[4][4] = {
    {10, 20, 30, 40},
    {1, 2, 3, 4},
    {-5, -6, -7, -8},
    {7, 8, 9, 10},
};

static s32 c[4][4];

int main(void) {
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 4; col++) {
      c[row][col] = a[row][col] + b[col][row];
    }
  }

  s32 diagonal = 0;
  for (int i = 0; i < 4; i++) {
    diagonal += c[i][i];
  }

  int check = expect_s32(diagonal, 31, 1);
  if (check) return check;
  check = expect_s32(c[3][0], 49, 2);
  if (check) return check;
  return expect_s32(c[0][2], -2, 3);
}
