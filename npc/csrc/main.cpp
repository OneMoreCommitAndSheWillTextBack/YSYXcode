#include <cstddef>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int main(int argc, char *argv[]) {
  init(argc, argv);

  sdb_main();

  return 0;
}
