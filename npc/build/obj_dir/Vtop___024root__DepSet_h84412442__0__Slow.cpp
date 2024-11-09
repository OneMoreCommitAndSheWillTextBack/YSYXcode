// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vtop___024unit____Vdpiimwrap_ret_TOP____024unit(IData/*31:0*/ pc);
void Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(IData/*31:0*/ regval, IData/*31:0*/ regnum);
extern const VlUnpacked<CData/*3:0*/, 64> Vtop__ConstPool__TABLE_ha43bcb51_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((IData)((0x73U == (0x707fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)))) {
        Vtop___024unit____Vdpiimwrap_ret_TOP____024unit(0U);
    }
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0U], 0U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [1U], 1U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [2U], 2U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [3U], 3U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [4U], 4U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [5U], 5U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [6U], 6U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [7U], 7U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [8U], 8U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [9U], 9U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0xaU], 0xaU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0xbU], 0xbU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0xcU], 0xcU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0xdU], 0xdU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0xeU], 0xeU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0xfU], 0xfU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x10U], 0x10U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x11U], 0x11U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x12U], 0x12U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x13U], 0x13U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x14U], 0x14U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x15U], 0x15U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x16U], 0x16U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x17U], 0x17U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x18U], 0x18U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x19U], 0x19U);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x1aU], 0x1aU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x1bU], 0x1bU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x1cU], 0x1cU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x1dU], 0x1dU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x1eU], 0x1eU);
    Vtop___024unit____Vdpiimwrap_host_get_reg_TOP____024unit(
                                                             vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out
                                                             [0x1fU], 0x1fU);
    vlSelf->top__DOT__muxsig = ((((0x67U == (0x7fU 
                                             & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                     | (0x17U == (0x7fU 
                                                  & vlSelf->top__DOT__infetch0__DOT__reg_inst)))) 
                                 << 2U) | (((0x37U 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                            << 1U) 
                                           | (3U == 
                                              (0x7fU 
                                               & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    vlSelf->top__DOT__mem0__DOT__signalsig = ((4U != 
                                               (7U 
                                                & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                   >> 0xcU))) 
                                              & (5U 
                                                 != 
                                                 (7U 
                                                  & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                     >> 0xcU))));
    vlSelf->top__DOT__mem0__DOT__len = ((0U == (7U 
                                                & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                   >> 0xcU)))
                                         ? 1U : ((1U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                      >> 0xcU)))
                                                  ? 2U
                                                  : 
                                                 ((2U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                       >> 0xcU)))
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                        >> 0xcU)))
                                                    ? 1U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                         >> 0xcU)))
                                                     ? 2U
                                                     : 0U)))));
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
    vlSelf->top__DOT__decoder0__DOT__type_I = ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                               | ((0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                                  | ((0x13U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                                     | ((7U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                                        | (0x73U 
                                                           == 
                                                           (0x7fU 
                                                            & vlSelf->top__DOT__infetch0__DOT__reg_inst))))));
    vlSelf->top__DOT__mem0__DOT__read_s = ((1U == (IData)(vlSelf->top__DOT__mem0__DOT__len))
                                            ? (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->top__DOT__mem0__DOT__readreg 
                                                               >> 7U)))) 
                                                << 8U) 
                                               | (0xffU 
                                                  & vlSelf->top__DOT__mem0__DOT__readreg))
                                            : ((2U 
                                                == (IData)(vlSelf->top__DOT__mem0__DOT__len))
                                                ? (
                                                   ((- (IData)(
                                                               (1U 
                                                                & (vlSelf->top__DOT__mem0__DOT__readreg 
                                                                   >> 0xfU)))) 
                                                    << 0x10U) 
                                                   | (0xffffU 
                                                      & vlSelf->top__DOT__mem0__DOT__readreg))
                                                : vlSelf->top__DOT__mem0__DOT__readreg));
    vlSelf->top__DOT__regout2 = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                   >> 0x14U))];
    vlSelf->top__DOT__alu0__DOT__A_s = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                   >> 0xfU))];
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__regfile__DOT__rf[(0x1fU 
                                              & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                 >> 0x14U))];
    vlSelf->top__DOT__regew = ((IData)(vlSelf->top__DOT__decoder0__DOT__type_I) 
                               | ((0x33U == (0x7fU 
                                             & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                     | ((IData)(vlSelf->top__DOT__decoder0__DOT__type_U) 
                                        | (3U == (0x7fU 
                                                  & vlSelf->top__DOT__infetch0__DOT__reg_inst))))));
    if (vlSelf->top__DOT__decoder0__DOT__type_I) {
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__decoder0__DOT__I_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__I_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__I_imm;
    } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__decoder0__DOT__J_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__J_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__J_imm;
    } else if ((0x23U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__decoder0__DOT__S_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__S_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__S_imm;
    } else if ((0x63U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__decoder0__DOT__B_imm;
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__B_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__B_imm;
    } else if (vlSelf->top__DOT__decoder0__DOT__type_U) {
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
            = (0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst);
        vlSelf->top__DOT__imm = (0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst);
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = (0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst);
    } else {
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] = 0U;
        vlSelf->top__DOT__imm = 0U;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] = 0U;
    }
    vlSelf->top__DOT__muximm = ((3U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                | ((0x23U == (0x7fU 
                                              & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                   | ((IData)(vlSelf->top__DOT__decoder0__DOT__type_I) 
                                      | (0x67U == (0x7fU 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst)))));
    vlSelf->top__DOT__aluop = ((((0x33U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                 | (0x63U == (0x7fU 
                                              & vlSelf->top__DOT__infetch0__DOT__reg_inst))) 
                                << 1U) | ((3U != (0x7fU 
                                                  & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                          & ((IData)(vlSelf->top__DOT__decoder0__DOT__type_I) 
                                             | (0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__infetch0__DOT__reg_inst)))));
    if (vlSelf->top__DOT__mem0__DOT__signalsig) {
        vlSelf->top__DOT__memread = vlSelf->top__DOT__mem0__DOT__read_s;
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[2U] 
            = vlSelf->top__DOT__mem0__DOT__read_s;
    } else {
        vlSelf->top__DOT__memread = vlSelf->top__DOT__mem0__DOT__readreg;
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[2U] 
            = vlSelf->top__DOT__mem0__DOT__readreg;
    }
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->top__DOT__regout2));
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__imm)));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->top__DOT__imm)));
    vlSelf->top__DOT__pcaddimmbridge = (vlSelf->top__DOT__imm 
                                        + vlSelf->top__DOT__pcbridge);
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__muximm) == vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__muximm) == 
              vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__muximm) 
                       == vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muximm) 
                          == vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__aluarg2 = vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__lut_out;
    vlSelf->__Vtableidx1 = (((2U == (IData)(vlSelf->top__DOT__aluop)) 
                             << 5U) | (((0x67U == (0x7fU 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                        << 4U) | ((8U 
                                                   & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                      >> 0x1bU)) 
                                                  | (7U 
                                                     & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                                        >> 0xcU)))));
    vlSelf->top__DOT__alucontrol0__DOT__IRop = Vtop__ConstPool__TABLE_ha43bcb51_0
        [vlSelf->__Vtableidx1];
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__memread)));
    if (((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
         | (0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)))) {
        vlSelf->top__DOT__pcwritereg = ((IData)(4U) 
                                        + vlSelf->top__DOT__pcbridge);
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = ((IData)(4U) + vlSelf->top__DOT__pcbridge);
    } else if ((0x17U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__pcwritereg = vlSelf->top__DOT__pcaddimmbridge;
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__pcaddimmbridge;
    } else {
        vlSelf->top__DOT__pcwritereg = 0U;
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0U] = 0U;
    }
    vlSelf->top__DOT__aluopcode = ((3U == (IData)(vlSelf->top__DOT__aluop))
                                    ? ((IData)((0x6000U 
                                                == 
                                                (0x6000U 
                                                 & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                                        ? 8U : ((1U 
                                                 & VL_REDXOR_16(
                                                                (0x6000U 
                                                                 & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                                                 ? 9U
                                                 : 3U))
                                    : (((2U == (IData)(vlSelf->top__DOT__aluop)) 
                                        | (1U == (IData)(vlSelf->top__DOT__aluop)))
                                        ? (IData)(vlSelf->top__DOT__alucontrol0__DOT__IRop)
                                        : 1U));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[0U] 
        = (0x400000000ULL | (QData)((IData)(vlSelf->top__DOT__pcwritereg)));
    if ((1U & ((IData)(vlSelf->top__DOT__aluopcode) 
               ^ ((IData)(vlSelf->top__DOT__aluopcode) 
                  >> 1U)))) {
        vlSelf->top__DOT__carry = (1U & (IData)((1ULL 
                                                 & (((QData)((IData)(vlSelf->top__DOT__alu0__DOT__A_s)) 
                                                     + (QData)((IData)(vlSelf->top__DOT__aluarg2))) 
                                                    >> 0x20U))));
        vlSelf->top__DOT__alu0__DOT__addres = (vlSelf->top__DOT__alu0__DOT__A_s 
                                               + vlSelf->top__DOT__aluarg2);
    } else if ((1U & (~ ((IData)(vlSelf->top__DOT__aluopcode) 
                         ^ ((IData)(vlSelf->top__DOT__aluopcode) 
                            >> 1U))))) {
        vlSelf->top__DOT__carry = (1U & (IData)((1ULL 
                                                 & ((1ULL 
                                                     + 
                                                     ((QData)((IData)(vlSelf->top__DOT__alu0__DOT__A_s)) 
                                                      + (QData)((IData)(
                                                                        (~ vlSelf->top__DOT__aluarg2))))) 
                                                    >> 0x20U))));
        vlSelf->top__DOT__alu0__DOT__addres = ((IData)(1U) 
                                               + (vlSelf->top__DOT__alu0__DOT__A_s 
                                                  + 
                                                  (~ vlSelf->top__DOT__aluarg2)));
    }
    vlSelf->top__DOT__alu0__DOT____VdfgTmp_h1dc29214__0 
        = (IData)((0U != (0xcU & (IData)(vlSelf->top__DOT__aluopcode))));
    vlSelf->top__DOT__alu0__DOT__logsig = (IData)((4U 
                                                   == 
                                                   (0xcU 
                                                    & (IData)(vlSelf->top__DOT__aluopcode))));
    vlSelf->top__DOT__alu0__DOT__shfsig = (IData)((0xcU 
                                                   == 
                                                   (0xcU 
                                                    & (IData)(vlSelf->top__DOT__aluopcode))));
    vlSelf->top__DOT__alu0__DOT__sltsig = (IData)((8U 
                                                   == 
                                                   (0xcU 
                                                    & (IData)(vlSelf->top__DOT__aluopcode))));
    vlSelf->top__DOT__alu0__DOT__logres = ((2U & (IData)(vlSelf->top__DOT__aluopcode))
                                            ? ((1U 
                                                & (IData)(vlSelf->top__DOT__aluopcode))
                                                ? (~ 
                                                   (vlSelf->top__DOT__alu0__DOT__A_s 
                                                    | vlSelf->top__DOT__aluarg2))
                                                : (vlSelf->top__DOT__alu0__DOT__A_s 
                                                   ^ vlSelf->top__DOT__aluarg2))
                                            : ((1U 
                                                & (IData)(vlSelf->top__DOT__aluopcode))
                                                ? (vlSelf->top__DOT__alu0__DOT__A_s 
                                                   | vlSelf->top__DOT__aluarg2)
                                                : (vlSelf->top__DOT__alu0__DOT__A_s 
                                                   & vlSelf->top__DOT__aluarg2)));
    vlSelf->top__DOT__alu0__DOT__shfres = ((0U == (3U 
                                                   & (IData)(vlSelf->top__DOT__aluopcode)))
                                            ? ((0x1fU 
                                                >= vlSelf->top__DOT__aluarg2)
                                                ? (vlSelf->top__DOT__alu0__DOT__A_s 
                                                   << vlSelf->top__DOT__aluarg2)
                                                : 0U)
                                            : ((1U 
                                                == 
                                                (3U 
                                                 & (IData)(vlSelf->top__DOT__aluopcode)))
                                                ? (
                                                   (0x1fU 
                                                    >= vlSelf->top__DOT__aluarg2)
                                                    ? 
                                                   (vlSelf->top__DOT__alu0__DOT__A_s 
                                                    >> vlSelf->top__DOT__aluarg2)
                                                    : 0U)
                                                : (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlSelf->top__DOT__aluopcode)))
                                                    ? 
                                                   (((0x1fU 
                                                      >= vlSelf->top__DOT__aluarg2)
                                                      ? 
                                                     ((- (IData)(
                                                                 (vlSelf->top__DOT__alu0__DOT__A_s 
                                                                  >> 0x1fU))) 
                                                      << vlSelf->top__DOT__aluarg2)
                                                      : 0U) 
                                                    | ((0x1fU 
                                                        >= vlSelf->top__DOT__aluarg2)
                                                        ? 
                                                       (vlSelf->top__DOT__alu0__DOT__A_s 
                                                        >> vlSelf->top__DOT__aluarg2)
                                                        : 0U))
                                                    : 0U)));
    if ((1U & (IData)(vlSelf->top__DOT__aluopcode))) {
        if ((1U & (IData)(vlSelf->top__DOT__aluopcode))) {
            vlSelf->top__DOT__alu0__DOT__sltres = (
                                                   VL_LTS_III(32, vlSelf->top__DOT__alu0__DOT__A_s, vlSelf->top__DOT__aluarg2)
                                                    ? 1U
                                                    : 0U);
        }
    } else {
        vlSelf->top__DOT__alu0__DOT__sltres = ((vlSelf->top__DOT__alu0__DOT__A_s 
                                                < vlSelf->top__DOT__aluarg2)
                                                ? 1U
                                                : 0U);
    }
    if (vlSelf->top__DOT__alu0__DOT____VdfgTmp_h1dc29214__0) {
        if (vlSelf->top__DOT__alu0__DOT__logsig) {
            vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__logres;
            vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__alu0__DOT__logres;
        } else if (vlSelf->top__DOT__alu0__DOT__shfsig) {
            vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__shfres;
            vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__alu0__DOT__shfres;
        } else if (vlSelf->top__DOT__alu0__DOT__sltsig) {
            vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__sltres;
            vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__alu0__DOT__sltres;
        } else {
            vlSelf->top__DOT__res = 0U;
            vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[3U] = 0U;
        }
    } else {
        vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__addres;
        vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
            = vlSelf->top__DOT__alu0__DOT__addres;
    }
    vlSelf->top__DOT__npc = ((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))
                              ? vlSelf->top__DOT__pcaddimmbridge
                              : ((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))
                                  ? (0xfffffffeU & vlSelf->top__DOT__res)
                                  : ((IData)(((0x63U 
                                               == (0x707fU 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                              & (0U 
                                                 == vlSelf->top__DOT__res)))
                                      ? vlSelf->top__DOT__pcaddimmbridge
                                      : ((IData)(((0x1063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                                  & (0U 
                                                     != vlSelf->top__DOT__res)))
                                          ? vlSelf->top__DOT__pcaddimmbridge
                                          : ((IData)(4U) 
                                             + vlSelf->top__DOT__pcbridge)))));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(vlSelf->top__DOT__res));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                       == vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__muxsig) 
                                                  == 
                                                  vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                  [0U]);
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                          == vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit) 
                                                  | ((IData)(vlSelf->top__DOT__muxsig) 
                                                     == 
                                                     vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                     [1U]));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                          == vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit) 
                                                  | ((IData)(vlSelf->top__DOT__muxsig) 
                                                     == 
                                                     vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                     [2U]));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__muxsig) 
                          == vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit) 
                                                  | ((IData)(vlSelf->top__DOT__muxsig) 
                                                     == 
                                                     vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                     [3U]));
    vlSelf->top__DOT__regwrite = ((IData)(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit)
                                   ? vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out
                                   : 0U);
}
