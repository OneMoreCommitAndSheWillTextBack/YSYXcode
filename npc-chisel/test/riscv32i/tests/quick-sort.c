#include "test.h"

static void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static void quick_sort(int *a, int lo, int hi) {
  int i = lo;
  int j = hi;
  int pivot = a[(lo + hi) >> 1];

  while (i <= j) {
    while (a[i] < pivot) i++;
    while (a[j] > pivot) j--;

    if (i <= j) {
      swap(&a[i], &a[j]);
      i++;
      j--;
    }
  }

  if (lo < j) quick_sort(a, lo, j);
  if (i < hi) quick_sort(a, i, hi);
}

int main(void) {
  int values[] = {31, -4, 17, 0, 99, 17, -100, 5, 42, 1, 8, -7};
  const int expected[] = {-100, -7, -4, 0, 1, 5, 8, 17, 17, 31, 42, 99};
  const int count = (int)(sizeof(values) / sizeof(values[0]));

  quick_sort(values, 0, count - 1);

  for (int i = 0; i < count; i++) {
    if (values[i] != expected[i]) {
      return i + 1;
    }
  }

  return 0;
}
