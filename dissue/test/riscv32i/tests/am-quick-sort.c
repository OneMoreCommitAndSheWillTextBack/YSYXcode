#include "am_cpu_test.h"

#define N 20

static int a[N] = {2, 12, 14, 6, 13, 15, 16, 10, 0, 18, 11, 19, 9, 1, 7, 5, 4, 3, 8, 17};

static int partition(int *data, int p, int q) {
  int pivot = data[p];
  int i = p;
  int j = q;

  while (i < j) {
    while (i < j && data[j] > pivot) j--;
    data[i] = data[j];

    while (i < j && data[i] <= pivot) i++;
    data[j] = data[i];
  }

  data[i] = pivot;
  return i;
}

static void quick_sort(int *data, int p, int q) {
  if (p >= q) {
    return;
  }

  int m = partition(data, p, q);
  quick_sort(data, p, m - 1);
  quick_sort(data, m + 1, q);
}

int main(void) {
  quick_sort(a, 0, N - 1);
  for (int i = 0; i < N; i++) {
    check(a[i] == i);
  }

  quick_sort(a, 0, N - 1);
  for (int i = 0; i < N; i++) {
    check(a[i] == i);
  }

  return 0;
}
