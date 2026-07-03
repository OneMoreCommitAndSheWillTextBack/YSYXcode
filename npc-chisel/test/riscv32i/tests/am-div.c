#include "am_cpu_test.h"

#define N 10

static int a[N];

int main(void) {
  for (int i = 0; i < N; i++) {
    a[i] = i;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N + 1; j++) {
      a[i] = am_mul_s32(a[i], j);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N + 1; j++) {
      a[i] = am_div_s32(a[i], j);
    }
  }

  for (int i = 0; i < N; i++) {
    check(a[i] == i);
  }

  return 0;
}
