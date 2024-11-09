#include <cstddef>
#include <ios>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

extern bool batch_mode_on;
int main(int argc, char *argv[]) {
  init(argc, argv);

  batch_mode_on = true;
  if (batch_mode_on == false) {
    sdb_main();
  } else {
    cpu_exec(-1);
  }
  return 0;
}
