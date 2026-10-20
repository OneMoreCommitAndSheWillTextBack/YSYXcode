#include "pack_image.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <zstd.h>

#include "pack_log.h"

/* ---------------------------------------------------------------- hashing --
 *
 * npc64: a fast, non-cryptographic 64-bit hash used to verify that a decoded
 * image still matches what the packer produced. It is mirrored by the runner,
 * so the definition is frozen:
 *
 *   seed  = 0xcbf29ce484222325
 *   prime = 0x100000001b3
 *   mix(v): v ^= v >> 33; v *= 0xff51afd7ed558ccd; v ^= v >> 33;
 *           v *= 0xc4ceb9fe1a85ec53; v ^= v >> 33
 *   for every 8-byte little-endian group: h = (h ^ mix(group)) * prime
 *   a final group shorter than 8 bytes is zero-padded on the high side
 *   digest = mix(h ^ total_length)
 */
#define NPC64_SEED UINT64_C(0xcbf29ce484222325)
#define NPC64_PRIME UINT64_C(0x100000001b3)

static inline uint64_t npc64_mix(uint64_t value) {
  value ^= value >> 33;
  value *= UINT64_C(0xff51afd7ed558ccd);
  value ^= value >> 33;
  value *= UINT64_C(0xc4ceb9fe1a85ec53);
  value ^= value >> 33;
  return value;
}

typedef struct {
  uint64_t h;
  uint8_t carry[8];
  size_t carry_len;
} npc64_state_t;

static void npc64_init(npc64_state_t *state) {
  state->h = NPC64_SEED;
  state->carry_len = 0;
}

static uint64_t npc64_group(const uint8_t *data) {
  uint64_t value = 0;
  for (unsigned i = 0; i < 8; i++) {
    value |= (uint64_t)data[i] << (8 * i);
  }
  return value;
}

static void npc64_update(npc64_state_t *state, const uint8_t *data, size_t len) {
  if (state->carry_len > 0) {
    while (len > 0 && state->carry_len < 8) {
      state->carry[state->carry_len++] = *data++;
      len--;
    }
    if (state->carry_len == 8) {
      state->h = (state->h ^ npc64_mix(npc64_group(state->carry))) * NPC64_PRIME;
      state->carry_len = 0;
    }
  }
  while (len >= 8) {
    state->h = (state->h ^ npc64_mix(npc64_group(data))) * NPC64_PRIME;
    data += 8;
    len -= 8;
  }
  if (len > 0) {
    memcpy(state->carry, data, len);
    state->carry_len = len;
  }
}

static uint64_t npc64_final(npc64_state_t *state, uint64_t total) {
  if (state->carry_len > 0) {
    uint8_t padded[8] = {0};
    memcpy(padded, state->carry, state->carry_len);
    state->h = (state->h ^ npc64_mix(npc64_group(padded))) * NPC64_PRIME;
    state->carry_len = 0;
  }
  return npc64_mix(state->h ^ total);
}

/* ------------------------------------------------------------------ sinks -- */

typedef struct {
  FILE *fp;
  uint64_t position;
  uint64_t total;
  uint64_t written;
} sparse_ctx_t;

static int sparse_write(void *ctx, const void *buf, size_t len) {
  sparse_ctx_t *sparse = ctx;
  if (fwrite(buf, 1, len, sparse->fp) != len) {
    return -1;
  }
  sparse->position += len;
  sparse->written += len;
  return 0;
}

static int sparse_skip(void *ctx, uint64_t len) {
  sparse_ctx_t *sparse = ctx;
  if (fflush(sparse->fp) != 0) {
    return -1;
  }
  sparse->position += len;
  if (fseeko(sparse->fp, (off_t)sparse->position, SEEK_SET) != 0) {
    return -1;
  }
  return 0;
}

static int sparse_finish(void *ctx) {
  sparse_ctx_t *sparse = ctx;
  if (fflush(sparse->fp) != 0) {
    return -1;
  }
  if (ftruncate(fileno(sparse->fp), (off_t)sparse->total) != 0) {
    return -1;
  }
  return 0;
}

static void sparse_destroy(void *ctx) {
  sparse_ctx_t *sparse = ctx;
  if (sparse->fp != NULL) {
    fclose(sparse->fp);
  }
  free(sparse);
}

