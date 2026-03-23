#include "am.h"
#include "memory.h"
#include <common.h>
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
    if (j % 1000 == 0)
      Log("Hello World from Nanos-lite with arg '%s' for the %dth time!",
          (char *)arg, j);
    j++;
    yield();
  }
}

void context_kload(PCB *p, void (*entry)(void *), void *arg) {
  uint8_t *kstack_high = p->stack;
  Area kstack = {.end = kstack_high};
  p->cp = kcontext(kstack, entry, arg);
  pcb_num++;
}

#define MAXARG 32
#define MAXENVP 32
static char *allocate_string(char *current_pos, const char *source,
                             size_t len) {
  current_pos -= len;
  current_pos = (char *)((uintptr_t)current_pos & ~0x3);
  memcpy(current_pos, source, len);
  return current_pos;
}

uintptr_t argdeal_uload(uintptr_t stack_top, const char *filename, char *argv[],
                        char *envp[]) {
  char *argv_re[MAXARG];
  char *envp_re[MAXENVP];

  if (argv != NULL) {
    for (int i = 0; argv[i] != NULL; i++) {
      Log("argv[%d] is %s", i, argv[i]);
    }
  }

  // 让stack_top向下4字节对齐
  stack_top = stack_top & ~0x3;

  // string area
  char *string_area_cur = (char *)stack_top;
  int envp_count = 0;
  if (envp != NULL) {
    while (envp[envp_count] != NULL) {
      size_t len = strlen(envp[envp_count]) + 1;
      string_area_cur = allocate_string(string_area_cur, envp[envp_count], len);
      assert(envp_count < MAXENVP);
      envp_re[envp_count] = string_area_cur;
      envp_count++;
    }
  }

  int argv_count = 0;
  if (argv != NULL) {
    while (argv[argv_count] != NULL) {
      size_t len = strlen(argv[argv_count]) + 1;
      string_area_cur = allocate_string(string_area_cur, argv[argv_count], len);
      assert(argv_count < MAXARG);
      argv_re[argv_count] = string_area_cur;
      argv_count++;
    }
  }

  /*
   *  User Stack Layout (top to bottom)
   *
   *  +-------------------+
   *  |   ustack.end      |
   *  +-------------------+
   *  |   string area     |
   *  +-------------------+
   *  |   NULL            |
   *  |   envp[1]         |
   *  |   envp[0]         |
   *  +-------------------+
   *  |   NULL            |
   *  |   argv[argc-1]    |
   *  |   ...             |
   *  |   argv[0]         |
   *  +-------------------+
   *  |   argc            |
   *  +-------------------+ <-- cp->GPRx
   */

  size_t argc_val = argv_count;
  size_t ptr_slots = 1 + 1 + (argc_val + 1) + (envp_count + 1);
  uint32_t *ptr_array_base =
      (uint32_t *)((char *)string_area_cur - ptr_slots * sizeof(uint32_t));
  uint32_t *ptr_array_cur = ptr_array_base;

  *ptr_array_cur++ = 0;
  *ptr_array_cur++ = (uint32_t)argc_val;
  for (int i = 0; i < argv_count; i++)
    *ptr_array_cur++ = (uint32_t)argv_re[i];
  *ptr_array_cur++ = 0;
  for (int i = 0; i < envp_count; i++)
    *ptr_array_cur++ = (uint32_t)envp_re[i];
  *ptr_array_cur++ = 0;

  /* 调试：打印传递给用户程序的参数 */
  Log("argdeal_uload: ptr_array_base = %p, argc = %d", ptr_array_base,
      (int)argc_val);
  for (int i = 0; i < argv_count; i++) {
    Log("  argv_re[%d] = %p -> \"%s\"", i, (void *)argv_re[i], argv_re[i]);
  }
  for (int i = 0; i < envp_count; i++) {
    Log("  envp_re[%d] = %p -> \"%s\"", i, (void *)envp_re[i], envp_re[i]);
  }
  Log("  ptr_array content: [0]=%u [1]=%u [2]=%p [3]=%p ...", ptr_array_base[0],
      ptr_array_base[1], (void *)ptr_array_base[2], (void *)ptr_array_base[3]);

  return (uintptr_t)ptr_array_base;
}

void context_uload(PCB *p, const char *filename, char *argv[], char *envp[]) {
  Log("start to load user processes");
  if (p->cp == NULL) {
    pcb_num++;
  }
  void *new_alloc = new_page(8);
  uint8_t *alloc_end = (uint8_t *)new_alloc + 8 * PGSIZE;
  protect(&p->as);

  Log("protect the user area spaece");

  void *pa = alloc_end - PGSIZE;
  void *va = (uint8_t *)p->as.area.end - PGSIZE;
  for (int i = 0; i < 8; i++) {
    map(&p->as, va, pa, PTE_V | PTE_R | PTE_W);
    va -= PGSIZE;
    pa -= PGSIZE;
  }

  Log("areaspace: start = %p, end = %p", p->as.area.start, p->as.area.end);
  uintptr_t stack_start =
      argdeal_uload((uintptr_t)p->as.area.end, filename, argv, envp);
  uintptr_t entry = uload(p, filename);
  Area stack = {.end = (void *)stack_start};
  Log("context_uload: stack.end = %p, entry = %p", stack.end, (void *)entry);
  p->cp = ucontext(NULL, stack, (void *)entry);
  switch_boot_pcb();
  yield();
}

void init_proc() {
  switch_boot_pcb();

  Log("Initializing processes...");

  // naive_uload(NULL, "/bin/nterm");
  context_kload(&pcb[0], hello_fun, "A");

  char *argv[] = {"/bin/pal", "--skip", NULL};
  char *envp[] = {"PATH=/bin:/usr/bin", NULL};
  context_uload(&pcb[1], "/bin/dummy", argv, envp);
}

Context *schedule(Context *prev) {
  current->cp = prev;
  int cur = -1;
  if (current >= &pcb[0] && current < &pcb[pcb_num]) {
    cur = current - pcb;
  }
  int next = (cur + 1) % pcb_num;
  if (next > MAX_NR_PROC) {
    panic("the next should not larger than MAX_NR_PROC");
  }
  // Log("schedule: from %p to %p", prev, pcb[next].cp);
  current = &pcb[next];
  return current->cp;
}
