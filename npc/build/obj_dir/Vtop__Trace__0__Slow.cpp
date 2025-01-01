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
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBit(c+206,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBit(c+206,"rst", false,-1);
    tracep->declBit(c+178,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+185,"npc", false,-1, 31,0);
    tracep->declBus(c+101,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBit(c+20,"ifu_valid", false,-1);
    tracep->declBus(c+21,"src1", false,-1, 4,0);
    tracep->declBus(c+22,"src2", false,-1, 4,0);
    tracep->declBus(c+23,"rd", false,-1, 4,0);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBit(c+25,"ebreaksig", false,-1);
    tracep->declBit(c+26,"mretsig", false,-1);
    tracep->declBit(c+27,"ecallsig", false,-1);
    tracep->declBit(c+28,"regew", false,-1);
    tracep->declBit(c+29,"memew", false,-1);
    tracep->declBit(c+30,"memer", false,-1);
    tracep->declBit(c+31,"muximm", false,-1);
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBus(c+33,"muxsig", false,-1, 2,0);
    tracep->declBit(c+34,"func7", false,-1);
    tracep->declBit(c+35,"btypebranch", false,-1);
    tracep->declBit(c+36,"jalsig", false,-1);
    tracep->declBit(c+37,"jalrsig", false,-1);
    tracep->declBit(c+38,"auipcsig", false,-1);
    tracep->declBus(c+39,"aluop", false,-1, 1,0);
    tracep->declBit(c+179,"csrrw", false,-1);
    tracep->declBit(c+180,"csrrs", false,-1);
    tracep->declBit(c+20,"idu_valid", false,-1);
    tracep->declBus(c+40,"memmask", false,-1, 2,0);
    tracep->declBit(c+41,"memsextsig", false,-1);
    tracep->declBus(c+186,"regwrite", false,-1, 31,0);
    tracep->declBus(c+187,"regout1", false,-1, 31,0);
    tracep->declBus(c+188,"regout2", false,-1, 31,0);
    tracep->declBus(c+102,"mepc", false,-1, 31,0);
    tracep->declBus(c+103,"mtvec", false,-1, 31,0);
    tracep->declBit(c+178,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+189,"res", false,-1, 31,0);
    tracep->declBus(c+190,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+20,"exu_valid", false,-1);
    tracep->declBit(c+178,"ready_wbu_to_exu", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBit(c+35,"btypebranch", false,-1);
    tracep->declBit(c+34,"func7", false,-1);
    tracep->declBus(c+39,"aluop", false,-1, 1,0);
    tracep->declBit(c+37,"jalrsig", false,-1);
    tracep->declBit(c+36,"jalsig", false,-1);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBit(c+31,"muximm", false,-1);
    tracep->declBus(c+187,"regout1", false,-1, 31,0);
    tracep->declBus(c+188,"regout2", false,-1, 31,0);
    tracep->declBus(c+101,"pc", false,-1, 31,0);
    tracep->declBit(c+38,"auipcsig", false,-1);
    tracep->declBit(c+26,"mretsig", false,-1);
    tracep->declBit(c+27,"ecallsig", false,-1);
    tracep->declBus(c+103,"mtvec", false,-1, 31,0);
    tracep->declBus(c+102,"mepc", false,-1, 31,0);
    tracep->declBit(c+20,"valid_from", false,-1);
    tracep->declBit(c+178,"ready_from", false,-1);
    tracep->declBus(c+189,"res", false,-1, 31,0);
    tracep->declBus(c+185,"npc", false,-1, 31,0);
    tracep->declBus(c+190,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+20,"valid_to", false,-1);
    tracep->declBit(c+178,"ready_to", false,-1);
    tracep->declBus(c+104,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+191,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+42,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+192,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+193,"zero", false,-1);
    tracep->declBit(c+194,"signal", false,-1);
    tracep->declBit(c+195,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+187,"A", false,-1, 31,0);
    tracep->declBus(c+192,"B", false,-1, 31,0);
    tracep->declBus(c+42,"op", false,-1, 4,0);
    tracep->declBus(c+189,"res", false,-1, 31,0);
    tracep->declBit(c+193,"zero", false,-1);
    tracep->declBit(c+194,"signal", false,-1);
    tracep->declBit(c+195,"carry", false,-1);
    tracep->declBit(c+43,"addsig", false,-1);
    tracep->declBit(c+44,"logsig", false,-1);
    tracep->declBit(c+45,"shfsig", false,-1);
    tracep->declBit(c+46,"sltsig", false,-1);
    tracep->declBit(c+195,"carry_tmp", false,-1);
    tracep->declBit(c+47,"type_I", false,-1);
    tracep->declBus(c+196,"logres", false,-1, 31,0);
    tracep->declBus(c+197,"addres", false,-1, 31,0);
    tracep->declBit(c+198,"addzero", false,-1);
    tracep->declBus(c+199,"shfres", false,-1, 31,0);
    tracep->declBus(c+200,"sltres", false,-1, 31,0);
    tracep->declBus(c+187,"A_s", false,-1, 31,0);
    tracep->declBus(c+192,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBit(c+34,"func7", false,-1);
    tracep->declBus(c+39,"aluop", false,-1, 1,0);
    tracep->declBit(c+37,"jalrsig", false,-1);
    tracep->declBus(c+42,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+47,"type_I", false,-1);
    tracep->declBit(c+48,"type_B", false,-1);
    tracep->declBit(c+49,"type_R", false,-1);
    tracep->declBit(c+50,"addsig", false,-1);
    tracep->declBus(c+51,"branchop", false,-1, 3,0);
    tracep->declBus(c+52,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+35,"btypebranch", false,-1);
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBit(c+193,"zero", false,-1);
    tracep->declBit(c+194,"signal", false,-1);
    tracep->declBit(c+195,"carry", false,-1);
    tracep->declBus(c+189,"res", false,-1, 31,0);
    tracep->declBus(c+104,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+191,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+36,"jalsig", false,-1);
    tracep->declBit(c+37,"jalrsig", false,-1);
    tracep->declBit(c+38,"auipcsig", false,-1);
    tracep->declBit(c+26,"mretsig", false,-1);
    tracep->declBit(c+27,"ecallsig", false,-1);
    tracep->declBus(c+103,"mtvec", false,-1, 31,0);
    tracep->declBus(c+102,"mepc", false,-1, 31,0);
    tracep->declBus(c+185,"npc", false,-1, 31,0);
    tracep->declBus(c+190,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+210,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+192,"out", false,-1, 31,0);
    tracep->declBus(c+31,"key", false,-1, 0,0);
    tracep->declArray(c+75,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+210,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+192,"out", false,-1, 31,0);
    tracep->declBus(c+31,"key", false,-1, 0,0);
    tracep->declBus(c+213,"default_out", false,-1, 31,0);
    tracep->declArray(c+75,"lut", false,-1, 65,0);
    tracep->declBus(c+214,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+78+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+82+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+201,"lut_out", false,-1, 31,0);
    tracep->declBit(c+53,"hit", false,-1);
    tracep->declBus(c+215,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+101,"pc", false,-1, 31,0);
    tracep->declBus(c+104,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+101,"pc", false,-1, 31,0);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBus(c+191,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBit(c+20,"valid_from", false,-1);
    tracep->declBit(c+178,"ready_from", false,-1);
    tracep->declBit(c+25,"ebreaksig", false,-1);
    tracep->declBit(c+27,"ecallsig", false,-1);
    tracep->declBit(c+26,"mretsig", false,-1);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBit(c+34,"func7", false,-1);
    tracep->declBus(c+21,"src1", false,-1, 4,0);
    tracep->declBus(c+22,"src2", false,-1, 4,0);
    tracep->declBus(c+23,"rd", false,-1, 4,0);
    tracep->declBit(c+29,"memew", false,-1);
    tracep->declBus(c+33,"muxsig", false,-1, 2,0);
    tracep->declBit(c+30,"memer", false,-1);
    tracep->declBit(c+28,"regew", false,-1);
    tracep->declBit(c+31,"muximm", false,-1);
    tracep->declBit(c+35,"btypebranch", false,-1);
    tracep->declBit(c+37,"jalrsig", false,-1);
    tracep->declBit(c+36,"jalsig", false,-1);
    tracep->declBus(c+39,"aluop", false,-1, 1,0);
    tracep->declBit(c+38,"auipcsig", false,-1);
    tracep->declBit(c+179,"csrrw", false,-1);
    tracep->declBit(c+180,"csrrs", false,-1);
    tracep->declBit(c+20,"valid_to", false,-1);
    tracep->declBit(c+178,"ready_to", false,-1);
    tracep->declBus(c+40,"memmask", false,-1, 2,0);
    tracep->declBit(c+41,"memsextsig", false,-1);
    tracep->declBit(c+25,"ebreak", false,-1);
    tracep->declBit(c+27,"ecall", false,-1);
    tracep->declBit(c+26,"mret", false,-1);
    tracep->declBus(c+32,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+34,"func7bridge", false,-1);
    tracep->declBus(c+54,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBit(c+25,"ebreaksig", false,-1);
    tracep->declBit(c+27,"ecallsig", false,-1);
    tracep->declBit(c+26,"mretsig", false,-1);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBus(c+54,"opcode", false,-1, 6,0);
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBit(c+34,"func7", false,-1);
    tracep->declBus(c+21,"src1", false,-1, 4,0);
    tracep->declBus(c+22,"src2", false,-1, 4,0);
    tracep->declBus(c+23,"rd", false,-1, 4,0);
    tracep->declBus(c+40,"memmask", false,-1, 2,0);
    tracep->declBit(c+41,"memsextsig", false,-1);
    tracep->declBit(c+55,"type_I", false,-1);
    tracep->declBit(c+56,"type_R", false,-1);
    tracep->declBit(c+57,"type_U", false,-1);
    tracep->declBit(c+29,"type_S", false,-1);
    tracep->declBit(c+36,"type_J", false,-1);
    tracep->declBit(c+35,"type_B", false,-1);
    tracep->declBus(c+58,"I_imm", false,-1, 31,0);
    tracep->declBus(c+59,"U_imm", false,-1, 31,0);
    tracep->declBus(c+60,"S_imm", false,-1, 31,0);
    tracep->declBus(c+61,"J_imm", false,-1, 31,0);
    tracep->declBus(c+62,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+54,"opcode", false,-1, 6,0);
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBit(c+34,"func7", false,-1);
    tracep->declBit(c+25,"ebreaksig", false,-1);
    tracep->declBit(c+27,"ecallsig", false,-1);
    tracep->declBit(c+26,"mretsig", false,-1);
    tracep->declBit(c+29,"memew", false,-1);
    tracep->declBus(c+33,"muxsig", false,-1, 2,0);
    tracep->declBit(c+30,"memer", false,-1);
    tracep->declBit(c+28,"regew", false,-1);
    tracep->declBit(c+31,"muximm", false,-1);
    tracep->declBit(c+35,"btypebranch", false,-1);
    tracep->declBit(c+37,"jalrsig", false,-1);
    tracep->declBit(c+36,"jalsig", false,-1);
    tracep->declBus(c+39,"aluop", false,-1, 1,0);
    tracep->declBit(c+38,"auipcsig", false,-1);
    tracep->declBit(c+179,"csrrw", false,-1);
    tracep->declBit(c+180,"csrrs", false,-1);
    tracep->declBit(c+55,"type_I", false,-1);
    tracep->declBit(c+56,"type_R", false,-1);
    tracep->declBit(c+57,"type_U", false,-1);
    tracep->declBit(c+29,"type_S", false,-1);
    tracep->declBit(c+36,"type_J", false,-1);
    tracep->declBit(c+35,"type_B", false,-1);
    tracep->declBit(c+30,"load", false,-1);
    tracep->declBit(c+29,"store", false,-1);
    tracep->declBit(c+63,"regwritepc", false,-1);
    tracep->declBit(c+30,"regwritemem", false,-1);
    tracep->declBit(c+64,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBit(c+206,"rst", false,-1);
    tracep->declBus(c+185,"npc", false,-1, 31,0);
    tracep->declBit(c+178,"ready", false,-1);
    tracep->declBus(c+101,"pc", false,-1, 31,0);
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBit(c+20,"valid", false,-1);
    tracep->declBus(c+101,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+19,"instbridge", false,-1, 31,0);
    tracep->declBit(c+207,"infetch_ready", false,-1);
    tracep->pushNamePrefix("infetch0 ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBus(c+185,"pc", false,-1, 31,0);
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBit(c+20,"valid_to", false,-1);
    tracep->declBit(c+207,"ready_to", false,-1);
    tracep->declBit(c+178,"ready_from", false,-1);
    tracep->declBit(c+65,"state", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBus(c+185,"npc", false,-1, 31,0);
    tracep->declBit(c+206,"rst", false,-1);
    tracep->declBit(c+207,"ready_from", false,-1);
    tracep->declBus(c+101,"pcout", false,-1, 31,0);
    tracep->declBus(c+216,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBit(c+206,"rst", false,-1);
    tracep->declBit(c+28,"ew", false,-1);
    tracep->declBus(c+23,"addr", false,-1, 4,0);
    tracep->declBus(c+21,"src1", false,-1, 4,0);
    tracep->declBus(c+22,"src2", false,-1, 4,0);
    tracep->declBus(c+66,"csr", false,-1, 11,0);
    tracep->declBus(c+186,"data", false,-1, 31,0);
    tracep->declBit(c+179,"csrrw", false,-1);
    tracep->declBit(c+180,"csrrs", false,-1);
    tracep->declBit(c+27,"ecallsig", false,-1);
    tracep->declBit(c+20,"valid", false,-1);
    tracep->declBus(c+187,"regout1", false,-1, 31,0);
    tracep->declBus(c+188,"regout2", false,-1, 31,0);
    tracep->declBus(c+102,"mepc", false,-1, 31,0);
    tracep->declBus(c+103,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+105+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+137+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+181,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+202,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+181,"out", false,-1, 1,0);
    tracep->declBus(c+66,"key", false,-1, 11,0);
    tracep->declQuad(c+219,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+181,"out", false,-1, 1,0);
    tracep->declBus(c+66,"key", false,-1, 11,0);
    tracep->declBus(c+221,"default_out", false,-1, 1,0);
    tracep->declQuad(c+219,"lut", false,-1, 55,0);
    tracep->declBus(c+222,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+182,"lut_out", false,-1, 1,0);
    tracep->declBit(c+67,"hit", false,-1);
    tracep->declBus(c+223,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBit(c+206,"rst", false,-1);
    tracep->declBit(c+183,"ew", false,-1);
    tracep->declBit(c+179,"csrrw", false,-1);
    tracep->declBit(c+180,"csrrs", false,-1);
    tracep->declBit(c+27,"ecall", false,-1);
    tracep->declBus(c+181,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+23,"addr", false,-1, 4,0);
    tracep->declBus(c+202,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+141+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+173+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+177,"i", false,-1, 31,0);
    tracep->declBus(c+224,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBus(c+189,"res", false,-1, 31,0);
    tracep->declBus(c+188,"regout2", false,-1, 31,0);
    tracep->declBit(c+29,"memew", false,-1);
    tracep->declBit(c+30,"memer", false,-1);
    tracep->declBus(c+32,"func3", false,-1, 2,0);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBus(c+190,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+33,"muxsig", false,-1, 2,0);
    tracep->declBit(c+20,"valid_from", false,-1);
    tracep->declBus(c+40,"memmask", false,-1, 2,0);
    tracep->declBit(c+41,"memsextsig", false,-1);
    tracep->declBus(c+186,"regwrite", false,-1, 31,0);
    tracep->declBit(c+178,"ready_to", false,-1);
    tracep->declBus(c+68,"memread", false,-1, 31,0);
    tracep->declBus(c+208,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+205,"clk", false,-1);
    tracep->declBus(c+189,"addr", false,-1, 31,0);
    tracep->declBus(c+188,"write", false,-1, 31,0);
    tracep->declBit(c+30,"er", false,-1);
    tracep->declBit(c+29,"ew", false,-1);
    tracep->declBus(c+40,"memmask", false,-1, 2,0);
    tracep->declBit(c+41,"memsextsig", false,-1);
    tracep->declBus(c+68,"read", false,-1, 31,0);
    tracep->declBit(c+20,"valid_from", false,-1);
    tracep->declBit(c+178,"ready_to", false,-1);
    tracep->declBus(c+69,"readreg", false,-1, 31,0);
    tracep->declBus(c+69,"read_u", false,-1, 31,0);
    tracep->declBus(c+70,"read_s", false,-1, 31,0);
    tracep->declBit(c+184,"state", false,-1);
    tracep->declBus(c+71,"read_sb", false,-1, 31,0);
    tracep->declBus(c+72,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+225,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+211,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+73,"input_number", false,-1, 7,0);
    tracep->declBus(c+71,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+226,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+211,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+74,"input_number", false,-1, 15,0);
    tracep->declBus(c+72,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+227,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+186,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 2,0);
    tracep->declBus(c+212,"default_out", false,-1, 31,0);
    tracep->declArray(c+84,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+227,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+210,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+186,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 2,0);
    tracep->declBus(c+212,"default_out", false,-1, 31,0);
    tracep->declArray(c+84,"lut", false,-1, 139,0);
    tracep->declBus(c+228,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+89+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+97+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+203,"lut_out", false,-1, 31,0);
    tracep->declBit(c+204,"hit", false,-1);
    tracep->declBus(c+223,"i", false,-1, 31,0);
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
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__ifu0__DOT__instbridge),32);
    bufp->fullBit(oldp+20,((0U != vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullCData(oldp+21,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+22,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+23,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 7U))),5);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+25,((0x100073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+26,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+27,((0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+28,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                            | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                     | (3U == (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__instbridge))))))));
    bufp->fullBit(oldp+29,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+30,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+32,((7U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+33,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+34,((1U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+35,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+36,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+37,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+38,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullCData(oldp+39,(vlSelf->top__DOT__aluop),2);
    bufp->fullCData(oldp+40,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+42,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+43,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+44,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+47,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+48,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+49,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+50,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+51,(((IData)((0x6000U == (0x6000U 
                                                   & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                               ? 8U : ((1U & VL_REDXOR_16(
                                                          (0x6000U 
                                                           & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                                        ? 9U : 3U))),4);
    bufp->fullCData(oldp+52,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+53,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+54,((0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)),7);
    bufp->fullBit(oldp+55,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+56,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+57,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+59,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__instbridge)),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+63,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                            | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                               | ((0x17U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                  | (0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge))))));
    bufp->fullBit(oldp+64,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+65,(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__state));
    bufp->fullSData(oldp+66,((vlSelf->top__DOT__ifu0__DOT__instbridge 
                              >> 0x14U)),12);
    bufp->fullBit(oldp+67,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__read_s),32);
    bufp->fullIData(oldp+71,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                 >> 7U)))) 
                               << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullIData(oldp+72,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                 >> 0xfU)))) 
                               << 0x10U) | (0xffffU 
                                            & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullCData(oldp+73,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),8);
    bufp->fullSData(oldp+74,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),16);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+75,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+78,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+80,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+84,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+89,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+91,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+93,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+95,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+104,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+175,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+177,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+178,((1U & (~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)))));
    bufp->fullBit(oldp+179,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+180,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+181,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+182,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+183,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullBit(oldp+184,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state));
    bufp->fullIData(oldp+185,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+186,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+189,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+190,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+193,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+194,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+195,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+196,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+197,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+198,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+199,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+200,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+201,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+202,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+203,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+204,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+205,(vlSelf->clk));
    bufp->fullBit(oldp+206,(vlSelf->rst));
    bufp->fullBit(oldp+207,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                             & (0U != vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullIData(oldp+208,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                               & (0U != vlSelf->top__DOT__ifu0__DOT__instbridge))),32);
    bufp->fullIData(oldp+209,(2U),32);
    bufp->fullIData(oldp+210,(1U),32);
    bufp->fullIData(oldp+211,(0x20U),32);
    bufp->fullIData(oldp+212,(0U),32);
    bufp->fullIData(oldp+213,(0U),32);
    bufp->fullIData(oldp+214,(0x21U),32);
    bufp->fullIData(oldp+215,(2U),32);
    bufp->fullIData(oldp+216,(0x7ffffffcU),32);
    bufp->fullIData(oldp+217,(4U),32);
    bufp->fullIData(oldp+218,(0xcU),32);
    bufp->fullQData(oldp+219,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+221,(0U),2);
    bufp->fullIData(oldp+222,(0xeU),32);
    bufp->fullIData(oldp+223,(4U),32);
    bufp->fullIData(oldp+224,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+225,(8U),32);
    bufp->fullIData(oldp+226,(0x10U),32);
    bufp->fullIData(oldp+227,(3U),32);
    bufp->fullIData(oldp+228,(0x23U),32);
}
