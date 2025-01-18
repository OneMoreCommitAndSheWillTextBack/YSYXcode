// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/data/sram.v:2:29
    extern int guest_read(int addr, int len);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/data/sram.v:1:30
    extern void guest_write(int addr, int data, int len);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/reg/registers.v:2:30
    extern void host_get_csr(int csrval, int csrnum);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/top.v:2:30
    extern void host_get_inst(int inst);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/top.v:1:30
    extern void host_get_pc(int pc);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/reg/registers.v:1:30
    extern void host_get_reg(int regval, int regnum);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/wbu/wbu.v:1:30
    extern void host_get_valid(int valid);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/idu/maincontrol.v:1:30
    extern void ret(int pc);

#ifdef __cplusplus
}
#endif

#endif  // guard
