#include <common.h>
#include "syscall.h"
#include "am.h"


void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;

  switch (a[0]) {
    case SYSCALL_EXIT:
      halt(c->GPR2);

    case SYSCALL_YIELD: 
      c->GPRx = 0;
      break;

    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}
