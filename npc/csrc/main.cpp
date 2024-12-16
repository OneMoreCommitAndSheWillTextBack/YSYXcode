#include "common.h"

extern int times;
int main(int argc, char *argv[]) {
  init(argc, argv);

  if (batch_mode()) {
    cpu_exec(-1);
  } else {
    sdb_main();
  }

  printf("the times is %d\n", times);
  return 0;
}
