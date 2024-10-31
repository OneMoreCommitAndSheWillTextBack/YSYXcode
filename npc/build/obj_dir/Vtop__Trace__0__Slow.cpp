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
    tracep->declBit(c+222,"clk", false,-1);
    tracep->declBit(c+223,"rst", false,-1);
    tracep->declBus(c+224,"pc_out", false,-1, 31,0);
    tracep->declBus(c+225,"inst_out", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+226+i*1,"reg_out", true,(i+0), 31,0);
    }
    tracep->declBus(c+258,"host_get_addr", false,-1, 31,0);
    tracep->declBus(c+259,"host_write", false,-1, 31,0);
    tracep->declBus(c+260,"host_read", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+222,"clk", false,-1);
    tracep->declBit(c+223,"rst", false,-1);
    tracep->declBus(c+224,"pc_out", false,-1, 31,0);
    tracep->declBus(c+225,"inst_out", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+226+i*1,"reg_out", true,(i+0), 31,0);
    }
    tracep->declBus(c+258,"host_get_addr", false,-1, 31,0);
    tracep->declBus(c+259,"host_write", false,-1, 31,0);
    tracep->declBus(c+260,"host_read", false,-1, 31,0);
    tracep->declBus(c+170,"npc", false,-1, 31,0);
    tracep->declBus(c+7,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+225,"inst", false,-1, 31,0);
    tracep->declBus(c+8,"opcode", false,-1, 6,0);
    tracep->declBus(c+9,"func3_decoder", false,-1, 2,0);
    tracep->declBit(c+10,"func7_decoder", false,-1);
    tracep->declBus(c+11,"src1", false,-1, 4,0);
    tracep->declBus(c+12,"src2", false,-1, 4,0);
    tracep->declBus(c+13,"rd", false,-1, 4,0);
    tracep->declBus(c+171,"imm", false,-1, 31,0);
    tracep->declBit(c+261,"regew", false,-1);
    tracep->declBit(c+172,"memew", false,-1);
    tracep->declBit(c+173,"memer", false,-1);
    tracep->declBit(c+174,"muximm", false,-1);
    tracep->declBit(c+14,"regwritepc", false,-1);
    tracep->declBit(c+173,"regwritemem", false,-1);
    tracep->declBus(c+9,"func3_maincontrol", false,-1, 2,0);
    tracep->declBit(c+10,"func7_maincontrol", false,-1);
    tracep->declBit(c+15,"btypebranch", false,-1);
    tracep->declBit(c+16,"jalsig", false,-1);
    tracep->declBit(c+17,"jalrsig", false,-1);
    tracep->declBit(c+18,"auipcsig", false,-1);
    tracep->declBus(c+175,"aluop", false,-1, 1,0);
    tracep->declBus(c+218,"regwrite", false,-1, 31,0);
    tracep->declBus(c+19,"regout1", false,-1, 31,0);
    tracep->declBus(c+176,"regout2", false,-1, 31,0);
    tracep->declBus(c+177,"aluopcode", false,-1, 3,0);
    tracep->declBus(c+20,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+178,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+179,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+180,"zero", false,-1);
    tracep->declBit(c+181,"signal", false,-1);
    tracep->declBus(c+182,"res", false,-1, 31,0);
    tracep->declBus(c+183,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+262,"memread", false,-1, 31,0);
    tracep->declBus(c+219,"muxregormem", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+19,"A", false,-1, 31,0);
    tracep->declBus(c+179,"B", false,-1, 31,0);
    tracep->declBus(c+177,"op", false,-1, 3,0);
    tracep->declBus(c+182,"res", false,-1, 31,0);
    tracep->declBit(c+180,"zero", false,-1);
    tracep->declBit(c+181,"signal", false,-1);
    tracep->declBit(c+184,"addsig", false,-1);
    tracep->declBit(c+185,"logsig", false,-1);
    tracep->declBit(c+186,"shfsig", false,-1);
    tracep->declBit(c+187,"sltsig", false,-1);
    tracep->declBus(c+188,"logres", false,-1, 31,0);
    tracep->declBus(c+189,"addres", false,-1, 31,0);
    tracep->declBit(c+190,"addzero", false,-1);
    tracep->declBus(c+191,"shfres", false,-1, 31,0);
    tracep->declBus(c+192,"sltres", false,-1, 31,0);
    tracep->declBus(c+19,"A_s", false,-1, 31,0);
    tracep->declBus(c+179,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+9,"func3", false,-1, 2,0);
    tracep->declBit(c+10,"func7", false,-1);
    tracep->declBus(c+175,"aluop", false,-1, 1,0);
    tracep->declBit(c+17,"jalrsig", false,-1);
    tracep->declBus(c+177,"aluopcode", false,-1, 3,0);
    tracep->declBit(c+193,"type_I", false,-1);
    tracep->declBit(c+194,"type_B", false,-1);
    tracep->declBit(c+195,"type_R", false,-1);
    tracep->declBit(c+196,"addsig", false,-1);
    tracep->declBus(c+21,"branchop", false,-1, 3,0);
    tracep->declBus(c+197,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+15,"btypebranch", false,-1);
    tracep->declBus(c+9,"func3", false,-1, 2,0);
    tracep->declBit(c+180,"zero", false,-1);
    tracep->declBit(c+181,"signal", false,-1);
    tracep->declBus(c+182,"res", false,-1, 31,0);
    tracep->declBus(c+20,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+178,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+16,"jalsig", false,-1);
    tracep->declBit(c+17,"jalrsig", false,-1);
    tracep->declBit(c+18,"auipcsig", false,-1);
    tracep->declBus(c+170,"npc", false,-1, 31,0);
    tracep->declBus(c+183,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+170,"npc_tmp", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+267,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+179,"out", false,-1, 31,0);
    tracep->declBus(c+174,"key", false,-1, 0,0);
    tracep->declArray(c+198,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+267,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+268,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+179,"out", false,-1, 31,0);
    tracep->declBus(c+174,"key", false,-1, 0,0);
    tracep->declBus(c+269,"default_out", false,-1, 31,0);
    tracep->declArray(c+198,"lut", false,-1, 65,0);
    tracep->declBus(c+270,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+201+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+263+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+205,"lut_out", false,-1, 31,0);
    tracep->declBit(c+206,"hit", false,-1);
    tracep->declBus(c+271,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+225,"inst", false,-1, 31,0);
    tracep->declBus(c+171,"imm", false,-1, 31,0);
    tracep->declBus(c+8,"opcode", false,-1, 6,0);
    tracep->declBus(c+9,"func3", false,-1, 2,0);
    tracep->declBit(c+10,"func7", false,-1);
    tracep->declBus(c+11,"src1", false,-1, 4,0);
    tracep->declBus(c+12,"src2", false,-1, 4,0);
    tracep->declBus(c+13,"rd", false,-1, 4,0);
    tracep->declBit(c+207,"type_I", false,-1);
    tracep->declBit(c+22,"type_R", false,-1);
    tracep->declBit(c+23,"type_U", false,-1);
    tracep->declBit(c+172,"type_S", false,-1);
    tracep->declBit(c+16,"type_J", false,-1);
    tracep->declBit(c+15,"type_B", false,-1);
    tracep->declBus(c+24,"I_imm", false,-1, 31,0);
    tracep->declBus(c+25,"U_imm", false,-1, 31,0);
    tracep->declBus(c+26,"S_imm", false,-1, 31,0);
    tracep->declBus(c+27,"J_imm", false,-1, 31,0);
    tracep->declBus(c+28,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("infetch0 ");
    tracep->declBus(c+7,"pc", false,-1, 31,0);
    tracep->declBus(c+225,"inst", false,-1, 31,0);
    tracep->declBus(c+29,"reg_inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+8,"opcode", false,-1, 6,0);
    tracep->declBus(c+9,"func3", false,-1, 2,0);
    tracep->declBit(c+10,"func7", false,-1);
    tracep->declBit(c+172,"memew", false,-1);
    tracep->declBit(c+173,"memer", false,-1);
    tracep->declBit(c+261,"regew", false,-1);
    tracep->declBit(c+174,"muximm", false,-1);
    tracep->declBit(c+173,"regwritemem", false,-1);
    tracep->declBit(c+14,"regwritepc", false,-1);
    tracep->declBus(c+9,"func3_out", false,-1, 2,0);
    tracep->declBit(c+10,"func7_out", false,-1);
    tracep->declBit(c+15,"btypebranch", false,-1);
    tracep->declBit(c+17,"jalrsig", false,-1);
    tracep->declBit(c+16,"jalsig", false,-1);
    tracep->declBus(c+175,"aluop", false,-1, 1,0);
    tracep->declBit(c+18,"auipcsig", false,-1);
    tracep->declBit(c+207,"type_I", false,-1);
    tracep->declBit(c+22,"type_R", false,-1);
    tracep->declBit(c+23,"type_U", false,-1);
    tracep->declBit(c+172,"type_S", false,-1);
    tracep->declBit(c+16,"type_J", false,-1);
    tracep->declBit(c+15,"type_B", false,-1);
    tracep->declBit(c+173,"load", false,-1);
    tracep->declBit(c+172,"store", false,-1);
    tracep->declBit(c+30,"ebreaksig", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBus(c+182,"addr", false,-1, 31,0);
    tracep->declBus(c+176,"write", false,-1, 31,0);
    tracep->declBit(c+173,"er", false,-1);
    tracep->declBit(c+172,"ew", false,-1);
    tracep->declBus(c+262,"read", false,-1, 31,0);
    tracep->declBus(c+262,"readreg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+267,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+218,"out", false,-1, 31,0);
    tracep->declBus(c+14,"key", false,-1, 0,0);
    tracep->declArray(c+209,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+267,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+268,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+218,"out", false,-1, 31,0);
    tracep->declBus(c+14,"key", false,-1, 0,0);
    tracep->declBus(c+269,"default_out", false,-1, 31,0);
    tracep->declArray(c+209,"lut", false,-1, 65,0);
    tracep->declBus(c+270,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+212+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+216+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+220,"lut_out", false,-1, 31,0);
    tracep->declBit(c+31,"hit", false,-1);
    tracep->declBus(c+271,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+7,"pc", false,-1, 31,0);
    tracep->declBus(c+20,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+7,"pc", false,-1, 31,0);
    tracep->declBus(c+171,"imm", false,-1, 31,0);
    tracep->declBus(c+178,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+222,"clk", false,-1);
    tracep->declBus(c+170,"npc", false,-1, 31,0);
    tracep->declBit(c+223,"rst", false,-1);
    tracep->declBus(c+7,"pcout", false,-1, 31,0);
    tracep->declBus(c+272,"init", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+222,"clk", false,-1);
    tracep->declBit(c+223,"rst", false,-1);
    tracep->declBit(c+261,"ew", false,-1);
    tracep->declBus(c+13,"addr", false,-1, 4,0);
    tracep->declBus(c+11,"src1", false,-1, 4,0);
    tracep->declBus(c+12,"src2", false,-1, 4,0);
    tracep->declBus(c+218,"data", false,-1, 31,0);
    tracep->declBus(c+19,"regout1", false,-1, 31,0);
    tracep->declBus(c+176,"regout2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+32+i*1,"reg_out", true,(i+0), 31,0);
    }
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+64+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+222,"clk", false,-1);
    tracep->declBit(c+223,"rst", false,-1);
    tracep->declBit(c+261,"ew", false,-1);
    tracep->declBus(c+13,"addr", false,-1, 4,0);
    tracep->declBus(c+218,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+96+i*1,"out", true,(i+0), 31,0);
    }
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+128+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->declBus(c+160,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regormem ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+267,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+219,"out", false,-1, 31,0);
    tracep->declBus(c+173,"key", false,-1, 0,0);
    tracep->declArray(c+161,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+267,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+268,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+219,"out", false,-1, 31,0);
    tracep->declBus(c+173,"key", false,-1, 0,0);
    tracep->declBus(c+269,"default_out", false,-1, 31,0);
    tracep->declArray(c+161,"lut", false,-1, 65,0);
    tracep->declBus(c+270,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+164+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+168+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+221,"lut_out", false,-1, 31,0);
    tracep->declBit(c+208,"hit", false,-1);
    tracep->declBus(c+271,"i", false,-1, 31,0);
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
    VlWide<3>/*95:0*/ __Vtemp_h4f3e7bd4__0;
    VlWide<3>/*95:0*/ __Vtemp_h44c198b2__0;
    VlWide<3>/*95:0*/ __Vtemp_ha940484a__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+4,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+5,(vlSelf->top__DOT__regormem__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__regormem__DOT__i0__DOT__key_list[1]));
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__pcbridge),32);
    bufp->fullCData(oldp+8,((0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)),7);
    bufp->fullCData(oldp+9,((7U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                   >> 0xcU))),3);
    bufp->fullBit(oldp+10,((1U & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                  >> 0x1eU))));
    bufp->fullCData(oldp+11,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+12,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+13,((0x1fU & (vlSelf->top__DOT__infetch0__DOT__reg_inst 
                                       >> 7U))),5);
    bufp->fullBit(oldp+14,(vlSelf->top__DOT__regwritepc));
    bufp->fullBit(oldp+15,((0x63U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+16,((0x6fU == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+17,((0x67U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+18,((0x17U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__alu0__DOT__A_s),32);
    bufp->fullIData(oldp+20,(((IData)(4U) + vlSelf->top__DOT__pcbridge)),32);
    bufp->fullCData(oldp+21,(((IData)((0x6000U == (0x6000U 
                                                   & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                               ? 8U : ((1U & VL_REDXOR_16(
                                                          (0x6000U 
                                                           & vlSelf->top__DOT__infetch0__DOT__reg_inst)))
                                        ? 9U : 3U))),4);
    bufp->fullBit(oldp+22,((0x33U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+23,(vlSelf->top__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+25,((0xfffff000U & vlSelf->top__DOT__infetch0__DOT__reg_inst)),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__decoder0__DOT__B_imm),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__infetch0__DOT__reg_inst),32);
    bufp->fullBit(oldp+30,((IData)((0x73U == (0x707fU 
                                              & vlSelf->top__DOT__infetch0__DOT__reg_inst)))));
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+32,(vlSelf->top__DOT____Vcellout__regfile__reg_out[0]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT____Vcellout__regfile__reg_out[1]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT____Vcellout__regfile__reg_out[2]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT____Vcellout__regfile__reg_out[3]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT____Vcellout__regfile__reg_out[4]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT____Vcellout__regfile__reg_out[5]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT____Vcellout__regfile__reg_out[6]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT____Vcellout__regfile__reg_out[7]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT____Vcellout__regfile__reg_out[8]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT____Vcellout__regfile__reg_out[9]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT____Vcellout__regfile__reg_out[10]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT____Vcellout__regfile__reg_out[11]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT____Vcellout__regfile__reg_out[12]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT____Vcellout__regfile__reg_out[13]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT____Vcellout__regfile__reg_out[14]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT____Vcellout__regfile__reg_out[15]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT____Vcellout__regfile__reg_out[16]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT____Vcellout__regfile__reg_out[17]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT____Vcellout__regfile__reg_out[18]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT____Vcellout__regfile__reg_out[19]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT____Vcellout__regfile__reg_out[20]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT____Vcellout__regfile__reg_out[21]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT____Vcellout__regfile__reg_out[22]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT____Vcellout__regfile__reg_out[23]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT____Vcellout__regfile__reg_out[24]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT____Vcellout__regfile__reg_out[25]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT____Vcellout__regfile__reg_out[26]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT____Vcellout__regfile__reg_out[27]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT____Vcellout__regfile__reg_out[28]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT____Vcellout__regfile__reg_out[29]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT____Vcellout__regfile__reg_out[30]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT____Vcellout__regfile__reg_out[31]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[0]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[1]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[2]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[3]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[4]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[5]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[6]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[7]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[8]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[9]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[10]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[11]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[12]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[13]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[14]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[15]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[16]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[17]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[18]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[19]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[20]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[21]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[22]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[23]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[24]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[25]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[26]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[27]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[28]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[29]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[30]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__out[31]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[0]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[1]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[2]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[3]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[4]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[5]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[6]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[7]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[8]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[9]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[10]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[11]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[12]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[13]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[14]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[15]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[16]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[17]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[18]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[19]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[20]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[21]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[22]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[23]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[24]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[25]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[26]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[27]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[28]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[29]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[30]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__rf[31]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    __Vtemp_h4f3e7bd4__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__mem0__DOT__readreg))));
    __Vtemp_h4f3e7bd4__0[1U] = ((vlSelf->top__DOT__res 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__mem0__DOT__readreg))) 
                                                   >> 0x20U)));
    __Vtemp_h4f3e7bd4__0[2U] = (vlSelf->top__DOT__res 
                                >> 0x1fU);
    bufp->fullWData(oldp+161,(__Vtemp_h4f3e7bd4__0),66);
    bufp->fullQData(oldp+164,(vlSelf->top__DOT__regormem__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+166,(vlSelf->top__DOT__regormem__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regormem__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__branchcontrol0__DOT__npc_tmp),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+172,(vlSelf->top__DOT__decoder0__DOT__type_S));
    bufp->fullBit(oldp+173,(vlSelf->top__DOT__memer));
    bufp->fullBit(oldp+174,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+175,(vlSelf->top__DOT__aluop),2);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__regout2),32);
    bufp->fullCData(oldp+177,(vlSelf->top__DOT__aluopcode),4);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__aluarg2),32);
    bufp->fullBit(oldp+180,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+181,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullIData(oldp+182,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+183,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullBit(oldp+184,((1U & (~ (IData)(vlSelf->top__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+185,(vlSelf->top__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+186,(vlSelf->top__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+187,(vlSelf->top__DOT__alu0__DOT__sltsig));
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+189,(vlSelf->top__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+190,((0U == vlSelf->top__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__alu0__DOT__sltres),32);
    bufp->fullBit(oldp+193,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+194,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+195,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+196,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+197,(vlSelf->top__DOT__alucontrol0__DOT__IRop),4);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+198,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+201,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+203,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+205,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+206,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+207,(vlSelf->top__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+208,(vlSelf->top__DOT__regormem__DOT__i0__DOT__hit));
    __Vtemp_ha940484a__0[0U] = (IData)((QData)((IData)(vlSelf->top__DOT__muxregormem)));
    __Vtemp_ha940484a__0[1U] = ((vlSelf->top__DOT__pcwritereg 
                                 << 1U) | (IData)(((QData)((IData)(vlSelf->top__DOT__muxregormem)) 
                                                   >> 0x20U)));
    __Vtemp_ha940484a__0[2U] = (2U | (vlSelf->top__DOT__pcwritereg 
                                      >> 0x1fU));
    bufp->fullWData(oldp+209,(__Vtemp_ha940484a__0),66);
    bufp->fullQData(oldp+212,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+214,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+216,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+217,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+218,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+219,(vlSelf->top__DOT__muxregormem),32);
    bufp->fullIData(oldp+220,(vlSelf->top__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+221,(vlSelf->top__DOT__regormem__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+222,(vlSelf->clk));
    bufp->fullBit(oldp+223,(vlSelf->rst));
    bufp->fullIData(oldp+224,(vlSelf->pc_out),32);
    bufp->fullIData(oldp+225,(vlSelf->inst_out),32);
    bufp->fullIData(oldp+226,(vlSelf->reg_out[0]),32);
    bufp->fullIData(oldp+227,(vlSelf->reg_out[1]),32);
    bufp->fullIData(oldp+228,(vlSelf->reg_out[2]),32);
    bufp->fullIData(oldp+229,(vlSelf->reg_out[3]),32);
    bufp->fullIData(oldp+230,(vlSelf->reg_out[4]),32);
    bufp->fullIData(oldp+231,(vlSelf->reg_out[5]),32);
    bufp->fullIData(oldp+232,(vlSelf->reg_out[6]),32);
    bufp->fullIData(oldp+233,(vlSelf->reg_out[7]),32);
    bufp->fullIData(oldp+234,(vlSelf->reg_out[8]),32);
    bufp->fullIData(oldp+235,(vlSelf->reg_out[9]),32);
    bufp->fullIData(oldp+236,(vlSelf->reg_out[10]),32);
    bufp->fullIData(oldp+237,(vlSelf->reg_out[11]),32);
    bufp->fullIData(oldp+238,(vlSelf->reg_out[12]),32);
    bufp->fullIData(oldp+239,(vlSelf->reg_out[13]),32);
    bufp->fullIData(oldp+240,(vlSelf->reg_out[14]),32);
    bufp->fullIData(oldp+241,(vlSelf->reg_out[15]),32);
    bufp->fullIData(oldp+242,(vlSelf->reg_out[16]),32);
    bufp->fullIData(oldp+243,(vlSelf->reg_out[17]),32);
    bufp->fullIData(oldp+244,(vlSelf->reg_out[18]),32);
    bufp->fullIData(oldp+245,(vlSelf->reg_out[19]),32);
    bufp->fullIData(oldp+246,(vlSelf->reg_out[20]),32);
    bufp->fullIData(oldp+247,(vlSelf->reg_out[21]),32);
    bufp->fullIData(oldp+248,(vlSelf->reg_out[22]),32);
    bufp->fullIData(oldp+249,(vlSelf->reg_out[23]),32);
    bufp->fullIData(oldp+250,(vlSelf->reg_out[24]),32);
    bufp->fullIData(oldp+251,(vlSelf->reg_out[25]),32);
    bufp->fullIData(oldp+252,(vlSelf->reg_out[26]),32);
    bufp->fullIData(oldp+253,(vlSelf->reg_out[27]),32);
    bufp->fullIData(oldp+254,(vlSelf->reg_out[28]),32);
    bufp->fullIData(oldp+255,(vlSelf->reg_out[29]),32);
    bufp->fullIData(oldp+256,(vlSelf->reg_out[30]),32);
    bufp->fullIData(oldp+257,(vlSelf->reg_out[31]),32);
    bufp->fullIData(oldp+258,(vlSelf->host_get_addr),32);
    bufp->fullIData(oldp+259,(vlSelf->host_write),32);
    bufp->fullIData(oldp+260,(vlSelf->host_read),32);
    bufp->fullBit(oldp+261,(((IData)(vlSelf->top__DOT__decoder0__DOT__type_I) 
                             | ((0x33U == (0x7fU & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__infetch0__DOT__reg_inst)) 
                                   | (IData)(vlSelf->top__DOT__decoder0__DOT__type_U))))));
    bufp->fullIData(oldp+262,(vlSelf->top__DOT__mem0__DOT__readreg),32);
    bufp->fullIData(oldp+263,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+264,(vlSelf->top__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+265,(2U),32);
    bufp->fullIData(oldp+266,(1U),32);
    bufp->fullIData(oldp+267,(0x20U),32);
    bufp->fullIData(oldp+268,(0U),32);
    bufp->fullIData(oldp+269,(0U),32);
    bufp->fullIData(oldp+270,(0x21U),32);
    bufp->fullIData(oldp+271,(2U),32);
    bufp->fullIData(oldp+272,(0x80000000U),32);
}
