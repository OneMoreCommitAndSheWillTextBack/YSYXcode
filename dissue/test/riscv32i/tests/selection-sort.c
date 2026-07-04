#include "test.h"

static volatile s32 source_values[10] = {9, -2, 7, 0, 4, 4, -8, 11, 3, 1};
static const s32 expected_values[10] = {-8, -2, 0, 1, 3, 4, 4, 7, 9, 11};

static void selection_sort(s32 *data, int count) {
  for (int i = 0; i < count - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < count; j++) {
      if (data[j] < data[min_index]) {
        min_index = j;
      }
    }

    if (min_index != i) {
      s32 tmp = data[i];
      data[i] = data[min_index];
      data[min_index] = tmp;
    }
  }
}

int main(void) {
  s32 values[10];

  for (int i = 0; i < 10; i++) {
    values[i] = source_values[i];
  }

  selection_sort(values, 10);

  for (int i = 0; i < 10; i++) {
    if (values[i] != expected_values[i]) {
      return i + 1;
    }
  }

  return 0;
}
