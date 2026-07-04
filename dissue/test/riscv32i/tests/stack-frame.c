#include "test.h"

static volatile int base_value = 3;

static s32 fill_and_sum(int base) {
  volatile s32 local[12];
  s32 sum = 0;

  for (int i = 0; i < 12; i++) {
    local[i] = base + i;
  }

  for (int i = 11; i >= 0; i--) {
    sum += local[i];
  }

  return sum;
}

int main(void) {
  return expect_s32(fill_and_sum(base_value), 102, 1);
}
