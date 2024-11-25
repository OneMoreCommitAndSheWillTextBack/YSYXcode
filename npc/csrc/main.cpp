#include "common.h"

int main(int argc, char *argv[]) {
  init(argc, argv);

  if (batch_mode()) {
    cpu_exec(-1);
  } else {
    sdb_main();
  }
  return 0;
}
