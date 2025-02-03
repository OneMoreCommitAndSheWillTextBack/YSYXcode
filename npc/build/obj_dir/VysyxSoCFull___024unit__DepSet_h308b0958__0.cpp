// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull___024unit.h"

extern "C" void host_get_reg(int regval, int regnum);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(IData/*31:0*/ regval, IData/*31:0*/ regnum) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_host_get_reg_TOP____024unit\n"); );
    // Body
    int regval__Vcvt;
    for (size_t regval__Vidx = 0; regval__Vidx < 1; ++regval__Vidx) regval__Vcvt = regval;
    int regnum__Vcvt;
    for (size_t regnum__Vidx = 0; regnum__Vidx < 1; ++regnum__Vidx) regnum__Vcvt = regnum;
    host_get_reg(regval__Vcvt, regnum__Vcvt);
}

extern "C" void host_get_csr(int csrval, int csrnum);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_host_get_csr_TOP____024unit(IData/*31:0*/ csrval, IData/*31:0*/ csrnum) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_host_get_csr_TOP____024unit\n"); );
    // Body
    int csrval__Vcvt;
    for (size_t csrval__Vidx = 0; csrval__Vidx < 1; ++csrval__Vidx) csrval__Vcvt = csrval;
    int csrnum__Vcvt;
    for (size_t csrnum__Vidx = 0; csrnum__Vidx < 1; ++csrnum__Vidx) csrnum__Vcvt = csrnum;
    host_get_csr(csrval__Vcvt, csrnum__Vcvt);
}

extern "C" void host_get_pc(int pc);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_host_get_pc_TOP____024unit\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    host_get_pc(pc__Vcvt);
}

extern "C" void host_get_inst(int inst);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_host_get_inst_TOP____024unit(IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_host_get_inst_TOP____024unit\n"); );
    // Body
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    host_get_inst(inst__Vcvt);
}

extern "C" void host_get_valid(int valid);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_host_get_valid_TOP____024unit(IData/*31:0*/ valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_host_get_valid_TOP____024unit\n"); );
    // Body
    int valid__Vcvt;
    for (size_t valid__Vidx = 0; valid__Vidx < 1; ++valid__Vidx) valid__Vcvt = valid;
    host_get_valid(valid__Vcvt);
}

extern "C" void ret(int pc);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_ret_TOP____024unit(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_ret_TOP____024unit\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    ret(pc__Vcvt);
}

extern "C" void flash_read(int addr, int* data);

VL_INLINE_OPT void VysyxSoCFull___024unit____Vdpiimwrap_flash_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VysyxSoCFull___024unit____Vdpiimwrap_flash_read_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int data__Vcvt;
    flash_read(addr__Vcvt, &data__Vcvt);
    data = data__Vcvt;
}
