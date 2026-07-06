#include "npc_dpi.h"
#include "npc_host_bridge.h"
#include "npc_sim_types.h"

#include <cstdint>

namespace {

uint32_t dpi_word(const svBitVecVal *bits, uint32_t index) {
  return bits == nullptr ? 0 : static_cast<uint32_t>(bits[index]);
}

} // namespace

extern "C" void npc_difftest_commit(int valid_mask, int finish_mask, int pc0,
                                    int inst0, int pc1, int inst1) {
  NpcHostBridge::difftest_commit(
      static_cast<uint32_t>(valid_mask), static_cast<uint32_t>(finish_mask),
      static_cast<uint32_t>(pc0), static_cast<uint32_t>(inst0),
      static_cast<uint32_t>(pc1), static_cast<uint32_t>(inst1));
}

extern "C" void npc_difftest_context(int valid, int pc, int priv,
                                     const svBitVecVal *csr,
                                     const svBitVecVal *gpr) {
  NpcCpuContext context{};

  context.valid = valid != 0 ? 1 : 0;
  context.pc = static_cast<uint32_t>(pc);
  context.priv_ = static_cast<uint8_t>(priv & 0x3);

  context.csr.mstatus = dpi_word(csr, 0);
  context.csr.mtvec = dpi_word(csr, 1);
  context.csr.mepc = dpi_word(csr, 2);
  context.csr.mcause = dpi_word(csr, 3);
  context.csr.mtval = dpi_word(csr, 4);
  context.csr.mie = dpi_word(csr, 5);
  context.csr.mip = dpi_word(csr, 6);
  context.csr.mscratch = dpi_word(csr, 7);
  context.csr.mcycle = dpi_word(csr, 8);
  context.csr.minstret = dpi_word(csr, 9);

  for (uint32_t idx = 0; idx < NPC_GPR_COUNT; ++idx) {
    context.gpr.x[idx] = dpi_word(gpr, idx);
  }

  NpcHostBridge::difftest_context(&context);
}

extern "C" void npc_pmem_read(int addr, int len, int *data) {
  if (data == nullptr) {
    return;
  }

  *data = static_cast<int>(NpcHostBridge::pmem_read(
      static_cast<uint32_t>(addr), static_cast<uint32_t>(len)));
}

extern "C" void npc_pmem_write(int addr, int len, int data) {
  NpcHostBridge::pmem_write(static_cast<uint32_t>(addr),
                            static_cast<uint32_t>(len),
                            static_cast<uint32_t>(data));
}

extern "C" void npc_cache_hit(char hit) {
  NpcHostBridge::cache_hit(static_cast<uint8_t>(hit));
}

extern "C" void npc_issue_queue_perf(int issue_count, int occupancy,
                                     char block_ready, char block_operand) {
  NpcHostBridge::issue_queue_perf(
      static_cast<uint8_t>(issue_count), static_cast<uint8_t>(occupancy),
      static_cast<uint8_t>(block_ready), static_cast<uint8_t>(block_operand));
}

extern "C" void npc_div_perf(int cycles, char special) {
  NpcHostBridge::div_perf(static_cast<uint32_t>(cycles),
                          static_cast<uint8_t>(special));
}
