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
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
        bufp->chgSData(oldp+2,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
        bufp->chgSData(oldp+3,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
        bufp->chgSData(oldp+4,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
        bufp->chgSData(oldp+5,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
        bufp->chgSData(oldp+6,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
        bufp->chgSData(oldp+7,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
        bufp->chgSData(oldp+8,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
        bufp->chgSData(oldp+9,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
        bufp->chgCData(oldp+14,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
        bufp->chgCData(oldp+15,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
        bufp->chgCData(oldp+16,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
        bufp->chgCData(oldp+17,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__ifu0__DOT__instbridge),32);
        bufp->chgBit(oldp+19,((0U != vlSelf->top__DOT__ifu0__DOT__instbridge)));
        bufp->chgCData(oldp+20,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+21,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+22,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                          >> 7U))),5);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__imm),32);
        bufp->chgBit(oldp+24,((0x100073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
        bufp->chgBit(oldp+25,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
        bufp->chgBit(oldp+26,((0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
        bufp->chgBit(oldp+27,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                               | ((0x33U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                        | (3U == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__instbridge))))))));
        bufp->chgBit(oldp+28,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgBit(oldp+29,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgBit(oldp+30,(vlSelf->top__DOT__muximm));
        bufp->chgCData(oldp+31,((7U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+32,(vlSelf->top__DOT__muxsig),3);
        bufp->chgBit(oldp+33,((1U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                     >> 0x1eU))));
        bufp->chgBit(oldp+34,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgBit(oldp+35,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgBit(oldp+36,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgBit(oldp+37,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgCData(oldp+38,(vlSelf->top__DOT__aluop),2);
        bufp->chgCData(oldp+39,(vlSelf->top__DOT__memmask),3);
        bufp->chgBit(oldp+40,(vlSelf->top__DOT__memsextsig));
        bufp->chgCData(oldp+41,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
        bufp->chgBit(oldp+42,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
        bufp->chgBit(oldp+43,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
        bufp->chgBit(oldp+44,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
        bufp->chgBit(oldp+45,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
        bufp->chgBit(oldp+46,((1U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+47,((3U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+48,((2U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+49,((0U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgCData(oldp+50,(((IData)((0x6000U == 
                                          (0x6000U 
                                           & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                                  ? 8U : ((1U & VL_REDXOR_16(
                                                             (0x6000U 
                                                              & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                                           ? 9U : 3U))),4);
        bufp->chgCData(oldp+51,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
        bufp->chgBit(oldp+52,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+53,((0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)),7);
        bufp->chgBit(oldp+54,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
        bufp->chgBit(oldp+55,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgBit(oldp+56,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
        bufp->chgIData(oldp+58,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__instbridge)),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
        bufp->chgBit(oldp+62,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                  | ((0x17U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                     | (0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge))))));
        bufp->chgBit(oldp+63,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
        bufp->chgBit(oldp+64,(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__state));
        bufp->chgSData(oldp+65,((vlSelf->top__DOT__ifu0__DOT__instbridge 
                                 >> 0x14U)),12);
        bufp->chgBit(oldp+66,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__wbu0__DOT__memread),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__read_s),32);
        bufp->chgIData(oldp+70,((((- (IData)((1U & 
                                              (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                               >> 7U)))) 
                                  << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
        bufp->chgIData(oldp+71,((((- (IData)((1U & 
                                              (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                               >> 0xfU)))) 
                                  << 0x10U) | (0xffffU 
                                               & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
        bufp->chgCData(oldp+72,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),8);
        bufp->chgSData(oldp+73,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),16);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->top__DOT__imm))));
        __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                       >> 0x20U)));
        __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                    >> 0x1fU);
        bufp->chgWData(oldp+74,(__Vtemp_h44c198b2__0),66);
        bufp->chgQData(oldp+77,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+79,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
        bufp->chgWData(oldp+83,(__Vtemp_hdaf246d3__0),140);
        bufp->chgQData(oldp+88,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
        bufp->chgQData(oldp+90,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
        bufp->chgQData(oldp+92,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
        bufp->chgQData(oldp+94,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
        bufp->chgIData(oldp+96,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+97,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+98,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+99,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+100,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                 [2U]),32);
        bufp->chgIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                 [1U]),32);
        bufp->chgIData(oldp+103,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
        bufp->chgIData(oldp+104,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+106,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+111,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+112,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+113,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+114,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+115,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+118,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+119,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+120,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+121,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+122,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+123,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+125,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+126,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+135,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
        bufp->chgIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
        bufp->chgIData(oldp+137,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
        bufp->chgIData(oldp+138,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
        bufp->chgIData(oldp+139,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
        bufp->chgIData(oldp+140,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
        bufp->chgIData(oldp+141,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
        bufp->chgIData(oldp+142,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
        bufp->chgIData(oldp+143,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
        bufp->chgIData(oldp+144,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
        bufp->chgIData(oldp+145,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
        bufp->chgIData(oldp+146,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
        bufp->chgIData(oldp+147,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
        bufp->chgIData(oldp+148,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
        bufp->chgIData(oldp+149,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
        bufp->chgIData(oldp+150,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
        bufp->chgIData(oldp+152,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
        bufp->chgIData(oldp+153,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
        bufp->chgIData(oldp+154,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
        bufp->chgIData(oldp+155,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
        bufp->chgIData(oldp+156,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
        bufp->chgIData(oldp+157,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
        bufp->chgIData(oldp+158,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
        bufp->chgIData(oldp+160,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
        bufp->chgIData(oldp+161,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
        bufp->chgIData(oldp+162,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
        bufp->chgIData(oldp+163,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
        bufp->chgIData(oldp+164,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
        bufp->chgIData(oldp+165,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
        bufp->chgIData(oldp+166,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
        bufp->chgIData(oldp+167,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
        bufp->chgIData(oldp+168,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
        bufp->chgIData(oldp+169,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
        bufp->chgIData(oldp+170,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
        bufp->chgIData(oldp+171,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
        bufp->chgIData(oldp+172,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
        bufp->chgIData(oldp+173,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
        bufp->chgIData(oldp+174,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
        bufp->chgIData(oldp+175,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
        bufp->chgIData(oldp+176,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+177,((1U & (~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)))));
        bufp->chgBit(oldp+178,(vlSelf->top__DOT__csrrw));
        bufp->chgBit(oldp+179,(vlSelf->top__DOT__csrrs));
        bufp->chgCData(oldp+180,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
        bufp->chgCData(oldp+181,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
        bufp->chgBit(oldp+182,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
        bufp->chgBit(oldp+183,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+184,(vlSelf->top__DOT__npc),32);
        bufp->chgIData(oldp+185,(vlSelf->top__DOT__regwrite),32);
        bufp->chgIData(oldp+186,(vlSelf->top__DOT__regout1),32);
        bufp->chgIData(oldp+187,(vlSelf->top__DOT__regout2),32);
        bufp->chgIData(oldp+188,(vlSelf->top__DOT__res),32);
        bufp->chgIData(oldp+189,(vlSelf->top__DOT__pcwritereg),32);
        bufp->chgIData(oldp+190,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
        bufp->chgIData(oldp+191,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
        bufp->chgBit(oldp+192,((0U == vlSelf->top__DOT__res)));
        bufp->chgBit(oldp+193,((vlSelf->top__DOT__res 
                                >> 0x1fU)));
        bufp->chgBit(oldp+194,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
        bufp->chgIData(oldp+195,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
        bufp->chgIData(oldp+196,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
        bufp->chgBit(oldp+197,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
        bufp->chgIData(oldp+198,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
        bufp->chgIData(oldp+199,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
        bufp->chgIData(oldp+200,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
        bufp->chgIData(oldp+201,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
        bufp->chgIData(oldp+202,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+203,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    }
    bufp->chgBit(oldp+204,(vlSelf->clk));
    bufp->chgBit(oldp+205,(vlSelf->rst));
    bufp->chgBit(oldp+206,(((0U == vlSelf->top__DOT__ifu0__DOT__instbridge) 
                            & (~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)))));
    bufp->chgIData(oldp+207,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                              & (0U != vlSelf->top__DOT__ifu0__DOT__instbridge))),32);
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
