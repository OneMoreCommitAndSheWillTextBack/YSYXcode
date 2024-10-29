#include "common.h"
#include <stdio.h>

Npc *npc = NULL;
static void exe_once() {
  npc->top->clk = 1;
  npc->top->eval();
  npc->top->clk = 0;
  npc->top->eval();
}

static void execute(unsigned int n) {
  while (n--) {
    exe_once();
  }
}

void cpu_exec(int n) {
  switch (npc->state) {
  case STOP:
    npc->state = RUNNING;
    break;
  case END:
  case ABORT:
    printf("the npc has finished, please restart the npc\n");
    return;
    break;
  default:
    npc->state = RUNNING;
  }

  execute((unsigned int)n);

  switch (npc->state) {
  case RUNNING:
    npc->state = STOP;
    break;
  case END:
  case ABORT:
    printf("ended at pc = 0x%08x\n", npc->top->pc_out);
  default:
    npc->state = STOP;
  }
}

void set_npc_end(int sig) {
  if (sig == 0)
    npc->state = END;
  else
    npc->state = ABORT;
}
