#include "pack_restore.h"

#include <stddef.h>
#include <string.h>

#include "pack_log.h"

/* The state table lives in the guest's memory and is read by RISC-V code, so
 * it is little endian. So is every host this runs on; say so out loud. */
_Static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__, "pack assumes a little endian host");

/* Guards for the offsets restorer.S hardcodes. */
_Static_assert(offsetof(npc_state_table_t, magic) == 0x00, "table layout changed");
_Static_assert(offsetof(npc_state_table_t, patch_addr) == 0x08, "table layout changed");
_Static_assert(offsetof(npc_state_table_t, resume_pc) == 0x0c, "table layout changed");
_Static_assert(offsetof(npc_state_table_t, flags) == 0x14, "table layout changed");
_Static_assert(offsetof(npc_state_table_t, csr) == 0x18, "table layout changed");
_Static_assert(offsetof(npc_state_table_t, gpr) == 0x60, "table layout changed");
_Static_assert(offsetof(npc_state_table_t, mtime) == 0xe0, "table layout changed");
_Static_assert(offsetof(npc_state_table_t, mtimecmp) == 0xe8, "table layout changed");
_Static_assert(sizeof(npc_state_table_t) == 0xf0, "table layout changed");

/* NEMU's privilege encoding, from the same header pack_snapshot.c uses. */
enum { NPC_PRIV_S = 0, NPC_PRIV_M = 1, NPC_PRIV_U = 2 };

#define MSTATUS_MPP_SHIFT 11
#define MSTATUS_MPP_MASK (3u << MSTATUS_MPP_SHIFT)
#define MSTATUS_MPIE (1u << 7)
#define MSTATUS_MIE (1u << 3)
#define MSTATUS_MPRV (1u << 17)

static uint32_t mpp_for_priv(uint32_t priv) {
  switch (priv) {
    case NPC_PRIV_M:
      return 3u << MSTATUS_MPP_SHIFT;
    case NPC_PRIV_S:
      return 1u << MSTATUS_MPP_SHIFT;
    default:
      return 0;
  }
}

/*
 * Prepares mstatus so that the restorer's closing mret lands exactly on the
 * checkpoint's privilege with its interrupt enable state intact, and so that
 * the restorer's own loads are not translated halfway through.
 *
 *   MPP  <- the checkpoint's privilege   (where mret has to land)
 *   MPIE <- the checkpoint's MIE         (mret copies MPIE back into MIE)
 *   MIE  <- 0                            (overwritten by mret anyway)
 *   MPRV <- 0                            (restored after the loads if it was set)
 */
static uint32_t prepare_mstatus(uint32_t mstatus, uint32_t priv, uint32_t *flags) {
  uint32_t prepared = mstatus & ~(MSTATUS_MPP_MASK | MSTATUS_MPIE | MSTATUS_MIE | MSTATUS_MPRV);
  prepared |= mpp_for_priv(priv);
  if (mstatus & MSTATUS_MIE) {
    prepared |= MSTATUS_MPIE;
  }
  if (mstatus & MSTATUS_MPRV) {
    *flags |= NPC_TABLE_FLAG_MPRV;
  }
  return prepared;
}

static void store_trampoline(uint64_t target, uint8_t out[8]) {
  /* lui t0, hi ; jalr x0, lo(t0) */
  uint32_t hi = (uint32_t)((target + 0x800u) >> 12);
  int32_t lo = (int32_t)(target - ((uint64_t)hi << 12));
  uint32_t first = 0x000002b7u | (hi << 12);
  uint32_t second = 0x00028067u | (((uint32_t)lo & 0xfffu) << 20);
  memcpy(out + 0, &first, 4);
  memcpy(out + 4, &second, 4);
}

bool npc_restore_build(const uint8_t *restorer, size_t restorer_len, uint64_t reserved_paddr,
                       const npc_arch_state_t *state, uint32_t patch_addr, uint64_t mtime,
                       uint64_t mtimecmp, const uint8_t patch_bytes[8], uint8_t trampoline[8],
                       uint8_t page[NPC_PAGE_SIZE]) {
  if (restorer_len == 0 || restorer_len > NPC_PAGE_OFF_PATCH) {
    npc_error("restorer is %zu bytes; it must fit below the displaced bytes at 0x%x", restorer_len,
              NPC_PAGE_OFF_PATCH);
    return false;
  }
  if (reserved_paddr % NPC_PAGE_SIZE != 0) {
    npc_error("reserved page 0x%llx is not page aligned", (unsigned long long)reserved_paddr);
    return false;
  }

  memset(page, 0, NPC_PAGE_SIZE);
  memcpy(page + NPC_PAGE_OFF_CODE, restorer, restorer_len);
  memcpy(page + NPC_PAGE_OFF_PATCH, patch_bytes, 8);

  npc_state_table_t table = {0};
  table.magic = NPC_TABLE_MAGIC;
  table.version = NPC_TABLE_VERSION;
  table.patch_addr = patch_addr;
  table.resume_pc = state->pc;
  table.priv = state->priv;
  table.flags = 0;
  memcpy(table.gpr, state->gpr, sizeof table.gpr);
  memcpy(table.csr, state->csr, sizeof table.csr);
  table.mtime = mtime;
  table.mtimecmp = mtimecmp;

  for (unsigned i = 0; i < NPC_CSR_COUNT; i++) {
    if (i == NPC_CSR_IDX_mstatus) {
      table.csr[i] = prepare_mstatus(state->csr[i], state->priv, &table.flags);
    }
  }

  memcpy(page + NPC_PAGE_OFF_TABLE, &table, sizeof table);
  store_trampoline(reserved_paddr, trampoline);
  return true;
}
