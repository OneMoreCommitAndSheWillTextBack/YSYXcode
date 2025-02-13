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
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+1119,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1120,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1121,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1122,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1123,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1124,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1125,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1126,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1127,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1128,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1129,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1130,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1131,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1132,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1133,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1134,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1135,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1136,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1137,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1138,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+1119,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1120,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1121,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1122,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1123,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1124,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1125,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1126,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1127,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1128,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1129,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1130,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1131,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1132,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1133,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1134,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1135,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1136,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1137,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1138,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+622,"spi_sck", false,-1);
    tracep->declBus(c+623,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1139,"spi_mosi", false,-1);
    tracep->declBit(c+1140,"spi_miso", false,-1);
    tracep->declBit(c+1137,"uart_rx", false,-1);
    tracep->declBit(c+1138,"uart_tx", false,-1);
    tracep->declBit(c+1141,"psram_sck", false,-1);
    tracep->declBit(c+1142,"psram_ce_n", false,-1);
    tracep->declBus(c+176,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1143,"sdram_clk", false,-1);
    tracep->declBit(c+624,"sdram_cke", false,-1);
    tracep->declBit(c+625,"sdram_cs", false,-1);
    tracep->declBit(c+626,"sdram_ras", false,-1);
    tracep->declBit(c+627,"sdram_cas", false,-1);
    tracep->declBit(c+628,"sdram_we", false,-1);
    tracep->declBus(c+629,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+630,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+631,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+632,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1119,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1120,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1121,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1122,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1123,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1124,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1125,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1126,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1127,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1128,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1129,"ps2_clk", false,-1);
    tracep->declBit(c+1130,"ps2_data", false,-1);
    tracep->declBus(c+1131,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1132,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1133,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1134,"vga_hsync", false,-1);
    tracep->declBit(c+1135,"vga_vsync", false,-1);
    tracep->declBit(c+1136,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+111,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+112,"in_psel", false,-1);
    tracep->declBit(c+310,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+177,"in_pready", false,-1);
    tracep->declBus(c+178,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+116,"in_pslverr", false,-1);
    tracep->declBus(c+111,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+112,"out_psel", false,-1);
    tracep->declBit(c+310,"out_penable", false,-1);
    tracep->declBus(c+1176,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"out_pwrite", false,-1);
    tracep->declBus(c+114,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+177,"out_pready", false,-1);
    tracep->declBus(c+178,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+116,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+112,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+310,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+111,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1176,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+177,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+116,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+178,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+117,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+1144,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+111,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1176,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+633,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1177,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+634,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+118,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+1145,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+119,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1176,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1178,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1179,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1180,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+120,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+1146,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+121,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1176,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1181,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1182,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1183,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+122,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+1147,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+121,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1176,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+1184,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1185,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1186,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+123,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+1148,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+111,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1176,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1149,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1177,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+311,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+124,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+125,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+121,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1176,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+126,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1177,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1150,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+127,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+128,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+113,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+119,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1176,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+635,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1177,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+636,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+129,"sel_0", false,-1);
    tracep->declBit(c+130,"sel_1", false,-1);
    tracep->declBit(c+131,"sel_2", false,-1);
    tracep->declBit(c+132,"sel_3", false,-1);
    tracep->declBit(c+133,"sel_4", false,-1);
    tracep->declBit(c+134,"sel_5", false,-1);
    tracep->declBit(c+135,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+136,"auto_in_awready", false,-1);
    tracep->declBit(c+137,"auto_in_awvalid", false,-1);
    tracep->declBus(c+312,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1035,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1036,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+136,"auto_in_wready", false,-1);
    tracep->declBit(c+138,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+179,"auto_in_bready", false,-1);
    tracep->declBit(c+180,"auto_in_bvalid", false,-1);
    tracep->declBus(c+313,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+1151,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+139,"auto_in_arready", false,-1);
    tracep->declBit(c+140,"auto_in_arvalid", false,-1);
    tracep->declBus(c+314,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1039,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+944,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+181,"auto_in_rready", false,-1);
    tracep->declBit(c+182,"auto_in_rvalid", false,-1);
    tracep->declBus(c+315,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+183,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1151,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+112,"auto_out_psel", false,-1);
    tracep->declBit(c+310,"auto_out_penable", false,-1);
    tracep->declBit(c+113,"auto_out_pwrite", false,-1);
    tracep->declBus(c+111,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+114,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+177,"auto_out_pready", false,-1);
    tracep->declBit(c+116,"auto_out_pslverr", false,-1);
    tracep->declBus(c+178,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+310,"nodeOut_penable", false,-1);
    tracep->declBus(c+316,"state", false,-1, 1,0);
    tracep->declBit(c+139,"accept_read", false,-1);
    tracep->declBit(c+136,"accept_write", false,-1);
    tracep->declBit(c+317,"is_write_r", false,-1);
    tracep->declBit(c+113,"is_write", false,-1);
    tracep->declBus(c+315,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+313,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+318,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+319,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+320,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+321,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+141,"resp", false,-1, 1,0);
    tracep->declBus(c+322,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+1151,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+182,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+323,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+180,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+324,"auto_in_awready", false,-1);
    tracep->declBit(c+75,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1187,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1040,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1188,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1041,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1042,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+325,"auto_in_wready", false,-1);
    tracep->declBit(c+76,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"auto_in_wlast", false,-1);
    tracep->declBit(c+1152,"auto_in_bready", false,-1);
    tracep->declBit(c+184,"auto_in_bvalid", false,-1);
    tracep->declBus(c+185,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+186,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+326,"auto_in_arready", false,-1);
    tracep->declBit(c+77,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1190,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1191,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+945,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1192,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+78,"auto_in_rready", false,-1);
    tracep->declBit(c+187,"auto_in_rvalid", false,-1);
    tracep->declBus(c+188,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+39,"auto_in_rlast", false,-1);
    tracep->declBit(c+189,"auto_out_awready", false,-1);
    tracep->declBit(c+79,"auto_out_awvalid", false,-1);
    tracep->declBus(c+312,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1035,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1036,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+327,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+190,"auto_out_wready", false,-1);
    tracep->declBit(c+80,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+81,"auto_out_wlast", false,-1);
    tracep->declBit(c+191,"auto_out_bready", false,-1);
    tracep->declBit(c+192,"auto_out_bvalid", false,-1);
    tracep->declBus(c+185,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+193,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+194,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+195,"auto_out_arready", false,-1);
    tracep->declBit(c+82,"auto_out_arvalid", false,-1);
    tracep->declBus(c+314,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1039,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+944,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+328,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+78,"auto_out_rready", false,-1);
    tracep->declBit(c+187,"auto_out_rvalid", false,-1);
    tracep->declBus(c+188,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+40,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+196,"auto_out_rlast", false,-1);
    tracep->declBit(c+80,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+329,"w_idle", false,-1);
    tracep->declBit(c+197,"in_awready", false,-1);
    tracep->declBit(c+330,"busy", false,-1);
    tracep->declBus(c+331,"r_addr", false,-1, 31,0);
    tracep->declBus(c+332,"r_len", false,-1, 7,0);
    tracep->declBus(c+333,"len", false,-1, 7,0);
    tracep->declBus(c+1046,"addr", false,-1, 31,0);
    tracep->declBit(c+334,"busy_1", false,-1);
    tracep->declBus(c+335,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+336,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+337,"len_1", false,-1, 7,0);
    tracep->declBus(c+1047,"addr_1", false,-1, 31,0);
    tracep->declBit(c+338,"wbeats_latched", false,-1);
    tracep->declBit(c+79,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+83,"wbeats_valid", false,-1);
    tracep->declBus(c+339,"w_counter", false,-1, 8,0);
    tracep->declBus(c+84,"w_todo", false,-1, 8,0);
    tracep->declBit(c+81,"w_last", false,-1);
    tracep->declBit(c+191,"nodeOut_bready", false,-1);
    tracep->declBus(c+340,"error_0", false,-1, 1,0);
    tracep->declBus(c+341,"error_1", false,-1, 1,0);
    tracep->declBus(c+342,"error_2", false,-1, 1,0);
    tracep->declBus(c+343,"error_3", false,-1, 1,0);
    tracep->declBus(c+344,"error_4", false,-1, 1,0);
    tracep->declBus(c+345,"error_5", false,-1, 1,0);
    tracep->declBus(c+346,"error_6", false,-1, 1,0);
    tracep->declBus(c+347,"error_7", false,-1, 1,0);
    tracep->declBus(c+348,"error_8", false,-1, 1,0);
    tracep->declBus(c+349,"error_9", false,-1, 1,0);
    tracep->declBus(c+350,"error_10", false,-1, 1,0);
    tracep->declBus(c+351,"error_11", false,-1, 1,0);
    tracep->declBus(c+352,"error_12", false,-1, 1,0);
    tracep->declBus(c+353,"error_13", false,-1, 1,0);
    tracep->declBus(c+354,"error_14", false,-1, 1,0);
    tracep->declBus(c+355,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+326,"io_enq_ready", false,-1);
    tracep->declBit(c+77,"io_enq_valid", false,-1);
    tracep->declBus(c+1190,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1045,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1191,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+945,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1192,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+198,"io_deq_ready", false,-1);
    tracep->declBit(c+82,"io_deq_valid", false,-1);
    tracep->declBus(c+314,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1048,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+356,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+944,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+357,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+358,"ram", false,-1, 48,0);
    tracep->declBit(c+360,"full", false,-1);
    tracep->declBit(c+82,"io_deq_valid_0", false,-1);
    tracep->declBit(c+199,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+324,"io_enq_ready", false,-1);
    tracep->declBit(c+75,"io_enq_valid", false,-1);
    tracep->declBus(c+1187,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1040,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1188,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1041,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1042,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+200,"io_deq_ready", false,-1);
    tracep->declBit(c+85,"io_deq_valid", false,-1);
    tracep->declBus(c+312,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1049,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+361,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1036,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1050,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+362,"ram", false,-1, 48,0);
    tracep->declBit(c+364,"full", false,-1);
    tracep->declBit(c+85,"io_deq_valid_0", false,-1);
    tracep->declBit(c+201,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+325,"io_enq_ready", false,-1);
    tracep->declBit(c+76,"io_enq_valid", false,-1);
    tracep->declBus(c+1043,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1044,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1189,"io_enq_bits_last", false,-1);
    tracep->declBit(c+202,"io_deq_ready", false,-1);
    tracep->declBit(c+86,"io_deq_valid", false,-1);
    tracep->declBus(c+1037,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1038,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+365,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+366,"ram", false,-1, 36,0);
    tracep->declBit(c+368,"full", false,-1);
    tracep->declBit(c+86,"io_deq_valid_0", false,-1);
    tracep->declBit(c+203,"do_enq", false,-1);
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
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+204,"auto_in_awready", false,-1);
    tracep->declBit(c+142,"auto_in_awvalid", false,-1);
    tracep->declBus(c+312,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1154,"auto_in_wready", false,-1);
    tracep->declBit(c+1155,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+205,"auto_in_bready", false,-1);
    tracep->declBit(c+369,"auto_in_bvalid", false,-1);
    tracep->declBus(c+370,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+371,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+206,"auto_in_arready", false,-1);
    tracep->declBit(c+1156,"auto_in_arvalid", false,-1);
    tracep->declBus(c+314,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1052,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+207,"auto_in_rready", false,-1);
    tracep->declBit(c+372,"auto_in_rvalid", false,-1);
    tracep->declBus(c+373,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+374,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+375,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+206,"nodeIn_arready", false,-1);
    tracep->declBit(c+204,"nodeIn_awready", false,-1);
    tracep->declBit(c+1053,"w_sel0", false,-1);
    tracep->declBit(c+369,"w_full", false,-1);
    tracep->declBus(c+370,"w_id", false,-1, 3,0);
    tracep->declBit(c+376,"r_sel1", false,-1);
    tracep->declBit(c+377,"w_sel1", false,-1);
    tracep->declBit(c+372,"r_full", false,-1);
    tracep->declBus(c+373,"r_id", false,-1, 3,0);
    tracep->declBit(c+208,"ren", false,-1);
    tracep->declBit(c+378,"rdata_REG", false,-1);
    tracep->declBus(c+379,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+380,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+381,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+382,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1054,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+208,"R0_en", false,-1);
    tracep->declBit(c+1117,"R0_clk", false,-1);
    tracep->declBus(c+383,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1055,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+209,"W0_en", false,-1);
    tracep->declBit(c+1117,"W0_clk", false,-1);
    tracep->declBus(c+1037,"W0_data", false,-1, 31,0);
    tracep->declBus(c+1038,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+324,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+75,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1187,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1040,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1188,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1041,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1042,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+325,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+76,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1152,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+184,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+185,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+186,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+326,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+77,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1190,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1191,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+945,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1192,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+78,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+187,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+188,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+39,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+324,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+75,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1187,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1040,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1188,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1041,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1042,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+325,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+76,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1152,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+184,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+185,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+186,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+326,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+77,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1190,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1191,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+945,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1192,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+78,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+187,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+188,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+39,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+210,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+87,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+312,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1035,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1036,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+190,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+80,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+81,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+191,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+192,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+185,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+193,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+211,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+88,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+314,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1039,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+944,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+78,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+187,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+188,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+196,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+204,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+142,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+312,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1154,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1155,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+205,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+369,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+370,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+371,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+206,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1156,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+314,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1052,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+207,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+372,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+373,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+374,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+375,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1157,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1158,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+384,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1159,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+314,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1056,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1160,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+385,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+386,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+387,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+136,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+137,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+312,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1035,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+1036,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+136,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+138,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+179,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+180,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+313,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+1151,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+139,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+140,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+314,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1039,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+944,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+181,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+182,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+315,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+183,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+1151,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+192,"in_0_bvalid", false,-1);
    tracep->declBit(c+187,"in_0_rvalid", false,-1);
    tracep->declBit(c+212,"in_0_wready", false,-1);
    tracep->declBit(c+213,"in_0_awready", false,-1);
    tracep->declBit(c+211,"in_0_arready", false,-1);
    tracep->declBit(c+210,"anonIn_awready", false,-1);
    tracep->declBit(c+1057,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1058,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1059,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1060,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1061,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1062,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+388,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+389,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+390,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+391,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+392,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+393,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+394,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+395,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+396,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+397,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+398,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+399,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+400,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+401,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+402,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+403,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+404,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+405,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+406,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+407,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+408,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+409,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+410,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+411,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+412,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+413,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+414,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+415,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+416,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+417,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+418,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+419,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+420,"latched", false,-1);
    tracep->declBit(c+89,"in_0_awvalid", false,-1);
    tracep->declBit(c+90,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+91,"in_0_wvalid", false,-1);
    tracep->declBit(c+421,"idle_3", false,-1);
    tracep->declBit(c+214,"anyValid", false,-1);
    tracep->declBus(c+215,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+422,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+216,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+217,"prefixOR_1", false,-1);
    tracep->declBit(c+218,"winner_3_1", false,-1);
    tracep->declBit(c+219,"winner_3_2", false,-1);
    tracep->declBit(c+423,"state_3_0", false,-1);
    tracep->declBit(c+424,"state_3_1", false,-1);
    tracep->declBit(c+425,"state_3_2", false,-1);
    tracep->declBit(c+220,"muxState_3_0", false,-1);
    tracep->declBit(c+221,"muxState_3_1", false,-1);
    tracep->declBit(c+222,"muxState_3_2", false,-1);
    tracep->declBit(c+426,"idle_4", false,-1);
    tracep->declBit(c+223,"anyValid_1", false,-1);
    tracep->declBus(c+224,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+427,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+225,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+226,"winner_4_0", false,-1);
    tracep->declBit(c+227,"winner_4_2", false,-1);
    tracep->declBit(c+428,"state_4_0", false,-1);
    tracep->declBit(c+429,"state_4_2", false,-1);
    tracep->declBit(c+228,"muxState_4_0", false,-1);
    tracep->declBit(c+229,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+430,"io_enq_ready", false,-1);
    tracep->declBit(c+90,"io_enq_valid", false,-1);
    tracep->declBus(c+1063,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+230,"io_deq_ready", false,-1);
    tracep->declBit(c+92,"io_deq_valid", false,-1);
    tracep->declBus(c+1064,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+431,"wrap", false,-1);
    tracep->declBit(c+432,"wrap_1", false,-1);
    tracep->declBit(c+433,"maybe_full", false,-1);
    tracep->declBit(c+434,"ptr_match", false,-1);
    tracep->declBit(c+435,"empty", false,-1);
    tracep->declBit(c+436,"full", false,-1);
    tracep->declBit(c+92,"io_deq_valid_0", false,-1);
    tracep->declBit(c+231,"do_deq", false,-1);
    tracep->declBit(c+232,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+432,"R0_addr", false,-1);
    tracep->declBit(c+1193,"R0_en", false,-1);
    tracep->declBit(c+1117,"R0_clk", false,-1);
    tracep->declBus(c+437,"R0_data", false,-1, 2,0);
    tracep->declBit(c+431,"W0_addr", false,-1);
    tracep->declBit(c+232,"W0_en", false,-1);
    tracep->declBit(c+1117,"W0_clk", false,-1);
    tracep->declBus(c+1063,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+438+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+189,"auto_in_awready", false,-1);
    tracep->declBit(c+79,"auto_in_awvalid", false,-1);
    tracep->declBus(c+312,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1035,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1036,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+327,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+190,"auto_in_wready", false,-1);
    tracep->declBit(c+80,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+81,"auto_in_wlast", false,-1);
    tracep->declBit(c+191,"auto_in_bready", false,-1);
    tracep->declBit(c+192,"auto_in_bvalid", false,-1);
    tracep->declBus(c+185,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+193,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+194,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+195,"auto_in_arready", false,-1);
    tracep->declBit(c+82,"auto_in_arvalid", false,-1);
    tracep->declBus(c+314,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1039,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+944,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+328,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+78,"auto_in_rready", false,-1);
    tracep->declBit(c+187,"auto_in_rvalid", false,-1);
    tracep->declBus(c+188,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+40,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+196,"auto_in_rlast", false,-1);
    tracep->declBit(c+210,"auto_out_awready", false,-1);
    tracep->declBit(c+87,"auto_out_awvalid", false,-1);
    tracep->declBus(c+312,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1035,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1036,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+190,"auto_out_wready", false,-1);
    tracep->declBit(c+80,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1037,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1038,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+81,"auto_out_wlast", false,-1);
    tracep->declBit(c+191,"auto_out_bready", false,-1);
    tracep->declBit(c+192,"auto_out_bvalid", false,-1);
    tracep->declBus(c+185,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+193,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+211,"auto_out_arready", false,-1);
    tracep->declBit(c+88,"auto_out_arvalid", false,-1);
    tracep->declBus(c+314,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1039,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+944,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+78,"auto_out_rready", false,-1);
    tracep->declBit(c+187,"auto_out_rvalid", false,-1);
    tracep->declBus(c+188,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+196,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+440,"io_enq_ready", false,-1);
    tracep->declBit(c+41,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+233,"io_deq_ready", false,-1);
    tracep->declBit(c+441,"io_deq_valid", false,-1);
    tracep->declBit(c+442,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+442,"ram_real_last", false,-1);
    tracep->declBit(c+441,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+443,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+444,"io_enq_ready", false,-1);
    tracep->declBit(c+42,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+234,"io_deq_ready", false,-1);
    tracep->declBit(c+445,"io_deq_valid", false,-1);
    tracep->declBit(c+446,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+446,"ram_real_last", false,-1);
    tracep->declBit(c+445,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+447,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+448,"io_enq_ready", false,-1);
    tracep->declBit(c+43,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+235,"io_deq_ready", false,-1);
    tracep->declBit(c+449,"io_deq_valid", false,-1);
    tracep->declBit(c+450,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+450,"ram_real_last", false,-1);
    tracep->declBit(c+449,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+451,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+452,"io_enq_ready", false,-1);
    tracep->declBit(c+44,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+236,"io_deq_ready", false,-1);
    tracep->declBit(c+453,"io_deq_valid", false,-1);
    tracep->declBit(c+454,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+454,"ram_real_last", false,-1);
    tracep->declBit(c+453,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+455,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+456,"io_enq_ready", false,-1);
    tracep->declBit(c+45,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+237,"io_deq_ready", false,-1);
    tracep->declBit(c+457,"io_deq_valid", false,-1);
    tracep->declBit(c+458,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+458,"ram_real_last", false,-1);
    tracep->declBit(c+457,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+459,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+460,"io_enq_ready", false,-1);
    tracep->declBit(c+46,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+238,"io_deq_ready", false,-1);
    tracep->declBit(c+461,"io_deq_valid", false,-1);
    tracep->declBit(c+462,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+462,"ram_real_last", false,-1);
    tracep->declBit(c+461,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+463,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+464,"io_enq_ready", false,-1);
    tracep->declBit(c+47,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+239,"io_deq_ready", false,-1);
    tracep->declBit(c+465,"io_deq_valid", false,-1);
    tracep->declBit(c+466,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+466,"ram_real_last", false,-1);
    tracep->declBit(c+465,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+467,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+468,"io_enq_ready", false,-1);
    tracep->declBit(c+48,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+240,"io_deq_ready", false,-1);
    tracep->declBit(c+469,"io_deq_valid", false,-1);
    tracep->declBit(c+470,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+470,"ram_real_last", false,-1);
    tracep->declBit(c+469,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+471,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+472,"io_enq_ready", false,-1);
    tracep->declBit(c+49,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+241,"io_deq_ready", false,-1);
    tracep->declBit(c+473,"io_deq_valid", false,-1);
    tracep->declBit(c+474,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+474,"ram_real_last", false,-1);
    tracep->declBit(c+473,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+475,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+476,"io_enq_ready", false,-1);
    tracep->declBit(c+50,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+242,"io_deq_ready", false,-1);
    tracep->declBit(c+477,"io_deq_valid", false,-1);
    tracep->declBit(c+478,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+478,"ram_real_last", false,-1);
    tracep->declBit(c+477,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+479,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+480,"io_enq_ready", false,-1);
    tracep->declBit(c+51,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+243,"io_deq_ready", false,-1);
    tracep->declBit(c+481,"io_deq_valid", false,-1);
    tracep->declBit(c+482,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+482,"ram_real_last", false,-1);
    tracep->declBit(c+481,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+483,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+484,"io_enq_ready", false,-1);
    tracep->declBit(c+52,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+244,"io_deq_ready", false,-1);
    tracep->declBit(c+485,"io_deq_valid", false,-1);
    tracep->declBit(c+486,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+486,"ram_real_last", false,-1);
    tracep->declBit(c+485,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+487,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+488,"io_enq_ready", false,-1);
    tracep->declBit(c+53,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+245,"io_deq_ready", false,-1);
    tracep->declBit(c+489,"io_deq_valid", false,-1);
    tracep->declBit(c+490,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+490,"ram_real_last", false,-1);
    tracep->declBit(c+489,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+491,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+492,"io_enq_ready", false,-1);
    tracep->declBit(c+54,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+246,"io_deq_ready", false,-1);
    tracep->declBit(c+493,"io_deq_valid", false,-1);
    tracep->declBit(c+494,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+494,"ram_real_last", false,-1);
    tracep->declBit(c+493,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+495,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+496,"io_enq_ready", false,-1);
    tracep->declBit(c+55,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+247,"io_deq_ready", false,-1);
    tracep->declBit(c+497,"io_deq_valid", false,-1);
    tracep->declBit(c+498,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+498,"ram_real_last", false,-1);
    tracep->declBit(c+497,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+499,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+500,"io_enq_ready", false,-1);
    tracep->declBit(c+56,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+248,"io_deq_ready", false,-1);
    tracep->declBit(c+501,"io_deq_valid", false,-1);
    tracep->declBit(c+502,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+502,"ram_real_last", false,-1);
    tracep->declBit(c+501,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+503,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+504,"io_enq_ready", false,-1);
    tracep->declBit(c+57,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+249,"io_deq_ready", false,-1);
    tracep->declBit(c+505,"io_deq_valid", false,-1);
    tracep->declBit(c+506,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+506,"ram_real_last", false,-1);
    tracep->declBit(c+505,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+507,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+508,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+250,"io_deq_ready", false,-1);
    tracep->declBit(c+509,"io_deq_valid", false,-1);
    tracep->declBit(c+510,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+510,"ram_real_last", false,-1);
    tracep->declBit(c+509,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+511,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+512,"io_enq_ready", false,-1);
    tracep->declBit(c+59,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+251,"io_deq_ready", false,-1);
    tracep->declBit(c+513,"io_deq_valid", false,-1);
    tracep->declBit(c+514,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+514,"ram_real_last", false,-1);
    tracep->declBit(c+513,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+515,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+516,"io_enq_ready", false,-1);
    tracep->declBit(c+60,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+252,"io_deq_ready", false,-1);
    tracep->declBit(c+517,"io_deq_valid", false,-1);
    tracep->declBit(c+518,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+518,"ram_real_last", false,-1);
    tracep->declBit(c+517,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+519,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+520,"io_enq_ready", false,-1);
    tracep->declBit(c+61,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+253,"io_deq_ready", false,-1);
    tracep->declBit(c+521,"io_deq_valid", false,-1);
    tracep->declBit(c+522,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+522,"ram_real_last", false,-1);
    tracep->declBit(c+521,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+523,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+524,"io_enq_ready", false,-1);
    tracep->declBit(c+62,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+254,"io_deq_ready", false,-1);
    tracep->declBit(c+525,"io_deq_valid", false,-1);
    tracep->declBit(c+526,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+526,"ram_real_last", false,-1);
    tracep->declBit(c+525,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+527,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+528,"io_enq_ready", false,-1);
    tracep->declBit(c+63,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+255,"io_deq_ready", false,-1);
    tracep->declBit(c+529,"io_deq_valid", false,-1);
    tracep->declBit(c+530,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+530,"ram_real_last", false,-1);
    tracep->declBit(c+529,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+531,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+532,"io_enq_ready", false,-1);
    tracep->declBit(c+64,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+256,"io_deq_ready", false,-1);
    tracep->declBit(c+533,"io_deq_valid", false,-1);
    tracep->declBit(c+534,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+534,"ram_real_last", false,-1);
    tracep->declBit(c+533,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+535,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+536,"io_enq_ready", false,-1);
    tracep->declBit(c+65,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+257,"io_deq_ready", false,-1);
    tracep->declBit(c+537,"io_deq_valid", false,-1);
    tracep->declBit(c+538,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+538,"ram_real_last", false,-1);
    tracep->declBit(c+537,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+539,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+540,"io_enq_ready", false,-1);
    tracep->declBit(c+66,"io_enq_valid", false,-1);
    tracep->declBit(c+327,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+258,"io_deq_ready", false,-1);
    tracep->declBit(c+541,"io_deq_valid", false,-1);
    tracep->declBit(c+542,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+542,"ram_real_last", false,-1);
    tracep->declBit(c+541,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+543,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+544,"io_enq_ready", false,-1);
    tracep->declBit(c+67,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+259,"io_deq_ready", false,-1);
    tracep->declBit(c+545,"io_deq_valid", false,-1);
    tracep->declBit(c+546,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+546,"ram_real_last", false,-1);
    tracep->declBit(c+545,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+547,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+548,"io_enq_ready", false,-1);
    tracep->declBit(c+68,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+260,"io_deq_ready", false,-1);
    tracep->declBit(c+549,"io_deq_valid", false,-1);
    tracep->declBit(c+550,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+550,"ram_real_last", false,-1);
    tracep->declBit(c+549,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+551,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+552,"io_enq_ready", false,-1);
    tracep->declBit(c+69,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+261,"io_deq_ready", false,-1);
    tracep->declBit(c+553,"io_deq_valid", false,-1);
    tracep->declBit(c+554,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+554,"ram_real_last", false,-1);
    tracep->declBit(c+553,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+555,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+556,"io_enq_ready", false,-1);
    tracep->declBit(c+70,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+262,"io_deq_ready", false,-1);
    tracep->declBit(c+557,"io_deq_valid", false,-1);
    tracep->declBit(c+558,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+558,"ram_real_last", false,-1);
    tracep->declBit(c+557,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+559,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+560,"io_enq_ready", false,-1);
    tracep->declBit(c+71,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+263,"io_deq_ready", false,-1);
    tracep->declBit(c+561,"io_deq_valid", false,-1);
    tracep->declBit(c+562,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+562,"ram_real_last", false,-1);
    tracep->declBit(c+561,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+563,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+564,"io_enq_ready", false,-1);
    tracep->declBit(c+72,"io_enq_valid", false,-1);
    tracep->declBit(c+328,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+264,"io_deq_ready", false,-1);
    tracep->declBit(c+565,"io_deq_valid", false,-1);
    tracep->declBit(c+566,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+566,"ram_real_last", false,-1);
    tracep->declBit(c+565,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+567,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+93,"reset", false,-1);
    tracep->declBit(c+324,"auto_master_out_awready", false,-1);
    tracep->declBit(c+75,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1187,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1040,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1188,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1041,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1042,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+325,"auto_master_out_wready", false,-1);
    tracep->declBit(c+76,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1152,"auto_master_out_bready", false,-1);
    tracep->declBit(c+184,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+185,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+186,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+326,"auto_master_out_arready", false,-1);
    tracep->declBit(c+77,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1190,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1191,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+945,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1192,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+78,"auto_master_out_rready", false,-1);
    tracep->declBit(c+187,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+188,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+38,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1153,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+39,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+93,"reset", false,-1);
    tracep->declBit(c+1177,"io_interrupt", false,-1);
    tracep->declBit(c+324,"io_master_awready", false,-1);
    tracep->declBit(c+75,"io_master_awvalid", false,-1);
    tracep->declBus(c+1040,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1187,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1188,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1041,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1042,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+325,"io_master_wready", false,-1);
    tracep->declBit(c+76,"io_master_wvalid", false,-1);
    tracep->declBus(c+1043,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"io_master_wlast", false,-1);
    tracep->declBit(c+1152,"io_master_bready", false,-1);
    tracep->declBit(c+184,"io_master_bvalid", false,-1);
    tracep->declBus(c+186,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+185,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+326,"io_master_arready", false,-1);
    tracep->declBit(c+77,"io_master_arvalid", false,-1);
    tracep->declBus(c+1045,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1190,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1191,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+945,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1192,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+78,"io_master_rready", false,-1);
    tracep->declBit(c+187,"io_master_rvalid", false,-1);
    tracep->declBus(c+1153,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+38,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+39,"io_master_rlast", false,-1);
    tracep->declBus(c+188,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1194,"io_slave_awready", false,-1);
    tracep->declBit(c+1177,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1195,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1196,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1191,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1197,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1198,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1199,"io_slave_wready", false,-1);
    tracep->declBit(c+1177,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1195,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1196,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1177,"io_slave_wlast", false,-1);
    tracep->declBit(c+1177,"io_slave_bready", false,-1);
    tracep->declBit(c+1200,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1201,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1202,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1203,"io_slave_arready", false,-1);
    tracep->declBit(c+1177,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1195,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1196,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1191,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1197,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1198,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1177,"io_slave_rready", false,-1);
    tracep->declBit(c+1204,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1205,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1206,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1207,"io_slave_rlast", false,-1);
    tracep->declBus(c+1208,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+946,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1065,"npc", false,-1, 31,0);
    tracep->declBus(c+861,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+947,"inst", false,-1, 31,0);
    tracep->declBit(c+948,"ifu_valid", false,-1);
    tracep->declBit(c+949,"ifu_arvalid", false,-1);
    tracep->declBit(c+950,"ifu_arready", false,-1);
    tracep->declBus(c+861,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+265,"ifu_rvalid", false,-1);
    tracep->declBit(c+946,"ifu_rready", false,-1);
    tracep->declBus(c+266,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+951,"reg_process", false,-1);
    tracep->declBus(c+952,"src1", false,-1, 4,0);
    tracep->declBus(c+953,"src2", false,-1, 4,0);
    tracep->declBus(c+954,"rd", false,-1, 4,0);
    tracep->declBus(c+955,"imm", false,-1, 31,0);
    tracep->declBit(c+956,"ebreaksig", false,-1);
    tracep->declBit(c+957,"mretsig", false,-1);
    tracep->declBit(c+958,"ecallsig", false,-1);
    tracep->declBit(c+959,"regew", false,-1);
    tracep->declBit(c+960,"memew", false,-1);
    tracep->declBit(c+961,"memer", false,-1);
    tracep->declBit(c+962,"muximm", false,-1);
    tracep->declBus(c+963,"func3", false,-1, 2,0);
    tracep->declBus(c+964,"muxsig", false,-1, 2,0);
    tracep->declBit(c+965,"func7", false,-1);
    tracep->declBit(c+966,"btypebranch", false,-1);
    tracep->declBit(c+967,"jalsig", false,-1);
    tracep->declBit(c+968,"jalrsig", false,-1);
    tracep->declBit(c+969,"auipcsig", false,-1);
    tracep->declBus(c+970,"aluop", false,-1, 1,0);
    tracep->declBit(c+971,"csrrw", false,-1);
    tracep->declBit(c+972,"csrrs", false,-1);
    tracep->declBit(c+948,"idu_valid", false,-1);
    tracep->declBus(c+973,"memmask", false,-1, 2,0);
    tracep->declBit(c+974,"memsextsig", false,-1);
    tracep->declBus(c+267,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1066,"regout1", false,-1, 31,0);
    tracep->declBus(c+1067,"regout2", false,-1, 31,0);
    tracep->declBus(c+862,"mepc", false,-1, 31,0);
    tracep->declBus(c+863,"mtvec", false,-1, 31,0);
    tracep->declBit(c+946,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1068,"res", false,-1, 31,0);
    tracep->declBus(c+1069,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+948,"exu_valid", false,-1);
    tracep->declBit(c+946,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1161,"memvalid", false,-1);
    tracep->declBus(c+975,"awvalid", false,-1, 1,0);
    tracep->declBus(c+975,"wvalid", false,-1, 1,0);
    tracep->declBus(c+976,"arvalid", false,-1, 1,0);
    tracep->declBus(c+977,"rready", false,-1, 1,0);
    tracep->declBus(c+978,"bready", false,-1, 1,0);
    tracep->declBus(c+73,"bvalid", false,-1, 1,0);
    tracep->declBus(c+268,"rvalid", false,-1, 1,0);
    tracep->declBus(c+568,"awready", false,-1, 1,0);
    tracep->declBus(c+568,"wready", false,-1, 1,0);
    tracep->declBus(c+979,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1162+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+269+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1070+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1072+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1074+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+271+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1076+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+980+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1209,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+93,"reset", false,-1);
    tracep->declBus(c+975,"awvalid", false,-1, 1,0);
    tracep->declBus(c+975,"wvalid", false,-1, 1,0);
    tracep->declBus(c+976,"arvalid", false,-1, 1,0);
    tracep->declBus(c+977,"rready", false,-1, 1,0);
    tracep->declBus(c+978,"bready", false,-1, 1,0);
    tracep->declBus(c+73,"bvalid", false,-1, 1,0);
    tracep->declBus(c+268,"rvalid", false,-1, 1,0);
    tracep->declBus(c+568,"awready", false,-1, 1,0);
    tracep->declBus(c+568,"wready", false,-1, 1,0);
    tracep->declBus(c+979,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1078+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1080+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1082+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1084+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+273+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+275+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1086+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+982+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->declBit(c+75,"awvalid_out", false,-1);
    tracep->declBit(c+76,"wvalid_out", false,-1);
    tracep->declBit(c+77,"arvalid_out", false,-1);
    tracep->declBit(c+78,"rready_out", false,-1);
    tracep->declBit(c+1152,"bready_out", false,-1);
    tracep->declBit(c+184,"bvalid_in", false,-1);
    tracep->declBit(c+187,"rvalid_in", false,-1);
    tracep->declBit(c+325,"awready_in", false,-1);
    tracep->declBit(c+325,"wready_in", false,-1);
    tracep->declBit(c+326,"arready_in", false,-1);
    tracep->declBus(c+1045,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1040,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1043,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+1044,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+38,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+186,"bresp_in", false,-1, 1,0);
    tracep->declBus(c+1041,"awsize_out", false,-1, 2,0);
    tracep->declBus(c+945,"arsize_out", false,-1, 2,0);
    tracep->declBit(c+569,"busy", false,-1);
    tracep->declBus(c+570,"giant", false,-1, 1,0);
    tracep->declBus(c+571,"i", false,-1, 31,0);
    tracep->declBus(c+1040,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1043,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1045,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1044,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1041,"awsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+945,"arsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1210,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+963,"func3", false,-1, 2,0);
    tracep->declBit(c+966,"btypebranch", false,-1);
    tracep->declBit(c+965,"func7", false,-1);
    tracep->declBus(c+970,"aluop", false,-1, 1,0);
    tracep->declBit(c+968,"jalrsig", false,-1);
    tracep->declBit(c+967,"jalsig", false,-1);
    tracep->declBus(c+955,"imm", false,-1, 31,0);
    tracep->declBit(c+962,"muximm", false,-1);
    tracep->declBus(c+1066,"regout1", false,-1, 31,0);
    tracep->declBus(c+1067,"regout2", false,-1, 31,0);
    tracep->declBus(c+861,"pc", false,-1, 31,0);
    tracep->declBit(c+969,"auipcsig", false,-1);
    tracep->declBit(c+957,"mretsig", false,-1);
    tracep->declBit(c+958,"ecallsig", false,-1);
    tracep->declBus(c+863,"mtvec", false,-1, 31,0);
    tracep->declBus(c+862,"mepc", false,-1, 31,0);
    tracep->declBit(c+948,"valid_from", false,-1);
    tracep->declBit(c+946,"ready_from", false,-1);
    tracep->declBus(c+1068,"res", false,-1, 31,0);
    tracep->declBus(c+1065,"npc", false,-1, 31,0);
    tracep->declBus(c+1069,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+948,"valid_to", false,-1);
    tracep->declBit(c+946,"ready_to", false,-1);
    tracep->declBus(c+864,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1088,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+984,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1089,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1090,"zero", false,-1);
    tracep->declBit(c+1091,"signal", false,-1);
    tracep->declBit(c+1092,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1066,"A", false,-1, 31,0);
    tracep->declBus(c+1089,"B", false,-1, 31,0);
    tracep->declBus(c+984,"op", false,-1, 4,0);
    tracep->declBus(c+1068,"res", false,-1, 31,0);
    tracep->declBit(c+1090,"zero", false,-1);
    tracep->declBit(c+1091,"signal", false,-1);
    tracep->declBit(c+1092,"carry", false,-1);
    tracep->declBit(c+985,"addsig", false,-1);
    tracep->declBit(c+986,"logsig", false,-1);
    tracep->declBit(c+987,"shfsig", false,-1);
    tracep->declBit(c+988,"sltsig", false,-1);
    tracep->declBit(c+1092,"carry_tmp", false,-1);
    tracep->declBit(c+989,"type_I", false,-1);
    tracep->declBus(c+1093,"logres", false,-1, 31,0);
    tracep->declBus(c+1094,"addres", false,-1, 31,0);
    tracep->declBit(c+1095,"addzero", false,-1);
    tracep->declBus(c+1096,"shfres", false,-1, 31,0);
    tracep->declBus(c+1097,"sltres", false,-1, 31,0);
    tracep->declBus(c+1066,"A_s", false,-1, 31,0);
    tracep->declBus(c+1089,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+963,"func3", false,-1, 2,0);
    tracep->declBit(c+965,"func7", false,-1);
    tracep->declBus(c+970,"aluop", false,-1, 1,0);
    tracep->declBit(c+968,"jalrsig", false,-1);
    tracep->declBus(c+984,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+989,"type_I", false,-1);
    tracep->declBit(c+990,"type_B", false,-1);
    tracep->declBit(c+991,"type_R", false,-1);
    tracep->declBit(c+992,"addsig", false,-1);
    tracep->declBus(c+993,"branchop", false,-1, 3,0);
    tracep->declBus(c+994,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+966,"btypebranch", false,-1);
    tracep->declBus(c+963,"func3", false,-1, 2,0);
    tracep->declBit(c+1090,"zero", false,-1);
    tracep->declBit(c+1091,"signal", false,-1);
    tracep->declBit(c+1092,"carry", false,-1);
    tracep->declBus(c+1068,"res", false,-1, 31,0);
    tracep->declBus(c+864,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1088,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+967,"jalsig", false,-1);
    tracep->declBit(c+968,"jalrsig", false,-1);
    tracep->declBit(c+969,"auipcsig", false,-1);
    tracep->declBit(c+957,"mretsig", false,-1);
    tracep->declBit(c+958,"ecallsig", false,-1);
    tracep->declBus(c+863,"mtvec", false,-1, 31,0);
    tracep->declBus(c+862,"mepc", false,-1, 31,0);
    tracep->declBus(c+1065,"npc", false,-1, 31,0);
    tracep->declBus(c+1069,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1211,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1089,"out", false,-1, 31,0);
    tracep->declBus(c+962,"key", false,-1, 0,0);
    tracep->declArray(c+1017,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1211,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1213,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1089,"out", false,-1, 31,0);
    tracep->declBus(c+962,"key", false,-1, 0,0);
    tracep->declBus(c+1195,"default_out", false,-1, 31,0);
    tracep->declArray(c+1017,"lut", false,-1, 65,0);
    tracep->declBus(c+1214,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1020+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1024+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1098,"lut_out", false,-1, 31,0);
    tracep->declBit(c+995,"hit", false,-1);
    tracep->declBus(c+1215,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+861,"pc", false,-1, 31,0);
    tracep->declBus(c+864,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+861,"pc", false,-1, 31,0);
    tracep->declBus(c+955,"imm", false,-1, 31,0);
    tracep->declBus(c+1088,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+947,"inst", false,-1, 31,0);
    tracep->declBit(c+948,"valid_from", false,-1);
    tracep->declBit(c+946,"ready_from", false,-1);
    tracep->declBit(c+956,"ebreaksig", false,-1);
    tracep->declBit(c+958,"ecallsig", false,-1);
    tracep->declBit(c+957,"mretsig", false,-1);
    tracep->declBus(c+955,"imm", false,-1, 31,0);
    tracep->declBus(c+963,"func3", false,-1, 2,0);
    tracep->declBit(c+965,"func7", false,-1);
    tracep->declBus(c+952,"src1", false,-1, 4,0);
    tracep->declBus(c+953,"src2", false,-1, 4,0);
    tracep->declBus(c+954,"rd", false,-1, 4,0);
    tracep->declBit(c+960,"memew", false,-1);
    tracep->declBus(c+964,"muxsig", false,-1, 2,0);
    tracep->declBit(c+961,"memer", false,-1);
    tracep->declBit(c+959,"regew", false,-1);
    tracep->declBit(c+962,"muximm", false,-1);
    tracep->declBit(c+966,"btypebranch", false,-1);
    tracep->declBit(c+968,"jalrsig", false,-1);
    tracep->declBit(c+967,"jalsig", false,-1);
    tracep->declBus(c+970,"aluop", false,-1, 1,0);
    tracep->declBit(c+969,"auipcsig", false,-1);
    tracep->declBit(c+971,"csrrw", false,-1);
    tracep->declBit(c+972,"csrrs", false,-1);
    tracep->declBit(c+948,"valid_to", false,-1);
    tracep->declBit(c+946,"ready_to", false,-1);
    tracep->declBus(c+973,"memmask", false,-1, 2,0);
    tracep->declBit(c+974,"memsextsig", false,-1);
    tracep->declBit(c+956,"ebreak", false,-1);
    tracep->declBit(c+958,"ecall", false,-1);
    tracep->declBit(c+957,"mret", false,-1);
    tracep->declBus(c+963,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+965,"func7bridge", false,-1);
    tracep->declBus(c+996,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+947,"inst", false,-1, 31,0);
    tracep->declBit(c+956,"ebreaksig", false,-1);
    tracep->declBit(c+958,"ecallsig", false,-1);
    tracep->declBit(c+957,"mretsig", false,-1);
    tracep->declBus(c+955,"imm", false,-1, 31,0);
    tracep->declBus(c+996,"opcode", false,-1, 6,0);
    tracep->declBus(c+963,"func3", false,-1, 2,0);
    tracep->declBit(c+965,"func7", false,-1);
    tracep->declBus(c+952,"src1", false,-1, 4,0);
    tracep->declBus(c+953,"src2", false,-1, 4,0);
    tracep->declBus(c+954,"rd", false,-1, 4,0);
    tracep->declBus(c+973,"memmask", false,-1, 2,0);
    tracep->declBit(c+974,"memsextsig", false,-1);
    tracep->declBit(c+997,"type_I", false,-1);
    tracep->declBit(c+998,"type_R", false,-1);
    tracep->declBit(c+999,"type_U", false,-1);
    tracep->declBit(c+960,"type_S", false,-1);
    tracep->declBit(c+967,"type_J", false,-1);
    tracep->declBit(c+966,"type_B", false,-1);
    tracep->declBus(c+1000,"I_imm", false,-1, 31,0);
    tracep->declBus(c+1001,"U_imm", false,-1, 31,0);
    tracep->declBus(c+1002,"S_imm", false,-1, 31,0);
    tracep->declBus(c+1003,"J_imm", false,-1, 31,0);
    tracep->declBus(c+1004,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+996,"opcode", false,-1, 6,0);
    tracep->declBus(c+963,"func3", false,-1, 2,0);
    tracep->declBit(c+965,"func7", false,-1);
    tracep->declBit(c+956,"ebreaksig", false,-1);
    tracep->declBit(c+958,"ecallsig", false,-1);
    tracep->declBit(c+957,"mretsig", false,-1);
    tracep->declBit(c+960,"memew", false,-1);
    tracep->declBus(c+964,"muxsig", false,-1, 2,0);
    tracep->declBit(c+961,"memer", false,-1);
    tracep->declBit(c+959,"regew", false,-1);
    tracep->declBit(c+962,"muximm", false,-1);
    tracep->declBit(c+966,"btypebranch", false,-1);
    tracep->declBit(c+968,"jalrsig", false,-1);
    tracep->declBit(c+967,"jalsig", false,-1);
    tracep->declBus(c+970,"aluop", false,-1, 1,0);
    tracep->declBit(c+969,"auipcsig", false,-1);
    tracep->declBit(c+971,"csrrw", false,-1);
    tracep->declBit(c+972,"csrrs", false,-1);
    tracep->declBit(c+997,"type_I", false,-1);
    tracep->declBit(c+998,"type_R", false,-1);
    tracep->declBit(c+999,"type_U", false,-1);
    tracep->declBit(c+960,"type_S", false,-1);
    tracep->declBit(c+967,"type_J", false,-1);
    tracep->declBit(c+966,"type_B", false,-1);
    tracep->declBit(c+961,"load", false,-1);
    tracep->declBit(c+960,"store", false,-1);
    tracep->declBit(c+1005,"regwritepc", false,-1);
    tracep->declBit(c+961,"regwritemem", false,-1);
    tracep->declBit(c+1006,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+93,"rst", false,-1);
    tracep->declBus(c+1065,"npc", false,-1, 31,0);
    tracep->declBit(c+946,"ready", false,-1);
    tracep->declBus(c+861,"pc", false,-1, 31,0);
    tracep->declBus(c+947,"inst", false,-1, 31,0);
    tracep->declBit(c+948,"valid", false,-1);
    tracep->declBit(c+951,"regprocess", false,-1);
    tracep->declBit(c+949,"arvalid", false,-1);
    tracep->declBit(c+950,"arready", false,-1);
    tracep->declBus(c+861,"araddr", false,-1, 31,0);
    tracep->declBit(c+265,"rvalid", false,-1);
    tracep->declBit(c+946,"rready", false,-1);
    tracep->declBus(c+266,"rdata", false,-1, 31,0);
    tracep->declBus(c+861,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1007,"infetch_ready", false,-1);
    tracep->declBus(c+1008,"state", false,-1, 2,0);
    tracep->declBus(c+947,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBus(c+1065,"npc", false,-1, 31,0);
    tracep->declBit(c+93,"rst", false,-1);
    tracep->declBit(c+1007,"ready_from", false,-1);
    tracep->declBus(c+861,"pcout", false,-1, 31,0);
    tracep->declBus(c+1216,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+93,"rst", false,-1);
    tracep->declBit(c+1164,"ew", false,-1);
    tracep->declBus(c+954,"addr", false,-1, 4,0);
    tracep->declBus(c+952,"src1", false,-1, 4,0);
    tracep->declBus(c+953,"src2", false,-1, 4,0);
    tracep->declBus(c+1009,"csr", false,-1, 11,0);
    tracep->declBus(c+267,"data", false,-1, 31,0);
    tracep->declBit(c+971,"csrrw", false,-1);
    tracep->declBit(c+972,"csrrs", false,-1);
    tracep->declBit(c+958,"ecallsig", false,-1);
    tracep->declBit(c+948,"valid", false,-1);
    tracep->declBus(c+1066,"regout1", false,-1, 31,0);
    tracep->declBus(c+1067,"regout2", false,-1, 31,0);
    tracep->declBus(c+862,"mepc", false,-1, 31,0);
    tracep->declBus(c+863,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+865+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+897+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1010,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+277,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1010,"out", false,-1, 1,0);
    tracep->declBus(c+1009,"key", false,-1, 11,0);
    tracep->declQuad(c+1219,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1218,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1213,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1010,"out", false,-1, 1,0);
    tracep->declBus(c+1009,"key", false,-1, 11,0);
    tracep->declBus(c+1198,"default_out", false,-1, 1,0);
    tracep->declQuad(c+1219,"lut", false,-1, 55,0);
    tracep->declBus(c+1221,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1011,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1012,"hit", false,-1);
    tracep->declBus(c+1222,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+93,"rst", false,-1);
    tracep->declBit(c+1165,"ew", false,-1);
    tracep->declBit(c+971,"csrrw", false,-1);
    tracep->declBit(c+972,"csrrs", false,-1);
    tracep->declBit(c+958,"ecall", false,-1);
    tracep->declBus(c+1010,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+954,"addr", false,-1, 4,0);
    tracep->declBus(c+277,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+901+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+933+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+937,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBus(c+1068,"res", false,-1, 31,0);
    tracep->declBus(c+1067,"regout2", false,-1, 31,0);
    tracep->declBit(c+960,"memew", false,-1);
    tracep->declBit(c+961,"memer", false,-1);
    tracep->declBus(c+955,"imm", false,-1, 31,0);
    tracep->declBus(c+1069,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+964,"muxsig", false,-1, 2,0);
    tracep->declBit(c+948,"valid_from", false,-1);
    tracep->declBus(c+973,"memmask", false,-1, 2,0);
    tracep->declBit(c+974,"memsextsig", false,-1);
    tracep->declBus(c+267,"regwrite", false,-1, 31,0);
    tracep->declBit(c+946,"ready_to", false,-1);
    tracep->declBit(c+1161,"memvalid", false,-1);
    tracep->declBit(c+1013,"awvalid", false,-1);
    tracep->declBit(c+572,"awready", false,-1);
    tracep->declBus(c+1068,"awaddr", false,-1, 31,0);
    tracep->declBit(c+1013,"wvalid", false,-1);
    tracep->declBit(c+572,"wready", false,-1);
    tracep->declBus(c+1099,"wdata", false,-1, 31,0);
    tracep->declBus(c+1100,"wstrb", false,-1, 3,0);
    tracep->declBit(c+74,"bvalid", false,-1);
    tracep->declBit(c+960,"bready", false,-1);
    tracep->declBus(c+278,"bresp", false,-1, 1,0);
    tracep->declBit(c+1166,"arvalid", false,-1);
    tracep->declBit(c+1014,"arready", false,-1);
    tracep->declBus(c+1068,"araddr", false,-1, 31,0);
    tracep->declBit(c+279,"rvalid", false,-1);
    tracep->declBit(c+961,"rready", false,-1);
    tracep->declBus(c+280,"rdata", false,-1, 31,0);
    tracep->declBus(c+1101,"awsize", false,-1, 2,0);
    tracep->declBus(c+1015,"arsize", false,-1, 2,0);
    tracep->declBus(c+1042,"awburst", false,-1, 1,0);
    tracep->declBus(c+573,"state", false,-1, 1,0);
    tracep->declBus(c+281,"memread", false,-1, 31,0);
    tracep->declBus(c+1102,"wdata_offset", false,-1, 1,0);
    tracep->declBit(c+1167,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+280,"data", false,-1, 31,0);
    tracep->declBus(c+973,"memmask", false,-1, 2,0);
    tracep->declBit(c+974,"memsextsig", false,-1);
    tracep->declBus(c+1103,"addr_offset", false,-1, 1,0);
    tracep->declBus(c+281,"read", false,-1, 31,0);
    tracep->declBus(c+282,"read_u", false,-1, 31,0);
    tracep->declBus(c+283,"read_s", false,-1, 31,0);
    tracep->declBus(c+284,"read_sb", false,-1, 31,0);
    tracep->declBus(c+285,"read_sh", false,-1, 31,0);
    tracep->declBus(c+286,"byte_data", false,-1, 7,0);
    tracep->declBus(c+287,"halfword_data", false,-1, 15,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1223,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1212,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+286,"input_number", false,-1, 7,0);
    tracep->declBus(c+284,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1224,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1212,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+287,"input_number", false,-1, 15,0);
    tracep->declBus(c+285,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1225,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+267,"out", false,-1, 31,0);
    tracep->declBus(c+964,"key", false,-1, 2,0);
    tracep->declBus(c+1213,"default_out", false,-1, 31,0);
    tracep->declArray(c+94,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1225,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1212,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1211,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+267,"out", false,-1, 31,0);
    tracep->declBus(c+964,"key", false,-1, 2,0);
    tracep->declBus(c+1213,"default_out", false,-1, 31,0);
    tracep->declArray(c+94,"lut", false,-1, 139,0);
    tracep->declBus(c+1226,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+99+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+107+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+288,"lut_out", false,-1, 31,0);
    tracep->declBit(c+289,"hit", false,-1);
    tracep->declBus(c+1222,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("strbcontol ");
    tracep->declBus(c+1068,"awaddr", false,-1, 31,0);
    tracep->declBus(c+973,"wirtelen", false,-1, 2,0);
    tracep->declBus(c+1100,"wstrb", false,-1, 3,0);
    tracep->declBus(c+1101,"awsize", false,-1, 2,0);
    tracep->declBus(c+1102,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1042,"awburst", false,-1, 1,0);
    tracep->declBit(c+1104,"inuart", false,-1);
    tracep->declBit(c+1105,"insram", false,-1);
    tracep->declBus(c+1106,"bus_size", false,-1, 1,0);
    tracep->declBus(c+1016,"wstrb_general", false,-1, 3,0);
    tracep->declBus(c+1227,"wstrb_byte", false,-1, 3,0);
    tracep->declBus(c+1228,"wstrb_halfword", false,-1, 3,0);
    tracep->declBus(c+1107,"wstrb_word", false,-1, 3,0);
    tracep->declBus(c+1108,"mux", false,-1, 4,0);
    tracep->pushNamePrefix("len_mux ");
    tracep->declBus(c+1225,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1209,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1225,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1101,"out", false,-1, 2,0);
    tracep->declBus(c+1106,"key", false,-1, 1,0);
    tracep->declBus(c+973,"default_out", false,-1, 2,0);
    tracep->declBus(c+1229,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1225,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1209,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1225,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1211,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1101,"out", false,-1, 2,0);
    tracep->declBus(c+1106,"key", false,-1, 1,0);
    tracep->declBus(c+973,"default_out", false,-1, 2,0);
    tracep->declBus(c+1229,"lut", false,-1, 14,0);
    tracep->declBus(c+1230,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+19+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+22+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+25+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1109,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1110,"hit", false,-1);
    tracep->declBus(c+1231,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("type_mux ");
    tracep->declBus(c+1209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1209,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1106,"out", false,-1, 1,0);
    tracep->declBus(c+1111,"key", false,-1, 1,0);
    tracep->declBus(c+1198,"default_out", false,-1, 1,0);
    tracep->declBus(c+1232,"lut", false,-1, 7,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1209,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1209,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1209,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1211,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1106,"out", false,-1, 1,0);
    tracep->declBus(c+1111,"key", false,-1, 1,0);
    tracep->declBus(c+1198,"default_out", false,-1, 1,0);
    tracep->declBus(c+1232,"lut", false,-1, 7,0);
    tracep->declBus(c+1217,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+28+i*1,"pair_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+30+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+32+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1112,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1113,"hit", false,-1);
    tracep->declBus(c+1215,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wstrb_mux ");
    tracep->declBus(c+1217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1209,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1217,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1100,"out", false,-1, 3,0);
    tracep->declBus(c+1106,"key", false,-1, 1,0);
    tracep->declBus(c+1026,"lut", false,-1, 23,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1217,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1209,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1217,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1213,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1100,"out", false,-1, 3,0);
    tracep->declBus(c+1106,"key", false,-1, 1,0);
    tracep->declBus(c+1196,"default_out", false,-1, 3,0);
    tracep->declBus(c+1026,"lut", false,-1, 23,0);
    tracep->declBus(c+1233,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1027+i*1,"pair_list", true,(i+0), 5,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+34+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1031+i*1,"data_list", true,(i+0), 3,0);
    }
    tracep->declBus(c+1114,"lut_out", false,-1, 3,0);
    tracep->declBit(c+1115,"hit", false,-1);
    tracep->declBus(c+1222,"i", false,-1, 31,0);
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"io_d", false,-1);
    tracep->declBit(c+574,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"io_d", false,-1);
    tracep->declBit(c+574,"io_q", false,-1);
    tracep->declBit(c+574,"sync_0", false,-1);
    tracep->declBit(c+575,"sync_1", false,-1);
    tracep->declBit(c+576,"sync_2", false,-1);
    tracep->declBit(c+577,"sync_3", false,-1);
    tracep->declBit(c+578,"sync_4", false,-1);
    tracep->declBit(c+579,"sync_5", false,-1);
    tracep->declBit(c+580,"sync_6", false,-1);
    tracep->declBit(c+581,"sync_7", false,-1);
    tracep->declBit(c+582,"sync_8", false,-1);
    tracep->declBit(c+583,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+122,"auto_in_psel", false,-1);
    tracep->declBit(c+1147,"auto_in_penable", false,-1);
    tracep->declBit(c+113,"auto_in_pwrite", false,-1);
    tracep->declBus(c+121,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1176,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1184,"auto_in_pready", false,-1);
    tracep->declBit(c+1185,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1186,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1119,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1120,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1121,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1122,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1123,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1124,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1125,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1126,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1127,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1128,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+143,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+122,"in_psel", false,-1);
    tracep->declBit(c+1147,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1184,"in_pready", false,-1);
    tracep->declBus(c+1186,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1185,"in_pslverr", false,-1);
    tracep->declBus(c+1119,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1120,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1121,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1122,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1123,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1124,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1125,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1126,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1127,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1128,"gpio_seg_7", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+120,"auto_in_psel", false,-1);
    tracep->declBit(c+1146,"auto_in_penable", false,-1);
    tracep->declBit(c+113,"auto_in_pwrite", false,-1);
    tracep->declBus(c+121,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1176,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1181,"auto_in_pready", false,-1);
    tracep->declBit(c+1182,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1183,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1129,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1130,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+143,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+120,"in_psel", false,-1);
    tracep->declBit(c+1146,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1181,"in_pready", false,-1);
    tracep->declBus(c+1183,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1182,"in_pslverr", false,-1);
    tracep->declBit(c+1129,"ps2_clk", false,-1);
    tracep->declBit(c+1130,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+1157,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1158,"auto_in_wvalid", false,-1);
    tracep->declBit(c+384,"auto_in_arready", false,-1);
    tracep->declBit(c+1159,"auto_in_arvalid", false,-1);
    tracep->declBus(c+314,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1056,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1160,"auto_in_rready", false,-1);
    tracep->declBit(c+385,"auto_in_rvalid", false,-1);
    tracep->declBus(c+386,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+387,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+385,"state", false,-1);
    tracep->declBus(c+387,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+386,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1116,"raddr", false,-1, 31,0);
    tracep->declBit(c+144,"ren", false,-1);
    tracep->declBus(c+145,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+123,"auto_in_psel", false,-1);
    tracep->declBit(c+1148,"auto_in_penable", false,-1);
    tracep->declBit(c+113,"auto_in_pwrite", false,-1);
    tracep->declBus(c+111,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1176,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1149,"auto_in_pready", false,-1);
    tracep->declBit(c+1177,"auto_in_pslverr", false,-1);
    tracep->declBus(c+311,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1141,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+1142,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+176,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+111,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+123,"in_psel", false,-1);
    tracep->declBit(c+1148,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1149,"in_pready", false,-1);
    tracep->declBus(c+311,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1177,"in_pslverr", false,-1);
    tracep->declBit(c+1141,"qspi_sck", false,-1);
    tracep->declBit(c+1142,"qspi_ce_n", false,-1);
    tracep->declBus(c+176,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+176,"din", false,-1, 3,0);
    tracep->declBus(c+290,"dout", false,-1, 3,0);
    tracep->declBus(c+291,"douten", false,-1, 3,0);
    tracep->declBit(c+1168,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1117,"clk_i", false,-1);
    tracep->declBit(c+1118,"rst_i", false,-1);
    tracep->declBus(c+111,"adr_i", false,-1, 31,0);
    tracep->declBus(c+114,"dat_i", false,-1, 31,0);
    tracep->declBus(c+311,"dat_o", false,-1, 31,0);
    tracep->declBus(c+115,"sel_i", false,-1, 3,0);
    tracep->declBit(c+123,"cyc_i", false,-1);
    tracep->declBit(c+123,"stb_i", false,-1);
    tracep->declBit(c+1168,"ack_o", false,-1);
    tracep->declBit(c+113,"we_i", false,-1);
    tracep->declBit(c+1141,"sck", false,-1);
    tracep->declBit(c+1142,"ce_n", false,-1);
    tracep->declBus(c+176,"din", false,-1, 3,0);
    tracep->declBus(c+290,"dout", false,-1, 3,0);
    tracep->declBus(c+291,"douten", false,-1, 3,0);
    tracep->declBus(c+1234,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1235,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+637,"mr_sck", false,-1);
    tracep->declBit(c+638,"mr_ce_n", false,-1);
    tracep->declBus(c+176,"mr_din", false,-1, 3,0);
    tracep->declBus(c+639,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+640,"mr_doe", false,-1);
    tracep->declBit(c+641,"mw_sck", false,-1);
    tracep->declBit(c+642,"mw_ce_n", false,-1);
    tracep->declBus(c+176,"mw_din", false,-1, 3,0);
    tracep->declBus(c+292,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+643,"mw_doe", false,-1);
    tracep->declBit(c+293,"mr_rd", false,-1);
    tracep->declBit(c+644,"mr_done", false,-1);
    tracep->declBit(c+294,"mw_wr", false,-1);
    tracep->declBit(c+295,"mw_done", false,-1);
    tracep->declBit(c+123,"wb_valid", false,-1);
    tracep->declBit(c+146,"wb_we", false,-1);
    tracep->declBit(c+147,"wb_re", false,-1);
    tracep->declBit(c+645,"state", false,-1);
    tracep->declBit(c+296,"nstate", false,-1);
    tracep->declBus(c+148,"size", false,-1, 2,0);
    tracep->declBus(c+149,"byte0", false,-1, 7,0);
    tracep->declBus(c+150,"byte1", false,-1, 7,0);
    tracep->declBus(c+151,"byte2", false,-1, 7,0);
    tracep->declBus(c+152,"byte3", false,-1, 7,0);
    tracep->declBus(c+153,"wdata", false,-1, 31,0);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1169,"rst_n", false,-1);
    tracep->declBus(c+154,"addr", false,-1, 23,0);
    tracep->declBit(c+293,"rd", false,-1);
    tracep->declBus(c+1236,"size", false,-1, 2,0);
    tracep->declBit(c+644,"done", false,-1);
    tracep->declBus(c+311,"line", false,-1, 31,0);
    tracep->declBit(c+637,"sck", false,-1);
    tracep->declBit(c+638,"ce_n", false,-1);
    tracep->declBus(c+176,"din", false,-1, 3,0);
    tracep->declBus(c+639,"dout", false,-1, 3,0);
    tracep->declBit(c+640,"douten", false,-1);
    tracep->declBus(c+1234,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1235,"READ", false,-1, 0,0);
    tracep->declBus(c+1237,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+646,"state", false,-1);
    tracep->declBit(c+297,"nstate", false,-1);
    tracep->declBus(c+647,"counter", false,-1, 7,0);
    tracep->declBus(c+648,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+584+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1238,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+649,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1169,"rst_n", false,-1);
    tracep->declBus(c+155,"addr", false,-1, 23,0);
    tracep->declBus(c+153,"line", false,-1, 31,0);
    tracep->declBus(c+148,"size", false,-1, 2,0);
    tracep->declBit(c+294,"wr", false,-1);
    tracep->declBit(c+295,"done", false,-1);
    tracep->declBit(c+641,"sck", false,-1);
    tracep->declBit(c+642,"ce_n", false,-1);
    tracep->declBus(c+176,"din", false,-1, 3,0);
    tracep->declBus(c+292,"dout", false,-1, 3,0);
    tracep->declBit(c+643,"douten", false,-1);
    tracep->declBus(c+1234,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1235,"WRITE", false,-1, 0,0);
    tracep->declBus(c+156,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+650,"state", false,-1);
    tracep->declBit(c+298,"nstate", false,-1);
    tracep->declBus(c+651,"counter", false,-1, 7,0);
    tracep->declBus(c+652,"saddr", false,-1, 23,0);
    tracep->declBus(c+1239,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+117,"auto_in_psel", false,-1);
    tracep->declBit(c+1144,"auto_in_penable", false,-1);
    tracep->declBit(c+113,"auto_in_pwrite", false,-1);
    tracep->declBus(c+111,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1176,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+633,"auto_in_pready", false,-1);
    tracep->declBit(c+1177,"auto_in_pslverr", false,-1);
    tracep->declBus(c+634,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1143,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+624,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+625,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+626,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+627,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+628,"sdram_bundle_we", false,-1);
    tracep->declBus(c+629,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+630,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+631,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+632,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+111,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+117,"in_psel", false,-1);
    tracep->declBit(c+1144,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+633,"in_pready", false,-1);
    tracep->declBus(c+634,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1177,"in_pslverr", false,-1);
    tracep->declBit(c+1143,"sdram_clk", false,-1);
    tracep->declBit(c+624,"sdram_cke", false,-1);
    tracep->declBit(c+625,"sdram_cs", false,-1);
    tracep->declBit(c+626,"sdram_ras", false,-1);
    tracep->declBit(c+627,"sdram_cas", false,-1);
    tracep->declBit(c+628,"sdram_we", false,-1);
    tracep->declBus(c+629,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+630,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+631,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+632,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+653,"sdram_dout_en", false,-1);
    tracep->declBus(c+654,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+588,"state", false,-1, 1,0);
    tracep->declBit(c+655,"req_accept", false,-1);
    tracep->declBit(c+157,"is_read", false,-1);
    tracep->declBit(c+158,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1117,"clk_i", false,-1);
    tracep->declBit(c+1118,"rst_i", false,-1);
    tracep->declBus(c+159,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+157,"inport_rd_i", false,-1);
    tracep->declBus(c+1191,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+111,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+114,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+632,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+655,"inport_accept_o", false,-1);
    tracep->declBit(c+633,"inport_ack_o", false,-1);
    tracep->declBit(c+1177,"inport_error_o", false,-1);
    tracep->declBus(c+634,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1143,"sdram_clk_o", false,-1);
    tracep->declBit(c+624,"sdram_cke_o", false,-1);
    tracep->declBit(c+625,"sdram_cs_o", false,-1);
    tracep->declBit(c+626,"sdram_ras_o", false,-1);
    tracep->declBit(c+627,"sdram_cas_o", false,-1);
    tracep->declBit(c+628,"sdram_we_o", false,-1);
    tracep->declBus(c+631,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+629,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+630,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+654,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+653,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1240,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1241,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1242,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1209,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1209,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1209,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1217,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1243,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1244,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1245,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1246,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1217,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1247,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1248,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1249,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1250,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1251,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1252,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1227,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1196,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1253,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1217,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1196,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1227,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1252,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1248,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1250,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1249,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1251,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1247,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1254,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1255,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1256,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1256,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1224,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1256,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1209,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1209,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1233,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+111,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+159,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+157,"ram_rd_w", false,-1);
    tracep->declBit(c+655,"ram_accept_w", false,-1);
    tracep->declBus(c+114,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+634,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+633,"ram_ack_w", false,-1);
    tracep->declBit(c+160,"ram_req_w", false,-1);
    tracep->declBus(c+656,"command_q", false,-1, 3,0);
    tracep->declBus(c+629,"addr_q", false,-1, 12,0);
    tracep->declBus(c+654,"data_q", false,-1, 15,0);
    tracep->declBit(c+657,"data_rd_en_q", false,-1);
    tracep->declBus(c+631,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+624,"cke_q", false,-1);
    tracep->declBus(c+630,"bank_q", false,-1, 1,0);
    tracep->declBus(c+658,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+659,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+632,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+660,"refresh_q", false,-1);
    tracep->declBus(c+661,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+662+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+666,"state_q", false,-1, 3,0);
    tracep->declBus(c+299,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+300,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+667,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+668,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+161,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+162,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+163,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1217,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+669,"delay_q", false,-1, 3,0);
    tracep->declBus(c+301,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1257,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+670,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+671,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+672,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+673,"idx", false,-1, 31,0);
    tracep->declBus(c+674,"rd_q", false,-1, 3,0);
    tracep->declBit(c+633,"ack_q", false,-1);
    tracep->declArray(c+675,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+127,"auto_in_psel", false,-1);
    tracep->declBit(c+128,"auto_in_penable", false,-1);
    tracep->declBit(c+113,"auto_in_pwrite", false,-1);
    tracep->declBus(c+119,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1176,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+635,"auto_in_pready", false,-1);
    tracep->declBit(c+1177,"auto_in_pslverr", false,-1);
    tracep->declBus(c+636,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+622,"spi_bundle_sck", false,-1);
    tracep->declBus(c+623,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1139,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1140,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1258,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1259,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1223,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+164,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+127,"in_psel", false,-1);
    tracep->declBit(c+128,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+635,"in_pready", false,-1);
    tracep->declBus(c+636,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1177,"in_pslverr", false,-1);
    tracep->declBit(c+622,"spi_sck", false,-1);
    tracep->declBus(c+623,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1139,"spi_mosi", false,-1);
    tracep->declBit(c+1140,"spi_miso", false,-1);
    tracep->declBit(c+678,"spi_irq_out", false,-1);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1211,"Tp", false,-1, 31,0);
    tracep->declBit(c+1117,"wb_clk_i", false,-1);
    tracep->declBit(c+1118,"wb_rst_i", false,-1);
    tracep->declBus(c+165,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+114,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+636,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+115,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+113,"wb_we_i", false,-1);
    tracep->declBit(c+127,"wb_stb_i", false,-1);
    tracep->declBit(c+128,"wb_cyc_i", false,-1);
    tracep->declBit(c+635,"wb_ack_o", false,-1);
    tracep->declBit(c+1177,"wb_err_o", false,-1);
    tracep->declBit(c+678,"wb_int_o", false,-1);
    tracep->declBus(c+623,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+622,"sclk_pad_o", false,-1);
    tracep->declBit(c+1139,"mosi_pad_o", false,-1);
    tracep->declBit(c+1140,"miso_pad_i", false,-1);
    tracep->declBus(c+679,"divider", false,-1, 15,0);
    tracep->declBus(c+680,"ctrl", false,-1, 13,0);
    tracep->declBus(c+681,"ss", false,-1, 7,0);
    tracep->declBus(c+302,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+682,"rx", false,-1, 127,0);
    tracep->declBit(c+686,"rx_negedge", false,-1);
    tracep->declBit(c+687,"tx_negedge", false,-1);
    tracep->declBus(c+688,"char_len", false,-1, 6,0);
    tracep->declBit(c+689,"go", false,-1);
    tracep->declBit(c+690,"lsb", false,-1);
    tracep->declBit(c+691,"ie", false,-1);
    tracep->declBit(c+692,"ass", false,-1);
    tracep->declBit(c+166,"spi_divider_sel", false,-1);
    tracep->declBit(c+167,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+168,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+169,"spi_ss_sel", false,-1);
    tracep->declBit(c+693,"tip", false,-1);
    tracep->declBit(c+694,"pos_edge", false,-1);
    tracep->declBit(c+695,"neg_edge", false,-1);
    tracep->declBit(c+696,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1211,"Tp", false,-1, 31,0);
    tracep->declBit(c+1117,"clk_in", false,-1);
    tracep->declBit(c+1118,"rst", false,-1);
    tracep->declBit(c+693,"enable", false,-1);
    tracep->declBit(c+689,"go", false,-1);
    tracep->declBit(c+696,"last_clk", false,-1);
    tracep->declBus(c+679,"divider", false,-1, 15,0);
    tracep->declBit(c+622,"clk_out", false,-1);
    tracep->declBit(c+694,"pos_edge", false,-1);
    tracep->declBit(c+695,"neg_edge", false,-1);
    tracep->declBus(c+697,"cnt", false,-1, 15,0);
    tracep->declBit(c+698,"cnt_zero", false,-1);
    tracep->declBit(c+699,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1211,"Tp", false,-1, 31,0);
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1118,"rst", false,-1);
    tracep->declBus(c+170,"latch", false,-1, 3,0);
    tracep->declBus(c+115,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+688,"len", false,-1, 6,0);
    tracep->declBit(c+690,"lsb", false,-1);
    tracep->declBit(c+689,"go", false,-1);
    tracep->declBit(c+694,"pos_edge", false,-1);
    tracep->declBit(c+695,"neg_edge", false,-1);
    tracep->declBit(c+686,"rx_negedge", false,-1);
    tracep->declBit(c+687,"tx_negedge", false,-1);
    tracep->declBit(c+693,"tip", false,-1);
    tracep->declBit(c+696,"last", false,-1);
    tracep->declBus(c+114,"p_in", false,-1, 31,0);
    tracep->declArray(c+682,"p_out", false,-1, 127,0);
    tracep->declBit(c+622,"s_clk", false,-1);
    tracep->declBit(c+1140,"s_in", false,-1);
    tracep->declBit(c+1139,"s_out", false,-1);
    tracep->declBus(c+700,"cnt", false,-1, 7,0);
    tracep->declArray(c+682,"data", false,-1, 127,0);
    tracep->declBus(c+701,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+702,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+703,"rx_clk", false,-1);
    tracep->declBit(c+704,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+124,"auto_in_psel", false,-1);
    tracep->declBit(c+125,"auto_in_penable", false,-1);
    tracep->declBit(c+113,"auto_in_pwrite", false,-1);
    tracep->declBus(c+121,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1176,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+126,"auto_in_pready", false,-1);
    tracep->declBit(c+1177,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1150,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1137,"uart_rx", false,-1);
    tracep->declBit(c+1138,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+124,"in_psel", false,-1);
    tracep->declBit(c+125,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pready", false,-1);
    tracep->declBit(c+1177,"in_pslverr", false,-1);
    tracep->declBus(c+143,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+1150,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1137,"uart_rx", false,-1);
    tracep->declBit(c+1138,"uart_tx", false,-1);
    tracep->declBit(c+705,"rtsn", false,-1);
    tracep->declBit(c+1177,"ctsn", false,-1);
    tracep->declBit(c+706,"dtr_pad_o", false,-1);
    tracep->declBit(c+1177,"dsr_pad_i", false,-1);
    tracep->declBit(c+1177,"ri_pad_i", false,-1);
    tracep->declBit(c+1177,"dcd_pad_i", false,-1);
    tracep->declBit(c+707,"interrupt", false,-1);
    tracep->declBit(c+171,"reg_we", false,-1);
    tracep->declBit(c+172,"reg_re", false,-1);
    tracep->declBus(c+173,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+174,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+589,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+303,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+708,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1118,"wb_rst_i", false,-1);
    tracep->declBus(c+173,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+175,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+303,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+171,"wb_we_i", false,-1);
    tracep->declBit(c+172,"wb_re_i", false,-1);
    tracep->declBit(c+1138,"stx_pad_o", false,-1);
    tracep->declBit(c+1137,"srx_pad_i", false,-1);
    tracep->declBus(c+1254,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+708,"rts_pad_o", false,-1);
    tracep->declBit(c+706,"dtr_pad_o", false,-1);
    tracep->declBit(c+707,"int_o", false,-1);
    tracep->declBit(c+709,"enable", false,-1);
    tracep->declBit(c+710,"srx_pad", false,-1);
    tracep->declBus(c+711,"ier", false,-1, 3,0);
    tracep->declBus(c+712,"iir", false,-1, 3,0);
    tracep->declBus(c+713,"fcr", false,-1, 1,0);
    tracep->declBus(c+714,"mcr", false,-1, 4,0);
    tracep->declBus(c+715,"lcr", false,-1, 7,0);
    tracep->declBus(c+716,"msr", false,-1, 7,0);
    tracep->declBus(c+717,"dl", false,-1, 15,0);
    tracep->declBus(c+718,"scratch", false,-1, 7,0);
    tracep->declBit(c+719,"start_dlc", false,-1);
    tracep->declBit(c+720,"lsr_mask_d", false,-1);
    tracep->declBit(c+721,"msi_reset", false,-1);
    tracep->declBus(c+722,"dlc", false,-1, 15,0);
    tracep->declBus(c+723,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+724,"rx_reset", false,-1);
    tracep->declBit(c+725,"tx_reset", false,-1);
    tracep->declBit(c+726,"dlab", false,-1);
    tracep->declBit(c+1193,"cts_pad_i", false,-1);
    tracep->declBit(c+1177,"dsr_pad_i", false,-1);
    tracep->declBit(c+1177,"ri_pad_i", false,-1);
    tracep->declBit(c+1177,"dcd_pad_i", false,-1);
    tracep->declBit(c+727,"loopback", false,-1);
    tracep->declBit(c+1177,"cts", false,-1);
    tracep->declBit(c+1193,"dsr", false,-1);
    tracep->declBit(c+1193,"ri", false,-1);
    tracep->declBit(c+1193,"dcd", false,-1);
    tracep->declBit(c+728,"cts_c", false,-1);
    tracep->declBit(c+729,"dsr_c", false,-1);
    tracep->declBit(c+730,"ri_c", false,-1);
    tracep->declBit(c+731,"dcd_c", false,-1);
    tracep->declBus(c+732,"lsr", false,-1, 7,0);
    tracep->declBit(c+733,"lsr0", false,-1);
    tracep->declBit(c+734,"lsr1", false,-1);
    tracep->declBit(c+735,"lsr2", false,-1);
    tracep->declBit(c+736,"lsr3", false,-1);
    tracep->declBit(c+737,"lsr4", false,-1);
    tracep->declBit(c+738,"lsr5", false,-1);
    tracep->declBit(c+739,"lsr6", false,-1);
    tracep->declBit(c+740,"lsr7", false,-1);
    tracep->declBit(c+741,"lsr0r", false,-1);
    tracep->declBit(c+742,"lsr1r", false,-1);
    tracep->declBit(c+743,"lsr2r", false,-1);
    tracep->declBit(c+744,"lsr3r", false,-1);
    tracep->declBit(c+745,"lsr4r", false,-1);
    tracep->declBit(c+746,"lsr5r", false,-1);
    tracep->declBit(c+747,"lsr6r", false,-1);
    tracep->declBit(c+748,"lsr7r", false,-1);
    tracep->declBit(c+304,"lsr_mask", false,-1);
    tracep->declBit(c+749,"rls_int", false,-1);
    tracep->declBit(c+750,"rda_int", false,-1);
    tracep->declBit(c+751,"ti_int", false,-1);
    tracep->declBit(c+752,"thre_int", false,-1);
    tracep->declBit(c+753,"ms_int", false,-1);
    tracep->declBit(c+754,"tf_push", false,-1);
    tracep->declBit(c+755,"rf_pop", false,-1);
    tracep->declBus(c+1170,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+756,"rf_error_bit", false,-1);
    tracep->declBit(c+734,"rf_overrun", false,-1);
    tracep->declBit(c+757,"rf_push_pulse", false,-1);
    tracep->declBus(c+758,"rf_count", false,-1, 4,0);
    tracep->declBus(c+759,"tf_count", false,-1, 4,0);
    tracep->declBus(c+760,"tstate", false,-1, 2,0);
    tracep->declBus(c+761,"rstate", false,-1, 3,0);
    tracep->declBus(c+762,"counter_t", false,-1, 9,0);
    tracep->declBit(c+763,"thre_set_en", false,-1);
    tracep->declBus(c+764,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+765,"block_value", false,-1, 7,0);
    tracep->declBit(c+766,"serial_out", false,-1);
    tracep->declBit(c+767,"serial_in", false,-1);
    tracep->declBit(c+305,"lsr_mask_condition", false,-1);
    tracep->declBit(c+306,"iir_read", false,-1);
    tracep->declBit(c+307,"msr_read", false,-1);
    tracep->declBit(c+308,"fifo_read", false,-1);
    tracep->declBit(c+309,"fifo_write", false,-1);
    tracep->declBus(c+768,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+769,"lsr0_d", false,-1);
    tracep->declBit(c+770,"lsr1_d", false,-1);
    tracep->declBit(c+771,"lsr2_d", false,-1);
    tracep->declBit(c+772,"lsr3_d", false,-1);
    tracep->declBit(c+773,"lsr4_d", false,-1);
    tracep->declBit(c+774,"lsr5_d", false,-1);
    tracep->declBit(c+775,"lsr6_d", false,-1);
    tracep->declBit(c+776,"lsr7_d", false,-1);
    tracep->declBit(c+777,"rls_int_d", false,-1);
    tracep->declBit(c+778,"thre_int_d", false,-1);
    tracep->declBit(c+779,"ms_int_d", false,-1);
    tracep->declBit(c+780,"ti_int_d", false,-1);
    tracep->declBit(c+781,"rda_int_d", false,-1);
    tracep->declBit(c+782,"rls_int_rise", false,-1);
    tracep->declBit(c+783,"thre_int_rise", false,-1);
    tracep->declBit(c+784,"ms_int_rise", false,-1);
    tracep->declBit(c+785,"ti_int_rise", false,-1);
    tracep->declBit(c+786,"rda_int_rise", false,-1);
    tracep->declBit(c+787,"rls_int_pnd", false,-1);
    tracep->declBit(c+788,"rda_int_pnd", false,-1);
    tracep->declBit(c+789,"thre_int_pnd", false,-1);
    tracep->declBit(c+790,"ms_int_pnd", false,-1);
    tracep->declBit(c+791,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1211,"Tp", false,-1, 31,0);
    tracep->declBus(c+1211,"width", false,-1, 31,0);
    tracep->declBus(c+1235,"init_value", false,-1, 0,0);
    tracep->declBit(c+1118,"rst_i", false,-1);
    tracep->declBit(c+1117,"clk_i", false,-1);
    tracep->declBit(c+1177,"stage1_rst_i", false,-1);
    tracep->declBit(c+1193,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1137,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+710,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+792,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1118,"wb_rst_i", false,-1);
    tracep->declBus(c+715,"lcr", false,-1, 7,0);
    tracep->declBit(c+755,"rf_pop", false,-1);
    tracep->declBit(c+767,"srx_pad_i", false,-1);
    tracep->declBit(c+709,"enable", false,-1);
    tracep->declBit(c+724,"rx_reset", false,-1);
    tracep->declBit(c+304,"lsr_mask", false,-1);
    tracep->declBus(c+762,"counter_t", false,-1, 9,0);
    tracep->declBus(c+758,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1170,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+734,"rf_overrun", false,-1);
    tracep->declBit(c+756,"rf_error_bit", false,-1);
    tracep->declBus(c+761,"rstate", false,-1, 3,0);
    tracep->declBit(c+757,"rf_push_pulse", false,-1);
    tracep->declBus(c+793,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+794,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+795,"rshift", false,-1, 7,0);
    tracep->declBit(c+796,"rparity", false,-1);
    tracep->declBit(c+797,"rparity_error", false,-1);
    tracep->declBit(c+798,"rframing_error", false,-1);
    tracep->declBit(c+799,"rbit_in", false,-1);
    tracep->declBit(c+800,"rparity_xor", false,-1);
    tracep->declBus(c+801,"counter_b", false,-1, 7,0);
    tracep->declBit(c+802,"rf_push_q", false,-1);
    tracep->declBus(c+803,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+804,"rf_push", false,-1);
    tracep->declBit(c+805,"break_error", false,-1);
    tracep->declBit(c+806,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+807,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+808,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+809,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1196,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1227,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1252,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1248,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1250,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1249,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1251,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1247,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1254,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1255,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1260,"sr_push", false,-1, 3,0);
    tracep->declBus(c+810,"toc_value", false,-1, 9,0);
    tracep->declBus(c+811,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1261,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1224,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1217,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1230,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1118,"wb_rst_i", false,-1);
    tracep->declBit(c+757,"push", false,-1);
    tracep->declBit(c+755,"pop", false,-1);
    tracep->declBus(c+803,"data_in", false,-1, 10,0);
    tracep->declBit(c+724,"fifo_reset", false,-1);
    tracep->declBit(c+304,"reset_status", false,-1);
    tracep->declBus(c+1170,"data_out", false,-1, 10,0);
    tracep->declBit(c+734,"overrun", false,-1);
    tracep->declBus(c+758,"count", false,-1, 4,0);
    tracep->declBit(c+756,"error_bit", false,-1);
    tracep->declBus(c+1171,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+812+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+828,"top", false,-1, 3,0);
    tracep->declBus(c+829,"bottom", false,-1, 3,0);
    tracep->declBus(c+830,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+831,"word0", false,-1, 2,0);
    tracep->declBus(c+832,"word1", false,-1, 2,0);
    tracep->declBus(c+833,"word2", false,-1, 2,0);
    tracep->declBus(c+834,"word3", false,-1, 2,0);
    tracep->declBus(c+835,"word4", false,-1, 2,0);
    tracep->declBus(c+836,"word5", false,-1, 2,0);
    tracep->declBus(c+837,"word6", false,-1, 2,0);
    tracep->declBus(c+838,"word7", false,-1, 2,0);
    tracep->declBus(c+839,"word8", false,-1, 2,0);
    tracep->declBus(c+840,"word9", false,-1, 2,0);
    tracep->declBus(c+841,"word10", false,-1, 2,0);
    tracep->declBus(c+842,"word11", false,-1, 2,0);
    tracep->declBus(c+843,"word12", false,-1, 2,0);
    tracep->declBus(c+844,"word13", false,-1, 2,0);
    tracep->declBus(c+845,"word14", false,-1, 2,0);
    tracep->declBus(c+846,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1217,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1223,"data_width", false,-1, 31,0);
    tracep->declBus(c+1224,"depth", false,-1, 31,0);
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+757,"we", false,-1);
    tracep->declBus(c+828,"a", false,-1, 3,0);
    tracep->declBus(c+829,"dpra", false,-1, 3,0);
    tracep->declBus(c+847,"di", false,-1, 7,0);
    tracep->declBus(c+1171,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+590+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1118,"wb_rst_i", false,-1);
    tracep->declBus(c+715,"lcr", false,-1, 7,0);
    tracep->declBit(c+754,"tf_push", false,-1);
    tracep->declBus(c+175,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+709,"enable", false,-1);
    tracep->declBit(c+725,"tx_reset", false,-1);
    tracep->declBit(c+304,"lsr_mask", false,-1);
    tracep->declBit(c+766,"stx_pad_o", false,-1);
    tracep->declBus(c+760,"tstate", false,-1, 2,0);
    tracep->declBus(c+759,"tf_count", false,-1, 4,0);
    tracep->declBus(c+848,"counter", false,-1, 4,0);
    tracep->declBus(c+849,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+850,"shift_out", false,-1, 6,0);
    tracep->declBit(c+851,"stx_o_tmp", false,-1);
    tracep->declBit(c+852,"parity_xor", false,-1);
    tracep->declBit(c+853,"tf_pop", false,-1);
    tracep->declBit(c+854,"bit_out", false,-1);
    tracep->declBus(c+175,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1172,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+855,"tf_overrun", false,-1);
    tracep->declBus(c+1197,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1176,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1262,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1263,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1236,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1264,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1223,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1224,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1217,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1230,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+1118,"wb_rst_i", false,-1);
    tracep->declBit(c+754,"push", false,-1);
    tracep->declBit(c+853,"pop", false,-1);
    tracep->declBus(c+175,"data_in", false,-1, 7,0);
    tracep->declBit(c+725,"fifo_reset", false,-1);
    tracep->declBit(c+304,"reset_status", false,-1);
    tracep->declBus(c+1172,"data_out", false,-1, 7,0);
    tracep->declBit(c+855,"overrun", false,-1);
    tracep->declBus(c+759,"count", false,-1, 4,0);
    tracep->declBus(c+856,"top", false,-1, 3,0);
    tracep->declBus(c+857,"bottom", false,-1, 3,0);
    tracep->declBus(c+858,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1217,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1223,"data_width", false,-1, 31,0);
    tracep->declBus(c+1224,"depth", false,-1, 31,0);
    tracep->declBit(c+1117,"clk", false,-1);
    tracep->declBit(c+754,"we", false,-1);
    tracep->declBus(c+856,"a", false,-1, 3,0);
    tracep->declBus(c+857,"dpra", false,-1, 3,0);
    tracep->declBus(c+175,"di", false,-1, 7,0);
    tracep->declBus(c+1172,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+606+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBit(c+118,"auto_in_psel", false,-1);
    tracep->declBit(c+1145,"auto_in_penable", false,-1);
    tracep->declBit(c+113,"auto_in_pwrite", false,-1);
    tracep->declBus(c+119,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1176,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+114,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1178,"auto_in_pready", false,-1);
    tracep->declBit(c+1179,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1180,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1131,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1132,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1133,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1134,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1135,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1136,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1117,"clock", false,-1);
    tracep->declBit(c+1118,"reset", false,-1);
    tracep->declBus(c+164,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+118,"in_psel", false,-1);
    tracep->declBit(c+1145,"in_penable", false,-1);
    tracep->declBus(c+1176,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+113,"in_pwrite", false,-1);
    tracep->declBus(c+114,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+115,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1178,"in_pready", false,-1);
    tracep->declBus(c+1180,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1179,"in_pslverr", false,-1);
    tracep->declBus(c+1131,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1132,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1133,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1134,"vga_hsync", false,-1);
    tracep->declBit(c+1135,"vga_vsync", false,-1);
    tracep->declBit(c+1136,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+622,"sck", false,-1);
    tracep->declBit(c+859,"ss", false,-1);
    tracep->declBit(c+1139,"mosi", false,-1);
    tracep->declBit(c+1193,"miso", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+622,"sck", false,-1);
    tracep->declBit(c+860,"ss", false,-1);
    tracep->declBit(c+1139,"mosi", false,-1);
    tracep->declBit(c+1140,"miso", false,-1);
    tracep->declBit(c+860,"reset", false,-1);
    tracep->declBus(c+938,"state", false,-1, 2,0);
    tracep->declBus(c+939,"counter", false,-1, 7,0);
    tracep->declBus(c+940,"cmd", false,-1, 7,0);
    tracep->declBus(c+941,"addr", false,-1, 23,0);
    tracep->declBus(c+942,"data", false,-1, 31,0);
    tracep->declBit(c+943,"ren", false,-1);
    tracep->declBus(c+1173,"rdata", false,-1, 31,0);
    tracep->declBus(c+1174,"raddr", false,-1, 31,0);
    tracep->declBus(c+1175,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+622,"clock", false,-1);
    tracep->declBit(c+943,"valid", false,-1);
    tracep->declBus(c+940,"cmd", false,-1, 7,0);
    tracep->declBus(c+1174,"addr", false,-1, 31,0);
    tracep->declBus(c+1173,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+1141,"sck", false,-1);
    tracep->declBit(c+1142,"ce_n", false,-1);
    tracep->declBus(c+176,"dio", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1143,"clk", false,-1);
    tracep->declBit(c+624,"cke", false,-1);
    tracep->declBit(c+625,"cs", false,-1);
    tracep->declBit(c+626,"ras", false,-1);
    tracep->declBit(c+627,"cas", false,-1);
    tracep->declBit(c+628,"we", false,-1);
    tracep->declBus(c+629,"a", false,-1, 12,0);
    tracep->declBus(c+630,"ba", false,-1, 1,0);
    tracep->declBus(c+631,"dqm", false,-1, 1,0);
    tracep->declBus(c+632,"dq", false,-1, 15,0);
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
    bufp->fullCData(oldp+28,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[0]),4);
    bufp->fullCData(oldp+29,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[1]),4);
    bufp->fullCData(oldp+30,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+31,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+32,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+33,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+34,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+35,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+36,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+37,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[3]),2);
    bufp->fullIData(oldp+38,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                           : 0U) | 
                                         ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                           : 0U)))),32);
    bufp->fullBit(oldp+39,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+40,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+41,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+42,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+43,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+44,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+45,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+46,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+47,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+48,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+49,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+50,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+51,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+52,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+53,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+54,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+55,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+56,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+57,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+58,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+60,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+62,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+63,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+65,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+66,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+69,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+70,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+71,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+72,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+73,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+74,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+75,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+76,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+77,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+78,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+79,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+80,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+81,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+82,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+83,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+84,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+85,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+86,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+87,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+89,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+91,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+93,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+94,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+99,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+112,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+115,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+116,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+117,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+118,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+119,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+120,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+121,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+122,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+123,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+126,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_psel));
    bufp->fullBit(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_penable));
    bufp->fullBit(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+133,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+134,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+135,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+136,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+137,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+138,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+141,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+143,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+149,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+151,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+152,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+153,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+154,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+155,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+156,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+158,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+161,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+162,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+163,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+164,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullCData(oldp+165,((0x1fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),5);
    bufp->fullBit(oldp+166,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullBit(oldp+167,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+168,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
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
    bufp->fullBit(oldp+169,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+173,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+174,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+175,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullCData(oldp+176,((((((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out0) 
                                         & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten))) 
                                  | (0xcU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out1) 
                                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten)))) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0))),4);
    bufp->fullBit(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+178,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+179,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+181,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+183,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+184,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+186,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+190,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+222,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+226,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+230,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+232,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+233,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+234,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+235,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+236,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+237,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+238,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+239,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+240,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+241,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+242,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+243,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+244,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+245,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+246,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+247,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+248,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+249,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+250,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+251,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+252,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+253,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+254,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+255,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+256,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+257,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+258,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+259,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+260,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+261,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+262,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+263,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+264,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+265,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+266,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+267,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+268,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+269,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+270,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+271,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+272,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+273,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+274,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+276,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+277,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+278,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                              [1U]),2);
    bufp->fullBit(oldp+279,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                   >> 1U))));
    bufp->fullIData(oldp+280,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+281,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+282,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+284,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data))),32);
    bufp->fullIData(oldp+285,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data))),32);
    bufp->fullCData(oldp+286,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data),8);
    bufp->fullSData(oldp+287,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data),16);
    bufp->fullIData(oldp+288,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+289,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+291,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+292,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+293,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+294,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+296,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+297,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+307,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+308,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+309,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullBit(oldp+310,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullIData(oldp+311,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+312,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+313,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+314,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+316,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+317,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+321,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+322,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+324,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+325,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+326,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+327,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+328,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+329,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+345,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+350,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+352,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+353,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+354,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+355,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+356,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+358,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+360,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+361,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullQData(oldp+362,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+364,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+365,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+366,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+368,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+369,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+370,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+371,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+372,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+373,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+374,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+375,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+377,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+378,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+379,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+382,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+383,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+384,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+385,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+386,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+387,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+391,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+401,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+405,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+430,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+433,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+440,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+442,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+443,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+444,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+448,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+452,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+454,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+455,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+456,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+457,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+460,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+461,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+462,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+464,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+468,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+472,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+476,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+480,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+484,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+486,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+488,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+492,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+494,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+496,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+498,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+500,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+501,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+502,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+503,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+504,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+506,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+508,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+510,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+512,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+514,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+516,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+518,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+520,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+522,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+524,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+525,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+526,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+528,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+529,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+530,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+532,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+533,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+534,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+536,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+538,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+540,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+541,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+542,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+544,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+545,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+546,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+548,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+549,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+550,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+552,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+554,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+556,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+558,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+560,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+562,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+564,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+566,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullCData(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready),2);
    bufp->fullBit(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+570,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+572,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready) 
                                   >> 1U))));
    bufp->fullCData(oldp+573,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state),2);
    bufp->fullBit(oldp+574,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+575,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+577,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+582,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullCData(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+590,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+594,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+598,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+602,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+606,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+613,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+614,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+615,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+617,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+618,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+621,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullBit(oldp+622,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+623,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+624,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+625,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+626,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+627,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+628,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+629,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+630,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullSData(oldp+632,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                  ? 0U : 0xffffU) & 
                                ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                    ? 0U : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                      ? 0U : 0xffffU)) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                     ? 0U : 0xffffU))) 
                               & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                   ? 0U : 0xffffU))),16);
    bufp->fullBit(oldp+633,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullIData(oldp+634,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_pready));
    bufp->fullIData(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+637,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+639,((0xfU & ((8U > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
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
    bufp->fullBit(oldp+640,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+641,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+642,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+643,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+644,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+647,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+649,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+651,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+652,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullBit(oldp+653,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+655,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+656,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+658,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullBit(oldp+660,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+666,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullCData(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+670,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+673,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+674,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+675,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullSData(oldp+679,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+680,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+681,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+682,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+686,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+687,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+688,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+689,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+690,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+691,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+692,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+693,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+694,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+695,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+696,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+697,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+698,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+699,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+701,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+702,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+704,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+705,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+706,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+707,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+708,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+709,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+715,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+716,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+717,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+718,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+719,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+720,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+721,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+722,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+723,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+724,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+725,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+726,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+727,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+728,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+729,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+730,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+731,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+732,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+733,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+734,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+735,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+736,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+737,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+738,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+739,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+740,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+741,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+742,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+743,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+744,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+746,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+747,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+748,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+749,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+750,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+752,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+753,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+754,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+756,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+758,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+759,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+760,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+761,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+762,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+763,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+764,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+765,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+766,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+767,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+768,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+769,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+770,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+771,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+772,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+773,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+774,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+775,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+776,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+777,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+778,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+779,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+780,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+781,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+782,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+783,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+784,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+785,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+786,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+788,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+789,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+790,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+793,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+795,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+796,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+797,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+798,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+799,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+800,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+801,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+803,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+804,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+805,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+806,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+807,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+808,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+809,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+810,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+811,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+812,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+814,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+815,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+816,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+818,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+820,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+821,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+822,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+823,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+824,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+827,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+828,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+829,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+830,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+833,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+834,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+836,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+837,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+839,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+840,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+841,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+843,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+847,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+848,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+850,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+858,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+859,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_ss) 
                                   >> 7U))));
    bufp->fullBit(oldp+860,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullIData(oldp+861,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+862,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+864,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+866,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+867,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+868,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+869,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+870,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+874,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+875,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+877,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+894,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+900,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+901,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+920,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+921,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+922,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+923,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+928,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+929,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+930,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+931,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+932,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+933,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+936,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+937,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+938,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+939,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+940,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+941,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+942,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+943,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                             & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+944,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+945,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__arsize_out_reg),3);
    bufp->fullBit(oldp+946,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+947,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+948,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+949,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullBit(oldp+950,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullBit(oldp+951,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+952,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+953,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+954,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+955,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+956,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+957,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+958,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+959,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                      | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+960,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+961,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+962,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+963,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+964,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+965,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+966,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+967,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+968,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+969,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+972,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+973,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+975,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+976,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+977,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+978,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+979,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullCData(oldp+980,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[0]),3);
    bufp->fullCData(oldp+981,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[1]),3);
    bufp->fullCData(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[0]),3);
    bufp->fullCData(oldp+983,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[1]),3);
    bufp->fullCData(oldp+984,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+985,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+987,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+988,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+989,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+990,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+991,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+992,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+993,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+994,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+995,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+996,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+997,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+998,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+999,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+1000,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+1001,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+1002,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+1003,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+1004,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+1005,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 | ((0x17U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+1006,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1007,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))));
    bufp->fullCData(oldp+1008,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),3);
    bufp->fullSData(oldp+1009,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                >> 0x14U)),12);
    bufp->fullCData(oldp+1010,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+1011,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1012,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+1013,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+1014,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    >> 1U))));
    bufp->fullCData(oldp+1015,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : 2U))),3);
    bufp->fullCData(oldp+1016,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullWData(oldp+1017,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1020,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1022,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1024,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1025,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1026,((0x11830U | ((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullCData(oldp+1027,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[0]),6);
    bufp->fullCData(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[1]),6);
    bufp->fullCData(oldp+1029,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[2]),6);
    bufp->fullCData(oldp+1030,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[3]),6);
    bufp->fullCData(oldp+1031,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[0]),4);
    bufp->fullCData(oldp+1032,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[1]),4);
    bufp->fullCData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[2]),4);
    bufp->fullCData(oldp+1034,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[3]),4);
    bufp->fullIData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullCData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullIData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullCData(oldp+1038,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullIData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullCData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awsize_out_reg),3);
    bufp->fullCData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullIData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullCData(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1046,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1047,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1048,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1049,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullCData(oldp+1050,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullIData(oldp+1051,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1052,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1053,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1054,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1055,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1056,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1057,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1058,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1059,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1060,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1061,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
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
    bufp->fullBit(oldp+1062,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1063,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1064,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1065,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1066,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1067,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1068,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1069,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1070,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1071,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1072,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1073,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullCData(oldp+1074,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+1075,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+1076,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[0]),3);
    bufp->fullCData(oldp+1077,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[1]),3);
    bufp->fullIData(oldp+1078,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1079,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1080,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1081,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1082,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1083,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullCData(oldp+1084,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+1085,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+1086,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[0]),3);
    bufp->fullCData(oldp+1087,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[1]),3);
    bufp->fullIData(oldp+1088,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1089,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1090,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1091,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1092,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1093,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1094,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1095,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1096,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1097,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1098,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+1099,(((0x1fU >= (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                             ? (3U 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                             : 0U) 
                                           << 3U)) ? 
                                (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                       ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                       : 0U) << 3U))
                                 : 0U)),32);
    bufp->fullCData(oldp+1100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__wstrb),4);
    bufp->fullCData(oldp+1101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awsize),3);
    bufp->fullCData(oldp+1102,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                 ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : 0U)),2);
    bufp->fullCData(oldp+1103,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),2);
    bufp->fullBit(oldp+1104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__inuart));
    bufp->fullBit(oldp+1105,(((0xf000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0xfffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullCData(oldp+1106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size),2);
    bufp->fullCData(oldp+1107,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
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
    bufp->fullCData(oldp+1108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux),5);
    bufp->fullCData(oldp+1109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT____Vcellinp__type_mux__key),2);
    bufp->fullCData(oldp+1112,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__lut_out),4);
    bufp->fullBit(oldp+1115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+1116,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1117,(vlSelf->clock));
    bufp->fullBit(oldp+1118,(vlSelf->reset));
    bufp->fullSData(oldp+1119,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1120,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1121,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1122,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1123,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1124,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1125,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1126,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1127,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1128,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1129,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1130,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1131,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1132,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1133,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1134,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1135,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1136,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1137,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1138,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1139,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+1140,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullBit(oldp+1141,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck))));
    bufp->fullBit(oldp+1142,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n))));
    bufp->fullBit(oldp+1143,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullBit(oldp+1144,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1145,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1146,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1147,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1148,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1149,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1150,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullCData(oldp+1151,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                 ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                    << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))),2);
    bufp->fullBit(oldp+1152,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullCData(oldp+1153,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1154,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1155,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1156,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1157,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
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
    bufp->fullBit(oldp+1158,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1159,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1160,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1161,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullIData(oldp+1162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullBit(oldp+1164,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1165,(((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1166,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state)))));
    bufp->fullBit(oldp+1167,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                     & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready)) 
                                    >> 1U))));
    bufp->fullBit(oldp+1168,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1169,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1170,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullIData(oldp+1173,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1174,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1175,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullCData(oldp+1176,(1U),3);
    bufp->fullBit(oldp+1177,(0U));
    bufp->fullBit(oldp+1178,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1179,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1180,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1181,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1182,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1183,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1184,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pready));
    bufp->fullBit(oldp+1185,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullIData(oldp+1186,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_prdata),32);
    bufp->fullCData(oldp+1187,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1188,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullBit(oldp+1189,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1190,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1191,(0U),8);
    bufp->fullCData(oldp+1192,(1U),2);
    bufp->fullBit(oldp+1193,(1U));
    bufp->fullBit(oldp+1194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1195,(0U),32);
    bufp->fullCData(oldp+1196,(0U),4);
    bufp->fullCData(oldp+1197,(0U),3);
    bufp->fullCData(oldp+1198,(0U),2);
    bufp->fullBit(oldp+1199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1209,(2U),32);
    bufp->fullIData(oldp+1210,(2U),32);
    bufp->fullIData(oldp+1211,(1U),32);
    bufp->fullIData(oldp+1212,(0x20U),32);
    bufp->fullIData(oldp+1213,(0U),32);
    bufp->fullIData(oldp+1214,(0x21U),32);
    bufp->fullIData(oldp+1215,(2U),32);
    bufp->fullIData(oldp+1216,(0x20000000U),32);
    bufp->fullIData(oldp+1217,(4U),32);
    bufp->fullIData(oldp+1218,(0xcU),32);
    bufp->fullQData(oldp+1219,(0x3000c153418d0bULL),56);
    bufp->fullIData(oldp+1221,(0xeU),32);
    bufp->fullIData(oldp+1222,(4U),32);
    bufp->fullIData(oldp+1223,(8U),32);
    bufp->fullIData(oldp+1224,(0x10U),32);
    bufp->fullIData(oldp+1225,(3U),32);
    bufp->fullIData(oldp+1226,(0x23U),32);
    bufp->fullCData(oldp+1227,(1U),4);
    bufp->fullCData(oldp+1228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword),4);
    bufp->fullSData(oldp+1229,(0x223aU),15);
    bufp->fullIData(oldp+1230,(5U),32);
    bufp->fullIData(oldp+1231,(3U),32);
    bufp->fullCData(oldp+1232,(0xb5U),8);
    bufp->fullIData(oldp+1233,(6U),32);
    bufp->fullBit(oldp+1234,(0U));
    bufp->fullBit(oldp+1235,(1U));
    bufp->fullCData(oldp+1236,(4U),3);
    bufp->fullCData(oldp+1237,(0x1bU),8);
    bufp->fullCData(oldp+1238,(0xebU),8);
    bufp->fullCData(oldp+1239,(0x38U),8);
    bufp->fullIData(oldp+1240,(0x64U),32);
    bufp->fullIData(oldp+1241,(0x18U),32);
    bufp->fullIData(oldp+1242,(9U),32);
    bufp->fullIData(oldp+1243,(0xdU),32);
    bufp->fullIData(oldp+1244,(0x2000U),32);
    bufp->fullIData(oldp+1245,(0x2710U),32);
    bufp->fullIData(oldp+1246,(0x30cU),32);
    bufp->fullCData(oldp+1247,(7U),4);
    bufp->fullCData(oldp+1248,(3U),4);
    bufp->fullCData(oldp+1249,(5U),4);
    bufp->fullCData(oldp+1250,(4U),4);
    bufp->fullCData(oldp+1251,(6U),4);
    bufp->fullCData(oldp+1252,(2U),4);
    bufp->fullSData(oldp+1253,(0x21U),13);
    bufp->fullCData(oldp+1254,(8U),4);
    bufp->fullCData(oldp+1255,(9U),4);
    bufp->fullIData(oldp+1256,(0xaU),32);
    bufp->fullIData(oldp+1257,(0x11U),32);
    bufp->fullIData(oldp+1258,(0x30000000U),32);
    bufp->fullIData(oldp+1259,(0x3fffffffU),32);
    bufp->fullCData(oldp+1260,(0xaU),4);
    bufp->fullIData(oldp+1261,(0xbU),32);
    bufp->fullCData(oldp+1262,(2U),3);
    bufp->fullCData(oldp+1263,(3U),3);
    bufp->fullCData(oldp+1264,(5U),3);
}
