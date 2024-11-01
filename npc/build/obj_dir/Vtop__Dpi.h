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
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/infetch.v:1:29
    extern int get_inst(int pc);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/mem.v:2:29
    extern int guest_read(int addr);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/mem.v:1:30
    extern void guest_write(int addr, int data);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/pc/pcreg.v:1:30
    extern void host_get_pc(int pc);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/reg/registers.v:1:30
    extern void host_get_reg(svLogicVecVal* data);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/control/maincontrol.v:1:30
    extern void ret();

#ifdef __cplusplus
}
#endif

#endif  // guard
