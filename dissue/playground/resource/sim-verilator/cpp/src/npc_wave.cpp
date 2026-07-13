#include "npc_wave.h"

#include "Vnpc.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include <memory>

NpcWave::NpcWave() : trace_(nullptr) {}

NpcWave::~NpcWave() { close(); }

void NpcWave::init(VerilatedContext *context, Vnpc *top, const char *path) {
  if (context == nullptr || top == nullptr) {
    return;
  }

  const char *wave_path = path == nullptr ? "wave.vcd" : path;

  Verilated::traceEverOn(true);
  context->traceEverOn(true);

  trace_ = std::make_unique<VerilatedVcdC>();
  top->trace(trace_.get(), 0);
  trace_->open(wave_path);
}

void NpcWave::enable() { enable_ = true; }

void NpcWave::disable() { enable_ = false; }

void NpcWave::close() {
  if (trace_ != nullptr) {
    trace_->close();
    trace_.reset();
  }
}

void NpcWave::abandon() {
  // A lightsss child owns the duplicated trace after a process handoff.
  trace_.release();
  enable_ = false;
}

void NpcWave::dump(uint64_t time) {
  if (!enable_ || trace_ == nullptr) {
    return;
  }

  trace_->dump(time);
}
