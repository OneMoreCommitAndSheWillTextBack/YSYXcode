#include <common.h>
#include "syscall.h"

static Context* do_event(Event e, Context* c) {
  switch (e.event) {
    case EVENT_YIELD:
      Log("yield, event id is 1");
      break;
    case EVENT_SYSCALL:
      Log("meet a syscall, event id is 2, syscall id is %d", c->gpr[17]);
      do_syscall(c);
      break;
    default: panic("Unhandled event ID = %d", e.event);
  }

  return c;
}

void init_irq(void) {
  Log("Initializing interrupt/exception handler...");
  cte_init(do_event);
}
