#include <cstddef>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int main(int argc, char **argv) {
  char *filepath = NULL;
  if (argc > 1) {
    filepath = argv[1];
  }
  init(filepath);

  cpu_exec(-1);

  return 0;
}
