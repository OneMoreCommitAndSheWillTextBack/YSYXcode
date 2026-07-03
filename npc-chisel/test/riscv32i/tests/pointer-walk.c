#include "test.h"

static volatile s32 values[9] = {5, -1, 8, 12, -7, 3, 0, 6, 9};

int main(void) {
  volatile s32 *p = values;
  volatile s32 *end = values + 9;
  s32 odd_sum = 0;
  s32 even_sum = 0;

  while (p < end) {
    s32 value = *p;
    if ((value & 1) != 0) {
      odd_sum += value;
    } else {
      even_sum += value;
    }
    p++;
  }

  int check = expect_s32(odd_sum, 9, 1);
  if (check) return check;
  check = expect_s32(even_sum, 26, 2);
  if (check) return check;
  return expect_s32(odd_sum + even_sum, 35, 3);
}
