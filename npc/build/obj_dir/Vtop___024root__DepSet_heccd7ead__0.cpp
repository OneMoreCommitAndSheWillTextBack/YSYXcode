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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    VL_WRITEF("0x%08x: 0x%08x\n",32,vlSelf->top__DOT__pcbridge,
              32,vlSelf->inst_out);
}

extern const VlUnpacked<CData/*3:0*/, 64> Vtop__ConstPool__TABLE_ha43bcb51_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->top__DOT__regout2 = vlSelf->top__DOT__regfile__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                   >> 0x14U))];
    vlSelf->top__DOT__decoder0__DOT__type_S = (0x23U 
                                               == (0x7fU 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst));
    vlSelf->top__DOT__memer = (3U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst));
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->top__DOT__regout2));
    vlSelf->top__DOT__regormem__DOT__i0__DOT__hit = 
        ((IData)(vlSelf->top__DOT__memer) == vlSelf->top__DOT__regormem__DOT__i0__DOT__key_list
         [0U]);
    vlSelf->top__DOT__regormem__DOT__i0__DOT__hit = 
        ((IData)(vlSelf->top__DOT__regormem__DOT__i0__DOT__hit) 
         | ((IData)(vlSelf->top__DOT__memer) == vlSelf->top__DOT__regormem__DOT__i0__DOT__key_list
            [1U]));
    vlSelf->top__DOT__decoder0__DOT__type_I = ((IData)(vlSelf->top__DOT__memer) 
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
    if (vlSelf->top__DOT__decoder0__DOT__type_I) {
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__I_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__I_imm;
    } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__J_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__J_imm;
    } else if (vlSelf->top__DOT__decoder0__DOT__type_S) {
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__S_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__S_imm;
    } else if ((0x63U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__imm = vlSelf->top__DOT__decoder0__DOT__B_imm;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = vlSelf->top__DOT__decoder0__DOT__B_imm;
    } else if (vlSelf->top__DOT__decoder0__DOT__type_U) {
        vlSelf->top__DOT__imm = (0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst);
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] 
            = (0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst);
    } else {
        vlSelf->top__DOT__imm = 0U;
        vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0U] = 0U;
    }
    vlSelf->top__DOT__muximm = ((IData)(vlSelf->top__DOT__memer) 
                                | ((IData)(vlSelf->top__DOT__decoder0__DOT__type_S) 
                                   | ((IData)(vlSelf->top__DOT__decoder0__DOT__type_I) 
                                      | (0x67U == (0x7fU 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst)))));
    vlSelf->top__DOT__aluop = ((((0x33U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                 | (0x63U == (0x7fU 
                                              & vlSelf->top__DOT__infetch0__DOT__reg_inst))) 
                                << 1U) | ((IData)(vlSelf->top__DOT__decoder0__DOT__type_I) 
                                          | (0x63U 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__imm)));
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
    if ((1U & ((IData)(vlSelf->top__DOT__aluopcode) 
               ^ ((IData)(vlSelf->top__DOT__aluopcode) 
                  >> 1U)))) {
        vlSelf->top__DOT__alu0__DOT__addres = (vlSelf->top__DOT__alu0__DOT__A_s 
                                               + vlSelf->top__DOT__aluarg2);
    } else if ((1U & (~ ((IData)(vlSelf->top__DOT__aluopcode) 
                         ^ ((IData)(vlSelf->top__DOT__aluopcode) 
                            >> 1U))))) {
        vlSelf->top__DOT__alu0__DOT__addres = ((IData)(1U) 
                                               + (vlSelf->top__DOT__alu0__DOT__A_s 
                                                  + 
                                                  (~ vlSelf->top__DOT__aluarg2)));
    }
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
                                                   VL_GTS_III(32, vlSelf->top__DOT__alu0__DOT__A_s, vlSelf->top__DOT__aluarg2)
                                                    ? 1U
                                                    : 0U);
        }
    } else {
        vlSelf->top__DOT__alu0__DOT__sltres = ((vlSelf->top__DOT__alu0__DOT__A_s 
                                                > vlSelf->top__DOT__aluarg2)
                                                ? 1U
                                                : 0U);
    }
    if (vlSelf->top__DOT__alu0__DOT____VdfgTmp_h1dc29214__0) {
        if (vlSelf->top__DOT__alu0__DOT__logsig) {
            vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[1U] 
                = vlSelf->top__DOT__alu0__DOT__logres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__logres;
        } else if (vlSelf->top__DOT__alu0__DOT__shfsig) {
            vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[1U] 
                = vlSelf->top__DOT__alu0__DOT__shfres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__shfres;
        } else if (vlSelf->top__DOT__alu0__DOT__sltsig) {
            vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[1U] 
                = vlSelf->top__DOT__alu0__DOT__sltres;
            vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__sltres;
        } else {
            vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[1U] = 0U;
            vlSelf->top__DOT__res = 0U;
        }
    } else {
        vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[1U] 
            = vlSelf->top__DOT__alu0__DOT__addres;
        vlSelf->top__DOT__res = vlSelf->top__DOT__alu0__DOT__addres;
    }
    vlSelf->top__DOT__regormem__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->top__DOT__res));
    if ((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__pcwritereg = ((IData)(4U) 
                                        + vlSelf->top__DOT__pcbridge);
        vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp 
            = vlSelf->top__DOT__pcaddimmbridge;
    } else if ((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__pcwritereg = ((IData)(4U) 
                                        + vlSelf->top__DOT__pcbridge);
        vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp 
            = (0xfffffffeU & vlSelf->top__DOT__res);
    } else if ((0x63U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        if ((0U == (7U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                          >> 0xcU)))) {
            vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp 
                = ((0U == vlSelf->top__DOT__res) ? vlSelf->top__DOT__pcaddimmbridge
                    : ((IData)(4U) + vlSelf->top__DOT__pcbridge));
        } else if (VL_LIKELY((1U == (7U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                           >> 0xcU))))) {
            vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp 
                = ((0U == vlSelf->top__DOT__res) ? 
                   ((IData)(4U) + vlSelf->top__DOT__pcbridge)
                    : vlSelf->top__DOT__pcaddimmbridge);
        } else {
            VL_WRITEF("meet a unknown B type inst\n");
        }
    } else if ((0x17U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))) {
        vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp 
            = ((IData)(4U) + vlSelf->top__DOT__pcbridge);
        vlSelf->top__DOT__pcwritereg = vlSelf->top__DOT__pcaddimmbridge;
    } else {
        vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp 
            = ((IData)(4U) + vlSelf->top__DOT__pcbridge);
    }
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[1U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__pcwritereg)));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__pcwritereg;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__regormem__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__memer) 
                       == vlSelf->top__DOT__regormem__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__regormem__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__regormem__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__memer) 
                          == vlSelf->top__DOT__regormem__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__muxregormem = vlSelf->top__DOT__regormem__DOT__i0__DOT__lut_out;
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[0U] 
        = (QData)((IData)(vlSelf->top__DOT__muxregormem));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__muxregormem;
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__regwritepc) 
                       == vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->top__DOT__regwritepc) 
                          == vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__regwrite = vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((vlSelf->__VnbaTriggered.at(1U) | vlSelf->__VnbaTriggered.at(2U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
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
