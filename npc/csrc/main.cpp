#include "common.h"

extern int times;
extern Npc *npc;
int main(int argc, char *argv[]) {
  init(argc, argv);

  if (batch_mode()) {
    cpu_exec(-1);
  } else {
    sdb_main();
  }

  printf("the times is %d\n", times);
  return (npc->state == QUIT) ? 0 : -1;
}
