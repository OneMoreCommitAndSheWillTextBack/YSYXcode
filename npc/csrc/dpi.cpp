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

extern "C" void npc_pmem_read(uint32_t addr, uint32_t len, uint32_t *data) {
  *data = paddr_read(addr, len);
}

extern "C" void npc_pmem_write(uint32_t addr, uint32_t len, uint32_t data) {
  paddr_write(addr, len, data);
}

extern "C" void sdram_write(uint8_t bank, uint16_t row, uint16_t col, uint16_t data, uint8_t dqm) {
    uint32_t addr;
    addr |= (col & 0x1FF) << 1;            // col占据 bit[9:1]
    addr |= (bank & 0x3) << (9 + 1);      // bank占据 bit[11:10]
    addr |= (row & 0x1FFF) << (9 + 2 + 1); // row占据 bit[24:12]

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
  addr |= (col & 0x1FF) << 1;            // col占据 bit[9:1]
  addr |= (bank & 0x3) << (9 + 1);      // bank占据 bit[11:10]
  addr |= (row & 0x1FFF) << (9 + 2 + 1); // row占据 bit[24:12]

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

extern "C" void host_get_io_op(uint32_t addr) { 
  // 外设地址范围定义（MMIO 设备，difftest 时需要跳过检查）
  // 按地址顺序排列，便于维护和扩展
  
  // CLINT: 0x0200_0000 ~ 0x0200_ffff
  if (addr >= 0x02000000 && addr <= 0x0200ffff) {
    set_diff_pass();
    return;
  }
  
  // UART16550: 0x1000_0000 ~ 0x1000_0fff
  if (addr >= 0x10000000 && addr <= 0x10000fff) {
    set_diff_pass();
    return;
  }
  
  // SPI master: 0x1000_1000 ~ 0x1000_1fff
  if (addr >= 0x10001000 && addr <= 0x10001fff) {
    set_diff_pass();
    return;
  }
  
  // GPIO: 0x1000_2000 ~ 0x1000_200f
  if (addr >= 0x10002000 && addr <= 0x1000200f) {
    set_diff_pass();
    return;
  }
  
  // PS2: 0x1001_1000 ~ 0x1001_1007
  if (addr >= 0x10011000 && addr <= 0x10011007) {
    set_diff_pass();
    return;
  }
  
  // VGA: 0x2100_0000 ~ 0x211f_ffff
  if (addr >= 0x21000000 && addr <= 0x211fffff) {
    set_diff_pass();
    return;
  }
  
  // ChipLink MMIO: 0x4000_0000 ~ 0x7fff_ffff
  if (addr >= 0x40000000 && addr <= 0x7fffffff) {
    set_diff_pass();
    return;
  }
  
  // ChipLink MEM: 0xc000_0000 ~ 0xffff_ffff
  if (addr >= 0xc0000000 && addr <= 0xffffffff) {
    set_diff_pass();
    return;
  }
}

extern Npc *npc;
unsigned long long io_record_time = 0;
extern "C" void host_get_cpu_axi_valid() {
  io_record_time = npc->timer;
  npc->iocount++;
}

extern "C" void host_get_cpu_axi_ready() {
  npc->iotimer += npc->timer - io_record_time;
}

unsigned ifu_record_time = 0;
extern "C" void host_get_ifu_start() {
  npc->ifucount ++;
  ifu_record_time = npc->timer;
}

extern "C" void host_get_ifu_finish() {
  npc->ifutimer += npc->timer - ifu_record_time;
}

extern "C" void host_get_exu_valid() {
  npc->exucount ++;
}

extern "C" void host_get_icache_miss() {
  npc->icache_miss_time++;
}
