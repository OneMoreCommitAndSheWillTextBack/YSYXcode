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
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+1127,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1128,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1129,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1130,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1131,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1132,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1133,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1134,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1135,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1136,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1137,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1138,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1139,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1140,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1141,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1142,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1143,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1144,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1145,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1146,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+1127,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1128,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1129,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1130,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1131,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1132,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1133,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1134,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1135,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1136,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1137,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1138,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1139,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1140,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1141,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1142,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1143,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1144,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1145,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1146,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+625,"spi_sck", false,-1);
    tracep->declBus(c+626,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1147,"spi_mosi", false,-1);
    tracep->declBit(c+1148,"spi_miso", false,-1);
    tracep->declBit(c+1145,"uart_rx", false,-1);
    tracep->declBit(c+1146,"uart_tx", false,-1);
    tracep->declBit(c+1149,"psram_sck", false,-1);
    tracep->declBit(c+1150,"psram_ce_n", false,-1);
    tracep->declBus(c+179,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1151,"sdram_clk", false,-1);
    tracep->declBit(c+627,"sdram_cke", false,-1);
    tracep->declBit(c+628,"sdram_cs", false,-1);
    tracep->declBit(c+629,"sdram_ras", false,-1);
    tracep->declBit(c+630,"sdram_cas", false,-1);
    tracep->declBit(c+631,"sdram_we", false,-1);
    tracep->declBus(c+632,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+633,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+634,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+635,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1127,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1128,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1129,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1130,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1131,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1132,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1133,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1134,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1135,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1136,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1137,"ps2_clk", false,-1);
    tracep->declBit(c+1138,"ps2_data", false,-1);
    tracep->declBus(c+1139,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1140,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1141,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1142,"vga_hsync", false,-1);
    tracep->declBit(c+1143,"vga_vsync", false,-1);
    tracep->declBit(c+1144,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+114,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+115,"in_psel", false,-1);
    tracep->declBit(c+313,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+180,"in_pready", false,-1);
    tracep->declBus(c+181,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+119,"in_pslverr", false,-1);
    tracep->declBus(c+114,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+115,"out_psel", false,-1);
    tracep->declBit(c+313,"out_penable", false,-1);
    tracep->declBus(c+1187,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"out_pwrite", false,-1);
    tracep->declBus(c+117,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+180,"out_pready", false,-1);
    tracep->declBus(c+181,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+119,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+115,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+313,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+114,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1187,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+180,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+119,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+181,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+120,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+1152,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+114,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1187,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+636,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1188,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+637,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+121,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+1153,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+122,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1187,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1190,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1191,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+123,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+1154,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+124,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1187,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1192,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1193,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1194,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+125,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+1155,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+124,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1187,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+1195,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1196,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1197,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+126,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+1156,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+114,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1187,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1157,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1188,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+314,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+127,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+128,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+124,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1187,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+129,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1188,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1158,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+130,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+131,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+116,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+122,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1187,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+638,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1188,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+639,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+132,"sel_0", false,-1);
    tracep->declBit(c+133,"sel_1", false,-1);
    tracep->declBit(c+134,"sel_2", false,-1);
    tracep->declBit(c+135,"sel_3", false,-1);
    tracep->declBit(c+136,"sel_4", false,-1);
    tracep->declBit(c+137,"sel_5", false,-1);
    tracep->declBit(c+138,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+139,"auto_in_awready", false,-1);
    tracep->declBit(c+140,"auto_in_awvalid", false,-1);
    tracep->declBus(c+315,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+139,"auto_in_wready", false,-1);
    tracep->declBit(c+141,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+182,"auto_in_bready", false,-1);
    tracep->declBit(c+183,"auto_in_bvalid", false,-1);
    tracep->declBus(c+316,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+1159,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+142,"auto_in_arready", false,-1);
    tracep->declBit(c+143,"auto_in_arvalid", false,-1);
    tracep->declBus(c+317,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+950,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+184,"auto_in_rready", false,-1);
    tracep->declBit(c+185,"auto_in_rvalid", false,-1);
    tracep->declBus(c+318,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+186,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1159,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+115,"auto_out_psel", false,-1);
    tracep->declBit(c+313,"auto_out_penable", false,-1);
    tracep->declBit(c+116,"auto_out_pwrite", false,-1);
    tracep->declBus(c+114,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+117,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+180,"auto_out_pready", false,-1);
    tracep->declBit(c+119,"auto_out_pslverr", false,-1);
    tracep->declBus(c+181,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+313,"nodeOut_penable", false,-1);
    tracep->declBus(c+319,"state", false,-1, 1,0);
    tracep->declBit(c+142,"accept_read", false,-1);
    tracep->declBit(c+139,"accept_write", false,-1);
    tracep->declBit(c+320,"is_write_r", false,-1);
    tracep->declBit(c+116,"is_write", false,-1);
    tracep->declBus(c+318,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+316,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+321,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+322,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+323,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+324,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+144,"resp", false,-1, 1,0);
    tracep->declBus(c+325,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+1159,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+185,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+326,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+183,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+327,"auto_in_awready", false,-1);
    tracep->declBit(c+78,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1198,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1046,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1199,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1047,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1048,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+328,"auto_in_wready", false,-1);
    tracep->declBit(c+79,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1049,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1050,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1200,"auto_in_wlast", false,-1);
    tracep->declBit(c+1160,"auto_in_bready", false,-1);
    tracep->declBit(c+187,"auto_in_bvalid", false,-1);
    tracep->declBus(c+188,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+189,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+329,"auto_in_arready", false,-1);
    tracep->declBit(c+80,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1201,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1202,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+951,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1203,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+81,"auto_in_rready", false,-1);
    tracep->declBit(c+190,"auto_in_rvalid", false,-1);
    tracep->declBus(c+191,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+42,"auto_in_rlast", false,-1);
    tracep->declBit(c+192,"auto_out_awready", false,-1);
    tracep->declBit(c+82,"auto_out_awvalid", false,-1);
    tracep->declBus(c+315,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+330,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+193,"auto_out_wready", false,-1);
    tracep->declBit(c+83,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+84,"auto_out_wlast", false,-1);
    tracep->declBit(c+194,"auto_out_bready", false,-1);
    tracep->declBit(c+195,"auto_out_bvalid", false,-1);
    tracep->declBus(c+188,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+196,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+197,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+198,"auto_out_arready", false,-1);
    tracep->declBit(c+85,"auto_out_arvalid", false,-1);
    tracep->declBus(c+317,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+950,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+331,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+81,"auto_out_rready", false,-1);
    tracep->declBit(c+190,"auto_out_rvalid", false,-1);
    tracep->declBus(c+191,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+43,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+199,"auto_out_rlast", false,-1);
    tracep->declBit(c+83,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+332,"w_idle", false,-1);
    tracep->declBit(c+200,"in_awready", false,-1);
    tracep->declBit(c+333,"busy", false,-1);
    tracep->declBus(c+334,"r_addr", false,-1, 31,0);
    tracep->declBus(c+335,"r_len", false,-1, 7,0);
    tracep->declBus(c+336,"len", false,-1, 7,0);
    tracep->declBus(c+1052,"addr", false,-1, 31,0);
    tracep->declBit(c+337,"busy_1", false,-1);
    tracep->declBus(c+338,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+339,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+340,"len_1", false,-1, 7,0);
    tracep->declBus(c+1053,"addr_1", false,-1, 31,0);
    tracep->declBit(c+341,"wbeats_latched", false,-1);
    tracep->declBit(c+82,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+86,"wbeats_valid", false,-1);
    tracep->declBus(c+342,"w_counter", false,-1, 8,0);
    tracep->declBus(c+87,"w_todo", false,-1, 8,0);
    tracep->declBit(c+84,"w_last", false,-1);
    tracep->declBit(c+194,"nodeOut_bready", false,-1);
    tracep->declBus(c+343,"error_0", false,-1, 1,0);
    tracep->declBus(c+344,"error_1", false,-1, 1,0);
    tracep->declBus(c+345,"error_2", false,-1, 1,0);
    tracep->declBus(c+346,"error_3", false,-1, 1,0);
    tracep->declBus(c+347,"error_4", false,-1, 1,0);
    tracep->declBus(c+348,"error_5", false,-1, 1,0);
    tracep->declBus(c+349,"error_6", false,-1, 1,0);
    tracep->declBus(c+350,"error_7", false,-1, 1,0);
    tracep->declBus(c+351,"error_8", false,-1, 1,0);
    tracep->declBus(c+352,"error_9", false,-1, 1,0);
    tracep->declBus(c+353,"error_10", false,-1, 1,0);
    tracep->declBus(c+354,"error_11", false,-1, 1,0);
    tracep->declBus(c+355,"error_12", false,-1, 1,0);
    tracep->declBus(c+356,"error_13", false,-1, 1,0);
    tracep->declBus(c+357,"error_14", false,-1, 1,0);
    tracep->declBus(c+358,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+329,"io_enq_ready", false,-1);
    tracep->declBit(c+80,"io_enq_valid", false,-1);
    tracep->declBus(c+1201,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1051,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1202,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+951,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1203,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+201,"io_deq_ready", false,-1);
    tracep->declBit(c+85,"io_deq_valid", false,-1);
    tracep->declBus(c+317,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1054,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+359,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+950,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+360,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+361,"ram", false,-1, 48,0);
    tracep->declBit(c+363,"full", false,-1);
    tracep->declBit(c+85,"io_deq_valid_0", false,-1);
    tracep->declBit(c+202,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+327,"io_enq_ready", false,-1);
    tracep->declBit(c+78,"io_enq_valid", false,-1);
    tracep->declBus(c+1198,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1046,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1199,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1047,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1048,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+203,"io_deq_ready", false,-1);
    tracep->declBit(c+88,"io_deq_valid", false,-1);
    tracep->declBus(c+315,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1055,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+364,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1042,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1056,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+365,"ram", false,-1, 48,0);
    tracep->declBit(c+367,"full", false,-1);
    tracep->declBit(c+88,"io_deq_valid_0", false,-1);
    tracep->declBit(c+204,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+328,"io_enq_ready", false,-1);
    tracep->declBit(c+79,"io_enq_valid", false,-1);
    tracep->declBus(c+1049,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1050,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1200,"io_enq_bits_last", false,-1);
    tracep->declBit(c+205,"io_deq_ready", false,-1);
    tracep->declBit(c+89,"io_deq_valid", false,-1);
    tracep->declBus(c+1043,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1044,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+368,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+369,"ram", false,-1, 36,0);
    tracep->declBit(c+371,"full", false,-1);
    tracep->declBit(c+89,"io_deq_valid_0", false,-1);
    tracep->declBit(c+206,"do_enq", false,-1);
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
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+207,"auto_in_awready", false,-1);
    tracep->declBit(c+145,"auto_in_awvalid", false,-1);
    tracep->declBus(c+315,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1057,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1162,"auto_in_wready", false,-1);
    tracep->declBit(c+1163,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+208,"auto_in_bready", false,-1);
    tracep->declBit(c+372,"auto_in_bvalid", false,-1);
    tracep->declBus(c+373,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+374,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+209,"auto_in_arready", false,-1);
    tracep->declBit(c+1164,"auto_in_arvalid", false,-1);
    tracep->declBus(c+317,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1058,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+210,"auto_in_rready", false,-1);
    tracep->declBit(c+375,"auto_in_rvalid", false,-1);
    tracep->declBus(c+376,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+377,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+378,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+209,"nodeIn_arready", false,-1);
    tracep->declBit(c+207,"nodeIn_awready", false,-1);
    tracep->declBit(c+1059,"w_sel0", false,-1);
    tracep->declBit(c+372,"w_full", false,-1);
    tracep->declBus(c+373,"w_id", false,-1, 3,0);
    tracep->declBit(c+379,"r_sel1", false,-1);
    tracep->declBit(c+380,"w_sel1", false,-1);
    tracep->declBit(c+375,"r_full", false,-1);
    tracep->declBus(c+376,"r_id", false,-1, 3,0);
    tracep->declBit(c+211,"ren", false,-1);
    tracep->declBit(c+381,"rdata_REG", false,-1);
    tracep->declBus(c+382,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+383,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+384,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+385,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1060,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+211,"R0_en", false,-1);
    tracep->declBit(c+1125,"R0_clk", false,-1);
    tracep->declBus(c+386,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1061,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+212,"W0_en", false,-1);
    tracep->declBit(c+1125,"W0_clk", false,-1);
    tracep->declBus(c+1043,"W0_data", false,-1, 31,0);
    tracep->declBus(c+1044,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+327,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+78,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1198,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1046,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1199,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1047,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1048,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+328,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+79,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1049,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1050,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1200,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1160,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+187,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+188,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+189,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+329,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+80,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1201,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1202,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+951,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1203,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+81,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+190,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+191,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+42,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+327,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+78,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1198,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1046,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1199,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1047,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1048,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+328,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+79,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1049,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1050,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1200,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1160,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+187,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+188,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+189,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+329,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+80,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1201,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1202,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+951,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1203,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+81,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+190,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+191,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+42,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+213,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+90,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+315,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+193,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+83,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+84,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+194,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+195,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+188,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+196,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+214,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+91,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+317,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+950,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+81,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+190,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+191,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+199,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+207,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+145,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+315,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1057,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1162,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1163,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+208,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+372,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+373,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+374,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+209,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1164,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+317,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1058,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+210,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+375,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+376,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+377,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+378,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1165,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1166,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+387,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1167,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+317,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1062,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1168,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+388,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+389,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+390,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+139,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+140,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+315,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+139,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+141,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+182,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+183,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+316,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+1159,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+142,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+143,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+317,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+950,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+184,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+185,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+318,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+186,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+1159,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+195,"in_0_bvalid", false,-1);
    tracep->declBit(c+190,"in_0_rvalid", false,-1);
    tracep->declBit(c+215,"in_0_wready", false,-1);
    tracep->declBit(c+216,"in_0_awready", false,-1);
    tracep->declBit(c+214,"in_0_arready", false,-1);
    tracep->declBit(c+213,"anonIn_awready", false,-1);
    tracep->declBit(c+1063,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1064,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1065,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1066,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1067,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1068,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+391,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+392,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+393,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+394,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+395,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+396,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+397,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+398,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+399,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+400,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+401,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+402,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+403,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+404,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+405,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+406,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+407,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+408,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+409,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+410,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+411,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+412,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+413,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+414,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+415,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+416,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+417,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+418,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+419,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+420,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+421,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+422,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+423,"latched", false,-1);
    tracep->declBit(c+92,"in_0_awvalid", false,-1);
    tracep->declBit(c+93,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+94,"in_0_wvalid", false,-1);
    tracep->declBit(c+424,"idle_3", false,-1);
    tracep->declBit(c+217,"anyValid", false,-1);
    tracep->declBus(c+218,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+425,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+219,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+220,"prefixOR_1", false,-1);
    tracep->declBit(c+221,"winner_3_1", false,-1);
    tracep->declBit(c+222,"winner_3_2", false,-1);
    tracep->declBit(c+426,"state_3_0", false,-1);
    tracep->declBit(c+427,"state_3_1", false,-1);
    tracep->declBit(c+428,"state_3_2", false,-1);
    tracep->declBit(c+223,"muxState_3_0", false,-1);
    tracep->declBit(c+224,"muxState_3_1", false,-1);
    tracep->declBit(c+225,"muxState_3_2", false,-1);
    tracep->declBit(c+429,"idle_4", false,-1);
    tracep->declBit(c+226,"anyValid_1", false,-1);
    tracep->declBus(c+227,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+430,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+228,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+229,"winner_4_0", false,-1);
    tracep->declBit(c+230,"winner_4_2", false,-1);
    tracep->declBit(c+431,"state_4_0", false,-1);
    tracep->declBit(c+432,"state_4_2", false,-1);
    tracep->declBit(c+231,"muxState_4_0", false,-1);
    tracep->declBit(c+232,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+433,"io_enq_ready", false,-1);
    tracep->declBit(c+93,"io_enq_valid", false,-1);
    tracep->declBus(c+1069,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+233,"io_deq_ready", false,-1);
    tracep->declBit(c+95,"io_deq_valid", false,-1);
    tracep->declBus(c+1070,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+434,"wrap", false,-1);
    tracep->declBit(c+435,"wrap_1", false,-1);
    tracep->declBit(c+436,"maybe_full", false,-1);
    tracep->declBit(c+437,"ptr_match", false,-1);
    tracep->declBit(c+438,"empty", false,-1);
    tracep->declBit(c+439,"full", false,-1);
    tracep->declBit(c+95,"io_deq_valid_0", false,-1);
    tracep->declBit(c+234,"do_deq", false,-1);
    tracep->declBit(c+235,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+435,"R0_addr", false,-1);
    tracep->declBit(c+1204,"R0_en", false,-1);
    tracep->declBit(c+1125,"R0_clk", false,-1);
    tracep->declBus(c+440,"R0_data", false,-1, 2,0);
    tracep->declBit(c+434,"W0_addr", false,-1);
    tracep->declBit(c+235,"W0_en", false,-1);
    tracep->declBit(c+1125,"W0_clk", false,-1);
    tracep->declBus(c+1069,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+441+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+192,"auto_in_awready", false,-1);
    tracep->declBit(c+82,"auto_in_awvalid", false,-1);
    tracep->declBus(c+315,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+330,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+193,"auto_in_wready", false,-1);
    tracep->declBit(c+83,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+84,"auto_in_wlast", false,-1);
    tracep->declBit(c+194,"auto_in_bready", false,-1);
    tracep->declBit(c+195,"auto_in_bvalid", false,-1);
    tracep->declBus(c+188,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+196,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+197,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+198,"auto_in_arready", false,-1);
    tracep->declBit(c+85,"auto_in_arvalid", false,-1);
    tracep->declBus(c+317,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+950,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+331,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+81,"auto_in_rready", false,-1);
    tracep->declBit(c+190,"auto_in_rvalid", false,-1);
    tracep->declBus(c+191,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+43,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+199,"auto_in_rlast", false,-1);
    tracep->declBit(c+213,"auto_out_awready", false,-1);
    tracep->declBit(c+90,"auto_out_awvalid", false,-1);
    tracep->declBus(c+315,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1041,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+193,"auto_out_wready", false,-1);
    tracep->declBit(c+83,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1043,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1044,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+84,"auto_out_wlast", false,-1);
    tracep->declBit(c+194,"auto_out_bready", false,-1);
    tracep->declBit(c+195,"auto_out_bvalid", false,-1);
    tracep->declBus(c+188,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+196,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+214,"auto_out_arready", false,-1);
    tracep->declBit(c+91,"auto_out_arvalid", false,-1);
    tracep->declBus(c+317,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1045,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+950,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+81,"auto_out_rready", false,-1);
    tracep->declBit(c+190,"auto_out_rvalid", false,-1);
    tracep->declBus(c+191,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+199,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+443,"io_enq_ready", false,-1);
    tracep->declBit(c+44,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+236,"io_deq_ready", false,-1);
    tracep->declBit(c+444,"io_deq_valid", false,-1);
    tracep->declBit(c+445,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+445,"ram_real_last", false,-1);
    tracep->declBit(c+444,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+446,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+447,"io_enq_ready", false,-1);
    tracep->declBit(c+45,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+237,"io_deq_ready", false,-1);
    tracep->declBit(c+448,"io_deq_valid", false,-1);
    tracep->declBit(c+449,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+449,"ram_real_last", false,-1);
    tracep->declBit(c+448,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+450,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+451,"io_enq_ready", false,-1);
    tracep->declBit(c+46,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+238,"io_deq_ready", false,-1);
    tracep->declBit(c+452,"io_deq_valid", false,-1);
    tracep->declBit(c+453,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+453,"ram_real_last", false,-1);
    tracep->declBit(c+452,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+454,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+455,"io_enq_ready", false,-1);
    tracep->declBit(c+47,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+239,"io_deq_ready", false,-1);
    tracep->declBit(c+456,"io_deq_valid", false,-1);
    tracep->declBit(c+457,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+457,"ram_real_last", false,-1);
    tracep->declBit(c+456,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+458,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+459,"io_enq_ready", false,-1);
    tracep->declBit(c+48,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+240,"io_deq_ready", false,-1);
    tracep->declBit(c+460,"io_deq_valid", false,-1);
    tracep->declBit(c+461,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+461,"ram_real_last", false,-1);
    tracep->declBit(c+460,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+462,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+463,"io_enq_ready", false,-1);
    tracep->declBit(c+49,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+241,"io_deq_ready", false,-1);
    tracep->declBit(c+464,"io_deq_valid", false,-1);
    tracep->declBit(c+465,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+465,"ram_real_last", false,-1);
    tracep->declBit(c+464,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+466,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+467,"io_enq_ready", false,-1);
    tracep->declBit(c+50,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+242,"io_deq_ready", false,-1);
    tracep->declBit(c+468,"io_deq_valid", false,-1);
    tracep->declBit(c+469,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+469,"ram_real_last", false,-1);
    tracep->declBit(c+468,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+470,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+471,"io_enq_ready", false,-1);
    tracep->declBit(c+51,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+243,"io_deq_ready", false,-1);
    tracep->declBit(c+472,"io_deq_valid", false,-1);
    tracep->declBit(c+473,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+473,"ram_real_last", false,-1);
    tracep->declBit(c+472,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+474,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+475,"io_enq_ready", false,-1);
    tracep->declBit(c+52,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+244,"io_deq_ready", false,-1);
    tracep->declBit(c+476,"io_deq_valid", false,-1);
    tracep->declBit(c+477,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+477,"ram_real_last", false,-1);
    tracep->declBit(c+476,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+478,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+479,"io_enq_ready", false,-1);
    tracep->declBit(c+53,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+245,"io_deq_ready", false,-1);
    tracep->declBit(c+480,"io_deq_valid", false,-1);
    tracep->declBit(c+481,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+481,"ram_real_last", false,-1);
    tracep->declBit(c+480,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+482,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+483,"io_enq_ready", false,-1);
    tracep->declBit(c+54,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+246,"io_deq_ready", false,-1);
    tracep->declBit(c+484,"io_deq_valid", false,-1);
    tracep->declBit(c+485,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+485,"ram_real_last", false,-1);
    tracep->declBit(c+484,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+486,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+487,"io_enq_ready", false,-1);
    tracep->declBit(c+55,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+247,"io_deq_ready", false,-1);
    tracep->declBit(c+488,"io_deq_valid", false,-1);
    tracep->declBit(c+489,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+489,"ram_real_last", false,-1);
    tracep->declBit(c+488,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+490,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+491,"io_enq_ready", false,-1);
    tracep->declBit(c+56,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+248,"io_deq_ready", false,-1);
    tracep->declBit(c+492,"io_deq_valid", false,-1);
    tracep->declBit(c+493,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+493,"ram_real_last", false,-1);
    tracep->declBit(c+492,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+494,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+495,"io_enq_ready", false,-1);
    tracep->declBit(c+57,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+249,"io_deq_ready", false,-1);
    tracep->declBit(c+496,"io_deq_valid", false,-1);
    tracep->declBit(c+497,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+497,"ram_real_last", false,-1);
    tracep->declBit(c+496,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+498,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+499,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+250,"io_deq_ready", false,-1);
    tracep->declBit(c+500,"io_deq_valid", false,-1);
    tracep->declBit(c+501,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+501,"ram_real_last", false,-1);
    tracep->declBit(c+500,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+502,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+503,"io_enq_ready", false,-1);
    tracep->declBit(c+59,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+251,"io_deq_ready", false,-1);
    tracep->declBit(c+504,"io_deq_valid", false,-1);
    tracep->declBit(c+505,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+505,"ram_real_last", false,-1);
    tracep->declBit(c+504,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+506,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+507,"io_enq_ready", false,-1);
    tracep->declBit(c+60,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+252,"io_deq_ready", false,-1);
    tracep->declBit(c+508,"io_deq_valid", false,-1);
    tracep->declBit(c+509,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+509,"ram_real_last", false,-1);
    tracep->declBit(c+508,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+510,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+511,"io_enq_ready", false,-1);
    tracep->declBit(c+61,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+253,"io_deq_ready", false,-1);
    tracep->declBit(c+512,"io_deq_valid", false,-1);
    tracep->declBit(c+513,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+513,"ram_real_last", false,-1);
    tracep->declBit(c+512,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+514,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+515,"io_enq_ready", false,-1);
    tracep->declBit(c+62,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+254,"io_deq_ready", false,-1);
    tracep->declBit(c+516,"io_deq_valid", false,-1);
    tracep->declBit(c+517,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+517,"ram_real_last", false,-1);
    tracep->declBit(c+516,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+518,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+519,"io_enq_ready", false,-1);
    tracep->declBit(c+63,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+255,"io_deq_ready", false,-1);
    tracep->declBit(c+520,"io_deq_valid", false,-1);
    tracep->declBit(c+521,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+521,"ram_real_last", false,-1);
    tracep->declBit(c+520,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+522,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+523,"io_enq_ready", false,-1);
    tracep->declBit(c+64,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+256,"io_deq_ready", false,-1);
    tracep->declBit(c+524,"io_deq_valid", false,-1);
    tracep->declBit(c+525,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+525,"ram_real_last", false,-1);
    tracep->declBit(c+524,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+526,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+527,"io_enq_ready", false,-1);
    tracep->declBit(c+65,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+257,"io_deq_ready", false,-1);
    tracep->declBit(c+528,"io_deq_valid", false,-1);
    tracep->declBit(c+529,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+529,"ram_real_last", false,-1);
    tracep->declBit(c+528,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+530,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+531,"io_enq_ready", false,-1);
    tracep->declBit(c+66,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+258,"io_deq_ready", false,-1);
    tracep->declBit(c+532,"io_deq_valid", false,-1);
    tracep->declBit(c+533,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+533,"ram_real_last", false,-1);
    tracep->declBit(c+532,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+534,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+535,"io_enq_ready", false,-1);
    tracep->declBit(c+67,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+259,"io_deq_ready", false,-1);
    tracep->declBit(c+536,"io_deq_valid", false,-1);
    tracep->declBit(c+537,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+537,"ram_real_last", false,-1);
    tracep->declBit(c+536,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+538,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+539,"io_enq_ready", false,-1);
    tracep->declBit(c+68,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+260,"io_deq_ready", false,-1);
    tracep->declBit(c+540,"io_deq_valid", false,-1);
    tracep->declBit(c+541,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+541,"ram_real_last", false,-1);
    tracep->declBit(c+540,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+542,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+543,"io_enq_ready", false,-1);
    tracep->declBit(c+69,"io_enq_valid", false,-1);
    tracep->declBit(c+330,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+261,"io_deq_ready", false,-1);
    tracep->declBit(c+544,"io_deq_valid", false,-1);
    tracep->declBit(c+545,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+545,"ram_real_last", false,-1);
    tracep->declBit(c+544,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+546,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+547,"io_enq_ready", false,-1);
    tracep->declBit(c+70,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+262,"io_deq_ready", false,-1);
    tracep->declBit(c+548,"io_deq_valid", false,-1);
    tracep->declBit(c+549,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+549,"ram_real_last", false,-1);
    tracep->declBit(c+548,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+550,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+551,"io_enq_ready", false,-1);
    tracep->declBit(c+71,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+263,"io_deq_ready", false,-1);
    tracep->declBit(c+552,"io_deq_valid", false,-1);
    tracep->declBit(c+553,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+553,"ram_real_last", false,-1);
    tracep->declBit(c+552,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+554,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+555,"io_enq_ready", false,-1);
    tracep->declBit(c+72,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+264,"io_deq_ready", false,-1);
    tracep->declBit(c+556,"io_deq_valid", false,-1);
    tracep->declBit(c+557,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+557,"ram_real_last", false,-1);
    tracep->declBit(c+556,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+558,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+559,"io_enq_ready", false,-1);
    tracep->declBit(c+73,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+265,"io_deq_ready", false,-1);
    tracep->declBit(c+560,"io_deq_valid", false,-1);
    tracep->declBit(c+561,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+561,"ram_real_last", false,-1);
    tracep->declBit(c+560,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+562,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+563,"io_enq_ready", false,-1);
    tracep->declBit(c+74,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+266,"io_deq_ready", false,-1);
    tracep->declBit(c+564,"io_deq_valid", false,-1);
    tracep->declBit(c+565,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+565,"ram_real_last", false,-1);
    tracep->declBit(c+564,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+566,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+567,"io_enq_ready", false,-1);
    tracep->declBit(c+75,"io_enq_valid", false,-1);
    tracep->declBit(c+331,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+267,"io_deq_ready", false,-1);
    tracep->declBit(c+568,"io_deq_valid", false,-1);
    tracep->declBit(c+569,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+569,"ram_real_last", false,-1);
    tracep->declBit(c+568,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+570,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+96,"reset", false,-1);
    tracep->declBit(c+327,"auto_master_out_awready", false,-1);
    tracep->declBit(c+78,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1198,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1046,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1199,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1047,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1048,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+328,"auto_master_out_wready", false,-1);
    tracep->declBit(c+79,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1049,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1050,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1200,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1160,"auto_master_out_bready", false,-1);
    tracep->declBit(c+187,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+188,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+189,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+329,"auto_master_out_arready", false,-1);
    tracep->declBit(c+80,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1201,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1051,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1202,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+951,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1203,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+81,"auto_master_out_rready", false,-1);
    tracep->declBit(c+190,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+191,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+41,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1161,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+42,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+96,"reset", false,-1);
    tracep->declBit(c+1188,"io_interrupt", false,-1);
    tracep->declBit(c+327,"io_master_awready", false,-1);
    tracep->declBit(c+78,"io_master_awvalid", false,-1);
    tracep->declBus(c+1046,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1198,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1199,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1047,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1048,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+328,"io_master_wready", false,-1);
    tracep->declBit(c+79,"io_master_wvalid", false,-1);
    tracep->declBus(c+1049,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+1050,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1200,"io_master_wlast", false,-1);
    tracep->declBit(c+1160,"io_master_bready", false,-1);
    tracep->declBit(c+187,"io_master_bvalid", false,-1);
    tracep->declBus(c+189,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+188,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+329,"io_master_arready", false,-1);
    tracep->declBit(c+80,"io_master_arvalid", false,-1);
    tracep->declBus(c+1051,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1201,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1202,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+951,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1203,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+81,"io_master_rready", false,-1);
    tracep->declBit(c+190,"io_master_rvalid", false,-1);
    tracep->declBus(c+1161,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+41,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+42,"io_master_rlast", false,-1);
    tracep->declBus(c+191,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1205,"io_slave_awready", false,-1);
    tracep->declBit(c+1188,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1206,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1207,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1202,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1208,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1209,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1210,"io_slave_wready", false,-1);
    tracep->declBit(c+1188,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1206,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1207,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1188,"io_slave_wlast", false,-1);
    tracep->declBit(c+1188,"io_slave_bready", false,-1);
    tracep->declBit(c+1211,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1212,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1213,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1214,"io_slave_arready", false,-1);
    tracep->declBit(c+1188,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1206,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1207,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1202,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1208,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1209,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1188,"io_slave_rready", false,-1);
    tracep->declBit(c+1215,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1216,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1217,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1218,"io_slave_rlast", false,-1);
    tracep->declBus(c+1219,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+952,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1071,"npc", false,-1, 31,0);
    tracep->declBus(c+863,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+953,"inst", false,-1, 31,0);
    tracep->declBit(c+954,"ifu_valid", false,-1);
    tracep->declBit(c+955,"ifu_arvalid", false,-1);
    tracep->declBit(c+956,"ifu_arready", false,-1);
    tracep->declBus(c+863,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+268,"ifu_rvalid", false,-1);
    tracep->declBit(c+952,"ifu_rready", false,-1);
    tracep->declBus(c+269,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+957,"reg_process", false,-1);
    tracep->declBus(c+958,"src1", false,-1, 4,0);
    tracep->declBus(c+959,"src2", false,-1, 4,0);
    tracep->declBus(c+960,"rd", false,-1, 4,0);
    tracep->declBus(c+961,"imm", false,-1, 31,0);
    tracep->declBit(c+962,"ebreaksig", false,-1);
    tracep->declBit(c+963,"mretsig", false,-1);
    tracep->declBit(c+964,"ecallsig", false,-1);
    tracep->declBit(c+965,"regew", false,-1);
    tracep->declBit(c+966,"memew", false,-1);
    tracep->declBit(c+967,"memer", false,-1);
    tracep->declBit(c+968,"muximm", false,-1);
    tracep->declBus(c+969,"func3", false,-1, 2,0);
    tracep->declBus(c+970,"muxsig", false,-1, 2,0);
    tracep->declBit(c+971,"func7", false,-1);
    tracep->declBit(c+972,"btypebranch", false,-1);
    tracep->declBit(c+973,"jalsig", false,-1);
    tracep->declBit(c+974,"jalrsig", false,-1);
    tracep->declBit(c+975,"auipcsig", false,-1);
    tracep->declBus(c+976,"aluop", false,-1, 1,0);
    tracep->declBit(c+977,"csrrw", false,-1);
    tracep->declBit(c+978,"csrrs", false,-1);
    tracep->declBit(c+954,"idu_valid", false,-1);
    tracep->declBus(c+979,"memmask", false,-1, 2,0);
    tracep->declBit(c+980,"memsextsig", false,-1);
    tracep->declBus(c+270,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1072,"regout1", false,-1, 31,0);
    tracep->declBus(c+1073,"regout2", false,-1, 31,0);
    tracep->declBus(c+864,"mepc", false,-1, 31,0);
    tracep->declBus(c+865,"mtvec", false,-1, 31,0);
    tracep->declBit(c+952,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1074,"res", false,-1, 31,0);
    tracep->declBus(c+1075,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+954,"exu_valid", false,-1);
    tracep->declBit(c+952,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1169,"memvalid", false,-1);
    tracep->declBus(c+981,"awvalid", false,-1, 1,0);
    tracep->declBus(c+981,"wvalid", false,-1, 1,0);
    tracep->declBus(c+982,"arvalid", false,-1, 1,0);
    tracep->declBus(c+983,"rready", false,-1, 1,0);
    tracep->declBus(c+984,"bready", false,-1, 1,0);
    tracep->declBus(c+76,"bvalid", false,-1, 1,0);
    tracep->declBus(c+271,"rvalid", false,-1, 1,0);
    tracep->declBus(c+571,"awready", false,-1, 1,0);
    tracep->declBus(c+571,"wready", false,-1, 1,0);
    tracep->declBus(c+985,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1170+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+272+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1076+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1078+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1080+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+274+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1082+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+986+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1220,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+96,"reset", false,-1);
    tracep->declBus(c+981,"awvalid", false,-1, 1,0);
    tracep->declBus(c+981,"wvalid", false,-1, 1,0);
    tracep->declBus(c+982,"arvalid", false,-1, 1,0);
    tracep->declBus(c+983,"rready", false,-1, 1,0);
    tracep->declBus(c+984,"bready", false,-1, 1,0);
    tracep->declBus(c+76,"bvalid", false,-1, 1,0);
    tracep->declBus(c+271,"rvalid", false,-1, 1,0);
    tracep->declBus(c+571,"awready", false,-1, 1,0);
    tracep->declBus(c+571,"wready", false,-1, 1,0);
    tracep->declBus(c+985,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1084+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1086+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1088+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1090+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+276+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+278+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1092+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+988+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->declBit(c+78,"awvalid_out", false,-1);
    tracep->declBit(c+79,"wvalid_out", false,-1);
    tracep->declBit(c+80,"arvalid_out", false,-1);
    tracep->declBit(c+81,"rready_out", false,-1);
    tracep->declBit(c+1160,"bready_out", false,-1);
    tracep->declBit(c+187,"bvalid_in", false,-1);
    tracep->declBit(c+190,"rvalid_in", false,-1);
    tracep->declBit(c+328,"awready_in", false,-1);
    tracep->declBit(c+328,"wready_in", false,-1);
    tracep->declBit(c+329,"arready_in", false,-1);
    tracep->declBus(c+1051,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1046,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1049,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+1050,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+41,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+189,"bresp_in", false,-1, 1,0);
    tracep->declBus(c+1047,"awsize_out", false,-1, 2,0);
    tracep->declBus(c+951,"arsize_out", false,-1, 2,0);
    tracep->declBit(c+572,"busy", false,-1);
    tracep->declBus(c+573,"giant", false,-1, 1,0);
    tracep->declBus(c+574,"i", false,-1, 31,0);
    tracep->declBus(c+1046,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1049,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1051,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1050,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1047,"awsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+951,"arsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1221,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+969,"func3", false,-1, 2,0);
    tracep->declBit(c+972,"btypebranch", false,-1);
    tracep->declBit(c+971,"func7", false,-1);
    tracep->declBus(c+976,"aluop", false,-1, 1,0);
    tracep->declBit(c+974,"jalrsig", false,-1);
    tracep->declBit(c+973,"jalsig", false,-1);
    tracep->declBus(c+961,"imm", false,-1, 31,0);
    tracep->declBit(c+968,"muximm", false,-1);
    tracep->declBus(c+1072,"regout1", false,-1, 31,0);
    tracep->declBus(c+1073,"regout2", false,-1, 31,0);
    tracep->declBus(c+863,"pc", false,-1, 31,0);
    tracep->declBit(c+975,"auipcsig", false,-1);
    tracep->declBit(c+963,"mretsig", false,-1);
    tracep->declBit(c+964,"ecallsig", false,-1);
    tracep->declBus(c+865,"mtvec", false,-1, 31,0);
    tracep->declBus(c+864,"mepc", false,-1, 31,0);
    tracep->declBit(c+954,"valid_from", false,-1);
    tracep->declBit(c+952,"ready_from", false,-1);
    tracep->declBus(c+1074,"res", false,-1, 31,0);
    tracep->declBus(c+1071,"npc", false,-1, 31,0);
    tracep->declBus(c+1075,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+954,"valid_to", false,-1);
    tracep->declBit(c+952,"ready_to", false,-1);
    tracep->declBus(c+866,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1094,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+990,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1095,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1096,"zero", false,-1);
    tracep->declBit(c+1097,"signal", false,-1);
    tracep->declBit(c+1098,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1072,"A", false,-1, 31,0);
    tracep->declBus(c+1095,"B", false,-1, 31,0);
    tracep->declBus(c+990,"op", false,-1, 4,0);
    tracep->declBus(c+1074,"res", false,-1, 31,0);
    tracep->declBit(c+1096,"zero", false,-1);
    tracep->declBit(c+1097,"signal", false,-1);
    tracep->declBit(c+1098,"carry", false,-1);
    tracep->declBit(c+991,"addsig", false,-1);
    tracep->declBit(c+992,"logsig", false,-1);
    tracep->declBit(c+993,"shfsig", false,-1);
    tracep->declBit(c+994,"sltsig", false,-1);
    tracep->declBit(c+1098,"carry_tmp", false,-1);
    tracep->declBit(c+995,"type_I", false,-1);
    tracep->declBus(c+1099,"logres", false,-1, 31,0);
    tracep->declBus(c+1100,"addres", false,-1, 31,0);
    tracep->declBit(c+1101,"addzero", false,-1);
    tracep->declBus(c+1102,"shfres", false,-1, 31,0);
    tracep->declBus(c+1103,"sltres", false,-1, 31,0);
    tracep->declBus(c+1072,"A_s", false,-1, 31,0);
    tracep->declBus(c+1095,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+969,"func3", false,-1, 2,0);
    tracep->declBit(c+971,"func7", false,-1);
    tracep->declBus(c+976,"aluop", false,-1, 1,0);
    tracep->declBit(c+974,"jalrsig", false,-1);
    tracep->declBus(c+990,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+995,"type_I", false,-1);
    tracep->declBit(c+996,"type_B", false,-1);
    tracep->declBit(c+997,"type_R", false,-1);
    tracep->declBit(c+998,"addsig", false,-1);
    tracep->declBus(c+999,"branchop", false,-1, 3,0);
    tracep->declBus(c+1000,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+972,"btypebranch", false,-1);
    tracep->declBus(c+969,"func3", false,-1, 2,0);
    tracep->declBit(c+1096,"zero", false,-1);
    tracep->declBit(c+1097,"signal", false,-1);
    tracep->declBit(c+1098,"carry", false,-1);
    tracep->declBus(c+1074,"res", false,-1, 31,0);
    tracep->declBus(c+866,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1094,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+973,"jalsig", false,-1);
    tracep->declBit(c+974,"jalrsig", false,-1);
    tracep->declBit(c+975,"auipcsig", false,-1);
    tracep->declBit(c+963,"mretsig", false,-1);
    tracep->declBit(c+964,"ecallsig", false,-1);
    tracep->declBus(c+865,"mtvec", false,-1, 31,0);
    tracep->declBus(c+864,"mepc", false,-1, 31,0);
    tracep->declBus(c+1071,"npc", false,-1, 31,0);
    tracep->declBus(c+1075,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1220,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1222,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1223,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1095,"out", false,-1, 31,0);
    tracep->declBus(c+968,"key", false,-1, 0,0);
    tracep->declArray(c+1023,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1220,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1222,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1223,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1224,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1095,"out", false,-1, 31,0);
    tracep->declBus(c+968,"key", false,-1, 0,0);
    tracep->declBus(c+1206,"default_out", false,-1, 31,0);
    tracep->declArray(c+1023,"lut", false,-1, 65,0);
    tracep->declBus(c+1225,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1026+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1030+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1104,"lut_out", false,-1, 31,0);
    tracep->declBit(c+1001,"hit", false,-1);
    tracep->declBus(c+1226,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+863,"pc", false,-1, 31,0);
    tracep->declBus(c+866,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+863,"pc", false,-1, 31,0);
    tracep->declBus(c+961,"imm", false,-1, 31,0);
    tracep->declBus(c+1094,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+953,"inst", false,-1, 31,0);
    tracep->declBit(c+954,"valid_from", false,-1);
    tracep->declBit(c+952,"ready_from", false,-1);
    tracep->declBit(c+962,"ebreaksig", false,-1);
    tracep->declBit(c+964,"ecallsig", false,-1);
    tracep->declBit(c+963,"mretsig", false,-1);
    tracep->declBus(c+961,"imm", false,-1, 31,0);
    tracep->declBus(c+969,"func3", false,-1, 2,0);
    tracep->declBit(c+971,"func7", false,-1);
    tracep->declBus(c+958,"src1", false,-1, 4,0);
    tracep->declBus(c+959,"src2", false,-1, 4,0);
    tracep->declBus(c+960,"rd", false,-1, 4,0);
    tracep->declBit(c+966,"memew", false,-1);
    tracep->declBus(c+970,"muxsig", false,-1, 2,0);
    tracep->declBit(c+967,"memer", false,-1);
    tracep->declBit(c+965,"regew", false,-1);
    tracep->declBit(c+968,"muximm", false,-1);
    tracep->declBit(c+972,"btypebranch", false,-1);
    tracep->declBit(c+974,"jalrsig", false,-1);
    tracep->declBit(c+973,"jalsig", false,-1);
    tracep->declBus(c+976,"aluop", false,-1, 1,0);
    tracep->declBit(c+975,"auipcsig", false,-1);
    tracep->declBit(c+977,"csrrw", false,-1);
    tracep->declBit(c+978,"csrrs", false,-1);
    tracep->declBit(c+954,"valid_to", false,-1);
    tracep->declBit(c+952,"ready_to", false,-1);
    tracep->declBus(c+979,"memmask", false,-1, 2,0);
    tracep->declBit(c+980,"memsextsig", false,-1);
    tracep->declBit(c+962,"ebreak", false,-1);
    tracep->declBit(c+964,"ecall", false,-1);
    tracep->declBit(c+963,"mret", false,-1);
    tracep->declBus(c+969,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+971,"func7bridge", false,-1);
    tracep->declBus(c+1002,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+953,"inst", false,-1, 31,0);
    tracep->declBit(c+962,"ebreaksig", false,-1);
    tracep->declBit(c+964,"ecallsig", false,-1);
    tracep->declBit(c+963,"mretsig", false,-1);
    tracep->declBus(c+961,"imm", false,-1, 31,0);
    tracep->declBus(c+1002,"opcode", false,-1, 6,0);
    tracep->declBus(c+969,"func3", false,-1, 2,0);
    tracep->declBit(c+971,"func7", false,-1);
    tracep->declBus(c+958,"src1", false,-1, 4,0);
    tracep->declBus(c+959,"src2", false,-1, 4,0);
    tracep->declBus(c+960,"rd", false,-1, 4,0);
    tracep->declBus(c+979,"memmask", false,-1, 2,0);
    tracep->declBit(c+980,"memsextsig", false,-1);
    tracep->declBit(c+1003,"type_I", false,-1);
    tracep->declBit(c+1004,"type_R", false,-1);
    tracep->declBit(c+1005,"type_U", false,-1);
    tracep->declBit(c+966,"type_S", false,-1);
    tracep->declBit(c+973,"type_J", false,-1);
    tracep->declBit(c+972,"type_B", false,-1);
    tracep->declBus(c+1006,"I_imm", false,-1, 31,0);
    tracep->declBus(c+1007,"U_imm", false,-1, 31,0);
    tracep->declBus(c+1008,"S_imm", false,-1, 31,0);
    tracep->declBus(c+1009,"J_imm", false,-1, 31,0);
    tracep->declBus(c+1010,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+1002,"opcode", false,-1, 6,0);
    tracep->declBus(c+969,"func3", false,-1, 2,0);
    tracep->declBit(c+971,"func7", false,-1);
    tracep->declBit(c+962,"ebreaksig", false,-1);
    tracep->declBit(c+964,"ecallsig", false,-1);
    tracep->declBit(c+963,"mretsig", false,-1);
    tracep->declBit(c+966,"memew", false,-1);
    tracep->declBus(c+970,"muxsig", false,-1, 2,0);
    tracep->declBit(c+967,"memer", false,-1);
    tracep->declBit(c+965,"regew", false,-1);
    tracep->declBit(c+968,"muximm", false,-1);
    tracep->declBit(c+972,"btypebranch", false,-1);
    tracep->declBit(c+974,"jalrsig", false,-1);
    tracep->declBit(c+973,"jalsig", false,-1);
    tracep->declBus(c+976,"aluop", false,-1, 1,0);
    tracep->declBit(c+975,"auipcsig", false,-1);
    tracep->declBit(c+977,"csrrw", false,-1);
    tracep->declBit(c+978,"csrrs", false,-1);
    tracep->declBit(c+1003,"type_I", false,-1);
    tracep->declBit(c+1004,"type_R", false,-1);
    tracep->declBit(c+1005,"type_U", false,-1);
    tracep->declBit(c+966,"type_S", false,-1);
    tracep->declBit(c+973,"type_J", false,-1);
    tracep->declBit(c+972,"type_B", false,-1);
    tracep->declBit(c+967,"load", false,-1);
    tracep->declBit(c+966,"store", false,-1);
    tracep->declBit(c+1011,"regwritepc", false,-1);
    tracep->declBit(c+967,"regwritemem", false,-1);
    tracep->declBit(c+1012,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+96,"rst", false,-1);
    tracep->declBus(c+1071,"npc", false,-1, 31,0);
    tracep->declBit(c+952,"ready", false,-1);
    tracep->declBus(c+863,"pc", false,-1, 31,0);
    tracep->declBus(c+953,"inst", false,-1, 31,0);
    tracep->declBit(c+954,"valid", false,-1);
    tracep->declBit(c+957,"regprocess", false,-1);
    tracep->declBit(c+955,"arvalid", false,-1);
    tracep->declBit(c+956,"arready", false,-1);
    tracep->declBus(c+863,"araddr", false,-1, 31,0);
    tracep->declBit(c+268,"rvalid", false,-1);
    tracep->declBit(c+952,"rready", false,-1);
    tracep->declBus(c+269,"rdata", false,-1, 31,0);
    tracep->declBus(c+863,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1013,"infetch_ready", false,-1);
    tracep->declBus(c+1014,"state", false,-1, 2,0);
    tracep->declBus(c+953,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBus(c+1071,"npc", false,-1, 31,0);
    tracep->declBit(c+96,"rst", false,-1);
    tracep->declBit(c+1013,"ready_from", false,-1);
    tracep->declBus(c+863,"pcout", false,-1, 31,0);
    tracep->declBus(c+1227,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+96,"rst", false,-1);
    tracep->declBit(c+1172,"ew", false,-1);
    tracep->declBus(c+960,"addr", false,-1, 4,0);
    tracep->declBus(c+958,"src1", false,-1, 4,0);
    tracep->declBus(c+959,"src2", false,-1, 4,0);
    tracep->declBus(c+1015,"csr", false,-1, 11,0);
    tracep->declBus(c+270,"data", false,-1, 31,0);
    tracep->declBit(c+977,"csrrw", false,-1);
    tracep->declBit(c+978,"csrrs", false,-1);
    tracep->declBit(c+964,"ecallsig", false,-1);
    tracep->declBit(c+954,"valid", false,-1);
    tracep->declBus(c+1072,"regout1", false,-1, 31,0);
    tracep->declBus(c+1073,"regout2", false,-1, 31,0);
    tracep->declBus(c+864,"mepc", false,-1, 31,0);
    tracep->declBus(c+865,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+867+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+899+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1016,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+280,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1228,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1229,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1220,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1016,"out", false,-1, 1,0);
    tracep->declBus(c+1015,"key", false,-1, 11,0);
    tracep->declQuad(c+1230,"lut", false,-1, 55,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1228,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1229,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1220,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1224,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1016,"out", false,-1, 1,0);
    tracep->declBus(c+1015,"key", false,-1, 11,0);
    tracep->declBus(c+1209,"default_out", false,-1, 1,0);
    tracep->declQuad(c+1230,"lut", false,-1, 55,0);
    tracep->declBus(c+1232,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 13,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1017,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1018,"hit", false,-1);
    tracep->declBus(c+1233,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+96,"rst", false,-1);
    tracep->declBit(c+1173,"ew", false,-1);
    tracep->declBit(c+977,"csrrw", false,-1);
    tracep->declBit(c+978,"csrrs", false,-1);
    tracep->declBit(c+964,"ecall", false,-1);
    tracep->declBus(c+1016,"csr_choose", false,-1, 1,0);
    tracep->declBus(c+960,"addr", false,-1, 4,0);
    tracep->declBus(c+280,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+903+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+935+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+939,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBus(c+1074,"res", false,-1, 31,0);
    tracep->declBus(c+1073,"regout2", false,-1, 31,0);
    tracep->declBit(c+966,"memew", false,-1);
    tracep->declBit(c+967,"memer", false,-1);
    tracep->declBus(c+961,"imm", false,-1, 31,0);
    tracep->declBus(c+1075,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+970,"muxsig", false,-1, 2,0);
    tracep->declBit(c+954,"valid_from", false,-1);
    tracep->declBus(c+979,"memmask", false,-1, 2,0);
    tracep->declBit(c+980,"memsextsig", false,-1);
    tracep->declBus(c+270,"regwrite", false,-1, 31,0);
    tracep->declBit(c+952,"ready_to", false,-1);
    tracep->declBit(c+1169,"memvalid", false,-1);
    tracep->declBit(c+1019,"awvalid", false,-1);
    tracep->declBit(c+575,"awready", false,-1);
    tracep->declBus(c+1074,"awaddr", false,-1, 31,0);
    tracep->declBit(c+1019,"wvalid", false,-1);
    tracep->declBit(c+575,"wready", false,-1);
    tracep->declBus(c+1105,"wdata", false,-1, 31,0);
    tracep->declBus(c+1106,"wstrb", false,-1, 3,0);
    tracep->declBit(c+77,"bvalid", false,-1);
    tracep->declBit(c+966,"bready", false,-1);
    tracep->declBus(c+281,"bresp", false,-1, 1,0);
    tracep->declBit(c+1174,"arvalid", false,-1);
    tracep->declBit(c+1020,"arready", false,-1);
    tracep->declBus(c+1074,"araddr", false,-1, 31,0);
    tracep->declBit(c+282,"rvalid", false,-1);
    tracep->declBit(c+967,"rready", false,-1);
    tracep->declBus(c+283,"rdata", false,-1, 31,0);
    tracep->declBus(c+1107,"awsize", false,-1, 2,0);
    tracep->declBus(c+1021,"arsize", false,-1, 2,0);
    tracep->declBus(c+1048,"awburst", false,-1, 1,0);
    tracep->declBus(c+576,"state", false,-1, 1,0);
    tracep->declBus(c+284,"memread", false,-1, 31,0);
    tracep->declBus(c+1108,"wdata_offset", false,-1, 1,0);
    tracep->declBit(c+1175,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBus(c+283,"data", false,-1, 31,0);
    tracep->declBus(c+979,"memmask", false,-1, 2,0);
    tracep->declBit(c+980,"memsextsig", false,-1);
    tracep->declBus(c+1109,"addr_offset", false,-1, 1,0);
    tracep->declBus(c+284,"read", false,-1, 31,0);
    tracep->declBus(c+285,"read_u", false,-1, 31,0);
    tracep->declBus(c+286,"read_s", false,-1, 31,0);
    tracep->declBus(c+287,"read_sb", false,-1, 31,0);
    tracep->declBus(c+288,"read_sh", false,-1, 31,0);
    tracep->declBus(c+289,"byte_data", false,-1, 7,0);
    tracep->declBus(c+290,"halfword_data", false,-1, 15,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1234,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1223,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+289,"input_number", false,-1, 7,0);
    tracep->declBus(c+287,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1235,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1223,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+290,"input_number", false,-1, 15,0);
    tracep->declBus(c+288,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1228,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1236,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1223,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+270,"out", false,-1, 31,0);
    tracep->declBus(c+970,"key", false,-1, 2,0);
    tracep->declBus(c+1224,"default_out", false,-1, 31,0);
    tracep->declArray(c+97,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1228,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1236,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1223,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1222,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+270,"out", false,-1, 31,0);
    tracep->declBus(c+970,"key", false,-1, 2,0);
    tracep->declBus(c+1224,"default_out", false,-1, 31,0);
    tracep->declArray(c+97,"lut", false,-1, 139,0);
    tracep->declBus(c+1237,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+102+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+110+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+291,"lut_out", false,-1, 31,0);
    tracep->declBit(c+292,"hit", false,-1);
    tracep->declBus(c+1233,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("strbcontol ");
    tracep->declBus(c+1074,"awaddr", false,-1, 31,0);
    tracep->declBus(c+979,"wirtelen", false,-1, 2,0);
    tracep->declBus(c+1106,"wstrb", false,-1, 3,0);
    tracep->declBus(c+1107,"awsize", false,-1, 2,0);
    tracep->declBus(c+1108,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1048,"awburst", false,-1, 1,0);
    tracep->declBus(c+1236,"device_num", false,-1, 31,0);
    tracep->declBit(c+1110,"inuart", false,-1);
    tracep->declBit(c+1111,"insram", false,-1);
    tracep->declBit(c+1112,"inflash", false,-1);
    tracep->declBit(c+1113,"inspi", false,-1);
    tracep->declBus(c+1114,"bus_size", false,-1, 1,0);
    tracep->declBus(c+1022,"wstrb_general", false,-1, 3,0);
    tracep->declBus(c+1238,"wstrb_byte", false,-1, 3,0);
    tracep->declBus(c+1239,"wstrb_halfword", false,-1, 3,0);
    tracep->declBus(c+1115,"wstrb_word", false,-1, 3,0);
    tracep->declBus(c+1116,"mux", false,-1, 4,0);
    tracep->pushNamePrefix("len_mux ");
    tracep->declBus(c+1236,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1220,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1236,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1107,"out", false,-1, 2,0);
    tracep->declBus(c+1114,"key", false,-1, 1,0);
    tracep->declBus(c+979,"default_out", false,-1, 2,0);
    tracep->declBus(c+1240,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1236,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1220,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1236,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1222,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1107,"out", false,-1, 2,0);
    tracep->declBus(c+1114,"key", false,-1, 1,0);
    tracep->declBus(c+979,"default_out", false,-1, 2,0);
    tracep->declBus(c+1240,"lut", false,-1, 14,0);
    tracep->declBus(c+1241,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+19+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+22+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+25+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1117,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1118,"hit", false,-1);
    tracep->declBus(c+1242,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("type_mux ");
    tracep->declBus(c+1236,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1236,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1220,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1114,"out", false,-1, 1,0);
    tracep->declBus(c+1119,"key", false,-1, 2,0);
    tracep->declBus(c+1209,"default_out", false,-1, 1,0);
    tracep->declBus(c+1243,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1236,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1236,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1220,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1222,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1114,"out", false,-1, 1,0);
    tracep->declBus(c+1119,"key", false,-1, 2,0);
    tracep->declBus(c+1209,"default_out", false,-1, 1,0);
    tracep->declBus(c+1243,"lut", false,-1, 14,0);
    tracep->declBus(c+1241,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+28+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+31+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+34+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1120,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1121,"hit", false,-1);
    tracep->declBus(c+1242,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wstrb_mux ");
    tracep->declBus(c+1228,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1220,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1228,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1106,"out", false,-1, 3,0);
    tracep->declBus(c+1114,"key", false,-1, 1,0);
    tracep->declBus(c+1032,"lut", false,-1, 23,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1228,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1220,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1228,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1224,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1106,"out", false,-1, 3,0);
    tracep->declBus(c+1114,"key", false,-1, 1,0);
    tracep->declBus(c+1207,"default_out", false,-1, 3,0);
    tracep->declBus(c+1032,"lut", false,-1, 23,0);
    tracep->declBus(c+1244,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1033+i*1,"pair_list", true,(i+0), 5,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+37+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1037+i*1,"data_list", true,(i+0), 3,0);
    }
    tracep->declBus(c+1122,"lut_out", false,-1, 3,0);
    tracep->declBit(c+1123,"hit", false,-1);
    tracep->declBus(c+1233,"i", false,-1, 31,0);
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"io_d", false,-1);
    tracep->declBit(c+577,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"io_d", false,-1);
    tracep->declBit(c+577,"io_q", false,-1);
    tracep->declBit(c+577,"sync_0", false,-1);
    tracep->declBit(c+578,"sync_1", false,-1);
    tracep->declBit(c+579,"sync_2", false,-1);
    tracep->declBit(c+580,"sync_3", false,-1);
    tracep->declBit(c+581,"sync_4", false,-1);
    tracep->declBit(c+582,"sync_5", false,-1);
    tracep->declBit(c+583,"sync_6", false,-1);
    tracep->declBit(c+584,"sync_7", false,-1);
    tracep->declBit(c+585,"sync_8", false,-1);
    tracep->declBit(c+586,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+125,"auto_in_psel", false,-1);
    tracep->declBit(c+1155,"auto_in_penable", false,-1);
    tracep->declBit(c+116,"auto_in_pwrite", false,-1);
    tracep->declBus(c+124,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1187,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1195,"auto_in_pready", false,-1);
    tracep->declBit(c+1196,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1197,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1127,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1128,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1129,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1130,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1131,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1132,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1133,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1134,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1135,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1136,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+146,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+125,"in_psel", false,-1);
    tracep->declBit(c+1155,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1195,"in_pready", false,-1);
    tracep->declBus(c+1197,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1196,"in_pslverr", false,-1);
    tracep->declBus(c+1127,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1128,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1129,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1130,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1131,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1132,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1133,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1134,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1135,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1136,"gpio_seg_7", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+123,"auto_in_psel", false,-1);
    tracep->declBit(c+1154,"auto_in_penable", false,-1);
    tracep->declBit(c+116,"auto_in_pwrite", false,-1);
    tracep->declBus(c+124,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1187,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1192,"auto_in_pready", false,-1);
    tracep->declBit(c+1193,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1194,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1137,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1138,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+146,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+123,"in_psel", false,-1);
    tracep->declBit(c+1154,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1192,"in_pready", false,-1);
    tracep->declBus(c+1194,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1193,"in_pslverr", false,-1);
    tracep->declBit(c+1137,"ps2_clk", false,-1);
    tracep->declBit(c+1138,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+1165,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1166,"auto_in_wvalid", false,-1);
    tracep->declBit(c+387,"auto_in_arready", false,-1);
    tracep->declBit(c+1167,"auto_in_arvalid", false,-1);
    tracep->declBus(c+317,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1062,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1168,"auto_in_rready", false,-1);
    tracep->declBit(c+388,"auto_in_rvalid", false,-1);
    tracep->declBus(c+389,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+390,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+388,"state", false,-1);
    tracep->declBus(c+390,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+389,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1124,"raddr", false,-1, 31,0);
    tracep->declBit(c+147,"ren", false,-1);
    tracep->declBus(c+148,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+126,"auto_in_psel", false,-1);
    tracep->declBit(c+1156,"auto_in_penable", false,-1);
    tracep->declBit(c+116,"auto_in_pwrite", false,-1);
    tracep->declBus(c+114,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1187,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1157,"auto_in_pready", false,-1);
    tracep->declBit(c+1188,"auto_in_pslverr", false,-1);
    tracep->declBus(c+314,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1149,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+1150,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+179,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+114,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+126,"in_psel", false,-1);
    tracep->declBit(c+1156,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1157,"in_pready", false,-1);
    tracep->declBus(c+314,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1188,"in_pslverr", false,-1);
    tracep->declBit(c+1149,"qspi_sck", false,-1);
    tracep->declBit(c+1150,"qspi_ce_n", false,-1);
    tracep->declBus(c+179,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+179,"din", false,-1, 3,0);
    tracep->declBus(c+293,"dout", false,-1, 3,0);
    tracep->declBus(c+294,"douten", false,-1, 3,0);
    tracep->declBit(c+1176,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1125,"clk_i", false,-1);
    tracep->declBit(c+1126,"rst_i", false,-1);
    tracep->declBus(c+114,"adr_i", false,-1, 31,0);
    tracep->declBus(c+117,"dat_i", false,-1, 31,0);
    tracep->declBus(c+314,"dat_o", false,-1, 31,0);
    tracep->declBus(c+118,"sel_i", false,-1, 3,0);
    tracep->declBit(c+126,"cyc_i", false,-1);
    tracep->declBit(c+126,"stb_i", false,-1);
    tracep->declBit(c+1176,"ack_o", false,-1);
    tracep->declBit(c+116,"we_i", false,-1);
    tracep->declBit(c+1149,"sck", false,-1);
    tracep->declBit(c+1150,"ce_n", false,-1);
    tracep->declBus(c+179,"din", false,-1, 3,0);
    tracep->declBus(c+293,"dout", false,-1, 3,0);
    tracep->declBus(c+294,"douten", false,-1, 3,0);
    tracep->declBus(c+1245,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1246,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+640,"mr_sck", false,-1);
    tracep->declBit(c+641,"mr_ce_n", false,-1);
    tracep->declBus(c+179,"mr_din", false,-1, 3,0);
    tracep->declBus(c+642,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+643,"mr_doe", false,-1);
    tracep->declBit(c+644,"mw_sck", false,-1);
    tracep->declBit(c+645,"mw_ce_n", false,-1);
    tracep->declBus(c+179,"mw_din", false,-1, 3,0);
    tracep->declBus(c+295,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+646,"mw_doe", false,-1);
    tracep->declBit(c+296,"mr_rd", false,-1);
    tracep->declBit(c+647,"mr_done", false,-1);
    tracep->declBit(c+297,"mw_wr", false,-1);
    tracep->declBit(c+298,"mw_done", false,-1);
    tracep->declBit(c+126,"wb_valid", false,-1);
    tracep->declBit(c+149,"wb_we", false,-1);
    tracep->declBit(c+150,"wb_re", false,-1);
    tracep->declBit(c+648,"state", false,-1);
    tracep->declBit(c+299,"nstate", false,-1);
    tracep->declBus(c+151,"size", false,-1, 2,0);
    tracep->declBus(c+152,"byte0", false,-1, 7,0);
    tracep->declBus(c+153,"byte1", false,-1, 7,0);
    tracep->declBus(c+154,"byte2", false,-1, 7,0);
    tracep->declBus(c+155,"byte3", false,-1, 7,0);
    tracep->declBus(c+156,"wdata", false,-1, 31,0);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1177,"rst_n", false,-1);
    tracep->declBus(c+157,"addr", false,-1, 23,0);
    tracep->declBit(c+296,"rd", false,-1);
    tracep->declBus(c+1247,"size", false,-1, 2,0);
    tracep->declBit(c+647,"done", false,-1);
    tracep->declBus(c+314,"line", false,-1, 31,0);
    tracep->declBit(c+640,"sck", false,-1);
    tracep->declBit(c+641,"ce_n", false,-1);
    tracep->declBus(c+179,"din", false,-1, 3,0);
    tracep->declBus(c+642,"dout", false,-1, 3,0);
    tracep->declBit(c+643,"douten", false,-1);
    tracep->declBus(c+1245,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1246,"READ", false,-1, 0,0);
    tracep->declBus(c+1248,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+649,"state", false,-1);
    tracep->declBit(c+300,"nstate", false,-1);
    tracep->declBus(c+650,"counter", false,-1, 7,0);
    tracep->declBus(c+651,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+587+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1249,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+652,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1177,"rst_n", false,-1);
    tracep->declBus(c+158,"addr", false,-1, 23,0);
    tracep->declBus(c+156,"line", false,-1, 31,0);
    tracep->declBus(c+151,"size", false,-1, 2,0);
    tracep->declBit(c+297,"wr", false,-1);
    tracep->declBit(c+298,"done", false,-1);
    tracep->declBit(c+644,"sck", false,-1);
    tracep->declBit(c+645,"ce_n", false,-1);
    tracep->declBus(c+179,"din", false,-1, 3,0);
    tracep->declBus(c+295,"dout", false,-1, 3,0);
    tracep->declBit(c+646,"douten", false,-1);
    tracep->declBus(c+1245,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1246,"WRITE", false,-1, 0,0);
    tracep->declBus(c+159,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+653,"state", false,-1);
    tracep->declBit(c+301,"nstate", false,-1);
    tracep->declBus(c+654,"counter", false,-1, 7,0);
    tracep->declBus(c+655,"saddr", false,-1, 23,0);
    tracep->declBus(c+1250,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+120,"auto_in_psel", false,-1);
    tracep->declBit(c+1152,"auto_in_penable", false,-1);
    tracep->declBit(c+116,"auto_in_pwrite", false,-1);
    tracep->declBus(c+114,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1187,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+636,"auto_in_pready", false,-1);
    tracep->declBit(c+1188,"auto_in_pslverr", false,-1);
    tracep->declBus(c+637,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1151,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+627,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+628,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+629,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+630,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+631,"sdram_bundle_we", false,-1);
    tracep->declBus(c+632,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+633,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+634,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+635,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+114,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+120,"in_psel", false,-1);
    tracep->declBit(c+1152,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+636,"in_pready", false,-1);
    tracep->declBus(c+637,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1188,"in_pslverr", false,-1);
    tracep->declBit(c+1151,"sdram_clk", false,-1);
    tracep->declBit(c+627,"sdram_cke", false,-1);
    tracep->declBit(c+628,"sdram_cs", false,-1);
    tracep->declBit(c+629,"sdram_ras", false,-1);
    tracep->declBit(c+630,"sdram_cas", false,-1);
    tracep->declBit(c+631,"sdram_we", false,-1);
    tracep->declBus(c+632,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+633,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+634,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+635,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+656,"sdram_dout_en", false,-1);
    tracep->declBus(c+657,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+591,"state", false,-1, 1,0);
    tracep->declBit(c+658,"req_accept", false,-1);
    tracep->declBit(c+160,"is_read", false,-1);
    tracep->declBit(c+161,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1125,"clk_i", false,-1);
    tracep->declBit(c+1126,"rst_i", false,-1);
    tracep->declBus(c+162,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+160,"inport_rd_i", false,-1);
    tracep->declBus(c+1202,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+114,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+117,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+635,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+658,"inport_accept_o", false,-1);
    tracep->declBit(c+636,"inport_ack_o", false,-1);
    tracep->declBit(c+1188,"inport_error_o", false,-1);
    tracep->declBus(c+637,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1151,"sdram_clk_o", false,-1);
    tracep->declBit(c+627,"sdram_cke_o", false,-1);
    tracep->declBit(c+628,"sdram_cs_o", false,-1);
    tracep->declBit(c+629,"sdram_ras_o", false,-1);
    tracep->declBit(c+630,"sdram_cas_o", false,-1);
    tracep->declBit(c+631,"sdram_we_o", false,-1);
    tracep->declBus(c+634,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+632,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+633,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+657,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+656,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1251,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1252,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1253,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1220,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1220,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1220,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1228,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1254,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1255,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1256,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1257,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1228,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1258,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1259,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1260,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1261,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1262,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1263,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1238,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1207,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1264,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1228,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1207,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1238,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1263,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1259,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1261,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1260,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1262,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1258,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1265,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1266,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1267,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1267,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1235,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1267,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1220,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1220,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1244,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+114,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+162,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+160,"ram_rd_w", false,-1);
    tracep->declBit(c+658,"ram_accept_w", false,-1);
    tracep->declBus(c+117,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+637,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+636,"ram_ack_w", false,-1);
    tracep->declBit(c+163,"ram_req_w", false,-1);
    tracep->declBus(c+659,"command_q", false,-1, 3,0);
    tracep->declBus(c+632,"addr_q", false,-1, 12,0);
    tracep->declBus(c+657,"data_q", false,-1, 15,0);
    tracep->declBit(c+660,"data_rd_en_q", false,-1);
    tracep->declBus(c+634,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+627,"cke_q", false,-1);
    tracep->declBus(c+633,"bank_q", false,-1, 1,0);
    tracep->declBus(c+661,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+662,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+635,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+663,"refresh_q", false,-1);
    tracep->declBus(c+664,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+665+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+669,"state_q", false,-1, 3,0);
    tracep->declBus(c+302,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+303,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+670,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+671,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+164,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+165,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+166,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1228,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+672,"delay_q", false,-1, 3,0);
    tracep->declBus(c+304,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1268,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+673,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+674,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+675,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+676,"idx", false,-1, 31,0);
    tracep->declBus(c+677,"rd_q", false,-1, 3,0);
    tracep->declBit(c+636,"ack_q", false,-1);
    tracep->declArray(c+678,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+130,"auto_in_psel", false,-1);
    tracep->declBit(c+131,"auto_in_penable", false,-1);
    tracep->declBit(c+116,"auto_in_pwrite", false,-1);
    tracep->declBus(c+122,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1187,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+638,"auto_in_pready", false,-1);
    tracep->declBit(c+1188,"auto_in_pslverr", false,-1);
    tracep->declBus(c+639,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+625,"spi_bundle_sck", false,-1);
    tracep->declBus(c+626,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1147,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1148,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1269,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1270,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1234,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+167,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+130,"in_psel", false,-1);
    tracep->declBit(c+131,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+638,"in_pready", false,-1);
    tracep->declBus(c+639,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1188,"in_pslverr", false,-1);
    tracep->declBit(c+625,"spi_sck", false,-1);
    tracep->declBus(c+626,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1147,"spi_mosi", false,-1);
    tracep->declBit(c+1148,"spi_miso", false,-1);
    tracep->declBit(c+681,"spi_irq_out", false,-1);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1222,"Tp", false,-1, 31,0);
    tracep->declBit(c+1125,"wb_clk_i", false,-1);
    tracep->declBit(c+1126,"wb_rst_i", false,-1);
    tracep->declBus(c+168,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+117,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+639,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+118,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+116,"wb_we_i", false,-1);
    tracep->declBit(c+130,"wb_stb_i", false,-1);
    tracep->declBit(c+131,"wb_cyc_i", false,-1);
    tracep->declBit(c+638,"wb_ack_o", false,-1);
    tracep->declBit(c+1188,"wb_err_o", false,-1);
    tracep->declBit(c+681,"wb_int_o", false,-1);
    tracep->declBus(c+626,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+625,"sclk_pad_o", false,-1);
    tracep->declBit(c+1147,"mosi_pad_o", false,-1);
    tracep->declBit(c+1148,"miso_pad_i", false,-1);
    tracep->declBus(c+682,"divider", false,-1, 15,0);
    tracep->declBus(c+683,"ctrl", false,-1, 13,0);
    tracep->declBus(c+684,"ss", false,-1, 7,0);
    tracep->declBus(c+305,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+685,"rx", false,-1, 127,0);
    tracep->declBit(c+689,"rx_negedge", false,-1);
    tracep->declBit(c+690,"tx_negedge", false,-1);
    tracep->declBus(c+691,"char_len", false,-1, 6,0);
    tracep->declBit(c+692,"go", false,-1);
    tracep->declBit(c+693,"lsb", false,-1);
    tracep->declBit(c+694,"ie", false,-1);
    tracep->declBit(c+695,"ass", false,-1);
    tracep->declBit(c+169,"spi_divider_sel", false,-1);
    tracep->declBit(c+170,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+171,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+172,"spi_ss_sel", false,-1);
    tracep->declBit(c+696,"tip", false,-1);
    tracep->declBit(c+697,"pos_edge", false,-1);
    tracep->declBit(c+698,"neg_edge", false,-1);
    tracep->declBit(c+699,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1222,"Tp", false,-1, 31,0);
    tracep->declBit(c+1125,"clk_in", false,-1);
    tracep->declBit(c+1126,"rst", false,-1);
    tracep->declBit(c+696,"enable", false,-1);
    tracep->declBit(c+692,"go", false,-1);
    tracep->declBit(c+699,"last_clk", false,-1);
    tracep->declBus(c+682,"divider", false,-1, 15,0);
    tracep->declBit(c+625,"clk_out", false,-1);
    tracep->declBit(c+697,"pos_edge", false,-1);
    tracep->declBit(c+698,"neg_edge", false,-1);
    tracep->declBus(c+700,"cnt", false,-1, 15,0);
    tracep->declBit(c+701,"cnt_zero", false,-1);
    tracep->declBit(c+702,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1222,"Tp", false,-1, 31,0);
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1126,"rst", false,-1);
    tracep->declBus(c+173,"latch", false,-1, 3,0);
    tracep->declBus(c+118,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+691,"len", false,-1, 6,0);
    tracep->declBit(c+693,"lsb", false,-1);
    tracep->declBit(c+692,"go", false,-1);
    tracep->declBit(c+697,"pos_edge", false,-1);
    tracep->declBit(c+698,"neg_edge", false,-1);
    tracep->declBit(c+689,"rx_negedge", false,-1);
    tracep->declBit(c+690,"tx_negedge", false,-1);
    tracep->declBit(c+696,"tip", false,-1);
    tracep->declBit(c+699,"last", false,-1);
    tracep->declBus(c+117,"p_in", false,-1, 31,0);
    tracep->declArray(c+685,"p_out", false,-1, 127,0);
    tracep->declBit(c+625,"s_clk", false,-1);
    tracep->declBit(c+1148,"s_in", false,-1);
    tracep->declBit(c+1147,"s_out", false,-1);
    tracep->declBus(c+703,"cnt", false,-1, 7,0);
    tracep->declArray(c+685,"data", false,-1, 127,0);
    tracep->declBus(c+704,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+705,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+706,"rx_clk", false,-1);
    tracep->declBit(c+707,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+127,"auto_in_psel", false,-1);
    tracep->declBit(c+128,"auto_in_penable", false,-1);
    tracep->declBit(c+116,"auto_in_pwrite", false,-1);
    tracep->declBus(c+124,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1187,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+129,"auto_in_pready", false,-1);
    tracep->declBit(c+1188,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1158,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1145,"uart_rx", false,-1);
    tracep->declBit(c+1146,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+127,"in_psel", false,-1);
    tracep->declBit(c+128,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pready", false,-1);
    tracep->declBit(c+1188,"in_pslverr", false,-1);
    tracep->declBus(c+146,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+1158,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1145,"uart_rx", false,-1);
    tracep->declBit(c+1146,"uart_tx", false,-1);
    tracep->declBit(c+708,"rtsn", false,-1);
    tracep->declBit(c+1188,"ctsn", false,-1);
    tracep->declBit(c+709,"dtr_pad_o", false,-1);
    tracep->declBit(c+1188,"dsr_pad_i", false,-1);
    tracep->declBit(c+1188,"ri_pad_i", false,-1);
    tracep->declBit(c+1188,"dcd_pad_i", false,-1);
    tracep->declBit(c+710,"interrupt", false,-1);
    tracep->declBit(c+174,"reg_we", false,-1);
    tracep->declBit(c+175,"reg_re", false,-1);
    tracep->declBus(c+176,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+177,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+592,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+306,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+711,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1126,"wb_rst_i", false,-1);
    tracep->declBus(c+176,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+178,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+306,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+174,"wb_we_i", false,-1);
    tracep->declBit(c+175,"wb_re_i", false,-1);
    tracep->declBit(c+1146,"stx_pad_o", false,-1);
    tracep->declBit(c+1145,"srx_pad_i", false,-1);
    tracep->declBus(c+1265,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+711,"rts_pad_o", false,-1);
    tracep->declBit(c+709,"dtr_pad_o", false,-1);
    tracep->declBit(c+710,"int_o", false,-1);
    tracep->declBit(c+712,"enable", false,-1);
    tracep->declBit(c+713,"srx_pad", false,-1);
    tracep->declBus(c+714,"ier", false,-1, 3,0);
    tracep->declBus(c+715,"iir", false,-1, 3,0);
    tracep->declBus(c+716,"fcr", false,-1, 1,0);
    tracep->declBus(c+717,"mcr", false,-1, 4,0);
    tracep->declBus(c+718,"lcr", false,-1, 7,0);
    tracep->declBus(c+719,"msr", false,-1, 7,0);
    tracep->declBus(c+720,"dl", false,-1, 15,0);
    tracep->declBus(c+721,"scratch", false,-1, 7,0);
    tracep->declBit(c+722,"start_dlc", false,-1);
    tracep->declBit(c+723,"lsr_mask_d", false,-1);
    tracep->declBit(c+724,"msi_reset", false,-1);
    tracep->declBus(c+725,"dlc", false,-1, 15,0);
    tracep->declBus(c+726,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+727,"rx_reset", false,-1);
    tracep->declBit(c+728,"tx_reset", false,-1);
    tracep->declBit(c+729,"dlab", false,-1);
    tracep->declBit(c+1204,"cts_pad_i", false,-1);
    tracep->declBit(c+1188,"dsr_pad_i", false,-1);
    tracep->declBit(c+1188,"ri_pad_i", false,-1);
    tracep->declBit(c+1188,"dcd_pad_i", false,-1);
    tracep->declBit(c+730,"loopback", false,-1);
    tracep->declBit(c+1188,"cts", false,-1);
    tracep->declBit(c+1204,"dsr", false,-1);
    tracep->declBit(c+1204,"ri", false,-1);
    tracep->declBit(c+1204,"dcd", false,-1);
    tracep->declBit(c+731,"cts_c", false,-1);
    tracep->declBit(c+732,"dsr_c", false,-1);
    tracep->declBit(c+733,"ri_c", false,-1);
    tracep->declBit(c+734,"dcd_c", false,-1);
    tracep->declBus(c+735,"lsr", false,-1, 7,0);
    tracep->declBit(c+736,"lsr0", false,-1);
    tracep->declBit(c+737,"lsr1", false,-1);
    tracep->declBit(c+738,"lsr2", false,-1);
    tracep->declBit(c+739,"lsr3", false,-1);
    tracep->declBit(c+740,"lsr4", false,-1);
    tracep->declBit(c+741,"lsr5", false,-1);
    tracep->declBit(c+742,"lsr6", false,-1);
    tracep->declBit(c+743,"lsr7", false,-1);
    tracep->declBit(c+744,"lsr0r", false,-1);
    tracep->declBit(c+745,"lsr1r", false,-1);
    tracep->declBit(c+746,"lsr2r", false,-1);
    tracep->declBit(c+747,"lsr3r", false,-1);
    tracep->declBit(c+748,"lsr4r", false,-1);
    tracep->declBit(c+749,"lsr5r", false,-1);
    tracep->declBit(c+750,"lsr6r", false,-1);
    tracep->declBit(c+751,"lsr7r", false,-1);
    tracep->declBit(c+307,"lsr_mask", false,-1);
    tracep->declBit(c+752,"rls_int", false,-1);
    tracep->declBit(c+753,"rda_int", false,-1);
    tracep->declBit(c+754,"ti_int", false,-1);
    tracep->declBit(c+755,"thre_int", false,-1);
    tracep->declBit(c+756,"ms_int", false,-1);
    tracep->declBit(c+757,"tf_push", false,-1);
    tracep->declBit(c+758,"rf_pop", false,-1);
    tracep->declBus(c+1178,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+759,"rf_error_bit", false,-1);
    tracep->declBit(c+737,"rf_overrun", false,-1);
    tracep->declBit(c+760,"rf_push_pulse", false,-1);
    tracep->declBus(c+761,"rf_count", false,-1, 4,0);
    tracep->declBus(c+762,"tf_count", false,-1, 4,0);
    tracep->declBus(c+763,"tstate", false,-1, 2,0);
    tracep->declBus(c+764,"rstate", false,-1, 3,0);
    tracep->declBus(c+765,"counter_t", false,-1, 9,0);
    tracep->declBit(c+766,"thre_set_en", false,-1);
    tracep->declBus(c+767,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+768,"block_value", false,-1, 7,0);
    tracep->declBit(c+769,"serial_out", false,-1);
    tracep->declBit(c+770,"serial_in", false,-1);
    tracep->declBit(c+308,"lsr_mask_condition", false,-1);
    tracep->declBit(c+309,"iir_read", false,-1);
    tracep->declBit(c+310,"msr_read", false,-1);
    tracep->declBit(c+311,"fifo_read", false,-1);
    tracep->declBit(c+312,"fifo_write", false,-1);
    tracep->declBus(c+771,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+772,"lsr0_d", false,-1);
    tracep->declBit(c+773,"lsr1_d", false,-1);
    tracep->declBit(c+774,"lsr2_d", false,-1);
    tracep->declBit(c+775,"lsr3_d", false,-1);
    tracep->declBit(c+776,"lsr4_d", false,-1);
    tracep->declBit(c+777,"lsr5_d", false,-1);
    tracep->declBit(c+778,"lsr6_d", false,-1);
    tracep->declBit(c+779,"lsr7_d", false,-1);
    tracep->declBit(c+780,"rls_int_d", false,-1);
    tracep->declBit(c+781,"thre_int_d", false,-1);
    tracep->declBit(c+782,"ms_int_d", false,-1);
    tracep->declBit(c+783,"ti_int_d", false,-1);
    tracep->declBit(c+784,"rda_int_d", false,-1);
    tracep->declBit(c+785,"rls_int_rise", false,-1);
    tracep->declBit(c+786,"thre_int_rise", false,-1);
    tracep->declBit(c+787,"ms_int_rise", false,-1);
    tracep->declBit(c+788,"ti_int_rise", false,-1);
    tracep->declBit(c+789,"rda_int_rise", false,-1);
    tracep->declBit(c+790,"rls_int_pnd", false,-1);
    tracep->declBit(c+791,"rda_int_pnd", false,-1);
    tracep->declBit(c+792,"thre_int_pnd", false,-1);
    tracep->declBit(c+793,"ms_int_pnd", false,-1);
    tracep->declBit(c+794,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1222,"Tp", false,-1, 31,0);
    tracep->declBus(c+1222,"width", false,-1, 31,0);
    tracep->declBus(c+1246,"init_value", false,-1, 0,0);
    tracep->declBit(c+1126,"rst_i", false,-1);
    tracep->declBit(c+1125,"clk_i", false,-1);
    tracep->declBit(c+1188,"stage1_rst_i", false,-1);
    tracep->declBit(c+1204,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1145,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+713,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+795,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1126,"wb_rst_i", false,-1);
    tracep->declBus(c+718,"lcr", false,-1, 7,0);
    tracep->declBit(c+758,"rf_pop", false,-1);
    tracep->declBit(c+770,"srx_pad_i", false,-1);
    tracep->declBit(c+712,"enable", false,-1);
    tracep->declBit(c+727,"rx_reset", false,-1);
    tracep->declBit(c+307,"lsr_mask", false,-1);
    tracep->declBus(c+765,"counter_t", false,-1, 9,0);
    tracep->declBus(c+761,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1178,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+737,"rf_overrun", false,-1);
    tracep->declBit(c+759,"rf_error_bit", false,-1);
    tracep->declBus(c+764,"rstate", false,-1, 3,0);
    tracep->declBit(c+760,"rf_push_pulse", false,-1);
    tracep->declBus(c+796,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+797,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+798,"rshift", false,-1, 7,0);
    tracep->declBit(c+799,"rparity", false,-1);
    tracep->declBit(c+800,"rparity_error", false,-1);
    tracep->declBit(c+801,"rframing_error", false,-1);
    tracep->declBit(c+802,"rbit_in", false,-1);
    tracep->declBit(c+803,"rparity_xor", false,-1);
    tracep->declBus(c+804,"counter_b", false,-1, 7,0);
    tracep->declBit(c+805,"rf_push_q", false,-1);
    tracep->declBus(c+806,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+807,"rf_push", false,-1);
    tracep->declBit(c+808,"break_error", false,-1);
    tracep->declBit(c+809,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+810,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+811,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+812,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1207,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1238,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1263,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1259,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1261,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1260,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1262,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1258,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1265,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1266,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1271,"sr_push", false,-1, 3,0);
    tracep->declBus(c+813,"toc_value", false,-1, 9,0);
    tracep->declBus(c+814,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1272,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1235,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1228,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1241,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1126,"wb_rst_i", false,-1);
    tracep->declBit(c+760,"push", false,-1);
    tracep->declBit(c+758,"pop", false,-1);
    tracep->declBus(c+806,"data_in", false,-1, 10,0);
    tracep->declBit(c+727,"fifo_reset", false,-1);
    tracep->declBit(c+307,"reset_status", false,-1);
    tracep->declBus(c+1178,"data_out", false,-1, 10,0);
    tracep->declBit(c+737,"overrun", false,-1);
    tracep->declBus(c+761,"count", false,-1, 4,0);
    tracep->declBit(c+759,"error_bit", false,-1);
    tracep->declBus(c+1179,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+815+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+831,"top", false,-1, 3,0);
    tracep->declBus(c+832,"bottom", false,-1, 3,0);
    tracep->declBus(c+833,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+834,"word0", false,-1, 2,0);
    tracep->declBus(c+835,"word1", false,-1, 2,0);
    tracep->declBus(c+836,"word2", false,-1, 2,0);
    tracep->declBus(c+837,"word3", false,-1, 2,0);
    tracep->declBus(c+838,"word4", false,-1, 2,0);
    tracep->declBus(c+839,"word5", false,-1, 2,0);
    tracep->declBus(c+840,"word6", false,-1, 2,0);
    tracep->declBus(c+841,"word7", false,-1, 2,0);
    tracep->declBus(c+842,"word8", false,-1, 2,0);
    tracep->declBus(c+843,"word9", false,-1, 2,0);
    tracep->declBus(c+844,"word10", false,-1, 2,0);
    tracep->declBus(c+845,"word11", false,-1, 2,0);
    tracep->declBus(c+846,"word12", false,-1, 2,0);
    tracep->declBus(c+847,"word13", false,-1, 2,0);
    tracep->declBus(c+848,"word14", false,-1, 2,0);
    tracep->declBus(c+849,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1228,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1234,"data_width", false,-1, 31,0);
    tracep->declBus(c+1235,"depth", false,-1, 31,0);
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+760,"we", false,-1);
    tracep->declBus(c+831,"a", false,-1, 3,0);
    tracep->declBus(c+832,"dpra", false,-1, 3,0);
    tracep->declBus(c+850,"di", false,-1, 7,0);
    tracep->declBus(c+1179,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+593+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1126,"wb_rst_i", false,-1);
    tracep->declBus(c+718,"lcr", false,-1, 7,0);
    tracep->declBit(c+757,"tf_push", false,-1);
    tracep->declBus(c+178,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+712,"enable", false,-1);
    tracep->declBit(c+728,"tx_reset", false,-1);
    tracep->declBit(c+307,"lsr_mask", false,-1);
    tracep->declBit(c+769,"stx_pad_o", false,-1);
    tracep->declBus(c+763,"tstate", false,-1, 2,0);
    tracep->declBus(c+762,"tf_count", false,-1, 4,0);
    tracep->declBus(c+851,"counter", false,-1, 4,0);
    tracep->declBus(c+852,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+853,"shift_out", false,-1, 6,0);
    tracep->declBit(c+854,"stx_o_tmp", false,-1);
    tracep->declBit(c+855,"parity_xor", false,-1);
    tracep->declBit(c+856,"tf_pop", false,-1);
    tracep->declBit(c+857,"bit_out", false,-1);
    tracep->declBus(c+178,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1180,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+858,"tf_overrun", false,-1);
    tracep->declBus(c+1208,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1187,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1273,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1274,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1247,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1275,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1234,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1235,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1228,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1241,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+1126,"wb_rst_i", false,-1);
    tracep->declBit(c+757,"push", false,-1);
    tracep->declBit(c+856,"pop", false,-1);
    tracep->declBus(c+178,"data_in", false,-1, 7,0);
    tracep->declBit(c+728,"fifo_reset", false,-1);
    tracep->declBit(c+307,"reset_status", false,-1);
    tracep->declBus(c+1180,"data_out", false,-1, 7,0);
    tracep->declBit(c+858,"overrun", false,-1);
    tracep->declBus(c+762,"count", false,-1, 4,0);
    tracep->declBus(c+859,"top", false,-1, 3,0);
    tracep->declBus(c+860,"bottom", false,-1, 3,0);
    tracep->declBus(c+861,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1228,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1234,"data_width", false,-1, 31,0);
    tracep->declBus(c+1235,"depth", false,-1, 31,0);
    tracep->declBit(c+1125,"clk", false,-1);
    tracep->declBit(c+757,"we", false,-1);
    tracep->declBus(c+859,"a", false,-1, 3,0);
    tracep->declBus(c+860,"dpra", false,-1, 3,0);
    tracep->declBus(c+178,"di", false,-1, 7,0);
    tracep->declBus(c+1180,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+609+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBit(c+121,"auto_in_psel", false,-1);
    tracep->declBit(c+1153,"auto_in_penable", false,-1);
    tracep->declBit(c+116,"auto_in_pwrite", false,-1);
    tracep->declBus(c+122,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1187,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+117,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"auto_in_pready", false,-1);
    tracep->declBit(c+1190,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1191,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1139,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1140,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1141,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1142,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1143,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1144,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1125,"clock", false,-1);
    tracep->declBit(c+1126,"reset", false,-1);
    tracep->declBus(c+167,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+121,"in_psel", false,-1);
    tracep->declBit(c+1153,"in_penable", false,-1);
    tracep->declBus(c+1187,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+116,"in_pwrite", false,-1);
    tracep->declBus(c+117,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+118,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1189,"in_pready", false,-1);
    tracep->declBus(c+1191,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1190,"in_pslverr", false,-1);
    tracep->declBus(c+1139,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1140,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1141,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1142,"vga_hsync", false,-1);
    tracep->declBit(c+1143,"vga_vsync", false,-1);
    tracep->declBit(c+1144,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+625,"sck", false,-1);
    tracep->declBit(c+1181,"ss", false,-1);
    tracep->declBit(c+1147,"mosi", false,-1);
    tracep->declBit(c+1182,"miso", false,-1);
    tracep->declBus(c+946,"buffer", false,-1, 7,0);
    tracep->declBus(c+947,"count", false,-1, 2,0);
    tracep->declBus(c+948,"state", false,-1, 1,0);
    tracep->declBit(c+949,"buffer_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+625,"sck", false,-1);
    tracep->declBit(c+862,"ss", false,-1);
    tracep->declBit(c+1147,"mosi", false,-1);
    tracep->declBit(c+1183,"miso", false,-1);
    tracep->declBit(c+862,"reset", false,-1);
    tracep->declBus(c+940,"state", false,-1, 2,0);
    tracep->declBus(c+941,"counter", false,-1, 7,0);
    tracep->declBus(c+942,"cmd", false,-1, 7,0);
    tracep->declBus(c+943,"addr", false,-1, 23,0);
    tracep->declBus(c+944,"data", false,-1, 31,0);
    tracep->declBit(c+945,"ren", false,-1);
    tracep->declBus(c+1184,"rdata", false,-1, 31,0);
    tracep->declBus(c+1185,"raddr", false,-1, 31,0);
    tracep->declBus(c+1186,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+625,"clock", false,-1);
    tracep->declBit(c+945,"valid", false,-1);
    tracep->declBus(c+942,"cmd", false,-1, 7,0);
    tracep->declBus(c+1185,"addr", false,-1, 31,0);
    tracep->declBus(c+1184,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+1149,"sck", false,-1);
    tracep->declBit(c+1150,"ce_n", false,-1);
    tracep->declBus(c+179,"dio", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1151,"clk", false,-1);
    tracep->declBit(c+627,"cke", false,-1);
    tracep->declBit(c+628,"cs", false,-1);
    tracep->declBit(c+629,"ras", false,-1);
    tracep->declBit(c+630,"cas", false,-1);
    tracep->declBit(c+631,"we", false,-1);
    tracep->declBus(c+632,"a", false,-1, 12,0);
    tracep->declBus(c+633,"ba", false,-1, 1,0);
    tracep->declBus(c+634,"dqm", false,-1, 1,0);
    tracep->declBus(c+635,"dq", false,-1, 15,0);
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
    bufp->fullCData(oldp+28,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[0]),5);
    bufp->fullCData(oldp+29,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[1]),5);
    bufp->fullCData(oldp+30,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[2]),5);
    bufp->fullCData(oldp+31,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+32,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+33,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+34,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+35,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+36,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+37,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+38,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+39,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+40,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[3]),2);
    bufp->fullIData(oldp+41,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                           : 0U) | 
                                         ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                           : 0U)))),32);
    bufp->fullBit(oldp+42,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+43,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+44,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+45,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+46,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+47,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+48,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+49,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+50,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+51,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+52,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+53,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+54,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+55,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+56,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+57,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+58,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+60,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+62,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+63,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+65,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+66,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+69,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+70,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+71,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+72,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+73,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+74,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+75,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+76,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+77,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+78,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+79,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+80,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+81,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+82,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+83,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+84,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+85,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+86,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+87,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+89,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+91,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+93,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+94,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+95,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+97,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+112,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+115,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+118,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+119,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+120,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+121,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+122,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+123,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+124,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+125,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+129,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_psel));
    bufp->fullBit(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_0_penable));
    bufp->fullBit(oldp+132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+133,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+134,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+135,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+136,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+137,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+138,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+143,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+144,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+146,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+149,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+152,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+153,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+154,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+155,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+156,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+157,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+158,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+159,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+164,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+165,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+166,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+167,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullCData(oldp+168,((0x1fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),5);
    bufp->fullBit(oldp+169,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullBit(oldp+170,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+171,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
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
    bufp->fullBit(oldp+172,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)))));
    bufp->fullCData(oldp+173,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+174,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+175,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+176,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullCData(oldp+179,((((((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out0) 
                                         & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten))) 
                                  | (0xcU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__qspi_dio__out__strong__out1) 
                                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten)))) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0)) 
                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__qspi_dio__en0))),4);
    bufp->fullBit(oldp+180,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+181,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+182,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+184,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+186,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+190,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+210,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+222,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+226,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+230,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+232,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+234,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+235,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+236,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+237,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+238,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+239,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+240,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+241,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+242,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+243,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+244,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+245,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+246,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+247,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+248,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+249,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+250,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+251,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+252,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+253,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+254,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+255,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+256,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+257,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+258,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+259,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+260,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+261,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+262,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+263,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+264,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+265,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+266,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+267,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+268,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+269,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+270,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+271,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+272,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+273,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+274,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+276,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+277,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+278,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+279,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+280,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+281,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                              [1U]),2);
    bufp->fullBit(oldp+282,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                   >> 1U))));
    bufp->fullIData(oldp+283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+284,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+285,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+286,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+287,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data))),32);
    bufp->fullIData(oldp+288,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data))),32);
    bufp->fullCData(oldp+289,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data),8);
    bufp->fullSData(oldp+290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data),16);
    bufp->fullIData(oldp+291,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+292,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+293,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+294,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+296,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+297,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+307,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+308,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+309,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+310,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+311,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+312,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullBit(oldp+313,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullIData(oldp+314,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+316,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+317,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+321,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+322,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+324,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+325,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+326,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+327,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+328,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+329,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+330,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+331,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+332,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+345,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+350,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+352,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+353,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+354,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+355,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+356,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+358,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+359,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+360,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+361,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+363,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+364,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullQData(oldp+365,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+367,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+368,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+369,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+371,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+372,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+373,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+374,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+375,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+377,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+378,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+379,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+382,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+383,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+384,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+385,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+386,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+387,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+391,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+401,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+405,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+433,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+442,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+443,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+444,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+447,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+451,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+452,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+454,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+455,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+456,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+457,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+459,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+461,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+462,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+463,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+464,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+467,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+468,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+471,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+472,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+475,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+479,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+483,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+484,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+486,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+487,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+488,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+491,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+492,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+494,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+495,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+496,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+498,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+499,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+501,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+502,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+503,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+506,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+507,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+510,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+511,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+512,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+514,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+515,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+516,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+518,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+519,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+522,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+523,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+524,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+525,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+526,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+527,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+529,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+530,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+531,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+532,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+533,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+534,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+535,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+536,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+538,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+539,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+540,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+541,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+542,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+543,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+544,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+545,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+546,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+547,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+548,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+549,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+550,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+551,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+552,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+554,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+555,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+558,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+559,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+560,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+562,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+563,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+566,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+567,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+570,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullCData(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready),2);
    bufp->fullBit(oldp+572,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+573,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+574,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+575,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready) 
                                   >> 1U))));
    bufp->fullCData(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state),2);
    bufp->fullBit(oldp+577,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+582,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+590,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullCData(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+594,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+598,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+602,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+606,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+613,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+614,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+615,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+617,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+618,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+621,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+622,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+623,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+624,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullBit(oldp+625,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+626,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+628,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+629,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+630,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+631,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+632,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+633,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+634,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullSData(oldp+635,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                  ? 0U : 0xffffU) & 
                                ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                    ? 0U : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q)) 
                                  & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                      ? 0U : 0xffffU)) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                     ? 0U : 0xffffU))) 
                               & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                   ? 0U : 0xffffU))),16);
    bufp->fullBit(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullIData(oldp+637,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_pready));
    bufp->fullIData(oldp+639,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+641,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+642,((0xfU & ((8U > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
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
    bufp->fullBit(oldp+643,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+644,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+646,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+647,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+649,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+651,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+652,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+653,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+655,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullBit(oldp+656,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+658,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+660,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullBit(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+666,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullCData(oldp+670,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+673,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+674,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+675,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+676,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+677,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+681,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullSData(oldp+682,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+683,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+684,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+685,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+689,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+690,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+691,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+692,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+693,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+694,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+695,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+696,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+697,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+698,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+699,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+701,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+702,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+704,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+705,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+706,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+707,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+708,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+709,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+711,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+715,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+716,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+717,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+718,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+719,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+720,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+721,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+722,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+723,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+724,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+725,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+726,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+727,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+728,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+729,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+730,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+731,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+732,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+733,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+734,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+735,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+736,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+737,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+738,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+739,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+740,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+741,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+742,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+743,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+744,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+746,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+747,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+748,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+749,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+750,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+752,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+753,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+754,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+756,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+758,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+759,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+760,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+761,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+762,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+763,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+764,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+765,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+766,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+767,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+768,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+769,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+770,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+771,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+772,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+773,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+774,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+775,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+776,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+777,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+778,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+779,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+780,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+781,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+782,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+783,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+784,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+785,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+786,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+787,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+788,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+789,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+790,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+793,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+795,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+796,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+797,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+798,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+799,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+800,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+801,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+803,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+804,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+805,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+806,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+807,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+808,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+809,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+810,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+811,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+812,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+814,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+815,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+816,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+818,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+820,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+821,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+822,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+823,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+824,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+827,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+828,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+829,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+830,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+833,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+834,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+836,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+837,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+839,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+840,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+841,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+843,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+848,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+850,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+858,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+860,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+861,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+862,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullIData(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+864,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+866,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+867,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+868,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+869,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+870,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+874,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+875,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+877,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+894,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+900,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+901,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+920,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+921,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+922,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+923,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+928,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+929,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+930,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+931,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+932,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+933,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+936,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+937,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+938,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+939,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+940,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+941,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+942,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+943,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+944,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+945,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                             & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+946,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer),8);
    bufp->fullCData(oldp+947,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count),3);
    bufp->fullCData(oldp+948,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state),2);
    bufp->fullBit(oldp+949,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                   >> (7U & ((IData)(7U) 
                                             - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))));
    bufp->fullCData(oldp+950,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+951,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__arsize_out_reg),3);
    bufp->fullBit(oldp+952,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+953,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+954,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+955,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullBit(oldp+956,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullBit(oldp+957,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+958,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+959,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+960,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+961,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+962,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+963,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+964,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+965,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                             & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                | ((0x33U == (0x7fU 
                                              & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                      | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+966,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+967,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+968,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+969,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+971,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+972,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+973,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+974,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+975,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+976,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+977,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+978,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+979,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+980,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+981,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                               << 1U)),2);
    bufp->fullCData(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+983,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+984,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                               << 1U)),2);
    bufp->fullCData(oldp+985,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullCData(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[0]),3);
    bufp->fullCData(oldp+987,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[1]),3);
    bufp->fullCData(oldp+988,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[0]),3);
    bufp->fullCData(oldp+989,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[1]),3);
    bufp->fullCData(oldp+990,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+991,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+992,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+993,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+994,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+995,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+996,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+997,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+998,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+999,(((IData)((0x6000U == 
                                        (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                ? 8U : ((1U & VL_REDXOR_16(
                                                           (0x6000U 
                                                            & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                         ? 9U : 3U))),4);
    bufp->fullCData(oldp+1000,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+1001,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1002,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+1003,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+1004,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1005,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+1006,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+1007,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+1008,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+1009,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+1010,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+1011,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 | ((0x17U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+1012,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1013,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))));
    bufp->fullCData(oldp+1014,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),3);
    bufp->fullSData(oldp+1015,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                >> 0x14U)),12);
    bufp->fullCData(oldp+1016,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),2);
    bufp->fullCData(oldp+1017,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1018,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+1019,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+1020,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    >> 1U))));
    bufp->fullCData(oldp+1021,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : 2U))),3);
    bufp->fullCData(oldp+1022,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullWData(oldp+1023,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1026,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1030,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1031,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1032,((0x11830U | ((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullCData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[0]),6);
    bufp->fullCData(oldp+1034,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[1]),6);
    bufp->fullCData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[2]),6);
    bufp->fullCData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[3]),6);
    bufp->fullCData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[0]),4);
    bufp->fullCData(oldp+1038,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[1]),4);
    bufp->fullCData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[2]),4);
    bufp->fullCData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[3]),4);
    bufp->fullIData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullCData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullIData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullCData(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1046,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullCData(oldp+1047,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awsize_out_reg),3);
    bufp->fullCData(oldp+1048,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullIData(oldp+1049,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullCData(oldp+1050,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullIData(oldp+1051,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1052,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1053,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1054,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1055,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullCData(oldp+1056,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullIData(oldp+1057,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1058,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1059,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1060,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1061,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1062,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1063,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1064,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1065,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1066,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1067,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
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
    bufp->fullBit(oldp+1068,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1069,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1070,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1071,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1072,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1073,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1074,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1075,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1076,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1077,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1078,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1079,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullCData(oldp+1080,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+1081,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+1082,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[0]),3);
    bufp->fullCData(oldp+1083,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[1]),3);
    bufp->fullIData(oldp+1084,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1085,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1086,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1087,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1088,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1089,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullCData(oldp+1090,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+1091,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+1092,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[0]),3);
    bufp->fullCData(oldp+1093,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[1]),3);
    bufp->fullIData(oldp+1094,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1095,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1096,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1097,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1098,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1099,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1101,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+1105,(((0x1fU >= (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                             ? (3U 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                             : 0U) 
                                           << 3U)) ? 
                                (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                       ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                       : 0U) << 3U))
                                 : 0U)),32);
    bufp->fullCData(oldp+1106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__wstrb),4);
    bufp->fullCData(oldp+1107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awsize),3);
    bufp->fullCData(oldp+1108,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                 ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : 0U)),2);
    bufp->fullCData(oldp+1109,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),2);
    bufp->fullBit(oldp+1110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__inuart));
    bufp->fullBit(oldp+1111,(((0xf000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0xfffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1112,(((0x30000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x3fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1113,(((0x10001000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x10001fffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullCData(oldp+1114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size),2);
    bufp->fullCData(oldp+1115,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
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
    bufp->fullCData(oldp+1116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux),5);
    bufp->fullCData(oldp+1117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT____Vcellinp__type_mux__key),3);
    bufp->fullCData(oldp+1120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__lut_out),4);
    bufp->fullBit(oldp+1123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+1124,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1125,(vlSelf->clock));
    bufp->fullBit(oldp+1126,(vlSelf->reset));
    bufp->fullSData(oldp+1127,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1128,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1129,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1130,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1131,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1132,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1133,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1134,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1135,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1136,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1137,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1138,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1139,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1140,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1141,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1142,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1143,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1144,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1145,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1146,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1147,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+1148,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
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
    bufp->fullBit(oldp+1149,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck))));
    bufp->fullBit(oldp+1150,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)
                               : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n))));
    bufp->fullBit(oldp+1151,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullBit(oldp+1152,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1153,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1154,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1155,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1156,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+1157,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1158,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullCData(oldp+1159,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                 ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                    << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))),2);
    bufp->fullBit(oldp+1160,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullCData(oldp+1161,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1162,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1163,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1164,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1165,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
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
    bufp->fullBit(oldp+1166,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1167,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1168,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1169,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullIData(oldp+1170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullBit(oldp+1172,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1173,(((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1174,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state)))));
    bufp->fullBit(oldp+1175,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                     & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready)) 
                                    >> 1U))));
    bufp->fullBit(oldp+1176,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1177,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1178,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1179,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullBit(oldp+1181,(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss));
    bufp->fullBit(oldp+1182,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
                                    | ((2U != (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state)) 
                                       | ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                          >> (7U & 
                                              ((IData)(7U) 
                                               - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))))));
    bufp->fullBit(oldp+1183,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullIData(oldp+1184,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1185,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1186,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullCData(oldp+1187,(1U),3);
    bufp->fullBit(oldp+1188,(0U));
    bufp->fullBit(oldp+1189,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1190,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1191,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1192,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1193,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1194,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1195,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pready));
    bufp->fullBit(oldp+1196,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullIData(oldp+1197,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_prdata),32);
    bufp->fullCData(oldp+1198,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1199,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullBit(oldp+1200,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1201,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1202,(0U),8);
    bufp->fullCData(oldp+1203,(1U),2);
    bufp->fullBit(oldp+1204,(1U));
    bufp->fullBit(oldp+1205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1206,(0U),32);
    bufp->fullCData(oldp+1207,(0U),4);
    bufp->fullCData(oldp+1208,(0U),3);
    bufp->fullCData(oldp+1209,(0U),2);
    bufp->fullBit(oldp+1210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1220,(2U),32);
    bufp->fullIData(oldp+1221,(2U),32);
    bufp->fullIData(oldp+1222,(1U),32);
    bufp->fullIData(oldp+1223,(0x20U),32);
    bufp->fullIData(oldp+1224,(0U),32);
    bufp->fullIData(oldp+1225,(0x21U),32);
    bufp->fullIData(oldp+1226,(2U),32);
    bufp->fullIData(oldp+1227,(0x20000000U),32);
    bufp->fullIData(oldp+1228,(4U),32);
    bufp->fullIData(oldp+1229,(0xcU),32);
    bufp->fullQData(oldp+1230,(0x3000c153418d0bULL),56);
    bufp->fullIData(oldp+1232,(0xeU),32);
    bufp->fullIData(oldp+1233,(4U),32);
    bufp->fullIData(oldp+1234,(8U),32);
    bufp->fullIData(oldp+1235,(0x10U),32);
    bufp->fullIData(oldp+1236,(3U),32);
    bufp->fullIData(oldp+1237,(0x23U),32);
    bufp->fullCData(oldp+1238,(1U),4);
    bufp->fullCData(oldp+1239,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword),4);
    bufp->fullSData(oldp+1240,(0x223aU),15);
    bufp->fullIData(oldp+1241,(5U),32);
    bufp->fullIData(oldp+1242,(3U),32);
    bufp->fullSData(oldp+1243,(0x4d25U),15);
    bufp->fullIData(oldp+1244,(6U),32);
    bufp->fullBit(oldp+1245,(0U));
    bufp->fullBit(oldp+1246,(1U));
    bufp->fullCData(oldp+1247,(4U),3);
    bufp->fullCData(oldp+1248,(0x1bU),8);
    bufp->fullCData(oldp+1249,(0xebU),8);
    bufp->fullCData(oldp+1250,(0x38U),8);
    bufp->fullIData(oldp+1251,(0x64U),32);
    bufp->fullIData(oldp+1252,(0x18U),32);
    bufp->fullIData(oldp+1253,(9U),32);
    bufp->fullIData(oldp+1254,(0xdU),32);
    bufp->fullIData(oldp+1255,(0x2000U),32);
    bufp->fullIData(oldp+1256,(0x2710U),32);
    bufp->fullIData(oldp+1257,(0x30cU),32);
    bufp->fullCData(oldp+1258,(7U),4);
    bufp->fullCData(oldp+1259,(3U),4);
    bufp->fullCData(oldp+1260,(5U),4);
    bufp->fullCData(oldp+1261,(4U),4);
    bufp->fullCData(oldp+1262,(6U),4);
    bufp->fullCData(oldp+1263,(2U),4);
    bufp->fullSData(oldp+1264,(0x21U),13);
    bufp->fullCData(oldp+1265,(8U),4);
    bufp->fullCData(oldp+1266,(9U),4);
    bufp->fullIData(oldp+1267,(0xaU),32);
    bufp->fullIData(oldp+1268,(0x11U),32);
    bufp->fullIData(oldp+1269,(0x30000000U),32);
    bufp->fullIData(oldp+1270,(0x3fffffffU),32);
    bufp->fullCData(oldp+1271,(0xaU),4);
    bufp->fullIData(oldp+1272,(0xbU),32);
    bufp->fullCData(oldp+1273,(2U),3);
    bufp->fullCData(oldp+1274,(3U),3);
    bufp->fullCData(oldp+1275,(5U),3);
}
