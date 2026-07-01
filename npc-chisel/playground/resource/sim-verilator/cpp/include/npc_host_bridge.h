#ifndef NPC_HOST_BRIDGE_H
#define NPC_HOST_BRIDGE_H

#include "npc_sim_types.h"
#include <cstdint>

class NpcHostBridge {
public:
  explicit NpcHostBridge(const NpcDpiCallbacks *callbacks);
  ~NpcHostBridge();

  NpcHostBridge(const NpcHostBridge &) = delete;
  NpcHostBridge &operator=(const NpcHostBridge &) = delete;

  static void commit(int valid, int finish, uint32_t pc, uint32_t inst);
  static void current_pc(uint32_t pc);
  static uint32_t pmem_read(uint32_t addr, uint32_t len);
  static void pmem_write(uint32_t addr, uint32_t len, uint32_t data);

private:
  NpcDpiCallbacks callbacks_{};
};

#endif
