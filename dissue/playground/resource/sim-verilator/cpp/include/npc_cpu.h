#ifndef NPC_CPU_H
#define NPC_CPU_H

#include "npc_sim_types.h"
#include "npc_wave.h"

#include <stdint.h>

class VerilatedContext;
class Vnpc;

void npc_cpu_reset(VerilatedContext &context, Vnpc &top, uint32_t cycles,
                   NpcWave &_wave);
void npc_cpu_step(VerilatedContext &context, Vnpc &top, NpcWave &_wave);
bool npc_cpu_get_gpr(Vnpc &top, NpcGprContext *out);
bool npc_cpu_get_csr(Vnpc &top, NpcCsrContext *out);
bool npc_cpu_get_context(Vnpc &top, NpcCpuContext *out);

#endif
