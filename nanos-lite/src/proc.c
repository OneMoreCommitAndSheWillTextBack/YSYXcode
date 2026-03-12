#include "am.h"
#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static int pcb_num = 0;
static PCB pcb_boot = {};
PCB *current = NULL;

void switch_boot_pcb() { current = &pcb_boot; }

void hello_fun(void *arg) {
  int j = 1;
  while (1) {
    Log("Hello World from Nanos-lite with arg '%s' for the %dth time!",
        (char *)arg, j);
    j++;
    yield();
  }
}

void context_kload(PCB *p, void (*entry)(void *), void *arg) {
  uint8_t *kstack_high = p->stack;
  Area kstack = { .end = kstack_high};
  p->cp = kcontext(kstack, entry, arg);
}

void init_proc() {
  switch_boot_pcb();

  Log("Initializing processes...");

  // naive_uload(NULL, "/bin/nterm");
  context_kload(&pcb[0], hello_fun, "A");
  context_kload(&pcb[1], hello_fun, "B");
  

}

Context *schedule(Context *prev) {
  int current = ((uintptr_t)prev - (uintptr_t)pcb) / sizeof(PCB);
  return pcb[(current + 1) / pcb_num].cp;
}
