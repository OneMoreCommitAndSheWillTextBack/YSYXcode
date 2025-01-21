// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Body
    if (vlSelf->top__DOT____Vcellinp__wbu0__bresp) {
        vlSelf->top__DOT__wbu0__DOT__bresp_get = 1U;
    }
    if (vlSelf->top__DOT____Vcellinp__wbu0__rvalid) {
        vlSelf->top__DOT__wbu0__DOT__rvalid_get = 1U;
    }
    if ((1U & (~ (IData)(vlSelf->top__DOT__ifu_valid)))) {
        vlSelf->top__DOT__wbu0__DOT__bresp_get = 0U;
        vlSelf->top__DOT__wbu0__DOT__rvalid_get = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->top__DOT____Vcellout__wbu0__awvalid = (
                                                   (~ (IData)(vlSelf->top__DOT__wbu0__DOT__bresp_get)) 
                                                   & (0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    vlSelf->top__DOT__ready_idu_to_ifu = ((0U == ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                  | (0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__ifu0__DOT__inst_reg)))) 
                                          | ((1U == 
                                              ((IData)(vlSelf->top__DOT__wbu0__DOT__rvalid_get) 
                                               & (3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)))) 
                                             | (1U 
                                                == 
                                                ((IData)(vlSelf->top__DOT__wbu0__DOT__bresp_get) 
                                                 & (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    vlSelf->top__DOT__data0__DOT__awvalid_sram = (0U 
                                                  != 
                                                  (((IData)(vlSelf->top__DOT____Vcellout__wbu0__awvalid) 
                                                    << 1U) 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant)));
    vlSelf->top__DOT__data0__DOT__wvalid_sram = (0U 
                                                 != 
                                                 ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                                  & ((IData)(vlSelf->top__DOT____Vcellout__wbu0__awvalid) 
                                                     << 1U)));
    vlSelf->top__DOT__data0__DOT__arvalid_in = ((((~ (IData)(vlSelf->top__DOT__wbu0__DOT__rvalid_get)) 
                                                  & (3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__ifu0__DOT__inst_reg))) 
                                                 << 1U) 
                                                | (IData)(vlSelf->top__DOT__ready_idu_to_ifu));
    vlSelf->top__DOT__data0__DOT__arvalid_sram = (0U 
                                                  != 
                                                  ((IData)(vlSelf->top__DOT__data0__DOT__arvalid_in) 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant)));
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(3U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(2U))) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/ysyx/project/ysyx-workbench/npc/vsrc/top.v", 4, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/ysyx/project/ysyx-workbench/npc/vsrc/top.v", 4, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
