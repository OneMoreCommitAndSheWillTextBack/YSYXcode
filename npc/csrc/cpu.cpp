#include "common.h"
#include <cassert>
#include <cstdint>
#include <stdio.h>
#include <string.h>

Npc *npc = NULL;
Cpu *cpu = NULL;
static void exe_once() {
  npc->top->clk = 1;
  npc->top->eval();
  npc->top->clk = 0;
  npc->top->eval();

#ifndef ITRACE
  char *p = cpu->logbuf;
  p += snprintf(p, sizeof(cpu->logbuf), "0x%08x:", cpu->pc);
  int i;
  p += snprintf(p, 10, " %08x", cpu->inst);
  memset(p, ' ', 1);
  p += 1;
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, cpu->logbuf + sizeof(cpu->logbuf) - p, cpu->pc,
              (uint8_t *)(&cpu->inst), 4);
#endif
}

void trace_or_diff() {
  exe_wp();
  printf("%s\n", cpu->logbuf);
}

static void execute(unsigned int n) {
  while (n--) {
    exe_once();
    trace_or_diff();
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
void set_npc_stop() { npc->state = STOP; }
