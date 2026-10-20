#include "pack_meta.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "pack_log.h"

bool npc_ensure_dir(const char *path) {
  char buffer[NPC_PATH_MAX * 2];
  if (snprintf(buffer, sizeof buffer, "%s", path) >= (int)sizeof buffer) {
    npc_error("output directory path is too long");
    return false;
  }
  for (char *cursor = buffer + 1; *cursor != '\0'; cursor++) {
    if (*cursor != '/') {
      continue;
    }
    *cursor = '\0';
    if (mkdir(buffer, 0777) != 0 && errno != EEXIST) {
      npc_error("cannot create %s: %s", buffer, strerror(errno));
      return false;
    }
    *cursor = '/';
  }
  if (mkdir(buffer, 0777) != 0 && errno != EEXIST) {
    npc_error("cannot create %s: %s", buffer, strerror(errno));
    return false;
  }
  return true;
}

static const char *const npc_csr_names[NPC_CSR_COUNT] = {
#define NPC_CSR_NAME(name) #name,
    NPC_CSR_LIST(NPC_CSR_NAME)
#undef NPC_CSR_NAME
};

static void write_state(FILE *fp, const npc_arch_state_t *state, const char *indent) {
  fprintf(fp, "%s\"pc\": \"0x%08x\",\n", indent, state->pc);
  fprintf(fp, "%s\"priv\": \"%s\",\n", indent, npc_priv_name(state->priv));
  fprintf(fp, "%s\"gpr\": [", indent);
  for (unsigned i = 0; i < 32; i++) {
    fprintf(fp, "\"0x%08x\"%s", state->gpr[i], i + 1 < 32 ? ", " : "");
  }
  fprintf(fp, "],\n");
  fprintf(fp, "%s\"csr\": {\n", indent);
  for (unsigned i = 0; i < NPC_CSR_COUNT; i++) {
    fprintf(fp, "%s  \"%s\": \"0x%08x\"%s\n", indent, npc_csr_names[i], state->csr[i],
            i + 1 < NPC_CSR_COUNT ? "," : "");
  }
  fprintf(fp, "%s}\n", indent);
}

bool npc_case_write_json(const char *path, const npc_case_t *item) {
  FILE *fp = fopen(path, "w");
  if (fp == NULL) {
    npc_error("cannot create %s: %s", path, strerror(errno));
    return false;
  }

  fprintf(fp, "{\n");
  fprintf(fp, "  \"index\": %u,\n", item->index);
  fprintf(fp, "  \"label\": \"%s\",\n", item->label);
  fprintf(fp, "  \"image\": \"%s\",\n", item->image);
  fprintf(fp, "  \"resume_pc\": \"0x%08x\",\n", item->state.pc);
  fprintf(fp, "  \"priv\": \"%s\",\n", npc_priv_name(item->state.priv));
  fprintf(fp, "  \"snap_inst\": %llu,\n", (unsigned long long)item->snap_inst);
  fprintf(fp, "  \"window_inst\": %llu,\n", (unsigned long long)item->window_inst);
  fprintf(fp, "  \"mtime\": %llu,\n", (unsigned long long)item->mtime);
  fprintf(fp, "  \"mtimecmp\": %llu,\n", (unsigned long long)item->mtimecmp);
  fprintf(fp, "  \"flags\": { \"trimmed\": %s, \"injected\": %s, \"mtimecmp_pushed\": %s },\n",
          item->trimmed ? "true" : "false", item->injected ? "true" : "false",
          item->mtimecmp_pushed ? "true" : "false");
  fprintf(fp, "  \"image_len\": %llu,\n", (unsigned long long)item->image_len);
  fprintf(fp, "  \"out_size\": %llu,\n", (unsigned long long)item->out_size);
  fprintf(fp, "  \"mem_hash_kind\": \"npc64\",\n");
  fprintf(fp, "  \"mem_hash\": \"0x%016llx\",\n", (unsigned long long)item->mem_hash);
  fprintf(fp, "  \"expected\": {\n");
  fprintf(fp, "    \"valid\": %s,\n", item->expected.has_expected ? "true" : "false");
  if (item->expected.has_expected) {
    write_state(fp, &item->expected.state, "    ");
  } else {
    fprintf(fp, "    \"pc\": \"0x00000000\",\n");
    fprintf(fp, "    \"priv\": \"?\",\n");
    fprintf(fp, "    \"gpr\": [],\n");
    fprintf(fp, "    \"csr\": {}\n");
  }
  fprintf(fp, "  }\n");
  fprintf(fp, "}\n");

  bool ok = fclose(fp) == 0;
  if (!ok) {
    npc_error("cannot finish %s: %s", path, strerror(errno));
  }
  return ok;
}

bool npc_index_append(const char *path, const npc_case_t *item, const char *json_path) {
  bool fresh = access(path, F_OK) != 0;
  FILE *fp = fopen(path, "a");
  if (fp == NULL) {
    npc_error("cannot append to %s: %s", path, strerror(errno));
    return false;
  }
  if (fresh) {
    fprintf(fp, "# index\tlabel\tjson\timage\twindow_inst\texpected_valid\n");
  }
  fprintf(fp, "%u\t%s\t%s\t%s\t%llu\t%s\n", item->index, item->label, json_path, item->image,
          (unsigned long long)item->window_inst, item->expected.has_expected ? "1" : "0");
  bool ok = fclose(fp) == 0;
  if (!ok) {
    npc_error("cannot finish %s: %s", path, strerror(errno));
  }
  return ok;
}

void npc_report_header(void) {
  fprintf(stderr,
          "%-4s %-20s %-4s %-10s %-10s %-9s %-11s %-9s %-9s %s\n", "case", "label", "priv",
          "resume", "window", "mem", "top", "image", "output", "ratio");
}

static void human(uint64_t bytes, char *out, size_t out_size) {
  const char *units[] = {"B", "KiB", "MiB", "GiB"};
  double value = (double)bytes;
  unsigned unit = 0;
  while (value >= 1024.0 && unit + 1 < sizeof units / sizeof units[0]) {
    value /= 1024.0;
    unit++;
  }
  snprintf(out, out_size, "%.1f%s", value, units[unit]);
}

void npc_case_print_report(const npc_case_t *item) {
  char mem_text[32];
  char top_text[32];
  char image_text[32];
  char out_text[32];
  human(item->mem_stats.nonzero_bytes, mem_text, sizeof mem_text);
  snprintf(top_text, sizeof top_text, "0x%llx", (unsigned long long)item->mem_stats.top_nonzero);
  human(item->image_len, image_text, sizeof image_text);
  human(item->out_size, out_text, sizeof out_text);
  double ratio = item->out_size > 0 ? (double)item->image_len / (double)item->out_size : 1.0;
  fprintf(stderr, "%-4u %-20s %-4s 0x%08x %-10llu %-9s %-11s %-9s %-9s %.2fx\n", item->index,
          item->label, npc_priv_name(item->state.priv), item->state.pc,
          (unsigned long long)item->window_inst, mem_text, top_text, image_text, out_text, ratio);
}
