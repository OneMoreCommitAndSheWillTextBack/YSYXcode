#ifndef NPC_PACK_RESTORE_H
#define NPC_PACK_RESTORE_H

#include <stdbool.h>
#include <stdint.h>

#include "npc_csr_list.h"
#include "pack_snapshot.h"

/*
 * The reserved page and the state table it carries. The table layout is the
 * contract between this packer and restorer/restorer.S: the program reads it
 * at these offsets, so any change here has to be mirrored there (the static
 * asserts in pack_restore.c guard the C side, and the restorer checks the
 * magic before it touches anything).
 *
 * Note for whoever compares a window's end state against the next checkpoint:
 * the restore deliberately perturbs three things to perform its mret, so they
 * must not take part in the comparison. mepc becomes resume_pc, and
 * mstatus.MPP / MPIE / MIE are rewritten so that mret lands on the right
 * privilege with the right interrupt enable state.
 */
#define NPC_PAGE_SIZE 4096u
#define NPC_PAGE_OFF_CODE 0x000u
#define NPC_PAGE_OFF_PATCH 0x7f8u
#define NPC_PAGE_OFF_TABLE 0x800u

#define NPC_TABLE_MAGIC 0x5243504eu /* 'N','P','C','R' */
#define NPC_TABLE_VERSION 1u

/* flags */
#define NPC_TABLE_FLAG_MPRV 0x1u /* the checkpoint had mstatus.MPRV set */

typedef struct {
  uint32_t magic;
  uint32_t version;
  uint32_t patch_addr; /* where the displaced 8 bytes go back */
  uint32_t resume_pc;
  uint32_t priv;
  uint32_t flags;
  uint32_t csr[NPC_CSR_COUNT];
  uint32_t gpr[32];
  uint64_t mtime;
  uint64_t mtimecmp;
} npc_state_table_t;

/*
 * Builds the two blobs that turn an ordinary image into a self restoring one:
 * an 8-byte trampoline that goes at the memory base, and the reserved page that
 * holds the restorer, the displaced bytes and the state table.
 *
 * `restorer` is the raw binary built by restorer/Makefile; `patch_bytes` are
 * the 8 bytes currently sitting at `patch_addr` in the snapshot.
 */
bool npc_restore_build(const uint8_t *restorer, size_t restorer_len, uint64_t reserved_paddr,
                       const npc_arch_state_t *state, uint32_t patch_addr, uint64_t mtime,
                       uint64_t mtimecmp, const uint8_t patch_bytes[8], uint8_t trampoline[8],
                       uint8_t page[NPC_PAGE_SIZE]);

#endif
