#ifndef NPC_DPI_H
#define NPC_DPI_H

extern "C" void npc_commit_group(int valid_mask, int finish_mask, int pc0,
                                 int inst0, int pc1, int inst1);
extern "C" void npc_pmem_read(int addr, int len, int *data);
extern "C" void npc_pmem_write(int addr, int len, int data);

#endif
