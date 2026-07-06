#include "test.h"

static volatile s32 lhs[] = {3, -7, 12, -5, 9, -11, 6, 4};
static volatile s32 rhs[] = {-2, 8, 5, -6, -3, 10, 7, -9};

static s32 dot_product(int count) {
  s32 sum = 0;

  for (int i = 0; i < count; i++) {
    sum += lhs[i] * rhs[i];
  }

  return sum;
}

int main(void) {
  return expect_s32(dot_product(8), -103, 1);
}
