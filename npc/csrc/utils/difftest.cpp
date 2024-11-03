#include "common.h"
#include <assert.h>
#include <cstddef>
#include <cstdint>
#include <dlfcn.h>

#ifdef DIFFTEST
void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction);
void (*ref_difftest_regcpy)(void *dut, bool direction);
void (*ref_difftest_exec)(uint64_t n);
void (*ref_difftest_init)(int port);

enum { DIFF_TO_DUT, DIFF_TO_REF };
extern Cpu *cpu;

void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(uint32_t, void *, size_t, bool))dlsym(
      handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy =
      (void (*)(void *, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_init = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_init(port);
  ref_difftest_memcpy(MBASE, guest_to_host(MBASE), img_size, DIFF_TO_REF);
  ref_difftest_regcpy(&(cpu->con), DIFF_TO_REF);
}

void checkregs(context *ref_context) {
  for (int i = 0; i < 32; i++) {
    if (ref_context->gpr[i] != cpu->con.gpr[i]) {
      goto regdiferror;
    }
  }
  if (ref_context->pc != cpu->con.pc)
    goto regdiferror;
  return;

regdiferror:
  printf("the difftest failed at pc %08x\n", cpu->con.pc);
  display_reg();
  assert(0);
}

void diff_step() {
  context ref_context;
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_context, DIFF_TO_DUT);
  checkregs(&ref_context);
  printf("get to here\n");
}

#endif
