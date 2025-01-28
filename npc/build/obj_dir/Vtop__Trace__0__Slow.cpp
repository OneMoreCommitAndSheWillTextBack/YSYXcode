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
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+516,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+516,"rst", false,-1);
    tracep->declBit(c+181,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+330,"npc", false,-1, 31,0);
    tracep->declBus(c+104,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+182,"inst", false,-1, 31,0);
    tracep->declBit(c+331,"ifu_valid", false,-1);
    tracep->declBit(c+181,"ifu_arvalid", false,-1);
    tracep->declBit(c+87,"ifu_arready", false,-1);
    tracep->declBus(c+330,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+332,"ifu_rvalid", false,-1);
    tracep->declBit(c+181,"ifu_rready", false,-1);
    tracep->declBus(c+333,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+183,"reg_process", false,-1);
    tracep->declBus(c+184,"src1", false,-1, 4,0);
    tracep->declBus(c+185,"src2", false,-1, 4,0);
    tracep->declBus(c+186,"rd", false,-1, 4,0);
    tracep->declBus(c+187,"imm", false,-1, 31,0);
    tracep->declBit(c+188,"ebreaksig", false,-1);
    tracep->declBit(c+189,"mretsig", false,-1);
    tracep->declBit(c+190,"ecallsig", false,-1);
    tracep->declBit(c+191,"regew", false,-1);
    tracep->declBit(c+192,"memew", false,-1);
    tracep->declBit(c+193,"memer", false,-1);
    tracep->declBit(c+194,"muximm", false,-1);
    tracep->declBus(c+195,"func3", false,-1, 2,0);
    tracep->declBus(c+196,"muxsig", false,-1, 2,0);
    tracep->declBit(c+197,"func7", false,-1);
    tracep->declBit(c+198,"btypebranch", false,-1);
    tracep->declBit(c+199,"jalsig", false,-1);
    tracep->declBit(c+200,"jalrsig", false,-1);
    tracep->declBit(c+201,"auipcsig", false,-1);
    tracep->declBus(c+202,"aluop", false,-1, 1,0);
    tracep->declBit(c+203,"csrrw", false,-1);
    tracep->declBit(c+204,"csrrs", false,-1);
    tracep->declBit(c+331,"idu_valid", false,-1);
    tracep->declBus(c+205,"memmask", false,-1, 2,0);
    tracep->declBit(c+206,"memsextsig", false,-1);
    tracep->declBus(c+334,"regwrite", false,-1, 31,0);
    tracep->declBus(c+335,"regout1", false,-1, 31,0);
    tracep->declBus(c+336,"regout2", false,-1, 31,0);
    tracep->declBus(c+105,"mepc", false,-1, 31,0);
    tracep->declBus(c+106,"mtvec", false,-1, 31,0);
    tracep->declBit(c+181,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+337,"res", false,-1, 31,0);
    tracep->declBus(c+338,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+331,"exu_valid", false,-1);
    tracep->declBit(c+181,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+271,"memvalid", false,-1);
    tracep->declBus(c+207,"awvalid", false,-1, 1,0);
    tracep->declBus(c+207,"wvalid", false,-1, 1,0);
    tracep->declBus(c+208,"arvalid", false,-1, 1,0);
    tracep->declBus(c+209,"rready", false,-1, 1,0);
    tracep->declBus(c+210,"bready", false,-1, 1,0);
    tracep->declBus(c+95,"bvalid", false,-1, 1,0);
    tracep->declBus(c+339,"rvalid", false,-1, 1,0);
    tracep->declBus(c+88,"awready", false,-1, 1,0);
    tracep->declBus(c+89,"wready", false,-1, 1,0);
    tracep->declBus(c+90,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+340+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+342+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+344+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+346+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+211+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+348+i*1,"bresp", true,(i+0));
    }
    tracep->pushNamePrefix("data0 ");
    tracep->declBus(c+518,"NUM", false,-1, 31,0);
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBus(c+207,"awvalid", false,-1, 1,0);
    tracep->declBus(c+207,"wvalid", false,-1, 1,0);
    tracep->declBus(c+208,"arvalid", false,-1, 1,0);
    tracep->declBus(c+209,"rready", false,-1, 1,0);
    tracep->declBus(c+210,"bready", false,-1, 1,0);
    tracep->declBus(c+95,"bvalid", false,-1, 1,0);
    tracep->declBus(c+339,"rvalid", false,-1, 1,0);
    tracep->declBus(c+88,"awready", false,-1, 1,0);
    tracep->declBus(c+89,"wready", false,-1, 1,0);
    tracep->declBus(c+90,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+350+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+352+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+354+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+356+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+213+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+358+i*1,"bresp", true,(i+0));
    }
    tracep->declBus(c+519,"DEVICE", false,-1, 31,0);
    tracep->declBus(c+207,"awvalid_in", false,-1, 1,0);
    tracep->declBus(c+207,"wvalid_in", false,-1, 1,0);
    tracep->declBus(c+208,"arvalid_in", false,-1, 1,0);
    tracep->declBus(c+209,"rready_in", false,-1, 1,0);
    tracep->declBus(c+210,"bready_in", false,-1, 1,0);
    tracep->declBus(c+339,"rvalid_out", false,-1, 1,0);
    tracep->declBus(c+88,"awready_out", false,-1, 1,0);
    tracep->declBus(c+89,"wready_out", false,-1, 1,0);
    tracep->declBus(c+90,"arready_out", false,-1, 1,0);
    tracep->declBus(c+95,"bvalid_out", false,-1, 1,0);
    tracep->declBit(c+215,"awvalid_from_arbiter", false,-1);
    tracep->declBit(c+216,"wvalid_from_arbiter", false,-1);
    tracep->declBit(c+217,"arvalid_from_arbiter", false,-1);
    tracep->declBit(c+218,"rready_from_arbiter", false,-1);
    tracep->declBit(c+219,"bready_from_arbiter", false,-1);
    tracep->declBit(c+360,"rvalid_from_arbiter", false,-1);
    tracep->declBit(c+272,"awready_from_arbiter", false,-1);
    tracep->declBit(c+273,"wready_from_arbiter", false,-1);
    tracep->declBit(c+274,"arready_from_arbiter", false,-1);
    tracep->declBit(c+361,"bvalid_from_arbiter", false,-1);
    tracep->declBus(c+362,"awaddr_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+363,"araddr_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+364,"wdata_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+365,"rdata_from_arbiter", false,-1, 31,0);
    tracep->declBus(c+220,"wstrb_from_arbiter", false,-1, 3,0);
    tracep->declBit(c+366,"bresp_from_arbiter", false,-1);
    tracep->declBus(c+520,"device_num", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+367+i*1,"awvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+370+i*1,"wvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+373+i*1,"arvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+376+i*1,"rready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+379+i*1,"bready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+40+i*1,"rvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+43+i*1,"awready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+46+i*1,"wready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+49+i*1,"arready_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+1+i*1,"bvalid_from_xbar", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+382+i*1,"awaddr_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+385+i*1,"araddr_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+388+i*1,"wdata_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+391+i*1,"rdata_from_xbar", true,(i+0), 31,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+394+i*1,"wstrb_from_xbar", true,(i+0), 3,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+52+i*1,"bresp_from_xbar", true,(i+0));
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+518,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBus(c+207,"awvalid", false,-1, 1,0);
    tracep->declBus(c+207,"wvalid", false,-1, 1,0);
    tracep->declBus(c+208,"arvalid", false,-1, 1,0);
    tracep->declBus(c+209,"rready", false,-1, 1,0);
    tracep->declBus(c+210,"bready", false,-1, 1,0);
    tracep->declBus(c+95,"bvalid", false,-1, 1,0);
    tracep->declBus(c+339,"rvalid", false,-1, 1,0);
    tracep->declBus(c+88,"awready", false,-1, 1,0);
    tracep->declBus(c+89,"wready", false,-1, 1,0);
    tracep->declBus(c+90,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+397+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+399+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+401+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+221+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+403+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+405+i*1,"bresp", true,(i+0));
    }
    tracep->declBit(c+215,"awvalid_out", false,-1);
    tracep->declBit(c+216,"wvalid_out", false,-1);
    tracep->declBit(c+217,"arvalid_out", false,-1);
    tracep->declBit(c+218,"rready_out", false,-1);
    tracep->declBit(c+219,"bready_out", false,-1);
    tracep->declBit(c+361,"bvalid_in", false,-1);
    tracep->declBit(c+360,"rvalid_in", false,-1);
    tracep->declBit(c+272,"awready_in", false,-1);
    tracep->declBit(c+273,"wready_in", false,-1);
    tracep->declBit(c+274,"arready_in", false,-1);
    tracep->declBus(c+363,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+362,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+364,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+220,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+365,"rdata_in", false,-1, 31,0);
    tracep->declBit(c+366,"bresp_in", false,-1);
    tracep->declBit(c+55,"busy", false,-1);
    tracep->declBus(c+56,"giant", false,-1, 1,0);
    tracep->declBus(c+57,"i", false,-1, 31,0);
    tracep->declBus(c+362,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+364,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+363,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+220,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+521,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("client0 ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+407,"awvalid", false,-1);
    tracep->declBit(c+522,"awready", false,-1);
    tracep->declBus(c+408,"awaddr", false,-1, 31,0);
    tracep->declBit(c+409,"wvalid", false,-1);
    tracep->declBit(c+523,"wready", false,-1);
    tracep->declBus(c+410,"wdata", false,-1, 31,0);
    tracep->declBus(c+411,"wstrb", false,-1, 3,0);
    tracep->declBit(c+524,"bvalid", false,-1);
    tracep->declBit(c+412,"bready", false,-1);
    tracep->declBit(c+525,"bresp", false,-1);
    tracep->declBit(c+413,"arvalid", false,-1);
    tracep->declBit(c+58,"arready", false,-1);
    tracep->declBus(c+414,"araddr", false,-1, 31,0);
    tracep->declBit(c+415,"rready", false,-1);
    tracep->declBit(c+59,"rvalid", false,-1);
    tracep->declBus(c+96,"rdata", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+60+i*1,"mtime_reg", true,(i+0), 31,0);
    }
    tracep->declBit(c+59,"state", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem0 ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+416,"awvalid", false,-1);
    tracep->declBit(c+62,"awready", false,-1);
    tracep->declBus(c+417,"awaddr", false,-1, 31,0);
    tracep->declBit(c+418,"wvalid", false,-1);
    tracep->declBit(c+62,"wready", false,-1);
    tracep->declBus(c+419,"wdata", false,-1, 31,0);
    tracep->declBus(c+420,"wstrb", false,-1, 3,0);
    tracep->declBit(c+526,"bvalid", false,-1);
    tracep->declBit(c+421,"bready", false,-1);
    tracep->declBit(c+63,"bresp", false,-1);
    tracep->declBit(c+422,"arvalid", false,-1);
    tracep->declBit(c+62,"arready", false,-1);
    tracep->declBus(c+423,"araddr", false,-1, 31,0);
    tracep->declBit(c+424,"rready", false,-1);
    tracep->declBit(c+64,"rvalid", false,-1);
    tracep->declBus(c+425,"rdata", false,-1, 31,0);
    tracep->declBus(c+65,"state", false,-1, 1,0);
    tracep->declBus(c+66,"random_delay", false,-1, 3,0);
    tracep->declBit(c+67,"busy", false,-1);
    tracep->declBus(c+68,"random_count", false,-1, 3,0);
    tracep->declBus(c+426,"memmask", false,-1, 2,0);
    tracep->declBus(c+425,"rdatareg", false,-1, 31,0);
    tracep->pushNamePrefix("lsfr0 ");
    tracep->declBus(c+527,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+525,"reset", false,-1);
    tracep->declBus(c+66,"out", false,-1, 3,0);
    tracep->declBus(c+69,"random_num", false,-1, 7,0);
    tracep->declBit(c+70,"feedback", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+527,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+527,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+520,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+426,"out", false,-1, 2,0);
    tracep->declBus(c+420,"key", false,-1, 3,0);
    tracep->declBus(c+528,"lut", false,-1, 27,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+527,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+527,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+520,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+519,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+426,"out", false,-1, 2,0);
    tracep->declBus(c+420,"key", false,-1, 3,0);
    tracep->declBus(c+529,"default_out", false,-1, 2,0);
    tracep->declBus(c+528,"lut", false,-1, 27,0);
    tracep->declBus(c+530,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+4+i*1,"pair_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+8+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+12+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+427,"lut_out", false,-1, 2,0);
    tracep->declBit(c+428,"hit", false,-1);
    tracep->declBus(c+531,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("uart0 ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+429,"awvalid", false,-1);
    tracep->declBit(c+71,"awready", false,-1);
    tracep->declBus(c+430,"awaddr", false,-1, 31,0);
    tracep->declBit(c+431,"wvalid", false,-1);
    tracep->declBit(c+71,"wready", false,-1);
    tracep->declBus(c+432,"wdata", false,-1, 31,0);
    tracep->declBus(c+433,"wstrb", false,-1, 3,0);
    tracep->declBit(c+532,"bvalid", false,-1);
    tracep->declBit(c+434,"bready", false,-1);
    tracep->declBit(c+72,"bresp", false,-1);
    tracep->declBit(c+435,"arvalid", false,-1);
    tracep->declBit(c+533,"arready", false,-1);
    tracep->declBus(c+436,"araddr", false,-1, 31,0);
    tracep->declBit(c+437,"rready", false,-1);
    tracep->declBit(c+525,"rvalid", false,-1);
    tracep->declBus(c+519,"rdata", false,-1, 31,0);
    tracep->declBit(c+72,"state", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("xbar ");
    tracep->declBus(c+520,"DEVICE", false,-1, 31,0);
    tracep->declBit(c+215,"m_awvalid", false,-1);
    tracep->declBit(c+272,"m_awready", false,-1);
    tracep->declBus(c+362,"m_awaddr", false,-1, 31,0);
    tracep->declBit(c+216,"m_wvalid", false,-1);
    tracep->declBit(c+273,"m_wready", false,-1);
    tracep->declBus(c+364,"m_wdata", false,-1, 31,0);
    tracep->declBus(c+220,"m_wstrb", false,-1, 3,0);
    tracep->declBit(c+361,"m_bvalid", false,-1);
    tracep->declBit(c+219,"m_bready", false,-1);
    tracep->declBit(c+366,"m_bresp", false,-1);
    tracep->declBit(c+217,"m_arvalid", false,-1);
    tracep->declBit(c+274,"m_arready", false,-1);
    tracep->declBus(c+363,"m_araddr", false,-1, 31,0);
    tracep->declBit(c+360,"m_rvalid", false,-1);
    tracep->declBit(c+218,"m_rready", false,-1);
    tracep->declBus(c+365,"m_rdata", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+438+i*1,"s_awvalid", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+223+i*1,"s_awready", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+441+i*1,"s_awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+444+i*1,"s_wvalid", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+226+i*1,"s_wready", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+447+i*1,"s_wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+450+i*1,"s_wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+16+i*1,"s_bvalid", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+453+i*1,"s_bready", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+73+i*1,"s_bresp", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+456+i*1,"s_arvalid", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+229+i*1,"s_arready", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+459+i*1,"s_araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+76+i*1,"s_rvalid", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+462+i*1,"s_rready", true,(i+0));
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+465+i*1,"s_rdata", true,(i+0), 31,0);
    }
    tracep->declBit(c+468,"sig_sram", false,-1);
    tracep->declBus(c+469,"sig_device", false,-1, 1,0);
    tracep->declBit(c+275,"m_awready_urt", false,-1);
    tracep->declBit(c+276,"m_wready_urt", false,-1);
    tracep->declBit(c+470,"m_bvalid_urt", false,-1);
    tracep->declBit(c+97,"m_bresp_urt", false,-1);
    tracep->declBit(c+277,"m_arready_urt", false,-1);
    tracep->declBit(c+98,"m_rvalid_urt", false,-1);
    tracep->declBus(c+471,"m_rdata_urt", false,-1, 31,0);
    tracep->declBit(c+278,"m_awready_sram", false,-1);
    tracep->declBit(c+279,"m_wready_sram", false,-1);
    tracep->declBit(c+472,"m_bvalid_sram", false,-1);
    tracep->declBit(c+99,"m_bresp_sram", false,-1);
    tracep->declBit(c+280,"m_arready_sram", false,-1);
    tracep->declBit(c+100,"m_rvalid_sram", false,-1);
    tracep->declBus(c+473,"m_rdata_sram", false,-1, 31,0);
    tracep->declBit(c+281,"m_awready_client", false,-1);
    tracep->declBit(c+282,"m_wready_client", false,-1);
    tracep->declBit(c+474,"m_bvalid_client", false,-1);
    tracep->declBit(c+101,"m_bresp_client", false,-1);
    tracep->declBit(c+283,"m_arready_client", false,-1);
    tracep->declBit(c+102,"m_rvalid_client", false,-1);
    tracep->declBus(c+475,"m_rdata_client", false,-1, 31,0);
    tracep->pushNamePrefix("client_input ");
    tracep->declBit(c+215,"awvalid", false,-1);
    tracep->declBus(c+362,"awaddr", false,-1, 31,0);
    tracep->declBit(c+216,"wvalid", false,-1);
    tracep->declBus(c+364,"wdata", false,-1, 31,0);
    tracep->declBus(c+220,"wstrb", false,-1, 3,0);
    tracep->declBit(c+219,"bready", false,-1);
    tracep->declBit(c+217,"arvalid", false,-1);
    tracep->declBus(c+363,"araddr", false,-1, 31,0);
    tracep->declBit(c+218,"rready", false,-1);
    tracep->declBit(c+476,"sig", false,-1);
    tracep->declBit(c+284,"awvalid_out", false,-1);
    tracep->declBus(c+477,"awaddr_out", false,-1, 31,0);
    tracep->declBit(c+285,"wvalid_out", false,-1);
    tracep->declBus(c+478,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+286,"wstrb_out", false,-1, 3,0);
    tracep->declBit(c+287,"bready_out", false,-1);
    tracep->declBit(c+288,"arvalid_out", false,-1);
    tracep->declBus(c+479,"araddr_out", false,-1, 31,0);
    tracep->declBit(c+289,"rready_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("client_output ");
    tracep->declBit(c+281,"awready", false,-1);
    tracep->declBit(c+282,"wready", false,-1);
    tracep->declBit(c+474,"bvalid", false,-1);
    tracep->declBit(c+101,"bresp", false,-1);
    tracep->declBit(c+283,"arready", false,-1);
    tracep->declBit(c+102,"rvalid", false,-1);
    tracep->declBus(c+475,"rdata", false,-1, 31,0);
    tracep->declBit(c+476,"sig", false,-1);
    tracep->declBit(c+232,"awready_in", false,-1);
    tracep->declBit(c+233,"wready_in", false,-1);
    tracep->declBit(c+19,"bvalid_in", false,-1);
    tracep->declBit(c+79,"bresp_in", false,-1);
    tracep->declBit(c+234,"arready_in", false,-1);
    tracep->declBit(c+80,"rvalid_in", false,-1);
    tracep->declBus(c+480,"rdata_in", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mux ");
    tracep->declBus(c+518,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+534,"KEY_LEN", false,-1, 31,0);
    tracep->declArray(c+535,"tbl", false,-1, 127,0);
    tracep->declBus(c+481,"data", false,-1, 31,0);
    tracep->declBus(c+469,"out", false,-1, 1,0);
    tracep->pushNamePrefix("compare_loop[0] ");
    tracep->declBus(c+539,"upper_bound", false,-1, 31,0);
    tracep->declBus(c+540,"lower_bound", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("compare_loop[1] ");
    tracep->declBus(c+541,"upper_bound", false,-1, 31,0);
    tracep->declBus(c+542,"lower_bound", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("sram_input ");
    tracep->declBit(c+215,"awvalid", false,-1);
    tracep->declBus(c+362,"awaddr", false,-1, 31,0);
    tracep->declBit(c+216,"wvalid", false,-1);
    tracep->declBus(c+364,"wdata", false,-1, 31,0);
    tracep->declBus(c+220,"wstrb", false,-1, 3,0);
    tracep->declBit(c+219,"bready", false,-1);
    tracep->declBit(c+217,"arvalid", false,-1);
    tracep->declBus(c+363,"araddr", false,-1, 31,0);
    tracep->declBit(c+218,"rready", false,-1);
    tracep->declBit(c+468,"sig", false,-1);
    tracep->declBit(c+290,"awvalid_out", false,-1);
    tracep->declBus(c+482,"awaddr_out", false,-1, 31,0);
    tracep->declBit(c+291,"wvalid_out", false,-1);
    tracep->declBus(c+483,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+292,"wstrb_out", false,-1, 3,0);
    tracep->declBit(c+293,"bready_out", false,-1);
    tracep->declBit(c+294,"arvalid_out", false,-1);
    tracep->declBus(c+484,"araddr_out", false,-1, 31,0);
    tracep->declBit(c+295,"rready_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sram_output ");
    tracep->declBit(c+278,"awready", false,-1);
    tracep->declBit(c+279,"wready", false,-1);
    tracep->declBit(c+472,"bvalid", false,-1);
    tracep->declBit(c+99,"bresp", false,-1);
    tracep->declBit(c+280,"arready", false,-1);
    tracep->declBit(c+100,"rvalid", false,-1);
    tracep->declBus(c+473,"rdata", false,-1, 31,0);
    tracep->declBit(c+468,"sig", false,-1);
    tracep->declBit(c+235,"awready_in", false,-1);
    tracep->declBit(c+236,"wready_in", false,-1);
    tracep->declBit(c+20,"bvalid_in", false,-1);
    tracep->declBit(c+81,"bresp_in", false,-1);
    tracep->declBit(c+237,"arready_in", false,-1);
    tracep->declBit(c+82,"rvalid_in", false,-1);
    tracep->declBus(c+485,"rdata_in", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("urt_input ");
    tracep->declBit(c+215,"awvalid", false,-1);
    tracep->declBus(c+362,"awaddr", false,-1, 31,0);
    tracep->declBit(c+216,"wvalid", false,-1);
    tracep->declBus(c+364,"wdata", false,-1, 31,0);
    tracep->declBus(c+220,"wstrb", false,-1, 3,0);
    tracep->declBit(c+219,"bready", false,-1);
    tracep->declBit(c+217,"arvalid", false,-1);
    tracep->declBus(c+363,"araddr", false,-1, 31,0);
    tracep->declBit(c+218,"rready", false,-1);
    tracep->declBit(c+486,"sig", false,-1);
    tracep->declBit(c+296,"awvalid_out", false,-1);
    tracep->declBus(c+487,"awaddr_out", false,-1, 31,0);
    tracep->declBit(c+297,"wvalid_out", false,-1);
    tracep->declBus(c+488,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+298,"wstrb_out", false,-1, 3,0);
    tracep->declBit(c+299,"bready_out", false,-1);
    tracep->declBit(c+300,"arvalid_out", false,-1);
    tracep->declBus(c+489,"araddr_out", false,-1, 31,0);
    tracep->declBit(c+301,"rready_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("urt_output ");
    tracep->declBit(c+275,"awready", false,-1);
    tracep->declBit(c+276,"wready", false,-1);
    tracep->declBit(c+470,"bvalid", false,-1);
    tracep->declBit(c+97,"bresp", false,-1);
    tracep->declBit(c+277,"arready", false,-1);
    tracep->declBit(c+98,"rvalid", false,-1);
    tracep->declBus(c+471,"rdata", false,-1, 31,0);
    tracep->declBit(c+486,"sig", false,-1);
    tracep->declBit(c+238,"awready_in", false,-1);
    tracep->declBit(c+239,"wready_in", false,-1);
    tracep->declBit(c+21,"bvalid_in", false,-1);
    tracep->declBit(c+83,"bresp_in", false,-1);
    tracep->declBit(c+240,"arready_in", false,-1);
    tracep->declBit(c+84,"rvalid_in", false,-1);
    tracep->declBus(c+490,"rdata_in", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+195,"func3", false,-1, 2,0);
    tracep->declBit(c+198,"btypebranch", false,-1);
    tracep->declBit(c+197,"func7", false,-1);
    tracep->declBus(c+202,"aluop", false,-1, 1,0);
    tracep->declBit(c+200,"jalrsig", false,-1);
    tracep->declBit(c+199,"jalsig", false,-1);
    tracep->declBus(c+187,"imm", false,-1, 31,0);
    tracep->declBit(c+194,"muximm", false,-1);
    tracep->declBus(c+335,"regout1", false,-1, 31,0);
    tracep->declBus(c+336,"regout2", false,-1, 31,0);
    tracep->declBus(c+104,"pc", false,-1, 31,0);
    tracep->declBit(c+201,"auipcsig", false,-1);
    tracep->declBit(c+189,"mretsig", false,-1);
    tracep->declBit(c+190,"ecallsig", false,-1);
    tracep->declBus(c+106,"mtvec", false,-1, 31,0);
    tracep->declBus(c+105,"mepc", false,-1, 31,0);
    tracep->declBit(c+331,"valid_from", false,-1);
    tracep->declBit(c+181,"ready_from", false,-1);
    tracep->declBus(c+337,"res", false,-1, 31,0);
    tracep->declBus(c+330,"npc", false,-1, 31,0);
    tracep->declBus(c+338,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+331,"valid_to", false,-1);
    tracep->declBit(c+181,"ready_to", false,-1);
    tracep->declBus(c+107,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+491,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+241,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+492,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+493,"zero", false,-1);
    tracep->declBit(c+494,"signal", false,-1);
    tracep->declBit(c+495,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+335,"A", false,-1, 31,0);
    tracep->declBus(c+492,"B", false,-1, 31,0);
    tracep->declBus(c+241,"op", false,-1, 4,0);
    tracep->declBus(c+337,"res", false,-1, 31,0);
    tracep->declBit(c+493,"zero", false,-1);
    tracep->declBit(c+494,"signal", false,-1);
    tracep->declBit(c+495,"carry", false,-1);
    tracep->declBit(c+242,"addsig", false,-1);
    tracep->declBit(c+243,"logsig", false,-1);
    tracep->declBit(c+244,"shfsig", false,-1);
    tracep->declBit(c+245,"sltsig", false,-1);
    tracep->declBit(c+495,"carry_tmp", false,-1);
    tracep->declBit(c+246,"type_I", false,-1);
    tracep->declBus(c+496,"logres", false,-1, 31,0);
    tracep->declBus(c+497,"addres", false,-1, 31,0);
    tracep->declBit(c+498,"addzero", false,-1);
    tracep->declBus(c+499,"shfres", false,-1, 31,0);
    tracep->declBus(c+500,"sltres", false,-1, 31,0);
    tracep->declBus(c+335,"A_s", false,-1, 31,0);
    tracep->declBus(c+492,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+195,"func3", false,-1, 2,0);
    tracep->declBit(c+197,"func7", false,-1);
    tracep->declBus(c+202,"aluop", false,-1, 1,0);
    tracep->declBit(c+200,"jalrsig", false,-1);
    tracep->declBus(c+241,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+246,"type_I", false,-1);
    tracep->declBit(c+247,"type_B", false,-1);
    tracep->declBit(c+248,"type_R", false,-1);
    tracep->declBit(c+249,"addsig", false,-1);
    tracep->declBus(c+250,"branchop", false,-1, 3,0);
    tracep->declBus(c+251,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+198,"btypebranch", false,-1);
    tracep->declBus(c+195,"func3", false,-1, 2,0);
    tracep->declBit(c+493,"zero", false,-1);
    tracep->declBit(c+494,"signal", false,-1);
    tracep->declBit(c+495,"carry", false,-1);
    tracep->declBus(c+337,"res", false,-1, 31,0);
    tracep->declBus(c+107,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+491,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+199,"jalsig", false,-1);
    tracep->declBit(c+200,"jalrsig", false,-1);
    tracep->declBit(c+201,"auipcsig", false,-1);
    tracep->declBit(c+189,"mretsig", false,-1);
    tracep->declBit(c+190,"ecallsig", false,-1);
    tracep->declBus(c+106,"mtvec", false,-1, 31,0);
    tracep->declBus(c+105,"mepc", false,-1, 31,0);
    tracep->declBus(c+330,"npc", false,-1, 31,0);
    tracep->declBus(c+338,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+518,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+543,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+534,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+492,"out", false,-1, 31,0);
    tracep->declBus(c+194,"key", false,-1, 0,0);
    tracep->declArray(c+302,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+518,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+543,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+534,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+519,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+492,"out", false,-1, 31,0);
    tracep->declBus(c+194,"key", false,-1, 0,0);
    tracep->declBus(c+544,"default_out", false,-1, 31,0);
    tracep->declArray(c+302,"lut", false,-1, 65,0);
    tracep->declBus(c+545,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+305+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+22+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+309+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+501,"lut_out", false,-1, 31,0);
    tracep->declBit(c+252,"hit", false,-1);
    tracep->declBus(c+546,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+104,"pc", false,-1, 31,0);
    tracep->declBus(c+107,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+104,"pc", false,-1, 31,0);
    tracep->declBus(c+187,"imm", false,-1, 31,0);
    tracep->declBus(c+491,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+182,"inst", false,-1, 31,0);
    tracep->declBit(c+331,"valid_from", false,-1);
    tracep->declBit(c+181,"ready_from", false,-1);
    tracep->declBit(c+188,"ebreaksig", false,-1);
    tracep->declBit(c+190,"ecallsig", false,-1);
    tracep->declBit(c+189,"mretsig", false,-1);
    tracep->declBus(c+187,"imm", false,-1, 31,0);
    tracep->declBus(c+195,"func3", false,-1, 2,0);
    tracep->declBit(c+197,"func7", false,-1);
    tracep->declBus(c+184,"src1", false,-1, 4,0);
    tracep->declBus(c+185,"src2", false,-1, 4,0);
    tracep->declBus(c+186,"rd", false,-1, 4,0);
    tracep->declBit(c+192,"memew", false,-1);
    tracep->declBus(c+196,"muxsig", false,-1, 2,0);
    tracep->declBit(c+193,"memer", false,-1);
    tracep->declBit(c+191,"regew", false,-1);
    tracep->declBit(c+194,"muximm", false,-1);
    tracep->declBit(c+198,"btypebranch", false,-1);
    tracep->declBit(c+200,"jalrsig", false,-1);
    tracep->declBit(c+199,"jalsig", false,-1);
    tracep->declBus(c+202,"aluop", false,-1, 1,0);
    tracep->declBit(c+201,"auipcsig", false,-1);
    tracep->declBit(c+203,"csrrw", false,-1);
    tracep->declBit(c+204,"csrrs", false,-1);
    tracep->declBit(c+331,"valid_to", false,-1);
    tracep->declBit(c+181,"ready_to", false,-1);
    tracep->declBus(c+205,"memmask", false,-1, 2,0);
    tracep->declBit(c+206,"memsextsig", false,-1);
    tracep->declBit(c+188,"ebreak", false,-1);
    tracep->declBit(c+190,"ecall", false,-1);
    tracep->declBit(c+189,"mret", false,-1);
    tracep->declBus(c+195,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+197,"func7bridge", false,-1);
    tracep->declBus(c+253,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+182,"inst", false,-1, 31,0);
    tracep->declBit(c+188,"ebreaksig", false,-1);
    tracep->declBit(c+190,"ecallsig", false,-1);
    tracep->declBit(c+189,"mretsig", false,-1);
    tracep->declBus(c+187,"imm", false,-1, 31,0);
    tracep->declBus(c+253,"opcode", false,-1, 6,0);
    tracep->declBus(c+195,"func3", false,-1, 2,0);
    tracep->declBit(c+197,"func7", false,-1);
    tracep->declBus(c+184,"src1", false,-1, 4,0);
    tracep->declBus(c+185,"src2", false,-1, 4,0);
    tracep->declBus(c+186,"rd", false,-1, 4,0);
    tracep->declBus(c+205,"memmask", false,-1, 2,0);
    tracep->declBit(c+206,"memsextsig", false,-1);
    tracep->declBit(c+254,"type_I", false,-1);
    tracep->declBit(c+255,"type_R", false,-1);
    tracep->declBit(c+256,"type_U", false,-1);
    tracep->declBit(c+192,"type_S", false,-1);
    tracep->declBit(c+199,"type_J", false,-1);
    tracep->declBit(c+198,"type_B", false,-1);
    tracep->declBus(c+257,"I_imm", false,-1, 31,0);
    tracep->declBus(c+258,"U_imm", false,-1, 31,0);
    tracep->declBus(c+259,"S_imm", false,-1, 31,0);
    tracep->declBus(c+260,"J_imm", false,-1, 31,0);
    tracep->declBus(c+261,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+253,"opcode", false,-1, 6,0);
    tracep->declBus(c+195,"func3", false,-1, 2,0);
    tracep->declBit(c+197,"func7", false,-1);
    tracep->declBit(c+188,"ebreaksig", false,-1);
    tracep->declBit(c+190,"ecallsig", false,-1);
    tracep->declBit(c+189,"mretsig", false,-1);
    tracep->declBit(c+192,"memew", false,-1);
    tracep->declBus(c+196,"muxsig", false,-1, 2,0);
    tracep->declBit(c+193,"memer", false,-1);
    tracep->declBit(c+191,"regew", false,-1);
    tracep->declBit(c+194,"muximm", false,-1);
    tracep->declBit(c+198,"btypebranch", false,-1);
    tracep->declBit(c+200,"jalrsig", false,-1);
    tracep->declBit(c+199,"jalsig", false,-1);
    tracep->declBus(c+202,"aluop", false,-1, 1,0);
    tracep->declBit(c+201,"auipcsig", false,-1);
    tracep->declBit(c+203,"csrrw", false,-1);
    tracep->declBit(c+204,"csrrs", false,-1);
    tracep->declBit(c+254,"type_I", false,-1);
    tracep->declBit(c+255,"type_R", false,-1);
    tracep->declBit(c+256,"type_U", false,-1);
    tracep->declBit(c+192,"type_S", false,-1);
    tracep->declBit(c+199,"type_J", false,-1);
    tracep->declBit(c+198,"type_B", false,-1);
    tracep->declBit(c+193,"load", false,-1);
    tracep->declBit(c+192,"store", false,-1);
    tracep->declBit(c+262,"regwritepc", false,-1);
    tracep->declBit(c+193,"regwritemem", false,-1);
    tracep->declBit(c+263,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+516,"rst", false,-1);
    tracep->declBus(c+330,"npc", false,-1, 31,0);
    tracep->declBit(c+181,"ready", false,-1);
    tracep->declBus(c+104,"pc", false,-1, 31,0);
    tracep->declBus(c+182,"inst", false,-1, 31,0);
    tracep->declBit(c+331,"valid", false,-1);
    tracep->declBit(c+183,"regprocess", false,-1);
    tracep->declBit(c+181,"arvalid", false,-1);
    tracep->declBit(c+87,"arready", false,-1);
    tracep->declBus(c+330,"araddr", false,-1, 31,0);
    tracep->declBit(c+332,"rvalid", false,-1);
    tracep->declBit(c+181,"rready", false,-1);
    tracep->declBus(c+333,"rdata", false,-1, 31,0);
    tracep->declBus(c+104,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+332,"infetch_ready", false,-1);
    tracep->declBus(c+264,"state", false,-1, 1,0);
    tracep->declBus(c+182,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBus(c+330,"npc", false,-1, 31,0);
    tracep->declBit(c+516,"rst", false,-1);
    tracep->declBit(c+332,"ready_from", false,-1);
    tracep->declBus(c+104,"pcout", false,-1, 31,0);
    tracep->declBus(c+547,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+516,"rst", false,-1);
    tracep->declBit(c+311,"ew", false,-1);
    tracep->declBus(c+186,"addr", false,-1, 4,0);
    tracep->declBus(c+184,"src1", false,-1, 4,0);
    tracep->declBus(c+185,"src2", false,-1, 4,0);
    tracep->declBus(c+265,"csr", false,-1, 11,0);
    tracep->declBus(c+334,"data", false,-1, 31,0);
    tracep->declBit(c+203,"csrrw", false,-1);
    tracep->declBit(c+204,"csrrs", false,-1);
    tracep->declBit(c+190,"ecallsig", false,-1);
    tracep->declBit(c+331,"valid", false,-1);
    tracep->declBus(c+335,"regout1", false,-1, 31,0);
    tracep->declBus(c+336,"regout2", false,-1, 31,0);
    tracep->declBus(c+105,"mepc", false,-1, 31,0);
    tracep->declBus(c+106,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+108+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+140+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+266,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+502,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+527,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+548,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+518,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+266,"out", false,-1, 1,0);
    tracep->declBus(c+265,"key", false,-1, 11,0);
    tracep->declQuad(c+549,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+527,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+548,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+518,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+519,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+266,"out", false,-1, 1,0);
    tracep->declBus(c+265,"key", false,-1, 11,0);
    tracep->declBus(c+551,"default_out", false,-1, 1,0);
    tracep->declQuad(c+549,"lut", false,-1, 55,0);
    tracep->declBus(c+552,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+24+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+28+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+32+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+267,"lut_out", false,-1, 1,0);
    tracep->declBit(c+268,"hit", false,-1);
    tracep->declBus(c+531,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBit(c+516,"rst", false,-1);
    tracep->declBit(c+312,"ew", false,-1);
    tracep->declBit(c+203,"csrrw", false,-1);
    tracep->declBit(c+204,"csrrs", false,-1);
    tracep->declBit(c+190,"ecall", false,-1);
    tracep->declBus(c+266,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+186,"addr", false,-1, 4,0);
    tracep->declBus(c+502,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+144+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+176+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+180,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+515,"clk", false,-1);
    tracep->declBus(c+337,"res", false,-1, 31,0);
    tracep->declBus(c+336,"regout2", false,-1, 31,0);
    tracep->declBit(c+192,"memew", false,-1);
    tracep->declBit(c+193,"memer", false,-1);
    tracep->declBus(c+187,"imm", false,-1, 31,0);
    tracep->declBus(c+338,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+196,"muxsig", false,-1, 2,0);
    tracep->declBit(c+331,"valid_from", false,-1);
    tracep->declBus(c+205,"memmask", false,-1, 2,0);
    tracep->declBit(c+206,"memsextsig", false,-1);
    tracep->declBus(c+334,"regwrite", false,-1, 31,0);
    tracep->declBit(c+181,"ready_to", false,-1);
    tracep->declBit(c+271,"memvalid", false,-1);
    tracep->declBit(c+269,"awvalid", false,-1);
    tracep->declBit(c+91,"awready", false,-1);
    tracep->declBus(c+337,"awaddr", false,-1, 31,0);
    tracep->declBit(c+269,"wvalid", false,-1);
    tracep->declBit(c+92,"wready", false,-1);
    tracep->declBus(c+336,"wdata", false,-1, 31,0);
    tracep->declBus(c+270,"wstrb", false,-1, 3,0);
    tracep->declBit(c+103,"bvalid", false,-1);
    tracep->declBit(c+192,"bready", false,-1);
    tracep->declBit(c+503,"bresp", false,-1);
    tracep->declBit(c+517,"arvalid", false,-1);
    tracep->declBit(c+93,"arready", false,-1);
    tracep->declBus(c+337,"araddr", false,-1, 31,0);
    tracep->declBit(c+504,"rvalid", false,-1);
    tracep->declBit(c+193,"rready", false,-1);
    tracep->declBus(c+505,"rdata", false,-1, 31,0);
    tracep->declBus(c+506,"memread", false,-1, 31,0);
    tracep->declBit(c+85,"bresp_get", false,-1);
    tracep->declBit(c+86,"rvalid_get", false,-1);
    tracep->declBit(c+94,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+505,"data", false,-1, 31,0);
    tracep->declBus(c+205,"memmask", false,-1, 2,0);
    tracep->declBit(c+206,"memsextsig", false,-1);
    tracep->declBus(c+506,"read", false,-1, 31,0);
    tracep->declBus(c+507,"read_u", false,-1, 31,0);
    tracep->declBus(c+508,"read_s", false,-1, 31,0);
    tracep->declBus(c+509,"read_sb", false,-1, 31,0);
    tracep->declBus(c+510,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+553,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+534,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+511,"input_number", false,-1, 7,0);
    tracep->declBus(c+509,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+554,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+534,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+512,"input_number", false,-1, 15,0);
    tracep->declBus(c+510,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+527,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+520,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+534,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+334,"out", false,-1, 31,0);
    tracep->declBus(c+196,"key", false,-1, 2,0);
    tracep->declBus(c+519,"default_out", false,-1, 31,0);
    tracep->declArray(c+313,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+527,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+520,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+534,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+543,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+334,"out", false,-1, 31,0);
    tracep->declBus(c+196,"key", false,-1, 2,0);
    tracep->declBus(c+519,"default_out", false,-1, 31,0);
    tracep->declArray(c+313,"lut", false,-1, 139,0);
    tracep->declBus(c+555,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+318+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+36+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+326+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+513,"lut_out", false,-1, 31,0);
    tracep->declBit(c+514,"hit", false,-1);
    tracep->declBus(c+531,"i", false,-1, 31,0);
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
    VlWide<4>/*127:0*/ __Vtemp_h47d130a0__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[0]));
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[1]));
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__data0__DOT__bvalid_from_xbar[2]));
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),7);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),7);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),7);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),7);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list[3]),4);
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+15,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list[3]),3);
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[0]));
    bufp->fullBit(oldp+17,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[1]));
    bufp->fullBit(oldp+18,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid[2]));
    bufp->fullBit(oldp+19,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                           [2U]));
    bufp->fullBit(oldp+20,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                           [0U]));
    bufp->fullBit(oldp+21,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                           [1U]));
    bufp->fullBit(oldp+22,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+23,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullSData(oldp+24,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+25,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+26,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+27,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+28,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+29,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+30,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+31,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+32,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+33,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+34,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+35,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+37,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+38,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+39,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullBit(oldp+40,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[0]));
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[1]));
    bufp->fullBit(oldp+42,(vlSelf->top__DOT__data0__DOT__rvalid_from_xbar[2]));
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[0]));
    bufp->fullBit(oldp+44,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[1]));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__data0__DOT__awready_from_xbar[2]));
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[0]));
    bufp->fullBit(oldp+47,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[1]));
    bufp->fullBit(oldp+48,(vlSelf->top__DOT__data0__DOT__wready_from_xbar[2]));
    bufp->fullBit(oldp+49,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[0]));
    bufp->fullBit(oldp+50,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[1]));
    bufp->fullBit(oldp+51,(vlSelf->top__DOT__data0__DOT__arready_from_xbar[2]));
    bufp->fullBit(oldp+52,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[0]));
    bufp->fullBit(oldp+53,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[1]));
    bufp->fullBit(oldp+54,(vlSelf->top__DOT__data0__DOT__bresp_from_xbar[2]));
    bufp->fullBit(oldp+55,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+56,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+58,((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__client0__DOT__state)))));
    bufp->fullBit(oldp+59,(vlSelf->top__DOT__data0__DOT__client0__DOT__state));
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg[0]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg[1]),32);
    bufp->fullBit(oldp+62,(((~ (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy)) 
                            & (0U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state)))));
    bufp->fullBit(oldp+63,((2U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullBit(oldp+64,((1U == (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__state))));
    bufp->fullCData(oldp+65,(vlSelf->top__DOT__data0__DOT__mem0__DOT__state),2);
    bufp->fullCData(oldp+66,((0xfU & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))),4);
    bufp->fullBit(oldp+67,(vlSelf->top__DOT__data0__DOT__mem0__DOT__busy));
    bufp->fullCData(oldp+68,(vlSelf->top__DOT__data0__DOT__mem0__DOT__random_count),4);
    bufp->fullCData(oldp+69,(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num),8);
    bufp->fullBit(oldp+70,((1U & VL_REDXOR_8((0xb8U 
                                              & (IData)(vlSelf->top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num))))));
    bufp->fullBit(oldp+71,((1U & (~ (IData)(vlSelf->top__DOT__data0__DOT__uart0__DOT__state)))));
    bufp->fullBit(oldp+72,(vlSelf->top__DOT__data0__DOT__uart0__DOT__state));
    bufp->fullBit(oldp+73,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[0]));
    bufp->fullBit(oldp+74,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[1]));
    bufp->fullBit(oldp+75,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp[2]));
    bufp->fullBit(oldp+76,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[0]));
    bufp->fullBit(oldp+77,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[1]));
    bufp->fullBit(oldp+78,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid[2]));
    bufp->fullBit(oldp+79,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                           [2U]));
    bufp->fullBit(oldp+80,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                           [2U]));
    bufp->fullBit(oldp+81,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                           [0U]));
    bufp->fullBit(oldp+82,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                           [0U]));
    bufp->fullBit(oldp+83,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                           [1U]));
    bufp->fullBit(oldp+84,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                           [1U]));
    bufp->fullBit(oldp+85,(vlSelf->top__DOT__wbu0__DOT__bresp_get));
    bufp->fullBit(oldp+86,(vlSelf->top__DOT__wbu0__DOT__rvalid_get));
    bufp->fullBit(oldp+87,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                            & ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                               | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                   [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                  | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                     & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                     [0U]))))));
    bufp->fullCData(oldp+88,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                              & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                            | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                [2U] 
                                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                               | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                  [0U]))))))),2);
    bufp->fullCData(oldp+89,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                              & (- (IData)((((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                             [1U]) 
                                            | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                                & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                [2U]) 
                                               | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                  [0U]))))))),2);
    bufp->fullCData(oldp+90,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                              & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                            | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                [2U] 
                                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                               | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                  [0U]))))))),2);
    bufp->fullBit(oldp+91,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                   & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                  [1U] 
                                                  & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                 | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                     [2U] 
                                                     & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                    | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                       & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                       [0U])))))) 
                                  >> 1U))));
    bufp->fullBit(oldp+92,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                  [1U]) 
                                                 | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                                     & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                     [2U]) 
                                                    | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                       & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                       [0U])))))) 
                                  >> 1U))));
    bufp->fullBit(oldp+93,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                   & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                  [1U] 
                                                  & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                 | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                     [2U] 
                                                     & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                    | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                       & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                       [0U])))))) 
                                  >> 1U))));
    bufp->fullBit(oldp+94,((1U & ((((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (- (IData)(((
                                                   vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                   [1U] 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                  | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                      [2U] 
                                                      & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                     | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                        & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                                        [0U])))))) 
                                   & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                       & (- (IData)(
                                                    ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                      [1U] 
                                                      & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                     | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                         [2U] 
                                                         & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                        | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                                           [0U])))))) 
                                      & ((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                         & (- (IData)(
                                                      (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                                                        & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                        [1U]) 
                                                       | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                                           & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                           [2U]) 
                                                          | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                             [0U])))))))) 
                                  >> 1U))));
    bufp->fullCData(oldp+95,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                              & (- (IData)(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                            | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                [2U] 
                                                & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                               | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                  & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                  [0U]))))))),2);
    bufp->fullIData(oldp+96,(((IData)(vlSelf->top__DOT__data0__DOT__client0__DOT__state)
                               ? ((0xa0000048U == vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                                   [2U]) ? vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg
                                  [0U] : ((0xa000004fU 
                                           == vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                                           [2U]) ? 
                                          vlSelf->top__DOT__data0__DOT__client0__DOT__mtime_reg
                                          [1U] : 0U))
                               : 0U)),32);
    bufp->fullBit(oldp+97,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                            [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullBit(oldp+98,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                            [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullBit(oldp+99,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                            & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                            [0U])));
    bufp->fullBit(oldp+100,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                             [0U])));
    bufp->fullBit(oldp+101,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bresp
                             [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+102,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rvalid
                             [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+103,((1U & (((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__giant) 
                                    & (- (IData)(((
                                                   vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                   [1U] 
                                                   & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                                                  | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                      [2U] 
                                                      & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                                     | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                        & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                                        [0U])))))) 
                                   >> 1U))));
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+107,(((IData)(4U) + vlSelf->top__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+151,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+155,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+156,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+157,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+159,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+160,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+161,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+162,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+163,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+164,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+165,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+166,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+167,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+168,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+169,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+173,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+174,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+175,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+176,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+177,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+178,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+179,(vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+180,(vlSelf->top__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullBit(oldp+181,(vlSelf->top__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+182,(vlSelf->top__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+183,((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+184,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+185,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+186,((0x1fU & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+187,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+188,((0x100073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+189,((0x30200073U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+190,((0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+191,(((3U != (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                      | (IData)(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U)))))));
    bufp->fullBit(oldp+192,((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+193,((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+194,(vlSelf->top__DOT__muximm));
    bufp->fullCData(oldp+195,((7U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+196,(vlSelf->top__DOT__muxsig),3);
    bufp->fullBit(oldp+197,((1U & (vlSelf->top__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+198,((0x63U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+199,((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+200,((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+201,((0x17U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+202,(vlSelf->top__DOT__aluop),2);
    bufp->fullBit(oldp+203,(vlSelf->top__DOT__csrrw));
    bufp->fullBit(oldp+204,(vlSelf->top__DOT__csrrs));
    bufp->fullCData(oldp+205,(vlSelf->top__DOT__memmask),3);
    bufp->fullBit(oldp+206,(vlSelf->top__DOT__memsextsig));
    bufp->fullCData(oldp+207,(((IData)(vlSelf->top__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+208,(vlSelf->top__DOT__data0__DOT__arvalid_in),2);
    bufp->fullCData(oldp+209,((((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                << 1U) | (IData)(vlSelf->top__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+210,(((0x23U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+211,(vlSelf->top__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+212,(vlSelf->top__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+213,(vlSelf->top__DOT____Vcellinp__data0__wstrb[0]),4);
    bufp->fullCData(oldp+214,(vlSelf->top__DOT____Vcellinp__data0__wstrb[1]),4);
    bufp->fullBit(oldp+215,(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter));
    bufp->fullBit(oldp+216,(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter));
    bufp->fullBit(oldp+217,(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter));
    bufp->fullBit(oldp+218,(vlSelf->top__DOT__data0__DOT__rready_from_arbiter));
    bufp->fullBit(oldp+219,(vlSelf->top__DOT__data0__DOT__bready_from_arbiter));
    bufp->fullCData(oldp+220,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullCData(oldp+221,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+222,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullBit(oldp+223,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[0]));
    bufp->fullBit(oldp+224,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[1]));
    bufp->fullBit(oldp+225,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready[2]));
    bufp->fullBit(oldp+226,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[0]));
    bufp->fullBit(oldp+227,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[1]));
    bufp->fullBit(oldp+228,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready[2]));
    bufp->fullBit(oldp+229,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[0]));
    bufp->fullBit(oldp+230,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[1]));
    bufp->fullBit(oldp+231,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready[2]));
    bufp->fullBit(oldp+232,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                            [2U]));
    bufp->fullBit(oldp+233,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                            [2U]));
    bufp->fullBit(oldp+234,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                            [2U]));
    bufp->fullBit(oldp+235,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                            [0U]));
    bufp->fullBit(oldp+236,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                            [0U]));
    bufp->fullBit(oldp+237,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                            [0U]));
    bufp->fullBit(oldp+238,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                            [1U]));
    bufp->fullBit(oldp+239,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                            [1U]));
    bufp->fullBit(oldp+240,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                            [1U]));
    bufp->fullCData(oldp+241,(vlSelf->top__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+242,((1U & (~ (IData)(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+243,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+244,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+245,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+246,((1U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+247,((3U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+248,((2U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullBit(oldp+249,((0U == (IData)(vlSelf->top__DOT__aluop))));
    bufp->fullCData(oldp+250,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->top__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+251,(vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+252,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+253,((0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+254,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I));
    bufp->fullBit(oldp+255,((0x33U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+256,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U));
    bufp->fullIData(oldp+257,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+258,((0xfffff000U & vlSelf->top__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+259,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+260,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+261,(vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+262,(((0x67U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             | ((0x6fU == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                                   | (0x73U == vlSelf->top__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+263,((0x37U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+264,(vlSelf->top__DOT__ifu0__DOT__state),2);
    bufp->fullSData(oldp+265,((vlSelf->top__DOT__ifu0__DOT__inst_reg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+266,(vlSelf->top__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+267,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+268,(vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+269,(vlSelf->top__DOT____Vcellout__wbu0__awvalid));
    bufp->fullCData(oldp+270,(((1U == (IData)(vlSelf->top__DOT__memmask))
                                ? 1U : ((2U == (IData)(vlSelf->top__DOT__memmask))
                                         ? 2U : ((3U 
                                                  == (IData)(vlSelf->top__DOT__memmask))
                                                  ? 4U
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->top__DOT__memmask))
                                                   ? 8U
                                                   : 0U))))),4);
    bufp->fullBit(oldp+271,(((3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                >> 1U))));
    bufp->fullBit(oldp+272,(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                              [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                             | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                 [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                   & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                                   [0U])))));
    bufp->fullBit(oldp+273,((((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                              & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                              [1U]) | (((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                        & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                        [2U]) | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                                 & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                                                 [0U])))));
    bufp->fullBit(oldp+274,(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                              [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                             | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                 [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                   & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                                   [0U])))));
    bufp->fullBit(oldp+275,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullBit(oldp+276,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                             [1U])));
    bufp->fullBit(oldp+277,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullBit(oldp+278,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                             [0U])));
    bufp->fullBit(oldp+279,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                             [0U])));
    bufp->fullBit(oldp+280,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                             [0U])));
    bufp->fullBit(oldp+281,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_awready
                             [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+282,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_wready
                             [2U])));
    bufp->fullBit(oldp+283,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_arready
                             [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+284,(((IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+285,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
    bufp->fullCData(oldp+286,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),4);
    bufp->fullBit(oldp+287,(((IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+288,(((IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+289,(((IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullBit(oldp+290,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter))));
    bufp->fullBit(oldp+291,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
    bufp->fullCData(oldp+292,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),4);
    bufp->fullBit(oldp+293,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter))));
    bufp->fullBit(oldp+294,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter))));
    bufp->fullBit(oldp+295,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter))));
    bufp->fullBit(oldp+296,(((IData)(vlSelf->top__DOT__data0__DOT__awvalid_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullBit(oldp+297,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__wvalid_from_arbiter))));
    bufp->fullCData(oldp+298,(((IData)(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg) 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),4);
    bufp->fullBit(oldp+299,(((IData)(vlSelf->top__DOT__data0__DOT__bready_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullBit(oldp+300,(((IData)(vlSelf->top__DOT__data0__DOT__arvalid_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullBit(oldp+301,(((IData)(vlSelf->top__DOT__data0__DOT__rready_from_arbiter) 
                             & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    __Vtemp_h44c198b2__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->top__DOT__imm))));
    __Vtemp_h44c198b2__0[1U] = ((vlSelf->top__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->top__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h44c198b2__0[2U] = (vlSelf->top__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+302,(__Vtemp_h44c198b2__0),66);
    bufp->fullQData(oldp+305,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+307,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+309,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+310,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullBit(oldp+311,((((1U == (IData)(vlSelf->top__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+312,(((IData)(vlSelf->top__DOT__ifu_valid) 
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
    bufp->fullWData(oldp+313,(__Vtemp_hdaf246d3__0),140);
    bufp->fullQData(oldp+318,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+320,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+322,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+324,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+326,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+327,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+328,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+329,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+330,(vlSelf->top__DOT__npc),32);
    bufp->fullBit(oldp+331,(vlSelf->top__DOT__ifu_valid));
    bufp->fullBit(oldp+332,((1U & (IData)(vlSelf->top__DOT__data0__DOT__rvalid_out))));
    bufp->fullIData(oldp+333,(vlSelf->top__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+334,(vlSelf->top__DOT__regwrite),32);
    bufp->fullIData(oldp+335,(vlSelf->top__DOT__regout1),32);
    bufp->fullIData(oldp+336,(vlSelf->top__DOT__regout2),32);
    bufp->fullIData(oldp+337,(vlSelf->top__DOT__res),32);
    bufp->fullIData(oldp+338,(vlSelf->top__DOT__pcwritereg),32);
    bufp->fullCData(oldp+339,(vlSelf->top__DOT__data0__DOT__rvalid_out),2);
    bufp->fullIData(oldp+340,(vlSelf->top__DOT__araddr[0]),32);
    bufp->fullIData(oldp+341,(vlSelf->top__DOT__araddr[1]),32);
    bufp->fullIData(oldp+342,(vlSelf->top__DOT__rdata[0]),32);
    bufp->fullIData(oldp+343,(vlSelf->top__DOT__rdata[1]),32);
    bufp->fullIData(oldp+344,(vlSelf->top__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+345,(vlSelf->top__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+346,(vlSelf->top__DOT__wdata[0]),32);
    bufp->fullIData(oldp+347,(vlSelf->top__DOT__wdata[1]),32);
    bufp->fullBit(oldp+348,(vlSelf->top__DOT__bresp[0]));
    bufp->fullBit(oldp+349,(vlSelf->top__DOT__bresp[1]));
    bufp->fullIData(oldp+350,(vlSelf->top__DOT____Vcellinp__data0__araddr[0]),32);
    bufp->fullIData(oldp+351,(vlSelf->top__DOT____Vcellinp__data0__araddr[1]),32);
    bufp->fullIData(oldp+352,(vlSelf->top__DOT____Vcellout__data0__rdata[0]),32);
    bufp->fullIData(oldp+353,(vlSelf->top__DOT____Vcellout__data0__rdata[1]),32);
    bufp->fullIData(oldp+354,(vlSelf->top__DOT____Vcellinp__data0__awaddr[0]),32);
    bufp->fullIData(oldp+355,(vlSelf->top__DOT____Vcellinp__data0__awaddr[1]),32);
    bufp->fullIData(oldp+356,(vlSelf->top__DOT____Vcellinp__data0__wdata[0]),32);
    bufp->fullIData(oldp+357,(vlSelf->top__DOT____Vcellinp__data0__wdata[1]),32);
    bufp->fullBit(oldp+358,(vlSelf->top__DOT____Vcellout__data0__bresp[0]));
    bufp->fullBit(oldp+359,(vlSelf->top__DOT____Vcellout__data0__bresp[1]));
    bufp->fullBit(oldp+360,(vlSelf->top__DOT__data0__DOT__rvalid_from_arbiter));
    bufp->fullBit(oldp+361,(((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                              [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig)) 
                             | ((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                 [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig)) 
                                | ((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                                   & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                                   [0U])))));
    bufp->fullIData(oldp+362,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullIData(oldp+363,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+364,(vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullIData(oldp+365,((vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_urt 
                               | (vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_client 
                                  | vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_sram))),32);
    bufp->fullBit(oldp+366,(vlSelf->top__DOT__data0__DOT__bresp_from_arbiter));
    bufp->fullBit(oldp+367,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[0]));
    bufp->fullBit(oldp+368,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[1]));
    bufp->fullBit(oldp+369,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar[2]));
    bufp->fullBit(oldp+370,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[0]));
    bufp->fullBit(oldp+371,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[1]));
    bufp->fullBit(oldp+372,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar[2]));
    bufp->fullBit(oldp+373,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[0]));
    bufp->fullBit(oldp+374,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[1]));
    bufp->fullBit(oldp+375,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar[2]));
    bufp->fullBit(oldp+376,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[0]));
    bufp->fullBit(oldp+377,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[1]));
    bufp->fullBit(oldp+378,(vlSelf->top__DOT__data0__DOT__rready_from_xbar[2]));
    bufp->fullBit(oldp+379,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[0]));
    bufp->fullBit(oldp+380,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[1]));
    bufp->fullBit(oldp+381,(vlSelf->top__DOT__data0__DOT__bready_from_xbar[2]));
    bufp->fullIData(oldp+382,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[0]),32);
    bufp->fullIData(oldp+383,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[1]),32);
    bufp->fullIData(oldp+384,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar[2]),32);
    bufp->fullIData(oldp+385,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[0]),32);
    bufp->fullIData(oldp+386,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[1]),32);
    bufp->fullIData(oldp+387,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar[2]),32);
    bufp->fullIData(oldp+388,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[0]),32);
    bufp->fullIData(oldp+389,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[1]),32);
    bufp->fullIData(oldp+390,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar[2]),32);
    bufp->fullIData(oldp+391,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[0]),32);
    bufp->fullIData(oldp+392,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[1]),32);
    bufp->fullIData(oldp+393,(vlSelf->top__DOT__data0__DOT__rdata_from_xbar[2]),32);
    bufp->fullCData(oldp+394,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[0]),4);
    bufp->fullCData(oldp+395,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[1]),4);
    bufp->fullCData(oldp+396,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar[2]),4);
    bufp->fullIData(oldp+397,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+398,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+399,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+400,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+401,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+402,(vlSelf->top__DOT__data0__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullIData(oldp+403,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+404,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullBit(oldp+405,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[0]));
    bufp->fullBit(oldp+406,(vlSelf->top__DOT__data0__DOT____Vcellout__arviter0__bresp[1]));
    bufp->fullBit(oldp+407,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                            [2U]));
    bufp->fullIData(oldp+408,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                              [2U]),32);
    bufp->fullBit(oldp+409,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                            [2U]));
    bufp->fullIData(oldp+410,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                              [2U]),32);
    bufp->fullCData(oldp+411,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                              [2U]),4);
    bufp->fullBit(oldp+412,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                            [2U]));
    bufp->fullBit(oldp+413,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                            [2U]));
    bufp->fullIData(oldp+414,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                              [2U]),32);
    bufp->fullBit(oldp+415,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                            [2U]));
    bufp->fullBit(oldp+416,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                            [0U]));
    bufp->fullIData(oldp+417,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                              [0U]),32);
    bufp->fullBit(oldp+418,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                            [0U]));
    bufp->fullIData(oldp+419,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                              [0U]),32);
    bufp->fullCData(oldp+420,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                              [0U]),4);
    bufp->fullBit(oldp+421,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                            [0U]));
    bufp->fullBit(oldp+422,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                            [0U]));
    bufp->fullIData(oldp+423,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                              [0U]),32);
    bufp->fullBit(oldp+424,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                            [0U]));
    bufp->fullIData(oldp+425,(vlSelf->top__DOT__data0__DOT__mem0__DOT__rdatareg),32);
    bufp->fullCData(oldp+426,(vlSelf->top__DOT__data0__DOT__mem0__DOT__memmask),3);
    bufp->fullCData(oldp+427,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+428,(vlSelf->top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+429,(vlSelf->top__DOT__data0__DOT__awvalid_from_xbar
                            [1U]));
    bufp->fullIData(oldp+430,(vlSelf->top__DOT__data0__DOT__awaddr_from_xbar
                              [1U]),32);
    bufp->fullBit(oldp+431,(vlSelf->top__DOT__data0__DOT__wvalid_from_xbar
                            [1U]));
    bufp->fullIData(oldp+432,(vlSelf->top__DOT__data0__DOT__wdata_from_xbar
                              [1U]),32);
    bufp->fullCData(oldp+433,(vlSelf->top__DOT__data0__DOT__wstrb_from_xbar
                              [1U]),4);
    bufp->fullBit(oldp+434,(vlSelf->top__DOT__data0__DOT__bready_from_xbar
                            [1U]));
    bufp->fullBit(oldp+435,(vlSelf->top__DOT__data0__DOT__arvalid_from_xbar
                            [1U]));
    bufp->fullIData(oldp+436,(vlSelf->top__DOT__data0__DOT__araddr_from_xbar
                              [1U]),32);
    bufp->fullBit(oldp+437,(vlSelf->top__DOT__data0__DOT__rready_from_xbar
                            [1U]));
    bufp->fullBit(oldp+438,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[0]));
    bufp->fullBit(oldp+439,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[1]));
    bufp->fullBit(oldp+440,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awvalid[2]));
    bufp->fullIData(oldp+441,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[0]),32);
    bufp->fullIData(oldp+442,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[1]),32);
    bufp->fullIData(oldp+443,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_awaddr[2]),32);
    bufp->fullBit(oldp+444,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[0]));
    bufp->fullBit(oldp+445,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[1]));
    bufp->fullBit(oldp+446,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wvalid[2]));
    bufp->fullIData(oldp+447,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[0]),32);
    bufp->fullIData(oldp+448,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[1]),32);
    bufp->fullIData(oldp+449,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wdata[2]),32);
    bufp->fullCData(oldp+450,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[0]),4);
    bufp->fullCData(oldp+451,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[1]),4);
    bufp->fullCData(oldp+452,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_wstrb[2]),4);
    bufp->fullBit(oldp+453,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[0]));
    bufp->fullBit(oldp+454,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[1]));
    bufp->fullBit(oldp+455,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_bready[2]));
    bufp->fullBit(oldp+456,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[0]));
    bufp->fullBit(oldp+457,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[1]));
    bufp->fullBit(oldp+458,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_arvalid[2]));
    bufp->fullIData(oldp+459,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[0]),32);
    bufp->fullIData(oldp+460,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[1]),32);
    bufp->fullIData(oldp+461,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_araddr[2]),32);
    bufp->fullBit(oldp+462,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[0]));
    bufp->fullBit(oldp+463,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[1]));
    bufp->fullBit(oldp+464,(vlSelf->top__DOT__data0__DOT____Vcellout__xbar__s_rready[2]));
    bufp->fullIData(oldp+465,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[0]),32);
    bufp->fullIData(oldp+466,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[1]),32);
    bufp->fullIData(oldp+467,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata[2]),32);
    bufp->fullBit(oldp+468,(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram));
    bufp->fullCData(oldp+469,((((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig) 
                                << 1U) | (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))),2);
    bufp->fullBit(oldp+470,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                             [1U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))));
    bufp->fullIData(oldp+471,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_urt),32);
    bufp->fullBit(oldp+472,(((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram) 
                             & vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                             [0U])));
    bufp->fullIData(oldp+473,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_sram),32);
    bufp->fullBit(oldp+474,((vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_bvalid
                             [2U] & (IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))));
    bufp->fullIData(oldp+475,(vlSelf->top__DOT__data0__DOT__xbar__DOT__m_rdata_client),32);
    bufp->fullBit(oldp+476,(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig));
    bufp->fullIData(oldp+477,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),32);
    bufp->fullIData(oldp+478,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),32);
    bufp->fullIData(oldp+479,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__client_input__sig))))),32);
    bufp->fullIData(oldp+480,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                              [2U]),32);
    bufp->fullIData(oldp+481,(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__mux__data),32);
    bufp->fullIData(oldp+482,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),32);
    bufp->fullIData(oldp+483,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),32);
    bufp->fullIData(oldp+484,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT__sig_sram))))),32);
    bufp->fullIData(oldp+485,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                              [0U]),32);
    bufp->fullBit(oldp+486,(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig));
    bufp->fullIData(oldp+487,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),32);
    bufp->fullIData(oldp+488,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),32);
    bufp->fullIData(oldp+489,((vlSelf->top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg 
                               & (- (IData)((IData)(vlSelf->top__DOT__data0__DOT__xbar__DOT____Vcellinp__urt_input__sig))))),32);
    bufp->fullIData(oldp+490,(vlSelf->top__DOT__data0__DOT____Vcellinp__xbar__s_rdata
                              [1U]),32);
    bufp->fullIData(oldp+491,(vlSelf->top__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+492,(vlSelf->top__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+493,((0U == vlSelf->top__DOT__res)));
    bufp->fullBit(oldp+494,((vlSelf->top__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+495,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+496,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+497,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+498,((0U == vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+499,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+500,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+501,(vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+502,(vlSelf->top__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullBit(oldp+503,(vlSelf->top__DOT__bresp
                            [1U]));
    bufp->fullBit(oldp+504,((1U & ((IData)(vlSelf->top__DOT__data0__DOT__rvalid_out) 
                                   >> 1U))));
    bufp->fullIData(oldp+505,(vlSelf->top__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+506,(vlSelf->top__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+507,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+508,(vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+509,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->top__DOT__rdata
                                          [1U]))),32);
    bufp->fullIData(oldp+510,((((- (IData)((1U & (vlSelf->top__DOT__rdata
                                                  [1U] 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->top__DOT__rdata
                                             [1U]))),32);
    bufp->fullCData(oldp+511,((0xffU & vlSelf->top__DOT__rdata
                               [1U])),8);
    bufp->fullSData(oldp+512,((0xffffU & vlSelf->top__DOT__rdata
                               [1U])),16);
    bufp->fullIData(oldp+513,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+514,(vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+515,(vlSelf->clk));
    bufp->fullBit(oldp+516,(vlSelf->rst));
    bufp->fullBit(oldp+517,(((~ (IData)(vlSelf->top__DOT__wbu0__DOT__rvalid_get)) 
                             & (3U == (0x7fU & vlSelf->top__DOT__ifu0__DOT__inst_reg)))));
    bufp->fullIData(oldp+518,(2U),32);
    bufp->fullIData(oldp+519,(0U),32);
    bufp->fullIData(oldp+520,(3U),32);
    bufp->fullIData(oldp+521,(2U),32);
    bufp->fullBit(oldp+522,(vlSelf->top__DOT__data0__DOT____Vcellout__client0__awready));
    bufp->fullBit(oldp+523,(vlSelf->top__DOT__data0__DOT____Vcellout__client0__wready));
    bufp->fullBit(oldp+524,(vlSelf->top__DOT__data0__DOT____Vcellout__client0__bvalid));
    bufp->fullBit(oldp+525,(0U));
    bufp->fullBit(oldp+526,(vlSelf->top__DOT__data0__DOT____Vcellout__mem0__bvalid));
    bufp->fullIData(oldp+527,(4U),32);
    bufp->fullIData(oldp+528,(0x12491c4U),28);
    bufp->fullCData(oldp+529,(0U),3);
    bufp->fullIData(oldp+530,(7U),32);
    bufp->fullIData(oldp+531,(4U),32);
    bufp->fullBit(oldp+532,(vlSelf->top__DOT__data0__DOT____Vcellout__uart0__bvalid));
    bufp->fullBit(oldp+533,(vlSelf->top__DOT__data0__DOT____Vcellout__uart0__arready));
    bufp->fullIData(oldp+534,(0x20U),32);
    __Vtemp_h47d130a0__0[0U] = 0xa000004fU;
    __Vtemp_h47d130a0__0[1U] = 0xa0000048U;
    __Vtemp_h47d130a0__0[2U] = 0xa00003ffU;
    __Vtemp_h47d130a0__0[3U] = 0xa00003f8U;
    bufp->fullWData(oldp+535,(__Vtemp_h47d130a0__0),128);
    bufp->fullIData(oldp+539,(0xa000004fU),32);
    bufp->fullIData(oldp+540,(0xa0000048U),32);
    bufp->fullIData(oldp+541,(0xa00003ffU),32);
    bufp->fullIData(oldp+542,(0xa00003f8U),32);
    bufp->fullIData(oldp+543,(1U),32);
    bufp->fullIData(oldp+544,(0U),32);
    bufp->fullIData(oldp+545,(0x21U),32);
    bufp->fullIData(oldp+546,(2U),32);
    bufp->fullIData(oldp+547,(0x7ffffffcU),32);
    bufp->fullIData(oldp+548,(0xcU),32);
    bufp->fullQData(oldp+549,(0x3000c153418d0bULL),56);
    bufp->fullCData(oldp+551,(0U),2);
    bufp->fullIData(oldp+552,(0xeU),32);
    bufp->fullIData(oldp+553,(8U),32);
    bufp->fullIData(oldp+554,(0x10U),32);
    bufp->fullIData(oldp+555,(0x23U),32);
}
