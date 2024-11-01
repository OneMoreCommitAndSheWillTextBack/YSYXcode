#include "common.h"
#include <cstdint>
#include <stdlib.h>
#include <verilated.h>

extern "C" void ret() { set_npc_end(); }

extern "C" int guest_read(int addr) {
  uint32_t ret = pmem_read((uint32_t)addr, 4);
  return ret;
}

extern "C" void guest_write(int addr, int data) {
  // printf("the write addr is %08x\n", addr);
  pmem_write((uint32_t)addr, 4, (uint32_t)data);
  return;
}

extern "C" int get_inst(int pc) {
  uint32_t *inst = (uint32_t *)guest_to_host((uint32_t)pc);
  return *inst;
}

extern Cpu *cpu;
extern "C" void host_get_pc(int pc) {
  cpu->pc = (uint32_t)pc;
  return;
}

extern "C" void host_get_reg(const svLogicVecVal reg_array[32]) {
  for (int i = 0; i < 32; i++) {
    cpu->gpr[i] = reg_array[i].aval;
  }
}
