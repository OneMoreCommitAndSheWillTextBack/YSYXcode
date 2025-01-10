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

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__regout2 = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                   >> 0x14U))];
    vlSelf->top__DOT__regout1 = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                   >> 0xfU))];
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__regfile__DOT__rf[(0x1fU 
                                              & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                                 >> 0x14U))];
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->top__DOT__regout2));
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
    if (vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0) {
        if (vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig) {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres;
        } else if (vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig) {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres;
        } else if (vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig) {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
                = vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres;
        } else {
            vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] = 0U;
            vlSelf->top__DOT__res = 0U;
        }
    } else {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3U] 
            = vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres;
        vlSelf->top__DOT__res = vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres;
    }
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(vlSelf->top__DOT__res));
    vlSelf->top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0 
        = (1U & ((~ vlSelf->top__DOT__res) | (0U == vlSelf->top__DOT__res)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__ifu0__DOT__pcbridge = vlSelf->__Vdly__top__DOT__ifu0__DOT__pcbridge;
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
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
    VlTriggerVec<2> __VpreTriggered;
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
