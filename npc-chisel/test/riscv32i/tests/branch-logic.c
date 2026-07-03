#include "test.h"

static volatile s32 values[6] = {7, -3, 0, 12, -8, 5};

int main(void) {
  int positives = 0;
  int nonpositives = 0;
  s32 score = 0;

  for (int i = 0; i < 6; i++) {
    s32 value = values[i];
    if (value > 0 && value < 10) {
      positives++;
      score += value;
    } else if (value <= 0) {
      nonpositives++;
      score -= value;
    } else {
      score += 1;
    }
  }

  int check = expect_s32(positives, 2, 1);
  if (check) return check;
  check = expect_s32(nonpositives, 3, 2);
  if (check) return check;
  return expect_s32(score, 24, 3);
}
