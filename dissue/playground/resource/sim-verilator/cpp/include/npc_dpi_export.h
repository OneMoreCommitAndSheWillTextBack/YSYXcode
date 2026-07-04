#ifndef NPC_DPI_EXPORT_H
#define NPC_DPI_EXPORT_H

#include <stdint.h>

#if defined(__GNUC__) || defined(__clang__)
#define NPC_WEAK_DPI_EXPORT __attribute__((weak))
#else
#define NPC_WEAK_DPI_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

uint8_t npc_dpi_context_valid(void) NPC_WEAK_DPI_EXPORT;
uint32_t npc_dpi_get_pc(void) NPC_WEAK_DPI_EXPORT;
uint32_t npc_dpi_get_priv(void) NPC_WEAK_DPI_EXPORT;
uint32_t npc_dpi_get_gpr(uint32_t idx) NPC_WEAK_DPI_EXPORT;
uint32_t npc_dpi_get_csr(uint32_t addr) NPC_WEAK_DPI_EXPORT;

#ifdef __cplusplus
}
#endif

#endif
