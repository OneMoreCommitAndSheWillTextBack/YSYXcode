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
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+1262,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1263,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1264,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1265,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1266,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1267,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1268,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1269,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1270,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1271,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1272,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1273,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1274,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1275,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1276,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1277,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1278,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1279,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1280,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1281,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+1262,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1263,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1264,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1265,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1266,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1267,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1268,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1269,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1270,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1271,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1272,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1273,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1274,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1275,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1276,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1277,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1278,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1279,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1280,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1281,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+727,"spi_sck", false,-1);
    tracep->declBus(c+728,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1066,"spi_mosi", false,-1);
    tracep->declBit(c+1282,"spi_miso", false,-1);
    tracep->declBit(c+1280,"uart_rx", false,-1);
    tracep->declBit(c+1281,"uart_tx", false,-1);
    tracep->declBit(c+207,"psram_sck", false,-1);
    tracep->declBit(c+208,"psram_ce_n", false,-1);
    tracep->declBus(c+1283,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1284,"sdram_clk", false,-1);
    tracep->declBit(c+729,"sdram_cke", false,-1);
    tracep->declBit(c+730,"sdram_cs", false,-1);
    tracep->declBit(c+731,"sdram_ras", false,-1);
    tracep->declBit(c+732,"sdram_cas", false,-1);
    tracep->declBit(c+733,"sdram_we", false,-1);
    tracep->declBus(c+734,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+735,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+1067,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+1285,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1262,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1263,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1264,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1265,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1266,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1267,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1268,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1269,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1270,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1271,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1272,"ps2_clk", false,-1);
    tracep->declBit(c+1273,"ps2_data", false,-1);
    tracep->declBus(c+1274,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1275,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1276,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1277,"vga_hsync", false,-1);
    tracep->declBit(c+1278,"vga_vsync", false,-1);
    tracep->declBit(c+1279,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+127,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+128,"in_psel", false,-1);
    tracep->declBit(c+386,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+209,"in_pready", false,-1);
    tracep->declBus(c+210,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+132,"in_pslverr", false,-1);
    tracep->declBus(c+127,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+128,"out_psel", false,-1);
    tracep->declBit(c+386,"out_penable", false,-1);
    tracep->declBus(c+1322,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"out_pwrite", false,-1);
    tracep->declBus(c+130,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+209,"out_pready", false,-1);
    tracep->declBus(c+210,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+132,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+128,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+386,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+127,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1322,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+209,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+132,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+210,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+133,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+47,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+127,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1322,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+736,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1323,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+1286,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+134,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+48,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+135,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1322,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1324,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1325,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1326,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+136,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+49,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+137,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1322,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1327,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1328,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1329,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+138,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+50,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+137,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1322,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+387,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1330,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1287,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+139,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+51,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+127,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1322,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1288,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1323,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+388,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+140,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+141,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+137,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1322,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+142,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1323,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1289,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+143,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+52,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+129,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+135,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1322,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+1290,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1323,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+1291,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+144,"sel_0", false,-1);
    tracep->declBit(c+145,"sel_1", false,-1);
    tracep->declBit(c+146,"sel_2", false,-1);
    tracep->declBit(c+147,"sel_3", false,-1);
    tracep->declBit(c+148,"sel_4", false,-1);
    tracep->declBit(c+149,"sel_5", false,-1);
    tracep->declBit(c+150,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+151,"auto_in_awready", false,-1);
    tracep->declBit(c+152,"auto_in_awvalid", false,-1);
    tracep->declBus(c+389,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1172,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1173,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+151,"auto_in_wready", false,-1);
    tracep->declBit(c+153,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+211,"auto_in_bready", false,-1);
    tracep->declBit(c+212,"auto_in_bvalid", false,-1);
    tracep->declBus(c+390,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+53,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+154,"auto_in_arready", false,-1);
    tracep->declBit(c+155,"auto_in_arvalid", false,-1);
    tracep->declBus(c+391,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1176,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1079,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+213,"auto_in_rready", false,-1);
    tracep->declBit(c+214,"auto_in_rvalid", false,-1);
    tracep->declBus(c+392,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+215,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+53,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+128,"auto_out_psel", false,-1);
    tracep->declBit(c+386,"auto_out_penable", false,-1);
    tracep->declBit(c+129,"auto_out_pwrite", false,-1);
    tracep->declBus(c+127,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+130,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+209,"auto_out_pready", false,-1);
    tracep->declBit(c+132,"auto_out_pslverr", false,-1);
    tracep->declBus(c+210,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+386,"nodeOut_penable", false,-1);
    tracep->declBus(c+393,"state", false,-1, 1,0);
    tracep->declBit(c+154,"accept_read", false,-1);
    tracep->declBit(c+151,"accept_write", false,-1);
    tracep->declBit(c+394,"is_write_r", false,-1);
    tracep->declBit(c+129,"is_write", false,-1);
    tracep->declBus(c+392,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+390,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+395,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+396,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+397,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+398,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+156,"resp", false,-1, 1,0);
    tracep->declBus(c+399,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+53,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+214,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+400,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+212,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+401,"auto_in_awready", false,-1);
    tracep->declBit(c+91,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1331,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1177,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1332,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1178,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1179,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+402,"auto_in_wready", false,-1);
    tracep->declBit(c+92,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1180,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1333,"auto_in_wlast", false,-1);
    tracep->declBit(c+1292,"auto_in_bready", false,-1);
    tracep->declBit(c+216,"auto_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+403,"auto_in_arready", false,-1);
    tracep->declBit(c+93,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1334,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1182,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1335,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1080,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1336,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+94,"auto_in_rready", false,-1);
    tracep->declBit(c+219,"auto_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+55,"auto_in_rlast", false,-1);
    tracep->declBit(c+221,"auto_out_awready", false,-1);
    tracep->declBit(c+95,"auto_out_awvalid", false,-1);
    tracep->declBus(c+389,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1172,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1173,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+404,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+222,"auto_out_wready", false,-1);
    tracep->declBit(c+96,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+97,"auto_out_wlast", false,-1);
    tracep->declBit(c+223,"auto_out_bready", false,-1);
    tracep->declBit(c+224,"auto_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+226,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+227,"auto_out_arready", false,-1);
    tracep->declBit(c+98,"auto_out_arvalid", false,-1);
    tracep->declBus(c+391,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1176,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1079,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+405,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+94,"auto_out_rready", false,-1);
    tracep->declBit(c+219,"auto_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+56,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+228,"auto_out_rlast", false,-1);
    tracep->declBit(c+96,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+406,"w_idle", false,-1);
    tracep->declBit(c+229,"in_awready", false,-1);
    tracep->declBit(c+407,"busy", false,-1);
    tracep->declBus(c+408,"r_addr", false,-1, 31,0);
    tracep->declBus(c+409,"r_len", false,-1, 7,0);
    tracep->declBus(c+410,"len", false,-1, 7,0);
    tracep->declBus(c+1183,"addr", false,-1, 31,0);
    tracep->declBit(c+411,"busy_1", false,-1);
    tracep->declBus(c+412,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+413,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+414,"len_1", false,-1, 7,0);
    tracep->declBus(c+1184,"addr_1", false,-1, 31,0);
    tracep->declBit(c+415,"wbeats_latched", false,-1);
    tracep->declBit(c+95,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+99,"wbeats_valid", false,-1);
    tracep->declBus(c+416,"w_counter", false,-1, 8,0);
    tracep->declBus(c+100,"w_todo", false,-1, 8,0);
    tracep->declBit(c+97,"w_last", false,-1);
    tracep->declBit(c+223,"nodeOut_bready", false,-1);
    tracep->declBus(c+417,"error_0", false,-1, 1,0);
    tracep->declBus(c+418,"error_1", false,-1, 1,0);
    tracep->declBus(c+419,"error_2", false,-1, 1,0);
    tracep->declBus(c+420,"error_3", false,-1, 1,0);
    tracep->declBus(c+421,"error_4", false,-1, 1,0);
    tracep->declBus(c+422,"error_5", false,-1, 1,0);
    tracep->declBus(c+423,"error_6", false,-1, 1,0);
    tracep->declBus(c+424,"error_7", false,-1, 1,0);
    tracep->declBus(c+425,"error_8", false,-1, 1,0);
    tracep->declBus(c+426,"error_9", false,-1, 1,0);
    tracep->declBus(c+427,"error_10", false,-1, 1,0);
    tracep->declBus(c+428,"error_11", false,-1, 1,0);
    tracep->declBus(c+429,"error_12", false,-1, 1,0);
    tracep->declBus(c+430,"error_13", false,-1, 1,0);
    tracep->declBus(c+431,"error_14", false,-1, 1,0);
    tracep->declBus(c+432,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+403,"io_enq_ready", false,-1);
    tracep->declBit(c+93,"io_enq_valid", false,-1);
    tracep->declBus(c+1334,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1182,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1335,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1080,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1336,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+230,"io_deq_ready", false,-1);
    tracep->declBit(c+98,"io_deq_valid", false,-1);
    tracep->declBus(c+391,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1185,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+433,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1079,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+434,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+435,"ram", false,-1, 48,0);
    tracep->declBit(c+437,"full", false,-1);
    tracep->declBit(c+98,"io_deq_valid_0", false,-1);
    tracep->declBit(c+231,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+401,"io_enq_ready", false,-1);
    tracep->declBit(c+91,"io_enq_valid", false,-1);
    tracep->declBus(c+1331,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1177,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1332,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1178,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1179,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+232,"io_deq_ready", false,-1);
    tracep->declBit(c+101,"io_deq_valid", false,-1);
    tracep->declBus(c+389,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1186,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+438,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1173,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1187,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+439,"ram", false,-1, 48,0);
    tracep->declBit(c+441,"full", false,-1);
    tracep->declBit(c+101,"io_deq_valid_0", false,-1);
    tracep->declBit(c+233,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+402,"io_enq_ready", false,-1);
    tracep->declBit(c+92,"io_enq_valid", false,-1);
    tracep->declBus(c+1180,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1181,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1333,"io_enq_bits_last", false,-1);
    tracep->declBit(c+234,"io_deq_ready", false,-1);
    tracep->declBit(c+102,"io_deq_valid", false,-1);
    tracep->declBus(c+1174,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1175,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+442,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+443,"ram", false,-1, 36,0);
    tracep->declBit(c+445,"full", false,-1);
    tracep->declBit(c+102,"io_deq_valid_0", false,-1);
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
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+236,"auto_in_awready", false,-1);
    tracep->declBit(c+157,"auto_in_awvalid", false,-1);
    tracep->declBus(c+389,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1188,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1294,"auto_in_wready", false,-1);
    tracep->declBit(c+1295,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+237,"auto_in_bready", false,-1);
    tracep->declBit(c+446,"auto_in_bvalid", false,-1);
    tracep->declBus(c+447,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+448,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+238,"auto_in_arready", false,-1);
    tracep->declBit(c+1296,"auto_in_arvalid", false,-1);
    tracep->declBus(c+391,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1189,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+239,"auto_in_rready", false,-1);
    tracep->declBit(c+449,"auto_in_rvalid", false,-1);
    tracep->declBus(c+450,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+451,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+452,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+238,"nodeIn_arready", false,-1);
    tracep->declBit(c+236,"nodeIn_awready", false,-1);
    tracep->declBit(c+1190,"w_sel0", false,-1);
    tracep->declBit(c+446,"w_full", false,-1);
    tracep->declBus(c+447,"w_id", false,-1, 3,0);
    tracep->declBit(c+453,"r_sel1", false,-1);
    tracep->declBit(c+454,"w_sel1", false,-1);
    tracep->declBit(c+449,"r_full", false,-1);
    tracep->declBus(c+450,"r_id", false,-1, 3,0);
    tracep->declBit(c+240,"ren", false,-1);
    tracep->declBit(c+455,"rdata_REG", false,-1);
    tracep->declBus(c+456,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+457,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+458,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+459,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1191,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+240,"R0_en", false,-1);
    tracep->declBit(c+1260,"R0_clk", false,-1);
    tracep->declBus(c+460,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1192,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+241,"W0_en", false,-1);
    tracep->declBit(c+1260,"W0_clk", false,-1);
    tracep->declBus(c+1174,"W0_data", false,-1, 31,0);
    tracep->declBus(c+1175,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+401,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+91,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1331,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1177,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1332,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1178,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1179,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+402,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+92,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1180,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1333,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1292,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+216,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+403,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+93,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1334,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1182,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1335,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1080,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1336,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+94,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+219,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+55,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+401,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+91,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1331,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1177,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1332,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1178,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1179,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+402,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+92,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1180,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1333,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1292,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+216,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+403,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+93,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1334,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1182,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1335,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1080,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1336,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+94,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+219,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+55,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+242,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+103,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+389,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1172,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1173,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+222,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+96,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+97,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+223,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+224,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+243,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+104,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+391,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1176,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1079,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+94,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+219,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+228,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+236,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+157,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+389,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1188,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1294,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1295,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+237,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+446,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+447,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+448,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+238,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1296,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+391,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1189,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+239,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+449,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+450,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+451,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+452,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1297,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1298,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+461,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1299,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+391,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1193,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1300,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+462,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+463,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+464,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+151,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+152,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+389,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1172,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+1173,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+151,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+153,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+211,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+212,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+390,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+53,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+154,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+155,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+391,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1176,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+1079,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+213,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+214,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+392,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+215,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+53,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+224,"in_0_bvalid", false,-1);
    tracep->declBit(c+219,"in_0_rvalid", false,-1);
    tracep->declBit(c+244,"in_0_wready", false,-1);
    tracep->declBit(c+245,"in_0_awready", false,-1);
    tracep->declBit(c+243,"in_0_arready", false,-1);
    tracep->declBit(c+242,"anonIn_awready", false,-1);
    tracep->declBit(c+1194,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1195,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1196,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1197,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1198,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1199,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+465,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+466,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+467,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+468,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+469,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+470,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+471,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+472,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+473,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+474,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+475,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+476,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+477,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+478,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+479,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+480,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+481,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+482,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+483,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+484,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+485,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+486,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+487,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+488,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+489,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+490,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+491,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+492,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+493,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+494,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+495,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+496,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+497,"latched", false,-1);
    tracep->declBit(c+105,"in_0_awvalid", false,-1);
    tracep->declBit(c+106,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+107,"in_0_wvalid", false,-1);
    tracep->declBit(c+498,"idle_3", false,-1);
    tracep->declBit(c+246,"anyValid", false,-1);
    tracep->declBus(c+247,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+499,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+248,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+249,"prefixOR_1", false,-1);
    tracep->declBit(c+250,"winner_3_1", false,-1);
    tracep->declBit(c+251,"winner_3_2", false,-1);
    tracep->declBit(c+500,"state_3_0", false,-1);
    tracep->declBit(c+501,"state_3_1", false,-1);
    tracep->declBit(c+502,"state_3_2", false,-1);
    tracep->declBit(c+252,"muxState_3_0", false,-1);
    tracep->declBit(c+253,"muxState_3_1", false,-1);
    tracep->declBit(c+254,"muxState_3_2", false,-1);
    tracep->declBit(c+503,"idle_4", false,-1);
    tracep->declBit(c+255,"anyValid_1", false,-1);
    tracep->declBus(c+256,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+504,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+257,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+258,"winner_4_0", false,-1);
    tracep->declBit(c+259,"winner_4_2", false,-1);
    tracep->declBit(c+505,"state_4_0", false,-1);
    tracep->declBit(c+506,"state_4_2", false,-1);
    tracep->declBit(c+260,"muxState_4_0", false,-1);
    tracep->declBit(c+261,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+507,"io_enq_ready", false,-1);
    tracep->declBit(c+106,"io_enq_valid", false,-1);
    tracep->declBus(c+1200,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+262,"io_deq_ready", false,-1);
    tracep->declBit(c+108,"io_deq_valid", false,-1);
    tracep->declBus(c+1201,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+508,"wrap", false,-1);
    tracep->declBit(c+509,"wrap_1", false,-1);
    tracep->declBit(c+510,"maybe_full", false,-1);
    tracep->declBit(c+511,"ptr_match", false,-1);
    tracep->declBit(c+512,"empty", false,-1);
    tracep->declBit(c+513,"full", false,-1);
    tracep->declBit(c+108,"io_deq_valid_0", false,-1);
    tracep->declBit(c+263,"do_deq", false,-1);
    tracep->declBit(c+264,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+509,"R0_addr", false,-1);
    tracep->declBit(c+1337,"R0_en", false,-1);
    tracep->declBit(c+1260,"R0_clk", false,-1);
    tracep->declBus(c+514,"R0_data", false,-1, 2,0);
    tracep->declBit(c+508,"W0_addr", false,-1);
    tracep->declBit(c+264,"W0_en", false,-1);
    tracep->declBit(c+1260,"W0_clk", false,-1);
    tracep->declBus(c+1200,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+515+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+221,"auto_in_awready", false,-1);
    tracep->declBit(c+95,"auto_in_awvalid", false,-1);
    tracep->declBus(c+389,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1172,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1173,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+404,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+222,"auto_in_wready", false,-1);
    tracep->declBit(c+96,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+97,"auto_in_wlast", false,-1);
    tracep->declBit(c+223,"auto_in_bready", false,-1);
    tracep->declBit(c+224,"auto_in_bvalid", false,-1);
    tracep->declBus(c+217,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+226,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+227,"auto_in_arready", false,-1);
    tracep->declBit(c+98,"auto_in_arvalid", false,-1);
    tracep->declBus(c+391,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1176,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1079,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+405,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+94,"auto_in_rready", false,-1);
    tracep->declBit(c+219,"auto_in_rvalid", false,-1);
    tracep->declBus(c+220,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+56,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+228,"auto_in_rlast", false,-1);
    tracep->declBit(c+242,"auto_out_awready", false,-1);
    tracep->declBit(c+103,"auto_out_awvalid", false,-1);
    tracep->declBus(c+389,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1172,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1173,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+222,"auto_out_wready", false,-1);
    tracep->declBit(c+96,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1174,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1175,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+97,"auto_out_wlast", false,-1);
    tracep->declBit(c+223,"auto_out_bready", false,-1);
    tracep->declBit(c+224,"auto_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+225,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+243,"auto_out_arready", false,-1);
    tracep->declBit(c+104,"auto_out_arvalid", false,-1);
    tracep->declBus(c+391,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1176,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1079,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+94,"auto_out_rready", false,-1);
    tracep->declBit(c+219,"auto_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+228,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+517,"io_enq_ready", false,-1);
    tracep->declBit(c+57,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+265,"io_deq_ready", false,-1);
    tracep->declBit(c+518,"io_deq_valid", false,-1);
    tracep->declBit(c+519,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+519,"ram_real_last", false,-1);
    tracep->declBit(c+518,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+520,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+521,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+266,"io_deq_ready", false,-1);
    tracep->declBit(c+522,"io_deq_valid", false,-1);
    tracep->declBit(c+523,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+523,"ram_real_last", false,-1);
    tracep->declBit(c+522,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+524,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+525,"io_enq_ready", false,-1);
    tracep->declBit(c+59,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+267,"io_deq_ready", false,-1);
    tracep->declBit(c+526,"io_deq_valid", false,-1);
    tracep->declBit(c+527,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+527,"ram_real_last", false,-1);
    tracep->declBit(c+526,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+528,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+529,"io_enq_ready", false,-1);
    tracep->declBit(c+60,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+268,"io_deq_ready", false,-1);
    tracep->declBit(c+530,"io_deq_valid", false,-1);
    tracep->declBit(c+531,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+531,"ram_real_last", false,-1);
    tracep->declBit(c+530,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+532,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+533,"io_enq_ready", false,-1);
    tracep->declBit(c+61,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+269,"io_deq_ready", false,-1);
    tracep->declBit(c+534,"io_deq_valid", false,-1);
    tracep->declBit(c+535,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+535,"ram_real_last", false,-1);
    tracep->declBit(c+534,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+536,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+537,"io_enq_ready", false,-1);
    tracep->declBit(c+62,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+270,"io_deq_ready", false,-1);
    tracep->declBit(c+538,"io_deq_valid", false,-1);
    tracep->declBit(c+539,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+539,"ram_real_last", false,-1);
    tracep->declBit(c+538,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+540,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+541,"io_enq_ready", false,-1);
    tracep->declBit(c+63,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+271,"io_deq_ready", false,-1);
    tracep->declBit(c+542,"io_deq_valid", false,-1);
    tracep->declBit(c+543,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+543,"ram_real_last", false,-1);
    tracep->declBit(c+542,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+544,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+545,"io_enq_ready", false,-1);
    tracep->declBit(c+64,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+272,"io_deq_ready", false,-1);
    tracep->declBit(c+546,"io_deq_valid", false,-1);
    tracep->declBit(c+547,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+547,"ram_real_last", false,-1);
    tracep->declBit(c+546,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+548,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+549,"io_enq_ready", false,-1);
    tracep->declBit(c+65,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+273,"io_deq_ready", false,-1);
    tracep->declBit(c+550,"io_deq_valid", false,-1);
    tracep->declBit(c+551,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+551,"ram_real_last", false,-1);
    tracep->declBit(c+550,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+552,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+553,"io_enq_ready", false,-1);
    tracep->declBit(c+66,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+274,"io_deq_ready", false,-1);
    tracep->declBit(c+554,"io_deq_valid", false,-1);
    tracep->declBit(c+555,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+555,"ram_real_last", false,-1);
    tracep->declBit(c+554,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+556,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+557,"io_enq_ready", false,-1);
    tracep->declBit(c+67,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+275,"io_deq_ready", false,-1);
    tracep->declBit(c+558,"io_deq_valid", false,-1);
    tracep->declBit(c+559,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+559,"ram_real_last", false,-1);
    tracep->declBit(c+558,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+560,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+561,"io_enq_ready", false,-1);
    tracep->declBit(c+68,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+276,"io_deq_ready", false,-1);
    tracep->declBit(c+562,"io_deq_valid", false,-1);
    tracep->declBit(c+563,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+563,"ram_real_last", false,-1);
    tracep->declBit(c+562,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+564,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+565,"io_enq_ready", false,-1);
    tracep->declBit(c+69,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+277,"io_deq_ready", false,-1);
    tracep->declBit(c+566,"io_deq_valid", false,-1);
    tracep->declBit(c+567,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+567,"ram_real_last", false,-1);
    tracep->declBit(c+566,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+568,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+569,"io_enq_ready", false,-1);
    tracep->declBit(c+70,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+278,"io_deq_ready", false,-1);
    tracep->declBit(c+570,"io_deq_valid", false,-1);
    tracep->declBit(c+571,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+571,"ram_real_last", false,-1);
    tracep->declBit(c+570,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+572,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+573,"io_enq_ready", false,-1);
    tracep->declBit(c+71,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+279,"io_deq_ready", false,-1);
    tracep->declBit(c+574,"io_deq_valid", false,-1);
    tracep->declBit(c+575,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+575,"ram_real_last", false,-1);
    tracep->declBit(c+574,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+576,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+577,"io_enq_ready", false,-1);
    tracep->declBit(c+72,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+280,"io_deq_ready", false,-1);
    tracep->declBit(c+578,"io_deq_valid", false,-1);
    tracep->declBit(c+579,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+579,"ram_real_last", false,-1);
    tracep->declBit(c+578,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+580,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+581,"io_enq_ready", false,-1);
    tracep->declBit(c+73,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+281,"io_deq_ready", false,-1);
    tracep->declBit(c+582,"io_deq_valid", false,-1);
    tracep->declBit(c+583,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+583,"ram_real_last", false,-1);
    tracep->declBit(c+582,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+584,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+585,"io_enq_ready", false,-1);
    tracep->declBit(c+74,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+282,"io_deq_ready", false,-1);
    tracep->declBit(c+586,"io_deq_valid", false,-1);
    tracep->declBit(c+587,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+587,"ram_real_last", false,-1);
    tracep->declBit(c+586,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+588,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+589,"io_enq_ready", false,-1);
    tracep->declBit(c+75,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+283,"io_deq_ready", false,-1);
    tracep->declBit(c+590,"io_deq_valid", false,-1);
    tracep->declBit(c+591,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+591,"ram_real_last", false,-1);
    tracep->declBit(c+590,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+592,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+593,"io_enq_ready", false,-1);
    tracep->declBit(c+76,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+284,"io_deq_ready", false,-1);
    tracep->declBit(c+594,"io_deq_valid", false,-1);
    tracep->declBit(c+595,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+595,"ram_real_last", false,-1);
    tracep->declBit(c+594,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+596,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+597,"io_enq_ready", false,-1);
    tracep->declBit(c+77,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+285,"io_deq_ready", false,-1);
    tracep->declBit(c+598,"io_deq_valid", false,-1);
    tracep->declBit(c+599,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+599,"ram_real_last", false,-1);
    tracep->declBit(c+598,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+600,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+601,"io_enq_ready", false,-1);
    tracep->declBit(c+78,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+286,"io_deq_ready", false,-1);
    tracep->declBit(c+602,"io_deq_valid", false,-1);
    tracep->declBit(c+603,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+603,"ram_real_last", false,-1);
    tracep->declBit(c+602,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+604,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+605,"io_enq_ready", false,-1);
    tracep->declBit(c+79,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+287,"io_deq_ready", false,-1);
    tracep->declBit(c+606,"io_deq_valid", false,-1);
    tracep->declBit(c+607,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+607,"ram_real_last", false,-1);
    tracep->declBit(c+606,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+608,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+609,"io_enq_ready", false,-1);
    tracep->declBit(c+80,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+288,"io_deq_ready", false,-1);
    tracep->declBit(c+610,"io_deq_valid", false,-1);
    tracep->declBit(c+611,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+611,"ram_real_last", false,-1);
    tracep->declBit(c+610,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+612,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+613,"io_enq_ready", false,-1);
    tracep->declBit(c+81,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+289,"io_deq_ready", false,-1);
    tracep->declBit(c+614,"io_deq_valid", false,-1);
    tracep->declBit(c+615,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+615,"ram_real_last", false,-1);
    tracep->declBit(c+614,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+616,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+617,"io_enq_ready", false,-1);
    tracep->declBit(c+82,"io_enq_valid", false,-1);
    tracep->declBit(c+404,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+290,"io_deq_ready", false,-1);
    tracep->declBit(c+618,"io_deq_valid", false,-1);
    tracep->declBit(c+619,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+619,"ram_real_last", false,-1);
    tracep->declBit(c+618,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+620,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+621,"io_enq_ready", false,-1);
    tracep->declBit(c+83,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+291,"io_deq_ready", false,-1);
    tracep->declBit(c+622,"io_deq_valid", false,-1);
    tracep->declBit(c+623,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+623,"ram_real_last", false,-1);
    tracep->declBit(c+622,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+624,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+625,"io_enq_ready", false,-1);
    tracep->declBit(c+84,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+292,"io_deq_ready", false,-1);
    tracep->declBit(c+626,"io_deq_valid", false,-1);
    tracep->declBit(c+627,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+627,"ram_real_last", false,-1);
    tracep->declBit(c+626,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+628,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+629,"io_enq_ready", false,-1);
    tracep->declBit(c+85,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+293,"io_deq_ready", false,-1);
    tracep->declBit(c+630,"io_deq_valid", false,-1);
    tracep->declBit(c+631,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+631,"ram_real_last", false,-1);
    tracep->declBit(c+630,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+632,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+633,"io_enq_ready", false,-1);
    tracep->declBit(c+86,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+294,"io_deq_ready", false,-1);
    tracep->declBit(c+634,"io_deq_valid", false,-1);
    tracep->declBit(c+635,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+635,"ram_real_last", false,-1);
    tracep->declBit(c+634,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+636,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+637,"io_enq_ready", false,-1);
    tracep->declBit(c+87,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+295,"io_deq_ready", false,-1);
    tracep->declBit(c+638,"io_deq_valid", false,-1);
    tracep->declBit(c+639,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+639,"ram_real_last", false,-1);
    tracep->declBit(c+638,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+640,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+641,"io_enq_ready", false,-1);
    tracep->declBit(c+88,"io_enq_valid", false,-1);
    tracep->declBit(c+405,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+296,"io_deq_ready", false,-1);
    tracep->declBit(c+642,"io_deq_valid", false,-1);
    tracep->declBit(c+643,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+643,"ram_real_last", false,-1);
    tracep->declBit(c+642,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+644,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+109,"reset", false,-1);
    tracep->declBit(c+401,"auto_master_out_awready", false,-1);
    tracep->declBit(c+91,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1331,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1177,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1332,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1178,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1179,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+402,"auto_master_out_wready", false,-1);
    tracep->declBit(c+92,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1180,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1181,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1333,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1292,"auto_master_out_bready", false,-1);
    tracep->declBit(c+216,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+217,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+218,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+403,"auto_master_out_arready", false,-1);
    tracep->declBit(c+93,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1334,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1182,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1335,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1080,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1336,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+94,"auto_master_out_rready", false,-1);
    tracep->declBit(c+219,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+220,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+54,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1293,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+55,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+109,"reset", false,-1);
    tracep->declBit(c+1323,"io_interrupt", false,-1);
    tracep->declBit(c+401,"io_master_awready", false,-1);
    tracep->declBit(c+91,"io_master_awvalid", false,-1);
    tracep->declBus(c+1177,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1331,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1332,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1178,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1179,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+402,"io_master_wready", false,-1);
    tracep->declBit(c+92,"io_master_wvalid", false,-1);
    tracep->declBus(c+1180,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+1181,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1333,"io_master_wlast", false,-1);
    tracep->declBit(c+1292,"io_master_bready", false,-1);
    tracep->declBit(c+216,"io_master_bvalid", false,-1);
    tracep->declBus(c+218,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+217,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+403,"io_master_arready", false,-1);
    tracep->declBit(c+93,"io_master_arvalid", false,-1);
    tracep->declBus(c+1182,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1334,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1335,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+1080,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1336,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+94,"io_master_rready", false,-1);
    tracep->declBit(c+219,"io_master_rvalid", false,-1);
    tracep->declBus(c+1293,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+54,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+55,"io_master_rlast", false,-1);
    tracep->declBus(c+220,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1338,"io_slave_awready", false,-1);
    tracep->declBit(c+1323,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1339,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1340,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1335,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1341,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1342,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1343,"io_slave_wready", false,-1);
    tracep->declBit(c+1323,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1339,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1340,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1323,"io_slave_wlast", false,-1);
    tracep->declBit(c+1323,"io_slave_bready", false,-1);
    tracep->declBit(c+1344,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1345,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1346,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1347,"io_slave_arready", false,-1);
    tracep->declBit(c+1323,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1339,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1340,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1335,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1341,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1342,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1323,"io_slave_rready", false,-1);
    tracep->declBit(c+1348,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1349,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1350,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1351,"io_slave_rlast", false,-1);
    tracep->declBus(c+1352,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+1081,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1202,"npc", false,-1, 31,0);
    tracep->declBus(c+965,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+1082,"inst", false,-1, 31,0);
    tracep->declBit(c+1083,"ifu_valid", false,-1);
    tracep->declBit(c+1084,"ifu_arvalid", false,-1);
    tracep->declBit(c+1085,"ifu_arready", false,-1);
    tracep->declBus(c+965,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+297,"ifu_rvalid", false,-1);
    tracep->declBit(c+1081,"ifu_rready", false,-1);
    tracep->declBus(c+298,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+1086,"reg_process", false,-1);
    tracep->declBus(c+1087,"src1", false,-1, 4,0);
    tracep->declBus(c+1088,"src2", false,-1, 4,0);
    tracep->declBus(c+1089,"rd", false,-1, 4,0);
    tracep->declBus(c+1090,"imm", false,-1, 31,0);
    tracep->declBit(c+1091,"ebreaksig", false,-1);
    tracep->declBit(c+1092,"mretsig", false,-1);
    tracep->declBit(c+1093,"ecallsig", false,-1);
    tracep->declBit(c+1094,"regew", false,-1);
    tracep->declBit(c+1095,"memew", false,-1);
    tracep->declBit(c+1096,"memer", false,-1);
    tracep->declBit(c+1097,"muximm", false,-1);
    tracep->declBus(c+1098,"func3", false,-1, 2,0);
    tracep->declBus(c+1099,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1100,"func7", false,-1);
    tracep->declBit(c+1101,"btypebranch", false,-1);
    tracep->declBit(c+1102,"jalsig", false,-1);
    tracep->declBit(c+1103,"jalrsig", false,-1);
    tracep->declBit(c+1104,"auipcsig", false,-1);
    tracep->declBus(c+1105,"aluop", false,-1, 1,0);
    tracep->declBit(c+1106,"csrrw", false,-1);
    tracep->declBit(c+1107,"csrrs", false,-1);
    tracep->declBit(c+1083,"idu_valid", false,-1);
    tracep->declBus(c+1108,"memmask", false,-1, 2,0);
    tracep->declBit(c+1109,"memsextsig", false,-1);
    tracep->declBus(c+299,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1203,"regout1", false,-1, 31,0);
    tracep->declBus(c+1204,"regout2", false,-1, 31,0);
    tracep->declBus(c+966,"mepc", false,-1, 31,0);
    tracep->declBus(c+967,"mtvec", false,-1, 31,0);
    tracep->declBit(c+1081,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1205,"res", false,-1, 31,0);
    tracep->declBus(c+1206,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1083,"exu_valid", false,-1);
    tracep->declBit(c+1081,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1301,"memvalid", false,-1);
    tracep->declBus(c+1110,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1110,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1111,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1112,"rready", false,-1, 1,0);
    tracep->declBus(c+1113,"bready", false,-1, 1,0);
    tracep->declBus(c+89,"bvalid", false,-1, 1,0);
    tracep->declBus(c+300,"rvalid", false,-1, 1,0);
    tracep->declBus(c+645,"awready", false,-1, 1,0);
    tracep->declBus(c+645,"wready", false,-1, 1,0);
    tracep->declBus(c+1114,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1302+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+301+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1207+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1209+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1211+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+303+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1213+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1115+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1353,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+109,"reset", false,-1);
    tracep->declBus(c+1110,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1110,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1111,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1112,"rready", false,-1, 1,0);
    tracep->declBus(c+1113,"bready", false,-1, 1,0);
    tracep->declBus(c+89,"bvalid", false,-1, 1,0);
    tracep->declBus(c+300,"rvalid", false,-1, 1,0);
    tracep->declBus(c+645,"awready", false,-1, 1,0);
    tracep->declBus(c+645,"wready", false,-1, 1,0);
    tracep->declBus(c+1114,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1215+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1217+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1219+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1221+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+305+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+307+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1223+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1117+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->declBit(c+91,"awvalid_out", false,-1);
    tracep->declBit(c+92,"wvalid_out", false,-1);
    tracep->declBit(c+93,"arvalid_out", false,-1);
    tracep->declBit(c+94,"rready_out", false,-1);
    tracep->declBit(c+1292,"bready_out", false,-1);
    tracep->declBit(c+216,"bvalid_in", false,-1);
    tracep->declBit(c+219,"rvalid_in", false,-1);
    tracep->declBit(c+402,"awready_in", false,-1);
    tracep->declBit(c+402,"wready_in", false,-1);
    tracep->declBit(c+403,"arready_in", false,-1);
    tracep->declBus(c+1182,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1177,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1180,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+1181,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+54,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+218,"bresp_in", false,-1, 1,0);
    tracep->declBus(c+1178,"awsize_out", false,-1, 2,0);
    tracep->declBus(c+1080,"arsize_out", false,-1, 2,0);
    tracep->declBit(c+646,"busy", false,-1);
    tracep->declBus(c+647,"giant", false,-1, 1,0);
    tracep->declBus(c+648,"i", false,-1, 31,0);
    tracep->declBus(c+1177,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1180,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1182,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1181,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1178,"awsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1080,"arsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1354,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+1098,"func3", false,-1, 2,0);
    tracep->declBit(c+1101,"btypebranch", false,-1);
    tracep->declBit(c+1100,"func7", false,-1);
    tracep->declBus(c+1105,"aluop", false,-1, 1,0);
    tracep->declBit(c+1103,"jalrsig", false,-1);
    tracep->declBit(c+1102,"jalsig", false,-1);
    tracep->declBus(c+1090,"imm", false,-1, 31,0);
    tracep->declBit(c+1097,"muximm", false,-1);
    tracep->declBus(c+1203,"regout1", false,-1, 31,0);
    tracep->declBus(c+1204,"regout2", false,-1, 31,0);
    tracep->declBus(c+965,"pc", false,-1, 31,0);
    tracep->declBit(c+1104,"auipcsig", false,-1);
    tracep->declBit(c+1092,"mretsig", false,-1);
    tracep->declBit(c+1093,"ecallsig", false,-1);
    tracep->declBus(c+967,"mtvec", false,-1, 31,0);
    tracep->declBus(c+966,"mepc", false,-1, 31,0);
    tracep->declBit(c+1083,"valid_from", false,-1);
    tracep->declBit(c+1081,"ready_from", false,-1);
    tracep->declBus(c+1205,"res", false,-1, 31,0);
    tracep->declBus(c+1202,"npc", false,-1, 31,0);
    tracep->declBus(c+1206,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1083,"valid_to", false,-1);
    tracep->declBit(c+1081,"ready_to", false,-1);
    tracep->declBus(c+968,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1225,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+1119,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1226,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1227,"zero", false,-1);
    tracep->declBit(c+1228,"signal", false,-1);
    tracep->declBit(c+1229,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1203,"A", false,-1, 31,0);
    tracep->declBus(c+1226,"B", false,-1, 31,0);
    tracep->declBus(c+1119,"op", false,-1, 4,0);
    tracep->declBus(c+1205,"res", false,-1, 31,0);
    tracep->declBit(c+1227,"zero", false,-1);
    tracep->declBit(c+1228,"signal", false,-1);
    tracep->declBit(c+1229,"carry", false,-1);
    tracep->declBit(c+1120,"addsig", false,-1);
    tracep->declBit(c+1121,"logsig", false,-1);
    tracep->declBit(c+1122,"shfsig", false,-1);
    tracep->declBit(c+1123,"sltsig", false,-1);
    tracep->declBit(c+1229,"carry_tmp", false,-1);
    tracep->declBit(c+1124,"type_I", false,-1);
    tracep->declBus(c+1230,"logres", false,-1, 31,0);
    tracep->declBus(c+1231,"addres", false,-1, 31,0);
    tracep->declBit(c+1232,"addzero", false,-1);
    tracep->declBus(c+1233,"shfres", false,-1, 31,0);
    tracep->declBus(c+1234,"sltres", false,-1, 31,0);
    tracep->declBus(c+1203,"A_s", false,-1, 31,0);
    tracep->declBus(c+1226,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+1098,"func3", false,-1, 2,0);
    tracep->declBit(c+1100,"func7", false,-1);
    tracep->declBus(c+1105,"aluop", false,-1, 1,0);
    tracep->declBit(c+1103,"jalrsig", false,-1);
    tracep->declBus(c+1119,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+1124,"type_I", false,-1);
    tracep->declBit(c+1125,"type_B", false,-1);
    tracep->declBit(c+1126,"type_R", false,-1);
    tracep->declBit(c+1127,"addsig", false,-1);
    tracep->declBus(c+1128,"branchop", false,-1, 3,0);
    tracep->declBus(c+1129,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+1101,"btypebranch", false,-1);
    tracep->declBus(c+1098,"func3", false,-1, 2,0);
    tracep->declBit(c+1227,"zero", false,-1);
    tracep->declBit(c+1228,"signal", false,-1);
    tracep->declBit(c+1229,"carry", false,-1);
    tracep->declBus(c+1205,"res", false,-1, 31,0);
    tracep->declBus(c+968,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1225,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+1102,"jalsig", false,-1);
    tracep->declBit(c+1103,"jalrsig", false,-1);
    tracep->declBit(c+1104,"auipcsig", false,-1);
    tracep->declBit(c+1092,"mretsig", false,-1);
    tracep->declBit(c+1093,"ecallsig", false,-1);
    tracep->declBus(c+967,"mtvec", false,-1, 31,0);
    tracep->declBus(c+966,"mepc", false,-1, 31,0);
    tracep->declBus(c+1202,"npc", false,-1, 31,0);
    tracep->declBus(c+1206,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1353,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1355,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1356,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1226,"out", false,-1, 31,0);
    tracep->declBus(c+1097,"key", false,-1, 0,0);
    tracep->declArray(c+1154,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1353,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1355,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1356,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1357,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1226,"out", false,-1, 31,0);
    tracep->declBus(c+1097,"key", false,-1, 0,0);
    tracep->declBus(c+1339,"default_out", false,-1, 31,0);
    tracep->declArray(c+1154,"lut", false,-1, 65,0);
    tracep->declBus(c+1358,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1157+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1161+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1235,"lut_out", false,-1, 31,0);
    tracep->declBit(c+1130,"hit", false,-1);
    tracep->declBus(c+1359,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+965,"pc", false,-1, 31,0);
    tracep->declBus(c+968,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+965,"pc", false,-1, 31,0);
    tracep->declBus(c+1090,"imm", false,-1, 31,0);
    tracep->declBus(c+1225,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+1082,"inst", false,-1, 31,0);
    tracep->declBit(c+1083,"valid_from", false,-1);
    tracep->declBit(c+1081,"ready_from", false,-1);
    tracep->declBit(c+1091,"ebreaksig", false,-1);
    tracep->declBit(c+1093,"ecallsig", false,-1);
    tracep->declBit(c+1092,"mretsig", false,-1);
    tracep->declBus(c+1090,"imm", false,-1, 31,0);
    tracep->declBus(c+1098,"func3", false,-1, 2,0);
    tracep->declBit(c+1100,"func7", false,-1);
    tracep->declBus(c+1087,"src1", false,-1, 4,0);
    tracep->declBus(c+1088,"src2", false,-1, 4,0);
    tracep->declBus(c+1089,"rd", false,-1, 4,0);
    tracep->declBit(c+1095,"memew", false,-1);
    tracep->declBus(c+1099,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1096,"memer", false,-1);
    tracep->declBit(c+1094,"regew", false,-1);
    tracep->declBit(c+1097,"muximm", false,-1);
    tracep->declBit(c+1101,"btypebranch", false,-1);
    tracep->declBit(c+1103,"jalrsig", false,-1);
    tracep->declBit(c+1102,"jalsig", false,-1);
    tracep->declBus(c+1105,"aluop", false,-1, 1,0);
    tracep->declBit(c+1104,"auipcsig", false,-1);
    tracep->declBit(c+1106,"csrrw", false,-1);
    tracep->declBit(c+1107,"csrrs", false,-1);
    tracep->declBit(c+1083,"valid_to", false,-1);
    tracep->declBit(c+1081,"ready_to", false,-1);
    tracep->declBus(c+1108,"memmask", false,-1, 2,0);
    tracep->declBit(c+1109,"memsextsig", false,-1);
    tracep->declBit(c+1091,"ebreak", false,-1);
    tracep->declBit(c+1093,"ecall", false,-1);
    tracep->declBit(c+1092,"mret", false,-1);
    tracep->declBus(c+1098,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+1100,"func7bridge", false,-1);
    tracep->declBus(c+1131,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+1082,"inst", false,-1, 31,0);
    tracep->declBit(c+1091,"ebreaksig", false,-1);
    tracep->declBit(c+1093,"ecallsig", false,-1);
    tracep->declBit(c+1092,"mretsig", false,-1);
    tracep->declBus(c+1090,"imm", false,-1, 31,0);
    tracep->declBus(c+1131,"opcode", false,-1, 6,0);
    tracep->declBus(c+1098,"func3", false,-1, 2,0);
    tracep->declBit(c+1100,"func7", false,-1);
    tracep->declBus(c+1087,"src1", false,-1, 4,0);
    tracep->declBus(c+1088,"src2", false,-1, 4,0);
    tracep->declBus(c+1089,"rd", false,-1, 4,0);
    tracep->declBus(c+1108,"memmask", false,-1, 2,0);
    tracep->declBit(c+1109,"memsextsig", false,-1);
    tracep->declBit(c+1132,"type_I", false,-1);
    tracep->declBit(c+1133,"type_R", false,-1);
    tracep->declBit(c+1134,"type_U", false,-1);
    tracep->declBit(c+1095,"type_S", false,-1);
    tracep->declBit(c+1102,"type_J", false,-1);
    tracep->declBit(c+1101,"type_B", false,-1);
    tracep->declBus(c+1135,"I_imm", false,-1, 31,0);
    tracep->declBus(c+1136,"U_imm", false,-1, 31,0);
    tracep->declBus(c+1137,"S_imm", false,-1, 31,0);
    tracep->declBus(c+1138,"J_imm", false,-1, 31,0);
    tracep->declBus(c+1139,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+1131,"opcode", false,-1, 6,0);
    tracep->declBus(c+1098,"func3", false,-1, 2,0);
    tracep->declBit(c+1100,"func7", false,-1);
    tracep->declBit(c+1091,"ebreaksig", false,-1);
    tracep->declBit(c+1093,"ecallsig", false,-1);
    tracep->declBit(c+1092,"mretsig", false,-1);
    tracep->declBit(c+1095,"memew", false,-1);
    tracep->declBus(c+1099,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1096,"memer", false,-1);
    tracep->declBit(c+1094,"regew", false,-1);
    tracep->declBit(c+1097,"muximm", false,-1);
    tracep->declBit(c+1101,"btypebranch", false,-1);
    tracep->declBit(c+1103,"jalrsig", false,-1);
    tracep->declBit(c+1102,"jalsig", false,-1);
    tracep->declBus(c+1105,"aluop", false,-1, 1,0);
    tracep->declBit(c+1104,"auipcsig", false,-1);
    tracep->declBit(c+1106,"csrrw", false,-1);
    tracep->declBit(c+1107,"csrrs", false,-1);
    tracep->declBit(c+1132,"type_I", false,-1);
    tracep->declBit(c+1133,"type_R", false,-1);
    tracep->declBit(c+1134,"type_U", false,-1);
    tracep->declBit(c+1095,"type_S", false,-1);
    tracep->declBit(c+1102,"type_J", false,-1);
    tracep->declBit(c+1101,"type_B", false,-1);
    tracep->declBit(c+1096,"load", false,-1);
    tracep->declBit(c+1095,"store", false,-1);
    tracep->declBit(c+1140,"regwritepc", false,-1);
    tracep->declBit(c+1096,"regwritemem", false,-1);
    tracep->declBit(c+1141,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBus(c+1202,"npc", false,-1, 31,0);
    tracep->declBit(c+1081,"ready", false,-1);
    tracep->declBus(c+965,"pc", false,-1, 31,0);
    tracep->declBus(c+1082,"inst", false,-1, 31,0);
    tracep->declBit(c+1083,"valid", false,-1);
    tracep->declBit(c+1086,"regprocess", false,-1);
    tracep->declBit(c+1084,"arvalid", false,-1);
    tracep->declBit(c+1085,"arready", false,-1);
    tracep->declBus(c+965,"araddr", false,-1, 31,0);
    tracep->declBit(c+297,"rvalid", false,-1);
    tracep->declBit(c+1081,"rready", false,-1);
    tracep->declBus(c+298,"rdata", false,-1, 31,0);
    tracep->declBus(c+965,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1142,"infetch_ready", false,-1);
    tracep->declBus(c+1143,"state", false,-1, 2,0);
    tracep->declBus(c+1082,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBus(c+1202,"npc", false,-1, 31,0);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBit(c+1142,"ready_from", false,-1);
    tracep->declBus(c+965,"pcout", false,-1, 31,0);
    tracep->declBus(c+1360,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBit(c+1304,"ew", false,-1);
    tracep->declBus(c+1089,"addr", false,-1, 4,0);
    tracep->declBus(c+1087,"src1", false,-1, 4,0);
    tracep->declBus(c+1088,"src2", false,-1, 4,0);
    tracep->declBus(c+1144,"csr", false,-1, 11,0);
    tracep->declBus(c+299,"data", false,-1, 31,0);
    tracep->declBit(c+1106,"csrrw", false,-1);
    tracep->declBit(c+1107,"csrrs", false,-1);
    tracep->declBit(c+1093,"ecallsig", false,-1);
    tracep->declBit(c+1083,"valid", false,-1);
    tracep->declBus(c+1203,"regout1", false,-1, 31,0);
    tracep->declBus(c+1204,"regout2", false,-1, 31,0);
    tracep->declBus(c+966,"mepc", false,-1, 31,0);
    tracep->declBus(c+967,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+969+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+1001+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1145,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+309,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1361,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1362,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1363,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1145,"out", false,-1, 2,0);
    tracep->declBus(c+1144,"key", false,-1, 11,0);
    tracep->declArray(c+1364,"lut", false,-1, 89,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1361,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1362,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1363,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1357,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1145,"out", false,-1, 2,0);
    tracep->declBus(c+1144,"key", false,-1, 11,0);
    tracep->declBus(c+1341,"default_out", false,-1, 2,0);
    tracep->declArray(c+1364,"lut", false,-1, 89,0);
    tracep->declBus(c+1367,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 14,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+9+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+15+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1146,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1147,"hit", false,-1);
    tracep->declBus(c+1368,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBit(c+1305,"ew", false,-1);
    tracep->declBit(c+1106,"csrrw", false,-1);
    tracep->declBit(c+1107,"csrrs", false,-1);
    tracep->declBit(c+1093,"ecall", false,-1);
    tracep->declBus(c+1145,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+1089,"addr", false,-1, 4,0);
    tracep->declBus(c+309,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1007+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+1039+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1045,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBus(c+1205,"res", false,-1, 31,0);
    tracep->declBus(c+1204,"regout2", false,-1, 31,0);
    tracep->declBit(c+1095,"memew", false,-1);
    tracep->declBit(c+1096,"memer", false,-1);
    tracep->declBus(c+1090,"imm", false,-1, 31,0);
    tracep->declBus(c+1206,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+1099,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1083,"valid_from", false,-1);
    tracep->declBus(c+1108,"memmask", false,-1, 2,0);
    tracep->declBit(c+1109,"memsextsig", false,-1);
    tracep->declBus(c+299,"regwrite", false,-1, 31,0);
    tracep->declBit(c+1081,"ready_to", false,-1);
    tracep->declBit(c+1301,"memvalid", false,-1);
    tracep->declBit(c+1148,"awvalid", false,-1);
    tracep->declBit(c+649,"awready", false,-1);
    tracep->declBus(c+1205,"awaddr", false,-1, 31,0);
    tracep->declBit(c+1148,"wvalid", false,-1);
    tracep->declBit(c+649,"wready", false,-1);
    tracep->declBus(c+1236,"wdata", false,-1, 31,0);
    tracep->declBus(c+1237,"wstrb", false,-1, 3,0);
    tracep->declBit(c+90,"bvalid", false,-1);
    tracep->declBit(c+1095,"bready", false,-1);
    tracep->declBus(c+310,"bresp", false,-1, 1,0);
    tracep->declBit(c+1306,"arvalid", false,-1);
    tracep->declBit(c+1149,"arready", false,-1);
    tracep->declBus(c+1238,"araddr", false,-1, 31,0);
    tracep->declBit(c+311,"rvalid", false,-1);
    tracep->declBit(c+1096,"rready", false,-1);
    tracep->declBus(c+312,"rdata", false,-1, 31,0);
    tracep->declBus(c+1239,"awsize", false,-1, 2,0);
    tracep->declBus(c+1150,"arsize", false,-1, 2,0);
    tracep->declBus(c+1179,"awburst", false,-1, 1,0);
    tracep->declBus(c+650,"state", false,-1, 1,0);
    tracep->declBus(c+313,"memread", false,-1, 31,0);
    tracep->declBus(c+1240,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1151,"access_size_i", false,-1, 1,0);
    tracep->declBit(c+1241,"aligned_sram", false,-1);
    tracep->declBit(c+1307,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBit(c+1241,"is_unalign", false,-1);
    tracep->declBus(c+312,"data", false,-1, 31,0);
    tracep->declBus(c+1108,"memmask", false,-1, 2,0);
    tracep->declBit(c+1109,"memsextsig", false,-1);
    tracep->declBus(c+1242,"addr_offset", false,-1, 1,0);
    tracep->declBus(c+313,"read", false,-1, 31,0);
    tracep->declBus(c+314,"read_u", false,-1, 31,0);
    tracep->declBus(c+315,"read_s", false,-1, 31,0);
    tracep->declBus(c+316,"read_sb", false,-1, 31,0);
    tracep->declBus(c+317,"read_sh", false,-1, 31,0);
    tracep->declBus(c+318,"byte_data", false,-1, 7,0);
    tracep->declBus(c+319,"halfword_data", false,-1, 15,0);
    tracep->declBus(c+1308,"halfword_data_unalign", false,-1, 15,0);
    tracep->declBus(c+1309,"byte_data_unalign", false,-1, 7,0);
    tracep->declBus(c+320,"halfword_data_align", false,-1, 15,0);
    tracep->declBus(c+321,"byte_data_align", false,-1, 7,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1369,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1356,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+318,"input_number", false,-1, 7,0);
    tracep->declBus(c+316,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1370,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1356,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+319,"input_number", false,-1, 15,0);
    tracep->declBus(c+317,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1371,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1363,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1356,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+299,"out", false,-1, 31,0);
    tracep->declBus(c+1099,"key", false,-1, 2,0);
    tracep->declBus(c+1357,"default_out", false,-1, 31,0);
    tracep->declArray(c+110,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1371,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1363,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1356,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1355,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+299,"out", false,-1, 31,0);
    tracep->declBus(c+1099,"key", false,-1, 2,0);
    tracep->declBus(c+1357,"default_out", false,-1, 31,0);
    tracep->declArray(c+110,"lut", false,-1, 139,0);
    tracep->declBus(c+1372,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+115+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+21+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+123+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+322,"lut_out", false,-1, 31,0);
    tracep->declBit(c+323,"hit", false,-1);
    tracep->declBus(c+1373,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("strbcontol ");
    tracep->declBus(c+1205,"awaddr", false,-1, 31,0);
    tracep->declBus(c+1108,"wirtelen", false,-1, 2,0);
    tracep->declBus(c+1237,"wstrb", false,-1, 3,0);
    tracep->declBus(c+1239,"awsize", false,-1, 2,0);
    tracep->declBus(c+1240,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1179,"awburst", false,-1, 1,0);
    tracep->declBus(c+1363,"device_num", false,-1, 31,0);
    tracep->declBit(c+1243,"inuart", false,-1);
    tracep->declBit(c+1244,"insram", false,-1);
    tracep->declBit(c+1245,"inflash", false,-1);
    tracep->declBit(c+1246,"inspi", false,-1);
    tracep->declBit(c+1247,"inpsram", false,-1);
    tracep->declBit(c+1248,"insdram", false,-1);
    tracep->declBus(c+1249,"bus_size", false,-1, 1,0);
    tracep->declBus(c+1152,"awsize_general", false,-1, 2,0);
    tracep->declBus(c+1153,"wstrb_general", false,-1, 3,0);
    tracep->declBus(c+1374,"wstrb_byte", false,-1, 3,0);
    tracep->declBus(c+1375,"wstrb_halfword", false,-1, 3,0);
    tracep->declBus(c+1250,"wstrb_word", false,-1, 3,0);
    tracep->declBus(c+1251,"mux", false,-1, 4,0);
    tracep->pushNamePrefix("len_mux ");
    tracep->declBus(c+1363,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1353,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1363,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1239,"out", false,-1, 2,0);
    tracep->declBus(c+1249,"key", false,-1, 1,0);
    tracep->declBus(c+1152,"default_out", false,-1, 2,0);
    tracep->declBus(c+1376,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1363,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1353,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1363,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1355,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1239,"out", false,-1, 2,0);
    tracep->declBus(c+1249,"key", false,-1, 1,0);
    tracep->declBus(c+1152,"default_out", false,-1, 2,0);
    tracep->declBus(c+1376,"lut", false,-1, 14,0);
    tracep->declBus(c+1377,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+25+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+28+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+31+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1252,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1253,"hit", false,-1);
    tracep->declBus(c+1378,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("type_mux ");
    tracep->declBus(c+1363,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1363,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1353,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1249,"out", false,-1, 1,0);
    tracep->declBus(c+1254,"key", false,-1, 2,0);
    tracep->declBus(c+1342,"default_out", false,-1, 1,0);
    tracep->declBus(c+1379,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1363,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1363,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1353,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1355,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1249,"out", false,-1, 1,0);
    tracep->declBus(c+1254,"key", false,-1, 2,0);
    tracep->declBus(c+1342,"default_out", false,-1, 1,0);
    tracep->declBus(c+1379,"lut", false,-1, 14,0);
    tracep->declBus(c+1377,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+34+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+37+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+40+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1255,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1256,"hit", false,-1);
    tracep->declBus(c+1378,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wstrb_mux ");
    tracep->declBus(c+1371,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1353,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1371,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1237,"out", false,-1, 3,0);
    tracep->declBus(c+1249,"key", false,-1, 1,0);
    tracep->declBus(c+1163,"lut", false,-1, 23,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1371,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1353,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1371,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1357,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1237,"out", false,-1, 3,0);
    tracep->declBus(c+1249,"key", false,-1, 1,0);
    tracep->declBus(c+1340,"default_out", false,-1, 3,0);
    tracep->declBus(c+1163,"lut", false,-1, 23,0);
    tracep->declBus(c+1361,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1164+i*1,"pair_list", true,(i+0), 5,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+43+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1168+i*1,"data_list", true,(i+0), 3,0);
    }
    tracep->declBus(c+1257,"lut_out", false,-1, 3,0);
    tracep->declBit(c+1258,"hit", false,-1);
    tracep->declBus(c+1373,"i", false,-1, 31,0);
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"io_d", false,-1);
    tracep->declBit(c+651,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"io_d", false,-1);
    tracep->declBit(c+651,"io_q", false,-1);
    tracep->declBit(c+651,"sync_0", false,-1);
    tracep->declBit(c+652,"sync_1", false,-1);
    tracep->declBit(c+653,"sync_2", false,-1);
    tracep->declBit(c+654,"sync_3", false,-1);
    tracep->declBit(c+655,"sync_4", false,-1);
    tracep->declBit(c+656,"sync_5", false,-1);
    tracep->declBit(c+657,"sync_6", false,-1);
    tracep->declBit(c+658,"sync_7", false,-1);
    tracep->declBit(c+659,"sync_8", false,-1);
    tracep->declBit(c+660,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+138,"auto_in_psel", false,-1);
    tracep->declBit(c+50,"auto_in_penable", false,-1);
    tracep->declBit(c+129,"auto_in_pwrite", false,-1);
    tracep->declBus(c+137,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1322,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+387,"auto_in_pready", false,-1);
    tracep->declBit(c+1330,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1287,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1262,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1263,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1264,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1265,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1266,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1267,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1268,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1269,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1270,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1271,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+158,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+138,"in_psel", false,-1);
    tracep->declBit(c+50,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+387,"in_pready", false,-1);
    tracep->declBus(c+1287,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1330,"in_pslverr", false,-1);
    tracep->declBus(c+1262,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1263,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1264,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1265,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1266,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1267,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1268,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1269,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1270,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1271,"gpio_seg_7", false,-1, 7,0);
    tracep->declBus(c+661,"state", false,-1, 1,0);
    tracep->declBit(c+159,"is_read", false,-1);
    tracep->declBit(c+160,"is_write", false,-1);
    tracep->declBus(c+662,"segment_reg_q", false,-1, 31,0);
    tracep->declBit(c+663,"req_accept", false,-1);
    tracep->pushNamePrefix("gpio_urt_core ");
    tracep->declBit(c+1260,"clk_i", false,-1);
    tracep->declBit(c+1261,"rst_i", false,-1);
    tracep->declBit(c+159,"inport_rd_i", false,-1);
    tracep->declBus(c+131,"inport_wr_i", false,-1, 3,0);
    tracep->declBus(c+158,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+130,"inport_write_data_i", false,-1, 31,0);
    tracep->declBit(c+1323,"inport_len_i", false,-1);
    tracep->declBit(c+50,"inport_penable", false,-1);
    tracep->declBit(c+663,"inport_accept_o", false,-1);
    tracep->declBus(c+1287,"gpio_rdata_o", false,-1, 31,0);
    tracep->declBit(c+387,"inport_ack_o", false,-1);
    tracep->declBus(c+1262,"gpio_out_o", false,-1, 15,0);
    tracep->declBus(c+1263,"gpio_in_o", false,-1, 15,0);
    tracep->declBus(c+662,"gpio_led_o", false,-1, 31,0);
    tracep->declBit(c+159,"read", false,-1);
    tracep->declBit(c+161,"write", false,-1);
    tracep->declBit(c+162,"addr_led", false,-1);
    tracep->declBit(c+163,"addr_switch", false,-1);
    tracep->declBit(c+164,"addr_segment", false,-1);
    tracep->declBit(c+165,"addr_reserved", false,-1);
    tracep->declBus(c+131,"byte_enable", false,-1, 3,0);
    tracep->declBus(c+664,"gpio_out_light_q", false,-1, 15,0);
    tracep->declBus(c+665,"gpio_int_sw_q", false,-1, 15,0);
    tracep->declBus(c+1380,"gpio_out_num", false,-1, 31,0);
    tracep->declBus(c+666,"state_current_q", false,-1, 1,0);
    tracep->declBus(c+166,"state_next_r", false,-1, 1,0);
    tracep->declBit(c+167,"write_enable_r", false,-1);
    tracep->declBit(c+168,"idle_ack_r", false,-1);
    tracep->declBit(c+667,"write_enable_q", false,-1);
    tracep->declBit(c+663,"accept_o", false,-1);
    tracep->declBit(c+1381,"ack_q", false,-1);
    tracep->declBit(c+387,"idle_ack_q", false,-1);
    tracep->declBit(c+667,"write_enable", false,-1);
    tracep->declBus(c+662,"segment_reg_q", false,-1, 31,0);
    tracep->declBus(c+1287,"read_data_r", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+136,"auto_in_psel", false,-1);
    tracep->declBit(c+49,"auto_in_penable", false,-1);
    tracep->declBit(c+129,"auto_in_pwrite", false,-1);
    tracep->declBus(c+137,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1322,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1327,"auto_in_pready", false,-1);
    tracep->declBit(c+1328,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1329,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1272,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1273,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+158,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+136,"in_psel", false,-1);
    tracep->declBit(c+49,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1327,"in_pready", false,-1);
    tracep->declBus(c+1329,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1328,"in_pslverr", false,-1);
    tracep->declBit(c+1272,"ps2_clk", false,-1);
    tracep->declBit(c+1273,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+1297,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1298,"auto_in_wvalid", false,-1);
    tracep->declBit(c+461,"auto_in_arready", false,-1);
    tracep->declBit(c+1299,"auto_in_arvalid", false,-1);
    tracep->declBus(c+391,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1193,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1300,"auto_in_rready", false,-1);
    tracep->declBit(c+462,"auto_in_rvalid", false,-1);
    tracep->declBus(c+463,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+464,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+462,"state", false,-1);
    tracep->declBus(c+464,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+463,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1259,"raddr", false,-1, 31,0);
    tracep->declBit(c+169,"ren", false,-1);
    tracep->declBus(c+170,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+139,"auto_in_psel", false,-1);
    tracep->declBit(c+51,"auto_in_penable", false,-1);
    tracep->declBit(c+129,"auto_in_pwrite", false,-1);
    tracep->declBus(c+127,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1322,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1288,"auto_in_pready", false,-1);
    tracep->declBit(c+1323,"auto_in_pslverr", false,-1);
    tracep->declBus(c+388,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+207,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+208,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+1283,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+127,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+139,"in_psel", false,-1);
    tracep->declBit(c+51,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1288,"in_pready", false,-1);
    tracep->declBus(c+388,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1323,"in_pslverr", false,-1);
    tracep->declBit(c+207,"qspi_sck", false,-1);
    tracep->declBit(c+208,"qspi_ce_n", false,-1);
    tracep->declBus(c+1283,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+1283,"din", false,-1, 3,0);
    tracep->declBus(c+324,"dout", false,-1, 3,0);
    tracep->declBus(c+325,"douten", false,-1, 3,0);
    tracep->declBit(c+1310,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1260,"clk_i", false,-1);
    tracep->declBit(c+1261,"rst_i", false,-1);
    tracep->declBus(c+127,"adr_i", false,-1, 31,0);
    tracep->declBus(c+130,"dat_i", false,-1, 31,0);
    tracep->declBus(c+388,"dat_o", false,-1, 31,0);
    tracep->declBus(c+131,"sel_i", false,-1, 3,0);
    tracep->declBit(c+139,"cyc_i", false,-1);
    tracep->declBit(c+139,"stb_i", false,-1);
    tracep->declBit(c+1310,"ack_o", false,-1);
    tracep->declBit(c+129,"we_i", false,-1);
    tracep->declBit(c+207,"sck", false,-1);
    tracep->declBit(c+208,"ce_n", false,-1);
    tracep->declBus(c+1283,"din", false,-1, 3,0);
    tracep->declBus(c+324,"dout", false,-1, 3,0);
    tracep->declBus(c+325,"douten", false,-1, 3,0);
    tracep->declBus(c+1382,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1383,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+737,"mr_sck", false,-1);
    tracep->declBit(c+738,"mr_ce_n", false,-1);
    tracep->declBus(c+1283,"mr_din", false,-1, 3,0);
    tracep->declBus(c+739,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+740,"mr_doe", false,-1);
    tracep->declBit(c+741,"mw_sck", false,-1);
    tracep->declBit(c+742,"mw_ce_n", false,-1);
    tracep->declBus(c+1283,"mw_din", false,-1, 3,0);
    tracep->declBus(c+326,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+743,"mw_doe", false,-1);
    tracep->declBit(c+327,"mr_rd", false,-1);
    tracep->declBit(c+744,"mr_done", false,-1);
    tracep->declBit(c+328,"mw_wr", false,-1);
    tracep->declBit(c+329,"mw_done", false,-1);
    tracep->declBit(c+139,"wb_valid", false,-1);
    tracep->declBit(c+171,"wb_we", false,-1);
    tracep->declBit(c+172,"wb_re", false,-1);
    tracep->declBit(c+745,"state", false,-1);
    tracep->declBit(c+330,"nstate", false,-1);
    tracep->declBus(c+173,"size", false,-1, 2,0);
    tracep->declBus(c+174,"byte0", false,-1, 7,0);
    tracep->declBus(c+175,"byte1", false,-1, 7,0);
    tracep->declBus(c+176,"byte2", false,-1, 7,0);
    tracep->declBus(c+177,"byte3", false,-1, 7,0);
    tracep->declBus(c+178,"wdata", false,-1, 31,0);
    tracep->declBit(c+668,"qpi_valid", false,-1);
    tracep->declBit(c+669,"qpi_ce_n", false,-1);
    tracep->declBus(c+1283,"qpi_din", false,-1, 3,0);
    tracep->declBus(c+670,"qpi_dout", false,-1, 3,0);
    tracep->declBit(c+1311,"qpi_sck", false,-1);
    tracep->declBit(c+668,"qpi_doe", false,-1);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1312,"rst_n", false,-1);
    tracep->declBus(c+179,"addr", false,-1, 23,0);
    tracep->declBit(c+327,"rd", false,-1);
    tracep->declBus(c+1384,"size", false,-1, 2,0);
    tracep->declBit(c+744,"done", false,-1);
    tracep->declBus(c+388,"line", false,-1, 31,0);
    tracep->declBit(c+737,"sck", false,-1);
    tracep->declBit(c+738,"ce_n", false,-1);
    tracep->declBus(c+1283,"din", false,-1, 3,0);
    tracep->declBus(c+739,"dout", false,-1, 3,0);
    tracep->declBit(c+740,"douten", false,-1);
    tracep->declBus(c+1382,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1383,"READ", false,-1, 0,0);
    tracep->declBus(c+1385,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+746,"state", false,-1);
    tracep->declBit(c+331,"nstate", false,-1);
    tracep->declBus(c+747,"counter", false,-1, 7,0);
    tracep->declBus(c+748,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+671+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1386,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+749,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1312,"rst_n", false,-1);
    tracep->declBus(c+180,"addr", false,-1, 23,0);
    tracep->declBus(c+178,"line", false,-1, 31,0);
    tracep->declBus(c+173,"size", false,-1, 2,0);
    tracep->declBit(c+328,"wr", false,-1);
    tracep->declBit(c+329,"done", false,-1);
    tracep->declBit(c+741,"sck", false,-1);
    tracep->declBit(c+742,"ce_n", false,-1);
    tracep->declBus(c+1283,"din", false,-1, 3,0);
    tracep->declBus(c+326,"dout", false,-1, 3,0);
    tracep->declBit(c+743,"douten", false,-1);
    tracep->declBus(c+1382,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1383,"WRITE", false,-1, 0,0);
    tracep->declBus(c+181,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+750,"state", false,-1);
    tracep->declBit(c+332,"nstate", false,-1);
    tracep->declBus(c+751,"counter", false,-1, 7,0);
    tracep->declBus(c+752,"saddr", false,-1, 23,0);
    tracep->declBus(c+1387,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("QPI ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1261,"rst", false,-1);
    tracep->declBit(c+668,"valid", false,-1);
    tracep->declBit(c+1311,"sck", false,-1);
    tracep->declBit(c+669,"ce_n", false,-1);
    tracep->declBus(c+1283,"din", false,-1, 3,0);
    tracep->declBus(c+670,"dout", false,-1, 3,0);
    tracep->declBit(c+668,"douten", false,-1);
    tracep->declBit(c+675,"finish", false,-1);
    tracep->declBus(c+1388,"H_35", false,-1, 7,0);
    tracep->declBus(c+676,"counter", false,-1, 2,0);
    tracep->declBus(c+677,"state", false,-1, 1,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+133,"auto_in_psel", false,-1);
    tracep->declBit(c+47,"auto_in_penable", false,-1);
    tracep->declBit(c+129,"auto_in_pwrite", false,-1);
    tracep->declBus(c+127,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1322,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+736,"auto_in_pready", false,-1);
    tracep->declBit(c+1323,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1286,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1284,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+729,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+730,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+731,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+732,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+733,"sdram_bundle_we", false,-1);
    tracep->declBus(c+734,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+735,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+1067,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+1285,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+127,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+133,"in_psel", false,-1);
    tracep->declBit(c+47,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+736,"in_pready", false,-1);
    tracep->declBus(c+1286,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1323,"in_pslverr", false,-1);
    tracep->declBit(c+1284,"sdram_clk", false,-1);
    tracep->declBit(c+729,"sdram_cke", false,-1);
    tracep->declBit(c+730,"sdram_cs", false,-1);
    tracep->declBit(c+731,"sdram_ras", false,-1);
    tracep->declBit(c+732,"sdram_cas", false,-1);
    tracep->declBit(c+733,"sdram_we", false,-1);
    tracep->declBus(c+734,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+735,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+1067,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+1285,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+1068,"sdram_dout_en", false,-1);
    tracep->declBus(c+1069,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+678,"state", false,-1, 1,0);
    tracep->declBit(c+1070,"req_accept", false,-1);
    tracep->declBit(c+182,"is_read", false,-1);
    tracep->declBit(c+183,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1260,"clk_i", false,-1);
    tracep->declBit(c+1261,"rst_i", false,-1);
    tracep->declBus(c+184,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+182,"inport_rd_i", false,-1);
    tracep->declBus(c+1335,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+127,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+130,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+1285,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+1070,"inport_accept_o", false,-1);
    tracep->declBit(c+736,"inport_ack_o", false,-1);
    tracep->declBit(c+1323,"inport_error_o", false,-1);
    tracep->declBus(c+1286,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1284,"sdram_clk_o", false,-1);
    tracep->declBit(c+729,"sdram_cke_o", false,-1);
    tracep->declBit(c+730,"sdram_cs_o", false,-1);
    tracep->declBit(c+731,"sdram_ras_o", false,-1);
    tracep->declBit(c+732,"sdram_cas_o", false,-1);
    tracep->declBit(c+733,"sdram_we_o", false,-1);
    tracep->declBus(c+1067,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+734,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+735,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+1069,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+1068,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1389,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1390,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1391,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1353,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1353,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1353,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1371,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1392,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1393,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1394,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1395,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1371,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1396,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1397,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1398,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1399,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1400,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1401,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1374,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1340,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1402,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1371,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1340,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1374,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1401,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1397,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1399,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1398,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1400,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1396,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1403,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1404,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1405,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1405,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1370,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1405,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1353,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1353,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1361,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+127,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+184,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+182,"ram_rd_w", false,-1);
    tracep->declBit(c+1070,"ram_accept_w", false,-1);
    tracep->declBus(c+130,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+1286,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+736,"ram_ack_w", false,-1);
    tracep->declBit(c+185,"ram_req_w", false,-1);
    tracep->declBus(c+753,"command_q", false,-1, 3,0);
    tracep->declBus(c+734,"addr_q", false,-1, 12,0);
    tracep->declBus(c+1069,"data_q", false,-1, 15,0);
    tracep->declBit(c+1071,"data_rd_en_q", false,-1);
    tracep->declBus(c+1067,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+729,"cke_q", false,-1);
    tracep->declBus(c+735,"bank_q", false,-1, 1,0);
    tracep->declBus(c+1072,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+1073,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+1285,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+754,"refresh_q", false,-1);
    tracep->declBus(c+755,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+756+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+1074,"state_q", false,-1, 3,0);
    tracep->declBus(c+333,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+334,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+760,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+761,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+186,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+187,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+188,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1371,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+762,"delay_q", false,-1, 3,0);
    tracep->declBus(c+335,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1406,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+763,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+764,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+765,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+766,"idx", false,-1, 31,0);
    tracep->declBus(c+767,"rd_q", false,-1, 3,0);
    tracep->declBit(c+736,"ack_q", false,-1);
    tracep->declArray(c+1075,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+143,"auto_in_psel", false,-1);
    tracep->declBit(c+52,"auto_in_penable", false,-1);
    tracep->declBit(c+129,"auto_in_pwrite", false,-1);
    tracep->declBus(c+135,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1322,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1290,"auto_in_pready", false,-1);
    tracep->declBit(c+1323,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1291,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+727,"spi_bundle_sck", false,-1);
    tracep->declBus(c+728,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1066,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1282,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1360,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1407,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1369,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+189,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+143,"in_psel", false,-1);
    tracep->declBit(c+52,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1290,"in_pready", false,-1);
    tracep->declBus(c+1291,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1323,"in_pslverr", false,-1);
    tracep->declBit(c+727,"spi_sck", false,-1);
    tracep->declBus(c+728,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1066,"spi_mosi", false,-1);
    tracep->declBit(c+1282,"spi_miso", false,-1);
    tracep->declBit(c+768,"spi_irq_out", false,-1);
    tracep->declBus(c+679,"state", false,-1, 2,0);
    tracep->declBit(c+680,"penable", false,-1);
    tracep->declBit(c+190,"is_xip_access", false,-1);
    tracep->declBus(c+681,"xip_paddr", false,-1, 4,0);
    tracep->declBus(c+191,"xip_pwdata", false,-1, 31,0);
    tracep->declBus(c+192,"xip_pstrb", false,-1, 3,0);
    tracep->declBit(c+682,"xip_pwirte", false,-1);
    tracep->declBit(c+769,"apb_pready", false,-1);
    tracep->declBus(c+193,"apb_addr", false,-1, 4,0);
    tracep->declBus(c+194,"apb_pwdata", false,-1, 31,0);
    tracep->declBus(c+192,"apb_pstrb", false,-1, 3,0);
    tracep->declBit(c+195,"apb_penable", false,-1);
    tracep->declBit(c+143,"apb_psel", false,-1);
    tracep->declBit(c+196,"apb_pwrite", false,-1);
    tracep->declBus(c+770,"apb_prdata", false,-1, 31,0);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1355,"Tp", false,-1, 31,0);
    tracep->declBit(c+1260,"wb_clk_i", false,-1);
    tracep->declBit(c+1261,"wb_rst_i", false,-1);
    tracep->declBus(c+193,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+194,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+770,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+192,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+196,"wb_we_i", false,-1);
    tracep->declBit(c+143,"wb_stb_i", false,-1);
    tracep->declBit(c+195,"wb_cyc_i", false,-1);
    tracep->declBit(c+769,"wb_ack_o", false,-1);
    tracep->declBit(c+1323,"wb_err_o", false,-1);
    tracep->declBit(c+768,"wb_int_o", false,-1);
    tracep->declBus(c+728,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+727,"sclk_pad_o", false,-1);
    tracep->declBit(c+1066,"mosi_pad_o", false,-1);
    tracep->declBit(c+1282,"miso_pad_i", false,-1);
    tracep->declBus(c+771,"divider", false,-1, 15,0);
    tracep->declBus(c+772,"ctrl", false,-1, 13,0);
    tracep->declBus(c+773,"ss", false,-1, 7,0);
    tracep->declBus(c+336,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+774,"rx", false,-1, 127,0);
    tracep->declBit(c+778,"rx_negedge", false,-1);
    tracep->declBit(c+779,"tx_negedge", false,-1);
    tracep->declBus(c+780,"char_len", false,-1, 6,0);
    tracep->declBit(c+781,"go", false,-1);
    tracep->declBit(c+782,"lsb", false,-1);
    tracep->declBit(c+783,"ie", false,-1);
    tracep->declBit(c+784,"ass", false,-1);
    tracep->declBit(c+197,"spi_divider_sel", false,-1);
    tracep->declBit(c+198,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+199,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+200,"spi_ss_sel", false,-1);
    tracep->declBit(c+785,"tip", false,-1);
    tracep->declBit(c+786,"pos_edge", false,-1);
    tracep->declBit(c+787,"neg_edge", false,-1);
    tracep->declBit(c+788,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1355,"Tp", false,-1, 31,0);
    tracep->declBit(c+1260,"clk_in", false,-1);
    tracep->declBit(c+1261,"rst", false,-1);
    tracep->declBit(c+785,"enable", false,-1);
    tracep->declBit(c+781,"go", false,-1);
    tracep->declBit(c+788,"last_clk", false,-1);
    tracep->declBus(c+771,"divider", false,-1, 15,0);
    tracep->declBit(c+727,"clk_out", false,-1);
    tracep->declBit(c+786,"pos_edge", false,-1);
    tracep->declBit(c+787,"neg_edge", false,-1);
    tracep->declBus(c+789,"cnt", false,-1, 15,0);
    tracep->declBit(c+790,"cnt_zero", false,-1);
    tracep->declBit(c+791,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1355,"Tp", false,-1, 31,0);
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1261,"rst", false,-1);
    tracep->declBus(c+201,"latch", false,-1, 3,0);
    tracep->declBus(c+192,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+780,"len", false,-1, 6,0);
    tracep->declBit(c+782,"lsb", false,-1);
    tracep->declBit(c+781,"go", false,-1);
    tracep->declBit(c+786,"pos_edge", false,-1);
    tracep->declBit(c+787,"neg_edge", false,-1);
    tracep->declBit(c+778,"rx_negedge", false,-1);
    tracep->declBit(c+779,"tx_negedge", false,-1);
    tracep->declBit(c+785,"tip", false,-1);
    tracep->declBit(c+788,"last", false,-1);
    tracep->declBus(c+194,"p_in", false,-1, 31,0);
    tracep->declArray(c+774,"p_out", false,-1, 127,0);
    tracep->declBit(c+727,"s_clk", false,-1);
    tracep->declBit(c+1282,"s_in", false,-1);
    tracep->declBit(c+1066,"s_out", false,-1);
    tracep->declBus(c+792,"cnt", false,-1, 7,0);
    tracep->declArray(c+774,"data", false,-1, 127,0);
    tracep->declBus(c+793,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+794,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+795,"rx_clk", false,-1);
    tracep->declBit(c+796,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+140,"auto_in_psel", false,-1);
    tracep->declBit(c+141,"auto_in_penable", false,-1);
    tracep->declBit(c+129,"auto_in_pwrite", false,-1);
    tracep->declBus(c+137,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1322,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+142,"auto_in_pready", false,-1);
    tracep->declBit(c+1323,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1289,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1280,"uart_rx", false,-1);
    tracep->declBit(c+1281,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+140,"in_psel", false,-1);
    tracep->declBit(c+141,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+142,"in_pready", false,-1);
    tracep->declBit(c+1323,"in_pslverr", false,-1);
    tracep->declBus(c+158,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+1289,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1280,"uart_rx", false,-1);
    tracep->declBit(c+1281,"uart_tx", false,-1);
    tracep->declBit(c+797,"rtsn", false,-1);
    tracep->declBit(c+1323,"ctsn", false,-1);
    tracep->declBit(c+798,"dtr_pad_o", false,-1);
    tracep->declBit(c+1323,"dsr_pad_i", false,-1);
    tracep->declBit(c+1323,"ri_pad_i", false,-1);
    tracep->declBit(c+1323,"dcd_pad_i", false,-1);
    tracep->declBit(c+799,"interrupt", false,-1);
    tracep->declBit(c+202,"reg_we", false,-1);
    tracep->declBit(c+203,"reg_re", false,-1);
    tracep->declBus(c+204,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+205,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+683,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+337,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+800,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1261,"wb_rst_i", false,-1);
    tracep->declBus(c+204,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+206,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+337,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+202,"wb_we_i", false,-1);
    tracep->declBit(c+203,"wb_re_i", false,-1);
    tracep->declBit(c+1281,"stx_pad_o", false,-1);
    tracep->declBit(c+1280,"srx_pad_i", false,-1);
    tracep->declBus(c+1403,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+800,"rts_pad_o", false,-1);
    tracep->declBit(c+798,"dtr_pad_o", false,-1);
    tracep->declBit(c+799,"int_o", false,-1);
    tracep->declBit(c+801,"enable", false,-1);
    tracep->declBit(c+802,"srx_pad", false,-1);
    tracep->declBus(c+803,"ier", false,-1, 3,0);
    tracep->declBus(c+804,"iir", false,-1, 3,0);
    tracep->declBus(c+805,"fcr", false,-1, 1,0);
    tracep->declBus(c+806,"mcr", false,-1, 4,0);
    tracep->declBus(c+807,"lcr", false,-1, 7,0);
    tracep->declBus(c+808,"msr", false,-1, 7,0);
    tracep->declBus(c+809,"dl", false,-1, 15,0);
    tracep->declBus(c+810,"scratch", false,-1, 7,0);
    tracep->declBit(c+811,"start_dlc", false,-1);
    tracep->declBit(c+812,"lsr_mask_d", false,-1);
    tracep->declBit(c+813,"msi_reset", false,-1);
    tracep->declBus(c+814,"dlc", false,-1, 15,0);
    tracep->declBus(c+815,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+816,"rx_reset", false,-1);
    tracep->declBit(c+817,"tx_reset", false,-1);
    tracep->declBit(c+818,"dlab", false,-1);
    tracep->declBit(c+1337,"cts_pad_i", false,-1);
    tracep->declBit(c+1323,"dsr_pad_i", false,-1);
    tracep->declBit(c+1323,"ri_pad_i", false,-1);
    tracep->declBit(c+1323,"dcd_pad_i", false,-1);
    tracep->declBit(c+819,"loopback", false,-1);
    tracep->declBit(c+1323,"cts", false,-1);
    tracep->declBit(c+1337,"dsr", false,-1);
    tracep->declBit(c+1337,"ri", false,-1);
    tracep->declBit(c+1337,"dcd", false,-1);
    tracep->declBit(c+820,"cts_c", false,-1);
    tracep->declBit(c+821,"dsr_c", false,-1);
    tracep->declBit(c+822,"ri_c", false,-1);
    tracep->declBit(c+823,"dcd_c", false,-1);
    tracep->declBus(c+824,"lsr", false,-1, 7,0);
    tracep->declBit(c+825,"lsr0", false,-1);
    tracep->declBit(c+826,"lsr1", false,-1);
    tracep->declBit(c+827,"lsr2", false,-1);
    tracep->declBit(c+828,"lsr3", false,-1);
    tracep->declBit(c+829,"lsr4", false,-1);
    tracep->declBit(c+830,"lsr5", false,-1);
    tracep->declBit(c+831,"lsr6", false,-1);
    tracep->declBit(c+832,"lsr7", false,-1);
    tracep->declBit(c+833,"lsr0r", false,-1);
    tracep->declBit(c+834,"lsr1r", false,-1);
    tracep->declBit(c+835,"lsr2r", false,-1);
    tracep->declBit(c+836,"lsr3r", false,-1);
    tracep->declBit(c+837,"lsr4r", false,-1);
    tracep->declBit(c+838,"lsr5r", false,-1);
    tracep->declBit(c+839,"lsr6r", false,-1);
    tracep->declBit(c+840,"lsr7r", false,-1);
    tracep->declBit(c+338,"lsr_mask", false,-1);
    tracep->declBit(c+841,"rls_int", false,-1);
    tracep->declBit(c+842,"rda_int", false,-1);
    tracep->declBit(c+843,"ti_int", false,-1);
    tracep->declBit(c+844,"thre_int", false,-1);
    tracep->declBit(c+845,"ms_int", false,-1);
    tracep->declBit(c+846,"tf_push", false,-1);
    tracep->declBit(c+847,"rf_pop", false,-1);
    tracep->declBus(c+1313,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+848,"rf_error_bit", false,-1);
    tracep->declBit(c+826,"rf_overrun", false,-1);
    tracep->declBit(c+849,"rf_push_pulse", false,-1);
    tracep->declBus(c+850,"rf_count", false,-1, 4,0);
    tracep->declBus(c+851,"tf_count", false,-1, 4,0);
    tracep->declBus(c+852,"tstate", false,-1, 2,0);
    tracep->declBus(c+853,"rstate", false,-1, 3,0);
    tracep->declBus(c+854,"counter_t", false,-1, 9,0);
    tracep->declBit(c+855,"thre_set_en", false,-1);
    tracep->declBus(c+856,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+857,"block_value", false,-1, 7,0);
    tracep->declBit(c+858,"serial_out", false,-1);
    tracep->declBit(c+859,"serial_in", false,-1);
    tracep->declBit(c+339,"lsr_mask_condition", false,-1);
    tracep->declBit(c+340,"iir_read", false,-1);
    tracep->declBit(c+341,"msr_read", false,-1);
    tracep->declBit(c+342,"fifo_read", false,-1);
    tracep->declBit(c+343,"fifo_write", false,-1);
    tracep->declBus(c+860,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+861,"lsr0_d", false,-1);
    tracep->declBit(c+862,"lsr1_d", false,-1);
    tracep->declBit(c+863,"lsr2_d", false,-1);
    tracep->declBit(c+864,"lsr3_d", false,-1);
    tracep->declBit(c+865,"lsr4_d", false,-1);
    tracep->declBit(c+866,"lsr5_d", false,-1);
    tracep->declBit(c+867,"lsr6_d", false,-1);
    tracep->declBit(c+868,"lsr7_d", false,-1);
    tracep->declBit(c+869,"rls_int_d", false,-1);
    tracep->declBit(c+870,"thre_int_d", false,-1);
    tracep->declBit(c+871,"ms_int_d", false,-1);
    tracep->declBit(c+872,"ti_int_d", false,-1);
    tracep->declBit(c+873,"rda_int_d", false,-1);
    tracep->declBit(c+874,"rls_int_rise", false,-1);
    tracep->declBit(c+875,"thre_int_rise", false,-1);
    tracep->declBit(c+876,"ms_int_rise", false,-1);
    tracep->declBit(c+877,"ti_int_rise", false,-1);
    tracep->declBit(c+878,"rda_int_rise", false,-1);
    tracep->declBit(c+879,"rls_int_pnd", false,-1);
    tracep->declBit(c+880,"rda_int_pnd", false,-1);
    tracep->declBit(c+881,"thre_int_pnd", false,-1);
    tracep->declBit(c+882,"ms_int_pnd", false,-1);
    tracep->declBit(c+883,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1355,"Tp", false,-1, 31,0);
    tracep->declBus(c+1355,"width", false,-1, 31,0);
    tracep->declBus(c+1383,"init_value", false,-1, 0,0);
    tracep->declBit(c+1261,"rst_i", false,-1);
    tracep->declBit(c+1260,"clk_i", false,-1);
    tracep->declBit(c+1323,"stage1_rst_i", false,-1);
    tracep->declBit(c+1337,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1280,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+802,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+884,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1261,"wb_rst_i", false,-1);
    tracep->declBus(c+807,"lcr", false,-1, 7,0);
    tracep->declBit(c+847,"rf_pop", false,-1);
    tracep->declBit(c+859,"srx_pad_i", false,-1);
    tracep->declBit(c+801,"enable", false,-1);
    tracep->declBit(c+816,"rx_reset", false,-1);
    tracep->declBit(c+338,"lsr_mask", false,-1);
    tracep->declBus(c+854,"counter_t", false,-1, 9,0);
    tracep->declBus(c+850,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1313,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+826,"rf_overrun", false,-1);
    tracep->declBit(c+848,"rf_error_bit", false,-1);
    tracep->declBus(c+853,"rstate", false,-1, 3,0);
    tracep->declBit(c+849,"rf_push_pulse", false,-1);
    tracep->declBus(c+885,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+886,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+887,"rshift", false,-1, 7,0);
    tracep->declBit(c+888,"rparity", false,-1);
    tracep->declBit(c+889,"rparity_error", false,-1);
    tracep->declBit(c+890,"rframing_error", false,-1);
    tracep->declBit(c+891,"rbit_in", false,-1);
    tracep->declBit(c+892,"rparity_xor", false,-1);
    tracep->declBus(c+893,"counter_b", false,-1, 7,0);
    tracep->declBit(c+894,"rf_push_q", false,-1);
    tracep->declBus(c+895,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+896,"rf_push", false,-1);
    tracep->declBit(c+897,"break_error", false,-1);
    tracep->declBit(c+898,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+899,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+900,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+901,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1340,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1374,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1401,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1397,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1399,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1398,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1400,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1396,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1403,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1404,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1408,"sr_push", false,-1, 3,0);
    tracep->declBus(c+902,"toc_value", false,-1, 9,0);
    tracep->declBus(c+903,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1409,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1370,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1371,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1377,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1261,"wb_rst_i", false,-1);
    tracep->declBit(c+849,"push", false,-1);
    tracep->declBit(c+847,"pop", false,-1);
    tracep->declBus(c+895,"data_in", false,-1, 10,0);
    tracep->declBit(c+816,"fifo_reset", false,-1);
    tracep->declBit(c+338,"reset_status", false,-1);
    tracep->declBus(c+1313,"data_out", false,-1, 10,0);
    tracep->declBit(c+826,"overrun", false,-1);
    tracep->declBus(c+850,"count", false,-1, 4,0);
    tracep->declBit(c+848,"error_bit", false,-1);
    tracep->declBus(c+1314,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+904+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+920,"top", false,-1, 3,0);
    tracep->declBus(c+921,"bottom", false,-1, 3,0);
    tracep->declBus(c+922,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+923,"word0", false,-1, 2,0);
    tracep->declBus(c+924,"word1", false,-1, 2,0);
    tracep->declBus(c+925,"word2", false,-1, 2,0);
    tracep->declBus(c+926,"word3", false,-1, 2,0);
    tracep->declBus(c+927,"word4", false,-1, 2,0);
    tracep->declBus(c+928,"word5", false,-1, 2,0);
    tracep->declBus(c+929,"word6", false,-1, 2,0);
    tracep->declBus(c+930,"word7", false,-1, 2,0);
    tracep->declBus(c+931,"word8", false,-1, 2,0);
    tracep->declBus(c+932,"word9", false,-1, 2,0);
    tracep->declBus(c+933,"word10", false,-1, 2,0);
    tracep->declBus(c+934,"word11", false,-1, 2,0);
    tracep->declBus(c+935,"word12", false,-1, 2,0);
    tracep->declBus(c+936,"word13", false,-1, 2,0);
    tracep->declBus(c+937,"word14", false,-1, 2,0);
    tracep->declBus(c+938,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1371,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1369,"data_width", false,-1, 31,0);
    tracep->declBus(c+1370,"depth", false,-1, 31,0);
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+849,"we", false,-1);
    tracep->declBus(c+920,"a", false,-1, 3,0);
    tracep->declBus(c+921,"dpra", false,-1, 3,0);
    tracep->declBus(c+939,"di", false,-1, 7,0);
    tracep->declBus(c+1314,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+684+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1261,"wb_rst_i", false,-1);
    tracep->declBus(c+807,"lcr", false,-1, 7,0);
    tracep->declBit(c+846,"tf_push", false,-1);
    tracep->declBus(c+206,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+801,"enable", false,-1);
    tracep->declBit(c+817,"tx_reset", false,-1);
    tracep->declBit(c+338,"lsr_mask", false,-1);
    tracep->declBit(c+858,"stx_pad_o", false,-1);
    tracep->declBus(c+852,"tstate", false,-1, 2,0);
    tracep->declBus(c+851,"tf_count", false,-1, 4,0);
    tracep->declBus(c+940,"counter", false,-1, 4,0);
    tracep->declBus(c+941,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+942,"shift_out", false,-1, 6,0);
    tracep->declBit(c+943,"stx_o_tmp", false,-1);
    tracep->declBit(c+944,"parity_xor", false,-1);
    tracep->declBit(c+945,"tf_pop", false,-1);
    tracep->declBit(c+946,"bit_out", false,-1);
    tracep->declBus(c+206,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1315,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+947,"tf_overrun", false,-1);
    tracep->declBus(c+1341,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1322,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1410,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1411,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1384,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1412,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1369,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1370,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1371,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1377,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+1261,"wb_rst_i", false,-1);
    tracep->declBit(c+846,"push", false,-1);
    tracep->declBit(c+945,"pop", false,-1);
    tracep->declBus(c+206,"data_in", false,-1, 7,0);
    tracep->declBit(c+817,"fifo_reset", false,-1);
    tracep->declBit(c+338,"reset_status", false,-1);
    tracep->declBus(c+1315,"data_out", false,-1, 7,0);
    tracep->declBit(c+947,"overrun", false,-1);
    tracep->declBus(c+851,"count", false,-1, 4,0);
    tracep->declBus(c+948,"top", false,-1, 3,0);
    tracep->declBus(c+949,"bottom", false,-1, 3,0);
    tracep->declBus(c+950,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1371,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1369,"data_width", false,-1, 31,0);
    tracep->declBus(c+1370,"depth", false,-1, 31,0);
    tracep->declBit(c+1260,"clk", false,-1);
    tracep->declBit(c+846,"we", false,-1);
    tracep->declBus(c+948,"a", false,-1, 3,0);
    tracep->declBus(c+949,"dpra", false,-1, 3,0);
    tracep->declBus(c+206,"di", false,-1, 7,0);
    tracep->declBus(c+1315,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+700+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBit(c+134,"auto_in_psel", false,-1);
    tracep->declBit(c+48,"auto_in_penable", false,-1);
    tracep->declBit(c+129,"auto_in_pwrite", false,-1);
    tracep->declBus(c+135,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1322,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+130,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1324,"auto_in_pready", false,-1);
    tracep->declBit(c+1325,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1326,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1274,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1275,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1276,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1277,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1278,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1279,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1260,"clock", false,-1);
    tracep->declBit(c+1261,"reset", false,-1);
    tracep->declBus(c+189,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+134,"in_psel", false,-1);
    tracep->declBit(c+48,"in_penable", false,-1);
    tracep->declBus(c+1322,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+129,"in_pwrite", false,-1);
    tracep->declBus(c+130,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1324,"in_pready", false,-1);
    tracep->declBus(c+1326,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1325,"in_pslverr", false,-1);
    tracep->declBus(c+1274,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1275,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1276,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1277,"vga_hsync", false,-1);
    tracep->declBit(c+1278,"vga_vsync", false,-1);
    tracep->declBit(c+1279,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+727,"sck", false,-1);
    tracep->declBit(c+1078,"ss", false,-1);
    tracep->declBit(c+1066,"mosi", false,-1);
    tracep->declBit(c+1316,"miso", false,-1);
    tracep->declBus(c+1052,"buffer", false,-1, 7,0);
    tracep->declBus(c+1053,"count", false,-1, 2,0);
    tracep->declBus(c+1054,"state", false,-1, 1,0);
    tracep->declBit(c+1055,"buffer_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+727,"sck", false,-1);
    tracep->declBit(c+951,"ss", false,-1);
    tracep->declBit(c+1066,"mosi", false,-1);
    tracep->declBit(c+1317,"miso", false,-1);
    tracep->declBit(c+951,"reset", false,-1);
    tracep->declBus(c+1046,"state", false,-1, 2,0);
    tracep->declBus(c+1047,"counter", false,-1, 7,0);
    tracep->declBus(c+1048,"cmd", false,-1, 7,0);
    tracep->declBus(c+1049,"addr", false,-1, 23,0);
    tracep->declBus(c+1050,"data", false,-1, 31,0);
    tracep->declBit(c+1051,"ren", false,-1);
    tracep->declBus(c+1318,"rdata", false,-1, 31,0);
    tracep->declBus(c+1319,"raddr", false,-1, 31,0);
    tracep->declBus(c+1320,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+727,"clock", false,-1);
    tracep->declBit(c+1051,"valid", false,-1);
    tracep->declBus(c+1048,"cmd", false,-1, 7,0);
    tracep->declBus(c+1319,"addr", false,-1, 31,0);
    tracep->declBus(c+1318,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+207,"sck", false,-1);
    tracep->declBit(c+208,"ce_n", false,-1);
    tracep->declBus(c+1283,"dio", false,-1, 3,0);
    tracep->declBus(c+716,"state", false,-1, 3,0);
    tracep->declBus(c+717,"inst_buffer", false,-1, 7,0);
    tracep->declBus(c+718,"addr_buffer", false,-1, 23,0);
    tracep->declBus(c+719,"inst_counter", false,-1, 2,0);
    tracep->declBus(c+720,"addr_counter", false,-1, 2,0);
    tracep->declBus(c+721,"wait_counter", false,-1, 2,0);
    tracep->declBus(c+722,"data", false,-1, 7,0);
    tracep->declBit(c+723,"finish", false,-1);
    tracep->declBus(c+724,"dio_out_reg", false,-1, 3,0);
    tracep->declBit(c+725,"dio_en", false,-1);
    tracep->declBit(c+726,"qpi_mode", false,-1);
    tracep->declBit(c+208,"reset", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1284,"clk", false,-1);
    tracep->declBit(c+729,"cke", false,-1);
    tracep->declBit(c+730,"cs", false,-1);
    tracep->declBit(c+731,"ras", false,-1);
    tracep->declBit(c+732,"cas", false,-1);
    tracep->declBit(c+733,"we", false,-1);
    tracep->declBus(c+734,"a", false,-1, 12,0);
    tracep->declBus(c+735,"ba", false,-1, 1,0);
    tracep->declBus(c+1067,"dqm", false,-1, 1,0);
    tracep->declBus(c+1285,"dq", false,-1, 15,0);
    tracep->declBus(c+344,"mode_q", false,-1, 12,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+345+i*1,"row_reg", true,(i+0), 12,0);
    }
    tracep->declBit(c+730,"command_inhibit", false,-1);
    tracep->declBit(c+952,"no_operation", false,-1);
    tracep->declBit(c+953,"active", false,-1);
    tracep->declBit(c+954,"read", false,-1);
    tracep->declBit(c+955,"write", false,-1);
    tracep->declBit(c+956,"burst_terminate", false,-1);
    tracep->declBit(c+957,"precharge", false,-1);
    tracep->declBit(c+958,"auto_refresh", false,-1);
    tracep->declBit(c+959,"load_mode_register", false,-1);
    tracep->declBit(c+960,"nop", false,-1);
    tracep->declBus(c+1363,"CAS_TIMER_W", false,-1, 31,0);
    tracep->declBus(c+349,"cas_timer_q", false,-1, 2,0);
    tracep->declBit(c+350,"cas_done", false,-1);
    tracep->declBit(c+351,"counting", false,-1);
    tracep->declBit(c+1413,"cas_start", false,-1);
    tracep->declBus(c+1363,"BL_TIMER_W", false,-1, 31,0);
    tracep->declBus(c+352,"bl_timer_q", false,-1, 2,0);
    tracep->declBit(c+353,"bl_valid", false,-1);
    tracep->declBit(c+354,"bl_start_q", false,-1);
    tracep->declBit(c+355,"bl_done", false,-1);
    tracep->declBus(c+1361,"MAX_PIPELINE", false,-1, 31,0);
    tracep->declBus(c+1414,"rd_pip_in_addr_q", false,-1, 12,0);
    tracep->declBit(c+1415,"rd_pip_in_val_q", false,-1);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+356+i*1,"pip_addr_q", true,(i+0), 12,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBit(c+362+i*1,"pip_valid_q", true,(i+0));
    }
    tracep->declBus(c+962,"data_output", false,-1, 15,0);
    tracep->declBus(c+368,"pipeline_cl", false,-1, 2,0);
    tracep->declBus(c+963,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBus(c+368,"cl", false,-1, 2,0);
    tracep->declBus(c+369,"select_bank", false,-1, 1,0);
    tracep->declBus(c+370,"select_col", false,-1, 9,0);
    tracep->declBit(c+371,"select_valid", false,-1);
    tracep->declBit(c+964,"rd_data_valid_q", false,-1);
    tracep->declBus(c+372,"dqm_pipe", false,-1, 3,0);
    tracep->declBus(c+373,"rd_dqm_out_q", false,-1, 1,0);
    tracep->declBit(c+374,"read_state_r", false,-1);
    tracep->declBus(c+1285,"sdram_data", false,-1, 15,0);
    tracep->declBus(c+375,"wr_in_addr_q", false,-1, 12,0);
    tracep->declBit(c+376,"wr_in_val_q", false,-1);
    tracep->declBus(c+377,"mode_val_q", false,-1, 12,0);
    tracep->declBit(c+378,"mode_chg_q", false,-1);
    tracep->declBus(c+379,"acti_val_q", false,-1, 14,0);
    tracep->declBit(c+380,"acti_chg_q", false,-1);
    tracep->declBus(c+1340,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1374,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1401,"STATE_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1397,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1399,"STATE_READ_DATA", false,-1, 3,0);
    tracep->declBus(c+1398,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1400,"STATE_WRITE", false,-1, 3,0);
    tracep->declBus(c+1396,"STATE_WRITE_DATA", false,-1, 3,0);
    tracep->declBus(c+1404,"STATE_MODE_REG", false,-1, 3,0);
    tracep->declBus(c+381,"state_current_q", false,-1, 3,0);
    tracep->declBus(c+1056,"state_next_r", false,-1, 3,0);
    tracep->declBit(c+1321,"valclk", false,-1);
    tracep->declBus(c+382,"prev_addr_q", false,-1, 12,0);
    tracep->declBus(c+961,"cur_addr_r", false,-1, 12,0);
    tracep->declBus(c+383,"cur_addr_b_r", false,-1, 12,0);
    tracep->declBus(c+1057,"rd_pip_in_addr_r", false,-1, 12,0);
    tracep->declBit(c+1058,"rd_pip_in_val_r", false,-1);
    tracep->declBus(c+1059,"wr_in_addr_r", false,-1, 12,0);
    tracep->declBit(c+1060,"wr_in_val_r", false,-1);
    tracep->declBit(c+1061,"bl_start_r", false,-1);
    tracep->declBit(c+1062,"mode_chg_r", false,-1);
    tracep->declBus(c+1063,"mode_val_r", false,-1, 12,0);
    tracep->declBit(c+1064,"acti_chg_r", false,-1);
    tracep->declBus(c+1065,"acti_val_r", false,-1, 14,0);
    tracep->declBit(c+384,"sig_save_addr", false,-1);
    tracep->pushNamePrefix("decoder ");
    tracep->declBit(c+730,"cs_n", false,-1);
    tracep->declBit(c+731,"ras_n", false,-1);
    tracep->declBit(c+732,"cas_n", false,-1);
    tracep->declBit(c+733,"we_n", false,-1);
    tracep->declBit(c+730,"command_inhibit", false,-1);
    tracep->declBit(c+952,"no_operation", false,-1);
    tracep->declBit(c+953,"active", false,-1);
    tracep->declBit(c+954,"read", false,-1);
    tracep->declBit(c+955,"write", false,-1);
    tracep->declBit(c+956,"burst_terminate", false,-1);
    tracep->declBit(c+957,"precharge", false,-1);
    tracep->declBit(c+958,"auto_refresh", false,-1);
    tracep->declBit(c+959,"load_mode_register", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+385,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
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
    bufp->fullCData(oldp+34,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[0]),5);
    bufp->fullCData(oldp+35,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[1]),5);
    bufp->fullCData(oldp+36,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__pair_list[2]),5);
    bufp->fullCData(oldp+37,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+38,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+39,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+40,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[0]),2);
    bufp->fullCData(oldp+41,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[1]),2);
    bufp->fullCData(oldp+42,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__data_list[2]),2);
    bufp->fullCData(oldp+43,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+44,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+45,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+46,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__key_list[3]),2);
    bufp->fullBit(oldp+47,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+48,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+49,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+50,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+51,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+52,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullCData(oldp+53,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                               ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                  << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))),2);
    bufp->fullIData(oldp+54,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                           : 0U) | 
                                         ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                           : 0U)))),32);
    bufp->fullBit(oldp+55,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+56,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+57,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+58,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+60,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+62,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+63,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+65,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+66,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+69,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+70,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+71,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+72,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+73,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+74,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+75,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+76,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+77,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+78,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+79,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+80,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+81,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+82,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+83,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+84,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+85,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+86,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+87,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+88,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+89,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+90,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+91,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+93,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+94,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+95,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+97,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+98,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+99,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+103,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+109,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+110,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__byte_enable),4);
    bufp->fullBit(oldp+132,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+133,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+134,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+135,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+136,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+137,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+138,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+139,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+142,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_psel));
    bufp->fullBit(oldp+144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+149,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+152,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+153,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+154,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+155,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+156,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+157,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+158,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__is_read));
    bufp->fullBit(oldp+160,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT____VdfgTmp_hfb738304__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write))));
    bufp->fullBit(oldp+161,((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__byte_enable))));
    bufp->fullBit(oldp+162,((0U == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullBit(oldp+163,((4U == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullBit(oldp+164,((8U == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullBit(oldp+165,((0xcU == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullCData(oldp+166,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__state_next_r),2);
    bufp->fullBit(oldp+167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__write_enable_r));
    bufp->fullBit(oldp+168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__idle_ack_r));
    bufp->fullBit(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+173,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+174,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+175,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+176,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+177,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+178,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+179,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+180,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+181,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+186,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+187,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+188,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+189,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+190,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__is_xip_access));
    bufp->fullIData(oldp+191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pwdata),32);
    bufp->fullCData(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pstrb),4);
    bufp->fullCData(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr),5);
    bufp->fullIData(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwdata),32);
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_penable));
    bufp->fullBit(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwrite));
    bufp->fullBit(oldp+197,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullBit(oldp+198,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__spi_tx_sel),4);
    bufp->fullBit(oldp+200,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+204,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT___asic_psram_sck));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__psram__DOT__reset));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+210,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
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
    bufp->fullSData(oldp+320,((0xffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),16);
    bufp->fullCData(oldp+321,((0xffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),8);
    bufp->fullIData(oldp+322,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+324,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+325,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+326,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+327,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullSData(oldp+344,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q),13);
    bufp->fullSData(oldp+345,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[0]),13);
    bufp->fullSData(oldp+346,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[1]),13);
    bufp->fullSData(oldp+347,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[2]),13);
    bufp->fullSData(oldp+348,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[3]),13);
    bufp->fullCData(oldp+349,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_timer_q),3);
    bufp->fullBit(oldp+350,(((0U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_timer_q)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__counting))));
    bufp->fullBit(oldp+351,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__counting));
    bufp->fullCData(oldp+352,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_timer_q),3);
    bufp->fullBit(oldp+353,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_valid));
    bufp->fullBit(oldp+354,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_start_q));
    bufp->fullBit(oldp+355,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_done));
    bufp->fullSData(oldp+356,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[0]),13);
    bufp->fullSData(oldp+357,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[1]),13);
    bufp->fullSData(oldp+358,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[2]),13);
    bufp->fullSData(oldp+359,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[3]),13);
    bufp->fullSData(oldp+360,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[4]),13);
    bufp->fullSData(oldp+361,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[5]),13);
    bufp->fullBit(oldp+362,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[0]));
    bufp->fullBit(oldp+363,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[1]));
    bufp->fullBit(oldp+364,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[2]));
    bufp->fullBit(oldp+365,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[3]));
    bufp->fullBit(oldp+366,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[4]));
    bufp->fullBit(oldp+367,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[5]));
    bufp->fullCData(oldp+368,((7U & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q) 
                                     >> 4U))),3);
    bufp->fullCData(oldp+369,((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h7c6dd055__0) 
                                     >> 0xbU))),2);
    bufp->fullSData(oldp+370,((0x3ffU & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h7c6dd055__0))),10);
    bufp->fullBit(oldp+371,(((5U >= (7U & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q) 
                                            >> 4U) 
                                           - (IData)(2U)))) 
                             & vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q
                             [(7U & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q) 
                                      >> 4U) - (IData)(2U)))])));
    bufp->fullCData(oldp+372,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__dqm_pipe),4);
    bufp->fullCData(oldp+373,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_dqm_out_q),2);
    bufp->fullBit(oldp+374,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                             | (4U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)))));
    bufp->fullSData(oldp+375,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_addr_q),13);
    bufp->fullBit(oldp+376,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_val_q));
    bufp->fullSData(oldp+377,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_val_q),13);
    bufp->fullBit(oldp+378,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_chg_q));
    bufp->fullSData(oldp+379,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_val_q),15);
    bufp->fullBit(oldp+380,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_chg_q));
    bufp->fullCData(oldp+381,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q),4);
    bufp->fullSData(oldp+382,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__prev_addr_q),13);
    bufp->fullSData(oldp+383,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cur_addr_b_r),13);
    bufp->fullBit(oldp+384,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                             | ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                                | ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                                   | (7U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)))))));
    bufp->fullIData(oldp+385,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+386,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullBit(oldp+387,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__idle_ack_q));
    bufp->fullIData(oldp+388,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+391,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+401,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+402,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+403,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+404,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+405,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+406,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+433,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullQData(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+442,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+443,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+448,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+452,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+454,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+455,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+456,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+457,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+461,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+462,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+464,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+468,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+472,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+484,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+486,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+488,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+492,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+494,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+496,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+498,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+501,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+502,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+503,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+506,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+507,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+510,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+512,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+514,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+516,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+517,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+518,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+521,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+522,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+524,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+525,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+526,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+529,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+530,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+532,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+533,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+534,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+536,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+537,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+538,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+540,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+541,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+542,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+544,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+545,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+546,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+548,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+549,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+550,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+552,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+553,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+554,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+557,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+558,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+560,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+561,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+562,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+565,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+566,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+569,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+570,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+572,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+573,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+574,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+575,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+577,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+581,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+582,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+585,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+589,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+590,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+593,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+594,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+597,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+598,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+601,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+602,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+605,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+606,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+609,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+613,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+614,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+615,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+617,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+618,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+621,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+622,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+623,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+624,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+625,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+626,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+628,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+629,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+630,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+632,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+633,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+634,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+637,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+639,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+641,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+642,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+643,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+644,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullCData(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready),2);
    bufp->fullBit(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+647,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+649,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready) 
                                   >> 1U))));
    bufp->fullCData(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state),2);
    bufp->fullBit(oldp+651,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+652,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+653,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+655,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+656,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+658,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+660,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__state),2);
    bufp->fullIData(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__segment_reg_q),32);
    bufp->fullBit(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__accept_o));
    bufp->fullSData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__gpio_out_light_q),16);
    bufp->fullSData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__gpio_int_sw_q),16);
    bufp->fullCData(oldp+666,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__state_current_q),2);
    bufp->fullBit(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__write_enable_q));
    bufp->fullBit(oldp+668,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))));
    bufp->fullBit(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__qpi_ce_n));
    bufp->fullCData(oldp+670,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))
                                ? (1U & (0x35U >> (7U 
                                                   & ((IData)(7U) 
                                                      - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter)))))
                                : 0U)),4);
    bufp->fullCData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+673,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+674,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullBit(oldp+675,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__finish));
    bufp->fullCData(oldp+676,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter),3);
    bufp->fullCData(oldp+677,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state),2);
    bufp->fullCData(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+679,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state),3);
    bufp->fullBit(oldp+680,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__penable));
    bufp->fullCData(oldp+681,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
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
    bufp->fullBit(oldp+682,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                             | ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                | ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                   | ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                      | (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))))))));
    bufp->fullCData(oldp+683,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+684,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+685,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+686,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+687,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+688,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+689,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+690,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+691,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+692,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+693,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+694,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+695,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+696,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+697,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+698,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+699,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+701,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+702,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+704,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+705,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+706,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+707,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+708,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+709,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+715,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+716,(vlSelf->ysyxSoCFull__DOT__psram__DOT__state),4);
    bufp->fullCData(oldp+717,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_buffer),8);
    bufp->fullIData(oldp+718,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_buffer),24);
    bufp->fullCData(oldp+719,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_counter),3);
    bufp->fullCData(oldp+720,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_counter),3);
    bufp->fullCData(oldp+721,(vlSelf->ysyxSoCFull__DOT__psram__DOT__wait_counter),3);
    bufp->fullCData(oldp+722,(vlSelf->ysyxSoCFull__DOT__psram__DOT__data),8);
    bufp->fullBit(oldp+723,(vlSelf->ysyxSoCFull__DOT__psram__DOT__finish));
    bufp->fullCData(oldp+724,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_out_reg),4);
    bufp->fullBit(oldp+725,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_en));
    bufp->fullBit(oldp+726,(vlSelf->ysyxSoCFull__DOT__psram__DOT__qpi_mode));
    bufp->fullBit(oldp+727,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+728,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+729,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+730,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+731,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+732,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+733,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+734,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+735,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullBit(oldp+736,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullBit(oldp+737,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+738,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+739,(((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                ? 0xeU : ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                           ? 0xbU : 
                                          (0xfU & (
                                                   (8U 
                                                    == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                                    ? 
                                                   (vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr 
                                                    >> 0x14U)
                                                    : 
                                                   ((9U 
                                                     == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
                                                     ? 
                                                    (vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr 
                                                     >> 0x10U)
                                                     : 
                                                    ((0xaU 
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
                                                         : 0U)))))))))),4);
    bufp->fullBit(oldp+740,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+741,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+742,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+743,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+744,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+746,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+747,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+748,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+749,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+750,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+752,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullCData(oldp+753,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+754,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+756,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+758,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+759,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+760,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+761,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+762,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+763,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+764,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+765,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+766,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+767,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullBit(oldp+768,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullBit(oldp+769,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready));
    bufp->fullIData(oldp+770,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_prdata),32);
    bufp->fullSData(oldp+771,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+772,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+773,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+774,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+778,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+779,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+780,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+781,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+782,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+783,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+784,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+785,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+786,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+788,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+789,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+790,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+791,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+793,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+795,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+796,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+797,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+798,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+799,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+800,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+801,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+803,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+804,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+805,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+806,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+807,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+808,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+809,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+810,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+811,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+812,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+814,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+815,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+816,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+818,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+819,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+820,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+821,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+822,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+823,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+824,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+827,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+828,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+829,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+830,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+833,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+834,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+836,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+837,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+839,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+840,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+841,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+843,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+848,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+850,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+855,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+858,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+860,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+861,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+862,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+864,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+866,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+867,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+868,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+869,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+870,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+874,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+875,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+876,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+877,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+878,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+894,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+897,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+898,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+899,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+900,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+901,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+903,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+920,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+921,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+922,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+923,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+928,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+929,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+930,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+931,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+932,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+933,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+936,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+937,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+938,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+939,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+940,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+941,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+942,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+943,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+944,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+945,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+946,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+947,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+948,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+949,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+950,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+951,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullBit(oldp+952,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6beba8fe__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullBit(oldp+953,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__active));
    bufp->fullBit(oldp+954,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__read));
    bufp->fullBit(oldp+955,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__write));
    bufp->fullBit(oldp+956,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__burst_terminate));
    bufp->fullBit(oldp+957,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6818f070__0))));
    bufp->fullBit(oldp+958,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h84ea0254__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullBit(oldp+959,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__load_mode_register));
    bufp->fullBit(oldp+960,((((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h84ea0254__0) 
                              | (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6beba8fe__0)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+961,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cur_addr_r),13);
    bufp->fullSData(oldp+962,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_data_valid_q)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__sdram_data_input_i)
                                : 0U)),16);
    bufp->fullSData(oldp+963,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__sdram_data_input_i),16);
    bufp->fullBit(oldp+964,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_data_valid_q));
    bufp->fullIData(oldp+965,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+966,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+967,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+968,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+969,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+972,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+973,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+975,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+976,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+977,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+978,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+979,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+980,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+981,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+983,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+984,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+985,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+987,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+988,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+989,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+990,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+991,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+992,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+993,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+994,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+995,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+996,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+997,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+998,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+999,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+1000,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+1001,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+1002,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+1003,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+1004,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+1005,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[4]),32);
    bufp->fullIData(oldp+1006,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[5]),32);
    bufp->fullIData(oldp+1007,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+1008,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+1009,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+1010,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+1011,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+1012,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+1013,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+1014,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+1015,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+1016,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+1017,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+1018,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+1019,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+1020,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+1021,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+1022,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+1023,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+1024,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+1025,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+1026,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+1027,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+1029,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+1030,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+1031,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+1032,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+1034,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+1038,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[4]),32);
    bufp->fullIData(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[5]),32);
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+1046,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+1047,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+1048,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+1049,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+1050,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+1051,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                              & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+1052,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer),8);
    bufp->fullCData(oldp+1053,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count),3);
    bufp->fullCData(oldp+1054,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state),2);
    bufp->fullBit(oldp+1055,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                    >> (7U & ((IData)(7U) 
                                              - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))));
    bufp->fullCData(oldp+1056,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_next_r),4);
    bufp->fullSData(oldp+1057,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_addr_r),13);
    bufp->fullBit(oldp+1058,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_val_r));
    bufp->fullSData(oldp+1059,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_addr_r),13);
    bufp->fullBit(oldp+1060,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_val_r));
    bufp->fullBit(oldp+1061,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_start_r));
    bufp->fullBit(oldp+1062,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_chg_r));
    bufp->fullSData(oldp+1063,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_val_r),13);
    bufp->fullBit(oldp+1064,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_chg_r));
    bufp->fullSData(oldp+1065,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_val_r),15);
    bufp->fullBit(oldp+1066,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullCData(oldp+1067,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullBit(oldp+1068,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+1069,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+1070,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                              | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullBit(oldp+1071,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+1072,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+1073,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullCData(oldp+1074,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullWData(oldp+1075,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+1078,(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss));
    bufp->fullCData(oldp+1079,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+1080,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__arsize_out_reg),3);
    bufp->fullBit(oldp+1081,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+1082,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+1083,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+1084,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullBit(oldp+1085,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullBit(oldp+1086,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+1087,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 0xfU))),5);
    bufp->fullCData(oldp+1088,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 0x14U))),5);
    bufp->fullCData(oldp+1089,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 7U))),5);
    bufp->fullIData(oldp+1090,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+1091,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1092,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1093,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1094,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                 | ((0x33U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | ((0x6fU == (0x7fU 
                                                  & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                       | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+1095,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1096,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1097,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+1098,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                      >> 0xcU))),3);
    bufp->fullCData(oldp+1099,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+1100,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                    >> 0x1eU))));
    bufp->fullBit(oldp+1101,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1102,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1103,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1104,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+1105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+1106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+1107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+1108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+1109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+1110,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                                << 1U)),2);
    bufp->fullCData(oldp+1111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+1112,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+1113,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U)),2);
    bufp->fullCData(oldp+1114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullCData(oldp+1115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[0]),3);
    bufp->fullCData(oldp+1116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[1]),3);
    bufp->fullCData(oldp+1117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[0]),3);
    bufp->fullCData(oldp+1118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[1]),3);
    bufp->fullCData(oldp+1119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+1120,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+1121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+1122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+1123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+1124,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1125,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1126,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1127,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+1128,(((IData)((0x6000U == 
                                         (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                 ? 8U : ((1U & VL_REDXOR_16(
                                                            (0x6000U 
                                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                          ? 9U : 3U))),4);
    bufp->fullCData(oldp+1129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+1130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1131,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+1132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+1133,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1134,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+1135,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+1136,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+1137,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+1138,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+1139,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+1140,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 | ((0x17U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+1141,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1142,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))));
    bufp->fullCData(oldp+1143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),3);
    bufp->fullSData(oldp+1144,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                >> 0x14U)),12);
    bufp->fullCData(oldp+1145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),3);
    bufp->fullCData(oldp+1146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+1148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+1149,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    >> 1U))));
    bufp->fullCData(oldp+1150,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : 2U))),3);
    bufp->fullCData(oldp+1151,(((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 1U : ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 2U : 0U))),2);
    bufp->fullCData(oldp+1152,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : ((4U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 2U
                                                   : 0U)))),3);
    bufp->fullCData(oldp+1153,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullWData(oldp+1154,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1163,((0x11830U | ((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullCData(oldp+1164,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[0]),6);
    bufp->fullCData(oldp+1165,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[1]),6);
    bufp->fullCData(oldp+1166,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[2]),6);
    bufp->fullCData(oldp+1167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[3]),6);
    bufp->fullCData(oldp+1168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[0]),4);
    bufp->fullCData(oldp+1169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[1]),4);
    bufp->fullCData(oldp+1170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[2]),4);
    bufp->fullCData(oldp+1171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[3]),4);
    bufp->fullIData(oldp+1172,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullCData(oldp+1173,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullIData(oldp+1174,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullCData(oldp+1175,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullIData(oldp+1176,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullCData(oldp+1178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awsize_out_reg),3);
    bufp->fullCData(oldp+1179,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullIData(oldp+1180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullCData(oldp+1181,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullIData(oldp+1182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1186,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullCData(oldp+1187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullIData(oldp+1188,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1189,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1190,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1191,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1192,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1193,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1198,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
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
    bufp->fullBit(oldp+1199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullCData(oldp+1211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+1212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+1213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[0]),3);
    bufp->fullCData(oldp+1214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[1]),3);
    bufp->fullIData(oldp+1215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullCData(oldp+1221,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+1222,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+1223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[0]),3);
    bufp->fullCData(oldp+1224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[1]),3);
    bufp->fullIData(oldp+1225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1226,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1227,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1228,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1230,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1232,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1234,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1235,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+1236,(((0x1fU >= (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                             ? (3U 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                             : 0U) 
                                           << 3U)) ? 
                                (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                       ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                       : 0U) << 3U))
                                 : 0U)),32);
    bufp->fullCData(oldp+1237,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__wstrb),4);
    bufp->fullIData(oldp+1238,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__aligned_sram)
                                 ? (0xfffffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),32);
    bufp->fullCData(oldp+1239,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awsize),3);
    bufp->fullCData(oldp+1240,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                 ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : 0U)),2);
    bufp->fullBit(oldp+1241,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__aligned_sram));
    bufp->fullCData(oldp+1242,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),2);
    bufp->fullBit(oldp+1243,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__inuart));
    bufp->fullBit(oldp+1244,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__insram));
    bufp->fullBit(oldp+1245,(((0x30000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x3fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1246,(((0x10001000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x10001fffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1247,(((0x80000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x9fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1248,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__insdram));
    bufp->fullCData(oldp+1249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size),2);
    bufp->fullCData(oldp+1250,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
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
    bufp->fullCData(oldp+1251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux),5);
    bufp->fullCData(oldp+1252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1254,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT____Vcellinp__type_mux__key),3);
    bufp->fullCData(oldp+1255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__lut_out),4);
    bufp->fullBit(oldp+1258,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+1259,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1260,(vlSelf->clock));
    bufp->fullBit(oldp+1261,(vlSelf->reset));
    bufp->fullSData(oldp+1262,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1263,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1264,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1265,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1266,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1267,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1268,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1269,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1270,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1271,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1272,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1273,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1274,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1275,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1276,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1277,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1278,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1279,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1280,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1281,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1282,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
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
    bufp->fullCData(oldp+1283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__din),4);
    bufp->fullBit(oldp+1284,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullSData(oldp+1285,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                    ? 0U : 0xffffU) 
                                  & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                        ? 0U : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q)) 
                                      & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                          ? 0U : 0xffffU)) 
                                     & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                         ? 0U : 0xffffU))) 
                                 & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
                                     ? 0U : 0xffffU)) 
                                | ((((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__dq__out__strong__out0) 
                                     & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_he546b431__0)
                                         ? 0xffU : 0U)) 
                                    | ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__dq__out__strong__out1) 
                                       & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h09eb8e3c__0)
                                            ? 0xffU
                                            : 0U) << 8U))) 
                                   & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_he546b431__0)
                                        ? 0xffU : 0U) 
                                      | (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h09eb8e3c__0)
                                           ? 0xffU : 0U) 
                                         << 8U))))),16);
    bufp->fullIData(oldp+1286,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                 << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullIData(oldp+1287,(((8U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                 ? ((4U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                     ? 0U : ((2U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                              ? 0U : 
                                             ((1U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                               ? 0U
                                               : vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__segment_reg_q)))
                                 : ((4U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                     ? ((2U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                         ? 0U : ((1U 
                                                  & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                                  ? 0U
                                                  : (IData)(vlSelf->externalPins_gpio_in)))
                                     : ((2U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                         ? 0U : ((1U 
                                                  & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
                                                  ? 0U
                                                  : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__gpio_out_light_q)))))),32);
    bufp->fullBit(oldp+1288,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1289,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullBit(oldp+1290,((1U & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                     ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                     : ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                         ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                         : 0U)))));
    bufp->fullIData(oldp+1291,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+1292,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullCData(oldp+1293,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1294,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1295,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1296,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1297,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
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
    bufp->fullBit(oldp+1298,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1299,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1300,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1301,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullIData(oldp+1302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullBit(oldp+1304,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1305,(((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1306,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state)))));
    bufp->fullBit(oldp+1307,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                     & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready)) 
                                    >> 1U))));
    bufp->fullSData(oldp+1308,((0xffffU & ((2U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                            ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                               [1U] 
                                               >> 0x10U)
                                            : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                           [1U]))),16);
    bufp->fullCData(oldp+1309,((0xffU & ((0U == (3U 
                                                 & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))
                                          ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                         [1U] : ((1U 
                                                  == 
                                                  (3U 
                                                   & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))
                                                  ? 
                                                 (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                                  [1U] 
                                                  >> 8U)
                                                  : 
                                                 ((2U 
                                                   == 
                                                   (3U 
                                                    & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))
                                                   ? 
                                                  (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                                   [1U] 
                                                   >> 0x10U)
                                                   : 
                                                  (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                                   [1U] 
                                                   >> 0x18U)))))),8);
    bufp->fullBit(oldp+1310,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1311,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state)) 
                              & (IData)(vlSelf->clock))));
    bufp->fullBit(oldp+1312,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1313,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullBit(oldp+1316,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
                                    | ((2U != (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state)) 
                                       | ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                          >> (7U & 
                                              ((IData)(7U) 
                                               - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))))));
    bufp->fullBit(oldp+1317,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullIData(oldp+1318,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1319,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1320,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullBit(oldp+1321,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__valclk));
    bufp->fullCData(oldp+1322,(1U),3);
    bufp->fullBit(oldp+1323,(0U));
    bufp->fullBit(oldp+1324,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1325,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1326,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1327,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1328,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1329,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1330,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullCData(oldp+1331,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1332,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullBit(oldp+1333,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1334,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1335,(0U),8);
    bufp->fullCData(oldp+1336,(1U),2);
    bufp->fullBit(oldp+1337,(1U));
    bufp->fullBit(oldp+1338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1339,(0U),32);
    bufp->fullCData(oldp+1340,(0U),4);
    bufp->fullCData(oldp+1341,(0U),3);
    bufp->fullCData(oldp+1342,(0U),2);
    bufp->fullBit(oldp+1343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1345,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1350,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1352,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1353,(2U),32);
    bufp->fullIData(oldp+1354,(2U),32);
    bufp->fullIData(oldp+1355,(1U),32);
    bufp->fullIData(oldp+1356,(0x20U),32);
    bufp->fullIData(oldp+1357,(0U),32);
    bufp->fullIData(oldp+1358,(0x21U),32);
    bufp->fullIData(oldp+1359,(2U),32);
    bufp->fullIData(oldp+1360,(0x30000000U),32);
    bufp->fullIData(oldp+1361,(6U),32);
    bufp->fullIData(oldp+1362,(0xcU),32);
    bufp->fullIData(oldp+1363,(3U),32);
    __Vtemp_ha129e8f8__0[0U] = 0xfc467895U;
    __Vtemp_ha129e8f8__0[1U] = 0x93414684U;
    __Vtemp_ha129e8f8__0[2U] = 0xc00182U;
    bufp->fullWData(oldp+1364,(__Vtemp_ha129e8f8__0),90);
    bufp->fullIData(oldp+1367,(0xfU),32);
    bufp->fullIData(oldp+1368,(6U),32);
    bufp->fullIData(oldp+1369,(8U),32);
    bufp->fullIData(oldp+1370,(0x10U),32);
    bufp->fullIData(oldp+1371,(4U),32);
    bufp->fullIData(oldp+1372,(0x23U),32);
    bufp->fullIData(oldp+1373,(4U),32);
    bufp->fullCData(oldp+1374,(1U),4);
    bufp->fullCData(oldp+1375,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword),4);
    bufp->fullSData(oldp+1376,(0x223aU),15);
    bufp->fullIData(oldp+1377,(5U),32);
    bufp->fullIData(oldp+1378,(3U),32);
    bufp->fullSData(oldp+1379,(0x4d45U),15);
    bufp->fullIData(oldp+1380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__gpio_out_num),32);
    bufp->fullBit(oldp+1381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__ack_q));
    bufp->fullBit(oldp+1382,(0U));
    bufp->fullBit(oldp+1383,(1U));
    bufp->fullCData(oldp+1384,(4U),3);
    bufp->fullCData(oldp+1385,(0x1bU),8);
    bufp->fullCData(oldp+1386,(0xebU),8);
    bufp->fullCData(oldp+1387,(0x38U),8);
    bufp->fullCData(oldp+1388,(0x35U),8);
    bufp->fullIData(oldp+1389,(0x64U),32);
    bufp->fullIData(oldp+1390,(0x18U),32);
    bufp->fullIData(oldp+1391,(9U),32);
    bufp->fullIData(oldp+1392,(0xdU),32);
    bufp->fullIData(oldp+1393,(0x2000U),32);
    bufp->fullIData(oldp+1394,(0x2710U),32);
    bufp->fullIData(oldp+1395,(0x30cU),32);
    bufp->fullCData(oldp+1396,(7U),4);
    bufp->fullCData(oldp+1397,(3U),4);
    bufp->fullCData(oldp+1398,(5U),4);
    bufp->fullCData(oldp+1399,(4U),4);
    bufp->fullCData(oldp+1400,(6U),4);
    bufp->fullCData(oldp+1401,(2U),4);
    bufp->fullSData(oldp+1402,(0x21U),13);
    bufp->fullCData(oldp+1403,(8U),4);
    bufp->fullCData(oldp+1404,(9U),4);
    bufp->fullIData(oldp+1405,(0xaU),32);
    bufp->fullIData(oldp+1406,(0x11U),32);
    bufp->fullIData(oldp+1407,(0x3fffffffU),32);
    bufp->fullCData(oldp+1408,(0xaU),4);
    bufp->fullIData(oldp+1409,(0xbU),32);
    bufp->fullCData(oldp+1410,(2U),3);
    bufp->fullCData(oldp+1411,(3U),3);
    bufp->fullCData(oldp+1412,(5U),3);
    bufp->fullBit(oldp+1413,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_start));
    bufp->fullSData(oldp+1414,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_addr_q),13);
    bufp->fullBit(oldp+1415,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_val_q));
}
