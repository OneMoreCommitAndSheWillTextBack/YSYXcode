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

extern "C" void npc_sim_reset_with_opaque(NpcSim *sim, void *opaque,
                                            uint32_t cycles) {
  if (sim == nullptr) {
    return;
  }

  sim->reset(cycles, opaque);
}

extern "C" void npc_sim_step_with_opaque(NpcSim *sim, void *opaque) {
  if (sim == nullptr) {
    return;
  }

  sim->step(opaque);
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

extern "C" void npc_sim_abandon_wave(NpcSim *sim) {
  if (sim == nullptr) {
    return;
  }

  sim->abandon_wave();
}
