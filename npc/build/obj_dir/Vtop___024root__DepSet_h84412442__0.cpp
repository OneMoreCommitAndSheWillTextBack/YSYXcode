// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_h6b552b7a__0;
    __Vtrigcurrexpr_h6b552b7a__0 = 0;
    __Vtrigcurrexpr_h6b552b7a__0 = ((IData)(vlSelf->top__DOT__decoder0__DOT__type_S) 
                                    | (IData)(vlSelf->top__DOT__memer));
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(1U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->rst) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__rst))));
    vlSelf->__VactTriggered.at(2U) = ((IData)(__Vtrigcurrexpr_h6b552b7a__0) 
                                      != (IData)(vlSelf->__Vtrigprevexpr_h6b552b7a__0));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
    vlSelf->__Vtrigprevexpr_h6b552b7a__0 = __Vtrigcurrexpr_h6b552b7a__0;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(2U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop___024unit____Vdpiimwrap_ret_TOP____024unit();
void Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(IData/*31:0*/ pc);
void Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(VlUnpacked<IData/*31:0*/, 32> &data);
void Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ &get_inst__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    VlUnpacked<IData/*31:0*/, 32> __Vtask_host_get_reg__4__data;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        __Vtask_host_get_reg__4__data[__Vi0] = 0;
    }
    CData/*4:0*/ __Vdlyvdim0__top__DOT__regfile__DOT__registers0__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__regfile__DOT__registers0__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__regfile__DOT__registers0__DOT__rf__v0;
    __Vdlyvval__top__DOT__regfile__DOT__registers0__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT__registers0__DOT__rf__v0;
    __Vdlyvset__top__DOT__regfile__DOT__registers0__DOT__rf__v0 = 0;
    // Body
    if ((vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp 
         == vlSelf->top__DOT__pcbridge)) {
        Vtop___024unit____Vdpiimwrap_ret_TOP____024unit();
    }
    Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(vlSelf->top__DOT__pcbridge);
    __Vdlyvset__top__DOT__regfile__DOT__registers0__DOT__rf__v0 = 0U;
    if (vlSelf->rst) {
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__i = 0x20U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[1U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[2U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[3U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[4U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[5U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[6U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[7U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[8U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[9U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xaU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xbU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xcU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xdU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xeU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xfU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x10U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x11U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x12U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x13U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x14U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x15U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x16U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x17U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x18U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x19U] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1aU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1bU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1cU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1dU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1eU] = 0U;
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1fU] = 0U;
    }
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(__Vtask_host_get_reg__4__data);
    vlSelf->top__DOT__pcbridge = ((IData)(vlSelf->rst)
                                   ? 0x80000000U : vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp);
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1fU] 
        = __Vtask_host_get_reg__4__data[0U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1eU] 
        = __Vtask_host_get_reg__4__data[1U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1dU] 
        = __Vtask_host_get_reg__4__data[2U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1cU] 
        = __Vtask_host_get_reg__4__data[3U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1bU] 
        = __Vtask_host_get_reg__4__data[4U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x1aU] 
        = __Vtask_host_get_reg__4__data[5U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x19U] 
        = __Vtask_host_get_reg__4__data[6U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x18U] 
        = __Vtask_host_get_reg__4__data[7U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x17U] 
        = __Vtask_host_get_reg__4__data[8U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x16U] 
        = __Vtask_host_get_reg__4__data[9U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x15U] 
        = __Vtask_host_get_reg__4__data[0xaU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x14U] 
        = __Vtask_host_get_reg__4__data[0xbU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x13U] 
        = __Vtask_host_get_reg__4__data[0xcU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x12U] 
        = __Vtask_host_get_reg__4__data[0xdU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x11U] 
        = __Vtask_host_get_reg__4__data[0xeU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0x10U] 
        = __Vtask_host_get_reg__4__data[0xfU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xfU] 
        = __Vtask_host_get_reg__4__data[0x10U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xeU] 
        = __Vtask_host_get_reg__4__data[0x11U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xdU] 
        = __Vtask_host_get_reg__4__data[0x12U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xcU] 
        = __Vtask_host_get_reg__4__data[0x13U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xbU] 
        = __Vtask_host_get_reg__4__data[0x14U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0xaU] 
        = __Vtask_host_get_reg__4__data[0x15U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[9U] 
        = __Vtask_host_get_reg__4__data[0x16U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[8U] 
        = __Vtask_host_get_reg__4__data[0x17U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[7U] 
        = __Vtask_host_get_reg__4__data[0x18U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[6U] 
        = __Vtask_host_get_reg__4__data[0x19U];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[5U] 
        = __Vtask_host_get_reg__4__data[0x1aU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[4U] 
        = __Vtask_host_get_reg__4__data[0x1bU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[3U] 
        = __Vtask_host_get_reg__4__data[0x1cU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[2U] 
        = __Vtask_host_get_reg__4__data[0x1dU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[1U] 
        = __Vtask_host_get_reg__4__data[0x1eU];
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0U] 
        = __Vtask_host_get_reg__4__data[0x1fU];
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        if (((IData)(vlSelf->top__DOT__decoder0__DOT__type_I) 
             | ((0x33U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                | ((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                   | (IData)(vlSelf->top__DOT__decoder0__DOT__type_U))))) {
            __Vdlyvval__top__DOT__regfile__DOT__registers0__DOT__rf__v0 
                = vlSelf->top__DOT__regwrite;
            __Vdlyvset__top__DOT__regfile__DOT__registers0__DOT__rf__v0 = 1U;
            __Vdlyvdim0__top__DOT__regfile__DOT__registers0__DOT__rf__v0 
                = (0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                            >> 7U));
        }
    }
    if (__Vdlyvset__top__DOT__regfile__DOT__registers0__DOT__rf__v0) {
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[__Vdlyvdim0__top__DOT__regfile__DOT__registers0__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__regfile__DOT__registers0__DOT__rf__v0;
    }
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x1fU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x1fU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x1eU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x1eU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x1dU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x1dU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x1cU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x1cU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x1bU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x1bU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x1aU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x1aU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x19U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x19U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x18U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x18U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x17U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x17U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x16U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x16U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x15U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x15U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x14U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x14U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x13U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x13U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x12U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x12U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x11U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x11U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0x10U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0x10U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0xfU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0xfU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0xeU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0xeU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0xdU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0xdU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0xcU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0xcU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0xbU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0xbU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0xaU] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0xaU];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[9U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [9U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[8U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [8U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[7U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [7U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[6U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [6U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[5U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [5U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[4U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [4U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[3U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [3U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[2U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [2U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[1U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [1U];
    vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0U] 
        = vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf
        [0U];
    vlSelf->pc_out = vlSelf->top__DOT__pcbridge;
    Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit(vlSelf->top__DOT__pcbridge, vlSelf->__Vfunc_get_inst__2__Vfuncout);
    vlSelf->top__DOT__infetch0__DOT__reg_inst = vlSelf->__Vfunc_get_inst__2__Vfuncout;
    vlSelf->top__DOT__regfile__DOT__rf[0x1fU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x1fU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1eU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x1eU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1dU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x1dU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1cU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x1cU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1bU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x1bU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1aU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x1aU];
    vlSelf->top__DOT__regfile__DOT__rf[0x19U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x19U];
    vlSelf->top__DOT__regfile__DOT__rf[0x18U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x18U];
    vlSelf->top__DOT__regfile__DOT__rf[0x17U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x17U];
    vlSelf->top__DOT__regfile__DOT__rf[0x16U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x16U];
    vlSelf->top__DOT__regfile__DOT__rf[0x15U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x15U];
    vlSelf->top__DOT__regfile__DOT__rf[0x14U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x14U];
    vlSelf->top__DOT__regfile__DOT__rf[0x13U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x13U];
    vlSelf->top__DOT__regfile__DOT__rf[0x12U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x12U];
    vlSelf->top__DOT__regfile__DOT__rf[0x11U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x11U];
    vlSelf->top__DOT__regfile__DOT__rf[0x10U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0x10U];
    vlSelf->top__DOT__regfile__DOT__rf[0xfU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0xfU];
    vlSelf->top__DOT__regfile__DOT__rf[0xeU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0xeU];
    vlSelf->top__DOT__regfile__DOT__rf[0xdU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0xdU];
    vlSelf->top__DOT__regfile__DOT__rf[0xcU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0xcU];
    vlSelf->top__DOT__regfile__DOT__rf[0xbU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0xbU];
    vlSelf->top__DOT__regfile__DOT__rf[0xaU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0xaU];
    vlSelf->top__DOT__regfile__DOT__rf[9U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [9U];
    vlSelf->top__DOT__regfile__DOT__rf[8U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [8U];
    vlSelf->top__DOT__regfile__DOT__rf[7U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [7U];
    vlSelf->top__DOT__regfile__DOT__rf[6U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [6U];
    vlSelf->top__DOT__regfile__DOT__rf[5U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [5U];
    vlSelf->top__DOT__regfile__DOT__rf[4U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [4U];
    vlSelf->top__DOT__regfile__DOT__rf[3U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [3U];
    vlSelf->top__DOT__regfile__DOT__rf[2U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [2U];
    vlSelf->top__DOT__regfile__DOT__rf[1U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [1U];
    vlSelf->top__DOT__regfile__DOT__rf[0U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
        [0U];
    if ((IData)((0x73U == (0x707fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)))) {
        Vtop___024unit____Vdpiimwrap_ret_TOP____024unit();
    }
    vlSelf->inst_out = vlSelf->top__DOT__infetch0__DOT__reg_inst;
    vlSelf->top__DOT__regwritepc = ((0x67U == (0x7fU 
                                               & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                    | ((0x6fU == (0x7fU 
                                                  & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                       | (0x17U == 
                                          (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    vlSelf->top__DOT__decoder0__DOT__I_imm = (((- (IData)(
                                                          (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                 >> 0x14U));
    vlSelf->top__DOT__decoder0__DOT__J_imm = (((- (IData)(
                                                          (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                           >> 0x1fU))) 
                                               << 0x14U) 
                                              | ((0xff000U 
                                                  & vlSelf->top__DOT__infetch0__DOT__reg_inst) 
                                                 | ((0x800U 
                                                     & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                          >> 0x14U)))));
    vlSelf->top__DOT__decoder0__DOT__S_imm = (((- (IData)(
                                                          (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | ((0xfe0U 
                                                  & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                       >> 7U))));
    vlSelf->top__DOT__decoder0__DOT__B_imm = (((- (IData)(
                                                          (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | ((0x800U 
                                                  & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                     << 4U)) 
                                                 | ((0x7e0U 
                                                     & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                        >> 0x14U)) 
                                                    | (0x1eU 
                                                       & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                          >> 7U)))));
    vlSelf->top__DOT__decoder0__DOT__type_U = ((0x37U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                               | (0x17U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst)));
    vlSelf->top__DOT__alu0__DOT__A_s = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                   >> 0xfU))];
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__regfile__DOT__rf[(0x1fU 
                                              & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                 >> 0x14U))];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x1fU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x1fU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x1eU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x1eU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x1dU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x1dU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x1cU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x1cU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x1bU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x1bU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x1aU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x1aU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x19U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x19U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x18U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x18U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x17U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x17U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x16U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x16U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x15U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x15U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x14U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x14U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x13U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x13U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x12U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x12U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x11U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x11U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0x10U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0x10U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0xfU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0xfU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0xeU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0xeU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0xdU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0xdU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0xcU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0xcU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0xbU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0xbU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0xaU] 
        = vlSelf->top__DOT__regfile__DOT__rf[0xaU];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[9U] 
        = vlSelf->top__DOT__regfile__DOT__rf[9U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[8U] 
        = vlSelf->top__DOT__regfile__DOT__rf[8U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[7U] 
        = vlSelf->top__DOT__regfile__DOT__rf[7U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[6U] 
        = vlSelf->top__DOT__regfile__DOT__rf[6U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[5U] 
        = vlSelf->top__DOT__regfile__DOT__rf[5U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[4U] 
        = vlSelf->top__DOT__regfile__DOT__rf[4U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[3U] 
        = vlSelf->top__DOT__regfile__DOT__rf[3U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[2U] 
        = vlSelf->top__DOT__regfile__DOT__rf[2U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[1U] 
        = vlSelf->top__DOT__regfile__DOT__rf[1U];
    vlSelf->top__DOT____Vcellout__regfile__reg_out[0U] 
        = vlSelf->top__DOT__regfile__DOT__rf[0U];
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__regwritepc) 
                                                  == 
                                                  vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                  [0U]);
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit) 
                                                  | ((IData)(vlSelf->top__DOT__regwritepc) 
                                                     == 
                                                     vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                     [1U]));
    vlSelf->reg_out[0x1fU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x1fU];
    vlSelf->reg_out[0x1eU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x1eU];
    vlSelf->reg_out[0x1dU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x1dU];
    vlSelf->reg_out[0x1cU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x1cU];
    vlSelf->reg_out[0x1bU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x1bU];
    vlSelf->reg_out[0x1aU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x1aU];
    vlSelf->reg_out[0x19U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x19U];
    vlSelf->reg_out[0x18U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x18U];
    vlSelf->reg_out[0x17U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x17U];
    vlSelf->reg_out[0x16U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x16U];
    vlSelf->reg_out[0x15U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x15U];
    vlSelf->reg_out[0x14U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x14U];
    vlSelf->reg_out[0x13U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x13U];
    vlSelf->reg_out[0x12U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x12U];
    vlSelf->reg_out[0x11U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x11U];
    vlSelf->reg_out[0x10U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0x10U];
    vlSelf->reg_out[0xfU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0xfU];
    vlSelf->reg_out[0xeU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0xeU];
    vlSelf->reg_out[0xdU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0xdU];
    vlSelf->reg_out[0xcU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0xcU];
    vlSelf->reg_out[0xbU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0xbU];
    vlSelf->reg_out[0xaU] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0xaU];
    vlSelf->reg_out[9U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [9U];
    vlSelf->reg_out[8U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [8U];
    vlSelf->reg_out[7U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [7U];
    vlSelf->reg_out[6U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [6U];
    vlSelf->reg_out[5U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [5U];
    vlSelf->reg_out[4U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [4U];
    vlSelf->reg_out[3U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [3U];
    vlSelf->reg_out[2U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [2U];
    vlSelf->reg_out[1U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [1U];
    vlSelf->reg_out[0U] = vlSelf->top__DOT____Vcellout__regfile__reg_out
        [0U];
}

void Vtop___024unit____Vdpiimwrap_guest_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ data);
void Vtop___024unit____Vdpiimwrap_guest_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &guest_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vfunc_guest_read__6__Vfuncout;
    __Vfunc_guest_read__6__Vfuncout = 0;
    // Body
    if (vlSelf->top__DOT__decoder0__DOT__type_S) {
        Vtop___024unit____Vdpiimwrap_guest_write_TOP____024unit(vlSelf->top__DOT__res, vlSelf->top__DOT__regout2);
    } else if (vlSelf->top__DOT__memer) {
        Vtop___024unit____Vdpiimwrap_guest_read_TOP____024unit(vlSelf->top__DOT__res, __Vfunc_guest_read__6__Vfuncout);
        vlSelf->top__DOT__mem0__DOT__readreg = __Vfunc_guest_read__6__Vfuncout;
    }
    vlSelf->top__DOT__regormem__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__mem0__DOT__readreg)));
    vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__mem0__DOT__readreg;
}
