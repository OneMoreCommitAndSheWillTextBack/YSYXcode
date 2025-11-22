#include "memory/memsocdiff.h"

#ifdef CONFIG_TARGET_SHARE
  #define MROM_SIZE 0xfff
  #define MROM_START 0x20000000
  #define MROM_END 0x20000fff
  static uint8_t mrom[MROM_SIZE] PG_ALIGN = {};

  #define SRAM_SIZE 8 * 1024 * 1024
  #define SRAM_START 0x0f000000
  #define SRAM_END 0x0f001fff
  static uint8_t sram[SRAM_SIZE] PG_ALIGN = {};

  #define FALSH_SIZE 0x0fffffff
  #define FALSH_START 0x30000000
  #define FALSH_END 0x3fffffff
  static uint8_t flash[FALSH_SIZE] PG_ALIGN = {};

  #define SDRAM_SIZE 0x20000000
  #define SDRAN_START 0xa0000000
  #define SDRAM_END 0xbfffffff
  static uint8_t sdram [SDRAM_SIZE] PG_ALIGN = {};

  soc_device soc_devices[] = {
    {0x20000000, 0x20000fff, "mrom" , mrom},
    {0x0f000000, 0x0f001fff, "sram" , sram},
    {0x10000000, 0x10000fff, "uart" , NULL},
    {0x30000000, 0x3fffffff, "flash", flash},
    {0x10001000, 0x10001fff, "spi"  , NULL},
    {0xa0000000, 0xbfffffff, "sdram", sdram},
    {0x10002000, 0x1000200f, "gpio" , NULL},
    {0x10011000, 0x10011007, "ps2", NULL},
    {0x21000000, 0x211fffff, "vga", NULL},
  };

  soc_device* fetch_the_soc(paddr_t addr){
    for (int i = 0; i < ARRLEN(soc_devices); i++) {
      if (addr >= soc_devices[i].soc_start && addr <= soc_devices[i].soc_end) {
        return soc_devices + i;
      }
    }
    return NULL;
  }

  void init_soc() {
    memset(mrom, 0, MROM_SIZE);
    memset(sram, 0, SRAM_SIZE);
  }
#else
  soc_device* fetch_the_soc(paddr_t addr) {return NULL;}
  void init_soc() {}
#endif