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
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+1065,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1066,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1067,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1068,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1069,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1070,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1071,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1072,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1073,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1074,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1075,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1076,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1077,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1078,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1079,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1080,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1081,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1082,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1083,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1084,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+1065,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1066,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1067,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1068,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1069,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1070,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1071,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1072,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1073,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1074,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1075,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1076,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1077,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1078,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1079,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1080,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1081,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1082,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1083,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1084,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+612,"spi_sck", false,-1);
    tracep->declBus(c+613,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1085,"spi_mosi", false,-1);
    tracep->declBit(c+1086,"spi_miso", false,-1);
    tracep->declBit(c+1083,"uart_rx", false,-1);
    tracep->declBit(c+1084,"uart_tx", false,-1);
    tracep->declBit(c+1087,"psram_sck", false,-1);
    tracep->declBit(c+1088,"psram_ce_n", false,-1);
    tracep->declBus(c+157,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1089,"sdram_clk", false,-1);
    tracep->declBit(c+614,"sdram_cke", false,-1);
    tracep->declBit(c+615,"sdram_cs", false,-1);
    tracep->declBit(c+616,"sdram_ras", false,-1);
    tracep->declBit(c+617,"sdram_cas", false,-1);
    tracep->declBit(c+618,"sdram_we", false,-1);
    tracep->declBus(c+619,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+620,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+621,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+622,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1065,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1066,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1067,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1068,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1069,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1070,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1071,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1072,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1073,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1074,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1075,"ps2_clk", false,-1);
    tracep->declBit(c+1076,"ps2_data", false,-1);
    tracep->declBus(c+1077,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1078,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1079,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1080,"vga_hsync", false,-1);
    tracep->declBit(c+1081,"vga_vsync", false,-1);
    tracep->declBit(c+1082,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+92,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+93,"in_psel", false,-1);
    tracep->declBit(c+292,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+158,"in_pready", false,-1);
    tracep->declBus(c+159,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+97,"in_pslverr", false,-1);
    tracep->declBus(c+92,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+93,"out_psel", false,-1);
    tracep->declBit(c+292,"out_penable", false,-1);
    tracep->declBus(c+1119,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"out_pwrite", false,-1);
    tracep->declBus(c+95,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+158,"out_pready", false,-1);
    tracep->declBus(c+159,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+97,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+93,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+292,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+92,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1119,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+158,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+97,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+159,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+98,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+1090,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+92,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1119,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+623,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1120,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+624,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+99,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+1091,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+100,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1119,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1121,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1122,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1123,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+101,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+1092,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+102,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1119,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1124,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1125,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1126,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+103,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+1093,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+102,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1119,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+1127,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1128,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1129,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+104,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+1094,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+92,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1119,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1095,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1120,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+293,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+105,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+106,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+102,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1119,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+107,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1120,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1096,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+108,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+109,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+94,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+100,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1119,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+625,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1120,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+626,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+110,"sel_0", false,-1);
    tracep->declBit(c+111,"sel_1", false,-1);
    tracep->declBit(c+112,"sel_2", false,-1);
    tracep->declBit(c+113,"sel_3", false,-1);
    tracep->declBit(c+114,"sel_4", false,-1);
    tracep->declBit(c+115,"sel_5", false,-1);
    tracep->declBit(c+116,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+117,"auto_in_awready", false,-1);
    tracep->declBit(c+118,"auto_in_awvalid", false,-1);
    tracep->declBus(c+294,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1010,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+295,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+117,"auto_in_wready", false,-1);
    tracep->declBit(c+119,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+160,"auto_in_bready", false,-1);
    tracep->declBit(c+161,"auto_in_bvalid", false,-1);
    tracep->declBus(c+296,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+1097,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+120,"auto_in_arready", false,-1);
    tracep->declBit(c+121,"auto_in_arvalid", false,-1);
    tracep->declBus(c+297,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1012,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+298,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+162,"auto_in_rready", false,-1);
    tracep->declBit(c+163,"auto_in_rvalid", false,-1);
    tracep->declBus(c+299,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+164,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1097,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+93,"auto_out_psel", false,-1);
    tracep->declBit(c+292,"auto_out_penable", false,-1);
    tracep->declBit(c+94,"auto_out_pwrite", false,-1);
    tracep->declBus(c+92,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+95,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+158,"auto_out_pready", false,-1);
    tracep->declBit(c+97,"auto_out_pslverr", false,-1);
    tracep->declBus(c+159,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+292,"nodeOut_penable", false,-1);
    tracep->declBus(c+300,"state", false,-1, 1,0);
    tracep->declBit(c+120,"accept_read", false,-1);
    tracep->declBit(c+117,"accept_write", false,-1);
    tracep->declBit(c+301,"is_write_r", false,-1);
    tracep->declBit(c+94,"is_write", false,-1);
    tracep->declBus(c+299,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+296,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+302,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+303,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+304,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+305,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+122,"resp", false,-1, 1,0);
    tracep->declBus(c+306,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+1097,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+163,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+307,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+161,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+308,"auto_in_awready", false,-1);
    tracep->declBit(c+56,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1130,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1013,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1131,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1132,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1133,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+309,"auto_in_wready", false,-1);
    tracep->declBit(c+57,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1014,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+935,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1134,"auto_in_wlast", false,-1);
    tracep->declBit(c+1098,"auto_in_bready", false,-1);
    tracep->declBit(c+165,"auto_in_bvalid", false,-1);
    tracep->declBus(c+166,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+167,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+310,"auto_in_arready", false,-1);
    tracep->declBit(c+58,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1135,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1015,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1137,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1138,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+59,"auto_in_rready", false,-1);
    tracep->declBit(c+168,"auto_in_rvalid", false,-1);
    tracep->declBus(c+169,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+20,"auto_in_rlast", false,-1);
    tracep->declBit(c+170,"auto_out_awready", false,-1);
    tracep->declBit(c+60,"auto_out_awvalid", false,-1);
    tracep->declBus(c+294,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1010,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+295,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+311,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+171,"auto_out_wready", false,-1);
    tracep->declBit(c+61,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+62,"auto_out_wlast", false,-1);
    tracep->declBit(c+172,"auto_out_bready", false,-1);
    tracep->declBit(c+173,"auto_out_bvalid", false,-1);
    tracep->declBus(c+166,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+174,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+175,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+176,"auto_out_arready", false,-1);
    tracep->declBit(c+63,"auto_out_arvalid", false,-1);
    tracep->declBus(c+297,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1012,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+298,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+312,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+59,"auto_out_rready", false,-1);
    tracep->declBit(c+168,"auto_out_rvalid", false,-1);
    tracep->declBus(c+169,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+21,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+177,"auto_out_rlast", false,-1);
    tracep->declBit(c+61,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+313,"w_idle", false,-1);
    tracep->declBit(c+178,"in_awready", false,-1);
    tracep->declBit(c+314,"busy", false,-1);
    tracep->declBus(c+315,"r_addr", false,-1, 31,0);
    tracep->declBus(c+316,"r_len", false,-1, 7,0);
    tracep->declBus(c+317,"len", false,-1, 7,0);
    tracep->declBus(c+1016,"addr", false,-1, 31,0);
    tracep->declBit(c+318,"busy_1", false,-1);
    tracep->declBus(c+319,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+320,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+321,"len_1", false,-1, 7,0);
    tracep->declBus(c+1017,"addr_1", false,-1, 31,0);
    tracep->declBit(c+322,"wbeats_latched", false,-1);
    tracep->declBit(c+60,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+64,"wbeats_valid", false,-1);
    tracep->declBus(c+323,"w_counter", false,-1, 8,0);
    tracep->declBus(c+65,"w_todo", false,-1, 8,0);
    tracep->declBit(c+62,"w_last", false,-1);
    tracep->declBit(c+172,"nodeOut_bready", false,-1);
    tracep->declBus(c+324,"error_0", false,-1, 1,0);
    tracep->declBus(c+325,"error_1", false,-1, 1,0);
    tracep->declBus(c+326,"error_2", false,-1, 1,0);
    tracep->declBus(c+327,"error_3", false,-1, 1,0);
    tracep->declBus(c+328,"error_4", false,-1, 1,0);
    tracep->declBus(c+329,"error_5", false,-1, 1,0);
    tracep->declBus(c+330,"error_6", false,-1, 1,0);
    tracep->declBus(c+331,"error_7", false,-1, 1,0);
    tracep->declBus(c+332,"error_8", false,-1, 1,0);
    tracep->declBus(c+333,"error_9", false,-1, 1,0);
    tracep->declBus(c+334,"error_10", false,-1, 1,0);
    tracep->declBus(c+335,"error_11", false,-1, 1,0);
    tracep->declBus(c+336,"error_12", false,-1, 1,0);
    tracep->declBus(c+337,"error_13", false,-1, 1,0);
    tracep->declBus(c+338,"error_14", false,-1, 1,0);
    tracep->declBus(c+339,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+310,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBus(c+1135,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1015,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1136,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1137,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1138,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+179,"io_deq_ready", false,-1);
    tracep->declBit(c+63,"io_deq_valid", false,-1);
    tracep->declBus(c+297,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1018,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+340,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+298,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+341,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+342,"ram", false,-1, 48,0);
    tracep->declBit(c+344,"full", false,-1);
    tracep->declBit(c+63,"io_deq_valid_0", false,-1);
    tracep->declBit(c+180,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+308,"io_enq_ready", false,-1);
    tracep->declBit(c+56,"io_enq_valid", false,-1);
    tracep->declBus(c+1130,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1013,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1131,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1132,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1133,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+181,"io_deq_ready", false,-1);
    tracep->declBit(c+66,"io_deq_valid", false,-1);
    tracep->declBus(c+294,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1019,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+345,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+295,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+346,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+347,"ram", false,-1, 48,0);
    tracep->declBit(c+349,"full", false,-1);
    tracep->declBit(c+66,"io_deq_valid_0", false,-1);
    tracep->declBit(c+182,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+309,"io_enq_ready", false,-1);
    tracep->declBit(c+57,"io_enq_valid", false,-1);
    tracep->declBus(c+1014,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+935,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1134,"io_enq_bits_last", false,-1);
    tracep->declBit(c+183,"io_deq_ready", false,-1);
    tracep->declBit(c+67,"io_deq_valid", false,-1);
    tracep->declBus(c+1011,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+934,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+350,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+351,"ram", false,-1, 36,0);
    tracep->declBit(c+353,"full", false,-1);
    tracep->declBit(c+67,"io_deq_valid_0", false,-1);
    tracep->declBit(c+184,"do_enq", false,-1);
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
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+185,"auto_in_awready", false,-1);
    tracep->declBit(c+123,"auto_in_awvalid", false,-1);
    tracep->declBus(c+294,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1020,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1100,"auto_in_wready", false,-1);
    tracep->declBit(c+1101,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+186,"auto_in_bready", false,-1);
    tracep->declBit(c+354,"auto_in_bvalid", false,-1);
    tracep->declBus(c+355,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+356,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+187,"auto_in_arready", false,-1);
    tracep->declBit(c+1102,"auto_in_arvalid", false,-1);
    tracep->declBus(c+297,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1021,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+188,"auto_in_rready", false,-1);
    tracep->declBit(c+357,"auto_in_rvalid", false,-1);
    tracep->declBus(c+358,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+359,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+360,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+187,"nodeIn_arready", false,-1);
    tracep->declBit(c+185,"nodeIn_awready", false,-1);
    tracep->declBit(c+1022,"w_sel0", false,-1);
    tracep->declBit(c+354,"w_full", false,-1);
    tracep->declBus(c+355,"w_id", false,-1, 3,0);
    tracep->declBit(c+361,"r_sel1", false,-1);
    tracep->declBit(c+362,"w_sel1", false,-1);
    tracep->declBit(c+357,"r_full", false,-1);
    tracep->declBus(c+358,"r_id", false,-1, 3,0);
    tracep->declBit(c+189,"ren", false,-1);
    tracep->declBit(c+363,"rdata_REG", false,-1);
    tracep->declBus(c+364,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+365,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+366,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+367,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1023,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+189,"R0_en", false,-1);
    tracep->declBit(c+1063,"R0_clk", false,-1);
    tracep->declBus(c+368,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1024,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+190,"W0_en", false,-1);
    tracep->declBit(c+1063,"W0_clk", false,-1);
    tracep->declBus(c+1011,"W0_data", false,-1, 31,0);
    tracep->declBus(c+934,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+308,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+56,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1130,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1013,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1131,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1132,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1133,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+309,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+57,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1014,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+935,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1134,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1098,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+165,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+166,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+167,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+310,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+58,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1135,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1015,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1137,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1138,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+59,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+168,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+169,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+20,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+308,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+56,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1130,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1013,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1131,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1132,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1133,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+309,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+57,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1014,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+935,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1134,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1098,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+165,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+166,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+167,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+310,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+58,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1135,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1015,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1137,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1138,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+59,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+168,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+169,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+20,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+191,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+68,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+294,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1010,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+295,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+171,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+61,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+62,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+172,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+173,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+166,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+174,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+192,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+69,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+297,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1012,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+298,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+59,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+168,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+169,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+177,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+185,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+123,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+294,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1020,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1100,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1101,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+186,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+354,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+355,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+356,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+187,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1102,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+297,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1021,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+188,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+357,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+358,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+359,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+360,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1103,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1104,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+369,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1105,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+297,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1025,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1106,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+370,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+371,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+372,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+117,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+118,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+294,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1010,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+295,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+117,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+119,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+160,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+161,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+296,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+1097,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+120,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+121,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+297,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1012,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+298,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+162,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+163,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+299,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+164,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+1097,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+173,"in_0_bvalid", false,-1);
    tracep->declBit(c+168,"in_0_rvalid", false,-1);
    tracep->declBit(c+193,"in_0_wready", false,-1);
    tracep->declBit(c+194,"in_0_awready", false,-1);
    tracep->declBit(c+192,"in_0_arready", false,-1);
    tracep->declBit(c+191,"anonIn_awready", false,-1);
    tracep->declBit(c+1026,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1027,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1028,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1029,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1030,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1031,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+373,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+374,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+375,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+376,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+377,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+378,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+379,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+380,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+381,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+382,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+383,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+384,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+385,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+386,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+387,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+388,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+389,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+390,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+391,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+392,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+393,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+394,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+395,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+396,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+397,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+398,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+399,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+400,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+401,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+402,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+403,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+404,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+405,"latched", false,-1);
    tracep->declBit(c+70,"in_0_awvalid", false,-1);
    tracep->declBit(c+71,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+72,"in_0_wvalid", false,-1);
    tracep->declBit(c+406,"idle_3", false,-1);
    tracep->declBit(c+195,"anyValid", false,-1);
    tracep->declBus(c+196,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+407,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+197,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+198,"prefixOR_1", false,-1);
    tracep->declBit(c+199,"winner_3_1", false,-1);
    tracep->declBit(c+200,"winner_3_2", false,-1);
    tracep->declBit(c+408,"state_3_0", false,-1);
    tracep->declBit(c+409,"state_3_1", false,-1);
    tracep->declBit(c+410,"state_3_2", false,-1);
    tracep->declBit(c+201,"muxState_3_0", false,-1);
    tracep->declBit(c+202,"muxState_3_1", false,-1);
    tracep->declBit(c+203,"muxState_3_2", false,-1);
    tracep->declBit(c+411,"idle_4", false,-1);
    tracep->declBit(c+204,"anyValid_1", false,-1);
    tracep->declBus(c+205,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+412,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+206,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+207,"winner_4_0", false,-1);
    tracep->declBit(c+208,"winner_4_2", false,-1);
    tracep->declBit(c+413,"state_4_0", false,-1);
    tracep->declBit(c+414,"state_4_2", false,-1);
    tracep->declBit(c+209,"muxState_4_0", false,-1);
    tracep->declBit(c+210,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+415,"io_enq_ready", false,-1);
    tracep->declBit(c+71,"io_enq_valid", false,-1);
    tracep->declBus(c+1032,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+211,"io_deq_ready", false,-1);
    tracep->declBit(c+73,"io_deq_valid", false,-1);
    tracep->declBus(c+1033,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+416,"wrap", false,-1);
    tracep->declBit(c+417,"wrap_1", false,-1);
    tracep->declBit(c+418,"maybe_full", false,-1);
    tracep->declBit(c+419,"ptr_match", false,-1);
    tracep->declBit(c+420,"empty", false,-1);
    tracep->declBit(c+421,"full", false,-1);
    tracep->declBit(c+73,"io_deq_valid_0", false,-1);
    tracep->declBit(c+212,"do_deq", false,-1);
    tracep->declBit(c+213,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+417,"R0_addr", false,-1);
    tracep->declBit(c+1139,"R0_en", false,-1);
    tracep->declBit(c+1063,"R0_clk", false,-1);
    tracep->declBus(c+422,"R0_data", false,-1, 2,0);
    tracep->declBit(c+416,"W0_addr", false,-1);
    tracep->declBit(c+213,"W0_en", false,-1);
    tracep->declBit(c+1063,"W0_clk", false,-1);
    tracep->declBus(c+1032,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+423+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+170,"auto_in_awready", false,-1);
    tracep->declBit(c+60,"auto_in_awvalid", false,-1);
    tracep->declBus(c+294,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1010,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+295,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+311,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+171,"auto_in_wready", false,-1);
    tracep->declBit(c+61,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+62,"auto_in_wlast", false,-1);
    tracep->declBit(c+172,"auto_in_bready", false,-1);
    tracep->declBit(c+173,"auto_in_bvalid", false,-1);
    tracep->declBus(c+166,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+174,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+175,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+176,"auto_in_arready", false,-1);
    tracep->declBit(c+63,"auto_in_arvalid", false,-1);
    tracep->declBus(c+297,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1012,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+298,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+312,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+59,"auto_in_rready", false,-1);
    tracep->declBit(c+168,"auto_in_rvalid", false,-1);
    tracep->declBus(c+169,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+21,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+177,"auto_in_rlast", false,-1);
    tracep->declBit(c+191,"auto_out_awready", false,-1);
    tracep->declBit(c+68,"auto_out_awvalid", false,-1);
    tracep->declBus(c+294,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1010,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+295,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+171,"auto_out_wready", false,-1);
    tracep->declBit(c+61,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1011,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+934,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+62,"auto_out_wlast", false,-1);
    tracep->declBit(c+172,"auto_out_bready", false,-1);
    tracep->declBit(c+173,"auto_out_bvalid", false,-1);
    tracep->declBus(c+166,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+174,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+192,"auto_out_arready", false,-1);
    tracep->declBit(c+69,"auto_out_arvalid", false,-1);
    tracep->declBus(c+297,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1012,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+298,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+59,"auto_out_rready", false,-1);
    tracep->declBit(c+168,"auto_out_rvalid", false,-1);
    tracep->declBus(c+169,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+177,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+425,"io_enq_ready", false,-1);
    tracep->declBit(c+22,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+214,"io_deq_ready", false,-1);
    tracep->declBit(c+426,"io_deq_valid", false,-1);
    tracep->declBit(c+427,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+427,"ram_real_last", false,-1);
    tracep->declBit(c+426,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+428,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+429,"io_enq_ready", false,-1);
    tracep->declBit(c+23,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+215,"io_deq_ready", false,-1);
    tracep->declBit(c+430,"io_deq_valid", false,-1);
    tracep->declBit(c+431,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+431,"ram_real_last", false,-1);
    tracep->declBit(c+430,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+432,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+433,"io_enq_ready", false,-1);
    tracep->declBit(c+24,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+216,"io_deq_ready", false,-1);
    tracep->declBit(c+434,"io_deq_valid", false,-1);
    tracep->declBit(c+435,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+435,"ram_real_last", false,-1);
    tracep->declBit(c+434,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+436,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+437,"io_enq_ready", false,-1);
    tracep->declBit(c+25,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+217,"io_deq_ready", false,-1);
    tracep->declBit(c+438,"io_deq_valid", false,-1);
    tracep->declBit(c+439,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+439,"ram_real_last", false,-1);
    tracep->declBit(c+438,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+440,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+441,"io_enq_ready", false,-1);
    tracep->declBit(c+26,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+218,"io_deq_ready", false,-1);
    tracep->declBit(c+442,"io_deq_valid", false,-1);
    tracep->declBit(c+443,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+443,"ram_real_last", false,-1);
    tracep->declBit(c+442,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+444,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+445,"io_enq_ready", false,-1);
    tracep->declBit(c+27,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+219,"io_deq_ready", false,-1);
    tracep->declBit(c+446,"io_deq_valid", false,-1);
    tracep->declBit(c+447,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+447,"ram_real_last", false,-1);
    tracep->declBit(c+446,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+448,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+449,"io_enq_ready", false,-1);
    tracep->declBit(c+28,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+220,"io_deq_ready", false,-1);
    tracep->declBit(c+450,"io_deq_valid", false,-1);
    tracep->declBit(c+451,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+451,"ram_real_last", false,-1);
    tracep->declBit(c+450,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+452,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+453,"io_enq_ready", false,-1);
    tracep->declBit(c+29,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+221,"io_deq_ready", false,-1);
    tracep->declBit(c+454,"io_deq_valid", false,-1);
    tracep->declBit(c+455,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+455,"ram_real_last", false,-1);
    tracep->declBit(c+454,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+456,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+457,"io_enq_ready", false,-1);
    tracep->declBit(c+30,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+222,"io_deq_ready", false,-1);
    tracep->declBit(c+458,"io_deq_valid", false,-1);
    tracep->declBit(c+459,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+459,"ram_real_last", false,-1);
    tracep->declBit(c+458,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+460,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+461,"io_enq_ready", false,-1);
    tracep->declBit(c+31,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+223,"io_deq_ready", false,-1);
    tracep->declBit(c+462,"io_deq_valid", false,-1);
    tracep->declBit(c+463,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+463,"ram_real_last", false,-1);
    tracep->declBit(c+462,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+464,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+465,"io_enq_ready", false,-1);
    tracep->declBit(c+32,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+224,"io_deq_ready", false,-1);
    tracep->declBit(c+466,"io_deq_valid", false,-1);
    tracep->declBit(c+467,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+467,"ram_real_last", false,-1);
    tracep->declBit(c+466,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+468,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+469,"io_enq_ready", false,-1);
    tracep->declBit(c+33,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+225,"io_deq_ready", false,-1);
    tracep->declBit(c+470,"io_deq_valid", false,-1);
    tracep->declBit(c+471,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+471,"ram_real_last", false,-1);
    tracep->declBit(c+470,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+472,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+473,"io_enq_ready", false,-1);
    tracep->declBit(c+34,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+226,"io_deq_ready", false,-1);
    tracep->declBit(c+474,"io_deq_valid", false,-1);
    tracep->declBit(c+475,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+475,"ram_real_last", false,-1);
    tracep->declBit(c+474,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+476,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+477,"io_enq_ready", false,-1);
    tracep->declBit(c+35,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+227,"io_deq_ready", false,-1);
    tracep->declBit(c+478,"io_deq_valid", false,-1);
    tracep->declBit(c+479,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+479,"ram_real_last", false,-1);
    tracep->declBit(c+478,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+480,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+481,"io_enq_ready", false,-1);
    tracep->declBit(c+36,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+228,"io_deq_ready", false,-1);
    tracep->declBit(c+482,"io_deq_valid", false,-1);
    tracep->declBit(c+483,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+483,"ram_real_last", false,-1);
    tracep->declBit(c+482,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+484,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+485,"io_enq_ready", false,-1);
    tracep->declBit(c+37,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+229,"io_deq_ready", false,-1);
    tracep->declBit(c+486,"io_deq_valid", false,-1);
    tracep->declBit(c+487,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+487,"ram_real_last", false,-1);
    tracep->declBit(c+486,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+488,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+489,"io_enq_ready", false,-1);
    tracep->declBit(c+38,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+230,"io_deq_ready", false,-1);
    tracep->declBit(c+490,"io_deq_valid", false,-1);
    tracep->declBit(c+491,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+491,"ram_real_last", false,-1);
    tracep->declBit(c+490,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+492,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+493,"io_enq_ready", false,-1);
    tracep->declBit(c+39,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+231,"io_deq_ready", false,-1);
    tracep->declBit(c+494,"io_deq_valid", false,-1);
    tracep->declBit(c+495,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+495,"ram_real_last", false,-1);
    tracep->declBit(c+494,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+496,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+497,"io_enq_ready", false,-1);
    tracep->declBit(c+40,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+232,"io_deq_ready", false,-1);
    tracep->declBit(c+498,"io_deq_valid", false,-1);
    tracep->declBit(c+499,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+499,"ram_real_last", false,-1);
    tracep->declBit(c+498,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+500,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+501,"io_enq_ready", false,-1);
    tracep->declBit(c+41,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+233,"io_deq_ready", false,-1);
    tracep->declBit(c+502,"io_deq_valid", false,-1);
    tracep->declBit(c+503,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+503,"ram_real_last", false,-1);
    tracep->declBit(c+502,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+504,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+505,"io_enq_ready", false,-1);
    tracep->declBit(c+42,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+234,"io_deq_ready", false,-1);
    tracep->declBit(c+506,"io_deq_valid", false,-1);
    tracep->declBit(c+507,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+507,"ram_real_last", false,-1);
    tracep->declBit(c+506,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+508,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+509,"io_enq_ready", false,-1);
    tracep->declBit(c+43,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+235,"io_deq_ready", false,-1);
    tracep->declBit(c+510,"io_deq_valid", false,-1);
    tracep->declBit(c+511,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+511,"ram_real_last", false,-1);
    tracep->declBit(c+510,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+512,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+513,"io_enq_ready", false,-1);
    tracep->declBit(c+44,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+236,"io_deq_ready", false,-1);
    tracep->declBit(c+514,"io_deq_valid", false,-1);
    tracep->declBit(c+515,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+515,"ram_real_last", false,-1);
    tracep->declBit(c+514,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+516,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+517,"io_enq_ready", false,-1);
    tracep->declBit(c+45,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+237,"io_deq_ready", false,-1);
    tracep->declBit(c+518,"io_deq_valid", false,-1);
    tracep->declBit(c+519,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+519,"ram_real_last", false,-1);
    tracep->declBit(c+518,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+520,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+521,"io_enq_ready", false,-1);
    tracep->declBit(c+46,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+238,"io_deq_ready", false,-1);
    tracep->declBit(c+522,"io_deq_valid", false,-1);
    tracep->declBit(c+523,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+523,"ram_real_last", false,-1);
    tracep->declBit(c+522,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+524,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+525,"io_enq_ready", false,-1);
    tracep->declBit(c+47,"io_enq_valid", false,-1);
    tracep->declBit(c+311,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+239,"io_deq_ready", false,-1);
    tracep->declBit(c+526,"io_deq_valid", false,-1);
    tracep->declBit(c+527,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+527,"ram_real_last", false,-1);
    tracep->declBit(c+526,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+528,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+529,"io_enq_ready", false,-1);
    tracep->declBit(c+48,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+240,"io_deq_ready", false,-1);
    tracep->declBit(c+530,"io_deq_valid", false,-1);
    tracep->declBit(c+531,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+531,"ram_real_last", false,-1);
    tracep->declBit(c+530,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+532,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+533,"io_enq_ready", false,-1);
    tracep->declBit(c+49,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+241,"io_deq_ready", false,-1);
    tracep->declBit(c+534,"io_deq_valid", false,-1);
    tracep->declBit(c+535,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+535,"ram_real_last", false,-1);
    tracep->declBit(c+534,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+536,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+537,"io_enq_ready", false,-1);
    tracep->declBit(c+50,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+242,"io_deq_ready", false,-1);
    tracep->declBit(c+538,"io_deq_valid", false,-1);
    tracep->declBit(c+539,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+539,"ram_real_last", false,-1);
    tracep->declBit(c+538,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+540,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+541,"io_enq_ready", false,-1);
    tracep->declBit(c+51,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+243,"io_deq_ready", false,-1);
    tracep->declBit(c+542,"io_deq_valid", false,-1);
    tracep->declBit(c+543,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+543,"ram_real_last", false,-1);
    tracep->declBit(c+542,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+544,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+545,"io_enq_ready", false,-1);
    tracep->declBit(c+52,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+244,"io_deq_ready", false,-1);
    tracep->declBit(c+546,"io_deq_valid", false,-1);
    tracep->declBit(c+547,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+547,"ram_real_last", false,-1);
    tracep->declBit(c+546,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+548,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+549,"io_enq_ready", false,-1);
    tracep->declBit(c+53,"io_enq_valid", false,-1);
    tracep->declBit(c+312,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+245,"io_deq_ready", false,-1);
    tracep->declBit(c+550,"io_deq_valid", false,-1);
    tracep->declBit(c+551,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+551,"ram_real_last", false,-1);
    tracep->declBit(c+550,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+552,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+74,"reset", false,-1);
    tracep->declBit(c+308,"auto_master_out_awready", false,-1);
    tracep->declBit(c+56,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1130,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1013,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1131,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1132,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1133,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+309,"auto_master_out_wready", false,-1);
    tracep->declBit(c+57,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1014,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+935,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1134,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1098,"auto_master_out_bready", false,-1);
    tracep->declBit(c+165,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+166,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+167,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+310,"auto_master_out_arready", false,-1);
    tracep->declBit(c+58,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1135,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1015,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1137,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1138,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+59,"auto_master_out_rready", false,-1);
    tracep->declBit(c+168,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+169,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+19,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1099,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+20,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+74,"reset", false,-1);
    tracep->declBit(c+1120,"io_interrupt", false,-1);
    tracep->declBit(c+308,"io_master_awready", false,-1);
    tracep->declBit(c+56,"io_master_awvalid", false,-1);
    tracep->declBus(c+1013,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1130,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1131,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1132,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1133,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+309,"io_master_wready", false,-1);
    tracep->declBit(c+57,"io_master_wvalid", false,-1);
    tracep->declBus(c+1014,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+935,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1134,"io_master_wlast", false,-1);
    tracep->declBit(c+1098,"io_master_bready", false,-1);
    tracep->declBit(c+165,"io_master_bvalid", false,-1);
    tracep->declBus(c+167,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+166,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+310,"io_master_arready", false,-1);
    tracep->declBit(c+58,"io_master_arvalid", false,-1);
    tracep->declBus(c+1015,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1135,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1136,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+1137,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1138,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+59,"io_master_rready", false,-1);
    tracep->declBit(c+168,"io_master_rvalid", false,-1);
    tracep->declBus(c+1099,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+19,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+20,"io_master_rlast", false,-1);
    tracep->declBus(c+169,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1140,"io_slave_awready", false,-1);
    tracep->declBit(c+1120,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1141,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1142,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1136,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1143,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1144,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1145,"io_slave_wready", false,-1);
    tracep->declBit(c+1120,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1141,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1142,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1120,"io_slave_wlast", false,-1);
    tracep->declBit(c+1120,"io_slave_bready", false,-1);
    tracep->declBit(c+1146,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1147,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1148,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1149,"io_slave_arready", false,-1);
    tracep->declBit(c+1120,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1141,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1142,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1136,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1143,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1144,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1120,"io_slave_rready", false,-1);
    tracep->declBit(c+1150,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1151,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1152,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1153,"io_slave_rlast", false,-1);
    tracep->declBus(c+1154,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+936,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1034,"npc", false,-1, 31,0);
    tracep->declBus(c+851,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+937,"inst", false,-1, 31,0);
    tracep->declBit(c+246,"ifu_valid", false,-1);
    tracep->declBit(c+938,"ifu_arvalid", false,-1);
    tracep->declBit(c+553,"ifu_arready", false,-1);
    tracep->declBus(c+1034,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+247,"ifu_rvalid", false,-1);
    tracep->declBit(c+936,"ifu_rready", false,-1);
    tracep->declBus(c+248,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+939,"reg_process", false,-1);
    tracep->declBus(c+940,"src1", false,-1, 4,0);
    tracep->declBus(c+941,"src2", false,-1, 4,0);
    tracep->declBus(c+942,"rd", false,-1, 4,0);
    tracep->declBus(c+943,"imm", false,-1, 31,0);
    tracep->declBit(c+944,"ebreaksig", false,-1);
    tracep->declBit(c+945,"mretsig", false,-1);
    tracep->declBit(c+946,"ecallsig", false,-1);
    tracep->declBit(c+947,"regew", false,-1);
    tracep->declBit(c+948,"memew", false,-1);
    tracep->declBit(c+949,"memer", false,-1);
    tracep->declBit(c+950,"muximm", false,-1);
    tracep->declBus(c+951,"func3", false,-1, 2,0);
    tracep->declBus(c+952,"muxsig", false,-1, 2,0);
    tracep->declBit(c+953,"func7", false,-1);
    tracep->declBit(c+954,"btypebranch", false,-1);
    tracep->declBit(c+955,"jalsig", false,-1);
    tracep->declBit(c+956,"jalrsig", false,-1);
    tracep->declBit(c+957,"auipcsig", false,-1);
    tracep->declBus(c+958,"aluop", false,-1, 1,0);
    tracep->declBit(c+959,"csrrw", false,-1);
    tracep->declBit(c+960,"csrrs", false,-1);
    tracep->declBit(c+246,"idu_valid", false,-1);
    tracep->declBus(c+961,"memmask", false,-1, 2,0);
    tracep->declBit(c+962,"memsextsig", false,-1);
    tracep->declBus(c+249,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1035,"regout1", false,-1, 31,0);
    tracep->declBus(c+1036,"regout2", false,-1, 31,0);
    tracep->declBus(c+852,"mepc", false,-1, 31,0);
    tracep->declBus(c+853,"mtvec", false,-1, 31,0);
    tracep->declBit(c+936,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1037,"res", false,-1, 31,0);
    tracep->declBus(c+1038,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+246,"exu_valid", false,-1);
    tracep->declBit(c+936,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1107,"memvalid", false,-1);
    tracep->declBus(c+963,"awvalid", false,-1, 1,0);
    tracep->declBus(c+963,"wvalid", false,-1, 1,0);
    tracep->declBus(c+964,"arvalid", false,-1, 1,0);
    tracep->declBus(c+965,"rready", false,-1, 1,0);
    tracep->declBus(c+966,"bready", false,-1, 1,0);
    tracep->declBus(c+54,"bvalid", false,-1, 1,0);
    tracep->declBus(c+250,"rvalid", false,-1, 1,0);
    tracep->declBus(c+554,"awready", false,-1, 1,0);
    tracep->declBus(c+554,"wready", false,-1, 1,0);
    tracep->declBus(c+555,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1039+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+251+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1041+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1043+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+967+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+253+i*1,"bresp", true,(i+0), 1,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1155,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+74,"reset", false,-1);
    tracep->declBus(c+963,"awvalid", false,-1, 1,0);
    tracep->declBus(c+963,"wvalid", false,-1, 1,0);
    tracep->declBus(c+964,"arvalid", false,-1, 1,0);
    tracep->declBus(c+965,"rready", false,-1, 1,0);
    tracep->declBus(c+966,"bready", false,-1, 1,0);
    tracep->declBus(c+54,"bvalid", false,-1, 1,0);
    tracep->declBus(c+250,"rvalid", false,-1, 1,0);
    tracep->declBus(c+554,"awready", false,-1, 1,0);
    tracep->declBus(c+554,"wready", false,-1, 1,0);
    tracep->declBus(c+555,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1045+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1047+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1049+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+969+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+255+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+257+i*1,"bresp", true,(i+0), 1,0);
    }
    tracep->declBit(c+56,"awvalid_out", false,-1);
    tracep->declBit(c+57,"wvalid_out", false,-1);
    tracep->declBit(c+58,"arvalid_out", false,-1);
    tracep->declBit(c+59,"rready_out", false,-1);
    tracep->declBit(c+1098,"bready_out", false,-1);
    tracep->declBit(c+165,"bvalid_in", false,-1);
    tracep->declBit(c+168,"rvalid_in", false,-1);
    tracep->declBit(c+309,"awready_in", false,-1);
    tracep->declBit(c+309,"wready_in", false,-1);
    tracep->declBit(c+310,"arready_in", false,-1);
    tracep->declBus(c+1015,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1013,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1014,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+935,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+19,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+167,"bresp_in", false,-1, 1,0);
    tracep->declBit(c+556,"busy", false,-1);
    tracep->declBus(c+557,"giant", false,-1, 1,0);
    tracep->declBus(c+558,"i", false,-1, 31,0);
    tracep->declBus(c+1013,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1014,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1015,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+935,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1156,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+951,"func3", false,-1, 2,0);
    tracep->declBit(c+954,"btypebranch", false,-1);
    tracep->declBit(c+953,"func7", false,-1);
    tracep->declBus(c+958,"aluop", false,-1, 1,0);
    tracep->declBit(c+956,"jalrsig", false,-1);
    tracep->declBit(c+955,"jalsig", false,-1);
    tracep->declBus(c+943,"imm", false,-1, 31,0);
    tracep->declBit(c+950,"muximm", false,-1);
    tracep->declBus(c+1035,"regout1", false,-1, 31,0);
    tracep->declBus(c+1036,"regout2", false,-1, 31,0);
    tracep->declBus(c+851,"pc", false,-1, 31,0);
    tracep->declBit(c+957,"auipcsig", false,-1);
    tracep->declBit(c+945,"mretsig", false,-1);
    tracep->declBit(c+946,"ecallsig", false,-1);
    tracep->declBus(c+853,"mtvec", false,-1, 31,0);
    tracep->declBus(c+852,"mepc", false,-1, 31,0);
    tracep->declBit(c+246,"valid_from", false,-1);
    tracep->declBit(c+936,"ready_from", false,-1);
    tracep->declBus(c+1037,"res", false,-1, 31,0);
    tracep->declBus(c+1034,"npc", false,-1, 31,0);
    tracep->declBus(c+1038,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+246,"valid_to", false,-1);
    tracep->declBit(c+936,"ready_to", false,-1);
    tracep->declBus(c+854,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1051,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+971,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1052,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1053,"zero", false,-1);
    tracep->declBit(c+1054,"signal", false,-1);
    tracep->declBit(c+1055,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1035,"A", false,-1, 31,0);
    tracep->declBus(c+1052,"B", false,-1, 31,0);
    tracep->declBus(c+971,"op", false,-1, 4,0);
    tracep->declBus(c+1037,"res", false,-1, 31,0);
    tracep->declBit(c+1053,"zero", false,-1);
    tracep->declBit(c+1054,"signal", false,-1);
    tracep->declBit(c+1055,"carry", false,-1);
    tracep->declBit(c+972,"addsig", false,-1);
    tracep->declBit(c+973,"logsig", false,-1);
    tracep->declBit(c+974,"shfsig", false,-1);
    tracep->declBit(c+975,"sltsig", false,-1);
    tracep->declBit(c+1055,"carry_tmp", false,-1);
    tracep->declBit(c+976,"type_I", false,-1);
    tracep->declBus(c+1056,"logres", false,-1, 31,0);
    tracep->declBus(c+1057,"addres", false,-1, 31,0);
    tracep->declBit(c+1058,"addzero", false,-1);
    tracep->declBus(c+1059,"shfres", false,-1, 31,0);
    tracep->declBus(c+1060,"sltres", false,-1, 31,0);
    tracep->declBus(c+1035,"A_s", false,-1, 31,0);
    tracep->declBus(c+1052,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+951,"func3", false,-1, 2,0);
    tracep->declBit(c+953,"func7", false,-1);
    tracep->declBus(c+958,"aluop", false,-1, 1,0);
    tracep->declBit(c+956,"jalrsig", false,-1);
    tracep->declBus(c+971,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+976,"type_I", false,-1);
    tracep->declBit(c+977,"type_B", false,-1);
    tracep->declBit(c+978,"type_R", false,-1);
    tracep->declBit(c+979,"addsig", false,-1);
    tracep->declBus(c+980,"branchop", false,-1, 3,0);
    tracep->declBus(c+981,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+954,"btypebranch", false,-1);
    tracep->declBus(c+951,"func3", false,-1, 2,0);
    tracep->declBit(c+1053,"zero", false,-1);
    tracep->declBit(c+1054,"signal", false,-1);
    tracep->declBit(c+1055,"carry", false,-1);
    tracep->declBus(c+1037,"res", false,-1, 31,0);
    tracep->declBus(c+854,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1051,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+955,"jalsig", false,-1);
    tracep->declBit(c+956,"jalrsig", false,-1);
    tracep->declBit(c+957,"auipcsig", false,-1);
    tracep->declBit(c+945,"mretsig", false,-1);
    tracep->declBit(c+946,"ecallsig", false,-1);
    tracep->declBus(c+853,"mtvec", false,-1, 31,0);
    tracep->declBus(c+852,"mepc", false,-1, 31,0);
    tracep->declBus(c+1034,"npc", false,-1, 31,0);
    tracep->declBus(c+1038,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1155,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1157,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1052,"out", false,-1, 31,0);
    tracep->declBus(c+950,"key", false,-1, 0,0);
    tracep->declArray(c+1001,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1155,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1157,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1159,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1052,"out", false,-1, 31,0);
    tracep->declBus(c+950,"key", false,-1, 0,0);
    tracep->declBus(c+1141,"default_out", false,-1, 31,0);
    tracep->declArray(c+1001,"lut", false,-1, 65,0);
    tracep->declBus(c+1160,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1004+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1008+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1061,"lut_out", false,-1, 31,0);
    tracep->declBit(c+982,"hit", false,-1);
    tracep->declBus(c+1161,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+851,"pc", false,-1, 31,0);
    tracep->declBus(c+854,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+851,"pc", false,-1, 31,0);
    tracep->declBus(c+943,"imm", false,-1, 31,0);
    tracep->declBus(c+1051,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+937,"inst", false,-1, 31,0);
    tracep->declBit(c+246,"valid_from", false,-1);
    tracep->declBit(c+936,"ready_from", false,-1);
    tracep->declBit(c+944,"ebreaksig", false,-1);
    tracep->declBit(c+946,"ecallsig", false,-1);
    tracep->declBit(c+945,"mretsig", false,-1);
    tracep->declBus(c+943,"imm", false,-1, 31,0);
    tracep->declBus(c+951,"func3", false,-1, 2,0);
    tracep->declBit(c+953,"func7", false,-1);
    tracep->declBus(c+940,"src1", false,-1, 4,0);
    tracep->declBus(c+941,"src2", false,-1, 4,0);
    tracep->declBus(c+942,"rd", false,-1, 4,0);
    tracep->declBit(c+948,"memew", false,-1);
    tracep->declBus(c+952,"muxsig", false,-1, 2,0);
    tracep->declBit(c+949,"memer", false,-1);
    tracep->declBit(c+947,"regew", false,-1);
    tracep->declBit(c+950,"muximm", false,-1);
    tracep->declBit(c+954,"btypebranch", false,-1);
    tracep->declBit(c+956,"jalrsig", false,-1);
    tracep->declBit(c+955,"jalsig", false,-1);
    tracep->declBus(c+958,"aluop", false,-1, 1,0);
    tracep->declBit(c+957,"auipcsig", false,-1);
    tracep->declBit(c+959,"csrrw", false,-1);
    tracep->declBit(c+960,"csrrs", false,-1);
    tracep->declBit(c+246,"valid_to", false,-1);
    tracep->declBit(c+936,"ready_to", false,-1);
    tracep->declBus(c+961,"memmask", false,-1, 2,0);
    tracep->declBit(c+962,"memsextsig", false,-1);
    tracep->declBit(c+944,"ebreak", false,-1);
    tracep->declBit(c+946,"ecall", false,-1);
    tracep->declBit(c+945,"mret", false,-1);
    tracep->declBus(c+951,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+953,"func7bridge", false,-1);
    tracep->declBus(c+983,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+937,"inst", false,-1, 31,0);
    tracep->declBit(c+944,"ebreaksig", false,-1);
    tracep->declBit(c+946,"ecallsig", false,-1);
    tracep->declBit(c+945,"mretsig", false,-1);
    tracep->declBus(c+943,"imm", false,-1, 31,0);
    tracep->declBus(c+983,"opcode", false,-1, 6,0);
    tracep->declBus(c+951,"func3", false,-1, 2,0);
    tracep->declBit(c+953,"func7", false,-1);
    tracep->declBus(c+940,"src1", false,-1, 4,0);
    tracep->declBus(c+941,"src2", false,-1, 4,0);
    tracep->declBus(c+942,"rd", false,-1, 4,0);
    tracep->declBus(c+961,"memmask", false,-1, 2,0);
    tracep->declBit(c+962,"memsextsig", false,-1);
    tracep->declBit(c+984,"type_I", false,-1);
    tracep->declBit(c+985,"type_R", false,-1);
    tracep->declBit(c+986,"type_U", false,-1);
    tracep->declBit(c+948,"type_S", false,-1);
    tracep->declBit(c+955,"type_J", false,-1);
    tracep->declBit(c+954,"type_B", false,-1);
    tracep->declBus(c+987,"I_imm", false,-1, 31,0);
    tracep->declBus(c+988,"U_imm", false,-1, 31,0);
    tracep->declBus(c+989,"S_imm", false,-1, 31,0);
    tracep->declBus(c+990,"J_imm", false,-1, 31,0);
    tracep->declBus(c+991,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+983,"opcode", false,-1, 6,0);
    tracep->declBus(c+951,"func3", false,-1, 2,0);
    tracep->declBit(c+953,"func7", false,-1);
    tracep->declBit(c+944,"ebreaksig", false,-1);
    tracep->declBit(c+946,"ecallsig", false,-1);
    tracep->declBit(c+945,"mretsig", false,-1);
    tracep->declBit(c+948,"memew", false,-1);
    tracep->declBus(c+952,"muxsig", false,-1, 2,0);
    tracep->declBit(c+949,"memer", false,-1);
    tracep->declBit(c+947,"regew", false,-1);
    tracep->declBit(c+950,"muximm", false,-1);
    tracep->declBit(c+954,"btypebranch", false,-1);
    tracep->declBit(c+956,"jalrsig", false,-1);
    tracep->declBit(c+955,"jalsig", false,-1);
    tracep->declBus(c+958,"aluop", false,-1, 1,0);
    tracep->declBit(c+957,"auipcsig", false,-1);
    tracep->declBit(c+959,"csrrw", false,-1);
    tracep->declBit(c+960,"csrrs", false,-1);
    tracep->declBit(c+984,"type_I", false,-1);
    tracep->declBit(c+985,"type_R", false,-1);
    tracep->declBit(c+986,"type_U", false,-1);
    tracep->declBit(c+948,"type_S", false,-1);
    tracep->declBit(c+955,"type_J", false,-1);
    tracep->declBit(c+954,"type_B", false,-1);
    tracep->declBit(c+949,"load", false,-1);
    tracep->declBit(c+948,"store", false,-1);
    tracep->declBit(c+992,"regwritepc", false,-1);
    tracep->declBit(c+949,"regwritemem", false,-1);
    tracep->declBit(c+993,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+74,"rst", false,-1);
    tracep->declBus(c+1034,"npc", false,-1, 31,0);
    tracep->declBit(c+936,"ready", false,-1);
    tracep->declBus(c+851,"pc", false,-1, 31,0);
    tracep->declBus(c+937,"inst", false,-1, 31,0);
    tracep->declBit(c+246,"valid", false,-1);
    tracep->declBit(c+939,"regprocess", false,-1);
    tracep->declBit(c+938,"arvalid", false,-1);
    tracep->declBit(c+553,"arready", false,-1);
    tracep->declBus(c+1034,"araddr", false,-1, 31,0);
    tracep->declBit(c+247,"rvalid", false,-1);
    tracep->declBit(c+936,"rready", false,-1);
    tracep->declBus(c+248,"rdata", false,-1, 31,0);
    tracep->declBus(c+851,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+247,"infetch_ready", false,-1);
    tracep->declBus(c+994,"state", false,-1, 1,0);
    tracep->declBus(c+937,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBus(c+1034,"npc", false,-1, 31,0);
    tracep->declBit(c+74,"rst", false,-1);
    tracep->declBit(c+247,"ready_from", false,-1);
    tracep->declBus(c+851,"pcout", false,-1, 31,0);
    tracep->declBus(c+1162,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+74,"rst", false,-1);
    tracep->declBit(c+1108,"ew", false,-1);
    tracep->declBus(c+942,"addr", false,-1, 4,0);
    tracep->declBus(c+940,"src1", false,-1, 4,0);
    tracep->declBus(c+941,"src2", false,-1, 4,0);
    tracep->declBus(c+995,"csr", false,-1, 11,0);
    tracep->declBus(c+249,"data", false,-1, 31,0);
    tracep->declBit(c+959,"csrrw", false,-1);
    tracep->declBit(c+960,"csrrs", false,-1);
    tracep->declBit(c+946,"ecallsig", false,-1);
    tracep->declBit(c+246,"valid", false,-1);
    tracep->declBus(c+1035,"regout1", false,-1, 31,0);
    tracep->declBus(c+1036,"regout2", false,-1, 31,0);
    tracep->declBus(c+852,"mepc", false,-1, 31,0);
    tracep->declBus(c+853,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+855+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+887+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+996,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+259,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1164,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1155,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+996,"out", false,-1, 1,0);
    tracep->declBus(c+995,"key", false,-1, 11,0);
    tracep->declQuad(c+1165,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1164,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1155,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1159,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+996,"out", false,-1, 1,0);
    tracep->declBus(c+995,"key", false,-1, 11,0);
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
    tracep->declBus(c+997,"lut_out", false,-1, 1,0);
    tracep->declBit(c+998,"hit", false,-1);
    tracep->declBus(c+1168,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+74,"rst", false,-1);
    tracep->declBit(c+1109,"ew", false,-1);
    tracep->declBit(c+959,"csrrw", false,-1);
    tracep->declBit(c+960,"csrrs", false,-1);
    tracep->declBit(c+946,"ecall", false,-1);
    tracep->declBus(c+996,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+942,"addr", false,-1, 4,0);
    tracep->declBus(c+259,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+891+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+923+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+927,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBus(c+1037,"res", false,-1, 31,0);
    tracep->declBus(c+1036,"regout2", false,-1, 31,0);
    tracep->declBit(c+948,"memew", false,-1);
    tracep->declBit(c+949,"memer", false,-1);
    tracep->declBus(c+943,"imm", false,-1, 31,0);
    tracep->declBus(c+1038,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+952,"muxsig", false,-1, 2,0);
    tracep->declBit(c+246,"valid_from", false,-1);
    tracep->declBus(c+961,"memmask", false,-1, 2,0);
    tracep->declBit(c+962,"memsextsig", false,-1);
    tracep->declBus(c+249,"regwrite", false,-1, 31,0);
    tracep->declBit(c+936,"ready_to", false,-1);
    tracep->declBit(c+1107,"memvalid", false,-1);
    tracep->declBit(c+999,"awvalid", false,-1);
    tracep->declBit(c+559,"awready", false,-1);
    tracep->declBus(c+1037,"awaddr", false,-1, 31,0);
    tracep->declBit(c+999,"wvalid", false,-1);
    tracep->declBit(c+559,"wready", false,-1);
    tracep->declBus(c+1036,"wdata", false,-1, 31,0);
    tracep->declBus(c+1000,"wstrb", false,-1, 3,0);
    tracep->declBit(c+55,"bvalid", false,-1);
    tracep->declBit(c+948,"bready", false,-1);
    tracep->declBus(c+260,"bresp", false,-1, 1,0);
    tracep->declBit(c+1110,"arvalid", false,-1);
    tracep->declBit(c+560,"arready", false,-1);
    tracep->declBus(c+1037,"araddr", false,-1, 31,0);
    tracep->declBit(c+261,"rvalid", false,-1);
    tracep->declBit(c+949,"rready", false,-1);
    tracep->declBus(c+262,"rdata", false,-1, 31,0);
    tracep->declBus(c+263,"memread", false,-1, 31,0);
    tracep->declBit(c+561,"bresp_get", false,-1);
    tracep->declBit(c+562,"rvalid_get", false,-1);
    tracep->declBit(c+563,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+262,"data", false,-1, 31,0);
    tracep->declBus(c+961,"memmask", false,-1, 2,0);
    tracep->declBit(c+962,"memsextsig", false,-1);
    tracep->declBus(c+263,"read", false,-1, 31,0);
    tracep->declBus(c+264,"read_u", false,-1, 31,0);
    tracep->declBus(c+265,"read_s", false,-1, 31,0);
    tracep->declBus(c+266,"read_sb", false,-1, 31,0);
    tracep->declBus(c+267,"read_sh", false,-1, 31,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1169,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1158,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+268,"input_number", false,-1, 7,0);
    tracep->declBus(c+266,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1170,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1158,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+269,"input_number", false,-1, 15,0);
    tracep->declBus(c+267,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1171,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+249,"out", false,-1, 31,0);
    tracep->declBus(c+952,"key", false,-1, 2,0);
    tracep->declBus(c+1159,"default_out", false,-1, 31,0);
    tracep->declArray(c+75,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1163,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1171,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1158,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1157,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+249,"out", false,-1, 31,0);
    tracep->declBus(c+952,"key", false,-1, 2,0);
    tracep->declBus(c+1159,"default_out", false,-1, 31,0);
    tracep->declArray(c+75,"lut", false,-1, 139,0);
    tracep->declBus(c+1172,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+80+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+88+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+270,"lut_out", false,-1, 31,0);
    tracep->declBit(c+271,"hit", false,-1);
    tracep->declBus(c+1168,"i", false,-1, 31,0);
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"io_d", false,-1);
    tracep->declBit(c+564,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"io_d", false,-1);
    tracep->declBit(c+564,"io_q", false,-1);
    tracep->declBit(c+564,"sync_0", false,-1);
    tracep->declBit(c+565,"sync_1", false,-1);
    tracep->declBit(c+566,"sync_2", false,-1);
    tracep->declBit(c+567,"sync_3", false,-1);
    tracep->declBit(c+568,"sync_4", false,-1);
    tracep->declBit(c+569,"sync_5", false,-1);
    tracep->declBit(c+570,"sync_6", false,-1);
    tracep->declBit(c+571,"sync_7", false,-1);
    tracep->declBit(c+572,"sync_8", false,-1);
    tracep->declBit(c+573,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+103,"auto_in_psel", false,-1);
    tracep->declBit(c+1093,"auto_in_penable", false,-1);
    tracep->declBit(c+94,"auto_in_pwrite", false,-1);
    tracep->declBus(c+102,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1119,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1127,"auto_in_pready", false,-1);
    tracep->declBit(c+1128,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1129,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1065,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1066,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1067,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1068,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1069,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1070,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1071,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1072,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1073,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1074,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+124,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+103,"in_psel", false,-1);
    tracep->declBit(c+1093,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1127,"in_pready", false,-1);
    tracep->declBus(c+1129,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1128,"in_pslverr", false,-1);
    tracep->declBus(c+1065,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1066,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1067,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1068,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1069,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1070,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1071,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1072,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1073,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1074,"gpio_seg_7", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+101,"auto_in_psel", false,-1);
    tracep->declBit(c+1092,"auto_in_penable", false,-1);
    tracep->declBit(c+94,"auto_in_pwrite", false,-1);
    tracep->declBus(c+102,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1119,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1124,"auto_in_pready", false,-1);
    tracep->declBit(c+1125,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1126,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1075,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1076,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+124,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+101,"in_psel", false,-1);
    tracep->declBit(c+1092,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1124,"in_pready", false,-1);
    tracep->declBus(c+1126,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1125,"in_pslverr", false,-1);
    tracep->declBit(c+1075,"ps2_clk", false,-1);
    tracep->declBit(c+1076,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+1103,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1104,"auto_in_wvalid", false,-1);
    tracep->declBit(c+369,"auto_in_arready", false,-1);
    tracep->declBit(c+1105,"auto_in_arvalid", false,-1);
    tracep->declBus(c+297,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1025,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1106,"auto_in_rready", false,-1);
    tracep->declBit(c+370,"auto_in_rvalid", false,-1);
    tracep->declBus(c+371,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+372,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+370,"state", false,-1);
    tracep->declBus(c+372,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+371,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1062,"raddr", false,-1, 31,0);
    tracep->declBit(c+125,"ren", false,-1);
    tracep->declBus(c+126,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+104,"auto_in_psel", false,-1);
    tracep->declBit(c+1094,"auto_in_penable", false,-1);
    tracep->declBit(c+94,"auto_in_pwrite", false,-1);
    tracep->declBus(c+92,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1119,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1095,"auto_in_pready", false,-1);
    tracep->declBit(c+1120,"auto_in_pslverr", false,-1);
    tracep->declBus(c+293,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1087,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+1088,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+157,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+92,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+104,"in_psel", false,-1);
    tracep->declBit(c+1094,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1095,"in_pready", false,-1);
    tracep->declBus(c+293,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1120,"in_pslverr", false,-1);
    tracep->declBit(c+1087,"qspi_sck", false,-1);
    tracep->declBit(c+1088,"qspi_ce_n", false,-1);
    tracep->declBus(c+157,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+157,"din", false,-1, 3,0);
    tracep->declBus(c+272,"dout", false,-1, 3,0);
    tracep->declBus(c+273,"douten", false,-1, 3,0);
    tracep->declBit(c+1111,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1063,"clk_i", false,-1);
    tracep->declBit(c+1064,"rst_i", false,-1);
    tracep->declBus(c+92,"adr_i", false,-1, 31,0);
    tracep->declBus(c+95,"dat_i", false,-1, 31,0);
    tracep->declBus(c+293,"dat_o", false,-1, 31,0);
    tracep->declBus(c+96,"sel_i", false,-1, 3,0);
    tracep->declBit(c+104,"cyc_i", false,-1);
    tracep->declBit(c+104,"stb_i", false,-1);
    tracep->declBit(c+1111,"ack_o", false,-1);
    tracep->declBit(c+94,"we_i", false,-1);
    tracep->declBit(c+1087,"sck", false,-1);
    tracep->declBit(c+1088,"ce_n", false,-1);
    tracep->declBus(c+157,"din", false,-1, 3,0);
    tracep->declBus(c+272,"dout", false,-1, 3,0);
    tracep->declBus(c+273,"douten", false,-1, 3,0);
    tracep->declBus(c+1173,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1174,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+627,"mr_sck", false,-1);
    tracep->declBit(c+628,"mr_ce_n", false,-1);
    tracep->declBus(c+157,"mr_din", false,-1, 3,0);
    tracep->declBus(c+629,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+630,"mr_doe", false,-1);
    tracep->declBit(c+631,"mw_sck", false,-1);
    tracep->declBit(c+632,"mw_ce_n", false,-1);
    tracep->declBus(c+157,"mw_din", false,-1, 3,0);
    tracep->declBus(c+274,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+633,"mw_doe", false,-1);
    tracep->declBit(c+275,"mr_rd", false,-1);
    tracep->declBit(c+634,"mr_done", false,-1);
    tracep->declBit(c+276,"mw_wr", false,-1);
    tracep->declBit(c+277,"mw_done", false,-1);
    tracep->declBit(c+104,"wb_valid", false,-1);
    tracep->declBit(c+127,"wb_we", false,-1);
    tracep->declBit(c+128,"wb_re", false,-1);
    tracep->declBit(c+635,"state", false,-1);
    tracep->declBit(c+278,"nstate", false,-1);
    tracep->declBus(c+129,"size", false,-1, 2,0);
    tracep->declBus(c+130,"byte0", false,-1, 7,0);
    tracep->declBus(c+131,"byte1", false,-1, 7,0);
    tracep->declBus(c+132,"byte2", false,-1, 7,0);
    tracep->declBus(c+133,"byte3", false,-1, 7,0);
    tracep->declBus(c+134,"wdata", false,-1, 31,0);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1112,"rst_n", false,-1);
    tracep->declBus(c+135,"addr", false,-1, 23,0);
    tracep->declBit(c+275,"rd", false,-1);
    tracep->declBus(c+1137,"size", false,-1, 2,0);
    tracep->declBit(c+634,"done", false,-1);
    tracep->declBus(c+293,"line", false,-1, 31,0);
    tracep->declBit(c+627,"sck", false,-1);
    tracep->declBit(c+628,"ce_n", false,-1);
    tracep->declBus(c+157,"din", false,-1, 3,0);
    tracep->declBus(c+629,"dout", false,-1, 3,0);
    tracep->declBit(c+630,"douten", false,-1);
    tracep->declBus(c+1173,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1174,"READ", false,-1, 0,0);
    tracep->declBus(c+1175,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+636,"state", false,-1);
    tracep->declBit(c+279,"nstate", false,-1);
    tracep->declBus(c+637,"counter", false,-1, 7,0);
    tracep->declBus(c+638,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+574+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1176,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+639,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1112,"rst_n", false,-1);
    tracep->declBus(c+136,"addr", false,-1, 23,0);
    tracep->declBus(c+134,"line", false,-1, 31,0);
    tracep->declBus(c+129,"size", false,-1, 2,0);
    tracep->declBit(c+276,"wr", false,-1);
    tracep->declBit(c+277,"done", false,-1);
    tracep->declBit(c+631,"sck", false,-1);
    tracep->declBit(c+632,"ce_n", false,-1);
    tracep->declBus(c+157,"din", false,-1, 3,0);
    tracep->declBus(c+274,"dout", false,-1, 3,0);
    tracep->declBit(c+633,"douten", false,-1);
    tracep->declBus(c+1173,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1174,"WRITE", false,-1, 0,0);
    tracep->declBus(c+137,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+640,"state", false,-1);
    tracep->declBit(c+280,"nstate", false,-1);
    tracep->declBus(c+641,"counter", false,-1, 7,0);
    tracep->declBus(c+642,"saddr", false,-1, 23,0);
    tracep->declBus(c+1177,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+98,"auto_in_psel", false,-1);
    tracep->declBit(c+1090,"auto_in_penable", false,-1);
    tracep->declBit(c+94,"auto_in_pwrite", false,-1);
    tracep->declBus(c+92,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1119,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+623,"auto_in_pready", false,-1);
    tracep->declBit(c+1120,"auto_in_pslverr", false,-1);
    tracep->declBus(c+624,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1089,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+614,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+615,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+616,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+617,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+618,"sdram_bundle_we", false,-1);
    tracep->declBus(c+619,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+620,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+621,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+622,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+92,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+98,"in_psel", false,-1);
    tracep->declBit(c+1090,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+623,"in_pready", false,-1);
    tracep->declBus(c+624,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1120,"in_pslverr", false,-1);
    tracep->declBit(c+1089,"sdram_clk", false,-1);
    tracep->declBit(c+614,"sdram_cke", false,-1);
    tracep->declBit(c+615,"sdram_cs", false,-1);
    tracep->declBit(c+616,"sdram_ras", false,-1);
    tracep->declBit(c+617,"sdram_cas", false,-1);
    tracep->declBit(c+618,"sdram_we", false,-1);
    tracep->declBus(c+619,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+620,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+621,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+622,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+643,"sdram_dout_en", false,-1);
    tracep->declBus(c+644,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+578,"state", false,-1, 1,0);
    tracep->declBit(c+645,"req_accept", false,-1);
    tracep->declBit(c+138,"is_read", false,-1);
    tracep->declBit(c+139,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1063,"clk_i", false,-1);
    tracep->declBit(c+1064,"rst_i", false,-1);
    tracep->declBus(c+140,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+138,"inport_rd_i", false,-1);
    tracep->declBus(c+1136,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+92,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+95,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+622,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+645,"inport_accept_o", false,-1);
    tracep->declBit(c+623,"inport_ack_o", false,-1);
    tracep->declBit(c+1120,"inport_error_o", false,-1);
    tracep->declBus(c+624,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1089,"sdram_clk_o", false,-1);
    tracep->declBit(c+614,"sdram_cke_o", false,-1);
    tracep->declBit(c+615,"sdram_cs_o", false,-1);
    tracep->declBit(c+616,"sdram_ras_o", false,-1);
    tracep->declBit(c+617,"sdram_cas_o", false,-1);
    tracep->declBit(c+618,"sdram_we_o", false,-1);
    tracep->declBus(c+621,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+619,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+620,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+644,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+643,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1178,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1179,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1180,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1163,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1181,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1182,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1183,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1184,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1163,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1185,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1186,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1187,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1188,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1189,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1190,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1135,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1142,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1191,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1163,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1142,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1135,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1190,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1186,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1188,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1187,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1189,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1185,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1192,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1193,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1194,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1194,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1170,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1194,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1155,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1195,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+92,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+140,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+138,"ram_rd_w", false,-1);
    tracep->declBit(c+645,"ram_accept_w", false,-1);
    tracep->declBus(c+95,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+624,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+623,"ram_ack_w", false,-1);
    tracep->declBit(c+141,"ram_req_w", false,-1);
    tracep->declBus(c+646,"command_q", false,-1, 3,0);
    tracep->declBus(c+619,"addr_q", false,-1, 12,0);
    tracep->declBus(c+644,"data_q", false,-1, 15,0);
    tracep->declBit(c+647,"data_rd_en_q", false,-1);
    tracep->declBus(c+621,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+614,"cke_q", false,-1);
    tracep->declBus(c+620,"bank_q", false,-1, 1,0);
    tracep->declBus(c+648,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+649,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+622,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+650,"refresh_q", false,-1);
    tracep->declBus(c+651,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+652+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+656,"state_q", false,-1, 3,0);
    tracep->declBus(c+281,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+282,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+657,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+658,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+142,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+143,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+144,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1163,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+659,"delay_q", false,-1, 3,0);
    tracep->declBus(c+283,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1196,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+660,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+661,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+662,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+663,"idx", false,-1, 31,0);
    tracep->declBus(c+664,"rd_q", false,-1, 3,0);
    tracep->declBit(c+623,"ack_q", false,-1);
    tracep->declArray(c+665,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+108,"auto_in_psel", false,-1);
    tracep->declBit(c+109,"auto_in_penable", false,-1);
    tracep->declBit(c+94,"auto_in_pwrite", false,-1);
    tracep->declBus(c+100,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1119,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+625,"auto_in_pready", false,-1);
    tracep->declBit(c+1120,"auto_in_pslverr", false,-1);
    tracep->declBus(c+626,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+612,"spi_bundle_sck", false,-1);
    tracep->declBus(c+613,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1085,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1086,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1197,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1198,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1169,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+145,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+108,"in_psel", false,-1);
    tracep->declBit(c+109,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+625,"in_pready", false,-1);
    tracep->declBus(c+626,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1120,"in_pslverr", false,-1);
    tracep->declBit(c+612,"spi_sck", false,-1);
    tracep->declBus(c+613,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1085,"spi_mosi", false,-1);
    tracep->declBit(c+1086,"spi_miso", false,-1);
    tracep->declBit(c+668,"spi_irq_out", false,-1);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBit(c+1063,"wb_clk_i", false,-1);
    tracep->declBit(c+1064,"wb_rst_i", false,-1);
    tracep->declBus(c+146,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+95,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+626,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+96,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+94,"wb_we_i", false,-1);
    tracep->declBit(c+108,"wb_stb_i", false,-1);
    tracep->declBit(c+109,"wb_cyc_i", false,-1);
    tracep->declBit(c+625,"wb_ack_o", false,-1);
    tracep->declBit(c+1120,"wb_err_o", false,-1);
    tracep->declBit(c+668,"wb_int_o", false,-1);
    tracep->declBus(c+613,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+612,"sclk_pad_o", false,-1);
    tracep->declBit(c+1085,"mosi_pad_o", false,-1);
    tracep->declBit(c+1086,"miso_pad_i", false,-1);
    tracep->declBus(c+669,"divider", false,-1, 15,0);
    tracep->declBus(c+670,"ctrl", false,-1, 13,0);
    tracep->declBus(c+671,"ss", false,-1, 7,0);
    tracep->declBus(c+284,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+672,"rx", false,-1, 127,0);
    tracep->declBit(c+676,"rx_negedge", false,-1);
    tracep->declBit(c+677,"tx_negedge", false,-1);
    tracep->declBus(c+678,"char_len", false,-1, 6,0);
    tracep->declBit(c+679,"go", false,-1);
    tracep->declBit(c+680,"lsb", false,-1);
    tracep->declBit(c+681,"ie", false,-1);
    tracep->declBit(c+682,"ass", false,-1);
    tracep->declBit(c+147,"spi_divider_sel", false,-1);
    tracep->declBit(c+148,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+149,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+150,"spi_ss_sel", false,-1);
    tracep->declBit(c+683,"tip", false,-1);
    tracep->declBit(c+684,"pos_edge", false,-1);
    tracep->declBit(c+685,"neg_edge", false,-1);
    tracep->declBit(c+686,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBit(c+1063,"clk_in", false,-1);
    tracep->declBit(c+1064,"rst", false,-1);
    tracep->declBit(c+683,"enable", false,-1);
    tracep->declBit(c+679,"go", false,-1);
    tracep->declBit(c+686,"last_clk", false,-1);
    tracep->declBus(c+669,"divider", false,-1, 15,0);
    tracep->declBit(c+612,"clk_out", false,-1);
    tracep->declBit(c+684,"pos_edge", false,-1);
    tracep->declBit(c+685,"neg_edge", false,-1);
    tracep->declBus(c+687,"cnt", false,-1, 15,0);
    tracep->declBit(c+688,"cnt_zero", false,-1);
    tracep->declBit(c+689,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1064,"rst", false,-1);
    tracep->declBus(c+151,"latch", false,-1, 3,0);
    tracep->declBus(c+96,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+678,"len", false,-1, 6,0);
    tracep->declBit(c+680,"lsb", false,-1);
    tracep->declBit(c+679,"go", false,-1);
    tracep->declBit(c+684,"pos_edge", false,-1);
    tracep->declBit(c+685,"neg_edge", false,-1);
    tracep->declBit(c+676,"rx_negedge", false,-1);
    tracep->declBit(c+677,"tx_negedge", false,-1);
    tracep->declBit(c+683,"tip", false,-1);
    tracep->declBit(c+686,"last", false,-1);
    tracep->declBus(c+95,"p_in", false,-1, 31,0);
    tracep->declArray(c+672,"p_out", false,-1, 127,0);
    tracep->declBit(c+612,"s_clk", false,-1);
    tracep->declBit(c+1086,"s_in", false,-1);
    tracep->declBit(c+1085,"s_out", false,-1);
    tracep->declBus(c+690,"cnt", false,-1, 7,0);
    tracep->declArray(c+672,"data", false,-1, 127,0);
    tracep->declBus(c+691,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+692,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+693,"rx_clk", false,-1);
    tracep->declBit(c+694,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+105,"auto_in_psel", false,-1);
    tracep->declBit(c+106,"auto_in_penable", false,-1);
    tracep->declBit(c+94,"auto_in_pwrite", false,-1);
    tracep->declBus(c+102,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1119,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+107,"auto_in_pready", false,-1);
    tracep->declBit(c+1120,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1096,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1083,"uart_rx", false,-1);
    tracep->declBit(c+1084,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+105,"in_psel", false,-1);
    tracep->declBit(c+106,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+107,"in_pready", false,-1);
    tracep->declBit(c+1120,"in_pslverr", false,-1);
    tracep->declBus(c+124,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+1096,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1083,"uart_rx", false,-1);
    tracep->declBit(c+1084,"uart_tx", false,-1);
    tracep->declBit(c+695,"rtsn", false,-1);
    tracep->declBit(c+1120,"ctsn", false,-1);
    tracep->declBit(c+696,"dtr_pad_o", false,-1);
    tracep->declBit(c+1120,"dsr_pad_i", false,-1);
    tracep->declBit(c+1120,"ri_pad_i", false,-1);
    tracep->declBit(c+1120,"dcd_pad_i", false,-1);
    tracep->declBit(c+697,"interrupt", false,-1);
    tracep->declBit(c+152,"reg_we", false,-1);
    tracep->declBit(c+153,"reg_re", false,-1);
    tracep->declBus(c+154,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+155,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+579,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+285,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+698,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1064,"wb_rst_i", false,-1);
    tracep->declBus(c+154,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+156,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+285,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+152,"wb_we_i", false,-1);
    tracep->declBit(c+153,"wb_re_i", false,-1);
    tracep->declBit(c+1084,"stx_pad_o", false,-1);
    tracep->declBit(c+1083,"srx_pad_i", false,-1);
    tracep->declBus(c+1192,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+698,"rts_pad_o", false,-1);
    tracep->declBit(c+696,"dtr_pad_o", false,-1);
    tracep->declBit(c+697,"int_o", false,-1);
    tracep->declBit(c+699,"enable", false,-1);
    tracep->declBit(c+700,"srx_pad", false,-1);
    tracep->declBus(c+701,"ier", false,-1, 3,0);
    tracep->declBus(c+702,"iir", false,-1, 3,0);
    tracep->declBus(c+703,"fcr", false,-1, 1,0);
    tracep->declBus(c+704,"mcr", false,-1, 4,0);
    tracep->declBus(c+705,"lcr", false,-1, 7,0);
    tracep->declBus(c+706,"msr", false,-1, 7,0);
    tracep->declBus(c+707,"dl", false,-1, 15,0);
    tracep->declBus(c+708,"scratch", false,-1, 7,0);
    tracep->declBit(c+709,"start_dlc", false,-1);
    tracep->declBit(c+710,"lsr_mask_d", false,-1);
    tracep->declBit(c+711,"msi_reset", false,-1);
    tracep->declBus(c+712,"dlc", false,-1, 15,0);
    tracep->declBus(c+713,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+714,"rx_reset", false,-1);
    tracep->declBit(c+715,"tx_reset", false,-1);
    tracep->declBit(c+716,"dlab", false,-1);
    tracep->declBit(c+1139,"cts_pad_i", false,-1);
    tracep->declBit(c+1120,"dsr_pad_i", false,-1);
    tracep->declBit(c+1120,"ri_pad_i", false,-1);
    tracep->declBit(c+1120,"dcd_pad_i", false,-1);
    tracep->declBit(c+717,"loopback", false,-1);
    tracep->declBit(c+1120,"cts", false,-1);
    tracep->declBit(c+1139,"dsr", false,-1);
    tracep->declBit(c+1139,"ri", false,-1);
    tracep->declBit(c+1139,"dcd", false,-1);
    tracep->declBit(c+718,"cts_c", false,-1);
    tracep->declBit(c+719,"dsr_c", false,-1);
    tracep->declBit(c+720,"ri_c", false,-1);
    tracep->declBit(c+721,"dcd_c", false,-1);
    tracep->declBus(c+722,"lsr", false,-1, 7,0);
    tracep->declBit(c+723,"lsr0", false,-1);
    tracep->declBit(c+724,"lsr1", false,-1);
    tracep->declBit(c+725,"lsr2", false,-1);
    tracep->declBit(c+726,"lsr3", false,-1);
    tracep->declBit(c+727,"lsr4", false,-1);
    tracep->declBit(c+728,"lsr5", false,-1);
    tracep->declBit(c+729,"lsr6", false,-1);
    tracep->declBit(c+730,"lsr7", false,-1);
    tracep->declBit(c+731,"lsr0r", false,-1);
    tracep->declBit(c+732,"lsr1r", false,-1);
    tracep->declBit(c+733,"lsr2r", false,-1);
    tracep->declBit(c+734,"lsr3r", false,-1);
    tracep->declBit(c+735,"lsr4r", false,-1);
    tracep->declBit(c+736,"lsr5r", false,-1);
    tracep->declBit(c+737,"lsr6r", false,-1);
    tracep->declBit(c+738,"lsr7r", false,-1);
    tracep->declBit(c+286,"lsr_mask", false,-1);
    tracep->declBit(c+739,"rls_int", false,-1);
    tracep->declBit(c+740,"rda_int", false,-1);
    tracep->declBit(c+741,"ti_int", false,-1);
    tracep->declBit(c+742,"thre_int", false,-1);
    tracep->declBit(c+743,"ms_int", false,-1);
    tracep->declBit(c+744,"tf_push", false,-1);
    tracep->declBit(c+745,"rf_pop", false,-1);
    tracep->declBus(c+1113,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+746,"rf_error_bit", false,-1);
    tracep->declBit(c+724,"rf_overrun", false,-1);
    tracep->declBit(c+747,"rf_push_pulse", false,-1);
    tracep->declBus(c+748,"rf_count", false,-1, 4,0);
    tracep->declBus(c+749,"tf_count", false,-1, 4,0);
    tracep->declBus(c+750,"tstate", false,-1, 2,0);
    tracep->declBus(c+751,"rstate", false,-1, 3,0);
    tracep->declBus(c+752,"counter_t", false,-1, 9,0);
    tracep->declBit(c+753,"thre_set_en", false,-1);
    tracep->declBus(c+754,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+755,"block_value", false,-1, 7,0);
    tracep->declBit(c+756,"serial_out", false,-1);
    tracep->declBit(c+757,"serial_in", false,-1);
    tracep->declBit(c+287,"lsr_mask_condition", false,-1);
    tracep->declBit(c+288,"iir_read", false,-1);
    tracep->declBit(c+289,"msr_read", false,-1);
    tracep->declBit(c+290,"fifo_read", false,-1);
    tracep->declBit(c+291,"fifo_write", false,-1);
    tracep->declBus(c+758,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+759,"lsr0_d", false,-1);
    tracep->declBit(c+760,"lsr1_d", false,-1);
    tracep->declBit(c+761,"lsr2_d", false,-1);
    tracep->declBit(c+762,"lsr3_d", false,-1);
    tracep->declBit(c+763,"lsr4_d", false,-1);
    tracep->declBit(c+764,"lsr5_d", false,-1);
    tracep->declBit(c+765,"lsr6_d", false,-1);
    tracep->declBit(c+766,"lsr7_d", false,-1);
    tracep->declBit(c+767,"rls_int_d", false,-1);
    tracep->declBit(c+768,"thre_int_d", false,-1);
    tracep->declBit(c+769,"ms_int_d", false,-1);
    tracep->declBit(c+770,"ti_int_d", false,-1);
    tracep->declBit(c+771,"rda_int_d", false,-1);
    tracep->declBit(c+772,"rls_int_rise", false,-1);
    tracep->declBit(c+773,"thre_int_rise", false,-1);
    tracep->declBit(c+774,"ms_int_rise", false,-1);
    tracep->declBit(c+775,"ti_int_rise", false,-1);
    tracep->declBit(c+776,"rda_int_rise", false,-1);
    tracep->declBit(c+777,"rls_int_pnd", false,-1);
    tracep->declBit(c+778,"rda_int_pnd", false,-1);
    tracep->declBit(c+779,"thre_int_pnd", false,-1);
    tracep->declBit(c+780,"ms_int_pnd", false,-1);
    tracep->declBit(c+781,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1157,"Tp", false,-1, 31,0);
    tracep->declBus(c+1157,"width", false,-1, 31,0);
    tracep->declBus(c+1174,"init_value", false,-1, 0,0);
    tracep->declBit(c+1064,"rst_i", false,-1);
    tracep->declBit(c+1063,"clk_i", false,-1);
    tracep->declBit(c+1120,"stage1_rst_i", false,-1);
    tracep->declBit(c+1139,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1083,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+700,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+782,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1064,"wb_rst_i", false,-1);
    tracep->declBus(c+705,"lcr", false,-1, 7,0);
    tracep->declBit(c+745,"rf_pop", false,-1);
    tracep->declBit(c+757,"srx_pad_i", false,-1);
    tracep->declBit(c+699,"enable", false,-1);
    tracep->declBit(c+714,"rx_reset", false,-1);
    tracep->declBit(c+286,"lsr_mask", false,-1);
    tracep->declBus(c+752,"counter_t", false,-1, 9,0);
    tracep->declBus(c+748,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1113,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+724,"rf_overrun", false,-1);
    tracep->declBit(c+746,"rf_error_bit", false,-1);
    tracep->declBus(c+751,"rstate", false,-1, 3,0);
    tracep->declBit(c+747,"rf_push_pulse", false,-1);
    tracep->declBus(c+783,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+784,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+785,"rshift", false,-1, 7,0);
    tracep->declBit(c+786,"rparity", false,-1);
    tracep->declBit(c+787,"rparity_error", false,-1);
    tracep->declBit(c+788,"rframing_error", false,-1);
    tracep->declBit(c+789,"rbit_in", false,-1);
    tracep->declBit(c+790,"rparity_xor", false,-1);
    tracep->declBus(c+791,"counter_b", false,-1, 7,0);
    tracep->declBit(c+792,"rf_push_q", false,-1);
    tracep->declBus(c+793,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+794,"rf_push", false,-1);
    tracep->declBit(c+795,"break_error", false,-1);
    tracep->declBit(c+796,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+797,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+798,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+799,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1142,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1135,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1190,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1186,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1188,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1187,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1189,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1185,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1192,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1193,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1199,"sr_push", false,-1, 3,0);
    tracep->declBus(c+800,"toc_value", false,-1, 9,0);
    tracep->declBus(c+801,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1200,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1170,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1163,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1201,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1064,"wb_rst_i", false,-1);
    tracep->declBit(c+747,"push", false,-1);
    tracep->declBit(c+745,"pop", false,-1);
    tracep->declBus(c+793,"data_in", false,-1, 10,0);
    tracep->declBit(c+714,"fifo_reset", false,-1);
    tracep->declBit(c+286,"reset_status", false,-1);
    tracep->declBus(c+1113,"data_out", false,-1, 10,0);
    tracep->declBit(c+724,"overrun", false,-1);
    tracep->declBus(c+748,"count", false,-1, 4,0);
    tracep->declBit(c+746,"error_bit", false,-1);
    tracep->declBus(c+1114,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+802+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+818,"top", false,-1, 3,0);
    tracep->declBus(c+819,"bottom", false,-1, 3,0);
    tracep->declBus(c+820,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+821,"word0", false,-1, 2,0);
    tracep->declBus(c+822,"word1", false,-1, 2,0);
    tracep->declBus(c+823,"word2", false,-1, 2,0);
    tracep->declBus(c+824,"word3", false,-1, 2,0);
    tracep->declBus(c+825,"word4", false,-1, 2,0);
    tracep->declBus(c+826,"word5", false,-1, 2,0);
    tracep->declBus(c+827,"word6", false,-1, 2,0);
    tracep->declBus(c+828,"word7", false,-1, 2,0);
    tracep->declBus(c+829,"word8", false,-1, 2,0);
    tracep->declBus(c+830,"word9", false,-1, 2,0);
    tracep->declBus(c+831,"word10", false,-1, 2,0);
    tracep->declBus(c+832,"word11", false,-1, 2,0);
    tracep->declBus(c+833,"word12", false,-1, 2,0);
    tracep->declBus(c+834,"word13", false,-1, 2,0);
    tracep->declBus(c+835,"word14", false,-1, 2,0);
    tracep->declBus(c+836,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1163,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1169,"data_width", false,-1, 31,0);
    tracep->declBus(c+1170,"depth", false,-1, 31,0);
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+747,"we", false,-1);
    tracep->declBus(c+818,"a", false,-1, 3,0);
    tracep->declBus(c+819,"dpra", false,-1, 3,0);
    tracep->declBus(c+837,"di", false,-1, 7,0);
    tracep->declBus(c+1114,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+580+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1064,"wb_rst_i", false,-1);
    tracep->declBus(c+705,"lcr", false,-1, 7,0);
    tracep->declBit(c+744,"tf_push", false,-1);
    tracep->declBus(c+156,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+699,"enable", false,-1);
    tracep->declBit(c+715,"tx_reset", false,-1);
    tracep->declBit(c+286,"lsr_mask", false,-1);
    tracep->declBit(c+756,"stx_pad_o", false,-1);
    tracep->declBus(c+750,"tstate", false,-1, 2,0);
    tracep->declBus(c+749,"tf_count", false,-1, 4,0);
    tracep->declBus(c+838,"counter", false,-1, 4,0);
    tracep->declBus(c+839,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+840,"shift_out", false,-1, 6,0);
    tracep->declBit(c+841,"stx_o_tmp", false,-1);
    tracep->declBit(c+842,"parity_xor", false,-1);
    tracep->declBit(c+843,"tf_pop", false,-1);
    tracep->declBit(c+844,"bit_out", false,-1);
    tracep->declBus(c+156,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1115,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+845,"tf_overrun", false,-1);
    tracep->declBus(c+1143,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1119,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1202,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1203,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1137,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1204,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1169,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1170,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1163,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1201,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+1064,"wb_rst_i", false,-1);
    tracep->declBit(c+744,"push", false,-1);
    tracep->declBit(c+843,"pop", false,-1);
    tracep->declBus(c+156,"data_in", false,-1, 7,0);
    tracep->declBit(c+715,"fifo_reset", false,-1);
    tracep->declBit(c+286,"reset_status", false,-1);
    tracep->declBus(c+1115,"data_out", false,-1, 7,0);
    tracep->declBit(c+845,"overrun", false,-1);
    tracep->declBus(c+749,"count", false,-1, 4,0);
    tracep->declBus(c+846,"top", false,-1, 3,0);
    tracep->declBus(c+847,"bottom", false,-1, 3,0);
    tracep->declBus(c+848,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1163,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1169,"data_width", false,-1, 31,0);
    tracep->declBus(c+1170,"depth", false,-1, 31,0);
    tracep->declBit(c+1063,"clk", false,-1);
    tracep->declBit(c+744,"we", false,-1);
    tracep->declBus(c+846,"a", false,-1, 3,0);
    tracep->declBus(c+847,"dpra", false,-1, 3,0);
    tracep->declBus(c+156,"di", false,-1, 7,0);
    tracep->declBus(c+1115,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+596+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBit(c+99,"auto_in_psel", false,-1);
    tracep->declBit(c+1091,"auto_in_penable", false,-1);
    tracep->declBit(c+94,"auto_in_pwrite", false,-1);
    tracep->declBus(c+100,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1119,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+95,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1121,"auto_in_pready", false,-1);
    tracep->declBit(c+1122,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1123,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1077,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1078,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1079,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1080,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1081,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1082,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1063,"clock", false,-1);
    tracep->declBit(c+1064,"reset", false,-1);
    tracep->declBus(c+145,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+99,"in_psel", false,-1);
    tracep->declBit(c+1091,"in_penable", false,-1);
    tracep->declBus(c+1119,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+94,"in_pwrite", false,-1);
    tracep->declBus(c+95,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+96,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1121,"in_pready", false,-1);
    tracep->declBus(c+1123,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1122,"in_pslverr", false,-1);
    tracep->declBus(c+1077,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1078,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1079,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1080,"vga_hsync", false,-1);
    tracep->declBit(c+1081,"vga_vsync", false,-1);
    tracep->declBit(c+1082,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+612,"sck", false,-1);
    tracep->declBit(c+849,"ss", false,-1);
    tracep->declBit(c+1085,"mosi", false,-1);
    tracep->declBit(c+1139,"miso", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+612,"sck", false,-1);
    tracep->declBit(c+850,"ss", false,-1);
    tracep->declBit(c+1085,"mosi", false,-1);
    tracep->declBit(c+1086,"miso", false,-1);
    tracep->declBit(c+850,"reset", false,-1);
    tracep->declBus(c+928,"state", false,-1, 2,0);
    tracep->declBus(c+929,"counter", false,-1, 7,0);
    tracep->declBus(c+930,"cmd", false,-1, 7,0);
    tracep->declBus(c+931,"addr", false,-1, 23,0);
    tracep->declBus(c+932,"data", false,-1, 31,0);
    tracep->declBit(c+933,"ren", false,-1);
    tracep->declBus(c+1116,"rdata", false,-1, 31,0);
    tracep->declBus(c+1117,"raddr", false,-1, 31,0);
    tracep->declBus(c+1118,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+612,"clock", false,-1);
    tracep->declBit(c+933,"valid", false,-1);
    tracep->declBus(c+930,"cmd", false,-1, 7,0);
    tracep->declBus(c+1117,"addr", false,-1, 31,0);
    tracep->declBus(c+1116,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+1087,"sck", false,-1);
    tracep->declBit(c+1088,"ce_n", false,-1);
    tracep->declBus(c+157,"dio", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1089,"clk", false,-1);
    tracep->declBit(c+614,"cke", false,-1);
    tracep->declBit(c+615,"cs", false,-1);
    tracep->declBit(c+616,"ras", false,-1);
    tracep->declBit(c+617,"cas", false,-1);
    tracep->declBit(c+618,"we", false,-1);
    tracep->declBus(c+619,"a", false,-1, 12,0);
    tracep->declBus(c+620,"ba", false,-1, 1,0);
    tracep->declBus(c+621,"dqm", false,-1, 1,0);
    tracep->declBus(c+622,"dq", false,-1, 15,0);
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
    VlWide<5>/*159:0*/ __Vtemp_h3a4ae3bd__0;
    VlWide<3>/*95:0*/ __Vtemp_h49f7fb6a__0;
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
    bufp->fullIData(oldp+19,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                           : 0U) | 
                                         ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                           : 0U)))),32);
    bufp->fullBit(oldp+20,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+21,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+22,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+23,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+24,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+25,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+26,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+27,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+28,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+29,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+30,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+31,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+32,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+33,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+34,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+35,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+36,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+37,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+38,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+39,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+40,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+41,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+42,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+43,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+44,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+45,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+46,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+47,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+48,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+49,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+50,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+51,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+52,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+53,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+54,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+55,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+56,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+57,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+58,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+59,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+60,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+61,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+62,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+63,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+64,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+65,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+66,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+67,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+68,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+69,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+70,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+71,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+72,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+73,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+74,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+75,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+80,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+82,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+84,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+86,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+89,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+91,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+93,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+94,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+95,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+97,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+98,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+99,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+100,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+101,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+102,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+103,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+107,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_psel));
    bufp->fullBit(oldp+109,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_penable));
    bufp->fullBit(oldp+110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+112,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+118,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+119,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+121,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+122,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+123,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+124,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+132,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+133,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+134,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+135,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+136,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+137,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+138,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+142,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+143,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+144,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+145,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullCData(oldp+146,((0x1fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),5);
    bufp->fullBit(oldp+147,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullBit(oldp+148,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+149,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
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
    bufp->fullBit(oldp+150,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+152,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+153,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+154,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+156,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullCData(oldp+157,((((((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out0) 
                                         & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten))) 
                                  | (0xcU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out1) 
                                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten)))) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0))),4);
    bufp->fullBit(oldp+158,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+159,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+160,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+162,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+164,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+165,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+166,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+167,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+170,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+173,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+174,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+175,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+176,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+179,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+181,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+186,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+190,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+214,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+215,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+216,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+217,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+218,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+219,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+220,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+221,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+222,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+223,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+224,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+225,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+226,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+227,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+228,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+229,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+230,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+231,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+232,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+233,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+234,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+235,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+236,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+237,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+238,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+239,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+240,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+241,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+242,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+243,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+244,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+245,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+246,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+247,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+248,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+250,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+254,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+258,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+259,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+260,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                              [1U]),2);
    bufp->fullBit(oldp+261,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                   >> 1U))));
    bufp->fullIData(oldp+262,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+265,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+266,((((- (IData)((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                                  [1U] 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                          [1U]))),32);
    bufp->fullIData(oldp+267,((((- (IData)((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                                  [1U] 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                             [1U]))),32);
    bufp->fullCData(oldp+268,((0xffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),8);
    bufp->fullSData(oldp+269,((0xffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),16);
    bufp->fullIData(oldp+270,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+271,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+272,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+273,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+274,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+276,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+277,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+278,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+279,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+280,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+281,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+282,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+284,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+285,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+286,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+287,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+288,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+289,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+291,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullBit(oldp+292,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullIData(oldp+293,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+294,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullCData(oldp+296,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+297,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+307,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+308,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+309,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+310,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+311,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+312,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+313,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+316,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+317,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+321,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+322,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+324,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+325,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+326,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+327,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+345,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullCData(oldp+346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullQData(oldp+347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+350,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+353,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+354,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+355,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+356,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+358,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+359,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+360,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+361,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+362,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+363,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+364,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+365,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+366,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+367,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+368,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+369,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+370,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+371,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+372,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+373,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+374,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+375,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+377,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+378,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+379,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+382,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+383,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+384,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+385,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+386,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+387,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+391,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+401,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+405,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+415,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+425,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+429,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+433,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+437,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+441,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+442,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+443,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+444,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+445,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+449,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+452,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+453,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+454,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+455,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+456,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+457,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+461,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+462,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+464,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+465,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+468,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+469,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+472,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+473,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+477,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+481,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+484,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+485,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+486,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+488,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+489,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+492,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+493,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+494,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+496,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+497,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+498,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+501,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+502,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+503,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+505,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+506,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+509,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+510,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+512,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+513,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+514,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+516,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+517,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+518,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+521,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+522,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+524,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+525,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+526,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+529,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+530,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+532,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+533,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+534,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+536,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+537,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+538,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+540,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+541,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+542,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+544,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+545,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+546,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+548,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+549,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+550,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+552,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+553,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullCData(oldp+554,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                               & (- (IData)((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full))))))),2);
    bufp->fullCData(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullBit(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+558,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+559,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                    & (- (IData)((1U 
                                                  & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))))) 
                                   >> 1U))));
    bufp->fullBit(oldp+560,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                   >> 1U))));
    bufp->fullBit(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__bresp_get));
    bufp->fullBit(oldp+562,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__rvalid_get));
    bufp->fullBit(oldp+563,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                       & (- (IData)(
                                                    (1U 
                                                     & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full))))))) 
                                   >> 1U))));
    bufp->fullBit(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+566,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+570,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+572,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+573,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+574,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+575,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+577,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullCData(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+582,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+590,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+594,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+598,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+602,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+606,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullBit(oldp+612,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+613,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+614,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+615,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+616,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+617,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+618,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+621,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullSData(oldp+622,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                  ? 0U : 0xffffU) & 
                                ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                    ? 0U : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                      ? 0U : 0xffffU)) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                     ? 0U : 0xffffU))) 
                               & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                   ? 0U : 0xffffU))),16);
    bufp->fullBit(oldp+623,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullIData(oldp+624,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+625,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_pready));
    bufp->fullIData(oldp+626,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+628,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+629,((0xfU & ((8U > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
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
    bufp->fullBit(oldp+630,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+632,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+633,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+634,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+637,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+639,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+641,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+642,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullBit(oldp+643,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+644,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+645,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+647,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+649,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullBit(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+651,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+652,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+653,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+655,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+656,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullCData(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+658,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+660,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullSData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+670,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+676,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+677,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+678,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+679,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+680,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+681,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+682,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+683,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+684,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+685,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+686,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+687,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+688,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+689,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+690,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+691,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+692,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+693,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+694,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+695,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+696,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+697,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+698,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+699,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+701,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+702,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+704,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+705,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+706,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+707,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+708,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+709,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+715,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+716,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+717,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+718,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+719,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+720,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+721,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+722,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+723,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+724,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+725,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+726,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+727,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+728,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+729,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+730,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+731,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+732,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+733,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+734,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+735,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+736,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+737,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+738,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+739,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+740,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+741,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+742,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+743,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+744,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+746,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+747,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+748,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+749,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+750,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+752,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+753,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+754,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+756,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+758,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+759,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+760,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+761,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+762,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+763,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+764,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+765,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+766,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+767,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+768,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+769,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+770,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+771,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+772,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+773,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+774,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+775,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+776,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+777,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+778,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+779,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+780,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+781,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+782,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+783,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+784,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+785,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+786,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+788,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+789,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+790,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+793,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+795,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+796,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+797,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+798,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+799,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+800,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+801,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+803,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+804,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+805,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+806,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+807,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+808,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+809,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+810,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+811,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+812,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+814,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+815,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+816,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+818,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+820,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+821,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+822,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+823,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+824,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+827,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+828,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+829,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+830,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+833,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+834,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+836,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+837,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+839,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+840,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+841,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+843,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+848,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+849,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_ss) 
                                   >> 7U))));
    bufp->fullBit(oldp+850,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullIData(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+854,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+858,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+860,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+861,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+862,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+864,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+866,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+867,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+868,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+869,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+870,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+874,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+875,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+877,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+894,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+900,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+901,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+920,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+921,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+922,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+923,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+928,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+929,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+930,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+931,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+932,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+933,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                             & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullCData(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullBit(oldp+936,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+937,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+938,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu) 
                             & (2U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)))));
    bufp->fullBit(oldp+939,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+940,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+941,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+942,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+943,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+944,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+945,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+946,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+947,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                      | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+948,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+949,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+950,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+951,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+952,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+953,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+954,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+955,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+956,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+957,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+958,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+959,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+960,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+961,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+962,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+963,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+964,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+965,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+966,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+967,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+968,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+969,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+972,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+973,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+975,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+976,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+977,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+978,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+979,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+980,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+981,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+983,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+984,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+985,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+987,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+988,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+989,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+990,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+991,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+992,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                             | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+993,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+994,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),2);
    bufp->fullSData(oldp+995,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                               >> 0x14U)),12);
    bufp->fullCData(oldp+996,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+997,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+998,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+999,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullCData(oldp+1000,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 1U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 3U : ((3U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 7U
                                                   : 0xfU)))),4);
    __Vtemp_h49f7fb6a__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))));
    __Vtemp_h49f7fb6a__0[1U] = ((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h49f7fb6a__0[2U] = (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+1001,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1004,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1006,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1008,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1009,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1010,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullIData(oldp+1011,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullIData(oldp+1012,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1013,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullIData(oldp+1014,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullIData(oldp+1015,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1016,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1017,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1018,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1019,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1020,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1021,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1022,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1023,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1024,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1025,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1026,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1027,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1029,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1030,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                               >> 0x1bU)) 
                                     | ((0xcU & (8U 
                                                 ^ 
                                                 (0x3cU 
                                                  & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                     >> 0x1aU)))) 
                                        | ((2U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                  >> 0x17U)) 
                                           | (1U & 
                                              (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                               >> 0xcU))))))));
    bufp->fullBit(oldp+1031,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1032,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1034,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1038,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullIData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1046,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1047,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1048,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1049,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1050,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullIData(oldp+1051,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1052,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1053,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1054,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1055,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1056,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1057,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1058,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1059,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1060,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1061,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+1062,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1063,(vlSelf->clock));
    bufp->fullBit(oldp+1064,(vlSelf->reset));
    bufp->fullSData(oldp+1065,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1066,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1067,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1068,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1069,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1070,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1071,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1072,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1073,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1074,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1075,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1076,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1077,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1078,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1079,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1080,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1081,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1082,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1083,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1084,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1085,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+1086,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullBit(oldp+1087,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck))));
    bufp->fullBit(oldp+1088,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n))));
    bufp->fullBit(oldp+1089,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullBit(oldp+1090,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1091,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1092,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1093,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1094,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1095,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1096,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullCData(oldp+1097,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                 ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                    << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))),2);
    bufp->fullBit(oldp+1098,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullCData(oldp+1099,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1100,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1101,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1102,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1103,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
                              & (0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                  >> 0x1bU)) 
                                        | ((0xcU & 
                                            (8U ^ (0x3cU 
                                                   & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                      >> 0x1aU)))) 
                                           | ((2U & 
                                               (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                >> 0x17U)) 
                                              | (1U 
                                                 & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                    >> 0xcU)))))))));
    bufp->fullBit(oldp+1104,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1105,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1106,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1107,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullBit(oldp+1108,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1109,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
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
    bufp->fullBit(oldp+1110,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__rvalid_get)) 
                              & (3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))));
    bufp->fullBit(oldp+1111,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1112,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1113,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullIData(oldp+1116,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1117,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1118,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullCData(oldp+1119,(1U),3);
    bufp->fullBit(oldp+1120,(0U));
    bufp->fullBit(oldp+1121,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1122,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1123,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1124,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1125,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1126,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1127,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pready));
    bufp->fullBit(oldp+1128,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullIData(oldp+1129,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_prdata),32);
    bufp->fullCData(oldp+1130,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1131,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullCData(oldp+1132,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awsize),3);
    bufp->fullCData(oldp+1133,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullBit(oldp+1134,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1135,(1U),4);
    bufp->fullCData(oldp+1136,(0U),8);
    bufp->fullCData(oldp+1137,(4U),3);
    bufp->fullCData(oldp+1138,(1U),2);
    bufp->fullBit(oldp+1139,(1U));
    bufp->fullBit(oldp+1140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1141,(0U),32);
    bufp->fullCData(oldp+1142,(0U),4);
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
    bufp->fullCData(oldp+1175,(0x1bU),8);
    bufp->fullCData(oldp+1176,(0xebU),8);
    bufp->fullCData(oldp+1177,(0x38U),8);
    bufp->fullIData(oldp+1178,(0x64U),32);
    bufp->fullIData(oldp+1179,(0x18U),32);
    bufp->fullIData(oldp+1180,(9U),32);
    bufp->fullIData(oldp+1181,(0xdU),32);
    bufp->fullIData(oldp+1182,(0x2000U),32);
    bufp->fullIData(oldp+1183,(0x2710U),32);
    bufp->fullIData(oldp+1184,(0x30cU),32);
    bufp->fullCData(oldp+1185,(7U),4);
    bufp->fullCData(oldp+1186,(3U),4);
    bufp->fullCData(oldp+1187,(5U),4);
    bufp->fullCData(oldp+1188,(4U),4);
    bufp->fullCData(oldp+1189,(6U),4);
    bufp->fullCData(oldp+1190,(2U),4);
    bufp->fullSData(oldp+1191,(0x21U),13);
    bufp->fullCData(oldp+1192,(8U),4);
    bufp->fullCData(oldp+1193,(9U),4);
    bufp->fullIData(oldp+1194,(0xaU),32);
    bufp->fullIData(oldp+1195,(6U),32);
    bufp->fullIData(oldp+1196,(0x11U),32);
    bufp->fullIData(oldp+1197,(0x30000000U),32);
    bufp->fullIData(oldp+1198,(0x3fffffffU),32);
    bufp->fullCData(oldp+1199,(0xaU),4);
    bufp->fullIData(oldp+1200,(0xbU),32);
    bufp->fullIData(oldp+1201,(5U),32);
    bufp->fullCData(oldp+1202,(2U),3);
    bufp->fullCData(oldp+1203,(3U),3);
    bufp->fullCData(oldp+1204,(5U),3);
}
