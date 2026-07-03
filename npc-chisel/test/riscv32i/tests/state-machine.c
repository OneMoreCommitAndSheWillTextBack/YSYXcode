#include "test.h"

static volatile char text[] = "a12+b7-c03";

static void commit_number(int has_number, int sign, s32 current, s32 *sum) {
  if (!has_number) {
    return;
  }

  if (sign > 0) {
    *sum += current;
  } else {
    *sum -= current;
  }
}

int main(void) {
  s32 sum = 0;
  s32 current = 0;
  int sign = 1;
  int has_number = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    char ch = text[i];

    if (ch >= '0' && ch <= '9') {
      current = (current << 3) + (current << 1) + (ch - '0');
      has_number = 1;
    } else {
      commit_number(has_number, sign, current, &sum);
      current = 0;
      has_number = 0;

      if (ch == '-') {
        sign = -1;
      } else if (ch == '+') {
        sign = 1;
      }
    }
  }

  commit_number(has_number, sign, current, &sum);
  return expect_s32(sum, 16, 1);
}
