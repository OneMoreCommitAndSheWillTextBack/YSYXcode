#include "test.h"

static volatile s32 input_a = 19;
static volatile s32 input_b = -7;
static volatile s32 input_c = -5;

static s32 add3(s32 a, s32 b, s32 c) {
  return a + b + c;
}

static s32 abs32(s32 value) {
  return value < 0 ? -value : value;
}

static s32 clamp(s32 value, s32 lo, s32 hi) {
  if (value < lo) return lo;
  if (value > hi) return hi;
  return value;
}

static s32 accumulate_stride(s32 start, s32 step) {
  s32 sum = 0;
  s32 value = start;

  for (int i = 0; i < 6; i++) {
    sum += value;
    value += step;
  }

  return sum;
}

int main(void) {
  s32 a = input_a;
  s32 b = input_b;
  s32 c = input_c;

  s32 mixed = add3(a, b, c) - clamp(a - b, -20, 20) + abs32(c);
  int check = expect_s32(mixed, -8, 1);
  if (check) return check;

  return expect_s32(accumulate_stride(5, 4), 90, 2);
}
