#include "common.h"
#include <cstdint>
#include <iostream>

const unsigned int mbase = 0x80000000;
const unsigned int msize = 0x8000000;
static uint8_t pmem[msize] = {};

uint8_t *guest_to_host(uint32_t addr) { return pmem + addr - mbase; }

uint32_t pmem_read(uint32_t address, uint32_t len) {
  uint8_t *addr = guest_to_host(address);
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

void pmem_write(uint32_t address, uint32_t len, uint32_t data) {
  uint8_t *addr = guest_to_host(address);
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
