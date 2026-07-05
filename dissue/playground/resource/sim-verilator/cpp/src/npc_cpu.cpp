#include "npc_cpu.h"

#include "Vnpc.h"
#include "cstdint"
#include "npc_wave.h"
#include "verilated.h"

void npc_cpu_reset(VerilatedContext &context, Vnpc &top, uint32_t cycles,
                   NpcWave &_wave) {
  top.reset = 1;
  top.clock = 0;
  top.eval();
  context.timeInc(1);

  for (uint32_t i = 0; i < cycles; ++i) {
    top.clock = 1;
    top.eval();
    context.timeInc(1);
    _wave.dump(context.time());

    top.clock = 0;
    top.eval();
    context.timeInc(1);
    _wave.dump(context.time());
  }

  top.reset = 0;
  top.eval();
  context.timeInc(1);
}

void npc_cpu_step(VerilatedContext &context, Vnpc &top, NpcWave &_wave) {
  top.clock = 1;
  top.eval();
  context.timeInc(1);

  _wave.dump(context.time());

  top.clock = 0;
  top.eval();
  context.timeInc(1);

  _wave.dump(context.time());
}
