#include "npc_cpu.h"

#include "Vnpc.h"
#include "cstdint"
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

constexpr const char *NPC_CONTEXT_DPI_SCOPES[] = {
    "npc.u_core.core.contextDpi",
    "TOP.npc.u_core.core.contextDpi",
    "TOP.u_core.core.contextDpi",
};

const VerilatedScope *npc_cpu_context_scope(Vnpc &top) {
  for (const char *name : NPC_CONTEXT_DPI_SCOPES) {
    if (const VerilatedScope *scope = top.contextp()->scopeFind(name)) {
      return scope;
    }
  }

  return nullptr;
}

class NpcDpiScope {
public:
  explicit NpcDpiScope(Vnpc &top)
      : previous_(Verilated::dpiScope()), current_(npc_cpu_context_scope(top)) {
    if (current_ != nullptr) {
      Verilated::dpiScope(current_);
    }
  }

  ~NpcDpiScope() {
    if (current_ != nullptr) {
      Verilated::dpiScope(previous_);
    }
  }

  bool valid() const { return current_ != nullptr; }

private:
  const VerilatedScope *previous_;
  const VerilatedScope *current_;
};

bool npc_cpu_context_ready(Vnpc &top) {
  NpcDpiScope scope(top);
  return scope.valid() && Vnpc::npc_dpi_context_valid() != 0;
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
  NpcDpiScope scope(top);
  if (!scope.valid() || Vnpc::npc_dpi_context_valid() == 0) {
    return false;
  }

  for (uint32_t i = 0; i < NPC_GPR_COUNT; ++i) {
    out->x[i] = Vnpc::npc_dpi_get_gpr(i);
  }

  return true;
}

bool npc_cpu_get_csr(Vnpc &top, NpcCsrContext *out) {
  (void)top;

  if (out == nullptr) {
    return false;
  }

  *out = {};
  NpcDpiScope scope(top);
  if (!scope.valid() || Vnpc::npc_dpi_context_valid() == 0) {
    return false;
  }

  out->mstatus = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MSTATUS));
  out->mtvec = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MTVEC));
  out->mepc = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MEPC));
  out->mcause = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MCAUSE));
  out->mtval = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MTVAL));
  out->mie = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MIE));
  out->mip = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MIP));
  out->mscratch = static_cast<uint32_t>(Vnpc::npc_dpi_get_csr(CSR_MSCRATCH));
  out->mcycle = Vnpc::npc_dpi_get_csr(CSR_MCYCLE);
  out->minstret = Vnpc::npc_dpi_get_csr(CSR_MINSTRET);

  return true;
}

bool npc_cpu_get_context(Vnpc &top, NpcCpuContext *out) {
  if (out == nullptr) {
    return false;
  }

  *out = {};
  NpcDpiScope scope(top);
  if (!scope.valid() || Vnpc::npc_dpi_context_valid() == 0) {
    return false;
  }

  NpcGprContext gpr{};
  NpcCsrContext csr{};
  if (!npc_cpu_get_gpr(top, &gpr) || !npc_cpu_get_csr(top, &csr)) {
    return false;
  }

  out->valid = 1;
  out->pc = Vnpc::npc_dpi_get_pc();
  out->priv_ = static_cast<uint8_t>(Vnpc::npc_dpi_get_priv() & 0x3);
  out->gpr = gpr;
  out->csr = csr;

  return true;
}
