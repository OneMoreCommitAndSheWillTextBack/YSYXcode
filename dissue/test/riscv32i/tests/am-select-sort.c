#include "am_cpu_test.h"

#define N 20

static int a[N] = {2, 12, 14, 6, 13, 15, 16, 10, 0, 18, 11, 19, 9, 1, 7, 5, 4, 3, 8, 17};

static void select_sort(void) {
  for (int i = 0; i < N - 1; i++) {
    int k = i;
    for (int j = i + 1; j < N; j++) {
      if (a[j] < a[k]) {
        k = j;
      }
    }

    int t = a[i];
    a[i] = a[k];
    a[k] = t;
  }
}

int main(void) {
  select_sort();
  for (int i = 0; i < N; i++) {
    check(a[i] == i);
  }

  select_sort();
  for (int i = 0; i < N; i++) {
    check(a[i] == i);
  }

  return 0;
}
