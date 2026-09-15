#ifndef NPC_CPU_H
#define NPC_CPU_H

#include "npc_wave.h"

#include <stdint.h>

class VerilatedContext;
#include "Vsim_top.h"

void npc_cpu_reset(VerilatedContext &context, Vsim_top &top, uint32_t cycles,
                   NpcWave &_wave);
void npc_cpu_step(VerilatedContext &context, Vsim_top &top, NpcWave &_wave);

#endif
