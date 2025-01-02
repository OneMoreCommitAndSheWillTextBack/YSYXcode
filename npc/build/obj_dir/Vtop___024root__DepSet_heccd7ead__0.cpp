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
    vlSelf->top__DOT__ifu0__DOT__pcbridge = vlSelf->__Vdly__top__DOT__ifu0__DOT__pcbridge;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state = vlSelf->__Vdly__top__DOT__wbu0__DOT__mem0__DOT__state;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    // Body
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
    vlSelf->top__DOT__regfile__DOT__reg_write_data 
        = (((IData)(vlSelf->top__DOT__csrrs) | (IData)(vlSelf->top__DOT__csrrw))
            ? vlSelf->top__DOT__regout1 : vlSelf->top__DOT__regwrite);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(1U) | vlSelf->__VnbaTriggered.at(2U))) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if (((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
         | vlSelf->__VnbaTriggered.at(2U))) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
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
    VlTriggerVec<3> __VpreTriggered;
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
                    VL_FATAL_MT("/home/ysyx/project/ysyx-workbench/npc/vsrc/top.v", 1, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/ysyx/project/ysyx-workbench/npc/vsrc/top.v", 1, "", "NBA region did not converge.");
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
