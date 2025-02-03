#include "common.h"

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data) {
  printf("call the function mrom_read\n");
  *data =  0b00000000000100000000000001110011;
}

extern int times;
extern Npc *npc;
int main(int argc, char *argv[]) {
  Verilated::commandArgs(argc, argv);
  init(argc, argv);

  if (batch_mode()) {
    cpu_exec(-1);
  } else {
    sdb_main();
  }

  printf("the times is %d\n", times);
  return (npc->state == QUIT | npc->state == END) ? 0 : -1;
}
