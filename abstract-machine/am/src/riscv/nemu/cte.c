#include <am.h>
#include <klib.h>
#include <riscv/riscv.h>
#include <stdint.h>

static Context *(*user_handler)(Event, Context *) = NULL;
void __am_get_cur_as(Context *c);
void __am_switch(Context *c);

Context *__am_irq_handle(Context *c) {
  // printf("into am irq handle, mcause is %d\n", c->mcause);
  __am_get_cur_as(c);
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      // clang-format off
      case -1:
        ev.event = EVENT_YIELD;
        break;
			case 1:
        if(c->gpr[17] == -1) 
          ev.event = EVENT_YIELD; 
        else
          ev.event = EVENT_SYSCALL;
        break;
      default: ev.event = EVENT_ERROR; break;
      // clang-format on
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  __am_switch(c);
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  // 这个减一不可以删掉，否则cp和context会重合，修改一个会导致另一个发生改变
  Context *context = (Context *)kstack.end - 1; 
  context->mstatus = 0x1800;
  context->mepc = (uintptr_t)entry;
  context->gpr[10] = (uintptr_t)arg;
  return context;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() { return false; }

void iset(bool enable) {}
