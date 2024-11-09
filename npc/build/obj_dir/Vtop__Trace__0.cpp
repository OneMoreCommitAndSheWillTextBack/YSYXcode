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
    VlWide<5>/*159:0*/ __Vtemp_h999ddfee__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[1]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[2]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[3]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[4]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[5]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[6]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[7]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[8]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[9]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[10]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[11]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[12]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[13]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[14]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[15]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[16]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[17]),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[18]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[19]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[20]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[21]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[22]),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[23]),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[24]),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[25]),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[26]),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[27]),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[28]),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[29]),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[30]),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[31]),32);
        bufp->chgIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+71,(vlSelf->top__DOT__mem0__DOT__readreg),32);
        bufp->chgIData(oldp+72,((((- (IData)((1U & 
                                              (vlSelf->top__DOT__mem0__DOT__readreg 
                                               >> 7U)))) 
                                  << 8U) | (0xffU & vlSelf->top__DOT__mem0__DOT__readreg))),32);
        bufp->chgIData(oldp+73,((((- (IData)((1U & 
                                              (vlSelf->top__DOT__mem0__DOT__readreg 
                                               >> 0xfU)))) 
                                  << 0x10U) | (0xffffU 
                                               & vlSelf->top__DOT__mem0__DOT__readreg))),32);
        bufp->chgCData(oldp+74,((0xffU & vlSelf->top__DOT__mem0__DOT__readreg)),8);
        bufp->chgSData(oldp+75,((0xffffU & vlSelf->top__DOT__mem0__DOT__readreg)),16);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+76,(vlSelf->top__DOT__infetch0__DOT__reg_inst),32);
        bufp->chgCData(oldp+77,((0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)),7);
        bufp->chgCData(oldp+78,((7U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+79,((1U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                     >> 0x1eU))));
        bufp->chgCData(oldp+80,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+81,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+82,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                          >> 7U))),5);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__imm),32);
        bufp->chgBit(oldp+84,(vlSelf->top__DOT__regew));
        bufp->chgBit(oldp+85,((0x23U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgBit(oldp+86,((3U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgBit(oldp+87,(vlSelf->top__DOT__muximm));
        bufp->chgCData(oldp+88,(vlSelf->top__DOT__muxsig),3);
        bufp->chgBit(oldp+89,((0x63U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgBit(oldp+90,((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgBit(oldp+91,((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgBit(oldp+92,((0x17U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgCData(oldp+93,(vlSelf->top__DOT__aluop),2);
        bufp->chgCData(oldp+94,(vlSelf->top__DOT__aluopcode),4);
        bufp->chgBit(oldp+95,((1U & (~ (IData)(vlSelf->top__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
        bufp->chgBit(oldp+96,(vlSelf->top__DOT__alu0__DOT__logsig));
        bufp->chgBit(oldp+97,(vlSelf->top__DOT__alu0__DOT__shfsig));
        bufp->chgBit(oldp+98,(vlSelf->top__DOT__alu0__DOT__sltsig));
        bufp->chgBit(oldp+99,((1U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+100,((3U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+101,((2U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+102,((0U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgCData(oldp+103,(((IData)((0x6000U 
                                           == (0x6000U 
                                               & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                                   ? 8U : ((1U & VL_REDXOR_16(
                                                              (0x6000U 
                                                               & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                                            ? 9U : 3U))),4);
        bufp->chgCData(oldp+104,(vlSelf->top__DOT__alucontrol0__DOT__IRop),4);
        bufp->chgBit(oldp+105,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+106,(vlSelf->top__DOT__decoder0__DOT__type_I));
        bufp->chgBit(oldp+107,((0x33U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgBit(oldp+108,(vlSelf->top__DOT__decoder0__DOT__type_U));
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__decoder0__DOT__I_imm),32);
        bufp->chgIData(oldp+110,((0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst)),32);
        bufp->chgIData(oldp+111,(vlSelf->top__DOT__decoder0__DOT__S_imm),32);
        bufp->chgIData(oldp+112,(vlSelf->top__DOT__decoder0__DOT__J_imm),32);
        bufp->chgIData(oldp+113,(vlSelf->top__DOT__decoder0__DOT__B_imm),32);
        bufp->chgBit(oldp+114,((IData)((0x73U == (0x707fU 
                                                  & vlSelf->top__DOT__infetch0__DOT__reg_inst)))));
        bufp->chgBit(oldp+115,(((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                   | (0x17U == (0x7fU 
                                                & vlSelf->top__DOT__infetch0__DOT__reg_inst))))));
        bufp->chgBit(oldp+116,((0x37U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
        bufp->chgCData(oldp+117,(vlSelf->top__DOT__mem0__DOT__len),3);
        bufp->chgBit(oldp+118,(vlSelf->top__DOT__mem0__DOT__signalsig));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
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
        bufp->chgWData(oldp+119,(__Vtemp_h44c198b2__0),66);
        bufp->chgQData(oldp+122,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+124,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+126,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+127,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    }
    if (VL_UNLIKELY((((vlSelf->__Vm_traceActivity[3U] 
                       | vlSelf->__Vm_traceActivity
                       [4U]) | vlSelf->__Vm_traceActivity
                      [5U]) | vlSelf->__Vm_traceActivity
                     [6U]))) {
        __Vtemp_h999ddfee__0[0U] = (IData)((0x400000000ULL 
                                            | (QData)((IData)(vlSelf->top__DOT__pcwritereg))));
        __Vtemp_h999ddfee__0[1U] = ((vlSelf->top__DOT__imm 
                                     << 3U) | (IData)(
                                                      ((0x400000000ULL 
                                                        | (QData)((IData)(vlSelf->top__DOT__pcwritereg))) 
                                                       >> 0x20U)));
        __Vtemp_h999ddfee__0[2U] = (0x10U | ((vlSelf->top__DOT__memread 
                                              << 6U) 
                                             | (vlSelf->top__DOT__imm 
                                                >> 0x1dU)));
        __Vtemp_h999ddfee__0[3U] = (0x40U | ((vlSelf->top__DOT__res 
                                              << 9U) 
                                             | (vlSelf->top__DOT__memread 
                                                >> 0x1aU)));
        __Vtemp_h999ddfee__0[4U] = (vlSelf->top__DOT__res 
                                    >> 0x17U);
        bufp->chgWData(oldp+128,(__Vtemp_h999ddfee__0),140);
        bufp->chgQData(oldp+133,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
        bufp->chgQData(oldp+135,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
        bufp->chgQData(oldp+137,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
        bufp->chgQData(oldp+139,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
        bufp->chgIData(oldp+141,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+142,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+143,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+144,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+145,(vlSelf->top__DOT__alu0__DOT__A_s),32);
        bufp->chgIData(oldp+146,(vlSelf->top__DOT__regout2),32);
        bufp->chgIData(oldp+147,(vlSelf->top__DOT__aluarg2),32);
        bufp->chgBit(oldp+148,((0U == vlSelf->top__DOT__res)));
        bufp->chgBit(oldp+149,((vlSelf->top__DOT__res 
                                >> 0x1fU)));
        bufp->chgBit(oldp+150,(vlSelf->top__DOT__carry));
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__res),32);
        bufp->chgIData(oldp+152,(vlSelf->top__DOT__alu0__DOT__logres),32);
        bufp->chgIData(oldp+153,(vlSelf->top__DOT__alu0__DOT__addres),32);
        bufp->chgBit(oldp+154,((0U == vlSelf->top__DOT__alu0__DOT__addres)));
        bufp->chgIData(oldp+155,(vlSelf->top__DOT__alu0__DOT__shfres),32);
        bufp->chgIData(oldp+156,(vlSelf->top__DOT__alu0__DOT__sltres),32);
        bufp->chgIData(oldp+157,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        bufp->chgIData(oldp+158,(vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp),32);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__pcaddimmbridge),32);
        bufp->chgIData(oldp+160,(vlSelf->top__DOT__pcwritereg),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[7U])) {
        bufp->chgIData(oldp+161,(vlSelf->top__DOT__regwrite),32);
        bufp->chgIData(oldp+162,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+163,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit));
    }
    bufp->chgBit(oldp+164,(vlSelf->clk));
    bufp->chgBit(oldp+165,(vlSelf->rst));
    bufp->chgIData(oldp+166,(vlSelf->top__DOT__pcbridge),32);
    bufp->chgIData(oldp+167,(((IData)(4U) + vlSelf->top__DOT__pcbridge)),32);
    bufp->chgIData(oldp+168,(vlSelf->top__DOT__memread),32);
    bufp->chgIData(oldp+169,(vlSelf->top__DOT__mem0__DOT__read_s),32);
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
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
