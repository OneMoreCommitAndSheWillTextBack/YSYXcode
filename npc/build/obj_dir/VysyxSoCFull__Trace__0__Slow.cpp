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
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+1168,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1169,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1170,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1171,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1172,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1173,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1174,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1175,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1176,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1177,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1178,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1179,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1180,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1181,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1182,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1183,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1184,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1185,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1186,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1187,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+1168,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1169,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1170,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1171,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1172,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1173,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1174,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1175,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1176,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1177,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1178,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1179,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1180,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1181,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1182,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1183,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1184,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1185,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1186,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1187,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+660,"spi_sck", false,-1);
    tracep->declBus(c+661,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1188,"spi_mosi", false,-1);
    tracep->declBit(c+1189,"spi_miso", false,-1);
    tracep->declBit(c+1186,"uart_rx", false,-1);
    tracep->declBit(c+1187,"uart_tx", false,-1);
    tracep->declBit(c+209,"psram_sck", false,-1);
    tracep->declBit(c+210,"psram_ce_n", false,-1);
    tracep->declBus(c+1190,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1191,"sdram_clk", false,-1);
    tracep->declBit(c+662,"sdram_cke", false,-1);
    tracep->declBit(c+663,"sdram_cs", false,-1);
    tracep->declBit(c+664,"sdram_ras", false,-1);
    tracep->declBit(c+665,"sdram_cas", false,-1);
    tracep->declBit(c+666,"sdram_we", false,-1);
    tracep->declBus(c+667,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+668,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+669,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+670,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1168,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1169,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1170,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1171,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1172,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1173,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1174,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1175,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1176,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1177,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1178,"ps2_clk", false,-1);
    tracep->declBit(c+1179,"ps2_data", false,-1);
    tracep->declBus(c+1180,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1181,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1182,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1183,"vga_hsync", false,-1);
    tracep->declBit(c+1184,"vga_vsync", false,-1);
    tracep->declBit(c+1185,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+123,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+124,"in_psel", false,-1);
    tracep->declBit(c+326,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+211,"in_pready", false,-1);
    tracep->declBus(c+193,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+128,"in_pslverr", false,-1);
    tracep->declBus(c+123,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+124,"out_psel", false,-1);
    tracep->declBit(c+326,"out_penable", false,-1);
    tracep->declBus(c+1227,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"out_pwrite", false,-1);
    tracep->declBus(c+126,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+211,"out_pready", false,-1);
    tracep->declBus(c+193,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+128,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+124,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+326,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+123,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+211,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+128,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+193,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+129,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+44,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+123,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+671,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1228,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+672,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+130,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+45,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+131,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1227,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1229,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1230,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1231,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+132,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+46,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+133,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1227,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1232,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1233,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1234,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+134,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+47,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+133,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1227,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+1235,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1236,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1237,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+135,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+48,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+123,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1192,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1228,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+327,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+136,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+137,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+133,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1227,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+138,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1228,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1193,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+139,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+49,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+125,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+131,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1227,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+1194,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1228,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+1195,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+140,"sel_0", false,-1);
    tracep->declBit(c+141,"sel_1", false,-1);
    tracep->declBit(c+142,"sel_2", false,-1);
    tracep->declBit(c+143,"sel_3", false,-1);
    tracep->declBit(c+144,"sel_4", false,-1);
    tracep->declBit(c+145,"sel_5", false,-1);
    tracep->declBit(c+146,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+147,"auto_in_awready", false,-1);
    tracep->declBit(c+148,"auto_in_awvalid", false,-1);
    tracep->declBus(c+328,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1081,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1082,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+147,"auto_in_wready", false,-1);
    tracep->declBit(c+149,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+212,"auto_in_bready", false,-1);
    tracep->declBit(c+213,"auto_in_bvalid", false,-1);
    tracep->declBus(c+329,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+50,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+150,"auto_in_arready", false,-1);
    tracep->declBit(c+151,"auto_in_arvalid", false,-1);
    tracep->declBus(c+330,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1085,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+989,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+214,"auto_in_rready", false,-1);
    tracep->declBit(c+215,"auto_in_rvalid", false,-1);
    tracep->declBus(c+331,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+194,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+50,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+124,"auto_out_psel", false,-1);
    tracep->declBit(c+326,"auto_out_penable", false,-1);
    tracep->declBit(c+125,"auto_out_pwrite", false,-1);
    tracep->declBus(c+123,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+126,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+211,"auto_out_pready", false,-1);
    tracep->declBit(c+128,"auto_out_pslverr", false,-1);
    tracep->declBus(c+193,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+326,"nodeOut_penable", false,-1);
    tracep->declBus(c+332,"state", false,-1, 1,0);
    tracep->declBit(c+150,"accept_read", false,-1);
    tracep->declBit(c+147,"accept_write", false,-1);
    tracep->declBit(c+333,"is_write_r", false,-1);
    tracep->declBit(c+125,"is_write", false,-1);
    tracep->declBus(c+331,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+329,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+334,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+335,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+336,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+337,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+152,"resp", false,-1, 1,0);
    tracep->declBus(c+338,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+50,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+215,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+339,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+213,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+340,"auto_in_awready", false,-1);
    tracep->declBit(c+87,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1238,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1086,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1239,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1087,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1088,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+341,"auto_in_wready", false,-1);
    tracep->declBit(c+88,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1089,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1090,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1240,"auto_in_wlast", false,-1);
    tracep->declBit(c+1196,"auto_in_bready", false,-1);
    tracep->declBit(c+216,"auto_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+342,"auto_in_arready", false,-1);
    tracep->declBit(c+89,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1241,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1091,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1242,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+990,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1243,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+90,"auto_in_rready", false,-1);
    tracep->declBit(c+219,"auto_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+51,"auto_in_rlast", false,-1);
    tracep->declBit(c+221,"auto_out_awready", false,-1);
    tracep->declBit(c+91,"auto_out_awvalid", false,-1);
    tracep->declBus(c+328,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1081,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1082,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+343,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+222,"auto_out_wready", false,-1);
    tracep->declBit(c+92,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+93,"auto_out_wlast", false,-1);
    tracep->declBit(c+223,"auto_out_bready", false,-1);
    tracep->declBit(c+224,"auto_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+226,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+227,"auto_out_arready", false,-1);
    tracep->declBit(c+94,"auto_out_arvalid", false,-1);
    tracep->declBus(c+330,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1085,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+989,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+344,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+90,"auto_out_rready", false,-1);
    tracep->declBit(c+219,"auto_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+52,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+228,"auto_out_rlast", false,-1);
    tracep->declBit(c+92,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+345,"w_idle", false,-1);
    tracep->declBit(c+229,"in_awready", false,-1);
    tracep->declBit(c+346,"busy", false,-1);
    tracep->declBus(c+347,"r_addr", false,-1, 31,0);
    tracep->declBus(c+348,"r_len", false,-1, 7,0);
    tracep->declBus(c+349,"len", false,-1, 7,0);
    tracep->declBus(c+1092,"addr", false,-1, 31,0);
    tracep->declBit(c+350,"busy_1", false,-1);
    tracep->declBus(c+351,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+352,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+353,"len_1", false,-1, 7,0);
    tracep->declBus(c+1093,"addr_1", false,-1, 31,0);
    tracep->declBit(c+354,"wbeats_latched", false,-1);
    tracep->declBit(c+91,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+95,"wbeats_valid", false,-1);
    tracep->declBus(c+355,"w_counter", false,-1, 8,0);
    tracep->declBus(c+96,"w_todo", false,-1, 8,0);
    tracep->declBit(c+93,"w_last", false,-1);
    tracep->declBit(c+223,"nodeOut_bready", false,-1);
    tracep->declBus(c+356,"error_0", false,-1, 1,0);
    tracep->declBus(c+357,"error_1", false,-1, 1,0);
    tracep->declBus(c+358,"error_2", false,-1, 1,0);
    tracep->declBus(c+359,"error_3", false,-1, 1,0);
    tracep->declBus(c+360,"error_4", false,-1, 1,0);
    tracep->declBus(c+361,"error_5", false,-1, 1,0);
    tracep->declBus(c+362,"error_6", false,-1, 1,0);
    tracep->declBus(c+363,"error_7", false,-1, 1,0);
    tracep->declBus(c+364,"error_8", false,-1, 1,0);
    tracep->declBus(c+365,"error_9", false,-1, 1,0);
    tracep->declBus(c+366,"error_10", false,-1, 1,0);
    tracep->declBus(c+367,"error_11", false,-1, 1,0);
    tracep->declBus(c+368,"error_12", false,-1, 1,0);
    tracep->declBus(c+369,"error_13", false,-1, 1,0);
    tracep->declBus(c+370,"error_14", false,-1, 1,0);
    tracep->declBus(c+371,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+342,"io_enq_ready", false,-1);
    tracep->declBit(c+89,"io_enq_valid", false,-1);
    tracep->declBus(c+1241,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1091,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1242,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+990,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1243,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+230,"io_deq_ready", false,-1);
    tracep->declBit(c+94,"io_deq_valid", false,-1);
    tracep->declBus(c+330,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1094,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+372,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+989,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+373,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+374,"ram", false,-1, 48,0);
    tracep->declBit(c+376,"full", false,-1);
    tracep->declBit(c+94,"io_deq_valid_0", false,-1);
    tracep->declBit(c+231,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+340,"io_enq_ready", false,-1);
    tracep->declBit(c+87,"io_enq_valid", false,-1);
    tracep->declBus(c+1238,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1086,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1239,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1087,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1088,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+232,"io_deq_ready", false,-1);
    tracep->declBit(c+97,"io_deq_valid", false,-1);
    tracep->declBus(c+328,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1095,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+377,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1082,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1096,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+378,"ram", false,-1, 48,0);
    tracep->declBit(c+380,"full", false,-1);
    tracep->declBit(c+97,"io_deq_valid_0", false,-1);
    tracep->declBit(c+233,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+341,"io_enq_ready", false,-1);
    tracep->declBit(c+88,"io_enq_valid", false,-1);
    tracep->declBus(c+1089,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1090,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1240,"io_enq_bits_last", false,-1);
    tracep->declBit(c+234,"io_deq_ready", false,-1);
    tracep->declBit(c+98,"io_deq_valid", false,-1);
    tracep->declBus(c+1083,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1084,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+381,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+382,"ram", false,-1, 36,0);
    tracep->declBit(c+384,"full", false,-1);
    tracep->declBit(c+98,"io_deq_valid_0", false,-1);
    tracep->declBit(c+235,"do_enq", false,-1);
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
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+236,"auto_in_awready", false,-1);
    tracep->declBit(c+153,"auto_in_awvalid", false,-1);
    tracep->declBus(c+328,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1097,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1199,"auto_in_wready", false,-1);
    tracep->declBit(c+1200,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+237,"auto_in_bready", false,-1);
    tracep->declBit(c+385,"auto_in_bvalid", false,-1);
    tracep->declBus(c+386,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+387,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+238,"auto_in_arready", false,-1);
    tracep->declBit(c+1201,"auto_in_arvalid", false,-1);
    tracep->declBus(c+330,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1098,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+239,"auto_in_rready", false,-1);
    tracep->declBit(c+388,"auto_in_rvalid", false,-1);
    tracep->declBus(c+389,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+390,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+391,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+238,"nodeIn_arready", false,-1);
    tracep->declBit(c+236,"nodeIn_awready", false,-1);
    tracep->declBit(c+1099,"w_sel0", false,-1);
    tracep->declBit(c+385,"w_full", false,-1);
    tracep->declBus(c+386,"w_id", false,-1, 3,0);
    tracep->declBit(c+392,"r_sel1", false,-1);
    tracep->declBit(c+393,"w_sel1", false,-1);
    tracep->declBit(c+388,"r_full", false,-1);
    tracep->declBus(c+389,"r_id", false,-1, 3,0);
    tracep->declBit(c+240,"ren", false,-1);
    tracep->declBit(c+394,"rdata_REG", false,-1);
    tracep->declBus(c+395,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+396,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+397,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+398,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1100,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+240,"R0_en", false,-1);
    tracep->declBit(c+1166,"R0_clk", false,-1);
    tracep->declBus(c+399,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1101,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+241,"W0_en", false,-1);
    tracep->declBit(c+1166,"W0_clk", false,-1);
    tracep->declBus(c+1083,"W0_data", false,-1, 31,0);
    tracep->declBus(c+1084,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+340,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+87,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1238,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1086,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1239,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1087,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1088,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+341,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+88,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1089,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1090,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1240,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1196,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+216,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+342,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+89,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1241,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1091,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1242,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+990,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1243,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+90,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+219,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+51,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+340,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+87,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1238,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1086,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1239,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1087,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1088,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+341,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+88,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1089,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1090,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1240,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1196,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+216,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+342,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+89,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1241,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1091,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1242,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+990,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1243,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+90,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+219,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+51,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+242,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+99,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+328,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1081,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1082,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+222,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+92,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+93,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+223,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+224,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+243,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+100,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+330,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1085,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+989,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+90,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+219,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+228,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+236,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+153,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+328,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1097,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1199,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1200,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+237,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+385,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+386,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+387,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+238,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1201,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+330,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1098,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+239,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+388,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+389,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+390,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+391,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1202,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1203,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+400,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1204,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+330,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1102,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1205,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+401,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+402,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+403,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+147,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+148,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+328,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1081,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+1082,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+147,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+149,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+212,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+213,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+329,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+50,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+150,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+151,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+330,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1085,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+989,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+214,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+215,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+331,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+194,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+50,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+224,"in_0_bvalid", false,-1);
    tracep->declBit(c+219,"in_0_rvalid", false,-1);
    tracep->declBit(c+244,"in_0_wready", false,-1);
    tracep->declBit(c+245,"in_0_awready", false,-1);
    tracep->declBit(c+243,"in_0_arready", false,-1);
    tracep->declBit(c+242,"anonIn_awready", false,-1);
    tracep->declBit(c+1103,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1104,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1105,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1106,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1107,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1108,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+404,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+405,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+406,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+407,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+408,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+409,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+410,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+411,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+412,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+413,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+414,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+415,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+416,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+417,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+418,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+419,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+420,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+421,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+422,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+423,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+424,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+425,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+426,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+427,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+428,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+429,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+430,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+431,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+432,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+433,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+434,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+435,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+436,"latched", false,-1);
    tracep->declBit(c+101,"in_0_awvalid", false,-1);
    tracep->declBit(c+102,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+103,"in_0_wvalid", false,-1);
    tracep->declBit(c+437,"idle_3", false,-1);
    tracep->declBit(c+246,"anyValid", false,-1);
    tracep->declBus(c+247,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+438,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+248,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+249,"prefixOR_1", false,-1);
    tracep->declBit(c+250,"winner_3_1", false,-1);
    tracep->declBit(c+251,"winner_3_2", false,-1);
    tracep->declBit(c+439,"state_3_0", false,-1);
    tracep->declBit(c+440,"state_3_1", false,-1);
    tracep->declBit(c+441,"state_3_2", false,-1);
    tracep->declBit(c+252,"muxState_3_0", false,-1);
    tracep->declBit(c+253,"muxState_3_1", false,-1);
    tracep->declBit(c+254,"muxState_3_2", false,-1);
    tracep->declBit(c+442,"idle_4", false,-1);
    tracep->declBit(c+255,"anyValid_1", false,-1);
    tracep->declBus(c+256,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+443,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+257,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+258,"winner_4_0", false,-1);
    tracep->declBit(c+259,"winner_4_2", false,-1);
    tracep->declBit(c+444,"state_4_0", false,-1);
    tracep->declBit(c+445,"state_4_2", false,-1);
    tracep->declBit(c+260,"muxState_4_0", false,-1);
    tracep->declBit(c+261,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+446,"io_enq_ready", false,-1);
    tracep->declBit(c+102,"io_enq_valid", false,-1);
    tracep->declBus(c+1109,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+262,"io_deq_ready", false,-1);
    tracep->declBit(c+104,"io_deq_valid", false,-1);
    tracep->declBus(c+1110,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+447,"wrap", false,-1);
    tracep->declBit(c+448,"wrap_1", false,-1);
    tracep->declBit(c+449,"maybe_full", false,-1);
    tracep->declBit(c+450,"ptr_match", false,-1);
    tracep->declBit(c+451,"empty", false,-1);
    tracep->declBit(c+452,"full", false,-1);
    tracep->declBit(c+104,"io_deq_valid_0", false,-1);
    tracep->declBit(c+263,"do_deq", false,-1);
    tracep->declBit(c+264,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+448,"R0_addr", false,-1);
    tracep->declBit(c+1244,"R0_en", false,-1);
    tracep->declBit(c+1166,"R0_clk", false,-1);
    tracep->declBus(c+453,"R0_data", false,-1, 2,0);
    tracep->declBit(c+447,"W0_addr", false,-1);
    tracep->declBit(c+264,"W0_en", false,-1);
    tracep->declBit(c+1166,"W0_clk", false,-1);
    tracep->declBus(c+1109,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+454+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+221,"auto_in_awready", false,-1);
    tracep->declBit(c+91,"auto_in_awvalid", false,-1);
    tracep->declBus(c+328,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1081,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1082,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+343,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+222,"auto_in_wready", false,-1);
    tracep->declBit(c+92,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+93,"auto_in_wlast", false,-1);
    tracep->declBit(c+223,"auto_in_bready", false,-1);
    tracep->declBit(c+224,"auto_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+226,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+227,"auto_in_arready", false,-1);
    tracep->declBit(c+94,"auto_in_arvalid", false,-1);
    tracep->declBus(c+330,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1085,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+989,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+344,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+90,"auto_in_rready", false,-1);
    tracep->declBit(c+219,"auto_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+52,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+228,"auto_in_rlast", false,-1);
    tracep->declBit(c+242,"auto_out_awready", false,-1);
    tracep->declBit(c+99,"auto_out_awvalid", false,-1);
    tracep->declBus(c+328,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1081,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1082,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+222,"auto_out_wready", false,-1);
    tracep->declBit(c+92,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1083,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1084,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+93,"auto_out_wlast", false,-1);
    tracep->declBit(c+223,"auto_out_bready", false,-1);
    tracep->declBit(c+224,"auto_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+243,"auto_out_arready", false,-1);
    tracep->declBit(c+100,"auto_out_arvalid", false,-1);
    tracep->declBus(c+330,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1085,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+989,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+90,"auto_out_rready", false,-1);
    tracep->declBit(c+219,"auto_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+228,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+456,"io_enq_ready", false,-1);
    tracep->declBit(c+53,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+265,"io_deq_ready", false,-1);
    tracep->declBit(c+457,"io_deq_valid", false,-1);
    tracep->declBit(c+458,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+458,"ram_real_last", false,-1);
    tracep->declBit(c+457,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+459,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+460,"io_enq_ready", false,-1);
    tracep->declBit(c+54,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+266,"io_deq_ready", false,-1);
    tracep->declBit(c+461,"io_deq_valid", false,-1);
    tracep->declBit(c+462,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+462,"ram_real_last", false,-1);
    tracep->declBit(c+461,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+463,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+464,"io_enq_ready", false,-1);
    tracep->declBit(c+55,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+267,"io_deq_ready", false,-1);
    tracep->declBit(c+465,"io_deq_valid", false,-1);
    tracep->declBit(c+466,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+466,"ram_real_last", false,-1);
    tracep->declBit(c+465,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+467,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+468,"io_enq_ready", false,-1);
    tracep->declBit(c+56,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+268,"io_deq_ready", false,-1);
    tracep->declBit(c+469,"io_deq_valid", false,-1);
    tracep->declBit(c+470,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+470,"ram_real_last", false,-1);
    tracep->declBit(c+469,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+471,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+472,"io_enq_ready", false,-1);
    tracep->declBit(c+57,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+269,"io_deq_ready", false,-1);
    tracep->declBit(c+473,"io_deq_valid", false,-1);
    tracep->declBit(c+474,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+474,"ram_real_last", false,-1);
    tracep->declBit(c+473,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+475,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+476,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+270,"io_deq_ready", false,-1);
    tracep->declBit(c+477,"io_deq_valid", false,-1);
    tracep->declBit(c+478,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+478,"ram_real_last", false,-1);
    tracep->declBit(c+477,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+479,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+480,"io_enq_ready", false,-1);
    tracep->declBit(c+59,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+271,"io_deq_ready", false,-1);
    tracep->declBit(c+481,"io_deq_valid", false,-1);
    tracep->declBit(c+482,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+482,"ram_real_last", false,-1);
    tracep->declBit(c+481,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+483,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+484,"io_enq_ready", false,-1);
    tracep->declBit(c+60,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+272,"io_deq_ready", false,-1);
    tracep->declBit(c+485,"io_deq_valid", false,-1);
    tracep->declBit(c+486,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+486,"ram_real_last", false,-1);
    tracep->declBit(c+485,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+487,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+488,"io_enq_ready", false,-1);
    tracep->declBit(c+61,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+273,"io_deq_ready", false,-1);
    tracep->declBit(c+489,"io_deq_valid", false,-1);
    tracep->declBit(c+490,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+490,"ram_real_last", false,-1);
    tracep->declBit(c+489,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+491,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+492,"io_enq_ready", false,-1);
    tracep->declBit(c+62,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+274,"io_deq_ready", false,-1);
    tracep->declBit(c+493,"io_deq_valid", false,-1);
    tracep->declBit(c+494,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+494,"ram_real_last", false,-1);
    tracep->declBit(c+493,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+495,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+496,"io_enq_ready", false,-1);
    tracep->declBit(c+63,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+275,"io_deq_ready", false,-1);
    tracep->declBit(c+497,"io_deq_valid", false,-1);
    tracep->declBit(c+498,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+498,"ram_real_last", false,-1);
    tracep->declBit(c+497,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+499,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+500,"io_enq_ready", false,-1);
    tracep->declBit(c+64,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+276,"io_deq_ready", false,-1);
    tracep->declBit(c+501,"io_deq_valid", false,-1);
    tracep->declBit(c+502,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+502,"ram_real_last", false,-1);
    tracep->declBit(c+501,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+503,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+504,"io_enq_ready", false,-1);
    tracep->declBit(c+65,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+277,"io_deq_ready", false,-1);
    tracep->declBit(c+505,"io_deq_valid", false,-1);
    tracep->declBit(c+506,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+506,"ram_real_last", false,-1);
    tracep->declBit(c+505,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+507,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+508,"io_enq_ready", false,-1);
    tracep->declBit(c+66,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+278,"io_deq_ready", false,-1);
    tracep->declBit(c+509,"io_deq_valid", false,-1);
    tracep->declBit(c+510,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+510,"ram_real_last", false,-1);
    tracep->declBit(c+509,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+511,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+512,"io_enq_ready", false,-1);
    tracep->declBit(c+67,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+279,"io_deq_ready", false,-1);
    tracep->declBit(c+513,"io_deq_valid", false,-1);
    tracep->declBit(c+514,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+514,"ram_real_last", false,-1);
    tracep->declBit(c+513,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+515,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+516,"io_enq_ready", false,-1);
    tracep->declBit(c+68,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+280,"io_deq_ready", false,-1);
    tracep->declBit(c+517,"io_deq_valid", false,-1);
    tracep->declBit(c+518,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+518,"ram_real_last", false,-1);
    tracep->declBit(c+517,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+519,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+520,"io_enq_ready", false,-1);
    tracep->declBit(c+69,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+281,"io_deq_ready", false,-1);
    tracep->declBit(c+521,"io_deq_valid", false,-1);
    tracep->declBit(c+522,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+522,"ram_real_last", false,-1);
    tracep->declBit(c+521,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+523,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+524,"io_enq_ready", false,-1);
    tracep->declBit(c+70,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+282,"io_deq_ready", false,-1);
    tracep->declBit(c+525,"io_deq_valid", false,-1);
    tracep->declBit(c+526,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+526,"ram_real_last", false,-1);
    tracep->declBit(c+525,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+527,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+528,"io_enq_ready", false,-1);
    tracep->declBit(c+71,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+283,"io_deq_ready", false,-1);
    tracep->declBit(c+529,"io_deq_valid", false,-1);
    tracep->declBit(c+530,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+530,"ram_real_last", false,-1);
    tracep->declBit(c+529,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+531,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+532,"io_enq_ready", false,-1);
    tracep->declBit(c+72,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+284,"io_deq_ready", false,-1);
    tracep->declBit(c+533,"io_deq_valid", false,-1);
    tracep->declBit(c+534,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+534,"ram_real_last", false,-1);
    tracep->declBit(c+533,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+535,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+536,"io_enq_ready", false,-1);
    tracep->declBit(c+73,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+285,"io_deq_ready", false,-1);
    tracep->declBit(c+537,"io_deq_valid", false,-1);
    tracep->declBit(c+538,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+538,"ram_real_last", false,-1);
    tracep->declBit(c+537,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+539,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+540,"io_enq_ready", false,-1);
    tracep->declBit(c+74,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+286,"io_deq_ready", false,-1);
    tracep->declBit(c+541,"io_deq_valid", false,-1);
    tracep->declBit(c+542,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+542,"ram_real_last", false,-1);
    tracep->declBit(c+541,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+543,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+544,"io_enq_ready", false,-1);
    tracep->declBit(c+75,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+287,"io_deq_ready", false,-1);
    tracep->declBit(c+545,"io_deq_valid", false,-1);
    tracep->declBit(c+546,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+546,"ram_real_last", false,-1);
    tracep->declBit(c+545,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+547,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+548,"io_enq_ready", false,-1);
    tracep->declBit(c+76,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+288,"io_deq_ready", false,-1);
    tracep->declBit(c+549,"io_deq_valid", false,-1);
    tracep->declBit(c+550,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+550,"ram_real_last", false,-1);
    tracep->declBit(c+549,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+551,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+552,"io_enq_ready", false,-1);
    tracep->declBit(c+77,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+289,"io_deq_ready", false,-1);
    tracep->declBit(c+553,"io_deq_valid", false,-1);
    tracep->declBit(c+554,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+554,"ram_real_last", false,-1);
    tracep->declBit(c+553,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+555,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+556,"io_enq_ready", false,-1);
    tracep->declBit(c+78,"io_enq_valid", false,-1);
    tracep->declBit(c+343,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+290,"io_deq_ready", false,-1);
    tracep->declBit(c+557,"io_deq_valid", false,-1);
    tracep->declBit(c+558,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+558,"ram_real_last", false,-1);
    tracep->declBit(c+557,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+559,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+560,"io_enq_ready", false,-1);
    tracep->declBit(c+79,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+291,"io_deq_ready", false,-1);
    tracep->declBit(c+561,"io_deq_valid", false,-1);
    tracep->declBit(c+562,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+562,"ram_real_last", false,-1);
    tracep->declBit(c+561,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+563,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+564,"io_enq_ready", false,-1);
    tracep->declBit(c+80,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+292,"io_deq_ready", false,-1);
    tracep->declBit(c+565,"io_deq_valid", false,-1);
    tracep->declBit(c+566,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+566,"ram_real_last", false,-1);
    tracep->declBit(c+565,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+567,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+568,"io_enq_ready", false,-1);
    tracep->declBit(c+81,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+293,"io_deq_ready", false,-1);
    tracep->declBit(c+569,"io_deq_valid", false,-1);
    tracep->declBit(c+570,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+570,"ram_real_last", false,-1);
    tracep->declBit(c+569,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+571,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+572,"io_enq_ready", false,-1);
    tracep->declBit(c+82,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+294,"io_deq_ready", false,-1);
    tracep->declBit(c+573,"io_deq_valid", false,-1);
    tracep->declBit(c+574,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+574,"ram_real_last", false,-1);
    tracep->declBit(c+573,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+575,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+576,"io_enq_ready", false,-1);
    tracep->declBit(c+83,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+295,"io_deq_ready", false,-1);
    tracep->declBit(c+577,"io_deq_valid", false,-1);
    tracep->declBit(c+578,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+578,"ram_real_last", false,-1);
    tracep->declBit(c+577,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+579,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+580,"io_enq_ready", false,-1);
    tracep->declBit(c+84,"io_enq_valid", false,-1);
    tracep->declBit(c+344,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+296,"io_deq_ready", false,-1);
    tracep->declBit(c+581,"io_deq_valid", false,-1);
    tracep->declBit(c+582,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+582,"ram_real_last", false,-1);
    tracep->declBit(c+581,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+583,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+105,"reset", false,-1);
    tracep->declBit(c+340,"auto_master_out_awready", false,-1);
    tracep->declBit(c+87,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1238,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1086,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1239,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1087,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1088,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+341,"auto_master_out_wready", false,-1);
    tracep->declBit(c+88,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1089,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1090,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1240,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1196,"auto_master_out_bready", false,-1);
    tracep->declBit(c+216,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+342,"auto_master_out_arready", false,-1);
    tracep->declBit(c+89,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1241,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1091,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1242,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+990,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1243,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+90,"auto_master_out_rready", false,-1);
    tracep->declBit(c+219,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+1197,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1198,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+51,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+105,"reset", false,-1);
    tracep->declBit(c+1228,"io_interrupt", false,-1);
    tracep->declBit(c+340,"io_master_awready", false,-1);
    tracep->declBit(c+87,"io_master_awvalid", false,-1);
    tracep->declBus(c+1086,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1238,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1239,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1087,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1088,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+341,"io_master_wready", false,-1);
    tracep->declBit(c+88,"io_master_wvalid", false,-1);
    tracep->declBus(c+1089,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+1090,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1240,"io_master_wlast", false,-1);
    tracep->declBit(c+1196,"io_master_bready", false,-1);
    tracep->declBit(c+216,"io_master_bvalid", false,-1);
    tracep->declBus(c+218,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+217,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+342,"io_master_arready", false,-1);
    tracep->declBit(c+89,"io_master_arvalid", false,-1);
    tracep->declBus(c+1091,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1241,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1242,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+990,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1243,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+90,"io_master_rready", false,-1);
    tracep->declBit(c+219,"io_master_rvalid", false,-1);
    tracep->declBus(c+1198,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+1197,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+51,"io_master_rlast", false,-1);
    tracep->declBus(c+220,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1245,"io_slave_awready", false,-1);
    tracep->declBit(c+1228,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1246,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1247,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1242,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1248,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1249,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1250,"io_slave_wready", false,-1);
    tracep->declBit(c+1228,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1246,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1247,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1228,"io_slave_wlast", false,-1);
    tracep->declBit(c+1228,"io_slave_bready", false,-1);
    tracep->declBit(c+1251,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1252,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1253,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1254,"io_slave_arready", false,-1);
    tracep->declBit(c+1228,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1246,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1247,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1242,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1248,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1249,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1228,"io_slave_rready", false,-1);
    tracep->declBit(c+1255,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1256,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1257,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1258,"io_slave_rlast", false,-1);
    tracep->declBus(c+1259,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+991,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1111,"npc", false,-1, 31,0);
    tracep->declBus(c+898,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+992,"inst", false,-1, 31,0);
    tracep->declBit(c+993,"ifu_valid", false,-1);
    tracep->declBit(c+994,"ifu_arvalid", false,-1);
    tracep->declBit(c+995,"ifu_arready", false,-1);
    tracep->declBus(c+898,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+297,"ifu_rvalid", false,-1);
    tracep->declBit(c+991,"ifu_rready", false,-1);
    tracep->declBus(c+298,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+996,"reg_process", false,-1);
    tracep->declBus(c+997,"src1", false,-1, 4,0);
    tracep->declBus(c+998,"src2", false,-1, 4,0);
    tracep->declBus(c+999,"rd", false,-1, 4,0);
    tracep->declBus(c+1000,"imm", false,-1, 31,0);
    tracep->declBit(c+1001,"ebreaksig", false,-1);
    tracep->declBit(c+1002,"mretsig", false,-1);
    tracep->declBit(c+1003,"ecallsig", false,-1);
    tracep->declBit(c+1004,"regew", false,-1);
    tracep->declBit(c+1005,"memew", false,-1);
    tracep->declBit(c+1006,"memer", false,-1);
    tracep->declBit(c+1007,"muximm", false,-1);
    tracep->declBus(c+1008,"func3", false,-1, 2,0);
    tracep->declBus(c+1009,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1010,"func7", false,-1);
    tracep->declBit(c+1011,"btypebranch", false,-1);
    tracep->declBit(c+1012,"jalsig", false,-1);
    tracep->declBit(c+1013,"jalrsig", false,-1);
    tracep->declBit(c+1014,"auipcsig", false,-1);
    tracep->declBus(c+1015,"aluop", false,-1, 1,0);
    tracep->declBit(c+1016,"csrrw", false,-1);
    tracep->declBit(c+1017,"csrrs", false,-1);
    tracep->declBit(c+993,"idu_valid", false,-1);
    tracep->declBus(c+1018,"memmask", false,-1, 2,0);
    tracep->declBit(c+1019,"memsextsig", false,-1);
    tracep->declBus(c+299,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1112,"regout1", false,-1, 31,0);
    tracep->declBus(c+1113,"regout2", false,-1, 31,0);
    tracep->declBus(c+899,"mepc", false,-1, 31,0);
    tracep->declBus(c+900,"mtvec", false,-1, 31,0);
    tracep->declBit(c+991,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1114,"res", false,-1, 31,0);
    tracep->declBus(c+1115,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+993,"exu_valid", false,-1);
    tracep->declBit(c+991,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1206,"memvalid", false,-1);
    tracep->declBus(c+1020,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1020,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1021,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1022,"rready", false,-1, 1,0);
    tracep->declBus(c+1023,"bready", false,-1, 1,0);
    tracep->declBus(c+85,"bvalid", false,-1, 1,0);
    tracep->declBus(c+300,"rvalid", false,-1, 1,0);
    tracep->declBus(c+584,"awready", false,-1, 1,0);
    tracep->declBus(c+584,"wready", false,-1, 1,0);
    tracep->declBus(c+1024,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1207+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+301+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1116+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1118+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1120+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+303+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1122+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1025+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1260,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+105,"reset", false,-1);
    tracep->declBus(c+1020,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1020,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1021,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1022,"rready", false,-1, 1,0);
    tracep->declBus(c+1023,"bready", false,-1, 1,0);
    tracep->declBus(c+85,"bvalid", false,-1, 1,0);
    tracep->declBus(c+300,"rvalid", false,-1, 1,0);
    tracep->declBus(c+584,"awready", false,-1, 1,0);
    tracep->declBus(c+584,"wready", false,-1, 1,0);
    tracep->declBus(c+1024,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1124+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1126+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1128+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1130+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+305+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+307+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1132+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1027+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->declBit(c+87,"awvalid_out", false,-1);
    tracep->declBit(c+88,"wvalid_out", false,-1);
    tracep->declBit(c+89,"arvalid_out", false,-1);
    tracep->declBit(c+90,"rready_out", false,-1);
    tracep->declBit(c+1196,"bready_out", false,-1);
    tracep->declBit(c+216,"bvalid_in", false,-1);
    tracep->declBit(c+219,"rvalid_in", false,-1);
    tracep->declBit(c+341,"awready_in", false,-1);
    tracep->declBit(c+341,"wready_in", false,-1);
    tracep->declBit(c+342,"arready_in", false,-1);
    tracep->declBus(c+1091,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1086,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1089,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+1090,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+1197,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+218,"bresp_in", false,-1, 1,0);
    tracep->declBus(c+1087,"awsize_out", false,-1, 2,0);
    tracep->declBus(c+990,"arsize_out", false,-1, 2,0);
    tracep->declBit(c+585,"busy", false,-1);
    tracep->declBus(c+586,"giant", false,-1, 1,0);
    tracep->declBus(c+587,"i", false,-1, 31,0);
    tracep->declBus(c+1086,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1089,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1091,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1090,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1087,"awsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+990,"arsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1261,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+1008,"func3", false,-1, 2,0);
    tracep->declBit(c+1011,"btypebranch", false,-1);
    tracep->declBit(c+1010,"func7", false,-1);
    tracep->declBus(c+1015,"aluop", false,-1, 1,0);
    tracep->declBit(c+1013,"jalrsig", false,-1);
    tracep->declBit(c+1012,"jalsig", false,-1);
    tracep->declBus(c+1000,"imm", false,-1, 31,0);
    tracep->declBit(c+1007,"muximm", false,-1);
    tracep->declBus(c+1112,"regout1", false,-1, 31,0);
    tracep->declBus(c+1113,"regout2", false,-1, 31,0);
    tracep->declBus(c+898,"pc", false,-1, 31,0);
    tracep->declBit(c+1014,"auipcsig", false,-1);
    tracep->declBit(c+1002,"mretsig", false,-1);
    tracep->declBit(c+1003,"ecallsig", false,-1);
    tracep->declBus(c+900,"mtvec", false,-1, 31,0);
    tracep->declBus(c+899,"mepc", false,-1, 31,0);
    tracep->declBit(c+993,"valid_from", false,-1);
    tracep->declBit(c+991,"ready_from", false,-1);
    tracep->declBus(c+1114,"res", false,-1, 31,0);
    tracep->declBus(c+1111,"npc", false,-1, 31,0);
    tracep->declBus(c+1115,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+993,"valid_to", false,-1);
    tracep->declBit(c+991,"ready_to", false,-1);
    tracep->declBus(c+901,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1134,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+1029,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1135,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1136,"zero", false,-1);
    tracep->declBit(c+1137,"signal", false,-1);
    tracep->declBit(c+1138,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1112,"A", false,-1, 31,0);
    tracep->declBus(c+1135,"B", false,-1, 31,0);
    tracep->declBus(c+1029,"op", false,-1, 4,0);
    tracep->declBus(c+1114,"res", false,-1, 31,0);
    tracep->declBit(c+1136,"zero", false,-1);
    tracep->declBit(c+1137,"signal", false,-1);
    tracep->declBit(c+1138,"carry", false,-1);
    tracep->declBit(c+1030,"addsig", false,-1);
    tracep->declBit(c+1031,"logsig", false,-1);
    tracep->declBit(c+1032,"shfsig", false,-1);
    tracep->declBit(c+1033,"sltsig", false,-1);
    tracep->declBit(c+1138,"carry_tmp", false,-1);
    tracep->declBit(c+1034,"type_I", false,-1);
    tracep->declBus(c+1139,"logres", false,-1, 31,0);
    tracep->declBus(c+1140,"addres", false,-1, 31,0);
    tracep->declBit(c+1141,"addzero", false,-1);
    tracep->declBus(c+1142,"shfres", false,-1, 31,0);
    tracep->declBus(c+1143,"sltres", false,-1, 31,0);
    tracep->declBus(c+1112,"A_s", false,-1, 31,0);
    tracep->declBus(c+1135,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+1008,"func3", false,-1, 2,0);
    tracep->declBit(c+1010,"func7", false,-1);
    tracep->declBus(c+1015,"aluop", false,-1, 1,0);
    tracep->declBit(c+1013,"jalrsig", false,-1);
    tracep->declBus(c+1029,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+1034,"type_I", false,-1);
    tracep->declBit(c+1035,"type_B", false,-1);
    tracep->declBit(c+1036,"type_R", false,-1);
    tracep->declBit(c+1037,"addsig", false,-1);
    tracep->declBus(c+1038,"branchop", false,-1, 3,0);
    tracep->declBus(c+1039,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+1011,"btypebranch", false,-1);
    tracep->declBus(c+1008,"func3", false,-1, 2,0);
    tracep->declBit(c+1136,"zero", false,-1);
    tracep->declBit(c+1137,"signal", false,-1);
    tracep->declBit(c+1138,"carry", false,-1);
    tracep->declBus(c+1114,"res", false,-1, 31,0);
    tracep->declBus(c+901,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1134,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+1012,"jalsig", false,-1);
    tracep->declBit(c+1013,"jalrsig", false,-1);
    tracep->declBit(c+1014,"auipcsig", false,-1);
    tracep->declBit(c+1002,"mretsig", false,-1);
    tracep->declBit(c+1003,"ecallsig", false,-1);
    tracep->declBus(c+900,"mtvec", false,-1, 31,0);
    tracep->declBus(c+899,"mepc", false,-1, 31,0);
    tracep->declBus(c+1111,"npc", false,-1, 31,0);
    tracep->declBus(c+1115,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1260,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1262,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1263,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1135,"out", false,-1, 31,0);
    tracep->declBus(c+1007,"key", false,-1, 0,0);
    tracep->declArray(c+1063,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1260,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1262,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1263,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1264,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1135,"out", false,-1, 31,0);
    tracep->declBus(c+1007,"key", false,-1, 0,0);
    tracep->declBus(c+1246,"default_out", false,-1, 31,0);
    tracep->declArray(c+1063,"lut", false,-1, 65,0);
    tracep->declBus(c+1265,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1066+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1070+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1144,"lut_out", false,-1, 31,0);
    tracep->declBit(c+1040,"hit", false,-1);
    tracep->declBus(c+1266,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+898,"pc", false,-1, 31,0);
    tracep->declBus(c+901,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+898,"pc", false,-1, 31,0);
    tracep->declBus(c+1000,"imm", false,-1, 31,0);
    tracep->declBus(c+1134,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+992,"inst", false,-1, 31,0);
    tracep->declBit(c+993,"valid_from", false,-1);
    tracep->declBit(c+991,"ready_from", false,-1);
    tracep->declBit(c+1001,"ebreaksig", false,-1);
    tracep->declBit(c+1003,"ecallsig", false,-1);
    tracep->declBit(c+1002,"mretsig", false,-1);
    tracep->declBus(c+1000,"imm", false,-1, 31,0);
    tracep->declBus(c+1008,"func3", false,-1, 2,0);
    tracep->declBit(c+1010,"func7", false,-1);
    tracep->declBus(c+997,"src1", false,-1, 4,0);
    tracep->declBus(c+998,"src2", false,-1, 4,0);
    tracep->declBus(c+999,"rd", false,-1, 4,0);
    tracep->declBit(c+1005,"memew", false,-1);
    tracep->declBus(c+1009,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1006,"memer", false,-1);
    tracep->declBit(c+1004,"regew", false,-1);
    tracep->declBit(c+1007,"muximm", false,-1);
    tracep->declBit(c+1011,"btypebranch", false,-1);
    tracep->declBit(c+1013,"jalrsig", false,-1);
    tracep->declBit(c+1012,"jalsig", false,-1);
    tracep->declBus(c+1015,"aluop", false,-1, 1,0);
    tracep->declBit(c+1014,"auipcsig", false,-1);
    tracep->declBit(c+1016,"csrrw", false,-1);
    tracep->declBit(c+1017,"csrrs", false,-1);
    tracep->declBit(c+993,"valid_to", false,-1);
    tracep->declBit(c+991,"ready_to", false,-1);
    tracep->declBus(c+1018,"memmask", false,-1, 2,0);
    tracep->declBit(c+1019,"memsextsig", false,-1);
    tracep->declBit(c+1001,"ebreak", false,-1);
    tracep->declBit(c+1003,"ecall", false,-1);
    tracep->declBit(c+1002,"mret", false,-1);
    tracep->declBus(c+1008,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+1010,"func7bridge", false,-1);
    tracep->declBus(c+1041,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+992,"inst", false,-1, 31,0);
    tracep->declBit(c+1001,"ebreaksig", false,-1);
    tracep->declBit(c+1003,"ecallsig", false,-1);
    tracep->declBit(c+1002,"mretsig", false,-1);
    tracep->declBus(c+1000,"imm", false,-1, 31,0);
    tracep->declBus(c+1041,"opcode", false,-1, 6,0);
    tracep->declBus(c+1008,"func3", false,-1, 2,0);
    tracep->declBit(c+1010,"func7", false,-1);
    tracep->declBus(c+997,"src1", false,-1, 4,0);
    tracep->declBus(c+998,"src2", false,-1, 4,0);
    tracep->declBus(c+999,"rd", false,-1, 4,0);
    tracep->declBus(c+1018,"memmask", false,-1, 2,0);
    tracep->declBit(c+1019,"memsextsig", false,-1);
    tracep->declBit(c+1042,"type_I", false,-1);
    tracep->declBit(c+1043,"type_R", false,-1);
    tracep->declBit(c+1044,"type_U", false,-1);
    tracep->declBit(c+1005,"type_S", false,-1);
    tracep->declBit(c+1012,"type_J", false,-1);
    tracep->declBit(c+1011,"type_B", false,-1);
    tracep->declBus(c+1045,"I_imm", false,-1, 31,0);
    tracep->declBus(c+1046,"U_imm", false,-1, 31,0);
    tracep->declBus(c+1047,"S_imm", false,-1, 31,0);
    tracep->declBus(c+1048,"J_imm", false,-1, 31,0);
    tracep->declBus(c+1049,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+1041,"opcode", false,-1, 6,0);
    tracep->declBus(c+1008,"func3", false,-1, 2,0);
    tracep->declBit(c+1010,"func7", false,-1);
    tracep->declBit(c+1001,"ebreaksig", false,-1);
    tracep->declBit(c+1003,"ecallsig", false,-1);
    tracep->declBit(c+1002,"mretsig", false,-1);
    tracep->declBit(c+1005,"memew", false,-1);
    tracep->declBus(c+1009,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1006,"memer", false,-1);
    tracep->declBit(c+1004,"regew", false,-1);
    tracep->declBit(c+1007,"muximm", false,-1);
    tracep->declBit(c+1011,"btypebranch", false,-1);
    tracep->declBit(c+1013,"jalrsig", false,-1);
    tracep->declBit(c+1012,"jalsig", false,-1);
    tracep->declBus(c+1015,"aluop", false,-1, 1,0);
    tracep->declBit(c+1014,"auipcsig", false,-1);
    tracep->declBit(c+1016,"csrrw", false,-1);
    tracep->declBit(c+1017,"csrrs", false,-1);
    tracep->declBit(c+1042,"type_I", false,-1);
    tracep->declBit(c+1043,"type_R", false,-1);
    tracep->declBit(c+1044,"type_U", false,-1);
    tracep->declBit(c+1005,"type_S", false,-1);
    tracep->declBit(c+1012,"type_J", false,-1);
    tracep->declBit(c+1011,"type_B", false,-1);
    tracep->declBit(c+1006,"load", false,-1);
    tracep->declBit(c+1005,"store", false,-1);
    tracep->declBit(c+1050,"regwritepc", false,-1);
    tracep->declBit(c+1006,"regwritemem", false,-1);
    tracep->declBit(c+1051,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+105,"rst", false,-1);
    tracep->declBus(c+1111,"npc", false,-1, 31,0);
    tracep->declBit(c+991,"ready", false,-1);
    tracep->declBus(c+898,"pc", false,-1, 31,0);
    tracep->declBus(c+992,"inst", false,-1, 31,0);
    tracep->declBit(c+993,"valid", false,-1);
    tracep->declBit(c+996,"regprocess", false,-1);
    tracep->declBit(c+994,"arvalid", false,-1);
    tracep->declBit(c+995,"arready", false,-1);
    tracep->declBus(c+898,"araddr", false,-1, 31,0);
    tracep->declBit(c+297,"rvalid", false,-1);
    tracep->declBit(c+991,"rready", false,-1);
    tracep->declBus(c+298,"rdata", false,-1, 31,0);
    tracep->declBus(c+898,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1052,"infetch_ready", false,-1);
    tracep->declBus(c+1053,"state", false,-1, 2,0);
    tracep->declBus(c+992,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBus(c+1111,"npc", false,-1, 31,0);
    tracep->declBit(c+105,"rst", false,-1);
    tracep->declBit(c+1052,"ready_from", false,-1);
    tracep->declBus(c+898,"pcout", false,-1, 31,0);
    tracep->declBus(c+1267,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+105,"rst", false,-1);
    tracep->declBit(c+1209,"ew", false,-1);
    tracep->declBus(c+999,"addr", false,-1, 4,0);
    tracep->declBus(c+997,"src1", false,-1, 4,0);
    tracep->declBus(c+998,"src2", false,-1, 4,0);
    tracep->declBus(c+1054,"csr", false,-1, 11,0);
    tracep->declBus(c+299,"data", false,-1, 31,0);
    tracep->declBit(c+1016,"csrrw", false,-1);
    tracep->declBit(c+1017,"csrrs", false,-1);
    tracep->declBit(c+1003,"ecallsig", false,-1);
    tracep->declBit(c+993,"valid", false,-1);
    tracep->declBus(c+1112,"regout1", false,-1, 31,0);
    tracep->declBus(c+1113,"regout2", false,-1, 31,0);
    tracep->declBus(c+899,"mepc", false,-1, 31,0);
    tracep->declBus(c+900,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+902+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+934+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1055,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+309,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1268,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1269,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1270,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1055,"out", false,-1, 2,0);
    tracep->declBus(c+1054,"key", false,-1, 11,0);
    tracep->declArray(c+1271,"lut", false,-1, 89,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1268,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1269,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1270,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1264,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1055,"out", false,-1, 2,0);
    tracep->declBus(c+1054,"key", false,-1, 11,0);
    tracep->declBus(c+1248,"default_out", false,-1, 2,0);
    tracep->declArray(c+1271,"lut", false,-1, 89,0);
    tracep->declBus(c+1274,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 14,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+9+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+15+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1056,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1057,"hit", false,-1);
    tracep->declBus(c+1275,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+105,"rst", false,-1);
    tracep->declBit(c+1210,"ew", false,-1);
    tracep->declBit(c+1016,"csrrw", false,-1);
    tracep->declBit(c+1017,"csrrs", false,-1);
    tracep->declBit(c+1003,"ecall", false,-1);
    tracep->declBus(c+1055,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+999,"addr", false,-1, 4,0);
    tracep->declBus(c+309,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+940+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+972+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+978,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBus(c+1114,"res", false,-1, 31,0);
    tracep->declBus(c+1113,"regout2", false,-1, 31,0);
    tracep->declBit(c+1005,"memew", false,-1);
    tracep->declBit(c+1006,"memer", false,-1);
    tracep->declBus(c+1000,"imm", false,-1, 31,0);
    tracep->declBus(c+1115,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+1009,"muxsig", false,-1, 2,0);
    tracep->declBit(c+993,"valid_from", false,-1);
    tracep->declBus(c+1018,"memmask", false,-1, 2,0);
    tracep->declBit(c+1019,"memsextsig", false,-1);
    tracep->declBus(c+299,"regwrite", false,-1, 31,0);
    tracep->declBit(c+991,"ready_to", false,-1);
    tracep->declBit(c+1206,"memvalid", false,-1);
    tracep->declBit(c+1058,"awvalid", false,-1);
    tracep->declBit(c+588,"awready", false,-1);
    tracep->declBus(c+1114,"awaddr", false,-1, 31,0);
    tracep->declBit(c+1058,"wvalid", false,-1);
    tracep->declBit(c+588,"wready", false,-1);
    tracep->declBus(c+1145,"wdata", false,-1, 31,0);
    tracep->declBus(c+1146,"wstrb", false,-1, 3,0);
    tracep->declBit(c+86,"bvalid", false,-1);
    tracep->declBit(c+1005,"bready", false,-1);
    tracep->declBus(c+310,"bresp", false,-1, 1,0);
    tracep->declBit(c+1211,"arvalid", false,-1);
    tracep->declBit(c+1059,"arready", false,-1);
    tracep->declBus(c+1114,"araddr", false,-1, 31,0);
    tracep->declBit(c+311,"rvalid", false,-1);
    tracep->declBit(c+1006,"rready", false,-1);
    tracep->declBus(c+312,"rdata", false,-1, 31,0);
    tracep->declBus(c+1147,"awsize", false,-1, 2,0);
    tracep->declBus(c+1060,"arsize", false,-1, 2,0);
    tracep->declBus(c+1088,"awburst", false,-1, 1,0);
    tracep->declBus(c+589,"state", false,-1, 1,0);
    tracep->declBus(c+313,"memread", false,-1, 31,0);
    tracep->declBus(c+1148,"wdata_offset", false,-1, 1,0);
    tracep->declBit(c+1212,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+312,"data", false,-1, 31,0);
    tracep->declBus(c+1018,"memmask", false,-1, 2,0);
    tracep->declBit(c+1019,"memsextsig", false,-1);
    tracep->declBus(c+1149,"addr_offset", false,-1, 1,0);
    tracep->declBus(c+313,"read", false,-1, 31,0);
    tracep->declBus(c+314,"read_u", false,-1, 31,0);
    tracep->declBus(c+315,"read_s", false,-1, 31,0);
    tracep->declBus(c+316,"read_sb", false,-1, 31,0);
    tracep->declBus(c+317,"read_sh", false,-1, 31,0);
    tracep->declBus(c+318,"byte_data", false,-1, 7,0);
    tracep->declBus(c+319,"halfword_data", false,-1, 15,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1276,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1263,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+318,"input_number", false,-1, 7,0);
    tracep->declBus(c+316,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1277,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1263,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+319,"input_number", false,-1, 15,0);
    tracep->declBus(c+317,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1278,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1270,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1263,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+299,"out", false,-1, 31,0);
    tracep->declBus(c+1009,"key", false,-1, 2,0);
    tracep->declBus(c+1264,"default_out", false,-1, 31,0);
    tracep->declArray(c+106,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1278,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1270,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1263,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1262,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+299,"out", false,-1, 31,0);
    tracep->declBus(c+1009,"key", false,-1, 2,0);
    tracep->declBus(c+1264,"default_out", false,-1, 31,0);
    tracep->declArray(c+106,"lut", false,-1, 139,0);
    tracep->declBus(c+1279,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+111+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+21+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+119+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+320,"lut_out", false,-1, 31,0);
    tracep->declBit(c+321,"hit", false,-1);
    tracep->declBus(c+1280,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("strbcontol ");
    tracep->declBus(c+1114,"awaddr", false,-1, 31,0);
    tracep->declBus(c+1018,"wirtelen", false,-1, 2,0);
    tracep->declBus(c+1146,"wstrb", false,-1, 3,0);
    tracep->declBus(c+1147,"awsize", false,-1, 2,0);
    tracep->declBus(c+1148,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1088,"awburst", false,-1, 1,0);
    tracep->declBus(c+1260,"device_num", false,-1, 31,0);
    tracep->declBit(c+1150,"inuart", false,-1);
    tracep->declBit(c+1151,"insram", false,-1);
    tracep->declBit(c+1152,"inflash", false,-1);
    tracep->declBit(c+1153,"inspi", false,-1);
    tracep->declBit(c+1154,"inpsram", false,-1);
    tracep->declBus(c+1155,"bus_size", false,-1, 1,0);
    tracep->declBus(c+1061,"awsize_general", false,-1, 2,0);
    tracep->declBus(c+1062,"wstrb_general", false,-1, 3,0);
    tracep->declBus(c+1281,"wstrb_byte", false,-1, 3,0);
    tracep->declBus(c+1282,"wstrb_halfword", false,-1, 3,0);
    tracep->declBus(c+1156,"wstrb_word", false,-1, 3,0);
    tracep->declBus(c+1157,"mux", false,-1, 4,0);
    tracep->pushNamePrefix("len_mux ");
    tracep->declBus(c+1270,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1260,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1270,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1147,"out", false,-1, 2,0);
    tracep->declBus(c+1155,"key", false,-1, 1,0);
    tracep->declBus(c+1061,"default_out", false,-1, 2,0);
    tracep->declBus(c+1283,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1270,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1260,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1270,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1262,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1147,"out", false,-1, 2,0);
    tracep->declBus(c+1155,"key", false,-1, 1,0);
    tracep->declBus(c+1061,"default_out", false,-1, 2,0);
    tracep->declBus(c+1283,"lut", false,-1, 14,0);
    tracep->declBus(c+1284,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+25+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+28+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+31+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1158,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1159,"hit", false,-1);
    tracep->declBus(c+1285,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("type_mux ");
    tracep->declBus(c+1260,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1260,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1260,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1155,"out", false,-1, 1,0);
    tracep->declBus(c+1160,"key", false,-1, 1,0);
    tracep->declBus(c+1249,"default_out", false,-1, 1,0);
    tracep->declBus(c+1286,"lut", false,-1, 7,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1260,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1260,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1260,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1262,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1155,"out", false,-1, 1,0);
    tracep->declBus(c+1160,"key", false,-1, 1,0);
    tracep->declBus(c+1249,"default_out", false,-1, 1,0);
    tracep->declBus(c+1286,"lut", false,-1, 7,0);
    tracep->declBus(c+1278,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+34+i*1,"pair_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+36+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+38+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1161,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1162,"hit", false,-1);
    tracep->declBus(c+1266,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wstrb_mux ");
    tracep->declBus(c+1278,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1260,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1278,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1146,"out", false,-1, 3,0);
    tracep->declBus(c+1155,"key", false,-1, 1,0);
    tracep->declBus(c+1072,"lut", false,-1, 23,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1278,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1260,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1278,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1264,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1146,"out", false,-1, 3,0);
    tracep->declBus(c+1155,"key", false,-1, 1,0);
    tracep->declBus(c+1247,"default_out", false,-1, 3,0);
    tracep->declBus(c+1072,"lut", false,-1, 23,0);
    tracep->declBus(c+1268,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1073+i*1,"pair_list", true,(i+0), 5,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+40+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1077+i*1,"data_list", true,(i+0), 3,0);
    }
    tracep->declBus(c+1163,"lut_out", false,-1, 3,0);
    tracep->declBit(c+1164,"hit", false,-1);
    tracep->declBus(c+1280,"i", false,-1, 31,0);
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"io_d", false,-1);
    tracep->declBit(c+590,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"io_d", false,-1);
    tracep->declBit(c+590,"io_q", false,-1);
    tracep->declBit(c+590,"sync_0", false,-1);
    tracep->declBit(c+591,"sync_1", false,-1);
    tracep->declBit(c+592,"sync_2", false,-1);
    tracep->declBit(c+593,"sync_3", false,-1);
    tracep->declBit(c+594,"sync_4", false,-1);
    tracep->declBit(c+595,"sync_5", false,-1);
    tracep->declBit(c+596,"sync_6", false,-1);
    tracep->declBit(c+597,"sync_7", false,-1);
    tracep->declBit(c+598,"sync_8", false,-1);
    tracep->declBit(c+599,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+134,"auto_in_psel", false,-1);
    tracep->declBit(c+47,"auto_in_penable", false,-1);
    tracep->declBit(c+125,"auto_in_pwrite", false,-1);
    tracep->declBus(c+133,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1227,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1235,"auto_in_pready", false,-1);
    tracep->declBit(c+1236,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1237,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1168,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1169,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1170,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1171,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1172,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1173,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1174,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1175,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1176,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1177,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+154,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+134,"in_psel", false,-1);
    tracep->declBit(c+47,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1235,"in_pready", false,-1);
    tracep->declBus(c+1237,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1236,"in_pslverr", false,-1);
    tracep->declBus(c+1168,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1169,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1170,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1171,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1172,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1173,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1174,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1175,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1176,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1177,"gpio_seg_7", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+132,"auto_in_psel", false,-1);
    tracep->declBit(c+46,"auto_in_penable", false,-1);
    tracep->declBit(c+125,"auto_in_pwrite", false,-1);
    tracep->declBus(c+133,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1227,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1232,"auto_in_pready", false,-1);
    tracep->declBit(c+1233,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1234,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1178,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1179,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+154,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+132,"in_psel", false,-1);
    tracep->declBit(c+46,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1232,"in_pready", false,-1);
    tracep->declBus(c+1234,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1233,"in_pslverr", false,-1);
    tracep->declBit(c+1178,"ps2_clk", false,-1);
    tracep->declBit(c+1179,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+1202,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1203,"auto_in_wvalid", false,-1);
    tracep->declBit(c+400,"auto_in_arready", false,-1);
    tracep->declBit(c+1204,"auto_in_arvalid", false,-1);
    tracep->declBus(c+330,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1102,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1205,"auto_in_rready", false,-1);
    tracep->declBit(c+401,"auto_in_rvalid", false,-1);
    tracep->declBus(c+402,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+403,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+401,"state", false,-1);
    tracep->declBus(c+403,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+402,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1165,"raddr", false,-1, 31,0);
    tracep->declBit(c+155,"ren", false,-1);
    tracep->declBus(c+156,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+135,"auto_in_psel", false,-1);
    tracep->declBit(c+48,"auto_in_penable", false,-1);
    tracep->declBit(c+125,"auto_in_pwrite", false,-1);
    tracep->declBus(c+123,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1192,"auto_in_pready", false,-1);
    tracep->declBit(c+1228,"auto_in_pslverr", false,-1);
    tracep->declBus(c+327,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+209,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+210,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+1190,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+123,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+135,"in_psel", false,-1);
    tracep->declBit(c+48,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1192,"in_pready", false,-1);
    tracep->declBus(c+327,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1228,"in_pslverr", false,-1);
    tracep->declBit(c+209,"qspi_sck", false,-1);
    tracep->declBit(c+210,"qspi_ce_n", false,-1);
    tracep->declBus(c+1190,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+1190,"din", false,-1, 3,0);
    tracep->declBus(c+322,"dout", false,-1, 3,0);
    tracep->declBus(c+323,"douten", false,-1, 3,0);
    tracep->declBit(c+1213,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1166,"clk_i", false,-1);
    tracep->declBit(c+1167,"rst_i", false,-1);
    tracep->declBus(c+123,"adr_i", false,-1, 31,0);
    tracep->declBus(c+126,"dat_i", false,-1, 31,0);
    tracep->declBus(c+327,"dat_o", false,-1, 31,0);
    tracep->declBus(c+127,"sel_i", false,-1, 3,0);
    tracep->declBit(c+135,"cyc_i", false,-1);
    tracep->declBit(c+135,"stb_i", false,-1);
    tracep->declBit(c+1213,"ack_o", false,-1);
    tracep->declBit(c+125,"we_i", false,-1);
    tracep->declBit(c+209,"sck", false,-1);
    tracep->declBit(c+210,"ce_n", false,-1);
    tracep->declBus(c+1190,"din", false,-1, 3,0);
    tracep->declBus(c+322,"dout", false,-1, 3,0);
    tracep->declBus(c+323,"douten", false,-1, 3,0);
    tracep->declBus(c+1287,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1288,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+673,"mr_sck", false,-1);
    tracep->declBit(c+674,"mr_ce_n", false,-1);
    tracep->declBus(c+1190,"mr_din", false,-1, 3,0);
    tracep->declBus(c+675,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+676,"mr_doe", false,-1);
    tracep->declBit(c+892,"mw_sck", false,-1);
    tracep->declBit(c+893,"mw_ce_n", false,-1);
    tracep->declBus(c+1190,"mw_din", false,-1, 3,0);
    tracep->declBus(c+1214,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+894,"mw_doe", false,-1);
    tracep->declBit(c+195,"mr_rd", false,-1);
    tracep->declBit(c+677,"mr_done", false,-1);
    tracep->declBit(c+196,"mw_wr", false,-1);
    tracep->declBit(c+1215,"mw_done", false,-1);
    tracep->declBit(c+135,"wb_valid", false,-1);
    tracep->declBit(c+157,"wb_we", false,-1);
    tracep->declBit(c+158,"wb_re", false,-1);
    tracep->declBit(c+678,"state", false,-1);
    tracep->declBit(c+324,"nstate", false,-1);
    tracep->declBus(c+159,"size", false,-1, 2,0);
    tracep->declBus(c+160,"byte0", false,-1, 7,0);
    tracep->declBus(c+161,"byte1", false,-1, 7,0);
    tracep->declBus(c+162,"byte2", false,-1, 7,0);
    tracep->declBus(c+163,"byte3", false,-1, 7,0);
    tracep->declBus(c+164,"wdata", false,-1, 31,0);
    tracep->declBit(c+600,"qpi_valid", false,-1);
    tracep->declBit(c+601,"qpi_ce_n", false,-1);
    tracep->declBus(c+1190,"qpi_din", false,-1, 3,0);
    tracep->declBus(c+602,"qpi_dout", false,-1, 3,0);
    tracep->declBit(c+1216,"qpi_sck", false,-1);
    tracep->declBit(c+603,"qpi_doe", false,-1);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1217,"rst_n", false,-1);
    tracep->declBus(c+165,"addr", false,-1, 23,0);
    tracep->declBit(c+195,"rd", false,-1);
    tracep->declBus(c+1289,"size", false,-1, 2,0);
    tracep->declBit(c+677,"done", false,-1);
    tracep->declBus(c+327,"line", false,-1, 31,0);
    tracep->declBit(c+673,"sck", false,-1);
    tracep->declBit(c+674,"ce_n", false,-1);
    tracep->declBus(c+1190,"din", false,-1, 3,0);
    tracep->declBus(c+675,"dout", false,-1, 3,0);
    tracep->declBit(c+676,"douten", false,-1);
    tracep->declBus(c+1287,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1288,"READ", false,-1, 0,0);
    tracep->declBus(c+1290,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+679,"state", false,-1);
    tracep->declBit(c+197,"nstate", false,-1);
    tracep->declBus(c+680,"counter", false,-1, 7,0);
    tracep->declBus(c+681,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+604+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1291,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+682,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"rst_n", false,-1);
    tracep->declBus(c+166,"addr", false,-1, 23,0);
    tracep->declBus(c+164,"line", false,-1, 31,0);
    tracep->declBus(c+159,"size", false,-1, 2,0);
    tracep->declBit(c+196,"wr", false,-1);
    tracep->declBit(c+1215,"done", false,-1);
    tracep->declBit(c+892,"sck", false,-1);
    tracep->declBit(c+893,"ce_n", false,-1);
    tracep->declBus(c+1190,"din", false,-1, 3,0);
    tracep->declBus(c+1214,"dout", false,-1, 3,0);
    tracep->declBit(c+894,"douten", false,-1);
    tracep->declBus(c+1287,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1288,"WRITE", false,-1, 0,0);
    tracep->declBus(c+167,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+895,"state", false,-1);
    tracep->declBit(c+325,"nstate", false,-1);
    tracep->declBus(c+896,"counter", false,-1, 7,0);
    tracep->declBus(c+897,"saddr", false,-1, 23,0);
    tracep->declBus(c+1292,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("QPI ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"rst", false,-1);
    tracep->declBit(c+600,"valid", false,-1);
    tracep->declBit(c+1216,"sck", false,-1);
    tracep->declBit(c+601,"ce_n", false,-1);
    tracep->declBus(c+1190,"din", false,-1, 3,0);
    tracep->declBus(c+602,"dout", false,-1, 3,0);
    tracep->declBit(c+603,"douten", false,-1);
    tracep->declBit(c+608,"finish", false,-1);
    tracep->declBus(c+1293,"H_35", false,-1, 7,0);
    tracep->declBus(c+609,"counter", false,-1, 2,0);
    tracep->declBus(c+610,"state", false,-1, 1,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+129,"auto_in_psel", false,-1);
    tracep->declBit(c+44,"auto_in_penable", false,-1);
    tracep->declBit(c+125,"auto_in_pwrite", false,-1);
    tracep->declBus(c+123,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+671,"auto_in_pready", false,-1);
    tracep->declBit(c+1228,"auto_in_pslverr", false,-1);
    tracep->declBus(c+672,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1191,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+662,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+663,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+664,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+665,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+666,"sdram_bundle_we", false,-1);
    tracep->declBus(c+667,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+668,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+669,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+670,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+123,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+129,"in_psel", false,-1);
    tracep->declBit(c+44,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+671,"in_pready", false,-1);
    tracep->declBus(c+672,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1228,"in_pslverr", false,-1);
    tracep->declBit(c+1191,"sdram_clk", false,-1);
    tracep->declBit(c+662,"sdram_cke", false,-1);
    tracep->declBit(c+663,"sdram_cs", false,-1);
    tracep->declBit(c+664,"sdram_ras", false,-1);
    tracep->declBit(c+665,"sdram_cas", false,-1);
    tracep->declBit(c+666,"sdram_we", false,-1);
    tracep->declBus(c+667,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+668,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+669,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+670,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+683,"sdram_dout_en", false,-1);
    tracep->declBus(c+684,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+611,"state", false,-1, 1,0);
    tracep->declBit(c+685,"req_accept", false,-1);
    tracep->declBit(c+168,"is_read", false,-1);
    tracep->declBit(c+169,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1166,"clk_i", false,-1);
    tracep->declBit(c+1167,"rst_i", false,-1);
    tracep->declBus(c+170,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+168,"inport_rd_i", false,-1);
    tracep->declBus(c+1242,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+123,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+126,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+670,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+685,"inport_accept_o", false,-1);
    tracep->declBit(c+671,"inport_ack_o", false,-1);
    tracep->declBit(c+1228,"inport_error_o", false,-1);
    tracep->declBus(c+672,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1191,"sdram_clk_o", false,-1);
    tracep->declBit(c+662,"sdram_cke_o", false,-1);
    tracep->declBit(c+663,"sdram_cs_o", false,-1);
    tracep->declBit(c+664,"sdram_ras_o", false,-1);
    tracep->declBit(c+665,"sdram_cas_o", false,-1);
    tracep->declBit(c+666,"sdram_we_o", false,-1);
    tracep->declBus(c+669,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+667,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+668,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+684,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+683,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1294,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1295,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1296,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1260,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1260,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1260,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1278,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1297,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1298,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1299,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1300,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1278,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1301,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1302,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1303,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1304,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1305,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1306,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1281,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1247,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1307,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1278,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1247,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1281,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1306,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1302,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1304,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1303,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1305,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1301,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1308,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1309,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1310,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1310,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1277,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1310,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1260,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1260,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1268,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+123,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+170,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+168,"ram_rd_w", false,-1);
    tracep->declBit(c+685,"ram_accept_w", false,-1);
    tracep->declBus(c+126,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+672,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+671,"ram_ack_w", false,-1);
    tracep->declBit(c+171,"ram_req_w", false,-1);
    tracep->declBus(c+686,"command_q", false,-1, 3,0);
    tracep->declBus(c+667,"addr_q", false,-1, 12,0);
    tracep->declBus(c+684,"data_q", false,-1, 15,0);
    tracep->declBit(c+687,"data_rd_en_q", false,-1);
    tracep->declBus(c+669,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+662,"cke_q", false,-1);
    tracep->declBus(c+668,"bank_q", false,-1, 1,0);
    tracep->declBus(c+688,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+689,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+670,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+690,"refresh_q", false,-1);
    tracep->declBus(c+691,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+692+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+696,"state_q", false,-1, 3,0);
    tracep->declBus(c+198,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+199,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+697,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+698,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+172,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+173,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+174,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1278,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+699,"delay_q", false,-1, 3,0);
    tracep->declBus(c+200,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1311,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+700,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+701,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+702,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+703,"idx", false,-1, 31,0);
    tracep->declBus(c+704,"rd_q", false,-1, 3,0);
    tracep->declBit(c+671,"ack_q", false,-1);
    tracep->declArray(c+705,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+139,"auto_in_psel", false,-1);
    tracep->declBit(c+49,"auto_in_penable", false,-1);
    tracep->declBit(c+125,"auto_in_pwrite", false,-1);
    tracep->declBus(c+131,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1227,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1194,"auto_in_pready", false,-1);
    tracep->declBit(c+1228,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1195,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+660,"spi_bundle_sck", false,-1);
    tracep->declBus(c+661,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1188,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1189,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1267,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1312,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1276,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+175,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+139,"in_psel", false,-1);
    tracep->declBit(c+49,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1194,"in_pready", false,-1);
    tracep->declBus(c+1195,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1228,"in_pslverr", false,-1);
    tracep->declBit(c+660,"spi_sck", false,-1);
    tracep->declBus(c+661,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1188,"spi_mosi", false,-1);
    tracep->declBit(c+1189,"spi_miso", false,-1);
    tracep->declBit(c+708,"spi_irq_out", false,-1);
    tracep->declBus(c+612,"state", false,-1, 2,0);
    tracep->declBit(c+613,"penable", false,-1);
    tracep->declBit(c+176,"is_xip_access", false,-1);
    tracep->declBus(c+614,"xip_paddr", false,-1, 4,0);
    tracep->declBus(c+177,"xip_pwdata", false,-1, 31,0);
    tracep->declBus(c+178,"xip_pstrb", false,-1, 3,0);
    tracep->declBit(c+615,"xip_pwirte", false,-1);
    tracep->declBit(c+709,"apb_pready", false,-1);
    tracep->declBus(c+179,"apb_addr", false,-1, 4,0);
    tracep->declBus(c+180,"apb_pwdata", false,-1, 31,0);
    tracep->declBus(c+178,"apb_pstrb", false,-1, 3,0);
    tracep->declBit(c+181,"apb_penable", false,-1);
    tracep->declBit(c+139,"apb_psel", false,-1);
    tracep->declBit(c+182,"apb_pwrite", false,-1);
    tracep->declBus(c+710,"apb_prdata", false,-1, 31,0);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1262,"Tp", false,-1, 31,0);
    tracep->declBit(c+1166,"wb_clk_i", false,-1);
    tracep->declBit(c+1167,"wb_rst_i", false,-1);
    tracep->declBus(c+179,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+180,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+710,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+178,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+182,"wb_we_i", false,-1);
    tracep->declBit(c+139,"wb_stb_i", false,-1);
    tracep->declBit(c+181,"wb_cyc_i", false,-1);
    tracep->declBit(c+709,"wb_ack_o", false,-1);
    tracep->declBit(c+1228,"wb_err_o", false,-1);
    tracep->declBit(c+708,"wb_int_o", false,-1);
    tracep->declBus(c+661,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+660,"sclk_pad_o", false,-1);
    tracep->declBit(c+1188,"mosi_pad_o", false,-1);
    tracep->declBit(c+1189,"miso_pad_i", false,-1);
    tracep->declBus(c+711,"divider", false,-1, 15,0);
    tracep->declBus(c+712,"ctrl", false,-1, 13,0);
    tracep->declBus(c+713,"ss", false,-1, 7,0);
    tracep->declBus(c+201,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+714,"rx", false,-1, 127,0);
    tracep->declBit(c+718,"rx_negedge", false,-1);
    tracep->declBit(c+719,"tx_negedge", false,-1);
    tracep->declBus(c+720,"char_len", false,-1, 6,0);
    tracep->declBit(c+721,"go", false,-1);
    tracep->declBit(c+722,"lsb", false,-1);
    tracep->declBit(c+723,"ie", false,-1);
    tracep->declBit(c+724,"ass", false,-1);
    tracep->declBit(c+183,"spi_divider_sel", false,-1);
    tracep->declBit(c+184,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+185,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+186,"spi_ss_sel", false,-1);
    tracep->declBit(c+725,"tip", false,-1);
    tracep->declBit(c+726,"pos_edge", false,-1);
    tracep->declBit(c+727,"neg_edge", false,-1);
    tracep->declBit(c+728,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1262,"Tp", false,-1, 31,0);
    tracep->declBit(c+1166,"clk_in", false,-1);
    tracep->declBit(c+1167,"rst", false,-1);
    tracep->declBit(c+725,"enable", false,-1);
    tracep->declBit(c+721,"go", false,-1);
    tracep->declBit(c+728,"last_clk", false,-1);
    tracep->declBus(c+711,"divider", false,-1, 15,0);
    tracep->declBit(c+660,"clk_out", false,-1);
    tracep->declBit(c+726,"pos_edge", false,-1);
    tracep->declBit(c+727,"neg_edge", false,-1);
    tracep->declBus(c+729,"cnt", false,-1, 15,0);
    tracep->declBit(c+730,"cnt_zero", false,-1);
    tracep->declBit(c+731,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1262,"Tp", false,-1, 31,0);
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"rst", false,-1);
    tracep->declBus(c+187,"latch", false,-1, 3,0);
    tracep->declBus(c+178,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+720,"len", false,-1, 6,0);
    tracep->declBit(c+722,"lsb", false,-1);
    tracep->declBit(c+721,"go", false,-1);
    tracep->declBit(c+726,"pos_edge", false,-1);
    tracep->declBit(c+727,"neg_edge", false,-1);
    tracep->declBit(c+718,"rx_negedge", false,-1);
    tracep->declBit(c+719,"tx_negedge", false,-1);
    tracep->declBit(c+725,"tip", false,-1);
    tracep->declBit(c+728,"last", false,-1);
    tracep->declBus(c+180,"p_in", false,-1, 31,0);
    tracep->declArray(c+714,"p_out", false,-1, 127,0);
    tracep->declBit(c+660,"s_clk", false,-1);
    tracep->declBit(c+1189,"s_in", false,-1);
    tracep->declBit(c+1188,"s_out", false,-1);
    tracep->declBus(c+732,"cnt", false,-1, 7,0);
    tracep->declArray(c+714,"data", false,-1, 127,0);
    tracep->declBus(c+733,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+734,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+735,"rx_clk", false,-1);
    tracep->declBit(c+736,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+136,"auto_in_psel", false,-1);
    tracep->declBit(c+137,"auto_in_penable", false,-1);
    tracep->declBit(c+125,"auto_in_pwrite", false,-1);
    tracep->declBus(c+133,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1227,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+138,"auto_in_pready", false,-1);
    tracep->declBit(c+1228,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1193,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1186,"uart_rx", false,-1);
    tracep->declBit(c+1187,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+136,"in_psel", false,-1);
    tracep->declBit(c+137,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+138,"in_pready", false,-1);
    tracep->declBit(c+1228,"in_pslverr", false,-1);
    tracep->declBus(c+154,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+1193,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1186,"uart_rx", false,-1);
    tracep->declBit(c+1187,"uart_tx", false,-1);
    tracep->declBit(c+737,"rtsn", false,-1);
    tracep->declBit(c+1228,"ctsn", false,-1);
    tracep->declBit(c+738,"dtr_pad_o", false,-1);
    tracep->declBit(c+1228,"dsr_pad_i", false,-1);
    tracep->declBit(c+1228,"ri_pad_i", false,-1);
    tracep->declBit(c+1228,"dcd_pad_i", false,-1);
    tracep->declBit(c+739,"interrupt", false,-1);
    tracep->declBit(c+188,"reg_we", false,-1);
    tracep->declBit(c+189,"reg_re", false,-1);
    tracep->declBus(c+190,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+191,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+616,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+202,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+740,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"wb_rst_i", false,-1);
    tracep->declBus(c+190,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+192,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+202,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+188,"wb_we_i", false,-1);
    tracep->declBit(c+189,"wb_re_i", false,-1);
    tracep->declBit(c+1187,"stx_pad_o", false,-1);
    tracep->declBit(c+1186,"srx_pad_i", false,-1);
    tracep->declBus(c+1308,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+740,"rts_pad_o", false,-1);
    tracep->declBit(c+738,"dtr_pad_o", false,-1);
    tracep->declBit(c+739,"int_o", false,-1);
    tracep->declBit(c+741,"enable", false,-1);
    tracep->declBit(c+742,"srx_pad", false,-1);
    tracep->declBus(c+743,"ier", false,-1, 3,0);
    tracep->declBus(c+744,"iir", false,-1, 3,0);
    tracep->declBus(c+745,"fcr", false,-1, 1,0);
    tracep->declBus(c+746,"mcr", false,-1, 4,0);
    tracep->declBus(c+747,"lcr", false,-1, 7,0);
    tracep->declBus(c+748,"msr", false,-1, 7,0);
    tracep->declBus(c+749,"dl", false,-1, 15,0);
    tracep->declBus(c+750,"scratch", false,-1, 7,0);
    tracep->declBit(c+751,"start_dlc", false,-1);
    tracep->declBit(c+752,"lsr_mask_d", false,-1);
    tracep->declBit(c+753,"msi_reset", false,-1);
    tracep->declBus(c+754,"dlc", false,-1, 15,0);
    tracep->declBus(c+755,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+756,"rx_reset", false,-1);
    tracep->declBit(c+757,"tx_reset", false,-1);
    tracep->declBit(c+758,"dlab", false,-1);
    tracep->declBit(c+1244,"cts_pad_i", false,-1);
    tracep->declBit(c+1228,"dsr_pad_i", false,-1);
    tracep->declBit(c+1228,"ri_pad_i", false,-1);
    tracep->declBit(c+1228,"dcd_pad_i", false,-1);
    tracep->declBit(c+759,"loopback", false,-1);
    tracep->declBit(c+1228,"cts", false,-1);
    tracep->declBit(c+1244,"dsr", false,-1);
    tracep->declBit(c+1244,"ri", false,-1);
    tracep->declBit(c+1244,"dcd", false,-1);
    tracep->declBit(c+760,"cts_c", false,-1);
    tracep->declBit(c+761,"dsr_c", false,-1);
    tracep->declBit(c+762,"ri_c", false,-1);
    tracep->declBit(c+763,"dcd_c", false,-1);
    tracep->declBus(c+764,"lsr", false,-1, 7,0);
    tracep->declBit(c+765,"lsr0", false,-1);
    tracep->declBit(c+766,"lsr1", false,-1);
    tracep->declBit(c+767,"lsr2", false,-1);
    tracep->declBit(c+768,"lsr3", false,-1);
    tracep->declBit(c+769,"lsr4", false,-1);
    tracep->declBit(c+770,"lsr5", false,-1);
    tracep->declBit(c+771,"lsr6", false,-1);
    tracep->declBit(c+772,"lsr7", false,-1);
    tracep->declBit(c+773,"lsr0r", false,-1);
    tracep->declBit(c+774,"lsr1r", false,-1);
    tracep->declBit(c+775,"lsr2r", false,-1);
    tracep->declBit(c+776,"lsr3r", false,-1);
    tracep->declBit(c+777,"lsr4r", false,-1);
    tracep->declBit(c+778,"lsr5r", false,-1);
    tracep->declBit(c+779,"lsr6r", false,-1);
    tracep->declBit(c+780,"lsr7r", false,-1);
    tracep->declBit(c+203,"lsr_mask", false,-1);
    tracep->declBit(c+781,"rls_int", false,-1);
    tracep->declBit(c+782,"rda_int", false,-1);
    tracep->declBit(c+783,"ti_int", false,-1);
    tracep->declBit(c+784,"thre_int", false,-1);
    tracep->declBit(c+785,"ms_int", false,-1);
    tracep->declBit(c+786,"tf_push", false,-1);
    tracep->declBit(c+787,"rf_pop", false,-1);
    tracep->declBus(c+1218,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+788,"rf_error_bit", false,-1);
    tracep->declBit(c+766,"rf_overrun", false,-1);
    tracep->declBit(c+789,"rf_push_pulse", false,-1);
    tracep->declBus(c+790,"rf_count", false,-1, 4,0);
    tracep->declBus(c+791,"tf_count", false,-1, 4,0);
    tracep->declBus(c+792,"tstate", false,-1, 2,0);
    tracep->declBus(c+793,"rstate", false,-1, 3,0);
    tracep->declBus(c+794,"counter_t", false,-1, 9,0);
    tracep->declBit(c+795,"thre_set_en", false,-1);
    tracep->declBus(c+796,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+797,"block_value", false,-1, 7,0);
    tracep->declBit(c+798,"serial_out", false,-1);
    tracep->declBit(c+799,"serial_in", false,-1);
    tracep->declBit(c+204,"lsr_mask_condition", false,-1);
    tracep->declBit(c+205,"iir_read", false,-1);
    tracep->declBit(c+206,"msr_read", false,-1);
    tracep->declBit(c+207,"fifo_read", false,-1);
    tracep->declBit(c+208,"fifo_write", false,-1);
    tracep->declBus(c+800,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+801,"lsr0_d", false,-1);
    tracep->declBit(c+802,"lsr1_d", false,-1);
    tracep->declBit(c+803,"lsr2_d", false,-1);
    tracep->declBit(c+804,"lsr3_d", false,-1);
    tracep->declBit(c+805,"lsr4_d", false,-1);
    tracep->declBit(c+806,"lsr5_d", false,-1);
    tracep->declBit(c+807,"lsr6_d", false,-1);
    tracep->declBit(c+808,"lsr7_d", false,-1);
    tracep->declBit(c+809,"rls_int_d", false,-1);
    tracep->declBit(c+810,"thre_int_d", false,-1);
    tracep->declBit(c+811,"ms_int_d", false,-1);
    tracep->declBit(c+812,"ti_int_d", false,-1);
    tracep->declBit(c+813,"rda_int_d", false,-1);
    tracep->declBit(c+814,"rls_int_rise", false,-1);
    tracep->declBit(c+815,"thre_int_rise", false,-1);
    tracep->declBit(c+816,"ms_int_rise", false,-1);
    tracep->declBit(c+817,"ti_int_rise", false,-1);
    tracep->declBit(c+818,"rda_int_rise", false,-1);
    tracep->declBit(c+819,"rls_int_pnd", false,-1);
    tracep->declBit(c+820,"rda_int_pnd", false,-1);
    tracep->declBit(c+821,"thre_int_pnd", false,-1);
    tracep->declBit(c+822,"ms_int_pnd", false,-1);
    tracep->declBit(c+823,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1262,"Tp", false,-1, 31,0);
    tracep->declBus(c+1262,"width", false,-1, 31,0);
    tracep->declBus(c+1288,"init_value", false,-1, 0,0);
    tracep->declBit(c+1167,"rst_i", false,-1);
    tracep->declBit(c+1166,"clk_i", false,-1);
    tracep->declBit(c+1228,"stage1_rst_i", false,-1);
    tracep->declBit(c+1244,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1186,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+742,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+824,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"wb_rst_i", false,-1);
    tracep->declBus(c+747,"lcr", false,-1, 7,0);
    tracep->declBit(c+787,"rf_pop", false,-1);
    tracep->declBit(c+799,"srx_pad_i", false,-1);
    tracep->declBit(c+741,"enable", false,-1);
    tracep->declBit(c+756,"rx_reset", false,-1);
    tracep->declBit(c+203,"lsr_mask", false,-1);
    tracep->declBus(c+794,"counter_t", false,-1, 9,0);
    tracep->declBus(c+790,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1218,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+766,"rf_overrun", false,-1);
    tracep->declBit(c+788,"rf_error_bit", false,-1);
    tracep->declBus(c+793,"rstate", false,-1, 3,0);
    tracep->declBit(c+789,"rf_push_pulse", false,-1);
    tracep->declBus(c+825,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+826,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+827,"rshift", false,-1, 7,0);
    tracep->declBit(c+828,"rparity", false,-1);
    tracep->declBit(c+829,"rparity_error", false,-1);
    tracep->declBit(c+830,"rframing_error", false,-1);
    tracep->declBit(c+831,"rbit_in", false,-1);
    tracep->declBit(c+832,"rparity_xor", false,-1);
    tracep->declBus(c+833,"counter_b", false,-1, 7,0);
    tracep->declBit(c+834,"rf_push_q", false,-1);
    tracep->declBus(c+835,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+836,"rf_push", false,-1);
    tracep->declBit(c+837,"break_error", false,-1);
    tracep->declBit(c+838,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+839,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+840,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+841,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1247,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1281,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1306,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1302,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1304,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1303,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1305,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1301,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1308,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1309,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1313,"sr_push", false,-1, 3,0);
    tracep->declBus(c+842,"toc_value", false,-1, 9,0);
    tracep->declBus(c+843,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1314,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1277,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1278,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1284,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"wb_rst_i", false,-1);
    tracep->declBit(c+789,"push", false,-1);
    tracep->declBit(c+787,"pop", false,-1);
    tracep->declBus(c+835,"data_in", false,-1, 10,0);
    tracep->declBit(c+756,"fifo_reset", false,-1);
    tracep->declBit(c+203,"reset_status", false,-1);
    tracep->declBus(c+1218,"data_out", false,-1, 10,0);
    tracep->declBit(c+766,"overrun", false,-1);
    tracep->declBus(c+790,"count", false,-1, 4,0);
    tracep->declBit(c+788,"error_bit", false,-1);
    tracep->declBus(c+1219,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+844+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+860,"top", false,-1, 3,0);
    tracep->declBus(c+861,"bottom", false,-1, 3,0);
    tracep->declBus(c+862,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+863,"word0", false,-1, 2,0);
    tracep->declBus(c+864,"word1", false,-1, 2,0);
    tracep->declBus(c+865,"word2", false,-1, 2,0);
    tracep->declBus(c+866,"word3", false,-1, 2,0);
    tracep->declBus(c+867,"word4", false,-1, 2,0);
    tracep->declBus(c+868,"word5", false,-1, 2,0);
    tracep->declBus(c+869,"word6", false,-1, 2,0);
    tracep->declBus(c+870,"word7", false,-1, 2,0);
    tracep->declBus(c+871,"word8", false,-1, 2,0);
    tracep->declBus(c+872,"word9", false,-1, 2,0);
    tracep->declBus(c+873,"word10", false,-1, 2,0);
    tracep->declBus(c+874,"word11", false,-1, 2,0);
    tracep->declBus(c+875,"word12", false,-1, 2,0);
    tracep->declBus(c+876,"word13", false,-1, 2,0);
    tracep->declBus(c+877,"word14", false,-1, 2,0);
    tracep->declBus(c+878,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1278,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1276,"data_width", false,-1, 31,0);
    tracep->declBus(c+1277,"depth", false,-1, 31,0);
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+789,"we", false,-1);
    tracep->declBus(c+860,"a", false,-1, 3,0);
    tracep->declBus(c+861,"dpra", false,-1, 3,0);
    tracep->declBus(c+879,"di", false,-1, 7,0);
    tracep->declBus(c+1219,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+617+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"wb_rst_i", false,-1);
    tracep->declBus(c+747,"lcr", false,-1, 7,0);
    tracep->declBit(c+786,"tf_push", false,-1);
    tracep->declBus(c+192,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+741,"enable", false,-1);
    tracep->declBit(c+757,"tx_reset", false,-1);
    tracep->declBit(c+203,"lsr_mask", false,-1);
    tracep->declBit(c+798,"stx_pad_o", false,-1);
    tracep->declBus(c+792,"tstate", false,-1, 2,0);
    tracep->declBus(c+791,"tf_count", false,-1, 4,0);
    tracep->declBus(c+880,"counter", false,-1, 4,0);
    tracep->declBus(c+881,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+882,"shift_out", false,-1, 6,0);
    tracep->declBit(c+883,"stx_o_tmp", false,-1);
    tracep->declBit(c+884,"parity_xor", false,-1);
    tracep->declBit(c+885,"tf_pop", false,-1);
    tracep->declBit(c+886,"bit_out", false,-1);
    tracep->declBus(c+192,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1220,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+887,"tf_overrun", false,-1);
    tracep->declBus(c+1248,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1227,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1315,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1316,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1289,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1317,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1276,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1277,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1278,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1284,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+1167,"wb_rst_i", false,-1);
    tracep->declBit(c+786,"push", false,-1);
    tracep->declBit(c+885,"pop", false,-1);
    tracep->declBus(c+192,"data_in", false,-1, 7,0);
    tracep->declBit(c+757,"fifo_reset", false,-1);
    tracep->declBit(c+203,"reset_status", false,-1);
    tracep->declBus(c+1220,"data_out", false,-1, 7,0);
    tracep->declBit(c+887,"overrun", false,-1);
    tracep->declBus(c+791,"count", false,-1, 4,0);
    tracep->declBus(c+888,"top", false,-1, 3,0);
    tracep->declBus(c+889,"bottom", false,-1, 3,0);
    tracep->declBus(c+890,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1278,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1276,"data_width", false,-1, 31,0);
    tracep->declBus(c+1277,"depth", false,-1, 31,0);
    tracep->declBit(c+1166,"clk", false,-1);
    tracep->declBit(c+786,"we", false,-1);
    tracep->declBus(c+888,"a", false,-1, 3,0);
    tracep->declBus(c+889,"dpra", false,-1, 3,0);
    tracep->declBus(c+192,"di", false,-1, 7,0);
    tracep->declBus(c+1220,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+633+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBit(c+130,"auto_in_psel", false,-1);
    tracep->declBit(c+45,"auto_in_penable", false,-1);
    tracep->declBit(c+125,"auto_in_pwrite", false,-1);
    tracep->declBus(c+131,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1227,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+126,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1229,"auto_in_pready", false,-1);
    tracep->declBit(c+1230,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1231,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1180,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1181,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1182,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1183,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1184,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1185,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1166,"clock", false,-1);
    tracep->declBit(c+1167,"reset", false,-1);
    tracep->declBus(c+175,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+130,"in_psel", false,-1);
    tracep->declBit(c+45,"in_penable", false,-1);
    tracep->declBus(c+1227,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+125,"in_pwrite", false,-1);
    tracep->declBus(c+126,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1229,"in_pready", false,-1);
    tracep->declBus(c+1231,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1230,"in_pslverr", false,-1);
    tracep->declBus(c+1180,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1181,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1182,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1183,"vga_hsync", false,-1);
    tracep->declBit(c+1184,"vga_vsync", false,-1);
    tracep->declBit(c+1185,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+660,"sck", false,-1);
    tracep->declBit(c+1221,"ss", false,-1);
    tracep->declBit(c+1188,"mosi", false,-1);
    tracep->declBit(c+1222,"miso", false,-1);
    tracep->declBus(c+985,"buffer", false,-1, 7,0);
    tracep->declBus(c+986,"count", false,-1, 2,0);
    tracep->declBus(c+987,"state", false,-1, 1,0);
    tracep->declBit(c+988,"buffer_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+660,"sck", false,-1);
    tracep->declBit(c+891,"ss", false,-1);
    tracep->declBit(c+1188,"mosi", false,-1);
    tracep->declBit(c+1223,"miso", false,-1);
    tracep->declBit(c+891,"reset", false,-1);
    tracep->declBus(c+979,"state", false,-1, 2,0);
    tracep->declBus(c+980,"counter", false,-1, 7,0);
    tracep->declBus(c+981,"cmd", false,-1, 7,0);
    tracep->declBus(c+982,"addr", false,-1, 23,0);
    tracep->declBus(c+983,"data", false,-1, 31,0);
    tracep->declBit(c+984,"ren", false,-1);
    tracep->declBus(c+1224,"rdata", false,-1, 31,0);
    tracep->declBus(c+1225,"raddr", false,-1, 31,0);
    tracep->declBus(c+1226,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+660,"clock", false,-1);
    tracep->declBit(c+984,"valid", false,-1);
    tracep->declBus(c+981,"cmd", false,-1, 7,0);
    tracep->declBus(c+1225,"addr", false,-1, 31,0);
    tracep->declBus(c+1224,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+209,"sck", false,-1);
    tracep->declBit(c+210,"ce_n", false,-1);
    tracep->declBus(c+1190,"dio", false,-1, 3,0);
    tracep->declBus(c+649,"state", false,-1, 3,0);
    tracep->declBus(c+650,"inst_buffer", false,-1, 7,0);
    tracep->declBus(c+651,"addr_buffer", false,-1, 23,0);
    tracep->declBus(c+652,"inst_counter", false,-1, 2,0);
    tracep->declBus(c+653,"addr_counter", false,-1, 2,0);
    tracep->declBus(c+654,"wait_counter", false,-1, 2,0);
    tracep->declBus(c+655,"data", false,-1, 7,0);
    tracep->declBit(c+656,"finish", false,-1);
    tracep->declBus(c+657,"dio_out_reg", false,-1, 3,0);
    tracep->declBit(c+658,"dio_en", false,-1);
    tracep->declBit(c+659,"qpi_mode", false,-1);
    tracep->declBit(c+210,"reset", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1191,"clk", false,-1);
    tracep->declBit(c+662,"cke", false,-1);
    tracep->declBit(c+663,"cs", false,-1);
    tracep->declBit(c+664,"ras", false,-1);
    tracep->declBit(c+665,"cas", false,-1);
    tracep->declBit(c+666,"we", false,-1);
    tracep->declBus(c+667,"a", false,-1, 12,0);
    tracep->declBus(c+668,"ba", false,-1, 1,0);
    tracep->declBus(c+669,"dqm", false,-1, 1,0);
    tracep->declBus(c+670,"dq", false,-1, 15,0);
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
    VlWide<3>/*95:0*/ __Vtemp_ha129e8f8__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1]));
    bufp->fullSData(oldp+3,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0]),15);
    bufp->fullSData(oldp+4,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1]),15);
    bufp->fullSData(oldp+5,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2]),15);
    bufp->fullSData(oldp+6,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3]),15);
    bufp->fullSData(oldp+7,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[4]),15);
    bufp->fullSData(oldp+8,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[5]),15);
    bufp->fullSData(oldp+9,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0]),12);
    bufp->fullSData(oldp+10,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1]),12);
    bufp->fullSData(oldp+11,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2]),12);
    bufp->fullSData(oldp+12,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3]),12);
    bufp->fullSData(oldp+13,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[4]),12);
    bufp->fullSData(oldp+14,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[5]),12);
    bufp->fullCData(oldp+15,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+16,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+17,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+18,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3]),3);
    bufp->fullCData(oldp+19,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[4]),3);
    bufp->fullCData(oldp+20,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[5]),3);
    bufp->fullCData(oldp+21,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+22,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+23,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+24,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3]),3);
    bufp->fullCData(oldp+25,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__pair_list[0]),5);
    bufp->fullCData(oldp+26,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__pair_list[1]),5);
    bufp->fullCData(oldp+27,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__pair_list[2]),5);
    bufp->fullCData(oldp+28,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+29,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+30,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+31,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+32,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+33,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+34,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[0]),4);
    bufp->fullCData(oldp+35,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[1]),4);
    bufp->fullCData(oldp+36,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+37,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+38,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+39,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+40,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+41,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+42,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+43,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[3]),2);
    bufp->fullBit(oldp+44,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+45,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+46,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+47,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+48,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+49,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullCData(oldp+50,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                               ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                  << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))),2);
    bufp->fullBit(oldp+51,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+52,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+53,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+54,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+55,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+56,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+57,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+58,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+60,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+62,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+63,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+65,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+66,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+69,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+70,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+71,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+72,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+73,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+74,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+75,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+76,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+77,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+78,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+79,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+80,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+81,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+82,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+83,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+84,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+85,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+86,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+87,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+89,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+91,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+93,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+94,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+95,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+97,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+98,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+99,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+100,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+106,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+129,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+130,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+131,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+132,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+133,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+134,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+135,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+136,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+137,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+138,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_psel));
    bufp->fullBit(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+148,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+149,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+151,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+152,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+153,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+154,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+156,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+158,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+162,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+163,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+164,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+165,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+166,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+167,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+172,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+173,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+174,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+175,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+176,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__is_xip_access));
    bufp->fullIData(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pwdata),32);
    bufp->fullCData(oldp+178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pstrb),4);
    bufp->fullCData(oldp+179,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr),5);
    bufp->fullIData(oldp+180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwdata),32);
    bufp->fullBit(oldp+181,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_penable));
    bufp->fullBit(oldp+182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwrite));
    bufp->fullBit(oldp+183,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullBit(oldp+184,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__spi_tx_sel),4);
    bufp->fullBit(oldp+186,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+190,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullIData(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullIData(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullCData(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT___asic_psram_sck));
    bufp->fullBit(oldp+210,(vlSelf->ysyxSoCFull__DOT__psram__DOT__reset));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullBit(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+218,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+222,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+226,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+230,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+232,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+234,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+235,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+236,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+237,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+238,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+239,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+240,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+241,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+242,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+243,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+244,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+245,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+246,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+247,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+248,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+250,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+254,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+258,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+259,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+260,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+261,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+262,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+265,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+266,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+267,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+268,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+269,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+270,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+271,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+272,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+273,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+274,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+275,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+276,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+277,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+278,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+279,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+280,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+281,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+282,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+283,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+284,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+285,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+286,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+287,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+288,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+289,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+290,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+291,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+292,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+293,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+294,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+295,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+296,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+297,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+307,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+308,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+309,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+310,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                              [1U]),2);
    bufp->fullBit(oldp+311,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                   >> 1U))));
    bufp->fullIData(oldp+312,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+313,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+316,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data))),32);
    bufp->fullIData(oldp+317,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data))),32);
    bufp->fullCData(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data),8);
    bufp->fullSData(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data),16);
    bufp->fullIData(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+321,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+322,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullBit(oldp+324,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+325,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullBit(oldp+326,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullIData(oldp+327,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+340,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+341,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+342,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+343,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+344,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+345,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+350,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+352,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+353,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+354,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+355,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+356,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+358,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+359,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+360,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+361,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+362,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+363,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+364,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+365,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+366,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+367,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+368,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+369,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+370,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+371,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+372,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+373,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+374,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+377,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullQData(oldp+378,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+381,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+382,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+384,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+385,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+386,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+387,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+391,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+400,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+401,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+405,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+433,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+442,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+443,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+444,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+446,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+452,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+454,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+455,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+456,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+457,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+460,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+461,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+462,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+464,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+468,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+472,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+476,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+480,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+484,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+486,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+488,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+492,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+494,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+496,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+498,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+500,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+501,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+502,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+503,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+504,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+506,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+508,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+510,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+512,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+514,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+516,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+518,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+520,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+522,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+524,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+525,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+526,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+528,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+529,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+530,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+532,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+533,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+534,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+536,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+538,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+540,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+541,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+542,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+544,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+545,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+546,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+548,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+549,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+550,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+552,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+554,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+556,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+558,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+560,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+562,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+564,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+566,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+568,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+570,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+572,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+573,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+574,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+575,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+576,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+577,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+580,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+582,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullCData(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready),2);
    bufp->fullBit(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+588,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready) 
                                   >> 1U))));
    bufp->fullCData(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state),2);
    bufp->fullBit(oldp+590,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+594,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+598,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullBit(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__qpi_valid));
    bufp->fullBit(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__qpi_ce_n));
    bufp->fullCData(oldp+602,(((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))
                                ? (1U & (0x35U >> (7U 
                                                   & ((IData)(7U) 
                                                      - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter)))))
                                : 0U)),4);
    bufp->fullBit(oldp+603,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))));
    bufp->fullCData(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+606,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullBit(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__finish));
    bufp->fullCData(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter),3);
    bufp->fullCData(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state),2);
    bufp->fullCData(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state),3);
    bufp->fullBit(oldp+613,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__penable));
    bufp->fullCData(oldp+614,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                ? 4U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                         ? 0x18U : 
                                        ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                          ? 0x10U : 
                                         ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                           ? 0x14U : 
                                          ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                            ? 0x10U
                                            : ((7U 
                                                == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                                ? 0x18U
                                                : 0U))))))),5);
    bufp->fullBit(oldp+615,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                             | ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                | ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                   | ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                      | (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))))))));
    bufp->fullCData(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+617,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+618,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+621,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+622,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+623,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+624,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+625,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+626,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+628,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+629,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+630,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+632,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+633,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+634,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+637,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+639,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+641,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+642,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+643,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+644,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+647,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+649,(vlSelf->ysyxSoCFull__DOT__psram__DOT__state),4);
    bufp->fullCData(oldp+650,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_buffer),8);
    bufp->fullIData(oldp+651,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_buffer),24);
    bufp->fullCData(oldp+652,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_counter),3);
    bufp->fullCData(oldp+653,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_counter),3);
    bufp->fullCData(oldp+654,(vlSelf->ysyxSoCFull__DOT__psram__DOT__wait_counter),3);
    bufp->fullCData(oldp+655,(vlSelf->ysyxSoCFull__DOT__psram__DOT__data),8);
    bufp->fullBit(oldp+656,(vlSelf->ysyxSoCFull__DOT__psram__DOT__finish));
    bufp->fullCData(oldp+657,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_out_reg),4);
    bufp->fullBit(oldp+658,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_en));
    bufp->fullBit(oldp+659,(vlSelf->ysyxSoCFull__DOT__psram__DOT__qpi_mode));
    bufp->fullBit(oldp+660,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+661,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+663,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+664,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+665,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+666,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullSData(oldp+670,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                  ? 0U : 0xffffU) & 
                                ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                    ? 0U : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                      ? 0U : 0xffffU)) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                     ? 0U : 0xffffU))) 
                               & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                   ? 0U : 0xffffU))),16);
    bufp->fullBit(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullIData(oldp+672,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+673,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+674,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+675,((0xfU & ((8U > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
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
    bufp->fullBit(oldp+676,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+677,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+679,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+680,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+681,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+682,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+683,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+684,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+685,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+686,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+687,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+688,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+689,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullBit(oldp+690,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+691,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+692,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+693,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+694,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+695,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+696,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullCData(oldp+697,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+698,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+699,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+701,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+702,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+704,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+705,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+708,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullBit(oldp+709,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready));
    bufp->fullIData(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_prdata),32);
    bufp->fullSData(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+718,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+719,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+720,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+721,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+722,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+723,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+724,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+725,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+726,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+727,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+728,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+729,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+730,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+731,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+732,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+733,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+734,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+735,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+736,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+737,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+738,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+739,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+740,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+741,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+742,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+743,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+744,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+746,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+747,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+748,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+749,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+750,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+752,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+753,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+754,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+756,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+758,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+759,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+760,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+761,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+762,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+763,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+764,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+765,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+766,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+767,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+768,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+769,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+770,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+771,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+772,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+773,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+774,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+775,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+776,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+777,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+778,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+779,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+780,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+781,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+782,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+783,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+784,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+785,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+786,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+788,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+789,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+790,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+793,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+795,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+796,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+797,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+798,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+799,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+800,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+801,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+803,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+804,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+805,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+806,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+807,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+808,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+809,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+810,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+811,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+812,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+814,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+815,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+816,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+817,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+818,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+820,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+821,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+822,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+823,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+824,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+827,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+828,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+829,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+830,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+833,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+834,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+836,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+837,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+838,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+839,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+840,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+841,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+843,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+848,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+850,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+858,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+860,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+861,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+862,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+864,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+866,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+867,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+868,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+869,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+870,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+874,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+875,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+877,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+879,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+890,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+891,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullBit(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+894,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullIData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+900,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+901,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+920,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+921,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+922,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+923,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+928,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+929,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+930,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+931,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+932,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+933,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+936,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+937,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+938,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[4]),32);
    bufp->fullIData(oldp+939,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[5]),32);
    bufp->fullIData(oldp+940,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+941,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+942,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+943,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+944,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+945,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+946,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+947,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+948,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+949,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+950,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+951,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+952,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+953,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+954,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+955,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+956,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+957,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+958,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+959,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+960,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+961,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+962,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+963,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+964,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+965,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+966,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+967,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+968,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+969,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+972,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+973,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+975,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+976,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[4]),32);
    bufp->fullIData(oldp+977,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[5]),32);
    bufp->fullIData(oldp+978,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+979,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+980,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+981,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+982,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+983,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+984,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                             & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+985,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer),8);
    bufp->fullCData(oldp+986,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count),3);
    bufp->fullCData(oldp+987,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state),2);
    bufp->fullBit(oldp+988,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                   >> (7U & ((IData)(7U) 
                                             - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))));
    bufp->fullCData(oldp+989,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+990,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__arsize_out_reg),3);
    bufp->fullBit(oldp+991,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+992,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+993,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+994,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullBit(oldp+995,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullBit(oldp+996,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+997,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+998,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+999,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+1000,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+1001,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1002,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1003,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1004,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                 | ((0x33U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | ((0x6fU == (0x7fU 
                                                  & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                       | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+1005,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1006,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1007,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+1008,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                      >> 0xcU))),3);
    bufp->fullCData(oldp+1009,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+1010,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                    >> 0x1eU))));
    bufp->fullBit(oldp+1011,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1012,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1013,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1014,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+1015,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+1016,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+1017,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+1018,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+1019,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+1020,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                                << 1U)),2);
    bufp->fullCData(oldp+1021,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+1022,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+1023,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U)),2);
    bufp->fullCData(oldp+1024,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullCData(oldp+1025,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[0]),3);
    bufp->fullCData(oldp+1026,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[1]),3);
    bufp->fullCData(oldp+1027,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[0]),3);
    bufp->fullCData(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[1]),3);
    bufp->fullCData(oldp+1029,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+1030,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+1031,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+1032,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+1034,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1035,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1036,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1037,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+1038,(((IData)((0x6000U == 
                                         (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                 ? 8U : ((1U & VL_REDXOR_16(
                                                            (0x6000U 
                                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                          ? 9U : 3U))),4);
    bufp->fullCData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1041,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+1043,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+1046,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+1047,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+1048,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+1049,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+1050,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 | ((0x17U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+1051,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1052,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))));
    bufp->fullCData(oldp+1053,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),3);
    bufp->fullSData(oldp+1054,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                >> 0x14U)),12);
    bufp->fullCData(oldp+1055,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),3);
    bufp->fullCData(oldp+1056,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1057,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+1058,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+1059,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    >> 1U))));
    bufp->fullCData(oldp+1060,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : 2U))),3);
    bufp->fullCData(oldp+1061,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : ((4U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 2U
                                                   : 0U)))),3);
    bufp->fullCData(oldp+1062,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 1U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 3U : ((4U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 0xfU
                                                   : 0U)))),4);
    __Vtemp_h49f7fb6a__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))));
    __Vtemp_h49f7fb6a__0[1U] = ((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h49f7fb6a__0[2U] = (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+1063,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1066,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1068,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1070,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1071,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1072,((0x11830U | ((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                               ? 1U
                                               : ((2U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 3U
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                    ? 0xfU
                                                    : 0U))) 
                                             << 0x12U) 
                                            | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword) 
                                                << 6U) 
                                               | ((4U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                   ? 1U
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                    ? 2U
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                     ? 4U
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                      ? 8U
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                       ? 3U
                                                       : 
                                                      ((0xaU 
                                                        == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                        ? 0xcU
                                                        : 
                                                       ((0x10U 
                                                         == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                         ? 0xfU
                                                         : 0U))))))))))),24);
    bufp->fullCData(oldp+1073,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[0]),6);
    bufp->fullCData(oldp+1074,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[1]),6);
    bufp->fullCData(oldp+1075,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[2]),6);
    bufp->fullCData(oldp+1076,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[3]),6);
    bufp->fullCData(oldp+1077,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[0]),4);
    bufp->fullCData(oldp+1078,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[1]),4);
    bufp->fullCData(oldp+1079,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[2]),4);
    bufp->fullCData(oldp+1080,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[3]),4);
    bufp->fullIData(oldp+1081,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullCData(oldp+1082,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullIData(oldp+1083,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullCData(oldp+1084,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullIData(oldp+1085,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1086,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullCData(oldp+1087,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awsize_out_reg),3);
    bufp->fullCData(oldp+1088,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullIData(oldp+1089,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullCData(oldp+1090,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullIData(oldp+1091,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1092,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1093,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1094,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1095,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullCData(oldp+1096,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullIData(oldp+1097,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1098,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1099,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1100,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1101,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1102,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1107,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
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
    bufp->fullBit(oldp+1108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1112,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullCData(oldp+1120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+1121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+1122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[0]),3);
    bufp->fullCData(oldp+1123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[1]),3);
    bufp->fullIData(oldp+1124,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullCData(oldp+1130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+1131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+1132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[0]),3);
    bufp->fullCData(oldp+1133,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[1]),3);
    bufp->fullIData(oldp+1134,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1135,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1136,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1137,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1138,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1141,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1142,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+1145,(((0x1fU >= (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                             ? (3U 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                             : 0U) 
                                           << 3U)) ? 
                                (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                       ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                       : 0U) << 3U))
                                 : 0U)),32);
    bufp->fullCData(oldp+1146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__wstrb),4);
    bufp->fullCData(oldp+1147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awsize),3);
    bufp->fullCData(oldp+1148,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                 ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : 0U)),2);
    bufp->fullCData(oldp+1149,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),2);
    bufp->fullBit(oldp+1150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__inuart));
    bufp->fullBit(oldp+1151,(((0xf000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0xfffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1152,(((0x30000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x3fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1153,(((0x10001000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x10001fffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1154,(((0x80000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x9fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullCData(oldp+1155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size),2);
    bufp->fullCData(oldp+1156,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                 ? 1U : ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                          ? 2U : ((6U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                   ? 4U
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                    ? 8U
                                                    : 
                                                   ((8U 
                                                     == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                     ? 3U
                                                     : 
                                                    ((0xaU 
                                                      == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                      ? 0xcU
                                                      : 
                                                     ((0x10U 
                                                       == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
                                                       ? 0xfU
                                                       : 0U)))))))),4);
    bufp->fullCData(oldp+1157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux),5);
    bufp->fullCData(oldp+1158,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT____Vcellinp__type_mux__key),2);
    bufp->fullCData(oldp+1161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__lut_out),4);
    bufp->fullBit(oldp+1164,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+1165,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1166,(vlSelf->clock));
    bufp->fullBit(oldp+1167,(vlSelf->reset));
    bufp->fullSData(oldp+1168,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1169,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1170,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1171,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1172,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1173,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1174,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1175,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1176,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1177,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1178,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1179,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1180,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1181,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1182,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1183,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1184,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1185,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1186,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1187,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1188,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+1189,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
                                     | ((2U != (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state)) 
                                        | ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                           >> (7U & 
                                               ((IData)(7U) 
                                                - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))) 
                                    & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                       | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                            ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                            : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                          >> 0x1fU))))));
    bufp->fullCData(oldp+1190,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__din),4);
    bufp->fullBit(oldp+1191,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullBit(oldp+1192,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1193,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullBit(oldp+1194,((1U & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                     ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                     : ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                         ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                         : 0U)))));
    bufp->fullIData(oldp+1195,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+1196,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullIData(oldp+1197,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                  : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                             ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                             : 0U) 
                                           | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                               ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                               : 0U)))),32);
    bufp->fullCData(oldp+1198,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1199,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1200,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1201,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1202,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
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
    bufp->fullBit(oldp+1203,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1204,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1205,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1206,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullIData(oldp+1207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullBit(oldp+1209,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1210,(((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
                                & ((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                      | ((0x33U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         | ((0x6fU 
                                             == (0x7fU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                            | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))) 
                               | ((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                     >> 1U))) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid))));
    bufp->fullBit(oldp+1211,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state)))));
    bufp->fullBit(oldp+1212,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                     & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready)) 
                                    >> 1U))));
    bufp->fullBit(oldp+1213,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullCData(oldp+1214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+1215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+1216,(((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state)) 
                              & (IData)(vlSelf->clock))));
    bufp->fullBit(oldp+1217,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1218,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullBit(oldp+1221,(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss));
    bufp->fullBit(oldp+1222,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
                                    | ((2U != (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state)) 
                                       | ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                          >> (7U & 
                                              ((IData)(7U) 
                                               - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))))));
    bufp->fullBit(oldp+1223,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullIData(oldp+1224,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1225,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1226,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullCData(oldp+1227,(1U),3);
    bufp->fullBit(oldp+1228,(0U));
    bufp->fullBit(oldp+1229,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1230,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1231,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1232,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1233,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1234,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1235,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pready));
    bufp->fullBit(oldp+1236,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullIData(oldp+1237,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_prdata),32);
    bufp->fullCData(oldp+1238,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1239,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullBit(oldp+1240,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1241,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1242,(0U),8);
    bufp->fullCData(oldp+1243,(1U),2);
    bufp->fullBit(oldp+1244,(1U));
    bufp->fullBit(oldp+1245,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1246,(0U),32);
    bufp->fullCData(oldp+1247,(0U),4);
    bufp->fullCData(oldp+1248,(0U),3);
    bufp->fullCData(oldp+1249,(0U),2);
    bufp->fullBit(oldp+1250,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1254,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1258,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1259,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1260,(2U),32);
    bufp->fullIData(oldp+1261,(2U),32);
    bufp->fullIData(oldp+1262,(1U),32);
    bufp->fullIData(oldp+1263,(0x20U),32);
    bufp->fullIData(oldp+1264,(0U),32);
    bufp->fullIData(oldp+1265,(0x21U),32);
    bufp->fullIData(oldp+1266,(2U),32);
    bufp->fullIData(oldp+1267,(0x30000000U),32);
    bufp->fullIData(oldp+1268,(6U),32);
    bufp->fullIData(oldp+1269,(0xcU),32);
    bufp->fullIData(oldp+1270,(3U),32);
    __Vtemp_ha129e8f8__0[0U] = 0xfc467895U;
    __Vtemp_ha129e8f8__0[1U] = 0x93414684U;
    __Vtemp_ha129e8f8__0[2U] = 0xc00182U;
    bufp->fullWData(oldp+1271,(__Vtemp_ha129e8f8__0),90);
    bufp->fullIData(oldp+1274,(0xfU),32);
    bufp->fullIData(oldp+1275,(6U),32);
    bufp->fullIData(oldp+1276,(8U),32);
    bufp->fullIData(oldp+1277,(0x10U),32);
    bufp->fullIData(oldp+1278,(4U),32);
    bufp->fullIData(oldp+1279,(0x23U),32);
    bufp->fullIData(oldp+1280,(4U),32);
    bufp->fullCData(oldp+1281,(1U),4);
    bufp->fullCData(oldp+1282,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword),4);
    bufp->fullSData(oldp+1283,(0x223aU),15);
    bufp->fullIData(oldp+1284,(5U),32);
    bufp->fullIData(oldp+1285,(3U),32);
    bufp->fullCData(oldp+1286,(0xb5U),8);
    bufp->fullBit(oldp+1287,(0U));
    bufp->fullBit(oldp+1288,(1U));
    bufp->fullCData(oldp+1289,(4U),3);
    bufp->fullCData(oldp+1290,(0x1bU),8);
    bufp->fullCData(oldp+1291,(0xebU),8);
    bufp->fullCData(oldp+1292,(0x38U),8);
    bufp->fullCData(oldp+1293,(0x35U),8);
    bufp->fullIData(oldp+1294,(0x64U),32);
    bufp->fullIData(oldp+1295,(0x18U),32);
    bufp->fullIData(oldp+1296,(9U),32);
    bufp->fullIData(oldp+1297,(0xdU),32);
    bufp->fullIData(oldp+1298,(0x2000U),32);
    bufp->fullIData(oldp+1299,(0x2710U),32);
    bufp->fullIData(oldp+1300,(0x30cU),32);
    bufp->fullCData(oldp+1301,(7U),4);
    bufp->fullCData(oldp+1302,(3U),4);
    bufp->fullCData(oldp+1303,(5U),4);
    bufp->fullCData(oldp+1304,(4U),4);
    bufp->fullCData(oldp+1305,(6U),4);
    bufp->fullCData(oldp+1306,(2U),4);
    bufp->fullSData(oldp+1307,(0x21U),13);
    bufp->fullCData(oldp+1308,(8U),4);
    bufp->fullCData(oldp+1309,(9U),4);
    bufp->fullIData(oldp+1310,(0xaU),32);
    bufp->fullIData(oldp+1311,(0x11U),32);
    bufp->fullIData(oldp+1312,(0x3fffffffU),32);
    bufp->fullCData(oldp+1313,(0xaU),4);
    bufp->fullIData(oldp+1314,(0xbU),32);
    bufp->fullCData(oldp+1315,(2U),3);
    bufp->fullCData(oldp+1316,(3U),3);
    bufp->fullCData(oldp+1317,(5U),3);
}
