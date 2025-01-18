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
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBit(c+108,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+233,"npc", false,-1, 31,0);
    tracep->declBus(c+31,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+109,"inst", false,-1, 31,0);
    tracep->declBit(c+110,"ifu_valid", false,-1);
    tracep->declBit(c+108,"ifu_arvalid", false,-1);
    tracep->declBit(c+111,"ifu_arready", false,-1);
    tracep->declBus(c+233,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+110,"ifu_rvalid", false,-1);
    tracep->declBit(c+108,"ifu_rready", false,-1);
    tracep->declBus(c+234,"ifu_rdata", false,-1, 31,0);
    tracep->declBus(c+112,"src1", false,-1, 4,0);
    tracep->declBus(c+113,"src2", false,-1, 4,0);
    tracep->declBus(c+114,"rd", false,-1, 4,0);
    tracep->declBus(c+115,"imm", false,-1, 31,0);
    tracep->declBit(c+116,"ebreaksig", false,-1);
    tracep->declBit(c+117,"mretsig", false,-1);
    tracep->declBit(c+118,"ecallsig", false,-1);
    tracep->declBit(c+119,"regew", false,-1);
    tracep->declBit(c+120,"memew", false,-1);
    tracep->declBit(c+121,"memer", false,-1);
    tracep->declBit(c+122,"muximm", false,-1);
    tracep->declBus(c+123,"func3", false,-1, 2,0);
    tracep->declBus(c+124,"muxsig", false,-1, 2,0);
    tracep->declBit(c+125,"func7", false,-1);
    tracep->declBit(c+126,"btypebranch", false,-1);
    tracep->declBit(c+127,"jalsig", false,-1);
    tracep->declBit(c+128,"jalrsig", false,-1);
    tracep->declBit(c+129,"auipcsig", false,-1);
    tracep->declBus(c+130,"aluop", false,-1, 1,0);
    tracep->declBit(c+131,"csrrw", false,-1);
    tracep->declBit(c+132,"csrrs", false,-1);
    tracep->declBit(c+110,"idu_valid", false,-1);
    tracep->declBus(c+133,"memmask", false,-1, 2,0);
    tracep->declBit(c+134,"memsextsig", false,-1);
    tracep->declBus(c+235,"regwrite", false,-1, 31,0);
    tracep->declBus(c+236,"regout1", false,-1, 31,0);
    tracep->declBus(c+237,"regout2", false,-1, 31,0);
    tracep->declBus(c+32,"mepc", false,-1, 31,0);
    tracep->declBus(c+33,"mtvec", false,-1, 31,0);
    tracep->declBit(c+108,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+238,"res", false,-1, 31,0);
    tracep->declBus(c+239,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+110,"exu_valid", false,-1);
    tracep->declBit(c+108,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+108,"memvalid", false,-1);
    tracep->declBus(c+135,"awvalid", false,-1, 1,0);
    tracep->declBus(c+135,"wvalid", false,-1, 1,0);
    tracep->declBus(c+136,"arvalid", false,-1, 1,0);
    tracep->declBus(c+136,"rready", false,-1, 1,0);
    tracep->declBus(c+135,"bready", false,-1, 1,0);
    tracep->declBus(c+137,"bvalid", false,-1, 1,0);
    tracep->declBus(c+138,"rvalid", false,-1, 1,0);
    tracep->declBus(c+139,"awready", false,-1, 1,0);
    tracep->declBus(c+139,"wready", false,-1, 1,0);
    tracep->declBus(c+139,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+240+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+242+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+244+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+246+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+140+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+142+i*1,"bresp", true,(i+0));
    }
    tracep->pushNamePrefix("data0 ");
    tracep->declBus(c+292,"NUM", false,-1, 31,0);
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBus(c+135,"awvalid", false,-1, 1,0);
    tracep->declBus(c+135,"wvalid", false,-1, 1,0);
    tracep->declBus(c+136,"arvalid", false,-1, 1,0);
    tracep->declBus(c+136,"rready", false,-1, 1,0);
    tracep->declBus(c+135,"bready", false,-1, 1,0);
    tracep->declBus(c+137,"bvalid", false,-1, 1,0);
    tracep->declBus(c+138,"rvalid", false,-1, 1,0);
    tracep->declBus(c+139,"awready", false,-1, 1,0);
    tracep->declBus(c+139,"wready", false,-1, 1,0);
    tracep->declBus(c+139,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+248+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+250+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+252+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+254+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+144+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+146+i*1,"bresp", true,(i+0));
    }
    tracep->declBus(c+293,"DEVICE", false,-1, 31,0);
    tracep->declBus(c+135,"awvalid_in", false,-1, 1,0);
    tracep->declBus(c+135,"wvalid_in", false,-1, 1,0);
    tracep->declBus(c+136,"arvalid_in", false,-1, 1,0);
    tracep->declBus(c+136,"rready_in", false,-1, 1,0);
    tracep->declBus(c+135,"bready_in", false,-1, 1,0);
    tracep->declBus(c+138,"rvalid_out", false,-1, 1,0);
    tracep->declBus(c+139,"awready_out", false,-1, 1,0);
    tracep->declBus(c+139,"wready_out", false,-1, 1,0);
    tracep->declBus(c+139,"arready_out", false,-1, 1,0);
    tracep->declBus(c+137,"bvalid_out", false,-1, 1,0);
    tracep->declBit(c+148,"awvalid_sram", false,-1);
    tracep->declBit(c+149,"wvalid_sram", false,-1);
    tracep->declBit(c+150,"arvalid_sram", false,-1);
    tracep->declBit(c+151,"rready_sram", false,-1);
    tracep->declBit(c+148,"bready_sram", false,-1);
    tracep->declBit(c+152,"rvalid_sram", false,-1);
    tracep->declBit(c+153,"awready_sram", false,-1);
    tracep->declBit(c+153,"wready_sram", false,-1);
    tracep->declBit(c+153,"arready_sram", false,-1);
    tracep->declBit(c+294,"bvalid_sram", false,-1);
    tracep->declBus(c+256,"awaddr_sram", false,-1, 31,0);
    tracep->declBus(c+257,"araddr_sram", false,-1, 31,0);
    tracep->declBus(c+258,"wdata_sram", false,-1, 31,0);
    tracep->declBus(c+259,"rdata_sram", false,-1, 31,0);
    tracep->declBus(c+154,"wstrb_sram", false,-1, 3,0);
    tracep->declBit(c+155,"bresp_sram", false,-1);
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+292,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBus(c+135,"awvalid", false,-1, 1,0);
    tracep->declBus(c+135,"wvalid", false,-1, 1,0);
    tracep->declBus(c+136,"arvalid", false,-1, 1,0);
    tracep->declBus(c+136,"rready", false,-1, 1,0);
    tracep->declBus(c+135,"bready", false,-1, 1,0);
    tracep->declBus(c+137,"bvalid", false,-1, 1,0);
    tracep->declBus(c+138,"rvalid", false,-1, 1,0);
    tracep->declBus(c+139,"awready", false,-1, 1,0);
    tracep->declBus(c+139,"wready", false,-1, 1,0);
    tracep->declBus(c+139,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+260+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+262+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+264+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+156+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+266+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+158+i*1,"bresp", true,(i+0));
    }
    tracep->declBit(c+148,"awvalid_out", false,-1);
    tracep->declBit(c+149,"wvalid_out", false,-1);
    tracep->declBit(c+150,"arvalid_out", false,-1);
    tracep->declBit(c+151,"rready_out", false,-1);
    tracep->declBit(c+148,"bready_out", false,-1);
    tracep->declBit(c+294,"bvalid_in", false,-1);
    tracep->declBit(c+152,"rvalid_in", false,-1);
    tracep->declBit(c+153,"awready_in", false,-1);
    tracep->declBit(c+153,"wready_in", false,-1);
    tracep->declBit(c+153,"arready_in", false,-1);
    tracep->declBus(c+257,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+256,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+258,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+154,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+259,"rdata_in", false,-1, 31,0);
    tracep->declBit(c+155,"bresp_in", false,-1);
    tracep->declBit(c+160,"busy", false,-1);
    tracep->declBus(c+161,"giant", false,-1, 1,0);
    tracep->declBus(c+162,"i", false,-1, 31,0);
    tracep->declBus(c+256,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+258,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+257,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+154,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+295,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+148,"awvalid", false,-1);
    tracep->declBit(c+153,"awready", false,-1);
    tracep->declBus(c+256,"awaddr", false,-1, 31,0);
    tracep->declBit(c+149,"wvalid", false,-1);
    tracep->declBit(c+153,"wready", false,-1);
    tracep->declBus(c+258,"wdata", false,-1, 31,0);
    tracep->declBus(c+154,"wstrb", false,-1, 3,0);
    tracep->declBit(c+294,"bvalid", false,-1);
    tracep->declBit(c+148,"bready", false,-1);
    tracep->declBit(c+155,"bresp", false,-1);
    tracep->declBit(c+150,"arvalid", false,-1);
    tracep->declBit(c+153,"arready", false,-1);
    tracep->declBus(c+257,"araddr", false,-1, 31,0);
    tracep->declBit(c+151,"rready", false,-1);
    tracep->declBit(c+152,"rvalid", false,-1);
    tracep->declBus(c+259,"rdata", false,-1, 31,0);
    tracep->declBus(c+163,"state", false,-1, 1,0);
    tracep->declBus(c+164,"random_delay", false,-1, 3,0);
    tracep->declBit(c+165,"busy", false,-1);
    tracep->declBus(c+166,"random_count", false,-1, 3,0);
    tracep->declBus(c+167,"memmask", false,-1, 2,0);
    tracep->declBus(c+259,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("lsfr0 ");
    tracep->declBus(c+296,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+297,"reset", false,-1);
    tracep->declBus(c+164,"out", false,-1, 3,0);
    tracep->declBus(c+168,"random_num", false,-1, 7,0);
    tracep->declBit(c+169,"feedback", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+296,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+298,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+167,"out", false,-1, 2,0);
    tracep->declBus(c+154,"key", false,-1, 3,0);
    tracep->declBus(c+299,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+296,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+298,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+293,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+167,"out", false,-1, 2,0);
    tracep->declBus(c+154,"key", false,-1, 3,0);
    tracep->declBus(c+300,"default_out", false,-1, 2,0);
    tracep->declBus(c+299,"lut", false,-1, 27,0);
    tracep->declBus(c+301,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+9+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+170,"lut_out", false,-1, 2,0);
    tracep->declBit(c+171,"hit", false,-1);
    tracep->declBus(c+302,"i", false,-1, 31,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+123,"func3", false,-1, 2,0);
    tracep->declBit(c+126,"btypebranch", false,-1);
    tracep->declBit(c+125,"func7", false,-1);
    tracep->declBus(c+130,"aluop", false,-1, 1,0);
    tracep->declBit(c+128,"jalrsig", false,-1);
    tracep->declBit(c+127,"jalsig", false,-1);
    tracep->declBus(c+115,"imm", false,-1, 31,0);
    tracep->declBit(c+122,"muximm", false,-1);
    tracep->declBus(c+236,"regout1", false,-1, 31,0);
    tracep->declBus(c+237,"regout2", false,-1, 31,0);
    tracep->declBus(c+31,"pc", false,-1, 31,0);
    tracep->declBit(c+129,"auipcsig", false,-1);
    tracep->declBit(c+117,"mretsig", false,-1);
    tracep->declBit(c+118,"ecallsig", false,-1);
    tracep->declBus(c+33,"mtvec", false,-1, 31,0);
    tracep->declBus(c+32,"mepc", false,-1, 31,0);
    tracep->declBit(c+110,"valid_from", false,-1);
    tracep->declBit(c+108,"ready_from", false,-1);
    tracep->declBus(c+238,"res", false,-1, 31,0);
    tracep->declBus(c+233,"npc", false,-1, 31,0);
    tracep->declBus(c+239,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+110,"valid_to", false,-1);
    tracep->declBit(c+108,"ready_to", false,-1);
    tracep->declBus(c+34,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+268,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+172,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+269,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+270,"zero", false,-1);
    tracep->declBit(c+271,"signal", false,-1);
    tracep->declBit(c+272,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+236,"A", false,-1, 31,0);
    tracep->declBus(c+269,"B", false,-1, 31,0);
    tracep->declBus(c+172,"op", false,-1, 4,0);
    tracep->declBus(c+238,"res", false,-1, 31,0);
    tracep->declBit(c+270,"zero", false,-1);
    tracep->declBit(c+271,"signal", false,-1);
    tracep->declBit(c+272,"carry", false,-1);
    tracep->declBit(c+173,"addsig", false,-1);
    tracep->declBit(c+174,"logsig", false,-1);
    tracep->declBit(c+175,"shfsig", false,-1);
    tracep->declBit(c+176,"sltsig", false,-1);
    tracep->declBit(c+272,"carry_tmp", false,-1);
    tracep->declBit(c+177,"type_I", false,-1);
    tracep->declBus(c+273,"logres", false,-1, 31,0);
    tracep->declBus(c+274,"addres", false,-1, 31,0);
    tracep->declBit(c+275,"addzero", false,-1);
    tracep->declBus(c+276,"shfres", false,-1, 31,0);
    tracep->declBus(c+277,"sltres", false,-1, 31,0);
    tracep->declBus(c+236,"A_s", false,-1, 31,0);
    tracep->declBus(c+269,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+123,"func3", false,-1, 2,0);
    tracep->declBit(c+125,"func7", false,-1);
    tracep->declBus(c+130,"aluop", false,-1, 1,0);
    tracep->declBit(c+128,"jalrsig", false,-1);
    tracep->declBus(c+172,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+177,"type_I", false,-1);
    tracep->declBit(c+178,"type_B", false,-1);
    tracep->declBit(c+179,"type_R", false,-1);
    tracep->declBit(c+180,"addsig", false,-1);
    tracep->declBus(c+181,"branchop", false,-1, 3,0);
    tracep->declBus(c+182,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+126,"btypebranch", false,-1);
    tracep->declBus(c+123,"func3", false,-1, 2,0);
    tracep->declBit(c+270,"zero", false,-1);
    tracep->declBit(c+271,"signal", false,-1);
    tracep->declBit(c+272,"carry", false,-1);
    tracep->declBus(c+238,"res", false,-1, 31,0);
    tracep->declBus(c+34,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+268,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+127,"jalsig", false,-1);
    tracep->declBit(c+128,"jalrsig", false,-1);
    tracep->declBit(c+129,"auipcsig", false,-1);
    tracep->declBit(c+117,"mretsig", false,-1);
    tracep->declBit(c+118,"ecallsig", false,-1);
    tracep->declBus(c+33,"mtvec", false,-1, 31,0);
    tracep->declBus(c+32,"mepc", false,-1, 31,0);
    tracep->declBus(c+233,"npc", false,-1, 31,0);
    tracep->declBus(c+239,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+292,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+303,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+304,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+269,"out", false,-1, 31,0);
    tracep->declBus(c+122,"key", false,-1, 0,0);
    tracep->declArray(c+207,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+292,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+303,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+304,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+293,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+269,"out", false,-1, 31,0);
    tracep->declBus(c+122,"key", false,-1, 0,0);
    tracep->declBus(c+305,"default_out", false,-1, 31,0);
    tracep->declArray(c+207,"lut", false,-1, 65,0);
    tracep->declBus(c+306,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+210+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+13+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+214+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+278,"lut_out", false,-1, 31,0);
    tracep->declBit(c+183,"hit", false,-1);
    tracep->declBus(c+307,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+31,"pc", false,-1, 31,0);
    tracep->declBus(c+34,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+31,"pc", false,-1, 31,0);
    tracep->declBus(c+115,"imm", false,-1, 31,0);
    tracep->declBus(c+268,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+109,"inst", false,-1, 31,0);
    tracep->declBit(c+110,"valid_from", false,-1);
    tracep->declBit(c+108,"ready_from", false,-1);
    tracep->declBit(c+116,"ebreaksig", false,-1);
    tracep->declBit(c+118,"ecallsig", false,-1);
    tracep->declBit(c+117,"mretsig", false,-1);
    tracep->declBus(c+115,"imm", false,-1, 31,0);
    tracep->declBus(c+123,"func3", false,-1, 2,0);
    tracep->declBit(c+125,"func7", false,-1);
    tracep->declBus(c+112,"src1", false,-1, 4,0);
    tracep->declBus(c+113,"src2", false,-1, 4,0);
    tracep->declBus(c+114,"rd", false,-1, 4,0);
    tracep->declBit(c+120,"memew", false,-1);
    tracep->declBus(c+124,"muxsig", false,-1, 2,0);
    tracep->declBit(c+121,"memer", false,-1);
    tracep->declBit(c+119,"regew", false,-1);
    tracep->declBit(c+122,"muximm", false,-1);
    tracep->declBit(c+126,"btypebranch", false,-1);
    tracep->declBit(c+128,"jalrsig", false,-1);
    tracep->declBit(c+127,"jalsig", false,-1);
    tracep->declBus(c+130,"aluop", false,-1, 1,0);
    tracep->declBit(c+129,"auipcsig", false,-1);
    tracep->declBit(c+131,"csrrw", false,-1);
    tracep->declBit(c+132,"csrrs", false,-1);
    tracep->declBit(c+110,"valid_to", false,-1);
    tracep->declBit(c+108,"ready_to", false,-1);
    tracep->declBus(c+133,"memmask", false,-1, 2,0);
    tracep->declBit(c+134,"memsextsig", false,-1);
    tracep->declBit(c+116,"ebreak", false,-1);
    tracep->declBit(c+118,"ecall", false,-1);
    tracep->declBit(c+117,"mret", false,-1);
    tracep->declBus(c+123,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+125,"func7bridge", false,-1);
    tracep->declBus(c+184,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+109,"inst", false,-1, 31,0);
    tracep->declBit(c+116,"ebreaksig", false,-1);
    tracep->declBit(c+118,"ecallsig", false,-1);
    tracep->declBit(c+117,"mretsig", false,-1);
    tracep->declBus(c+115,"imm", false,-1, 31,0);
    tracep->declBus(c+184,"opcode", false,-1, 6,0);
    tracep->declBus(c+123,"func3", false,-1, 2,0);
    tracep->declBit(c+125,"func7", false,-1);
    tracep->declBus(c+112,"src1", false,-1, 4,0);
    tracep->declBus(c+113,"src2", false,-1, 4,0);
    tracep->declBus(c+114,"rd", false,-1, 4,0);
    tracep->declBus(c+133,"memmask", false,-1, 2,0);
    tracep->declBit(c+134,"memsextsig", false,-1);
    tracep->declBit(c+185,"type_I", false,-1);
    tracep->declBit(c+186,"type_R", false,-1);
    tracep->declBit(c+187,"type_U", false,-1);
    tracep->declBit(c+120,"type_S", false,-1);
    tracep->declBit(c+127,"type_J", false,-1);
    tracep->declBit(c+126,"type_B", false,-1);
    tracep->declBus(c+188,"I_imm", false,-1, 31,0);
    tracep->declBus(c+189,"U_imm", false,-1, 31,0);
    tracep->declBus(c+190,"S_imm", false,-1, 31,0);
    tracep->declBus(c+191,"J_imm", false,-1, 31,0);
    tracep->declBus(c+192,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+184,"opcode", false,-1, 6,0);
    tracep->declBus(c+123,"func3", false,-1, 2,0);
    tracep->declBit(c+125,"func7", false,-1);
    tracep->declBit(c+116,"ebreaksig", false,-1);
    tracep->declBit(c+118,"ecallsig", false,-1);
    tracep->declBit(c+117,"mretsig", false,-1);
    tracep->declBit(c+120,"memew", false,-1);
    tracep->declBus(c+124,"muxsig", false,-1, 2,0);
    tracep->declBit(c+121,"memer", false,-1);
    tracep->declBit(c+119,"regew", false,-1);
    tracep->declBit(c+122,"muximm", false,-1);
    tracep->declBit(c+126,"btypebranch", false,-1);
    tracep->declBit(c+128,"jalrsig", false,-1);
    tracep->declBit(c+127,"jalsig", false,-1);
    tracep->declBus(c+130,"aluop", false,-1, 1,0);
    tracep->declBit(c+129,"auipcsig", false,-1);
    tracep->declBit(c+131,"csrrw", false,-1);
    tracep->declBit(c+132,"csrrs", false,-1);
    tracep->declBit(c+185,"type_I", false,-1);
    tracep->declBit(c+186,"type_R", false,-1);
    tracep->declBit(c+187,"type_U", false,-1);
    tracep->declBit(c+120,"type_S", false,-1);
    tracep->declBit(c+127,"type_J", false,-1);
    tracep->declBit(c+126,"type_B", false,-1);
    tracep->declBit(c+121,"load", false,-1);
    tracep->declBit(c+120,"store", false,-1);
    tracep->declBit(c+193,"regwritepc", false,-1);
    tracep->declBit(c+121,"regwritemem", false,-1);
    tracep->declBit(c+194,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBus(c+233,"npc", false,-1, 31,0);
    tracep->declBit(c+108,"ready", false,-1);
    tracep->declBus(c+31,"pc", false,-1, 31,0);
    tracep->declBus(c+109,"inst", false,-1, 31,0);
    tracep->declBit(c+110,"valid", false,-1);
    tracep->declBit(c+108,"arvalid", false,-1);
    tracep->declBit(c+111,"arready", false,-1);
    tracep->declBus(c+233,"araddr", false,-1, 31,0);
    tracep->declBit(c+110,"rvalid", false,-1);
    tracep->declBit(c+108,"rready", false,-1);
    tracep->declBus(c+234,"rdata", false,-1, 31,0);
    tracep->declBus(c+31,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+110,"infetch_ready", false,-1);
    tracep->declBus(c+109,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBus(c+233,"npc", false,-1, 31,0);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBit(c+110,"ready_from", false,-1);
    tracep->declBus(c+31,"pcout", false,-1, 31,0);
    tracep->declBus(c+308,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBit(c+195,"ew", false,-1);
    tracep->declBus(c+114,"addr", false,-1, 4,0);
    tracep->declBus(c+112,"src1", false,-1, 4,0);
    tracep->declBus(c+113,"src2", false,-1, 4,0);
    tracep->declBus(c+196,"csr", false,-1, 11,0);
    tracep->declBus(c+235,"data", false,-1, 31,0);
    tracep->declBit(c+131,"csrrw", false,-1);
    tracep->declBit(c+132,"csrrs", false,-1);
    tracep->declBit(c+118,"ecallsig", false,-1);
    tracep->declBit(c+110,"valid", false,-1);
    tracep->declBus(c+236,"regout1", false,-1, 31,0);
    tracep->declBus(c+237,"regout2", false,-1, 31,0);
    tracep->declBus(c+32,"mepc", false,-1, 31,0);
    tracep->declBus(c+33,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+35+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+67+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+197,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+279,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+309,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+197,"out", false,-1, 1,0);
    tracep->declBus(c+196,"key", false,-1, 11,0);
    tracep->declQuad(c+310,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+309,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+293,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+197,"out", false,-1, 1,0);
    tracep->declBus(c+196,"key", false,-1, 11,0);
    tracep->declBus(c+312,"default_out", false,-1, 1,0);
    tracep->declQuad(c+310,"lut", false,-1, 55,0);
    tracep->declBus(c+313,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+19+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+23+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+198,"lut_out", false,-1, 1,0);
    tracep->declBit(c+199,"hit", false,-1);
    tracep->declBus(c+302,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBit(c+200,"ew", false,-1);
    tracep->declBit(c+131,"csrrw", false,-1);
    tracep->declBit(c+132,"csrrs", false,-1);
    tracep->declBit(c+118,"ecall", false,-1);
    tracep->declBus(c+197,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+114,"addr", false,-1, 4,0);
    tracep->declBus(c+279,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+71+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+103+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+107,"i", false,-1, 31,0);
    tracep->declBus(c+314,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBus(c+238,"res", false,-1, 31,0);
    tracep->declBus(c+237,"regout2", false,-1, 31,0);
    tracep->declBit(c+120,"memew", false,-1);
    tracep->declBit(c+121,"memer", false,-1);
    tracep->declBus(c+115,"imm", false,-1, 31,0);
    tracep->declBus(c+239,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+124,"muxsig", false,-1, 2,0);
    tracep->declBit(c+110,"valid_from", false,-1);
    tracep->declBus(c+133,"memmask", false,-1, 2,0);
    tracep->declBit(c+134,"memsextsig", false,-1);
    tracep->declBus(c+235,"regwrite", false,-1, 31,0);
    tracep->declBit(c+108,"ready_to", false,-1);
    tracep->declBit(c+108,"memvalid", false,-1);
    tracep->declBit(c+120,"awvalid", false,-1);
    tracep->declBit(c+201,"awready", false,-1);
    tracep->declBus(c+238,"awaddr", false,-1, 31,0);
    tracep->declBit(c+120,"wvalid", false,-1);
    tracep->declBit(c+201,"wready", false,-1);
    tracep->declBus(c+237,"wdata", false,-1, 31,0);
    tracep->declBus(c+202,"wstrb", false,-1, 3,0);
    tracep->declBit(c+203,"bvalid", false,-1);
    tracep->declBit(c+120,"bready", false,-1);
    tracep->declBit(c+204,"bresp", false,-1);
    tracep->declBit(c+121,"arvalid", false,-1);
    tracep->declBit(c+201,"arready", false,-1);
    tracep->declBus(c+238,"araddr", false,-1, 31,0);
    tracep->declBit(c+205,"rvalid", false,-1);
    tracep->declBit(c+121,"rready", false,-1);
    tracep->declBus(c+280,"rdata", false,-1, 31,0);
    tracep->declBus(c+281,"memread", false,-1, 31,0);
    tracep->declBit(c+201,"ready", false,-1);
    tracep->declBus(c+206,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+280,"data", false,-1, 31,0);
    tracep->declBus(c+133,"memmask", false,-1, 2,0);
    tracep->declBit(c+134,"memsextsig", false,-1);
    tracep->declBus(c+281,"read", false,-1, 31,0);
    tracep->declBus(c+282,"read_u", false,-1, 31,0);
    tracep->declBus(c+283,"read_s", false,-1, 31,0);
    tracep->declBus(c+284,"read_sb", false,-1, 31,0);
    tracep->declBus(c+285,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+315,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+304,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+286,"input_number", false,-1, 7,0);
    tracep->declBus(c+284,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+316,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+304,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+287,"input_number", false,-1, 15,0);
    tracep->declBus(c+285,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+298,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+304,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+235,"out", false,-1, 31,0);
    tracep->declBus(c+124,"key", false,-1, 2,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+216,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+298,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+304,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+303,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+235,"out", false,-1, 31,0);
    tracep->declBus(c+124,"key", false,-1, 2,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+216,"lut", false,-1, 139,0);
    tracep->declBus(c+317,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+221+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+27+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+229+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+288,"lut_out", false,-1, 31,0);
    tracep->declBit(c+289,"hit", false,-1);
    tracep->declBus(c+302,"i", false,-1, 31,0);
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
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+14,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullSData(oldp+15,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+16,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+17,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+18,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+19,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+20,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+21,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+22,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+23,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+24,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+25,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+26,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+27,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+28,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+29,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+30,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullIData(oldp+34,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+108,(vlSelf->top__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+110,((1U & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
    bufp->fullBit(oldp+111,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                             & ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))));
    bufp->fullCData(oldp+112,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+113,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+114,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+116,((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+117,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+118,((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+119,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                             | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                      | (3U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__inst_reg))))))));
    bufp->fullBit(oldp+120,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+121,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+122,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+123,((7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+124,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+125,((1U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+126,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+127,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+128,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+129,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+130,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+131,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+132,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+133,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+134,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+135,(((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+136,(vlSelf->top__DOT__data0__DOT__arvalid_in),2);
    bufp->fullCData(oldp+137,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram))))),2);
    bufp->fullCData(oldp+138,(vlSelf->top__DOT__data0__DOT__rvalid_out),2);
    bufp->fullCData(oldp+139,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                               & (- (IData)(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                             & (0U 
                                                == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))))),2);
    bufp->fullCData(oldp+140,(vlSelf->top__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+141,(vlSelf->top__DOT__wstrb[1]),4);
    bufp->fullBit(oldp+142,(vlSelf->top__DOT__bresp[0]));
    bufp->fullBit(oldp+143,(vlSelf->top__DOT__bresp[1]));
    bufp->fullCData(oldp+144,(vlSelf->top__DOT____Vcellinp__data0__wstrb[0]),4);
    bufp->fullCData(oldp+145,(vlSelf->top__DOT____Vcellinp__data0__wstrb[1]),4);
    bufp->fullBit(oldp+146,(vlSelf->top__DOT____Vcellout__data0__bresp[0]));
    bufp->fullBit(oldp+147,(vlSelf->top__DOT____Vcellout__data0__bresp[1]));
    bufp->fullBit(oldp+148,(vlSelf->top__DOT__data0__DOT__awvalid_sram));
    bufp->fullBit(oldp+149,(vlSelf->top__DOT__data0__DOT__wvalid_sram));
    bufp->fullBit(oldp+150,(vlSelf->top__DOT__data0__DOT__arvalid_sram));
    bufp->fullBit(oldp+151,((0U != ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (IData)(vlSelf->top__DOT__data0__DOT__arvalid_in)))));
    bufp->fullBit(oldp+152,((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullBit(oldp+153,(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                             & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
    bufp->fullCData(oldp+154,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullBit(oldp+155,((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullCData(oldp+156,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+157,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullBit(oldp+158,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0]));
    bufp->fullBit(oldp+159,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[1]));
    bufp->fullBit(oldp+160,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+161,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__i),32);
    bufp->fullCData(oldp+163,(vlSelf->top__DOT__data0__DOT__mem0__DOT__state),2);
    bufp->fullCData(oldp+164,((0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))),4);
    bufp->fullBit(oldp+165,(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy));
    bufp->fullCData(oldp+166,(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count),4);
    bufp->fullCData(oldp+167,(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask),3);
    bufp->fullCData(oldp+168,(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num),8);
    bufp->fullBit(oldp+169,((1U & VL_REDXOR_8((0xb8U 
                                               & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))))));
    bufp->fullCData(oldp+170,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+171,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+172,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+173,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+174,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+175,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+176,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+177,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+178,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+179,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+180,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+181,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+182,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+183,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+184,((0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+185,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+186,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+187,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+189,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+190,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+191,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+192,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+193,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+194,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+195,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                             & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                         | (3U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)))))))));
    bufp->fullSData(oldp+196,((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+197,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+198,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+199,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+200,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullBit(oldp+201,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (- (IData)(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                                  & (0U 
                                                     == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))))) 
                                   >> 1U))));
    bufp->fullCData(oldp+202,(((1U == (IData)(vlSelf->top__DOT__memmask))
                                ? 1U : ((2U == (IData)(vlSelf->top__DOT__memmask))
                                         ? 2U : ((3U 
                                                  == (IData)(vlSelf->top__DOT__memmask))
                                                  ? 4U
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->top__DOT__memmask))
                                                   ? 8U
                                                   : 0U))))),4);
    bufp->fullBit(oldp+203,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram)))) 
                                   >> 1U))));
    bufp->fullBit(oldp+204,(vlSelf->top__DOT__bresp
                            [1U]));
    bufp->fullBit(oldp+205,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U))));
    bufp->fullIData(oldp+206,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                     & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                         & (- (IData)(
                                                      ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                                       & (0U 
                                                          == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))))) 
                                        >> 1U)))),32);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+207,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+210,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+212,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+214,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+215,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+216,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+221,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+223,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+225,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+227,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+229,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+230,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+231,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+232,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+233,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+234,(vlSelf->top__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+235,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+236,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+237,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+238,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+239,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+240,(vlSelf->top__DOT__araddr[0]),32);
    bufp->fullIData(oldp+241,(vlSelf->top__DOT__araddr[1]),32);
    bufp->fullIData(oldp+242,(vlSelf->top__DOT__rdata[0]),32);
    bufp->fullIData(oldp+243,(vlSelf->top__DOT__rdata[1]),32);
    bufp->fullIData(oldp+244,(vlSelf->top__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+245,(vlSelf->top__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+246,(vlSelf->top__DOT__wdata[0]),32);
    bufp->fullIData(oldp+247,(vlSelf->top__DOT__wdata[1]),32);
    bufp->fullIData(oldp+248,(vlSelf->top__DOT____Vcellinp__data0__araddr[0]),32);
    bufp->fullIData(oldp+249,(vlSelf->top__DOT____Vcellinp__data0__araddr[1]),32);
    bufp->fullIData(oldp+250,(vlSelf->top__DOT____Vcellout__data0__rdata[0]),32);
    bufp->fullIData(oldp+251,(vlSelf->top__DOT____Vcellout__data0__rdata[1]),32);
    bufp->fullIData(oldp+252,(vlSelf->top__DOT____Vcellinp__data0__awaddr[0]),32);
    bufp->fullIData(oldp+253,(vlSelf->top__DOT____Vcellinp__data0__awaddr[1]),32);
    bufp->fullIData(oldp+254,(vlSelf->top__DOT____Vcellinp__data0__wdata[0]),32);
    bufp->fullIData(oldp+255,(vlSelf->top__DOT____Vcellinp__data0__wdata[1]),32);
    bufp->fullIData(oldp+256,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullIData(oldp+257,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+258,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullIData(oldp+259,(vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg),32);
    bufp->fullIData(oldp+260,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+261,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+262,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+263,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+264,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+265,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullIData(oldp+266,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+267,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullIData(oldp+268,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+269,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+270,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+271,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+272,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+273,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+274,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+275,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+276,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+277,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+278,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+279,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+280,(vlSelf->top__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+281,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+282,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+283,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+284,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__rdata
                                          [1U]))),32);
    bufp->fullIData(oldp+285,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__rdata
                                             [1U]))),32);
    bufp->fullCData(oldp+286,((0xffU & vlSelf->top__DOT__rdata
                               [1U])),8);
    bufp->fullSData(oldp+287,((0xffffU & vlSelf->top__DOT__rdata
                               [1U])),16);
    bufp->fullIData(oldp+288,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+289,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+290,(vlSelf->clk));
    bufp->fullBit(oldp+291,(vlSelf->rst));
    bufp->fullIData(oldp+292,(2U),32);
    bufp->fullIData(oldp+293,(0U),32);
    bufp->fullBit(oldp+294,(vlSelf->top__DOT__data0__DOT__bvalid_sram));
    bufp->fullIData(oldp+295,(2U),32);
    bufp->fullIData(oldp+296,(4U),32);
    bufp->fullBit(oldp+297,(0U));
    bufp->fullIData(oldp+298,(3U),32);
    bufp->fullIData(oldp+299,(0x12491c4U),28);
    bufp->fullCData(oldp+300,(0U),3);
    bufp->fullIData(oldp+301,(7U),32);
    bufp->fullIData(oldp+302,(4U),32);
    bufp->fullIData(oldp+303,(1U),32);
    bufp->fullIData(oldp+304,(0x20U),32);
    bufp->fullIData(oldp+305,(0U),32);
    bufp->fullIData(oldp+306,(0x21U),32);
    bufp->fullIData(oldp+307,(2U),32);
    bufp->fullIData(oldp+308,(0x7ffffffcU),32);
    bufp->fullIData(oldp+309,(0xcU),32);
    bufp->fullQData(oldp+310,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+312,(0U),2);
    bufp->fullIData(oldp+313,(0xeU),32);
    bufp->fullIData(oldp+314,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+315,(8U),32);
    bufp->fullIData(oldp+316,(0x10U),32);
    bufp->fullIData(oldp+317,(0x23U),32);
}
