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
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBit(c+177,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBit(c+177,"rst", false,-1);
    tracep->declBit(c+180,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+133,"npc", false,-1, 31,0);
    tracep->declBus(c+48,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+181,"inst", false,-1, 31,0);
    tracep->declBit(c+182,"ifu_valid", false,-1);
    tracep->declBus(c+183,"src1", false,-1, 4,0);
    tracep->declBus(c+184,"src2", false,-1, 4,0);
    tracep->declBus(c+185,"rd", false,-1, 4,0);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBit(c+186,"ebreaksig", false,-1);
    tracep->declBit(c+187,"mretsig", false,-1);
    tracep->declBit(c+188,"ecallsig", false,-1);
    tracep->declBit(c+2,"regew", false,-1);
    tracep->declBit(c+189,"memew", false,-1);
    tracep->declBit(c+190,"memer", false,-1);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+192,"func7", false,-1);
    tracep->declBit(c+193,"btypebranch", false,-1);
    tracep->declBit(c+194,"jalsig", false,-1);
    tracep->declBit(c+195,"jalrsig", false,-1);
    tracep->declBit(c+196,"auipcsig", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+182,"idu_valid", false,-1);
    tracep->declBus(c+172,"regwrite", false,-1, 31,0);
    tracep->declBus(c+49,"regout1", false,-1, 31,0);
    tracep->declBus(c+134,"regout2", false,-1, 31,0);
    tracep->declBus(c+50,"mepc", false,-1, 31,0);
    tracep->declBus(c+51,"mtvec", false,-1, 31,0);
    tracep->declBus(c+135,"res", false,-1, 31,0);
    tracep->declBus(c+136,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+182,"exu_valid", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBit(c+193,"btypebranch", false,-1);
    tracep->declBit(c+192,"func7", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+195,"jalrsig", false,-1);
    tracep->declBit(c+194,"jalsig", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBus(c+49,"regout1", false,-1, 31,0);
    tracep->declBus(c+134,"regout2", false,-1, 31,0);
    tracep->declBus(c+48,"pc", false,-1, 31,0);
    tracep->declBit(c+196,"auipcsig", false,-1);
    tracep->declBit(c+187,"mretsig", false,-1);
    tracep->declBit(c+188,"ecallsig", false,-1);
    tracep->declBus(c+51,"mtvec", false,-1, 31,0);
    tracep->declBus(c+50,"mepc", false,-1, 31,0);
    tracep->declBit(c+182,"valid_from_idu", false,-1);
    tracep->declBus(c+135,"res", false,-1, 31,0);
    tracep->declBus(c+133,"npc", false,-1, 31,0);
    tracep->declBus(c+136,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+182,"valid", false,-1);
    tracep->declBus(c+52,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+137,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+8,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+138,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+139,"zero", false,-1);
    tracep->declBit(c+140,"signal", false,-1);
    tracep->declBit(c+141,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+49,"A", false,-1, 31,0);
    tracep->declBus(c+138,"B", false,-1, 31,0);
    tracep->declBus(c+8,"op", false,-1, 4,0);
    tracep->declBus(c+135,"res", false,-1, 31,0);
    tracep->declBit(c+139,"zero", false,-1);
    tracep->declBit(c+140,"signal", false,-1);
    tracep->declBit(c+141,"carry", false,-1);
    tracep->declBit(c+9,"addsig", false,-1);
    tracep->declBit(c+10,"logsig", false,-1);
    tracep->declBit(c+11,"shfsig", false,-1);
    tracep->declBit(c+12,"sltsig", false,-1);
    tracep->declBit(c+141,"carry_tmp", false,-1);
    tracep->declBit(c+13,"type_I", false,-1);
    tracep->declBus(c+142,"logres", false,-1, 31,0);
    tracep->declBus(c+143,"addres", false,-1, 31,0);
    tracep->declBit(c+144,"addzero", false,-1);
    tracep->declBus(c+145,"shfres", false,-1, 31,0);
    tracep->declBus(c+146,"sltres", false,-1, 31,0);
    tracep->declBus(c+49,"A_s", false,-1, 31,0);
    tracep->declBus(c+138,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBit(c+192,"func7", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+195,"jalrsig", false,-1);
    tracep->declBus(c+8,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+13,"type_I", false,-1);
    tracep->declBit(c+14,"type_B", false,-1);
    tracep->declBit(c+15,"type_R", false,-1);
    tracep->declBit(c+16,"addsig", false,-1);
    tracep->declBus(c+197,"branchop", false,-1, 3,0);
    tracep->declBus(c+17,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+193,"btypebranch", false,-1);
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBit(c+139,"zero", false,-1);
    tracep->declBit(c+140,"signal", false,-1);
    tracep->declBit(c+141,"carry", false,-1);
    tracep->declBus(c+135,"res", false,-1, 31,0);
    tracep->declBus(c+52,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+137,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+194,"jalsig", false,-1);
    tracep->declBit(c+195,"jalrsig", false,-1);
    tracep->declBit(c+196,"auipcsig", false,-1);
    tracep->declBit(c+187,"mretsig", false,-1);
    tracep->declBit(c+188,"ecallsig", false,-1);
    tracep->declBus(c+51,"mtvec", false,-1, 31,0);
    tracep->declBus(c+50,"mepc", false,-1, 31,0);
    tracep->declBus(c+133,"npc", false,-1, 31,0);
    tracep->declBus(c+136,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+198,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+199,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+200,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"out", false,-1, 31,0);
    tracep->declBus(c+3,"key", false,-1, 0,0);
    tracep->declArray(c+147,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+198,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+199,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+200,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+201,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+138,"out", false,-1, 31,0);
    tracep->declBus(c+3,"key", false,-1, 0,0);
    tracep->declBus(c+202,"default_out", false,-1, 31,0);
    tracep->declArray(c+147,"lut", false,-1, 65,0);
    tracep->declBus(c+203,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+150+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+18+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+53+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+154,"lut_out", false,-1, 31,0);
    tracep->declBit(c+20,"hit", false,-1);
    tracep->declBus(c+204,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+48,"pc", false,-1, 31,0);
    tracep->declBus(c+52,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+48,"pc", false,-1, 31,0);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+137,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+181,"inst", false,-1, 31,0);
    tracep->declBit(c+182,"valid_from_ifu", false,-1);
    tracep->declBit(c+186,"ebreaksig", false,-1);
    tracep->declBit(c+188,"ecallsig", false,-1);
    tracep->declBit(c+187,"mretsig", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBit(c+192,"func7", false,-1);
    tracep->declBus(c+183,"src1", false,-1, 4,0);
    tracep->declBus(c+184,"src2", false,-1, 4,0);
    tracep->declBus(c+185,"rd", false,-1, 4,0);
    tracep->declBit(c+189,"memew", false,-1);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+190,"memer", false,-1);
    tracep->declBit(c+2,"regew", false,-1);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBit(c+193,"btypebranch", false,-1);
    tracep->declBit(c+195,"jalrsig", false,-1);
    tracep->declBit(c+194,"jalsig", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+196,"auipcsig", false,-1);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+182,"valid", false,-1);
    tracep->declBit(c+180,"ready", false,-1);
    tracep->declBit(c+186,"ebreak", false,-1);
    tracep->declBit(c+188,"ecall", false,-1);
    tracep->declBit(c+187,"mret", false,-1);
    tracep->declBus(c+191,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+192,"func7bridge", false,-1);
    tracep->declBus(c+205,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+181,"inst", false,-1, 31,0);
    tracep->declBit(c+186,"ebreaksig", false,-1);
    tracep->declBit(c+188,"ecallsig", false,-1);
    tracep->declBit(c+187,"mretsig", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+205,"opcode", false,-1, 6,0);
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBit(c+192,"func7", false,-1);
    tracep->declBus(c+183,"src1", false,-1, 4,0);
    tracep->declBus(c+184,"src2", false,-1, 4,0);
    tracep->declBus(c+185,"rd", false,-1, 4,0);
    tracep->declBit(c+21,"type_I", false,-1);
    tracep->declBit(c+206,"type_R", false,-1);
    tracep->declBit(c+22,"type_U", false,-1);
    tracep->declBit(c+189,"type_S", false,-1);
    tracep->declBit(c+194,"type_J", false,-1);
    tracep->declBit(c+193,"type_B", false,-1);
    tracep->declBus(c+23,"I_imm", false,-1, 31,0);
    tracep->declBus(c+207,"U_imm", false,-1, 31,0);
    tracep->declBus(c+24,"S_imm", false,-1, 31,0);
    tracep->declBus(c+25,"J_imm", false,-1, 31,0);
    tracep->declBus(c+26,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+205,"opcode", false,-1, 6,0);
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBit(c+192,"func7", false,-1);
    tracep->declBit(c+186,"ebreaksig", false,-1);
    tracep->declBit(c+188,"ecallsig", false,-1);
    tracep->declBit(c+187,"mretsig", false,-1);
    tracep->declBit(c+189,"memew", false,-1);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+190,"memer", false,-1);
    tracep->declBit(c+2,"regew", false,-1);
    tracep->declBit(c+3,"muximm", false,-1);
    tracep->declBit(c+193,"btypebranch", false,-1);
    tracep->declBit(c+195,"jalrsig", false,-1);
    tracep->declBit(c+194,"jalsig", false,-1);
    tracep->declBus(c+5,"aluop", false,-1, 1,0);
    tracep->declBit(c+196,"auipcsig", false,-1);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+21,"type_I", false,-1);
    tracep->declBit(c+206,"type_R", false,-1);
    tracep->declBit(c+22,"type_U", false,-1);
    tracep->declBit(c+189,"type_S", false,-1);
    tracep->declBit(c+194,"type_J", false,-1);
    tracep->declBit(c+193,"type_B", false,-1);
    tracep->declBit(c+190,"load", false,-1);
    tracep->declBit(c+189,"store", false,-1);
    tracep->declBit(c+208,"regwritepc", false,-1);
    tracep->declBit(c+190,"regwritemem", false,-1);
    tracep->declBit(c+209,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBit(c+177,"rst", false,-1);
    tracep->declBus(c+133,"npc", false,-1, 31,0);
    tracep->declBit(c+180,"ready", false,-1);
    tracep->declBus(c+48,"pc", false,-1, 31,0);
    tracep->declBus(c+181,"inst", false,-1, 31,0);
    tracep->declBit(c+182,"valid", false,-1);
    tracep->declBus(c+48,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+181,"instbridge", false,-1, 31,0);
    tracep->declBit(c+182,"get_inst", false,-1);
    tracep->pushNamePrefix("infetch0 ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBus(c+48,"pc", false,-1, 31,0);
    tracep->declBit(c+180,"ready", false,-1);
    tracep->declBus(c+181,"inst", false,-1, 31,0);
    tracep->declBit(c+182,"valid", false,-1);
    tracep->declBus(c+181,"reg_inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBus(c+133,"npc", false,-1, 31,0);
    tracep->declBit(c+177,"rst", false,-1);
    tracep->declBit(c+182,"get_inst", false,-1);
    tracep->declBus(c+48,"pcout", false,-1, 31,0);
    tracep->declBus(c+210,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBit(c+177,"rst", false,-1);
    tracep->declBit(c+2,"ew", false,-1);
    tracep->declBus(c+185,"addr", false,-1, 4,0);
    tracep->declBus(c+183,"src1", false,-1, 4,0);
    tracep->declBus(c+184,"src2", false,-1, 4,0);
    tracep->declBus(c+211,"csr", false,-1, 11,0);
    tracep->declBus(c+172,"data", false,-1, 31,0);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+188,"ecallsig", false,-1);
    tracep->declBus(c+49,"regout1", false,-1, 31,0);
    tracep->declBus(c+134,"regout2", false,-1, 31,0);
    tracep->declBus(c+50,"mepc", false,-1, 31,0);
    tracep->declBus(c+51,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+55+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+87+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+27,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+173,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+212,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+213,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+198,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+27,"out", false,-1, 1,0);
    tracep->declBus(c+211,"key", false,-1, 11,0);
    tracep->declQuad(c+214,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+212,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+213,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+198,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+201,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+27,"out", false,-1, 1,0);
    tracep->declBus(c+211,"key", false,-1, 11,0);
    tracep->declBus(c+216,"default_out", false,-1, 1,0);
    tracep->declQuad(c+214,"lut", false,-1, 55,0);
    tracep->declBus(c+217,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+28+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+32+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+36+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+40,"lut_out", false,-1, 1,0);
    tracep->declBit(c+41,"hit", false,-1);
    tracep->declBus(c+218,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBit(c+177,"rst", false,-1);
    tracep->declBit(c+2,"ew", false,-1);
    tracep->declBit(c+6,"csrrw", false,-1);
    tracep->declBit(c+7,"csrrs", false,-1);
    tracep->declBit(c+188,"ecall", false,-1);
    tracep->declBus(c+27,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+185,"addr", false,-1, 4,0);
    tracep->declBus(c+173,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+91+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+123+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+127,"i", false,-1, 31,0);
    tracep->declBus(c+219,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBus(c+135,"res", false,-1, 31,0);
    tracep->declBus(c+134,"regout2", false,-1, 31,0);
    tracep->declBit(c+189,"memew", false,-1);
    tracep->declBit(c+190,"memer", false,-1);
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+136,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+4,"muxsig", false,-1, 2,0);
    tracep->declBit(c+182,"valid_from_exu", false,-1);
    tracep->declBus(c+172,"regwrite", false,-1, 31,0);
    tracep->declBus(c+178,"memread", false,-1, 31,0);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+176,"clk", false,-1);
    tracep->declBus(c+135,"addr", false,-1, 31,0);
    tracep->declBus(c+134,"write", false,-1, 31,0);
    tracep->declBus(c+191,"func3", false,-1, 2,0);
    tracep->declBit(c+190,"er", false,-1);
    tracep->declBit(c+189,"ew", false,-1);
    tracep->declBus(c+178,"read", false,-1, 31,0);
    tracep->declBus(c+128,"readreg", false,-1, 31,0);
    tracep->declBus(c+42,"len", false,-1, 2,0);
    tracep->declBit(c+43,"signalsig", false,-1);
    tracep->declBus(c+128,"read_u", false,-1, 31,0);
    tracep->declBus(c+179,"read_s", false,-1, 31,0);
    tracep->declBus(c+129,"read_sb", false,-1, 31,0);
    tracep->declBus(c+130,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+220,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+200,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+131,"input_number", false,-1, 7,0);
    tracep->declBus(c+129,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+221,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+200,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+132,"input_number", false,-1, 15,0);
    tracep->declBus(c+130,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+212,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+222,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+200,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+172,"out", false,-1, 31,0);
    tracep->declBus(c+4,"key", false,-1, 2,0);
    tracep->declBus(c+201,"default_out", false,-1, 31,0);
    tracep->declArray(c+155,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+212,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+222,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+200,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+199,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+172,"out", false,-1, 31,0);
    tracep->declBus(c+4,"key", false,-1, 2,0);
    tracep->declBus(c+201,"default_out", false,-1, 31,0);
    tracep->declArray(c+155,"lut", false,-1, 139,0);
    tracep->declBus(c+223,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+160+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+44+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+168+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+174,"lut_out", false,-1, 31,0);
    tracep->declBit(c+175,"hit", false,-1);
    tracep->declBus(c+218,"i", false,-1, 31,0);
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
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__regew));
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__muxsig),3);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+9,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+13,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+14,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+15,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+16,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+17,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+18,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+19,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+20,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+21,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+22,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullCData(oldp+27,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullSData(oldp+28,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+29,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+30,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+31,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+32,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+33,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+34,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+35,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+37,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+38,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+39,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+40,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+42,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__len),3);
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__signalsig));
    bufp->fullCData(oldp+44,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+45,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+46,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+47,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullIData(oldp+52,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg),32);
    bufp->fullIData(oldp+129,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullIData(oldp+130,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullCData(oldp+131,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),8);
    bufp->fullSData(oldp+132,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),16);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+139,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+140,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+141,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+144,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+147,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+150,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+152,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
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
    bufp->fullWData(oldp+155,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+160,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+162,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+164,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+166,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+175,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+176,(vlSelf->clk));
    bufp->fullBit(oldp+177,(vlSelf->rst));
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__read_s),32);
    bufp->fullBit(oldp+180,(1U));
    bufp->fullIData(oldp+181,(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst),32);
    bufp->fullBit(oldp+182,((0U != vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)));
    bufp->fullCData(oldp+183,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+184,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+185,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                        >> 7U))),5);
    bufp->fullBit(oldp+186,((0x100073U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)));
    bufp->fullBit(oldp+187,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)));
    bufp->fullBit(oldp+188,((0x73U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)));
    bufp->fullBit(oldp+189,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+190,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullCData(oldp+191,((7U & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                     >> 0xcU))),3);
    bufp->fullBit(oldp+192,((1U & (vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+193,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+194,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+195,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullBit(oldp+196,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullCData(oldp+197,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)))
                                         ? 9U : 3U))),4);
    bufp->fullIData(oldp+198,(2U),32);
    bufp->fullIData(oldp+199,(1U),32);
    bufp->fullIData(oldp+200,(0x20U),32);
    bufp->fullIData(oldp+201,(0U),32);
    bufp->fullIData(oldp+202,(0U),32);
    bufp->fullIData(oldp+203,(0x21U),32);
    bufp->fullIData(oldp+204,(2U),32);
    bufp->fullCData(oldp+205,((0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)),7);
    bufp->fullBit(oldp+206,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullIData(oldp+207,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)),32);
    bufp->fullBit(oldp+208,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))))));
    bufp->fullBit(oldp+209,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst))));
    bufp->fullIData(oldp+210,(0x80000000U),32);
    bufp->fullSData(oldp+211,((vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__reg_inst 
                               >> 0x14U)),12);
    bufp->fullIData(oldp+212,(4U),32);
    bufp->fullIData(oldp+213,(0xcU),32);
    bufp->fullQData(oldp+214,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+216,(0U),2);
    bufp->fullIData(oldp+217,(0xeU),32);
    bufp->fullIData(oldp+218,(4U),32);
    bufp->fullIData(oldp+219,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+220,(8U),32);
    bufp->fullIData(oldp+221,(0x10U),32);
    bufp->fullIData(oldp+222,(3U),32);
    bufp->fullIData(oldp+223,(0x23U),32);
}
