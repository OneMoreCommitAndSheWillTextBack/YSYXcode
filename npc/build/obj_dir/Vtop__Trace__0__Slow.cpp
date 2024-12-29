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
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBit(c+202,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBit(c+202,"rst", false,-1);
    tracep->declBit(c+208,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+181,"npc", false,-1, 31,0);
    tracep->declBus(c+203,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+95,"inst", false,-1, 31,0);
    tracep->declBit(c+96,"ifu_valid", false,-1);
    tracep->declBus(c+97,"src1", false,-1, 4,0);
    tracep->declBus(c+98,"src2", false,-1, 4,0);
    tracep->declBus(c+99,"rd", false,-1, 4,0);
    tracep->declBus(c+100,"imm", false,-1, 31,0);
    tracep->declBit(c+101,"ebreaksig", false,-1);
    tracep->declBit(c+102,"mretsig", false,-1);
    tracep->declBit(c+103,"ecallsig", false,-1);
    tracep->declBit(c+104,"regew", false,-1);
    tracep->declBit(c+105,"memew", false,-1);
    tracep->declBit(c+106,"memer", false,-1);
    tracep->declBit(c+107,"muximm", false,-1);
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBus(c+109,"muxsig", false,-1, 2,0);
    tracep->declBit(c+110,"func7", false,-1);
    tracep->declBit(c+111,"btypebranch", false,-1);
    tracep->declBit(c+112,"jalsig", false,-1);
    tracep->declBit(c+113,"jalrsig", false,-1);
    tracep->declBit(c+114,"auipcsig", false,-1);
    tracep->declBus(c+115,"aluop", false,-1, 1,0);
    tracep->declBit(c+116,"csrrw", false,-1);
    tracep->declBit(c+117,"csrrs", false,-1);
    tracep->declBit(c+96,"idu_valid", false,-1);
    tracep->declBus(c+204,"memmask", false,-1, 2,0);
    tracep->declBit(c+118,"memsextsig", false,-1);
    tracep->declBus(c+197,"regwrite", false,-1, 31,0);
    tracep->declBus(c+182,"regout1", false,-1, 31,0);
    tracep->declBus(c+183,"regout2", false,-1, 31,0);
    tracep->declBus(c+19,"mepc", false,-1, 31,0);
    tracep->declBus(c+20,"mtvec", false,-1, 31,0);
    tracep->declBus(c+184,"res", false,-1, 31,0);
    tracep->declBus(c+185,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+96,"exu_valid", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBit(c+111,"btypebranch", false,-1);
    tracep->declBit(c+110,"func7", false,-1);
    tracep->declBus(c+115,"aluop", false,-1, 1,0);
    tracep->declBit(c+113,"jalrsig", false,-1);
    tracep->declBit(c+112,"jalsig", false,-1);
    tracep->declBus(c+100,"imm", false,-1, 31,0);
    tracep->declBit(c+107,"muximm", false,-1);
    tracep->declBus(c+182,"regout1", false,-1, 31,0);
    tracep->declBus(c+183,"regout2", false,-1, 31,0);
    tracep->declBus(c+203,"pc", false,-1, 31,0);
    tracep->declBit(c+114,"auipcsig", false,-1);
    tracep->declBit(c+102,"mretsig", false,-1);
    tracep->declBit(c+103,"ecallsig", false,-1);
    tracep->declBus(c+20,"mtvec", false,-1, 31,0);
    tracep->declBus(c+19,"mepc", false,-1, 31,0);
    tracep->declBit(c+96,"valid_from_idu", false,-1);
    tracep->declBus(c+184,"res", false,-1, 31,0);
    tracep->declBus(c+181,"npc", false,-1, 31,0);
    tracep->declBus(c+185,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+96,"valid", false,-1);
    tracep->declBus(c+205,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+186,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+119,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+187,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+188,"zero", false,-1);
    tracep->declBit(c+189,"signal", false,-1);
    tracep->declBit(c+190,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+182,"A", false,-1, 31,0);
    tracep->declBus(c+187,"B", false,-1, 31,0);
    tracep->declBus(c+119,"op", false,-1, 4,0);
    tracep->declBus(c+184,"res", false,-1, 31,0);
    tracep->declBit(c+188,"zero", false,-1);
    tracep->declBit(c+189,"signal", false,-1);
    tracep->declBit(c+190,"carry", false,-1);
    tracep->declBit(c+120,"addsig", false,-1);
    tracep->declBit(c+121,"logsig", false,-1);
    tracep->declBit(c+122,"shfsig", false,-1);
    tracep->declBit(c+123,"sltsig", false,-1);
    tracep->declBit(c+190,"carry_tmp", false,-1);
    tracep->declBit(c+124,"type_I", false,-1);
    tracep->declBus(c+191,"logres", false,-1, 31,0);
    tracep->declBus(c+192,"addres", false,-1, 31,0);
    tracep->declBit(c+193,"addzero", false,-1);
    tracep->declBus(c+194,"shfres", false,-1, 31,0);
    tracep->declBus(c+195,"sltres", false,-1, 31,0);
    tracep->declBus(c+182,"A_s", false,-1, 31,0);
    tracep->declBus(c+187,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBit(c+110,"func7", false,-1);
    tracep->declBus(c+115,"aluop", false,-1, 1,0);
    tracep->declBit(c+113,"jalrsig", false,-1);
    tracep->declBus(c+119,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+124,"type_I", false,-1);
    tracep->declBit(c+125,"type_B", false,-1);
    tracep->declBit(c+126,"type_R", false,-1);
    tracep->declBit(c+127,"addsig", false,-1);
    tracep->declBus(c+128,"branchop", false,-1, 3,0);
    tracep->declBus(c+129,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+111,"btypebranch", false,-1);
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBit(c+188,"zero", false,-1);
    tracep->declBit(c+189,"signal", false,-1);
    tracep->declBit(c+190,"carry", false,-1);
    tracep->declBus(c+184,"res", false,-1, 31,0);
    tracep->declBus(c+205,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+186,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+112,"jalsig", false,-1);
    tracep->declBit(c+113,"jalrsig", false,-1);
    tracep->declBit(c+114,"auipcsig", false,-1);
    tracep->declBit(c+102,"mretsig", false,-1);
    tracep->declBit(c+103,"ecallsig", false,-1);
    tracep->declBus(c+20,"mtvec", false,-1, 31,0);
    tracep->declBus(c+19,"mepc", false,-1, 31,0);
    tracep->declBus(c+181,"npc", false,-1, 31,0);
    tracep->declBus(c+185,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+210,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+187,"out", false,-1, 31,0);
    tracep->declBus(c+107,"key", false,-1, 0,0);
    tracep->declArray(c+150,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+210,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+187,"out", false,-1, 31,0);
    tracep->declBus(c+107,"key", false,-1, 0,0);
    tracep->declBus(c+213,"default_out", false,-1, 31,0);
    tracep->declArray(c+150,"lut", false,-1, 65,0);
    tracep->declBus(c+214,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+153+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+157+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+196,"lut_out", false,-1, 31,0);
    tracep->declBit(c+130,"hit", false,-1);
    tracep->declBus(c+215,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+203,"pc", false,-1, 31,0);
    tracep->declBus(c+205,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+203,"pc", false,-1, 31,0);
    tracep->declBus(c+100,"imm", false,-1, 31,0);
    tracep->declBus(c+186,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+95,"inst", false,-1, 31,0);
    tracep->declBit(c+96,"valid_from_ifu", false,-1);
    tracep->declBit(c+101,"ebreaksig", false,-1);
    tracep->declBit(c+103,"ecallsig", false,-1);
    tracep->declBit(c+102,"mretsig", false,-1);
    tracep->declBus(c+100,"imm", false,-1, 31,0);
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBit(c+110,"func7", false,-1);
    tracep->declBus(c+97,"src1", false,-1, 4,0);
    tracep->declBus(c+98,"src2", false,-1, 4,0);
    tracep->declBus(c+99,"rd", false,-1, 4,0);
    tracep->declBit(c+105,"memew", false,-1);
    tracep->declBus(c+109,"muxsig", false,-1, 2,0);
    tracep->declBit(c+106,"memer", false,-1);
    tracep->declBit(c+104,"regew", false,-1);
    tracep->declBit(c+107,"muximm", false,-1);
    tracep->declBit(c+111,"btypebranch", false,-1);
    tracep->declBit(c+113,"jalrsig", false,-1);
    tracep->declBit(c+112,"jalsig", false,-1);
    tracep->declBus(c+115,"aluop", false,-1, 1,0);
    tracep->declBit(c+114,"auipcsig", false,-1);
    tracep->declBit(c+116,"csrrw", false,-1);
    tracep->declBit(c+117,"csrrs", false,-1);
    tracep->declBit(c+96,"valid", false,-1);
    tracep->declBit(c+208,"ready", false,-1);
    tracep->declBus(c+204,"memmask", false,-1, 2,0);
    tracep->declBit(c+118,"memsextsig", false,-1);
    tracep->declBit(c+101,"ebreak", false,-1);
    tracep->declBit(c+103,"ecall", false,-1);
    tracep->declBit(c+102,"mret", false,-1);
    tracep->declBus(c+108,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+110,"func7bridge", false,-1);
    tracep->declBus(c+131,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+95,"inst", false,-1, 31,0);
    tracep->declBit(c+101,"ebreaksig", false,-1);
    tracep->declBit(c+103,"ecallsig", false,-1);
    tracep->declBit(c+102,"mretsig", false,-1);
    tracep->declBus(c+100,"imm", false,-1, 31,0);
    tracep->declBus(c+131,"opcode", false,-1, 6,0);
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBit(c+110,"func7", false,-1);
    tracep->declBus(c+97,"src1", false,-1, 4,0);
    tracep->declBus(c+98,"src2", false,-1, 4,0);
    tracep->declBus(c+99,"rd", false,-1, 4,0);
    tracep->declBus(c+204,"memmask", false,-1, 2,0);
    tracep->declBit(c+118,"memsextsig", false,-1);
    tracep->declBit(c+132,"type_I", false,-1);
    tracep->declBit(c+133,"type_R", false,-1);
    tracep->declBit(c+134,"type_U", false,-1);
    tracep->declBit(c+105,"type_S", false,-1);
    tracep->declBit(c+112,"type_J", false,-1);
    tracep->declBit(c+111,"type_B", false,-1);
    tracep->declBus(c+135,"I_imm", false,-1, 31,0);
    tracep->declBus(c+136,"U_imm", false,-1, 31,0);
    tracep->declBus(c+137,"S_imm", false,-1, 31,0);
    tracep->declBus(c+138,"J_imm", false,-1, 31,0);
    tracep->declBus(c+139,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+131,"opcode", false,-1, 6,0);
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBit(c+110,"func7", false,-1);
    tracep->declBit(c+101,"ebreaksig", false,-1);
    tracep->declBit(c+103,"ecallsig", false,-1);
    tracep->declBit(c+102,"mretsig", false,-1);
    tracep->declBit(c+105,"memew", false,-1);
    tracep->declBus(c+109,"muxsig", false,-1, 2,0);
    tracep->declBit(c+106,"memer", false,-1);
    tracep->declBit(c+104,"regew", false,-1);
    tracep->declBit(c+107,"muximm", false,-1);
    tracep->declBit(c+111,"btypebranch", false,-1);
    tracep->declBit(c+113,"jalrsig", false,-1);
    tracep->declBit(c+112,"jalsig", false,-1);
    tracep->declBus(c+115,"aluop", false,-1, 1,0);
    tracep->declBit(c+114,"auipcsig", false,-1);
    tracep->declBit(c+116,"csrrw", false,-1);
    tracep->declBit(c+117,"csrrs", false,-1);
    tracep->declBit(c+132,"type_I", false,-1);
    tracep->declBit(c+133,"type_R", false,-1);
    tracep->declBit(c+134,"type_U", false,-1);
    tracep->declBit(c+105,"type_S", false,-1);
    tracep->declBit(c+112,"type_J", false,-1);
    tracep->declBit(c+111,"type_B", false,-1);
    tracep->declBit(c+106,"load", false,-1);
    tracep->declBit(c+105,"store", false,-1);
    tracep->declBit(c+140,"regwritepc", false,-1);
    tracep->declBit(c+106,"regwritemem", false,-1);
    tracep->declBit(c+141,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBit(c+202,"rst", false,-1);
    tracep->declBus(c+181,"npc", false,-1, 31,0);
    tracep->declBit(c+208,"ready", false,-1);
    tracep->declBus(c+203,"pc", false,-1, 31,0);
    tracep->declBus(c+95,"inst", false,-1, 31,0);
    tracep->declBit(c+96,"valid", false,-1);
    tracep->declBus(c+203,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+95,"instbridge", false,-1, 31,0);
    tracep->declBit(c+21,"pc_valid", false,-1);
    tracep->declBit(c+142,"infetch_ready", false,-1);
    tracep->pushNamePrefix("infetch0 ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBus(c+203,"pc", false,-1, 31,0);
    tracep->declBus(c+95,"inst", false,-1, 31,0);
    tracep->declBit(c+96,"valid_to", false,-1);
    tracep->declBit(c+21,"valid_from", false,-1);
    tracep->declBit(c+142,"ready_to", false,-1);
    tracep->declBit(c+208,"ready_from", false,-1);
    tracep->declBit(c+143,"state", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBus(c+181,"npc", false,-1, 31,0);
    tracep->declBit(c+202,"rst", false,-1);
    tracep->declBit(c+142,"ready_from", false,-1);
    tracep->declBus(c+203,"pcout", false,-1, 31,0);
    tracep->declBit(c+21,"valid_to", false,-1);
    tracep->declBus(c+216,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBit(c+202,"rst", false,-1);
    tracep->declBit(c+104,"ew", false,-1);
    tracep->declBus(c+99,"addr", false,-1, 4,0);
    tracep->declBus(c+97,"src1", false,-1, 4,0);
    tracep->declBus(c+98,"src2", false,-1, 4,0);
    tracep->declBus(c+144,"csr", false,-1, 11,0);
    tracep->declBus(c+197,"data", false,-1, 31,0);
    tracep->declBit(c+116,"csrrw", false,-1);
    tracep->declBit(c+117,"csrrs", false,-1);
    tracep->declBit(c+103,"ecallsig", false,-1);
    tracep->declBit(c+96,"valid", false,-1);
    tracep->declBus(c+182,"regout1", false,-1, 31,0);
    tracep->declBus(c+183,"regout2", false,-1, 31,0);
    tracep->declBus(c+19,"mepc", false,-1, 31,0);
    tracep->declBus(c+20,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+22+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+54+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+145,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+198,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+145,"out", false,-1, 1,0);
    tracep->declBus(c+144,"key", false,-1, 11,0);
    tracep->declQuad(c+219,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+212,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+145,"out", false,-1, 1,0);
    tracep->declBus(c+144,"key", false,-1, 11,0);
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
    tracep->declBus(c+146,"lut_out", false,-1, 1,0);
    tracep->declBit(c+147,"hit", false,-1);
    tracep->declBus(c+223,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBit(c+202,"rst", false,-1);
    tracep->declBit(c+148,"ew", false,-1);
    tracep->declBit(c+116,"csrrw", false,-1);
    tracep->declBit(c+117,"csrrs", false,-1);
    tracep->declBit(c+103,"ecall", false,-1);
    tracep->declBus(c+145,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+99,"addr", false,-1, 4,0);
    tracep->declBus(c+198,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+58+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+90+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+94,"i", false,-1, 31,0);
    tracep->declBus(c+224,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBus(c+184,"res", false,-1, 31,0);
    tracep->declBus(c+183,"regout2", false,-1, 31,0);
    tracep->declBit(c+105,"memew", false,-1);
    tracep->declBit(c+106,"memer", false,-1);
    tracep->declBus(c+108,"func3", false,-1, 2,0);
    tracep->declBus(c+100,"imm", false,-1, 31,0);
    tracep->declBus(c+185,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+109,"muxsig", false,-1, 2,0);
    tracep->declBit(c+96,"valid_from_exu", false,-1);
    tracep->declBus(c+204,"memmask", false,-1, 2,0);
    tracep->declBit(c+118,"memsextsig", false,-1);
    tracep->declBus(c+197,"regwrite", false,-1, 31,0);
    tracep->declBus(c+206,"memread", false,-1, 31,0);
    tracep->declBus(c+149,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+201,"clk", false,-1);
    tracep->declBus(c+184,"addr", false,-1, 31,0);
    tracep->declBus(c+183,"write", false,-1, 31,0);
    tracep->declBit(c+106,"er", false,-1);
    tracep->declBit(c+105,"ew", false,-1);
    tracep->declBus(c+204,"memmask", false,-1, 2,0);
    tracep->declBit(c+118,"memsextsig", false,-1);
    tracep->declBus(c+206,"read", false,-1, 31,0);
    tracep->declBus(c+176,"readreg", false,-1, 31,0);
    tracep->declBus(c+176,"read_u", false,-1, 31,0);
    tracep->declBus(c+207,"read_s", false,-1, 31,0);
    tracep->declBus(c+177,"read_sb", false,-1, 31,0);
    tracep->declBus(c+178,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+225,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+211,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+179,"input_number", false,-1, 7,0);
    tracep->declBus(c+177,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+226,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+211,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+180,"input_number", false,-1, 15,0);
    tracep->declBus(c+178,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+227,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+197,"out", false,-1, 31,0);
    tracep->declBus(c+109,"key", false,-1, 2,0);
    tracep->declBus(c+212,"default_out", false,-1, 31,0);
    tracep->declArray(c+159,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+227,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+211,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+210,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+197,"out", false,-1, 31,0);
    tracep->declBus(c+109,"key", false,-1, 2,0);
    tracep->declBus(c+212,"default_out", false,-1, 31,0);
    tracep->declArray(c+159,"lut", false,-1, 139,0);
    tracep->declBus(c+228,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+164+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+172+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+199,"lut_out", false,-1, 31,0);
    tracep->declBit(c+200,"hit", false,-1);
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
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullBit(oldp+21,(vlSelf->top__DOT__ifu0__DOT__pc_valid));
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__ifu0__DOT__instbridge),32);
    bufp->fullBit(oldp+96,((0U != vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullCData(oldp+97,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+98,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+99,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                       >> 7U))),5);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+101,((0x100073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+102,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+103,((0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge)));
    bufp->fullBit(oldp+104,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                             | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                      | (3U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__instbridge))))))));
    bufp->fullBit(oldp+105,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+106,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+107,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+108,((7U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+109,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+110,((1U & (vlSelf->top__DOT__ifu0__DOT__instbridge 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+111,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+112,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+113,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+114,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullCData(oldp+115,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+116,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+117,(vlSelf->top__DOT__csrrs));
    bufp->fullBit(oldp+118,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+119,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+120,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+121,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+122,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+123,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+124,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+125,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+126,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+127,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+128,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__instbridge)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+129,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+130,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+131,((0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)),7);
    bufp->fullBit(oldp+132,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+133,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+134,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+136,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__instbridge)),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+140,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__instbridge)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__instbridge))))));
    bufp->fullBit(oldp+141,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__instbridge))));
    bufp->fullBit(oldp+142,((1U & (~ (IData)(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__state)))));
    bufp->fullBit(oldp+143,(vlSelf->top__DOT__ifu0__DOT__infetch0__DOT__state));
    bufp->fullSData(oldp+144,((vlSelf->top__DOT__ifu0__DOT__instbridge 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+145,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+146,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+147,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+148,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullIData(oldp+149,((0U != vlSelf->top__DOT__ifu0__DOT__instbridge)),32);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+150,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+153,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+155,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+159,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+164,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+166,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+168,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+170,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+175,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg),32);
    bufp->fullIData(oldp+177,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullIData(oldp+178,((((- (IData)((1U & (vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg))),32);
    bufp->fullCData(oldp+179,((0xffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),8);
    bufp->fullSData(oldp+180,((0xffffU & vlSelf->top__DOT__wbu0__DOT__mem0__DOT__readreg)),16);
    bufp->fullIData(oldp+181,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+182,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+183,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+184,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+185,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+186,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+188,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+189,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+190,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+193,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+194,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+195,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+196,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+197,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+198,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+199,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+200,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+201,(vlSelf->clk));
    bufp->fullBit(oldp+202,(vlSelf->rst));
    bufp->fullIData(oldp+203,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullCData(oldp+204,(vlSelf->top__DOT__memmask),3);
    bufp->fullIData(oldp+205,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+206,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+207,(vlSelf->top__DOT__wbu0__DOT__mem0__DOT__read_s),32);
    bufp->fullBit(oldp+208,(1U));
    bufp->fullIData(oldp+209,(2U),32);
    bufp->fullIData(oldp+210,(1U),32);
    bufp->fullIData(oldp+211,(0x20U),32);
    bufp->fullIData(oldp+212,(0U),32);
    bufp->fullIData(oldp+213,(0U),32);
    bufp->fullIData(oldp+214,(0x21U),32);
    bufp->fullIData(oldp+215,(2U),32);
    bufp->fullIData(oldp+216,(0x80000000U),32);
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
