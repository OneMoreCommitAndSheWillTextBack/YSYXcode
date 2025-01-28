// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_h44c198b2__0;
    VlWide<5>/*159:0*/ __Vtemp_hdaf246d3__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[0]));
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[1]));
        bufp->chgBit(oldp+2,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[2]));
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
        bufp->chgCData(oldp+14,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
        bufp->chgBit(oldp+15,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[0]));
        bufp->chgBit(oldp+16,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[1]));
        bufp->chgBit(oldp+17,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[2]));
        bufp->chgBit(oldp+18,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                              [2U]));
        bufp->chgBit(oldp+19,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                              [0U]));
        bufp->chgBit(oldp+20,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                              [1U]));
        bufp->chgBit(oldp+21,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
        bufp->chgSData(oldp+23,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
        bufp->chgSData(oldp+24,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
        bufp->chgSData(oldp+25,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
        bufp->chgSData(oldp+26,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
        bufp->chgSData(oldp+27,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
        bufp->chgSData(oldp+28,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
        bufp->chgSData(oldp+29,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
        bufp->chgSData(oldp+30,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
        bufp->chgCData(oldp+31,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
        bufp->chgCData(oldp+32,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
        bufp->chgCData(oldp+33,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
        bufp->chgCData(oldp+34,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
        bufp->chgCData(oldp+35,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
        bufp->chgCData(oldp+36,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
        bufp->chgCData(oldp+37,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
        bufp->chgCData(oldp+38,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+39,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[0]));
        bufp->chgBit(oldp+40,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[1]));
        bufp->chgBit(oldp+41,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[2]));
        bufp->chgBit(oldp+42,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[0]));
        bufp->chgBit(oldp+43,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[1]));
        bufp->chgBit(oldp+44,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[2]));
        bufp->chgBit(oldp+45,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[0]));
        bufp->chgBit(oldp+46,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[1]));
        bufp->chgBit(oldp+47,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[2]));
        bufp->chgBit(oldp+48,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[0]));
        bufp->chgBit(oldp+49,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[1]));
        bufp->chgBit(oldp+50,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[2]));
        bufp->chgBit(oldp+51,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[0]));
        bufp->chgBit(oldp+52,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[1]));
        bufp->chgBit(oldp+53,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[2]));
        bufp->chgBit(oldp+54,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy));
        bufp->chgCData(oldp+55,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant),2);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__i),32);
        bufp->chgBit(oldp+57,((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__client0__DOT__state)))));
        bufp->chgBit(oldp+58,(vlSelf->top__DOT__data0__DOT__client0__DOT__state));
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg[0]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg[1]),32);
        bufp->chgBit(oldp+61,(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                               & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
        bufp->chgBit(oldp+62,((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
        bufp->chgBit(oldp+63,((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
        bufp->chgCData(oldp+64,(vlSelf->top__DOT__data0__DOT__mem0__DOT__state),2);
        bufp->chgCData(oldp+65,((0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))),4);
        bufp->chgBit(oldp+66,(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy));
        bufp->chgCData(oldp+67,(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count),4);
        bufp->chgCData(oldp+68,(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num),8);
        bufp->chgBit(oldp+69,((1U & VL_REDXOR_8((0xb8U 
                                                 & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))))));
        bufp->chgBit(oldp+70,((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__uart0__DOT__state)))));
        bufp->chgBit(oldp+71,(vlSelf->top__DOT__data0__DOT__uart0__DOT__state));
        bufp->chgBit(oldp+72,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[0]));
        bufp->chgBit(oldp+73,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[1]));
        bufp->chgBit(oldp+74,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[2]));
        bufp->chgBit(oldp+75,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[0]));
        bufp->chgBit(oldp+76,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[1]));
        bufp->chgBit(oldp+77,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[2]));
        bufp->chgBit(oldp+78,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                              [2U]));
        bufp->chgBit(oldp+79,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                              [2U]));
        bufp->chgBit(oldp+80,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                              [0U]));
        bufp->chgBit(oldp+81,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                              [0U]));
        bufp->chgBit(oldp+82,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                              [1U]));
        bufp->chgBit(oldp+83,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                              [1U]));
        bufp->chgBit(oldp+84,(vlSelf->top__DOT__wbu0__DOT__bresp_get));
        bufp->chgBit(oldp+85,(vlSelf->top__DOT__wbu0__DOT__rvalid_get));
    }
    if (VL_UNLIKELY(((vlSelf->__Vm_traceActivity[1U] 
                      | vlSelf->__Vm_traceActivity[3U]) 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+86,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                               & ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                   [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                  | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                      [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                     | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                        & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                        [0U]))))));
        bufp->chgCData(oldp+87,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                 & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                [1U] 
                                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                               | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                   [2U] 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                  | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                     & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                     [0U]))))))),2);
        bufp->chgCData(oldp+88,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                 & (- (IData)((((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                [1U]) 
                                               | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                                   & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                   [2U]) 
                                                  | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                     & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                     [0U]))))))),2);
        bufp->chgCData(oldp+89,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                 & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                [1U] 
                                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                               | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                   [2U] 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                  | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                     & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                     [0U]))))))),2);
        bufp->chgBit(oldp+90,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                      & (- (IData)(
                                                   ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                     [1U] 
                                                     & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                    | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                        [2U] 
                                                        & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                       | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                          & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                          [0U])))))) 
                                     >> 1U))));
        bufp->chgBit(oldp+91,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                      & (- (IData)(
                                                   (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                                     & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                     [1U]) 
                                                    | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                                        & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                        [2U]) 
                                                       | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                          & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                          [0U])))))) 
                                     >> 1U))));
        bufp->chgBit(oldp+92,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                      & (- (IData)(
                                                   ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                     [1U] 
                                                     & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                    | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                        [2U] 
                                                        & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                       | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                          & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                          [0U])))))) 
                                     >> 1U))));
        bufp->chgBit(oldp+93,((1U & ((((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                       & (- (IData)(
                                                    ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                      [1U] 
                                                      & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                     | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                         [2U] 
                                                         & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                        | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                           [0U])))))) 
                                      & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                          & (- (IData)(
                                                       ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                         [1U] 
                                                         & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                        | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                            [2U] 
                                                            & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                           | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                              & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                              [0U])))))) 
                                         & ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                            & (- (IData)(
                                                         (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                           [1U]) 
                                                          | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                                              & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                              [2U]) 
                                                             | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                                [0U])))))))) 
                                     >> 1U))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgCData(oldp+94,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                 & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                [1U] 
                                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                               | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                   [2U] 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                  | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                     & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                     [0U]))))))),2);
        bufp->chgIData(oldp+95,(((IData)(vlSelf->top__DOT__data0__DOT__client0__DOT__state)
                                  ? ((0xa0000048U == 
                                      vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                                      [2U]) ? vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg
                                     [0U] : ((0xa000004fU 
                                              == vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                                              [2U])
                                              ? vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg
                                             [1U] : 0U))
                                  : 0U)),32);
        bufp->chgBit(oldp+96,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                               [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgBit(oldp+97,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                               [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgBit(oldp+98,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                               & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                               [0U])));
        bufp->chgBit(oldp+99,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                               & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                               [0U])));
        bufp->chgBit(oldp+100,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                                [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+101,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                                [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+102,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                       & (- (IData)(
                                                    ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                      [1U] 
                                                      & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                     | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                         [2U] 
                                                         & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                        | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                           [0U])))))) 
                                      >> 1U))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+103,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
        bufp->chgIData(oldp+104,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                 [2U]),32);
        bufp->chgIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                 [1U]),32);
        bufp->chgIData(oldp+106,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
        bufp->chgIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+111,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+112,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+113,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+114,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+115,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+118,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+119,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+120,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+121,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+122,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+123,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+125,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+126,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+135,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+137,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+138,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
        bufp->chgIData(oldp+139,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
        bufp->chgIData(oldp+140,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
        bufp->chgIData(oldp+141,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
        bufp->chgIData(oldp+142,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
        bufp->chgIData(oldp+143,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
        bufp->chgIData(oldp+144,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
        bufp->chgIData(oldp+145,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
        bufp->chgIData(oldp+146,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
        bufp->chgIData(oldp+147,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
        bufp->chgIData(oldp+148,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
        bufp->chgIData(oldp+149,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
        bufp->chgIData(oldp+150,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
        bufp->chgIData(oldp+152,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
        bufp->chgIData(oldp+153,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
        bufp->chgIData(oldp+154,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
        bufp->chgIData(oldp+155,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
        bufp->chgIData(oldp+156,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
        bufp->chgIData(oldp+157,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
        bufp->chgIData(oldp+158,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
        bufp->chgIData(oldp+160,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
        bufp->chgIData(oldp+161,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
        bufp->chgIData(oldp+162,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
        bufp->chgIData(oldp+163,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
        bufp->chgIData(oldp+164,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
        bufp->chgIData(oldp+165,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
        bufp->chgIData(oldp+166,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
        bufp->chgIData(oldp+167,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
        bufp->chgIData(oldp+168,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
        bufp->chgIData(oldp+169,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
        bufp->chgIData(oldp+170,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
        bufp->chgIData(oldp+171,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
        bufp->chgIData(oldp+172,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
        bufp->chgIData(oldp+173,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
        bufp->chgIData(oldp+174,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
        bufp->chgIData(oldp+175,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
        bufp->chgIData(oldp+176,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
        bufp->chgIData(oldp+177,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
        bufp->chgIData(oldp+178,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
        bufp->chgIData(oldp+179,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+180,(vlSelf->top__DOT__ready_idu_to_ifu));
        bufp->chgIData(oldp+181,(vlSelf->top__DOT__ifu0__DOT__inst_reg),32);
        bufp->chgBit(oldp+182,((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state))));
        bufp->chgCData(oldp+183,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+184,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+185,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                           >> 7U))),5);
        bufp->chgIData(oldp+186,(vlSelf->top__DOT__imm),32);
        bufp->chgBit(oldp+187,((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
        bufp->chgBit(oldp+188,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
        bufp->chgBit(oldp+189,((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
        bufp->chgBit(oldp+190,(((3U != (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                   | ((0x33U == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | ((0x6fU == 
                                          (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                         | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))));
        bufp->chgBit(oldp+191,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+192,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+193,(vlSelf->top__DOT__muximm));
        bufp->chgCData(oldp+194,((7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+195,(vlSelf->top__DOT__muxsig),3);
        bufp->chgBit(oldp+196,((1U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                      >> 0x1eU))));
        bufp->chgBit(oldp+197,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+198,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+199,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+200,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgCData(oldp+201,(vlSelf->top__DOT__aluop),2);
        bufp->chgBit(oldp+202,(vlSelf->top__DOT__csrrw));
        bufp->chgBit(oldp+203,(vlSelf->top__DOT__csrrs));
        bufp->chgCData(oldp+204,(vlSelf->top__DOT__memmask),3);
        bufp->chgBit(oldp+205,(vlSelf->top__DOT__memsextsig));
        bufp->chgCData(oldp+206,(((IData)(vlSelf->top__DOT____Vcellout__wbu0__awvalid) 
                                  << 1U)),2);
        bufp->chgCData(oldp+207,(vlSelf->top__DOT__data0__DOT__arvalid_in),2);
        bufp->chgCData(oldp+208,((((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   << 1U) | (IData)(vlSelf->top__DOT__ready_idu_to_ifu))),2);
        bufp->chgCData(oldp+209,(((0x23U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                  << 1U)),2);
        bufp->chgCData(oldp+210,(vlSelf->top__DOT__wstrb[0]),4);
        bufp->chgCData(oldp+211,(vlSelf->top__DOT__wstrb[1]),4);
        bufp->chgCData(oldp+212,(vlSelf->top__DOT____Vcellinp__data0__wstrb[0]),4);
        bufp->chgCData(oldp+213,(vlSelf->top__DOT____Vcellinp__data0__wstrb[1]),4);
        bufp->chgBit(oldp+214,(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter));
        bufp->chgBit(oldp+215,(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter));
        bufp->chgBit(oldp+216,(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter));
        bufp->chgBit(oldp+217,(vlSelf->top__DOT__data0__DOT__rready_from_arbiter));
        bufp->chgBit(oldp+218,(vlSelf->top__DOT__data0__DOT__bready_from_arbiter));
        bufp->chgCData(oldp+219,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg),4);
        bufp->chgCData(oldp+220,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0]),4);
        bufp->chgCData(oldp+221,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1]),4);
        bufp->chgBit(oldp+222,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[0]));
        bufp->chgBit(oldp+223,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[1]));
        bufp->chgBit(oldp+224,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[2]));
        bufp->chgBit(oldp+225,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[0]));
        bufp->chgBit(oldp+226,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[1]));
        bufp->chgBit(oldp+227,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[2]));
        bufp->chgBit(oldp+228,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[0]));
        bufp->chgBit(oldp+229,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[1]));
        bufp->chgBit(oldp+230,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[2]));
        bufp->chgBit(oldp+231,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                               [2U]));
        bufp->chgBit(oldp+232,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                               [2U]));
        bufp->chgBit(oldp+233,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                               [2U]));
        bufp->chgBit(oldp+234,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                               [0U]));
        bufp->chgBit(oldp+235,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                               [0U]));
        bufp->chgBit(oldp+236,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                               [0U]));
        bufp->chgBit(oldp+237,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                               [1U]));
        bufp->chgBit(oldp+238,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                               [1U]));
        bufp->chgBit(oldp+239,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                               [1U]));
        bufp->chgCData(oldp+240,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
        bufp->chgBit(oldp+241,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
        bufp->chgBit(oldp+242,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
        bufp->chgBit(oldp+243,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
        bufp->chgBit(oldp+244,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
        bufp->chgBit(oldp+245,((1U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+246,((3U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+247,((2U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+248,((0U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgCData(oldp+249,(((IData)((0x6000U 
                                           == (0x6000U 
                                               & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                   ? 8U : ((1U & VL_REDXOR_16(
                                                              (0x6000U 
                                                               & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                            ? 9U : 3U))),4);
        bufp->chgCData(oldp+250,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
        bufp->chgBit(oldp+251,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+252,((0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)),7);
        bufp->chgBit(oldp+253,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
        bufp->chgBit(oldp+254,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+255,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
        bufp->chgIData(oldp+256,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
        bufp->chgIData(oldp+257,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)),32);
        bufp->chgIData(oldp+258,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
        bufp->chgIData(oldp+259,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
        bufp->chgIData(oldp+260,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
        bufp->chgBit(oldp+261,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x17U == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
        bufp->chgBit(oldp+262,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgCData(oldp+263,(vlSelf->top__DOT__ifu0__DOT__state),2);
        bufp->chgSData(oldp+264,((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                  >> 0x14U)),12);
        bufp->chgCData(oldp+265,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
        bufp->chgCData(oldp+266,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
        bufp->chgBit(oldp+267,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+268,(vlSelf->top__DOT____Vcellout__wbu0__awvalid));
        bufp->chgCData(oldp+269,(((1U == (IData)(vlSelf->top__DOT__memmask))
                                   ? 1U : ((2U == (IData)(vlSelf->top__DOT__memmask))
                                            ? 2U : 
                                           ((3U == (IData)(vlSelf->top__DOT__memmask))
                                             ? 4U : 
                                            ((4U == (IData)(vlSelf->top__DOT__memmask))
                                              ? 8U : 0U))))),4);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+270,(((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U))));
        bufp->chgBit(oldp+271,(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                 [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                    [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                   | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                      & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                      [0U])))));
        bufp->chgBit(oldp+272,((((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                 & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                 [1U]) | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                           [2U]) | 
                                          ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                           [0U])))));
        bufp->chgBit(oldp+273,(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                 [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                    [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                   | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                      & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                      [0U])))));
        bufp->chgBit(oldp+274,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgBit(oldp+275,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                [1U])));
        bufp->chgBit(oldp+276,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgBit(oldp+277,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                [0U])));
        bufp->chgBit(oldp+278,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                [0U])));
        bufp->chgBit(oldp+279,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                [0U])));
        bufp->chgBit(oldp+280,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+281,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                [2U])));
        bufp->chgBit(oldp+282,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+283,(((IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+284,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
        bufp->chgCData(oldp+285,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),4);
        bufp->chgBit(oldp+286,(((IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+287,(((IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+288,(((IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgBit(oldp+289,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter))));
        bufp->chgBit(oldp+290,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
        bufp->chgCData(oldp+291,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),4);
        bufp->chgBit(oldp+292,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter))));
        bufp->chgBit(oldp+293,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter))));
        bufp->chgBit(oldp+294,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter))));
        bufp->chgBit(oldp+295,(((IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgBit(oldp+296,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
        bufp->chgCData(oldp+297,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),4);
        bufp->chgBit(oldp+298,(((IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgBit(oldp+299,(((IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgBit(oldp+300,(((IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter) 
                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->top__DOT__imm))));
        __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                       >> 0x20U)));
        __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                    >> 0x1fU);
        bufp->chgWData(oldp+301,(__Vtemp_h44c198b2__0),66);
        bufp->chgQData(oldp+304,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+306,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+308,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+309,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
        bufp->chgBit(oldp+310,((((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state)) 
                                 & ((3U != (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                    & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                       | ((0x33U == 
                                           (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                          | ((0x6fU 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                             | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))) 
                                | ((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                      >> 1U)))));
        bufp->chgBit(oldp+311,(((IData)(vlSelf->top__DOT__ifu_valid) 
                                & (((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state)) 
                                    & ((3U != (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                       & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                          | ((0x33U 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                             | ((0x6fU 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                                | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))) 
                                   | ((3U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                         >> 1U))))));
        __Vtemp_hdaf246d3__0[0U] = (IData)((0x400000000ULL 
                                            | (QData)((IData)(vlSelf->top__DOT__pcwritereg))));
        __Vtemp_hdaf246d3__0[1U] = ((vlSelf->top__DOT__imm 
                                     << 3U) | (IData)(
                                                      ((0x400000000ULL 
                                                        | (QData)((IData)(vlSelf->top__DOT__pcwritereg))) 
                                                       >> 0x20U)));
        __Vtemp_hdaf246d3__0[2U] = (0x10U | ((vlSelf->top__DOT__wbu0__DOT__memread 
                                              << 6U) 
                                             | (vlSelf->top__DOT__imm 
                                                >> 0x1dU)));
        __Vtemp_hdaf246d3__0[3U] = (0x40U | ((vlSelf->top__DOT__res 
                                              << 9U) 
                                             | (vlSelf->top__DOT__wbu0__DOT__memread 
                                                >> 0x1aU)));
        __Vtemp_hdaf246d3__0[4U] = (vlSelf->top__DOT__res 
                                    >> 0x17U);
        bufp->chgWData(oldp+312,(__Vtemp_hdaf246d3__0),140);
        bufp->chgQData(oldp+317,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
        bufp->chgQData(oldp+319,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
        bufp->chgQData(oldp+321,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
        bufp->chgQData(oldp+323,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
        bufp->chgIData(oldp+325,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+326,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+327,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+328,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+329,(vlSelf->top__DOT__npc),32);
        bufp->chgBit(oldp+330,(vlSelf->top__DOT__ifu_valid));
        bufp->chgBit(oldp+331,((1U & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
        bufp->chgIData(oldp+332,(vlSelf->top__DOT__rdata
                                 [0U]),32);
        bufp->chgIData(oldp+333,(vlSelf->top__DOT__regwrite),32);
        bufp->chgIData(oldp+334,(vlSelf->top__DOT__regout1),32);
        bufp->chgIData(oldp+335,(vlSelf->top__DOT__regout2),32);
        bufp->chgIData(oldp+336,(vlSelf->top__DOT__res),32);
        bufp->chgIData(oldp+337,(vlSelf->top__DOT__pcwritereg),32);
        bufp->chgCData(oldp+338,(vlSelf->top__DOT__data0__DOT__rvalid_out),2);
        bufp->chgIData(oldp+339,(vlSelf->top__DOT__araddr[0]),32);
        bufp->chgIData(oldp+340,(vlSelf->top__DOT__araddr[1]),32);
        bufp->chgIData(oldp+341,(vlSelf->top__DOT__rdata[0]),32);
        bufp->chgIData(oldp+342,(vlSelf->top__DOT__rdata[1]),32);
        bufp->chgIData(oldp+343,(vlSelf->top__DOT__awaddr[0]),32);
        bufp->chgIData(oldp+344,(vlSelf->top__DOT__awaddr[1]),32);
        bufp->chgIData(oldp+345,(vlSelf->top__DOT__wdata[0]),32);
        bufp->chgIData(oldp+346,(vlSelf->top__DOT__wdata[1]),32);
        bufp->chgBit(oldp+347,(vlSelf->top__DOT__bresp[0]));
        bufp->chgBit(oldp+348,(vlSelf->top__DOT__bresp[1]));
        bufp->chgIData(oldp+349,(vlSelf->top__DOT____Vcellinp__data0__araddr[0]),32);
        bufp->chgIData(oldp+350,(vlSelf->top__DOT____Vcellinp__data0__araddr[1]),32);
        bufp->chgIData(oldp+351,(vlSelf->top__DOT____Vcellout__data0__rdata[0]),32);
        bufp->chgIData(oldp+352,(vlSelf->top__DOT____Vcellout__data0__rdata[1]),32);
        bufp->chgIData(oldp+353,(vlSelf->top__DOT____Vcellinp__data0__awaddr[0]),32);
        bufp->chgIData(oldp+354,(vlSelf->top__DOT____Vcellinp__data0__awaddr[1]),32);
        bufp->chgIData(oldp+355,(vlSelf->top__DOT____Vcellinp__data0__wdata[0]),32);
        bufp->chgIData(oldp+356,(vlSelf->top__DOT____Vcellinp__data0__wdata[1]),32);
        bufp->chgBit(oldp+357,(vlSelf->top__DOT____Vcellout__data0__bresp[0]));
        bufp->chgBit(oldp+358,(vlSelf->top__DOT____Vcellout__data0__bresp[1]));
        bufp->chgBit(oldp+359,(vlSelf->top__DOT__data0__DOT__rvalid_from_arbiter));
        bufp->chgBit(oldp+360,(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                 [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                    [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                   | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                      & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                      [0U])))));
        bufp->chgIData(oldp+361,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg),32);
        bufp->chgIData(oldp+362,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg),32);
        bufp->chgIData(oldp+363,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg),32);
        bufp->chgIData(oldp+364,((vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_urt 
                                  | (vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_client 
                                     | vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_sram))),32);
        bufp->chgBit(oldp+365,(vlSelf->top__DOT__data0__DOT__bresp_from_arbiter));
        bufp->chgBit(oldp+366,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[0]));
        bufp->chgBit(oldp+367,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[1]));
        bufp->chgBit(oldp+368,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[2]));
        bufp->chgBit(oldp+369,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[0]));
        bufp->chgBit(oldp+370,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[1]));
        bufp->chgBit(oldp+371,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[2]));
        bufp->chgBit(oldp+372,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[0]));
        bufp->chgBit(oldp+373,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[1]));
        bufp->chgBit(oldp+374,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[2]));
        bufp->chgBit(oldp+375,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[0]));
        bufp->chgBit(oldp+376,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[1]));
        bufp->chgBit(oldp+377,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[2]));
        bufp->chgBit(oldp+378,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[0]));
        bufp->chgBit(oldp+379,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[1]));
        bufp->chgBit(oldp+380,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[2]));
        bufp->chgIData(oldp+381,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[0]),32);
        bufp->chgIData(oldp+382,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[1]),32);
        bufp->chgIData(oldp+383,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[2]),32);
        bufp->chgIData(oldp+384,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[0]),32);
        bufp->chgIData(oldp+385,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[1]),32);
        bufp->chgIData(oldp+386,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[2]),32);
        bufp->chgIData(oldp+387,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[0]),32);
        bufp->chgIData(oldp+388,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[1]),32);
        bufp->chgIData(oldp+389,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[2]),32);
        bufp->chgIData(oldp+390,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[0]),32);
        bufp->chgIData(oldp+391,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[1]),32);
        bufp->chgIData(oldp+392,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[2]),32);
        bufp->chgCData(oldp+393,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[0]),4);
        bufp->chgCData(oldp+394,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[1]),4);
        bufp->chgCData(oldp+395,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[2]),4);
        bufp->chgIData(oldp+396,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0]),32);
        bufp->chgIData(oldp+397,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1]),32);
        bufp->chgIData(oldp+398,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0]),32);
        bufp->chgIData(oldp+399,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1]),32);
        bufp->chgIData(oldp+400,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0]),32);
        bufp->chgIData(oldp+401,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1]),32);
        bufp->chgIData(oldp+402,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0]),32);
        bufp->chgIData(oldp+403,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[1]),32);
        bufp->chgBit(oldp+404,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0]));
        bufp->chgBit(oldp+405,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[1]));
        bufp->chgBit(oldp+406,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                               [2U]));
        bufp->chgIData(oldp+407,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                                 [2U]),32);
        bufp->chgBit(oldp+408,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                               [2U]));
        bufp->chgIData(oldp+409,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                                 [2U]),32);
        bufp->chgCData(oldp+410,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                                 [2U]),4);
        bufp->chgBit(oldp+411,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                               [2U]));
        bufp->chgBit(oldp+412,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                               [2U]));
        bufp->chgIData(oldp+413,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                                 [2U]),32);
        bufp->chgBit(oldp+414,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                               [2U]));
        bufp->chgBit(oldp+415,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                               [0U]));
        bufp->chgIData(oldp+416,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                                 [0U]),32);
        bufp->chgBit(oldp+417,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                               [0U]));
        bufp->chgIData(oldp+418,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                                 [0U]),32);
        bufp->chgCData(oldp+419,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                                 [0U]),4);
        bufp->chgBit(oldp+420,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                               [0U]));
        bufp->chgBit(oldp+421,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                               [0U]));
        bufp->chgIData(oldp+422,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                                 [0U]),32);
        bufp->chgBit(oldp+423,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                               [0U]));
        bufp->chgIData(oldp+424,(vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg),32);
        bufp->chgCData(oldp+425,(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask),3);
        bufp->chgCData(oldp+426,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out),3);
        bufp->chgBit(oldp+427,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+428,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                               [1U]));
        bufp->chgIData(oldp+429,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                                 [1U]),32);
        bufp->chgBit(oldp+430,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                               [1U]));
        bufp->chgIData(oldp+431,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                                 [1U]),32);
        bufp->chgCData(oldp+432,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                                 [1U]),4);
        bufp->chgBit(oldp+433,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                               [1U]));
        bufp->chgBit(oldp+434,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                               [1U]));
        bufp->chgIData(oldp+435,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                                 [1U]),32);
        bufp->chgBit(oldp+436,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                               [1U]));
        bufp->chgBit(oldp+437,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[0]));
        bufp->chgBit(oldp+438,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[1]));
        bufp->chgBit(oldp+439,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[2]));
        bufp->chgIData(oldp+440,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[0]),32);
        bufp->chgIData(oldp+441,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[1]),32);
        bufp->chgIData(oldp+442,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[2]),32);
        bufp->chgBit(oldp+443,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[0]));
        bufp->chgBit(oldp+444,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[1]));
        bufp->chgBit(oldp+445,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[2]));
        bufp->chgIData(oldp+446,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[0]),32);
        bufp->chgIData(oldp+447,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[1]),32);
        bufp->chgIData(oldp+448,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[2]),32);
        bufp->chgCData(oldp+449,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[0]),4);
        bufp->chgCData(oldp+450,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[1]),4);
        bufp->chgCData(oldp+451,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[2]),4);
        bufp->chgBit(oldp+452,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[0]));
        bufp->chgBit(oldp+453,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[1]));
        bufp->chgBit(oldp+454,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[2]));
        bufp->chgBit(oldp+455,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[0]));
        bufp->chgBit(oldp+456,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[1]));
        bufp->chgBit(oldp+457,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[2]));
        bufp->chgIData(oldp+458,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[0]),32);
        bufp->chgIData(oldp+459,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[1]),32);
        bufp->chgIData(oldp+460,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[2]),32);
        bufp->chgBit(oldp+461,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[0]));
        bufp->chgBit(oldp+462,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[1]));
        bufp->chgBit(oldp+463,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[2]));
        bufp->chgIData(oldp+464,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[0]),32);
        bufp->chgIData(oldp+465,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[1]),32);
        bufp->chgIData(oldp+466,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[2]),32);
        bufp->chgBit(oldp+467,(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram));
        bufp->chgCData(oldp+468,((((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                   << 1U) | (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))),2);
        bufp->chgBit(oldp+469,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
        bufp->chgIData(oldp+470,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_urt),32);
        bufp->chgBit(oldp+471,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                [0U])));
        bufp->chgIData(oldp+472,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_sram),32);
        bufp->chgBit(oldp+473,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
        bufp->chgIData(oldp+474,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_client),32);
        bufp->chgBit(oldp+475,(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig));
        bufp->chgIData(oldp+476,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),32);
        bufp->chgIData(oldp+477,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),32);
        bufp->chgIData(oldp+478,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),32);
        bufp->chgIData(oldp+479,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                                 [2U]),32);
        bufp->chgIData(oldp+480,(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__mux__data),32);
        bufp->chgIData(oldp+481,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),32);
        bufp->chgIData(oldp+482,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),32);
        bufp->chgIData(oldp+483,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),32);
        bufp->chgIData(oldp+484,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                                 [0U]),32);
        bufp->chgBit(oldp+485,(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig));
        bufp->chgIData(oldp+486,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),32);
        bufp->chgIData(oldp+487,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),32);
        bufp->chgIData(oldp+488,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                                  & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),32);
        bufp->chgIData(oldp+489,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                                 [1U]),32);
        bufp->chgIData(oldp+490,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
        bufp->chgIData(oldp+491,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
        bufp->chgBit(oldp+492,((0U == vlSelf->top__DOT__res)));
        bufp->chgBit(oldp+493,((vlSelf->top__DOT__res 
                                >> 0x1fU)));
        bufp->chgBit(oldp+494,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
        bufp->chgIData(oldp+495,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
        bufp->chgIData(oldp+496,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
        bufp->chgBit(oldp+497,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
        bufp->chgIData(oldp+498,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
        bufp->chgIData(oldp+499,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
        bufp->chgIData(oldp+500,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
        bufp->chgIData(oldp+501,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
        bufp->chgBit(oldp+502,(vlSelf->top__DOT__bresp
                               [1U]));
        bufp->chgBit(oldp+503,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                      >> 1U))));
        bufp->chgIData(oldp+504,(vlSelf->top__DOT__rdata
                                 [1U]),32);
        bufp->chgIData(oldp+505,(vlSelf->top__DOT__wbu0__DOT__memread),32);
        bufp->chgIData(oldp+506,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
        bufp->chgIData(oldp+507,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
        bufp->chgIData(oldp+508,((((- (IData)((1U & 
                                               (vlSelf->top__DOT__rdata
                                                [1U] 
                                                >> 7U)))) 
                                   << 8U) | (0xffU 
                                             & vlSelf->top__DOT__rdata
                                             [1U]))),32);
        bufp->chgIData(oldp+509,((((- (IData)((1U & 
                                               (vlSelf->top__DOT__rdata
                                                [1U] 
                                                >> 0xfU)))) 
                                   << 0x10U) | (0xffffU 
                                                & vlSelf->top__DOT__rdata
                                                [1U]))),32);
        bufp->chgCData(oldp+510,((0xffU & vlSelf->top__DOT__rdata
                                  [1U])),8);
        bufp->chgSData(oldp+511,((0xffffU & vlSelf->top__DOT__rdata
                                  [1U])),16);
        bufp->chgIData(oldp+512,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+513,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    }
    bufp->chgBit(oldp+514,(vlSelf->clk));
    bufp->chgBit(oldp+515,(vlSelf->rst));
    bufp->chgBit(oldp+516,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__rvalid_get)) 
                            & (3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
