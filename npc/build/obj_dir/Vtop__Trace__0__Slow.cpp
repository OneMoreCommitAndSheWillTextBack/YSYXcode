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
    tracep->declBit(c+137,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+249,"npc", false,-1, 31,0);
    tracep->declBus(c+60,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+138,"inst", false,-1, 31,0);
    tracep->declBit(c+139,"ifu_valid", false,-1);
    tracep->declBit(c+137,"ifu_arvalid", false,-1);
    tracep->declBit(c+31,"ifu_arready", false,-1);
    tracep->declBus(c+249,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+139,"ifu_rvalid", false,-1);
    tracep->declBit(c+137,"ifu_rready", false,-1);
    tracep->declBus(c+140,"ifu_rdata", false,-1, 31,0);
    tracep->declBus(c+141,"src1", false,-1, 4,0);
    tracep->declBus(c+142,"src2", false,-1, 4,0);
    tracep->declBus(c+143,"rd", false,-1, 4,0);
    tracep->declBus(c+144,"imm", false,-1, 31,0);
    tracep->declBit(c+145,"ebreaksig", false,-1);
    tracep->declBit(c+146,"mretsig", false,-1);
    tracep->declBit(c+147,"ecallsig", false,-1);
    tracep->declBit(c+148,"regew", false,-1);
    tracep->declBit(c+149,"memew", false,-1);
    tracep->declBit(c+150,"memer", false,-1);
    tracep->declBit(c+151,"muximm", false,-1);
    tracep->declBus(c+152,"func3", false,-1, 2,0);
    tracep->declBus(c+153,"muxsig", false,-1, 2,0);
    tracep->declBit(c+154,"func7", false,-1);
    tracep->declBit(c+155,"btypebranch", false,-1);
    tracep->declBit(c+156,"jalsig", false,-1);
    tracep->declBit(c+157,"jalrsig", false,-1);
    tracep->declBit(c+158,"auipcsig", false,-1);
    tracep->declBus(c+159,"aluop", false,-1, 1,0);
    tracep->declBit(c+160,"csrrw", false,-1);
    tracep->declBit(c+161,"csrrs", false,-1);
    tracep->declBit(c+139,"idu_valid", false,-1);
    tracep->declBus(c+162,"memmask", false,-1, 2,0);
    tracep->declBit(c+163,"memsextsig", false,-1);
    tracep->declBus(c+250,"regwrite", false,-1, 31,0);
    tracep->declBus(c+251,"regout1", false,-1, 31,0);
    tracep->declBus(c+252,"regout2", false,-1, 31,0);
    tracep->declBus(c+61,"mepc", false,-1, 31,0);
    tracep->declBus(c+62,"mtvec", false,-1, 31,0);
    tracep->declBit(c+137,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+253,"res", false,-1, 31,0);
    tracep->declBus(c+254,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+139,"exu_valid", false,-1);
    tracep->declBit(c+137,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+137,"memvalid", false,-1);
    tracep->declBus(c+164,"awvalid", false,-1, 1,0);
    tracep->declBus(c+164,"wvalid", false,-1, 1,0);
    tracep->declBus(c+165,"arvalid", false,-1, 1,0);
    tracep->declBus(c+165,"rready", false,-1, 1,0);
    tracep->declBus(c+164,"bready", false,-1, 1,0);
    tracep->declBus(c+32,"bvalid", false,-1, 1,0);
    tracep->declBus(c+166,"rvalid", false,-1, 1,0);
    tracep->declBus(c+33,"awready", false,-1, 1,0);
    tracep->declBus(c+33,"wready", false,-1, 1,0);
    tracep->declBus(c+33,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+255+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+167+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+257+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+259+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+169+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+34+i*1,"bresp", true,(i+0));
    }
    tracep->pushNamePrefix("data0 ");
    tracep->declBus(c+293,"NUM", false,-1, 31,0);
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBus(c+164,"awvalid", false,-1, 1,0);
    tracep->declBus(c+164,"wvalid", false,-1, 1,0);
    tracep->declBus(c+165,"arvalid", false,-1, 1,0);
    tracep->declBus(c+165,"rready", false,-1, 1,0);
    tracep->declBus(c+164,"bready", false,-1, 1,0);
    tracep->declBus(c+32,"bvalid", false,-1, 1,0);
    tracep->declBus(c+166,"rvalid", false,-1, 1,0);
    tracep->declBus(c+33,"awready", false,-1, 1,0);
    tracep->declBus(c+33,"wready", false,-1, 1,0);
    tracep->declBus(c+33,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+261+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+36+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+263+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+265+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+171+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+38+i*1,"bresp", true,(i+0));
    }
    tracep->declBus(c+294,"DEVICE", false,-1, 31,0);
    tracep->declBus(c+164,"awvalid_in", false,-1, 1,0);
    tracep->declBus(c+164,"wvalid_in", false,-1, 1,0);
    tracep->declBus(c+165,"arvalid_in", false,-1, 1,0);
    tracep->declBus(c+165,"rready_in", false,-1, 1,0);
    tracep->declBus(c+164,"bready_in", false,-1, 1,0);
    tracep->declBus(c+166,"rvalid_out", false,-1, 1,0);
    tracep->declBus(c+33,"awready_out", false,-1, 1,0);
    tracep->declBus(c+33,"wready_out", false,-1, 1,0);
    tracep->declBus(c+33,"arready_out", false,-1, 1,0);
    tracep->declBus(c+32,"bvalid_out", false,-1, 1,0);
    tracep->declBit(c+173,"awvalid_sram", false,-1);
    tracep->declBit(c+174,"wvalid_sram", false,-1);
    tracep->declBit(c+175,"arvalid_sram", false,-1);
    tracep->declBit(c+176,"rready_sram", false,-1);
    tracep->declBit(c+173,"bready_sram", false,-1);
    tracep->declBit(c+40,"rvalid_sram", false,-1);
    tracep->declBit(c+41,"awready_sram", false,-1);
    tracep->declBit(c+41,"wready_sram", false,-1);
    tracep->declBit(c+41,"arready_sram", false,-1);
    tracep->declBit(c+295,"bvalid_sram", false,-1);
    tracep->declBus(c+267,"awaddr_sram", false,-1, 31,0);
    tracep->declBus(c+268,"araddr_sram", false,-1, 31,0);
    tracep->declBus(c+269,"wdata_sram", false,-1, 31,0);
    tracep->declBus(c+42,"rdata_sram", false,-1, 31,0);
    tracep->declBus(c+177,"wstrb_sram", false,-1, 3,0);
    tracep->declBit(c+43,"bresp_sram", false,-1);
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+293,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBus(c+164,"awvalid", false,-1, 1,0);
    tracep->declBus(c+164,"wvalid", false,-1, 1,0);
    tracep->declBus(c+165,"arvalid", false,-1, 1,0);
    tracep->declBus(c+165,"rready", false,-1, 1,0);
    tracep->declBus(c+164,"bready", false,-1, 1,0);
    tracep->declBus(c+32,"bvalid", false,-1, 1,0);
    tracep->declBus(c+166,"rvalid", false,-1, 1,0);
    tracep->declBus(c+33,"awready", false,-1, 1,0);
    tracep->declBus(c+33,"wready", false,-1, 1,0);
    tracep->declBus(c+33,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+270+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+272+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+274+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+178+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+44+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+46+i*1,"bresp", true,(i+0));
    }
    tracep->declBit(c+173,"awvalid_out", false,-1);
    tracep->declBit(c+174,"wvalid_out", false,-1);
    tracep->declBit(c+175,"arvalid_out", false,-1);
    tracep->declBit(c+176,"rready_out", false,-1);
    tracep->declBit(c+173,"bready_out", false,-1);
    tracep->declBit(c+295,"bvalid_in", false,-1);
    tracep->declBit(c+40,"rvalid_in", false,-1);
    tracep->declBit(c+41,"awready_in", false,-1);
    tracep->declBit(c+41,"wready_in", false,-1);
    tracep->declBit(c+41,"arready_in", false,-1);
    tracep->declBus(c+268,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+267,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+269,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+177,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+42,"rdata_in", false,-1, 31,0);
    tracep->declBit(c+43,"bresp_in", false,-1);
    tracep->declBit(c+48,"busy", false,-1);
    tracep->declBus(c+49,"grant", false,-1, 1,0);
    tracep->declBus(c+50,"next_grant", false,-1, 1,0);
    tracep->declBus(c+267,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+269,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+268,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+177,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+296,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+173,"awvalid", false,-1);
    tracep->declBit(c+41,"awready", false,-1);
    tracep->declBus(c+267,"awaddr", false,-1, 31,0);
    tracep->declBit(c+174,"wvalid", false,-1);
    tracep->declBit(c+41,"wready", false,-1);
    tracep->declBus(c+269,"wdata", false,-1, 31,0);
    tracep->declBus(c+177,"wstrb", false,-1, 3,0);
    tracep->declBit(c+295,"bvalid", false,-1);
    tracep->declBit(c+173,"bready", false,-1);
    tracep->declBit(c+43,"bresp", false,-1);
    tracep->declBit(c+175,"arvalid", false,-1);
    tracep->declBit(c+41,"arready", false,-1);
    tracep->declBus(c+268,"araddr", false,-1, 31,0);
    tracep->declBit(c+176,"rready", false,-1);
    tracep->declBit(c+40,"rvalid", false,-1);
    tracep->declBus(c+42,"rdata", false,-1, 31,0);
    tracep->declBus(c+51,"state", false,-1, 1,0);
    tracep->declBus(c+52,"random_delay", false,-1, 3,0);
    tracep->declBit(c+53,"busy", false,-1);
    tracep->declBus(c+54,"random_count", false,-1, 3,0);
    tracep->declBus(c+180,"memmask", false,-1, 2,0);
    tracep->declBus(c+42,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("lsfr0 ");
    tracep->declBus(c+297,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+298,"reset", false,-1);
    tracep->declBus(c+52,"out", false,-1, 3,0);
    tracep->declBus(c+55,"random_num", false,-1, 7,0);
    tracep->declBit(c+56,"feedback", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+297,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+297,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+299,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+180,"out", false,-1, 2,0);
    tracep->declBus(c+177,"key", false,-1, 3,0);
    tracep->declBus(c+300,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+297,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+297,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+299,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+294,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+180,"out", false,-1, 2,0);
    tracep->declBus(c+177,"key", false,-1, 3,0);
    tracep->declBus(c+301,"default_out", false,-1, 2,0);
    tracep->declBus(c+300,"lut", false,-1, 27,0);
    tracep->declBus(c+302,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+9+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+181,"lut_out", false,-1, 2,0);
    tracep->declBit(c+182,"hit", false,-1);
    tracep->declBus(c+303,"i", false,-1, 31,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+152,"func3", false,-1, 2,0);
    tracep->declBit(c+155,"btypebranch", false,-1);
    tracep->declBit(c+154,"func7", false,-1);
    tracep->declBus(c+159,"aluop", false,-1, 1,0);
    tracep->declBit(c+157,"jalrsig", false,-1);
    tracep->declBit(c+156,"jalsig", false,-1);
    tracep->declBus(c+144,"imm", false,-1, 31,0);
    tracep->declBit(c+151,"muximm", false,-1);
    tracep->declBus(c+251,"regout1", false,-1, 31,0);
    tracep->declBus(c+252,"regout2", false,-1, 31,0);
    tracep->declBus(c+60,"pc", false,-1, 31,0);
    tracep->declBit(c+158,"auipcsig", false,-1);
    tracep->declBit(c+146,"mretsig", false,-1);
    tracep->declBit(c+147,"ecallsig", false,-1);
    tracep->declBus(c+62,"mtvec", false,-1, 31,0);
    tracep->declBus(c+61,"mepc", false,-1, 31,0);
    tracep->declBit(c+139,"valid_from", false,-1);
    tracep->declBit(c+137,"ready_from", false,-1);
    tracep->declBus(c+253,"res", false,-1, 31,0);
    tracep->declBus(c+249,"npc", false,-1, 31,0);
    tracep->declBus(c+254,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+139,"valid_to", false,-1);
    tracep->declBit(c+137,"ready_to", false,-1);
    tracep->declBus(c+63,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+276,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+183,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+277,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+278,"zero", false,-1);
    tracep->declBit(c+279,"signal", false,-1);
    tracep->declBit(c+280,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+251,"A", false,-1, 31,0);
    tracep->declBus(c+277,"B", false,-1, 31,0);
    tracep->declBus(c+183,"op", false,-1, 4,0);
    tracep->declBus(c+253,"res", false,-1, 31,0);
    tracep->declBit(c+278,"zero", false,-1);
    tracep->declBit(c+279,"signal", false,-1);
    tracep->declBit(c+280,"carry", false,-1);
    tracep->declBit(c+184,"addsig", false,-1);
    tracep->declBit(c+185,"logsig", false,-1);
    tracep->declBit(c+186,"shfsig", false,-1);
    tracep->declBit(c+187,"sltsig", false,-1);
    tracep->declBit(c+280,"carry_tmp", false,-1);
    tracep->declBit(c+188,"type_I", false,-1);
    tracep->declBus(c+281,"logres", false,-1, 31,0);
    tracep->declBus(c+282,"addres", false,-1, 31,0);
    tracep->declBit(c+283,"addzero", false,-1);
    tracep->declBus(c+284,"shfres", false,-1, 31,0);
    tracep->declBus(c+285,"sltres", false,-1, 31,0);
    tracep->declBus(c+251,"A_s", false,-1, 31,0);
    tracep->declBus(c+277,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+152,"func3", false,-1, 2,0);
    tracep->declBit(c+154,"func7", false,-1);
    tracep->declBus(c+159,"aluop", false,-1, 1,0);
    tracep->declBit(c+157,"jalrsig", false,-1);
    tracep->declBus(c+183,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+188,"type_I", false,-1);
    tracep->declBit(c+189,"type_B", false,-1);
    tracep->declBit(c+190,"type_R", false,-1);
    tracep->declBit(c+191,"addsig", false,-1);
    tracep->declBus(c+192,"branchop", false,-1, 3,0);
    tracep->declBus(c+193,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+155,"btypebranch", false,-1);
    tracep->declBus(c+152,"func3", false,-1, 2,0);
    tracep->declBit(c+278,"zero", false,-1);
    tracep->declBit(c+279,"signal", false,-1);
    tracep->declBit(c+280,"carry", false,-1);
    tracep->declBus(c+253,"res", false,-1, 31,0);
    tracep->declBus(c+63,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+276,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+156,"jalsig", false,-1);
    tracep->declBit(c+157,"jalrsig", false,-1);
    tracep->declBit(c+158,"auipcsig", false,-1);
    tracep->declBit(c+146,"mretsig", false,-1);
    tracep->declBit(c+147,"ecallsig", false,-1);
    tracep->declBus(c+62,"mtvec", false,-1, 31,0);
    tracep->declBus(c+61,"mepc", false,-1, 31,0);
    tracep->declBus(c+249,"npc", false,-1, 31,0);
    tracep->declBus(c+254,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+293,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+304,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+305,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+277,"out", false,-1, 31,0);
    tracep->declBus(c+151,"key", false,-1, 0,0);
    tracep->declArray(c+223,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+293,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+304,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+305,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+294,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+277,"out", false,-1, 31,0);
    tracep->declBus(c+151,"key", false,-1, 0,0);
    tracep->declBus(c+306,"default_out", false,-1, 31,0);
    tracep->declArray(c+223,"lut", false,-1, 65,0);
    tracep->declBus(c+307,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+226+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+13+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+230+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+286,"lut_out", false,-1, 31,0);
    tracep->declBit(c+194,"hit", false,-1);
    tracep->declBus(c+308,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+60,"pc", false,-1, 31,0);
    tracep->declBus(c+63,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+60,"pc", false,-1, 31,0);
    tracep->declBus(c+144,"imm", false,-1, 31,0);
    tracep->declBus(c+276,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+138,"inst", false,-1, 31,0);
    tracep->declBit(c+139,"valid_from", false,-1);
    tracep->declBit(c+137,"ready_from", false,-1);
    tracep->declBit(c+145,"ebreaksig", false,-1);
    tracep->declBit(c+147,"ecallsig", false,-1);
    tracep->declBit(c+146,"mretsig", false,-1);
    tracep->declBus(c+144,"imm", false,-1, 31,0);
    tracep->declBus(c+152,"func3", false,-1, 2,0);
    tracep->declBit(c+154,"func7", false,-1);
    tracep->declBus(c+141,"src1", false,-1, 4,0);
    tracep->declBus(c+142,"src2", false,-1, 4,0);
    tracep->declBus(c+143,"rd", false,-1, 4,0);
    tracep->declBit(c+149,"memew", false,-1);
    tracep->declBus(c+153,"muxsig", false,-1, 2,0);
    tracep->declBit(c+150,"memer", false,-1);
    tracep->declBit(c+148,"regew", false,-1);
    tracep->declBit(c+151,"muximm", false,-1);
    tracep->declBit(c+155,"btypebranch", false,-1);
    tracep->declBit(c+157,"jalrsig", false,-1);
    tracep->declBit(c+156,"jalsig", false,-1);
    tracep->declBus(c+159,"aluop", false,-1, 1,0);
    tracep->declBit(c+158,"auipcsig", false,-1);
    tracep->declBit(c+160,"csrrw", false,-1);
    tracep->declBit(c+161,"csrrs", false,-1);
    tracep->declBit(c+139,"valid_to", false,-1);
    tracep->declBit(c+137,"ready_to", false,-1);
    tracep->declBus(c+162,"memmask", false,-1, 2,0);
    tracep->declBit(c+163,"memsextsig", false,-1);
    tracep->declBit(c+145,"ebreak", false,-1);
    tracep->declBit(c+147,"ecall", false,-1);
    tracep->declBit(c+146,"mret", false,-1);
    tracep->declBus(c+152,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+154,"func7bridge", false,-1);
    tracep->declBus(c+195,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+138,"inst", false,-1, 31,0);
    tracep->declBit(c+145,"ebreaksig", false,-1);
    tracep->declBit(c+147,"ecallsig", false,-1);
    tracep->declBit(c+146,"mretsig", false,-1);
    tracep->declBus(c+144,"imm", false,-1, 31,0);
    tracep->declBus(c+195,"opcode", false,-1, 6,0);
    tracep->declBus(c+152,"func3", false,-1, 2,0);
    tracep->declBit(c+154,"func7", false,-1);
    tracep->declBus(c+141,"src1", false,-1, 4,0);
    tracep->declBus(c+142,"src2", false,-1, 4,0);
    tracep->declBus(c+143,"rd", false,-1, 4,0);
    tracep->declBus(c+162,"memmask", false,-1, 2,0);
    tracep->declBit(c+163,"memsextsig", false,-1);
    tracep->declBit(c+196,"type_I", false,-1);
    tracep->declBit(c+197,"type_R", false,-1);
    tracep->declBit(c+198,"type_U", false,-1);
    tracep->declBit(c+149,"type_S", false,-1);
    tracep->declBit(c+156,"type_J", false,-1);
    tracep->declBit(c+155,"type_B", false,-1);
    tracep->declBus(c+199,"I_imm", false,-1, 31,0);
    tracep->declBus(c+200,"U_imm", false,-1, 31,0);
    tracep->declBus(c+201,"S_imm", false,-1, 31,0);
    tracep->declBus(c+202,"J_imm", false,-1, 31,0);
    tracep->declBus(c+203,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+195,"opcode", false,-1, 6,0);
    tracep->declBus(c+152,"func3", false,-1, 2,0);
    tracep->declBit(c+154,"func7", false,-1);
    tracep->declBit(c+145,"ebreaksig", false,-1);
    tracep->declBit(c+147,"ecallsig", false,-1);
    tracep->declBit(c+146,"mretsig", false,-1);
    tracep->declBit(c+149,"memew", false,-1);
    tracep->declBus(c+153,"muxsig", false,-1, 2,0);
    tracep->declBit(c+150,"memer", false,-1);
    tracep->declBit(c+148,"regew", false,-1);
    tracep->declBit(c+151,"muximm", false,-1);
    tracep->declBit(c+155,"btypebranch", false,-1);
    tracep->declBit(c+157,"jalrsig", false,-1);
    tracep->declBit(c+156,"jalsig", false,-1);
    tracep->declBus(c+159,"aluop", false,-1, 1,0);
    tracep->declBit(c+158,"auipcsig", false,-1);
    tracep->declBit(c+160,"csrrw", false,-1);
    tracep->declBit(c+161,"csrrs", false,-1);
    tracep->declBit(c+196,"type_I", false,-1);
    tracep->declBit(c+197,"type_R", false,-1);
    tracep->declBit(c+198,"type_U", false,-1);
    tracep->declBit(c+149,"type_S", false,-1);
    tracep->declBit(c+156,"type_J", false,-1);
    tracep->declBit(c+155,"type_B", false,-1);
    tracep->declBit(c+150,"load", false,-1);
    tracep->declBit(c+149,"store", false,-1);
    tracep->declBit(c+204,"regwritepc", false,-1);
    tracep->declBit(c+150,"regwritemem", false,-1);
    tracep->declBit(c+205,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBus(c+249,"npc", false,-1, 31,0);
    tracep->declBit(c+137,"ready", false,-1);
    tracep->declBus(c+60,"pc", false,-1, 31,0);
    tracep->declBus(c+138,"inst", false,-1, 31,0);
    tracep->declBit(c+139,"valid", false,-1);
    tracep->declBit(c+137,"arvalid", false,-1);
    tracep->declBit(c+31,"arready", false,-1);
    tracep->declBus(c+249,"araddr", false,-1, 31,0);
    tracep->declBit(c+139,"rvalid", false,-1);
    tracep->declBit(c+137,"rready", false,-1);
    tracep->declBus(c+140,"rdata", false,-1, 31,0);
    tracep->declBus(c+60,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+206,"infetch_ready", false,-1);
    tracep->declBus(c+138,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBus(c+249,"npc", false,-1, 31,0);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBit(c+206,"ready_from", false,-1);
    tracep->declBus(c+60,"pcout", false,-1, 31,0);
    tracep->declBus(c+309,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBit(c+207,"ew", false,-1);
    tracep->declBus(c+143,"addr", false,-1, 4,0);
    tracep->declBus(c+141,"src1", false,-1, 4,0);
    tracep->declBus(c+142,"src2", false,-1, 4,0);
    tracep->declBus(c+208,"csr", false,-1, 11,0);
    tracep->declBus(c+250,"data", false,-1, 31,0);
    tracep->declBit(c+160,"csrrw", false,-1);
    tracep->declBit(c+161,"csrrs", false,-1);
    tracep->declBit(c+147,"ecallsig", false,-1);
    tracep->declBit(c+139,"valid", false,-1);
    tracep->declBus(c+251,"regout1", false,-1, 31,0);
    tracep->declBus(c+252,"regout2", false,-1, 31,0);
    tracep->declBus(c+61,"mepc", false,-1, 31,0);
    tracep->declBus(c+62,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+64+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+96+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+209,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+287,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+297,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+310,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+293,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+209,"out", false,-1, 1,0);
    tracep->declBus(c+208,"key", false,-1, 11,0);
    tracep->declQuad(c+311,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+297,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+310,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+293,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+294,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+209,"out", false,-1, 1,0);
    tracep->declBus(c+208,"key", false,-1, 11,0);
    tracep->declBus(c+313,"default_out", false,-1, 1,0);
    tracep->declQuad(c+311,"lut", false,-1, 55,0);
    tracep->declBus(c+314,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+19+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+23+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+210,"lut_out", false,-1, 1,0);
    tracep->declBit(c+211,"hit", false,-1);
    tracep->declBus(c+303,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+290,"clk", false,-1);
    tracep->declBit(c+291,"rst", false,-1);
    tracep->declBit(c+212,"ew", false,-1);
    tracep->declBit(c+160,"csrrw", false,-1);
    tracep->declBit(c+161,"csrrs", false,-1);
    tracep->declBit(c+147,"ecall", false,-1);
    tracep->declBus(c+209,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+143,"addr", false,-1, 4,0);
    tracep->declBus(c+287,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+100+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+132+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+136,"i", false,-1, 31,0);
    tracep->declBus(c+315,"tmp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBus(c+253,"res", false,-1, 31,0);
    tracep->declBus(c+252,"regout2", false,-1, 31,0);
    tracep->declBit(c+149,"memew", false,-1);
    tracep->declBit(c+150,"memer", false,-1);
    tracep->declBus(c+144,"imm", false,-1, 31,0);
    tracep->declBus(c+254,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+153,"muxsig", false,-1, 2,0);
    tracep->declBit(c+139,"valid_from", false,-1);
    tracep->declBus(c+162,"memmask", false,-1, 2,0);
    tracep->declBit(c+163,"memsextsig", false,-1);
    tracep->declBus(c+250,"regwrite", false,-1, 31,0);
    tracep->declBit(c+137,"ready_to", false,-1);
    tracep->declBit(c+137,"memvalid", false,-1);
    tracep->declBit(c+149,"awvalid", false,-1);
    tracep->declBit(c+57,"awready", false,-1);
    tracep->declBus(c+253,"awaddr", false,-1, 31,0);
    tracep->declBit(c+149,"wvalid", false,-1);
    tracep->declBit(c+57,"wready", false,-1);
    tracep->declBus(c+252,"wdata", false,-1, 31,0);
    tracep->declBus(c+213,"wstrb", false,-1, 3,0);
    tracep->declBit(c+58,"bvalid", false,-1);
    tracep->declBit(c+149,"bready", false,-1);
    tracep->declBit(c+59,"bresp", false,-1);
    tracep->declBit(c+150,"arvalid", false,-1);
    tracep->declBit(c+57,"arready", false,-1);
    tracep->declBus(c+253,"araddr", false,-1, 31,0);
    tracep->declBit(c+214,"rvalid", false,-1);
    tracep->declBit(c+150,"rready", false,-1);
    tracep->declBus(c+215,"rdata", false,-1, 31,0);
    tracep->declBus(c+216,"memread", false,-1, 31,0);
    tracep->declBit(c+57,"ready", false,-1);
    tracep->declBus(c+292,"valid", false,-1, 31,0);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+215,"data", false,-1, 31,0);
    tracep->declBus(c+162,"memmask", false,-1, 2,0);
    tracep->declBit(c+163,"memsextsig", false,-1);
    tracep->declBus(c+216,"read", false,-1, 31,0);
    tracep->declBus(c+217,"read_u", false,-1, 31,0);
    tracep->declBus(c+218,"read_s", false,-1, 31,0);
    tracep->declBus(c+219,"read_sb", false,-1, 31,0);
    tracep->declBus(c+220,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+316,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+305,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+221,"input_number", false,-1, 7,0);
    tracep->declBus(c+219,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+317,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+305,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+222,"input_number", false,-1, 15,0);
    tracep->declBus(c+220,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+297,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+299,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+305,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+250,"out", false,-1, 31,0);
    tracep->declBus(c+153,"key", false,-1, 2,0);
    tracep->declBus(c+294,"default_out", false,-1, 31,0);
    tracep->declArray(c+232,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+297,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+299,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+305,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+304,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+250,"out", false,-1, 31,0);
    tracep->declBus(c+153,"key", false,-1, 2,0);
    tracep->declBus(c+294,"default_out", false,-1, 31,0);
    tracep->declArray(c+232,"lut", false,-1, 139,0);
    tracep->declBus(c+318,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+237+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+27+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+245+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+288,"lut_out", false,-1, 31,0);
    tracep->declBit(c+289,"hit", false,-1);
    tracep->declBus(c+303,"i", false,-1, 31,0);
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
    bufp->fullBit(oldp+31,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__grant) 
                            & ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                               & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))));
    bufp->fullCData(oldp+32,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__grant) 
                              & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram))))),2);
    bufp->fullCData(oldp+33,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__grant) 
                              & (- (IData)(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                            & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))))))),2);
    bufp->fullBit(oldp+34,(vlSelf->top__DOT__bresp[0]));
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__bresp[1]));
    bufp->fullIData(oldp+36,(vlSelf->top__DOT____Vcellout__data0__rdata[0]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT____Vcellout__data0__rdata[1]),32);
    bufp->fullBit(oldp+38,(vlSelf->top__DOT____Vcellout__data0__bresp[0]));
    bufp->fullBit(oldp+39,(vlSelf->top__DOT____Vcellout__data0__bresp[1]));
    bufp->fullBit(oldp+40,((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullBit(oldp+41,(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                            & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg),32);
    bufp->fullBit(oldp+43,((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0]));
    bufp->fullBit(oldp+47,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[1]));
    bufp->fullBit(oldp+48,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+49,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__grant),2);
    bufp->fullCData(oldp+50,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__next_grant),2);
    bufp->fullCData(oldp+51,(vlSelf->top__DOT__data0__DOT__mem0__DOT__state),2);
    bufp->fullCData(oldp+52,((0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))),4);
    bufp->fullBit(oldp+53,(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy));
    bufp->fullCData(oldp+54,(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count),4);
    bufp->fullCData(oldp+55,(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num),8);
    bufp->fullBit(oldp+56,((1U & VL_REDXOR_8((0xb8U 
                                              & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))))));
    bufp->fullBit(oldp+57,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__grant) 
                                   & (- (IData)(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                                 & (0U 
                                                    == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))))) 
                                  >> 1U))));
    bufp->fullBit(oldp+58,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__grant) 
                                   & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__bvalid_sram)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+59,(vlSelf->top__DOT__bresp[1U]));
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullIData(oldp+63,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+137,(vlSelf->top__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+139,((1U & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__rdata
                              [0U]),32);
    bufp->fullCData(oldp+141,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+142,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+143,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+145,((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+146,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+147,((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+148,(((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                             | ((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                      | (3U == (0x7fU 
                                                & vlSelf->top__DOT__ifu0__DOT__inst_reg))))))));
    bufp->fullBit(oldp+149,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+150,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+151,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+152,((7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+153,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+154,((1U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+155,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+156,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+157,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+158,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+159,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+160,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+161,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+162,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+163,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+164,(((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+165,(vlSelf->top__DOT__data0__DOT__arvalid_in),2);
    bufp->fullCData(oldp+166,(vlSelf->top__DOT__data0__DOT__rvalid_out),2);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__rdata[0]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__rdata[1]),32);
    bufp->fullCData(oldp+169,(vlSelf->top__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+170,(vlSelf->top__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+171,(vlSelf->top__DOT____Vcellinp__data0__wstrb[0]),4);
    bufp->fullCData(oldp+172,(vlSelf->top__DOT____Vcellinp__data0__wstrb[1]),4);
    bufp->fullBit(oldp+173,(vlSelf->top__DOT__data0__DOT__awvalid_sram));
    bufp->fullBit(oldp+174,(vlSelf->top__DOT__data0__DOT__wvalid_sram));
    bufp->fullBit(oldp+175,(vlSelf->top__DOT__data0__DOT__arvalid_sram));
    bufp->fullBit(oldp+176,(vlSelf->top__DOT__data0__DOT__rready_sram));
    bufp->fullCData(oldp+177,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullCData(oldp+178,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+179,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+180,(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask),3);
    bufp->fullCData(oldp+181,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+182,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+183,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+184,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+185,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+186,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+187,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+188,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+189,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+190,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+191,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+192,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+193,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+194,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+195,((0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+196,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+197,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+198,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+199,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+200,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+201,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+202,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+203,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+204,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+205,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+206,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
    bufp->fullBit(oldp+207,(((IData)(vlSelf->top__DOT__ready_idu_to_ifu) 
                             & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U) 
                                         | (3U == (0x7fU 
                                                   & vlSelf->top__DOT__ifu0__DOT__inst_reg)))))))));
    bufp->fullSData(oldp+208,((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+209,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+210,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+211,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+212,(vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew));
    bufp->fullCData(oldp+213,(((1U == (IData)(vlSelf->top__DOT__memmask))
                                ? 1U : ((2U == (IData)(vlSelf->top__DOT__memmask))
                                         ? 2U : ((3U 
                                                  == (IData)(vlSelf->top__DOT__memmask))
                                                  ? 4U
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->top__DOT__memmask))
                                                   ? 8U
                                                   : 0U))))),4);
    bufp->fullBit(oldp+214,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U))));
    bufp->fullIData(oldp+215,(vlSelf->top__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+216,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+217,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+218,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+219,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__rdata
                                          [1U]))),32);
    bufp->fullIData(oldp+220,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__rdata
                                             [1U]))),32);
    bufp->fullCData(oldp+221,((0xffU & vlSelf->top__DOT__rdata
                               [1U])),8);
    bufp->fullSData(oldp+222,((0xffffU & vlSelf->top__DOT__rdata
                               [1U])),16);
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+223,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+226,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+228,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+230,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+231,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
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
    bufp->fullWData(oldp+232,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+237,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+239,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+241,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+243,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+245,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+246,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+247,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+248,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+249,(vlSelf->top__DOT__npc),32);
    bufp->fullIData(oldp+250,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+251,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+252,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+253,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+254,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullIData(oldp+255,(vlSelf->top__DOT__araddr[0]),32);
    bufp->fullIData(oldp+256,(vlSelf->top__DOT__araddr[1]),32);
    bufp->fullIData(oldp+257,(vlSelf->top__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+258,(vlSelf->top__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+259,(vlSelf->top__DOT__wdata[0]),32);
    bufp->fullIData(oldp+260,(vlSelf->top__DOT__wdata[1]),32);
    bufp->fullIData(oldp+261,(vlSelf->top__DOT____Vcellinp__data0__araddr[0]),32);
    bufp->fullIData(oldp+262,(vlSelf->top__DOT____Vcellinp__data0__araddr[1]),32);
    bufp->fullIData(oldp+263,(vlSelf->top__DOT____Vcellinp__data0__awaddr[0]),32);
    bufp->fullIData(oldp+264,(vlSelf->top__DOT____Vcellinp__data0__awaddr[1]),32);
    bufp->fullIData(oldp+265,(vlSelf->top__DOT____Vcellinp__data0__wdata[0]),32);
    bufp->fullIData(oldp+266,(vlSelf->top__DOT____Vcellinp__data0__wdata[1]),32);
    bufp->fullIData(oldp+267,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullIData(oldp+268,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+269,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullIData(oldp+270,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+271,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+272,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+273,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+274,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+275,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullIData(oldp+276,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+277,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+278,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+279,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+280,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+281,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+282,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+283,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+284,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+285,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+286,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+287,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullIData(oldp+288,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+289,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+290,(vlSelf->clk));
    bufp->fullBit(oldp+291,(vlSelf->rst));
    bufp->fullIData(oldp+292,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                     & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__grant) 
                                         & (- (IData)(
                                                      ((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                                                       & (0U 
                                                          == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))))) 
                                        >> 1U)))),32);
    bufp->fullIData(oldp+293,(2U),32);
    bufp->fullIData(oldp+294,(0U),32);
    bufp->fullBit(oldp+295,(vlSelf->top__DOT__data0__DOT__bvalid_sram));
    bufp->fullIData(oldp+296,(2U),32);
    bufp->fullIData(oldp+297,(4U),32);
    bufp->fullBit(oldp+298,(0U));
    bufp->fullIData(oldp+299,(3U),32);
    bufp->fullIData(oldp+300,(0x12491c4U),28);
    bufp->fullCData(oldp+301,(0U),3);
    bufp->fullIData(oldp+302,(7U),32);
    bufp->fullIData(oldp+303,(4U),32);
    bufp->fullIData(oldp+304,(1U),32);
    bufp->fullIData(oldp+305,(0x20U),32);
    bufp->fullIData(oldp+306,(0U),32);
    bufp->fullIData(oldp+307,(0x21U),32);
    bufp->fullIData(oldp+308,(2U),32);
    bufp->fullIData(oldp+309,(0x7ffffffcU),32);
    bufp->fullIData(oldp+310,(0xcU),32);
    bufp->fullQData(oldp+311,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+313,(0U),2);
    bufp->fullIData(oldp+314,(0xeU),32);
    bufp->fullIData(oldp+315,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp),32);
    bufp->fullIData(oldp+316,(8U),32);
    bufp->fullIData(oldp+317,(0x10U),32);
    bufp->fullIData(oldp+318,(0x23U),32);
}
