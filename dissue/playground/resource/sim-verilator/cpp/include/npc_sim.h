#ifndef NPC_SIM_H
#define NPC_SIM_H

#include "npc_cpu.h"
#include "npc_host_bridge.h"
#include "npc_wave.h"

#include <memory>
#include <stdint.h>

class VerilatedContext;
class Vnpc;

class NpcSim {
public:
  explicit NpcSim(const NpcDpiCallbacks *callbacks);
  ~NpcSim();

  NpcSim(const NpcSim &) = delete;
  NpcSim &operator=(const NpcSim &) = delete;

  void reset(uint32_t reset_cycles);
  void reset(uint32_t reset_cycles, void *opaque);
  void step();
  void step(void *opaque);

  bool initialized() const;

  void init_wave(const char *path);
  void enable_wave();
  void disable_wave();
  void close_wave();
  void abandon_wave();

private:
  NpcHostBridge bridge_;
  std::unique_ptr<VerilatedContext> context_;
  std::unique_ptr<Vnpc> top_;
  NpcWave wave_;
};

#endif
