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

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data) {
  *data = pmem_read(guest_to_host(addr), 4);
  // if(*data != 0)
  //   printf("read mrom addr 0x%08x data 0x%08x\n", addr, *data);
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
