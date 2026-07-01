#ifndef NPC_DPI_H
#define NPC_DPI_H

extern "C" void npc_commit(int valid, int finish, int pc, int inst);
extern "C" void npc_get_current_pc(int pc);
extern "C" void npc_pmem_read(int addr, int len, int *data);
extern "C" void npc_pmem_write(int addr, int len, int data);

#endif
