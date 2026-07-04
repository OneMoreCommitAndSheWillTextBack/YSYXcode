#include "test.h"

static const s32 sorted_values[9] = {-9, -3, 0, 4, 8, 12, 17, 23, 42};
static volatile s32 target_hit = 17;
static volatile s32 target_miss = 6;
static volatile s32 target_first = -9;

static int binary_search(s32 target) {
  int lo = 0;
  int hi = 8;

  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    s32 value = sorted_values[mid];

    if (value == target) {
      return mid;
    }
    if (value < target) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return -1;
}

int main(void) {
  int check = expect_s32(binary_search(target_hit), 6, 1);
  if (check) return check;
  check = expect_s32(binary_search(target_miss), -1, 2);
  if (check) return check;
  return expect_s32(binary_search(target_first), 0, 3);
}