bool npc_sink_open_sparse(const char *path, uint64_t total_len, npc_sink_t *sink) {
  sparse_ctx_t *ctx = calloc(1, sizeof *ctx);
  if (ctx == NULL) {
    npc_error("out of memory");
    return false;
  }
  ctx->fp = fopen(path, "wb");
  if (ctx->fp == NULL) {
    npc_error("cannot create %s: %s", path, strerror(errno));
    free(ctx);
    return false;
  }
  ctx->total = total_len;
  sink->write = sparse_write;
  sink->skip = sparse_skip;
  sink->finish = sparse_finish;
  sink->destroy = sparse_destroy;
  sink->ctx = ctx;
  return true;
}

typedef struct {
  FILE *fp;
  ZSTD_CCtx *cctx;
  uint8_t *out;
  size_t out_cap;
  uint64_t written;
} zstd_ctx_t;

static int zstd_write(void *ctx, const void *buf, size_t len) {
  zstd_ctx_t *zstd = ctx;
  ZSTD_inBuffer in = {buf, len, 0};
  while (in.pos < in.size) {
    ZSTD_outBuffer out = {zstd->out, zstd->out_cap, 0};
    size_t remaining = ZSTD_compressStream2(zstd->cctx, &out, &in, ZSTD_e_continue);
    if (ZSTD_isError(remaining)) {
      npc_error("zstd: %s", ZSTD_getErrorName(remaining));
      return -1;
    }
    if (out.pos > 0) {
      if (fwrite(zstd->out, 1, out.pos, zstd->fp) != out.pos) {
        return -1;
      }
      zstd->written += out.pos;
    }
  }
  return 0;
}

static int zstd_finish(void *ctx) {
  zstd_ctx_t *zstd = ctx;
  ZSTD_inBuffer in = {NULL, 0, 0};
  for (;;) {
    ZSTD_outBuffer out = {zstd->out, zstd->out_cap, 0};
    size_t remaining = ZSTD_compressStream2(zstd->cctx, &out, &in, ZSTD_e_end);
    if (ZSTD_isError(remaining)) {
      npc_error("zstd: %s", ZSTD_getErrorName(remaining));
      return -1;
    }
    if (out.pos > 0) {
      if (fwrite(zstd->out, 1, out.pos, zstd->fp) != out.pos) {
        return -1;
      }
      zstd->written += out.pos;
    }
    if (remaining == 0) {
      break;
    }
  }
  return fflush(zstd->fp) == 0 ? 0 : -1;
}

static void zstd_destroy(void *ctx) {
  zstd_ctx_t *zstd = ctx;
  if (zstd->cctx != NULL) {
    ZSTD_freeCCtx(zstd->cctx);
  }
  if (zstd->fp != NULL) {
    fclose(zstd->fp);
  }
  free(zstd->out);
  free(zstd);
}

bool npc_sink_open_zstd(const char *path, int level, uint64_t total_len, npc_sink_t *sink) {
  (void)total_len;
  zstd_ctx_t *ctx = calloc(1, sizeof *ctx);
  if (ctx == NULL) {
    npc_error("out of memory");
    return false;
  }
  ctx->out_cap = ZSTD_CStreamOutSize();
  ctx->out = malloc(ctx->out_cap);
  ctx->cctx = ZSTD_createCCtx();
  if (ctx->out == NULL || ctx->cctx == NULL) {
    npc_error("cannot initialise zstd");
    zstd_destroy(ctx);
    return false;
  }
  ctx->fp = fopen(path, "wb");
  if (ctx->fp == NULL) {
    npc_error("cannot create %s: %s", path, strerror(errno));
    zstd_destroy(ctx);
    return false;
  }
  ZSTD_CCtx_setParameter(ctx->cctx, ZSTD_c_compressionLevel, level);
  ZSTD_CCtx_setParameter(ctx->cctx, ZSTD_c_checksumFlag, 1);

  sink->write = zstd_write;
  sink->skip = NULL;
  sink->finish = zstd_finish;
  sink->destroy = zstd_destroy;
  sink->ctx = ctx;
  return true;
}

typedef struct {
  FILE *fp;
  uint64_t written;
} stream_ctx_t;

static int stream_write(void *ctx, const void *buf, size_t len) {
  stream_ctx_t *stream = ctx;
  if (fwrite(buf, 1, len, stream->fp) != len) {
    return -1;
  }
  stream->written += len;
  return 0;
}

static int stream_finish(void *ctx) {
  stream_ctx_t *stream = ctx;
  return fflush(stream->fp) == 0 ? 0 : -1;
}

static void stream_destroy(void *ctx) { free(ctx); }

bool npc_sink_open_stream(FILE *fp, npc_sink_t *sink) {
  stream_ctx_t *ctx = calloc(1, sizeof *ctx);
  if (ctx == NULL) {
    npc_error("out of memory");
    return false;
  }
  ctx->fp = fp;
  sink->write = stream_write;
  sink->skip = NULL;
  sink->finish = stream_finish;
  sink->destroy = stream_destroy;
  sink->ctx = ctx;
  return true;
}

