#include "npc_cpu.h"

#include "Vnpc.h"
#include "cstdint"
#include "npc_dpi_export.h"
#include "verilated.h"

namespace {

constexpr uint32_t CSR_MSTATUS = 0x300;
constexpr uint32_t CSR_MIE = 0x304;
constexpr uint32_t CSR_MTVEC = 0x305;
constexpr uint32_t CSR_MSCRATCH = 0x340;
constexpr uint32_t CSR_MEPC = 0x341;
constexpr uint32_t CSR_MCAUSE = 0x342;
constexpr uint32_t CSR_MTVAL = 0x343;
constexpr uint32_t CSR_MIP = 0x344;
constexpr uint32_t CSR_MCYCLE = 0xB00;
constexpr uint32_t CSR_MINSTRET = 0xB02;

bool npc_cpu_context_api_available() {
  return npc_dpi_context_valid != nullptr && npc_dpi_get_pc != nullptr &&
         npc_dpi_get_priv != nullptr && npc_dpi_get_gpr != nullptr &&
         npc_dpi_get_csr != nullptr;
}

bool npc_cpu_context_ready() {
  return npc_cpu_context_api_available() && npc_dpi_context_valid() != 0;
}

} // namespace

void npc_cpu_reset(VerilatedContext &context, Vnpc &top, uint32_t cycles) {
  top.reset = 1;
  top.clock = 0;
  top.eval();
  context.timeInc(1);

  for (uint32_t i = 0; i < cycles; ++i) {
    top.clock = 1;
    top.eval();
    context.timeInc(1);

    top.clock = 0;
    top.eval();
    context.timeInc(1);
  }

  top.reset = 0;
  top.eval();
  context.timeInc(1);
}

void npc_cpu_step(VerilatedContext &context, Vnpc &top) {
  top.clock = 1;
  top.eval();
  context.timeInc(1);

  top.clock = 0;
  top.eval();
  context.timeInc(1);
}

bool npc_cpu_get_gpr(Vnpc &top, NpcGprContext *out) {
  (void)top;

  if (out == nullptr) {
    return false;
  }

  *out = {};
  if (!npc_cpu_context_ready()) {
    return false;
  }

  for (uint32_t i = 0; i < NPC_GPR_COUNT; ++i) {
    out->x[i] = npc_dpi_get_gpr(i);
  }

  return true;
}

bool npc_cpu_get_csr(Vnpc &top, NpcCsrContext *out) {
  (void)top;

  if (out == nullptr) {
    return false;
  }

  *out = {};
  if (!npc_cpu_context_ready()) {
    return false;
  }

  out->mstatus = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MSTATUS));
  out->mtvec = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MTVEC));
  out->mepc = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MEPC));
  out->mcause = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MCAUSE));
  out->mtval = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MTVAL));
  out->mie = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MIE));
  out->mip = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MIP));
  out->mscratch = static_cast<uint32_t>(npc_dpi_get_csr(CSR_MSCRATCH));
  out->mcycle = npc_dpi_get_csr(CSR_MCYCLE);
  out->minstret = npc_dpi_get_csr(CSR_MINSTRET);

  return true;
}

bool npc_cpu_get_context(Vnpc &top, NpcCpuContext *out) {
  if (out == nullptr) {
    return false;
  }

  *out = {};
  if (!npc_cpu_context_ready()) {
    return false;
  }

  NpcGprContext gpr{};
  NpcCsrContext csr{};
  if (!npc_cpu_get_gpr(top, &gpr) || !npc_cpu_get_csr(top, &csr)) {
    return false;
  }

  out->valid = 1;
  out->pc = npc_dpi_get_pc();
  out->priv_ = static_cast<uint8_t>(npc_dpi_get_priv() & 0x3);
  out->gpr = gpr;
  out->csr = csr;

  return true;
}
