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
extern "C" void npc_frontend_perf(int events, int stall_events,
                                  char ifu_correction,
                                  int fetch_queue_occupancy,
                                  int fetch_queue_enqueue_width,
                                  int fetch_queue_dequeue_width,
                                  char icache_lookup_valid,
                                  int icache_block_valid_mask,
                                  int icache_miss_mask, int icache_block_addr0,
                                  int icache_block_addr1);
extern "C" void npc_issue_queue_perf(int issue_count, int occupancy,
                                     char block_ready, char block_operand);
extern "C" void npc_div_perf(int cycles, char special);
extern "C" void npc_bpu_perf(int cfi_class, char pred_hit, char pred_taken,
                              char actual_taken, char correct);
extern "C" void npc_mem_perf(int events, int mshr_occupancy,
                              int store_queue_occupancy,
                              int load_txn_occupancy);
extern "C" void npc_pipeline_trace(int kind, int flags, int slot, int rob_idx,
                                    int producer0, int producer1, int pc,
                                    int inst, int raw_inst, int sequence,
                                    int epoch, int resource, int txn_id);
#endif
