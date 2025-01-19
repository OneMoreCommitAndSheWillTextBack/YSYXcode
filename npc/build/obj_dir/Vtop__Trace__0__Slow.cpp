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
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBit(c+292,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBit(c+292,"rst", false,-1);
    tracep->declBit(c+283,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+226,"npc", false,-1, 31,0);
    tracep->declBus(c+34,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+111,"inst", false,-1, 31,0);
    tracep->declBit(c+112,"ifu_valid", false,-1);
    tracep->declBit(c+283,"ifu_arvalid", false,-1);
    tracep->declBit(c+113,"ifu_arready", false,-1);
    tracep->declBus(c+226,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+114,"ifu_rvalid", false,-1);
    tracep->declBit(c+283,"ifu_rready", false,-1);
    tracep->declBus(c+227,"ifu_rdata", false,-1, 31,0);
    tracep->declBus(c+115,"src1", false,-1, 4,0);
    tracep->declBus(c+116,"src2", false,-1, 4,0);
    tracep->declBus(c+117,"rd", false,-1, 4,0);
    tracep->declBus(c+118,"imm", false,-1, 31,0);
    tracep->declBit(c+119,"ebreaksig", false,-1);
    tracep->declBit(c+120,"mretsig", false,-1);
    tracep->declBit(c+121,"ecallsig", false,-1);
    tracep->declBit(c+122,"regew", false,-1);
    tracep->declBit(c+123,"memew", false,-1);
    tracep->declBit(c+124,"memer", false,-1);
    tracep->declBit(c+125,"muximm", false,-1);
    tracep->declBus(c+126,"func3", false,-1, 2,0);
    tracep->declBus(c+127,"muxsig", false,-1, 2,0);
    tracep->declBit(c+128,"func7", false,-1);
    tracep->declBit(c+129,"btypebranch", false,-1);
    tracep->declBit(c+130,"jalsig", false,-1);
    tracep->declBit(c+131,"jalrsig", false,-1);
    tracep->declBit(c+132,"auipcsig", false,-1);
    tracep->declBus(c+133,"aluop", false,-1, 1,0);
    tracep->declBit(c+134,"csrrw", false,-1);
    tracep->declBit(c+135,"csrrs", false,-1);
    tracep->declBit(c+112,"idu_valid", false,-1);
    tracep->declBus(c+136,"memmask", false,-1, 2,0);
    tracep->declBit(c+137,"memsextsig", false,-1);
    tracep->declBus(c+228,"regwrite", false,-1, 31,0);
    tracep->declBus(c+229,"regout1", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBus(c+35,"mepc", false,-1, 31,0);
    tracep->declBus(c+36,"mtvec", false,-1, 31,0);
    tracep->declBit(c+283,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+112,"exu_valid", false,-1);
    tracep->declBit(c+283,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+283,"memvalid", false,-1);
    tracep->declBus(c+284,"awvalid", false,-1, 1,0);
    tracep->declBus(c+284,"wvalid", false,-1, 1,0);
    tracep->declBus(c+285,"arvalid", false,-1, 1,0);
    tracep->declBus(c+285,"rready", false,-1, 1,0);
    tracep->declBus(c+138,"bready", false,-1, 1,0);
    tracep->declBus(c+139,"bvalid", false,-1, 1,0);
    tracep->declBus(c+140,"rvalid", false,-1, 1,0);
    tracep->declBus(c+141,"awready", false,-1, 1,0);
    tracep->declBus(c+141,"wready", false,-1, 1,0);
    tracep->declBus(c+141,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+233+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+235+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+237+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+239+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+142+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+144+i*1,"bresp", true,(i+0));
    }
    tracep->pushNamePrefix("data0 ");
    tracep->declBus(c+296,"NUM", false,-1, 31,0);
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBus(c+284,"awvalid", false,-1, 1,0);
    tracep->declBus(c+284,"wvalid", false,-1, 1,0);
    tracep->declBus(c+285,"arvalid", false,-1, 1,0);
    tracep->declBus(c+285,"rready", false,-1, 1,0);
    tracep->declBus(c+138,"bready", false,-1, 1,0);
    tracep->declBus(c+139,"bvalid", false,-1, 1,0);
    tracep->declBus(c+140,"rvalid", false,-1, 1,0);
    tracep->declBus(c+141,"awready", false,-1, 1,0);
    tracep->declBus(c+141,"wready", false,-1, 1,0);
    tracep->declBus(c+141,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+241+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+243+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+245+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+247+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+146+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+148+i*1,"bresp", true,(i+0));
    }
    tracep->declBus(c+297,"DEVICE", false,-1, 31,0);
    tracep->declBus(c+284,"awvalid_in", false,-1, 1,0);
    tracep->declBus(c+284,"wvalid_in", false,-1, 1,0);
    tracep->declBus(c+285,"arvalid_in", false,-1, 1,0);
    tracep->declBus(c+285,"rready_in", false,-1, 1,0);
    tracep->declBus(c+138,"bready_in", false,-1, 1,0);
    tracep->declBus(c+140,"rvalid_out", false,-1, 1,0);
    tracep->declBus(c+141,"awready_out", false,-1, 1,0);
    tracep->declBus(c+141,"wready_out", false,-1, 1,0);
    tracep->declBus(c+141,"arready_out", false,-1, 1,0);
    tracep->declBus(c+139,"bvalid_out", false,-1, 1,0);
    tracep->declBit(c+286,"awvalid_sram", false,-1);
    tracep->declBit(c+287,"wvalid_sram", false,-1);
    tracep->declBit(c+288,"arvalid_sram", false,-1);
    tracep->declBit(c+293,"rready_sram", false,-1);
    tracep->declBit(c+150,"bready_sram", false,-1);
    tracep->declBit(c+151,"rvalid_sram", false,-1);
    tracep->declBit(c+152,"awready_sram", false,-1);
    tracep->declBit(c+152,"wready_sram", false,-1);
    tracep->declBit(c+152,"arready_sram", false,-1);
    tracep->declBit(c+298,"bvalid_sram", false,-1);
    tracep->declBus(c+249,"awaddr_sram", false,-1, 31,0);
    tracep->declBus(c+250,"araddr_sram", false,-1, 31,0);
    tracep->declBus(c+251,"wdata_sram", false,-1, 31,0);
    tracep->declBus(c+252,"rdata_sram", false,-1, 31,0);
    tracep->declBus(c+153,"wstrb_sram", false,-1, 3,0);
    tracep->declBit(c+154,"bresp_sram", false,-1);
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+296,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBus(c+284,"awvalid", false,-1, 1,0);
    tracep->declBus(c+284,"wvalid", false,-1, 1,0);
    tracep->declBus(c+285,"arvalid", false,-1, 1,0);
    tracep->declBus(c+285,"rready", false,-1, 1,0);
    tracep->declBus(c+138,"bready", false,-1, 1,0);
    tracep->declBus(c+139,"bvalid", false,-1, 1,0);
    tracep->declBus(c+140,"rvalid", false,-1, 1,0);
    tracep->declBus(c+141,"awready", false,-1, 1,0);
    tracep->declBus(c+141,"wready", false,-1, 1,0);
    tracep->declBus(c+141,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+253+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+255+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+257+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+155+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+259+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+157+i*1,"bresp", true,(i+0));
    }
    tracep->declBit(c+286,"awvalid_out", false,-1);
    tracep->declBit(c+287,"wvalid_out", false,-1);
    tracep->declBit(c+288,"arvalid_out", false,-1);
    tracep->declBit(c+293,"rready_out", false,-1);
    tracep->declBit(c+150,"bready_out", false,-1);
    tracep->declBit(c+298,"bvalid_in", false,-1);
    tracep->declBit(c+151,"rvalid_in", false,-1);
    tracep->declBit(c+152,"awready_in", false,-1);
    tracep->declBit(c+152,"wready_in", false,-1);
    tracep->declBit(c+152,"arready_in", false,-1);
    tracep->declBus(c+250,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+249,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+251,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+153,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+252,"rdata_in", false,-1, 31,0);
    tracep->declBit(c+154,"bresp_in", false,-1);
    tracep->declBit(c+159,"busy", false,-1);
    tracep->declBus(c+160,"giant", false,-1, 1,0);
    tracep->declBus(c+161,"i", false,-1, 31,0);
    tracep->declBus(c+249,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+251,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+250,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+153,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+299,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBit(c+286,"awvalid", false,-1);
    tracep->declBit(c+152,"awready", false,-1);
    tracep->declBus(c+249,"awaddr", false,-1, 31,0);
    tracep->declBit(c+287,"wvalid", false,-1);
    tracep->declBit(c+152,"wready", false,-1);
    tracep->declBus(c+251,"wdata", false,-1, 31,0);
    tracep->declBus(c+153,"wstrb", false,-1, 3,0);
    tracep->declBit(c+298,"bvalid", false,-1);
    tracep->declBit(c+150,"bready", false,-1);
    tracep->declBit(c+154,"bresp", false,-1);
    tracep->declBit(c+288,"arvalid", false,-1);
    tracep->declBit(c+152,"arready", false,-1);
    tracep->declBus(c+250,"araddr", false,-1, 31,0);
    tracep->declBit(c+293,"rready", false,-1);
    tracep->declBit(c+151,"rvalid", false,-1);
    tracep->declBus(c+252,"rdata", false,-1, 31,0);
    tracep->declBus(c+162,"state", false,-1, 1,0);
    tracep->declBus(c+31,"random_delay", false,-1, 3,0);
    tracep->declBit(c+163,"busy", false,-1);
    tracep->declBus(c+164,"random_count", false,-1, 3,0);
    tracep->declBus(c+165,"memmask", false,-1, 2,0);
    tracep->declBus(c+252,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("lsfr0 ");
    tracep->declBus(c+300,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBit(c+301,"reset", false,-1);
    tracep->declBus(c+31,"out", false,-1, 3,0);
    tracep->declBus(c+32,"random_num", false,-1, 7,0);
    tracep->declBit(c+33,"feedback", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+300,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+300,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+302,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+165,"out", false,-1, 2,0);
    tracep->declBus(c+153,"key", false,-1, 3,0);
    tracep->declBus(c+303,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+300,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+300,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+302,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+297,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+165,"out", false,-1, 2,0);
    tracep->declBus(c+153,"key", false,-1, 3,0);
    tracep->declBus(c+304,"default_out", false,-1, 2,0);
    tracep->declBus(c+303,"lut", false,-1, 27,0);
    tracep->declBus(c+305,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+9+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+166,"lut_out", false,-1, 2,0);
    tracep->declBit(c+167,"hit", false,-1);
    tracep->declBus(c+306,"i", false,-1, 31,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+126,"func3", false,-1, 2,0);
    tracep->declBit(c+129,"btypebranch", false,-1);
    tracep->declBit(c+128,"func7", false,-1);
    tracep->declBus(c+133,"aluop", false,-1, 1,0);
    tracep->declBit(c+131,"jalrsig", false,-1);
    tracep->declBit(c+130,"jalsig", false,-1);
    tracep->declBus(c+118,"imm", false,-1, 31,0);
    tracep->declBit(c+125,"muximm", false,-1);
    tracep->declBus(c+229,"regout1", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBus(c+34,"pc", false,-1, 31,0);
    tracep->declBit(c+132,"auipcsig", false,-1);
    tracep->declBit(c+120,"mretsig", false,-1);
    tracep->declBit(c+121,"ecallsig", false,-1);
    tracep->declBus(c+36,"mtvec", false,-1, 31,0);
    tracep->declBus(c+35,"mepc", false,-1, 31,0);
    tracep->declBit(c+112,"valid_from", false,-1);
    tracep->declBit(c+283,"ready_from", false,-1);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+226,"npc", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+112,"valid_to", false,-1);
    tracep->declBit(c+283,"ready_to", false,-1);
    tracep->declBus(c+37,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+261,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+168,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+262,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+263,"zero", false,-1);
    tracep->declBit(c+264,"signal", false,-1);
    tracep->declBit(c+265,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+229,"A", false,-1, 31,0);
    tracep->declBus(c+262,"B", false,-1, 31,0);
    tracep->declBus(c+168,"op", false,-1, 4,0);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBit(c+263,"zero", false,-1);
    tracep->declBit(c+264,"signal", false,-1);
    tracep->declBit(c+265,"carry", false,-1);
    tracep->declBit(c+169,"addsig", false,-1);
    tracep->declBit(c+170,"logsig", false,-1);
    tracep->declBit(c+171,"shfsig", false,-1);
    tracep->declBit(c+172,"sltsig", false,-1);
    tracep->declBit(c+265,"carry_tmp", false,-1);
    tracep->declBit(c+173,"type_I", false,-1);
    tracep->declBus(c+266,"logres", false,-1, 31,0);
    tracep->declBus(c+267,"addres", false,-1, 31,0);
    tracep->declBit(c+268,"addzero", false,-1);
    tracep->declBus(c+269,"shfres", false,-1, 31,0);
    tracep->declBus(c+270,"sltres", false,-1, 31,0);
    tracep->declBus(c+229,"A_s", false,-1, 31,0);
    tracep->declBus(c+262,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+126,"func3", false,-1, 2,0);
    tracep->declBit(c+128,"func7", false,-1);
    tracep->declBus(c+133,"aluop", false,-1, 1,0);
    tracep->declBit(c+131,"jalrsig", false,-1);
    tracep->declBus(c+168,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+173,"type_I", false,-1);
    tracep->declBit(c+174,"type_B", false,-1);
    tracep->declBit(c+175,"type_R", false,-1);
    tracep->declBit(c+176,"addsig", false,-1);
    tracep->declBus(c+177,"branchop", false,-1, 3,0);
    tracep->declBus(c+178,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+129,"btypebranch", false,-1);
    tracep->declBus(c+126,"func3", false,-1, 2,0);
    tracep->declBit(c+263,"zero", false,-1);
    tracep->declBit(c+264,"signal", false,-1);
    tracep->declBit(c+265,"carry", false,-1);
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+37,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+261,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+130,"jalsig", false,-1);
    tracep->declBit(c+131,"jalrsig", false,-1);
    tracep->declBit(c+132,"auipcsig", false,-1);
    tracep->declBit(c+120,"mretsig", false,-1);
    tracep->declBit(c+121,"ecallsig", false,-1);
    tracep->declBus(c+36,"mtvec", false,-1, 31,0);
    tracep->declBus(c+35,"mepc", false,-1, 31,0);
    tracep->declBus(c+226,"npc", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+307,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+308,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+262,"out", false,-1, 31,0);
    tracep->declBus(c+125,"key", false,-1, 0,0);
    tracep->declArray(c+200,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+307,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+308,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+297,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+262,"out", false,-1, 31,0);
    tracep->declBus(c+125,"key", false,-1, 0,0);
    tracep->declBus(c+309,"default_out", false,-1, 31,0);
    tracep->declArray(c+200,"lut", false,-1, 65,0);
    tracep->declBus(c+310,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+203+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+13+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+207+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+271,"lut_out", false,-1, 31,0);
    tracep->declBit(c+179,"hit", false,-1);
    tracep->declBus(c+311,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+34,"pc", false,-1, 31,0);
    tracep->declBus(c+37,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+34,"pc", false,-1, 31,0);
    tracep->declBus(c+118,"imm", false,-1, 31,0);
    tracep->declBus(c+261,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+111,"inst", false,-1, 31,0);
    tracep->declBit(c+112,"valid_from", false,-1);
    tracep->declBit(c+283,"ready_from", false,-1);
    tracep->declBit(c+119,"ebreaksig", false,-1);
    tracep->declBit(c+121,"ecallsig", false,-1);
    tracep->declBit(c+120,"mretsig", false,-1);
    tracep->declBus(c+118,"imm", false,-1, 31,0);
    tracep->declBus(c+126,"func3", false,-1, 2,0);
    tracep->declBit(c+128,"func7", false,-1);
    tracep->declBus(c+115,"src1", false,-1, 4,0);
    tracep->declBus(c+116,"src2", false,-1, 4,0);
    tracep->declBus(c+117,"rd", false,-1, 4,0);
    tracep->declBit(c+123,"memew", false,-1);
    tracep->declBus(c+127,"muxsig", false,-1, 2,0);
    tracep->declBit(c+124,"memer", false,-1);
    tracep->declBit(c+122,"regew", false,-1);
    tracep->declBit(c+125,"muximm", false,-1);
    tracep->declBit(c+129,"btypebranch", false,-1);
    tracep->declBit(c+131,"jalrsig", false,-1);
    tracep->declBit(c+130,"jalsig", false,-1);
    tracep->declBus(c+133,"aluop", false,-1, 1,0);
    tracep->declBit(c+132,"auipcsig", false,-1);
    tracep->declBit(c+134,"csrrw", false,-1);
    tracep->declBit(c+135,"csrrs", false,-1);
    tracep->declBit(c+112,"valid_to", false,-1);
    tracep->declBit(c+283,"ready_to", false,-1);
    tracep->declBus(c+136,"memmask", false,-1, 2,0);
    tracep->declBit(c+137,"memsextsig", false,-1);
    tracep->declBit(c+119,"ebreak", false,-1);
    tracep->declBit(c+121,"ecall", false,-1);
    tracep->declBit(c+120,"mret", false,-1);
    tracep->declBus(c+126,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+128,"func7bridge", false,-1);
    tracep->declBus(c+180,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+111,"inst", false,-1, 31,0);
    tracep->declBit(c+119,"ebreaksig", false,-1);
    tracep->declBit(c+121,"ecallsig", false,-1);
    tracep->declBit(c+120,"mretsig", false,-1);
    tracep->declBus(c+118,"imm", false,-1, 31,0);
    tracep->declBus(c+180,"opcode", false,-1, 6,0);
    tracep->declBus(c+126,"func3", false,-1, 2,0);
    tracep->declBit(c+128,"func7", false,-1);
    tracep->declBus(c+115,"src1", false,-1, 4,0);
    tracep->declBus(c+116,"src2", false,-1, 4,0);
    tracep->declBus(c+117,"rd", false,-1, 4,0);
    tracep->declBus(c+136,"memmask", false,-1, 2,0);
    tracep->declBit(c+137,"memsextsig", false,-1);
    tracep->declBit(c+181,"type_I", false,-1);
    tracep->declBit(c+182,"type_R", false,-1);
    tracep->declBit(c+183,"type_U", false,-1);
    tracep->declBit(c+123,"type_S", false,-1);
    tracep->declBit(c+130,"type_J", false,-1);
    tracep->declBit(c+129,"type_B", false,-1);
    tracep->declBus(c+184,"I_imm", false,-1, 31,0);
    tracep->declBus(c+185,"U_imm", false,-1, 31,0);
    tracep->declBus(c+186,"S_imm", false,-1, 31,0);
    tracep->declBus(c+187,"J_imm", false,-1, 31,0);
    tracep->declBus(c+188,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+180,"opcode", false,-1, 6,0);
    tracep->declBus(c+126,"func3", false,-1, 2,0);
    tracep->declBit(c+128,"func7", false,-1);
    tracep->declBit(c+119,"ebreaksig", false,-1);
    tracep->declBit(c+121,"ecallsig", false,-1);
    tracep->declBit(c+120,"mretsig", false,-1);
    tracep->declBit(c+123,"memew", false,-1);
    tracep->declBus(c+127,"muxsig", false,-1, 2,0);
    tracep->declBit(c+124,"memer", false,-1);
    tracep->declBit(c+122,"regew", false,-1);
    tracep->declBit(c+125,"muximm", false,-1);
    tracep->declBit(c+129,"btypebranch", false,-1);
    tracep->declBit(c+131,"jalrsig", false,-1);
    tracep->declBit(c+130,"jalsig", false,-1);
    tracep->declBus(c+133,"aluop", false,-1, 1,0);
    tracep->declBit(c+132,"auipcsig", false,-1);
    tracep->declBit(c+134,"csrrw", false,-1);
    tracep->declBit(c+135,"csrrs", false,-1);
    tracep->declBit(c+181,"type_I", false,-1);
    tracep->declBit(c+182,"type_R", false,-1);
    tracep->declBit(c+183,"type_U", false,-1);
    tracep->declBit(c+123,"type_S", false,-1);
    tracep->declBit(c+130,"type_J", false,-1);
    tracep->declBit(c+129,"type_B", false,-1);
    tracep->declBit(c+124,"load", false,-1);
    tracep->declBit(c+123,"store", false,-1);
    tracep->declBit(c+189,"regwritepc", false,-1);
    tracep->declBit(c+124,"regwritemem", false,-1);
    tracep->declBit(c+190,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBit(c+292,"rst", false,-1);
    tracep->declBus(c+226,"npc", false,-1, 31,0);
    tracep->declBit(c+283,"ready", false,-1);
    tracep->declBus(c+34,"pc", false,-1, 31,0);
    tracep->declBus(c+111,"inst", false,-1, 31,0);
    tracep->declBit(c+112,"valid", false,-1);
    tracep->declBit(c+283,"arvalid", false,-1);
    tracep->declBit(c+113,"arready", false,-1);
    tracep->declBus(c+226,"araddr", false,-1, 31,0);
    tracep->declBit(c+114,"rvalid", false,-1);
    tracep->declBit(c+283,"rready", false,-1);
    tracep->declBus(c+227,"rdata", false,-1, 31,0);
    tracep->declBus(c+34,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+114,"infetch_ready", false,-1);
    tracep->declBus(c+111,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBus(c+226,"npc", false,-1, 31,0);
    tracep->declBit(c+292,"rst", false,-1);
    tracep->declBit(c+114,"ready_from", false,-1);
    tracep->declBus(c+34,"pcout", false,-1, 31,0);
    tracep->declBus(c+312,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBit(c+292,"rst", false,-1);
    tracep->declBit(c+294,"ew", false,-1);
    tracep->declBus(c+117,"addr", false,-1, 4,0);
    tracep->declBus(c+115,"src1", false,-1, 4,0);
    tracep->declBus(c+116,"src2", false,-1, 4,0);
    tracep->declBus(c+191,"csr", false,-1, 11,0);
    tracep->declBus(c+228,"data", false,-1, 31,0);
    tracep->declBit(c+134,"csrrw", false,-1);
    tracep->declBit(c+135,"csrrs", false,-1);
    tracep->declBit(c+121,"ecallsig", false,-1);
    tracep->declBit(c+112,"valid", false,-1);
    tracep->declBus(c+229,"regout1", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBus(c+35,"mepc", false,-1, 31,0);
    tracep->declBus(c+36,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+38+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+70+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+192,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+272,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+300,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+313,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+296,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+192,"out", false,-1, 1,0);
    tracep->declBus(c+191,"key", false,-1, 11,0);
    tracep->declQuad(c+314,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+300,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+313,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+296,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+297,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+192,"out", false,-1, 1,0);
    tracep->declBus(c+191,"key", false,-1, 11,0);
    tracep->declBus(c+316,"default_out", false,-1, 1,0);
    tracep->declQuad(c+314,"lut", false,-1, 55,0);
    tracep->declBus(c+317,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+19+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+23+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+193,"lut_out", false,-1, 1,0);
    tracep->declBit(c+194,"hit", false,-1);
    tracep->declBus(c+306,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+291,"clk", false,-1);
    tracep->declBit(c+292,"rst", false,-1);
    tracep->declBit(c+289,"ew", false,-1);
    tracep->declBit(c+134,"csrrw", false,-1);
    tracep->declBit(c+135,"csrrs", false,-1);
    tracep->declBit(c+121,"ecall", false,-1);
    tracep->declBus(c+192,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+117,"addr", false,-1, 4,0);
    tracep->declBus(c+272,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+74+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+106+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+110,"i", false,-1, 31,0);
    tracep->declBus(c+318,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBus(c+231,"res", false,-1, 31,0);
    tracep->declBus(c+230,"regout2", false,-1, 31,0);
    tracep->declBit(c+123,"memew", false,-1);
    tracep->declBit(c+124,"memer", false,-1);
    tracep->declBus(c+118,"imm", false,-1, 31,0);
    tracep->declBus(c+232,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+127,"muxsig", false,-1, 2,0);
    tracep->declBit(c+112,"valid_from", false,-1);
    tracep->declBus(c+136,"memmask", false,-1, 2,0);
    tracep->declBit(c+137,"memsextsig", false,-1);
    tracep->declBus(c+228,"regwrite", false,-1, 31,0);
    tracep->declBit(c+283,"ready_to", false,-1);
    tracep->declBit(c+283,"memvalid", false,-1);
    tracep->declBit(c+290,"awvalid", false,-1);
    tracep->declBit(c+195,"awready", false,-1);
    tracep->declBus(c+231,"awaddr", false,-1, 31,0);
    tracep->declBit(c+290,"wvalid", false,-1);
    tracep->declBit(c+195,"wready", false,-1);
    tracep->declBus(c+230,"wdata", false,-1, 31,0);
    tracep->declBus(c+196,"wstrb", false,-1, 3,0);
    tracep->declBit(c+197,"bvalid", false,-1);
    tracep->declBit(c+123,"bready", false,-1);
    tracep->declBit(c+198,"bresp", false,-1);
    tracep->declBit(c+124,"arvalid", false,-1);
    tracep->declBit(c+195,"arready", false,-1);
    tracep->declBus(c+231,"araddr", false,-1, 31,0);
    tracep->declBit(c+199,"rvalid", false,-1);
    tracep->declBit(c+124,"rready", false,-1);
    tracep->declBus(c+273,"rdata", false,-1, 31,0);
    tracep->declBus(c+274,"memread", false,-1, 31,0);
    tracep->declBit(c+295,"bresp_get", false,-1);
    tracep->declBit(c+195,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+273,"data", false,-1, 31,0);
    tracep->declBus(c+136,"memmask", false,-1, 2,0);
    tracep->declBit(c+137,"memsextsig", false,-1);
    tracep->declBus(c+274,"read", false,-1, 31,0);
    tracep->declBus(c+275,"read_u", false,-1, 31,0);
    tracep->declBus(c+276,"read_s", false,-1, 31,0);
    tracep->declBus(c+277,"read_sb", false,-1, 31,0);
    tracep->declBus(c+278,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+319,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+308,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+279,"input_number", false,-1, 7,0);
    tracep->declBus(c+277,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+320,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+308,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+280,"input_number", false,-1, 15,0);
    tracep->declBus(c+278,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+300,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+302,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+308,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+228,"out", false,-1, 31,0);
    tracep->declBus(c+127,"key", false,-1, 2,0);
    tracep->declBus(c+297,"default_out", false,-1, 31,0);
    tracep->declArray(c+209,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+300,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+302,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+308,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+307,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+228,"out", false,-1, 31,0);
    tracep->declBus(c+127,"key", false,-1, 2,0);
    tracep->declBus(c+297,"default_out", false,-1, 31,0);
    tracep->declArray(c+209,"lut", false,-1, 139,0);
    tracep->declBus(c+321,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+214+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+27+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+222+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+281,"lut_out", false,-1, 31,0);
    tracep->declBit(c+282,"hit", false,-1);
    tracep->declBus(c+306,"i", false,-1, 31,0);
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
    bufp->fullCData(oldp+31,((0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))),4);
    bufp->fullCData(oldp+32,(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num),8);
    bufp->fullBit(oldp+33,((1U & VL_REDXOR_8((0xb8U 
                                              & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))))));
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullIData(oldp+37,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+112,(vlSelf->top__DOT__ifu_valid));
    bufp->fullBit(oldp+113,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                             & ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))));
    bufp->fullBit(oldp+114,((1U & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
    bufp->fullCData(oldp+115,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+116,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+117,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+119,((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+120,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+121,((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+122,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                             | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                      | (3U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__inst_reg))))))));
    bufp->fullBit(oldp+123,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+124,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+125,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+126,((7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+127,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+128,((1U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+129,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+130,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+131,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+132,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+133,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+134,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+135,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+136,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+137,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+138,(((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+139,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram))))),2);
    bufp->fullCData(oldp+140,(vlSelf->top__DOT__data0__DOT__rvalid_out),2);
    bufp->fullCData(oldp+141,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                               & (- (IData)(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                             & (0U 
                                                == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))))),2);
    bufp->fullCData(oldp+142,(vlSelf->top__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+143,(vlSelf->top__DOT__wstrb[1]),4);
    bufp->fullBit(oldp+144,(vlSelf->top__DOT__bresp[0]));
    bufp->fullBit(oldp+145,(vlSelf->top__DOT__bresp[1]));
    bufp->fullCData(oldp+146,(vlSelf->top__DOT____Vcellinp__data0__wstrb[0]),4);
    bufp->fullCData(oldp+147,(vlSelf->top__DOT____Vcellinp__data0__wstrb[1]),4);
    bufp->fullBit(oldp+148,(vlSelf->top__DOT____Vcellout__data0__bresp[0]));
    bufp->fullBit(oldp+149,(vlSelf->top__DOT____Vcellout__data0__bresp[1]));
    bufp->fullBit(oldp+150,((0U != (((0x23U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                     << 1U) & (IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant)))));
    bufp->fullBit(oldp+151,((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullBit(oldp+152,(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                             & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
    bufp->fullCData(oldp+153,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullBit(oldp+154,((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullCData(oldp+155,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+156,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullBit(oldp+157,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0]));
    bufp->fullBit(oldp+158,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[1]));
    bufp->fullBit(oldp+159,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+160,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__i),32);
    bufp->fullCData(oldp+162,(vlSelf->top__DOT__data0__DOT__mem0__DOT__state),2);
    bufp->fullBit(oldp+163,(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy));
    bufp->fullCData(oldp+164,(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count),4);
    bufp->fullCData(oldp+165,(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask),3);
    bufp->fullCData(oldp+166,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+167,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+168,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+169,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+170,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+171,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+172,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+173,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+174,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+175,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+176,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+177,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+178,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+179,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+180,((0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+181,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+182,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+183,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+184,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+185,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+186,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+188,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+189,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+190,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullSData(oldp+191,((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+192,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+193,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+194,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+195,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (- (IData)(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                                  & (0U 
                                                     == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))))) 
                                   >> 1U))));
    bufp->fullCData(oldp+196,(((1U == (IData)(vlSelf->top__DOT__memmask))
                                ? 1U : ((2U == (IData)(vlSelf->top__DOT__memmask))
                                         ? 2U : ((3U 
                                                  == (IData)(vlSelf->top__DOT__memmask))
                                                  ? 4U
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->top__DOT__memmask))
                                                   ? 8U
                                                   : 0U))))),4);
    bufp->fullBit(oldp+197,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram)))) 
                                   >> 1U))));
    bufp->fullBit(oldp+198,(vlSelf->top__DOT____Vcellinp__wbu0__bresp));
    bufp->fullBit(oldp+199,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U))));
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+200,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+203,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+205,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+207,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+208,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+209,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+214,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+216,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+218,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+220,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+222,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+223,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+224,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+225,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+226,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+227,(vlSelf->top__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+228,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+229,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+230,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+231,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+232,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+233,(vlSelf->top__DOT__araddr[0]),32);
    bufp->fullIData(oldp+234,(vlSelf->top__DOT__araddr[1]),32);
    bufp->fullIData(oldp+235,(vlSelf->top__DOT__rdata[0]),32);
    bufp->fullIData(oldp+236,(vlSelf->top__DOT__rdata[1]),32);
    bufp->fullIData(oldp+237,(vlSelf->top__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+238,(vlSelf->top__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+239,(vlSelf->top__DOT__wdata[0]),32);
    bufp->fullIData(oldp+240,(vlSelf->top__DOT__wdata[1]),32);
    bufp->fullIData(oldp+241,(vlSelf->top__DOT____Vcellinp__data0__araddr[0]),32);
    bufp->fullIData(oldp+242,(vlSelf->top__DOT____Vcellinp__data0__araddr[1]),32);
    bufp->fullIData(oldp+243,(vlSelf->top__DOT____Vcellout__data0__rdata[0]),32);
    bufp->fullIData(oldp+244,(vlSelf->top__DOT____Vcellout__data0__rdata[1]),32);
    bufp->fullIData(oldp+245,(vlSelf->top__DOT____Vcellinp__data0__awaddr[0]),32);
    bufp->fullIData(oldp+246,(vlSelf->top__DOT____Vcellinp__data0__awaddr[1]),32);
    bufp->fullIData(oldp+247,(vlSelf->top__DOT____Vcellinp__data0__wdata[0]),32);
    bufp->fullIData(oldp+248,(vlSelf->top__DOT____Vcellinp__data0__wdata[1]),32);
    bufp->fullIData(oldp+249,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullIData(oldp+250,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+251,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullIData(oldp+252,(vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg),32);
    bufp->fullIData(oldp+253,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+254,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+255,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+256,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+257,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+258,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullIData(oldp+259,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+260,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullIData(oldp+261,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+262,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+263,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+264,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+265,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+266,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+267,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+268,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+269,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+270,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+271,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+272,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+273,(vlSelf->top__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+274,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+275,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+276,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+277,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__rdata
                                          [1U]))),32);
    bufp->fullIData(oldp+278,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__rdata
                                             [1U]))),32);
    bufp->fullCData(oldp+279,((0xffU & vlSelf->top__DOT__rdata
                               [1U])),8);
    bufp->fullSData(oldp+280,((0xffffU & vlSelf->top__DOT__rdata
                               [1U])),16);
    bufp->fullIData(oldp+281,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+282,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+283,(vlSelf->top__DOT__ready_idu_to_ifu));
    bufp->fullCData(oldp+284,(((IData)(vlSelf->top__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+285,(vlSelf->top__DOT__data0__DOT__arvalid_in),2);
    bufp->fullBit(oldp+286,(vlSelf->top__DOT__data0__DOT__awvalid_sram));
    bufp->fullBit(oldp+287,(vlSelf->top__DOT__data0__DOT__wvalid_sram));
    bufp->fullBit(oldp+288,(vlSelf->top__DOT__data0__DOT__arvalid_sram));
    bufp->fullBit(oldp+289,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullBit(oldp+290,(vlSelf->top__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+291,(vlSelf->clk));
    bufp->fullBit(oldp+292,(vlSelf->rst));
    bufp->fullBit(oldp+293,((0U != ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (IData)(vlSelf->top__DOT__data0__DOT__arvalid_in)))));
    bufp->fullBit(oldp+294,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                             & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                         | (3U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)))))))));
    bufp->fullBit(oldp+295,(vlSelf->top__DOT__wbu0__DOT__bresp_get));
    bufp->fullIData(oldp+296,(2U),32);
    bufp->fullIData(oldp+297,(0U),32);
    bufp->fullBit(oldp+298,(vlSelf->top__DOT__data0__DOT__bvalid_sram));
    bufp->fullIData(oldp+299,(2U),32);
    bufp->fullIData(oldp+300,(4U),32);
    bufp->fullBit(oldp+301,(0U));
    bufp->fullIData(oldp+302,(3U),32);
    bufp->fullIData(oldp+303,(0x12491c4U),28);
    bufp->fullCData(oldp+304,(0U),3);
    bufp->fullIData(oldp+305,(7U),32);
    bufp->fullIData(oldp+306,(4U),32);
    bufp->fullIData(oldp+307,(1U),32);
    bufp->fullIData(oldp+308,(0x20U),32);
    bufp->fullIData(oldp+309,(0U),32);
    bufp->fullIData(oldp+310,(0x21U),32);
    bufp->fullIData(oldp+311,(2U),32);
    bufp->fullIData(oldp+312,(0x7ffffffcU),32);
    bufp->fullIData(oldp+313,(0xcU),32);
    bufp->fullQData(oldp+314,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+316,(0U),2);
    bufp->fullIData(oldp+317,(0xeU),32);
    bufp->fullIData(oldp+318,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+319,(8U),32);
    bufp->fullIData(oldp+320,(0x10U),32);
    bufp->fullIData(oldp+321,(0x23U),32);
}
