#include <common.h>
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
  Area kstack = { .end = kstack_high };
  p->cp = kcontext(kstack, entry, arg);
  pcb_num++;
}

#define MAXARG 32
#define MAXENVP 32
static char* allocate_string(char *current_pos, const char *source, size_t len) {
    current_pos -= len;
    current_pos = (char *)((uintptr_t)current_pos & ~0x3);
    memcpy(current_pos, source, len);
    return current_pos;
}

uintptr_t argdeal_uload(uintptr_t stack_top, const char *filename, char *argv[], char *envp[]) {
  char *argv_re[MAXARG];
  char *envp_re[MAXENVP];

  // 让stack_top向下4字节对齐
  stack_top = stack_top & ~0x3;

  // string area
  char *string_area_cur = (char *)stack_top;
  int envp_count = 0;
  while(envp[envp_count] != NULL) {
    size_t len = strlen(envp[envp_count]) + 1;  
    string_area_cur = allocate_string(string_area_cur, envp[envp_count], len);    
    envp_re[envp_count] = string_area_cur;
    
    assert(envp_count < MAXENVP);
    envp_count++;
  }

  int argv_count = 0;
  while(argv[argv_count] != NULL) {
    size_t len = strlen(argv[argv_count]) + 1;
    string_area_cur = allocate_string(string_area_cur, argv[argv_count], len);  
    argv_re[argv_count+1] = string_area_cur;
    
    assert(argv_count+1 < MAXARG);
    argv_count++;
  }

  assert(filename != NULL);
  size_t filename_len = strlen(filename) + 1;
  string_area_cur = allocate_string(string_area_cur, filename, filename_len); 
  argv_re[0] = string_area_cur;

  uint32_t *ptr_array_pos = (uint32_t *)string_area_cur;
  *ptr_array_pos = 0;
  ptr_array_pos--;
  for(int i = envp_count - 1; i >= 0; i--) {
    *ptr_array_pos = (uint32_t)envp_re[i];
    ptr_array_pos--;
  }
  *ptr_array_pos = 0;
  ptr_array_pos--;
  for(int i = argv_count; i>= 0; i--) {
    *ptr_array_pos = (uint32_t)argv_re[i];
    ptr_array_pos--;
  }
  *ptr_array_pos = argv_count;
  ptr_array_pos--;
  return (uintptr_t)ptr_array_pos;
}

void context_uload(PCB *p, const char *filename, char *argv[], char *envp[]) {
  uintptr_t entry = uload(p, filename);
  p->cp = ucontext(NULL, heap, (void *)entry);
  pcb_num++;
}

void init_proc() {
  switch_boot_pcb();

  Log("Initializing processes...");

  // naive_uload(NULL, "/bin/nterm");
  context_kload(&pcb[0], hello_fun, "A");
  context_uload(&pcb[1], "/bin/pal", NULL, NULL);
}

Context *schedule(Context *prev) {
  current->cp = prev;
  int cur = -1;
  if (current >= &pcb[0] && current < &pcb[pcb_num]) {
    cur = current - pcb;
  }
  int next = (cur + 1) % pcb_num;
  if(next > MAX_NR_PROC) {
    panic("the next should not larger than MAX_NR_PROC");
  }
  Log("schedule: from %p to %p", prev, pcb[next].cp);
  current = &pcb[next];
  return pcb[next].cp;
}
