// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYXSOCFULL__DPI_H_
#define VERILATED_VYSYXSOCFULL__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/ysyx/project/ysyx-workbench/ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/reg/ysyx_24100007_registers.v:2:30
    extern void host_get_csr(int csrval, int csrnum);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/ysyx_24100007.v:2:30
    extern void host_get_inst(int inst);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/ysyx_24100007.v:1:30
    extern void host_get_pc(int pc);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/reg/ysyx_24100007_registers.v:1:30
    extern void host_get_reg(int regval, int regnum);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/wbu/ysyx_24100007_wbu.v:1:30
    extern void host_get_skip(int addr);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/ifu/ysyx_24100007_ifu.v:1:30
    extern void host_get_valid(int valid);
    // DPI import at /home/ysyx/project/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v:4648:30
    extern void mrom_read(int raddr, int* rdata);
    // DPI import at /home/ysyx/project/ysyx-workbench/ysyxSoC/perip/psram/psram.v:153:32
    extern char psram_read(int addr);
    // DPI import at /home/ysyx/project/ysyx-workbench/ysyxSoC/perip/psram/psram.v:152:32
    extern void psram_write(int addr, char data);
    // DPI import at /home/ysyx/project/ysyx-workbench/npc/vsrc/idu/ysyx_24100007_maincontrol.v:1:30
    extern void ret(int pc);

#ifdef __cplusplus
}
#endif

#endif  // guard
