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

void Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ &get_inst__Vfuncrtn);
void Vtop___024unit____Vdpiimwrap_ret_TOP____024unit();
extern const VlUnpacked<CData/*3:0*/, 64> Vtop__ConstPool__TABLE_ha43bcb51_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->pc_out = vlSelf->top__DOT__pcbridge;
    vlSelf->top__DOT__regormem__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__mem0__DOT__readreg)));
    vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__mem0__DOT__readreg;
    Vtop___024unit____Vdpiimwrap_get_inst_TOP____024unit(vlSelf->top__DOT__pcbridge, vlSelf->__Vfunc_get_inst__3__Vfuncout);
    vlSelf->top__DOT__infetch0__DOT__reg_inst = vlSelf->__Vfunc_get_inst__3__Vfuncout;
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
    vlSelf->top__DOT__decoder0__DOT__type_S = (0x23U 
                                               == (0x7fU 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst));
    vlSelf->top__DOT__memer = (3U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst));
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
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__regwritepc) 
                                                  == 
                                                  vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                  [0U]);
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit = ((IData)(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit) 
                                                  | ((IData)(vlSelf->top__DOT__regwritepc) 
                                                     == 
                                                     vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list
                                                     [1U]));
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
    vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->top__DOT__regout2));
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
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[0U] 
        = (QData)((IData)(vlSelf->top__DOT__muxregormem));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0U] 
        = vlSelf->top__DOT__muxregormem;
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[1U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->top__DOT__pcwritereg)));
    vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1U] 
        = vlSelf->top__DOT__pcwritereg;
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
