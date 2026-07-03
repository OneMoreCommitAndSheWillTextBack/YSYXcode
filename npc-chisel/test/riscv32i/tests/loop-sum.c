#include "test.h"

static volatile int limit = 20;

int main(void) {
  int n = limit;
  s32 alternating = 0;

  for (int i = 1; i <= n; i++) {
    if ((i & 1) != 0) {
      alternating += i;
    } else {
      alternating -= i;
    }
  }

  int check = expect_s32(alternating, -10, 1);
  if (check) return check;

  s32 masked_sum = 0;
  while (n > 0) {
    masked_sum += n & 3;
    n--;
  }

  check = expect_s32(masked_sum, 30, 2);
  if (check) return check;

  s32 odd_sum = 0;
  int step = 1;
  do {
    odd_sum += step;
    step += 2;
  } while (step < 10);

  return expect_s32(odd_sum, 25, 3);
}
