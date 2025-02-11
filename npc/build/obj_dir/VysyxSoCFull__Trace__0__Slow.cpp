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
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+1108,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1109,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1110,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1111,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1112,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1113,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1114,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1115,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1116,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1117,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1118,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1119,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1120,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1121,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1122,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1123,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1124,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1125,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1126,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1127,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+1108,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1109,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1110,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1111,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1112,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1113,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1114,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1115,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1116,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1117,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1118,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1119,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1120,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1121,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1122,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1123,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1124,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1125,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1126,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1127,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+620,"spi_sck", false,-1);
    tracep->declBus(c+621,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1128,"spi_mosi", false,-1);
    tracep->declBit(c+1129,"spi_miso", false,-1);
    tracep->declBit(c+1126,"uart_rx", false,-1);
    tracep->declBit(c+1127,"uart_tx", false,-1);
    tracep->declBit(c+1130,"psram_sck", false,-1);
    tracep->declBit(c+1131,"psram_ce_n", false,-1);
    tracep->declBus(c+173,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1132,"sdram_clk", false,-1);
    tracep->declBit(c+622,"sdram_cke", false,-1);
    tracep->declBit(c+623,"sdram_cs", false,-1);
    tracep->declBit(c+624,"sdram_ras", false,-1);
    tracep->declBit(c+625,"sdram_cas", false,-1);
    tracep->declBit(c+626,"sdram_we", false,-1);
    tracep->declBus(c+627,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+628,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+629,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+630,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1108,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1109,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1110,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1111,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1112,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1113,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1114,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1115,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1116,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1117,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1118,"ps2_clk", false,-1);
    tracep->declBit(c+1119,"ps2_data", false,-1);
    tracep->declBus(c+1120,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1121,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1122,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1123,"vga_hsync", false,-1);
    tracep->declBit(c+1124,"vga_vsync", false,-1);
    tracep->declBit(c+1125,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+108,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+109,"in_psel", false,-1);
    tracep->declBit(c+307,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+174,"in_pready", false,-1);
    tracep->declBus(c+175,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+113,"in_pslverr", false,-1);
    tracep->declBus(c+108,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+109,"out_psel", false,-1);
    tracep->declBit(c+307,"out_penable", false,-1);
    tracep->declBus(c+1165,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"out_pwrite", false,-1);
    tracep->declBus(c+111,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+174,"out_pready", false,-1);
    tracep->declBus(c+175,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+113,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+109,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+307,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+108,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1165,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+174,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+113,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+175,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+114,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+1133,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+108,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1165,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+631,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1166,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+632,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+115,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+1134,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+116,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1165,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1167,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1168,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1169,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+117,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+1135,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+118,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1165,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1170,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1171,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1172,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+119,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+1136,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+118,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1165,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+1173,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1174,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1175,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+120,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+1137,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+108,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1165,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1138,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1166,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+308,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+121,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+122,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+118,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1165,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+123,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1166,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1139,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+124,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+125,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+110,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+116,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1165,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+633,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1166,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+634,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+126,"sel_0", false,-1);
    tracep->declBit(c+127,"sel_1", false,-1);
    tracep->declBit(c+128,"sel_2", false,-1);
    tracep->declBit(c+129,"sel_3", false,-1);
    tracep->declBit(c+130,"sel_4", false,-1);
    tracep->declBit(c+131,"sel_5", false,-1);
    tracep->declBit(c+132,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+133,"auto_in_awready", false,-1);
    tracep->declBit(c+134,"auto_in_awvalid", false,-1);
    tracep->declBus(c+309,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1032,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1033,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+133,"auto_in_wready", false,-1);
    tracep->declBit(c+135,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+176,"auto_in_bready", false,-1);
    tracep->declBit(c+177,"auto_in_bvalid", false,-1);
    tracep->declBus(c+310,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+1140,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+136,"auto_in_arready", false,-1);
    tracep->declBit(c+137,"auto_in_arvalid", false,-1);
    tracep->declBus(c+311,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1036,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+942,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+178,"auto_in_rready", false,-1);
    tracep->declBit(c+179,"auto_in_rvalid", false,-1);
    tracep->declBus(c+312,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+180,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1140,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+109,"auto_out_psel", false,-1);
    tracep->declBit(c+307,"auto_out_penable", false,-1);
    tracep->declBit(c+110,"auto_out_pwrite", false,-1);
    tracep->declBus(c+108,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+111,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+174,"auto_out_pready", false,-1);
    tracep->declBit(c+113,"auto_out_pslverr", false,-1);
    tracep->declBus(c+175,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+307,"nodeOut_penable", false,-1);
    tracep->declBus(c+313,"state", false,-1, 1,0);
    tracep->declBit(c+136,"accept_read", false,-1);
    tracep->declBit(c+133,"accept_write", false,-1);
    tracep->declBit(c+314,"is_write_r", false,-1);
    tracep->declBit(c+110,"is_write", false,-1);
    tracep->declBus(c+312,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+310,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+315,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+316,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+317,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+318,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+138,"resp", false,-1, 1,0);
    tracep->declBus(c+319,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+1140,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+179,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+320,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+177,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+321,"auto_in_awready", false,-1);
    tracep->declBit(c+72,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1176,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1037,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1177,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1038,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+322,"auto_in_wready", false,-1);
    tracep->declBit(c+73,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1039,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1040,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1179,"auto_in_wlast", false,-1);
    tracep->declBit(c+1141,"auto_in_bready", false,-1);
    tracep->declBit(c+181,"auto_in_bvalid", false,-1);
    tracep->declBus(c+182,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+183,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+323,"auto_in_arready", false,-1);
    tracep->declBit(c+74,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1180,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+943,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+75,"auto_in_rready", false,-1);
    tracep->declBit(c+184,"auto_in_rvalid", false,-1);
    tracep->declBus(c+185,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+36,"auto_in_rlast", false,-1);
    tracep->declBit(c+186,"auto_out_awready", false,-1);
    tracep->declBit(c+76,"auto_out_awvalid", false,-1);
    tracep->declBus(c+309,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1032,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1033,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+324,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+187,"auto_out_wready", false,-1);
    tracep->declBit(c+77,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+78,"auto_out_wlast", false,-1);
    tracep->declBit(c+188,"auto_out_bready", false,-1);
    tracep->declBit(c+189,"auto_out_bvalid", false,-1);
    tracep->declBus(c+182,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+190,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+191,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+192,"auto_out_arready", false,-1);
    tracep->declBit(c+79,"auto_out_arvalid", false,-1);
    tracep->declBus(c+311,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1036,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+942,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+325,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+75,"auto_out_rready", false,-1);
    tracep->declBit(c+184,"auto_out_rvalid", false,-1);
    tracep->declBus(c+185,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+37,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+193,"auto_out_rlast", false,-1);
    tracep->declBit(c+77,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+326,"w_idle", false,-1);
    tracep->declBit(c+194,"in_awready", false,-1);
    tracep->declBit(c+327,"busy", false,-1);
    tracep->declBus(c+328,"r_addr", false,-1, 31,0);
    tracep->declBus(c+329,"r_len", false,-1, 7,0);
    tracep->declBus(c+330,"len", false,-1, 7,0);
    tracep->declBus(c+1042,"addr", false,-1, 31,0);
    tracep->declBit(c+331,"busy_1", false,-1);
    tracep->declBus(c+332,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+333,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+334,"len_1", false,-1, 7,0);
    tracep->declBus(c+1043,"addr_1", false,-1, 31,0);
    tracep->declBit(c+335,"wbeats_latched", false,-1);
    tracep->declBit(c+76,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+80,"wbeats_valid", false,-1);
    tracep->declBus(c+336,"w_counter", false,-1, 8,0);
    tracep->declBus(c+81,"w_todo", false,-1, 8,0);
    tracep->declBit(c+78,"w_last", false,-1);
    tracep->declBit(c+188,"nodeOut_bready", false,-1);
    tracep->declBus(c+337,"error_0", false,-1, 1,0);
    tracep->declBus(c+338,"error_1", false,-1, 1,0);
    tracep->declBus(c+339,"error_2", false,-1, 1,0);
    tracep->declBus(c+340,"error_3", false,-1, 1,0);
    tracep->declBus(c+341,"error_4", false,-1, 1,0);
    tracep->declBus(c+342,"error_5", false,-1, 1,0);
    tracep->declBus(c+343,"error_6", false,-1, 1,0);
    tracep->declBus(c+344,"error_7", false,-1, 1,0);
    tracep->declBus(c+345,"error_8", false,-1, 1,0);
    tracep->declBus(c+346,"error_9", false,-1, 1,0);
    tracep->declBus(c+347,"error_10", false,-1, 1,0);
    tracep->declBus(c+348,"error_11", false,-1, 1,0);
    tracep->declBus(c+349,"error_12", false,-1, 1,0);
    tracep->declBus(c+350,"error_13", false,-1, 1,0);
    tracep->declBus(c+351,"error_14", false,-1, 1,0);
    tracep->declBus(c+352,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+323,"io_enq_ready", false,-1);
    tracep->declBit(c+74,"io_enq_valid", false,-1);
    tracep->declBus(c+1180,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1041,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1181,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+943,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1178,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+195,"io_deq_ready", false,-1);
    tracep->declBit(c+79,"io_deq_valid", false,-1);
    tracep->declBus(c+311,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1044,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+353,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+942,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+354,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+355,"ram", false,-1, 48,0);
    tracep->declBit(c+357,"full", false,-1);
    tracep->declBit(c+79,"io_deq_valid_0", false,-1);
    tracep->declBit(c+196,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+321,"io_enq_ready", false,-1);
    tracep->declBit(c+72,"io_enq_valid", false,-1);
    tracep->declBus(c+1176,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1037,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1177,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1038,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1178,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+197,"io_deq_ready", false,-1);
    tracep->declBit(c+82,"io_deq_valid", false,-1);
    tracep->declBus(c+309,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1045,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+358,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1033,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+359,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+360,"ram", false,-1, 48,0);
    tracep->declBit(c+362,"full", false,-1);
    tracep->declBit(c+82,"io_deq_valid_0", false,-1);
    tracep->declBit(c+198,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+322,"io_enq_ready", false,-1);
    tracep->declBit(c+73,"io_enq_valid", false,-1);
    tracep->declBus(c+1039,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1040,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1179,"io_enq_bits_last", false,-1);
    tracep->declBit(c+199,"io_deq_ready", false,-1);
    tracep->declBit(c+83,"io_deq_valid", false,-1);
    tracep->declBus(c+1034,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1035,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+363,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+364,"ram", false,-1, 36,0);
    tracep->declBit(c+366,"full", false,-1);
    tracep->declBit(c+83,"io_deq_valid_0", false,-1);
    tracep->declBit(c+200,"do_enq", false,-1);
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
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+201,"auto_in_awready", false,-1);
    tracep->declBit(c+139,"auto_in_awvalid", false,-1);
    tracep->declBus(c+309,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1046,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1143,"auto_in_wready", false,-1);
    tracep->declBit(c+1144,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+202,"auto_in_bready", false,-1);
    tracep->declBit(c+367,"auto_in_bvalid", false,-1);
    tracep->declBus(c+368,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+369,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+203,"auto_in_arready", false,-1);
    tracep->declBit(c+1145,"auto_in_arvalid", false,-1);
    tracep->declBus(c+311,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1047,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+204,"auto_in_rready", false,-1);
    tracep->declBit(c+370,"auto_in_rvalid", false,-1);
    tracep->declBus(c+371,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+372,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+373,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+203,"nodeIn_arready", false,-1);
    tracep->declBit(c+201,"nodeIn_awready", false,-1);
    tracep->declBit(c+1048,"w_sel0", false,-1);
    tracep->declBit(c+367,"w_full", false,-1);
    tracep->declBus(c+368,"w_id", false,-1, 3,0);
    tracep->declBit(c+374,"r_sel1", false,-1);
    tracep->declBit(c+375,"w_sel1", false,-1);
    tracep->declBit(c+370,"r_full", false,-1);
    tracep->declBus(c+371,"r_id", false,-1, 3,0);
    tracep->declBit(c+205,"ren", false,-1);
    tracep->declBit(c+376,"rdata_REG", false,-1);
    tracep->declBus(c+377,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+378,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+379,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+380,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1049,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+205,"R0_en", false,-1);
    tracep->declBit(c+1106,"R0_clk", false,-1);
    tracep->declBus(c+381,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1050,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+206,"W0_en", false,-1);
    tracep->declBit(c+1106,"W0_clk", false,-1);
    tracep->declBus(c+1034,"W0_data", false,-1, 31,0);
    tracep->declBus(c+1035,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+321,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+72,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1176,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1037,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1177,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1038,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+322,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+73,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1039,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1040,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1179,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1141,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+181,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+182,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+183,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+323,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+74,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1180,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+943,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+75,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+184,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+185,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+36,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+321,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+72,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1176,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1037,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1177,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1038,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+322,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+73,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1039,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1040,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1179,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1141,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+181,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+182,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+183,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+323,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+74,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1180,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+943,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+75,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+184,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+185,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+36,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+207,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+84,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+309,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1032,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1033,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+187,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+77,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+78,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+188,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+189,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+182,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+190,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+208,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+85,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+311,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1036,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+942,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+75,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+184,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+185,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+193,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+201,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+139,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+309,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1046,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1143,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1144,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+202,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+367,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+368,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+369,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+203,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1145,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+311,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1047,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+204,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+370,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+371,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+372,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+373,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1146,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1147,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+382,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1148,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+311,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1149,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+383,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+384,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+385,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+133,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+134,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+309,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1032,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+1033,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+133,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+135,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+176,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+177,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+310,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+1140,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+136,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+137,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+311,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1036,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+942,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+178,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+179,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+312,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+180,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+1140,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+189,"in_0_bvalid", false,-1);
    tracep->declBit(c+184,"in_0_rvalid", false,-1);
    tracep->declBit(c+209,"in_0_wready", false,-1);
    tracep->declBit(c+210,"in_0_awready", false,-1);
    tracep->declBit(c+208,"in_0_arready", false,-1);
    tracep->declBit(c+207,"anonIn_awready", false,-1);
    tracep->declBit(c+1052,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1053,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1054,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1055,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1056,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1057,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+386,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+387,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+388,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+389,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+390,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+391,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+392,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+393,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+394,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+395,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+396,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+397,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+398,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+399,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+400,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+401,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+402,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+403,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+404,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+405,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+406,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+407,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+408,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+409,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+410,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+411,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+412,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+413,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+414,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+415,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+416,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+417,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+418,"latched", false,-1);
    tracep->declBit(c+86,"in_0_awvalid", false,-1);
    tracep->declBit(c+87,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+88,"in_0_wvalid", false,-1);
    tracep->declBit(c+419,"idle_3", false,-1);
    tracep->declBit(c+211,"anyValid", false,-1);
    tracep->declBus(c+212,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+420,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+213,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+214,"prefixOR_1", false,-1);
    tracep->declBit(c+215,"winner_3_1", false,-1);
    tracep->declBit(c+216,"winner_3_2", false,-1);
    tracep->declBit(c+421,"state_3_0", false,-1);
    tracep->declBit(c+422,"state_3_1", false,-1);
    tracep->declBit(c+423,"state_3_2", false,-1);
    tracep->declBit(c+217,"muxState_3_0", false,-1);
    tracep->declBit(c+218,"muxState_3_1", false,-1);
    tracep->declBit(c+219,"muxState_3_2", false,-1);
    tracep->declBit(c+424,"idle_4", false,-1);
    tracep->declBit(c+220,"anyValid_1", false,-1);
    tracep->declBus(c+221,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+425,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+222,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+223,"winner_4_0", false,-1);
    tracep->declBit(c+224,"winner_4_2", false,-1);
    tracep->declBit(c+426,"state_4_0", false,-1);
    tracep->declBit(c+427,"state_4_2", false,-1);
    tracep->declBit(c+225,"muxState_4_0", false,-1);
    tracep->declBit(c+226,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+428,"io_enq_ready", false,-1);
    tracep->declBit(c+87,"io_enq_valid", false,-1);
    tracep->declBus(c+1058,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+227,"io_deq_ready", false,-1);
    tracep->declBit(c+89,"io_deq_valid", false,-1);
    tracep->declBus(c+1059,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+429,"wrap", false,-1);
    tracep->declBit(c+430,"wrap_1", false,-1);
    tracep->declBit(c+431,"maybe_full", false,-1);
    tracep->declBit(c+432,"ptr_match", false,-1);
    tracep->declBit(c+433,"empty", false,-1);
    tracep->declBit(c+434,"full", false,-1);
    tracep->declBit(c+89,"io_deq_valid_0", false,-1);
    tracep->declBit(c+228,"do_deq", false,-1);
    tracep->declBit(c+229,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+430,"R0_addr", false,-1);
    tracep->declBit(c+1182,"R0_en", false,-1);
    tracep->declBit(c+1106,"R0_clk", false,-1);
    tracep->declBus(c+435,"R0_data", false,-1, 2,0);
    tracep->declBit(c+429,"W0_addr", false,-1);
    tracep->declBit(c+229,"W0_en", false,-1);
    tracep->declBit(c+1106,"W0_clk", false,-1);
    tracep->declBus(c+1058,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+436+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+186,"auto_in_awready", false,-1);
    tracep->declBit(c+76,"auto_in_awvalid", false,-1);
    tracep->declBus(c+309,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1032,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1033,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+324,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+187,"auto_in_wready", false,-1);
    tracep->declBit(c+77,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+78,"auto_in_wlast", false,-1);
    tracep->declBit(c+188,"auto_in_bready", false,-1);
    tracep->declBit(c+189,"auto_in_bvalid", false,-1);
    tracep->declBus(c+182,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+190,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+191,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+192,"auto_in_arready", false,-1);
    tracep->declBit(c+79,"auto_in_arvalid", false,-1);
    tracep->declBus(c+311,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1036,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+942,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+325,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+75,"auto_in_rready", false,-1);
    tracep->declBit(c+184,"auto_in_rvalid", false,-1);
    tracep->declBus(c+185,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+37,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+193,"auto_in_rlast", false,-1);
    tracep->declBit(c+207,"auto_out_awready", false,-1);
    tracep->declBit(c+84,"auto_out_awvalid", false,-1);
    tracep->declBus(c+309,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1032,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1033,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+187,"auto_out_wready", false,-1);
    tracep->declBit(c+77,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1034,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1035,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+78,"auto_out_wlast", false,-1);
    tracep->declBit(c+188,"auto_out_bready", false,-1);
    tracep->declBit(c+189,"auto_out_bvalid", false,-1);
    tracep->declBus(c+182,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+190,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+208,"auto_out_arready", false,-1);
    tracep->declBit(c+85,"auto_out_arvalid", false,-1);
    tracep->declBus(c+311,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1036,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+942,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+75,"auto_out_rready", false,-1);
    tracep->declBit(c+184,"auto_out_rvalid", false,-1);
    tracep->declBus(c+185,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+193,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+438,"io_enq_ready", false,-1);
    tracep->declBit(c+38,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+230,"io_deq_ready", false,-1);
    tracep->declBit(c+439,"io_deq_valid", false,-1);
    tracep->declBit(c+440,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+440,"ram_real_last", false,-1);
    tracep->declBit(c+439,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+441,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+442,"io_enq_ready", false,-1);
    tracep->declBit(c+39,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+231,"io_deq_ready", false,-1);
    tracep->declBit(c+443,"io_deq_valid", false,-1);
    tracep->declBit(c+444,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+444,"ram_real_last", false,-1);
    tracep->declBit(c+443,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+445,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+446,"io_enq_ready", false,-1);
    tracep->declBit(c+40,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+232,"io_deq_ready", false,-1);
    tracep->declBit(c+447,"io_deq_valid", false,-1);
    tracep->declBit(c+448,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+448,"ram_real_last", false,-1);
    tracep->declBit(c+447,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+449,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+450,"io_enq_ready", false,-1);
    tracep->declBit(c+41,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+233,"io_deq_ready", false,-1);
    tracep->declBit(c+451,"io_deq_valid", false,-1);
    tracep->declBit(c+452,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+452,"ram_real_last", false,-1);
    tracep->declBit(c+451,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+453,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+454,"io_enq_ready", false,-1);
    tracep->declBit(c+42,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+234,"io_deq_ready", false,-1);
    tracep->declBit(c+455,"io_deq_valid", false,-1);
    tracep->declBit(c+456,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+456,"ram_real_last", false,-1);
    tracep->declBit(c+455,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+457,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+458,"io_enq_ready", false,-1);
    tracep->declBit(c+43,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+235,"io_deq_ready", false,-1);
    tracep->declBit(c+459,"io_deq_valid", false,-1);
    tracep->declBit(c+460,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+460,"ram_real_last", false,-1);
    tracep->declBit(c+459,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+461,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+462,"io_enq_ready", false,-1);
    tracep->declBit(c+44,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+236,"io_deq_ready", false,-1);
    tracep->declBit(c+463,"io_deq_valid", false,-1);
    tracep->declBit(c+464,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+464,"ram_real_last", false,-1);
    tracep->declBit(c+463,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+465,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+466,"io_enq_ready", false,-1);
    tracep->declBit(c+45,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+237,"io_deq_ready", false,-1);
    tracep->declBit(c+467,"io_deq_valid", false,-1);
    tracep->declBit(c+468,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+468,"ram_real_last", false,-1);
    tracep->declBit(c+467,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+469,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+470,"io_enq_ready", false,-1);
    tracep->declBit(c+46,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+238,"io_deq_ready", false,-1);
    tracep->declBit(c+471,"io_deq_valid", false,-1);
    tracep->declBit(c+472,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+472,"ram_real_last", false,-1);
    tracep->declBit(c+471,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+473,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+474,"io_enq_ready", false,-1);
    tracep->declBit(c+47,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+239,"io_deq_ready", false,-1);
    tracep->declBit(c+475,"io_deq_valid", false,-1);
    tracep->declBit(c+476,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+476,"ram_real_last", false,-1);
    tracep->declBit(c+475,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+477,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+478,"io_enq_ready", false,-1);
    tracep->declBit(c+48,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+240,"io_deq_ready", false,-1);
    tracep->declBit(c+479,"io_deq_valid", false,-1);
    tracep->declBit(c+480,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+480,"ram_real_last", false,-1);
    tracep->declBit(c+479,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+481,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+482,"io_enq_ready", false,-1);
    tracep->declBit(c+49,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+241,"io_deq_ready", false,-1);
    tracep->declBit(c+483,"io_deq_valid", false,-1);
    tracep->declBit(c+484,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+484,"ram_real_last", false,-1);
    tracep->declBit(c+483,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+485,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+486,"io_enq_ready", false,-1);
    tracep->declBit(c+50,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+242,"io_deq_ready", false,-1);
    tracep->declBit(c+487,"io_deq_valid", false,-1);
    tracep->declBit(c+488,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+488,"ram_real_last", false,-1);
    tracep->declBit(c+487,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+489,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+490,"io_enq_ready", false,-1);
    tracep->declBit(c+51,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+243,"io_deq_ready", false,-1);
    tracep->declBit(c+491,"io_deq_valid", false,-1);
    tracep->declBit(c+492,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+492,"ram_real_last", false,-1);
    tracep->declBit(c+491,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+493,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+494,"io_enq_ready", false,-1);
    tracep->declBit(c+52,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+244,"io_deq_ready", false,-1);
    tracep->declBit(c+495,"io_deq_valid", false,-1);
    tracep->declBit(c+496,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+496,"ram_real_last", false,-1);
    tracep->declBit(c+495,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+497,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+498,"io_enq_ready", false,-1);
    tracep->declBit(c+53,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+245,"io_deq_ready", false,-1);
    tracep->declBit(c+499,"io_deq_valid", false,-1);
    tracep->declBit(c+500,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+500,"ram_real_last", false,-1);
    tracep->declBit(c+499,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+501,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+502,"io_enq_ready", false,-1);
    tracep->declBit(c+54,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+246,"io_deq_ready", false,-1);
    tracep->declBit(c+503,"io_deq_valid", false,-1);
    tracep->declBit(c+504,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+504,"ram_real_last", false,-1);
    tracep->declBit(c+503,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+505,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+506,"io_enq_ready", false,-1);
    tracep->declBit(c+55,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+247,"io_deq_ready", false,-1);
    tracep->declBit(c+507,"io_deq_valid", false,-1);
    tracep->declBit(c+508,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+508,"ram_real_last", false,-1);
    tracep->declBit(c+507,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+509,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+510,"io_enq_ready", false,-1);
    tracep->declBit(c+56,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+248,"io_deq_ready", false,-1);
    tracep->declBit(c+511,"io_deq_valid", false,-1);
    tracep->declBit(c+512,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+512,"ram_real_last", false,-1);
    tracep->declBit(c+511,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+513,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+514,"io_enq_ready", false,-1);
    tracep->declBit(c+57,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+249,"io_deq_ready", false,-1);
    tracep->declBit(c+515,"io_deq_valid", false,-1);
    tracep->declBit(c+516,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+516,"ram_real_last", false,-1);
    tracep->declBit(c+515,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+517,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+518,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+250,"io_deq_ready", false,-1);
    tracep->declBit(c+519,"io_deq_valid", false,-1);
    tracep->declBit(c+520,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+520,"ram_real_last", false,-1);
    tracep->declBit(c+519,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+521,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+522,"io_enq_ready", false,-1);
    tracep->declBit(c+59,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+251,"io_deq_ready", false,-1);
    tracep->declBit(c+523,"io_deq_valid", false,-1);
    tracep->declBit(c+524,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+524,"ram_real_last", false,-1);
    tracep->declBit(c+523,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+525,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+526,"io_enq_ready", false,-1);
    tracep->declBit(c+60,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+252,"io_deq_ready", false,-1);
    tracep->declBit(c+527,"io_deq_valid", false,-1);
    tracep->declBit(c+528,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+528,"ram_real_last", false,-1);
    tracep->declBit(c+527,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+529,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+530,"io_enq_ready", false,-1);
    tracep->declBit(c+61,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+253,"io_deq_ready", false,-1);
    tracep->declBit(c+531,"io_deq_valid", false,-1);
    tracep->declBit(c+532,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+532,"ram_real_last", false,-1);
    tracep->declBit(c+531,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+533,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+534,"io_enq_ready", false,-1);
    tracep->declBit(c+62,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+254,"io_deq_ready", false,-1);
    tracep->declBit(c+535,"io_deq_valid", false,-1);
    tracep->declBit(c+536,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+536,"ram_real_last", false,-1);
    tracep->declBit(c+535,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+537,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+538,"io_enq_ready", false,-1);
    tracep->declBit(c+63,"io_enq_valid", false,-1);
    tracep->declBit(c+324,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+255,"io_deq_ready", false,-1);
    tracep->declBit(c+539,"io_deq_valid", false,-1);
    tracep->declBit(c+540,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+540,"ram_real_last", false,-1);
    tracep->declBit(c+539,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+541,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+542,"io_enq_ready", false,-1);
    tracep->declBit(c+64,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+256,"io_deq_ready", false,-1);
    tracep->declBit(c+543,"io_deq_valid", false,-1);
    tracep->declBit(c+544,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+544,"ram_real_last", false,-1);
    tracep->declBit(c+543,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+545,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+546,"io_enq_ready", false,-1);
    tracep->declBit(c+65,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+257,"io_deq_ready", false,-1);
    tracep->declBit(c+547,"io_deq_valid", false,-1);
    tracep->declBit(c+548,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+548,"ram_real_last", false,-1);
    tracep->declBit(c+547,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+549,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+550,"io_enq_ready", false,-1);
    tracep->declBit(c+66,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+258,"io_deq_ready", false,-1);
    tracep->declBit(c+551,"io_deq_valid", false,-1);
    tracep->declBit(c+552,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+552,"ram_real_last", false,-1);
    tracep->declBit(c+551,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+553,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+554,"io_enq_ready", false,-1);
    tracep->declBit(c+67,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+259,"io_deq_ready", false,-1);
    tracep->declBit(c+555,"io_deq_valid", false,-1);
    tracep->declBit(c+556,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+556,"ram_real_last", false,-1);
    tracep->declBit(c+555,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+557,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+558,"io_enq_ready", false,-1);
    tracep->declBit(c+68,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+260,"io_deq_ready", false,-1);
    tracep->declBit(c+559,"io_deq_valid", false,-1);
    tracep->declBit(c+560,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+560,"ram_real_last", false,-1);
    tracep->declBit(c+559,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+561,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+562,"io_enq_ready", false,-1);
    tracep->declBit(c+69,"io_enq_valid", false,-1);
    tracep->declBit(c+325,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+261,"io_deq_ready", false,-1);
    tracep->declBit(c+563,"io_deq_valid", false,-1);
    tracep->declBit(c+564,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+564,"ram_real_last", false,-1);
    tracep->declBit(c+563,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+565,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+90,"reset", false,-1);
    tracep->declBit(c+321,"auto_master_out_awready", false,-1);
    tracep->declBit(c+72,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1176,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1037,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1177,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1038,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+322,"auto_master_out_wready", false,-1);
    tracep->declBit(c+73,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1039,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1040,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1179,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1141,"auto_master_out_bready", false,-1);
    tracep->declBit(c+181,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+182,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+183,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+323,"auto_master_out_arready", false,-1);
    tracep->declBit(c+74,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1180,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+943,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1178,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+75,"auto_master_out_rready", false,-1);
    tracep->declBit(c+184,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+185,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+35,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1142,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+36,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+90,"reset", false,-1);
    tracep->declBit(c+1166,"io_interrupt", false,-1);
    tracep->declBit(c+321,"io_master_awready", false,-1);
    tracep->declBit(c+72,"io_master_awvalid", false,-1);
    tracep->declBus(c+1037,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1176,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1177,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1038,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1178,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+322,"io_master_wready", false,-1);
    tracep->declBit(c+73,"io_master_wvalid", false,-1);
    tracep->declBus(c+1039,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+1040,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1179,"io_master_wlast", false,-1);
    tracep->declBit(c+1141,"io_master_bready", false,-1);
    tracep->declBit(c+181,"io_master_bvalid", false,-1);
    tracep->declBus(c+183,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+182,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+323,"io_master_arready", false,-1);
    tracep->declBit(c+74,"io_master_arvalid", false,-1);
    tracep->declBus(c+1041,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1180,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1181,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+943,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1178,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+75,"io_master_rready", false,-1);
    tracep->declBit(c+184,"io_master_rvalid", false,-1);
    tracep->declBus(c+1142,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+35,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+36,"io_master_rlast", false,-1);
    tracep->declBus(c+185,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1183,"io_slave_awready", false,-1);
    tracep->declBit(c+1166,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1184,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1185,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1181,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1186,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1187,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1188,"io_slave_wready", false,-1);
    tracep->declBit(c+1166,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1184,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1185,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1166,"io_slave_wlast", false,-1);
    tracep->declBit(c+1166,"io_slave_bready", false,-1);
    tracep->declBit(c+1189,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1190,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1191,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1192,"io_slave_arready", false,-1);
    tracep->declBit(c+1166,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1184,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1185,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1181,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1186,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1187,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1166,"io_slave_rready", false,-1);
    tracep->declBit(c+1193,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1194,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1195,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1196,"io_slave_rlast", false,-1);
    tracep->declBus(c+1197,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+944,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1060,"npc", false,-1, 31,0);
    tracep->declBus(c+859,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+945,"inst", false,-1, 31,0);
    tracep->declBit(c+946,"ifu_valid", false,-1);
    tracep->declBit(c+947,"ifu_arvalid", false,-1);
    tracep->declBit(c+948,"ifu_arready", false,-1);
    tracep->declBus(c+859,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+262,"ifu_rvalid", false,-1);
    tracep->declBit(c+944,"ifu_rready", false,-1);
    tracep->declBus(c+263,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+949,"reg_process", false,-1);
    tracep->declBus(c+950,"src1", false,-1, 4,0);
    tracep->declBus(c+951,"src2", false,-1, 4,0);
    tracep->declBus(c+952,"rd", false,-1, 4,0);
    tracep->declBus(c+953,"imm", false,-1, 31,0);
    tracep->declBit(c+954,"ebreaksig", false,-1);
    tracep->declBit(c+955,"mretsig", false,-1);
    tracep->declBit(c+956,"ecallsig", false,-1);
    tracep->declBit(c+957,"regew", false,-1);
    tracep->declBit(c+958,"memew", false,-1);
    tracep->declBit(c+959,"memer", false,-1);
    tracep->declBit(c+960,"muximm", false,-1);
    tracep->declBus(c+961,"func3", false,-1, 2,0);
    tracep->declBus(c+962,"muxsig", false,-1, 2,0);
    tracep->declBit(c+963,"func7", false,-1);
    tracep->declBit(c+964,"btypebranch", false,-1);
    tracep->declBit(c+965,"jalsig", false,-1);
    tracep->declBit(c+966,"jalrsig", false,-1);
    tracep->declBit(c+967,"auipcsig", false,-1);
    tracep->declBus(c+968,"aluop", false,-1, 1,0);
    tracep->declBit(c+969,"csrrw", false,-1);
    tracep->declBit(c+970,"csrrs", false,-1);
    tracep->declBit(c+946,"idu_valid", false,-1);
    tracep->declBus(c+971,"memmask", false,-1, 2,0);
    tracep->declBit(c+972,"memsextsig", false,-1);
    tracep->declBus(c+264,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1061,"regout1", false,-1, 31,0);
    tracep->declBus(c+1062,"regout2", false,-1, 31,0);
    tracep->declBus(c+860,"mepc", false,-1, 31,0);
    tracep->declBus(c+861,"mtvec", false,-1, 31,0);
    tracep->declBit(c+944,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1063,"res", false,-1, 31,0);
    tracep->declBus(c+1064,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+946,"exu_valid", false,-1);
    tracep->declBit(c+944,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1150,"memvalid", false,-1);
    tracep->declBus(c+973,"awvalid", false,-1, 1,0);
    tracep->declBus(c+973,"wvalid", false,-1, 1,0);
    tracep->declBus(c+974,"arvalid", false,-1, 1,0);
    tracep->declBus(c+975,"rready", false,-1, 1,0);
    tracep->declBus(c+976,"bready", false,-1, 1,0);
    tracep->declBus(c+70,"bvalid", false,-1, 1,0);
    tracep->declBus(c+265,"rvalid", false,-1, 1,0);
    tracep->declBus(c+566,"awready", false,-1, 1,0);
    tracep->declBus(c+566,"wready", false,-1, 1,0);
    tracep->declBus(c+977,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1151+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+266+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1065+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1067+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1069+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+268+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1071+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+978+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1198,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+90,"reset", false,-1);
    tracep->declBus(c+973,"awvalid", false,-1, 1,0);
    tracep->declBus(c+973,"wvalid", false,-1, 1,0);
    tracep->declBus(c+974,"arvalid", false,-1, 1,0);
    tracep->declBus(c+975,"rready", false,-1, 1,0);
    tracep->declBus(c+976,"bready", false,-1, 1,0);
    tracep->declBus(c+70,"bvalid", false,-1, 1,0);
    tracep->declBus(c+265,"rvalid", false,-1, 1,0);
    tracep->declBus(c+566,"awready", false,-1, 1,0);
    tracep->declBus(c+566,"wready", false,-1, 1,0);
    tracep->declBus(c+977,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1073+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1075+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1077+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1079+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+270+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+272+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1081+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+980+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->declBit(c+72,"awvalid_out", false,-1);
    tracep->declBit(c+73,"wvalid_out", false,-1);
    tracep->declBit(c+74,"arvalid_out", false,-1);
    tracep->declBit(c+75,"rready_out", false,-1);
    tracep->declBit(c+1141,"bready_out", false,-1);
    tracep->declBit(c+181,"bvalid_in", false,-1);
    tracep->declBit(c+184,"rvalid_in", false,-1);
    tracep->declBit(c+322,"awready_in", false,-1);
    tracep->declBit(c+322,"wready_in", false,-1);
    tracep->declBit(c+323,"arready_in", false,-1);
    tracep->declBus(c+1041,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1037,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1039,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+1040,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+35,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+183,"bresp_in", false,-1, 1,0);
    tracep->declBus(c+1038,"awsize_out", false,-1, 2,0);
    tracep->declBus(c+943,"arsize_out", false,-1, 2,0);
    tracep->declBit(c+567,"busy", false,-1);
    tracep->declBus(c+568,"giant", false,-1, 1,0);
    tracep->declBus(c+569,"i", false,-1, 31,0);
    tracep->declBus(c+1037,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1039,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1041,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1040,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1038,"awsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+943,"arsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1199,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+961,"func3", false,-1, 2,0);
    tracep->declBit(c+964,"btypebranch", false,-1);
    tracep->declBit(c+963,"func7", false,-1);
    tracep->declBus(c+968,"aluop", false,-1, 1,0);
    tracep->declBit(c+966,"jalrsig", false,-1);
    tracep->declBit(c+965,"jalsig", false,-1);
    tracep->declBus(c+953,"imm", false,-1, 31,0);
    tracep->declBit(c+960,"muximm", false,-1);
    tracep->declBus(c+1061,"regout1", false,-1, 31,0);
    tracep->declBus(c+1062,"regout2", false,-1, 31,0);
    tracep->declBus(c+859,"pc", false,-1, 31,0);
    tracep->declBit(c+967,"auipcsig", false,-1);
    tracep->declBit(c+955,"mretsig", false,-1);
    tracep->declBit(c+956,"ecallsig", false,-1);
    tracep->declBus(c+861,"mtvec", false,-1, 31,0);
    tracep->declBus(c+860,"mepc", false,-1, 31,0);
    tracep->declBit(c+946,"valid_from", false,-1);
    tracep->declBit(c+944,"ready_from", false,-1);
    tracep->declBus(c+1063,"res", false,-1, 31,0);
    tracep->declBus(c+1060,"npc", false,-1, 31,0);
    tracep->declBus(c+1064,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+946,"valid_to", false,-1);
    tracep->declBit(c+944,"ready_to", false,-1);
    tracep->declBus(c+862,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1083,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+982,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1084,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1085,"zero", false,-1);
    tracep->declBit(c+1086,"signal", false,-1);
    tracep->declBit(c+1087,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1061,"A", false,-1, 31,0);
    tracep->declBus(c+1084,"B", false,-1, 31,0);
    tracep->declBus(c+982,"op", false,-1, 4,0);
    tracep->declBus(c+1063,"res", false,-1, 31,0);
    tracep->declBit(c+1085,"zero", false,-1);
    tracep->declBit(c+1086,"signal", false,-1);
    tracep->declBit(c+1087,"carry", false,-1);
    tracep->declBit(c+983,"addsig", false,-1);
    tracep->declBit(c+984,"logsig", false,-1);
    tracep->declBit(c+985,"shfsig", false,-1);
    tracep->declBit(c+986,"sltsig", false,-1);
    tracep->declBit(c+1087,"carry_tmp", false,-1);
    tracep->declBit(c+987,"type_I", false,-1);
    tracep->declBus(c+1088,"logres", false,-1, 31,0);
    tracep->declBus(c+1089,"addres", false,-1, 31,0);
    tracep->declBit(c+1090,"addzero", false,-1);
    tracep->declBus(c+1091,"shfres", false,-1, 31,0);
    tracep->declBus(c+1092,"sltres", false,-1, 31,0);
    tracep->declBus(c+1061,"A_s", false,-1, 31,0);
    tracep->declBus(c+1084,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+961,"func3", false,-1, 2,0);
    tracep->declBit(c+963,"func7", false,-1);
    tracep->declBus(c+968,"aluop", false,-1, 1,0);
    tracep->declBit(c+966,"jalrsig", false,-1);
    tracep->declBus(c+982,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+987,"type_I", false,-1);
    tracep->declBit(c+988,"type_B", false,-1);
    tracep->declBit(c+989,"type_R", false,-1);
    tracep->declBit(c+990,"addsig", false,-1);
    tracep->declBus(c+991,"branchop", false,-1, 3,0);
    tracep->declBus(c+992,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+964,"btypebranch", false,-1);
    tracep->declBus(c+961,"func3", false,-1, 2,0);
    tracep->declBit(c+1085,"zero", false,-1);
    tracep->declBit(c+1086,"signal", false,-1);
    tracep->declBit(c+1087,"carry", false,-1);
    tracep->declBus(c+1063,"res", false,-1, 31,0);
    tracep->declBus(c+862,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1083,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+965,"jalsig", false,-1);
    tracep->declBit(c+966,"jalrsig", false,-1);
    tracep->declBit(c+967,"auipcsig", false,-1);
    tracep->declBit(c+955,"mretsig", false,-1);
    tracep->declBit(c+956,"ecallsig", false,-1);
    tracep->declBus(c+861,"mtvec", false,-1, 31,0);
    tracep->declBus(c+860,"mepc", false,-1, 31,0);
    tracep->declBus(c+1060,"npc", false,-1, 31,0);
    tracep->declBus(c+1064,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1198,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1200,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1201,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1084,"out", false,-1, 31,0);
    tracep->declBus(c+960,"key", false,-1, 0,0);
    tracep->declArray(c+1023,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1198,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1200,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1201,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1202,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1084,"out", false,-1, 31,0);
    tracep->declBus(c+960,"key", false,-1, 0,0);
    tracep->declBus(c+1184,"default_out", false,-1, 31,0);
    tracep->declArray(c+1023,"lut", false,-1, 65,0);
    tracep->declBus(c+1203,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1026+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1030+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1093,"lut_out", false,-1, 31,0);
    tracep->declBit(c+993,"hit", false,-1);
    tracep->declBus(c+1204,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+859,"pc", false,-1, 31,0);
    tracep->declBus(c+862,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+859,"pc", false,-1, 31,0);
    tracep->declBus(c+953,"imm", false,-1, 31,0);
    tracep->declBus(c+1083,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+945,"inst", false,-1, 31,0);
    tracep->declBit(c+946,"valid_from", false,-1);
    tracep->declBit(c+944,"ready_from", false,-1);
    tracep->declBit(c+954,"ebreaksig", false,-1);
    tracep->declBit(c+956,"ecallsig", false,-1);
    tracep->declBit(c+955,"mretsig", false,-1);
    tracep->declBus(c+953,"imm", false,-1, 31,0);
    tracep->declBus(c+961,"func3", false,-1, 2,0);
    tracep->declBit(c+963,"func7", false,-1);
    tracep->declBus(c+950,"src1", false,-1, 4,0);
    tracep->declBus(c+951,"src2", false,-1, 4,0);
    tracep->declBus(c+952,"rd", false,-1, 4,0);
    tracep->declBit(c+958,"memew", false,-1);
    tracep->declBus(c+962,"muxsig", false,-1, 2,0);
    tracep->declBit(c+959,"memer", false,-1);
    tracep->declBit(c+957,"regew", false,-1);
    tracep->declBit(c+960,"muximm", false,-1);
    tracep->declBit(c+964,"btypebranch", false,-1);
    tracep->declBit(c+966,"jalrsig", false,-1);
    tracep->declBit(c+965,"jalsig", false,-1);
    tracep->declBus(c+968,"aluop", false,-1, 1,0);
    tracep->declBit(c+967,"auipcsig", false,-1);
    tracep->declBit(c+969,"csrrw", false,-1);
    tracep->declBit(c+970,"csrrs", false,-1);
    tracep->declBit(c+946,"valid_to", false,-1);
    tracep->declBit(c+944,"ready_to", false,-1);
    tracep->declBus(c+971,"memmask", false,-1, 2,0);
    tracep->declBit(c+972,"memsextsig", false,-1);
    tracep->declBit(c+954,"ebreak", false,-1);
    tracep->declBit(c+956,"ecall", false,-1);
    tracep->declBit(c+955,"mret", false,-1);
    tracep->declBus(c+961,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+963,"func7bridge", false,-1);
    tracep->declBus(c+994,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+945,"inst", false,-1, 31,0);
    tracep->declBit(c+954,"ebreaksig", false,-1);
    tracep->declBit(c+956,"ecallsig", false,-1);
    tracep->declBit(c+955,"mretsig", false,-1);
    tracep->declBus(c+953,"imm", false,-1, 31,0);
    tracep->declBus(c+994,"opcode", false,-1, 6,0);
    tracep->declBus(c+961,"func3", false,-1, 2,0);
    tracep->declBit(c+963,"func7", false,-1);
    tracep->declBus(c+950,"src1", false,-1, 4,0);
    tracep->declBus(c+951,"src2", false,-1, 4,0);
    tracep->declBus(c+952,"rd", false,-1, 4,0);
    tracep->declBus(c+971,"memmask", false,-1, 2,0);
    tracep->declBit(c+972,"memsextsig", false,-1);
    tracep->declBit(c+995,"type_I", false,-1);
    tracep->declBit(c+996,"type_R", false,-1);
    tracep->declBit(c+997,"type_U", false,-1);
    tracep->declBit(c+958,"type_S", false,-1);
    tracep->declBit(c+965,"type_J", false,-1);
    tracep->declBit(c+964,"type_B", false,-1);
    tracep->declBus(c+998,"I_imm", false,-1, 31,0);
    tracep->declBus(c+999,"U_imm", false,-1, 31,0);
    tracep->declBus(c+1000,"S_imm", false,-1, 31,0);
    tracep->declBus(c+1001,"J_imm", false,-1, 31,0);
    tracep->declBus(c+1002,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+994,"opcode", false,-1, 6,0);
    tracep->declBus(c+961,"func3", false,-1, 2,0);
    tracep->declBit(c+963,"func7", false,-1);
    tracep->declBit(c+954,"ebreaksig", false,-1);
    tracep->declBit(c+956,"ecallsig", false,-1);
    tracep->declBit(c+955,"mretsig", false,-1);
    tracep->declBit(c+958,"memew", false,-1);
    tracep->declBus(c+962,"muxsig", false,-1, 2,0);
    tracep->declBit(c+959,"memer", false,-1);
    tracep->declBit(c+957,"regew", false,-1);
    tracep->declBit(c+960,"muximm", false,-1);
    tracep->declBit(c+964,"btypebranch", false,-1);
    tracep->declBit(c+966,"jalrsig", false,-1);
    tracep->declBit(c+965,"jalsig", false,-1);
    tracep->declBus(c+968,"aluop", false,-1, 1,0);
    tracep->declBit(c+967,"auipcsig", false,-1);
    tracep->declBit(c+969,"csrrw", false,-1);
    tracep->declBit(c+970,"csrrs", false,-1);
    tracep->declBit(c+995,"type_I", false,-1);
    tracep->declBit(c+996,"type_R", false,-1);
    tracep->declBit(c+997,"type_U", false,-1);
    tracep->declBit(c+958,"type_S", false,-1);
    tracep->declBit(c+965,"type_J", false,-1);
    tracep->declBit(c+964,"type_B", false,-1);
    tracep->declBit(c+959,"load", false,-1);
    tracep->declBit(c+958,"store", false,-1);
    tracep->declBit(c+1003,"regwritepc", false,-1);
    tracep->declBit(c+959,"regwritemem", false,-1);
    tracep->declBit(c+1004,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+90,"rst", false,-1);
    tracep->declBus(c+1060,"npc", false,-1, 31,0);
    tracep->declBit(c+944,"ready", false,-1);
    tracep->declBus(c+859,"pc", false,-1, 31,0);
    tracep->declBus(c+945,"inst", false,-1, 31,0);
    tracep->declBit(c+946,"valid", false,-1);
    tracep->declBit(c+949,"regprocess", false,-1);
    tracep->declBit(c+947,"arvalid", false,-1);
    tracep->declBit(c+948,"arready", false,-1);
    tracep->declBus(c+859,"araddr", false,-1, 31,0);
    tracep->declBit(c+262,"rvalid", false,-1);
    tracep->declBit(c+944,"rready", false,-1);
    tracep->declBus(c+263,"rdata", false,-1, 31,0);
    tracep->declBus(c+859,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1005,"infetch_ready", false,-1);
    tracep->declBus(c+1006,"state", false,-1, 2,0);
    tracep->declBus(c+945,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBus(c+1060,"npc", false,-1, 31,0);
    tracep->declBit(c+90,"rst", false,-1);
    tracep->declBit(c+1005,"ready_from", false,-1);
    tracep->declBus(c+859,"pcout", false,-1, 31,0);
    tracep->declBus(c+1205,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+90,"rst", false,-1);
    tracep->declBit(c+1153,"ew", false,-1);
    tracep->declBus(c+952,"addr", false,-1, 4,0);
    tracep->declBus(c+950,"src1", false,-1, 4,0);
    tracep->declBus(c+951,"src2", false,-1, 4,0);
    tracep->declBus(c+1007,"csr", false,-1, 11,0);
    tracep->declBus(c+264,"data", false,-1, 31,0);
    tracep->declBit(c+969,"csrrw", false,-1);
    tracep->declBit(c+970,"csrrs", false,-1);
    tracep->declBit(c+956,"ecallsig", false,-1);
    tracep->declBit(c+946,"valid", false,-1);
    tracep->declBus(c+1061,"regout1", false,-1, 31,0);
    tracep->declBus(c+1062,"regout2", false,-1, 31,0);
    tracep->declBus(c+860,"mepc", false,-1, 31,0);
    tracep->declBus(c+861,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+863+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+895+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1008,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+274,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1206,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1207,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1198,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1008,"out", false,-1, 1,0);
    tracep->declBus(c+1007,"key", false,-1, 11,0);
    tracep->declQuad(c+1208,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1206,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1207,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1198,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1202,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1008,"out", false,-1, 1,0);
    tracep->declBus(c+1007,"key", false,-1, 11,0);
    tracep->declBus(c+1187,"default_out", false,-1, 1,0);
    tracep->declQuad(c+1208,"lut", false,-1, 55,0);
    tracep->declBus(c+1210,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1009,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1010,"hit", false,-1);
    tracep->declBus(c+1211,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+90,"rst", false,-1);
    tracep->declBit(c+1154,"ew", false,-1);
    tracep->declBit(c+969,"csrrw", false,-1);
    tracep->declBit(c+970,"csrrs", false,-1);
    tracep->declBit(c+956,"ecall", false,-1);
    tracep->declBus(c+1008,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+952,"addr", false,-1, 4,0);
    tracep->declBus(c+274,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+899+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+931+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+935,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBus(c+1063,"res", false,-1, 31,0);
    tracep->declBus(c+1062,"regout2", false,-1, 31,0);
    tracep->declBit(c+958,"memew", false,-1);
    tracep->declBit(c+959,"memer", false,-1);
    tracep->declBus(c+953,"imm", false,-1, 31,0);
    tracep->declBus(c+1064,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+962,"muxsig", false,-1, 2,0);
    tracep->declBit(c+946,"valid_from", false,-1);
    tracep->declBus(c+971,"memmask", false,-1, 2,0);
    tracep->declBit(c+972,"memsextsig", false,-1);
    tracep->declBus(c+264,"regwrite", false,-1, 31,0);
    tracep->declBit(c+944,"ready_to", false,-1);
    tracep->declBit(c+1150,"memvalid", false,-1);
    tracep->declBit(c+1011,"awvalid", false,-1);
    tracep->declBit(c+570,"awready", false,-1);
    tracep->declBus(c+1063,"awaddr", false,-1, 31,0);
    tracep->declBit(c+1011,"wvalid", false,-1);
    tracep->declBit(c+570,"wready", false,-1);
    tracep->declBus(c+1062,"wdata", false,-1, 31,0);
    tracep->declBus(c+1094,"wstrb", false,-1, 3,0);
    tracep->declBit(c+71,"bvalid", false,-1);
    tracep->declBit(c+958,"bready", false,-1);
    tracep->declBus(c+275,"bresp", false,-1, 1,0);
    tracep->declBit(c+1155,"arvalid", false,-1);
    tracep->declBit(c+1012,"arready", false,-1);
    tracep->declBus(c+1063,"araddr", false,-1, 31,0);
    tracep->declBit(c+276,"rvalid", false,-1);
    tracep->declBit(c+959,"rready", false,-1);
    tracep->declBus(c+277,"rdata", false,-1, 31,0);
    tracep->declBus(c+1095,"awsize", false,-1, 2,0);
    tracep->declBus(c+971,"arsize", false,-1, 2,0);
    tracep->declBus(c+571,"state", false,-1, 1,0);
    tracep->declBus(c+278,"memread", false,-1, 31,0);
    tracep->declBit(c+1156,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+277,"data", false,-1, 31,0);
    tracep->declBus(c+971,"memmask", false,-1, 2,0);
    tracep->declBit(c+972,"memsextsig", false,-1);
    tracep->declBus(c+1096,"addr_offset", false,-1, 1,0);
    tracep->declBus(c+278,"read", false,-1, 31,0);
    tracep->declBus(c+279,"read_u", false,-1, 31,0);
    tracep->declBus(c+280,"read_s", false,-1, 31,0);
    tracep->declBus(c+281,"read_sb", false,-1, 31,0);
    tracep->declBus(c+282,"read_sh", false,-1, 31,0);
    tracep->declBus(c+283,"byte_data", false,-1, 7,0);
    tracep->declBus(c+284,"halfword_data", false,-1, 15,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1212,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1201,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+283,"input_number", false,-1, 7,0);
    tracep->declBus(c+281,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1213,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1201,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+284,"input_number", false,-1, 15,0);
    tracep->declBus(c+282,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1206,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1214,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1201,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+264,"out", false,-1, 31,0);
    tracep->declBus(c+962,"key", false,-1, 2,0);
    tracep->declBus(c+1202,"default_out", false,-1, 31,0);
    tracep->declArray(c+91,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1206,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1214,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1201,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1200,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+264,"out", false,-1, 31,0);
    tracep->declBus(c+962,"key", false,-1, 2,0);
    tracep->declBus(c+1202,"default_out", false,-1, 31,0);
    tracep->declArray(c+91,"lut", false,-1, 139,0);
    tracep->declBus(c+1215,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+96+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+104+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+285,"lut_out", false,-1, 31,0);
    tracep->declBit(c+286,"hit", false,-1);
    tracep->declBus(c+1211,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("strbcontol ");
    tracep->declBus(c+1062,"wdata_in", false,-1, 31,0);
    tracep->declBus(c+1063,"awaddr", false,-1, 31,0);
    tracep->declBus(c+971,"wirtelen", false,-1, 2,0);
    tracep->declBus(c+1094,"wstrb", false,-1, 3,0);
    tracep->declBus(c+1095,"awsize", false,-1, 2,0);
    tracep->declBit(c+1097,"insram", false,-1);
    tracep->declBus(c+1098,"bus_size", false,-1, 1,0);
    tracep->declBus(c+1013,"wstrb_general", false,-1, 3,0);
    tracep->declBus(c+1216,"wstrb_byte", false,-1, 3,0);
    tracep->declBus(c+1217,"wstrb_halfword", false,-1, 3,0);
    tracep->declBus(c+1218,"wstrb_word", false,-1, 3,0);
    tracep->pushNamePrefix("len_mux ");
    tracep->declBus(c+1214,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1198,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1214,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1095,"out", false,-1, 2,0);
    tracep->declBus(c+1098,"key", false,-1, 1,0);
    tracep->declBus(c+971,"default_out", false,-1, 2,0);
    tracep->declBus(c+1219,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1214,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1198,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1214,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1200,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1095,"out", false,-1, 2,0);
    tracep->declBus(c+1098,"key", false,-1, 1,0);
    tracep->declBus(c+971,"default_out", false,-1, 2,0);
    tracep->declBus(c+1219,"lut", false,-1, 14,0);
    tracep->declBus(c+1220,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+19+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+22+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+25+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1099,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1100,"hit", false,-1);
    tracep->declBus(c+1221,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("type_mux ");
    tracep->declBus(c+1200,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1200,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1198,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1098,"out", false,-1, 1,0);
    tracep->declBus(c+1097,"key", false,-1, 0,0);
    tracep->declBus(c+1187,"default_out", false,-1, 1,0);
    tracep->declBus(c+1222,"lut", false,-1, 2,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1200,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1200,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1198,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1200,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1098,"out", false,-1, 1,0);
    tracep->declBus(c+1097,"key", false,-1, 0,0);
    tracep->declBus(c+1187,"default_out", false,-1, 1,0);
    tracep->declBus(c+1222,"lut", false,-1, 2,0);
    tracep->declBus(c+1214,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+28+i*1,"pair_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+29+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+30+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1101,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1102,"hit", false,-1);
    tracep->declBus(c+1223,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wstrb_mux ");
    tracep->declBus(c+1206,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1198,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1206,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1094,"out", false,-1, 3,0);
    tracep->declBus(c+1098,"key", false,-1, 1,0);
    tracep->declBus(c+1014,"lut", false,-1, 23,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1206,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1198,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1206,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1202,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1094,"out", false,-1, 3,0);
    tracep->declBus(c+1098,"key", false,-1, 1,0);
    tracep->declBus(c+1185,"default_out", false,-1, 3,0);
    tracep->declBus(c+1014,"lut", false,-1, 23,0);
    tracep->declBus(c+1224,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1015+i*1,"pair_list", true,(i+0), 5,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+31+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1019+i*1,"data_list", true,(i+0), 3,0);
    }
    tracep->declBus(c+1103,"lut_out", false,-1, 3,0);
    tracep->declBit(c+1104,"hit", false,-1);
    tracep->declBus(c+1211,"i", false,-1, 31,0);
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"io_d", false,-1);
    tracep->declBit(c+572,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"io_d", false,-1);
    tracep->declBit(c+572,"io_q", false,-1);
    tracep->declBit(c+572,"sync_0", false,-1);
    tracep->declBit(c+573,"sync_1", false,-1);
    tracep->declBit(c+574,"sync_2", false,-1);
    tracep->declBit(c+575,"sync_3", false,-1);
    tracep->declBit(c+576,"sync_4", false,-1);
    tracep->declBit(c+577,"sync_5", false,-1);
    tracep->declBit(c+578,"sync_6", false,-1);
    tracep->declBit(c+579,"sync_7", false,-1);
    tracep->declBit(c+580,"sync_8", false,-1);
    tracep->declBit(c+581,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+119,"auto_in_psel", false,-1);
    tracep->declBit(c+1136,"auto_in_penable", false,-1);
    tracep->declBit(c+110,"auto_in_pwrite", false,-1);
    tracep->declBus(c+118,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1165,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1173,"auto_in_pready", false,-1);
    tracep->declBit(c+1174,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1175,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1108,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1109,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1110,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1111,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1112,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1113,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1114,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1115,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1116,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1117,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+140,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+119,"in_psel", false,-1);
    tracep->declBit(c+1136,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1173,"in_pready", false,-1);
    tracep->declBus(c+1175,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1174,"in_pslverr", false,-1);
    tracep->declBus(c+1108,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1109,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1110,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1111,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1112,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1113,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1114,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1115,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1116,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1117,"gpio_seg_7", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+117,"auto_in_psel", false,-1);
    tracep->declBit(c+1135,"auto_in_penable", false,-1);
    tracep->declBit(c+110,"auto_in_pwrite", false,-1);
    tracep->declBus(c+118,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1165,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1170,"auto_in_pready", false,-1);
    tracep->declBit(c+1171,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1172,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1118,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1119,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+140,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+117,"in_psel", false,-1);
    tracep->declBit(c+1135,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1170,"in_pready", false,-1);
    tracep->declBus(c+1172,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1171,"in_pslverr", false,-1);
    tracep->declBit(c+1118,"ps2_clk", false,-1);
    tracep->declBit(c+1119,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+1146,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1147,"auto_in_wvalid", false,-1);
    tracep->declBit(c+382,"auto_in_arready", false,-1);
    tracep->declBit(c+1148,"auto_in_arvalid", false,-1);
    tracep->declBus(c+311,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1149,"auto_in_rready", false,-1);
    tracep->declBit(c+383,"auto_in_rvalid", false,-1);
    tracep->declBus(c+384,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+385,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+383,"state", false,-1);
    tracep->declBus(c+385,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+384,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1105,"raddr", false,-1, 31,0);
    tracep->declBit(c+141,"ren", false,-1);
    tracep->declBus(c+142,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+120,"auto_in_psel", false,-1);
    tracep->declBit(c+1137,"auto_in_penable", false,-1);
    tracep->declBit(c+110,"auto_in_pwrite", false,-1);
    tracep->declBus(c+108,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1165,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1138,"auto_in_pready", false,-1);
    tracep->declBit(c+1166,"auto_in_pslverr", false,-1);
    tracep->declBus(c+308,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1130,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+1131,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+173,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+108,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+120,"in_psel", false,-1);
    tracep->declBit(c+1137,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1138,"in_pready", false,-1);
    tracep->declBus(c+308,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1166,"in_pslverr", false,-1);
    tracep->declBit(c+1130,"qspi_sck", false,-1);
    tracep->declBit(c+1131,"qspi_ce_n", false,-1);
    tracep->declBus(c+173,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+173,"din", false,-1, 3,0);
    tracep->declBus(c+287,"dout", false,-1, 3,0);
    tracep->declBus(c+288,"douten", false,-1, 3,0);
    tracep->declBit(c+1157,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1106,"clk_i", false,-1);
    tracep->declBit(c+1107,"rst_i", false,-1);
    tracep->declBus(c+108,"adr_i", false,-1, 31,0);
    tracep->declBus(c+111,"dat_i", false,-1, 31,0);
    tracep->declBus(c+308,"dat_o", false,-1, 31,0);
    tracep->declBus(c+112,"sel_i", false,-1, 3,0);
    tracep->declBit(c+120,"cyc_i", false,-1);
    tracep->declBit(c+120,"stb_i", false,-1);
    tracep->declBit(c+1157,"ack_o", false,-1);
    tracep->declBit(c+110,"we_i", false,-1);
    tracep->declBit(c+1130,"sck", false,-1);
    tracep->declBit(c+1131,"ce_n", false,-1);
    tracep->declBus(c+173,"din", false,-1, 3,0);
    tracep->declBus(c+287,"dout", false,-1, 3,0);
    tracep->declBus(c+288,"douten", false,-1, 3,0);
    tracep->declBus(c+1225,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1226,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+635,"mr_sck", false,-1);
    tracep->declBit(c+636,"mr_ce_n", false,-1);
    tracep->declBus(c+173,"mr_din", false,-1, 3,0);
    tracep->declBus(c+637,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+638,"mr_doe", false,-1);
    tracep->declBit(c+639,"mw_sck", false,-1);
    tracep->declBit(c+640,"mw_ce_n", false,-1);
    tracep->declBus(c+173,"mw_din", false,-1, 3,0);
    tracep->declBus(c+289,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+641,"mw_doe", false,-1);
    tracep->declBit(c+290,"mr_rd", false,-1);
    tracep->declBit(c+642,"mr_done", false,-1);
    tracep->declBit(c+291,"mw_wr", false,-1);
    tracep->declBit(c+292,"mw_done", false,-1);
    tracep->declBit(c+120,"wb_valid", false,-1);
    tracep->declBit(c+143,"wb_we", false,-1);
    tracep->declBit(c+144,"wb_re", false,-1);
    tracep->declBit(c+643,"state", false,-1);
    tracep->declBit(c+293,"nstate", false,-1);
    tracep->declBus(c+145,"size", false,-1, 2,0);
    tracep->declBus(c+146,"byte0", false,-1, 7,0);
    tracep->declBus(c+147,"byte1", false,-1, 7,0);
    tracep->declBus(c+148,"byte2", false,-1, 7,0);
    tracep->declBus(c+149,"byte3", false,-1, 7,0);
    tracep->declBus(c+150,"wdata", false,-1, 31,0);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1158,"rst_n", false,-1);
    tracep->declBus(c+151,"addr", false,-1, 23,0);
    tracep->declBit(c+290,"rd", false,-1);
    tracep->declBus(c+1227,"size", false,-1, 2,0);
    tracep->declBit(c+642,"done", false,-1);
    tracep->declBus(c+308,"line", false,-1, 31,0);
    tracep->declBit(c+635,"sck", false,-1);
    tracep->declBit(c+636,"ce_n", false,-1);
    tracep->declBus(c+173,"din", false,-1, 3,0);
    tracep->declBus(c+637,"dout", false,-1, 3,0);
    tracep->declBit(c+638,"douten", false,-1);
    tracep->declBus(c+1225,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1226,"READ", false,-1, 0,0);
    tracep->declBus(c+1228,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+644,"state", false,-1);
    tracep->declBit(c+294,"nstate", false,-1);
    tracep->declBus(c+645,"counter", false,-1, 7,0);
    tracep->declBus(c+646,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+582+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1229,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+647,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1158,"rst_n", false,-1);
    tracep->declBus(c+152,"addr", false,-1, 23,0);
    tracep->declBus(c+150,"line", false,-1, 31,0);
    tracep->declBus(c+145,"size", false,-1, 2,0);
    tracep->declBit(c+291,"wr", false,-1);
    tracep->declBit(c+292,"done", false,-1);
    tracep->declBit(c+639,"sck", false,-1);
    tracep->declBit(c+640,"ce_n", false,-1);
    tracep->declBus(c+173,"din", false,-1, 3,0);
    tracep->declBus(c+289,"dout", false,-1, 3,0);
    tracep->declBit(c+641,"douten", false,-1);
    tracep->declBus(c+1225,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1226,"WRITE", false,-1, 0,0);
    tracep->declBus(c+153,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+648,"state", false,-1);
    tracep->declBit(c+295,"nstate", false,-1);
    tracep->declBus(c+649,"counter", false,-1, 7,0);
    tracep->declBus(c+650,"saddr", false,-1, 23,0);
    tracep->declBus(c+1230,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+114,"auto_in_psel", false,-1);
    tracep->declBit(c+1133,"auto_in_penable", false,-1);
    tracep->declBit(c+110,"auto_in_pwrite", false,-1);
    tracep->declBus(c+108,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1165,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+631,"auto_in_pready", false,-1);
    tracep->declBit(c+1166,"auto_in_pslverr", false,-1);
    tracep->declBus(c+632,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1132,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+622,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+623,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+624,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+625,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+626,"sdram_bundle_we", false,-1);
    tracep->declBus(c+627,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+628,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+629,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+630,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+108,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+114,"in_psel", false,-1);
    tracep->declBit(c+1133,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+631,"in_pready", false,-1);
    tracep->declBus(c+632,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1166,"in_pslverr", false,-1);
    tracep->declBit(c+1132,"sdram_clk", false,-1);
    tracep->declBit(c+622,"sdram_cke", false,-1);
    tracep->declBit(c+623,"sdram_cs", false,-1);
    tracep->declBit(c+624,"sdram_ras", false,-1);
    tracep->declBit(c+625,"sdram_cas", false,-1);
    tracep->declBit(c+626,"sdram_we", false,-1);
    tracep->declBus(c+627,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+628,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+629,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+630,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+651,"sdram_dout_en", false,-1);
    tracep->declBus(c+652,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+586,"state", false,-1, 1,0);
    tracep->declBit(c+653,"req_accept", false,-1);
    tracep->declBit(c+154,"is_read", false,-1);
    tracep->declBit(c+155,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1106,"clk_i", false,-1);
    tracep->declBit(c+1107,"rst_i", false,-1);
    tracep->declBus(c+156,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+154,"inport_rd_i", false,-1);
    tracep->declBus(c+1181,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+108,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+111,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+630,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+653,"inport_accept_o", false,-1);
    tracep->declBit(c+631,"inport_ack_o", false,-1);
    tracep->declBit(c+1166,"inport_error_o", false,-1);
    tracep->declBus(c+632,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1132,"sdram_clk_o", false,-1);
    tracep->declBit(c+622,"sdram_cke_o", false,-1);
    tracep->declBit(c+623,"sdram_cs_o", false,-1);
    tracep->declBit(c+624,"sdram_ras_o", false,-1);
    tracep->declBit(c+625,"sdram_cas_o", false,-1);
    tracep->declBit(c+626,"sdram_we_o", false,-1);
    tracep->declBus(c+629,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+627,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+628,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+652,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+651,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1231,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1232,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1233,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1198,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1198,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1198,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1206,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1234,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1235,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1236,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1237,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1206,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1238,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1239,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1240,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1241,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1242,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1243,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1216,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1185,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1244,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1206,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1185,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1216,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1243,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1239,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1241,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1240,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1242,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1238,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1245,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1246,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1247,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1247,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1213,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1247,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1198,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1198,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1224,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+108,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+156,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+154,"ram_rd_w", false,-1);
    tracep->declBit(c+653,"ram_accept_w", false,-1);
    tracep->declBus(c+111,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+632,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+631,"ram_ack_w", false,-1);
    tracep->declBit(c+157,"ram_req_w", false,-1);
    tracep->declBus(c+654,"command_q", false,-1, 3,0);
    tracep->declBus(c+627,"addr_q", false,-1, 12,0);
    tracep->declBus(c+652,"data_q", false,-1, 15,0);
    tracep->declBit(c+655,"data_rd_en_q", false,-1);
    tracep->declBus(c+629,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+622,"cke_q", false,-1);
    tracep->declBus(c+628,"bank_q", false,-1, 1,0);
    tracep->declBus(c+656,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+657,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+630,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+658,"refresh_q", false,-1);
    tracep->declBus(c+659,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+660+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+664,"state_q", false,-1, 3,0);
    tracep->declBus(c+296,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+297,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+665,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+666,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+158,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+159,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+160,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1206,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+667,"delay_q", false,-1, 3,0);
    tracep->declBus(c+298,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1248,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+668,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+669,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+670,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+671,"idx", false,-1, 31,0);
    tracep->declBus(c+672,"rd_q", false,-1, 3,0);
    tracep->declBit(c+631,"ack_q", false,-1);
    tracep->declArray(c+673,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+124,"auto_in_psel", false,-1);
    tracep->declBit(c+125,"auto_in_penable", false,-1);
    tracep->declBit(c+110,"auto_in_pwrite", false,-1);
    tracep->declBus(c+116,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1165,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+633,"auto_in_pready", false,-1);
    tracep->declBit(c+1166,"auto_in_pslverr", false,-1);
    tracep->declBus(c+634,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+620,"spi_bundle_sck", false,-1);
    tracep->declBus(c+621,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1128,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1129,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1249,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1250,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1212,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+161,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+124,"in_psel", false,-1);
    tracep->declBit(c+125,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+633,"in_pready", false,-1);
    tracep->declBus(c+634,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1166,"in_pslverr", false,-1);
    tracep->declBit(c+620,"spi_sck", false,-1);
    tracep->declBus(c+621,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1128,"spi_mosi", false,-1);
    tracep->declBit(c+1129,"spi_miso", false,-1);
    tracep->declBit(c+676,"spi_irq_out", false,-1);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1200,"Tp", false,-1, 31,0);
    tracep->declBit(c+1106,"wb_clk_i", false,-1);
    tracep->declBit(c+1107,"wb_rst_i", false,-1);
    tracep->declBus(c+162,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+111,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+634,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+112,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+110,"wb_we_i", false,-1);
    tracep->declBit(c+124,"wb_stb_i", false,-1);
    tracep->declBit(c+125,"wb_cyc_i", false,-1);
    tracep->declBit(c+633,"wb_ack_o", false,-1);
    tracep->declBit(c+1166,"wb_err_o", false,-1);
    tracep->declBit(c+676,"wb_int_o", false,-1);
    tracep->declBus(c+621,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+620,"sclk_pad_o", false,-1);
    tracep->declBit(c+1128,"mosi_pad_o", false,-1);
    tracep->declBit(c+1129,"miso_pad_i", false,-1);
    tracep->declBus(c+677,"divider", false,-1, 15,0);
    tracep->declBus(c+678,"ctrl", false,-1, 13,0);
    tracep->declBus(c+679,"ss", false,-1, 7,0);
    tracep->declBus(c+299,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+680,"rx", false,-1, 127,0);
    tracep->declBit(c+684,"rx_negedge", false,-1);
    tracep->declBit(c+685,"tx_negedge", false,-1);
    tracep->declBus(c+686,"char_len", false,-1, 6,0);
    tracep->declBit(c+687,"go", false,-1);
    tracep->declBit(c+688,"lsb", false,-1);
    tracep->declBit(c+689,"ie", false,-1);
    tracep->declBit(c+690,"ass", false,-1);
    tracep->declBit(c+163,"spi_divider_sel", false,-1);
    tracep->declBit(c+164,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+165,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+166,"spi_ss_sel", false,-1);
    tracep->declBit(c+691,"tip", false,-1);
    tracep->declBit(c+692,"pos_edge", false,-1);
    tracep->declBit(c+693,"neg_edge", false,-1);
    tracep->declBit(c+694,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1200,"Tp", false,-1, 31,0);
    tracep->declBit(c+1106,"clk_in", false,-1);
    tracep->declBit(c+1107,"rst", false,-1);
    tracep->declBit(c+691,"enable", false,-1);
    tracep->declBit(c+687,"go", false,-1);
    tracep->declBit(c+694,"last_clk", false,-1);
    tracep->declBus(c+677,"divider", false,-1, 15,0);
    tracep->declBit(c+620,"clk_out", false,-1);
    tracep->declBit(c+692,"pos_edge", false,-1);
    tracep->declBit(c+693,"neg_edge", false,-1);
    tracep->declBus(c+695,"cnt", false,-1, 15,0);
    tracep->declBit(c+696,"cnt_zero", false,-1);
    tracep->declBit(c+697,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1200,"Tp", false,-1, 31,0);
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1107,"rst", false,-1);
    tracep->declBus(c+167,"latch", false,-1, 3,0);
    tracep->declBus(c+112,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+686,"len", false,-1, 6,0);
    tracep->declBit(c+688,"lsb", false,-1);
    tracep->declBit(c+687,"go", false,-1);
    tracep->declBit(c+692,"pos_edge", false,-1);
    tracep->declBit(c+693,"neg_edge", false,-1);
    tracep->declBit(c+684,"rx_negedge", false,-1);
    tracep->declBit(c+685,"tx_negedge", false,-1);
    tracep->declBit(c+691,"tip", false,-1);
    tracep->declBit(c+694,"last", false,-1);
    tracep->declBus(c+111,"p_in", false,-1, 31,0);
    tracep->declArray(c+680,"p_out", false,-1, 127,0);
    tracep->declBit(c+620,"s_clk", false,-1);
    tracep->declBit(c+1129,"s_in", false,-1);
    tracep->declBit(c+1128,"s_out", false,-1);
    tracep->declBus(c+698,"cnt", false,-1, 7,0);
    tracep->declArray(c+680,"data", false,-1, 127,0);
    tracep->declBus(c+699,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+700,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+701,"rx_clk", false,-1);
    tracep->declBit(c+702,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+121,"auto_in_psel", false,-1);
    tracep->declBit(c+122,"auto_in_penable", false,-1);
    tracep->declBit(c+110,"auto_in_pwrite", false,-1);
    tracep->declBus(c+118,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1165,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+123,"auto_in_pready", false,-1);
    tracep->declBit(c+1166,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1139,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1126,"uart_rx", false,-1);
    tracep->declBit(c+1127,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+121,"in_psel", false,-1);
    tracep->declBit(c+122,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+123,"in_pready", false,-1);
    tracep->declBit(c+1166,"in_pslverr", false,-1);
    tracep->declBus(c+140,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+1139,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1126,"uart_rx", false,-1);
    tracep->declBit(c+1127,"uart_tx", false,-1);
    tracep->declBit(c+703,"rtsn", false,-1);
    tracep->declBit(c+1166,"ctsn", false,-1);
    tracep->declBit(c+704,"dtr_pad_o", false,-1);
    tracep->declBit(c+1166,"dsr_pad_i", false,-1);
    tracep->declBit(c+1166,"ri_pad_i", false,-1);
    tracep->declBit(c+1166,"dcd_pad_i", false,-1);
    tracep->declBit(c+705,"interrupt", false,-1);
    tracep->declBit(c+168,"reg_we", false,-1);
    tracep->declBit(c+169,"reg_re", false,-1);
    tracep->declBus(c+170,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+171,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+587,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+300,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+706,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1107,"wb_rst_i", false,-1);
    tracep->declBus(c+170,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+172,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+300,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+168,"wb_we_i", false,-1);
    tracep->declBit(c+169,"wb_re_i", false,-1);
    tracep->declBit(c+1127,"stx_pad_o", false,-1);
    tracep->declBit(c+1126,"srx_pad_i", false,-1);
    tracep->declBus(c+1245,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+706,"rts_pad_o", false,-1);
    tracep->declBit(c+704,"dtr_pad_o", false,-1);
    tracep->declBit(c+705,"int_o", false,-1);
    tracep->declBit(c+707,"enable", false,-1);
    tracep->declBit(c+708,"srx_pad", false,-1);
    tracep->declBus(c+709,"ier", false,-1, 3,0);
    tracep->declBus(c+710,"iir", false,-1, 3,0);
    tracep->declBus(c+711,"fcr", false,-1, 1,0);
    tracep->declBus(c+712,"mcr", false,-1, 4,0);
    tracep->declBus(c+713,"lcr", false,-1, 7,0);
    tracep->declBus(c+714,"msr", false,-1, 7,0);
    tracep->declBus(c+715,"dl", false,-1, 15,0);
    tracep->declBus(c+716,"scratch", false,-1, 7,0);
    tracep->declBit(c+717,"start_dlc", false,-1);
    tracep->declBit(c+718,"lsr_mask_d", false,-1);
    tracep->declBit(c+719,"msi_reset", false,-1);
    tracep->declBus(c+720,"dlc", false,-1, 15,0);
    tracep->declBus(c+721,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+722,"rx_reset", false,-1);
    tracep->declBit(c+723,"tx_reset", false,-1);
    tracep->declBit(c+724,"dlab", false,-1);
    tracep->declBit(c+1182,"cts_pad_i", false,-1);
    tracep->declBit(c+1166,"dsr_pad_i", false,-1);
    tracep->declBit(c+1166,"ri_pad_i", false,-1);
    tracep->declBit(c+1166,"dcd_pad_i", false,-1);
    tracep->declBit(c+725,"loopback", false,-1);
    tracep->declBit(c+1166,"cts", false,-1);
    tracep->declBit(c+1182,"dsr", false,-1);
    tracep->declBit(c+1182,"ri", false,-1);
    tracep->declBit(c+1182,"dcd", false,-1);
    tracep->declBit(c+726,"cts_c", false,-1);
    tracep->declBit(c+727,"dsr_c", false,-1);
    tracep->declBit(c+728,"ri_c", false,-1);
    tracep->declBit(c+729,"dcd_c", false,-1);
    tracep->declBus(c+730,"lsr", false,-1, 7,0);
    tracep->declBit(c+731,"lsr0", false,-1);
    tracep->declBit(c+732,"lsr1", false,-1);
    tracep->declBit(c+733,"lsr2", false,-1);
    tracep->declBit(c+734,"lsr3", false,-1);
    tracep->declBit(c+735,"lsr4", false,-1);
    tracep->declBit(c+736,"lsr5", false,-1);
    tracep->declBit(c+737,"lsr6", false,-1);
    tracep->declBit(c+738,"lsr7", false,-1);
    tracep->declBit(c+739,"lsr0r", false,-1);
    tracep->declBit(c+740,"lsr1r", false,-1);
    tracep->declBit(c+741,"lsr2r", false,-1);
    tracep->declBit(c+742,"lsr3r", false,-1);
    tracep->declBit(c+743,"lsr4r", false,-1);
    tracep->declBit(c+744,"lsr5r", false,-1);
    tracep->declBit(c+745,"lsr6r", false,-1);
    tracep->declBit(c+746,"lsr7r", false,-1);
    tracep->declBit(c+301,"lsr_mask", false,-1);
    tracep->declBit(c+747,"rls_int", false,-1);
    tracep->declBit(c+748,"rda_int", false,-1);
    tracep->declBit(c+749,"ti_int", false,-1);
    tracep->declBit(c+750,"thre_int", false,-1);
    tracep->declBit(c+751,"ms_int", false,-1);
    tracep->declBit(c+752,"tf_push", false,-1);
    tracep->declBit(c+753,"rf_pop", false,-1);
    tracep->declBus(c+1159,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+754,"rf_error_bit", false,-1);
    tracep->declBit(c+732,"rf_overrun", false,-1);
    tracep->declBit(c+755,"rf_push_pulse", false,-1);
    tracep->declBus(c+756,"rf_count", false,-1, 4,0);
    tracep->declBus(c+757,"tf_count", false,-1, 4,0);
    tracep->declBus(c+758,"tstate", false,-1, 2,0);
    tracep->declBus(c+759,"rstate", false,-1, 3,0);
    tracep->declBus(c+760,"counter_t", false,-1, 9,0);
    tracep->declBit(c+761,"thre_set_en", false,-1);
    tracep->declBus(c+762,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+763,"block_value", false,-1, 7,0);
    tracep->declBit(c+764,"serial_out", false,-1);
    tracep->declBit(c+765,"serial_in", false,-1);
    tracep->declBit(c+302,"lsr_mask_condition", false,-1);
    tracep->declBit(c+303,"iir_read", false,-1);
    tracep->declBit(c+304,"msr_read", false,-1);
    tracep->declBit(c+305,"fifo_read", false,-1);
    tracep->declBit(c+306,"fifo_write", false,-1);
    tracep->declBus(c+766,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+767,"lsr0_d", false,-1);
    tracep->declBit(c+768,"lsr1_d", false,-1);
    tracep->declBit(c+769,"lsr2_d", false,-1);
    tracep->declBit(c+770,"lsr3_d", false,-1);
    tracep->declBit(c+771,"lsr4_d", false,-1);
    tracep->declBit(c+772,"lsr5_d", false,-1);
    tracep->declBit(c+773,"lsr6_d", false,-1);
    tracep->declBit(c+774,"lsr7_d", false,-1);
    tracep->declBit(c+775,"rls_int_d", false,-1);
    tracep->declBit(c+776,"thre_int_d", false,-1);
    tracep->declBit(c+777,"ms_int_d", false,-1);
    tracep->declBit(c+778,"ti_int_d", false,-1);
    tracep->declBit(c+779,"rda_int_d", false,-1);
    tracep->declBit(c+780,"rls_int_rise", false,-1);
    tracep->declBit(c+781,"thre_int_rise", false,-1);
    tracep->declBit(c+782,"ms_int_rise", false,-1);
    tracep->declBit(c+783,"ti_int_rise", false,-1);
    tracep->declBit(c+784,"rda_int_rise", false,-1);
    tracep->declBit(c+785,"rls_int_pnd", false,-1);
    tracep->declBit(c+786,"rda_int_pnd", false,-1);
    tracep->declBit(c+787,"thre_int_pnd", false,-1);
    tracep->declBit(c+788,"ms_int_pnd", false,-1);
    tracep->declBit(c+789,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1200,"Tp", false,-1, 31,0);
    tracep->declBus(c+1200,"width", false,-1, 31,0);
    tracep->declBus(c+1226,"init_value", false,-1, 0,0);
    tracep->declBit(c+1107,"rst_i", false,-1);
    tracep->declBit(c+1106,"clk_i", false,-1);
    tracep->declBit(c+1166,"stage1_rst_i", false,-1);
    tracep->declBit(c+1182,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1126,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+708,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+790,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1107,"wb_rst_i", false,-1);
    tracep->declBus(c+713,"lcr", false,-1, 7,0);
    tracep->declBit(c+753,"rf_pop", false,-1);
    tracep->declBit(c+765,"srx_pad_i", false,-1);
    tracep->declBit(c+707,"enable", false,-1);
    tracep->declBit(c+722,"rx_reset", false,-1);
    tracep->declBit(c+301,"lsr_mask", false,-1);
    tracep->declBus(c+760,"counter_t", false,-1, 9,0);
    tracep->declBus(c+756,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1159,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+732,"rf_overrun", false,-1);
    tracep->declBit(c+754,"rf_error_bit", false,-1);
    tracep->declBus(c+759,"rstate", false,-1, 3,0);
    tracep->declBit(c+755,"rf_push_pulse", false,-1);
    tracep->declBus(c+791,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+792,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+793,"rshift", false,-1, 7,0);
    tracep->declBit(c+794,"rparity", false,-1);
    tracep->declBit(c+795,"rparity_error", false,-1);
    tracep->declBit(c+796,"rframing_error", false,-1);
    tracep->declBit(c+797,"rbit_in", false,-1);
    tracep->declBit(c+798,"rparity_xor", false,-1);
    tracep->declBus(c+799,"counter_b", false,-1, 7,0);
    tracep->declBit(c+800,"rf_push_q", false,-1);
    tracep->declBus(c+801,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+802,"rf_push", false,-1);
    tracep->declBit(c+803,"break_error", false,-1);
    tracep->declBit(c+804,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+805,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+806,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+807,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1185,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1216,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1243,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1239,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1241,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1240,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1242,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1238,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1245,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1246,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1251,"sr_push", false,-1, 3,0);
    tracep->declBus(c+808,"toc_value", false,-1, 9,0);
    tracep->declBus(c+809,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1252,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1213,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1206,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1220,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1107,"wb_rst_i", false,-1);
    tracep->declBit(c+755,"push", false,-1);
    tracep->declBit(c+753,"pop", false,-1);
    tracep->declBus(c+801,"data_in", false,-1, 10,0);
    tracep->declBit(c+722,"fifo_reset", false,-1);
    tracep->declBit(c+301,"reset_status", false,-1);
    tracep->declBus(c+1159,"data_out", false,-1, 10,0);
    tracep->declBit(c+732,"overrun", false,-1);
    tracep->declBus(c+756,"count", false,-1, 4,0);
    tracep->declBit(c+754,"error_bit", false,-1);
    tracep->declBus(c+1160,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+810+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+826,"top", false,-1, 3,0);
    tracep->declBus(c+827,"bottom", false,-1, 3,0);
    tracep->declBus(c+828,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+829,"word0", false,-1, 2,0);
    tracep->declBus(c+830,"word1", false,-1, 2,0);
    tracep->declBus(c+831,"word2", false,-1, 2,0);
    tracep->declBus(c+832,"word3", false,-1, 2,0);
    tracep->declBus(c+833,"word4", false,-1, 2,0);
    tracep->declBus(c+834,"word5", false,-1, 2,0);
    tracep->declBus(c+835,"word6", false,-1, 2,0);
    tracep->declBus(c+836,"word7", false,-1, 2,0);
    tracep->declBus(c+837,"word8", false,-1, 2,0);
    tracep->declBus(c+838,"word9", false,-1, 2,0);
    tracep->declBus(c+839,"word10", false,-1, 2,0);
    tracep->declBus(c+840,"word11", false,-1, 2,0);
    tracep->declBus(c+841,"word12", false,-1, 2,0);
    tracep->declBus(c+842,"word13", false,-1, 2,0);
    tracep->declBus(c+843,"word14", false,-1, 2,0);
    tracep->declBus(c+844,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1206,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1212,"data_width", false,-1, 31,0);
    tracep->declBus(c+1213,"depth", false,-1, 31,0);
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+755,"we", false,-1);
    tracep->declBus(c+826,"a", false,-1, 3,0);
    tracep->declBus(c+827,"dpra", false,-1, 3,0);
    tracep->declBus(c+845,"di", false,-1, 7,0);
    tracep->declBus(c+1160,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+588+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1107,"wb_rst_i", false,-1);
    tracep->declBus(c+713,"lcr", false,-1, 7,0);
    tracep->declBit(c+752,"tf_push", false,-1);
    tracep->declBus(c+172,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+707,"enable", false,-1);
    tracep->declBit(c+723,"tx_reset", false,-1);
    tracep->declBit(c+301,"lsr_mask", false,-1);
    tracep->declBit(c+764,"stx_pad_o", false,-1);
    tracep->declBus(c+758,"tstate", false,-1, 2,0);
    tracep->declBus(c+757,"tf_count", false,-1, 4,0);
    tracep->declBus(c+846,"counter", false,-1, 4,0);
    tracep->declBus(c+847,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+848,"shift_out", false,-1, 6,0);
    tracep->declBit(c+849,"stx_o_tmp", false,-1);
    tracep->declBit(c+850,"parity_xor", false,-1);
    tracep->declBit(c+851,"tf_pop", false,-1);
    tracep->declBit(c+852,"bit_out", false,-1);
    tracep->declBus(c+172,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1161,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+853,"tf_overrun", false,-1);
    tracep->declBus(c+1186,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1165,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1253,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1254,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1227,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1222,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1212,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1213,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1206,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1220,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+1107,"wb_rst_i", false,-1);
    tracep->declBit(c+752,"push", false,-1);
    tracep->declBit(c+851,"pop", false,-1);
    tracep->declBus(c+172,"data_in", false,-1, 7,0);
    tracep->declBit(c+723,"fifo_reset", false,-1);
    tracep->declBit(c+301,"reset_status", false,-1);
    tracep->declBus(c+1161,"data_out", false,-1, 7,0);
    tracep->declBit(c+853,"overrun", false,-1);
    tracep->declBus(c+757,"count", false,-1, 4,0);
    tracep->declBus(c+854,"top", false,-1, 3,0);
    tracep->declBus(c+855,"bottom", false,-1, 3,0);
    tracep->declBus(c+856,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1206,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1212,"data_width", false,-1, 31,0);
    tracep->declBus(c+1213,"depth", false,-1, 31,0);
    tracep->declBit(c+1106,"clk", false,-1);
    tracep->declBit(c+752,"we", false,-1);
    tracep->declBus(c+854,"a", false,-1, 3,0);
    tracep->declBus(c+855,"dpra", false,-1, 3,0);
    tracep->declBus(c+172,"di", false,-1, 7,0);
    tracep->declBus(c+1161,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+604+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBit(c+115,"auto_in_psel", false,-1);
    tracep->declBit(c+1134,"auto_in_penable", false,-1);
    tracep->declBit(c+110,"auto_in_pwrite", false,-1);
    tracep->declBus(c+116,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1165,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+111,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1167,"auto_in_pready", false,-1);
    tracep->declBit(c+1168,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1169,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1120,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1121,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1122,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1123,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1124,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1125,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1106,"clock", false,-1);
    tracep->declBit(c+1107,"reset", false,-1);
    tracep->declBus(c+161,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+115,"in_psel", false,-1);
    tracep->declBit(c+1134,"in_penable", false,-1);
    tracep->declBus(c+1165,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+110,"in_pwrite", false,-1);
    tracep->declBus(c+111,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+112,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1167,"in_pready", false,-1);
    tracep->declBus(c+1169,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1168,"in_pslverr", false,-1);
    tracep->declBus(c+1120,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1121,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1122,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1123,"vga_hsync", false,-1);
    tracep->declBit(c+1124,"vga_vsync", false,-1);
    tracep->declBit(c+1125,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+620,"sck", false,-1);
    tracep->declBit(c+857,"ss", false,-1);
    tracep->declBit(c+1128,"mosi", false,-1);
    tracep->declBit(c+1182,"miso", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+620,"sck", false,-1);
    tracep->declBit(c+858,"ss", false,-1);
    tracep->declBit(c+1128,"mosi", false,-1);
    tracep->declBit(c+1129,"miso", false,-1);
    tracep->declBit(c+858,"reset", false,-1);
    tracep->declBus(c+936,"state", false,-1, 2,0);
    tracep->declBus(c+937,"counter", false,-1, 7,0);
    tracep->declBus(c+938,"cmd", false,-1, 7,0);
    tracep->declBus(c+939,"addr", false,-1, 23,0);
    tracep->declBus(c+940,"data", false,-1, 31,0);
    tracep->declBit(c+941,"ren", false,-1);
    tracep->declBus(c+1162,"rdata", false,-1, 31,0);
    tracep->declBus(c+1163,"raddr", false,-1, 31,0);
    tracep->declBus(c+1164,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+620,"clock", false,-1);
    tracep->declBit(c+941,"valid", false,-1);
    tracep->declBus(c+938,"cmd", false,-1, 7,0);
    tracep->declBus(c+1163,"addr", false,-1, 31,0);
    tracep->declBus(c+1162,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+1130,"sck", false,-1);
    tracep->declBit(c+1131,"ce_n", false,-1);
    tracep->declBus(c+173,"dio", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1132,"clk", false,-1);
    tracep->declBit(c+622,"cke", false,-1);
    tracep->declBit(c+623,"cs", false,-1);
    tracep->declBit(c+624,"ras", false,-1);
    tracep->declBit(c+625,"cas", false,-1);
    tracep->declBit(c+626,"we", false,-1);
    tracep->declBus(c+627,"a", false,-1, 12,0);
    tracep->declBus(c+628,"ba", false,-1, 1,0);
    tracep->declBus(c+629,"dqm", false,-1, 1,0);
    tracep->declBus(c+630,"dq", false,-1, 15,0);
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
    bufp->fullCData(oldp+19,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__pair_list[0]),5);
    bufp->fullCData(oldp+20,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__pair_list[1]),5);
    bufp->fullCData(oldp+21,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__pair_list[2]),5);
    bufp->fullCData(oldp+22,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+23,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+24,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+25,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__data_list[0]),3);
    bufp->fullCData(oldp+26,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__data_list[1]),3);
    bufp->fullCData(oldp+27,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__data_list[2]),3);
    bufp->fullCData(oldp+28,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[0]),3);
    bufp->fullBit(oldp+29,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[0]));
    bufp->fullCData(oldp+30,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+31,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+32,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+33,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+34,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[3]),2);
    bufp->fullIData(oldp+35,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                           : 0U) | 
                                         ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                           : 0U)))),32);
    bufp->fullBit(oldp+36,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+37,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+38,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+39,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+40,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+41,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+42,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+43,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+44,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+45,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+46,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+47,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+48,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+49,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+50,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+51,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+52,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+53,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+54,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+55,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+56,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+57,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+58,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+60,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+62,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+63,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+65,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+66,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+69,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+70,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+71,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+72,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+73,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+74,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+75,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+76,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+77,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+78,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+79,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+80,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+81,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+82,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+83,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+84,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+85,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+86,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+87,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+89,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+91,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+98,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+109,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+112,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+113,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+114,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+115,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+116,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+117,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+118,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+119,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+120,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+121,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+122,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+123,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_psel));
    bufp->fullBit(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_penable));
    bufp->fullBit(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+133,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+134,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+135,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+136,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+137,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+138,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+139,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+140,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+148,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+149,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+150,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+151,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+152,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+153,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+154,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+156,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+158,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+159,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+160,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+161,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullCData(oldp+162,((0x1fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),5);
    bufp->fullBit(oldp+163,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullBit(oldp+164,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+165,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
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
    bufp->fullBit(oldp+166,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+170,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullCData(oldp+173,((((((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out0) 
                                         & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten))) 
                                  | (0xcU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out1) 
                                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten)))) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0))),4);
    bufp->fullBit(oldp+174,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+175,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+176,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+178,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+179,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+180,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+181,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+183,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+186,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+190,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+191,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+222,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+226,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+230,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+231,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+232,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+233,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+234,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+235,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+236,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+237,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+238,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+239,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+240,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+241,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+242,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+243,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+244,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+245,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+246,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+247,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+248,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+249,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+250,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+251,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+252,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+253,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+254,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+255,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+256,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+257,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+258,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+259,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+260,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+261,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+262,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+265,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+266,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+267,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+268,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+269,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+270,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+271,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+272,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+273,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+274,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                              [1U]),2);
    bufp->fullBit(oldp+276,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                   >> 1U))));
    bufp->fullIData(oldp+277,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+278,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+279,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+280,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+281,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data))),32);
    bufp->fullIData(oldp+282,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data))),32);
    bufp->fullCData(oldp+283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data),8);
    bufp->fullSData(oldp+284,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data),16);
    bufp->fullIData(oldp+285,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+286,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+287,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+288,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+289,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+291,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+292,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+293,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+294,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+296,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+297,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullBit(oldp+307,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullIData(oldp+308,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+309,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+310,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+311,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+312,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+313,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+316,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+317,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+321,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+322,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+323,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+324,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+325,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+326,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+327,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+345,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+350,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+352,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+353,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+354,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+355,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+358,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullCData(oldp+359,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullQData(oldp+360,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+362,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+363,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+364,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+366,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+367,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+368,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+369,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+370,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+371,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+372,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+373,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+374,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+375,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+377,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+378,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+379,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+382,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+383,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+384,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+385,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+386,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+387,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+391,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+401,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+405,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+428,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+433,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+438,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+442,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+443,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+444,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+446,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+450,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+452,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+454,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+455,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+456,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+457,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+458,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+461,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+462,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+464,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+466,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+468,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+470,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+472,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+474,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+478,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+482,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+484,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+486,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+488,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+490,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+492,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+494,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+496,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+498,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+501,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+502,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+503,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+506,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+510,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+512,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+514,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+516,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+518,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+522,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+524,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+525,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+526,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+529,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+530,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+532,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+533,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+534,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+536,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+538,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+540,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+541,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+542,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+544,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+545,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+546,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+548,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+549,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+550,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+552,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+554,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+558,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+560,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+562,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullCData(oldp+566,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready),2);
    bufp->fullBit(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+570,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready) 
                                   >> 1U))));
    bufp->fullCData(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state),2);
    bufp->fullBit(oldp+572,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+573,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+574,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+575,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+577,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+582,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullCData(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+590,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+594,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+598,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+602,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+606,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+613,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+614,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+615,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+617,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+618,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullBit(oldp+620,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+621,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+622,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+623,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+624,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+625,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+626,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+628,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+629,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullSData(oldp+630,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                  ? 0U : 0xffffU) & 
                                ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                    ? 0U : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                      ? 0U : 0xffffU)) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                     ? 0U : 0xffffU))) 
                               & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                   ? 0U : 0xffffU))),16);
    bufp->fullBit(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullIData(oldp+632,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+633,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_pready));
    bufp->fullIData(oldp+634,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+637,((0xfU & ((8U > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
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
    bufp->fullBit(oldp+638,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+639,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+641,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+642,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+643,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+644,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+647,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+649,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullBit(oldp+651,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+652,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+653,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+655,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+656,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullBit(oldp+658,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+660,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullCData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+666,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+670,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+673,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+676,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullSData(oldp+677,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+679,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+680,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+684,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+685,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+686,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+687,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+688,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+689,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+690,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+691,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+692,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+693,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+694,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+695,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+696,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+697,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+698,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+699,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+701,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+702,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+703,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+704,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+705,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+706,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+707,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+708,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+709,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+715,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+716,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+717,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+718,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+719,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+720,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+721,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+722,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+723,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+724,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+725,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+726,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+727,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+728,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+729,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+730,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+731,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+732,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+733,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+734,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+735,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+736,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+737,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+738,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+739,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+740,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+741,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+742,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+743,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+744,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+746,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+747,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+748,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+749,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+750,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+752,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+753,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+754,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+756,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+758,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+759,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+760,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+761,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+762,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+763,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+764,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+765,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+766,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+767,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+768,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+769,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+770,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+771,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+772,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+773,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+774,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+775,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+776,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+777,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+778,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+779,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+780,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+781,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+782,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+783,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+784,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+785,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+786,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+788,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+789,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+790,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+793,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+795,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+796,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+797,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+798,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+799,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+800,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+801,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+803,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+804,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+805,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+806,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+807,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+808,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+809,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+810,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+811,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+812,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+814,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+815,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+816,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+818,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+820,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+821,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+822,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+823,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+824,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+827,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+828,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+829,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+830,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+833,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+834,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+836,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+837,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+839,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+840,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+841,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+843,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+845,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+848,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+850,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+856,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+857,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_ss) 
                                   >> 7U))));
    bufp->fullBit(oldp+858,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullIData(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+860,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+861,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+862,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+864,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+866,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+867,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+868,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+869,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+870,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+874,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+875,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+877,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+894,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+900,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+901,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+920,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+921,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+922,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+923,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+928,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+929,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+930,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+931,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+932,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+933,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+936,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+937,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+938,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+939,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+940,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+941,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                             & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+942,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+943,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__arsize_out_reg),3);
    bufp->fullBit(oldp+944,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+945,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+946,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+947,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullBit(oldp+948,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullBit(oldp+949,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+950,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+951,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+952,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+953,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+954,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+955,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+956,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+957,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                      | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+958,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+959,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+960,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+961,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+962,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+963,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+964,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+965,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+966,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+967,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+968,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+969,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+972,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+973,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+975,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+976,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+977,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullCData(oldp+978,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[0]),3);
    bufp->fullCData(oldp+979,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[1]),3);
    bufp->fullCData(oldp+980,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[0]),3);
    bufp->fullCData(oldp+981,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[1]),3);
    bufp->fullCData(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+983,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+984,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+985,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+987,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+988,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+989,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+990,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+991,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+992,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+993,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+994,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+995,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+996,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+997,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+998,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+999,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+1000,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+1001,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+1002,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+1003,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 | ((0x17U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+1004,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1005,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))));
    bufp->fullCData(oldp+1006,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),3);
    bufp->fullSData(oldp+1007,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                >> 0x14U)),12);
    bufp->fullCData(oldp+1008,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+1009,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1010,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+1011,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+1012,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    >> 1U))));
    bufp->fullCData(oldp+1013,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 1U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 3U : ((4U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 0xfU
                                                   : 0U)))),4);
    bufp->fullIData(oldp+1014,((0x11830U | ((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
                                               | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_word))))),24);
    bufp->fullCData(oldp+1015,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[0]),6);
    bufp->fullCData(oldp+1016,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[1]),6);
    bufp->fullCData(oldp+1017,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[2]),6);
    bufp->fullCData(oldp+1018,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[3]),6);
    bufp->fullCData(oldp+1019,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[0]),4);
    bufp->fullCData(oldp+1020,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[1]),4);
    bufp->fullCData(oldp+1021,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[2]),4);
    bufp->fullCData(oldp+1022,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[3]),4);
    __Vtemp_h49f7fb6a__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))));
    __Vtemp_h49f7fb6a__0[1U] = ((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))) 
                                                   >> 0x20U)));
    __Vtemp_h49f7fb6a__0[2U] = (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                >> 0x1fU);
    bufp->fullWData(oldp+1023,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1026,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1030,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1031,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1032,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullCData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullIData(oldp+1034,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullCData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullIData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullCData(oldp+1038,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awsize_out_reg),3);
    bufp->fullIData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullCData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullIData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1046,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1047,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1048,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1049,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1050,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1051,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1052,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1053,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1054,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1055,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1056,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
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
    bufp->fullBit(oldp+1057,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1058,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1059,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1060,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1061,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1062,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1063,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1064,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1065,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1066,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1067,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1068,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullCData(oldp+1069,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+1070,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+1071,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[0]),3);
    bufp->fullCData(oldp+1072,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[1]),3);
    bufp->fullIData(oldp+1073,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1074,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1075,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1076,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1077,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1078,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullCData(oldp+1079,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+1080,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+1081,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[0]),3);
    bufp->fullCData(oldp+1082,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[1]),3);
    bufp->fullIData(oldp+1083,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1084,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1085,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1086,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1087,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1088,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1089,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1090,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1091,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1092,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1093,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullCData(oldp+1094,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__wstrb),4);
    bufp->fullCData(oldp+1095,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awsize),3);
    bufp->fullCData(oldp+1096,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),2);
    bufp->fullBit(oldp+1097,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__insram));
    bufp->fullCData(oldp+1098,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size),2);
    bufp->fullCData(oldp+1099,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__lut_out),4);
    bufp->fullBit(oldp+1104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+1105,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1106,(vlSelf->clock));
    bufp->fullBit(oldp+1107,(vlSelf->reset));
    bufp->fullSData(oldp+1108,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1109,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1110,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1111,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1112,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1113,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1114,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1115,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1116,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1117,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1118,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1119,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1120,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1121,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1122,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1123,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1124,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1125,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1126,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1127,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1128,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+1129,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullBit(oldp+1130,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck))));
    bufp->fullBit(oldp+1131,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n))));
    bufp->fullBit(oldp+1132,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullBit(oldp+1133,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1134,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1135,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1136,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1137,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1138,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1139,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullCData(oldp+1140,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                 ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                    << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))),2);
    bufp->fullBit(oldp+1141,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullCData(oldp+1142,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1143,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1144,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1145,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1146,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
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
    bufp->fullBit(oldp+1147,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1148,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1149,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1150,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullIData(oldp+1151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1152,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullBit(oldp+1153,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1154,(((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1155,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state)))));
    bufp->fullBit(oldp+1156,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                     & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready)) 
                                    >> 1U))));
    bufp->fullBit(oldp+1157,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1158,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1159,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullIData(oldp+1162,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1163,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1164,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullCData(oldp+1165,(1U),3);
    bufp->fullBit(oldp+1166,(0U));
    bufp->fullBit(oldp+1167,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1168,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1169,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1170,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1171,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1172,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1173,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pready));
    bufp->fullBit(oldp+1174,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullIData(oldp+1175,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_prdata),32);
    bufp->fullCData(oldp+1176,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1177,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullCData(oldp+1178,(1U),2);
    bufp->fullBit(oldp+1179,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1180,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1181,(0U),8);
    bufp->fullBit(oldp+1182,(1U));
    bufp->fullBit(oldp+1183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1184,(0U),32);
    bufp->fullCData(oldp+1185,(0U),4);
    bufp->fullCData(oldp+1186,(0U),3);
    bufp->fullCData(oldp+1187,(0U),2);
    bufp->fullBit(oldp+1188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1190,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1198,(2U),32);
    bufp->fullIData(oldp+1199,(2U),32);
    bufp->fullIData(oldp+1200,(1U),32);
    bufp->fullIData(oldp+1201,(0x20U),32);
    bufp->fullIData(oldp+1202,(0U),32);
    bufp->fullIData(oldp+1203,(0x21U),32);
    bufp->fullIData(oldp+1204,(2U),32);
    bufp->fullIData(oldp+1205,(0x20000000U),32);
    bufp->fullIData(oldp+1206,(4U),32);
    bufp->fullIData(oldp+1207,(0xcU),32);
    bufp->fullQData(oldp+1208,(0x3000c153418d0bULL),56);
    bufp->fullIData(oldp+1210,(0xeU),32);
    bufp->fullIData(oldp+1211,(4U),32);
    bufp->fullIData(oldp+1212,(8U),32);
    bufp->fullIData(oldp+1213,(0x10U),32);
    bufp->fullIData(oldp+1214,(3U),32);
    bufp->fullIData(oldp+1215,(0x23U),32);
    bufp->fullCData(oldp+1216,(1U),4);
    bufp->fullCData(oldp+1217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword),4);
    bufp->fullCData(oldp+1218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_word),4);
    bufp->fullSData(oldp+1219,(0x265cU),15);
    bufp->fullIData(oldp+1220,(5U),32);
    bufp->fullIData(oldp+1221,(3U),32);
    bufp->fullCData(oldp+1222,(5U),3);
    bufp->fullIData(oldp+1223,(1U),32);
    bufp->fullIData(oldp+1224,(6U),32);
    bufp->fullBit(oldp+1225,(0U));
    bufp->fullBit(oldp+1226,(1U));
    bufp->fullCData(oldp+1227,(4U),3);
    bufp->fullCData(oldp+1228,(0x1bU),8);
    bufp->fullCData(oldp+1229,(0xebU),8);
    bufp->fullCData(oldp+1230,(0x38U),8);
    bufp->fullIData(oldp+1231,(0x64U),32);
    bufp->fullIData(oldp+1232,(0x18U),32);
    bufp->fullIData(oldp+1233,(9U),32);
    bufp->fullIData(oldp+1234,(0xdU),32);
    bufp->fullIData(oldp+1235,(0x2000U),32);
    bufp->fullIData(oldp+1236,(0x2710U),32);
    bufp->fullIData(oldp+1237,(0x30cU),32);
    bufp->fullCData(oldp+1238,(7U),4);
    bufp->fullCData(oldp+1239,(3U),4);
    bufp->fullCData(oldp+1240,(5U),4);
    bufp->fullCData(oldp+1241,(4U),4);
    bufp->fullCData(oldp+1242,(6U),4);
    bufp->fullCData(oldp+1243,(2U),4);
    bufp->fullSData(oldp+1244,(0x21U),13);
    bufp->fullCData(oldp+1245,(8U),4);
    bufp->fullCData(oldp+1246,(9U),4);
    bufp->fullIData(oldp+1247,(0xaU),32);
    bufp->fullIData(oldp+1248,(0x11U),32);
    bufp->fullIData(oldp+1249,(0x30000000U),32);
    bufp->fullIData(oldp+1250,(0x3fffffffU),32);
    bufp->fullCData(oldp+1251,(0xaU),4);
    bufp->fullIData(oldp+1252,(0xbU),32);
    bufp->fullCData(oldp+1253,(2U),3);
    bufp->fullCData(oldp+1254,(3U),3);
}
