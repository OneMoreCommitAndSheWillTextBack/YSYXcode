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
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+248,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+248,"rst", false,-1);
    tracep->declBit(c+221,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+227,"npc", false,-1, 31,0);
    tracep->declBus(c+144,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+46,"inst", false,-1, 31,0);
    tracep->declBit(c+47,"ifu_valid", false,-1);
    tracep->declBus(c+48,"src1", false,-1, 4,0);
    tracep->declBus(c+49,"src2", false,-1, 4,0);
    tracep->declBus(c+50,"rd", false,-1, 4,0);
    tracep->declBus(c+51,"imm", false,-1, 31,0);
    tracep->declBit(c+52,"ebreaksig", false,-1);
    tracep->declBit(c+53,"mretsig", false,-1);
    tracep->declBit(c+54,"ecallsig", false,-1);
    tracep->declBit(c+55,"regew", false,-1);
    tracep->declBit(c+56,"memew", false,-1);
    tracep->declBit(c+57,"memer", false,-1);
    tracep->declBit(c+58,"muximm", false,-1);
    tracep->declBus(c+59,"func3", false,-1, 2,0);
    tracep->declBus(c+60,"muxsig", false,-1, 2,0);
    tracep->declBit(c+61,"func7", false,-1);
    tracep->declBit(c+62,"btypebranch", false,-1);
    tracep->declBit(c+63,"jalsig", false,-1);
    tracep->declBit(c+64,"jalrsig", false,-1);
    tracep->declBit(c+65,"auipcsig", false,-1);
    tracep->declBus(c+66,"aluop", false,-1, 1,0);
    tracep->declBit(c+222,"csrrw", false,-1);
    tracep->declBit(c+223,"csrrs", false,-1);
    tracep->declBit(c+47,"idu_valid", false,-1);
    tracep->declBus(c+67,"memmask", false,-1, 2,0);
    tracep->declBit(c+68,"memsextsig", false,-1);
    tracep->declBus(c+228,"regwrite", false,-1, 31,0);
    tracep->declBus(c+229,"regout1", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBus(c+145,"mepc", false,-1, 31,0);
    tracep->declBus(c+146,"mtvec", false,-1, 31,0);
    tracep->declBit(c+221,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+47,"exu_valid", false,-1);
    tracep->declBit(c+221,"ready_wbu_to_exu", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+59,"func3", false,-1, 2,0);
    tracep->declBit(c+62,"btypebranch", false,-1);
    tracep->declBit(c+61,"func7", false,-1);
    tracep->declBus(c+66,"aluop", false,-1, 1,0);
    tracep->declBit(c+64,"jalrsig", false,-1);
    tracep->declBit(c+63,"jalsig", false,-1);
    tracep->declBus(c+51,"imm", false,-1, 31,0);
    tracep->declBit(c+58,"muximm", false,-1);
    tracep->declBus(c+229,"regout1", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBus(c+144,"pc", false,-1, 31,0);
    tracep->declBit(c+65,"auipcsig", false,-1);
    tracep->declBit(c+53,"mretsig", false,-1);
    tracep->declBit(c+54,"ecallsig", false,-1);
    tracep->declBus(c+146,"mtvec", false,-1, 31,0);
    tracep->declBus(c+145,"mepc", false,-1, 31,0);
    tracep->declBit(c+47,"valid_from", false,-1);
    tracep->declBit(c+221,"ready_from", false,-1);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+227,"npc", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+47,"valid_to", false,-1);
    tracep->declBit(c+221,"ready_to", false,-1);
    tracep->declBus(c+147,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+233,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+69,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+234,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+235,"zero", false,-1);
    tracep->declBit(c+236,"signal", false,-1);
    tracep->declBit(c+237,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+229,"A", false,-1, 31,0);
    tracep->declBus(c+234,"B", false,-1, 31,0);
    tracep->declBus(c+69,"op", false,-1, 4,0);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBit(c+235,"zero", false,-1);
    tracep->declBit(c+236,"signal", false,-1);
    tracep->declBit(c+237,"carry", false,-1);
    tracep->declBit(c+70,"addsig", false,-1);
    tracep->declBit(c+71,"logsig", false,-1);
    tracep->declBit(c+72,"shfsig", false,-1);
    tracep->declBit(c+73,"sltsig", false,-1);
    tracep->declBit(c+237,"carry_tmp", false,-1);
    tracep->declBit(c+74,"type_I", false,-1);
    tracep->declBus(c+238,"logres", false,-1, 31,0);
    tracep->declBus(c+239,"addres", false,-1, 31,0);
    tracep->declBit(c+240,"addzero", false,-1);
    tracep->declBus(c+241,"shfres", false,-1, 31,0);
    tracep->declBus(c+242,"sltres", false,-1, 31,0);
    tracep->declBus(c+229,"A_s", false,-1, 31,0);
    tracep->declBus(c+234,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+59,"func3", false,-1, 2,0);
    tracep->declBit(c+61,"func7", false,-1);
    tracep->declBus(c+66,"aluop", false,-1, 1,0);
    tracep->declBit(c+64,"jalrsig", false,-1);
    tracep->declBus(c+69,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+74,"type_I", false,-1);
    tracep->declBit(c+75,"type_B", false,-1);
    tracep->declBit(c+76,"type_R", false,-1);
    tracep->declBit(c+77,"addsig", false,-1);
    tracep->declBus(c+78,"branchop", false,-1, 3,0);
    tracep->declBus(c+79,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+62,"btypebranch", false,-1);
    tracep->declBus(c+59,"func3", false,-1, 2,0);
    tracep->declBit(c+235,"zero", false,-1);
    tracep->declBit(c+236,"signal", false,-1);
    tracep->declBit(c+237,"carry", false,-1);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+147,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+233,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+63,"jalsig", false,-1);
    tracep->declBit(c+64,"jalrsig", false,-1);
    tracep->declBit(c+65,"auipcsig", false,-1);
    tracep->declBit(c+53,"mretsig", false,-1);
    tracep->declBit(c+54,"ecallsig", false,-1);
    tracep->declBus(c+146,"mtvec", false,-1, 31,0);
    tracep->declBus(c+145,"mepc", false,-1, 31,0);
    tracep->declBus(c+227,"npc", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+252,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+253,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+254,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+234,"out", false,-1, 31,0);
    tracep->declBus(c+58,"key", false,-1, 0,0);
    tracep->declArray(c+118,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+252,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+253,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+254,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+255,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+234,"out", false,-1, 31,0);
    tracep->declBus(c+58,"key", false,-1, 0,0);
    tracep->declBus(c+256,"default_out", false,-1, 31,0);
    tracep->declArray(c+118,"lut", false,-1, 65,0);
    tracep->declBus(c+257,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+121+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+125+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+243,"lut_out", false,-1, 31,0);
    tracep->declBit(c+80,"hit", false,-1);
    tracep->declBus(c+258,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+144,"pc", false,-1, 31,0);
    tracep->declBus(c+147,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+144,"pc", false,-1, 31,0);
    tracep->declBus(c+51,"imm", false,-1, 31,0);
    tracep->declBus(c+233,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+46,"inst", false,-1, 31,0);
    tracep->declBit(c+47,"valid_from", false,-1);
    tracep->declBit(c+221,"ready_from", false,-1);
    tracep->declBit(c+52,"ebreaksig", false,-1);
    tracep->declBit(c+54,"ecallsig", false,-1);
    tracep->declBit(c+53,"mretsig", false,-1);
    tracep->declBus(c+51,"imm", false,-1, 31,0);
    tracep->declBus(c+59,"func3", false,-1, 2,0);
    tracep->declBit(c+61,"func7", false,-1);
    tracep->declBus(c+48,"src1", false,-1, 4,0);
    tracep->declBus(c+49,"src2", false,-1, 4,0);
    tracep->declBus(c+50,"rd", false,-1, 4,0);
    tracep->declBit(c+56,"memew", false,-1);
    tracep->declBus(c+60,"muxsig", false,-1, 2,0);
    tracep->declBit(c+57,"memer", false,-1);
    tracep->declBit(c+55,"regew", false,-1);
    tracep->declBit(c+58,"muximm", false,-1);
    tracep->declBit(c+62,"btypebranch", false,-1);
    tracep->declBit(c+64,"jalrsig", false,-1);
    tracep->declBit(c+63,"jalsig", false,-1);
    tracep->declBus(c+66,"aluop", false,-1, 1,0);
    tracep->declBit(c+65,"auipcsig", false,-1);
    tracep->declBit(c+222,"csrrw", false,-1);
    tracep->declBit(c+223,"csrrs", false,-1);
    tracep->declBit(c+47,"valid_to", false,-1);
    tracep->declBit(c+221,"ready_to", false,-1);
    tracep->declBus(c+67,"memmask", false,-1, 2,0);
    tracep->declBit(c+68,"memsextsig", false,-1);
    tracep->declBit(c+52,"ebreak", false,-1);
    tracep->declBit(c+54,"ecall", false,-1);
    tracep->declBit(c+53,"mret", false,-1);
    tracep->declBus(c+59,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+61,"func7bridge", false,-1);
    tracep->declBus(c+81,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+46,"inst", false,-1, 31,0);
    tracep->declBit(c+52,"ebreaksig", false,-1);
    tracep->declBit(c+54,"ecallsig", false,-1);
    tracep->declBit(c+53,"mretsig", false,-1);
    tracep->declBus(c+51,"imm", false,-1, 31,0);
    tracep->declBus(c+81,"opcode", false,-1, 6,0);
    tracep->declBus(c+59,"func3", false,-1, 2,0);
    tracep->declBit(c+61,"func7", false,-1);
    tracep->declBus(c+48,"src1", false,-1, 4,0);
    tracep->declBus(c+49,"src2", false,-1, 4,0);
    tracep->declBus(c+50,"rd", false,-1, 4,0);
    tracep->declBus(c+67,"memmask", false,-1, 2,0);
    tracep->declBit(c+68,"memsextsig", false,-1);
    tracep->declBit(c+82,"type_I", false,-1);
    tracep->declBit(c+83,"type_R", false,-1);
    tracep->declBit(c+84,"type_U", false,-1);
    tracep->declBit(c+56,"type_S", false,-1);
    tracep->declBit(c+63,"type_J", false,-1);
    tracep->declBit(c+62,"type_B", false,-1);
    tracep->declBus(c+85,"I_imm", false,-1, 31,0);
    tracep->declBus(c+86,"U_imm", false,-1, 31,0);
    tracep->declBus(c+87,"S_imm", false,-1, 31,0);
    tracep->declBus(c+88,"J_imm", false,-1, 31,0);
    tracep->declBus(c+89,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+81,"opcode", false,-1, 6,0);
    tracep->declBus(c+59,"func3", false,-1, 2,0);
    tracep->declBit(c+61,"func7", false,-1);
    tracep->declBit(c+52,"ebreaksig", false,-1);
    tracep->declBit(c+54,"ecallsig", false,-1);
    tracep->declBit(c+53,"mretsig", false,-1);
    tracep->declBit(c+56,"memew", false,-1);
    tracep->declBus(c+60,"muxsig", false,-1, 2,0);
    tracep->declBit(c+57,"memer", false,-1);
    tracep->declBit(c+55,"regew", false,-1);
    tracep->declBit(c+58,"muximm", false,-1);
    tracep->declBit(c+62,"btypebranch", false,-1);
    tracep->declBit(c+64,"jalrsig", false,-1);
    tracep->declBit(c+63,"jalsig", false,-1);
    tracep->declBus(c+66,"aluop", false,-1, 1,0);
    tracep->declBit(c+65,"auipcsig", false,-1);
    tracep->declBit(c+222,"csrrw", false,-1);
    tracep->declBit(c+223,"csrrs", false,-1);
    tracep->declBit(c+82,"type_I", false,-1);
    tracep->declBit(c+83,"type_R", false,-1);
    tracep->declBit(c+84,"type_U", false,-1);
    tracep->declBit(c+56,"type_S", false,-1);
    tracep->declBit(c+63,"type_J", false,-1);
    tracep->declBit(c+62,"type_B", false,-1);
    tracep->declBit(c+57,"load", false,-1);
    tracep->declBit(c+56,"store", false,-1);
    tracep->declBit(c+90,"regwritepc", false,-1);
    tracep->declBit(c+57,"regwritemem", false,-1);
    tracep->declBit(c+91,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+248,"rst", false,-1);
    tracep->declBus(c+227,"npc", false,-1, 31,0);
    tracep->declBit(c+221,"ready", false,-1);
    tracep->declBus(c+144,"pc", false,-1, 31,0);
    tracep->declBus(c+46,"inst", false,-1, 31,0);
    tracep->declBit(c+47,"valid", false,-1);
    tracep->declBus(c+144,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+46,"instbridge", false,-1, 31,0);
    tracep->declBit(c+249,"infetch_ready", false,-1);
    tracep->declBit(c+92,"arready", false,-1);
    tracep->declBit(c+92,"rready", false,-1);
    tracep->declBit(c+259,"arvalid", false,-1);
    tracep->declBit(c+260,"rvalid", false,-1);
    tracep->declBit(c+92,"awready", false,-1);
    tracep->declBit(c+92,"wready", false,-1);
    tracep->declBit(c+261,"bvalid", false,-1);
    tracep->declBit(c+262,"bresp", false,-1);
    tracep->pushNamePrefix("infetch ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+263,"awvalid", false,-1);
    tracep->declBit(c+92,"awready", false,-1);
    tracep->declBus(c+255,"awaddr", false,-1, 31,0);
    tracep->declBit(c+263,"wvalid", false,-1);
    tracep->declBit(c+92,"wready", false,-1);
    tracep->declBus(c+255,"wdata", false,-1, 31,0);
    tracep->declBus(c+264,"wstrb", false,-1, 3,0);
    tracep->declBit(c+261,"bvalid", false,-1);
    tracep->declBit(c+263,"bready", false,-1);
    tracep->declBit(c+262,"bresp", false,-1);
    tracep->declBit(c+221,"arvalid", false,-1);
    tracep->declBit(c+92,"arready", false,-1);
    tracep->declBus(c+144,"araddr", false,-1, 31,0);
    tracep->declBit(c+221,"rvalid", false,-1);
    tracep->declBit(c+92,"rready", false,-1);
    tracep->declBus(c+46,"rdata", false,-1, 31,0);
    tracep->declBus(c+93,"state", false,-1, 1,0);
    tracep->declBus(c+94,"random_delay", false,-1, 3,0);
    tracep->declBus(c+95,"random_count", false,-1, 3,0);
    tracep->declBus(c+3,"memmask", false,-1, 2,0);
    tracep->declBus(c+46,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("lsfr0 ");
    tracep->declBus(c+265,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+263,"reset", false,-1);
    tracep->declBus(c+94,"out", false,-1, 3,0);
    tracep->declBus(c+96,"random_num", false,-1, 7,0);
    tracep->declBit(c+97,"feedback", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+265,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+266,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+3,"out", false,-1, 2,0);
    tracep->declBus(c+264,"key", false,-1, 3,0);
    tracep->declBus(c+267,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+265,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+266,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+255,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+3,"out", false,-1, 2,0);
    tracep->declBus(c+264,"key", false,-1, 3,0);
    tracep->declBus(c+268,"default_out", false,-1, 2,0);
    tracep->declBus(c+267,"lut", false,-1, 27,0);
    tracep->declBus(c+269,"PAIR_LEN", false,-1, 31,0);
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
    tracep->declBus(c+270,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBus(c+227,"npc", false,-1, 31,0);
    tracep->declBit(c+248,"rst", false,-1);
    tracep->declBit(c+249,"ready_from", false,-1);
    tracep->declBus(c+144,"pcout", false,-1, 31,0);
    tracep->declBus(c+271,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+248,"rst", false,-1);
    tracep->declBit(c+250,"ew", false,-1);
    tracep->declBus(c+50,"addr", false,-1, 4,0);
    tracep->declBus(c+48,"src1", false,-1, 4,0);
    tracep->declBus(c+49,"src2", false,-1, 4,0);
    tracep->declBus(c+98,"csr", false,-1, 11,0);
    tracep->declBus(c+228,"data", false,-1, 31,0);
    tracep->declBit(c+222,"csrrw", false,-1);
    tracep->declBit(c+223,"csrrs", false,-1);
    tracep->declBit(c+54,"ecallsig", false,-1);
    tracep->declBit(c+47,"valid", false,-1);
    tracep->declBus(c+229,"regout1", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBus(c+145,"mepc", false,-1, 31,0);
    tracep->declBus(c+146,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+148+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+180+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+224,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+244,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+272,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+252,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+224,"out", false,-1, 1,0);
    tracep->declBus(c+98,"key", false,-1, 11,0);
    tracep->declQuad(c+273,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+272,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+252,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+255,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+224,"out", false,-1, 1,0);
    tracep->declBus(c+98,"key", false,-1, 11,0);
    tracep->declBus(c+275,"default_out", false,-1, 1,0);
    tracep->declQuad(c+273,"lut", false,-1, 55,0);
    tracep->declBus(c+276,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+18+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+22+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+26+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+225,"lut_out", false,-1, 1,0);
    tracep->declBit(c+99,"hit", false,-1);
    tracep->declBus(c+270,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+248,"rst", false,-1);
    tracep->declBit(c+226,"ew", false,-1);
    tracep->declBit(c+222,"csrrw", false,-1);
    tracep->declBit(c+223,"csrrs", false,-1);
    tracep->declBit(c+54,"ecall", false,-1);
    tracep->declBus(c+224,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+50,"addr", false,-1, 4,0);
    tracep->declBus(c+244,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+184+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+216+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+220,"i", false,-1, 31,0);
    tracep->declBus(c+277,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBit(c+56,"memew", false,-1);
    tracep->declBit(c+57,"memer", false,-1);
    tracep->declBus(c+51,"imm", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+60,"muxsig", false,-1, 2,0);
    tracep->declBit(c+47,"valid_from", false,-1);
    tracep->declBus(c+67,"memmask", false,-1, 2,0);
    tracep->declBit(c+68,"memsextsig", false,-1);
    tracep->declBus(c+228,"regwrite", false,-1, 31,0);
    tracep->declBit(c+221,"ready_to", false,-1);
    tracep->declBus(c+100,"readdata", false,-1, 31,0);
    tracep->declBus(c+101,"memread", false,-1, 31,0);
    tracep->declBus(c+102,"wstrb", false,-1, 3,0);
    tracep->declBit(c+103,"awready", false,-1);
    tracep->declBit(c+103,"wready", false,-1);
    tracep->declBit(c+278,"bvalid", false,-1);
    tracep->declBit(c+103,"arready", false,-1);
    tracep->declBit(c+103,"rready", false,-1);
    tracep->declBit(c+279,"bresp", false,-1);
    tracep->declBit(c+103,"ready", false,-1);
    tracep->declBit(c+221,"memready", false,-1);
    tracep->declBus(c+251,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+56,"awvalid", false,-1);
    tracep->declBit(c+103,"awready", false,-1);
    tracep->declBus(c+231,"awaddr", false,-1, 31,0);
    tracep->declBit(c+56,"wvalid", false,-1);
    tracep->declBit(c+103,"wready", false,-1);
    tracep->declBus(c+230,"wdata", false,-1, 31,0);
    tracep->declBus(c+102,"wstrb", false,-1, 3,0);
    tracep->declBit(c+278,"bvalid", false,-1);
    tracep->declBit(c+56,"bready", false,-1);
    tracep->declBit(c+279,"bresp", false,-1);
    tracep->declBit(c+57,"arvalid", false,-1);
    tracep->declBit(c+103,"arready", false,-1);
    tracep->declBus(c+231,"araddr", false,-1, 31,0);
    tracep->declBit(c+57,"rvalid", false,-1);
    tracep->declBit(c+103,"rready", false,-1);
    tracep->declBus(c+100,"rdata", false,-1, 31,0);
    tracep->declBus(c+104,"state", false,-1, 1,0);
    tracep->declBus(c+105,"random_delay", false,-1, 3,0);
    tracep->declBus(c+106,"random_count", false,-1, 3,0);
    tracep->declBus(c+107,"memmask", false,-1, 2,0);
    tracep->declBus(c+100,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("lsfr0 ");
    tracep->declBus(c+265,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+247,"clk", false,-1);
    tracep->declBit(c+263,"reset", false,-1);
    tracep->declBus(c+105,"out", false,-1, 3,0);
    tracep->declBus(c+108,"random_num", false,-1, 7,0);
    tracep->declBit(c+109,"feedback", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+265,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+266,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+107,"out", false,-1, 2,0);
    tracep->declBus(c+102,"key", false,-1, 3,0);
    tracep->declBus(c+267,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+265,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+266,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+255,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+107,"out", false,-1, 2,0);
    tracep->declBus(c+102,"key", false,-1, 3,0);
    tracep->declBus(c+268,"default_out", false,-1, 2,0);
    tracep->declBus(c+267,"lut", false,-1, 27,0);
    tracep->declBus(c+269,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+30+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+34+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+38+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+110,"lut_out", false,-1, 2,0);
    tracep->declBit(c+111,"hit", false,-1);
    tracep->declBus(c+270,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+100,"data", false,-1, 31,0);
    tracep->declBus(c+67,"memmask", false,-1, 2,0);
    tracep->declBit(c+68,"memsextsig", false,-1);
    tracep->declBus(c+101,"read", false,-1, 31,0);
    tracep->declBus(c+112,"read_u", false,-1, 31,0);
    tracep->declBus(c+113,"read_s", false,-1, 31,0);
    tracep->declBus(c+114,"read_sb", false,-1, 31,0);
    tracep->declBus(c+115,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+280,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+254,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+116,"input_number", false,-1, 7,0);
    tracep->declBus(c+114,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+281,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+254,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+117,"input_number", false,-1, 15,0);
    tracep->declBus(c+115,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+254,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+228,"out", false,-1, 31,0);
    tracep->declBus(c+60,"key", false,-1, 2,0);
    tracep->declBus(c+255,"default_out", false,-1, 31,0);
    tracep->declArray(c+127,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+265,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+266,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+254,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+253,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+228,"out", false,-1, 31,0);
    tracep->declBus(c+60,"key", false,-1, 2,0);
    tracep->declBus(c+255,"default_out", false,-1, 31,0);
    tracep->declArray(c+127,"lut", false,-1, 139,0);
    tracep->declBus(c+282,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+132+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+42+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+140+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+245,"lut_out", false,-1, 31,0);
    tracep->declBit(c+246,"hit", false,-1);
    tracep->declBus(c+270,"i", false,-1, 31,0);
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
    bufp->fullCData(oldp+30,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
    bufp->fullCData(oldp+31,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
    bufp->fullCData(oldp+32,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
    bufp->fullCData(oldp+33,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
    bufp->fullCData(oldp+34,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+35,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+37,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
    bufp->fullCData(oldp+38,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+39,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+40,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+41,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
    bufp->fullCData(oldp+42,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+43,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+44,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+45,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg),32);
    bufp->fullBit(oldp+47,((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullCData(oldp+48,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+49,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+50,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                       >> 7U))),5);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+52,((0x100073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+53,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+54,((0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+55,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                            | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                     | (3U == (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))))));
    bufp->fullBit(oldp+56,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+57,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+58,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+59,((7U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+60,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+61,((1U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+62,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+63,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+64,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+65,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullCData(oldp+66,(vlSelf->top__DOT__aluop),2);
    bufp->fullCData(oldp+67,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+68,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+69,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+70,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+71,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+72,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+73,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+74,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+75,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+76,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+77,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+78,(((IData)((0x6000U == (0x6000U 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                               ? 8U : ((1U & VL_REDXOR_16(
                                                          (0x6000U 
                                                           & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                                        ? 9U : 3U))),4);
    bufp->fullCData(oldp+79,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+80,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+81,((0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),7);
    bufp->fullBit(oldp+82,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+83,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+84,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+86,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+90,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                            | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                               | ((0x17U == (0x7fU 
                                             & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                  | (0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))));
    bufp->fullBit(oldp+91,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+92,((0U == (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state))));
    bufp->fullCData(oldp+93,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state),2);
    bufp->fullCData(oldp+94,((0xfU & (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num))),4);
    bufp->fullCData(oldp+95,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__random_count),4);
    bufp->fullCData(oldp+96,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num),8);
    bufp->fullBit(oldp+97,((1U & VL_REDXOR_8((0xb8U 
                                              & (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num))))));
    bufp->fullSData(oldp+98,((vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                              >> 0x14U)),12);
    bufp->fullBit(oldp+99,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullCData(oldp+102,(vlSelf->top__DOT__wbu0__DOT__wstrb),4);
    bufp->fullBit(oldp+103,((0U == (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state))));
    bufp->fullCData(oldp+104,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state),2);
    bufp->fullCData(oldp+105,((0xfU & (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num))),4);
    bufp->fullCData(oldp+106,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__random_count),4);
    bufp->fullCData(oldp+107,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__memmask),3);
    bufp->fullCData(oldp+108,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num),8);
    bufp->fullBit(oldp+109,((1U & VL_REDXOR_8((0xb8U 
                                               & (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num))))));
    bufp->fullCData(oldp+110,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+111,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+114,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg))),32);
    bufp->fullIData(oldp+115,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg))),32);
    bufp->fullCData(oldp+116,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg)),8);
    bufp->fullSData(oldp+117,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg)),16);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+118,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+121,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+123,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+127,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+132,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+134,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+136,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+138,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+147,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+175,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+177,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+180,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+181,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+182,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+183,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+184,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+185,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+186,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+189,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+190,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+193,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+194,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+195,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+196,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+197,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+198,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+199,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+200,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+201,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+202,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+203,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+204,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+205,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+206,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+207,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+208,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+209,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+210,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+211,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+212,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+213,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+214,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+215,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+216,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+217,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+218,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+219,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+220,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+221,(vlSelf->top__DOT__ready_idu_to_ifu));
    bufp->fullBit(oldp+222,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+223,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+224,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+225,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+226,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullIData(oldp+227,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+228,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+229,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+230,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+231,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+232,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+233,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+234,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+235,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+236,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+237,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+238,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+239,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+240,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+241,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+242,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+243,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+244,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+245,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+246,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+247,(vlSelf->clk));
    bufp->fullBit(oldp+248,(vlSelf->rst));
    bufp->fullBit(oldp+249,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                             & (0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+250,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                             & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                      | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                         | (3U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))))))));
    bufp->fullIData(oldp+251,(((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg) 
                               & (IData)(vlSelf->top__DOT__ready_idu_to_ifu))),32);
    bufp->fullIData(oldp+252,(2U),32);
    bufp->fullIData(oldp+253,(1U),32);
    bufp->fullIData(oldp+254,(0x20U),32);
    bufp->fullIData(oldp+255,(0U),32);
    bufp->fullIData(oldp+256,(0U),32);
    bufp->fullIData(oldp+257,(0x21U),32);
    bufp->fullIData(oldp+258,(2U),32);
    bufp->fullBit(oldp+259,(vlSelf->top__DOT__ifu0__DOT__arvalid));
    bufp->fullBit(oldp+260,(vlSelf->top__DOT__ifu0__DOT__rvalid));
    bufp->fullBit(oldp+261,(vlSelf->top__DOT__ifu0__DOT__bvalid));
    bufp->fullBit(oldp+262,(vlSelf->top__DOT__ifu0__DOT__bresp));
    bufp->fullBit(oldp+263,(0U));
    bufp->fullCData(oldp+264,(0U),4);
    bufp->fullIData(oldp+265,(4U),32);
    bufp->fullIData(oldp+266,(3U),32);
    bufp->fullIData(oldp+267,(0x12491c4U),28);
    bufp->fullCData(oldp+268,(0U),3);
    bufp->fullIData(oldp+269,(7U),32);
    bufp->fullIData(oldp+270,(4U),32);
    bufp->fullIData(oldp+271,(0x80000000U),32);
    bufp->fullIData(oldp+272,(0xcU),32);
    bufp->fullQData(oldp+273,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+275,(0U),2);
    bufp->fullIData(oldp+276,(0xeU),32);
    bufp->fullIData(oldp+277,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullBit(oldp+278,(vlSelf->top__DOT__wbu0__DOT__bvalid));
    bufp->fullBit(oldp+279,(vlSelf->top__DOT__wbu0__DOT__bresp));
    bufp->fullIData(oldp+280,(8U),32);
    bufp->fullIData(oldp+281,(0x10U),32);
    bufp->fullIData(oldp+282,(0x23U),32);
}
