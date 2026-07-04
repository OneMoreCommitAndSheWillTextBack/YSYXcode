#include "npc_sim.h"
#include "cstdint"
#include "npc_cpu.h"

#include "Vnpc.h"
#include "verilated.h"

NpcSim::NpcSim(const NpcDpiCallbacks *callbacks)
    : bridge_(callbacks), context_(std::make_unique<VerilatedContext>()),
      top_(std::make_unique<Vnpc>(context_.get(), "TOP")), wave_() {
  top_->clock = 0;
  top_->reset = 0;
  top_->eval();
}

NpcSim::~NpcSim() {
  if (top_ != nullptr) {
    top_->final();
  }

  top_.reset();
  context_.reset();
}

void NpcSim::reset(uint32_t reset_cycles) {
  if (!initialized()) {
    return;
  }

  npc_cpu_reset(*context_, *top_, reset_cycles, wave_);
}

void NpcSim::step() {
  if (!initialized()) {
    return;
  }

  npc_cpu_step(*context_, *top_, wave_);
}

bool NpcSim::get_gpr(NpcGprContext *out) {
  if (!initialized()) {
    return false;
  }

  return npc_cpu_get_gpr(*top_, out);
}

bool NpcSim::get_csr(NpcCsrContext *out) {
  if (!initialized()) {
    return false;
  }

  return npc_cpu_get_csr(*top_, out);
}

bool NpcSim::get_context(NpcCpuContext *out) {
  if (!initialized()) {
    return false;
  }

  return npc_cpu_get_context(*top_, out);
}

bool NpcSim::initialized() const {
  return context_ != nullptr && top_ != nullptr;
}

void NpcSim::init_wave(const char *path) {
  if (!initialized()) {
    return;
  }

  wave_.init(context_.get(), top_.get(), path);
}

void NpcSim::enable_wave() { wave_.enable(); }

void NpcSim::disable_wave() { wave_.disable(); }

void NpcSim::close_wave() { wave_.close(); }
