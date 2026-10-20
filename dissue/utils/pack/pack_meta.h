#ifndef NPC_PACK_META_H
#define NPC_PACK_META_H

#include <stdbool.h>
#include <stdint.h>

#include "pack_image.h"
#include "pack_snapshot.h"

typedef struct {
  bool has_expected;
  npc_arch_state_t state;
} npc_expected_t;

typedef struct {
  uint32_t index;
  const char *label;
  const char *image; /* final artifact path, or "-" when streamed to stdout */
  uint64_t snap_inst;
  uint64_t window_inst;
  uint64_t mtime;
  uint64_t mtimecmp;
  bool trimmed;
  bool injected;
  bool mtimecmp_pushed;
  uint64_t image_len;
  uint64_t out_size;
  uint64_t mem_hash;
  npc_image_stats_t mem_stats;
  npc_arch_state_t state;
  npc_expected_t expected;
} npc_case_t;

bool npc_case_write_json(const char *path, const npc_case_t *item);
bool npc_index_append(const char *path, const npc_case_t *item, const char *json_path);
bool npc_ensure_dir(const char *path);
void npc_case_print_report(const npc_case_t *item);
void npc_report_header(void);

#endif