void npc_sink_close(npc_sink_t *sink) {
  if (sink->destroy != NULL) {
    sink->destroy(sink->ctx);
  }
  memset(sink, 0, sizeof *sink);
}

/* -------------------------------------------------------------- scanning -- */

static bool chunk_is_zero(const uint8_t *data, size_t len) {
  for (size_t i = 0; i < len; i++) {
    if (data[i] != 0) {
      return false;
    }
  }
  return true;
}

bool npc_scan_memory(const npc_snapshot_t *snapshot, npc_image_stats_t *stats) {
  uint8_t *block = malloc(NPC_IO_BLOCK);
  if (block == NULL) {
    npc_error("out of memory");
    return false;
  }

  memset(stats, 0, sizeof *stats);
  for (uint64_t offset = 0; offset < snapshot->mem_size; offset += NPC_IO_BLOCK) {
    size_t len = snapshot->mem_size - offset < NPC_IO_BLOCK ? (size_t)(snapshot->mem_size - offset)
                                                            : NPC_IO_BLOCK;
    if (!npc_snapshot_read_mem(snapshot, offset, block, len)) {
      free(block);
      return false;
    }
    for (size_t p = 0; p < len; p += NPC_CHUNK_SIZE) {
      size_t chunk = len - p < NPC_CHUNK_SIZE ? len - p : NPC_CHUNK_SIZE;
      if (chunk_is_zero(block + p, chunk)) {
        continue;
      }
      stats->nonzero_chunks++;
      stats->top_nonzero = offset + p + chunk;
      for (size_t i = 0; i < chunk; i++) {
        if (block[p + i] != 0) {
          stats->nonzero_bytes++;
        }
      }
    }
  }

  free(block);
  return true;
}

/* -------------------------------------------------------------- emitting -- */

static void apply_injects(uint8_t *chunk, uint64_t addr, size_t len, const npc_inject_t *injects,
                          size_t n_injects) {
  for (size_t i = 0; i < n_injects; i++) {
    const npc_inject_t *inject = &injects[i];
    uint64_t start = inject->paddr > addr ? inject->paddr : addr;
    uint64_t end = inject->paddr + inject->len < addr + len ? inject->paddr + inject->len
                                                            : addr + len;
    if (start >= end) {
      continue;
    }
    memcpy(chunk + (size_t)(start - addr), inject->data + (size_t)(start - inject->paddr),
           (size_t)(end - start));
  }
}

bool npc_emit_image(const npc_snapshot_t *snapshot, const npc_inject_t *injects, size_t n_injects,
                    uint64_t image_len, npc_sink_t *sink, npc_image_stats_t *stats) {
  uint8_t *block = malloc(NPC_IO_BLOCK);
  uint8_t *chunk = malloc(NPC_CHUNK_SIZE);
  if (block == NULL || chunk == NULL) {
    npc_error("out of memory");
    free(block);
    free(chunk);
    return false;
  }

  npc64_state_t hash;
  npc64_init(&hash);
  uint64_t written = 0;
  bool ok = true;

  for (uint64_t offset = 0; ok && offset < image_len; offset += NPC_IO_BLOCK) {
    size_t len = image_len - offset < NPC_IO_BLOCK ? (size_t)(image_len - offset) : NPC_IO_BLOCK;
    ok = npc_snapshot_read_mem(snapshot, offset, block, len);
    for (size_t p = 0; ok && p < len; p += NPC_CHUNK_SIZE) {
      size_t size = len - p < NPC_CHUNK_SIZE ? len - p : NPC_CHUNK_SIZE;
      memcpy(chunk, block + p, size);
      uint64_t addr = snapshot->mem_base + offset + p;
      apply_injects(chunk, addr, size, injects, n_injects);
      npc64_update(&hash, chunk, size);
      if (chunk_is_zero(chunk, size) && sink->skip != NULL) {
        ok = sink->skip(sink->ctx, size) == 0;
      } else {
        ok = sink->write(sink->ctx, chunk, size) == 0;
        written += size;
      }
    }
  }

  if (ok && sink->finish != NULL) {
    ok = sink->finish(sink->ctx) == 0;
  }
  if (ok) {
    stats->written_bytes = written;
    stats->hash = npc64_final(&hash, image_len);
  } else {
    npc_error("failed while writing the image");
  }

  free(block);
  free(chunk);
  return ok;
}
