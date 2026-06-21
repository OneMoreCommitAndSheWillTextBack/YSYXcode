#include "npc_sim_shim.h"
#include "npc_sim.h"
#include <cstdint>

extern "C" NpcSim *npc_sim_new(const NpcDpiCallbacks *callbacks) {
  return new NpcSim{callbacks};
}

extern "C" void npc_sim_delete(NpcSim *sim) { delete sim; }

extern "C" void npc_sim_reset(NpcSim *sim, uint32_t cycles) {
  if (sim == nullptr) {
    return;
  }

  sim->reset(cycles);
}

extern "C" void npc_sim_step(NpcSim *sim) {
  if (sim == nullptr) {
    return;
  }

  sim->step();
}

extern "C" uint8_t npc_sim_get_gpr(NpcSim *sim, NpcGprContext *out) {
  if (sim == nullptr) {
    return 0;
  }

  return sim->get_gpr(out) ? 1 : 0;
}

extern "C" uint8_t npc_sim_get_csr(NpcSim *sim, NpcCsrContext *out) {
  if (sim == nullptr) {
    return 0;
  }

  return sim->get_csr(out) ? 1 : 0;
}

extern "C" uint8_t npc_sim_get_context(NpcSim *sim, NpcCpuContext *out) {
  if (sim == nullptr) {
    return 0;
  }

  return sim->get_context(out) ? 1 : 0;
}

extern "C" void npc_sim_init_wave(NpcSim *sim, const char *path) {
  if (sim == nullptr) {
    return;
  }

  sim->init_wave(path);
}

extern "C" void npc_sim_enable_wave(NpcSim *sim) {
  if (sim == nullptr) {
    return;
  }

  sim->enable_wave();
}

extern "C" void npc_sim_disable_wave(NpcSim *sim) {
  if (sim == nullptr) {
    return;
  }

  sim->disable_wave();
}

extern "C" void npc_sim_close_wave(NpcSim *sim) {
  if (sim == nullptr) {
    return;
  }

  sim->close_wave();
}
