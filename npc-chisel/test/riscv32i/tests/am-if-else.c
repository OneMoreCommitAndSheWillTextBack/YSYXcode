#include "am_cpu_test.h"

static int if_else(int n) {
  int cost;
  if (n > 500) cost = 150;
  else if (n > 300) cost = 100;
  else if (n > 100) cost = 75;
  else if (n > 50) cost = 50;
  else cost = 0;

  return cost;
}

static int test_data[] = {-1, 0, 49, 50, 51, 99, 100, 101, 299, 300, 301, 499, 500, 501};
static int ans[] = {0, 0, 0, 0, 50, 50, 50, 75, 75, 75, 100, 100, 100, 150};

int main(void) {
  for (int i = 0; i < LENGTH(test_data); i++) {
    check(if_else(test_data[i]) == ans[i]);
  }

  return 0;
}
