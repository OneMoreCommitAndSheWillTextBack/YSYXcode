#ifndef NPC_PACK_SNAPSHOT_H
#define NPC_PACK_SNAPSHOT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "npc_csr_list.h"

#define NPC_SNAP_MAGIC "NEMUSNAP"
#define NPC_SNAP_VERSION 1u
#define NPC_SNAP_HEADER_SIZE 32u
#define NPC_PATH_MAX 512
#define NPC_LABEL_MAX 64

/* One row of the manifest produced by ckpt_gen.py. */
typedef struct {
  uint32_t index;
  char label[NPC_LABEL_MAX];
  uint64_t inst;
  char snapshot[NPC_PATH_MAX];
  uint64_t mtime;
  uint64_t mtimecmp;
} npc_point_t;

/* The architectural state a checkpoint restores. */
typedef struct {
  uint32_t pc;
  uint32_t priv;
  uint32_t gpr[32];
  uint32_t csr[NPC_CSR_COUNT];
} npc_arch_state_t;

typedef struct {
  FILE *fp;
  char path[NPC_PATH_MAX];
  uint32_t version;
  uint32_t cpu_state_size;
  uint64_t mem_base;
  uint64_t mem_size;
} npc_snapshot_t;

/* Manifest */
bool npc_points_load(const char *tsv_path, npc_point_t **points, size_t *count);
void npc_points_free(npc_point_t *points);

/* Snapshot */
bool npc_snapshot_open(npc_snapshot_t *snapshot, const char *path);
void npc_snapshot_close(npc_snapshot_t *snapshot);
bool npc_snapshot_read_state(const npc_snapshot_t *snapshot, npc_arch_state_t *state);
bool npc_snapshot_read_mem(const npc_snapshot_t *snapshot, uint64_t offset, void *buf, size_t len);
bool npc_snapshot_range_is_zero(const npc_snapshot_t *snapshot, uint64_t offset, uint64_t len);

const char *npc_priv_name(uint32_t priv);

#endif
