#include "test.h"

static volatile u32 words[2] __attribute__((aligned(8))) = {
    0x55667788u,
    0x11223344u,
};

static volatile u32 full_word_index = 0u;
static volatile u32 partial_byte_index = 5u;

int main(void) {
  // Warm the 64-bit line before the stores below update it.
  if (words[1] != 0x11223344u) return 10;

  // The older store waits on this index load. The younger fixed-address load
  // reaches the StoreQueue first, then completes by forwarding from the store.
  u32 word_index = full_word_index;
  words[word_index] = 0x89abcdefu;
  u32 full_forward = words[0];
  if (full_forward != 0x89abcdefu) return 11;

  volatile u8 *bytes = (volatile u8 *)words;
  u32 byte_index = partial_byte_index;
  bytes[byte_index] = 0xeeu;
  u32 partial_forward = words[1];
  if (partial_forward != 0x1122ee44u) return 12;

  if (words[0] != 0x89abcdefu) return 13;
  if (words[1] != 0x1122ee44u) return 14;
  return 0;
}
