#include <am.h>
#include <klib.h>
#include <riscv/riscv.h>
#include <stdint.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c) {
  // printf("into am irq handle, mcause is %d\n", c->mcause);
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      // clang-format off
      case -1: ev.event = EVENT_YIELD; break;
      default: ev.event = EVENT_ERROR; break;
      // clang-format on
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

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
  uintptr_t *tmp = (uintptr_t *)kstack.end;

  *tmp = 0; // pdir = 0x1800
  tmp--;
  *tmp = (uintptr_t)entry; // mepc = entry
  tmp--;
  *tmp = 0x1800; // mstatus = 0x1800
  tmp--;
  *tmp = 0; // mcause
  tmp--;
  for (int i = 0; i < 32; i++) {
    tmp--;
  }

  printf("%d\n", tmp);
  for (uintptr_t *ptr = (uintptr_t *)kstack.end; ptr != tmp; ptr--) {
    printf("%d \\ \n", *ptr);
  }
  return (Context *)tmp;
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
