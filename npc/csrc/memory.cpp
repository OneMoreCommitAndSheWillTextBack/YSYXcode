#include "common.h"
#include "host.h"
#include "map.h"
#include <assert.h>
#include <cstdint>
#include <iostream>

/*
  due to add the soc 
  so the pre memory has changed to flash
*/

const unsigned int msize = 0x800000;
const unsigned int fsize = 0xfffffff;
static uint8_t pmem[msize] = {};
static uint8_t flash[fsize] = {};

bool in_flash(uint32_t addr) { return addr - FBASE < fsize; }
bool in_mrom(uint32_t addr) { return addr - MBASE < msize; }
bool in_pmem(uint32_t addr) { return in_mrom(addr) | in_flash(addr); }

uint8_t *mrom_to_host(uint32_t addr) { return pmem + addr - MBASE; }
uint8_t *flash_to_host(uint32_t addr) { return flash + addr - FBASE; }
uint8_t *guest_to_host(uint32_t addr) {
  if(in_mrom(addr))
    return mrom_to_host(addr);
  if(in_flash(addr))
    return flash_to_host(addr);
  printf("[guest_to_host]the addr 0x%08x is out of bound\n", addr);
  assert(0);
}

uint32_t pmem_read(uint8_t *addr, uint32_t len) {
  switch (len) {
  case 1:
    return *(uint8_t *)addr;
  case 2:
    return *(uint16_t *)addr;
  case 4:
    return *(uint32_t *)addr;
  default:
    std::cerr << "read invaild data len" << std::endl;
  }
  return *(uint32_t *)addr;
}

void pmem_write(uint8_t *addr, uint32_t len, uint32_t data) {
  switch (len) {
  case 1:
    *(uint8_t *)addr = data;
    return;
  case 2:
    *(uint16_t *)addr = data;
    return;
  case 4:
    *(uint32_t *)addr = data;
    return;
  default:
    std::cerr << "write invaild data len" << std::endl;
  }
  return;
}

uint32_t paddr_read(uint32_t addr, uint32_t len) {
  if (in_pmem(addr)) {
    uint32_t ret = pmem_read(guest_to_host(addr), len);
#ifdef MTRACE
    printf("[memory read] %u from 0x%08x\n", ret, addr);
#endif
    return ret;
  }
  return mmio_read(addr, len);
  printf("[paddr_read]the addr 0x%08x is out of bound\n", addr);
  assert(0);
}

void paddr_write(uint32_t addr, uint32_t len, uint32_t data) {
  if (in_pmem(addr)) {
    pmem_write(guest_to_host(addr), len, data);
#ifdef MTRACE
    printf("[memory write] %u to 0x%08x\n", data, addr);
#endif
    return;
  }
  mmio_write(addr, len, data);
  return;
  printf("[paddr_write]the addr 0x%08x is out of bound\n", addr);
  assert(0);
}