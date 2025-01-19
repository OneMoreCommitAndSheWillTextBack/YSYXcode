#include "common.h"
#include <cstdint>
#include <stdlib.h>
#include <verilated.h>

extern Cpu *cpu;
extern "C" void ret(int pc) {
  if (pc != 0)
    cpu->con.pc = (uint32_t)pc;
  set_npc_end();
}

extern "C" int guest_read(int addr, int len) {
  uint32_t ret = paddr_read((uint32_t)addr, len);
  return ret;
}

extern "C" void guest_write(uint32_t addr, uint32_t data, uint32_t len) {
  // printf("the write addr is %08x\n", addr);
  paddr_write((uint32_t)addr, len, (uint32_t)data);
  return;
}

extern "C" int get_inst(int pc) {
  uint32_t *inst = (uint32_t *)guest_to_host((uint32_t)pc);
  return *inst;
}

extern "C" void host_get_pc(int pc) {
  cpu->con.pc = (uint32_t)pc;
  return;
}

extern "C" void host_get_csr(int csrval, int csrnum) {
  switch (csrnum) {
  case 0:
    cpu->con.csr.mstatus = csrval;
    break;
  case 1:
    cpu->con.csr.mtvec = csrval;
    break;
  case 2:
    cpu->con.csr.mepc = csrval;
    break;
  case 3:
    cpu->con.csr.mcause = csrval;
    break;
  }
}

extern "C" void host_get_reg(int regval, int regnum) {
  cpu->con.gpr[regnum] = (uint32_t)(regval);
  return;
}

extern "C" void host_get_inst(int inst) {
  cpu->inst = (uint32_t)inst;
  return;
}

extern "C" void host_get_valid(int valid) { cpu->valid = valid; }
