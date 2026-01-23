#include <common.h>
#include "syscall.h"
#include "am.h"
#include "fs.h"

static char* sys_table[20] = {
  [SYS_exit] = "sys_exit",
  [SYS_yield] = "sys_yield",
};

static bool strace_on = false;

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  if(strace_on && sys_table[a[0]] != NULL)
    Log("[strace] syscall %s, args1 %d, args %d, args %d", sys_table[a[0]]);

  switch (a[0]) {
    case SYS_exit:
      halt(c->GPR2);

    case SYS_yield: 
      c->GPRx = 0;
      break;

    case SYS_write: {
      size_t res = fs_write(a[1], (void *)a[2], a[3]);
      c->GPRx = res;
      break;
    }

    case SYS_read: {
      size_t res = fs_read(a[1], (void *)a[2], a[3]);
      c->GPRx = res;
      break;
    }

    case SYS_lseek:
      c->GPRx = fs_lseek(a[1], a[2], a[3]);
      break;

    case SYS_close:
      c->GPRx = fs_close(a[1]);
      break;

    case SYS_open:
      c->GPRx = fs_open((const char*)a[1], a[2], a[3]);
      break;

    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}