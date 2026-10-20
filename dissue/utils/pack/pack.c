/*
 * pack - turn NEMU snapshots into images the dissue simulator can load.
 *
 * The output of a case is the *whole physical memory image*: everything the
 * snapshot holds, optionally trimmed to the last non-zero chunk and optionally
 * with blobs injected at fixed physical addresses. That is exactly what the
 * simulator's existing --image path expects, so neither the RTL nor the
 * harness has to change.
 *
 *   pack --manifest cases/manifest.tsv --out-dir cases/ --compress
 *   pack --manifest cases/manifest.tsv --case 000 --stdout --json case.json > image
 */
#include <errno.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "pack_image.h"
#include "pack_log.h"
#include "pack_meta.h"
#include "pack_restore.h"
#include "pack_snapshot.h"

/* One second on the 1 MHz timebase the platform declares: far beyond any
 * measurement window, so a pushed mtimecmp cannot fire inside one. */
#define NPC_MTIMECMP_PUSH UINT64_C(1000000)
#define NPC_ZSTD_LEVEL 9
#define NPC_INJECT_MAX 8
#define NPC_INJECT_MAX_BYTES (4u << 20)
#define NPC_RESERVED_DEFAULT UINT64_C(0x9fff0000)

typedef struct {
  uint64_t paddr;
  char path[NPC_PATH_MAX];
} inject_spec_t;

typedef struct {
  const char *manifest;
  const char *out_dir;
  bool to_stdout;
  const char *json_path;
  const char *case_selector;
  bool compress;
  bool trim;
  bool push_mtimecmp;
  bool delete_source;
  bool report;
  bool reserve_check;
  uint64_t reserve_paddr;
  uint64_t reserve_size;
  const char *restore_blob;
  uint64_t reserved_paddr;
  inject_spec_t inject_specs[NPC_INJECT_MAX];
  size_t n_inject_specs;
} cli_t;

static uint64_t align_up(uint64_t value, uint64_t alignment) {
  return (value + alignment - 1) / alignment * alignment;
}

static bool parse_hex(const char *text, uint64_t *value) {
  char *end = NULL;
  errno = 0;
  unsigned long long parsed = strtoull(text, &end, 0);
  if (errno != 0 || end == text || *end != '\0') {
    return false;
  }
  *value = (uint64_t)parsed;
  return true;
}

/* "<paddr>:<size>" or "<paddr>:<file>" */
static bool parse_pair(const char *text, uint64_t *first, char *second, size_t second_size) {
  const char *colon = strchr(text, ':');
  if (colon == NULL || colon == text || colon[1] == '\0') {
    return false;
  }
  char address[64];
  size_t address_len = (size_t)(colon - text);
  if (address_len >= sizeof address) {
    return false;
  }
  memcpy(address, text, address_len);
  address[address_len] = '\0';
  if (!parse_hex(address, first)) {
    return false;
  }
  snprintf(second, second_size, "%s", colon + 1);
  return true;
}

static bool load_file(const char *path, uint8_t **data, size_t *len) {
  FILE *fp = fopen(path, "rb");
  if (fp == NULL) {
    npc_error("cannot open %s: %s", path, strerror(errno));
    return false;
  }
  if (fseeko(fp, 0, SEEK_END) != 0) {
    npc_error("cannot seek in %s", path);
    fclose(fp);
    return false;
  }
  off_t size = ftello(fp);
  if (size <= 0 || (uint64_t)size > NPC_INJECT_MAX_BYTES) {
    npc_error("%s: inject blob must be between 1 byte and %u bytes", path, NPC_INJECT_MAX_BYTES);
    fclose(fp);
    return false;
  }
  uint8_t *buffer = malloc((size_t)size);
  if (buffer == NULL) {
    npc_error("out of memory");
    fclose(fp);
    return false;
  }
  rewind(fp);
  if (fread(buffer, 1, (size_t)size, fp) != (size_t)size) {
    npc_error("cannot read %s", path);
    free(buffer);
    fclose(fp);
    return false;
  }
  fclose(fp);
  *data = buffer;
  *len = (size_t)size;
  return true;
}

