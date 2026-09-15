// Host side of the vsoc AXI smoke test.
//
// Provides the frozen DPI contract (npc_pmem_read / npc_pmem_write) backed by a
// real 512 MiB array, and toggles the clock. A host-side out-of-range call is
// treated as a hard error: the RTL is supposed to answer DECERR first.
#include "Vaxi4_smoke_tb.h"
#include "verilated.h"

#include <cstdint>
#include <cstdio>
#include <vector>

namespace {

constexpr uint32_t kPmemBase = 0x8000'0000u;
constexpr uint32_t kPmemSize = 0x2000'0000u;  // 512 MiB, matches vsoc_pkg

std::vector<uint8_t> g_mem;
int                  g_host_errors = 0;

bool in_pmem(uint32_t addr, int len) {
  if (addr < kPmemBase) return false;
  return static_cast<uint64_t>(addr - kPmemBase) + static_cast<uint64_t>(len) <= kPmemSize;
}

void report_oob(const char* what, uint32_t addr, int len) {
  std::fprintf(stderr, "[smoke] HOST ERROR: %s outside pmem: addr=0x%08x len=%d\n",
               what, addr, len);
  g_host_errors++;
}

}  // namespace

extern "C" void npc_pmem_read(int addr, int len, int* data) {
  const uint32_t a = static_cast<uint32_t>(addr);
  if (!in_pmem(a, len)) {
    report_oob("read", a, len);
    *data = 0;
    return;
  }
  const uint32_t off = a - kPmemBase;
  uint32_t       value = 0;
  for (int i = 0; i < len; ++i) {
    value |= static_cast<uint32_t>(g_mem[off + i]) << (8 * i);
  }
  *data = static_cast<int>(value);
}

extern "C" void npc_pmem_write(int addr, int len, int data) {
  const uint32_t a = static_cast<uint32_t>(addr);
  if (!in_pmem(a, len)) {
    report_oob("write", a, len);
    return;
  }
  const uint32_t off = a - kPmemBase;
  for (int i = 0; i < len; ++i) {
    g_mem[off + i] = static_cast<uint8_t>((static_cast<uint32_t>(data) >> (8 * i)) & 0xffu);
  }
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  g_mem.assign(kPmemSize, 0);

  Vaxi4_smoke_tb top;
  top.clock = 0;
  top.reset = 1;

  auto step = [&top]() {
    top.clock = 0;
    top.eval();
    top.clock = 1;
    top.eval();
    top.clock = 0;
    top.eval();
  };

  for (int i = 0; i < 16; ++i) step();
  top.reset = 0;

  constexpr int kMaxCycles = 200000;
  int           cycles     = 0;
  while (top.done == 0 && cycles < kMaxCycles) {
    step();
    ++cycles;
  }

  std::printf("[smoke] cycles=%d rtl_errors=%u host_errors=%d\n",
              cycles, static_cast<unsigned>(top.error_count), g_host_errors);

  if (top.done == 0) {
    std::printf("[smoke] TIMEOUT: simulation did not finish\n");
    return 2;
  }
  if (top.error_count != 0 || g_host_errors != 0) {
    std::printf("[smoke] FAILED\n");
    return 1;
  }
  std::printf("[smoke] PASS\n");
  return 0;
}
