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
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBit(c+141,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+155,"npc", false,-1, 31,0);
    tracep->declBus(c+156,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+204,"inst", false,-1, 31,0);
    tracep->declBit(c+142,"ifu_valid", false,-1);
    tracep->declBus(c+205,"src1", false,-1, 4,0);
    tracep->declBus(c+206,"src2", false,-1, 4,0);
    tracep->declBus(c+207,"rd", false,-1, 4,0);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBit(c+208,"ebreaksig", false,-1);
    tracep->declBit(c+209,"mretsig", false,-1);
    tracep->declBit(c+210,"ecallsig", false,-1);
    tracep->declBit(c+2,"regew", false,-1);
    tracep->declBit(c+211,"memew", false,-1);
    tracep->declBit(c+212,"memer", false,-1);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBus(c+213,"func3", false,-1, 2,0);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+214,"func7", false,-1);
    tracep->declBit(c+215,"btypebranch", false,-1);
    tracep->declBit(c+216,"jalsig", false,-1);
    tracep->declBit(c+217,"jalrsig", false,-1);
    tracep->declBit(c+218,"auipcsig", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+142,"idu_valid", false,-1);
    tracep->declBus(c+8,"memmask", false,-1, 2,0);
    tracep->declBit(c+9,"memsextsig", false,-1);
    tracep->declBus(c+196,"regwrite", false,-1, 31,0);
    tracep->declBus(c+63,"regout1", false,-1, 31,0);
    tracep->declBus(c+157,"regout2", false,-1, 31,0);
    tracep->declBus(c+64,"mepc", false,-1, 31,0);
    tracep->declBus(c+65,"mtvec", false,-1, 31,0);
    tracep->declBit(c+141,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+158,"res", false,-1, 31,0);
    tracep->declBus(c+159,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+142,"exu_valid", false,-1);
    tracep->declBit(c+141,"ready_wbu_to_exu", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+213,"func3", false,-1, 2,0);
    tracep->declBit(c+215,"btypebranch", false,-1);
    tracep->declBit(c+214,"func7", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+217,"jalrsig", false,-1);
    tracep->declBit(c+216,"jalsig", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBus(c+63,"regout1", false,-1, 31,0);
    tracep->declBus(c+157,"regout2", false,-1, 31,0);
    tracep->declBus(c+156,"pc", false,-1, 31,0);
    tracep->declBit(c+218,"auipcsig", false,-1);
    tracep->declBit(c+209,"mretsig", false,-1);
    tracep->declBit(c+210,"ecallsig", false,-1);
    tracep->declBus(c+65,"mtvec", false,-1, 31,0);
    tracep->declBus(c+64,"mepc", false,-1, 31,0);
    tracep->declBit(c+142,"valid_from", false,-1);
    tracep->declBit(c+141,"ready_from", false,-1);
    tracep->declBus(c+158,"res", false,-1, 31,0);
    tracep->declBus(c+155,"npc", false,-1, 31,0);
    tracep->declBus(c+159,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+142,"valid_to", false,-1);
    tracep->declBit(c+141,"ready_to", false,-1);
    tracep->declBus(c+160,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+161,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+10,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+162,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+163,"zero", false,-1);
    tracep->declBit(c+164,"signal", false,-1);
    tracep->declBit(c+165,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+63,"A", false,-1, 31,0);
    tracep->declBus(c+162,"B", false,-1, 31,0);
    tracep->declBus(c+10,"op", false,-1, 4,0);
    tracep->declBus(c+158,"res", false,-1, 31,0);
    tracep->declBit(c+163,"zero", false,-1);
    tracep->declBit(c+164,"signal", false,-1);
    tracep->declBit(c+165,"carry", false,-1);
    tracep->declBit(c+11,"addsig", false,-1);
    tracep->declBit(c+12,"logsig", false,-1);
    tracep->declBit(c+13,"shfsig", false,-1);
    tracep->declBit(c+14,"sltsig", false,-1);
    tracep->declBit(c+165,"carry_tmp", false,-1);
    tracep->declBit(c+15,"type_I", false,-1);
    tracep->declBus(c+166,"logres", false,-1, 31,0);
    tracep->declBus(c+167,"addres", false,-1, 31,0);
    tracep->declBit(c+168,"addzero", false,-1);
    tracep->declBus(c+169,"shfres", false,-1, 31,0);
    tracep->declBus(c+170,"sltres", false,-1, 31,0);
    tracep->declBus(c+63,"A_s", false,-1, 31,0);
    tracep->declBus(c+162,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+213,"func3", false,-1, 2,0);
    tracep->declBit(c+214,"func7", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+217,"jalrsig", false,-1);
    tracep->declBus(c+10,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+15,"type_I", false,-1);
    tracep->declBit(c+16,"type_B", false,-1);
    tracep->declBit(c+17,"type_R", false,-1);
    tracep->declBit(c+18,"addsig", false,-1);
    tracep->declBus(c+219,"branchop", false,-1, 3,0);
    tracep->declBus(c+19,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+215,"btypebranch", false,-1);
    tracep->declBus(c+213,"func3", false,-1, 2,0);
    tracep->declBit(c+163,"zero", false,-1);
    tracep->declBit(c+164,"signal", false,-1);
    tracep->declBit(c+165,"carry", false,-1);
    tracep->declBus(c+158,"res", false,-1, 31,0);
    tracep->declBus(c+160,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+161,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+216,"jalsig", false,-1);
    tracep->declBit(c+217,"jalrsig", false,-1);
    tracep->declBit(c+218,"auipcsig", false,-1);
    tracep->declBit(c+209,"mretsig", false,-1);
    tracep->declBit(c+210,"ecallsig", false,-1);
    tracep->declBus(c+65,"mtvec", false,-1, 31,0);
    tracep->declBus(c+64,"mepc", false,-1, 31,0);
    tracep->declBus(c+155,"npc", false,-1, 31,0);
    tracep->declBus(c+159,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+220,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+221,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+222,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+162,"out", false,-1, 31,0);
    tracep->declBus(c+3,"key", false,-1, 0,0);
    tracep->declArray(c+171,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+220,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+221,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+222,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+223,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+162,"out", false,-1, 31,0);
    tracep->declBus(c+3,"key", false,-1, 0,0);
    tracep->declBus(c+224,"default_out", false,-1, 31,0);
    tracep->declArray(c+171,"lut", false,-1, 65,0);
    tracep->declBus(c+225,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+174+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+20+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+66+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+178,"lut_out", false,-1, 31,0);
    tracep->declBit(c+22,"hit", false,-1);
    tracep->declBus(c+226,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+156,"pc", false,-1, 31,0);
    tracep->declBus(c+160,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+156,"pc", false,-1, 31,0);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+161,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+204,"inst", false,-1, 31,0);
    tracep->declBit(c+142,"valid_from", false,-1);
    tracep->declBit(c+141,"ready_from", false,-1);
    tracep->declBit(c+208,"ebreaksig", false,-1);
    tracep->declBit(c+210,"ecallsig", false,-1);
    tracep->declBit(c+209,"mretsig", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+213,"func3", false,-1, 2,0);
    tracep->declBit(c+214,"func7", false,-1);
    tracep->declBus(c+205,"src1", false,-1, 4,0);
    tracep->declBus(c+206,"src2", false,-1, 4,0);
    tracep->declBus(c+207,"rd", false,-1, 4,0);
    tracep->declBit(c+211,"memew", false,-1);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+212,"memer", false,-1);
    tracep->declBit(c+2,"regew", false,-1);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBit(c+215,"btypebranch", false,-1);
    tracep->declBit(c+217,"jalrsig", false,-1);
    tracep->declBit(c+216,"jalsig", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+218,"auipcsig", false,-1);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+142,"valid_to", false,-1);
    tracep->declBit(c+141,"ready_to", false,-1);
    tracep->declBus(c+8,"memmask", false,-1, 2,0);
    tracep->declBit(c+9,"memsextsig", false,-1);
    tracep->declBit(c+208,"ebreak", false,-1);
    tracep->declBit(c+210,"ecall", false,-1);
    tracep->declBit(c+209,"mret", false,-1);
    tracep->declBus(c+213,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+214,"func7bridge", false,-1);
    tracep->declBus(c+227,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+204,"inst", false,-1, 31,0);
    tracep->declBit(c+208,"ebreaksig", false,-1);
    tracep->declBit(c+210,"ecallsig", false,-1);
    tracep->declBit(c+209,"mretsig", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+227,"opcode", false,-1, 6,0);
    tracep->declBus(c+213,"func3", false,-1, 2,0);
    tracep->declBit(c+214,"func7", false,-1);
    tracep->declBus(c+205,"src1", false,-1, 4,0);
    tracep->declBus(c+206,"src2", false,-1, 4,0);
    tracep->declBus(c+207,"rd", false,-1, 4,0);
    tracep->declBus(c+8,"memmask", false,-1, 2,0);
    tracep->declBit(c+9,"memsextsig", false,-1);
    tracep->declBit(c+23,"type_I", false,-1);
    tracep->declBit(c+228,"type_R", false,-1);
    tracep->declBit(c+24,"type_U", false,-1);
    tracep->declBit(c+211,"type_S", false,-1);
    tracep->declBit(c+216,"type_J", false,-1);
    tracep->declBit(c+215,"type_B", false,-1);
    tracep->declBus(c+25,"I_imm", false,-1, 31,0);
    tracep->declBus(c+229,"U_imm", false,-1, 31,0);
    tracep->declBus(c+26,"S_imm", false,-1, 31,0);
    tracep->declBus(c+27,"J_imm", false,-1, 31,0);
    tracep->declBus(c+28,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+227,"opcode", false,-1, 6,0);
    tracep->declBus(c+213,"func3", false,-1, 2,0);
    tracep->declBit(c+214,"func7", false,-1);
    tracep->declBit(c+208,"ebreaksig", false,-1);
    tracep->declBit(c+210,"ecallsig", false,-1);
    tracep->declBit(c+209,"mretsig", false,-1);
    tracep->declBit(c+211,"memew", false,-1);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+212,"memer", false,-1);
    tracep->declBit(c+2,"regew", false,-1);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBit(c+215,"btypebranch", false,-1);
    tracep->declBit(c+217,"jalrsig", false,-1);
    tracep->declBit(c+216,"jalsig", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+218,"auipcsig", false,-1);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+23,"type_I", false,-1);
    tracep->declBit(c+228,"type_R", false,-1);
    tracep->declBit(c+24,"type_U", false,-1);
    tracep->declBit(c+211,"type_S", false,-1);
    tracep->declBit(c+216,"type_J", false,-1);
    tracep->declBit(c+215,"type_B", false,-1);
    tracep->declBit(c+212,"load", false,-1);
    tracep->declBit(c+211,"store", false,-1);
    tracep->declBit(c+230,"regwritepc", false,-1);
    tracep->declBit(c+212,"regwritemem", false,-1);
    tracep->declBit(c+231,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBus(c+155,"npc", false,-1, 31,0);
    tracep->declBit(c+141,"ready", false,-1);
    tracep->declBus(c+156,"pc", false,-1, 31,0);
    tracep->declBus(c+204,"inst", false,-1, 31,0);
    tracep->declBit(c+142,"valid", false,-1);
    tracep->declBus(c+156,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+143,"instbridge", false,-1, 31,0);
    tracep->declBit(c+144,"infetch_ready", false,-1);
    tracep->declBit(c+145,"arready", false,-1);
    tracep->declBit(c+145,"rready", false,-1);
    tracep->declBit(c+232,"arvalid", false,-1);
    tracep->declBit(c+233,"rvalid", false,-1);
    tracep->declBit(c+145,"awready", false,-1);
    tracep->declBit(c+145,"wready", false,-1);
    tracep->declBit(c+234,"bvalid", false,-1);
    tracep->declBit(c+235,"bresp", false,-1);
    tracep->pushNamePrefix("infetch ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+236,"awvalid", false,-1);
    tracep->declBit(c+145,"awready", false,-1);
    tracep->declBus(c+223,"awaddr", false,-1, 31,0);
    tracep->declBit(c+236,"wvalid", false,-1);
    tracep->declBit(c+145,"wready", false,-1);
    tracep->declBus(c+223,"wdata", false,-1, 31,0);
    tracep->declBus(c+237,"wstrb", false,-1, 3,0);
    tracep->declBit(c+234,"bvalid", false,-1);
    tracep->declBit(c+236,"bready", false,-1);
    tracep->declBit(c+235,"bresp", false,-1);
    tracep->declBit(c+141,"arvalid", false,-1);
    tracep->declBit(c+145,"arready", false,-1);
    tracep->declBus(c+156,"araddr", false,-1, 31,0);
    tracep->declBit(c+141,"rvalid", false,-1);
    tracep->declBit(c+145,"rready", false,-1);
    tracep->declBus(c+143,"rdata", false,-1, 31,0);
    tracep->declBus(c+146,"state", false,-1, 1,0);
    tracep->declBus(c+29,"memmask", false,-1, 2,0);
    tracep->declBus(c+143,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+238,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+239,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+29,"out", false,-1, 2,0);
    tracep->declBus(c+237,"key", false,-1, 3,0);
    tracep->declBus(c+240,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+238,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+239,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+223,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+29,"out", false,-1, 2,0);
    tracep->declBus(c+237,"key", false,-1, 3,0);
    tracep->declBus(c+241,"default_out", false,-1, 2,0);
    tracep->declBus(c+240,"lut", false,-1, 27,0);
    tracep->declBus(c+242,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+30+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+34+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+38+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+42,"lut_out", false,-1, 2,0);
    tracep->declBit(c+43,"hit", false,-1);
    tracep->declBus(c+243,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBus(c+155,"npc", false,-1, 31,0);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBit(c+144,"ready_from", false,-1);
    tracep->declBus(c+156,"pcout", false,-1, 31,0);
    tracep->declBus(c+244,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBit(c+2,"ew", false,-1);
    tracep->declBus(c+207,"addr", false,-1, 4,0);
    tracep->declBus(c+205,"src1", false,-1, 4,0);
    tracep->declBus(c+206,"src2", false,-1, 4,0);
    tracep->declBus(c+245,"csr", false,-1, 11,0);
    tracep->declBus(c+196,"data", false,-1, 31,0);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+210,"ecallsig", false,-1);
    tracep->declBit(c+142,"valid", false,-1);
    tracep->declBus(c+63,"regout1", false,-1, 31,0);
    tracep->declBus(c+157,"regout2", false,-1, 31,0);
    tracep->declBus(c+64,"mepc", false,-1, 31,0);
    tracep->declBus(c+65,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+68+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+100+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+44,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+197,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+246,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+220,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+44,"out", false,-1, 1,0);
    tracep->declBus(c+245,"key", false,-1, 11,0);
    tracep->declQuad(c+247,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+246,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+220,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+223,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+44,"out", false,-1, 1,0);
    tracep->declBus(c+245,"key", false,-1, 11,0);
    tracep->declBus(c+249,"default_out", false,-1, 1,0);
    tracep->declQuad(c+247,"lut", false,-1, 55,0);
    tracep->declBus(c+250,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+45+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+49+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+53+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+57,"lut_out", false,-1, 1,0);
    tracep->declBit(c+58,"hit", false,-1);
    tracep->declBus(c+243,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBit(c+147,"ew", false,-1);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+210,"ecall", false,-1);
    tracep->declBus(c+44,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+207,"addr", false,-1, 4,0);
    tracep->declBus(c+197,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+104+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+136+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+140,"i", false,-1, 31,0);
    tracep->declBus(c+251,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBus(c+158,"res", false,-1, 31,0);
    tracep->declBus(c+157,"regout2", false,-1, 31,0);
    tracep->declBit(c+211,"memew", false,-1);
    tracep->declBit(c+212,"memer", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+159,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+142,"valid_from", false,-1);
    tracep->declBus(c+8,"memmask", false,-1, 2,0);
    tracep->declBit(c+9,"memsextsig", false,-1);
    tracep->declBus(c+196,"regwrite", false,-1, 31,0);
    tracep->declBit(c+141,"ready_to", false,-1);
    tracep->declBus(c+202,"memread", false,-1, 31,0);
    tracep->declBus(c+148,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBus(c+158,"addr", false,-1, 31,0);
    tracep->declBus(c+157,"write", false,-1, 31,0);
    tracep->declBit(c+212,"er", false,-1);
    tracep->declBit(c+211,"ew", false,-1);
    tracep->declBus(c+8,"memmask", false,-1, 2,0);
    tracep->declBit(c+9,"memsextsig", false,-1);
    tracep->declBus(c+202,"read", false,-1, 31,0);
    tracep->declBit(c+142,"valid_from", false,-1);
    tracep->declBit(c+141,"ready_to", false,-1);
    tracep->declBus(c+149,"readreg", false,-1, 31,0);
    tracep->declBus(c+149,"read_u", false,-1, 31,0);
    tracep->declBus(c+203,"read_s", false,-1, 31,0);
    tracep->declBit(c+150,"state", false,-1);
    tracep->declBus(c+151,"read_sb", false,-1, 31,0);
    tracep->declBus(c+152,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+252,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+222,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+153,"input_number", false,-1, 7,0);
    tracep->declBus(c+151,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+253,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+222,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+154,"input_number", false,-1, 15,0);
    tracep->declBus(c+152,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+239,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+222,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+196,"out", false,-1, 31,0);
    tracep->declBus(c+4,"key", false,-1, 2,0);
    tracep->declBus(c+223,"default_out", false,-1, 31,0);
    tracep->declArray(c+179,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+238,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+239,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+222,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+221,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+196,"out", false,-1, 31,0);
    tracep->declBus(c+4,"key", false,-1, 2,0);
    tracep->declBus(c+223,"default_out", false,-1, 31,0);
    tracep->declArray(c+179,"lut", false,-1, 139,0);
    tracep->declBus(c+254,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+184+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+59+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+192+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+198,"lut_out", false,-1, 31,0);
    tracep->declBit(c+199,"hit", false,-1);
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
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+2,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                           | ((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
                              | ((0x6fU == (0x7fU & vlSelf->top__DOT__inst)) 
                                 | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                    | (3U == (0x7fU 
                                              & vlSelf->top__DOT__inst))))))));
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__muxsig),3);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+9,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+11,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+14,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+15,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+16,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+17,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+18,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+19,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+20,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+21,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+22,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+23,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+24,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullCData(oldp+29,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__memmask),3);
    bufp->fullCData(oldp+30,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
    bufp->fullCData(oldp+31,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
    bufp->fullCData(oldp+32,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
    bufp->fullCData(oldp+33,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
    bufp->fullCData(oldp+34,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+35,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+37,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
    bufp->fullCData(oldp+38,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+39,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+40,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+41,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
    bufp->fullCData(oldp+42,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+44,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullSData(oldp+45,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+46,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+47,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+48,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+49,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+50,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+51,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+52,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+53,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+54,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+55,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+56,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+57,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+58,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+59,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+60,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+61,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+62,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+141,((1U & (~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)))));
    bufp->fullBit(oldp+142,((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg),32);
    bufp->fullBit(oldp+144,(((0U == (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state)) 
                             & ((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                                & (0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))));
    bufp->fullBit(oldp+145,((0U == (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state))));
    bufp->fullCData(oldp+146,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state),2);
    bufp->fullBit(oldp+147,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullIData(oldp+148,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state)) 
                               & (0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg),32);
    bufp->fullBit(oldp+150,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__state));
    bufp->fullIData(oldp+151,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullIData(oldp+152,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullCData(oldp+153,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),8);
    bufp->fullSData(oldp+154,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),16);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+160,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+163,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+164,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+165,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+168,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+171,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+174,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+176,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
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
    bufp->fullWData(oldp+179,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+184,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+186,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+188,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+190,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+193,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+194,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+195,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+196,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+197,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+198,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+199,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+200,(vlSelf->clk));
    bufp->fullBit(oldp+201,(vlSelf->rst));
    bufp->fullIData(oldp+202,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+203,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__read_s),32);
    bufp->fullIData(oldp+204,(vlSelf->top__DOT__inst),32);
    bufp->fullCData(oldp+205,((0x1fU & (vlSelf->top__DOT__inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+206,((0x1fU & (vlSelf->top__DOT__inst 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+207,((0x1fU & (vlSelf->top__DOT__inst 
                                        >> 7U))),5);
    bufp->fullBit(oldp+208,((0x100073U == vlSelf->top__DOT__inst)));
    bufp->fullBit(oldp+209,((0x30200073U == vlSelf->top__DOT__inst)));
    bufp->fullBit(oldp+210,((0x73U == vlSelf->top__DOT__inst)));
    bufp->fullBit(oldp+211,((0x23U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+212,((3U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullCData(oldp+213,((7U & (vlSelf->top__DOT__inst 
                                     >> 0xcU))),3);
    bufp->fullBit(oldp+214,((1U & (vlSelf->top__DOT__inst 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+215,((0x63U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+216,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+217,((0x67U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+218,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullCData(oldp+219,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__inst)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__inst)))
                                         ? 9U : 3U))),4);
    bufp->fullIData(oldp+220,(2U),32);
    bufp->fullIData(oldp+221,(1U),32);
    bufp->fullIData(oldp+222,(0x20U),32);
    bufp->fullIData(oldp+223,(0U),32);
    bufp->fullIData(oldp+224,(0U),32);
    bufp->fullIData(oldp+225,(0x21U),32);
    bufp->fullIData(oldp+226,(2U),32);
    bufp->fullCData(oldp+227,((0x7fU & vlSelf->top__DOT__inst)),7);
    bufp->fullBit(oldp+228,((0x33U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullIData(oldp+229,((0xfffff000U & vlSelf->top__DOT__inst)),32);
    bufp->fullBit(oldp+230,(((0x67U == (0x7fU & vlSelf->top__DOT__inst)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__inst)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__inst)) 
                                   | (0x73U == vlSelf->top__DOT__inst))))));
    bufp->fullBit(oldp+231,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
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
    bufp->fullSData(oldp+245,((vlSelf->top__DOT__inst 
                               >> 0x14U)),12);
    bufp->fullIData(oldp+246,(0xcU),32);
    bufp->fullQData(oldp+247,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+249,(0U),2);
    bufp->fullIData(oldp+250,(0xeU),32);
    bufp->fullIData(oldp+251,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+252,(8U),32);
    bufp->fullIData(oldp+253,(0x10U),32);
    bufp->fullIData(oldp+254,(0x23U),32);
}
