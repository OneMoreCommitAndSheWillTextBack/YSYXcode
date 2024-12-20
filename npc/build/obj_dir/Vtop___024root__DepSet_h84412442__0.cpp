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
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->rst) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__rst))));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(2U) = ((IData)(vlSelf->clk) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__clk));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
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

void Vtop___024unit____Vdpiimwrap_ret_TOP____024unit(IData/*31:0*/ pc);
void Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(IData/*31:0*/ regval, IData/*31:0*/ regnum);
void Vtop___024unit____Vdpiimwrap_host_get_csr_TOP____024unit(IData/*31:0*/ csrval, IData/*31:0*/ csrnum);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3deb3bf9__0;
    top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3deb3bf9__0 = 0;
    IData/*31:0*/ top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3ded67c7__0;
    top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3ded67c7__0 = 0;
    IData/*31:0*/ top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32da3398__0;
    top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32da3398__0 = 0;
    IData/*31:0*/ top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32f40fb6__0;
    top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32f40fb6__0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0;
    __Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0 = 0;
    // Body
    vlSelf->__Vdly__top__DOT__ifu0__DOT__pcbridge = vlSelf->top__DOT__ifu0__DOT__pcbridge;
    __Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0 = 0U;
    if (vlSelf->rst) {
        vlSelf->top__DOT__regfile__DOT__registers0__DOT__i = 0x20U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0xaU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0xbU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0xcU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0xdU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0xeU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0xfU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x10U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x11U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x12U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x13U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x14U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x15U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x16U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x17U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x18U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x19U] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x1aU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x1bU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x1cU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x1dU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x1eU] = 0U;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0x1fU] = 0U;
    } else if (vlSelf->top__DOT__regew) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[(0x1fU 
                                                                    & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                                       >> 7U))] 
            = vlSelf->top__DOT__regfile__DOT__reg_write_data;
    }
    if (vlSelf->top__DOT__csrrw) {
        top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3deb3bf9__0 
            = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
            [vlSelf->top__DOT__regfile__DOT__csr_choose];
        top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3ded67c7__0 
            = vlSelf->top__DOT__regfile__DOT__reg_write_data;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[(0x1fU 
                                                                    & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                                       >> 7U))] 
            = top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3deb3bf9__0;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[vlSelf->top__DOT__regfile__DOT__csr_choose] 
            = top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h3ded67c7__0;
    }
    if (vlSelf->top__DOT__csrrs) {
        top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32da3398__0 
            = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
            [vlSelf->top__DOT__regfile__DOT__csr_choose];
        top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32f40fb6__0 
            = (vlSelf->top__DOT__regfile__DOT__reg_write_data 
               | vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
               [vlSelf->top__DOT__regfile__DOT__csr_choose]);
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[(0x1fU 
                                                                    & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                                       >> 7U))] 
            = top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32da3398__0;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[vlSelf->top__DOT__regfile__DOT__csr_choose] 
            = top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32f40fb6__0;
    }
    if ((0x73U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2U] 
            = vlSelf->top__DOT__regfile__DOT__reg_write_data;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3U] 
            = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
            [0xfU];
    }
    if (vlSelf->rst) {
        vlSelf->__Vdly__top__DOT__ifu0__DOT__pcbridge = 0x80000000U;
    } else {
        if ((vlSelf->top__DOT__npc == vlSelf->top__DOT__ifu0__DOT__pcbridge)) {
            Vtop___024unit____Vdpiimwrap_ret_TOP____024unit(vlSelf->top__DOT__npc);
        }
        if ((0U != vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) {
            vlSelf->__Vdly__top__DOT__ifu0__DOT__pcbridge 
                = vlSelf->top__DOT__npc;
        }
    }
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        if (vlSelf->top__DOT__regew) {
            __Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0 = 1U;
        }
    }
    vlSelf->top__DOT__regfile__DOT__rf_csr[3U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
        [3U];
    vlSelf->top__DOT__regfile__DOT__rf_csr[2U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
        [2U];
    vlSelf->top__DOT__regfile__DOT__rf_csr[1U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
        [1U];
    vlSelf->top__DOT__regfile__DOT__rf_csr[0U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
        [0U];
    if (__Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0U] = 0U;
    }
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0U], 0U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [1U], 1U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [2U], 2U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [3U], 3U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [4U], 4U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [5U], 5U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [6U], 6U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [7U], 7U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [8U], 8U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [9U], 9U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0xaU], 0xaU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0xbU], 0xbU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0xcU], 0xcU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0xdU], 0xdU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0xeU], 0xeU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0xfU], 0xfU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x10U], 0x10U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x11U], 0x11U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x12U], 0x12U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x13U], 0x13U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x14U], 0x14U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x15U], 0x15U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x16U], 0x16U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x17U], 0x17U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x18U], 0x18U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x19U], 0x19U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x1aU], 0x1aU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x1bU], 0x1bU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x1cU], 0x1cU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x1dU], 0x1dU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x1eU], 0x1eU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
                                                             [0x1fU], 0x1fU);
    Vtop___024unit____Vdpiimwrap_host_get_csr_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
                                                             [0U], 0U);
    Vtop___024unit____Vdpiimwrap_host_get_csr_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
                                                             [1U], 1U);
    Vtop___024unit____Vdpiimwrap_host_get_csr_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
                                                             [2U], 2U);
    Vtop___024unit____Vdpiimwrap_host_get_csr_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr
                                                             [3U], 3U);
    vlSelf->top__DOT__regfile__DOT__rf[0x1fU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x1fU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1eU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x1eU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1dU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x1dU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1cU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x1cU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1bU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x1bU];
    vlSelf->top__DOT__regfile__DOT__rf[0x1aU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x1aU];
    vlSelf->top__DOT__regfile__DOT__rf[0x19U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x19U];
    vlSelf->top__DOT__regfile__DOT__rf[0x18U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x18U];
    vlSelf->top__DOT__regfile__DOT__rf[0x17U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x17U];
    vlSelf->top__DOT__regfile__DOT__rf[0x16U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x16U];
    vlSelf->top__DOT__regfile__DOT__rf[0x15U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x15U];
    vlSelf->top__DOT__regfile__DOT__rf[0x14U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x14U];
    vlSelf->top__DOT__regfile__DOT__rf[0x13U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x13U];
    vlSelf->top__DOT__regfile__DOT__rf[0x12U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x12U];
    vlSelf->top__DOT__regfile__DOT__rf[0x11U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x11U];
    vlSelf->top__DOT__regfile__DOT__rf[0x10U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0x10U];
    vlSelf->top__DOT__regfile__DOT__rf[0xfU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0xfU];
    vlSelf->top__DOT__regfile__DOT__rf[0xeU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0xeU];
    vlSelf->top__DOT__regfile__DOT__rf[0xdU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0xdU];
    vlSelf->top__DOT__regfile__DOT__rf[0xcU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0xcU];
    vlSelf->top__DOT__regfile__DOT__rf[0xbU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0xbU];
    vlSelf->top__DOT__regfile__DOT__rf[0xaU] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0xaU];
    vlSelf->top__DOT__regfile__DOT__rf[9U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [9U];
    vlSelf->top__DOT__regfile__DOT__rf[8U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [8U];
    vlSelf->top__DOT__regfile__DOT__rf[7U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [7U];
    vlSelf->top__DOT__regfile__DOT__rf[6U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [6U];
    vlSelf->top__DOT__regfile__DOT__rf[5U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [5U];
    vlSelf->top__DOT__regfile__DOT__rf[4U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [4U];
    vlSelf->top__DOT__regfile__DOT__rf[3U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [3U];
    vlSelf->top__DOT__regfile__DOT__rf[2U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [2U];
    vlSelf->top__DOT__regfile__DOT__rf[1U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [1U];
    vlSelf->top__DOT__regfile__DOT__rf[0U] = vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr
        [0U];
}

void Vtop___024unit____Vdpiimwrap_guest_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len);
void Vtop___024unit____Vdpiimwrap_guest_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &guest_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vfunc_guest_read__8__Vfuncout;
    __Vfunc_guest_read__8__Vfuncout = 0;
    // Body
    if (((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
         & (~ (IData)(vlSelf->clk)))) {
        Vtop___024unit____Vdpiimwrap_guest_write_TOP____024unit(vlSelf->top__DOT__res, vlSelf->top__DOT__regout2, (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__len));
    }
    if (((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
         & (~ (IData)(vlSelf->clk)))) {
        Vtop___024unit____Vdpiimwrap_guest_read_TOP____024unit(vlSelf->top__DOT__res, (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__len), __Vfunc_guest_read__8__Vfuncout);
        vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
            = __Vfunc_guest_read__8__Vfuncout;
    } else {
        vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg = 0U;
    }
}

void Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ &get_inst__Vfuncrtn);
extern const VlUnpacked<CData/*3:0*/, 64> Vtop__ConstPool__TABLE_ha43bcb51_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vfunc_get_inst__3__Vfuncout;
    __Vfunc_get_inst__3__Vfuncout = 0;
    // Body
    Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit(vlSelf->top__DOT__ifu0__DOT__pcbridge, __Vfunc_get_inst__3__Vfuncout);
    vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
        = __Vfunc_get_inst__3__Vfuncout;
    if ((0x100073U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) {
        Vtop___024unit____Vdpiimwrap_ret_TOP____024unit(0U);
    }
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
            >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit) 
           | ((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
               >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit) 
           | ((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
               >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit) 
           | ((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
               >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                        >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                           >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                           >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                           >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->top__DOT__regfile__DOT__csr_choose = vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out;
    vlSelf->top__DOT__csrrw = (IData)((0x1073U == (0x707fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)));
    vlSelf->top__DOT__csrrs = (IData)((0x2073U == (0x707fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)));
    vlSelf->top__DOT__muxsig = ((((0x67U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                     | ((0x17U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                        | (0x73U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))) 
                                 << 2U) | (((0x37U 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                            << 1U) 
                                           | (3U == 
                                              (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    vlSelf->top__DOT__wbu0__DOT__mem0__DOT__signalsig 
        = ((4U != (7U & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                         >> 0xcU))) & (5U != (7U & 
                                              (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                               >> 0xcU))));
    vlSelf->top__DOT__wbu0__DOT__mem0__DOT__len = (
                                                   (0U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                        >> 0xcU)))
                                                    ? 1U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                         >> 0xcU)))
                                                     ? 2U
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                          >> 0xcU)))
                                                      ? 4U
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                           >> 0xcU)))
                                                       ? 1U
                                                       : 
                                                      ((5U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                            >> 0xcU)))
                                                        ? 2U
                                                        : 0U)))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                        >> 0x1fU))) << 0xcU) | (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                        >> 0x1fU))) << 0x14U) | ((0xff000U 
                                                  & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst) 
                                                 | ((0x800U 
                                                     & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                          >> 0x14U)))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                        >> 0x1fU))) << 0xcU) | ((0xfe0U 
                                                 & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                      >> 7U))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                        >> 0x1fU))) << 0xcU) | ((0x800U 
                                                 & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                         >> 7U)))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U 
        = ((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
           | (0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I 
        = ((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
           | ((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
              | ((0x13U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                 | ((7U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                    | (0x73U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))))));
    vlSelf->top__DOT__regew = ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                               | ((0x33U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                        | (3U == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))))));
    if (vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm;
    } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm;
    } else if ((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm;
    } else if ((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm;
    } else if (vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = (0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst);
        vlSelf->top__DOT__imm = (0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst);
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = (0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst);
    } else {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] = 0U;
        vlSelf->top__DOT__imm = 0U;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] = 0U;
    }
    vlSelf->top__DOT__muximm = ((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                | ((0x23U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                      | (0x67U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))));
    vlSelf->top__DOT__aluop = ((((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                 | (0x63U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))) 
                                << 1U) | ((3U != (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                          & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                             | (0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))));
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__imm)));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__imm)));
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__muximm) == vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__muximm) == 
              vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->__Vtableidx1 = (((2U == (IData)(vlSelf->top__DOT__aluop)) 
                             << 5U) | (((0x67U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                        << 4U) | ((8U 
                                                   & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                      >> 0x1bU)) 
                                                  | (7U 
                                                     & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                                        >> 0xcU)))));
    vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop 
        = Vtop__ConstPool__TABLE_ha43bcb51_0[vlSelf->__Vtableidx1];
    vlSelf->__VdfgTmp_h33f498c0__0 = ((3U == (IData)(vlSelf->top__DOT__aluop))
                                       ? ((IData)((0x6000U 
                                                   == 
                                                   (0x6000U 
                                                    & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))
                                           ? 8U : (
                                                   (1U 
                                                    & VL_REDXOR_16(
                                                                   (0x6000U 
                                                                    & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))
                                                    ? 9U
                                                    : 3U))
                                       : (((2U == (IData)(vlSelf->top__DOT__aluop)) 
                                           | (1U == (IData)(vlSelf->top__DOT__aluop)))
                                           ? (IData)(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop)
                                           : 1U));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0 
        = (IData)((0U != (0xcU & (IData)(vlSelf->__VdfgTmp_h33f498c0__0))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig 
        = (IData)((4U == (0xcU & (IData)(vlSelf->__VdfgTmp_h33f498c0__0))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig 
        = (IData)((0xcU == (0xcU & (IData)(vlSelf->__VdfgTmp_h33f498c0__0))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig 
        = (IData)((8U == (0xcU & (IData)(vlSelf->__VdfgTmp_h33f498c0__0))));
    vlSelf->top__DOT__exu0__DOT__aluopcode = (((1U 
                                                == (IData)(vlSelf->top__DOT__aluop)) 
                                               << 4U) 
                                              | (IData)(vlSelf->__VdfgTmp_h33f498c0__0));
}

void Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(IData/*31:0*/ pc);
void Vtop___024unit____Vdpiimwrap_host_get_inst_TOP____024unit(IData/*31:0*/ inst);

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    // Body
    Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(vlSelf->top__DOT__ifu0__DOT__pcbridge);
    Vtop___024unit____Vdpiimwrap_host_get_inst_TOP____024unit(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst);
    VL_WRITEF("pc: 0x%08x %08x\n",32,vlSelf->top__DOT__ifu0__DOT__pcbridge,
              32,vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst);
    vlSelf->top__DOT__exu0__DOT__pcaddimmbridge = (vlSelf->top__DOT__imm 
                                                   + vlSelf->top__DOT__ifu0__DOT__pcbridge);
    if (((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
         | (0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))) {
        vlSelf->top__DOT__pcwritereg = ((IData)(4U) 
                                        + vlSelf->top__DOT__ifu0__DOT__pcbridge);
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = ((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge);
    } else if ((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__pcwritereg = vlSelf->top__DOT__exu0__DOT__pcaddimmbridge;
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__exu0__DOT__pcaddimmbridge;
    } else if ((0x73U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) {
        vlSelf->top__DOT__pcwritereg = ((IData)(4U) 
                                        + vlSelf->top__DOT__ifu0__DOT__pcbridge);
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = ((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge);
    } else {
        vlSelf->top__DOT__pcwritereg = 0U;
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] = 0U;
    }
    vlSelf->top__DOT__npc = ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))
                              ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                              : ((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))
                                  ? (0xfffffffeU & vlSelf->top__DOT__res)
                                  : ((IData)(((0x63U 
                                               == (0x707fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                              & (0U 
                                                 == vlSelf->top__DOT__res)))
                                      ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                      : ((IData)(((0x1063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                                  & (0U 
                                                     != vlSelf->top__DOT__res)))
                                          ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                          : ((IData)(
                                                     ((0x4063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                                      & vlSelf->top__DOT__res))
                                              ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                              : ((IData)(
                                                         ((0x5063U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                                          & (IData)(vlSelf->top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0)))
                                                  ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                                  : 
                                                 ((IData)(
                                                          ((0x6063U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                                           & vlSelf->top__DOT__res))
                                                   ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                                   : 
                                                  ((IData)(
                                                           ((0x7063U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                                            & (IData)(vlSelf->top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0)))
                                                    ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                                    : 
                                                   ((0x30200073U 
                                                     == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)
                                                     ? 
                                                    vlSelf->top__DOT__regfile__DOT__rf_csr
                                                    [2U]
                                                     : 
                                                    ((0x73U 
                                                      == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)
                                                      ? 
                                                     vlSelf->top__DOT__regfile__DOT__rf_csr
                                                     [1U]
                                                      : 
                                                     ((IData)(4U) 
                                                      + vlSelf->top__DOT__ifu0__DOT__pcbridge)))))))))));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0U] 
        = (0x400000000ULL | (QData)((IData)(vlSelf->top__DOT__pcwritereg)));
}
