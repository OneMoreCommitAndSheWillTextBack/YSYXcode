#include <am.h>
#include <klib.h>
#include <rtthread.h>
#include <stdint.h>

// clang-format off
static rt_ubase_t global_to, global_from;

static Context* ev_handler(Event e, Context *c) {
  // printf("get event ID = %d\n", e.event);
  switch (e.event) {
    case EVENT_YIELD:
      if(global_from){
        *(Context**)global_from = c;
      }
      c = *(Context **)global_to;
      break;
		case 5:
			break;
    default: printf("Unhandled event ID = %d\n", e.event); assert(0);
  }
  return c;
}

void __am_cte_init() {
  cte_init(ev_handler);
}

void rt_hw_context_switch_to(rt_ubase_t to) {
  global_to = to;
  yield();
}

void rt_hw_context_switch(rt_ubase_t from, rt_ubase_t to) {
  global_to = to;
  global_from = from;
  yield();
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
