#include <device/clint.h>
#include <device/map.h>
#include <isa.h>
#include <utils.h>

#ifdef CONFIG_HAS_CLINT

#include "../local-include/csr-table.h"

#ifndef STANDARD_MTIME
#define STANDARD_MTIME 1
#endif

static uint8_t *clint_space = NULL;
static uint32_t msip_regs[CLINT_NR_HARTS] = {};
static uint64_t mtimecmp_regs[CLINT_NR_HARTS] = {};
static uint64_t mtime_reg = 0;

static inline uint32_t clint_current_hart() { return cpu.csr.mhartid; }

static inline uint32_t *clint_u32_reg(uint32_t offset) {
  return (uint32_t *)(clint_space + CLINT_WORD_OFFSET(offset));
}

static uint64_t clint_load_u64(uint32_t offset) {
  uint64_t data = 0;
  memcpy(&data, clint_space + CLINT_DWORD_OFFSET(offset), sizeof(data));
  return data;
}

static void clint_store_u64(uint32_t offset, uint64_t data) {
  memcpy(clint_space + CLINT_DWORD_OFFSET(offset), &data, sizeof(data));
}

static virt_csr_entry_t *clint_mip_csr(void) {
  virt_csr_entry_t *mip = get_virt_csr(0x344);
  if (mip == NULL || mip->read == NULL || mip->write == NULL) {
    return NULL;
  }
  return mip;
}

static void clint_set_mip_pending(uint32_t hart, uint32_t bit, bool pending) {
  if (hart != clint_current_hart()) {
    return;
  }

  virt_csr_entry_t *mip = clint_mip_csr();
  if (mip == NULL) {
    return;
  }

  uint32_t value = mip->read();
  if (pending) {
    value |= bit;
  } else {
    value &= ~bit;
  }
  mip->write(value);
}

static void clint_update_timer_pending() {
  uint32_t hart = clint_current_hart();
  if (!CLINT_HART_VALID(hart)) {
    return;
  }

  clint_set_mip_pending(hart, MIP_MTIP, mtime_reg >= mtimecmp_regs[hart]);
}

void clint_update_mtime(uint64_t mtime) {
  mtime_reg = mtime;
  if (clint_space != NULL) {
    clint_store_u64(CLINT_MTIME_REG, mtime_reg);
  }
  clint_update_timer_pending();
}

static void clint_sync_msip(uint32_t offset, bool is_write) {
  uint32_t hart = CLINT_MSIP_HART_ID(offset);
  uint32_t *reg = clint_u32_reg(offset);

  if (!CLINT_HART_VALID(hart)) {
    *reg = 0;
    return;
  }

  if (is_write) {
    msip_regs[hart] = *reg & 0x1u;
    clint_set_mip_pending(hart, MIP_MSIP, msip_regs[hart] != 0);
  }

  *reg = msip_regs[hart];
}

static void clint_sync_mtimecmp(uint32_t offset, bool is_write) {
  uint32_t hart = CLINT_MTIMECMP_HART_ID(offset);

  if (!CLINT_HART_VALID(hart)) {
    clint_store_u64(offset, 0);
    return;
  }

  if (is_write) {
    mtimecmp_regs[hart] = clint_load_u64(offset);
#if STANDARD_MTIME
    if (hart == clint_current_hart()) {
      clint_update_timer_pending();
    }
#else
    // INFO: in order to keep compatibility
    // leave a simple mode of clint
    if (hart == clint_current_hart()) {
      clint_set_mip_pending(hart, MIP_MTIP, false);
    }
#endif
  } else {
    clint_store_u64(offset, mtimecmp_regs[hart]);
  }
}

static void clint_sync_mtime(uint32_t offset, bool is_write) {
  if (is_write) {
    clint_update_mtime(clint_load_u64(offset));
  } else {
    clint_store_u64(offset, mtime_reg);
  }
}

static void clint_zero_access(uint32_t offset, int len) {
  memset(clint_space + offset, 0, len);
}

void clint_io_handler(uint32_t offset, int len, bool is_write) {
  Assert(offset + len <= CLINT_SIZE,
         "invalid CLINT access: offset=0x%08x len=%d", offset, len);

  if (CLINT_IN_MSIP(offset)) {
    Assert(((offset & 0x3u) + len) <= 4,
           "CLINT MSIP access crosses register boundary: offset=0x%08x len=%d",
           offset, len);
    clint_sync_msip(offset, is_write);
    return;
  }

  if (CLINT_IN_MTIMECMP(offset)) {
    Assert(((offset & 0x7u) + len) <= 8,
           "CLINT MTIMECMP access crosses register boundary: offset=0x%08x "
           "len=%d",
           offset, len);
    clint_sync_mtimecmp(offset, is_write);
    return;
  }

  if (CLINT_IN_MTIME(offset)) {
    Assert(((offset & 0x7u) + len) <= 8,
           "CLINT MTIME access crosses register boundary: offset=0x%08x len=%d",
           offset, len);
    clint_sync_mtime(offset, is_write);
    return;
  }

  clint_zero_access(offset, len);
}

void init_clint() {
  clint_space = calloc(1, CLINT_SIZE);
  assert(clint_space != NULL);

  for (uint32_t hart = 0; hart < CLINT_NR_HARTS; hart++) {
    mtimecmp_regs[hart] = UINT64_MAX;
    clint_store_u64(CLINT_MTIMECMP_REG(hart), mtimecmp_regs[hart]);
  }

  clint_update_mtime(0);
  add_mmio_map("clint", CLINT_BASE, clint_space, CLINT_SIZE, clint_io_handler);
}

#endif
