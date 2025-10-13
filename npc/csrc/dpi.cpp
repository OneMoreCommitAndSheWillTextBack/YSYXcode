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

extern "C" void flash_read(int32_t addr, int32_t *data) { 
  *data = paddr_read(FBASE + addr, 4);
}
extern "C" void mrom_read(int32_t addr, int32_t *data) {
  *data = paddr_read(addr, 4);
}

extern "C" uint8_t psram_read(uint32_t addr) {
  return paddr_read(PSBASE + addr, 1);
}
extern "C" void psram_write(uint32_t addr, uint8_t data) {
  paddr_write(PSBASE + addr, 1, data);
}

extern "C" void sdram_write(uint8_t bank, uint16_t row, uint16_t col, uint16_t data, uint8_t dqm) {
    uint32_t addr;
    addr |= (col & 0x1FF) << 2;           // col占据 bit[10:2]
    addr |= (bank & 0x3) << (9 + 2);      // bank占据 bit[12:11]
    addr |= (row & 0x1FFF) << (9 + 2 + 2); // row占据 bit[25:13]

    if(!(dqm & 0b1)) {
      // printf("[sdram lowbyte write], bank: %hu, row %hu, col %hu => 0x%x, data: %x\n", bank, row, col, SDBASE + addr, data);
      paddr_write(SDBASE + addr, 1, data);
    }

    if(!(dqm & 0b10)) {
      // printf("[sdram higbyte write], bank: %hu, row %hu, col %hu => 0x%x, data: %x\n", bank, row, col, SDBASE + addr + 1, data >> 8);
      paddr_write(SDBASE + addr + 1, 1, data >> 8);    
    }
}

extern "C" void sdram_read(uint32_t bank, uint32_t row, uint32_t col, uint16_t *data) {
  uint32_t addr;
  addr |= (col & 0x1FF) << 2;           // col占据 bit[10:2]
  addr |= (bank & 0x3) << (9 + 2);      // bank占据 bit[12:11]
  addr |= (row & 0x1FFF) << (9 + 2 + 2); // row占据 bit[25:13]

  uint16_t ret = paddr_read(SDBASE + addr, 2);
  // printf("[sdram read], bank: %hu, row %hu, col %hu => 0x%x, reads: %x\n", bank, row, col, addr, ret);
  *data = ret;
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

extern "C" void host_get_skip(uint32_t addr) { 
  if(addr >= 0x10000000 && addr < 0x10000fff)
    set_diff_pass();
  if(addr >= 0x10001000 && addr < 0x10001fff){
    set_diff_pass();
  }
}