static void usage(FILE *out) {
  fprintf(out,
          "usage: pack --manifest <tsv> ( --out-dir <dir> [--compress] | --stdout --json <file> )\n"
          "            [--case <index|label>] [--no-trim] [--inject <paddr>:<file>]...\n"
          "            [--restore-blob <restorer.bin> [--reserved <paddr>]]\n"
          "            [--reserve-check <paddr>:<size>] [--push-mtimecmp]\n"
          "            [--delete-source] [--report]\n"
          "\n"
          "  --manifest    point list produced by ckpt_gen.py\n"
          "  --out-dir     write one image (and sidecar json) per case\n"
          "  --stdout      stream a single case's image to stdout (implies --case)\n"
          "  --json        sidecar location for --stdout\n"
          "  --case        restrict --out-dir to one case; required by --stdout\n"
          "  --compress    zstd-compress the image (--out-dir only)\n"
          "  --no-trim     keep the full physical memory instead of trimming zeros\n"
          "  --inject      place a blob at a physical address, overriding the snapshot\n"
          "  --restore-blob   make the image self restoring: write the trampoline at the\n"
          "                   memory base and the restorer plus state table at --reserved\n"
          "  --reserved    reserved page address for --restore-blob (default 0x9fff0000)\n"
          "  --reserve-check  require a range to be all zero in every snapshot\n"
          "  --push-mtimecmp  record mtimecmp far enough ahead to keep windows tick free\n"
          "  --delete-source  remove each snapshot once its case is packed\n"
          "  --report      print a per case summary to stderr\n");
}

static bool parse_cli(int argc, char **argv, cli_t *cli) {
  static const struct option options[] = {
      {"manifest", required_argument, NULL, 'm'},       {"out-dir", required_argument, NULL, 'o'},
      {"stdout", no_argument, NULL, 'S'},               {"json", required_argument, NULL, 'j'},
      {"case", required_argument, NULL, 'c'},           {"compress", no_argument, NULL, 'z'},
      {"no-trim", no_argument, NULL, 'T'},              {"inject", required_argument, NULL, 'i'},
      {"restore-blob", required_argument, NULL, 'B'},   {"reserved", required_argument, NULL, 'A'},
      {"reserve-check", required_argument, NULL, 'R'},  {"push-mtimecmp", no_argument, NULL, 'P'},
      {"delete-source", no_argument, NULL, 'D'},        {"report", no_argument, NULL, 'r'},
      {"help", no_argument, NULL, 'h'},                 {NULL, 0, NULL, 0},
  };

  cli->reserved_paddr = NPC_RESERVED_DEFAULT;

  int option = 0;
  while ((option = getopt_long(argc, argv, "m:o:Sj:c:zTi:B:A:R:PDrh", options, NULL)) != -1) {
    switch (option) {
      case 'm':
        cli->manifest = optarg;
        break;
      case 'o':
        cli->out_dir = optarg;
        break;
      case 'S':
        cli->to_stdout = true;
        break;
      case 'j':
        cli->json_path = optarg;
        break;
      case 'c':
        cli->case_selector = optarg;
        break;
      case 'B':
        cli->restore_blob = optarg;
        break;
      case 'A':
        if (!parse_hex(optarg, &cli->reserved_paddr)) {
          npc_error("--reserved expects a physical address, got '%s'", optarg);
          return false;
        }
        break;
      case 'z':
        cli->compress = true;
        break;
      case 'T':
        cli->trim = false;
        break;
      case 'i': {
        if (cli->n_inject_specs >= NPC_INJECT_MAX) {
          npc_error("at most %d --inject options are supported", NPC_INJECT_MAX);
          return false;
        }
        inject_spec_t *spec = &cli->inject_specs[cli->n_inject_specs];
        char path[NPC_PATH_MAX];
        if (!parse_pair(optarg, &spec->paddr, path, sizeof path)) {
          npc_error("--inject expects <paddr>:<file>, got '%s'", optarg);
          return false;
        }
        snprintf(spec->path, sizeof spec->path, "%s", path);
        cli->n_inject_specs++;
        break;
      }
      case 'R': {
        char size_text[64];
        if (!parse_pair(optarg, &cli->reserve_paddr, size_text, sizeof size_text) ||
            !parse_hex(size_text, &cli->reserve_size) || cli->reserve_size == 0) {
          npc_error("--reserve-check expects <paddr>:<size>, got '%s'", optarg);
          return false;
        }
        cli->reserve_check = true;
        break;
      }
      case 'P':
        cli->push_mtimecmp = true;
        break;
      case 'D':
        cli->delete_source = true;
        break;
      case 'r':
        cli->report = true;
        break;
      case 'h':
        usage(stdout);
        exit(0);
      default:
        usage(stderr);
        return false;
    }
  }

  if (cli->manifest == NULL) {
    npc_error("--manifest is required");
    return false;
  }
  if (cli->to_stdout == (cli->out_dir != NULL)) {
    npc_error("exactly one of --out-dir and --stdout is required");
    return false;
  }
  if (cli->to_stdout && cli->case_selector == NULL) {
    npc_error("--stdout needs --case to pick a single case");
    return false;
  }
  if (cli->to_stdout && cli->json_path == NULL) {
    npc_error("--stdout needs --json for the sidecar metadata");
    return false;
  }
  if (cli->to_stdout && cli->compress) {
    npc_error("--compress is meaningless with --stdout; streams are not compressed");
    return false;
  }
  return true;
}

