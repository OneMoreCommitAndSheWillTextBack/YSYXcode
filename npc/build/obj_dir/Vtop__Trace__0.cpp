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
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__memmask),3);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
        bufp->chgCData(oldp+14,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
        bufp->chgCData(oldp+15,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__lut_out),3);
        bufp->chgBit(oldp+16,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__hit));
        bufp->chgSData(oldp+17,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
        bufp->chgSData(oldp+18,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
        bufp->chgSData(oldp+19,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
        bufp->chgSData(oldp+20,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
        bufp->chgSData(oldp+21,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
        bufp->chgSData(oldp+22,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
        bufp->chgSData(oldp+23,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
        bufp->chgSData(oldp+24,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
        bufp->chgCData(oldp+25,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
        bufp->chgCData(oldp+26,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
        bufp->chgCData(oldp+27,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
        bufp->chgCData(oldp+28,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
        bufp->chgCData(oldp+29,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
        bufp->chgCData(oldp+30,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
        bufp->chgCData(oldp+31,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
        bufp->chgCData(oldp+32,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
        bufp->chgCData(oldp+33,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+34,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+35,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
        bufp->chgCData(oldp+36,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
        bufp->chgCData(oldp+37,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
        bufp->chgCData(oldp+38,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
        bufp->chgCData(oldp+39,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
        bufp->chgCData(oldp+40,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
        bufp->chgCData(oldp+41,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
        bufp->chgCData(oldp+42,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
        bufp->chgCData(oldp+43,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
        bufp->chgCData(oldp+44,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg),32);
        bufp->chgBit(oldp+46,((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
        bufp->chgCData(oldp+47,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+48,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+49,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                          >> 7U))),5);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__imm),32);
        bufp->chgBit(oldp+51,((0x100073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
        bufp->chgBit(oldp+52,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
        bufp->chgBit(oldp+53,((0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
        bufp->chgBit(oldp+54,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                               | ((0x33U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                        | (3U == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))))));
        bufp->chgBit(oldp+55,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgBit(oldp+56,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgBit(oldp+57,(vlSelf->top__DOT__muximm));
        bufp->chgCData(oldp+58,((7U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+59,(vlSelf->top__DOT__muxsig),3);
        bufp->chgBit(oldp+60,((1U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                     >> 0x1eU))));
        bufp->chgBit(oldp+61,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgBit(oldp+62,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgBit(oldp+63,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgBit(oldp+64,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgCData(oldp+65,(vlSelf->top__DOT__aluop),2);
        bufp->chgCData(oldp+66,(vlSelf->top__DOT__memmask),3);
        bufp->chgBit(oldp+67,(vlSelf->top__DOT__memsextsig));
        bufp->chgCData(oldp+68,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
        bufp->chgBit(oldp+69,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
        bufp->chgBit(oldp+70,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
        bufp->chgBit(oldp+71,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
        bufp->chgBit(oldp+72,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
        bufp->chgBit(oldp+73,((1U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+74,((3U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+75,((2U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+76,((0U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgCData(oldp+77,(((IData)((0x6000U == 
                                          (0x6000U 
                                           & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                                  ? 8U : ((1U & VL_REDXOR_16(
                                                             (0x6000U 
                                                              & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                                           ? 9U : 3U))),4);
        bufp->chgCData(oldp+78,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
        bufp->chgBit(oldp+79,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+80,((0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),7);
        bufp->chgBit(oldp+81,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
        bufp->chgBit(oldp+82,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgBit(oldp+83,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
        bufp->chgIData(oldp+84,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
        bufp->chgIData(oldp+85,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),32);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
        bufp->chgIData(oldp+87,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
        bufp->chgBit(oldp+89,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                  | ((0x17U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                     | (0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))));
        bufp->chgBit(oldp+90,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
        bufp->chgBit(oldp+91,((0U == (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state))));
        bufp->chgCData(oldp+92,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state),2);
        bufp->chgCData(oldp+93,((0xfU & (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num))),4);
        bufp->chgCData(oldp+94,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__random_count),4);
        bufp->chgCData(oldp+95,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num),8);
        bufp->chgBit(oldp+96,((1U & VL_REDXOR_8((0xb8U 
                                                 & (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num))))));
        bufp->chgSData(oldp+97,((vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                 >> 0x14U)),12);
        bufp->chgBit(oldp+98,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+99,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg),32);
        bufp->chgIData(oldp+100,(vlSelf->top__DOT__wbu0__DOT__memread),32);
        bufp->chgCData(oldp+101,(vlSelf->top__DOT__wbu0__DOT__wstrb),4);
        bufp->chgBit(oldp+102,((0U == (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state))));
        bufp->chgCData(oldp+103,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state),2);
        bufp->chgCData(oldp+104,((0xfU & (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num))),4);
        bufp->chgCData(oldp+105,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__random_count),4);
        bufp->chgCData(oldp+106,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__memmask),3);
        bufp->chgCData(oldp+107,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num),8);
        bufp->chgBit(oldp+108,((1U & VL_REDXOR_8((0xb8U 
                                                  & (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num))))));
        bufp->chgCData(oldp+109,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__lut_out),3);
        bufp->chgBit(oldp+110,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+111,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
        bufp->chgIData(oldp+112,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
        bufp->chgIData(oldp+113,((((- (IData)((1U & 
                                               (vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg 
                                                >> 7U)))) 
                                   << 8U) | (0xffU 
                                             & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg))),32);
        bufp->chgIData(oldp+114,((((- (IData)((1U & 
                                               (vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg 
                                                >> 0xfU)))) 
                                   << 0x10U) | (0xffffU 
                                                & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg))),32);
        bufp->chgCData(oldp+115,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg)),8);
        bufp->chgSData(oldp+116,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg)),16);
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
        bufp->chgWData(oldp+117,(__Vtemp_h44c198b2__0),66);
        bufp->chgQData(oldp+120,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+122,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+125,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
        bufp->chgWData(oldp+126,(__Vtemp_hdaf246d3__0),140);
        bufp->chgQData(oldp+131,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
        bufp->chgQData(oldp+133,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
        bufp->chgQData(oldp+135,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
        bufp->chgQData(oldp+137,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
        bufp->chgIData(oldp+139,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+140,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+141,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+142,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+143,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
        bufp->chgIData(oldp+144,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                 [2U]),32);
        bufp->chgIData(oldp+145,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                 [1U]),32);
        bufp->chgIData(oldp+146,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
        bufp->chgIData(oldp+147,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+148,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+149,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+150,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+152,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+153,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+154,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+155,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+156,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+157,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+158,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+160,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+161,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+162,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+163,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+164,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+165,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+166,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+167,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+168,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+169,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+170,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+171,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+172,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+173,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+174,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+175,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+176,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+177,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+178,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
        bufp->chgIData(oldp+179,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
        bufp->chgIData(oldp+180,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
        bufp->chgIData(oldp+181,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
        bufp->chgIData(oldp+182,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
        bufp->chgIData(oldp+183,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
        bufp->chgIData(oldp+184,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
        bufp->chgIData(oldp+185,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
        bufp->chgIData(oldp+186,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
        bufp->chgIData(oldp+187,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
        bufp->chgIData(oldp+188,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
        bufp->chgIData(oldp+189,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
        bufp->chgIData(oldp+190,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
        bufp->chgIData(oldp+191,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
        bufp->chgIData(oldp+192,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
        bufp->chgIData(oldp+193,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
        bufp->chgIData(oldp+194,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
        bufp->chgIData(oldp+195,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
        bufp->chgIData(oldp+196,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
        bufp->chgIData(oldp+197,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
        bufp->chgIData(oldp+198,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
        bufp->chgIData(oldp+199,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
        bufp->chgIData(oldp+200,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
        bufp->chgIData(oldp+201,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
        bufp->chgIData(oldp+202,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
        bufp->chgIData(oldp+203,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
        bufp->chgIData(oldp+204,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
        bufp->chgIData(oldp+205,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
        bufp->chgIData(oldp+206,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
        bufp->chgIData(oldp+207,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
        bufp->chgIData(oldp+208,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
        bufp->chgIData(oldp+209,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
        bufp->chgIData(oldp+210,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
        bufp->chgIData(oldp+211,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
        bufp->chgIData(oldp+212,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
        bufp->chgIData(oldp+213,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
        bufp->chgIData(oldp+214,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
        bufp->chgIData(oldp+215,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
        bufp->chgIData(oldp+216,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
        bufp->chgIData(oldp+217,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
        bufp->chgIData(oldp+218,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
        bufp->chgIData(oldp+219,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+220,(vlSelf->top__DOT__ready_idu_to_ifu));
        bufp->chgBit(oldp+221,(vlSelf->top__DOT__csrrw));
        bufp->chgBit(oldp+222,(vlSelf->top__DOT__csrrs));
        bufp->chgCData(oldp+223,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
        bufp->chgCData(oldp+224,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
        bufp->chgBit(oldp+225,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+226,(vlSelf->top__DOT__npc),32);
        bufp->chgIData(oldp+227,(vlSelf->top__DOT__regwrite),32);
        bufp->chgIData(oldp+228,(vlSelf->top__DOT__regout1),32);
        bufp->chgIData(oldp+229,(vlSelf->top__DOT__regout2),32);
        bufp->chgIData(oldp+230,(vlSelf->top__DOT__res),32);
        bufp->chgIData(oldp+231,(vlSelf->top__DOT__pcwritereg),32);
        bufp->chgIData(oldp+232,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
        bufp->chgIData(oldp+233,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
        bufp->chgBit(oldp+234,((0U == vlSelf->top__DOT__res)));
        bufp->chgBit(oldp+235,((vlSelf->top__DOT__res 
                                >> 0x1fU)));
        bufp->chgBit(oldp+236,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
        bufp->chgIData(oldp+237,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
        bufp->chgIData(oldp+238,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
        bufp->chgBit(oldp+239,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
        bufp->chgIData(oldp+240,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
        bufp->chgIData(oldp+241,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
        bufp->chgIData(oldp+242,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
        bufp->chgIData(oldp+243,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
        bufp->chgIData(oldp+244,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+245,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    }
    bufp->chgBit(oldp+246,(vlSelf->clk));
    bufp->chgBit(oldp+247,(vlSelf->rst));
    bufp->chgBit(oldp+248,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                            & (0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->chgBit(oldp+249,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                            & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                               | ((0x33U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                        | (3U == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))))))));
    bufp->chgIData(oldp+250,(((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg) 
                              & (IData)(vlSelf->top__DOT__ready_idu_to_ifu))),32);
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
