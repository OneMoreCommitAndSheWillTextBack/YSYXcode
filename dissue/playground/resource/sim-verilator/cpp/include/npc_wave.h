#ifndef NPC_WAVE_H
#define NPC_WAVE_H

#include <memory>
#include <stdint.h>

class VerilatedContext;
class VerilatedVcdC;
class Vnpc;

class NpcWave {
public:
  NpcWave();
  ~NpcWave();

  NpcWave(const NpcWave &) = delete;
  NpcWave &operator=(const NpcWave &) = delete;

  void init(VerilatedContext *context, Vnpc *top, const char *path);
  void enable();
  void disable();
  void close();
  void abandon();
  void dump(uint64_t time);

private:
  std::unique_ptr<VerilatedVcdC> trace_;
  bool enable_ = false;
};

#endif
