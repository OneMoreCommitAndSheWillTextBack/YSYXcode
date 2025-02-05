/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <device/mmio.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/paddr.h>

#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

static void out_of_bound(paddr_t addr);

#ifdef CONFIG_TARGET_SHARE
  #define MROM_SIZE 0xfff
  #define MROM_START 0x20000000
  #define MROM_END 0x20000fff
  static uint8_t mrom[MROM_SIZE] PG_ALIGN = {};

  #define SRAM_SIZE 8 * 1024 * 1024
  #define SRAM_START 0x0f000000
  #define SRAM_END 0x0f001fff
  static uint8_t sram[SRAM_SIZE] PG_ALIGN = {};

  word_t soc_read(paddr_t addr, int len) {

    if (addr >= MROM_START && addr <= MROM_END) {
      return host_read(mrom + addr - MROM_START, len);
    }
    if (addr >= SRAM_START && addr <= SRAM_END) {
      return host_read(sram + addr - SRAM_START, len);
    }
    out_of_bound(addr);
    return 0;
  }

  void soc_write(paddr_t addr, int len, word_t data) {
    if (addr >= MROM_START && addr <= MROM_END) {
      printf("the mrom cannot be written\n");
      assert(0);
    }
    if (addr >= SRAM_START && addr <= SRAM_END) {
      host_write(sram + addr - SRAM_START, len, data);
      return ;
    }
    out_of_bound(addr);
  }
    
#endif

uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
#ifdef CONFIG_MTRACE
  printf("[memory read] %u from 0x%08x\n", ret, addr);
#endif
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
#ifdef CONFIG_MTRACE
  printf("[memory write] %u to 0x%08x\n", data, addr);
#endif
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR
        ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT,
      PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr)))
    return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  IFDEF(CONFIG_TARGET_SHARE, return soc_read(addr, len);)
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  IFDEF(CONFIG_TARGET_SHARE, soc_write(addr, len, data); return);
  out_of_bound(addr);
}
