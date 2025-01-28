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
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+442,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+442,"rst", false,-1);
    tracep->declBit(c+172,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+292,"npc", false,-1, 31,0);
    tracep->declBus(c+95,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+173,"inst", false,-1, 31,0);
    tracep->declBit(c+293,"ifu_valid", false,-1);
    tracep->declBit(c+172,"ifu_arvalid", false,-1);
    tracep->declBit(c+443,"ifu_arready", false,-1);
    tracep->declBus(c+292,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+294,"ifu_rvalid", false,-1);
    tracep->declBit(c+172,"ifu_rready", false,-1);
    tracep->declBus(c+295,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+174,"reg_process", false,-1);
    tracep->declBus(c+175,"src1", false,-1, 4,0);
    tracep->declBus(c+176,"src2", false,-1, 4,0);
    tracep->declBus(c+177,"rd", false,-1, 4,0);
    tracep->declBus(c+178,"imm", false,-1, 31,0);
    tracep->declBit(c+179,"ebreaksig", false,-1);
    tracep->declBit(c+180,"mretsig", false,-1);
    tracep->declBit(c+181,"ecallsig", false,-1);
    tracep->declBit(c+182,"regew", false,-1);
    tracep->declBit(c+183,"memew", false,-1);
    tracep->declBit(c+184,"memer", false,-1);
    tracep->declBit(c+185,"muximm", false,-1);
    tracep->declBus(c+186,"func3", false,-1, 2,0);
    tracep->declBus(c+187,"muxsig", false,-1, 2,0);
    tracep->declBit(c+188,"func7", false,-1);
    tracep->declBit(c+189,"btypebranch", false,-1);
    tracep->declBit(c+190,"jalsig", false,-1);
    tracep->declBit(c+191,"jalrsig", false,-1);
    tracep->declBit(c+192,"auipcsig", false,-1);
    tracep->declBus(c+193,"aluop", false,-1, 1,0);
    tracep->declBit(c+194,"csrrw", false,-1);
    tracep->declBit(c+195,"csrrs", false,-1);
    tracep->declBit(c+293,"idu_valid", false,-1);
    tracep->declBus(c+196,"memmask", false,-1, 2,0);
    tracep->declBit(c+197,"memsextsig", false,-1);
    tracep->declBus(c+296,"regwrite", false,-1, 31,0);
    tracep->declBus(c+297,"regout1", false,-1, 31,0);
    tracep->declBus(c+298,"regout2", false,-1, 31,0);
    tracep->declBus(c+96,"mepc", false,-1, 31,0);
    tracep->declBus(c+97,"mtvec", false,-1, 31,0);
    tracep->declBit(c+172,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+299,"res", false,-1, 31,0);
    tracep->declBus(c+300,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+293,"exu_valid", false,-1);
    tracep->declBit(c+172,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+248,"memvalid", false,-1);
    tracep->declBus(c+198,"awvalid", false,-1, 1,0);
    tracep->declBus(c+198,"wvalid", false,-1, 1,0);
    tracep->declBus(c+199,"arvalid", false,-1, 1,0);
    tracep->declBus(c+200,"rready", false,-1, 1,0);
    tracep->declBus(c+201,"bready", false,-1, 1,0);
    tracep->declBus(c+79,"bvalid", false,-1, 1,0);
    tracep->declBus(c+301,"rvalid", false,-1, 1,0);
    tracep->declBus(c+80,"awready", false,-1, 1,0);
    tracep->declBus(c+81,"wready", false,-1, 1,0);
    tracep->declBus(c+444,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+302+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+304+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+306+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+308+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+202+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+310+i*1,"bresp", true,(i+0));
    }
    tracep->pushNamePrefix("data0 ");
    tracep->declBus(c+448,"NUM", false,-1, 31,0);
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBus(c+198,"awvalid", false,-1, 1,0);
    tracep->declBus(c+198,"wvalid", false,-1, 1,0);
    tracep->declBus(c+199,"arvalid", false,-1, 1,0);
    tracep->declBus(c+200,"rready", false,-1, 1,0);
    tracep->declBus(c+201,"bready", false,-1, 1,0);
    tracep->declBus(c+79,"bvalid", false,-1, 1,0);
    tracep->declBus(c+301,"rvalid", false,-1, 1,0);
    tracep->declBus(c+80,"awready", false,-1, 1,0);
    tracep->declBus(c+81,"wready", false,-1, 1,0);
    tracep->declBus(c+444,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+312+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+314+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+316+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+318+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+204+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+320+i*1,"bresp", true,(i+0));
    }
    tracep->declBus(c+449,"DEVICE", false,-1, 31,0);
    tracep->declBus(c+198,"awvalid_in", false,-1, 1,0);
    tracep->declBus(c+198,"wvalid_in", false,-1, 1,0);
    tracep->declBus(c+199,"arvalid_in", false,-1, 1,0);
    tracep->declBus(c+200,"rready_in", false,-1, 1,0);
    tracep->declBus(c+201,"bready_in", false,-1, 1,0);
    tracep->declBus(c+301,"rvalid_out", false,-1, 1,0);
    tracep->declBus(c+80,"awready_out", false,-1, 1,0);
    tracep->declBus(c+81,"wready_out", false,-1, 1,0);
    tracep->declBus(c+444,"arready_out", false,-1, 1,0);
    tracep->declBus(c+79,"bvalid_out", false,-1, 1,0);
    tracep->declBit(c+206,"awvalid_from_arbiter", false,-1);
    tracep->declBit(c+207,"wvalid_from_arbiter", false,-1);
    tracep->declBit(c+208,"arvalid_from_arbiter", false,-1);
    tracep->declBit(c+209,"rready_from_arbiter", false,-1);
    tracep->declBit(c+210,"bready_from_arbiter", false,-1);
    tracep->declBit(c+322,"rvalid_from_arbiter", false,-1);
    tracep->declBit(c+82,"awready_from_arbiter", false,-1);
    tracep->declBit(c+83,"wready_from_arbiter", false,-1);
    tracep->declBit(c+249,"arready_from_arbiter", false,-1);
    tracep->declBit(c+323,"bvalid_from_arbiter", false,-1);
    tracep->declBus(c+324,"awaddr_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+325,"araddr_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+326,"wdata_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+327,"rdata_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+211,"wstrb_from_arbiter", false,-1, 3,0);
    tracep->declBit(c+328,"bresp_from_arbiter", false,-1);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+329+i*1,"awvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+331+i*1,"wvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+333+i*1,"arvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+335+i*1,"rready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+337+i*1,"bready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+37+i*1,"rvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+39+i*1,"awready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+41+i*1,"wready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+43+i*1,"arready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+1+i*1,"bvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+339+i*1,"awaddr_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+341+i*1,"araddr_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+343+i*1,"wdata_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+345+i*1,"rdata_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+347+i*1,"wstrb_from_xbar", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+45+i*1,"bresp_from_xbar", true,(i+0));
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+448,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBus(c+198,"awvalid", false,-1, 1,0);
    tracep->declBus(c+198,"wvalid", false,-1, 1,0);
    tracep->declBus(c+199,"arvalid", false,-1, 1,0);
    tracep->declBus(c+200,"rready", false,-1, 1,0);
    tracep->declBus(c+201,"bready", false,-1, 1,0);
    tracep->declBus(c+79,"bvalid", false,-1, 1,0);
    tracep->declBus(c+301,"rvalid", false,-1, 1,0);
    tracep->declBus(c+80,"awready", false,-1, 1,0);
    tracep->declBus(c+81,"wready", false,-1, 1,0);
    tracep->declBus(c+444,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+349+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+351+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+353+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+212+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+355+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+357+i*1,"bresp", true,(i+0));
    }
    tracep->declBit(c+206,"awvalid_out", false,-1);
    tracep->declBit(c+207,"wvalid_out", false,-1);
    tracep->declBit(c+208,"arvalid_out", false,-1);
    tracep->declBit(c+209,"rready_out", false,-1);
    tracep->declBit(c+210,"bready_out", false,-1);
    tracep->declBit(c+323,"bvalid_in", false,-1);
    tracep->declBit(c+322,"rvalid_in", false,-1);
    tracep->declBit(c+82,"awready_in", false,-1);
    tracep->declBit(c+83,"wready_in", false,-1);
    tracep->declBit(c+249,"arready_in", false,-1);
    tracep->declBus(c+325,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+324,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+326,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+211,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+327,"rdata_in", false,-1, 31,0);
    tracep->declBit(c+328,"bresp_in", false,-1);
    tracep->declBit(c+47,"busy", false,-1);
    tracep->declBus(c+48,"giant", false,-1, 1,0);
    tracep->declBus(c+49,"i", false,-1, 31,0);
    tracep->declBus(c+324,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+326,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+325,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+211,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+450,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+359,"awvalid", false,-1);
    tracep->declBit(c+50,"awready", false,-1);
    tracep->declBus(c+360,"awaddr", false,-1, 31,0);
    tracep->declBit(c+361,"wvalid", false,-1);
    tracep->declBit(c+50,"wready", false,-1);
    tracep->declBus(c+362,"wdata", false,-1, 31,0);
    tracep->declBus(c+363,"wstrb", false,-1, 3,0);
    tracep->declBit(c+451,"bvalid", false,-1);
    tracep->declBit(c+364,"bready", false,-1);
    tracep->declBit(c+51,"bresp", false,-1);
    tracep->declBit(c+365,"arvalid", false,-1);
    tracep->declBit(c+50,"arready", false,-1);
    tracep->declBus(c+366,"araddr", false,-1, 31,0);
    tracep->declBit(c+367,"rready", false,-1);
    tracep->declBit(c+52,"rvalid", false,-1);
    tracep->declBus(c+368,"rdata", false,-1, 31,0);
    tracep->declBus(c+53,"state", false,-1, 1,0);
    tracep->declBus(c+54,"random_delay", false,-1, 3,0);
    tracep->declBit(c+55,"busy", false,-1);
    tracep->declBus(c+56,"random_count", false,-1, 3,0);
    tracep->declBus(c+369,"memmask", false,-1, 2,0);
    tracep->declBus(c+368,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("lsfr0 ");
    tracep->declBus(c+452,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+453,"reset", false,-1);
    tracep->declBus(c+54,"out", false,-1, 3,0);
    tracep->declBus(c+57,"random_num", false,-1, 7,0);
    tracep->declBit(c+58,"feedback", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+452,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+452,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+454,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+369,"out", false,-1, 2,0);
    tracep->declBus(c+363,"key", false,-1, 3,0);
    tracep->declBus(c+455,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+452,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+452,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+454,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+449,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+369,"out", false,-1, 2,0);
    tracep->declBus(c+363,"key", false,-1, 3,0);
    tracep->declBus(c+456,"default_out", false,-1, 2,0);
    tracep->declBus(c+455,"lut", false,-1, 27,0);
    tracep->declBus(c+457,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+370,"lut_out", false,-1, 2,0);
    tracep->declBit(c+371,"hit", false,-1);
    tracep->declBus(c+458,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("uart0 ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+372,"awvalid", false,-1);
    tracep->declBit(c+59,"awready", false,-1);
    tracep->declBus(c+373,"awaddr", false,-1, 31,0);
    tracep->declBit(c+374,"wvalid", false,-1);
    tracep->declBit(c+59,"wready", false,-1);
    tracep->declBus(c+375,"wdata", false,-1, 31,0);
    tracep->declBus(c+376,"wstrb", false,-1, 3,0);
    tracep->declBit(c+459,"bvalid", false,-1);
    tracep->declBit(c+377,"bready", false,-1);
    tracep->declBit(c+60,"bresp", false,-1);
    tracep->declBit(c+378,"arvalid", false,-1);
    tracep->declBit(c+460,"arready", false,-1);
    tracep->declBus(c+379,"araddr", false,-1, 31,0);
    tracep->declBit(c+380,"rready", false,-1);
    tracep->declBit(c+453,"rvalid", false,-1);
    tracep->declBus(c+449,"rdata", false,-1, 31,0);
    tracep->declBit(c+60,"state", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("xbar ");
    tracep->declBit(c+206,"m_awvalid", false,-1);
    tracep->declBit(c+82,"m_awready", false,-1);
    tracep->declBus(c+324,"m_awaddr", false,-1, 31,0);
    tracep->declBit(c+207,"m_wvalid", false,-1);
    tracep->declBit(c+83,"m_wready", false,-1);
    tracep->declBus(c+326,"m_wdata", false,-1, 31,0);
    tracep->declBus(c+211,"m_wstrb", false,-1, 3,0);
    tracep->declBit(c+323,"m_bvalid", false,-1);
    tracep->declBit(c+210,"m_bready", false,-1);
    tracep->declBit(c+328,"m_bresp", false,-1);
    tracep->declBit(c+208,"m_arvalid", false,-1);
    tracep->declBit(c+249,"m_arready", false,-1);
    tracep->declBus(c+325,"m_araddr", false,-1, 31,0);
    tracep->declBit(c+322,"m_rvalid", false,-1);
    tracep->declBit(c+209,"m_rready", false,-1);
    tracep->declBus(c+327,"m_rdata", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+381+i*1,"s_awvalid", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+61+i*1,"s_awready", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+383+i*1,"s_awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+385+i*1,"s_wvalid", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+63+i*1,"s_wready", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+387+i*1,"s_wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+389+i*1,"s_wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+15+i*1,"s_bvalid", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+391+i*1,"s_bready", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+65+i*1,"s_bresp", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+393+i*1,"s_arvalid", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+214+i*1,"s_arready", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+395+i*1,"s_araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+67+i*1,"s_rvalid", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+397+i*1,"s_rready", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+399+i*1,"s_rdata", true,(i+0), 31,0);
    }
    tracep->declBit(c+401,"sig_sram", false,-1);
    tracep->declBit(c+402,"sig_urt", false,-1);
    tracep->declBit(c+403,"test", false,-1);
    tracep->declBit(c+84,"m_awready_urt", false,-1);
    tracep->declBit(c+85,"m_wready_urt", false,-1);
    tracep->declBit(c+404,"m_bvalid_urt", false,-1);
    tracep->declBit(c+86,"m_bresp_urt", false,-1);
    tracep->declBit(c+250,"m_arready_urt", false,-1);
    tracep->declBit(c+87,"m_rvalid_urt", false,-1);
    tracep->declBus(c+405,"m_rdata_urt", false,-1, 31,0);
    tracep->declBit(c+88,"m_awready_sram", false,-1);
    tracep->declBit(c+89,"m_wready_sram", false,-1);
    tracep->declBit(c+406,"m_bvalid_sram", false,-1);
    tracep->declBit(c+90,"m_bresp_sram", false,-1);
    tracep->declBit(c+251,"m_arready_sram", false,-1);
    tracep->declBit(c+91,"m_rvalid_sram", false,-1);
    tracep->declBus(c+407,"m_rdata_sram", false,-1, 31,0);
    tracep->pushNamePrefix("mux ");
    tracep->declBus(c+461,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+462,"KEY_LEN", false,-1, 31,0);
    tracep->declQuad(c+463,"tbl", false,-1, 63,0);
    tracep->declBus(c+408,"data", false,-1, 31,0);
    tracep->declBus(c+402,"out", false,-1, 0,0);
    tracep->pushNamePrefix("compare_loop[0] ");
    tracep->declBus(c+465,"upper_bound", false,-1, 31,0);
    tracep->declBus(c+466,"lower_bound", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("sram_input ");
    tracep->declBit(c+206,"awvalid", false,-1);
    tracep->declBus(c+324,"awaddr", false,-1, 31,0);
    tracep->declBit(c+207,"wvalid", false,-1);
    tracep->declBus(c+326,"wdata", false,-1, 31,0);
    tracep->declBus(c+211,"wstrb", false,-1, 3,0);
    tracep->declBit(c+210,"bready", false,-1);
    tracep->declBit(c+208,"arvalid", false,-1);
    tracep->declBus(c+325,"araddr", false,-1, 31,0);
    tracep->declBit(c+209,"rready", false,-1);
    tracep->declBit(c+401,"sig", false,-1);
    tracep->declBit(c+252,"awvalid_out", false,-1);
    tracep->declBus(c+409,"awaddr_out", false,-1, 31,0);
    tracep->declBit(c+253,"wvalid_out", false,-1);
    tracep->declBus(c+410,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+254,"wstrb_out", false,-1, 3,0);
    tracep->declBit(c+255,"bready_out", false,-1);
    tracep->declBit(c+256,"arvalid_out", false,-1);
    tracep->declBus(c+411,"araddr_out", false,-1, 31,0);
    tracep->declBit(c+257,"rready_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sram_output ");
    tracep->declBit(c+88,"awready", false,-1);
    tracep->declBit(c+89,"wready", false,-1);
    tracep->declBit(c+406,"bvalid", false,-1);
    tracep->declBit(c+90,"bresp", false,-1);
    tracep->declBit(c+251,"arready", false,-1);
    tracep->declBit(c+91,"rvalid", false,-1);
    tracep->declBus(c+407,"rdata", false,-1, 31,0);
    tracep->declBit(c+401,"sig", false,-1);
    tracep->declBit(c+69,"awready_in", false,-1);
    tracep->declBit(c+70,"wready_in", false,-1);
    tracep->declBit(c+17,"bvalid_in", false,-1);
    tracep->declBit(c+71,"bresp_in", false,-1);
    tracep->declBit(c+216,"arready_in", false,-1);
    tracep->declBit(c+72,"rvalid_in", false,-1);
    tracep->declBus(c+412,"rdata_in", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("urt_input ");
    tracep->declBit(c+206,"awvalid", false,-1);
    tracep->declBus(c+324,"awaddr", false,-1, 31,0);
    tracep->declBit(c+207,"wvalid", false,-1);
    tracep->declBus(c+326,"wdata", false,-1, 31,0);
    tracep->declBus(c+211,"wstrb", false,-1, 3,0);
    tracep->declBit(c+210,"bready", false,-1);
    tracep->declBit(c+208,"arvalid", false,-1);
    tracep->declBus(c+325,"araddr", false,-1, 31,0);
    tracep->declBit(c+209,"rready", false,-1);
    tracep->declBit(c+402,"sig", false,-1);
    tracep->declBit(c+258,"awvalid_out", false,-1);
    tracep->declBus(c+413,"awaddr_out", false,-1, 31,0);
    tracep->declBit(c+259,"wvalid_out", false,-1);
    tracep->declBus(c+414,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+260,"wstrb_out", false,-1, 3,0);
    tracep->declBit(c+261,"bready_out", false,-1);
    tracep->declBit(c+262,"arvalid_out", false,-1);
    tracep->declBus(c+415,"araddr_out", false,-1, 31,0);
    tracep->declBit(c+263,"rready_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("urt_output ");
    tracep->declBit(c+84,"awready", false,-1);
    tracep->declBit(c+85,"wready", false,-1);
    tracep->declBit(c+404,"bvalid", false,-1);
    tracep->declBit(c+86,"bresp", false,-1);
    tracep->declBit(c+250,"arready", false,-1);
    tracep->declBit(c+87,"rvalid", false,-1);
    tracep->declBus(c+405,"rdata", false,-1, 31,0);
    tracep->declBit(c+402,"sig", false,-1);
    tracep->declBit(c+73,"awready_in", false,-1);
    tracep->declBit(c+74,"wready_in", false,-1);
    tracep->declBit(c+18,"bvalid_in", false,-1);
    tracep->declBit(c+75,"bresp_in", false,-1);
    tracep->declBit(c+217,"arready_in", false,-1);
    tracep->declBit(c+76,"rvalid_in", false,-1);
    tracep->declBus(c+416,"rdata_in", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+186,"func3", false,-1, 2,0);
    tracep->declBit(c+189,"btypebranch", false,-1);
    tracep->declBit(c+188,"func7", false,-1);
    tracep->declBus(c+193,"aluop", false,-1, 1,0);
    tracep->declBit(c+191,"jalrsig", false,-1);
    tracep->declBit(c+190,"jalsig", false,-1);
    tracep->declBus(c+178,"imm", false,-1, 31,0);
    tracep->declBit(c+185,"muximm", false,-1);
    tracep->declBus(c+297,"regout1", false,-1, 31,0);
    tracep->declBus(c+298,"regout2", false,-1, 31,0);
    tracep->declBus(c+95,"pc", false,-1, 31,0);
    tracep->declBit(c+192,"auipcsig", false,-1);
    tracep->declBit(c+180,"mretsig", false,-1);
    tracep->declBit(c+181,"ecallsig", false,-1);
    tracep->declBus(c+97,"mtvec", false,-1, 31,0);
    tracep->declBus(c+96,"mepc", false,-1, 31,0);
    tracep->declBit(c+293,"valid_from", false,-1);
    tracep->declBit(c+172,"ready_from", false,-1);
    tracep->declBus(c+299,"res", false,-1, 31,0);
    tracep->declBus(c+292,"npc", false,-1, 31,0);
    tracep->declBus(c+300,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+293,"valid_to", false,-1);
    tracep->declBit(c+172,"ready_to", false,-1);
    tracep->declBus(c+98,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+417,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+218,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+418,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+419,"zero", false,-1);
    tracep->declBit(c+420,"signal", false,-1);
    tracep->declBit(c+421,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+297,"A", false,-1, 31,0);
    tracep->declBus(c+418,"B", false,-1, 31,0);
    tracep->declBus(c+218,"op", false,-1, 4,0);
    tracep->declBus(c+299,"res", false,-1, 31,0);
    tracep->declBit(c+419,"zero", false,-1);
    tracep->declBit(c+420,"signal", false,-1);
    tracep->declBit(c+421,"carry", false,-1);
    tracep->declBit(c+219,"addsig", false,-1);
    tracep->declBit(c+220,"logsig", false,-1);
    tracep->declBit(c+221,"shfsig", false,-1);
    tracep->declBit(c+222,"sltsig", false,-1);
    tracep->declBit(c+421,"carry_tmp", false,-1);
    tracep->declBit(c+223,"type_I", false,-1);
    tracep->declBus(c+422,"logres", false,-1, 31,0);
    tracep->declBus(c+423,"addres", false,-1, 31,0);
    tracep->declBit(c+424,"addzero", false,-1);
    tracep->declBus(c+425,"shfres", false,-1, 31,0);
    tracep->declBus(c+426,"sltres", false,-1, 31,0);
    tracep->declBus(c+297,"A_s", false,-1, 31,0);
    tracep->declBus(c+418,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+186,"func3", false,-1, 2,0);
    tracep->declBit(c+188,"func7", false,-1);
    tracep->declBus(c+193,"aluop", false,-1, 1,0);
    tracep->declBit(c+191,"jalrsig", false,-1);
    tracep->declBus(c+218,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+223,"type_I", false,-1);
    tracep->declBit(c+224,"type_B", false,-1);
    tracep->declBit(c+225,"type_R", false,-1);
    tracep->declBit(c+226,"addsig", false,-1);
    tracep->declBus(c+227,"branchop", false,-1, 3,0);
    tracep->declBus(c+228,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+189,"btypebranch", false,-1);
    tracep->declBus(c+186,"func3", false,-1, 2,0);
    tracep->declBit(c+419,"zero", false,-1);
    tracep->declBit(c+420,"signal", false,-1);
    tracep->declBit(c+421,"carry", false,-1);
    tracep->declBus(c+299,"res", false,-1, 31,0);
    tracep->declBus(c+98,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+417,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+190,"jalsig", false,-1);
    tracep->declBit(c+191,"jalrsig", false,-1);
    tracep->declBit(c+192,"auipcsig", false,-1);
    tracep->declBit(c+180,"mretsig", false,-1);
    tracep->declBit(c+181,"ecallsig", false,-1);
    tracep->declBus(c+97,"mtvec", false,-1, 31,0);
    tracep->declBus(c+96,"mepc", false,-1, 31,0);
    tracep->declBus(c+292,"npc", false,-1, 31,0);
    tracep->declBus(c+300,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+448,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+461,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+462,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+418,"out", false,-1, 31,0);
    tracep->declBus(c+185,"key", false,-1, 0,0);
    tracep->declArray(c+264,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+448,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+461,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+462,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+449,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+418,"out", false,-1, 31,0);
    tracep->declBus(c+185,"key", false,-1, 0,0);
    tracep->declBus(c+467,"default_out", false,-1, 31,0);
    tracep->declArray(c+264,"lut", false,-1, 65,0);
    tracep->declBus(c+468,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+267+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+19+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+271+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+427,"lut_out", false,-1, 31,0);
    tracep->declBit(c+229,"hit", false,-1);
    tracep->declBus(c+469,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+95,"pc", false,-1, 31,0);
    tracep->declBus(c+98,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+95,"pc", false,-1, 31,0);
    tracep->declBus(c+178,"imm", false,-1, 31,0);
    tracep->declBus(c+417,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+173,"inst", false,-1, 31,0);
    tracep->declBit(c+293,"valid_from", false,-1);
    tracep->declBit(c+172,"ready_from", false,-1);
    tracep->declBit(c+179,"ebreaksig", false,-1);
    tracep->declBit(c+181,"ecallsig", false,-1);
    tracep->declBit(c+180,"mretsig", false,-1);
    tracep->declBus(c+178,"imm", false,-1, 31,0);
    tracep->declBus(c+186,"func3", false,-1, 2,0);
    tracep->declBit(c+188,"func7", false,-1);
    tracep->declBus(c+175,"src1", false,-1, 4,0);
    tracep->declBus(c+176,"src2", false,-1, 4,0);
    tracep->declBus(c+177,"rd", false,-1, 4,0);
    tracep->declBit(c+183,"memew", false,-1);
    tracep->declBus(c+187,"muxsig", false,-1, 2,0);
    tracep->declBit(c+184,"memer", false,-1);
    tracep->declBit(c+182,"regew", false,-1);
    tracep->declBit(c+185,"muximm", false,-1);
    tracep->declBit(c+189,"btypebranch", false,-1);
    tracep->declBit(c+191,"jalrsig", false,-1);
    tracep->declBit(c+190,"jalsig", false,-1);
    tracep->declBus(c+193,"aluop", false,-1, 1,0);
    tracep->declBit(c+192,"auipcsig", false,-1);
    tracep->declBit(c+194,"csrrw", false,-1);
    tracep->declBit(c+195,"csrrs", false,-1);
    tracep->declBit(c+293,"valid_to", false,-1);
    tracep->declBit(c+172,"ready_to", false,-1);
    tracep->declBus(c+196,"memmask", false,-1, 2,0);
    tracep->declBit(c+197,"memsextsig", false,-1);
    tracep->declBit(c+179,"ebreak", false,-1);
    tracep->declBit(c+181,"ecall", false,-1);
    tracep->declBit(c+180,"mret", false,-1);
    tracep->declBus(c+186,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+188,"func7bridge", false,-1);
    tracep->declBus(c+230,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+173,"inst", false,-1, 31,0);
    tracep->declBit(c+179,"ebreaksig", false,-1);
    tracep->declBit(c+181,"ecallsig", false,-1);
    tracep->declBit(c+180,"mretsig", false,-1);
    tracep->declBus(c+178,"imm", false,-1, 31,0);
    tracep->declBus(c+230,"opcode", false,-1, 6,0);
    tracep->declBus(c+186,"func3", false,-1, 2,0);
    tracep->declBit(c+188,"func7", false,-1);
    tracep->declBus(c+175,"src1", false,-1, 4,0);
    tracep->declBus(c+176,"src2", false,-1, 4,0);
    tracep->declBus(c+177,"rd", false,-1, 4,0);
    tracep->declBus(c+196,"memmask", false,-1, 2,0);
    tracep->declBit(c+197,"memsextsig", false,-1);
    tracep->declBit(c+231,"type_I", false,-1);
    tracep->declBit(c+232,"type_R", false,-1);
    tracep->declBit(c+233,"type_U", false,-1);
    tracep->declBit(c+183,"type_S", false,-1);
    tracep->declBit(c+190,"type_J", false,-1);
    tracep->declBit(c+189,"type_B", false,-1);
    tracep->declBus(c+234,"I_imm", false,-1, 31,0);
    tracep->declBus(c+235,"U_imm", false,-1, 31,0);
    tracep->declBus(c+236,"S_imm", false,-1, 31,0);
    tracep->declBus(c+237,"J_imm", false,-1, 31,0);
    tracep->declBus(c+238,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+230,"opcode", false,-1, 6,0);
    tracep->declBus(c+186,"func3", false,-1, 2,0);
    tracep->declBit(c+188,"func7", false,-1);
    tracep->declBit(c+179,"ebreaksig", false,-1);
    tracep->declBit(c+181,"ecallsig", false,-1);
    tracep->declBit(c+180,"mretsig", false,-1);
    tracep->declBit(c+183,"memew", false,-1);
    tracep->declBus(c+187,"muxsig", false,-1, 2,0);
    tracep->declBit(c+184,"memer", false,-1);
    tracep->declBit(c+182,"regew", false,-1);
    tracep->declBit(c+185,"muximm", false,-1);
    tracep->declBit(c+189,"btypebranch", false,-1);
    tracep->declBit(c+191,"jalrsig", false,-1);
    tracep->declBit(c+190,"jalsig", false,-1);
    tracep->declBus(c+193,"aluop", false,-1, 1,0);
    tracep->declBit(c+192,"auipcsig", false,-1);
    tracep->declBit(c+194,"csrrw", false,-1);
    tracep->declBit(c+195,"csrrs", false,-1);
    tracep->declBit(c+231,"type_I", false,-1);
    tracep->declBit(c+232,"type_R", false,-1);
    tracep->declBit(c+233,"type_U", false,-1);
    tracep->declBit(c+183,"type_S", false,-1);
    tracep->declBit(c+190,"type_J", false,-1);
    tracep->declBit(c+189,"type_B", false,-1);
    tracep->declBit(c+184,"load", false,-1);
    tracep->declBit(c+183,"store", false,-1);
    tracep->declBit(c+239,"regwritepc", false,-1);
    tracep->declBit(c+184,"regwritemem", false,-1);
    tracep->declBit(c+240,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+442,"rst", false,-1);
    tracep->declBus(c+292,"npc", false,-1, 31,0);
    tracep->declBit(c+172,"ready", false,-1);
    tracep->declBus(c+95,"pc", false,-1, 31,0);
    tracep->declBus(c+173,"inst", false,-1, 31,0);
    tracep->declBit(c+293,"valid", false,-1);
    tracep->declBit(c+174,"regprocess", false,-1);
    tracep->declBit(c+172,"arvalid", false,-1);
    tracep->declBit(c+443,"arready", false,-1);
    tracep->declBus(c+292,"araddr", false,-1, 31,0);
    tracep->declBit(c+294,"rvalid", false,-1);
    tracep->declBit(c+172,"rready", false,-1);
    tracep->declBus(c+295,"rdata", false,-1, 31,0);
    tracep->declBus(c+95,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+294,"infetch_ready", false,-1);
    tracep->declBus(c+241,"state", false,-1, 1,0);
    tracep->declBus(c+173,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBus(c+292,"npc", false,-1, 31,0);
    tracep->declBit(c+442,"rst", false,-1);
    tracep->declBit(c+294,"ready_from", false,-1);
    tracep->declBus(c+95,"pcout", false,-1, 31,0);
    tracep->declBus(c+470,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+442,"rst", false,-1);
    tracep->declBit(c+273,"ew", false,-1);
    tracep->declBus(c+177,"addr", false,-1, 4,0);
    tracep->declBus(c+175,"src1", false,-1, 4,0);
    tracep->declBus(c+176,"src2", false,-1, 4,0);
    tracep->declBus(c+242,"csr", false,-1, 11,0);
    tracep->declBus(c+296,"data", false,-1, 31,0);
    tracep->declBit(c+194,"csrrw", false,-1);
    tracep->declBit(c+195,"csrrs", false,-1);
    tracep->declBit(c+181,"ecallsig", false,-1);
    tracep->declBit(c+293,"valid", false,-1);
    tracep->declBus(c+297,"regout1", false,-1, 31,0);
    tracep->declBus(c+298,"regout2", false,-1, 31,0);
    tracep->declBus(c+96,"mepc", false,-1, 31,0);
    tracep->declBus(c+97,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+99+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+131+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+243,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+428,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+452,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+471,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+448,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+243,"out", false,-1, 1,0);
    tracep->declBus(c+242,"key", false,-1, 11,0);
    tracep->declQuad(c+472,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+452,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+471,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+448,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+449,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+243,"out", false,-1, 1,0);
    tracep->declBus(c+242,"key", false,-1, 11,0);
    tracep->declBus(c+474,"default_out", false,-1, 1,0);
    tracep->declQuad(c+472,"lut", false,-1, 55,0);
    tracep->declBus(c+475,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+21+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+25+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+29+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+244,"lut_out", false,-1, 1,0);
    tracep->declBit(c+245,"hit", false,-1);
    tracep->declBus(c+458,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBit(c+442,"rst", false,-1);
    tracep->declBit(c+274,"ew", false,-1);
    tracep->declBit(c+194,"csrrw", false,-1);
    tracep->declBit(c+195,"csrrs", false,-1);
    tracep->declBit(c+181,"ecall", false,-1);
    tracep->declBus(c+243,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+177,"addr", false,-1, 4,0);
    tracep->declBus(c+428,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+135+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+167+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+171,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+441,"clk", false,-1);
    tracep->declBus(c+299,"res", false,-1, 31,0);
    tracep->declBus(c+298,"regout2", false,-1, 31,0);
    tracep->declBit(c+183,"memew", false,-1);
    tracep->declBit(c+184,"memer", false,-1);
    tracep->declBus(c+178,"imm", false,-1, 31,0);
    tracep->declBus(c+300,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+187,"muxsig", false,-1, 2,0);
    tracep->declBit(c+293,"valid_from", false,-1);
    tracep->declBus(c+196,"memmask", false,-1, 2,0);
    tracep->declBit(c+197,"memsextsig", false,-1);
    tracep->declBus(c+296,"regwrite", false,-1, 31,0);
    tracep->declBit(c+172,"ready_to", false,-1);
    tracep->declBit(c+248,"memvalid", false,-1);
    tracep->declBit(c+246,"awvalid", false,-1);
    tracep->declBit(c+92,"awready", false,-1);
    tracep->declBus(c+299,"awaddr", false,-1, 31,0);
    tracep->declBit(c+246,"wvalid", false,-1);
    tracep->declBit(c+93,"wready", false,-1);
    tracep->declBus(c+298,"wdata", false,-1, 31,0);
    tracep->declBus(c+247,"wstrb", false,-1, 3,0);
    tracep->declBit(c+94,"bvalid", false,-1);
    tracep->declBit(c+183,"bready", false,-1);
    tracep->declBit(c+429,"bresp", false,-1);
    tracep->declBit(c+445,"arvalid", false,-1);
    tracep->declBit(c+446,"arready", false,-1);
    tracep->declBus(c+299,"araddr", false,-1, 31,0);
    tracep->declBit(c+430,"rvalid", false,-1);
    tracep->declBit(c+184,"rready", false,-1);
    tracep->declBus(c+431,"rdata", false,-1, 31,0);
    tracep->declBus(c+432,"memread", false,-1, 31,0);
    tracep->declBit(c+77,"bresp_get", false,-1);
    tracep->declBit(c+78,"rvalid_get", false,-1);
    tracep->declBit(c+447,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+431,"data", false,-1, 31,0);
    tracep->declBus(c+196,"memmask", false,-1, 2,0);
    tracep->declBit(c+197,"memsextsig", false,-1);
    tracep->declBus(c+432,"read", false,-1, 31,0);
    tracep->declBus(c+433,"read_u", false,-1, 31,0);
    tracep->declBus(c+434,"read_s", false,-1, 31,0);
    tracep->declBus(c+435,"read_sb", false,-1, 31,0);
    tracep->declBus(c+436,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+476,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+462,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+437,"input_number", false,-1, 7,0);
    tracep->declBus(c+435,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+477,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+462,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+438,"input_number", false,-1, 15,0);
    tracep->declBus(c+436,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+452,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+454,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+462,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+296,"out", false,-1, 31,0);
    tracep->declBus(c+187,"key", false,-1, 2,0);
    tracep->declBus(c+449,"default_out", false,-1, 31,0);
    tracep->declArray(c+275,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+452,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+454,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+462,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+461,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+296,"out", false,-1, 31,0);
    tracep->declBus(c+187,"key", false,-1, 2,0);
    tracep->declBus(c+449,"default_out", false,-1, 31,0);
    tracep->declArray(c+275,"lut", false,-1, 139,0);
    tracep->declBus(c+478,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+280+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+33+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+288+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+439,"lut_out", false,-1, 31,0);
    tracep->declBit(c+440,"hit", false,-1);
    tracep->declBus(c+458,"i", false,-1, 31,0);
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
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[0]));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[1]));
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[0]));
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[1]));
    bufp->fullBit(oldp+17,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                           [0U]));
    bufp->fullBit(oldp+18,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                           [1U]));
    bufp->fullBit(oldp+19,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+20,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullSData(oldp+21,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+22,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+23,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+24,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+25,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+26,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+27,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+28,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+29,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+30,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+31,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+32,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+33,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+34,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+35,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullBit(oldp+37,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[0]));
    bufp->fullBit(oldp+38,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[1]));
    bufp->fullBit(oldp+39,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[0]));
    bufp->fullBit(oldp+40,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[1]));
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[0]));
    bufp->fullBit(oldp+42,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[1]));
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[0]));
    bufp->fullBit(oldp+44,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[1]));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[0]));
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[1]));
    bufp->fullBit(oldp+47,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+48,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+50,(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                            & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
    bufp->fullBit(oldp+51,((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullBit(oldp+52,((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullCData(oldp+53,(vlSelf->top__DOT__data0__DOT__mem0__DOT__state),2);
    bufp->fullCData(oldp+54,((0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))),4);
    bufp->fullBit(oldp+55,(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy));
    bufp->fullCData(oldp+56,(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count),4);
    bufp->fullCData(oldp+57,(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num),8);
    bufp->fullBit(oldp+58,((1U & VL_REDXOR_8((0xb8U 
                                              & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))))));
    bufp->fullBit(oldp+59,((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__uart0__DOT__state)))));
    bufp->fullBit(oldp+60,(vlSelf->top__DOT__data0__DOT__uart0__DOT__state));
    bufp->fullBit(oldp+61,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[0]));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[1]));
    bufp->fullBit(oldp+63,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[0]));
    bufp->fullBit(oldp+64,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[1]));
    bufp->fullBit(oldp+65,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[0]));
    bufp->fullBit(oldp+66,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[1]));
    bufp->fullBit(oldp+67,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[0]));
    bufp->fullBit(oldp+68,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[1]));
    bufp->fullBit(oldp+69,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                           [0U]));
    bufp->fullBit(oldp+70,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                           [0U]));
    bufp->fullBit(oldp+71,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                           [0U]));
    bufp->fullBit(oldp+72,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                           [0U]));
    bufp->fullBit(oldp+73,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                           [1U]));
    bufp->fullBit(oldp+74,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                           [1U]));
    bufp->fullBit(oldp+75,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                           [1U]));
    bufp->fullBit(oldp+76,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                           [1U]));
    bufp->fullBit(oldp+77,(vlSelf->top__DOT__wbu0__DOT__bresp_get));
    bufp->fullBit(oldp+78,(vlSelf->top__DOT__wbu0__DOT__rvalid_get));
    bufp->fullCData(oldp+79,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                              & (- (IData)((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                             [0U]) 
                                            | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                               [1U] 
                                               & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))))),2);
    bufp->fullCData(oldp+80,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                              & (- (IData)((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                             [0U]) 
                                            | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                               [1U] 
                                               & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))))),2);
    bufp->fullCData(oldp+81,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                              & (- (IData)((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                             [0U]) 
                                            | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt) 
                                               & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                               [1U])))))),2);
    bufp->fullBit(oldp+82,((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                             [0U]) | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                      [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))));
    bufp->fullBit(oldp+83,((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                             [0U]) | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt) 
                                      & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                      [1U]))));
    bufp->fullBit(oldp+84,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                            [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullBit(oldp+85,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt) 
                            & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                            [1U])));
    bufp->fullBit(oldp+86,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                            [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullBit(oldp+87,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                            [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullBit(oldp+88,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                            & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                            [0U])));
    bufp->fullBit(oldp+89,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                            & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                            [0U])));
    bufp->fullBit(oldp+90,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                            & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                            [0U])));
    bufp->fullBit(oldp+91,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                            & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                            [0U])));
    bufp->fullBit(oldp+92,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                  [0U]) 
                                                 | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                    [1U] 
                                                    & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))))) 
                                  >> 1U))));
    bufp->fullBit(oldp+93,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                  [0U]) 
                                                 | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt) 
                                                    & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                    [1U]))))) 
                                  >> 1U))));
    bufp->fullBit(oldp+94,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                  [0U]) 
                                                 | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                    [1U] 
                                                    & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))))) 
                                  >> 1U))));
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [2U]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT__rf_csr
                             [1U]),32);
    bufp->fullIData(oldp+98,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+172,(vlSelf->top__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+174,((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+175,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+176,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+177,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+179,((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+180,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+181,((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+182,(((3U != (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))));
    bufp->fullBit(oldp+183,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+184,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+185,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+186,((7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+187,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+188,((1U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+189,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+190,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+191,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+192,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+193,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+194,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+195,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+196,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+197,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+198,(((IData)(vlSelf->top__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+199,(vlSelf->top__DOT__data0__DOT__arvalid_in),2);
    bufp->fullCData(oldp+200,((((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                << 1U) | (IData)(vlSelf->top__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+201,(((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+202,(vlSelf->top__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+203,(vlSelf->top__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+204,(vlSelf->top__DOT____Vcellinp__data0__wstrb[0]),4);
    bufp->fullCData(oldp+205,(vlSelf->top__DOT____Vcellinp__data0__wstrb[1]),4);
    bufp->fullBit(oldp+206,(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter));
    bufp->fullBit(oldp+207,(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter));
    bufp->fullBit(oldp+208,(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter));
    bufp->fullBit(oldp+209,(vlSelf->top__DOT__data0__DOT__rready_from_arbiter));
    bufp->fullBit(oldp+210,(vlSelf->top__DOT__data0__DOT__bready_from_arbiter));
    bufp->fullCData(oldp+211,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullCData(oldp+212,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+213,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullBit(oldp+214,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[0]));
    bufp->fullBit(oldp+215,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[1]));
    bufp->fullBit(oldp+216,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                            [0U]));
    bufp->fullBit(oldp+217,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                            [1U]));
    bufp->fullCData(oldp+218,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+219,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+220,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+221,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+222,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+223,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+224,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+225,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+226,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+227,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+228,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+229,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+230,((0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+231,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+232,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+233,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+234,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+235,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+236,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+237,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+238,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+239,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+240,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+241,(vlSelf->top__DOT__ifu0__DOT__state),2);
    bufp->fullSData(oldp+242,((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+243,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+244,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+245,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+246,(vlSelf->top__DOT____Vcellout__wbu0__awvalid));
    bufp->fullCData(oldp+247,(((1U == (IData)(vlSelf->top__DOT__memmask))
                                ? 1U : ((2U == (IData)(vlSelf->top__DOT__memmask))
                                         ? 2U : ((3U 
                                                  == (IData)(vlSelf->top__DOT__memmask))
                                                  ? 4U
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->top__DOT__memmask))
                                                   ? 8U
                                                   : 0U))))),4);
    bufp->fullBit(oldp+248,(((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                >> 1U))));
    bufp->fullBit(oldp+249,((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                              & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                              [0U]) | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                       [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))));
    bufp->fullBit(oldp+250,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullBit(oldp+251,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                             [0U])));
    bufp->fullBit(oldp+252,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter))));
    bufp->fullBit(oldp+253,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
    bufp->fullCData(oldp+254,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                               & (- (IData)((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))))),4);
    bufp->fullBit(oldp+255,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter))));
    bufp->fullBit(oldp+256,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter))));
    bufp->fullBit(oldp+257,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter))));
    bufp->fullBit(oldp+258,(((IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullBit(oldp+259,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
    bufp->fullCData(oldp+260,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))),4);
    bufp->fullBit(oldp+261,(((IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullBit(oldp+262,(((IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullBit(oldp+263,(((IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+264,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+267,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+269,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+271,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+272,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullBit(oldp+273,((((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state)) 
                              & ((3U != (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                 & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                    | ((0x33U == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                       | ((0x6fU == 
                                           (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                          | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))) 
                             | ((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U)))));
    bufp->fullBit(oldp+274,(((IData)(vlSelf->top__DOT__ifu_valid) 
                             & (((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state)) 
                                 & ((3U != (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                    & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                       | ((0x33U == 
                                           (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                          | ((0x6fU 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                             | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))) 
                                | ((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                      >> 1U))))));
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
    bufp->fullWData(oldp+275,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+280,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+282,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+284,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+286,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+288,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+289,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+290,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+291,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+292,(vlSelf->top__DOT__npc),32);
    bufp->fullBit(oldp+293,(vlSelf->top__DOT__ifu_valid));
    bufp->fullBit(oldp+294,((1U & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
    bufp->fullIData(oldp+295,(vlSelf->top__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+296,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+297,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+298,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+299,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+300,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullCData(oldp+301,(vlSelf->top__DOT__data0__DOT__rvalid_out),2);
    bufp->fullIData(oldp+302,(vlSelf->top__DOT__araddr[0]),32);
    bufp->fullIData(oldp+303,(vlSelf->top__DOT__araddr[1]),32);
    bufp->fullIData(oldp+304,(vlSelf->top__DOT__rdata[0]),32);
    bufp->fullIData(oldp+305,(vlSelf->top__DOT__rdata[1]),32);
    bufp->fullIData(oldp+306,(vlSelf->top__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+307,(vlSelf->top__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+308,(vlSelf->top__DOT__wdata[0]),32);
    bufp->fullIData(oldp+309,(vlSelf->top__DOT__wdata[1]),32);
    bufp->fullBit(oldp+310,(vlSelf->top__DOT__bresp[0]));
    bufp->fullBit(oldp+311,(vlSelf->top__DOT__bresp[1]));
    bufp->fullIData(oldp+312,(vlSelf->top__DOT____Vcellinp__data0__araddr[0]),32);
    bufp->fullIData(oldp+313,(vlSelf->top__DOT____Vcellinp__data0__araddr[1]),32);
    bufp->fullIData(oldp+314,(vlSelf->top__DOT____Vcellout__data0__rdata[0]),32);
    bufp->fullIData(oldp+315,(vlSelf->top__DOT____Vcellout__data0__rdata[1]),32);
    bufp->fullIData(oldp+316,(vlSelf->top__DOT____Vcellinp__data0__awaddr[0]),32);
    bufp->fullIData(oldp+317,(vlSelf->top__DOT____Vcellinp__data0__awaddr[1]),32);
    bufp->fullIData(oldp+318,(vlSelf->top__DOT____Vcellinp__data0__wdata[0]),32);
    bufp->fullIData(oldp+319,(vlSelf->top__DOT____Vcellinp__data0__wdata[1]),32);
    bufp->fullBit(oldp+320,(vlSelf->top__DOT____Vcellout__data0__bresp[0]));
    bufp->fullBit(oldp+321,(vlSelf->top__DOT____Vcellout__data0__bresp[1]));
    bufp->fullBit(oldp+322,(vlSelf->top__DOT__data0__DOT__rvalid_from_arbiter));
    bufp->fullBit(oldp+323,((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                              & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                              [0U]) | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                       [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))));
    bufp->fullIData(oldp+324,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullIData(oldp+325,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+326,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullIData(oldp+327,((vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_sram 
                               | vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_urt)),32);
    bufp->fullBit(oldp+328,(vlSelf->top__DOT__data0__DOT__bresp_from_arbiter));
    bufp->fullBit(oldp+329,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[0]));
    bufp->fullBit(oldp+330,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[1]));
    bufp->fullBit(oldp+331,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[0]));
    bufp->fullBit(oldp+332,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[1]));
    bufp->fullBit(oldp+333,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[0]));
    bufp->fullBit(oldp+334,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[1]));
    bufp->fullBit(oldp+335,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[0]));
    bufp->fullBit(oldp+336,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[1]));
    bufp->fullBit(oldp+337,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[0]));
    bufp->fullBit(oldp+338,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[1]));
    bufp->fullIData(oldp+339,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[0]),32);
    bufp->fullIData(oldp+340,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[1]),32);
    bufp->fullIData(oldp+341,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[0]),32);
    bufp->fullIData(oldp+342,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[1]),32);
    bufp->fullIData(oldp+343,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[0]),32);
    bufp->fullIData(oldp+344,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[1]),32);
    bufp->fullIData(oldp+345,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[0]),32);
    bufp->fullIData(oldp+346,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[1]),32);
    bufp->fullCData(oldp+347,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[0]),4);
    bufp->fullCData(oldp+348,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[1]),4);
    bufp->fullIData(oldp+349,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+350,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+351,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+352,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+353,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+354,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullIData(oldp+355,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+356,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullBit(oldp+357,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0]));
    bufp->fullBit(oldp+358,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[1]));
    bufp->fullBit(oldp+359,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                            [0U]));
    bufp->fullIData(oldp+360,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                              [0U]),32);
    bufp->fullBit(oldp+361,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                            [0U]));
    bufp->fullIData(oldp+362,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                              [0U]),32);
    bufp->fullCData(oldp+363,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                              [0U]),4);
    bufp->fullBit(oldp+364,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                            [0U]));
    bufp->fullBit(oldp+365,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                            [0U]));
    bufp->fullIData(oldp+366,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                              [0U]),32);
    bufp->fullBit(oldp+367,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                            [0U]));
    bufp->fullIData(oldp+368,(vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg),32);
    bufp->fullCData(oldp+369,(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask),3);
    bufp->fullCData(oldp+370,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+371,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+372,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                            [1U]));
    bufp->fullIData(oldp+373,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                              [1U]),32);
    bufp->fullBit(oldp+374,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                            [1U]));
    bufp->fullIData(oldp+375,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                              [1U]),32);
    bufp->fullCData(oldp+376,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                              [1U]),4);
    bufp->fullBit(oldp+377,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                            [1U]));
    bufp->fullBit(oldp+378,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                            [1U]));
    bufp->fullIData(oldp+379,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                              [1U]),32);
    bufp->fullBit(oldp+380,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                            [1U]));
    bufp->fullBit(oldp+381,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[0]));
    bufp->fullBit(oldp+382,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[1]));
    bufp->fullIData(oldp+383,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[0]),32);
    bufp->fullIData(oldp+384,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[1]),32);
    bufp->fullBit(oldp+385,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[0]));
    bufp->fullBit(oldp+386,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[1]));
    bufp->fullIData(oldp+387,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[0]),32);
    bufp->fullIData(oldp+388,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[1]),32);
    bufp->fullCData(oldp+389,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[0]),4);
    bufp->fullCData(oldp+390,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[1]),4);
    bufp->fullBit(oldp+391,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[0]));
    bufp->fullBit(oldp+392,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[1]));
    bufp->fullBit(oldp+393,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[0]));
    bufp->fullBit(oldp+394,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[1]));
    bufp->fullIData(oldp+395,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[0]),32);
    bufp->fullIData(oldp+396,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[1]),32);
    bufp->fullBit(oldp+397,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[0]));
    bufp->fullBit(oldp+398,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[1]));
    bufp->fullIData(oldp+399,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[0]),32);
    bufp->fullIData(oldp+400,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[1]),32);
    bufp->fullBit(oldp+401,((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))));
    bufp->fullBit(oldp+402,(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt));
    bufp->fullBit(oldp+403,(((0xa00003f8U <= vlSelf->top__DOT__data0__DOT__xbar__DOT____VdfgTmp_h62cc6d96__0) 
                             & (0xa00003ffU >= vlSelf->top__DOT__data0__DOT__xbar__DOT____VdfgTmp_h62cc6d96__0))));
    bufp->fullBit(oldp+404,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))));
    bufp->fullIData(oldp+405,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_urt),32);
    bufp->fullBit(oldp+406,(((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                             [0U])));
    bufp->fullIData(oldp+407,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_sram),32);
    bufp->fullIData(oldp+408,(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__mux__data),32);
    bufp->fullIData(oldp+409,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                               & (- (IData)((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))))),32);
    bufp->fullIData(oldp+410,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                               & (- (IData)((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))))),32);
    bufp->fullIData(oldp+411,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                               & (- (IData)((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))))),32);
    bufp->fullIData(oldp+412,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                              [0U]),32);
    bufp->fullIData(oldp+413,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))),32);
    bufp->fullIData(oldp+414,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))),32);
    bufp->fullIData(oldp+415,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))),32);
    bufp->fullIData(oldp+416,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                              [1U]),32);
    bufp->fullIData(oldp+417,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+418,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+419,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+420,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+421,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+422,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+423,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+424,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+425,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+426,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+427,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+428,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullBit(oldp+429,(vlSelf->top__DOT__bresp
                            [1U]));
    bufp->fullBit(oldp+430,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U))));
    bufp->fullIData(oldp+431,(vlSelf->top__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+432,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+433,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+434,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+435,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__rdata
                                          [1U]))),32);
    bufp->fullIData(oldp+436,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__rdata
                                             [1U]))),32);
    bufp->fullCData(oldp+437,((0xffU & vlSelf->top__DOT__rdata
                               [1U])),8);
    bufp->fullSData(oldp+438,((0xffffU & vlSelf->top__DOT__rdata
                               [1U])),16);
    bufp->fullIData(oldp+439,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+440,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+441,(vlSelf->clk));
    bufp->fullBit(oldp+442,(vlSelf->rst));
    bufp->fullBit(oldp+443,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                             & (((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                 & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                 [0U]) | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                          [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))));
    bufp->fullCData(oldp+444,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                               & (- (IData)((((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                              & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                              [0U]) 
                                             | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                [1U] 
                                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt))))))),2);
    bufp->fullBit(oldp+445,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__rvalid_get)) 
                             & (3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)))));
    bufp->fullBit(oldp+446,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (- (IData)(((
                                                   (~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                                   & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                   [0U]) 
                                                  | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                     [1U] 
                                                     & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))))) 
                                   >> 1U))));
    bufp->fullBit(oldp+447,((1U & ((((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                     & (- (IData)((
                                                   ((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                                    & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                    [0U]) 
                                                   | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                      [1U] 
                                                      & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))))) 
                                    & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                        & (- (IData)(
                                                     (((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                                       & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                       [0U]) 
                                                      | (vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                         [1U] 
                                                         & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)))))) 
                                       & ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                          & (- (IData)(
                                                       (((~ (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt)) 
                                                         & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                         [0U]) 
                                                        | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_urt) 
                                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                           [1U]))))))) 
                                   >> 1U))));
    bufp->fullIData(oldp+448,(2U),32);
    bufp->fullIData(oldp+449,(0U),32);
    bufp->fullIData(oldp+450,(2U),32);
    bufp->fullBit(oldp+451,(vlSelf->top__DOT__data0__DOT____Vcellout__mem0__bvalid));
    bufp->fullIData(oldp+452,(4U),32);
    bufp->fullBit(oldp+453,(0U));
    bufp->fullIData(oldp+454,(3U),32);
    bufp->fullIData(oldp+455,(0x12491c4U),28);
    bufp->fullCData(oldp+456,(0U),3);
    bufp->fullIData(oldp+457,(7U),32);
    bufp->fullIData(oldp+458,(4U),32);
    bufp->fullBit(oldp+459,(vlSelf->top__DOT__data0__DOT____Vcellout__uart0__bvalid));
    bufp->fullBit(oldp+460,(vlSelf->top__DOT__data0__DOT____Vcellout__uart0__arready));
    bufp->fullIData(oldp+461,(1U),32);
    bufp->fullIData(oldp+462,(0x20U),32);
    bufp->fullQData(oldp+463,(0xa00003f8a00003ffULL),64);
    bufp->fullIData(oldp+465,(0xa00003ffU),32);
    bufp->fullIData(oldp+466,(0xa00003f8U),32);
    bufp->fullIData(oldp+467,(0U),32);
    bufp->fullIData(oldp+468,(0x21U),32);
    bufp->fullIData(oldp+469,(2U),32);
    bufp->fullIData(oldp+470,(0x7ffffffcU),32);
    bufp->fullIData(oldp+471,(0xcU),32);
    bufp->fullQData(oldp+472,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+474,(0U),2);
    bufp->fullIData(oldp+475,(0xeU),32);
    bufp->fullIData(oldp+476,(8U),32);
    bufp->fullIData(oldp+477,(0x10U),32);
    bufp->fullIData(oldp+478,(0x23U),32);
}
