#ifndef NPC_CPU_H
#define NPC_CPU_H

#include "npc_wave.h"

#include <stdint.h>

class VerilatedContext;
class Vnpc;

void npc_cpu_reset(VerilatedContext &context, Vnpc &top, uint32_t cycles,
                   NpcWave &_wave);
void npc_cpu_step(VerilatedContext &context, Vnpc &top, NpcWave &_wave);

#endif
