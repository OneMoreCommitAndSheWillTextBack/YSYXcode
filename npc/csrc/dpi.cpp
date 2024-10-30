#include "common.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" void ret() { set_npc_end(); }

extern "C" int pmem_read(int addr) {
  uint32_t *data = (uint32_t *)guest_to_host((uint32_t)addr);
  return *data;
}
extern "C" void pmem_write(int addr, int data) {
  // printf("the write addr is %08x\n", addr);
  uint32_t *pos = (uint32_t *)guest_to_host((uint32_t)addr);
  *pos = (uint32_t)data;
  return;
}
extern "C" int get_inst(int pc) {
  uint32_t *inst = (uint32_t *)guest_to_host((uint32_t)pc);
  return *inst;
}
