#include "pack_snapshot.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "pack_log.h"

/*
 * The CPU state layout is taken straight from the NEMU tree this packer was
 * built against, so field order can never drift silently. Build with the same
 * include paths (and therefore the same generated config) as that NEMU build.
 */
#include <isa-def.h>

#if defined(CONFIG_RV64)
#error "pack only understands riscv32 NEMU snapshots"
#endif
#if defined(CONFIG_RVE)
#error "pack only understands 32-register (non-RVE) NEMU snapshots"
#endif

_Static_assert(S_MODE == 0 && M_MODE == 1 && U_MODE == 2, "priv encoding changed");
_Static_assert(sizeof(((riscv32_CPU_state *)0)->gpr) / sizeof(word_t) == 32,
               "pack expects a 32-register CPU state");

static uint32_t read_le32(const uint8_t *data) {
  return (uint32_t)data[0] | ((uint32_t)data[1] << 8) | ((uint32_t)data[2] << 16) |
         ((uint32_t)data[3] << 24);
}

static uint64_t read_le64(const uint8_t *data) {
  return (uint64_t)read_le32(data) | ((uint64_t)read_le32(data + 4) << 32);
}

static bool label_is_safe(const char *label) {
  if (label[0] == '\0' || strlen(label) >= NPC_LABEL_MAX) {
    return false;
  }
  for (const char *p = label; *p != '\0'; p++) {
    bool ok = (*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') ||
              *p == '.' || *p == '_' || *p == '-';
    if (!ok) {
      return false;
    }
  }
  return true;
}

bool npc_points_load(const char *tsv_path, npc_point_t **out_points, size_t *out_count) {
  FILE *fp = fopen(tsv_path, "r");
  if (fp == NULL) {
    npc_error("cannot open manifest %s: %s", tsv_path, strerror(errno));
    return false;
  }

  npc_point_t *points = NULL;
  size_t count = 0;
  size_t capacity = 0;
  char line[2048];
  size_t lineno = 0;
  bool ok = true;

  while (ok && fgets(line, sizeof line, fp) != NULL) {
    lineno++;
    char *cursor = line;
    while (*cursor == ' ' || *cursor == '\t') {
      cursor++;
    }
    if (*cursor == '\0' || *cursor == '\n' || *cursor == '#') {
      continue;
    }

    char *fields[6] = {0};
    int field_count = 0;
    char *save = NULL;
    for (char *token = strtok_r(cursor, " \t\r\n", &save); token != NULL && field_count < 6;
         token = strtok_r(NULL, " \t\r\n", &save)) {
      fields[field_count++] = token;
    }
    if (field_count != 6) {
      npc_error("%s:%zu: expected 6 columns, got %d", tsv_path, lineno, field_count);
      ok = false;
      break;
    }

    npc_point_t point = {0};
    point.index = (uint32_t)strtoul(fields[0], NULL, 10);
    snprintf(point.label, sizeof point.label, "%s", fields[1]);
    point.inst = strtoull(fields[2], NULL, 10);
    snprintf(point.snapshot, sizeof point.snapshot, "%s", fields[3]);
    point.mtime = strtoull(fields[4], NULL, 0);
    point.mtimecmp = strtoull(fields[5], NULL, 0);

    if (!label_is_safe(point.label)) {
      npc_error("%s:%zu: label '%s' is not usable as a file name", tsv_path, lineno, point.label);
      ok = false;
      break;
    }
    if (strlen(point.snapshot) >= NPC_PATH_MAX - 1) {
      npc_error("%s:%zu: snapshot path is too long", tsv_path, lineno);
      ok = false;
      break;
    }
    if (count > 0) {
      const npc_point_t *previous = &points[count - 1];
      if (point.index != previous->index + 1) {
        npc_error("%s:%zu: index %u does not follow %u", tsv_path, lineno, point.index,
                  previous->index);
        ok = false;
        break;
      }
      if (point.inst <= previous->inst) {
        npc_error("%s:%zu: instruction count %llu is not greater than the previous %llu",
                  tsv_path, lineno, (unsigned long long)point.inst,
                  (unsigned long long)previous->inst);
        ok = false;
        break;
      }
    }

    if (count == capacity) {
      capacity = capacity == 0 ? 8 : capacity * 2;
      npc_point_t *grown = realloc(points, capacity * sizeof *points);
      if (grown == NULL) {
        npc_error("out of memory while reading the manifest");
        ok = false;
        break;
      }
      points = grown;
    }
    points[count++] = point;
  }

  fclose(fp);

  if (ok && count == 0) {
    npc_error("%s: no points found", tsv_path);
    ok = false;
  }
  if (!ok) {
    free(points);
    return false;
  }

  *out_points = points;
  *out_count = count;
  return true;
}

void npc_points_free(npc_point_t *points) { free(points); }

bool npc_snapshot_open(npc_snapshot_t *snapshot, const char *path) {
  memset(snapshot, 0, sizeof *snapshot);
  snprintf(snapshot->path, sizeof snapshot->path, "%s", path);

  snapshot->fp = fopen(path, "rb");
  if (snapshot->fp == NULL) {
    npc_error("cannot open snapshot %s: %s", path, strerror(errno));
    return false;
  }

  uint8_t header[NPC_SNAP_HEADER_SIZE];
  if (fread(header, 1, sizeof header, snapshot->fp) != sizeof header) {
    npc_error("%s: cannot read the snapshot header", path);
    goto fail;
  }
  if (memcmp(header, NPC_SNAP_MAGIC, 8) != 0) {
    npc_error("%s: not a NEMUSNAP file", path);
    goto fail;
  }

  snapshot->version = read_le32(header + 8);
  snapshot->cpu_state_size = read_le32(header + 12);
  snapshot->mem_base = read_le64(header + 16);
  snapshot->mem_size = read_le64(header + 24);

  if (snapshot->version != NPC_SNAP_VERSION) {
    npc_error("%s: unsupported snapshot version %u", path, snapshot->version);
    goto fail;
  }
  if (snapshot->cpu_state_size != sizeof(riscv32_CPU_state)) {
    npc_error("%s: cpu_state_size is %u but this build expects %zu; rebuild pack against the NEMU "
              "tree that produced the snapshot",
              path, snapshot->cpu_state_size, sizeof(riscv32_CPU_state));
    goto fail;
  }
  if (fseeko(snapshot->fp, 0, SEEK_END) != 0) {
    npc_error("%s: cannot seek to the end: %s", path, strerror(errno));
    goto fail;
  }
  off_t size = ftello(snapshot->fp);
  uint64_t expected =
      (uint64_t)NPC_SNAP_HEADER_SIZE + snapshot->cpu_state_size + snapshot->mem_size;
  if (size < 0 || (uint64_t)size != expected) {
    npc_error("%s: size is %lld, expected %llu (header + cpu state + memory)", path,
              (long long)size, (unsigned long long)expected);
    goto fail;
  }

  return true;

fail:
  npc_snapshot_close(snapshot);
  return false;
}

void npc_snapshot_close(npc_snapshot_t *snapshot) {
  if (snapshot->fp != NULL) {
    fclose(snapshot->fp);
    snapshot->fp = NULL;
  }
}

bool npc_snapshot_read_state(const npc_snapshot_t *snapshot, npc_arch_state_t *state) {
  riscv32_CPU_state cpu;
  if (fseeko(snapshot->fp, (off_t)NPC_SNAP_HEADER_SIZE, SEEK_SET) != 0) {
    npc_error("%s: cannot seek to the CPU state", snapshot->path);
    return false;
  }
  if (fread(&cpu, sizeof cpu, 1, snapshot->fp) != 1) {
    npc_error("%s: cannot read the CPU state", snapshot->path);
    return false;
  }

  memset(state, 0, sizeof *state);
  state->pc = (uint32_t)cpu.pc;
  state->priv = (uint32_t)cpu.priv;
  for (unsigned i = 0; i < 32; i++) {
    state->gpr[i] = (uint32_t)cpu.gpr[i];
  }
  unsigned slot = 0;
#define NPC_CSR_TAKE(name) state->csr[slot++] = (uint32_t)cpu.csr.name;
  NPC_CSR_LIST(NPC_CSR_TAKE)
#undef NPC_CSR_TAKE
  return true;
}

bool npc_snapshot_read_mem(const npc_snapshot_t *snapshot, uint64_t offset, void *buf, size_t len) {
  if (offset + len > snapshot->mem_size) {
    npc_error("%s: memory read [0x%llx, 0x%llx) is out of range", snapshot->path,
              (unsigned long long)offset, (unsigned long long)(offset + len));
    return false;
  }
  if (len == 0) {
    return true;
  }
  off_t base = (off_t)(NPC_SNAP_HEADER_SIZE + snapshot->cpu_state_size + offset);
  if (fseeko(snapshot->fp, base, SEEK_SET) != 0) {
    npc_error("%s: cannot seek to memory offset 0x%llx", snapshot->path,
              (unsigned long long)offset);
    return false;
  }
  if (fread(buf, 1, len, snapshot->fp) != len) {
    npc_error("%s: cannot read %zu bytes at memory offset 0x%llx", snapshot->path, len,
              (unsigned long long)offset);
    return false;
  }
  return true;
}

bool npc_snapshot_range_is_zero(const npc_snapshot_t *snapshot, uint64_t offset, uint64_t len) {
  uint8_t block[64 * 1024];
  while (len > 0) {
    size_t step = len < sizeof block ? (size_t)len : sizeof block;
    if (!npc_snapshot_read_mem(snapshot, offset, block, step)) {
      return false;
    }
    for (size_t i = 0; i < step; i++) {
      if (block[i] != 0) {
        return false;
      }
    }
    offset += step;
    len -= step;
  }
  return true;
}

const char *npc_priv_name(uint32_t priv) {
  switch (priv) {
    case S_MODE:
      return "S";
    case M_MODE:
      return "M";
    case U_MODE:
      return "U";
    default:
      return "?";
  }
}
