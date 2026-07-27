#include "rtdef.h"
#include <am.h>
#include <klib.h>
#include <rtthread.h>

// clang-format off

static Context* ev_handler(Event e, Context *c) {
  // printf("get event ID = %d\n", e.event);
  rt_thread_t pcb = rt_thread_self();
  rt_uint32_t *user_data_p = (void *)&(pcb->user_data);
  switch (e.event) {
    case EVENT_YIELD:
    case EVENT_SYSCALL:
      if (user_data_p[1]) {
        *(Context**)user_data_p[1] = c;
      }
      c = *(Context **)user_data_p[0];
      break;
    case EVENT_IRQ_TIMER:
    break;
			break;
    default: printf("Unhandled event ID = %d\n", e.event); assert(0);
  }
  return c;
}

void __am_cte_init() {
  cte_init(ev_handler);
}

// to and from is the pointer point to the pointer of the context
void rt_hw_context_switch_to(rt_ubase_t to) {
  rt_thread_t pcb = rt_thread_self();
  rt_ubase_t userdata_store = pcb->user_data;
  rt_uint32_t *user_data_p = (void *)&(pcb->user_data);
  user_data_p[0] = to;
  user_data_p[1] = 0;
  yield();
  pcb->user_data = userdata_store;
}

void rt_hw_context_switch(rt_ubase_t from, rt_ubase_t to) {
  rt_thread_t pcb = rt_thread_self();
  rt_ubase_t userdata_store = pcb->user_data;
  rt_uint32_t *user_data_p = (void *)&(pcb->user_data);
  user_data_p[0] = to;
  user_data_p[1] = from;
  yield();
  pcb->user_data = userdata_store;
}

void rt_hw_context_switch_interrupt(void *context, rt_ubase_t from, rt_ubase_t to, struct rt_thread *to_thread) {
  assert(0);
}

typedef struct {
  void (*tentry)(void*);
  void *parameter;
  void (*texit)(void);
} pacage_function_args;

// due to once the function tentry returned 
// we need to call the texit 
// so we make the wrap_function to make sure the 
// tentry return the texit will been called;
void pacage_function(pacage_function_args *args){
  args->tentry(args->parameter);
  args->texit();

  printf("it should not reach here\n");
  assert(0);
}

rt_uint8_t *rt_hw_stack_init(void *tentry, void *parameter, rt_uint8_t *stack_addr, void *texit) {
  rt_uint8_t *context_start = (rt_uint8_t*)(((uintptr_t)stack_addr + sizeof(uintptr_t) - 1) & ~(sizeof(uintptr_t) - 1));
  
  context_start -= sizeof(pacage_function_args);
  pacage_function_args *args = (pacage_function_args *)context_start;
  args->parameter = parameter;
  args->tentry = (void (*)(void *))tentry;
  args->texit = (void (*)(void))texit;

  Area kstack = {.end = context_start};
  Context *context = kcontext(kstack, (void*)pacage_function, args);
  return (rt_uint8_t*)context;
}

// clang-format on
