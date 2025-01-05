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
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBit(c+222,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBit(c+222,"rst", false,-1);
    tracep->declBit(c+194,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+201,"npc", false,-1, 31,0);
    tracep->declBus(c+117,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+34,"inst", false,-1, 31,0);
    tracep->declBit(c+35,"ifu_valid", false,-1);
    tracep->declBus(c+36,"src1", false,-1, 4,0);
    tracep->declBus(c+37,"src2", false,-1, 4,0);
    tracep->declBus(c+38,"rd", false,-1, 4,0);
    tracep->declBus(c+39,"imm", false,-1, 31,0);
    tracep->declBit(c+40,"ebreaksig", false,-1);
    tracep->declBit(c+41,"mretsig", false,-1);
    tracep->declBit(c+42,"ecallsig", false,-1);
    tracep->declBit(c+43,"regew", false,-1);
    tracep->declBit(c+44,"memew", false,-1);
    tracep->declBit(c+45,"memer", false,-1);
    tracep->declBit(c+46,"muximm", false,-1);
    tracep->declBus(c+47,"func3", false,-1, 2,0);
    tracep->declBus(c+48,"muxsig", false,-1, 2,0);
    tracep->declBit(c+49,"func7", false,-1);
    tracep->declBit(c+50,"btypebranch", false,-1);
    tracep->declBit(c+51,"jalsig", false,-1);
    tracep->declBit(c+52,"jalrsig", false,-1);
    tracep->declBit(c+53,"auipcsig", false,-1);
    tracep->declBus(c+54,"aluop", false,-1, 1,0);
    tracep->declBit(c+195,"csrrw", false,-1);
    tracep->declBit(c+196,"csrrs", false,-1);
    tracep->declBit(c+35,"idu_valid", false,-1);
    tracep->declBus(c+55,"memmask", false,-1, 2,0);
    tracep->declBit(c+56,"memsextsig", false,-1);
    tracep->declBus(c+202,"regwrite", false,-1, 31,0);
    tracep->declBus(c+203,"regout1", false,-1, 31,0);
    tracep->declBus(c+204,"regout2", false,-1, 31,0);
    tracep->declBus(c+118,"mepc", false,-1, 31,0);
    tracep->declBus(c+119,"mtvec", false,-1, 31,0);
    tracep->declBit(c+194,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+205,"res", false,-1, 31,0);
    tracep->declBus(c+206,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+35,"exu_valid", false,-1);
    tracep->declBit(c+194,"ready_wbu_to_exu", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+47,"func3", false,-1, 2,0);
    tracep->declBit(c+50,"btypebranch", false,-1);
    tracep->declBit(c+49,"func7", false,-1);
    tracep->declBus(c+54,"aluop", false,-1, 1,0);
    tracep->declBit(c+52,"jalrsig", false,-1);
    tracep->declBit(c+51,"jalsig", false,-1);
    tracep->declBus(c+39,"imm", false,-1, 31,0);
    tracep->declBit(c+46,"muximm", false,-1);
    tracep->declBus(c+203,"regout1", false,-1, 31,0);
    tracep->declBus(c+204,"regout2", false,-1, 31,0);
    tracep->declBus(c+117,"pc", false,-1, 31,0);
    tracep->declBit(c+53,"auipcsig", false,-1);
    tracep->declBit(c+41,"mretsig", false,-1);
    tracep->declBit(c+42,"ecallsig", false,-1);
    tracep->declBus(c+119,"mtvec", false,-1, 31,0);
    tracep->declBus(c+118,"mepc", false,-1, 31,0);
    tracep->declBit(c+35,"valid_from", false,-1);
    tracep->declBit(c+194,"ready_from", false,-1);
    tracep->declBus(c+205,"res", false,-1, 31,0);
    tracep->declBus(c+201,"npc", false,-1, 31,0);
    tracep->declBus(c+206,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+35,"valid_to", false,-1);
    tracep->declBit(c+194,"ready_to", false,-1);
    tracep->declBus(c+120,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+207,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+57,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+208,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+209,"zero", false,-1);
    tracep->declBit(c+210,"signal", false,-1);
    tracep->declBit(c+211,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+203,"A", false,-1, 31,0);
    tracep->declBus(c+208,"B", false,-1, 31,0);
    tracep->declBus(c+57,"op", false,-1, 4,0);
    tracep->declBus(c+205,"res", false,-1, 31,0);
    tracep->declBit(c+209,"zero", false,-1);
    tracep->declBit(c+210,"signal", false,-1);
    tracep->declBit(c+211,"carry", false,-1);
    tracep->declBit(c+58,"addsig", false,-1);
    tracep->declBit(c+59,"logsig", false,-1);
    tracep->declBit(c+60,"shfsig", false,-1);
    tracep->declBit(c+61,"sltsig", false,-1);
    tracep->declBit(c+211,"carry_tmp", false,-1);
    tracep->declBit(c+62,"type_I", false,-1);
    tracep->declBus(c+212,"logres", false,-1, 31,0);
    tracep->declBus(c+213,"addres", false,-1, 31,0);
    tracep->declBit(c+214,"addzero", false,-1);
    tracep->declBus(c+215,"shfres", false,-1, 31,0);
    tracep->declBus(c+216,"sltres", false,-1, 31,0);
    tracep->declBus(c+203,"A_s", false,-1, 31,0);
    tracep->declBus(c+208,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+47,"func3", false,-1, 2,0);
    tracep->declBit(c+49,"func7", false,-1);
    tracep->declBus(c+54,"aluop", false,-1, 1,0);
    tracep->declBit(c+52,"jalrsig", false,-1);
    tracep->declBus(c+57,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+62,"type_I", false,-1);
    tracep->declBit(c+63,"type_B", false,-1);
    tracep->declBit(c+64,"type_R", false,-1);
    tracep->declBit(c+65,"addsig", false,-1);
    tracep->declBus(c+66,"branchop", false,-1, 3,0);
    tracep->declBus(c+67,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+50,"btypebranch", false,-1);
    tracep->declBus(c+47,"func3", false,-1, 2,0);
    tracep->declBit(c+209,"zero", false,-1);
    tracep->declBit(c+210,"signal", false,-1);
    tracep->declBit(c+211,"carry", false,-1);
    tracep->declBus(c+205,"res", false,-1, 31,0);
    tracep->declBus(c+120,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+207,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+51,"jalsig", false,-1);
    tracep->declBit(c+52,"jalrsig", false,-1);
    tracep->declBit(c+53,"auipcsig", false,-1);
    tracep->declBit(c+41,"mretsig", false,-1);
    tracep->declBit(c+42,"ecallsig", false,-1);
    tracep->declBus(c+119,"mtvec", false,-1, 31,0);
    tracep->declBus(c+118,"mepc", false,-1, 31,0);
    tracep->declBus(c+201,"npc", false,-1, 31,0);
    tracep->declBus(c+206,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+225,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+226,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+227,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+208,"out", false,-1, 31,0);
    tracep->declBus(c+46,"key", false,-1, 0,0);
    tracep->declArray(c+91,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+225,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+226,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+227,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+228,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+208,"out", false,-1, 31,0);
    tracep->declBus(c+46,"key", false,-1, 0,0);
    tracep->declBus(c+229,"default_out", false,-1, 31,0);
    tracep->declArray(c+91,"lut", false,-1, 65,0);
    tracep->declBus(c+230,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+94+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+98+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+217,"lut_out", false,-1, 31,0);
    tracep->declBit(c+68,"hit", false,-1);
    tracep->declBus(c+231,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+117,"pc", false,-1, 31,0);
    tracep->declBus(c+120,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+117,"pc", false,-1, 31,0);
    tracep->declBus(c+39,"imm", false,-1, 31,0);
    tracep->declBus(c+207,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+34,"inst", false,-1, 31,0);
    tracep->declBit(c+35,"valid_from", false,-1);
    tracep->declBit(c+194,"ready_from", false,-1);
    tracep->declBit(c+40,"ebreaksig", false,-1);
    tracep->declBit(c+42,"ecallsig", false,-1);
    tracep->declBit(c+41,"mretsig", false,-1);
    tracep->declBus(c+39,"imm", false,-1, 31,0);
    tracep->declBus(c+47,"func3", false,-1, 2,0);
    tracep->declBit(c+49,"func7", false,-1);
    tracep->declBus(c+36,"src1", false,-1, 4,0);
    tracep->declBus(c+37,"src2", false,-1, 4,0);
    tracep->declBus(c+38,"rd", false,-1, 4,0);
    tracep->declBit(c+44,"memew", false,-1);
    tracep->declBus(c+48,"muxsig", false,-1, 2,0);
    tracep->declBit(c+45,"memer", false,-1);
    tracep->declBit(c+43,"regew", false,-1);
    tracep->declBit(c+46,"muximm", false,-1);
    tracep->declBit(c+50,"btypebranch", false,-1);
    tracep->declBit(c+52,"jalrsig", false,-1);
    tracep->declBit(c+51,"jalsig", false,-1);
    tracep->declBus(c+54,"aluop", false,-1, 1,0);
    tracep->declBit(c+53,"auipcsig", false,-1);
    tracep->declBit(c+195,"csrrw", false,-1);
    tracep->declBit(c+196,"csrrs", false,-1);
    tracep->declBit(c+35,"valid_to", false,-1);
    tracep->declBit(c+194,"ready_to", false,-1);
    tracep->declBus(c+55,"memmask", false,-1, 2,0);
    tracep->declBit(c+56,"memsextsig", false,-1);
    tracep->declBit(c+40,"ebreak", false,-1);
    tracep->declBit(c+42,"ecall", false,-1);
    tracep->declBit(c+41,"mret", false,-1);
    tracep->declBus(c+47,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+49,"func7bridge", false,-1);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+34,"inst", false,-1, 31,0);
    tracep->declBit(c+40,"ebreaksig", false,-1);
    tracep->declBit(c+42,"ecallsig", false,-1);
    tracep->declBit(c+41,"mretsig", false,-1);
    tracep->declBus(c+39,"imm", false,-1, 31,0);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+47,"func3", false,-1, 2,0);
    tracep->declBit(c+49,"func7", false,-1);
    tracep->declBus(c+36,"src1", false,-1, 4,0);
    tracep->declBus(c+37,"src2", false,-1, 4,0);
    tracep->declBus(c+38,"rd", false,-1, 4,0);
    tracep->declBus(c+55,"memmask", false,-1, 2,0);
    tracep->declBit(c+56,"memsextsig", false,-1);
    tracep->declBit(c+70,"type_I", false,-1);
    tracep->declBit(c+71,"type_R", false,-1);
    tracep->declBit(c+72,"type_U", false,-1);
    tracep->declBit(c+44,"type_S", false,-1);
    tracep->declBit(c+51,"type_J", false,-1);
    tracep->declBit(c+50,"type_B", false,-1);
    tracep->declBus(c+73,"I_imm", false,-1, 31,0);
    tracep->declBus(c+74,"U_imm", false,-1, 31,0);
    tracep->declBus(c+75,"S_imm", false,-1, 31,0);
    tracep->declBus(c+76,"J_imm", false,-1, 31,0);
    tracep->declBus(c+77,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+47,"func3", false,-1, 2,0);
    tracep->declBit(c+49,"func7", false,-1);
    tracep->declBit(c+40,"ebreaksig", false,-1);
    tracep->declBit(c+42,"ecallsig", false,-1);
    tracep->declBit(c+41,"mretsig", false,-1);
    tracep->declBit(c+44,"memew", false,-1);
    tracep->declBus(c+48,"muxsig", false,-1, 2,0);
    tracep->declBit(c+45,"memer", false,-1);
    tracep->declBit(c+43,"regew", false,-1);
    tracep->declBit(c+46,"muximm", false,-1);
    tracep->declBit(c+50,"btypebranch", false,-1);
    tracep->declBit(c+52,"jalrsig", false,-1);
    tracep->declBit(c+51,"jalsig", false,-1);
    tracep->declBus(c+54,"aluop", false,-1, 1,0);
    tracep->declBit(c+53,"auipcsig", false,-1);
    tracep->declBit(c+195,"csrrw", false,-1);
    tracep->declBit(c+196,"csrrs", false,-1);
    tracep->declBit(c+70,"type_I", false,-1);
    tracep->declBit(c+71,"type_R", false,-1);
    tracep->declBit(c+72,"type_U", false,-1);
    tracep->declBit(c+44,"type_S", false,-1);
    tracep->declBit(c+51,"type_J", false,-1);
    tracep->declBit(c+50,"type_B", false,-1);
    tracep->declBit(c+45,"load", false,-1);
    tracep->declBit(c+44,"store", false,-1);
    tracep->declBit(c+78,"regwritepc", false,-1);
    tracep->declBit(c+45,"regwritemem", false,-1);
    tracep->declBit(c+79,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBit(c+222,"rst", false,-1);
    tracep->declBus(c+201,"npc", false,-1, 31,0);
    tracep->declBit(c+194,"ready", false,-1);
    tracep->declBus(c+117,"pc", false,-1, 31,0);
    tracep->declBus(c+34,"inst", false,-1, 31,0);
    tracep->declBit(c+35,"valid", false,-1);
    tracep->declBus(c+117,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+34,"instbridge", false,-1, 31,0);
    tracep->declBit(c+223,"infetch_ready", false,-1);
    tracep->declBit(c+80,"arready", false,-1);
    tracep->declBit(c+80,"rready", false,-1);
    tracep->declBit(c+232,"arvalid", false,-1);
    tracep->declBit(c+233,"rvalid", false,-1);
    tracep->declBit(c+80,"awready", false,-1);
    tracep->declBit(c+80,"wready", false,-1);
    tracep->declBit(c+234,"bvalid", false,-1);
    tracep->declBit(c+235,"bresp", false,-1);
    tracep->pushNamePrefix("infetch ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBit(c+236,"awvalid", false,-1);
    tracep->declBit(c+80,"awready", false,-1);
    tracep->declBus(c+228,"awaddr", false,-1, 31,0);
    tracep->declBit(c+236,"wvalid", false,-1);
    tracep->declBit(c+80,"wready", false,-1);
    tracep->declBus(c+228,"wdata", false,-1, 31,0);
    tracep->declBus(c+237,"wstrb", false,-1, 3,0);
    tracep->declBit(c+234,"bvalid", false,-1);
    tracep->declBit(c+236,"bready", false,-1);
    tracep->declBit(c+235,"bresp", false,-1);
    tracep->declBit(c+194,"arvalid", false,-1);
    tracep->declBit(c+80,"arready", false,-1);
    tracep->declBus(c+117,"araddr", false,-1, 31,0);
    tracep->declBit(c+194,"rvalid", false,-1);
    tracep->declBit(c+80,"rready", false,-1);
    tracep->declBus(c+34,"rdata", false,-1, 31,0);
    tracep->declBus(c+81,"state", false,-1, 1,0);
    tracep->declBus(c+3,"memmask", false,-1, 2,0);
    tracep->declBus(c+34,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+238,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+239,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+3,"out", false,-1, 2,0);
    tracep->declBus(c+237,"key", false,-1, 3,0);
    tracep->declBus(c+240,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+238,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+239,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+228,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+3,"out", false,-1, 2,0);
    tracep->declBus(c+237,"key", false,-1, 3,0);
    tracep->declBus(c+241,"default_out", false,-1, 2,0);
    tracep->declBus(c+240,"lut", false,-1, 27,0);
    tracep->declBus(c+242,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+4+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+8+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+12+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+16,"lut_out", false,-1, 2,0);
    tracep->declBit(c+17,"hit", false,-1);
    tracep->declBus(c+243,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBus(c+201,"npc", false,-1, 31,0);
    tracep->declBit(c+222,"rst", false,-1);
    tracep->declBit(c+223,"ready_from", false,-1);
    tracep->declBus(c+117,"pcout", false,-1, 31,0);
    tracep->declBus(c+244,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBit(c+222,"rst", false,-1);
    tracep->declBit(c+43,"ew", false,-1);
    tracep->declBus(c+38,"addr", false,-1, 4,0);
    tracep->declBus(c+36,"src1", false,-1, 4,0);
    tracep->declBus(c+37,"src2", false,-1, 4,0);
    tracep->declBus(c+82,"csr", false,-1, 11,0);
    tracep->declBus(c+202,"data", false,-1, 31,0);
    tracep->declBit(c+195,"csrrw", false,-1);
    tracep->declBit(c+196,"csrrs", false,-1);
    tracep->declBit(c+42,"ecallsig", false,-1);
    tracep->declBit(c+35,"valid", false,-1);
    tracep->declBus(c+203,"regout1", false,-1, 31,0);
    tracep->declBus(c+204,"regout2", false,-1, 31,0);
    tracep->declBus(c+118,"mepc", false,-1, 31,0);
    tracep->declBus(c+119,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+121+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+153+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+197,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+218,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+245,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+225,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+197,"out", false,-1, 1,0);
    tracep->declBus(c+82,"key", false,-1, 11,0);
    tracep->declQuad(c+246,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+245,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+225,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+228,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+197,"out", false,-1, 1,0);
    tracep->declBus(c+82,"key", false,-1, 11,0);
    tracep->declBus(c+248,"default_out", false,-1, 1,0);
    tracep->declQuad(c+246,"lut", false,-1, 55,0);
    tracep->declBus(c+249,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+18+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+22+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+26+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+198,"lut_out", false,-1, 1,0);
    tracep->declBit(c+83,"hit", false,-1);
    tracep->declBus(c+243,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBit(c+222,"rst", false,-1);
    tracep->declBit(c+199,"ew", false,-1);
    tracep->declBit(c+195,"csrrw", false,-1);
    tracep->declBit(c+196,"csrrs", false,-1);
    tracep->declBit(c+42,"ecall", false,-1);
    tracep->declBus(c+197,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+38,"addr", false,-1, 4,0);
    tracep->declBus(c+218,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+157+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+189+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+193,"i", false,-1, 31,0);
    tracep->declBus(c+250,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBus(c+205,"res", false,-1, 31,0);
    tracep->declBus(c+204,"regout2", false,-1, 31,0);
    tracep->declBit(c+44,"memew", false,-1);
    tracep->declBit(c+45,"memer", false,-1);
    tracep->declBus(c+39,"imm", false,-1, 31,0);
    tracep->declBus(c+206,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+48,"muxsig", false,-1, 2,0);
    tracep->declBit(c+35,"valid_from", false,-1);
    tracep->declBus(c+55,"memmask", false,-1, 2,0);
    tracep->declBit(c+56,"memsextsig", false,-1);
    tracep->declBus(c+202,"regwrite", false,-1, 31,0);
    tracep->declBit(c+194,"ready_to", false,-1);
    tracep->declBus(c+84,"memread", false,-1, 31,0);
    tracep->declBus(c+224,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+221,"clk", false,-1);
    tracep->declBus(c+205,"addr", false,-1, 31,0);
    tracep->declBus(c+204,"write", false,-1, 31,0);
    tracep->declBit(c+45,"er", false,-1);
    tracep->declBit(c+44,"ew", false,-1);
    tracep->declBus(c+55,"memmask", false,-1, 2,0);
    tracep->declBit(c+56,"memsextsig", false,-1);
    tracep->declBus(c+84,"read", false,-1, 31,0);
    tracep->declBit(c+35,"valid_from", false,-1);
    tracep->declBit(c+194,"ready_to", false,-1);
    tracep->declBus(c+85,"readreg", false,-1, 31,0);
    tracep->declBus(c+85,"read_u", false,-1, 31,0);
    tracep->declBus(c+86,"read_s", false,-1, 31,0);
    tracep->declBit(c+200,"state", false,-1);
    tracep->declBus(c+87,"read_sb", false,-1, 31,0);
    tracep->declBus(c+88,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+251,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+227,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+89,"input_number", false,-1, 7,0);
    tracep->declBus(c+87,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+252,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+227,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+90,"input_number", false,-1, 15,0);
    tracep->declBus(c+88,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+239,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+227,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+202,"out", false,-1, 31,0);
    tracep->declBus(c+48,"key", false,-1, 2,0);
    tracep->declBus(c+228,"default_out", false,-1, 31,0);
    tracep->declArray(c+100,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+239,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+227,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+226,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+202,"out", false,-1, 31,0);
    tracep->declBus(c+48,"key", false,-1, 2,0);
    tracep->declBus(c+228,"default_out", false,-1, 31,0);
    tracep->declArray(c+100,"lut", false,-1, 139,0);
    tracep->declBus(c+253,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+105+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+30+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+113+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+219,"lut_out", false,-1, 31,0);
    tracep->declBit(c+220,"hit", false,-1);
    tracep->declBus(c+243,"i", false,-1, 31,0);
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
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__memmask),3);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+15,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
    bufp->fullCData(oldp+16,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+17,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullSData(oldp+18,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+19,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+20,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+21,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+22,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+23,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+24,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+25,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+26,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+27,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+28,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+29,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+30,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+31,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+32,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+33,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg),32);
    bufp->fullBit(oldp+35,((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullCData(oldp+36,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+37,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+38,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                       >> 7U))),5);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+40,((0x100073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+41,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+42,((0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+43,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                            | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                     | (3U == (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))))));
    bufp->fullBit(oldp+44,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+45,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+47,((7U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+48,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+49,((1U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+50,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+51,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+52,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+53,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullCData(oldp+54,(vlSelf->top__DOT__aluop),2);
    bufp->fullCData(oldp+55,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+56,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+57,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+58,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+59,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+60,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+61,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+62,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+63,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+64,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+65,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+66,(((IData)((0x6000U == (0x6000U 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                               ? 8U : ((1U & VL_REDXOR_16(
                                                          (0x6000U 
                                                           & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                                        ? 9U : 3U))),4);
    bufp->fullCData(oldp+67,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+68,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+69,((0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),7);
    bufp->fullBit(oldp+70,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+71,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+72,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+74,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+78,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                            | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                               | ((0x17U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                  | (0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))));
    bufp->fullBit(oldp+79,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+80,((0U == (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state))));
    bufp->fullCData(oldp+81,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state),2);
    bufp->fullSData(oldp+82,((vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                              >> 0x14U)),12);
    bufp->fullBit(oldp+83,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__read_s),32);
    bufp->fullIData(oldp+87,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                 >> 7U)))) 
                               << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullIData(oldp+88,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                 >> 0xfU)))) 
                               << 0x10U) | (0xffffU 
                                            & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullCData(oldp+89,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),8);
    bufp->fullSData(oldp+90,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),16);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+91,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+94,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+96,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+100,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+105,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+107,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+109,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+111,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+120,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+175,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+177,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+180,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+181,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+182,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+183,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+184,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+185,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+186,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+189,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+190,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+193,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+194,((1U & (~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)))));
    bufp->fullBit(oldp+195,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+196,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+197,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+198,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+199,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullBit(oldp+200,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state));
    bufp->fullIData(oldp+201,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+202,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+203,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+204,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+205,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+206,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+207,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+208,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+209,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+210,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+211,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+212,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+213,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+214,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+215,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+216,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+217,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+218,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+219,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+220,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+221,(vlSelf->clk));
    bufp->fullBit(oldp+222,(vlSelf->rst));
    bufp->fullBit(oldp+223,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                             & (0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullIData(oldp+224,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                               & (0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))),32);
    bufp->fullIData(oldp+225,(2U),32);
    bufp->fullIData(oldp+226,(1U),32);
    bufp->fullIData(oldp+227,(0x20U),32);
    bufp->fullIData(oldp+228,(0U),32);
    bufp->fullIData(oldp+229,(0U),32);
    bufp->fullIData(oldp+230,(0x21U),32);
    bufp->fullIData(oldp+231,(2U),32);
    bufp->fullBit(oldp+232,(vlSelf->top__DOT__ifu0__DOT__arvalid));
    bufp->fullBit(oldp+233,(vlSelf->top__DOT__ifu0__DOT__rvalid));
    bufp->fullBit(oldp+234,(vlSelf->top__DOT__ifu0__DOT__bvalid));
    bufp->fullBit(oldp+235,(vlSelf->top__DOT__ifu0__DOT__bresp));
    bufp->fullBit(oldp+236,(0U));
    bufp->fullCData(oldp+237,(0U),4);
    bufp->fullIData(oldp+238,(4U),32);
    bufp->fullIData(oldp+239,(3U),32);
    bufp->fullIData(oldp+240,(0x12491c4U),28);
    bufp->fullCData(oldp+241,(0U),3);
    bufp->fullIData(oldp+242,(7U),32);
    bufp->fullIData(oldp+243,(4U),32);
    bufp->fullIData(oldp+244,(0x80000000U),32);
    bufp->fullIData(oldp+245,(0xcU),32);
    bufp->fullQData(oldp+246,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+248,(0U),2);
    bufp->fullIData(oldp+249,(0xeU),32);
    bufp->fullIData(oldp+250,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+251,(8U),32);
    bufp->fullIData(oldp+252,(0x10U),32);
    bufp->fullIData(oldp+253,(0x23U),32);
}
