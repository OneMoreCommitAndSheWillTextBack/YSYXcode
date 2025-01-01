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
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBit(c+208,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBit(c+208,"rst", false,-1);
    tracep->declBit(c+19,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+187,"npc", false,-1, 31,0);
    tracep->declBus(c+103,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+20,"inst", false,-1, 31,0);
    tracep->declBit(c+21,"ifu_valid", false,-1);
    tracep->declBus(c+22,"src1", false,-1, 4,0);
    tracep->declBus(c+23,"src2", false,-1, 4,0);
    tracep->declBus(c+24,"rd", false,-1, 4,0);
    tracep->declBus(c+25,"imm", false,-1, 31,0);
    tracep->declBit(c+26,"ebreaksig", false,-1);
    tracep->declBit(c+27,"mretsig", false,-1);
    tracep->declBit(c+28,"ecallsig", false,-1);
    tracep->declBit(c+29,"regew", false,-1);
    tracep->declBit(c+30,"memew", false,-1);
    tracep->declBit(c+31,"memer", false,-1);
    tracep->declBit(c+32,"muximm", false,-1);
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBus(c+34,"muxsig", false,-1, 2,0);
    tracep->declBit(c+35,"func7", false,-1);
    tracep->declBit(c+36,"btypebranch", false,-1);
    tracep->declBit(c+37,"jalsig", false,-1);
    tracep->declBit(c+38,"jalrsig", false,-1);
    tracep->declBit(c+39,"auipcsig", false,-1);
    tracep->declBus(c+40,"aluop", false,-1, 1,0);
    tracep->declBit(c+181,"csrrw", false,-1);
    tracep->declBit(c+182,"csrrs", false,-1);
    tracep->declBit(c+21,"idu_valid", false,-1);
    tracep->declBus(c+41,"memmask", false,-1, 2,0);
    tracep->declBit(c+42,"memsextsig", false,-1);
    tracep->declBus(c+188,"regwrite", false,-1, 31,0);
    tracep->declBus(c+189,"regout1", false,-1, 31,0);
    tracep->declBus(c+190,"regout2", false,-1, 31,0);
    tracep->declBus(c+104,"mepc", false,-1, 31,0);
    tracep->declBus(c+105,"mtvec", false,-1, 31,0);
    tracep->declBit(c+19,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+191,"res", false,-1, 31,0);
    tracep->declBus(c+192,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+21,"exu_valid", false,-1);
    tracep->declBit(c+19,"ready_wbu_to_exu", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBit(c+36,"btypebranch", false,-1);
    tracep->declBit(c+35,"func7", false,-1);
    tracep->declBus(c+40,"aluop", false,-1, 1,0);
    tracep->declBit(c+38,"jalrsig", false,-1);
    tracep->declBit(c+37,"jalsig", false,-1);
    tracep->declBus(c+25,"imm", false,-1, 31,0);
    tracep->declBit(c+32,"muximm", false,-1);
    tracep->declBus(c+189,"regout1", false,-1, 31,0);
    tracep->declBus(c+190,"regout2", false,-1, 31,0);
    tracep->declBus(c+103,"pc", false,-1, 31,0);
    tracep->declBit(c+39,"auipcsig", false,-1);
    tracep->declBit(c+27,"mretsig", false,-1);
    tracep->declBit(c+28,"ecallsig", false,-1);
    tracep->declBus(c+105,"mtvec", false,-1, 31,0);
    tracep->declBus(c+104,"mepc", false,-1, 31,0);
    tracep->declBit(c+21,"valid_from", false,-1);
    tracep->declBit(c+19,"ready_from", false,-1);
    tracep->declBus(c+191,"res", false,-1, 31,0);
    tracep->declBus(c+187,"npc", false,-1, 31,0);
    tracep->declBus(c+192,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+21,"valid_to", false,-1);
    tracep->declBit(c+19,"ready_to", false,-1);
    tracep->declBus(c+106,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+193,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+43,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+194,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+195,"zero", false,-1);
    tracep->declBit(c+196,"signal", false,-1);
    tracep->declBit(c+197,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+189,"A", false,-1, 31,0);
    tracep->declBus(c+194,"B", false,-1, 31,0);
    tracep->declBus(c+43,"op", false,-1, 4,0);
    tracep->declBus(c+191,"res", false,-1, 31,0);
    tracep->declBit(c+195,"zero", false,-1);
    tracep->declBit(c+196,"signal", false,-1);
    tracep->declBit(c+197,"carry", false,-1);
    tracep->declBit(c+44,"addsig", false,-1);
    tracep->declBit(c+45,"logsig", false,-1);
    tracep->declBit(c+46,"shfsig", false,-1);
    tracep->declBit(c+47,"sltsig", false,-1);
    tracep->declBit(c+197,"carry_tmp", false,-1);
    tracep->declBit(c+48,"type_I", false,-1);
    tracep->declBus(c+198,"logres", false,-1, 31,0);
    tracep->declBus(c+199,"addres", false,-1, 31,0);
    tracep->declBit(c+200,"addzero", false,-1);
    tracep->declBus(c+201,"shfres", false,-1, 31,0);
    tracep->declBus(c+202,"sltres", false,-1, 31,0);
    tracep->declBus(c+189,"A_s", false,-1, 31,0);
    tracep->declBus(c+194,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBit(c+35,"func7", false,-1);
    tracep->declBus(c+40,"aluop", false,-1, 1,0);
    tracep->declBit(c+38,"jalrsig", false,-1);
    tracep->declBus(c+43,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+48,"type_I", false,-1);
    tracep->declBit(c+49,"type_B", false,-1);
    tracep->declBit(c+50,"type_R", false,-1);
    tracep->declBit(c+51,"addsig", false,-1);
    tracep->declBus(c+52,"branchop", false,-1, 3,0);
    tracep->declBus(c+53,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+36,"btypebranch", false,-1);
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBit(c+195,"zero", false,-1);
    tracep->declBit(c+196,"signal", false,-1);
    tracep->declBit(c+197,"carry", false,-1);
    tracep->declBus(c+191,"res", false,-1, 31,0);
    tracep->declBus(c+106,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+193,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+37,"jalsig", false,-1);
    tracep->declBit(c+38,"jalrsig", false,-1);
    tracep->declBit(c+39,"auipcsig", false,-1);
    tracep->declBit(c+27,"mretsig", false,-1);
    tracep->declBit(c+28,"ecallsig", false,-1);
    tracep->declBus(c+105,"mtvec", false,-1, 31,0);
    tracep->declBus(c+104,"mepc", false,-1, 31,0);
    tracep->declBus(c+187,"npc", false,-1, 31,0);
    tracep->declBus(c+192,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+210,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+211,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+194,"out", false,-1, 31,0);
    tracep->declBus(c+32,"key", false,-1, 0,0);
    tracep->declArray(c+77,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+210,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+211,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+213,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+194,"out", false,-1, 31,0);
    tracep->declBus(c+32,"key", false,-1, 0,0);
    tracep->declBus(c+214,"default_out", false,-1, 31,0);
    tracep->declArray(c+77,"lut", false,-1, 65,0);
    tracep->declBus(c+215,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+80+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+84+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+203,"lut_out", false,-1, 31,0);
    tracep->declBit(c+54,"hit", false,-1);
    tracep->declBus(c+216,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+103,"pc", false,-1, 31,0);
    tracep->declBus(c+106,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+103,"pc", false,-1, 31,0);
    tracep->declBus(c+25,"imm", false,-1, 31,0);
    tracep->declBus(c+193,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+20,"inst", false,-1, 31,0);
    tracep->declBit(c+21,"valid_from", false,-1);
    tracep->declBit(c+19,"ready_from", false,-1);
    tracep->declBit(c+26,"ebreaksig", false,-1);
    tracep->declBit(c+28,"ecallsig", false,-1);
    tracep->declBit(c+27,"mretsig", false,-1);
    tracep->declBus(c+25,"imm", false,-1, 31,0);
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBit(c+35,"func7", false,-1);
    tracep->declBus(c+22,"src1", false,-1, 4,0);
    tracep->declBus(c+23,"src2", false,-1, 4,0);
    tracep->declBus(c+24,"rd", false,-1, 4,0);
    tracep->declBit(c+30,"memew", false,-1);
    tracep->declBus(c+34,"muxsig", false,-1, 2,0);
    tracep->declBit(c+31,"memer", false,-1);
    tracep->declBit(c+29,"regew", false,-1);
    tracep->declBit(c+32,"muximm", false,-1);
    tracep->declBit(c+36,"btypebranch", false,-1);
    tracep->declBit(c+38,"jalrsig", false,-1);
    tracep->declBit(c+37,"jalsig", false,-1);
    tracep->declBus(c+40,"aluop", false,-1, 1,0);
    tracep->declBit(c+39,"auipcsig", false,-1);
    tracep->declBit(c+181,"csrrw", false,-1);
    tracep->declBit(c+182,"csrrs", false,-1);
    tracep->declBit(c+21,"valid_to", false,-1);
    tracep->declBit(c+19,"ready_to", false,-1);
    tracep->declBus(c+41,"memmask", false,-1, 2,0);
    tracep->declBit(c+42,"memsextsig", false,-1);
    tracep->declBit(c+26,"ebreak", false,-1);
    tracep->declBit(c+28,"ecall", false,-1);
    tracep->declBit(c+27,"mret", false,-1);
    tracep->declBus(c+33,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+35,"func7bridge", false,-1);
    tracep->declBus(c+55,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+20,"inst", false,-1, 31,0);
    tracep->declBit(c+26,"ebreaksig", false,-1);
    tracep->declBit(c+28,"ecallsig", false,-1);
    tracep->declBit(c+27,"mretsig", false,-1);
    tracep->declBus(c+25,"imm", false,-1, 31,0);
    tracep->declBus(c+55,"opcode", false,-1, 6,0);
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBit(c+35,"func7", false,-1);
    tracep->declBus(c+22,"src1", false,-1, 4,0);
    tracep->declBus(c+23,"src2", false,-1, 4,0);
    tracep->declBus(c+24,"rd", false,-1, 4,0);
    tracep->declBus(c+41,"memmask", false,-1, 2,0);
    tracep->declBit(c+42,"memsextsig", false,-1);
    tracep->declBit(c+56,"type_I", false,-1);
    tracep->declBit(c+57,"type_R", false,-1);
    tracep->declBit(c+58,"type_U", false,-1);
    tracep->declBit(c+30,"type_S", false,-1);
    tracep->declBit(c+37,"type_J", false,-1);
    tracep->declBit(c+36,"type_B", false,-1);
    tracep->declBus(c+59,"I_imm", false,-1, 31,0);
    tracep->declBus(c+60,"U_imm", false,-1, 31,0);
    tracep->declBus(c+61,"S_imm", false,-1, 31,0);
    tracep->declBus(c+62,"J_imm", false,-1, 31,0);
    tracep->declBus(c+63,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+55,"opcode", false,-1, 6,0);
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBit(c+35,"func7", false,-1);
    tracep->declBit(c+26,"ebreaksig", false,-1);
    tracep->declBit(c+28,"ecallsig", false,-1);
    tracep->declBit(c+27,"mretsig", false,-1);
    tracep->declBit(c+30,"memew", false,-1);
    tracep->declBus(c+34,"muxsig", false,-1, 2,0);
    tracep->declBit(c+31,"memer", false,-1);
    tracep->declBit(c+29,"regew", false,-1);
    tracep->declBit(c+32,"muximm", false,-1);
    tracep->declBit(c+36,"btypebranch", false,-1);
    tracep->declBit(c+38,"jalrsig", false,-1);
    tracep->declBit(c+37,"jalsig", false,-1);
    tracep->declBus(c+40,"aluop", false,-1, 1,0);
    tracep->declBit(c+39,"auipcsig", false,-1);
    tracep->declBit(c+181,"csrrw", false,-1);
    tracep->declBit(c+182,"csrrs", false,-1);
    tracep->declBit(c+56,"type_I", false,-1);
    tracep->declBit(c+57,"type_R", false,-1);
    tracep->declBit(c+58,"type_U", false,-1);
    tracep->declBit(c+30,"type_S", false,-1);
    tracep->declBit(c+37,"type_J", false,-1);
    tracep->declBit(c+36,"type_B", false,-1);
    tracep->declBit(c+31,"load", false,-1);
    tracep->declBit(c+30,"store", false,-1);
    tracep->declBit(c+64,"regwritepc", false,-1);
    tracep->declBit(c+31,"regwritemem", false,-1);
    tracep->declBit(c+65,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBit(c+208,"rst", false,-1);
    tracep->declBus(c+187,"npc", false,-1, 31,0);
    tracep->declBit(c+19,"ready", false,-1);
    tracep->declBus(c+103,"pc", false,-1, 31,0);
    tracep->declBus(c+20,"inst", false,-1, 31,0);
    tracep->declBit(c+21,"valid", false,-1);
    tracep->declBus(c+103,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+20,"instbridge", false,-1, 31,0);
    tracep->declBit(c+107,"pc_valid", false,-1);
    tracep->declBit(c+209,"infetch_ready", false,-1);
    tracep->pushNamePrefix("infetch0 ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBus(c+103,"pc", false,-1, 31,0);
    tracep->declBus(c+20,"inst", false,-1, 31,0);
    tracep->declBit(c+21,"valid_to", false,-1);
    tracep->declBit(c+107,"valid_from", false,-1);
    tracep->declBit(c+209,"ready_to", false,-1);
    tracep->declBit(c+19,"ready_from", false,-1);
    tracep->declBit(c+183,"state", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBus(c+187,"npc", false,-1, 31,0);
    tracep->declBit(c+208,"rst", false,-1);
    tracep->declBit(c+209,"ready_from", false,-1);
    tracep->declBus(c+103,"pcout", false,-1, 31,0);
    tracep->declBit(c+107,"valid_to", false,-1);
    tracep->declBus(c+217,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBit(c+208,"rst", false,-1);
    tracep->declBit(c+29,"ew", false,-1);
    tracep->declBus(c+24,"addr", false,-1, 4,0);
    tracep->declBus(c+22,"src1", false,-1, 4,0);
    tracep->declBus(c+23,"src2", false,-1, 4,0);
    tracep->declBus(c+66,"csr", false,-1, 11,0);
    tracep->declBus(c+188,"data", false,-1, 31,0);
    tracep->declBit(c+181,"csrrw", false,-1);
    tracep->declBit(c+182,"csrrs", false,-1);
    tracep->declBit(c+28,"ecallsig", false,-1);
    tracep->declBit(c+21,"valid", false,-1);
    tracep->declBus(c+189,"regout1", false,-1, 31,0);
    tracep->declBus(c+190,"regout2", false,-1, 31,0);
    tracep->declBus(c+104,"mepc", false,-1, 31,0);
    tracep->declBus(c+105,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+108+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+140+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+184,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+204,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+218,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+219,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+210,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+184,"out", false,-1, 1,0);
    tracep->declBus(c+66,"key", false,-1, 11,0);
    tracep->declQuad(c+220,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+218,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+219,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+210,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+213,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+184,"out", false,-1, 1,0);
    tracep->declBus(c+66,"key", false,-1, 11,0);
    tracep->declBus(c+222,"default_out", false,-1, 1,0);
    tracep->declQuad(c+220,"lut", false,-1, 55,0);
    tracep->declBus(c+223,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+185,"lut_out", false,-1, 1,0);
    tracep->declBit(c+67,"hit", false,-1);
    tracep->declBus(c+224,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBit(c+208,"rst", false,-1);
    tracep->declBit(c+186,"ew", false,-1);
    tracep->declBit(c+181,"csrrw", false,-1);
    tracep->declBit(c+182,"csrrs", false,-1);
    tracep->declBit(c+28,"ecall", false,-1);
    tracep->declBus(c+184,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+24,"addr", false,-1, 4,0);
    tracep->declBus(c+204,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+144+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+176+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+180,"i", false,-1, 31,0);
    tracep->declBus(c+225,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBus(c+191,"res", false,-1, 31,0);
    tracep->declBus(c+190,"regout2", false,-1, 31,0);
    tracep->declBit(c+30,"memew", false,-1);
    tracep->declBit(c+31,"memer", false,-1);
    tracep->declBus(c+33,"func3", false,-1, 2,0);
    tracep->declBus(c+25,"imm", false,-1, 31,0);
    tracep->declBus(c+192,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+34,"muxsig", false,-1, 2,0);
    tracep->declBit(c+21,"valid_from", false,-1);
    tracep->declBus(c+41,"memmask", false,-1, 2,0);
    tracep->declBit(c+42,"memsextsig", false,-1);
    tracep->declBus(c+188,"regwrite", false,-1, 31,0);
    tracep->declBit(c+19,"ready_to", false,-1);
    tracep->declBus(c+68,"memread", false,-1, 31,0);
    tracep->declBus(c+69,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+207,"clk", false,-1);
    tracep->declBus(c+191,"addr", false,-1, 31,0);
    tracep->declBus(c+190,"write", false,-1, 31,0);
    tracep->declBit(c+31,"er", false,-1);
    tracep->declBit(c+30,"ew", false,-1);
    tracep->declBus(c+41,"memmask", false,-1, 2,0);
    tracep->declBit(c+42,"memsextsig", false,-1);
    tracep->declBus(c+68,"read", false,-1, 31,0);
    tracep->declBit(c+21,"valid_from", false,-1);
    tracep->declBit(c+19,"ready_to", false,-1);
    tracep->declBus(c+70,"readreg", false,-1, 31,0);
    tracep->declBus(c+70,"read_u", false,-1, 31,0);
    tracep->declBus(c+71,"read_s", false,-1, 31,0);
    tracep->declBit(c+72,"state", false,-1);
    tracep->declBus(c+73,"read_sb", false,-1, 31,0);
    tracep->declBus(c+74,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+226,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+212,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+75,"input_number", false,-1, 7,0);
    tracep->declBus(c+73,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+227,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+212,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+76,"input_number", false,-1, 15,0);
    tracep->declBus(c+74,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+218,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+228,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+188,"out", false,-1, 31,0);
    tracep->declBus(c+34,"key", false,-1, 2,0);
    tracep->declBus(c+213,"default_out", false,-1, 31,0);
    tracep->declArray(c+86,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+218,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+228,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+188,"out", false,-1, 31,0);
    tracep->declBus(c+34,"key", false,-1, 2,0);
    tracep->declBus(c+213,"default_out", false,-1, 31,0);
    tracep->declArray(c+86,"lut", false,-1, 139,0);
    tracep->declBus(c+229,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+91+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+99+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+205,"lut_out", false,-1, 31,0);
    tracep->declBit(c+206,"hit", false,-1);
    tracep->declBus(c+224,"i", false,-1, 31,0);
    tracep->popNamePrefix(4);
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
    VlWide<5>/*159:0*/ __Vtemp_hdaf246d3__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullSData(oldp+3,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+4,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+5,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+6,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+7,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+8,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+9,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+10,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+15,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+16,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+17,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+18,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullBit(oldp+19,((1U & (~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)))));
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__ifu0__DOT__instbridge),32);
    bufp->fullBit(oldp+21,((0U != vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullCData(oldp+22,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+23,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+24,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 7U))),5);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+26,((0x100073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+27,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+28,((0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+29,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                            | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                     | (3U == (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__instbridge))))))));
    bufp->fullBit(oldp+30,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+31,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+32,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+33,((7U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+34,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+35,((1U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+36,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+37,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+38,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+39,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullCData(oldp+40,(vlSelf->top__DOT__aluop),2);
    bufp->fullCData(oldp+41,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+42,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+43,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+44,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+47,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+48,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+49,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+50,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+51,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+52,(((IData)((0x6000U == (0x6000U 
                                                   & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                               ? 8U : ((1U & VL_REDXOR_16(
                                                          (0x6000U 
                                                           & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                                        ? 9U : 3U))),4);
    bufp->fullCData(oldp+53,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+54,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+55,((0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)),7);
    bufp->fullBit(oldp+56,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+57,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+58,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+60,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__instbridge)),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+64,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                            | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                               | ((0x17U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                  | (0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge))))));
    bufp->fullBit(oldp+65,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullSData(oldp+66,((vlSelf->top__DOT__ifu0__DOT__instbridge 
                              >> 0x14U)),12);
    bufp->fullBit(oldp+67,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+69,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                              & (0U != vlSelf->top__DOT__ifu0__DOT__instbridge))),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__read_s),32);
    bufp->fullBit(oldp+72,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state));
    bufp->fullIData(oldp+73,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                 >> 7U)))) 
                               << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullIData(oldp+74,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                 >> 0xfU)))) 
                               << 0x10U) | (0xffffU 
                                            & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullCData(oldp+75,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),8);
    bufp->fullSData(oldp+76,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),16);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+77,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+80,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+82,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    __Vtemp_hdaf246d3__0[0U] = (IData)((0x400000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__pcwritereg))));
    __Vtemp_hdaf246d3__0[1U] = ((vlSelf->top__DOT__imm 
                                 << 3U) | (IData)((
                                                   (0x400000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__pcwritereg))) 
                                                   >> 0x20U)));
    __Vtemp_hdaf246d3__0[2U] = (0x10U | ((vlSelf->top__DOT__wbu0__DOT__memread 
                                          << 6U) | 
                                         (vlSelf->top__DOT__imm 
                                          >> 0x1dU)));
    __Vtemp_hdaf246d3__0[3U] = (0x40U | ((vlSelf->top__DOT__res 
                                          << 9U) | 
                                         (vlSelf->top__DOT__wbu0__DOT__memread 
                                          >> 0x1aU)));
    __Vtemp_hdaf246d3__0[4U] = (vlSelf->top__DOT__res 
                                >> 0x17U);
    bufp->fullWData(oldp+86,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+91,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+93,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+95,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+97,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+106,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullBit(oldp+107,(vlSelf->top__DOT__ifu0__DOT__pc_valid));
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+175,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+177,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+180,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+181,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+182,(vlSelf->top__DOT__csrrs));
    bufp->fullBit(oldp+183,(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__state));
    bufp->fullCData(oldp+184,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+185,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+186,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+189,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+190,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+193,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+194,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+195,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+196,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+197,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+198,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+199,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+200,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+201,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+202,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+203,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+204,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+205,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+206,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+207,(vlSelf->clk));
    bufp->fullBit(oldp+208,(vlSelf->rst));
    bufp->fullBit(oldp+209,(((~ (IData)(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__state)) 
                             & (0U != vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullIData(oldp+210,(2U),32);
    bufp->fullIData(oldp+211,(1U),32);
    bufp->fullIData(oldp+212,(0x20U),32);
    bufp->fullIData(oldp+213,(0U),32);
    bufp->fullIData(oldp+214,(0U),32);
    bufp->fullIData(oldp+215,(0x21U),32);
    bufp->fullIData(oldp+216,(2U),32);
    bufp->fullIData(oldp+217,(0x80000000U),32);
    bufp->fullIData(oldp+218,(4U),32);
    bufp->fullIData(oldp+219,(0xcU),32);
    bufp->fullQData(oldp+220,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+222,(0U),2);
    bufp->fullIData(oldp+223,(0xeU),32);
    bufp->fullIData(oldp+224,(4U),32);
    bufp->fullIData(oldp+225,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+226,(8U),32);
    bufp->fullIData(oldp+227,(0x10U),32);
    bufp->fullIData(oldp+228,(3U),32);
    bufp->fullIData(oldp+229,(0x23U),32);
}