static bool case_selected(const cli_t *cli, const npc_point_t *point) {
  if (cli->case_selector == NULL) {
    return true;
  }
  if (strcmp(cli->case_selector, point->label) == 0) {
    return true;
  }
  uint64_t index = 0;
  return parse_hex(cli->case_selector, &index) && index == point->index;
}

static bool load_injects(const cli_t *cli, npc_inject_t *injects, uint8_t **buffers) {
  for (size_t i = 0; i < cli->n_inject_specs; i++) {
    size_t len = 0;
    if (!load_file(cli->inject_specs[i].path, &buffers[i], &len)) {
      return false;
    }
    injects[i].paddr = cli->inject_specs[i].paddr;
    injects[i].len = len;
    injects[i].data = buffers[i];
  }
  return true;
}

static void free_injects(const cli_t *cli, uint8_t **buffers) {
  for (size_t i = 0; i < cli->n_inject_specs; i++) {
    free(buffers[i]);
  }
}

static bool read_expected(const npc_point_t *point, npc_expected_t *expected) {
  npc_snapshot_t snapshot;
  if (!npc_snapshot_open(&snapshot, point->snapshot)) {
    return false;
  }
  bool ok = npc_snapshot_read_state(&snapshot, &expected->state);
  npc_snapshot_close(&snapshot);
  expected->has_expected = ok;
  return ok;
}

/* The restorer is the same program for every case, so it is loaded once. */
static const uint8_t *g_restorer = NULL;
static size_t g_restorer_len = 0;

