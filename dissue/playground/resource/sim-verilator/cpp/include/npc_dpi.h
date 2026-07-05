#ifndef NPC_DPI_H
#define NPC_DPI_H

#include "svdpi.h"

extern "C" void npc_difftest_commit(int valid_mask, int finish_mask, int pc0,
                                    int inst0, int pc1, int inst1);
extern "C" void npc_difftest_context(int valid, int pc, int priv,
                                     const svBitVecVal *csr,
                                     const svBitVecVal *gpr);
extern "C" void npc_pmem_read(int addr, int len, int *data);
extern "C" void npc_pmem_write(int addr, int len, int data);
extern "C" void npc_cache_hit(char hit);
extern "C" void npc_issue_queue_perf(int issue_count, int occupancy,
                                     char block_ready, char block_operand);
#endif
