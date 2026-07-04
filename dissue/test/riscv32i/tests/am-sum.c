#include "am_cpu_test.h"

int main(void) {
  int i = 1;
  volatile int sum = 0;

  while (i <= 100) {
    sum += i;
    i++;
  }

  check(sum == 5050);
  return 0;
}