static bool process_case(const cli_t *cli, const npc_point_t *points, size_t count, size_t index,
                         const npc_inject_t *injects, size_t n_injects, uint64_t *total_out) {
  const npc_point_t *point = &points[index];
  npc_case_t item = {0};
  npc_snapshot_t snapshot;
  npc_sink_t sink = {0};
  char temp_path[NPC_PATH_MAX * 2] = {0};
  char image_path[NPC_PATH_MAX * 2] = {0};
  char json_path[NPC_PATH_MAX * 2] = {0};
  char base[NPC_LABEL_MAX + 16];
  bool ok = false;

  if (snprintf(base, sizeof base, "%03u-%s", point->index, point->label) >= (int)sizeof base) {
    npc_error("case name is too long");
    return false;
  }

  if (!npc_snapshot_open(&snapshot, point->snapshot)) {
    return false;
  }
  if (!npc_snapshot_read_state(&snapshot, &item.state)) {
    npc_snapshot_close(&snapshot);
    return false;
  }

  item.mtime = point->mtime;
  item.mtimecmp = point->mtimecmp;
  if (cli->push_mtimecmp) {
    if (item.mtime < item.mtimecmp) {
      item.mtimecmp = item.mtime + NPC_MTIMECMP_PUSH;
      item.mtimecmp_pushed = true;
    } else {
      npc_error("%s: mtimecmp (0x%llx) is not ahead of mtime (0x%llx); leaving it alone",
                point->snapshot, (unsigned long long)item.mtimecmp,
                (unsigned long long)item.mtime);
    }
  }

  /* Per case injections: whatever the caller asked for, plus the two blobs
   * that make the image restore itself. */
  npc_inject_t case_injects[NPC_INJECT_MAX + 2];
  size_t case_inject_count = n_injects;
  memcpy(case_injects, injects, n_injects * sizeof *injects);

  uint8_t trampoline[8] = {0};
  uint8_t page[NPC_PAGE_SIZE];
  if (cli->restore_blob != NULL) {
    if (cli->reserved_paddr < snapshot.mem_base ||
        cli->reserved_paddr + NPC_PAGE_SIZE > snapshot.mem_base + snapshot.mem_size) {
      npc_error("%s: reserved page [0x%llx, 0x%llx) does not fit in memory", point->snapshot,
                (unsigned long long)cli->reserved_paddr,
                (unsigned long long)(cli->reserved_paddr + NPC_PAGE_SIZE));
      goto done;
    }
    uint8_t patch_bytes[8];
    if (!npc_snapshot_read_mem(&snapshot, 0, patch_bytes, sizeof patch_bytes)) {
      goto done;
    }
    if (!npc_restore_build(g_restorer, g_restorer_len, cli->reserved_paddr, &item.state,
                           (uint32_t)snapshot.mem_base, item.mtime, item.mtimecmp, patch_bytes,
                           trampoline, page)) {
      goto done;
    }
    case_injects[case_inject_count++] =
        (npc_inject_t){snapshot.mem_base, sizeof trampoline, trampoline};
    case_injects[case_inject_count++] =
        (npc_inject_t){cli->reserved_paddr, NPC_PAGE_SIZE, page};
  }

  if (!cli->to_stdout) {
    if (!npc_ensure_dir(cli->out_dir)) {
      goto done;
    }
    snprintf(image_path, sizeof image_path, "%s/%s.img%s", cli->out_dir, base,
             cli->compress ? ".zst" : "");
    snprintf(temp_path, sizeof temp_path, "%s.tmp", image_path);
    snprintf(json_path, sizeof json_path, "%s/%s.json", cli->out_dir, base);
  } else {
    snprintf(json_path, sizeof json_path, "%s", cli->json_path);
  }

  if (cli->reserve_check) {
    if (cli->reserve_paddr < snapshot.mem_base ||
        cli->reserve_paddr + cli->reserve_size > snapshot.mem_base + snapshot.mem_size) {
      npc_error("%s: reserve range [0x%llx, 0x%llx) is outside the snapshot's memory", point->snapshot,
                (unsigned long long)cli->reserve_paddr,
                (unsigned long long)(cli->reserve_paddr + cli->reserve_size));
      goto done;
    }
    if (!npc_snapshot_range_is_zero(&snapshot, cli->reserve_paddr - snapshot.mem_base,
                                    cli->reserve_size)) {
      npc_error("%s: reserve range [0x%llx, 0x%llx) is not zero in the snapshot; the guest has "
                "used it, so the device tree reservation is not in effect",
                point->snapshot, (unsigned long long)cli->reserve_paddr,
                (unsigned long long)(cli->reserve_paddr + cli->reserve_size));
      goto done;
    }
  }

  for (size_t i = 0; i < case_inject_count; i++) {
    if (case_injects[i].paddr < snapshot.mem_base ||
        case_injects[i].paddr + case_injects[i].len > snapshot.mem_base + snapshot.mem_size) {
      npc_error("%s: inject at 0x%llx (%llu bytes) does not fit in memory [0x%llx, 0x%llx)",
                point->snapshot, (unsigned long long)case_injects[i].paddr,
                (unsigned long long)case_injects[i].len,
                (unsigned long long)snapshot.mem_base,
                (unsigned long long)(snapshot.mem_base + snapshot.mem_size));
      goto done;
    }
  }

  if (!npc_scan_memory(&snapshot, &item.mem_stats)) {
    goto done;
  }

  uint64_t top = item.mem_stats.top_nonzero;
  for (size_t i = 0; i < case_inject_count; i++) {
    uint64_t end = case_injects[i].paddr + case_injects[i].len - snapshot.mem_base;
    if (end > top) {
      top = end;
    }
  }
  uint64_t image_len = cli->trim ? align_up(top, NPC_CHUNK_SIZE) : snapshot.mem_size;
  if (image_len == 0) {
    image_len = NPC_CHUNK_SIZE;
  }
  if (image_len > snapshot.mem_size) {
    npc_error("%s: image length 0x%llx exceeds the snapshot's memory 0x%llx", point->snapshot,
              (unsigned long long)image_len, (unsigned long long)snapshot.mem_size);
    goto done;
  }

  if (cli->to_stdout) {
    ok = npc_sink_open_stream(stdout, &sink);
  } else if (cli->compress) {
    ok = npc_sink_open_zstd(temp_path, NPC_ZSTD_LEVEL, image_len, &sink);
  } else {
    ok = npc_sink_open_sparse(temp_path, image_len, &sink);
  }
  if (!ok) {
    goto done;
  }

  ok = npc_emit_image(&snapshot, case_injects, case_inject_count, image_len, &sink,
                      &item.mem_stats);
  npc_sink_close(&sink);
  if (!ok) {
    if (!cli->to_stdout) {
      unlink(temp_path);
    }
    goto done;
  }

  if (!cli->to_stdout && rename(temp_path, image_path) != 0) {
    npc_error("cannot move %s to %s: %s", temp_path, image_path, strerror(errno));
    unlink(temp_path);
    ok = false;
    goto done;
  }

  item.index = point->index;
  item.label = point->label;
  item.image = cli->to_stdout ? "-" : image_path;
  item.snap_inst = point->inst;
  item.window_inst = index + 1 < count ? points[index + 1].inst - point->inst : 0;
  item.trimmed = image_len < snapshot.mem_size;
  item.injected = case_inject_count > 0;
  item.image_len = image_len;
  item.out_size = item.mem_stats.written_bytes;
  item.mem_hash = item.mem_stats.hash;

  if (index + 1 < count) {
    if (!read_expected(&points[index + 1], &item.expected)) {
      goto done;
    }
  }

  if (!npc_case_write_json(json_path, &item)) {
    ok = false;
    goto done;
  }
  if (!cli->to_stdout) {
    char index_path[NPC_PATH_MAX * 2];
    snprintf(index_path, sizeof index_path, "%s/index.tsv", cli->out_dir);
    if (!npc_index_append(index_path, &item, json_path)) {
      ok = false;
      goto done;
    }
  }

  if (cli->delete_source) {
    unlink(point->snapshot);
  }

  *total_out += item.out_size;
  if (cli->report) {
    npc_case_print_report(&item);
  }
  ok = true;

done:
  npc_snapshot_close(&snapshot);
  return ok;
}

