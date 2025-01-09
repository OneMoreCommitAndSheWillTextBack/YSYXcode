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
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBit(c+240,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBit(c+240,"rst", false,-1);
    tracep->declBit(c+121,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+232,"npc", false,-1, 31,0);
    tracep->declBus(c+241,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+122,"inst", false,-1, 31,0);
    tracep->declBit(c+123,"ifu_valid", false,-1);
    tracep->declBus(c+124,"src1", false,-1, 4,0);
    tracep->declBus(c+125,"src2", false,-1, 4,0);
    tracep->declBus(c+126,"rd", false,-1, 4,0);
    tracep->declBus(c+127,"imm", false,-1, 31,0);
    tracep->declBit(c+128,"ebreaksig", false,-1);
    tracep->declBit(c+129,"mretsig", false,-1);
    tracep->declBit(c+130,"ecallsig", false,-1);
    tracep->declBit(c+131,"regew", false,-1);
    tracep->declBit(c+132,"memew", false,-1);
    tracep->declBit(c+133,"memer", false,-1);
    tracep->declBit(c+134,"muximm", false,-1);
    tracep->declBus(c+135,"func3", false,-1, 2,0);
    tracep->declBus(c+136,"muxsig", false,-1, 2,0);
    tracep->declBit(c+137,"func7", false,-1);
    tracep->declBit(c+138,"btypebranch", false,-1);
    tracep->declBit(c+139,"jalsig", false,-1);
    tracep->declBit(c+140,"jalrsig", false,-1);
    tracep->declBit(c+141,"auipcsig", false,-1);
    tracep->declBus(c+142,"aluop", false,-1, 1,0);
    tracep->declBit(c+143,"csrrw", false,-1);
    tracep->declBit(c+144,"csrrs", false,-1);
    tracep->declBit(c+123,"idu_valid", false,-1);
    tracep->declBus(c+145,"memmask", false,-1, 2,0);
    tracep->declBit(c+146,"memsextsig", false,-1);
    tracep->declBus(c+233,"regwrite", false,-1, 31,0);
    tracep->declBus(c+219,"regout1", false,-1, 31,0);
    tracep->declBus(c+220,"regout2", false,-1, 31,0);
    tracep->declBus(c+46,"mepc", false,-1, 31,0);
    tracep->declBus(c+47,"mtvec", false,-1, 31,0);
    tracep->declBit(c+121,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+221,"res", false,-1, 31,0);
    tracep->declBus(c+234,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+123,"exu_valid", false,-1);
    tracep->declBit(c+121,"ready_wbu_to_exu", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+135,"func3", false,-1, 2,0);
    tracep->declBit(c+138,"btypebranch", false,-1);
    tracep->declBit(c+137,"func7", false,-1);
    tracep->declBus(c+142,"aluop", false,-1, 1,0);
    tracep->declBit(c+140,"jalrsig", false,-1);
    tracep->declBit(c+139,"jalsig", false,-1);
    tracep->declBus(c+127,"imm", false,-1, 31,0);
    tracep->declBit(c+134,"muximm", false,-1);
    tracep->declBus(c+219,"regout1", false,-1, 31,0);
    tracep->declBus(c+220,"regout2", false,-1, 31,0);
    tracep->declBus(c+241,"pc", false,-1, 31,0);
    tracep->declBit(c+141,"auipcsig", false,-1);
    tracep->declBit(c+129,"mretsig", false,-1);
    tracep->declBit(c+130,"ecallsig", false,-1);
    tracep->declBus(c+47,"mtvec", false,-1, 31,0);
    tracep->declBus(c+46,"mepc", false,-1, 31,0);
    tracep->declBit(c+123,"valid_from", false,-1);
    tracep->declBit(c+121,"ready_from", false,-1);
    tracep->declBus(c+221,"res", false,-1, 31,0);
    tracep->declBus(c+232,"npc", false,-1, 31,0);
    tracep->declBus(c+234,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+123,"valid_to", false,-1);
    tracep->declBit(c+121,"ready_to", false,-1);
    tracep->declBus(c+242,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+235,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+147,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+222,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+223,"zero", false,-1);
    tracep->declBit(c+224,"signal", false,-1);
    tracep->declBit(c+225,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+219,"A", false,-1, 31,0);
    tracep->declBus(c+222,"B", false,-1, 31,0);
    tracep->declBus(c+147,"op", false,-1, 4,0);
    tracep->declBus(c+221,"res", false,-1, 31,0);
    tracep->declBit(c+223,"zero", false,-1);
    tracep->declBit(c+224,"signal", false,-1);
    tracep->declBit(c+225,"carry", false,-1);
    tracep->declBit(c+148,"addsig", false,-1);
    tracep->declBit(c+149,"logsig", false,-1);
    tracep->declBit(c+150,"shfsig", false,-1);
    tracep->declBit(c+151,"sltsig", false,-1);
    tracep->declBit(c+225,"carry_tmp", false,-1);
    tracep->declBit(c+152,"type_I", false,-1);
    tracep->declBus(c+226,"logres", false,-1, 31,0);
    tracep->declBus(c+227,"addres", false,-1, 31,0);
    tracep->declBit(c+228,"addzero", false,-1);
    tracep->declBus(c+229,"shfres", false,-1, 31,0);
    tracep->declBus(c+230,"sltres", false,-1, 31,0);
    tracep->declBus(c+219,"A_s", false,-1, 31,0);
    tracep->declBus(c+222,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+135,"func3", false,-1, 2,0);
    tracep->declBit(c+137,"func7", false,-1);
    tracep->declBus(c+142,"aluop", false,-1, 1,0);
    tracep->declBit(c+140,"jalrsig", false,-1);
    tracep->declBus(c+147,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+152,"type_I", false,-1);
    tracep->declBit(c+153,"type_B", false,-1);
    tracep->declBit(c+154,"type_R", false,-1);
    tracep->declBit(c+155,"addsig", false,-1);
    tracep->declBus(c+156,"branchop", false,-1, 3,0);
    tracep->declBus(c+157,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+138,"btypebranch", false,-1);
    tracep->declBus(c+135,"func3", false,-1, 2,0);
    tracep->declBit(c+223,"zero", false,-1);
    tracep->declBit(c+224,"signal", false,-1);
    tracep->declBit(c+225,"carry", false,-1);
    tracep->declBus(c+221,"res", false,-1, 31,0);
    tracep->declBus(c+242,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+235,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+139,"jalsig", false,-1);
    tracep->declBit(c+140,"jalrsig", false,-1);
    tracep->declBit(c+141,"auipcsig", false,-1);
    tracep->declBit(c+129,"mretsig", false,-1);
    tracep->declBit(c+130,"ecallsig", false,-1);
    tracep->declBus(c+47,"mtvec", false,-1, 31,0);
    tracep->declBus(c+46,"mepc", false,-1, 31,0);
    tracep->declBus(c+232,"npc", false,-1, 31,0);
    tracep->declBus(c+234,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+243,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+244,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+245,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+222,"out", false,-1, 31,0);
    tracep->declBus(c+134,"key", false,-1, 0,0);
    tracep->declArray(c+193,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+243,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+244,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+245,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+246,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+222,"out", false,-1, 31,0);
    tracep->declBus(c+134,"key", false,-1, 0,0);
    tracep->declBus(c+247,"default_out", false,-1, 31,0);
    tracep->declArray(c+193,"lut", false,-1, 65,0);
    tracep->declBus(c+248,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+196+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+200+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+231,"lut_out", false,-1, 31,0);
    tracep->declBit(c+158,"hit", false,-1);
    tracep->declBus(c+249,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+241,"pc", false,-1, 31,0);
    tracep->declBus(c+242,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+241,"pc", false,-1, 31,0);
    tracep->declBus(c+127,"imm", false,-1, 31,0);
    tracep->declBus(c+235,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+122,"inst", false,-1, 31,0);
    tracep->declBit(c+123,"valid_from", false,-1);
    tracep->declBit(c+121,"ready_from", false,-1);
    tracep->declBit(c+128,"ebreaksig", false,-1);
    tracep->declBit(c+130,"ecallsig", false,-1);
    tracep->declBit(c+129,"mretsig", false,-1);
    tracep->declBus(c+127,"imm", false,-1, 31,0);
    tracep->declBus(c+135,"func3", false,-1, 2,0);
    tracep->declBit(c+137,"func7", false,-1);
    tracep->declBus(c+124,"src1", false,-1, 4,0);
    tracep->declBus(c+125,"src2", false,-1, 4,0);
    tracep->declBus(c+126,"rd", false,-1, 4,0);
    tracep->declBit(c+132,"memew", false,-1);
    tracep->declBus(c+136,"muxsig", false,-1, 2,0);
    tracep->declBit(c+133,"memer", false,-1);
    tracep->declBit(c+131,"regew", false,-1);
    tracep->declBit(c+134,"muximm", false,-1);
    tracep->declBit(c+138,"btypebranch", false,-1);
    tracep->declBit(c+140,"jalrsig", false,-1);
    tracep->declBit(c+139,"jalsig", false,-1);
    tracep->declBus(c+142,"aluop", false,-1, 1,0);
    tracep->declBit(c+141,"auipcsig", false,-1);
    tracep->declBit(c+143,"csrrw", false,-1);
    tracep->declBit(c+144,"csrrs", false,-1);
    tracep->declBit(c+123,"valid_to", false,-1);
    tracep->declBit(c+121,"ready_to", false,-1);
    tracep->declBus(c+145,"memmask", false,-1, 2,0);
    tracep->declBit(c+146,"memsextsig", false,-1);
    tracep->declBit(c+128,"ebreak", false,-1);
    tracep->declBit(c+130,"ecall", false,-1);
    tracep->declBit(c+129,"mret", false,-1);
    tracep->declBus(c+135,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+137,"func7bridge", false,-1);
    tracep->declBus(c+159,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+122,"inst", false,-1, 31,0);
    tracep->declBit(c+128,"ebreaksig", false,-1);
    tracep->declBit(c+130,"ecallsig", false,-1);
    tracep->declBit(c+129,"mretsig", false,-1);
    tracep->declBus(c+127,"imm", false,-1, 31,0);
    tracep->declBus(c+159,"opcode", false,-1, 6,0);
    tracep->declBus(c+135,"func3", false,-1, 2,0);
    tracep->declBit(c+137,"func7", false,-1);
    tracep->declBus(c+124,"src1", false,-1, 4,0);
    tracep->declBus(c+125,"src2", false,-1, 4,0);
    tracep->declBus(c+126,"rd", false,-1, 4,0);
    tracep->declBus(c+145,"memmask", false,-1, 2,0);
    tracep->declBit(c+146,"memsextsig", false,-1);
    tracep->declBit(c+160,"type_I", false,-1);
    tracep->declBit(c+161,"type_R", false,-1);
    tracep->declBit(c+162,"type_U", false,-1);
    tracep->declBit(c+132,"type_S", false,-1);
    tracep->declBit(c+139,"type_J", false,-1);
    tracep->declBit(c+138,"type_B", false,-1);
    tracep->declBus(c+163,"I_imm", false,-1, 31,0);
    tracep->declBus(c+164,"U_imm", false,-1, 31,0);
    tracep->declBus(c+165,"S_imm", false,-1, 31,0);
    tracep->declBus(c+166,"J_imm", false,-1, 31,0);
    tracep->declBus(c+167,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+159,"opcode", false,-1, 6,0);
    tracep->declBus(c+135,"func3", false,-1, 2,0);
    tracep->declBit(c+137,"func7", false,-1);
    tracep->declBit(c+128,"ebreaksig", false,-1);
    tracep->declBit(c+130,"ecallsig", false,-1);
    tracep->declBit(c+129,"mretsig", false,-1);
    tracep->declBit(c+132,"memew", false,-1);
    tracep->declBus(c+136,"muxsig", false,-1, 2,0);
    tracep->declBit(c+133,"memer", false,-1);
    tracep->declBit(c+131,"regew", false,-1);
    tracep->declBit(c+134,"muximm", false,-1);
    tracep->declBit(c+138,"btypebranch", false,-1);
    tracep->declBit(c+140,"jalrsig", false,-1);
    tracep->declBit(c+139,"jalsig", false,-1);
    tracep->declBus(c+142,"aluop", false,-1, 1,0);
    tracep->declBit(c+141,"auipcsig", false,-1);
    tracep->declBit(c+143,"csrrw", false,-1);
    tracep->declBit(c+144,"csrrs", false,-1);
    tracep->declBit(c+160,"type_I", false,-1);
    tracep->declBit(c+161,"type_R", false,-1);
    tracep->declBit(c+162,"type_U", false,-1);
    tracep->declBit(c+132,"type_S", false,-1);
    tracep->declBit(c+139,"type_J", false,-1);
    tracep->declBit(c+138,"type_B", false,-1);
    tracep->declBit(c+133,"load", false,-1);
    tracep->declBit(c+132,"store", false,-1);
    tracep->declBit(c+168,"regwritepc", false,-1);
    tracep->declBit(c+133,"regwritemem", false,-1);
    tracep->declBit(c+169,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBit(c+240,"rst", false,-1);
    tracep->declBus(c+232,"npc", false,-1, 31,0);
    tracep->declBit(c+121,"ready", false,-1);
    tracep->declBus(c+241,"pc", false,-1, 31,0);
    tracep->declBus(c+122,"inst", false,-1, 31,0);
    tracep->declBit(c+123,"valid", false,-1);
    tracep->declBus(c+241,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+122,"instbridge", false,-1, 31,0);
    tracep->declBit(c+170,"infetch_ready", false,-1);
    tracep->declBit(c+171,"arready", false,-1);
    tracep->declBit(c+171,"rready", false,-1);
    tracep->declBit(c+250,"arvalid", false,-1);
    tracep->declBit(c+251,"rvalid", false,-1);
    tracep->declBit(c+171,"awready", false,-1);
    tracep->declBit(c+171,"wready", false,-1);
    tracep->declBit(c+252,"bvalid", false,-1);
    tracep->declBit(c+253,"bresp", false,-1);
    tracep->pushNamePrefix("infetch ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBit(c+254,"awvalid", false,-1);
    tracep->declBit(c+171,"awready", false,-1);
    tracep->declBus(c+246,"awaddr", false,-1, 31,0);
    tracep->declBit(c+254,"wvalid", false,-1);
    tracep->declBit(c+171,"wready", false,-1);
    tracep->declBus(c+246,"wdata", false,-1, 31,0);
    tracep->declBus(c+255,"wstrb", false,-1, 3,0);
    tracep->declBit(c+252,"bvalid", false,-1);
    tracep->declBit(c+254,"bready", false,-1);
    tracep->declBit(c+253,"bresp", false,-1);
    tracep->declBit(c+121,"arvalid", false,-1);
    tracep->declBit(c+171,"arready", false,-1);
    tracep->declBus(c+241,"araddr", false,-1, 31,0);
    tracep->declBit(c+121,"rvalid", false,-1);
    tracep->declBit(c+171,"rready", false,-1);
    tracep->declBus(c+122,"rdata", false,-1, 31,0);
    tracep->declBus(c+172,"state", false,-1, 1,0);
    tracep->declBus(c+3,"memmask", false,-1, 2,0);
    tracep->declBus(c+122,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+256,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+257,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+3,"out", false,-1, 2,0);
    tracep->declBus(c+255,"key", false,-1, 3,0);
    tracep->declBus(c+258,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+256,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+257,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+246,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+3,"out", false,-1, 2,0);
    tracep->declBus(c+255,"key", false,-1, 3,0);
    tracep->declBus(c+259,"default_out", false,-1, 2,0);
    tracep->declBus(c+258,"lut", false,-1, 27,0);
    tracep->declBus(c+260,"PAIR_LEN", false,-1, 31,0);
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
    tracep->declBus(c+261,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBus(c+232,"npc", false,-1, 31,0);
    tracep->declBit(c+240,"rst", false,-1);
    tracep->declBit(c+170,"ready_from", false,-1);
    tracep->declBus(c+241,"pcout", false,-1, 31,0);
    tracep->declBus(c+262,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBit(c+240,"rst", false,-1);
    tracep->declBit(c+173,"ew", false,-1);
    tracep->declBus(c+126,"addr", false,-1, 4,0);
    tracep->declBus(c+124,"src1", false,-1, 4,0);
    tracep->declBus(c+125,"src2", false,-1, 4,0);
    tracep->declBus(c+174,"csr", false,-1, 11,0);
    tracep->declBus(c+233,"data", false,-1, 31,0);
    tracep->declBit(c+143,"csrrw", false,-1);
    tracep->declBit(c+144,"csrrs", false,-1);
    tracep->declBit(c+130,"ecallsig", false,-1);
    tracep->declBit(c+123,"valid", false,-1);
    tracep->declBus(c+219,"regout1", false,-1, 31,0);
    tracep->declBus(c+220,"regout2", false,-1, 31,0);
    tracep->declBus(c+46,"mepc", false,-1, 31,0);
    tracep->declBus(c+47,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+48+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+80+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+175,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+236,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+263,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+243,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+175,"out", false,-1, 1,0);
    tracep->declBus(c+174,"key", false,-1, 11,0);
    tracep->declQuad(c+264,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+263,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+243,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+246,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+175,"out", false,-1, 1,0);
    tracep->declBus(c+174,"key", false,-1, 11,0);
    tracep->declBus(c+266,"default_out", false,-1, 1,0);
    tracep->declQuad(c+264,"lut", false,-1, 55,0);
    tracep->declBus(c+267,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+18+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+22+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+26+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+176,"lut_out", false,-1, 1,0);
    tracep->declBit(c+177,"hit", false,-1);
    tracep->declBus(c+261,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBit(c+240,"rst", false,-1);
    tracep->declBit(c+178,"ew", false,-1);
    tracep->declBit(c+143,"csrrw", false,-1);
    tracep->declBit(c+144,"csrrs", false,-1);
    tracep->declBit(c+130,"ecall", false,-1);
    tracep->declBus(c+175,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+126,"addr", false,-1, 4,0);
    tracep->declBus(c+236,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+84+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+116+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+120,"i", false,-1, 31,0);
    tracep->declBus(c+268,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBus(c+221,"res", false,-1, 31,0);
    tracep->declBus(c+220,"regout2", false,-1, 31,0);
    tracep->declBit(c+132,"memew", false,-1);
    tracep->declBit(c+133,"memer", false,-1);
    tracep->declBus(c+127,"imm", false,-1, 31,0);
    tracep->declBus(c+234,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+136,"muxsig", false,-1, 2,0);
    tracep->declBit(c+123,"valid_from", false,-1);
    tracep->declBus(c+145,"memmask", false,-1, 2,0);
    tracep->declBit(c+146,"memsextsig", false,-1);
    tracep->declBus(c+233,"regwrite", false,-1, 31,0);
    tracep->declBit(c+121,"ready_to", false,-1);
    tracep->declBus(c+179,"readdata", false,-1, 31,0);
    tracep->declBus(c+180,"memread", false,-1, 31,0);
    tracep->declBus(c+181,"wstrb", false,-1, 3,0);
    tracep->declBit(c+121,"awready", false,-1);
    tracep->declBit(c+121,"wready", false,-1);
    tracep->declBit(c+269,"bvalid", false,-1);
    tracep->declBit(c+121,"arready", false,-1);
    tracep->declBit(c+121,"rready", false,-1);
    tracep->declBit(c+270,"bresp", false,-1);
    tracep->declBit(c+121,"ready", false,-1);
    tracep->declBit(c+182,"memready", false,-1);
    tracep->declBus(c+183,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+239,"clk", false,-1);
    tracep->declBit(c+132,"awvalid", false,-1);
    tracep->declBit(c+121,"awready", false,-1);
    tracep->declBus(c+221,"awaddr", false,-1, 31,0);
    tracep->declBit(c+132,"wvalid", false,-1);
    tracep->declBit(c+121,"wready", false,-1);
    tracep->declBus(c+220,"wdata", false,-1, 31,0);
    tracep->declBus(c+181,"wstrb", false,-1, 3,0);
    tracep->declBit(c+269,"bvalid", false,-1);
    tracep->declBit(c+132,"bready", false,-1);
    tracep->declBit(c+270,"bresp", false,-1);
    tracep->declBit(c+133,"arvalid", false,-1);
    tracep->declBit(c+121,"arready", false,-1);
    tracep->declBus(c+221,"araddr", false,-1, 31,0);
    tracep->declBit(c+133,"rvalid", false,-1);
    tracep->declBit(c+121,"rready", false,-1);
    tracep->declBus(c+179,"rdata", false,-1, 31,0);
    tracep->declBus(c+184,"state", false,-1, 1,0);
    tracep->declBus(c+185,"memmask", false,-1, 2,0);
    tracep->declBus(c+179,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+256,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+257,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+185,"out", false,-1, 2,0);
    tracep->declBus(c+181,"key", false,-1, 3,0);
    tracep->declBus(c+258,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+256,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+257,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+246,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+185,"out", false,-1, 2,0);
    tracep->declBus(c+181,"key", false,-1, 3,0);
    tracep->declBus(c+259,"default_out", false,-1, 2,0);
    tracep->declBus(c+258,"lut", false,-1, 27,0);
    tracep->declBus(c+260,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+30+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+34+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+38+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+186,"lut_out", false,-1, 2,0);
    tracep->declBit(c+187,"hit", false,-1);
    tracep->declBus(c+261,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+179,"data", false,-1, 31,0);
    tracep->declBus(c+145,"memmask", false,-1, 2,0);
    tracep->declBit(c+146,"memsextsig", false,-1);
    tracep->declBus(c+180,"read", false,-1, 31,0);
    tracep->declBus(c+179,"read_u", false,-1, 31,0);
    tracep->declBus(c+188,"read_s", false,-1, 31,0);
    tracep->declBus(c+189,"read_sb", false,-1, 31,0);
    tracep->declBus(c+190,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+271,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+245,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+191,"input_number", false,-1, 7,0);
    tracep->declBus(c+189,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+272,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+245,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+192,"input_number", false,-1, 15,0);
    tracep->declBus(c+190,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+257,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+245,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+233,"out", false,-1, 31,0);
    tracep->declBus(c+136,"key", false,-1, 2,0);
    tracep->declBus(c+246,"default_out", false,-1, 31,0);
    tracep->declArray(c+202,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+256,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+257,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+245,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+244,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+233,"out", false,-1, 31,0);
    tracep->declBus(c+136,"key", false,-1, 2,0);
    tracep->declBus(c+246,"default_out", false,-1, 31,0);
    tracep->declArray(c+202,"lut", false,-1, 139,0);
    tracep->declBus(c+273,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+207+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+42+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+215+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+237,"lut_out", false,-1, 31,0);
    tracep->declBit(c+238,"hit", false,-1);
    tracep->declBus(c+261,"i", false,-1, 31,0);
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
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+121,((0U == (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state))));
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg),32);
    bufp->fullBit(oldp+123,((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullCData(oldp+124,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+125,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+126,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+128,((0x100073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+129,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+130,((0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)));
    bufp->fullBit(oldp+131,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                             | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                      | (3U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))))));
    bufp->fullBit(oldp+132,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+133,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+134,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+135,((7U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+136,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+137,((1U & (vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+138,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+139,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+140,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+141,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullCData(oldp+142,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+143,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+144,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+145,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+146,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+147,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+148,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+149,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+150,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+151,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+152,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+153,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+154,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+155,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+156,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+157,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+158,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+159,((0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),7);
    bufp->fullBit(oldp+160,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+161,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+162,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+164,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+168,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))))));
    bufp->fullBit(oldp+169,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+170,(((0U == (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state)) 
                             & (0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg))));
    bufp->fullBit(oldp+171,((0U == (IData)(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state))));
    bufp->fullCData(oldp+172,(vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state),2);
    bufp->fullBit(oldp+173,(((0U == (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state)) 
                             & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                      | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                         | (3U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))))))));
    bufp->fullSData(oldp+174,((vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+175,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+176,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+177,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+178,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg),32);
    bufp->fullIData(oldp+180,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullCData(oldp+181,(vlSelf->top__DOT__wbu0__DOT__wstrb),4);
    bufp->fullBit(oldp+182,((1U & ((~ ((3U == (0x7fU 
                                               & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                       | (0x23U == 
                                          (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))) 
                                   | (0U != (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state))))));
    bufp->fullIData(oldp+183,(((0U != vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg) 
                               & ((~ ((3U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)) 
                                      | (0x23U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg)))) 
                                  | (0U != (IData)(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state))))),32);
    bufp->fullCData(oldp+184,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__state),2);
    bufp->fullCData(oldp+185,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__memmask),3);
    bufp->fullCData(oldp+186,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+187,(vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+189,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg))),32);
    bufp->fullIData(oldp+190,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg))),32);
    bufp->fullCData(oldp+191,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg)),8);
    bufp->fullSData(oldp+192,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg)),16);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+193,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+196,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+198,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+200,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+201,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+202,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+207,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+209,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+211,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+213,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+215,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+216,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+217,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+218,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+219,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+220,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+221,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+222,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+223,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+224,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+225,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+226,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+227,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+228,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+229,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+230,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+231,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+232,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+233,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+234,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+235,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+236,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+237,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+238,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+239,(vlSelf->clk));
    bufp->fullBit(oldp+240,(vlSelf->rst));
    bufp->fullIData(oldp+241,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+242,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+243,(2U),32);
    bufp->fullIData(oldp+244,(1U),32);
    bufp->fullIData(oldp+245,(0x20U),32);
    bufp->fullIData(oldp+246,(0U),32);
    bufp->fullIData(oldp+247,(0U),32);
    bufp->fullIData(oldp+248,(0x21U),32);
    bufp->fullIData(oldp+249,(2U),32);
    bufp->fullBit(oldp+250,(vlSelf->top__DOT__ifu0__DOT__arvalid));
    bufp->fullBit(oldp+251,(vlSelf->top__DOT__ifu0__DOT__rvalid));
    bufp->fullBit(oldp+252,(vlSelf->top__DOT__ifu0__DOT__bvalid));
    bufp->fullBit(oldp+253,(vlSelf->top__DOT__ifu0__DOT__bresp));
    bufp->fullBit(oldp+254,(0U));
    bufp->fullCData(oldp+255,(0U),4);
    bufp->fullIData(oldp+256,(4U),32);
    bufp->fullIData(oldp+257,(3U),32);
    bufp->fullIData(oldp+258,(0x12491c4U),28);
    bufp->fullCData(oldp+259,(0U),3);
    bufp->fullIData(oldp+260,(7U),32);
    bufp->fullIData(oldp+261,(4U),32);
    bufp->fullIData(oldp+262,(0x80000000U),32);
    bufp->fullIData(oldp+263,(0xcU),32);
    bufp->fullQData(oldp+264,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+266,(0U),2);
    bufp->fullIData(oldp+267,(0xeU),32);
    bufp->fullIData(oldp+268,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullBit(oldp+269,(vlSelf->top__DOT__wbu0__DOT__bvalid));
    bufp->fullBit(oldp+270,(vlSelf->top__DOT__wbu0__DOT__bresp));
    bufp->fullIData(oldp+271,(8U),32);
    bufp->fullIData(oldp+272,(0x10U),32);
    bufp->fullIData(oldp+273,(0x23U),32);
}
