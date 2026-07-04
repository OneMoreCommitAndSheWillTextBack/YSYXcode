#include "am_cpu_test.h"

static int ans[] = {101, 103, 107, 109, 113, 127, 131, 137, 139, 149};

int main(void) {
  int n = 0;

  for (int m = 101; m <= 150; m += 2) {
    int prime = 1;
    int i;
    for (i = 2; i < m; i++) {
      if (am_mod_s32(m, i) == 0) {
        prime = 0;
        break;
      }
    }
    if (prime) {
      check(i == ans[n]);
      n++;
    }
  }

  check(n == 10);
  return 0;
}
