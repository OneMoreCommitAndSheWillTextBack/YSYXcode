#include "common.h"
#include <cstdint>

const unsigned int mbase = 0x80000000;
const unsigned int msize = 0x8000000;
static uint8_t pmem[msize] = {};

uint8_t *guest_to_host(uint32_t addr) { return pmem + addr - mbase; }
