#include "am_cpu_test.h"

static int ans[] = {153, 370, 371, 407};

static int cube(int n) {
  return am_mul_s32(am_mul_s32(n, n), n);
}

int main(void) {
  int k = 0;

  for (int n = 100; n < 500; n++) {
    int n2 = am_div_s32(n, 100);
    int n1 = am_mod_s32(am_div_s32(n, 10), 10);
    int n0 = am_mod_s32(n, 10);

    if (n == cube(n2) + cube(n1) + cube(n0)) {
      check(n == ans[k]);
      k++;
    }
  }

  check(k == 4);
  return 0;
}
