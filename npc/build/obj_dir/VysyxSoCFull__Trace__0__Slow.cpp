// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VysyxSoCFull__Syms.h"


VL_ATTR_COLD void VysyxSoCFull___024root__trace_init_sub__TOP__0(VysyxSoCFull___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+1072,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1073,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1074,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1075,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1076,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1077,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1078,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1079,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1080,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1081,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1082,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1083,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1084,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1085,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1086,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1087,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1088,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1089,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1090,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1091,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+1072,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1073,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1074,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1075,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1076,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1077,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1078,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1079,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1080,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1081,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1082,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1083,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1084,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1085,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1086,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1087,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1088,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1089,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1090,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1091,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+388,"spi_sck", false,-1);
    tracep->declBus(c+389,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1092,"spi_mosi", false,-1);
    tracep->declBit(c+1093,"spi_miso", false,-1);
    tracep->declBit(c+1090,"uart_rx", false,-1);
    tracep->declBit(c+1091,"uart_tx", false,-1);
    tracep->declBit(c+1094,"psram_sck", false,-1);
    tracep->declBit(c+1095,"psram_ce_n", false,-1);
    tracep->declBus(c+941,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1096,"sdram_clk", false,-1);
    tracep->declBit(c+390,"sdram_cke", false,-1);
    tracep->declBit(c+391,"sdram_cs", false,-1);
    tracep->declBit(c+392,"sdram_ras", false,-1);
    tracep->declBit(c+393,"sdram_cas", false,-1);
    tracep->declBit(c+394,"sdram_we", false,-1);
    tracep->declBus(c+395,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+396,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+397,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+398,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1072,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1073,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1074,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1075,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1076,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1077,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1078,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1079,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1080,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1081,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1082,"ps2_clk", false,-1);
    tracep->declBit(c+1083,"ps2_data", false,-1);
    tracep->declBus(c+1084,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1085,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1086,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1087,"vga_hsync", false,-1);
    tracep->declBit(c+1088,"vga_vsync", false,-1);
    tracep->declBit(c+1089,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+825,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+826,"in_psel", false,-1);
    tracep->declBit(c+25,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+942,"in_pready", false,-1);
    tracep->declBus(c+943,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+830,"in_pslverr", false,-1);
    tracep->declBus(c+825,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+826,"out_psel", false,-1);
    tracep->declBit(c+25,"out_penable", false,-1);
    tracep->declBus(c+1118,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"out_pwrite", false,-1);
    tracep->declBus(c+828,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+942,"out_pready", false,-1);
    tracep->declBus(c+943,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+830,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+826,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+25,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+825,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1118,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+942,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+830,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+943,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+831,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+345,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+825,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1118,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+399,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1119,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+400,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+832,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+346,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+833,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1118,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1120,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1121,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1122,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+834,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+347,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+835,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1118,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1123,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1124,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1125,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+836,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+348,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+835,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1118,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+1126,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1127,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1128,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+837,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+349,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+825,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1118,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1097,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1119,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+26,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+838,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+839,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+835,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1118,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+840,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1119,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1098,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+841,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+842,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+827,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+833,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1118,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+401,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1119,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+402,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+843,"sel_0", false,-1);
    tracep->declBit(c+844,"sel_1", false,-1);
    tracep->declBit(c+845,"sel_2", false,-1);
    tracep->declBit(c+846,"sel_3", false,-1);
    tracep->declBit(c+847,"sel_4", false,-1);
    tracep->declBit(c+848,"sel_5", false,-1);
    tracep->declBit(c+849,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+850,"auto_in_awready", false,-1);
    tracep->declBit(c+851,"auto_in_awvalid", false,-1);
    tracep->declBus(c+27,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+852,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+28,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+850,"auto_in_wready", false,-1);
    tracep->declBit(c+853,"auto_in_wvalid", false,-1);
    tracep->declBus(c+854,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+944,"auto_in_bready", false,-1);
    tracep->declBit(c+945,"auto_in_bvalid", false,-1);
    tracep->declBus(c+29,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+350,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+855,"auto_in_arready", false,-1);
    tracep->declBit(c+856,"auto_in_arvalid", false,-1);
    tracep->declBus(c+30,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+857,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+31,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+946,"auto_in_rready", false,-1);
    tracep->declBit(c+947,"auto_in_rvalid", false,-1);
    tracep->declBus(c+32,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+948,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+350,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+826,"auto_out_psel", false,-1);
    tracep->declBit(c+25,"auto_out_penable", false,-1);
    tracep->declBit(c+827,"auto_out_pwrite", false,-1);
    tracep->declBus(c+825,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+828,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+942,"auto_out_pready", false,-1);
    tracep->declBit(c+830,"auto_out_pslverr", false,-1);
    tracep->declBus(c+943,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+25,"nodeOut_penable", false,-1);
    tracep->declBus(c+33,"state", false,-1, 1,0);
    tracep->declBit(c+855,"accept_read", false,-1);
    tracep->declBit(c+850,"accept_write", false,-1);
    tracep->declBit(c+34,"is_write_r", false,-1);
    tracep->declBit(c+827,"is_write", false,-1);
    tracep->declBus(c+32,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+29,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+35,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+36,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+37,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+38,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+858,"resp", false,-1, 1,0);
    tracep->declBus(c+39,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+350,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+947,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+40,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+945,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+41,"auto_in_awready", false,-1);
    tracep->declBit(c+711,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1129,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+859,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1130,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1131,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1132,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+42,"auto_in_wready", false,-1);
    tracep->declBit(c+712,"auto_in_wvalid", false,-1);
    tracep->declBus(c+860,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+713,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1133,"auto_in_wlast", false,-1);
    tracep->declBit(c+1099,"auto_in_bready", false,-1);
    tracep->declBit(c+949,"auto_in_bvalid", false,-1);
    tracep->declBus(c+950,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+951,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+43,"auto_in_arready", false,-1);
    tracep->declBit(c+714,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1134,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+861,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1135,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1136,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1137,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+715,"auto_in_rready", false,-1);
    tracep->declBit(c+952,"auto_in_rvalid", false,-1);
    tracep->declBus(c+953,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+352,"auto_in_rlast", false,-1);
    tracep->declBit(c+954,"auto_out_awready", false,-1);
    tracep->declBit(c+716,"auto_out_awvalid", false,-1);
    tracep->declBus(c+27,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+852,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+28,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+44,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+955,"auto_out_wready", false,-1);
    tracep->declBit(c+717,"auto_out_wvalid", false,-1);
    tracep->declBus(c+854,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+718,"auto_out_wlast", false,-1);
    tracep->declBit(c+956,"auto_out_bready", false,-1);
    tracep->declBit(c+957,"auto_out_bvalid", false,-1);
    tracep->declBus(c+950,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+958,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+959,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+960,"auto_out_arready", false,-1);
    tracep->declBit(c+719,"auto_out_arvalid", false,-1);
    tracep->declBus(c+30,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+857,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+31,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+45,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+715,"auto_out_rready", false,-1);
    tracep->declBit(c+952,"auto_out_rvalid", false,-1);
    tracep->declBus(c+953,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+353,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+961,"auto_out_rlast", false,-1);
    tracep->declBit(c+717,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+46,"w_idle", false,-1);
    tracep->declBit(c+962,"in_awready", false,-1);
    tracep->declBit(c+47,"busy", false,-1);
    tracep->declBus(c+48,"r_addr", false,-1, 31,0);
    tracep->declBus(c+49,"r_len", false,-1, 7,0);
    tracep->declBus(c+50,"len", false,-1, 7,0);
    tracep->declBus(c+862,"addr", false,-1, 31,0);
    tracep->declBit(c+51,"busy_1", false,-1);
    tracep->declBus(c+52,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+53,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+54,"len_1", false,-1, 7,0);
    tracep->declBus(c+863,"addr_1", false,-1, 31,0);
    tracep->declBit(c+55,"wbeats_latched", false,-1);
    tracep->declBit(c+716,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+720,"wbeats_valid", false,-1);
    tracep->declBus(c+56,"w_counter", false,-1, 8,0);
    tracep->declBus(c+721,"w_todo", false,-1, 8,0);
    tracep->declBit(c+718,"w_last", false,-1);
    tracep->declBit(c+956,"nodeOut_bready", false,-1);
    tracep->declBus(c+57,"error_0", false,-1, 1,0);
    tracep->declBus(c+58,"error_1", false,-1, 1,0);
    tracep->declBus(c+59,"error_2", false,-1, 1,0);
    tracep->declBus(c+60,"error_3", false,-1, 1,0);
    tracep->declBus(c+61,"error_4", false,-1, 1,0);
    tracep->declBus(c+62,"error_5", false,-1, 1,0);
    tracep->declBus(c+63,"error_6", false,-1, 1,0);
    tracep->declBus(c+64,"error_7", false,-1, 1,0);
    tracep->declBus(c+65,"error_8", false,-1, 1,0);
    tracep->declBus(c+66,"error_9", false,-1, 1,0);
    tracep->declBus(c+67,"error_10", false,-1, 1,0);
    tracep->declBus(c+68,"error_11", false,-1, 1,0);
    tracep->declBus(c+69,"error_12", false,-1, 1,0);
    tracep->declBus(c+70,"error_13", false,-1, 1,0);
    tracep->declBus(c+71,"error_14", false,-1, 1,0);
    tracep->declBus(c+72,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+43,"io_enq_ready", false,-1);
    tracep->declBit(c+714,"io_enq_valid", false,-1);
    tracep->declBus(c+1134,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+861,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1135,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1136,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1137,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+963,"io_deq_ready", false,-1);
    tracep->declBit(c+719,"io_deq_valid", false,-1);
    tracep->declBus(c+30,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+864,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+73,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+31,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+74,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+75,"ram", false,-1, 48,0);
    tracep->declBit(c+77,"full", false,-1);
    tracep->declBit(c+719,"io_deq_valid_0", false,-1);
    tracep->declBit(c+964,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+41,"io_enq_ready", false,-1);
    tracep->declBit(c+711,"io_enq_valid", false,-1);
    tracep->declBus(c+1129,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+859,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1130,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1131,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1132,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+965,"io_deq_ready", false,-1);
    tracep->declBit(c+722,"io_deq_valid", false,-1);
    tracep->declBus(c+27,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+865,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+78,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+28,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+79,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+80,"ram", false,-1, 48,0);
    tracep->declBit(c+82,"full", false,-1);
    tracep->declBit(c+722,"io_deq_valid_0", false,-1);
    tracep->declBit(c+966,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+42,"io_enq_ready", false,-1);
    tracep->declBit(c+712,"io_enq_valid", false,-1);
    tracep->declBus(c+860,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+713,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1133,"io_enq_bits_last", false,-1);
    tracep->declBit(c+967,"io_deq_ready", false,-1);
    tracep->declBit(c+723,"io_deq_valid", false,-1);
    tracep->declBus(c+854,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+710,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+83,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+84,"ram", false,-1, 36,0);
    tracep->declBit(c+86,"full", false,-1);
    tracep->declBit(c+723,"io_deq_valid_0", false,-1);
    tracep->declBit(c+968,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk3 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk4 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk5 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4ram ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+969,"auto_in_awready", false,-1);
    tracep->declBit(c+866,"auto_in_awvalid", false,-1);
    tracep->declBus(c+27,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+867,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1101,"auto_in_wready", false,-1);
    tracep->declBit(c+794,"auto_in_wvalid", false,-1);
    tracep->declBus(c+854,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+970,"auto_in_bready", false,-1);
    tracep->declBit(c+87,"auto_in_bvalid", false,-1);
    tracep->declBus(c+88,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+89,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+971,"auto_in_arready", false,-1);
    tracep->declBit(c+795,"auto_in_arvalid", false,-1);
    tracep->declBus(c+30,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+868,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+972,"auto_in_rready", false,-1);
    tracep->declBit(c+90,"auto_in_rvalid", false,-1);
    tracep->declBus(c+91,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+92,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+93,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+971,"nodeIn_arready", false,-1);
    tracep->declBit(c+969,"nodeIn_awready", false,-1);
    tracep->declBit(c+869,"w_sel0", false,-1);
    tracep->declBit(c+87,"w_full", false,-1);
    tracep->declBus(c+88,"w_id", false,-1, 3,0);
    tracep->declBit(c+94,"r_sel1", false,-1);
    tracep->declBit(c+95,"w_sel1", false,-1);
    tracep->declBit(c+90,"r_full", false,-1);
    tracep->declBus(c+91,"r_id", false,-1, 3,0);
    tracep->declBit(c+973,"ren", false,-1);
    tracep->declBit(c+96,"rdata_REG", false,-1);
    tracep->declBus(c+97,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+98,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+99,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+100,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+870,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+973,"R0_en", false,-1);
    tracep->declBit(c+1070,"R0_clk", false,-1);
    tracep->declBus(c+101,"R0_data", false,-1, 31,0);
    tracep->declBus(c+871,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+974,"W0_en", false,-1);
    tracep->declBit(c+1070,"W0_clk", false,-1);
    tracep->declBus(c+854,"W0_data", false,-1, 31,0);
    tracep->declBus(c+710,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+41,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+711,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1129,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+859,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1130,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1131,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1132,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+42,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+712,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+860,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+713,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1133,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1099,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+949,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+950,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+951,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+43,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+714,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1134,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+861,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1135,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1136,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1137,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+715,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+952,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+953,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+352,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+41,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+711,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1129,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+859,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1130,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1131,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1132,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+42,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+712,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+860,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+713,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1133,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1099,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+949,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+950,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+951,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+43,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+714,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1134,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+861,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1135,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1136,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1137,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+715,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+952,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+953,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+352,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+975,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+724,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+27,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+852,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+28,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+955,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+717,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+854,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+718,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+956,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+957,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+950,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+958,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+976,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+725,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+30,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+857,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+31,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+715,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+952,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+953,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+961,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+969,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+866,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+27,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+867,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1101,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+794,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+854,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+970,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+87,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+88,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+89,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+971,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+795,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+30,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+868,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+972,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+90,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+91,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+92,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+93,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+796,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+797,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+102,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+798,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+30,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+872,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1102,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+103,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+104,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+105,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+850,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+851,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+27,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+852,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+28,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+850,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+853,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+854,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+944,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+945,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+29,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+350,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+855,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+856,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+30,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+857,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+31,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+946,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+947,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+32,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+948,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+350,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+957,"in_0_bvalid", false,-1);
    tracep->declBit(c+952,"in_0_rvalid", false,-1);
    tracep->declBit(c+977,"in_0_wready", false,-1);
    tracep->declBit(c+978,"in_0_awready", false,-1);
    tracep->declBit(c+976,"in_0_arready", false,-1);
    tracep->declBit(c+975,"anonIn_awready", false,-1);
    tracep->declBit(c+873,"requestARIO_0_0", false,-1);
    tracep->declBit(c+874,"requestARIO_0_1", false,-1);
    tracep->declBit(c+875,"requestARIO_0_2", false,-1);
    tracep->declBit(c+876,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+877,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+878,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+106,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+107,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+108,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+109,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+110,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+111,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+112,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+113,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+114,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+115,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+116,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+117,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+118,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+119,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+120,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+121,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+122,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+123,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+124,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+125,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+126,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+127,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+128,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+129,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+130,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+131,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+132,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+133,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+134,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+135,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+136,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+137,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+138,"latched", false,-1);
    tracep->declBit(c+726,"in_0_awvalid", false,-1);
    tracep->declBit(c+727,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+728,"in_0_wvalid", false,-1);
    tracep->declBit(c+139,"idle_3", false,-1);
    tracep->declBit(c+979,"anyValid", false,-1);
    tracep->declBus(c+980,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+140,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+981,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+982,"prefixOR_1", false,-1);
    tracep->declBit(c+983,"winner_3_1", false,-1);
    tracep->declBit(c+984,"winner_3_2", false,-1);
    tracep->declBit(c+141,"state_3_0", false,-1);
    tracep->declBit(c+142,"state_3_1", false,-1);
    tracep->declBit(c+143,"state_3_2", false,-1);
    tracep->declBit(c+985,"muxState_3_0", false,-1);
    tracep->declBit(c+986,"muxState_3_1", false,-1);
    tracep->declBit(c+987,"muxState_3_2", false,-1);
    tracep->declBit(c+144,"idle_4", false,-1);
    tracep->declBit(c+988,"anyValid_1", false,-1);
    tracep->declBus(c+989,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+145,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+990,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+991,"winner_4_0", false,-1);
    tracep->declBit(c+992,"winner_4_2", false,-1);
    tracep->declBit(c+146,"state_4_0", false,-1);
    tracep->declBit(c+147,"state_4_2", false,-1);
    tracep->declBit(c+993,"muxState_4_0", false,-1);
    tracep->declBit(c+994,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+148,"io_enq_ready", false,-1);
    tracep->declBit(c+727,"io_enq_valid", false,-1);
    tracep->declBus(c+879,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+995,"io_deq_ready", false,-1);
    tracep->declBit(c+729,"io_deq_valid", false,-1);
    tracep->declBus(c+880,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+149,"wrap", false,-1);
    tracep->declBit(c+150,"wrap_1", false,-1);
    tracep->declBit(c+151,"maybe_full", false,-1);
    tracep->declBit(c+152,"ptr_match", false,-1);
    tracep->declBit(c+153,"empty", false,-1);
    tracep->declBit(c+154,"full", false,-1);
    tracep->declBit(c+729,"io_deq_valid_0", false,-1);
    tracep->declBit(c+996,"do_deq", false,-1);
    tracep->declBit(c+997,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+150,"R0_addr", false,-1);
    tracep->declBit(c+1138,"R0_en", false,-1);
    tracep->declBit(c+1070,"R0_clk", false,-1);
    tracep->declBus(c+155,"R0_data", false,-1, 2,0);
    tracep->declBit(c+149,"W0_addr", false,-1);
    tracep->declBit(c+997,"W0_en", false,-1);
    tracep->declBit(c+1070,"W0_clk", false,-1);
    tracep->declBus(c+879,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+156+i*1,"Memory", true,(i+0), 2,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk3 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4yank ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+954,"auto_in_awready", false,-1);
    tracep->declBit(c+716,"auto_in_awvalid", false,-1);
    tracep->declBus(c+27,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+852,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+28,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+44,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+955,"auto_in_wready", false,-1);
    tracep->declBit(c+717,"auto_in_wvalid", false,-1);
    tracep->declBus(c+854,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+718,"auto_in_wlast", false,-1);
    tracep->declBit(c+956,"auto_in_bready", false,-1);
    tracep->declBit(c+957,"auto_in_bvalid", false,-1);
    tracep->declBus(c+950,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+958,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+959,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+960,"auto_in_arready", false,-1);
    tracep->declBit(c+719,"auto_in_arvalid", false,-1);
    tracep->declBus(c+30,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+857,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+31,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+45,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+715,"auto_in_rready", false,-1);
    tracep->declBit(c+952,"auto_in_rvalid", false,-1);
    tracep->declBus(c+953,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+353,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+961,"auto_in_rlast", false,-1);
    tracep->declBit(c+975,"auto_out_awready", false,-1);
    tracep->declBit(c+724,"auto_out_awvalid", false,-1);
    tracep->declBus(c+27,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+852,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+28,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+955,"auto_out_wready", false,-1);
    tracep->declBit(c+717,"auto_out_wvalid", false,-1);
    tracep->declBus(c+854,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+710,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+718,"auto_out_wlast", false,-1);
    tracep->declBit(c+956,"auto_out_bready", false,-1);
    tracep->declBit(c+957,"auto_out_bvalid", false,-1);
    tracep->declBus(c+950,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+958,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+976,"auto_out_arready", false,-1);
    tracep->declBit(c+725,"auto_out_arvalid", false,-1);
    tracep->declBus(c+30,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+857,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+31,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+715,"auto_out_rready", false,-1);
    tracep->declBit(c+952,"auto_out_rvalid", false,-1);
    tracep->declBus(c+953,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+961,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+158,"io_enq_ready", false,-1);
    tracep->declBit(c+354,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+998,"io_deq_ready", false,-1);
    tracep->declBit(c+159,"io_deq_valid", false,-1);
    tracep->declBit(c+160,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+160,"ram_real_last", false,-1);
    tracep->declBit(c+159,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+161,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+162,"io_enq_ready", false,-1);
    tracep->declBit(c+355,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+999,"io_deq_ready", false,-1);
    tracep->declBit(c+163,"io_deq_valid", false,-1);
    tracep->declBit(c+164,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+164,"ram_real_last", false,-1);
    tracep->declBit(c+163,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+165,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+166,"io_enq_ready", false,-1);
    tracep->declBit(c+356,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1000,"io_deq_ready", false,-1);
    tracep->declBit(c+167,"io_deq_valid", false,-1);
    tracep->declBit(c+168,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+168,"ram_real_last", false,-1);
    tracep->declBit(c+167,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+169,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+170,"io_enq_ready", false,-1);
    tracep->declBit(c+357,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1001,"io_deq_ready", false,-1);
    tracep->declBit(c+171,"io_deq_valid", false,-1);
    tracep->declBit(c+172,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+172,"ram_real_last", false,-1);
    tracep->declBit(c+171,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+173,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+174,"io_enq_ready", false,-1);
    tracep->declBit(c+358,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1002,"io_deq_ready", false,-1);
    tracep->declBit(c+175,"io_deq_valid", false,-1);
    tracep->declBit(c+176,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+176,"ram_real_last", false,-1);
    tracep->declBit(c+175,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+177,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+178,"io_enq_ready", false,-1);
    tracep->declBit(c+359,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1003,"io_deq_ready", false,-1);
    tracep->declBit(c+179,"io_deq_valid", false,-1);
    tracep->declBit(c+180,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+180,"ram_real_last", false,-1);
    tracep->declBit(c+179,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+181,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+182,"io_enq_ready", false,-1);
    tracep->declBit(c+360,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1004,"io_deq_ready", false,-1);
    tracep->declBit(c+183,"io_deq_valid", false,-1);
    tracep->declBit(c+184,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+184,"ram_real_last", false,-1);
    tracep->declBit(c+183,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+185,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+186,"io_enq_ready", false,-1);
    tracep->declBit(c+361,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1005,"io_deq_ready", false,-1);
    tracep->declBit(c+187,"io_deq_valid", false,-1);
    tracep->declBit(c+188,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+188,"ram_real_last", false,-1);
    tracep->declBit(c+187,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+189,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+190,"io_enq_ready", false,-1);
    tracep->declBit(c+362,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1006,"io_deq_ready", false,-1);
    tracep->declBit(c+191,"io_deq_valid", false,-1);
    tracep->declBit(c+192,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+192,"ram_real_last", false,-1);
    tracep->declBit(c+191,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+193,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+194,"io_enq_ready", false,-1);
    tracep->declBit(c+363,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1007,"io_deq_ready", false,-1);
    tracep->declBit(c+195,"io_deq_valid", false,-1);
    tracep->declBit(c+196,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+196,"ram_real_last", false,-1);
    tracep->declBit(c+195,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+197,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+198,"io_enq_ready", false,-1);
    tracep->declBit(c+364,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1008,"io_deq_ready", false,-1);
    tracep->declBit(c+199,"io_deq_valid", false,-1);
    tracep->declBit(c+200,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+200,"ram_real_last", false,-1);
    tracep->declBit(c+199,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+201,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+202,"io_enq_ready", false,-1);
    tracep->declBit(c+365,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1009,"io_deq_ready", false,-1);
    tracep->declBit(c+203,"io_deq_valid", false,-1);
    tracep->declBit(c+204,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+204,"ram_real_last", false,-1);
    tracep->declBit(c+203,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+205,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+206,"io_enq_ready", false,-1);
    tracep->declBit(c+366,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1010,"io_deq_ready", false,-1);
    tracep->declBit(c+207,"io_deq_valid", false,-1);
    tracep->declBit(c+208,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+208,"ram_real_last", false,-1);
    tracep->declBit(c+207,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+209,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+210,"io_enq_ready", false,-1);
    tracep->declBit(c+367,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1011,"io_deq_ready", false,-1);
    tracep->declBit(c+211,"io_deq_valid", false,-1);
    tracep->declBit(c+212,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+212,"ram_real_last", false,-1);
    tracep->declBit(c+211,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+213,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+214,"io_enq_ready", false,-1);
    tracep->declBit(c+368,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1012,"io_deq_ready", false,-1);
    tracep->declBit(c+215,"io_deq_valid", false,-1);
    tracep->declBit(c+216,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+216,"ram_real_last", false,-1);
    tracep->declBit(c+215,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+217,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+218,"io_enq_ready", false,-1);
    tracep->declBit(c+369,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1013,"io_deq_ready", false,-1);
    tracep->declBit(c+219,"io_deq_valid", false,-1);
    tracep->declBit(c+220,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+220,"ram_real_last", false,-1);
    tracep->declBit(c+219,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+221,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+222,"io_enq_ready", false,-1);
    tracep->declBit(c+370,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1014,"io_deq_ready", false,-1);
    tracep->declBit(c+223,"io_deq_valid", false,-1);
    tracep->declBit(c+224,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+224,"ram_real_last", false,-1);
    tracep->declBit(c+223,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+225,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+226,"io_enq_ready", false,-1);
    tracep->declBit(c+371,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1015,"io_deq_ready", false,-1);
    tracep->declBit(c+227,"io_deq_valid", false,-1);
    tracep->declBit(c+228,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+228,"ram_real_last", false,-1);
    tracep->declBit(c+227,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+229,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+230,"io_enq_ready", false,-1);
    tracep->declBit(c+372,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1016,"io_deq_ready", false,-1);
    tracep->declBit(c+231,"io_deq_valid", false,-1);
    tracep->declBit(c+232,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+232,"ram_real_last", false,-1);
    tracep->declBit(c+231,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+233,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+234,"io_enq_ready", false,-1);
    tracep->declBit(c+373,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1017,"io_deq_ready", false,-1);
    tracep->declBit(c+235,"io_deq_valid", false,-1);
    tracep->declBit(c+236,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+236,"ram_real_last", false,-1);
    tracep->declBit(c+235,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+237,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+238,"io_enq_ready", false,-1);
    tracep->declBit(c+374,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1018,"io_deq_ready", false,-1);
    tracep->declBit(c+239,"io_deq_valid", false,-1);
    tracep->declBit(c+240,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+240,"ram_real_last", false,-1);
    tracep->declBit(c+239,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+241,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+242,"io_enq_ready", false,-1);
    tracep->declBit(c+375,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1019,"io_deq_ready", false,-1);
    tracep->declBit(c+243,"io_deq_valid", false,-1);
    tracep->declBit(c+244,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+244,"ram_real_last", false,-1);
    tracep->declBit(c+243,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+245,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+246,"io_enq_ready", false,-1);
    tracep->declBit(c+376,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1020,"io_deq_ready", false,-1);
    tracep->declBit(c+247,"io_deq_valid", false,-1);
    tracep->declBit(c+248,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+248,"ram_real_last", false,-1);
    tracep->declBit(c+247,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+249,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+250,"io_enq_ready", false,-1);
    tracep->declBit(c+377,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1021,"io_deq_ready", false,-1);
    tracep->declBit(c+251,"io_deq_valid", false,-1);
    tracep->declBit(c+252,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+252,"ram_real_last", false,-1);
    tracep->declBit(c+251,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+253,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+254,"io_enq_ready", false,-1);
    tracep->declBit(c+378,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1022,"io_deq_ready", false,-1);
    tracep->declBit(c+255,"io_deq_valid", false,-1);
    tracep->declBit(c+256,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+256,"ram_real_last", false,-1);
    tracep->declBit(c+255,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+257,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+258,"io_enq_ready", false,-1);
    tracep->declBit(c+379,"io_enq_valid", false,-1);
    tracep->declBit(c+44,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1023,"io_deq_ready", false,-1);
    tracep->declBit(c+259,"io_deq_valid", false,-1);
    tracep->declBit(c+260,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+260,"ram_real_last", false,-1);
    tracep->declBit(c+259,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+261,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+262,"io_enq_ready", false,-1);
    tracep->declBit(c+380,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1024,"io_deq_ready", false,-1);
    tracep->declBit(c+263,"io_deq_valid", false,-1);
    tracep->declBit(c+264,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+264,"ram_real_last", false,-1);
    tracep->declBit(c+263,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+265,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+266,"io_enq_ready", false,-1);
    tracep->declBit(c+381,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1025,"io_deq_ready", false,-1);
    tracep->declBit(c+267,"io_deq_valid", false,-1);
    tracep->declBit(c+268,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+268,"ram_real_last", false,-1);
    tracep->declBit(c+267,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+269,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+270,"io_enq_ready", false,-1);
    tracep->declBit(c+382,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1026,"io_deq_ready", false,-1);
    tracep->declBit(c+271,"io_deq_valid", false,-1);
    tracep->declBit(c+272,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+272,"ram_real_last", false,-1);
    tracep->declBit(c+271,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+273,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+274,"io_enq_ready", false,-1);
    tracep->declBit(c+383,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1027,"io_deq_ready", false,-1);
    tracep->declBit(c+275,"io_deq_valid", false,-1);
    tracep->declBit(c+276,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+276,"ram_real_last", false,-1);
    tracep->declBit(c+275,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+277,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+278,"io_enq_ready", false,-1);
    tracep->declBit(c+384,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1028,"io_deq_ready", false,-1);
    tracep->declBit(c+279,"io_deq_valid", false,-1);
    tracep->declBit(c+280,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+280,"ram_real_last", false,-1);
    tracep->declBit(c+279,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+281,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+282,"io_enq_ready", false,-1);
    tracep->declBit(c+385,"io_enq_valid", false,-1);
    tracep->declBit(c+45,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+1029,"io_deq_ready", false,-1);
    tracep->declBit(c+283,"io_deq_valid", false,-1);
    tracep->declBit(c+284,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+284,"ram_real_last", false,-1);
    tracep->declBit(c+283,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+285,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1103,"reset", false,-1);
    tracep->declBit(c+41,"auto_master_out_awready", false,-1);
    tracep->declBit(c+711,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1129,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+859,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1130,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1131,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1132,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+42,"auto_master_out_wready", false,-1);
    tracep->declBit(c+712,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+860,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+713,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1133,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1099,"auto_master_out_bready", false,-1);
    tracep->declBit(c+949,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+950,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+951,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+43,"auto_master_out_arready", false,-1);
    tracep->declBit(c+714,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1134,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+861,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1135,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1136,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1137,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+715,"auto_master_out_rready", false,-1);
    tracep->declBit(c+952,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+953,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+351,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1100,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+352,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1103,"reset", false,-1);
    tracep->declBit(c+1119,"io_interrupt", false,-1);
    tracep->declBit(c+41,"io_master_awready", false,-1);
    tracep->declBit(c+711,"io_master_awvalid", false,-1);
    tracep->declBus(c+859,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1129,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1130,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1131,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1132,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+42,"io_master_wready", false,-1);
    tracep->declBit(c+712,"io_master_wvalid", false,-1);
    tracep->declBus(c+860,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+713,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1133,"io_master_wlast", false,-1);
    tracep->declBit(c+1099,"io_master_bready", false,-1);
    tracep->declBit(c+949,"io_master_bvalid", false,-1);
    tracep->declBus(c+951,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+950,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+43,"io_master_arready", false,-1);
    tracep->declBit(c+714,"io_master_arvalid", false,-1);
    tracep->declBus(c+861,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1134,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1135,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+1136,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1137,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+715,"io_master_rready", false,-1);
    tracep->declBit(c+952,"io_master_rvalid", false,-1);
    tracep->declBus(c+1100,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+351,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+352,"io_master_rlast", false,-1);
    tracep->declBus(c+953,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1139,"io_slave_awready", false,-1);
    tracep->declBit(c+1119,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1140,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1141,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1142,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1143,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1144,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1145,"io_slave_wready", false,-1);
    tracep->declBit(c+1119,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1140,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1141,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1119,"io_slave_wlast", false,-1);
    tracep->declBit(c+1119,"io_slave_bready", false,-1);
    tracep->declBit(c+1146,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1147,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1148,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1149,"io_slave_arready", false,-1);
    tracep->declBit(c+1119,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1140,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1141,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1142,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1143,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1144,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1119,"io_slave_rready", false,-1);
    tracep->declBit(c+1150,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1151,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1152,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1153,"io_slave_rlast", false,-1);
    tracep->declBus(c+1154,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+730,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+881,"npc", false,-1, 31,0);
    tracep->declBus(c+627,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+731,"inst", false,-1, 31,0);
    tracep->declBit(c+1030,"ifu_valid", false,-1);
    tracep->declBit(c+730,"ifu_arvalid", false,-1);
    tracep->declBit(c+286,"ifu_arready", false,-1);
    tracep->declBus(c+881,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+1031,"ifu_rvalid", false,-1);
    tracep->declBit(c+730,"ifu_rready", false,-1);
    tracep->declBus(c+1032,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+732,"reg_process", false,-1);
    tracep->declBus(c+733,"src1", false,-1, 4,0);
    tracep->declBus(c+734,"src2", false,-1, 4,0);
    tracep->declBus(c+735,"rd", false,-1, 4,0);
    tracep->declBus(c+736,"imm", false,-1, 31,0);
    tracep->declBit(c+737,"ebreaksig", false,-1);
    tracep->declBit(c+738,"mretsig", false,-1);
    tracep->declBit(c+739,"ecallsig", false,-1);
    tracep->declBit(c+740,"regew", false,-1);
    tracep->declBit(c+741,"memew", false,-1);
    tracep->declBit(c+742,"memer", false,-1);
    tracep->declBit(c+743,"muximm", false,-1);
    tracep->declBus(c+744,"func3", false,-1, 2,0);
    tracep->declBus(c+745,"muxsig", false,-1, 2,0);
    tracep->declBit(c+746,"func7", false,-1);
    tracep->declBit(c+747,"btypebranch", false,-1);
    tracep->declBit(c+748,"jalsig", false,-1);
    tracep->declBit(c+749,"jalrsig", false,-1);
    tracep->declBit(c+750,"auipcsig", false,-1);
    tracep->declBus(c+751,"aluop", false,-1, 1,0);
    tracep->declBit(c+752,"csrrw", false,-1);
    tracep->declBit(c+753,"csrrs", false,-1);
    tracep->declBit(c+1030,"idu_valid", false,-1);
    tracep->declBus(c+754,"memmask", false,-1, 2,0);
    tracep->declBit(c+755,"memsextsig", false,-1);
    tracep->declBus(c+1033,"regwrite", false,-1, 31,0);
    tracep->declBus(c+882,"regout1", false,-1, 31,0);
    tracep->declBus(c+883,"regout2", false,-1, 31,0);
    tracep->declBus(c+628,"mepc", false,-1, 31,0);
    tracep->declBus(c+629,"mtvec", false,-1, 31,0);
    tracep->declBit(c+730,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+884,"res", false,-1, 31,0);
    tracep->declBus(c+885,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1030,"exu_valid", false,-1);
    tracep->declBit(c+730,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1104,"memvalid", false,-1);
    tracep->declBus(c+756,"awvalid", false,-1, 1,0);
    tracep->declBus(c+756,"wvalid", false,-1, 1,0);
    tracep->declBus(c+757,"arvalid", false,-1, 1,0);
    tracep->declBus(c+758,"rready", false,-1, 1,0);
    tracep->declBus(c+759,"bready", false,-1, 1,0);
    tracep->declBus(c+386,"bvalid", false,-1, 1,0);
    tracep->declBus(c+1034,"rvalid", false,-1, 1,0);
    tracep->declBus(c+287,"awready", false,-1, 1,0);
    tracep->declBus(c+287,"wready", false,-1, 1,0);
    tracep->declBus(c+288,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+886+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1035+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+888+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+890+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+760+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1037+i*1,"bresp", true,(i+0), 1,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1155,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBus(c+756,"awvalid", false,-1, 1,0);
    tracep->declBus(c+756,"wvalid", false,-1, 1,0);
    tracep->declBus(c+757,"arvalid", false,-1, 1,0);
    tracep->declBus(c+758,"rready", false,-1, 1,0);
    tracep->declBus(c+759,"bready", false,-1, 1,0);
    tracep->declBus(c+386,"bvalid", false,-1, 1,0);
    tracep->declBus(c+1034,"rvalid", false,-1, 1,0);
    tracep->declBus(c+287,"awready", false,-1, 1,0);
    tracep->declBus(c+287,"wready", false,-1, 1,0);
    tracep->declBus(c+288,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+892+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+894+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+896+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+762+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1039+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1041+i*1,"bresp", true,(i+0), 1,0);
    }
    tracep->declBit(c+711,"awvalid_out", false,-1);
    tracep->declBit(c+712,"wvalid_out", false,-1);
    tracep->declBit(c+714,"arvalid_out", false,-1);
    tracep->declBit(c+715,"rready_out", false,-1);
    tracep->declBit(c+1099,"bready_out", false,-1);
    tracep->declBit(c+949,"bvalid_in", false,-1);
    tracep->declBit(c+952,"rvalid_in", false,-1);
    tracep->declBit(c+42,"awready_in", false,-1);
    tracep->declBit(c+42,"wready_in", false,-1);
    tracep->declBit(c+43,"arready_in", false,-1);
    tracep->declBus(c+861,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+859,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+860,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+713,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+351,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+951,"bresp_in", false,-1, 1,0);
    tracep->declBit(c+289,"busy", false,-1);
    tracep->declBus(c+290,"giant", false,-1, 1,0);
    tracep->declBus(c+291,"i", false,-1, 31,0);
    tracep->declBus(c+859,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+860,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+861,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+713,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1156,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+744,"func3", false,-1, 2,0);
    tracep->declBit(c+747,"btypebranch", false,-1);
    tracep->declBit(c+746,"func7", false,-1);
    tracep->declBus(c+751,"aluop", false,-1, 1,0);
    tracep->declBit(c+749,"jalrsig", false,-1);
    tracep->declBit(c+748,"jalsig", false,-1);
    tracep->declBus(c+736,"imm", false,-1, 31,0);
    tracep->declBit(c+743,"muximm", false,-1);
    tracep->declBus(c+882,"regout1", false,-1, 31,0);
    tracep->declBus(c+883,"regout2", false,-1, 31,0);
    tracep->declBus(c+627,"pc", false,-1, 31,0);
    tracep->declBit(c+750,"auipcsig", false,-1);
    tracep->declBit(c+738,"mretsig", false,-1);
    tracep->declBit(c+739,"ecallsig", false,-1);
    tracep->declBus(c+629,"mtvec", false,-1, 31,0);
    tracep->declBus(c+628,"mepc", false,-1, 31,0);
    tracep->declBit(c+1030,"valid_from", false,-1);
    tracep->declBit(c+730,"ready_from", false,-1);
    tracep->declBus(c+884,"res", false,-1, 31,0);
    tracep->declBus(c+881,"npc", false,-1, 31,0);
    tracep->declBus(c+885,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1030,"valid_to", false,-1);
    tracep->declBit(c+730,"ready_to", false,-1);
    tracep->declBus(c+630,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+898,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+764,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+899,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+900,"zero", false,-1);
    tracep->declBit(c+901,"signal", false,-1);
    tracep->declBit(c+902,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+882,"A", false,-1, 31,0);
    tracep->declBus(c+899,"B", false,-1, 31,0);
    tracep->declBus(c+764,"op", false,-1, 4,0);
    tracep->declBus(c+884,"res", false,-1, 31,0);
    tracep->declBit(c+900,"zero", false,-1);
    tracep->declBit(c+901,"signal", false,-1);
    tracep->declBit(c+902,"carry", false,-1);
    tracep->declBit(c+765,"addsig", false,-1);
    tracep->declBit(c+766,"logsig", false,-1);
    tracep->declBit(c+767,"shfsig", false,-1);
    tracep->declBit(c+768,"sltsig", false,-1);
    tracep->declBit(c+902,"carry_tmp", false,-1);
    tracep->declBit(c+769,"type_I", false,-1);
    tracep->declBus(c+903,"logres", false,-1, 31,0);
    tracep->declBus(c+904,"addres", false,-1, 31,0);
    tracep->declBit(c+905,"addzero", false,-1);
    tracep->declBus(c+906,"shfres", false,-1, 31,0);
    tracep->declBus(c+907,"sltres", false,-1, 31,0);
    tracep->declBus(c+882,"A_s", false,-1, 31,0);
    tracep->declBus(c+899,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+744,"func3", false,-1, 2,0);
    tracep->declBit(c+746,"func7", false,-1);
    tracep->declBus(c+751,"aluop", false,-1, 1,0);
    tracep->declBit(c+749,"jalrsig", false,-1);
    tracep->declBus(c+764,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+769,"type_I", false,-1);
    tracep->declBit(c+770,"type_B", false,-1);
    tracep->declBit(c+771,"type_R", false,-1);
    tracep->declBit(c+772,"addsig", false,-1);
    tracep->declBus(c+773,"branchop", false,-1, 3,0);
    tracep->declBus(c+774,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+747,"btypebranch", false,-1);
    tracep->declBus(c+744,"func3", false,-1, 2,0);
    tracep->declBit(c+900,"zero", false,-1);
    tracep->declBit(c+901,"signal", false,-1);
    tracep->declBit(c+902,"carry", false,-1);
    tracep->declBus(c+884,"res", false,-1, 31,0);
    tracep->declBus(c+630,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+898,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+748,"jalsig", false,-1);
    tracep->declBit(c+749,"jalrsig", false,-1);
    tracep->declBit(c+750,"auipcsig", false,-1);
    tracep->declBit(c+738,"mretsig", false,-1);
    tracep->declBit(c+739,"ecallsig", false,-1);
    tracep->declBus(c+629,"mtvec", false,-1, 31,0);
    tracep->declBus(c+628,"mepc", false,-1, 31,0);
    tracep->declBus(c+881,"npc", false,-1, 31,0);
    tracep->declBus(c+885,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1155,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1157,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+899,"out", false,-1, 31,0);
    tracep->declBus(c+743,"key", false,-1, 0,0);
    tracep->declArray(c+799,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1155,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1157,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1159,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+899,"out", false,-1, 31,0);
    tracep->declBus(c+743,"key", false,-1, 0,0);
    tracep->declBus(c+1140,"default_out", false,-1, 31,0);
    tracep->declArray(c+799,"lut", false,-1, 65,0);
    tracep->declBus(c+1160,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+802+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+806+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+908,"lut_out", false,-1, 31,0);
    tracep->declBit(c+775,"hit", false,-1);
    tracep->declBus(c+1161,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+627,"pc", false,-1, 31,0);
    tracep->declBus(c+630,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+627,"pc", false,-1, 31,0);
    tracep->declBus(c+736,"imm", false,-1, 31,0);
    tracep->declBus(c+898,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+731,"inst", false,-1, 31,0);
    tracep->declBit(c+1030,"valid_from", false,-1);
    tracep->declBit(c+730,"ready_from", false,-1);
    tracep->declBit(c+737,"ebreaksig", false,-1);
    tracep->declBit(c+739,"ecallsig", false,-1);
    tracep->declBit(c+738,"mretsig", false,-1);
    tracep->declBus(c+736,"imm", false,-1, 31,0);
    tracep->declBus(c+744,"func3", false,-1, 2,0);
    tracep->declBit(c+746,"func7", false,-1);
    tracep->declBus(c+733,"src1", false,-1, 4,0);
    tracep->declBus(c+734,"src2", false,-1, 4,0);
    tracep->declBus(c+735,"rd", false,-1, 4,0);
    tracep->declBit(c+741,"memew", false,-1);
    tracep->declBus(c+745,"muxsig", false,-1, 2,0);
    tracep->declBit(c+742,"memer", false,-1);
    tracep->declBit(c+740,"regew", false,-1);
    tracep->declBit(c+743,"muximm", false,-1);
    tracep->declBit(c+747,"btypebranch", false,-1);
    tracep->declBit(c+749,"jalrsig", false,-1);
    tracep->declBit(c+748,"jalsig", false,-1);
    tracep->declBus(c+751,"aluop", false,-1, 1,0);
    tracep->declBit(c+750,"auipcsig", false,-1);
    tracep->declBit(c+752,"csrrw", false,-1);
    tracep->declBit(c+753,"csrrs", false,-1);
    tracep->declBit(c+1030,"valid_to", false,-1);
    tracep->declBit(c+730,"ready_to", false,-1);
    tracep->declBus(c+754,"memmask", false,-1, 2,0);
    tracep->declBit(c+755,"memsextsig", false,-1);
    tracep->declBit(c+737,"ebreak", false,-1);
    tracep->declBit(c+739,"ecall", false,-1);
    tracep->declBit(c+738,"mret", false,-1);
    tracep->declBus(c+744,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+746,"func7bridge", false,-1);
    tracep->declBus(c+776,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+731,"inst", false,-1, 31,0);
    tracep->declBit(c+737,"ebreaksig", false,-1);
    tracep->declBit(c+739,"ecallsig", false,-1);
    tracep->declBit(c+738,"mretsig", false,-1);
    tracep->declBus(c+736,"imm", false,-1, 31,0);
    tracep->declBus(c+776,"opcode", false,-1, 6,0);
    tracep->declBus(c+744,"func3", false,-1, 2,0);
    tracep->declBit(c+746,"func7", false,-1);
    tracep->declBus(c+733,"src1", false,-1, 4,0);
    tracep->declBus(c+734,"src2", false,-1, 4,0);
    tracep->declBus(c+735,"rd", false,-1, 4,0);
    tracep->declBus(c+754,"memmask", false,-1, 2,0);
    tracep->declBit(c+755,"memsextsig", false,-1);
    tracep->declBit(c+777,"type_I", false,-1);
    tracep->declBit(c+778,"type_R", false,-1);
    tracep->declBit(c+779,"type_U", false,-1);
    tracep->declBit(c+741,"type_S", false,-1);
    tracep->declBit(c+748,"type_J", false,-1);
    tracep->declBit(c+747,"type_B", false,-1);
    tracep->declBus(c+780,"I_imm", false,-1, 31,0);
    tracep->declBus(c+781,"U_imm", false,-1, 31,0);
    tracep->declBus(c+782,"S_imm", false,-1, 31,0);
    tracep->declBus(c+783,"J_imm", false,-1, 31,0);
    tracep->declBus(c+784,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+776,"opcode", false,-1, 6,0);
    tracep->declBus(c+744,"func3", false,-1, 2,0);
    tracep->declBit(c+746,"func7", false,-1);
    tracep->declBit(c+737,"ebreaksig", false,-1);
    tracep->declBit(c+739,"ecallsig", false,-1);
    tracep->declBit(c+738,"mretsig", false,-1);
    tracep->declBit(c+741,"memew", false,-1);
    tracep->declBus(c+745,"muxsig", false,-1, 2,0);
    tracep->declBit(c+742,"memer", false,-1);
    tracep->declBit(c+740,"regew", false,-1);
    tracep->declBit(c+743,"muximm", false,-1);
    tracep->declBit(c+747,"btypebranch", false,-1);
    tracep->declBit(c+749,"jalrsig", false,-1);
    tracep->declBit(c+748,"jalsig", false,-1);
    tracep->declBus(c+751,"aluop", false,-1, 1,0);
    tracep->declBit(c+750,"auipcsig", false,-1);
    tracep->declBit(c+752,"csrrw", false,-1);
    tracep->declBit(c+753,"csrrs", false,-1);
    tracep->declBit(c+777,"type_I", false,-1);
    tracep->declBit(c+778,"type_R", false,-1);
    tracep->declBit(c+779,"type_U", false,-1);
    tracep->declBit(c+741,"type_S", false,-1);
    tracep->declBit(c+748,"type_J", false,-1);
    tracep->declBit(c+747,"type_B", false,-1);
    tracep->declBit(c+742,"load", false,-1);
    tracep->declBit(c+741,"store", false,-1);
    tracep->declBit(c+785,"regwritepc", false,-1);
    tracep->declBit(c+742,"regwritemem", false,-1);
    tracep->declBit(c+786,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1103,"rst", false,-1);
    tracep->declBus(c+881,"npc", false,-1, 31,0);
    tracep->declBit(c+730,"ready", false,-1);
    tracep->declBus(c+627,"pc", false,-1, 31,0);
    tracep->declBus(c+731,"inst", false,-1, 31,0);
    tracep->declBit(c+1030,"valid", false,-1);
    tracep->declBit(c+732,"regprocess", false,-1);
    tracep->declBit(c+730,"arvalid", false,-1);
    tracep->declBit(c+286,"arready", false,-1);
    tracep->declBus(c+881,"araddr", false,-1, 31,0);
    tracep->declBit(c+1031,"rvalid", false,-1);
    tracep->declBit(c+730,"rready", false,-1);
    tracep->declBus(c+1032,"rdata", false,-1, 31,0);
    tracep->declBus(c+627,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1031,"infetch_ready", false,-1);
    tracep->declBus(c+787,"state", false,-1, 1,0);
    tracep->declBus(c+731,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBus(c+881,"npc", false,-1, 31,0);
    tracep->declBit(c+1103,"rst", false,-1);
    tracep->declBit(c+1031,"ready_from", false,-1);
    tracep->declBus(c+627,"pcout", false,-1, 31,0);
    tracep->declBus(c+1162,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1103,"rst", false,-1);
    tracep->declBit(c+1105,"ew", false,-1);
    tracep->declBus(c+735,"addr", false,-1, 4,0);
    tracep->declBus(c+733,"src1", false,-1, 4,0);
    tracep->declBus(c+734,"src2", false,-1, 4,0);
    tracep->declBus(c+788,"csr", false,-1, 11,0);
    tracep->declBus(c+1033,"data", false,-1, 31,0);
    tracep->declBit(c+752,"csrrw", false,-1);
    tracep->declBit(c+753,"csrrs", false,-1);
    tracep->declBit(c+739,"ecallsig", false,-1);
    tracep->declBit(c+1030,"valid", false,-1);
    tracep->declBus(c+882,"regout1", false,-1, 31,0);
    tracep->declBus(c+883,"regout2", false,-1, 31,0);
    tracep->declBus(c+628,"mepc", false,-1, 31,0);
    tracep->declBus(c+629,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+631+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+663+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+789,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+1043,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1164,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1155,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+789,"out", false,-1, 1,0);
    tracep->declBus(c+788,"key", false,-1, 11,0);
    tracep->declQuad(c+1165,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1164,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1155,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1159,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+789,"out", false,-1, 1,0);
    tracep->declBus(c+788,"key", false,-1, 11,0);
    tracep->declBus(c+1144,"default_out", false,-1, 1,0);
    tracep->declQuad(c+1165,"lut", false,-1, 55,0);
    tracep->declBus(c+1167,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+790,"lut_out", false,-1, 1,0);
    tracep->declBit(c+791,"hit", false,-1);
    tracep->declBus(c+1168,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1103,"rst", false,-1);
    tracep->declBit(c+1106,"ew", false,-1);
    tracep->declBit(c+752,"csrrw", false,-1);
    tracep->declBit(c+753,"csrrs", false,-1);
    tracep->declBit(c+739,"ecall", false,-1);
    tracep->declBus(c+789,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+735,"addr", false,-1, 4,0);
    tracep->declBus(c+1043,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+667+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+699+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+703,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBus(c+884,"res", false,-1, 31,0);
    tracep->declBus(c+883,"regout2", false,-1, 31,0);
    tracep->declBit(c+741,"memew", false,-1);
    tracep->declBit(c+742,"memer", false,-1);
    tracep->declBus(c+736,"imm", false,-1, 31,0);
    tracep->declBus(c+885,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+745,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1030,"valid_from", false,-1);
    tracep->declBus(c+754,"memmask", false,-1, 2,0);
    tracep->declBit(c+755,"memsextsig", false,-1);
    tracep->declBus(c+1033,"regwrite", false,-1, 31,0);
    tracep->declBit(c+730,"ready_to", false,-1);
    tracep->declBit(c+1104,"memvalid", false,-1);
    tracep->declBit(c+792,"awvalid", false,-1);
    tracep->declBit(c+292,"awready", false,-1);
    tracep->declBus(c+884,"awaddr", false,-1, 31,0);
    tracep->declBit(c+792,"wvalid", false,-1);
    tracep->declBit(c+292,"wready", false,-1);
    tracep->declBus(c+883,"wdata", false,-1, 31,0);
    tracep->declBus(c+793,"wstrb", false,-1, 3,0);
    tracep->declBit(c+387,"bvalid", false,-1);
    tracep->declBit(c+741,"bready", false,-1);
    tracep->declBus(c+1044,"bresp", false,-1, 1,0);
    tracep->declBit(c+1107,"arvalid", false,-1);
    tracep->declBit(c+293,"arready", false,-1);
    tracep->declBus(c+884,"araddr", false,-1, 31,0);
    tracep->declBit(c+1045,"rvalid", false,-1);
    tracep->declBit(c+742,"rready", false,-1);
    tracep->declBus(c+1046,"rdata", false,-1, 31,0);
    tracep->declBus(c+1047,"memread", false,-1, 31,0);
    tracep->declBit(c+294,"bresp_get", false,-1);
    tracep->declBit(c+295,"rvalid_get", false,-1);
    tracep->declBit(c+296,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+1046,"data", false,-1, 31,0);
    tracep->declBus(c+754,"memmask", false,-1, 2,0);
    tracep->declBit(c+755,"memsextsig", false,-1);
    tracep->declBus(c+1047,"read", false,-1, 31,0);
    tracep->declBus(c+1048,"read_u", false,-1, 31,0);
    tracep->declBus(c+1049,"read_s", false,-1, 31,0);
    tracep->declBus(c+1050,"read_sb", false,-1, 31,0);
    tracep->declBus(c+1051,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1169,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1158,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1052,"input_number", false,-1, 7,0);
    tracep->declBus(c+1050,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1170,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1158,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1053,"input_number", false,-1, 15,0);
    tracep->declBus(c+1051,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1171,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1033,"out", false,-1, 31,0);
    tracep->declBus(c+745,"key", false,-1, 2,0);
    tracep->declBus(c+1159,"default_out", false,-1, 31,0);
    tracep->declArray(c+808,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1171,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1157,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1033,"out", false,-1, 31,0);
    tracep->declBus(c+745,"key", false,-1, 2,0);
    tracep->declBus(c+1159,"default_out", false,-1, 31,0);
    tracep->declArray(c+808,"lut", false,-1, 139,0);
    tracep->declBus(c+1172,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+813+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+821+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1054,"lut_out", false,-1, 31,0);
    tracep->declBit(c+1055,"hit", false,-1);
    tracep->declBus(c+1168,"i", false,-1, 31,0);
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"io_d", false,-1);
    tracep->declBit(c+297,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"io_d", false,-1);
    tracep->declBit(c+297,"io_q", false,-1);
    tracep->declBit(c+297,"sync_0", false,-1);
    tracep->declBit(c+298,"sync_1", false,-1);
    tracep->declBit(c+299,"sync_2", false,-1);
    tracep->declBit(c+300,"sync_3", false,-1);
    tracep->declBit(c+301,"sync_4", false,-1);
    tracep->declBit(c+302,"sync_5", false,-1);
    tracep->declBit(c+303,"sync_6", false,-1);
    tracep->declBit(c+304,"sync_7", false,-1);
    tracep->declBit(c+305,"sync_8", false,-1);
    tracep->declBit(c+306,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+836,"auto_in_psel", false,-1);
    tracep->declBit(c+348,"auto_in_penable", false,-1);
    tracep->declBit(c+827,"auto_in_pwrite", false,-1);
    tracep->declBus(c+835,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1118,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1126,"auto_in_pready", false,-1);
    tracep->declBit(c+1127,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1128,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1072,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1073,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1074,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1075,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1076,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1077,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1078,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1079,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1080,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1081,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+909,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+836,"in_psel", false,-1);
    tracep->declBit(c+348,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1126,"in_pready", false,-1);
    tracep->declBus(c+1128,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1127,"in_pslverr", false,-1);
    tracep->declBus(c+1072,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1073,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1074,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1075,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1076,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1077,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1078,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1079,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1080,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1081,"gpio_seg_7", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+834,"auto_in_psel", false,-1);
    tracep->declBit(c+347,"auto_in_penable", false,-1);
    tracep->declBit(c+827,"auto_in_pwrite", false,-1);
    tracep->declBus(c+835,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1118,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1123,"auto_in_pready", false,-1);
    tracep->declBit(c+1124,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1125,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1082,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1083,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+909,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+834,"in_psel", false,-1);
    tracep->declBit(c+347,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1123,"in_pready", false,-1);
    tracep->declBus(c+1125,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1124,"in_pslverr", false,-1);
    tracep->declBit(c+1082,"ps2_clk", false,-1);
    tracep->declBit(c+1083,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+796,"auto_in_awvalid", false,-1);
    tracep->declBit(c+797,"auto_in_wvalid", false,-1);
    tracep->declBit(c+102,"auto_in_arready", false,-1);
    tracep->declBit(c+798,"auto_in_arvalid", false,-1);
    tracep->declBus(c+30,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+872,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1102,"auto_in_rready", false,-1);
    tracep->declBit(c+103,"auto_in_rvalid", false,-1);
    tracep->declBus(c+104,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+105,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+103,"state", false,-1);
    tracep->declBus(c+105,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+104,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+910,"raddr", false,-1, 31,0);
    tracep->declBit(c+911,"ren", false,-1);
    tracep->declBus(c+912,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+837,"auto_in_psel", false,-1);
    tracep->declBit(c+349,"auto_in_penable", false,-1);
    tracep->declBit(c+827,"auto_in_pwrite", false,-1);
    tracep->declBus(c+825,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1118,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1097,"auto_in_pready", false,-1);
    tracep->declBit(c+1119,"auto_in_pslverr", false,-1);
    tracep->declBus(c+26,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1094,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+1095,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+941,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+825,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+837,"in_psel", false,-1);
    tracep->declBit(c+349,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1097,"in_pready", false,-1);
    tracep->declBus(c+26,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1119,"in_pslverr", false,-1);
    tracep->declBit(c+1094,"qspi_sck", false,-1);
    tracep->declBit(c+1095,"qspi_ce_n", false,-1);
    tracep->declBus(c+941,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+941,"din", false,-1, 3,0);
    tracep->declBus(c+1056,"dout", false,-1, 3,0);
    tracep->declBus(c+1057,"douten", false,-1, 3,0);
    tracep->declBit(c+1108,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1070,"clk_i", false,-1);
    tracep->declBit(c+1071,"rst_i", false,-1);
    tracep->declBus(c+825,"adr_i", false,-1, 31,0);
    tracep->declBus(c+828,"dat_i", false,-1, 31,0);
    tracep->declBus(c+26,"dat_o", false,-1, 31,0);
    tracep->declBus(c+829,"sel_i", false,-1, 3,0);
    tracep->declBit(c+837,"cyc_i", false,-1);
    tracep->declBit(c+837,"stb_i", false,-1);
    tracep->declBit(c+1108,"ack_o", false,-1);
    tracep->declBit(c+827,"we_i", false,-1);
    tracep->declBit(c+1094,"sck", false,-1);
    tracep->declBit(c+1095,"ce_n", false,-1);
    tracep->declBus(c+941,"din", false,-1, 3,0);
    tracep->declBus(c+1056,"dout", false,-1, 3,0);
    tracep->declBus(c+1057,"douten", false,-1, 3,0);
    tracep->declBus(c+1173,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1174,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+403,"mr_sck", false,-1);
    tracep->declBit(c+404,"mr_ce_n", false,-1);
    tracep->declBus(c+941,"mr_din", false,-1, 3,0);
    tracep->declBus(c+405,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+406,"mr_doe", false,-1);
    tracep->declBit(c+407,"mw_sck", false,-1);
    tracep->declBit(c+408,"mw_ce_n", false,-1);
    tracep->declBus(c+941,"mw_din", false,-1, 3,0);
    tracep->declBus(c+1058,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+409,"mw_doe", false,-1);
    tracep->declBit(c+1059,"mr_rd", false,-1);
    tracep->declBit(c+410,"mr_done", false,-1);
    tracep->declBit(c+1060,"mw_wr", false,-1);
    tracep->declBit(c+1061,"mw_done", false,-1);
    tracep->declBit(c+837,"wb_valid", false,-1);
    tracep->declBit(c+913,"wb_we", false,-1);
    tracep->declBit(c+914,"wb_re", false,-1);
    tracep->declBit(c+411,"state", false,-1);
    tracep->declBit(c+1062,"nstate", false,-1);
    tracep->declBus(c+915,"size", false,-1, 2,0);
    tracep->declBus(c+916,"byte0", false,-1, 7,0);
    tracep->declBus(c+917,"byte1", false,-1, 7,0);
    tracep->declBus(c+918,"byte2", false,-1, 7,0);
    tracep->declBus(c+919,"byte3", false,-1, 7,0);
    tracep->declBus(c+920,"wdata", false,-1, 31,0);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1109,"rst_n", false,-1);
    tracep->declBus(c+921,"addr", false,-1, 23,0);
    tracep->declBit(c+1059,"rd", false,-1);
    tracep->declBus(c+1175,"size", false,-1, 2,0);
    tracep->declBit(c+410,"done", false,-1);
    tracep->declBus(c+26,"line", false,-1, 31,0);
    tracep->declBit(c+403,"sck", false,-1);
    tracep->declBit(c+404,"ce_n", false,-1);
    tracep->declBus(c+941,"din", false,-1, 3,0);
    tracep->declBus(c+405,"dout", false,-1, 3,0);
    tracep->declBit(c+406,"douten", false,-1);
    tracep->declBus(c+1173,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1174,"READ", false,-1, 0,0);
    tracep->declBus(c+1176,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+412,"state", false,-1);
    tracep->declBit(c+1063,"nstate", false,-1);
    tracep->declBus(c+413,"counter", false,-1, 7,0);
    tracep->declBus(c+414,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+307+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1177,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+415,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1109,"rst_n", false,-1);
    tracep->declBus(c+922,"addr", false,-1, 23,0);
    tracep->declBus(c+920,"line", false,-1, 31,0);
    tracep->declBus(c+915,"size", false,-1, 2,0);
    tracep->declBit(c+1060,"wr", false,-1);
    tracep->declBit(c+1061,"done", false,-1);
    tracep->declBit(c+407,"sck", false,-1);
    tracep->declBit(c+408,"ce_n", false,-1);
    tracep->declBus(c+941,"din", false,-1, 3,0);
    tracep->declBus(c+1058,"dout", false,-1, 3,0);
    tracep->declBit(c+409,"douten", false,-1);
    tracep->declBus(c+1173,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1174,"WRITE", false,-1, 0,0);
    tracep->declBus(c+923,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+416,"state", false,-1);
    tracep->declBit(c+1064,"nstate", false,-1);
    tracep->declBus(c+417,"counter", false,-1, 7,0);
    tracep->declBus(c+418,"saddr", false,-1, 23,0);
    tracep->declBus(c+1178,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+831,"auto_in_psel", false,-1);
    tracep->declBit(c+345,"auto_in_penable", false,-1);
    tracep->declBit(c+827,"auto_in_pwrite", false,-1);
    tracep->declBus(c+825,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1118,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+399,"auto_in_pready", false,-1);
    tracep->declBit(c+1119,"auto_in_pslverr", false,-1);
    tracep->declBus(c+400,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1096,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+390,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+391,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+392,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+393,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+394,"sdram_bundle_we", false,-1);
    tracep->declBus(c+395,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+396,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+397,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+398,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+825,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+831,"in_psel", false,-1);
    tracep->declBit(c+345,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+399,"in_pready", false,-1);
    tracep->declBus(c+400,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1119,"in_pslverr", false,-1);
    tracep->declBit(c+1096,"sdram_clk", false,-1);
    tracep->declBit(c+390,"sdram_cke", false,-1);
    tracep->declBit(c+391,"sdram_cs", false,-1);
    tracep->declBit(c+392,"sdram_ras", false,-1);
    tracep->declBit(c+393,"sdram_cas", false,-1);
    tracep->declBit(c+394,"sdram_we", false,-1);
    tracep->declBus(c+395,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+396,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+397,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+398,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+419,"sdram_dout_en", false,-1);
    tracep->declBus(c+420,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+311,"state", false,-1, 1,0);
    tracep->declBit(c+421,"req_accept", false,-1);
    tracep->declBit(c+924,"is_read", false,-1);
    tracep->declBit(c+925,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1070,"clk_i", false,-1);
    tracep->declBit(c+1071,"rst_i", false,-1);
    tracep->declBus(c+926,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+924,"inport_rd_i", false,-1);
    tracep->declBus(c+1142,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+825,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+828,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+398,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+421,"inport_accept_o", false,-1);
    tracep->declBit(c+399,"inport_ack_o", false,-1);
    tracep->declBit(c+1119,"inport_error_o", false,-1);
    tracep->declBus(c+400,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1096,"sdram_clk_o", false,-1);
    tracep->declBit(c+390,"sdram_cke_o", false,-1);
    tracep->declBit(c+391,"sdram_cs_o", false,-1);
    tracep->declBit(c+392,"sdram_ras_o", false,-1);
    tracep->declBit(c+393,"sdram_cas_o", false,-1);
    tracep->declBit(c+394,"sdram_we_o", false,-1);
    tracep->declBus(c+397,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+395,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+396,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+420,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+419,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1179,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1180,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1181,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1163,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1182,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1183,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1184,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1185,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1163,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1186,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1187,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1188,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1189,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1190,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1191,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1192,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1141,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1193,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1163,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1141,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1192,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1191,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1187,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1189,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1188,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1190,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1186,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1194,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1195,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1196,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1196,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1170,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1196,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1197,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+825,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+926,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+924,"ram_rd_w", false,-1);
    tracep->declBit(c+421,"ram_accept_w", false,-1);
    tracep->declBus(c+828,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+400,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+399,"ram_ack_w", false,-1);
    tracep->declBit(c+927,"ram_req_w", false,-1);
    tracep->declBus(c+422,"command_q", false,-1, 3,0);
    tracep->declBus(c+395,"addr_q", false,-1, 12,0);
    tracep->declBus(c+420,"data_q", false,-1, 15,0);
    tracep->declBit(c+423,"data_rd_en_q", false,-1);
    tracep->declBus(c+397,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+390,"cke_q", false,-1);
    tracep->declBus(c+396,"bank_q", false,-1, 1,0);
    tracep->declBus(c+424,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+425,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+398,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+426,"refresh_q", false,-1);
    tracep->declBus(c+427,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+428+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+432,"state_q", false,-1, 3,0);
    tracep->declBus(c+1065,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+1066,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+433,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+434,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+928,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+929,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+930,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1163,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+435,"delay_q", false,-1, 3,0);
    tracep->declBus(c+1067,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1198,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+436,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+437,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+438,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+439,"idx", false,-1, 31,0);
    tracep->declBus(c+440,"rd_q", false,-1, 3,0);
    tracep->declBit(c+399,"ack_q", false,-1);
    tracep->declArray(c+441,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+841,"auto_in_psel", false,-1);
    tracep->declBit(c+842,"auto_in_penable", false,-1);
    tracep->declBit(c+827,"auto_in_pwrite", false,-1);
    tracep->declBus(c+833,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1118,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+401,"auto_in_pready", false,-1);
    tracep->declBit(c+1119,"auto_in_pslverr", false,-1);
    tracep->declBus(c+402,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+388,"spi_bundle_sck", false,-1);
    tracep->declBus(c+389,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1092,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1093,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1199,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1200,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1169,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+931,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+841,"in_psel", false,-1);
    tracep->declBit(c+842,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+401,"in_pready", false,-1);
    tracep->declBus(c+402,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1119,"in_pslverr", false,-1);
    tracep->declBit(c+388,"spi_sck", false,-1);
    tracep->declBus(c+389,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1092,"spi_mosi", false,-1);
    tracep->declBit(c+1093,"spi_miso", false,-1);
    tracep->declBit(c+444,"spi_irq_out", false,-1);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBit(c+1070,"wb_clk_i", false,-1);
    tracep->declBit(c+1071,"wb_rst_i", false,-1);
    tracep->declBus(c+932,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+828,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+402,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+829,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+827,"wb_we_i", false,-1);
    tracep->declBit(c+841,"wb_stb_i", false,-1);
    tracep->declBit(c+842,"wb_cyc_i", false,-1);
    tracep->declBit(c+401,"wb_ack_o", false,-1);
    tracep->declBit(c+1119,"wb_err_o", false,-1);
    tracep->declBit(c+444,"wb_int_o", false,-1);
    tracep->declBus(c+389,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+388,"sclk_pad_o", false,-1);
    tracep->declBit(c+1092,"mosi_pad_o", false,-1);
    tracep->declBit(c+1093,"miso_pad_i", false,-1);
    tracep->declBus(c+445,"divider", false,-1, 15,0);
    tracep->declBus(c+446,"ctrl", false,-1, 13,0);
    tracep->declBus(c+447,"ss", false,-1, 7,0);
    tracep->declBus(c+1068,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+448,"rx", false,-1, 127,0);
    tracep->declBit(c+452,"rx_negedge", false,-1);
    tracep->declBit(c+453,"tx_negedge", false,-1);
    tracep->declBus(c+454,"char_len", false,-1, 6,0);
    tracep->declBit(c+455,"go", false,-1);
    tracep->declBit(c+456,"lsb", false,-1);
    tracep->declBit(c+457,"ie", false,-1);
    tracep->declBit(c+458,"ass", false,-1);
    tracep->declBit(c+933,"spi_divider_sel", false,-1);
    tracep->declBit(c+934,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+935,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+936,"spi_ss_sel", false,-1);
    tracep->declBit(c+459,"tip", false,-1);
    tracep->declBit(c+460,"pos_edge", false,-1);
    tracep->declBit(c+461,"neg_edge", false,-1);
    tracep->declBit(c+462,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBit(c+1070,"clk_in", false,-1);
    tracep->declBit(c+1071,"rst", false,-1);
    tracep->declBit(c+459,"enable", false,-1);
    tracep->declBit(c+455,"go", false,-1);
    tracep->declBit(c+462,"last_clk", false,-1);
    tracep->declBus(c+445,"divider", false,-1, 15,0);
    tracep->declBit(c+388,"clk_out", false,-1);
    tracep->declBit(c+460,"pos_edge", false,-1);
    tracep->declBit(c+461,"neg_edge", false,-1);
    tracep->declBus(c+463,"cnt", false,-1, 15,0);
    tracep->declBit(c+464,"cnt_zero", false,-1);
    tracep->declBit(c+465,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1071,"rst", false,-1);
    tracep->declBus(c+937,"latch", false,-1, 3,0);
    tracep->declBus(c+829,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+454,"len", false,-1, 6,0);
    tracep->declBit(c+456,"lsb", false,-1);
    tracep->declBit(c+455,"go", false,-1);
    tracep->declBit(c+460,"pos_edge", false,-1);
    tracep->declBit(c+461,"neg_edge", false,-1);
    tracep->declBit(c+452,"rx_negedge", false,-1);
    tracep->declBit(c+453,"tx_negedge", false,-1);
    tracep->declBit(c+459,"tip", false,-1);
    tracep->declBit(c+462,"last", false,-1);
    tracep->declBus(c+828,"p_in", false,-1, 31,0);
    tracep->declArray(c+448,"p_out", false,-1, 127,0);
    tracep->declBit(c+388,"s_clk", false,-1);
    tracep->declBit(c+1093,"s_in", false,-1);
    tracep->declBit(c+1092,"s_out", false,-1);
    tracep->declBus(c+466,"cnt", false,-1, 7,0);
    tracep->declArray(c+448,"data", false,-1, 127,0);
    tracep->declBus(c+467,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+468,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+469,"rx_clk", false,-1);
    tracep->declBit(c+470,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+838,"auto_in_psel", false,-1);
    tracep->declBit(c+839,"auto_in_penable", false,-1);
    tracep->declBit(c+827,"auto_in_pwrite", false,-1);
    tracep->declBus(c+835,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1118,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+840,"auto_in_pready", false,-1);
    tracep->declBit(c+1119,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1098,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1090,"uart_rx", false,-1);
    tracep->declBit(c+1091,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+838,"in_psel", false,-1);
    tracep->declBit(c+839,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+840,"in_pready", false,-1);
    tracep->declBit(c+1119,"in_pslverr", false,-1);
    tracep->declBus(c+909,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+1098,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1090,"uart_rx", false,-1);
    tracep->declBit(c+1091,"uart_tx", false,-1);
    tracep->declBit(c+471,"rtsn", false,-1);
    tracep->declBit(c+1119,"ctsn", false,-1);
    tracep->declBit(c+472,"dtr_pad_o", false,-1);
    tracep->declBit(c+1119,"dsr_pad_i", false,-1);
    tracep->declBit(c+1119,"ri_pad_i", false,-1);
    tracep->declBit(c+1119,"dcd_pad_i", false,-1);
    tracep->declBit(c+473,"interrupt", false,-1);
    tracep->declBit(c+1110,"reg_we", false,-1);
    tracep->declBit(c+1111,"reg_re", false,-1);
    tracep->declBus(c+938,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+939,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+312,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+1069,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+474,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1071,"wb_rst_i", false,-1);
    tracep->declBus(c+938,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+940,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+1069,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+1110,"wb_we_i", false,-1);
    tracep->declBit(c+1111,"wb_re_i", false,-1);
    tracep->declBit(c+1091,"stx_pad_o", false,-1);
    tracep->declBit(c+1090,"srx_pad_i", false,-1);
    tracep->declBus(c+1194,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+474,"rts_pad_o", false,-1);
    tracep->declBit(c+472,"dtr_pad_o", false,-1);
    tracep->declBit(c+473,"int_o", false,-1);
    tracep->declBit(c+475,"enable", false,-1);
    tracep->declBit(c+476,"srx_pad", false,-1);
    tracep->declBus(c+477,"ier", false,-1, 3,0);
    tracep->declBus(c+478,"iir", false,-1, 3,0);
    tracep->declBus(c+479,"fcr", false,-1, 1,0);
    tracep->declBus(c+480,"mcr", false,-1, 4,0);
    tracep->declBus(c+481,"lcr", false,-1, 7,0);
    tracep->declBus(c+482,"msr", false,-1, 7,0);
    tracep->declBus(c+483,"dl", false,-1, 15,0);
    tracep->declBus(c+484,"scratch", false,-1, 7,0);
    tracep->declBit(c+485,"start_dlc", false,-1);
    tracep->declBit(c+486,"lsr_mask_d", false,-1);
    tracep->declBit(c+487,"msi_reset", false,-1);
    tracep->declBus(c+488,"dlc", false,-1, 15,0);
    tracep->declBus(c+489,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+490,"rx_reset", false,-1);
    tracep->declBit(c+491,"tx_reset", false,-1);
    tracep->declBit(c+492,"dlab", false,-1);
    tracep->declBit(c+1138,"cts_pad_i", false,-1);
    tracep->declBit(c+1119,"dsr_pad_i", false,-1);
    tracep->declBit(c+1119,"ri_pad_i", false,-1);
    tracep->declBit(c+1119,"dcd_pad_i", false,-1);
    tracep->declBit(c+493,"loopback", false,-1);
    tracep->declBit(c+1119,"cts", false,-1);
    tracep->declBit(c+1138,"dsr", false,-1);
    tracep->declBit(c+1138,"ri", false,-1);
    tracep->declBit(c+1138,"dcd", false,-1);
    tracep->declBit(c+494,"cts_c", false,-1);
    tracep->declBit(c+495,"dsr_c", false,-1);
    tracep->declBit(c+496,"ri_c", false,-1);
    tracep->declBit(c+497,"dcd_c", false,-1);
    tracep->declBus(c+498,"lsr", false,-1, 7,0);
    tracep->declBit(c+499,"lsr0", false,-1);
    tracep->declBit(c+500,"lsr1", false,-1);
    tracep->declBit(c+501,"lsr2", false,-1);
    tracep->declBit(c+502,"lsr3", false,-1);
    tracep->declBit(c+503,"lsr4", false,-1);
    tracep->declBit(c+504,"lsr5", false,-1);
    tracep->declBit(c+505,"lsr6", false,-1);
    tracep->declBit(c+506,"lsr7", false,-1);
    tracep->declBit(c+507,"lsr0r", false,-1);
    tracep->declBit(c+508,"lsr1r", false,-1);
    tracep->declBit(c+509,"lsr2r", false,-1);
    tracep->declBit(c+510,"lsr3r", false,-1);
    tracep->declBit(c+511,"lsr4r", false,-1);
    tracep->declBit(c+512,"lsr5r", false,-1);
    tracep->declBit(c+513,"lsr6r", false,-1);
    tracep->declBit(c+514,"lsr7r", false,-1);
    tracep->declBit(c+19,"lsr_mask", false,-1);
    tracep->declBit(c+515,"rls_int", false,-1);
    tracep->declBit(c+516,"rda_int", false,-1);
    tracep->declBit(c+517,"ti_int", false,-1);
    tracep->declBit(c+518,"thre_int", false,-1);
    tracep->declBit(c+519,"ms_int", false,-1);
    tracep->declBit(c+520,"tf_push", false,-1);
    tracep->declBit(c+521,"rf_pop", false,-1);
    tracep->declBus(c+1112,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+522,"rf_error_bit", false,-1);
    tracep->declBit(c+500,"rf_overrun", false,-1);
    tracep->declBit(c+523,"rf_push_pulse", false,-1);
    tracep->declBus(c+524,"rf_count", false,-1, 4,0);
    tracep->declBus(c+525,"tf_count", false,-1, 4,0);
    tracep->declBus(c+526,"tstate", false,-1, 2,0);
    tracep->declBus(c+527,"rstate", false,-1, 3,0);
    tracep->declBus(c+528,"counter_t", false,-1, 9,0);
    tracep->declBit(c+529,"thre_set_en", false,-1);
    tracep->declBus(c+530,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+531,"block_value", false,-1, 7,0);
    tracep->declBit(c+532,"serial_out", false,-1);
    tracep->declBit(c+533,"serial_in", false,-1);
    tracep->declBit(c+20,"lsr_mask_condition", false,-1);
    tracep->declBit(c+21,"iir_read", false,-1);
    tracep->declBit(c+22,"msr_read", false,-1);
    tracep->declBit(c+23,"fifo_read", false,-1);
    tracep->declBit(c+24,"fifo_write", false,-1);
    tracep->declBus(c+534,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+535,"lsr0_d", false,-1);
    tracep->declBit(c+536,"lsr1_d", false,-1);
    tracep->declBit(c+537,"lsr2_d", false,-1);
    tracep->declBit(c+538,"lsr3_d", false,-1);
    tracep->declBit(c+539,"lsr4_d", false,-1);
    tracep->declBit(c+540,"lsr5_d", false,-1);
    tracep->declBit(c+541,"lsr6_d", false,-1);
    tracep->declBit(c+542,"lsr7_d", false,-1);
    tracep->declBit(c+543,"rls_int_d", false,-1);
    tracep->declBit(c+544,"thre_int_d", false,-1);
    tracep->declBit(c+545,"ms_int_d", false,-1);
    tracep->declBit(c+546,"ti_int_d", false,-1);
    tracep->declBit(c+547,"rda_int_d", false,-1);
    tracep->declBit(c+548,"rls_int_rise", false,-1);
    tracep->declBit(c+549,"thre_int_rise", false,-1);
    tracep->declBit(c+550,"ms_int_rise", false,-1);
    tracep->declBit(c+551,"ti_int_rise", false,-1);
    tracep->declBit(c+552,"rda_int_rise", false,-1);
    tracep->declBit(c+553,"rls_int_pnd", false,-1);
    tracep->declBit(c+554,"rda_int_pnd", false,-1);
    tracep->declBit(c+555,"thre_int_pnd", false,-1);
    tracep->declBit(c+556,"ms_int_pnd", false,-1);
    tracep->declBit(c+557,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBus(c+1157,"width", false,-1, 31,0);
    tracep->declBus(c+1174,"init_value", false,-1, 0,0);
    tracep->declBit(c+1071,"rst_i", false,-1);
    tracep->declBit(c+1070,"clk_i", false,-1);
    tracep->declBit(c+1119,"stage1_rst_i", false,-1);
    tracep->declBit(c+1138,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1090,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+476,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+558,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1071,"wb_rst_i", false,-1);
    tracep->declBus(c+481,"lcr", false,-1, 7,0);
    tracep->declBit(c+521,"rf_pop", false,-1);
    tracep->declBit(c+533,"srx_pad_i", false,-1);
    tracep->declBit(c+475,"enable", false,-1);
    tracep->declBit(c+490,"rx_reset", false,-1);
    tracep->declBit(c+19,"lsr_mask", false,-1);
    tracep->declBus(c+528,"counter_t", false,-1, 9,0);
    tracep->declBus(c+524,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1112,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+500,"rf_overrun", false,-1);
    tracep->declBit(c+522,"rf_error_bit", false,-1);
    tracep->declBus(c+527,"rstate", false,-1, 3,0);
    tracep->declBit(c+523,"rf_push_pulse", false,-1);
    tracep->declBus(c+559,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+560,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+561,"rshift", false,-1, 7,0);
    tracep->declBit(c+562,"rparity", false,-1);
    tracep->declBit(c+563,"rparity_error", false,-1);
    tracep->declBit(c+564,"rframing_error", false,-1);
    tracep->declBit(c+565,"rbit_in", false,-1);
    tracep->declBit(c+566,"rparity_xor", false,-1);
    tracep->declBus(c+567,"counter_b", false,-1, 7,0);
    tracep->declBit(c+568,"rf_push_q", false,-1);
    tracep->declBus(c+569,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+570,"rf_push", false,-1);
    tracep->declBit(c+571,"break_error", false,-1);
    tracep->declBit(c+572,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+573,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+574,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+575,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1141,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1192,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1191,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1187,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1189,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1188,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1190,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1186,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1194,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1195,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1201,"sr_push", false,-1, 3,0);
    tracep->declBus(c+576,"toc_value", false,-1, 9,0);
    tracep->declBus(c+577,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1202,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1170,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1163,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1203,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1071,"wb_rst_i", false,-1);
    tracep->declBit(c+523,"push", false,-1);
    tracep->declBit(c+521,"pop", false,-1);
    tracep->declBus(c+569,"data_in", false,-1, 10,0);
    tracep->declBit(c+490,"fifo_reset", false,-1);
    tracep->declBit(c+19,"reset_status", false,-1);
    tracep->declBus(c+1112,"data_out", false,-1, 10,0);
    tracep->declBit(c+500,"overrun", false,-1);
    tracep->declBus(c+524,"count", false,-1, 4,0);
    tracep->declBit(c+522,"error_bit", false,-1);
    tracep->declBus(c+1113,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+578+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+594,"top", false,-1, 3,0);
    tracep->declBus(c+595,"bottom", false,-1, 3,0);
    tracep->declBus(c+596,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+597,"word0", false,-1, 2,0);
    tracep->declBus(c+598,"word1", false,-1, 2,0);
    tracep->declBus(c+599,"word2", false,-1, 2,0);
    tracep->declBus(c+600,"word3", false,-1, 2,0);
    tracep->declBus(c+601,"word4", false,-1, 2,0);
    tracep->declBus(c+602,"word5", false,-1, 2,0);
    tracep->declBus(c+603,"word6", false,-1, 2,0);
    tracep->declBus(c+604,"word7", false,-1, 2,0);
    tracep->declBus(c+605,"word8", false,-1, 2,0);
    tracep->declBus(c+606,"word9", false,-1, 2,0);
    tracep->declBus(c+607,"word10", false,-1, 2,0);
    tracep->declBus(c+608,"word11", false,-1, 2,0);
    tracep->declBus(c+609,"word12", false,-1, 2,0);
    tracep->declBus(c+610,"word13", false,-1, 2,0);
    tracep->declBus(c+611,"word14", false,-1, 2,0);
    tracep->declBus(c+612,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1163,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1169,"data_width", false,-1, 31,0);
    tracep->declBus(c+1170,"depth", false,-1, 31,0);
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+523,"we", false,-1);
    tracep->declBus(c+594,"a", false,-1, 3,0);
    tracep->declBus(c+595,"dpra", false,-1, 3,0);
    tracep->declBus(c+613,"di", false,-1, 7,0);
    tracep->declBus(c+1113,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+313+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1071,"wb_rst_i", false,-1);
    tracep->declBus(c+481,"lcr", false,-1, 7,0);
    tracep->declBit(c+520,"tf_push", false,-1);
    tracep->declBus(c+940,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+475,"enable", false,-1);
    tracep->declBit(c+491,"tx_reset", false,-1);
    tracep->declBit(c+19,"lsr_mask", false,-1);
    tracep->declBit(c+532,"stx_pad_o", false,-1);
    tracep->declBus(c+526,"tstate", false,-1, 2,0);
    tracep->declBus(c+525,"tf_count", false,-1, 4,0);
    tracep->declBus(c+614,"counter", false,-1, 4,0);
    tracep->declBus(c+615,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+616,"shift_out", false,-1, 6,0);
    tracep->declBit(c+617,"stx_o_tmp", false,-1);
    tracep->declBit(c+618,"parity_xor", false,-1);
    tracep->declBit(c+619,"tf_pop", false,-1);
    tracep->declBit(c+620,"bit_out", false,-1);
    tracep->declBus(c+940,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1114,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+621,"tf_overrun", false,-1);
    tracep->declBus(c+1143,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1118,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1204,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1136,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1175,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1205,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1169,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1170,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1163,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1203,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+1071,"wb_rst_i", false,-1);
    tracep->declBit(c+520,"push", false,-1);
    tracep->declBit(c+619,"pop", false,-1);
    tracep->declBus(c+940,"data_in", false,-1, 7,0);
    tracep->declBit(c+491,"fifo_reset", false,-1);
    tracep->declBit(c+19,"reset_status", false,-1);
    tracep->declBus(c+1114,"data_out", false,-1, 7,0);
    tracep->declBit(c+621,"overrun", false,-1);
    tracep->declBus(c+525,"count", false,-1, 4,0);
    tracep->declBus(c+622,"top", false,-1, 3,0);
    tracep->declBus(c+623,"bottom", false,-1, 3,0);
    tracep->declBus(c+624,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1163,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1169,"data_width", false,-1, 31,0);
    tracep->declBus(c+1170,"depth", false,-1, 31,0);
    tracep->declBit(c+1070,"clk", false,-1);
    tracep->declBit(c+520,"we", false,-1);
    tracep->declBus(c+622,"a", false,-1, 3,0);
    tracep->declBus(c+623,"dpra", false,-1, 3,0);
    tracep->declBus(c+940,"di", false,-1, 7,0);
    tracep->declBus(c+1114,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+329+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBit(c+832,"auto_in_psel", false,-1);
    tracep->declBit(c+346,"auto_in_penable", false,-1);
    tracep->declBit(c+827,"auto_in_pwrite", false,-1);
    tracep->declBus(c+833,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1118,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+828,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1120,"auto_in_pready", false,-1);
    tracep->declBit(c+1121,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1122,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1084,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1085,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1086,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1087,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1088,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1089,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1070,"clock", false,-1);
    tracep->declBit(c+1071,"reset", false,-1);
    tracep->declBus(c+931,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+832,"in_psel", false,-1);
    tracep->declBit(c+346,"in_penable", false,-1);
    tracep->declBus(c+1118,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+827,"in_pwrite", false,-1);
    tracep->declBus(c+828,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+829,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1120,"in_pready", false,-1);
    tracep->declBus(c+1122,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1121,"in_pslverr", false,-1);
    tracep->declBus(c+1084,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1085,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1086,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1087,"vga_hsync", false,-1);
    tracep->declBit(c+1088,"vga_vsync", false,-1);
    tracep->declBit(c+1089,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+388,"sck", false,-1);
    tracep->declBit(c+625,"ss", false,-1);
    tracep->declBit(c+1092,"mosi", false,-1);
    tracep->declBit(c+1138,"miso", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+388,"sck", false,-1);
    tracep->declBit(c+626,"ss", false,-1);
    tracep->declBit(c+1092,"mosi", false,-1);
    tracep->declBit(c+1093,"miso", false,-1);
    tracep->declBit(c+626,"reset", false,-1);
    tracep->declBus(c+704,"state", false,-1, 2,0);
    tracep->declBus(c+705,"counter", false,-1, 7,0);
    tracep->declBus(c+706,"cmd", false,-1, 7,0);
    tracep->declBus(c+707,"addr", false,-1, 23,0);
    tracep->declBus(c+708,"data", false,-1, 31,0);
    tracep->declBit(c+709,"ren", false,-1);
    tracep->declBus(c+1115,"rdata", false,-1, 31,0);
    tracep->declBus(c+1116,"raddr", false,-1, 31,0);
    tracep->declBus(c+1117,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+388,"clock", false,-1);
    tracep->declBit(c+709,"valid", false,-1);
    tracep->declBus(c+706,"cmd", false,-1, 7,0);
    tracep->declBus(c+1116,"addr", false,-1, 31,0);
    tracep->declBus(c+1115,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+1094,"sck", false,-1);
    tracep->declBit(c+1095,"ce_n", false,-1);
    tracep->declBus(c+941,"dio", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1096,"clk", false,-1);
    tracep->declBit(c+390,"cke", false,-1);
    tracep->declBit(c+391,"cs", false,-1);
    tracep->declBit(c+392,"ras", false,-1);
    tracep->declBit(c+393,"cas", false,-1);
    tracep->declBit(c+394,"we", false,-1);
    tracep->declBus(c+395,"a", false,-1, 12,0);
    tracep->declBus(c+396,"ba", false,-1, 1,0);
    tracep->declBus(c+397,"dqm", false,-1, 1,0);
    tracep->declBus(c+398,"dq", false,-1, 15,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_init_top(VysyxSoCFull___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_init_top\n"); );
    // Body
    VysyxSoCFull___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VysyxSoCFull___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VysyxSoCFull___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VysyxSoCFull___024root__trace_register(VysyxSoCFull___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VysyxSoCFull___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VysyxSoCFull___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VysyxSoCFull___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_sub_0(VysyxSoCFull___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_full_top_0\n"); );
    // Init
    VysyxSoCFull___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VysyxSoCFull___024root*>(voidSelf);
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VysyxSoCFull___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_sub_0(VysyxSoCFull___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_h49f7fb6a__0;
    VlWide<5>/*159:0*/ __Vtemp_h3a4ae3bd__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullSData(oldp+3,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),14);
    bufp->fullSData(oldp+4,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),14);
    bufp->fullSData(oldp+5,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),14);
    bufp->fullSData(oldp+6,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),14);
    bufp->fullSData(oldp+7,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+8,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+9,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+10,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullCData(oldp+11,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+12,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+13,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+14,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),2);
    bufp->fullCData(oldp+15,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+16,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+17,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+18,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullBit(oldp+19,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+20,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+21,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+22,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+23,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+24,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullBit(oldp+25,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullIData(oldp+26,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                               [3U] << 0x18U) | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                  [2U] 
                                                  << 0x10U) 
                                                 | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [1U] 
                                                     << 8U) 
                                                    | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                    [0U])))),32);
    bufp->fullCData(oldp+27,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+28,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullCData(oldp+29,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+30,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+31,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+32,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+33,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+34,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+35,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+36,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+37,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+38,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+39,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+40,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+41,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+42,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+43,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+44,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+45,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+46,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+47,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+48,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+49,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+50,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+51,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+52,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+53,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+54,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+55,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+56,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+57,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+58,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+59,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+60,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+61,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+62,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+63,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+64,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+65,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+66,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+67,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+68,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+69,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+70,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+71,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+72,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+73,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+74,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+75,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+77,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+78,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullCData(oldp+79,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullQData(oldp+80,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+82,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+83,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                   ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                              >> 0x24U))
                                   : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+84,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+86,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+87,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+89,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                               ? 0U : 3U)),2);
    bufp->fullBit(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+91,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+93,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                               ? 0U : 3U)),2);
    bufp->fullBit(oldp+94,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+95,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+97,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+98,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+99,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+102,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+112,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+133,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+134,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+135,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+136,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+137,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+138,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+148,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+149,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+152,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+153,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+154,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+156,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+158,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+162,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+164,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+165,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+166,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+170,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+173,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+174,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+175,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+176,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+178,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+179,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+181,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+182,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+186,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+190,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+194,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+198,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+202,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+206,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+210,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+214,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+218,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+222,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+226,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+230,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+232,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+234,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+235,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+236,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+237,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+238,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+239,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+240,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+241,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+242,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+243,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+244,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+245,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+246,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+247,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+248,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+250,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+254,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+258,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+259,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+260,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+261,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+262,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+265,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+266,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+267,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+268,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+269,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+270,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+271,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+272,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+273,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+274,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+276,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+277,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+278,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+279,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+280,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+281,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+282,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+284,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+285,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+286,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full))))));
    bufp->fullCData(oldp+287,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                               & (- (IData)((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full))))))),2);
    bufp->fullCData(oldp+288,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                               & (- (IData)((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full))))))),2);
    bufp->fullBit(oldp+289,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+291,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+292,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                    & (- (IData)((1U 
                                                  & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))))) 
                                   >> 1U))));
    bufp->fullBit(oldp+293,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                    & (- (IData)((1U 
                                                  & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))))) 
                                   >> 1U))));
    bufp->fullBit(oldp+294,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__bresp_get));
    bufp->fullBit(oldp+295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__rvalid_get));
    bufp->fullBit(oldp+296,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                     & (- (IData)((1U 
                                                   & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))))) 
                                    & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                       & (- (IData)(
                                                    (1U 
                                                     & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full))))))) 
                                   >> 1U))));
    bufp->fullBit(oldp+297,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+307,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+308,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+309,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+310,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullCData(oldp+311,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+312,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+313,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+316,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+317,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+321,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+322,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+324,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+325,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+326,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+327,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullBit(oldp+345,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+346,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+347,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+348,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+349,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullCData(oldp+350,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                   << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))),2);
    bufp->fullIData(oldp+351,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                 ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                 : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                            ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                            : 0U) | 
                                          ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                            : 0U)))),32);
    bufp->fullBit(oldp+352,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
                                << 0xfU) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last) 
                                             << 0xeU) 
                                            | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last) 
                                                << 0xdU) 
                                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last) 
                                                   << 0xcU) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last) 
                                                      << 0xbU) 
                                                     | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last) 
                                                         << 0xaU) 
                                                        | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last) 
                                                            << 9U) 
                                                           | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last) 
                                                                  << 7U) 
                                                                 | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last) 
                                                                     << 6U) 
                                                                    | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last) 
                                                                        << 5U) 
                                                                       | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last) 
                                                                           << 4U) 
                                                                          | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last) 
                                                                              << 3U) 
                                                                             | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last)))))))))))))))) 
                              >> (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5))));
    bufp->fullBit(oldp+353,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
                                     << 0xfU) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last) 
                                                  << 0xeU) 
                                                 | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last) 
                                                     << 0xdU) 
                                                    | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last) 
                                                        << 0xcU) 
                                                       | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last) 
                                                           << 0xbU) 
                                                          | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last) 
                                                              << 0xaU) 
                                                             | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last) 
                                                                 << 9U) 
                                                                | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last) 
                                                                    << 8U) 
                                                                   | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last) 
                                                                       << 7U) 
                                                                      | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last) 
                                                                          << 6U) 
                                                                         | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last) 
                                                                             << 5U) 
                                                                            | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last) 
                                                                                << 4U) 
                                                                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last)))))))))))))))) 
                                   >> (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)))));
    bufp->fullBit(oldp+354,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+355,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+356,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+357,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+358,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+359,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+360,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+361,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+362,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+363,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+364,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+365,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+366,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+367,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+368,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+369,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+370,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+371,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+372,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+373,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+374,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+375,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+376,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+377,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+378,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+379,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+380,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+381,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+382,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+383,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+384,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+385,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+386,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                               & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+387,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                    & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                   >> 1U))));
    bufp->fullBit(oldp+388,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+389,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+391,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+392,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+393,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+394,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullSData(oldp+398,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                  ? 0U : 0xffffU) & 
                                ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                    ? 0U : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                      ? 0U : 0xffffU)) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                     ? 0U : 0xffffU))) 
                               & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                   ? 0U : 0xffffU))),16);
    bufp->fullBit(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullIData(oldp+400,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+401,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_pready));
    bufp->fullIData(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+405,((0xfU & ((8U > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                        ? (1U & (0xebU 
                                                 >> 
                                                 (7U 
                                                  & ((IData)(7U) 
                                                     - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))))
                                        : ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                            ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr 
                                               >> 0x14U)
                                            : ((9U 
                                                == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                                ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr 
                                                   >> 0x10U)
                                                : (
                                                   (0xaU 
                                                    == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                                    ? 
                                                   (vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr 
                                                    >> 0xcU)
                                                    : 
                                                   ((0xbU 
                                                     == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                                     ? 
                                                    (vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr 
                                                     >> 8U)
                                                     : 
                                                    ((0xcU 
                                                      == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                                      ? 
                                                     (vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr 
                                                      >> 4U)
                                                      : 
                                                     ((0xdU 
                                                       == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                                       ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr
                                                       : 0U))))))))),4);
    bufp->fullBit(oldp+406,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+409,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+410,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+415,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullBit(oldp+419,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+421,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullBit(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullCData(oldp+433,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+444,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullSData(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+452,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+453,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+454,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+455,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+456,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+457,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+458,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+461,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+462,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+464,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+465,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+467,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+468,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+471,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+472,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+474,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+484,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+486,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+488,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+492,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+493,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+494,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+495,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+496,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+497,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+498,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
                                << 7U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r) 
                                           << 6U) | 
                                          (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r) 
                                            << 5U) 
                                           | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r) 
                                               << 4U) 
                                              | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r) 
                                                  << 3U) 
                                                 | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r) 
                                                     << 2U) 
                                                    | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r) 
                                                        << 1U) 
                                                       | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r))))))))),8);
    bufp->fullBit(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+501,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+502,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+503,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+506,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+510,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+512,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+514,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+516,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+518,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+522,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                    [0U] | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                            [1U] | 
                                            (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                             [2U] | 
                                             (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                              [3U] 
                                              | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                 [4U] 
                                                 | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                    [5U] 
                                                    | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                       [6U] 
                                                       | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                          [7U] 
                                                          | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                             [8U] 
                                                             | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                [9U] 
                                                                | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                   [0xaU] 
                                                                   | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                      [0xbU] 
                                                                      | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                         [0xcU] 
                                                                         | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                            [0xdU] 
                                                                            | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                               [0xeU] 
                                                                               | vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                               [0xfU]))))))))))))))))));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+524,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+525,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+526,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+529,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+530,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+532,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+533,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+534,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+536,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+538,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+540,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+541,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+542,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+544,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+545,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+546,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+548,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+549,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+550,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+551,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+552,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+554,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+558,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+560,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+562,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+566,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+570,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+571,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+572,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+573,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+574,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+575,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+577,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+582,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+590,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+594,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+596,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+598,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+602,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+606,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+613,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+614,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+615,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+617,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+618,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+621,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+622,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+623,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+624,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+625,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_ss) 
                                   >> 7U))));
    bufp->fullBit(oldp+626,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullIData(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+628,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+629,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+630,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+632,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+633,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+634,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+637,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+639,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+641,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+642,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+643,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+644,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+647,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+649,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+651,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+652,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+653,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+655,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+656,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+658,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+660,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+666,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+670,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+673,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+674,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+675,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+676,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+677,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+679,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+680,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+681,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+682,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+683,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+684,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+685,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+686,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+687,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+688,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+689,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+690,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+691,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+692,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+693,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+694,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+695,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+696,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+697,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+698,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+699,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+701,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+702,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+704,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+705,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+706,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+707,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+708,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+709,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                             & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullBit(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullCData(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullBit(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+715,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+716,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+717,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+718,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+719,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+720,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+721,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+722,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+723,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+724,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+725,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+726,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+727,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+728,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+729,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+730,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+731,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+732,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+733,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+734,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+735,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+736,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+737,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+738,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+739,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+740,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                      | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+741,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+742,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+743,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+744,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+746,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+747,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+748,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+749,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+750,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+752,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+753,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+754,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+756,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+758,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+759,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+760,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+761,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+762,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+763,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+764,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+765,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+766,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+767,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+768,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+769,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+770,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+771,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+772,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+773,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+774,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+775,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+776,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+777,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+778,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+779,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+780,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+781,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+782,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+783,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+784,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+785,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                             | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+786,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),2);
    bufp->fullSData(oldp+788,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+789,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+790,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullCData(oldp+793,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                ? 1U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                         ? 3U : ((3U 
                                                  == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                  ? 7U
                                                  : 0xfU)))),4);
    bufp->fullBit(oldp+794,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                             & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                >> 2U))));
    bufp->fullBit(oldp+795,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+796,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
                             & (0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                 >> 0x1bU)) 
                                       | ((0xcU & (8U 
                                                   ^ 
                                                   (0x3cU 
                                                    & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                       >> 0x1aU)))) 
                                          | ((2U & 
                                              (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                               >> 0x17U)) 
                                             | (1U 
                                                & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                   >> 0xcU)))))))));
    bufp->fullBit(oldp+797,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                             & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                >> 1U))));
    bufp->fullBit(oldp+798,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    __Vtemp_h49f7fb6a__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))));
    __Vtemp_h49f7fb6a__0[1U] = ((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h49f7fb6a__0[2U] = (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+799,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+804,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+806,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+807,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    __Vtemp_h3a4ae3bd__0[0U] = (IData)((0x400000000ULL 
                                        | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg))));
    __Vtemp_h3a4ae3bd__0[1U] = ((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm 
                                 << 3U) | (IData)((
                                                   (0x400000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg))) 
                                                   >> 0x20U)));
    __Vtemp_h3a4ae3bd__0[2U] = (0x10U | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread 
                                          << 6U) | 
                                         (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm 
                                          >> 0x1dU)));
    __Vtemp_h3a4ae3bd__0[3U] = (0x40U | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                                          << 9U) | 
                                         (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread 
                                          >> 0x1aU)));
    __Vtemp_h3a4ae3bd__0[4U] = (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                                >> 0x17U);
    bufp->fullWData(oldp+808,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+815,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+821,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+822,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+823,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+824,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+827,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+828,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+829,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+830,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+831,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+832,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+833,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+834,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+835,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+836,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+837,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+839,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+840,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+841,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_psel));
    bufp->fullBit(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_penable));
    bufp->fullBit(oldp+843,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+848,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+850,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullIData(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullBit(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullIData(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullBit(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullIData(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullCData(oldp+858,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullIData(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullIData(oldp+860,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullIData(oldp+861,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+862,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+864,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullBit(oldp+866,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+867,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+868,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+869,((0x7800U == (0x7fffU & 
                                         (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 0xdU)))));
    bufp->fullSData(oldp+870,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                         >> 2U))),11);
    bufp->fullSData(oldp+871,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                         >> 2U))),11);
    bufp->fullIData(oldp+872,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+874,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+875,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+877,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                              >> 0x1bU)) 
                                    | ((0xcU & (8U 
                                                ^ (0x3cU 
                                                   & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                      >> 0x1aU)))) 
                                       | ((2U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                 >> 0x17U)) 
                                          | (1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                   >> 0xcU))))))));
    bufp->fullBit(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullIData(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullIData(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+894,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullIData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+900,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+901,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                             >> 0x1fU)));
    bufp->fullBit(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+905,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+909,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullIData(oldp+910,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+918,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+919,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+920,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+921,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+922,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+923,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+928,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+929,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+930,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+931,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullCData(oldp+932,((0x1fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),5);
    bufp->fullBit(oldp+933,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullBit(oldp+934,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+935,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                 & (0xcU == (0x1cU 
                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))) 
                                << 3U) | ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                            & (8U == 
                                               (0x1cU 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))) 
                                           << 2U) | 
                                          ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                             & (4U 
                                                == 
                                                (0x1cU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))) 
                                            << 1U) 
                                           | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                              & (0U 
                                                 == 
                                                 (0x1cU 
                                                  & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))))))),4);
    bufp->fullBit(oldp+936,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+937,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullCData(oldp+938,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+939,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+940,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullCData(oldp+941,((((((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out0) 
                                         & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten))) 
                                  | (0xcU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out1) 
                                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten)))) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0))),4);
    bufp->fullBit(oldp+942,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+943,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+944,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+945,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+946,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+947,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+948,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+949,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+950,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+951,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+952,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+953,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+954,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+955,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+956,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+957,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+958,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+959,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+960,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+961,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+962,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+963,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+964,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+965,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+966,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+967,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+968,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+969,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+972,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+973,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+975,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+976,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+977,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+978,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+979,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+980,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+981,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+983,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+984,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+985,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+987,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+988,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+989,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+990,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+991,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+992,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+993,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+994,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+995,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+996,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+997,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+998,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+999,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1000,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1001,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1002,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1003,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1004,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1005,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1006,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1007,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1008,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1009,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1010,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1011,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1012,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1013,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1014,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1015,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1016,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1017,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1018,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1019,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1020,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1021,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1022,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1023,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                              & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+1024,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1025,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1026,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1027,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1028,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1029,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                              & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+1030,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+1031,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+1032,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [0U]),32);
    bufp->fullIData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+1034,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+1038,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                               [1U]),2);
    bufp->fullBit(oldp+1045,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                    >> 1U))));
    bufp->fullIData(oldp+1046,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U]),32);
    bufp->fullIData(oldp+1047,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+1048,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+1049,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+1050,((((- (IData)((1U & (
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                                   [1U] 
                                                   >> 7U)))) 
                                 << 8U) | (0xffU & 
                                           vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                           [1U]))),32);
    bufp->fullIData(oldp+1051,((((- (IData)((1U & (
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                                   [1U] 
                                                   >> 0xfU)))) 
                                 << 0x10U) | (0xffffU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                              [1U]))),32);
    bufp->fullCData(oldp+1052,((0xffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                [1U])),8);
    bufp->fullSData(oldp+1053,((0xffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                [1U])),16);
    bufp->fullIData(oldp+1054,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+1055,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1056,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+1057,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+1058,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+1059,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+1060,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+1061,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+1062,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+1063,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+1064,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+1065,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+1066,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+1067,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+1068,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+1069,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+1070,(vlSelf->clock));
    bufp->fullBit(oldp+1071,(vlSelf->reset));
    bufp->fullSData(oldp+1072,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1073,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1074,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1075,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1076,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1077,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1078,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1079,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1080,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1081,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1082,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1083,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1084,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1085,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1086,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1087,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1088,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1089,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1090,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1091,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1092,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+1093,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullBit(oldp+1094,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck))));
    bufp->fullBit(oldp+1095,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n))));
    bufp->fullBit(oldp+1096,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullBit(oldp+1097,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1098,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullBit(oldp+1099,((0U != (((0x23U == (0x7fU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                      << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant)))));
    bufp->fullCData(oldp+1100,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1101,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1102,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1103,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
    bufp->fullBit(oldp+1104,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullBit(oldp+1105,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
                               & ((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                     | ((0x33U == (0x7fU 
                                                   & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                        | ((0x6fU == 
                                            (0x7fU 
                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                           | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))) 
                              | ((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                    >> 1U)))));
    bufp->fullBit(oldp+1106,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
                                  & ((3U != (0x7fU 
                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                     & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                        | ((0x33U == 
                                            (0x7fU 
                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                           | ((0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                              | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))) 
                                 | ((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                       >> 1U))))));
    bufp->fullBit(oldp+1107,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__rvalid_get)) 
                              & (3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))));
    bufp->fullBit(oldp+1108,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1109,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullBit(oldp+1110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+1111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullSData(oldp+1112,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullIData(oldp+1115,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1116,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1117,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullCData(oldp+1118,(1U),3);
    bufp->fullBit(oldp+1119,(0U));
    bufp->fullBit(oldp+1120,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1121,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1122,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1123,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1124,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1125,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1126,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pready));
    bufp->fullBit(oldp+1127,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullIData(oldp+1128,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_prdata),32);
    bufp->fullCData(oldp+1129,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1130,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullCData(oldp+1131,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awsize),3);
    bufp->fullCData(oldp+1132,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullBit(oldp+1133,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1134,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1135,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arlen),8);
    bufp->fullCData(oldp+1136,(3U),3);
    bufp->fullCData(oldp+1137,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arburst),2);
    bufp->fullBit(oldp+1138,(1U));
    bufp->fullBit(oldp+1139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1140,(0U),32);
    bufp->fullCData(oldp+1141,(0U),4);
    bufp->fullCData(oldp+1142,(0U),8);
    bufp->fullCData(oldp+1143,(0U),3);
    bufp->fullCData(oldp+1144,(0U),2);
    bufp->fullBit(oldp+1145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1149,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1152,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1153,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1154,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1155,(2U),32);
    bufp->fullIData(oldp+1156,(2U),32);
    bufp->fullIData(oldp+1157,(1U),32);
    bufp->fullIData(oldp+1158,(0x20U),32);
    bufp->fullIData(oldp+1159,(0U),32);
    bufp->fullIData(oldp+1160,(0x21U),32);
    bufp->fullIData(oldp+1161,(2U),32);
    bufp->fullIData(oldp+1162,(0x1ffffffcU),32);
    bufp->fullIData(oldp+1163,(4U),32);
    bufp->fullIData(oldp+1164,(0xcU),32);
    bufp->fullQData(oldp+1165,(0x3000c153418d0bULL),56);
    bufp->fullIData(oldp+1167,(0xeU),32);
    bufp->fullIData(oldp+1168,(4U),32);
    bufp->fullIData(oldp+1169,(8U),32);
    bufp->fullIData(oldp+1170,(0x10U),32);
    bufp->fullIData(oldp+1171,(3U),32);
    bufp->fullIData(oldp+1172,(0x23U),32);
    bufp->fullBit(oldp+1173,(0U));
    bufp->fullBit(oldp+1174,(1U));
    bufp->fullCData(oldp+1175,(4U),3);
    bufp->fullCData(oldp+1176,(0x1bU),8);
    bufp->fullCData(oldp+1177,(0xebU),8);
    bufp->fullCData(oldp+1178,(0x38U),8);
    bufp->fullIData(oldp+1179,(0x64U),32);
    bufp->fullIData(oldp+1180,(0x18U),32);
    bufp->fullIData(oldp+1181,(9U),32);
    bufp->fullIData(oldp+1182,(0xdU),32);
    bufp->fullIData(oldp+1183,(0x2000U),32);
    bufp->fullIData(oldp+1184,(0x2710U),32);
    bufp->fullIData(oldp+1185,(0x30cU),32);
    bufp->fullCData(oldp+1186,(7U),4);
    bufp->fullCData(oldp+1187,(3U),4);
    bufp->fullCData(oldp+1188,(5U),4);
    bufp->fullCData(oldp+1189,(4U),4);
    bufp->fullCData(oldp+1190,(6U),4);
    bufp->fullCData(oldp+1191,(2U),4);
    bufp->fullCData(oldp+1192,(1U),4);
    bufp->fullSData(oldp+1193,(0x21U),13);
    bufp->fullCData(oldp+1194,(8U),4);
    bufp->fullCData(oldp+1195,(9U),4);
    bufp->fullIData(oldp+1196,(0xaU),32);
    bufp->fullIData(oldp+1197,(6U),32);
    bufp->fullIData(oldp+1198,(0x11U),32);
    bufp->fullIData(oldp+1199,(0x30000000U),32);
    bufp->fullIData(oldp+1200,(0x3fffffffU),32);
    bufp->fullCData(oldp+1201,(0xaU),4);
    bufp->fullIData(oldp+1202,(0xbU),32);
    bufp->fullIData(oldp+1203,(5U),32);
    bufp->fullCData(oldp+1204,(2U),3);
    bufp->fullCData(oldp+1205,(5U),3);
}
