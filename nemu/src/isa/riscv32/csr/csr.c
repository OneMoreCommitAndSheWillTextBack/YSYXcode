#include "csr-xmacro.h"
#include "debug.h"
#include "isa-def.h"
#include <isa.h>
#include <stdint.h>

// NEMU currently models a single timer interrupt source through cpu.INTR.
// Keep software-writable pending bits locally and OR them with that hardware
// pending state when exposing mip/sip.
static uint32_t software_mip_pending = 0;

static inline uint32_t sie_mask(void) { return MIE_SSIE | MIE_STIE | MIE_SEIE; }
static inline uint32_t sip_mask(void) { return MIP_SSIP | MIP_STIP | MIP_SEIP; }

static inline uint32_t mip_writable_mask(void) {
  return MIP_SSIP | MIP_STIP | MIP_SEIP;
}

static inline uint32_t sstatus_mask(void) {
  return SSTATUS_SIE | SSTATUS_SPIE | SSTATUS_MXR | SSTATUS_SUM | SSTATUS_SPP;
}

// FIXME: some bit on mip csr is read only
// when write to these register would throw a
// illegal intruction exception
static inline uint32_t mip_value(void) {
  uint32_t timer_pending = cpu.INTR ? MIP_MTIP : 0;
  return (software_mip_pending & mip_writable_mask()) | timer_pending;
}

uint32_t virt_csr_mip_read(void) { return mip_value(); }

void virt_csr_mip_write(uint32_t data) {
  uint32_t mask = mip_writable_mask();
  software_mip_pending = (software_mip_pending & ~mask) | (data & mask);
}

uint32_t virt_csr_sip_read(void) {
  uint32_t mask = sip_mask() & cpu.csr.mideleg;
  return mip_value() & mask;
}

void virt_csr_sip_write(uint32_t data) {
  uint32_t mask = sip_mask() & cpu.csr.mideleg & mip_writable_mask();
  software_mip_pending = (software_mip_pending & ~mask) | (data & mask);
}

uint32_t virt_csr_sie_read(void) {
  uint32_t mask = sie_mask() & cpu.csr.mideleg;
  return cpu.csr.mie & mask;
}

void virt_csr_sie_write(uint32_t data) {
  uint32_t mask = sie_mask() & cpu.csr.mideleg;
  cpu.csr.mie = (cpu.csr.mie & ~mask) | (data & mask);
}

uint32_t virt_csr_sstatus_read(void) {
  uint32_t mask = sstatus_mask();
  return cpu.csr.mstatus & mask;
}

void virt_csr_sstatus_write(uint32_t data) {
  uint32_t mask = sstatus_mask();
  cpu.csr.mstatus = (cpu.csr.mstatus & ~mask) | (data & mask);
}
