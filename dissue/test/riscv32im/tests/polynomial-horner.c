#include "test.h"

static volatile s32 xs[] = {-3, -1, 0, 2, 5};
static volatile s32 coeffs[] = {3, -4, 0, 7, -2};
static const s32 expected[] = {328, -2, -2, 28, 1408};

static s32 eval_poly(s32 x) {
  s32 acc = 0;

  for (int i = 0; i < 5; i++) {
    acc = acc * x + coeffs[i];
  }

  return acc;
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    int check = expect_s32(eval_poly(xs[i]), expected[i], i + 1);
    if (check) return check;
  }

  return 0;
}
