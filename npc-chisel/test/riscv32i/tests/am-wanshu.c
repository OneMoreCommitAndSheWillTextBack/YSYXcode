#include "am_cpu_test.h"

static int ans[] = {6, 28};

int main(void) {
  int k = 0;

  for (int n = 1; n < 30; n++) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
      if (am_mod_s32(n, i) == 0) {
        sum += i;
      }
    }

    if (sum == n) {
      check(n == ans[k]);
      k++;
    }
  }

  check(k == 2);
  return 0;
}