int main(int argc, char **argv) {
  cli_t cli = {.trim = true};
  if (!parse_cli(argc, argv, &cli)) {
    return 1;
  }

  npc_point_t *points = NULL;
  size_t count = 0;
  if (!npc_points_load(cli.manifest, &points, &count)) {
    return 1;
  }

  npc_inject_t injects[NPC_INJECT_MAX] = {0};
  uint8_t *inject_buffers[NPC_INJECT_MAX] = {0};
  if (!load_injects(&cli, injects, inject_buffers)) {
    free_injects(&cli, inject_buffers);
    npc_points_free(points);
    return 1;
  }

  uint8_t *restorer = NULL;
  size_t restorer_len = 0;
  if (cli.restore_blob != NULL && !load_file(cli.restore_blob, &restorer, &restorer_len)) {
    free_injects(&cli, inject_buffers);
    npc_points_free(points);
    return 1;
  }
  g_restorer = restorer;
  g_restorer_len = restorer_len;

  if (cli.report) {
    npc_report_header();
  }

  bool ok = true;
  size_t processed = 0;
  uint64_t total_out = 0;
  for (size_t i = 0; i < count && ok; i++) {
    if (!case_selected(&cli, &points[i])) {
      continue;
    }
    ok = process_case(&cli, points, count, i, injects, cli.n_inject_specs, &total_out);
    processed++;
    if (cli.to_stdout) {
      break;
    }
  }

  if (ok && processed == 0) {
    npc_error("no case matched '%s'", cli.case_selector != NULL ? cli.case_selector : "");
    ok = false;
  }
  if (ok && cli.report) {
    fprintf(stderr, "%zu case(s), %llu bytes written\n", processed,
            (unsigned long long)total_out);
  }

  free(restorer);
  free_injects(&cli, inject_buffers);
  npc_points_free(points);
  return ok ? 0 : 1;
}
