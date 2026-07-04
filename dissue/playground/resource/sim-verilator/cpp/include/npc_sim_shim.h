#ifndef NPC_SIM_SHIM_H
#define NPC_SIM_SHIM_H

#include "npc_sim_types.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NpcSim NpcSim;

NpcSim *npc_sim_new(const NpcDpiCallbacks *callbacks);
void npc_sim_delete(NpcSim *sim);
void npc_sim_reset(NpcSim *sim, uint32_t cycles);
void npc_sim_step(NpcSim *sim);
uint8_t npc_sim_get_gpr(NpcSim *sim, NpcGprContext *out);
uint8_t npc_sim_get_csr(NpcSim *sim, NpcCsrContext *out);
uint8_t npc_sim_get_context(NpcSim *sim, NpcCpuContext *out);
void npc_sim_init_wave(NpcSim *sim, const char *path);
void npc_sim_enable_wave(NpcSim *sim);
void npc_sim_disable_wave(NpcSim *sim);
void npc_sim_close_wave(NpcSim *sim);

#ifdef __cplusplus
}
#endif

#endif
