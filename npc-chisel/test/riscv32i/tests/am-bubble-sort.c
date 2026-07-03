#include "am_cpu_test.h"

#define N 20

static int a[N] = {2, 12, 14, 6, 13, 15, 16, 10, 0, 18, 11, 19, 9, 1, 7, 5, 4, 3, 8, 17};

static void bubble_sort(void) {
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N - 1 - j; i++) {
      if (a[i] > a[i + 1]) {
        int t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
      }
    }
  }
}

int main(void) {
  bubble_sort();
  for (int i = 0; i < N; i++) {
    check(a[i] == i);
  }

  bubble_sort();
  for (int i = 0; i < N; i++) {
    check(a[i] == i);
  }

  return 0;
}
