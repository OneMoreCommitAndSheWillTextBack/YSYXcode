#include <isa.h>

#define DEFINE_VIRTUAL_CSR_PANIC(name, idx)                                    \
  uint32_t virt_csr_##name##_read(void) {                                      \
    panic("virtual csr 0x%03x (%s) read is not implemented", idx, #name);      \
    return 0;                                                                  \
  }                                                                            \
  void virt_csr_##name##_write(uint32_t data) {                                \
    panic("virtual csr 0x%03x (%s) write is not implemented: 0x%08x", idx,     \
          #name, data);                                                        \
  }

DEFINE_VIRTUAL_CSR_PANIC(sip, 0x144)
DEFINE_VIRTUAL_CSR_PANIC(mip, 0x344)

static inline uint32_t sie_mask(void) { return MIE_SSIE | MIE_STIE | MIE_SEIE; }

uint32_t virt_csr_sie_read(void) {
  uint32_t mask = sie_mask() & cpu.csr.mideleg;
  return cpu.csr.mie & mask;
}

void virt_csr_sie_write(uint32_t data) {
  uint32_t mask = sie_mask() & cpu.csr.mideleg;
  cpu.csr.mie = (cpu.csr.mie & ~mask) | (data & mask);
}
