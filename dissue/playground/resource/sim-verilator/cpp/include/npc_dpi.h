#ifndef NPC_DPI_H
#define NPC_DPI_H

#include "svdpi.h"
#include <cstdint>

extern "C" void npc_difftest_commit(int valid_mask, int finish_mask,
                                    int mem_valid_mask, int mem_write_mask,
                                    int pc0, int inst0, int raw_inst0,
                                    int inst_len0, int next_pc0, int mem_addr0,
                                    int mem_size0, int pc1, int inst1,
                                    int raw_inst1, int inst_len1, int next_pc1,
                                    int mem_addr1, int mem_size1,
                                    int async_intr_valid, int async_intr_cause,
                                    int async_intr_epc);
extern "C" void npc_difftest_context(int valid, int pc, int priv,
                                     const svBitVecVal *csr,
                                     const svBitVecVal *gpr);
extern "C" void npc_pmem_read(int addr, int len, int *data);
extern "C" void npc_pmem_write(int addr, int len, int data);
extern "C" uint64_t npc_time_read();
extern "C" void npc_cache_hit(char hit);
extern "C" void npc_issue_queue_perf(int issue_count, int occupancy,
                                     char block_ready, char block_operand);
extern "C" void npc_div_perf(int cycles, char special);
extern "C" void npc_bpu_perf(char correct);
extern "C" void npc_mem_perf(int events, int mshr_occupancy,
                              int store_queue_occupancy,
                              int load_txn_occupancy);
#endif
