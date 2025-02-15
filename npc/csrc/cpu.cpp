#include "common.h"
#include <cassert>
#include <cstdint>
#include <stdio.h>
#include <string.h>

Npc *npc = NULL;
Cpu *cpu = NULL;
#ifdef TRACE
Trace *trace = NULL;
#endif

int times = 1;

void demp_wave() {
#ifdef TRACE
  trace->context->timeInc(1);
  trace->tfp->dump(trace->context->time());
#endif
}

static void exe_once() {
  npc->top->clock = 1;
  npc->top->eval();
  demp_wave();
  npc->top->clock = 0;
  npc->top->eval();
  demp_wave();
  times += 1;

#ifdef ITRACE
  char *p = cpu->logbuf;
  p += snprintf(p, sizeof(cpu->logbuf), "0x%08x:", cpu->con.pc);
  int i;
  p += snprintf(p, 10, " %08x", cpu->inst);
  memset(p, ' ', 1);
  p += 1;
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, cpu->logbuf + sizeof(cpu->logbuf) - p, cpu->con.pc,
              (uint8_t *)(&cpu->inst), 4);
#endif
}

static int start_diff = 0;
void trace_or_diff() {
  exe_wp();
#ifdef ITRACE
  printf("%s\n", cpu->logbuf);
#endif
#ifdef DIFFTEST
  if (start_diff < 1 && cpu->valid == 1)
    start_diff++;
  if (start_diff == 1 && cpu->valid == 1) {
    diff_step();
  }

#endif
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
    printf("hit the good-trap\n");
  case ABORT:
    if (npc->state == ABORT)
      printf("hit the bad-trap\n");
    printf("ended at pc = 0x%08x\n", cpu->con.pc);
    break;
  default:
    npc->state = STOP;
  }
}

void tfpclose() {
#ifdef TRACE
  trace->tfp->close();
#endif
}

void set_npc_end() {
  int sig = cpu->con.gpr[10];

  if (sig == 0) {
    npc->state = END;
  } else {
    npc->state = ABORT;
  }
  tfpclose();
}

void set_npc_quit() {
  tfpclose();
  npc->state = QUIT;
}

void set_npc_stop() { npc->state = STOP; }

void npc_diff_quit() {
  tfpclose();
  assert(0);
}

void set_diff_pass() { set_ref_skip(); }