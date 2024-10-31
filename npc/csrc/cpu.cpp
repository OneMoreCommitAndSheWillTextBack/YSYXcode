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
    if (npc->state != RUNNING)
      return;
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
    break;
  default:
    npc->state = STOP;
  }
}

void set_npc_end() {
  int sig = npc->top->reg_out[10];

  if (sig == 0) {
    printf("hit the good-trap\n");
    npc->state = END;
  } else {
    printf("hit the bad-trap\n");
    npc->state = ABORT;
  }
}

void set_npc_quit() { npc->state = QUIT; }
