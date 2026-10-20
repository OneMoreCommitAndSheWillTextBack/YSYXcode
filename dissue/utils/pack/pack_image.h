#ifndef NPC_PACK_IMAGE_H
#define NPC_PACK_IMAGE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "pack_snapshot.h"

#define NPC_CHUNK_SIZE 4096u
#define NPC_IO_BLOCK (1u << 20)

/* A blob to be placed at a physical address, overriding whatever the snapshot
 * holds there. This is the seam the restorer will use later. */
typedef struct {
  uint64_t paddr;
  uint64_t len;
  const uint8_t *data;
} npc_inject_t;

typedef struct {
  uint64_t nonzero_bytes;
  uint64_t nonzero_chunks;
  uint64_t top_nonzero;  /* end offset (exclusive) of the last non-zero byte */
  uint64_t written_bytes;
  uint64_t hash; /* FNV-1a 64 over the logical image */
} npc_image_stats_t;

/* A destination for image bytes. `skip` is optional: sinks that can seek turn
 * a zero chunk into a hole, the others have to write it out. */
typedef struct {
  int (*write)(void *ctx, const void *buf, size_t len);
  int (*skip)(void *ctx, uint64_t len);
  int (*finish)(void *ctx);
  void (*destroy)(void *ctx);
  void *ctx;
} npc_sink_t;

bool npc_sink_open_sparse(const char *path, uint64_t total_len, npc_sink_t *sink);
bool npc_sink_open_zstd(const char *path, int level, uint64_t total_len, npc_sink_t *sink);
bool npc_sink_open_stream(FILE *fp, npc_sink_t *sink);
void npc_sink_close(npc_sink_t *sink);

bool npc_scan_memory(const npc_snapshot_t *snapshot, npc_image_stats_t *stats);
bool npc_emit_image(const npc_snapshot_t *snapshot, const npc_inject_t *injects, size_t n_injects,
                    uint64_t image_len, npc_sink_t *sink, npc_image_stats_t *stats);

#endif
