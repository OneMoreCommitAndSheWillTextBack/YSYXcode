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
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
        bufp->chgBit(oldp+12,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+13,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
        bufp->chgSData(oldp+14,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
        bufp->chgSData(oldp+15,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
        bufp->chgSData(oldp+16,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
        bufp->chgSData(oldp+17,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
        bufp->chgSData(oldp+18,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
        bufp->chgSData(oldp+19,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
        bufp->chgSData(oldp+20,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
        bufp->chgSData(oldp+21,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
        bufp->chgCData(oldp+22,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
        bufp->chgCData(oldp+23,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
        bufp->chgCData(oldp+24,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
        bufp->chgCData(oldp+25,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
        bufp->chgCData(oldp+26,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
        bufp->chgCData(oldp+27,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
        bufp->chgCData(oldp+28,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
        bufp->chgCData(oldp+29,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+30,((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state))));
        bufp->chgCData(oldp+31,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                 & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram))))),2);
        bufp->chgBit(oldp+32,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy));
        bufp->chgCData(oldp+33,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant),2);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__i),32);
        bufp->chgCData(oldp+35,((0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))),4);
        bufp->chgBit(oldp+36,(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy));
        bufp->chgCData(oldp+37,(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count),4);
        bufp->chgCData(oldp+38,(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num),8);
        bufp->chgBit(oldp+39,((1U & VL_REDXOR_8((0xb8U 
                                                 & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))))));
        bufp->chgCData(oldp+40,(vlSelf->top__DOT__ifu0__DOT__state),2);
        bufp->chgBit(oldp+41,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                      & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram)))) 
                                     >> 1U))));
        bufp->chgBit(oldp+42,(vlSelf->top__DOT__wbu0__DOT__bresp_get));
        bufp->chgBit(oldp+43,(vlSelf->top__DOT__wbu0__DOT__rvalid_get));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+44,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                               & ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                  & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))));
        bufp->chgCData(oldp+45,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                 & (- (IData)(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                               & (0U 
                                                  == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))))),2);
        bufp->chgBit(oldp+46,((0U != ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                      & (((3U == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                          << 1U) | (IData)(vlSelf->top__DOT__ready_idu_to_ifu))))));
        bufp->chgBit(oldp+47,((0U != (((0x23U == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                       << 1U) & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant)))));
        bufp->chgBit(oldp+48,(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                               & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
        bufp->chgBit(oldp+49,((((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state)) 
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
        bufp->chgBit(oldp+50,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                      & (- (IData)(
                                                   ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                                    & (0U 
                                                       == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))))) 
                                     >> 1U))));
        bufp->chgBit(oldp+51,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__rvalid_get)) 
                               & (3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                [2U]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__regfile__DOT__rf_csr
                                [1U]),32);
        bufp->chgIData(oldp+55,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
        bufp->chgIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
        bufp->chgIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
        bufp->chgIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
        bufp->chgIData(oldp+92,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
        bufp->chgIData(oldp+93,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
        bufp->chgIData(oldp+94,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
        bufp->chgIData(oldp+95,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
        bufp->chgIData(oldp+96,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
        bufp->chgIData(oldp+97,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
        bufp->chgIData(oldp+98,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
        bufp->chgIData(oldp+99,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
        bufp->chgIData(oldp+100,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
        bufp->chgIData(oldp+102,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
        bufp->chgIData(oldp+103,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
        bufp->chgIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
        bufp->chgIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
        bufp->chgIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
        bufp->chgIData(oldp+107,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
        bufp->chgIData(oldp+108,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
        bufp->chgIData(oldp+110,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
        bufp->chgIData(oldp+111,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
        bufp->chgIData(oldp+112,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
        bufp->chgIData(oldp+113,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
        bufp->chgIData(oldp+114,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
        bufp->chgIData(oldp+115,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
        bufp->chgIData(oldp+118,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
        bufp->chgIData(oldp+119,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
        bufp->chgIData(oldp+120,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
        bufp->chgIData(oldp+121,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
        bufp->chgIData(oldp+122,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
        bufp->chgIData(oldp+123,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
        bufp->chgIData(oldp+125,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
        bufp->chgIData(oldp+126,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
        bufp->chgIData(oldp+127,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
        bufp->chgIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+129,(vlSelf->top__DOT__ready_idu_to_ifu));
        bufp->chgIData(oldp+130,(vlSelf->top__DOT__ifu0__DOT__inst_reg),32);
        bufp->chgBit(oldp+131,(vlSelf->top__DOT__ifu_valid));
        bufp->chgBit(oldp+132,((1U & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
        bufp->chgCData(oldp+133,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+134,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+135,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                           >> 7U))),5);
        bufp->chgIData(oldp+136,(vlSelf->top__DOT__imm),32);
        bufp->chgBit(oldp+137,((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
        bufp->chgBit(oldp+138,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
        bufp->chgBit(oldp+139,((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
        bufp->chgBit(oldp+140,(((3U != (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                   | ((0x33U == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | ((0x6fU == 
                                          (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                         | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))));
        bufp->chgBit(oldp+141,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+142,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+143,(vlSelf->top__DOT__muximm));
        bufp->chgCData(oldp+144,((7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+145,(vlSelf->top__DOT__muxsig),3);
        bufp->chgBit(oldp+146,((1U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                      >> 0x1eU))));
        bufp->chgBit(oldp+147,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+148,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+149,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+150,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgCData(oldp+151,(vlSelf->top__DOT__aluop),2);
        bufp->chgBit(oldp+152,(vlSelf->top__DOT__csrrw));
        bufp->chgBit(oldp+153,(vlSelf->top__DOT__csrrs));
        bufp->chgCData(oldp+154,(vlSelf->top__DOT__memmask),3);
        bufp->chgBit(oldp+155,(vlSelf->top__DOT__memsextsig));
        bufp->chgBit(oldp+156,(((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U))));
        bufp->chgCData(oldp+157,(((IData)(vlSelf->top__DOT____Vcellout__wbu0__awvalid) 
                                  << 1U)),2);
        bufp->chgCData(oldp+158,(vlSelf->top__DOT__data0__DOT__arvalid_in),2);
        bufp->chgCData(oldp+159,((((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   << 1U) | (IData)(vlSelf->top__DOT__ready_idu_to_ifu))),2);
        bufp->chgCData(oldp+160,(((0x23U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                  << 1U)),2);
        bufp->chgCData(oldp+161,(vlSelf->top__DOT__data0__DOT__rvalid_out),2);
        bufp->chgCData(oldp+162,(vlSelf->top__DOT__wstrb[0]),4);
        bufp->chgCData(oldp+163,(vlSelf->top__DOT__wstrb[1]),4);
        bufp->chgBit(oldp+164,(vlSelf->top__DOT__bresp[0]));
        bufp->chgBit(oldp+165,(vlSelf->top__DOT__bresp[1]));
        bufp->chgCData(oldp+166,(vlSelf->top__DOT____Vcellinp__data0__wstrb[0]),4);
        bufp->chgCData(oldp+167,(vlSelf->top__DOT____Vcellinp__data0__wstrb[1]),4);
        bufp->chgBit(oldp+168,(vlSelf->top__DOT____Vcellout__data0__bresp[0]));
        bufp->chgBit(oldp+169,(vlSelf->top__DOT____Vcellout__data0__bresp[1]));
        bufp->chgBit(oldp+170,(vlSelf->top__DOT__data0__DOT__awvalid_sram));
        bufp->chgBit(oldp+171,(vlSelf->top__DOT__data0__DOT__wvalid_sram));
        bufp->chgBit(oldp+172,(vlSelf->top__DOT__data0__DOT__arvalid_sram));
        bufp->chgBit(oldp+173,((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
        bufp->chgCData(oldp+174,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg),4);
        bufp->chgBit(oldp+175,((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
        bufp->chgCData(oldp+176,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0]),4);
        bufp->chgCData(oldp+177,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1]),4);
        bufp->chgBit(oldp+178,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0]));
        bufp->chgBit(oldp+179,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[1]));
        bufp->chgCData(oldp+180,(vlSelf->top__DOT__data0__DOT__mem0__DOT__state),2);
        bufp->chgCData(oldp+181,(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask),3);
        bufp->chgCData(oldp+182,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out),3);
        bufp->chgBit(oldp+183,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+184,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
        bufp->chgBit(oldp+185,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
        bufp->chgBit(oldp+186,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
        bufp->chgBit(oldp+187,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
        bufp->chgBit(oldp+188,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
        bufp->chgBit(oldp+189,((1U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+190,((3U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+191,((2U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgBit(oldp+192,((0U == (IData)(vlSelf->top__DOT__aluop))));
        bufp->chgCData(oldp+193,(((IData)((0x6000U 
                                           == (0x6000U 
                                               & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                   ? 8U : ((1U & VL_REDXOR_16(
                                                              (0x6000U 
                                                               & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                            ? 9U : 3U))),4);
        bufp->chgCData(oldp+194,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
        bufp->chgBit(oldp+195,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+196,((0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)),7);
        bufp->chgBit(oldp+197,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
        bufp->chgBit(oldp+198,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgBit(oldp+199,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
        bufp->chgIData(oldp+200,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
        bufp->chgIData(oldp+201,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)),32);
        bufp->chgIData(oldp+202,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
        bufp->chgIData(oldp+203,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
        bufp->chgIData(oldp+204,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
        bufp->chgBit(oldp+205,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x17U == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
        bufp->chgBit(oldp+206,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
        bufp->chgSData(oldp+207,((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                  >> 0x14U)),12);
        bufp->chgCData(oldp+208,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
        bufp->chgCData(oldp+209,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
        bufp->chgBit(oldp+210,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+211,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
        bufp->chgBit(oldp+212,(vlSelf->top__DOT____Vcellout__wbu0__awvalid));
        bufp->chgCData(oldp+213,(((1U == (IData)(vlSelf->top__DOT__memmask))
                                   ? 1U : ((2U == (IData)(vlSelf->top__DOT__memmask))
                                            ? 2U : 
                                           ((3U == (IData)(vlSelf->top__DOT__memmask))
                                             ? 4U : 
                                            ((4U == (IData)(vlSelf->top__DOT__memmask))
                                              ? 8U : 0U))))),4);
        bufp->chgBit(oldp+214,(vlSelf->top__DOT__bresp
                               [1U]));
        bufp->chgBit(oldp+215,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                      >> 1U))));
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
        bufp->chgWData(oldp+216,(__Vtemp_h44c198b2__0),66);
        bufp->chgQData(oldp+219,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+221,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+223,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+224,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
        bufp->chgWData(oldp+225,(__Vtemp_hdaf246d3__0),140);
        bufp->chgQData(oldp+230,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
        bufp->chgQData(oldp+232,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
        bufp->chgQData(oldp+234,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
        bufp->chgQData(oldp+236,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
        bufp->chgIData(oldp+238,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+239,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+240,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+241,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+242,(vlSelf->top__DOT__npc),32);
        bufp->chgIData(oldp+243,(vlSelf->top__DOT__rdata
                                 [0U]),32);
        bufp->chgIData(oldp+244,(vlSelf->top__DOT__regwrite),32);
        bufp->chgIData(oldp+245,(vlSelf->top__DOT__regout1),32);
        bufp->chgIData(oldp+246,(vlSelf->top__DOT__regout2),32);
        bufp->chgIData(oldp+247,(vlSelf->top__DOT__res),32);
        bufp->chgIData(oldp+248,(vlSelf->top__DOT__pcwritereg),32);
        bufp->chgIData(oldp+249,(vlSelf->top__DOT__araddr[0]),32);
        bufp->chgIData(oldp+250,(vlSelf->top__DOT__araddr[1]),32);
        bufp->chgIData(oldp+251,(vlSelf->top__DOT__rdata[0]),32);
        bufp->chgIData(oldp+252,(vlSelf->top__DOT__rdata[1]),32);
        bufp->chgIData(oldp+253,(vlSelf->top__DOT__awaddr[0]),32);
        bufp->chgIData(oldp+254,(vlSelf->top__DOT__awaddr[1]),32);
        bufp->chgIData(oldp+255,(vlSelf->top__DOT__wdata[0]),32);
        bufp->chgIData(oldp+256,(vlSelf->top__DOT__wdata[1]),32);
        bufp->chgIData(oldp+257,(vlSelf->top__DOT____Vcellinp__data0__araddr[0]),32);
        bufp->chgIData(oldp+258,(vlSelf->top__DOT____Vcellinp__data0__araddr[1]),32);
        bufp->chgIData(oldp+259,(vlSelf->top__DOT____Vcellout__data0__rdata[0]),32);
        bufp->chgIData(oldp+260,(vlSelf->top__DOT____Vcellout__data0__rdata[1]),32);
        bufp->chgIData(oldp+261,(vlSelf->top__DOT____Vcellinp__data0__awaddr[0]),32);
        bufp->chgIData(oldp+262,(vlSelf->top__DOT____Vcellinp__data0__awaddr[1]),32);
        bufp->chgIData(oldp+263,(vlSelf->top__DOT____Vcellinp__data0__wdata[0]),32);
        bufp->chgIData(oldp+264,(vlSelf->top__DOT____Vcellinp__data0__wdata[1]),32);
        bufp->chgIData(oldp+265,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg),32);
        bufp->chgIData(oldp+266,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg),32);
        bufp->chgIData(oldp+267,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg),32);
        bufp->chgIData(oldp+268,(vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg),32);
        bufp->chgIData(oldp+269,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0]),32);
        bufp->chgIData(oldp+270,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1]),32);
        bufp->chgIData(oldp+271,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0]),32);
        bufp->chgIData(oldp+272,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1]),32);
        bufp->chgIData(oldp+273,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0]),32);
        bufp->chgIData(oldp+274,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1]),32);
        bufp->chgIData(oldp+275,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0]),32);
        bufp->chgIData(oldp+276,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[1]),32);
        bufp->chgIData(oldp+277,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
        bufp->chgIData(oldp+278,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
        bufp->chgBit(oldp+279,((0U == vlSelf->top__DOT__res)));
        bufp->chgBit(oldp+280,((vlSelf->top__DOT__res 
                                >> 0x1fU)));
        bufp->chgBit(oldp+281,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
        bufp->chgIData(oldp+282,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
        bufp->chgIData(oldp+283,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
        bufp->chgBit(oldp+284,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
        bufp->chgIData(oldp+285,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
        bufp->chgIData(oldp+286,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
        bufp->chgIData(oldp+287,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
        bufp->chgIData(oldp+288,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
        bufp->chgIData(oldp+289,(vlSelf->top__DOT__rdata
                                 [1U]),32);
        bufp->chgIData(oldp+290,(vlSelf->top__DOT__wbu0__DOT__memread),32);
        bufp->chgIData(oldp+291,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
        bufp->chgIData(oldp+292,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
        bufp->chgIData(oldp+293,((((- (IData)((1U & 
                                               (vlSelf->top__DOT__rdata
                                                [1U] 
                                                >> 7U)))) 
                                   << 8U) | (0xffU 
                                             & vlSelf->top__DOT__rdata
                                             [1U]))),32);
        bufp->chgIData(oldp+294,((((- (IData)((1U & 
                                               (vlSelf->top__DOT__rdata
                                                [1U] 
                                                >> 0xfU)))) 
                                   << 0x10U) | (0xffffU 
                                                & vlSelf->top__DOT__rdata
                                                [1U]))),32);
        bufp->chgCData(oldp+295,((0xffU & vlSelf->top__DOT__rdata
                                  [1U])),8);
        bufp->chgSData(oldp+296,((0xffffU & vlSelf->top__DOT__rdata
                                  [1U])),16);
        bufp->chgIData(oldp+297,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+298,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    }
    bufp->chgBit(oldp+299,(vlSelf->clk));
    bufp->chgBit(oldp+300,(vlSelf->rst));
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
