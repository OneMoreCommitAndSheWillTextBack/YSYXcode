// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+165,"clk", false,-1);
    tracep->declBit(c+166,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+165,"clk", false,-1);
    tracep->declBit(c+166,"rst", false,-1);
    tracep->declBus(c+159,"npc", false,-1, 31,0);
    tracep->declBus(c+167,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+77,"inst", false,-1, 31,0);
    tracep->declBus(c+78,"opcode", false,-1, 6,0);
    tracep->declBus(c+79,"func3_decoder", false,-1, 2,0);
    tracep->declBit(c+80,"func7_decoder", false,-1);
    tracep->declBus(c+81,"src1", false,-1, 4,0);
    tracep->declBus(c+82,"src2", false,-1, 4,0);
    tracep->declBus(c+83,"rd", false,-1, 4,0);
    tracep->declBus(c+84,"imm", false,-1, 31,0);
    tracep->declBit(c+85,"regew", false,-1);
    tracep->declBit(c+86,"memew", false,-1);
    tracep->declBit(c+87,"memer", false,-1);
    tracep->declBit(c+88,"muximm", false,-1);
    tracep->declBus(c+79,"func3_maincontrol", false,-1, 2,0);
    tracep->declBus(c+89,"muxsig", false,-1, 2,0);
    tracep->declBit(c+80,"func7_maincontrol", false,-1);
    tracep->declBit(c+90,"btypebranch", false,-1);
    tracep->declBit(c+91,"jalsig", false,-1);
    tracep->declBit(c+92,"jalrsig", false,-1);
    tracep->declBit(c+93,"auipcsig", false,-1);
    tracep->declBus(c+94,"aluop", false,-1, 1,0);
    tracep->declBus(c+162,"regwrite", false,-1, 31,0);
    tracep->declBus(c+146,"regout1", false,-1, 31,0);
    tracep->declBus(c+147,"regout2", false,-1, 31,0);
    tracep->declBus(c+95,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+168,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+160,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+148,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+149,"zero", false,-1);
    tracep->declBit(c+150,"signal", false,-1);
    tracep->declBit(c+151,"carry", false,-1);
    tracep->declBus(c+152,"res", false,-1, 31,0);
    tracep->declBus(c+161,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+169,"memread", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+146,"A", false,-1, 31,0);
    tracep->declBus(c+148,"B", false,-1, 31,0);
    tracep->declBus(c+95,"op", false,-1, 4,0);
    tracep->declBus(c+152,"res", false,-1, 31,0);
    tracep->declBit(c+149,"zero", false,-1);
    tracep->declBit(c+150,"signal", false,-1);
    tracep->declBit(c+151,"carry", false,-1);
    tracep->declBit(c+96,"addsig", false,-1);
    tracep->declBit(c+97,"logsig", false,-1);
    tracep->declBit(c+98,"shfsig", false,-1);
    tracep->declBit(c+99,"sltsig", false,-1);
    tracep->declBit(c+151,"carry_tmp", false,-1);
    tracep->declBit(c+100,"type_I", false,-1);
    tracep->declBus(c+153,"logres", false,-1, 31,0);
    tracep->declBus(c+154,"addres", false,-1, 31,0);
    tracep->declBit(c+155,"addzero", false,-1);
    tracep->declBus(c+156,"shfres", false,-1, 31,0);
    tracep->declBus(c+157,"sltres", false,-1, 31,0);
    tracep->declBus(c+146,"A_s", false,-1, 31,0);
    tracep->declBus(c+148,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+79,"func3", false,-1, 2,0);
    tracep->declBit(c+80,"func7", false,-1);
    tracep->declBus(c+94,"aluop", false,-1, 1,0);
    tracep->declBit(c+92,"jalrsig", false,-1);
    tracep->declBus(c+95,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+100,"type_I", false,-1);
    tracep->declBit(c+101,"type_B", false,-1);
    tracep->declBit(c+102,"type_R", false,-1);
    tracep->declBit(c+103,"addsig", false,-1);
    tracep->declBus(c+104,"branchop", false,-1, 3,0);
    tracep->declBus(c+105,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+90,"btypebranch", false,-1);
    tracep->declBus(c+79,"func3", false,-1, 2,0);
    tracep->declBit(c+149,"zero", false,-1);
    tracep->declBit(c+150,"signal", false,-1);
    tracep->declBit(c+151,"carry", false,-1);
    tracep->declBus(c+152,"res", false,-1, 31,0);
    tracep->declBus(c+168,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+160,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+91,"jalsig", false,-1);
    tracep->declBit(c+92,"jalrsig", false,-1);
    tracep->declBit(c+93,"auipcsig", false,-1);
    tracep->declBus(c+159,"npc", false,-1, 31,0);
    tracep->declBus(c+161,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+171,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+172,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+173,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+148,"out", false,-1, 31,0);
    tracep->declBus(c+88,"key", false,-1, 0,0);
    tracep->declArray(c+120,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+171,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+172,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+173,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+174,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+148,"out", false,-1, 31,0);
    tracep->declBus(c+88,"key", false,-1, 0,0);
    tracep->declBus(c+175,"default_out", false,-1, 31,0);
    tracep->declArray(c+120,"lut", false,-1, 65,0);
    tracep->declBus(c+176,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+123+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+127+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+158,"lut_out", false,-1, 31,0);
    tracep->declBit(c+106,"hit", false,-1);
    tracep->declBus(c+177,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+77,"inst", false,-1, 31,0);
    tracep->declBus(c+84,"imm", false,-1, 31,0);
    tracep->declBus(c+78,"opcode", false,-1, 6,0);
    tracep->declBus(c+79,"func3", false,-1, 2,0);
    tracep->declBit(c+80,"func7", false,-1);
    tracep->declBus(c+81,"src1", false,-1, 4,0);
    tracep->declBus(c+82,"src2", false,-1, 4,0);
    tracep->declBus(c+83,"rd", false,-1, 4,0);
    tracep->declBit(c+107,"type_I", false,-1);
    tracep->declBit(c+108,"type_R", false,-1);
    tracep->declBit(c+109,"type_U", false,-1);
    tracep->declBit(c+86,"type_S", false,-1);
    tracep->declBit(c+91,"type_J", false,-1);
    tracep->declBit(c+90,"type_B", false,-1);
    tracep->declBus(c+110,"I_imm", false,-1, 31,0);
    tracep->declBus(c+111,"U_imm", false,-1, 31,0);
    tracep->declBus(c+112,"S_imm", false,-1, 31,0);
    tracep->declBus(c+113,"J_imm", false,-1, 31,0);
    tracep->declBus(c+114,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("infetch0 ");
    tracep->declBus(c+167,"pc", false,-1, 31,0);
    tracep->declBus(c+77,"inst", false,-1, 31,0);
    tracep->declBus(c+77,"reg_inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+78,"opcode", false,-1, 6,0);
    tracep->declBus(c+79,"func3", false,-1, 2,0);
    tracep->declBit(c+80,"func7", false,-1);
    tracep->declBit(c+86,"memew", false,-1);
    tracep->declBus(c+89,"muxsig", false,-1, 2,0);
    tracep->declBit(c+87,"memer", false,-1);
    tracep->declBit(c+85,"regew", false,-1);
    tracep->declBit(c+88,"muximm", false,-1);
    tracep->declBus(c+79,"func3_out", false,-1, 2,0);
    tracep->declBit(c+80,"func7_out", false,-1);
    tracep->declBit(c+90,"btypebranch", false,-1);
    tracep->declBit(c+92,"jalrsig", false,-1);
    tracep->declBit(c+91,"jalsig", false,-1);
    tracep->declBus(c+94,"aluop", false,-1, 1,0);
    tracep->declBit(c+93,"auipcsig", false,-1);
    tracep->declBit(c+107,"type_I", false,-1);
    tracep->declBit(c+108,"type_R", false,-1);
    tracep->declBit(c+109,"type_U", false,-1);
    tracep->declBit(c+86,"type_S", false,-1);
    tracep->declBit(c+91,"type_J", false,-1);
    tracep->declBit(c+90,"type_B", false,-1);
    tracep->declBit(c+87,"load", false,-1);
    tracep->declBit(c+86,"store", false,-1);
    tracep->declBit(c+115,"ebreaksig", false,-1);
    tracep->declBit(c+116,"regwritepc", false,-1);
    tracep->declBit(c+87,"regwritemem", false,-1);
    tracep->declBit(c+117,"luisig", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+165,"clk", false,-1);
    tracep->declBus(c+152,"addr", false,-1, 31,0);
    tracep->declBus(c+147,"write", false,-1, 31,0);
    tracep->declBus(c+79,"func3", false,-1, 2,0);
    tracep->declBit(c+87,"er", false,-1);
    tracep->declBit(c+86,"ew", false,-1);
    tracep->declBus(c+169,"read", false,-1, 31,0);
    tracep->declBus(c+72,"readreg", false,-1, 31,0);
    tracep->declBus(c+118,"len", false,-1, 2,0);
    tracep->declBit(c+119,"signalsig", false,-1);
    tracep->declBus(c+72,"read_u", false,-1, 31,0);
    tracep->declBus(c+170,"read_s", false,-1, 31,0);
    tracep->declBus(c+73,"read_sb", false,-1, 31,0);
    tracep->declBus(c+74,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+178,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+173,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+75,"input_number", false,-1, 7,0);
    tracep->declBus(c+73,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+179,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+173,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+76,"input_number", false,-1, 15,0);
    tracep->declBus(c+74,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+180,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+181,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+173,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+162,"out", false,-1, 31,0);
    tracep->declBus(c+89,"key", false,-1, 2,0);
    tracep->declBus(c+174,"default_out", false,-1, 31,0);
    tracep->declArray(c+129,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+180,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+181,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+173,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+172,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+162,"out", false,-1, 31,0);
    tracep->declBus(c+89,"key", false,-1, 2,0);
    tracep->declBus(c+174,"default_out", false,-1, 31,0);
    tracep->declArray(c+129,"lut", false,-1, 139,0);
    tracep->declBus(c+182,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+134+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+142+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+163,"lut_out", false,-1, 31,0);
    tracep->declBit(c+164,"hit", false,-1);
    tracep->declBus(c+183,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+167,"pc", false,-1, 31,0);
    tracep->declBus(c+168,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+167,"pc", false,-1, 31,0);
    tracep->declBus(c+84,"imm", false,-1, 31,0);
    tracep->declBus(c+160,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+165,"clk", false,-1);
    tracep->declBus(c+159,"npc", false,-1, 31,0);
    tracep->declBit(c+166,"rst", false,-1);
    tracep->declBus(c+167,"pcout", false,-1, 31,0);
    tracep->declBus(c+184,"init", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+165,"clk", false,-1);
    tracep->declBit(c+166,"rst", false,-1);
    tracep->declBit(c+85,"ew", false,-1);
    tracep->declBus(c+83,"addr", false,-1, 4,0);
    tracep->declBus(c+81,"src1", false,-1, 4,0);
    tracep->declBus(c+82,"src2", false,-1, 4,0);
    tracep->declBus(c+162,"data", false,-1, 31,0);
    tracep->declBus(c+146,"regout1", false,-1, 31,0);
    tracep->declBus(c+147,"regout2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+7+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+165,"clk", false,-1);
    tracep->declBit(c+166,"rst", false,-1);
    tracep->declBit(c+85,"ew", false,-1);
    tracep->declBus(c+83,"addr", false,-1, 4,0);
    tracep->declBus(c+162,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+39+i*1,"out", true,(i+0), 31,0);
    }
    tracep->declBus(c+71,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_h44c198b2__0;
    VlWide<5>/*159:0*/ __Vtemp_h999ddfee__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[1]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[2]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[3]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[4]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[5]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[6]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[7]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[8]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[9]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[10]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[11]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[12]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[13]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[14]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[15]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[16]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[17]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[18]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[19]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[20]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[21]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[22]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[23]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[24]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[25]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[26]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[27]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[28]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[29]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[30]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[31]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__mem0__DOT__readreg),32);
    bufp->fullIData(oldp+73,((((- (IData)((1U & (vlSelf->top__DOT__mem0__DOT__readreg 
                                                 >> 7U)))) 
                               << 8U) | (0xffU & vlSelf->top__DOT__mem0__DOT__readreg))),32);
    bufp->fullIData(oldp+74,((((- (IData)((1U & (vlSelf->top__DOT__mem0__DOT__readreg 
                                                 >> 0xfU)))) 
                               << 0x10U) | (0xffffU 
                                            & vlSelf->top__DOT__mem0__DOT__readreg))),32);
    bufp->fullCData(oldp+75,((0xffU & vlSelf->top__DOT__mem0__DOT__readreg)),8);
    bufp->fullSData(oldp+76,((0xffffU & vlSelf->top__DOT__mem0__DOT__readreg)),16);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__infetch0__DOT__reg_inst),32);
    bufp->fullCData(oldp+78,((0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)),7);
    bufp->fullCData(oldp+79,((7U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+80,((1U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                  >> 0x1eU))));
    bufp->fullCData(oldp+81,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+82,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+83,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                       >> 7U))),5);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+85,(vlSelf->top__DOT__regew));
    bufp->fullBit(oldp+86,((0x23U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+87,((3U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+88,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+89,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+90,((0x63U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+91,((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+92,((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+93,((0x17U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullCData(oldp+94,(vlSelf->top__DOT__aluop),2);
    bufp->fullCData(oldp+95,(vlSelf->top__DOT__aluopcode),5);
    bufp->fullBit(oldp+96,((1U & (~ (IData)(vlSelf->top__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+97,(vlSelf->top__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+98,(vlSelf->top__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+99,(vlSelf->top__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+100,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+101,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+102,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+103,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+104,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+105,(vlSelf->top__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+106,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+107,(vlSelf->top__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+108,((0x33U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+109,(vlSelf->top__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+111,((0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst)),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+115,((IData)((0x73U == (0x707fU 
                                               & vlSelf->top__DOT__infetch0__DOT__reg_inst)))));
    bufp->fullBit(oldp+116,(((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                | (0x17U == (0x7fU 
                                             & vlSelf->top__DOT__infetch0__DOT__reg_inst))))));
    bufp->fullBit(oldp+117,((0x37U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullCData(oldp+118,(vlSelf->top__DOT__mem0__DOT__len),3);
    bufp->fullBit(oldp+119,(vlSelf->top__DOT__mem0__DOT__signalsig));
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+120,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+123,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+125,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    __Vtemp_h999ddfee__0[0U] = (IData)((0x400000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__pcwritereg))));
    __Vtemp_h999ddfee__0[1U] = ((vlSelf->top__DOT__imm 
                                 << 3U) | (IData)((
                                                   (0x400000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__pcwritereg))) 
                                                   >> 0x20U)));
    __Vtemp_h999ddfee__0[2U] = (0x10U | ((vlSelf->top__DOT__memread 
                                          << 6U) | 
                                         (vlSelf->top__DOT__imm 
                                          >> 0x1dU)));
    __Vtemp_h999ddfee__0[3U] = (0x40U | ((vlSelf->top__DOT__res 
                                          << 9U) | 
                                         (vlSelf->top__DOT__memread 
                                          >> 0x1aU)));
    __Vtemp_h999ddfee__0[4U] = (vlSelf->top__DOT__res 
                                >> 0x17U);
    bufp->fullWData(oldp+129,(__Vtemp_h999ddfee__0),140);
    bufp->fullQData(oldp+134,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+136,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+138,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+140,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__alu0__DOT__A_s),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__aluarg2),32);
    bufp->fullBit(oldp+149,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+150,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+151,(vlSelf->top__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+155,((0U == vlSelf->top__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+164,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+165,(vlSelf->clk));
    bufp->fullBit(oldp+166,(vlSelf->rst));
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__pcbridge),32);
    bufp->fullIData(oldp+168,(((IData)(4U) + vlSelf->top__DOT__pcbridge)),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__memread),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__mem0__DOT__read_s),32);
    bufp->fullIData(oldp+171,(2U),32);
    bufp->fullIData(oldp+172,(1U),32);
    bufp->fullIData(oldp+173,(0x20U),32);
    bufp->fullIData(oldp+174,(0U),32);
    bufp->fullIData(oldp+175,(0U),32);
    bufp->fullIData(oldp+176,(0x21U),32);
    bufp->fullIData(oldp+177,(2U),32);
    bufp->fullIData(oldp+178,(8U),32);
    bufp->fullIData(oldp+179,(0x10U),32);
    bufp->fullIData(oldp+180,(4U),32);
    bufp->fullIData(oldp+181,(3U),32);
    bufp->fullIData(oldp+182,(0x23U),32);
    bufp->fullIData(oldp+183,(4U),32);
    bufp->fullIData(oldp+184,(0x80000000U),32);
}
