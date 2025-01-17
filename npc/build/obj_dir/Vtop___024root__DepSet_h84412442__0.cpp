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
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(1U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->rst) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__rst))));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
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
    IData/*31:0*/ __Vdly__top__DOT__ifu0__DOT__pcbridge;
    __Vdly__top__DOT__ifu0__DOT__pcbridge = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0;
    __Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0 = 0;
    // Body
    __Vdly__top__DOT__ifu0__DOT__pcbridge = vlSelf->top__DOT__ifu0__DOT__pcbridge;
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
    } else if (vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[(0x1fU 
                                                                    & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
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
                                                                    & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
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
                                                                    & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                                       >> 7U))] 
            = top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32da3398__0;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[vlSelf->top__DOT__regfile__DOT__csr_choose] 
            = top__DOT__regfile__DOT__registers0__DOT____Vconcswap_1_h32f40fb6__0;
    }
    if ((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2U] 
            = vlSelf->top__DOT__regfile__DOT__reg_write_data;
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3U] = 1U;
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__ifu0__DOT__pcbridge = 0x80000000U;
    } else if (((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))) {
        if ((vlSelf->top__DOT__npc == vlSelf->top__DOT__ifu0__DOT__pcbridge)) {
            Vtop___024unit____Vdpiimwrap_ret_TOP____024unit(0U);
        }
        __Vdly__top__DOT__ifu0__DOT__pcbridge = vlSelf->top__DOT__npc;
    }
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        if (vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew) {
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
    vlSelf->top__DOT__ifu0__DOT__pcbridge = __Vdly__top__DOT__ifu0__DOT__pcbridge;
    if (__Vdlyvset__top__DOT__regfile__DOT____Vcellout__registers0__gr__v0) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0U] = 0U;
    }
    vlSelf->top__DOT__araddr[0U] = vlSelf->top__DOT__ifu0__DOT__pcbridge;
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
void Vtop___024unit____Vdpiimwrap_host_get_valid_TOP____024unit(IData/*31:0*/ valid);
extern const VlUnpacked<CData/*3:0*/, 64> Vtop__ConstPool__TABLE_ha43bcb51_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vfunc_guest_read__8__Vfuncout;
    __Vfunc_guest_read__8__Vfuncout = 0;
    // Body
    vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num 
        = ((0xfeU & ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num) 
                     << 1U)) | (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__feedback));
    if ((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))) {
        if (((IData)(vlSelf->top__DOT__data0__DOT__rvalid_sram) 
             & (IData)(vlSelf->top__DOT__data0__DOT__arvalid_sram))) {
            vlSelf->top__DOT__data0__DOT__mem0__DOT__busy = 0U;
            vlSelf->top__DOT__data0__DOT__mem0__DOT__state = 0U;
            vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count 
                = (0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num));
        }
    } else if ((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))) {
        if (((IData)(vlSelf->top__DOT__data0__DOT__wvalid_sram) 
             & (IData)(vlSelf->top__DOT__data0__DOT__awvalid_sram))) {
            vlSelf->top__DOT__data0__DOT__mem0__DOT__busy = 0U;
            vlSelf->top__DOT__data0__DOT__mem0__DOT__state = 0U;
            vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count 
                = (0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num));
        }
    } else if ((0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))) {
        if (((IData)(vlSelf->top__DOT__data0__DOT__arvalid_sram) 
             | ((IData)(vlSelf->top__DOT__data0__DOT__wvalid_sram) 
                & (IData)(vlSelf->top__DOT__data0__DOT__awvalid_sram)))) {
            vlSelf->top__DOT__data0__DOT__mem0__DOT__busy = 1U;
            if ((0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count))) {
                if (vlSelf->top__DOT__data0__DOT__arvalid_sram) {
                    vlSelf->top__DOT__data0__DOT__mem0__DOT__state = 1U;
                }
                if (((IData)(vlSelf->top__DOT__data0__DOT__wvalid_sram) 
                     & (IData)(vlSelf->top__DOT__data0__DOT__awvalid_sram))) {
                    vlSelf->top__DOT__data0__DOT__mem0__DOT__state = 2U;
                }
            } else {
                vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count 
                    = (0xfU & ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count) 
                               - (IData)(1U)));
            }
        }
    } else {
        vlSelf->top__DOT__data0__DOT__mem0__DOT__state = 0U;
    }
    if ((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))) {
        Vtop___024unit____Vdpiimwrap_guest_write_TOP____024unit(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg, vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg, (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask));
    }
    if ((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))) {
        Vtop___024unit____Vdpiimwrap_guest_read_TOP____024unit(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg, 4U, __Vfunc_guest_read__8__Vfuncout);
        vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg 
            = __Vfunc_guest_read__8__Vfuncout;
    } else {
        vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg = 0U;
    }
    if (vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy) {
        if (((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)) 
             | (2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))) {
            vlSelf->top__DOT__data0__DOT__arviter0__DOT__test = 1U;
            vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy = 0U;
            vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant = 0U;
        }
    } else {
        if ((1U & (IData)(vlSelf->top__DOT__data0__DOT__arvalid_in))) {
            vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant = 1U;
            vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy = 1U;
        }
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__i = 2U;
        if ((IData)((((IData)(vlSelf->top__DOT__data0__DOT__arvalid_in) 
                      >> 1U) | (0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))))) {
            vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant = 2U;
            vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy = 1U;
        }
    }
    if (vlSelf->top__DOT__ready_idu_to_ifu) {
        vlSelf->top__DOT__ifu0__DOT__inst_reg = vlSelf->top__DOT__rdata
            [0U];
    }
    vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__feedback 
        = (1U & VL_REDXOR_8((0xb8U & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))));
    vlSelf->top__DOT__data0__DOT__rvalid_sram = (1U 
                                                 == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state));
    vlSelf->top__DOT__data0__DOT__rvalid_out = ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                                & (- (IData)(
                                                             (1U 
                                                              == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
    if ((1U & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant))) {
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0U] 
            = (IData)((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)));
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0U] 
            = (IData)((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)));
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0U] 
            = vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg;
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0U] 
            = vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg;
    } else {
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0U] = 0U;
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0U] = 0U;
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0U] = 0U;
        vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0U] = 0U;
    }
    if ((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)) {
        Vtop___024unit____Vdpiimwrap_ret_TOP____024unit(0U);
    }
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((vlSelf->top__DOT__ifu0__DOT__inst_reg >> 0x14U) 
           == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit) 
           | ((vlSelf->top__DOT__ifu0__DOT__inst_reg 
               >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit) 
           | ((vlSelf->top__DOT__ifu0__DOT__inst_reg 
               >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit) 
           | ((vlSelf->top__DOT__ifu0__DOT__inst_reg 
               >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->top__DOT__data0__DOT__awvalid_sram = (0U 
                                                  != 
                                                  (((0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                    << 1U) 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant)));
    vlSelf->top__DOT__data0__DOT__wvalid_sram = (0U 
                                                 != 
                                                 ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                                  & ((0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                     << 1U)));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                        >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                           >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                           >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                           >> 0x14U) == vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->top__DOT__regfile__DOT__csr_choose = vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out;
    vlSelf->top__DOT__csrrw = (IData)((0x1073U == (0x707fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    vlSelf->top__DOT__csrrs = (IData)((0x2073U == (0x707fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    vlSelf->top__DOT__muxsig = ((((0x67U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                     | ((0x17U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                        | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)))) 
                                 << 2U) | (((0x37U 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                            << 1U) 
                                           | (3U == 
                                              (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    vlSelf->top__DOT__memsextsig = ((4U != (7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                  >> 0xcU))) 
                                    & (5U != (7U & 
                                              (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                               >> 0xcU))));
    vlSelf->top__DOT__memmask = ((0U == (7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                               >> 0xcU)))
                                  ? 1U : ((1U == (7U 
                                                  & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                     >> 0xcU)))
                                           ? 2U : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                        >> 0xcU)))
                                                    ? 4U
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                         >> 0xcU)))
                                                     ? 1U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                          >> 0xcU)))
                                                      ? 2U
                                                      : 0U)))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                        >> 0x1fU))) << 0xcU) | (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                        >> 0x1fU))) << 0x14U) | ((0xff000U 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg) 
                                                 | ((0x800U 
                                                     & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                          >> 0x14U)))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                        >> 0x1fU))) << 0xcU) | ((0xfe0U 
                                                 & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                      >> 7U))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm 
        = (((- (IData)((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                        >> 0x1fU))) << 0xcU) | ((0x800U 
                                                 & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                         >> 7U)))));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U 
        = ((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
           | (0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I 
        = ((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
           | ((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
              | ((0x13U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                 | ((7U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                    | (0x73U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    vlSelf->top__DOT____Vcellout__data0__bresp[1U] 
        = vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp
        [1U];
    vlSelf->top__DOT____Vcellout__data0__bresp[0U] 
        = vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp
        [0U];
    vlSelf->top__DOT____Vcellout__data0__rdata[1U] 
        = vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata
        [1U];
    vlSelf->top__DOT____Vcellout__data0__rdata[0U] 
        = vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata
        [0U];
    Vtop___024unit____Vdpiimwrap_host_get_valid_TOP____024unit(
                                                               (1U 
                                                                & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                                                   & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                                                       & (- (IData)(
                                                                                ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                                                                & (0U 
                                                                                == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))))) 
                                                                      >> 1U))));
    if (vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm;
    } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm;
    } else if ((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm;
    } else if ((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm;
    } else if (vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = (0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg);
        vlSelf->top__DOT__imm = (0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg);
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = (0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg);
    } else {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1U] = 0U;
        vlSelf->top__DOT__imm = 0U;
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] = 0U;
    }
    vlSelf->top__DOT__muximm = ((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x23U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                      | (0x67U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)))));
    vlSelf->top__DOT__aluop = ((((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                 | (0x63U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg))) 
                                << 1U) | ((3U != (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                          & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                             | (0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)))));
    vlSelf->top__DOT__bresp[1U] = vlSelf->top__DOT____Vcellout__data0__bresp
        [1U];
    vlSelf->top__DOT__bresp[0U] = vlSelf->top__DOT____Vcellout__data0__bresp
        [0U];
    vlSelf->top__DOT__rdata[1U] = vlSelf->top__DOT____Vcellout__data0__rdata
        [1U];
    vlSelf->top__DOT__rdata[0U] = vlSelf->top__DOT____Vcellout__data0__rdata
        [0U];
    if ((1U == (IData)(vlSelf->top__DOT__memmask))) {
        vlSelf->top__DOT__wstrb[1U] = 1U;
        vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s 
            = (((- (IData)((1U & (vlSelf->top__DOT__rdata
                                  [1U] >> 7U)))) << 8U) 
               | (0xffU & vlSelf->top__DOT__rdata[1U]));
        vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u 
            = (0xffU & vlSelf->top__DOT__rdata[1U]);
    } else if ((2U == (IData)(vlSelf->top__DOT__memmask))) {
        vlSelf->top__DOT__wstrb[1U] = 2U;
        vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s 
            = (((- (IData)((1U & (vlSelf->top__DOT__rdata
                                  [1U] >> 0xfU)))) 
                << 0x10U) | (0xffffU & vlSelf->top__DOT__rdata
                             [1U]));
        vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u 
            = (0xffffU & vlSelf->top__DOT__rdata[1U]);
    } else {
        vlSelf->top__DOT__wstrb[1U] = ((3U == (IData)(vlSelf->top__DOT__memmask))
                                        ? 4U : ((4U 
                                                 == (IData)(vlSelf->top__DOT__memmask))
                                                 ? 8U
                                                 : 0U));
        vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s 
            = vlSelf->top__DOT__rdata[1U];
        vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u 
            = vlSelf->top__DOT__rdata[1U];
    }
    vlSelf->top__DOT____Vcellinp__data0__wstrb[1U] 
        = vlSelf->top__DOT__wstrb[1U];
    vlSelf->top__DOT____Vcellinp__data0__wstrb[0U] 
        = vlSelf->top__DOT__wstrb[0U];
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
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                        << 4U) | ((8U 
                                                   & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                      >> 0x1bU)) 
                                                  | (7U 
                                                     & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                        >> 0xcU)))));
    vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop 
        = Vtop__ConstPool__TABLE_ha43bcb51_0[vlSelf->__Vtableidx1];
    vlSelf->top__DOT__ready_idu_to_ifu = ((0U == ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                  | (0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__ifu0__DOT__inst_reg)))) 
                                          | ((1U == 
                                              (1U & 
                                               (((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                                 >> 1U) 
                                                & (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__ifu0__DOT__inst_reg))))) 
                                             | (1U 
                                                == 
                                                (vlSelf->top__DOT__bresp
                                                 [1U] 
                                                 & (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1U] 
        = vlSelf->top__DOT____Vcellinp__data0__wstrb
        [1U];
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0U] 
        = vlSelf->top__DOT____Vcellinp__data0__wstrb
        [0U];
    vlSelf->__VdfgTmp_he79674ea__0 = ((3U == (IData)(vlSelf->top__DOT__aluop))
                                       ? ((IData)((0x6000U 
                                                   == 
                                                   (0x6000U 
                                                    & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                           ? 8U : (
                                                   (1U 
                                                    & VL_REDXOR_16(
                                                                   (0x6000U 
                                                                    & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                                    ? 9U
                                                    : 3U))
                                       : (((2U == (IData)(vlSelf->top__DOT__aluop)) 
                                           | (1U == (IData)(vlSelf->top__DOT__aluop)))
                                           ? (IData)(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop)
                                           : 1U));
    vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew 
        = (((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
            & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
               | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                  | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                     | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                        | (3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))))))) 
           & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out));
    vlSelf->top__DOT__data0__DOT__arvalid_in = (((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                 << 1U) 
                                                | (IData)(vlSelf->top__DOT__ready_idu_to_ifu));
    if (vlSelf->top__DOT__memsextsig) {
        vlSelf->top__DOT__wbu0__DOT__memread = vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s;
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2U] 
            = vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s;
    } else {
        vlSelf->top__DOT__wbu0__DOT__memread = vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u;
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2U] 
            = vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u;
    }
    vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg = 0U;
    if ((1U & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant))) {
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb
            [0U];
    }
    if ((2U & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant))) {
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb
            [1U];
    }
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0 
        = (IData)((0U != (0xcU & (IData)(vlSelf->__VdfgTmp_he79674ea__0))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig 
        = (IData)((4U == (0xcU & (IData)(vlSelf->__VdfgTmp_he79674ea__0))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig 
        = (IData)((0xcU == (0xcU & (IData)(vlSelf->__VdfgTmp_he79674ea__0))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig 
        = (IData)((8U == (0xcU & (IData)(vlSelf->__VdfgTmp_he79674ea__0))));
    vlSelf->top__DOT__exu0__DOT__aluopcode = (((1U 
                                                == (IData)(vlSelf->top__DOT__aluop)) 
                                               << 4U) 
                                              | (IData)(vlSelf->__VdfgTmp_he79674ea__0));
    vlSelf->top__DOT__data0__DOT__arvalid_sram = (0U 
                                                  != 
                                                  ((IData)(vlSelf->top__DOT__data0__DOT__arvalid_in) 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant)));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__wbu0__DOT__memread)));
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
           == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
              == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
              == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
              == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                       == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                          == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                          == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = ((IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                          == vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask 
        = vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out;
}

void Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(IData/*31:0*/ pc);
void Vtop___024unit____Vdpiimwrap_host_get_inst_TOP____024unit(IData/*31:0*/ inst);

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    Vtop___024unit____Vdpiimwrap_host_get_pc_TOP____024unit(vlSelf->top__DOT__ifu0__DOT__pcbridge);
    Vtop___024unit____Vdpiimwrap_host_get_inst_TOP____024unit(vlSelf->top__DOT__ifu0__DOT__inst_reg);
    vlSelf->top__DOT__regout2 = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                   >> 0x14U))];
    vlSelf->top__DOT__wdata[1U] = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                   >> 0x14U))];
    vlSelf->top__DOT__regout1 = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                   >> 0xfU))];
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__regfile__DOT__rf[(0x1fU 
                                              & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                                 >> 0x14U))];
    vlSelf->top__DOT__exu0__DOT__pcaddimmbridge = (vlSelf->top__DOT__imm 
                                                   + vlSelf->top__DOT__ifu0__DOT__pcbridge);
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->top__DOT__regout2));
    vlSelf->top__DOT____Vcellinp__data0__wdata[1U] 
        = vlSelf->top__DOT__wdata[1U];
    vlSelf->top__DOT____Vcellinp__data0__wdata[0U] 
        = vlSelf->top__DOT__wdata[0U];
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__muximm) 
                       == vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muximm) 
                          == vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__exu0__DOT__aluarg2 = vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out;
    if (((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
         | (0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)))) {
        vlSelf->top__DOT__pcwritereg = ((IData)(4U) 
                                        + vlSelf->top__DOT__ifu0__DOT__pcbridge);
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = ((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge);
    } else if ((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))) {
        vlSelf->top__DOT__pcwritereg = vlSelf->top__DOT__exu0__DOT__pcaddimmbridge;
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__exu0__DOT__pcaddimmbridge;
    } else if ((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)) {
        vlSelf->top__DOT__pcwritereg = ((IData)(4U) 
                                        + vlSelf->top__DOT__ifu0__DOT__pcbridge);
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = ((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge);
    } else {
        vlSelf->top__DOT__pcwritereg = 0U;
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0U] = 0U;
    }
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1U] 
        = vlSelf->top__DOT____Vcellinp__data0__wdata
        [1U];
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0U] 
        = vlSelf->top__DOT____Vcellinp__data0__wdata
        [0U];
    if ((1U & ((IData)(vlSelf->top__DOT__exu0__DOT__aluopcode) 
               ^ ((IData)(vlSelf->top__DOT__exu0__DOT__aluopcode) 
                  >> 1U)))) {
        vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp 
            = (1U & (IData)((1ULL & (((QData)((IData)(vlSelf->top__DOT__regout1)) 
                                      + (QData)((IData)(vlSelf->top__DOT__exu0__DOT__aluarg2))) 
                                     >> 0x20U))));
        vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres 
            = (vlSelf->top__DOT__regout1 + vlSelf->top__DOT__exu0__DOT__aluarg2);
    } else if ((1U & (~ ((IData)(vlSelf->top__DOT__exu0__DOT__aluopcode) 
                         ^ ((IData)(vlSelf->top__DOT__exu0__DOT__aluopcode) 
                            >> 1U))))) {
        vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp 
            = (1U & (IData)((1ULL & ((1ULL + ((QData)((IData)(vlSelf->top__DOT__regout1)) 
                                              + (QData)((IData)(
                                                                (~ vlSelf->top__DOT__exu0__DOT__aluarg2))))) 
                                     >> 0x20U))));
        vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres 
            = ((IData)(1U) + (vlSelf->top__DOT__regout1 
                              + (~ vlSelf->top__DOT__exu0__DOT__aluarg2)));
    }
    if ((1U & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode))) {
        if ((1U & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode))) {
            vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres 
                = (VL_LTS_III(32, vlSelf->top__DOT__regout1, vlSelf->top__DOT__exu0__DOT__aluarg2)
                    ? 1U : 0U);
        }
    } else {
        vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres 
            = ((vlSelf->top__DOT__regout1 < vlSelf->top__DOT__exu0__DOT__aluarg2)
                ? 1U : 0U);
    }
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres 
        = ((2U & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode))
            ? ((1U & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode))
                ? (~ (vlSelf->top__DOT__regout1 | vlSelf->top__DOT__exu0__DOT__aluarg2))
                : (vlSelf->top__DOT__regout1 ^ vlSelf->top__DOT__exu0__DOT__aluarg2))
            : ((1U & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode))
                ? (vlSelf->top__DOT__regout1 | vlSelf->top__DOT__exu0__DOT__aluarg2)
                : ((1U == (IData)(vlSelf->top__DOT__aluop))
                    ? (vlSelf->top__DOT__regout1 & vlSelf->top__DOT__exu0__DOT__aluarg2)
                    : (vlSelf->top__DOT__regout1 & vlSelf->top__DOT__exu0__DOT__aluarg2))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres 
        = ((0U == (3U & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode)))
            ? ((1U == (IData)(vlSelf->top__DOT__aluop))
                ? (vlSelf->top__DOT__regout1 << (0x1fU 
                                                 & vlSelf->top__DOT__exu0__DOT__aluarg2))
                : ((0x1fU >= vlSelf->top__DOT__exu0__DOT__aluarg2)
                    ? (vlSelf->top__DOT__regout1 << vlSelf->top__DOT__exu0__DOT__aluarg2)
                    : 0U)) : ((1U == (3U & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode)))
                               ? ((1U == (IData)(vlSelf->top__DOT__aluop))
                                   ? (vlSelf->top__DOT__regout1 
                                      >> (0x1fU & vlSelf->top__DOT__exu0__DOT__aluarg2))
                                   : ((0x1fU >= vlSelf->top__DOT__exu0__DOT__aluarg2)
                                       ? (vlSelf->top__DOT__regout1 
                                          >> vlSelf->top__DOT__exu0__DOT__aluarg2)
                                       : 0U)) : ((2U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlSelf->top__DOT__exu0__DOT__aluopcode)))
                                                  ? 
                                                 ((1U 
                                                   == (IData)(vlSelf->top__DOT__aluop))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__regout1, 
                                                                 (0x1fU 
                                                                  & vlSelf->top__DOT__exu0__DOT__aluarg2))
                                                   : 
                                                  ((0x1fU 
                                                    >= vlSelf->top__DOT__exu0__DOT__aluarg2)
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__regout1, vlSelf->top__DOT__exu0__DOT__aluarg2)
                                                    : 
                                                   (- 
                                                    (vlSelf->top__DOT__regout1 
                                                     >> 0x1fU))))
                                                  : 0U)));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0U] 
        = (0x400000000ULL | (QData)((IData)(vlSelf->top__DOT__pcwritereg)));
    vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg = 0U;
    if (vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0) {
        if (vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig) {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres;
            vlSelf->top__DOT__awaddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres;
            vlSelf->top__DOT__araddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres;
        } else if (vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig) {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres;
            vlSelf->top__DOT__awaddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres;
            vlSelf->top__DOT__araddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres;
        } else if (vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig) {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres;
            vlSelf->top__DOT__awaddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres;
            vlSelf->top__DOT__araddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres;
        } else {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] = 0U;
            vlSelf->top__DOT__res = 0U;
            vlSelf->top__DOT__awaddr[1U] = 0U;
            vlSelf->top__DOT__araddr[1U] = 0U;
        }
    } else {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
            = vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres;
        vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres;
        vlSelf->top__DOT__awaddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres;
        vlSelf->top__DOT__araddr[1U] = vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres;
    }
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                       == vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__muxsig) == vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                          == vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__muxsig) == 
              vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                          == vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__muxsig) == 
              vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                          == vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__muxsig) == 
              vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->top__DOT__regwrite = ((IData)(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit)
                                   ? vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out
                                   : 0U);
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(vlSelf->top__DOT__res));
    vlSelf->top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0 
        = (1U & ((~ vlSelf->top__DOT__res) | (0U == vlSelf->top__DOT__res)));
    vlSelf->top__DOT____Vcellinp__data0__awaddr[1U] 
        = vlSelf->top__DOT__awaddr[1U];
    vlSelf->top__DOT____Vcellinp__data0__awaddr[0U] 
        = vlSelf->top__DOT__awaddr[0U];
    vlSelf->top__DOT____Vcellinp__data0__araddr[1U] 
        = vlSelf->top__DOT__araddr[1U];
    vlSelf->top__DOT____Vcellinp__data0__araddr[0U] 
        = vlSelf->top__DOT__araddr[0U];
    vlSelf->top__DOT__regfile__DOT__reg_write_data 
        = (((IData)(vlSelf->top__DOT__csrrs) | (IData)(vlSelf->top__DOT__csrrw))
            ? vlSelf->top__DOT__regout1 : vlSelf->top__DOT__regwrite);
    vlSelf->top__DOT__npc = ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))
                              ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                              : ((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))
                                  ? (0xfffffffeU & vlSelf->top__DOT__res)
                                  : ((IData)(((0x63U 
                                               == (0x707fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                              & (0U 
                                                 == vlSelf->top__DOT__res)))
                                      ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                      : ((IData)(((0x1063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                  & (0U 
                                                     != vlSelf->top__DOT__res)))
                                          ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                          : ((IData)(
                                                     ((0x4063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                      & vlSelf->top__DOT__res))
                                              ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                              : ((IData)(
                                                         ((0x5063U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                          & (IData)(vlSelf->top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0)))
                                                  ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                                  : 
                                                 ((IData)(
                                                          ((0x6063U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                           & vlSelf->top__DOT__res))
                                                   ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                                   : 
                                                  ((IData)(
                                                           ((0x7063U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                            & (IData)(vlSelf->top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0)))
                                                    ? vlSelf->top__DOT__exu0__DOT__pcaddimmbridge
                                                    : 
                                                   ((0x30200073U 
                                                     == vlSelf->top__DOT__ifu0__DOT__inst_reg)
                                                     ? 
                                                    vlSelf->top__DOT__regfile__DOT__rf_csr
                                                    [2U]
                                                     : 
                                                    ((0x73U 
                                                      == vlSelf->top__DOT__ifu0__DOT__inst_reg)
                                                      ? 
                                                     vlSelf->top__DOT__regfile__DOT__rf_csr
                                                     [1U]
                                                      : 
                                                     ((IData)(4U) 
                                                      + vlSelf->top__DOT__ifu0__DOT__pcbridge)))))))))));
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1U] 
        = vlSelf->top__DOT____Vcellinp__data0__awaddr
        [1U];
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0U] 
        = vlSelf->top__DOT____Vcellinp__data0__awaddr
        [0U];
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1U] 
        = vlSelf->top__DOT____Vcellinp__data0__araddr
        [1U];
    vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0U] 
        = vlSelf->top__DOT____Vcellinp__data0__araddr
        [0U];
    vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg = 0U;
    if ((1U & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant))) {
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata
            [0U];
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr
            [0U];
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg = 0U;
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr
            [0U];
    } else {
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg = 0U;
    }
    if ((2U & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant))) {
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata
            [1U];
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr
            [1U];
        vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
            = vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr
            [1U];
    }
}
