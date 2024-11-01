// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024unit.h"

extern "C" void host_get_reg(svLogicVecVal* data);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(VlUnpacked<IData/*31:0*/, 32> &data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit\n"); );
    // Body
    svLogicVecVal data__Vcvt[32];
    host_get_reg(data__Vcvt);
    data[0U] = VL_SET_I_SVLV(&data__Vcvt[0]);
    data[1U] = VL_SET_I_SVLV(&data__Vcvt[1]);
    data[2U] = VL_SET_I_SVLV(&data__Vcvt[2]);
    data[3U] = VL_SET_I_SVLV(&data__Vcvt[3]);
    data[4U] = VL_SET_I_SVLV(&data__Vcvt[4]);
    data[5U] = VL_SET_I_SVLV(&data__Vcvt[5]);
    data[6U] = VL_SET_I_SVLV(&data__Vcvt[6]);
    data[7U] = VL_SET_I_SVLV(&data__Vcvt[7]);
    data[8U] = VL_SET_I_SVLV(&data__Vcvt[8]);
    data[9U] = VL_SET_I_SVLV(&data__Vcvt[9]);
    data[0xaU] = VL_SET_I_SVLV(&data__Vcvt[10]);
    data[0xbU] = VL_SET_I_SVLV(&data__Vcvt[11]);
    data[0xcU] = VL_SET_I_SVLV(&data__Vcvt[12]);
    data[0xdU] = VL_SET_I_SVLV(&data__Vcvt[13]);
    data[0xeU] = VL_SET_I_SVLV(&data__Vcvt[14]);
    data[0xfU] = VL_SET_I_SVLV(&data__Vcvt[15]);
    data[0x10U] = VL_SET_I_SVLV(&data__Vcvt[16]);
    data[0x11U] = VL_SET_I_SVLV(&data__Vcvt[17]);
    data[0x12U] = VL_SET_I_SVLV(&data__Vcvt[18]);
    data[0x13U] = VL_SET_I_SVLV(&data__Vcvt[19]);
    data[0x14U] = VL_SET_I_SVLV(&data__Vcvt[20]);
    data[0x15U] = VL_SET_I_SVLV(&data__Vcvt[21]);
    data[0x16U] = VL_SET_I_SVLV(&data__Vcvt[22]);
    data[0x17U] = VL_SET_I_SVLV(&data__Vcvt[23]);
    data[0x18U] = VL_SET_I_SVLV(&data__Vcvt[24]);
    data[0x19U] = VL_SET_I_SVLV(&data__Vcvt[25]);
    data[0x1aU] = VL_SET_I_SVLV(&data__Vcvt[26]);
    data[0x1bU] = VL_SET_I_SVLV(&data__Vcvt[27]);
    data[0x1cU] = VL_SET_I_SVLV(&data__Vcvt[28]);
    data[0x1dU] = VL_SET_I_SVLV(&data__Vcvt[29]);
    data[0x1eU] = VL_SET_I_SVLV(&data__Vcvt[30]);
    data[0x1fU] = VL_SET_I_SVLV(&data__Vcvt[31]);
}

extern "C" void host_get_pc(int pc);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    host_get_pc(pc__Vcvt);
}

extern "C" int get_inst(int pc);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ &get_inst__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int get_inst__Vfuncrtn__Vcvt;
    get_inst__Vfuncrtn__Vcvt = get_inst(pc__Vcvt);
    get_inst__Vfuncrtn = get_inst__Vfuncrtn__Vcvt;
}

extern "C" void ret();

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_ret_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_ret_TOP____024unit\n"); );
    // Body
    ret();
}

extern "C" void guest_write(int addr, int data);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_guest_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_guest_write_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int data__Vcvt;
    for (size_t data__Vidx = 0; data__Vidx < 1; ++data__Vidx) data__Vcvt = data;
    guest_write(addr__Vcvt, data__Vcvt);
}

extern "C" int guest_read(int addr);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_guest_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &guest_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_guest_read_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int guest_read__Vfuncrtn__Vcvt;
    guest_read__Vfuncrtn__Vcvt = guest_read(addr__Vcvt);
    guest_read__Vfuncrtn = guest_read__Vfuncrtn__Vcvt;
}
