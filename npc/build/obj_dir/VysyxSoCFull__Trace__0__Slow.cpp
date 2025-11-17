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
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+1308,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1309,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1310,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1311,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1312,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1313,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1314,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1315,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1316,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1317,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1318,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1319,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1320,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1321,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1322,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1323,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1324,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1325,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1326,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1327,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+1308,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1309,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1310,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1311,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1312,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1313,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1314,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1315,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1316,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1317,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1318,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1319,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1320,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1321,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1322,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1323,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1324,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1325,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1326,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1327,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+772,"spi_sck", false,-1);
    tracep->declBus(c+773,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1112,"spi_mosi", false,-1);
    tracep->declBit(c+1328,"spi_miso", false,-1);
    tracep->declBit(c+1326,"uart_rx", false,-1);
    tracep->declBit(c+1327,"uart_tx", false,-1);
    tracep->declBit(c+212,"psram_sck", false,-1);
    tracep->declBit(c+213,"psram_ce_n", false,-1);
    tracep->declBus(c+1329,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1330,"sdram_clk", false,-1);
    tracep->declBit(c+774,"sdram_cke", false,-1);
    tracep->declBit(c+775,"sdram_cs", false,-1);
    tracep->declBit(c+776,"sdram_ras", false,-1);
    tracep->declBit(c+777,"sdram_cas", false,-1);
    tracep->declBit(c+778,"sdram_we", false,-1);
    tracep->declBus(c+779,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+780,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+1113,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+1331,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1308,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1309,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1310,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1311,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1312,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1313,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1314,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1315,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1316,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1317,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1318,"ps2_clk", false,-1);
    tracep->declBit(c+1319,"ps2_data", false,-1);
    tracep->declBus(c+1320,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1321,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1322,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1323,"vga_hsync", false,-1);
    tracep->declBit(c+1324,"vga_vsync", false,-1);
    tracep->declBit(c+1325,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+128,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+129,"in_psel", false,-1);
    tracep->declBit(c+349,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+214,"in_pready", false,-1);
    tracep->declBus(c+215,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+133,"in_pslverr", false,-1);
    tracep->declBus(c+128,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+129,"out_psel", false,-1);
    tracep->declBit(c+349,"out_penable", false,-1);
    tracep->declBus(c+1370,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"out_pwrite", false,-1);
    tracep->declBus(c+131,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+214,"out_pready", false,-1);
    tracep->declBus(c+215,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+133,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+129,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+349,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+128,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1370,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+214,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+133,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+215,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+134,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+47,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+128,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1370,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+781,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1371,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+1332,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+135,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+48,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+136,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1370,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+782,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1372,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1373,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+137,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+49,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+138,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1370,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+350,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1374,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+351,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+139,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+50,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+138,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1370,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+352,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1375,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1333,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+140,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+51,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+128,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1370,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1334,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1371,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+353,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+141,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+142,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+138,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1370,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+143,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1371,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1335,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+144,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+52,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+130,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+136,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1370,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+1336,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1371,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+1337,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+145,"sel_0", false,-1);
    tracep->declBit(c+146,"sel_1", false,-1);
    tracep->declBit(c+147,"sel_2", false,-1);
    tracep->declBit(c+148,"sel_3", false,-1);
    tracep->declBit(c+149,"sel_4", false,-1);
    tracep->declBit(c+150,"sel_5", false,-1);
    tracep->declBit(c+151,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+152,"auto_in_awready", false,-1);
    tracep->declBit(c+153,"auto_in_awvalid", false,-1);
    tracep->declBus(c+354,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1218,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1219,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+152,"auto_in_wready", false,-1);
    tracep->declBit(c+154,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+216,"auto_in_bready", false,-1);
    tracep->declBit(c+217,"auto_in_bvalid", false,-1);
    tracep->declBus(c+355,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+53,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+155,"auto_in_arready", false,-1);
    tracep->declBit(c+156,"auto_in_arvalid", false,-1);
    tracep->declBus(c+356,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1222,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1125,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+218,"auto_in_rready", false,-1);
    tracep->declBit(c+219,"auto_in_rvalid", false,-1);
    tracep->declBus(c+357,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+220,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+53,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+129,"auto_out_psel", false,-1);
    tracep->declBit(c+349,"auto_out_penable", false,-1);
    tracep->declBit(c+130,"auto_out_pwrite", false,-1);
    tracep->declBus(c+128,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+131,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+214,"auto_out_pready", false,-1);
    tracep->declBit(c+133,"auto_out_pslverr", false,-1);
    tracep->declBus(c+215,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+349,"nodeOut_penable", false,-1);
    tracep->declBus(c+358,"state", false,-1, 1,0);
    tracep->declBit(c+155,"accept_read", false,-1);
    tracep->declBit(c+152,"accept_write", false,-1);
    tracep->declBit(c+359,"is_write_r", false,-1);
    tracep->declBit(c+130,"is_write", false,-1);
    tracep->declBus(c+357,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+355,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+360,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+361,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+362,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+363,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+157,"resp", false,-1, 1,0);
    tracep->declBus(c+364,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+53,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+219,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+365,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+217,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+366,"auto_in_awready", false,-1);
    tracep->declBit(c+92,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1376,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1223,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1377,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1224,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1225,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+367,"auto_in_wready", false,-1);
    tracep->declBit(c+93,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1226,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1378,"auto_in_wlast", false,-1);
    tracep->declBit(c+1338,"auto_in_bready", false,-1);
    tracep->declBit(c+221,"auto_in_bvalid", false,-1);
    tracep->declBus(c+222,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+223,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+368,"auto_in_arready", false,-1);
    tracep->declBit(c+94,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1379,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1228,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1380,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1126,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1381,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+95,"auto_in_rready", false,-1);
    tracep->declBit(c+224,"auto_in_rvalid", false,-1);
    tracep->declBus(c+225,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+56,"auto_in_rlast", false,-1);
    tracep->declBit(c+226,"auto_out_awready", false,-1);
    tracep->declBit(c+96,"auto_out_awvalid", false,-1);
    tracep->declBus(c+354,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1218,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1219,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+369,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+227,"auto_out_wready", false,-1);
    tracep->declBit(c+97,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+98,"auto_out_wlast", false,-1);
    tracep->declBit(c+228,"auto_out_bready", false,-1);
    tracep->declBit(c+229,"auto_out_bvalid", false,-1);
    tracep->declBus(c+222,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+230,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+231,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+232,"auto_out_arready", false,-1);
    tracep->declBit(c+99,"auto_out_arvalid", false,-1);
    tracep->declBus(c+356,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1222,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1125,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+370,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+95,"auto_out_rready", false,-1);
    tracep->declBit(c+224,"auto_out_rvalid", false,-1);
    tracep->declBus(c+225,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+57,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+233,"auto_out_rlast", false,-1);
    tracep->declBit(c+97,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+371,"w_idle", false,-1);
    tracep->declBit(c+234,"in_awready", false,-1);
    tracep->declBit(c+372,"busy", false,-1);
    tracep->declBus(c+373,"r_addr", false,-1, 31,0);
    tracep->declBus(c+374,"r_len", false,-1, 7,0);
    tracep->declBus(c+375,"len", false,-1, 7,0);
    tracep->declBus(c+1229,"addr", false,-1, 31,0);
    tracep->declBit(c+376,"busy_1", false,-1);
    tracep->declBus(c+377,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+378,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+379,"len_1", false,-1, 7,0);
    tracep->declBus(c+1230,"addr_1", false,-1, 31,0);
    tracep->declBit(c+380,"wbeats_latched", false,-1);
    tracep->declBit(c+96,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+100,"wbeats_valid", false,-1);
    tracep->declBus(c+381,"w_counter", false,-1, 8,0);
    tracep->declBus(c+101,"w_todo", false,-1, 8,0);
    tracep->declBit(c+98,"w_last", false,-1);
    tracep->declBit(c+228,"nodeOut_bready", false,-1);
    tracep->declBus(c+382,"error_0", false,-1, 1,0);
    tracep->declBus(c+383,"error_1", false,-1, 1,0);
    tracep->declBus(c+384,"error_2", false,-1, 1,0);
    tracep->declBus(c+385,"error_3", false,-1, 1,0);
    tracep->declBus(c+386,"error_4", false,-1, 1,0);
    tracep->declBus(c+387,"error_5", false,-1, 1,0);
    tracep->declBus(c+388,"error_6", false,-1, 1,0);
    tracep->declBus(c+389,"error_7", false,-1, 1,0);
    tracep->declBus(c+390,"error_8", false,-1, 1,0);
    tracep->declBus(c+391,"error_9", false,-1, 1,0);
    tracep->declBus(c+392,"error_10", false,-1, 1,0);
    tracep->declBus(c+393,"error_11", false,-1, 1,0);
    tracep->declBus(c+394,"error_12", false,-1, 1,0);
    tracep->declBus(c+395,"error_13", false,-1, 1,0);
    tracep->declBus(c+396,"error_14", false,-1, 1,0);
    tracep->declBus(c+397,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+368,"io_enq_ready", false,-1);
    tracep->declBit(c+94,"io_enq_valid", false,-1);
    tracep->declBus(c+1379,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1228,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1380,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1126,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1381,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+235,"io_deq_ready", false,-1);
    tracep->declBit(c+99,"io_deq_valid", false,-1);
    tracep->declBus(c+356,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1231,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+398,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1125,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+399,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+400,"ram", false,-1, 48,0);
    tracep->declBit(c+402,"full", false,-1);
    tracep->declBit(c+99,"io_deq_valid_0", false,-1);
    tracep->declBit(c+236,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+366,"io_enq_ready", false,-1);
    tracep->declBit(c+92,"io_enq_valid", false,-1);
    tracep->declBus(c+1376,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1223,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1377,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1224,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1225,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+237,"io_deq_ready", false,-1);
    tracep->declBit(c+102,"io_deq_valid", false,-1);
    tracep->declBus(c+354,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1232,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+403,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1219,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1233,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+404,"ram", false,-1, 48,0);
    tracep->declBit(c+406,"full", false,-1);
    tracep->declBit(c+102,"io_deq_valid_0", false,-1);
    tracep->declBit(c+238,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+367,"io_enq_ready", false,-1);
    tracep->declBit(c+93,"io_enq_valid", false,-1);
    tracep->declBus(c+1226,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1227,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1378,"io_enq_bits_last", false,-1);
    tracep->declBit(c+239,"io_deq_ready", false,-1);
    tracep->declBit(c+103,"io_deq_valid", false,-1);
    tracep->declBus(c+1220,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1221,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+407,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+408,"ram", false,-1, 36,0);
    tracep->declBit(c+410,"full", false,-1);
    tracep->declBit(c+103,"io_deq_valid_0", false,-1);
    tracep->declBit(c+240,"do_enq", false,-1);
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
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+241,"auto_in_awready", false,-1);
    tracep->declBit(c+158,"auto_in_awvalid", false,-1);
    tracep->declBus(c+354,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1234,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1340,"auto_in_wready", false,-1);
    tracep->declBit(c+1341,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+242,"auto_in_bready", false,-1);
    tracep->declBit(c+411,"auto_in_bvalid", false,-1);
    tracep->declBus(c+412,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+413,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+243,"auto_in_arready", false,-1);
    tracep->declBit(c+1342,"auto_in_arvalid", false,-1);
    tracep->declBus(c+356,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1235,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+244,"auto_in_rready", false,-1);
    tracep->declBit(c+414,"auto_in_rvalid", false,-1);
    tracep->declBus(c+415,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+416,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+417,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+243,"nodeIn_arready", false,-1);
    tracep->declBit(c+241,"nodeIn_awready", false,-1);
    tracep->declBit(c+1236,"w_sel0", false,-1);
    tracep->declBit(c+411,"w_full", false,-1);
    tracep->declBus(c+412,"w_id", false,-1, 3,0);
    tracep->declBit(c+418,"r_sel1", false,-1);
    tracep->declBit(c+419,"w_sel1", false,-1);
    tracep->declBit(c+414,"r_full", false,-1);
    tracep->declBus(c+415,"r_id", false,-1, 3,0);
    tracep->declBit(c+245,"ren", false,-1);
    tracep->declBit(c+420,"rdata_REG", false,-1);
    tracep->declBus(c+421,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+422,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+423,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+424,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1237,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+245,"R0_en", false,-1);
    tracep->declBit(c+1306,"R0_clk", false,-1);
    tracep->declBus(c+425,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1238,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+246,"W0_en", false,-1);
    tracep->declBit(c+1306,"W0_clk", false,-1);
    tracep->declBus(c+1220,"W0_data", false,-1, 31,0);
    tracep->declBus(c+1221,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+366,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+92,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1376,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1223,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1377,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1224,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1225,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+367,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+93,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1226,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1378,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1338,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+221,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+222,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+223,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+368,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+94,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1379,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1228,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1380,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1126,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1381,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+95,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+224,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+225,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+56,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+366,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+92,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1376,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1223,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1377,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1224,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1225,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+367,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+93,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1226,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1378,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1338,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+221,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+222,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+223,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+368,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+94,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1379,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1228,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1380,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1126,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1381,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+95,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+224,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+225,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+56,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+247,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+104,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+354,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1218,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1219,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+227,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+97,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+98,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+228,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+229,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+222,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+230,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+248,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+105,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+356,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1222,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1125,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+95,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+224,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+225,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+233,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+241,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+158,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+354,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1234,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1340,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1341,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+242,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+411,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+412,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+413,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+243,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1342,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+356,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1235,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+244,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+414,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+415,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+416,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+417,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1343,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1344,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+426,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1345,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+356,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1239,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1346,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+427,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+428,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+429,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+152,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+153,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+354,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1218,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+1219,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+152,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+154,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+216,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+217,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+355,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+53,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+155,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+156,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+356,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1222,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+1125,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+218,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+219,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+357,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+220,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+53,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+229,"in_0_bvalid", false,-1);
    tracep->declBit(c+224,"in_0_rvalid", false,-1);
    tracep->declBit(c+249,"in_0_wready", false,-1);
    tracep->declBit(c+250,"in_0_awready", false,-1);
    tracep->declBit(c+248,"in_0_arready", false,-1);
    tracep->declBit(c+247,"anonIn_awready", false,-1);
    tracep->declBit(c+1240,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1241,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1242,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1243,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1244,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1245,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+430,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+431,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+432,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+433,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+434,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+435,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+436,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+437,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+438,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+439,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+440,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+441,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+442,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+443,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+444,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+445,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+446,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+447,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+448,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+449,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+450,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+451,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+452,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+453,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+454,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+455,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+456,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+457,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+458,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+459,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+460,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+461,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+462,"latched", false,-1);
    tracep->declBit(c+106,"in_0_awvalid", false,-1);
    tracep->declBit(c+107,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+108,"in_0_wvalid", false,-1);
    tracep->declBit(c+463,"idle_3", false,-1);
    tracep->declBit(c+251,"anyValid", false,-1);
    tracep->declBus(c+252,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+464,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+253,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+254,"prefixOR_1", false,-1);
    tracep->declBit(c+255,"winner_3_1", false,-1);
    tracep->declBit(c+256,"winner_3_2", false,-1);
    tracep->declBit(c+465,"state_3_0", false,-1);
    tracep->declBit(c+466,"state_3_1", false,-1);
    tracep->declBit(c+467,"state_3_2", false,-1);
    tracep->declBit(c+257,"muxState_3_0", false,-1);
    tracep->declBit(c+258,"muxState_3_1", false,-1);
    tracep->declBit(c+259,"muxState_3_2", false,-1);
    tracep->declBit(c+468,"idle_4", false,-1);
    tracep->declBit(c+260,"anyValid_1", false,-1);
    tracep->declBus(c+261,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+469,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+262,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+263,"winner_4_0", false,-1);
    tracep->declBit(c+264,"winner_4_2", false,-1);
    tracep->declBit(c+470,"state_4_0", false,-1);
    tracep->declBit(c+471,"state_4_2", false,-1);
    tracep->declBit(c+265,"muxState_4_0", false,-1);
    tracep->declBit(c+266,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+472,"io_enq_ready", false,-1);
    tracep->declBit(c+107,"io_enq_valid", false,-1);
    tracep->declBus(c+1246,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+267,"io_deq_ready", false,-1);
    tracep->declBit(c+109,"io_deq_valid", false,-1);
    tracep->declBus(c+1247,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+473,"wrap", false,-1);
    tracep->declBit(c+474,"wrap_1", false,-1);
    tracep->declBit(c+475,"maybe_full", false,-1);
    tracep->declBit(c+476,"ptr_match", false,-1);
    tracep->declBit(c+477,"empty", false,-1);
    tracep->declBit(c+478,"full", false,-1);
    tracep->declBit(c+109,"io_deq_valid_0", false,-1);
    tracep->declBit(c+268,"do_deq", false,-1);
    tracep->declBit(c+269,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+474,"R0_addr", false,-1);
    tracep->declBit(c+1382,"R0_en", false,-1);
    tracep->declBit(c+1306,"R0_clk", false,-1);
    tracep->declBus(c+479,"R0_data", false,-1, 2,0);
    tracep->declBit(c+473,"W0_addr", false,-1);
    tracep->declBit(c+269,"W0_en", false,-1);
    tracep->declBit(c+1306,"W0_clk", false,-1);
    tracep->declBus(c+1246,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+480+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+226,"auto_in_awready", false,-1);
    tracep->declBit(c+96,"auto_in_awvalid", false,-1);
    tracep->declBus(c+354,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1218,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1219,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+369,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+227,"auto_in_wready", false,-1);
    tracep->declBit(c+97,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+98,"auto_in_wlast", false,-1);
    tracep->declBit(c+228,"auto_in_bready", false,-1);
    tracep->declBit(c+229,"auto_in_bvalid", false,-1);
    tracep->declBus(c+222,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+230,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+231,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+232,"auto_in_arready", false,-1);
    tracep->declBit(c+99,"auto_in_arvalid", false,-1);
    tracep->declBus(c+356,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1222,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1125,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+370,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+95,"auto_in_rready", false,-1);
    tracep->declBit(c+224,"auto_in_rvalid", false,-1);
    tracep->declBus(c+225,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+57,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+233,"auto_in_rlast", false,-1);
    tracep->declBit(c+247,"auto_out_awready", false,-1);
    tracep->declBit(c+104,"auto_out_awvalid", false,-1);
    tracep->declBus(c+354,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1218,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1219,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+227,"auto_out_wready", false,-1);
    tracep->declBit(c+97,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1220,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1221,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+98,"auto_out_wlast", false,-1);
    tracep->declBit(c+228,"auto_out_bready", false,-1);
    tracep->declBit(c+229,"auto_out_bvalid", false,-1);
    tracep->declBus(c+222,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+230,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+248,"auto_out_arready", false,-1);
    tracep->declBit(c+105,"auto_out_arvalid", false,-1);
    tracep->declBus(c+356,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1222,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1125,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+95,"auto_out_rready", false,-1);
    tracep->declBit(c+224,"auto_out_rvalid", false,-1);
    tracep->declBus(c+225,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+233,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+482,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+270,"io_deq_ready", false,-1);
    tracep->declBit(c+483,"io_deq_valid", false,-1);
    tracep->declBit(c+484,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+484,"ram_real_last", false,-1);
    tracep->declBit(c+483,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+485,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+486,"io_enq_ready", false,-1);
    tracep->declBit(c+59,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+271,"io_deq_ready", false,-1);
    tracep->declBit(c+487,"io_deq_valid", false,-1);
    tracep->declBit(c+488,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+488,"ram_real_last", false,-1);
    tracep->declBit(c+487,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+489,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+490,"io_enq_ready", false,-1);
    tracep->declBit(c+60,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+272,"io_deq_ready", false,-1);
    tracep->declBit(c+491,"io_deq_valid", false,-1);
    tracep->declBit(c+492,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+492,"ram_real_last", false,-1);
    tracep->declBit(c+491,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+493,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+494,"io_enq_ready", false,-1);
    tracep->declBit(c+61,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+273,"io_deq_ready", false,-1);
    tracep->declBit(c+495,"io_deq_valid", false,-1);
    tracep->declBit(c+496,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+496,"ram_real_last", false,-1);
    tracep->declBit(c+495,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+497,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+498,"io_enq_ready", false,-1);
    tracep->declBit(c+62,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+274,"io_deq_ready", false,-1);
    tracep->declBit(c+499,"io_deq_valid", false,-1);
    tracep->declBit(c+500,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+500,"ram_real_last", false,-1);
    tracep->declBit(c+499,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+501,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+502,"io_enq_ready", false,-1);
    tracep->declBit(c+63,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+275,"io_deq_ready", false,-1);
    tracep->declBit(c+503,"io_deq_valid", false,-1);
    tracep->declBit(c+504,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+504,"ram_real_last", false,-1);
    tracep->declBit(c+503,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+505,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+506,"io_enq_ready", false,-1);
    tracep->declBit(c+64,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+276,"io_deq_ready", false,-1);
    tracep->declBit(c+507,"io_deq_valid", false,-1);
    tracep->declBit(c+508,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+508,"ram_real_last", false,-1);
    tracep->declBit(c+507,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+509,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+510,"io_enq_ready", false,-1);
    tracep->declBit(c+65,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+277,"io_deq_ready", false,-1);
    tracep->declBit(c+511,"io_deq_valid", false,-1);
    tracep->declBit(c+512,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+512,"ram_real_last", false,-1);
    tracep->declBit(c+511,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+513,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+514,"io_enq_ready", false,-1);
    tracep->declBit(c+66,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+278,"io_deq_ready", false,-1);
    tracep->declBit(c+515,"io_deq_valid", false,-1);
    tracep->declBit(c+516,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+516,"ram_real_last", false,-1);
    tracep->declBit(c+515,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+517,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+518,"io_enq_ready", false,-1);
    tracep->declBit(c+67,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+279,"io_deq_ready", false,-1);
    tracep->declBit(c+519,"io_deq_valid", false,-1);
    tracep->declBit(c+520,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+520,"ram_real_last", false,-1);
    tracep->declBit(c+519,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+521,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+522,"io_enq_ready", false,-1);
    tracep->declBit(c+68,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+280,"io_deq_ready", false,-1);
    tracep->declBit(c+523,"io_deq_valid", false,-1);
    tracep->declBit(c+524,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+524,"ram_real_last", false,-1);
    tracep->declBit(c+523,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+525,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+526,"io_enq_ready", false,-1);
    tracep->declBit(c+69,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+281,"io_deq_ready", false,-1);
    tracep->declBit(c+527,"io_deq_valid", false,-1);
    tracep->declBit(c+528,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+528,"ram_real_last", false,-1);
    tracep->declBit(c+527,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+529,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+530,"io_enq_ready", false,-1);
    tracep->declBit(c+70,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+282,"io_deq_ready", false,-1);
    tracep->declBit(c+531,"io_deq_valid", false,-1);
    tracep->declBit(c+532,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+532,"ram_real_last", false,-1);
    tracep->declBit(c+531,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+533,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+534,"io_enq_ready", false,-1);
    tracep->declBit(c+71,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+283,"io_deq_ready", false,-1);
    tracep->declBit(c+535,"io_deq_valid", false,-1);
    tracep->declBit(c+536,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+536,"ram_real_last", false,-1);
    tracep->declBit(c+535,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+537,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+538,"io_enq_ready", false,-1);
    tracep->declBit(c+72,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+284,"io_deq_ready", false,-1);
    tracep->declBit(c+539,"io_deq_valid", false,-1);
    tracep->declBit(c+540,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+540,"ram_real_last", false,-1);
    tracep->declBit(c+539,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+541,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+542,"io_enq_ready", false,-1);
    tracep->declBit(c+73,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+285,"io_deq_ready", false,-1);
    tracep->declBit(c+543,"io_deq_valid", false,-1);
    tracep->declBit(c+544,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+544,"ram_real_last", false,-1);
    tracep->declBit(c+543,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+545,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+546,"io_enq_ready", false,-1);
    tracep->declBit(c+74,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+286,"io_deq_ready", false,-1);
    tracep->declBit(c+547,"io_deq_valid", false,-1);
    tracep->declBit(c+548,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+548,"ram_real_last", false,-1);
    tracep->declBit(c+547,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+549,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+550,"io_enq_ready", false,-1);
    tracep->declBit(c+75,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+287,"io_deq_ready", false,-1);
    tracep->declBit(c+551,"io_deq_valid", false,-1);
    tracep->declBit(c+552,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+552,"ram_real_last", false,-1);
    tracep->declBit(c+551,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+553,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+554,"io_enq_ready", false,-1);
    tracep->declBit(c+76,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+288,"io_deq_ready", false,-1);
    tracep->declBit(c+555,"io_deq_valid", false,-1);
    tracep->declBit(c+556,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+556,"ram_real_last", false,-1);
    tracep->declBit(c+555,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+557,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+558,"io_enq_ready", false,-1);
    tracep->declBit(c+77,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+289,"io_deq_ready", false,-1);
    tracep->declBit(c+559,"io_deq_valid", false,-1);
    tracep->declBit(c+560,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+560,"ram_real_last", false,-1);
    tracep->declBit(c+559,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+561,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+562,"io_enq_ready", false,-1);
    tracep->declBit(c+78,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+290,"io_deq_ready", false,-1);
    tracep->declBit(c+563,"io_deq_valid", false,-1);
    tracep->declBit(c+564,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+564,"ram_real_last", false,-1);
    tracep->declBit(c+563,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+565,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+566,"io_enq_ready", false,-1);
    tracep->declBit(c+79,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+291,"io_deq_ready", false,-1);
    tracep->declBit(c+567,"io_deq_valid", false,-1);
    tracep->declBit(c+568,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+568,"ram_real_last", false,-1);
    tracep->declBit(c+567,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+569,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+570,"io_enq_ready", false,-1);
    tracep->declBit(c+80,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+292,"io_deq_ready", false,-1);
    tracep->declBit(c+571,"io_deq_valid", false,-1);
    tracep->declBit(c+572,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+572,"ram_real_last", false,-1);
    tracep->declBit(c+571,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+573,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+574,"io_enq_ready", false,-1);
    tracep->declBit(c+81,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+293,"io_deq_ready", false,-1);
    tracep->declBit(c+575,"io_deq_valid", false,-1);
    tracep->declBit(c+576,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+576,"ram_real_last", false,-1);
    tracep->declBit(c+575,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+577,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+578,"io_enq_ready", false,-1);
    tracep->declBit(c+82,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+294,"io_deq_ready", false,-1);
    tracep->declBit(c+579,"io_deq_valid", false,-1);
    tracep->declBit(c+580,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+580,"ram_real_last", false,-1);
    tracep->declBit(c+579,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+581,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+582,"io_enq_ready", false,-1);
    tracep->declBit(c+83,"io_enq_valid", false,-1);
    tracep->declBit(c+369,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+295,"io_deq_ready", false,-1);
    tracep->declBit(c+583,"io_deq_valid", false,-1);
    tracep->declBit(c+584,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+584,"ram_real_last", false,-1);
    tracep->declBit(c+583,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+585,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+586,"io_enq_ready", false,-1);
    tracep->declBit(c+84,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+296,"io_deq_ready", false,-1);
    tracep->declBit(c+587,"io_deq_valid", false,-1);
    tracep->declBit(c+588,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+588,"ram_real_last", false,-1);
    tracep->declBit(c+587,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+589,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+590,"io_enq_ready", false,-1);
    tracep->declBit(c+85,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+297,"io_deq_ready", false,-1);
    tracep->declBit(c+591,"io_deq_valid", false,-1);
    tracep->declBit(c+592,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+592,"ram_real_last", false,-1);
    tracep->declBit(c+591,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+593,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+594,"io_enq_ready", false,-1);
    tracep->declBit(c+86,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+298,"io_deq_ready", false,-1);
    tracep->declBit(c+595,"io_deq_valid", false,-1);
    tracep->declBit(c+596,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+596,"ram_real_last", false,-1);
    tracep->declBit(c+595,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+597,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+598,"io_enq_ready", false,-1);
    tracep->declBit(c+87,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+299,"io_deq_ready", false,-1);
    tracep->declBit(c+599,"io_deq_valid", false,-1);
    tracep->declBit(c+600,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+600,"ram_real_last", false,-1);
    tracep->declBit(c+599,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+601,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+602,"io_enq_ready", false,-1);
    tracep->declBit(c+88,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+300,"io_deq_ready", false,-1);
    tracep->declBit(c+603,"io_deq_valid", false,-1);
    tracep->declBit(c+604,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+604,"ram_real_last", false,-1);
    tracep->declBit(c+603,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+605,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+606,"io_enq_ready", false,-1);
    tracep->declBit(c+89,"io_enq_valid", false,-1);
    tracep->declBit(c+370,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+301,"io_deq_ready", false,-1);
    tracep->declBit(c+607,"io_deq_valid", false,-1);
    tracep->declBit(c+608,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+608,"ram_real_last", false,-1);
    tracep->declBit(c+607,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+609,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+110,"reset", false,-1);
    tracep->declBit(c+366,"auto_master_out_awready", false,-1);
    tracep->declBit(c+92,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1376,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1223,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1377,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1224,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1225,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+367,"auto_master_out_wready", false,-1);
    tracep->declBit(c+93,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1226,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1227,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1378,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1338,"auto_master_out_bready", false,-1);
    tracep->declBit(c+221,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+222,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+223,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+368,"auto_master_out_arready", false,-1);
    tracep->declBit(c+94,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1379,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1228,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1380,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1126,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1381,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+95,"auto_master_out_rready", false,-1);
    tracep->declBit(c+224,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+225,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+55,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1339,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+56,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+110,"reset", false,-1);
    tracep->declBit(c+1371,"io_interrupt", false,-1);
    tracep->declBit(c+366,"io_master_awready", false,-1);
    tracep->declBit(c+92,"io_master_awvalid", false,-1);
    tracep->declBus(c+1223,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1376,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1377,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1224,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1225,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+367,"io_master_wready", false,-1);
    tracep->declBit(c+93,"io_master_wvalid", false,-1);
    tracep->declBus(c+1226,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+1227,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1378,"io_master_wlast", false,-1);
    tracep->declBit(c+1338,"io_master_bready", false,-1);
    tracep->declBit(c+221,"io_master_bvalid", false,-1);
    tracep->declBus(c+223,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+222,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+368,"io_master_arready", false,-1);
    tracep->declBit(c+94,"io_master_arvalid", false,-1);
    tracep->declBus(c+1228,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1379,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1380,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+1126,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1381,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+95,"io_master_rready", false,-1);
    tracep->declBit(c+224,"io_master_rvalid", false,-1);
    tracep->declBus(c+1339,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+55,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+56,"io_master_rlast", false,-1);
    tracep->declBus(c+225,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1383,"io_slave_awready", false,-1);
    tracep->declBit(c+1371,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1384,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1385,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1380,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1386,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1387,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1388,"io_slave_wready", false,-1);
    tracep->declBit(c+1371,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1384,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1385,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1371,"io_slave_wlast", false,-1);
    tracep->declBit(c+1371,"io_slave_bready", false,-1);
    tracep->declBit(c+1389,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1390,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1391,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1392,"io_slave_arready", false,-1);
    tracep->declBit(c+1371,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1384,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1385,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1380,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1386,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1387,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1371,"io_slave_rready", false,-1);
    tracep->declBit(c+1393,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1394,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1395,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1396,"io_slave_rlast", false,-1);
    tracep->declBus(c+1397,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+1127,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1248,"npc", false,-1, 31,0);
    tracep->declBus(c+1011,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+1128,"inst", false,-1, 31,0);
    tracep->declBit(c+1129,"ifu_valid", false,-1);
    tracep->declBit(c+1130,"ifu_arvalid", false,-1);
    tracep->declBit(c+1131,"ifu_arready", false,-1);
    tracep->declBus(c+1011,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+302,"ifu_rvalid", false,-1);
    tracep->declBit(c+1127,"ifu_rready", false,-1);
    tracep->declBus(c+303,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+1132,"reg_process", false,-1);
    tracep->declBus(c+1133,"src1", false,-1, 4,0);
    tracep->declBus(c+1134,"src2", false,-1, 4,0);
    tracep->declBus(c+1135,"rd", false,-1, 4,0);
    tracep->declBus(c+1136,"imm", false,-1, 31,0);
    tracep->declBit(c+1137,"ebreaksig", false,-1);
    tracep->declBit(c+1138,"mretsig", false,-1);
    tracep->declBit(c+1139,"ecallsig", false,-1);
    tracep->declBit(c+1140,"regew", false,-1);
    tracep->declBit(c+1141,"memew", false,-1);
    tracep->declBit(c+1142,"memer", false,-1);
    tracep->declBit(c+1143,"muximm", false,-1);
    tracep->declBus(c+1144,"func3", false,-1, 2,0);
    tracep->declBus(c+1145,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1146,"func7", false,-1);
    tracep->declBit(c+1147,"btypebranch", false,-1);
    tracep->declBit(c+1148,"jalsig", false,-1);
    tracep->declBit(c+1149,"jalrsig", false,-1);
    tracep->declBit(c+1150,"auipcsig", false,-1);
    tracep->declBus(c+1151,"aluop", false,-1, 1,0);
    tracep->declBit(c+1152,"csrrw", false,-1);
    tracep->declBit(c+1153,"csrrs", false,-1);
    tracep->declBit(c+1129,"idu_valid", false,-1);
    tracep->declBus(c+1154,"memmask", false,-1, 2,0);
    tracep->declBit(c+1155,"memsextsig", false,-1);
    tracep->declBus(c+304,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1249,"regout1", false,-1, 31,0);
    tracep->declBus(c+1250,"regout2", false,-1, 31,0);
    tracep->declBus(c+1012,"mepc", false,-1, 31,0);
    tracep->declBus(c+1013,"mtvec", false,-1, 31,0);
    tracep->declBit(c+1127,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1251,"res", false,-1, 31,0);
    tracep->declBus(c+1252,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1129,"exu_valid", false,-1);
    tracep->declBit(c+1127,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1347,"memvalid", false,-1);
    tracep->declBus(c+1156,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1156,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1157,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1158,"rready", false,-1, 1,0);
    tracep->declBus(c+1159,"bready", false,-1, 1,0);
    tracep->declBus(c+90,"bvalid", false,-1, 1,0);
    tracep->declBus(c+305,"rvalid", false,-1, 1,0);
    tracep->declBus(c+610,"awready", false,-1, 1,0);
    tracep->declBus(c+610,"wready", false,-1, 1,0);
    tracep->declBus(c+1160,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1348+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+306+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1253+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1255+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1257+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+308+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1259+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1161+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1398,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+110,"reset", false,-1);
    tracep->declBus(c+1156,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1156,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1157,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1158,"rready", false,-1, 1,0);
    tracep->declBus(c+1159,"bready", false,-1, 1,0);
    tracep->declBus(c+90,"bvalid", false,-1, 1,0);
    tracep->declBus(c+305,"rvalid", false,-1, 1,0);
    tracep->declBus(c+610,"awready", false,-1, 1,0);
    tracep->declBus(c+610,"wready", false,-1, 1,0);
    tracep->declBus(c+1160,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1261+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1263+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1265+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1267+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+310+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+312+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1269+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1163+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->declBit(c+92,"awvalid_out", false,-1);
    tracep->declBit(c+93,"wvalid_out", false,-1);
    tracep->declBit(c+94,"arvalid_out", false,-1);
    tracep->declBit(c+95,"rready_out", false,-1);
    tracep->declBit(c+1338,"bready_out", false,-1);
    tracep->declBit(c+221,"bvalid_in", false,-1);
    tracep->declBit(c+224,"rvalid_in", false,-1);
    tracep->declBit(c+367,"awready_in", false,-1);
    tracep->declBit(c+367,"wready_in", false,-1);
    tracep->declBit(c+368,"arready_in", false,-1);
    tracep->declBus(c+1228,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1223,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1226,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+1227,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+55,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+223,"bresp_in", false,-1, 1,0);
    tracep->declBus(c+1224,"awsize_out", false,-1, 2,0);
    tracep->declBus(c+1126,"arsize_out", false,-1, 2,0);
    tracep->declBit(c+611,"busy", false,-1);
    tracep->declBus(c+612,"giant", false,-1, 1,0);
    tracep->declBus(c+613,"i", false,-1, 31,0);
    tracep->declBus(c+1223,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1226,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1228,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1227,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1224,"awsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1126,"arsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1399,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+1144,"func3", false,-1, 2,0);
    tracep->declBit(c+1147,"btypebranch", false,-1);
    tracep->declBit(c+1146,"func7", false,-1);
    tracep->declBus(c+1151,"aluop", false,-1, 1,0);
    tracep->declBit(c+1149,"jalrsig", false,-1);
    tracep->declBit(c+1148,"jalsig", false,-1);
    tracep->declBus(c+1136,"imm", false,-1, 31,0);
    tracep->declBit(c+1143,"muximm", false,-1);
    tracep->declBus(c+1249,"regout1", false,-1, 31,0);
    tracep->declBus(c+1250,"regout2", false,-1, 31,0);
    tracep->declBus(c+1011,"pc", false,-1, 31,0);
    tracep->declBit(c+1150,"auipcsig", false,-1);
    tracep->declBit(c+1138,"mretsig", false,-1);
    tracep->declBit(c+1139,"ecallsig", false,-1);
    tracep->declBus(c+1013,"mtvec", false,-1, 31,0);
    tracep->declBus(c+1012,"mepc", false,-1, 31,0);
    tracep->declBit(c+1129,"valid_from", false,-1);
    tracep->declBit(c+1127,"ready_from", false,-1);
    tracep->declBus(c+1251,"res", false,-1, 31,0);
    tracep->declBus(c+1248,"npc", false,-1, 31,0);
    tracep->declBus(c+1252,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1129,"valid_to", false,-1);
    tracep->declBit(c+1127,"ready_to", false,-1);
    tracep->declBus(c+1014,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1271,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+1165,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1272,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1273,"zero", false,-1);
    tracep->declBit(c+1274,"signal", false,-1);
    tracep->declBit(c+1275,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1249,"A", false,-1, 31,0);
    tracep->declBus(c+1272,"B", false,-1, 31,0);
    tracep->declBus(c+1165,"op", false,-1, 4,0);
    tracep->declBus(c+1251,"res", false,-1, 31,0);
    tracep->declBit(c+1273,"zero", false,-1);
    tracep->declBit(c+1274,"signal", false,-1);
    tracep->declBit(c+1275,"carry", false,-1);
    tracep->declBit(c+1166,"addsig", false,-1);
    tracep->declBit(c+1167,"logsig", false,-1);
    tracep->declBit(c+1168,"shfsig", false,-1);
    tracep->declBit(c+1169,"sltsig", false,-1);
    tracep->declBit(c+1275,"carry_tmp", false,-1);
    tracep->declBit(c+1170,"type_I", false,-1);
    tracep->declBus(c+1276,"logres", false,-1, 31,0);
    tracep->declBus(c+1277,"addres", false,-1, 31,0);
    tracep->declBit(c+1278,"addzero", false,-1);
    tracep->declBus(c+1279,"shfres", false,-1, 31,0);
    tracep->declBus(c+1280,"sltres", false,-1, 31,0);
    tracep->declBus(c+1249,"A_s", false,-1, 31,0);
    tracep->declBus(c+1272,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+1144,"func3", false,-1, 2,0);
    tracep->declBit(c+1146,"func7", false,-1);
    tracep->declBus(c+1151,"aluop", false,-1, 1,0);
    tracep->declBit(c+1149,"jalrsig", false,-1);
    tracep->declBus(c+1165,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+1170,"type_I", false,-1);
    tracep->declBit(c+1171,"type_B", false,-1);
    tracep->declBit(c+1172,"type_R", false,-1);
    tracep->declBit(c+1173,"addsig", false,-1);
    tracep->declBus(c+1174,"branchop", false,-1, 3,0);
    tracep->declBus(c+1175,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+1147,"btypebranch", false,-1);
    tracep->declBus(c+1144,"func3", false,-1, 2,0);
    tracep->declBit(c+1273,"zero", false,-1);
    tracep->declBit(c+1274,"signal", false,-1);
    tracep->declBit(c+1275,"carry", false,-1);
    tracep->declBus(c+1251,"res", false,-1, 31,0);
    tracep->declBus(c+1014,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1271,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+1148,"jalsig", false,-1);
    tracep->declBit(c+1149,"jalrsig", false,-1);
    tracep->declBit(c+1150,"auipcsig", false,-1);
    tracep->declBit(c+1138,"mretsig", false,-1);
    tracep->declBit(c+1139,"ecallsig", false,-1);
    tracep->declBus(c+1013,"mtvec", false,-1, 31,0);
    tracep->declBus(c+1012,"mepc", false,-1, 31,0);
    tracep->declBus(c+1248,"npc", false,-1, 31,0);
    tracep->declBus(c+1252,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1398,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1400,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1401,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1272,"out", false,-1, 31,0);
    tracep->declBus(c+1143,"key", false,-1, 0,0);
    tracep->declArray(c+1200,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1398,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1400,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1401,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1402,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1272,"out", false,-1, 31,0);
    tracep->declBus(c+1143,"key", false,-1, 0,0);
    tracep->declBus(c+1384,"default_out", false,-1, 31,0);
    tracep->declArray(c+1200,"lut", false,-1, 65,0);
    tracep->declBus(c+1403,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1203+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1207+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1281,"lut_out", false,-1, 31,0);
    tracep->declBit(c+1176,"hit", false,-1);
    tracep->declBus(c+1404,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+1011,"pc", false,-1, 31,0);
    tracep->declBus(c+1014,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+1011,"pc", false,-1, 31,0);
    tracep->declBus(c+1136,"imm", false,-1, 31,0);
    tracep->declBus(c+1271,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+1128,"inst", false,-1, 31,0);
    tracep->declBit(c+1129,"valid_from", false,-1);
    tracep->declBit(c+1127,"ready_from", false,-1);
    tracep->declBit(c+1137,"ebreaksig", false,-1);
    tracep->declBit(c+1139,"ecallsig", false,-1);
    tracep->declBit(c+1138,"mretsig", false,-1);
    tracep->declBus(c+1136,"imm", false,-1, 31,0);
    tracep->declBus(c+1144,"func3", false,-1, 2,0);
    tracep->declBit(c+1146,"func7", false,-1);
    tracep->declBus(c+1133,"src1", false,-1, 4,0);
    tracep->declBus(c+1134,"src2", false,-1, 4,0);
    tracep->declBus(c+1135,"rd", false,-1, 4,0);
    tracep->declBit(c+1141,"memew", false,-1);
    tracep->declBus(c+1145,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1142,"memer", false,-1);
    tracep->declBit(c+1140,"regew", false,-1);
    tracep->declBit(c+1143,"muximm", false,-1);
    tracep->declBit(c+1147,"btypebranch", false,-1);
    tracep->declBit(c+1149,"jalrsig", false,-1);
    tracep->declBit(c+1148,"jalsig", false,-1);
    tracep->declBus(c+1151,"aluop", false,-1, 1,0);
    tracep->declBit(c+1150,"auipcsig", false,-1);
    tracep->declBit(c+1152,"csrrw", false,-1);
    tracep->declBit(c+1153,"csrrs", false,-1);
    tracep->declBit(c+1129,"valid_to", false,-1);
    tracep->declBit(c+1127,"ready_to", false,-1);
    tracep->declBus(c+1154,"memmask", false,-1, 2,0);
    tracep->declBit(c+1155,"memsextsig", false,-1);
    tracep->declBit(c+1137,"ebreak", false,-1);
    tracep->declBit(c+1139,"ecall", false,-1);
    tracep->declBit(c+1138,"mret", false,-1);
    tracep->declBus(c+1144,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+1146,"func7bridge", false,-1);
    tracep->declBus(c+1177,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+1128,"inst", false,-1, 31,0);
    tracep->declBit(c+1137,"ebreaksig", false,-1);
    tracep->declBit(c+1139,"ecallsig", false,-1);
    tracep->declBit(c+1138,"mretsig", false,-1);
    tracep->declBus(c+1136,"imm", false,-1, 31,0);
    tracep->declBus(c+1177,"opcode", false,-1, 6,0);
    tracep->declBus(c+1144,"func3", false,-1, 2,0);
    tracep->declBit(c+1146,"func7", false,-1);
    tracep->declBus(c+1133,"src1", false,-1, 4,0);
    tracep->declBus(c+1134,"src2", false,-1, 4,0);
    tracep->declBus(c+1135,"rd", false,-1, 4,0);
    tracep->declBus(c+1154,"memmask", false,-1, 2,0);
    tracep->declBit(c+1155,"memsextsig", false,-1);
    tracep->declBit(c+1178,"type_I", false,-1);
    tracep->declBit(c+1179,"type_R", false,-1);
    tracep->declBit(c+1180,"type_U", false,-1);
    tracep->declBit(c+1141,"type_S", false,-1);
    tracep->declBit(c+1148,"type_J", false,-1);
    tracep->declBit(c+1147,"type_B", false,-1);
    tracep->declBus(c+1181,"I_imm", false,-1, 31,0);
    tracep->declBus(c+1182,"U_imm", false,-1, 31,0);
    tracep->declBus(c+1183,"S_imm", false,-1, 31,0);
    tracep->declBus(c+1184,"J_imm", false,-1, 31,0);
    tracep->declBus(c+1185,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+1177,"opcode", false,-1, 6,0);
    tracep->declBus(c+1144,"func3", false,-1, 2,0);
    tracep->declBit(c+1146,"func7", false,-1);
    tracep->declBit(c+1137,"ebreaksig", false,-1);
    tracep->declBit(c+1139,"ecallsig", false,-1);
    tracep->declBit(c+1138,"mretsig", false,-1);
    tracep->declBit(c+1141,"memew", false,-1);
    tracep->declBus(c+1145,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1142,"memer", false,-1);
    tracep->declBit(c+1140,"regew", false,-1);
    tracep->declBit(c+1143,"muximm", false,-1);
    tracep->declBit(c+1147,"btypebranch", false,-1);
    tracep->declBit(c+1149,"jalrsig", false,-1);
    tracep->declBit(c+1148,"jalsig", false,-1);
    tracep->declBus(c+1151,"aluop", false,-1, 1,0);
    tracep->declBit(c+1150,"auipcsig", false,-1);
    tracep->declBit(c+1152,"csrrw", false,-1);
    tracep->declBit(c+1153,"csrrs", false,-1);
    tracep->declBit(c+1178,"type_I", false,-1);
    tracep->declBit(c+1179,"type_R", false,-1);
    tracep->declBit(c+1180,"type_U", false,-1);
    tracep->declBit(c+1141,"type_S", false,-1);
    tracep->declBit(c+1148,"type_J", false,-1);
    tracep->declBit(c+1147,"type_B", false,-1);
    tracep->declBit(c+1142,"load", false,-1);
    tracep->declBit(c+1141,"store", false,-1);
    tracep->declBit(c+1186,"regwritepc", false,-1);
    tracep->declBit(c+1142,"regwritemem", false,-1);
    tracep->declBit(c+1187,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+110,"rst", false,-1);
    tracep->declBus(c+1248,"npc", false,-1, 31,0);
    tracep->declBit(c+1127,"ready", false,-1);
    tracep->declBus(c+1011,"pc", false,-1, 31,0);
    tracep->declBus(c+1128,"inst", false,-1, 31,0);
    tracep->declBit(c+1129,"valid", false,-1);
    tracep->declBit(c+1132,"regprocess", false,-1);
    tracep->declBit(c+1130,"arvalid", false,-1);
    tracep->declBit(c+1131,"arready", false,-1);
    tracep->declBus(c+1011,"araddr", false,-1, 31,0);
    tracep->declBit(c+302,"rvalid", false,-1);
    tracep->declBit(c+1127,"rready", false,-1);
    tracep->declBus(c+303,"rdata", false,-1, 31,0);
    tracep->declBus(c+1011,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1188,"infetch_ready", false,-1);
    tracep->declBus(c+1189,"state", false,-1, 2,0);
    tracep->declBus(c+1128,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBus(c+1248,"npc", false,-1, 31,0);
    tracep->declBit(c+110,"rst", false,-1);
    tracep->declBit(c+1188,"ready_from", false,-1);
    tracep->declBus(c+1011,"pcout", false,-1, 31,0);
    tracep->declBus(c+1405,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+110,"rst", false,-1);
    tracep->declBit(c+1350,"ew", false,-1);
    tracep->declBus(c+1135,"addr", false,-1, 4,0);
    tracep->declBus(c+1133,"src1", false,-1, 4,0);
    tracep->declBus(c+1134,"src2", false,-1, 4,0);
    tracep->declBus(c+1190,"csr", false,-1, 11,0);
    tracep->declBus(c+304,"data", false,-1, 31,0);
    tracep->declBit(c+1152,"csrrw", false,-1);
    tracep->declBit(c+1153,"csrrs", false,-1);
    tracep->declBit(c+1139,"ecallsig", false,-1);
    tracep->declBit(c+1129,"valid", false,-1);
    tracep->declBus(c+1249,"regout1", false,-1, 31,0);
    tracep->declBus(c+1250,"regout2", false,-1, 31,0);
    tracep->declBus(c+1012,"mepc", false,-1, 31,0);
    tracep->declBus(c+1013,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1015+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+1047+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1191,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+314,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1406,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1407,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1408,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1191,"out", false,-1, 2,0);
    tracep->declBus(c+1190,"key", false,-1, 11,0);
    tracep->declArray(c+1409,"lut", false,-1, 89,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1406,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1407,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1408,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1402,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1191,"out", false,-1, 2,0);
    tracep->declBus(c+1190,"key", false,-1, 11,0);
    tracep->declBus(c+1386,"default_out", false,-1, 2,0);
    tracep->declArray(c+1409,"lut", false,-1, 89,0);
    tracep->declBus(c+1412,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 14,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+9+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+15+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1192,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1193,"hit", false,-1);
    tracep->declBus(c+1413,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+110,"rst", false,-1);
    tracep->declBit(c+1351,"ew", false,-1);
    tracep->declBit(c+1152,"csrrw", false,-1);
    tracep->declBit(c+1153,"csrrs", false,-1);
    tracep->declBit(c+1139,"ecall", false,-1);
    tracep->declBus(c+1191,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+1135,"addr", false,-1, 4,0);
    tracep->declBus(c+314,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1053+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+1085+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1091,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBus(c+1251,"res", false,-1, 31,0);
    tracep->declBus(c+1250,"regout2", false,-1, 31,0);
    tracep->declBit(c+1141,"memew", false,-1);
    tracep->declBit(c+1142,"memer", false,-1);
    tracep->declBus(c+1136,"imm", false,-1, 31,0);
    tracep->declBus(c+1252,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+1145,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1129,"valid_from", false,-1);
    tracep->declBus(c+1154,"memmask", false,-1, 2,0);
    tracep->declBit(c+1155,"memsextsig", false,-1);
    tracep->declBus(c+304,"regwrite", false,-1, 31,0);
    tracep->declBit(c+1127,"ready_to", false,-1);
    tracep->declBit(c+1347,"memvalid", false,-1);
    tracep->declBit(c+1194,"awvalid", false,-1);
    tracep->declBit(c+614,"awready", false,-1);
    tracep->declBus(c+1251,"awaddr", false,-1, 31,0);
    tracep->declBit(c+1194,"wvalid", false,-1);
    tracep->declBit(c+614,"wready", false,-1);
    tracep->declBus(c+1282,"wdata", false,-1, 31,0);
    tracep->declBus(c+1283,"wstrb", false,-1, 3,0);
    tracep->declBit(c+91,"bvalid", false,-1);
    tracep->declBit(c+1141,"bready", false,-1);
    tracep->declBus(c+315,"bresp", false,-1, 1,0);
    tracep->declBit(c+1352,"arvalid", false,-1);
    tracep->declBit(c+1195,"arready", false,-1);
    tracep->declBus(c+1284,"araddr", false,-1, 31,0);
    tracep->declBit(c+316,"rvalid", false,-1);
    tracep->declBit(c+1142,"rready", false,-1);
    tracep->declBus(c+317,"rdata", false,-1, 31,0);
    tracep->declBus(c+1285,"awsize", false,-1, 2,0);
    tracep->declBus(c+1196,"arsize", false,-1, 2,0);
    tracep->declBus(c+1225,"awburst", false,-1, 1,0);
    tracep->declBus(c+615,"state", false,-1, 1,0);
    tracep->declBus(c+318,"memread", false,-1, 31,0);
    tracep->declBus(c+1286,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1197,"access_size_i", false,-1, 1,0);
    tracep->declBit(c+1287,"aligned_sram", false,-1);
    tracep->declBit(c+1353,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBit(c+1287,"is_unalign", false,-1);
    tracep->declBus(c+317,"data", false,-1, 31,0);
    tracep->declBus(c+1154,"memmask", false,-1, 2,0);
    tracep->declBit(c+1155,"memsextsig", false,-1);
    tracep->declBus(c+1288,"addr_offset", false,-1, 1,0);
    tracep->declBus(c+318,"read", false,-1, 31,0);
    tracep->declBus(c+319,"read_u", false,-1, 31,0);
    tracep->declBus(c+320,"read_s", false,-1, 31,0);
    tracep->declBus(c+321,"read_sb", false,-1, 31,0);
    tracep->declBus(c+322,"read_sh", false,-1, 31,0);
    tracep->declBus(c+323,"byte_data", false,-1, 7,0);
    tracep->declBus(c+324,"halfword_data", false,-1, 15,0);
    tracep->declBus(c+1354,"halfword_data_unalign", false,-1, 15,0);
    tracep->declBus(c+1355,"byte_data_unalign", false,-1, 7,0);
    tracep->declBus(c+325,"halfword_data_align", false,-1, 15,0);
    tracep->declBus(c+326,"byte_data_align", false,-1, 7,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1414,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1401,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+323,"input_number", false,-1, 7,0);
    tracep->declBus(c+321,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1415,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1401,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+324,"input_number", false,-1, 15,0);
    tracep->declBus(c+322,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1416,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1408,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1401,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+304,"out", false,-1, 31,0);
    tracep->declBus(c+1145,"key", false,-1, 2,0);
    tracep->declBus(c+1402,"default_out", false,-1, 31,0);
    tracep->declArray(c+111,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1416,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1408,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1401,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1400,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+304,"out", false,-1, 31,0);
    tracep->declBus(c+1145,"key", false,-1, 2,0);
    tracep->declBus(c+1402,"default_out", false,-1, 31,0);
    tracep->declArray(c+111,"lut", false,-1, 139,0);
    tracep->declBus(c+1417,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+116+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+21+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+124+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+327,"lut_out", false,-1, 31,0);
    tracep->declBit(c+328,"hit", false,-1);
    tracep->declBus(c+1418,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("strbcontol ");
    tracep->declBus(c+1251,"awaddr", false,-1, 31,0);
    tracep->declBus(c+1154,"wirtelen", false,-1, 2,0);
    tracep->declBus(c+1283,"wstrb", false,-1, 3,0);
    tracep->declBus(c+1285,"awsize", false,-1, 2,0);
    tracep->declBus(c+1286,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1225,"awburst", false,-1, 1,0);
    tracep->declBus(c+1408,"device_num", false,-1, 31,0);
    tracep->declBit(c+1289,"inuart", false,-1);
    tracep->declBit(c+1290,"insram", false,-1);
    tracep->declBit(c+1291,"inflash", false,-1);
    tracep->declBit(c+1292,"inspi", false,-1);
    tracep->declBit(c+1293,"inpsram", false,-1);
    tracep->declBit(c+1294,"insdram", false,-1);
    tracep->declBus(c+1295,"bus_size", false,-1, 1,0);
    tracep->declBus(c+1198,"awsize_general", false,-1, 2,0);
    tracep->declBus(c+1199,"wstrb_general", false,-1, 3,0);
    tracep->declBus(c+1419,"wstrb_byte", false,-1, 3,0);
    tracep->declBus(c+1420,"wstrb_halfword", false,-1, 3,0);
    tracep->declBus(c+1296,"wstrb_word", false,-1, 3,0);
    tracep->declBus(c+1297,"mux", false,-1, 4,0);
    tracep->pushNamePrefix("len_mux ");
    tracep->declBus(c+1408,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1398,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1408,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1285,"out", false,-1, 2,0);
    tracep->declBus(c+1295,"key", false,-1, 1,0);
    tracep->declBus(c+1198,"default_out", false,-1, 2,0);
    tracep->declBus(c+1421,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1408,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1398,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1408,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1400,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1285,"out", false,-1, 2,0);
    tracep->declBus(c+1295,"key", false,-1, 1,0);
    tracep->declBus(c+1198,"default_out", false,-1, 2,0);
    tracep->declBus(c+1421,"lut", false,-1, 14,0);
    tracep->declBus(c+1422,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+25+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+28+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+31+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1298,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1299,"hit", false,-1);
    tracep->declBus(c+1423,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("type_mux ");
    tracep->declBus(c+1408,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1408,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1398,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1295,"out", false,-1, 1,0);
    tracep->declBus(c+1300,"key", false,-1, 2,0);
    tracep->declBus(c+1387,"default_out", false,-1, 1,0);
    tracep->declBus(c+1424,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1408,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1408,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1398,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1400,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1295,"out", false,-1, 1,0);
    tracep->declBus(c+1300,"key", false,-1, 2,0);
    tracep->declBus(c+1387,"default_out", false,-1, 1,0);
    tracep->declBus(c+1424,"lut", false,-1, 14,0);
    tracep->declBus(c+1422,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+34+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+37+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+40+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1301,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1302,"hit", false,-1);
    tracep->declBus(c+1423,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wstrb_mux ");
    tracep->declBus(c+1416,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1398,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1416,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1283,"out", false,-1, 3,0);
    tracep->declBus(c+1295,"key", false,-1, 1,0);
    tracep->declBus(c+1209,"lut", false,-1, 23,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1416,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1398,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1416,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1402,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1283,"out", false,-1, 3,0);
    tracep->declBus(c+1295,"key", false,-1, 1,0);
    tracep->declBus(c+1385,"default_out", false,-1, 3,0);
    tracep->declBus(c+1209,"lut", false,-1, 23,0);
    tracep->declBus(c+1406,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1210+i*1,"pair_list", true,(i+0), 5,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+43+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1214+i*1,"data_list", true,(i+0), 3,0);
    }
    tracep->declBus(c+1303,"lut_out", false,-1, 3,0);
    tracep->declBit(c+1304,"hit", false,-1);
    tracep->declBus(c+1418,"i", false,-1, 31,0);
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"io_d", false,-1);
    tracep->declBit(c+616,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"io_d", false,-1);
    tracep->declBit(c+616,"io_q", false,-1);
    tracep->declBit(c+616,"sync_0", false,-1);
    tracep->declBit(c+617,"sync_1", false,-1);
    tracep->declBit(c+618,"sync_2", false,-1);
    tracep->declBit(c+619,"sync_3", false,-1);
    tracep->declBit(c+620,"sync_4", false,-1);
    tracep->declBit(c+621,"sync_5", false,-1);
    tracep->declBit(c+622,"sync_6", false,-1);
    tracep->declBit(c+623,"sync_7", false,-1);
    tracep->declBit(c+624,"sync_8", false,-1);
    tracep->declBit(c+625,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+139,"auto_in_psel", false,-1);
    tracep->declBit(c+50,"auto_in_penable", false,-1);
    tracep->declBit(c+130,"auto_in_pwrite", false,-1);
    tracep->declBus(c+138,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1370,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+352,"auto_in_pready", false,-1);
    tracep->declBit(c+1375,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1333,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1308,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1309,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1310,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1311,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1312,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1313,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1314,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1315,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1316,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1317,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+159,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+139,"in_psel", false,-1);
    tracep->declBit(c+50,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+352,"in_pready", false,-1);
    tracep->declBus(c+1333,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1375,"in_pslverr", false,-1);
    tracep->declBus(c+1308,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1309,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1310,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1311,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1312,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1313,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1314,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1315,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1316,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1317,"gpio_seg_7", false,-1, 7,0);
    tracep->declBus(c+626,"state", false,-1, 1,0);
    tracep->declBit(c+160,"is_read", false,-1);
    tracep->declBit(c+161,"is_write", false,-1);
    tracep->declBus(c+627,"segment_reg_q", false,-1, 31,0);
    tracep->declBit(c+628,"req_accept", false,-1);
    tracep->pushNamePrefix("gpio_urt_core ");
    tracep->declBit(c+1306,"clk_i", false,-1);
    tracep->declBit(c+1307,"rst_i", false,-1);
    tracep->declBit(c+160,"inport_rd_i", false,-1);
    tracep->declBus(c+132,"inport_wr_i", false,-1, 3,0);
    tracep->declBus(c+159,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+131,"inport_write_data_i", false,-1, 31,0);
    tracep->declBit(c+1371,"inport_len_i", false,-1);
    tracep->declBit(c+50,"inport_penable", false,-1);
    tracep->declBit(c+628,"inport_accept_o", false,-1);
    tracep->declBus(c+1333,"gpio_rdata_o", false,-1, 31,0);
    tracep->declBit(c+352,"inport_ack_o", false,-1);
    tracep->declBus(c+1308,"gpio_out_o", false,-1, 15,0);
    tracep->declBus(c+1309,"gpio_in_o", false,-1, 15,0);
    tracep->declBus(c+627,"gpio_led_o", false,-1, 31,0);
    tracep->declBit(c+160,"read", false,-1);
    tracep->declBit(c+162,"write", false,-1);
    tracep->declBit(c+163,"addr_led", false,-1);
    tracep->declBit(c+164,"addr_switch", false,-1);
    tracep->declBit(c+165,"addr_segment", false,-1);
    tracep->declBit(c+166,"addr_reserved", false,-1);
    tracep->declBus(c+132,"byte_enable", false,-1, 3,0);
    tracep->declBus(c+629,"gpio_out_light_q", false,-1, 15,0);
    tracep->declBus(c+630,"gpio_int_sw_q", false,-1, 15,0);
    tracep->declBus(c+1425,"gpio_out_num", false,-1, 31,0);
    tracep->declBus(c+631,"state_current_q", false,-1, 1,0);
    tracep->declBus(c+167,"state_next_r", false,-1, 1,0);
    tracep->declBit(c+168,"write_enable_r", false,-1);
    tracep->declBit(c+169,"idle_ack_r", false,-1);
    tracep->declBit(c+632,"write_enable_q", false,-1);
    tracep->declBit(c+628,"accept_o", false,-1);
    tracep->declBit(c+1426,"ack_q", false,-1);
    tracep->declBit(c+352,"idle_ack_q", false,-1);
    tracep->declBit(c+632,"write_enable", false,-1);
    tracep->declBus(c+627,"segment_reg_q", false,-1, 31,0);
    tracep->declBus(c+1333,"read_data_r", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+137,"auto_in_psel", false,-1);
    tracep->declBit(c+49,"auto_in_penable", false,-1);
    tracep->declBit(c+130,"auto_in_pwrite", false,-1);
    tracep->declBus(c+138,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1370,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+350,"auto_in_pready", false,-1);
    tracep->declBit(c+1374,"auto_in_pslverr", false,-1);
    tracep->declBus(c+351,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1318,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1319,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+159,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+137,"in_psel", false,-1);
    tracep->declBit(c+49,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+350,"in_pready", false,-1);
    tracep->declBus(c+351,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1374,"in_pslverr", false,-1);
    tracep->declBit(c+1318,"ps2_clk", false,-1);
    tracep->declBit(c+1319,"ps2_data", false,-1);
    tracep->declBus(c+633,"state", false,-1, 1,0);
    tracep->declBit(c+170,"is_read", false,-1);
    tracep->declBit(c+634,"req_accept", false,-1);
    tracep->pushNamePrefix("ps2_ctrl_core ");
    tracep->declBit(c+1306,"clk_i", false,-1);
    tracep->declBit(c+1307,"rst_i", false,-1);
    tracep->declBit(c+170,"inport_rd_i", false,-1);
    tracep->declBus(c+1385,"inport_wr_i", false,-1, 3,0);
    tracep->declBus(c+159,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+1384,"inport_write_data_i", false,-1, 31,0);
    tracep->declBit(c+1371,"inport_len_i", false,-1);
    tracep->declBit(c+49,"inport_penable", false,-1);
    tracep->declBit(c+634,"inport_accept_o", false,-1);
    tracep->declBus(c+351,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+350,"inport_ack_o", false,-1);
    tracep->declBit(c+1318,"ps2_clk", false,-1);
    tracep->declBit(c+1319,"ps2_data", false,-1);
    tracep->declBus(c+635,"ps2_clk_sync", false,-1, 2,0);
    tracep->declBus(c+636,"count", false,-1, 3,0);
    tracep->declBus(c+637,"buffer", false,-1, 9,0);
    tracep->declBus(c+638,"buffer_out", false,-1, 7,0);
    tracep->declBit(c+639,"sampling", false,-1);
    tracep->declBit(c+640,"buffer_out_valid", false,-1);
    tracep->declBus(c+1402,"ST_IDLE", false,-1, 31,0);
    tracep->declBus(c+1400,"ST_READ", false,-1, 31,0);
    tracep->declBit(c+634,"state", false,-1);
    tracep->declBit(c+350,"idle_ack_q", false,-1);
    tracep->declBus(c+1414,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1408,"DATA_DEPTH_BASE", false,-1, 31,0);
    tracep->declBus(c+1414,"DATA_DEPTH", false,-1, 31,0);
    tracep->declBus(c+1416,"PTR_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1306,"w_clk", false,-1);
    tracep->declBit(c+1306,"r_clk", false,-1);
    tracep->declBit(c+640,"w_en", false,-1);
    tracep->declBit(c+171,"r_en", false,-1);
    tracep->declBus(c+638,"w_data", false,-1, 7,0);
    tracep->declBit(c+1356,"full", false,-1);
    tracep->declBit(c+1357,"empty", false,-1);
    tracep->declBus(c+641,"r_data", false,-1, 7,0);
    tracep->declBit(c+642,"r_data_valid", false,-1);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+643+i*1,"mem_array", true,(i+0), 7,0);
    }
    tracep->declBus(c+651,"w_ptr", false,-1, 3,0);
    tracep->declBus(c+652,"r_ptr", false,-1, 3,0);
    tracep->declBus(c+653,"i", false,-1, 3,0);
    tracep->declBus(c+654,"w_ptr_gray_d1", false,-1, 3,0);
    tracep->declBus(c+655,"w_ptr_gray_d2", false,-1, 3,0);
    tracep->declBus(c+656,"r_ptr_gray_d1", false,-1, 3,0);
    tracep->declBus(c+657,"r_ptr_gray_d2", false,-1, 3,0);
    tracep->declBus(c+658,"w_ptr_gray", false,-1, 3,0);
    tracep->declBus(c+659,"r_ptr_gray", false,-1, 3,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+1343,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1344,"auto_in_wvalid", false,-1);
    tracep->declBit(c+426,"auto_in_arready", false,-1);
    tracep->declBit(c+1345,"auto_in_arvalid", false,-1);
    tracep->declBus(c+356,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1239,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1346,"auto_in_rready", false,-1);
    tracep->declBit(c+427,"auto_in_rvalid", false,-1);
    tracep->declBus(c+428,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+429,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+427,"state", false,-1);
    tracep->declBus(c+429,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+428,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1305,"raddr", false,-1, 31,0);
    tracep->declBit(c+172,"ren", false,-1);
    tracep->declBus(c+173,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+140,"auto_in_psel", false,-1);
    tracep->declBit(c+51,"auto_in_penable", false,-1);
    tracep->declBit(c+130,"auto_in_pwrite", false,-1);
    tracep->declBus(c+128,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1370,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1334,"auto_in_pready", false,-1);
    tracep->declBit(c+1371,"auto_in_pslverr", false,-1);
    tracep->declBus(c+353,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+212,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+213,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+1329,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+128,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+140,"in_psel", false,-1);
    tracep->declBit(c+51,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1334,"in_pready", false,-1);
    tracep->declBus(c+353,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1371,"in_pslverr", false,-1);
    tracep->declBit(c+212,"qspi_sck", false,-1);
    tracep->declBit(c+213,"qspi_ce_n", false,-1);
    tracep->declBus(c+1329,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+1329,"din", false,-1, 3,0);
    tracep->declBus(c+329,"dout", false,-1, 3,0);
    tracep->declBus(c+330,"douten", false,-1, 3,0);
    tracep->declBit(c+1358,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1306,"clk_i", false,-1);
    tracep->declBit(c+1307,"rst_i", false,-1);
    tracep->declBus(c+128,"adr_i", false,-1, 31,0);
    tracep->declBus(c+131,"dat_i", false,-1, 31,0);
    tracep->declBus(c+353,"dat_o", false,-1, 31,0);
    tracep->declBus(c+132,"sel_i", false,-1, 3,0);
    tracep->declBit(c+140,"cyc_i", false,-1);
    tracep->declBit(c+140,"stb_i", false,-1);
    tracep->declBit(c+1358,"ack_o", false,-1);
    tracep->declBit(c+130,"we_i", false,-1);
    tracep->declBit(c+212,"sck", false,-1);
    tracep->declBit(c+213,"ce_n", false,-1);
    tracep->declBus(c+1329,"din", false,-1, 3,0);
    tracep->declBus(c+329,"dout", false,-1, 3,0);
    tracep->declBus(c+330,"douten", false,-1, 3,0);
    tracep->declBus(c+1427,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1428,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+783,"mr_sck", false,-1);
    tracep->declBit(c+784,"mr_ce_n", false,-1);
    tracep->declBus(c+1329,"mr_din", false,-1, 3,0);
    tracep->declBus(c+785,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+786,"mr_doe", false,-1);
    tracep->declBit(c+787,"mw_sck", false,-1);
    tracep->declBit(c+788,"mw_ce_n", false,-1);
    tracep->declBus(c+1329,"mw_din", false,-1, 3,0);
    tracep->declBus(c+331,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+789,"mw_doe", false,-1);
    tracep->declBit(c+332,"mr_rd", false,-1);
    tracep->declBit(c+790,"mr_done", false,-1);
    tracep->declBit(c+333,"mw_wr", false,-1);
    tracep->declBit(c+334,"mw_done", false,-1);
    tracep->declBit(c+140,"wb_valid", false,-1);
    tracep->declBit(c+174,"wb_we", false,-1);
    tracep->declBit(c+175,"wb_re", false,-1);
    tracep->declBit(c+791,"state", false,-1);
    tracep->declBit(c+335,"nstate", false,-1);
    tracep->declBus(c+176,"size", false,-1, 2,0);
    tracep->declBus(c+177,"byte0", false,-1, 7,0);
    tracep->declBus(c+178,"byte1", false,-1, 7,0);
    tracep->declBus(c+179,"byte2", false,-1, 7,0);
    tracep->declBus(c+180,"byte3", false,-1, 7,0);
    tracep->declBus(c+181,"wdata", false,-1, 31,0);
    tracep->declBit(c+660,"qpi_valid", false,-1);
    tracep->declBit(c+661,"qpi_ce_n", false,-1);
    tracep->declBus(c+1329,"qpi_din", false,-1, 3,0);
    tracep->declBus(c+662,"qpi_dout", false,-1, 3,0);
    tracep->declBit(c+1359,"qpi_sck", false,-1);
    tracep->declBit(c+660,"qpi_doe", false,-1);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1360,"rst_n", false,-1);
    tracep->declBus(c+182,"addr", false,-1, 23,0);
    tracep->declBit(c+332,"rd", false,-1);
    tracep->declBus(c+1429,"size", false,-1, 2,0);
    tracep->declBit(c+790,"done", false,-1);
    tracep->declBus(c+353,"line", false,-1, 31,0);
    tracep->declBit(c+783,"sck", false,-1);
    tracep->declBit(c+784,"ce_n", false,-1);
    tracep->declBus(c+1329,"din", false,-1, 3,0);
    tracep->declBus(c+785,"dout", false,-1, 3,0);
    tracep->declBit(c+786,"douten", false,-1);
    tracep->declBus(c+1427,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1428,"READ", false,-1, 0,0);
    tracep->declBus(c+1430,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+792,"state", false,-1);
    tracep->declBit(c+336,"nstate", false,-1);
    tracep->declBus(c+793,"counter", false,-1, 7,0);
    tracep->declBus(c+794,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+663+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1431,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+795,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1360,"rst_n", false,-1);
    tracep->declBus(c+183,"addr", false,-1, 23,0);
    tracep->declBus(c+181,"line", false,-1, 31,0);
    tracep->declBus(c+176,"size", false,-1, 2,0);
    tracep->declBit(c+333,"wr", false,-1);
    tracep->declBit(c+334,"done", false,-1);
    tracep->declBit(c+787,"sck", false,-1);
    tracep->declBit(c+788,"ce_n", false,-1);
    tracep->declBus(c+1329,"din", false,-1, 3,0);
    tracep->declBus(c+331,"dout", false,-1, 3,0);
    tracep->declBit(c+789,"douten", false,-1);
    tracep->declBus(c+1427,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1428,"WRITE", false,-1, 0,0);
    tracep->declBus(c+184,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+796,"state", false,-1);
    tracep->declBit(c+337,"nstate", false,-1);
    tracep->declBus(c+797,"counter", false,-1, 7,0);
    tracep->declBus(c+798,"saddr", false,-1, 23,0);
    tracep->declBus(c+1432,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("QPI ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1307,"rst", false,-1);
    tracep->declBit(c+660,"valid", false,-1);
    tracep->declBit(c+1359,"sck", false,-1);
    tracep->declBit(c+661,"ce_n", false,-1);
    tracep->declBus(c+1329,"din", false,-1, 3,0);
    tracep->declBus(c+662,"dout", false,-1, 3,0);
    tracep->declBit(c+660,"douten", false,-1);
    tracep->declBit(c+667,"finish", false,-1);
    tracep->declBus(c+1433,"H_35", false,-1, 7,0);
    tracep->declBus(c+668,"counter", false,-1, 2,0);
    tracep->declBus(c+669,"state", false,-1, 1,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+134,"auto_in_psel", false,-1);
    tracep->declBit(c+47,"auto_in_penable", false,-1);
    tracep->declBit(c+130,"auto_in_pwrite", false,-1);
    tracep->declBus(c+128,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1370,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+781,"auto_in_pready", false,-1);
    tracep->declBit(c+1371,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1332,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1330,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+774,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+775,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+776,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+777,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+778,"sdram_bundle_we", false,-1);
    tracep->declBus(c+779,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+780,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+1113,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+1331,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+128,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+134,"in_psel", false,-1);
    tracep->declBit(c+47,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+781,"in_pready", false,-1);
    tracep->declBus(c+1332,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1371,"in_pslverr", false,-1);
    tracep->declBit(c+1330,"sdram_clk", false,-1);
    tracep->declBit(c+774,"sdram_cke", false,-1);
    tracep->declBit(c+775,"sdram_cs", false,-1);
    tracep->declBit(c+776,"sdram_ras", false,-1);
    tracep->declBit(c+777,"sdram_cas", false,-1);
    tracep->declBit(c+778,"sdram_we", false,-1);
    tracep->declBus(c+779,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+780,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+1113,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+1331,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+1114,"sdram_dout_en", false,-1);
    tracep->declBus(c+1115,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+670,"state", false,-1, 1,0);
    tracep->declBit(c+1116,"req_accept", false,-1);
    tracep->declBit(c+185,"is_read", false,-1);
    tracep->declBit(c+186,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1306,"clk_i", false,-1);
    tracep->declBit(c+1307,"rst_i", false,-1);
    tracep->declBus(c+187,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+185,"inport_rd_i", false,-1);
    tracep->declBus(c+1380,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+128,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+131,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+1331,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+1116,"inport_accept_o", false,-1);
    tracep->declBit(c+781,"inport_ack_o", false,-1);
    tracep->declBit(c+1371,"inport_error_o", false,-1);
    tracep->declBus(c+1332,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1330,"sdram_clk_o", false,-1);
    tracep->declBit(c+774,"sdram_cke_o", false,-1);
    tracep->declBit(c+775,"sdram_cs_o", false,-1);
    tracep->declBit(c+776,"sdram_ras_o", false,-1);
    tracep->declBit(c+777,"sdram_cas_o", false,-1);
    tracep->declBit(c+778,"sdram_we_o", false,-1);
    tracep->declBus(c+1113,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+779,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+780,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+1115,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+1114,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1434,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1435,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1436,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1398,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1398,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1398,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1416,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1437,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1438,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1439,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1440,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1416,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1441,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1442,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1443,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1444,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1445,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1446,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1419,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1385,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1447,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1416,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1385,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1419,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1446,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1442,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1444,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1443,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1445,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1441,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1448,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1449,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1450,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1450,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1415,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1450,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1398,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1398,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1406,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+128,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+187,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+185,"ram_rd_w", false,-1);
    tracep->declBit(c+1116,"ram_accept_w", false,-1);
    tracep->declBus(c+131,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+1332,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+781,"ram_ack_w", false,-1);
    tracep->declBit(c+188,"ram_req_w", false,-1);
    tracep->declBus(c+799,"command_q", false,-1, 3,0);
    tracep->declBus(c+779,"addr_q", false,-1, 12,0);
    tracep->declBus(c+1115,"data_q", false,-1, 15,0);
    tracep->declBit(c+1117,"data_rd_en_q", false,-1);
    tracep->declBus(c+1113,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+774,"cke_q", false,-1);
    tracep->declBus(c+780,"bank_q", false,-1, 1,0);
    tracep->declBus(c+1118,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+1119,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+1331,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+800,"refresh_q", false,-1);
    tracep->declBus(c+801,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+802+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+1120,"state_q", false,-1, 3,0);
    tracep->declBus(c+338,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+339,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+806,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+807,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+189,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+190,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+191,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1416,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+808,"delay_q", false,-1, 3,0);
    tracep->declBus(c+340,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1451,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+809,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+810,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+811,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+812,"idx", false,-1, 31,0);
    tracep->declBus(c+813,"rd_q", false,-1, 3,0);
    tracep->declBit(c+781,"ack_q", false,-1);
    tracep->declArray(c+1121,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+144,"auto_in_psel", false,-1);
    tracep->declBit(c+52,"auto_in_penable", false,-1);
    tracep->declBit(c+130,"auto_in_pwrite", false,-1);
    tracep->declBus(c+136,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1370,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1336,"auto_in_pready", false,-1);
    tracep->declBit(c+1371,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1337,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+772,"spi_bundle_sck", false,-1);
    tracep->declBus(c+773,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1112,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1328,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1405,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1452,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1414,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+192,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+144,"in_psel", false,-1);
    tracep->declBit(c+52,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1336,"in_pready", false,-1);
    tracep->declBus(c+1337,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1371,"in_pslverr", false,-1);
    tracep->declBit(c+772,"spi_sck", false,-1);
    tracep->declBus(c+773,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1112,"spi_mosi", false,-1);
    tracep->declBit(c+1328,"spi_miso", false,-1);
    tracep->declBit(c+814,"spi_irq_out", false,-1);
    tracep->declBus(c+671,"state", false,-1, 2,0);
    tracep->declBit(c+672,"penable", false,-1);
    tracep->declBit(c+193,"is_xip_access", false,-1);
    tracep->declBus(c+673,"xip_paddr", false,-1, 4,0);
    tracep->declBus(c+194,"xip_pwdata", false,-1, 31,0);
    tracep->declBus(c+195,"xip_pstrb", false,-1, 3,0);
    tracep->declBit(c+674,"xip_pwirte", false,-1);
    tracep->declBit(c+815,"apb_pready", false,-1);
    tracep->declBus(c+196,"apb_addr", false,-1, 4,0);
    tracep->declBus(c+197,"apb_pwdata", false,-1, 31,0);
    tracep->declBus(c+195,"apb_pstrb", false,-1, 3,0);
    tracep->declBit(c+198,"apb_penable", false,-1);
    tracep->declBit(c+144,"apb_psel", false,-1);
    tracep->declBit(c+199,"apb_pwrite", false,-1);
    tracep->declBus(c+816,"apb_prdata", false,-1, 31,0);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1400,"Tp", false,-1, 31,0);
    tracep->declBit(c+1306,"wb_clk_i", false,-1);
    tracep->declBit(c+1307,"wb_rst_i", false,-1);
    tracep->declBus(c+196,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+197,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+816,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+195,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+199,"wb_we_i", false,-1);
    tracep->declBit(c+144,"wb_stb_i", false,-1);
    tracep->declBit(c+198,"wb_cyc_i", false,-1);
    tracep->declBit(c+815,"wb_ack_o", false,-1);
    tracep->declBit(c+1371,"wb_err_o", false,-1);
    tracep->declBit(c+814,"wb_int_o", false,-1);
    tracep->declBus(c+773,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+772,"sclk_pad_o", false,-1);
    tracep->declBit(c+1112,"mosi_pad_o", false,-1);
    tracep->declBit(c+1328,"miso_pad_i", false,-1);
    tracep->declBus(c+817,"divider", false,-1, 15,0);
    tracep->declBus(c+818,"ctrl", false,-1, 13,0);
    tracep->declBus(c+819,"ss", false,-1, 7,0);
    tracep->declBus(c+341,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+820,"rx", false,-1, 127,0);
    tracep->declBit(c+824,"rx_negedge", false,-1);
    tracep->declBit(c+825,"tx_negedge", false,-1);
    tracep->declBus(c+826,"char_len", false,-1, 6,0);
    tracep->declBit(c+827,"go", false,-1);
    tracep->declBit(c+828,"lsb", false,-1);
    tracep->declBit(c+829,"ie", false,-1);
    tracep->declBit(c+830,"ass", false,-1);
    tracep->declBit(c+200,"spi_divider_sel", false,-1);
    tracep->declBit(c+201,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+202,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+203,"spi_ss_sel", false,-1);
    tracep->declBit(c+831,"tip", false,-1);
    tracep->declBit(c+832,"pos_edge", false,-1);
    tracep->declBit(c+833,"neg_edge", false,-1);
    tracep->declBit(c+834,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1400,"Tp", false,-1, 31,0);
    tracep->declBit(c+1306,"clk_in", false,-1);
    tracep->declBit(c+1307,"rst", false,-1);
    tracep->declBit(c+831,"enable", false,-1);
    tracep->declBit(c+827,"go", false,-1);
    tracep->declBit(c+834,"last_clk", false,-1);
    tracep->declBus(c+817,"divider", false,-1, 15,0);
    tracep->declBit(c+772,"clk_out", false,-1);
    tracep->declBit(c+832,"pos_edge", false,-1);
    tracep->declBit(c+833,"neg_edge", false,-1);
    tracep->declBus(c+835,"cnt", false,-1, 15,0);
    tracep->declBit(c+836,"cnt_zero", false,-1);
    tracep->declBit(c+837,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1400,"Tp", false,-1, 31,0);
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1307,"rst", false,-1);
    tracep->declBus(c+204,"latch", false,-1, 3,0);
    tracep->declBus(c+195,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+826,"len", false,-1, 6,0);
    tracep->declBit(c+828,"lsb", false,-1);
    tracep->declBit(c+827,"go", false,-1);
    tracep->declBit(c+832,"pos_edge", false,-1);
    tracep->declBit(c+833,"neg_edge", false,-1);
    tracep->declBit(c+824,"rx_negedge", false,-1);
    tracep->declBit(c+825,"tx_negedge", false,-1);
    tracep->declBit(c+831,"tip", false,-1);
    tracep->declBit(c+834,"last", false,-1);
    tracep->declBus(c+197,"p_in", false,-1, 31,0);
    tracep->declArray(c+820,"p_out", false,-1, 127,0);
    tracep->declBit(c+772,"s_clk", false,-1);
    tracep->declBit(c+1328,"s_in", false,-1);
    tracep->declBit(c+1112,"s_out", false,-1);
    tracep->declBus(c+838,"cnt", false,-1, 7,0);
    tracep->declArray(c+820,"data", false,-1, 127,0);
    tracep->declBus(c+839,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+840,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+841,"rx_clk", false,-1);
    tracep->declBit(c+842,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+141,"auto_in_psel", false,-1);
    tracep->declBit(c+142,"auto_in_penable", false,-1);
    tracep->declBit(c+130,"auto_in_pwrite", false,-1);
    tracep->declBus(c+138,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1370,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+143,"auto_in_pready", false,-1);
    tracep->declBit(c+1371,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1335,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1326,"uart_rx", false,-1);
    tracep->declBit(c+1327,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+141,"in_psel", false,-1);
    tracep->declBit(c+142,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+143,"in_pready", false,-1);
    tracep->declBit(c+1371,"in_pslverr", false,-1);
    tracep->declBus(c+159,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+1335,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1326,"uart_rx", false,-1);
    tracep->declBit(c+1327,"uart_tx", false,-1);
    tracep->declBit(c+843,"rtsn", false,-1);
    tracep->declBit(c+1371,"ctsn", false,-1);
    tracep->declBit(c+844,"dtr_pad_o", false,-1);
    tracep->declBit(c+1371,"dsr_pad_i", false,-1);
    tracep->declBit(c+1371,"ri_pad_i", false,-1);
    tracep->declBit(c+1371,"dcd_pad_i", false,-1);
    tracep->declBit(c+845,"interrupt", false,-1);
    tracep->declBit(c+205,"reg_we", false,-1);
    tracep->declBit(c+206,"reg_re", false,-1);
    tracep->declBus(c+207,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+208,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+675,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+342,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+846,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1307,"wb_rst_i", false,-1);
    tracep->declBus(c+207,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+209,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+342,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+205,"wb_we_i", false,-1);
    tracep->declBit(c+206,"wb_re_i", false,-1);
    tracep->declBit(c+1327,"stx_pad_o", false,-1);
    tracep->declBit(c+1326,"srx_pad_i", false,-1);
    tracep->declBus(c+1448,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+846,"rts_pad_o", false,-1);
    tracep->declBit(c+844,"dtr_pad_o", false,-1);
    tracep->declBit(c+845,"int_o", false,-1);
    tracep->declBit(c+847,"enable", false,-1);
    tracep->declBit(c+848,"srx_pad", false,-1);
    tracep->declBus(c+849,"ier", false,-1, 3,0);
    tracep->declBus(c+850,"iir", false,-1, 3,0);
    tracep->declBus(c+851,"fcr", false,-1, 1,0);
    tracep->declBus(c+852,"mcr", false,-1, 4,0);
    tracep->declBus(c+853,"lcr", false,-1, 7,0);
    tracep->declBus(c+854,"msr", false,-1, 7,0);
    tracep->declBus(c+855,"dl", false,-1, 15,0);
    tracep->declBus(c+856,"scratch", false,-1, 7,0);
    tracep->declBit(c+857,"start_dlc", false,-1);
    tracep->declBit(c+858,"lsr_mask_d", false,-1);
    tracep->declBit(c+859,"msi_reset", false,-1);
    tracep->declBus(c+860,"dlc", false,-1, 15,0);
    tracep->declBus(c+861,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+862,"rx_reset", false,-1);
    tracep->declBit(c+863,"tx_reset", false,-1);
    tracep->declBit(c+864,"dlab", false,-1);
    tracep->declBit(c+1382,"cts_pad_i", false,-1);
    tracep->declBit(c+1371,"dsr_pad_i", false,-1);
    tracep->declBit(c+1371,"ri_pad_i", false,-1);
    tracep->declBit(c+1371,"dcd_pad_i", false,-1);
    tracep->declBit(c+865,"loopback", false,-1);
    tracep->declBit(c+1371,"cts", false,-1);
    tracep->declBit(c+1382,"dsr", false,-1);
    tracep->declBit(c+1382,"ri", false,-1);
    tracep->declBit(c+1382,"dcd", false,-1);
    tracep->declBit(c+866,"cts_c", false,-1);
    tracep->declBit(c+867,"dsr_c", false,-1);
    tracep->declBit(c+868,"ri_c", false,-1);
    tracep->declBit(c+869,"dcd_c", false,-1);
    tracep->declBus(c+870,"lsr", false,-1, 7,0);
    tracep->declBit(c+871,"lsr0", false,-1);
    tracep->declBit(c+872,"lsr1", false,-1);
    tracep->declBit(c+873,"lsr2", false,-1);
    tracep->declBit(c+874,"lsr3", false,-1);
    tracep->declBit(c+875,"lsr4", false,-1);
    tracep->declBit(c+876,"lsr5", false,-1);
    tracep->declBit(c+877,"lsr6", false,-1);
    tracep->declBit(c+878,"lsr7", false,-1);
    tracep->declBit(c+879,"lsr0r", false,-1);
    tracep->declBit(c+880,"lsr1r", false,-1);
    tracep->declBit(c+881,"lsr2r", false,-1);
    tracep->declBit(c+882,"lsr3r", false,-1);
    tracep->declBit(c+883,"lsr4r", false,-1);
    tracep->declBit(c+884,"lsr5r", false,-1);
    tracep->declBit(c+885,"lsr6r", false,-1);
    tracep->declBit(c+886,"lsr7r", false,-1);
    tracep->declBit(c+343,"lsr_mask", false,-1);
    tracep->declBit(c+887,"rls_int", false,-1);
    tracep->declBit(c+888,"rda_int", false,-1);
    tracep->declBit(c+889,"ti_int", false,-1);
    tracep->declBit(c+890,"thre_int", false,-1);
    tracep->declBit(c+891,"ms_int", false,-1);
    tracep->declBit(c+892,"tf_push", false,-1);
    tracep->declBit(c+893,"rf_pop", false,-1);
    tracep->declBus(c+1361,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+894,"rf_error_bit", false,-1);
    tracep->declBit(c+872,"rf_overrun", false,-1);
    tracep->declBit(c+895,"rf_push_pulse", false,-1);
    tracep->declBus(c+896,"rf_count", false,-1, 4,0);
    tracep->declBus(c+897,"tf_count", false,-1, 4,0);
    tracep->declBus(c+898,"tstate", false,-1, 2,0);
    tracep->declBus(c+899,"rstate", false,-1, 3,0);
    tracep->declBus(c+900,"counter_t", false,-1, 9,0);
    tracep->declBit(c+901,"thre_set_en", false,-1);
    tracep->declBus(c+902,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+903,"block_value", false,-1, 7,0);
    tracep->declBit(c+904,"serial_out", false,-1);
    tracep->declBit(c+905,"serial_in", false,-1);
    tracep->declBit(c+344,"lsr_mask_condition", false,-1);
    tracep->declBit(c+345,"iir_read", false,-1);
    tracep->declBit(c+346,"msr_read", false,-1);
    tracep->declBit(c+347,"fifo_read", false,-1);
    tracep->declBit(c+348,"fifo_write", false,-1);
    tracep->declBus(c+906,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+907,"lsr0_d", false,-1);
    tracep->declBit(c+908,"lsr1_d", false,-1);
    tracep->declBit(c+909,"lsr2_d", false,-1);
    tracep->declBit(c+910,"lsr3_d", false,-1);
    tracep->declBit(c+911,"lsr4_d", false,-1);
    tracep->declBit(c+912,"lsr5_d", false,-1);
    tracep->declBit(c+913,"lsr6_d", false,-1);
    tracep->declBit(c+914,"lsr7_d", false,-1);
    tracep->declBit(c+915,"rls_int_d", false,-1);
    tracep->declBit(c+916,"thre_int_d", false,-1);
    tracep->declBit(c+917,"ms_int_d", false,-1);
    tracep->declBit(c+918,"ti_int_d", false,-1);
    tracep->declBit(c+919,"rda_int_d", false,-1);
    tracep->declBit(c+920,"rls_int_rise", false,-1);
    tracep->declBit(c+921,"thre_int_rise", false,-1);
    tracep->declBit(c+922,"ms_int_rise", false,-1);
    tracep->declBit(c+923,"ti_int_rise", false,-1);
    tracep->declBit(c+924,"rda_int_rise", false,-1);
    tracep->declBit(c+925,"rls_int_pnd", false,-1);
    tracep->declBit(c+926,"rda_int_pnd", false,-1);
    tracep->declBit(c+927,"thre_int_pnd", false,-1);
    tracep->declBit(c+928,"ms_int_pnd", false,-1);
    tracep->declBit(c+929,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1400,"Tp", false,-1, 31,0);
    tracep->declBus(c+1400,"width", false,-1, 31,0);
    tracep->declBus(c+1428,"init_value", false,-1, 0,0);
    tracep->declBit(c+1307,"rst_i", false,-1);
    tracep->declBit(c+1306,"clk_i", false,-1);
    tracep->declBit(c+1371,"stage1_rst_i", false,-1);
    tracep->declBit(c+1382,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1326,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+848,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+930,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1307,"wb_rst_i", false,-1);
    tracep->declBus(c+853,"lcr", false,-1, 7,0);
    tracep->declBit(c+893,"rf_pop", false,-1);
    tracep->declBit(c+905,"srx_pad_i", false,-1);
    tracep->declBit(c+847,"enable", false,-1);
    tracep->declBit(c+862,"rx_reset", false,-1);
    tracep->declBit(c+343,"lsr_mask", false,-1);
    tracep->declBus(c+900,"counter_t", false,-1, 9,0);
    tracep->declBus(c+896,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1361,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+872,"rf_overrun", false,-1);
    tracep->declBit(c+894,"rf_error_bit", false,-1);
    tracep->declBus(c+899,"rstate", false,-1, 3,0);
    tracep->declBit(c+895,"rf_push_pulse", false,-1);
    tracep->declBus(c+931,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+932,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+933,"rshift", false,-1, 7,0);
    tracep->declBit(c+934,"rparity", false,-1);
    tracep->declBit(c+935,"rparity_error", false,-1);
    tracep->declBit(c+936,"rframing_error", false,-1);
    tracep->declBit(c+937,"rbit_in", false,-1);
    tracep->declBit(c+938,"rparity_xor", false,-1);
    tracep->declBus(c+939,"counter_b", false,-1, 7,0);
    tracep->declBit(c+940,"rf_push_q", false,-1);
    tracep->declBus(c+941,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+942,"rf_push", false,-1);
    tracep->declBit(c+943,"break_error", false,-1);
    tracep->declBit(c+944,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+945,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+946,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+947,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1385,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1419,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1446,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1442,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1444,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1443,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1445,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1441,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1448,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1449,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1453,"sr_push", false,-1, 3,0);
    tracep->declBus(c+948,"toc_value", false,-1, 9,0);
    tracep->declBus(c+949,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1454,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1415,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1416,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1422,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1307,"wb_rst_i", false,-1);
    tracep->declBit(c+895,"push", false,-1);
    tracep->declBit(c+893,"pop", false,-1);
    tracep->declBus(c+941,"data_in", false,-1, 10,0);
    tracep->declBit(c+862,"fifo_reset", false,-1);
    tracep->declBit(c+343,"reset_status", false,-1);
    tracep->declBus(c+1361,"data_out", false,-1, 10,0);
    tracep->declBit(c+872,"overrun", false,-1);
    tracep->declBus(c+896,"count", false,-1, 4,0);
    tracep->declBit(c+894,"error_bit", false,-1);
    tracep->declBus(c+1362,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+950+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+966,"top", false,-1, 3,0);
    tracep->declBus(c+967,"bottom", false,-1, 3,0);
    tracep->declBus(c+968,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+969,"word0", false,-1, 2,0);
    tracep->declBus(c+970,"word1", false,-1, 2,0);
    tracep->declBus(c+971,"word2", false,-1, 2,0);
    tracep->declBus(c+972,"word3", false,-1, 2,0);
    tracep->declBus(c+973,"word4", false,-1, 2,0);
    tracep->declBus(c+974,"word5", false,-1, 2,0);
    tracep->declBus(c+975,"word6", false,-1, 2,0);
    tracep->declBus(c+976,"word7", false,-1, 2,0);
    tracep->declBus(c+977,"word8", false,-1, 2,0);
    tracep->declBus(c+978,"word9", false,-1, 2,0);
    tracep->declBus(c+979,"word10", false,-1, 2,0);
    tracep->declBus(c+980,"word11", false,-1, 2,0);
    tracep->declBus(c+981,"word12", false,-1, 2,0);
    tracep->declBus(c+982,"word13", false,-1, 2,0);
    tracep->declBus(c+983,"word14", false,-1, 2,0);
    tracep->declBus(c+984,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1416,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1414,"data_width", false,-1, 31,0);
    tracep->declBus(c+1415,"depth", false,-1, 31,0);
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+895,"we", false,-1);
    tracep->declBus(c+966,"a", false,-1, 3,0);
    tracep->declBus(c+967,"dpra", false,-1, 3,0);
    tracep->declBus(c+985,"di", false,-1, 7,0);
    tracep->declBus(c+1362,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+676+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1307,"wb_rst_i", false,-1);
    tracep->declBus(c+853,"lcr", false,-1, 7,0);
    tracep->declBit(c+892,"tf_push", false,-1);
    tracep->declBus(c+209,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+847,"enable", false,-1);
    tracep->declBit(c+863,"tx_reset", false,-1);
    tracep->declBit(c+343,"lsr_mask", false,-1);
    tracep->declBit(c+904,"stx_pad_o", false,-1);
    tracep->declBus(c+898,"tstate", false,-1, 2,0);
    tracep->declBus(c+897,"tf_count", false,-1, 4,0);
    tracep->declBus(c+986,"counter", false,-1, 4,0);
    tracep->declBus(c+987,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+988,"shift_out", false,-1, 6,0);
    tracep->declBit(c+989,"stx_o_tmp", false,-1);
    tracep->declBit(c+990,"parity_xor", false,-1);
    tracep->declBit(c+991,"tf_pop", false,-1);
    tracep->declBit(c+992,"bit_out", false,-1);
    tracep->declBus(c+209,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1363,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+993,"tf_overrun", false,-1);
    tracep->declBus(c+1386,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1370,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1455,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1456,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1429,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1457,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1414,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1415,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1416,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1422,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+1307,"wb_rst_i", false,-1);
    tracep->declBit(c+892,"push", false,-1);
    tracep->declBit(c+991,"pop", false,-1);
    tracep->declBus(c+209,"data_in", false,-1, 7,0);
    tracep->declBit(c+863,"fifo_reset", false,-1);
    tracep->declBit(c+343,"reset_status", false,-1);
    tracep->declBus(c+1363,"data_out", false,-1, 7,0);
    tracep->declBit(c+993,"overrun", false,-1);
    tracep->declBus(c+897,"count", false,-1, 4,0);
    tracep->declBus(c+994,"top", false,-1, 3,0);
    tracep->declBus(c+995,"bottom", false,-1, 3,0);
    tracep->declBus(c+996,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1416,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1414,"data_width", false,-1, 31,0);
    tracep->declBus(c+1415,"depth", false,-1, 31,0);
    tracep->declBit(c+1306,"clk", false,-1);
    tracep->declBit(c+892,"we", false,-1);
    tracep->declBus(c+994,"a", false,-1, 3,0);
    tracep->declBus(c+995,"dpra", false,-1, 3,0);
    tracep->declBus(c+209,"di", false,-1, 7,0);
    tracep->declBus(c+1363,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+692+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBit(c+135,"auto_in_psel", false,-1);
    tracep->declBit(c+48,"auto_in_penable", false,-1);
    tracep->declBit(c+130,"auto_in_pwrite", false,-1);
    tracep->declBus(c+136,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1370,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+131,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+782,"auto_in_pready", false,-1);
    tracep->declBit(c+1372,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1373,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1320,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1321,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1322,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1323,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1324,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1325,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1306,"clock", false,-1);
    tracep->declBit(c+1307,"reset", false,-1);
    tracep->declBus(c+192,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+135,"in_psel", false,-1);
    tracep->declBit(c+48,"in_penable", false,-1);
    tracep->declBus(c+1370,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+130,"in_pwrite", false,-1);
    tracep->declBus(c+131,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+132,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+782,"in_pready", false,-1);
    tracep->declBus(c+1373,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1372,"in_pslverr", false,-1);
    tracep->declBus(c+1320,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1321,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1322,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1323,"vga_hsync", false,-1);
    tracep->declBit(c+1324,"vga_vsync", false,-1);
    tracep->declBit(c+1325,"vga_valid", false,-1);
    tracep->declBus(c+708,"state", false,-1, 1,0);
    tracep->declBit(c+54,"req_accept", false,-1);
    tracep->declBit(c+54,"is_write", false,-1);
    tracep->pushNamePrefix("vga_core_inst ");
    tracep->declBit(c+1306,"clk_i", false,-1);
    tracep->declBit(c+1307,"rst_i", false,-1);
    tracep->declBit(c+1371,"inport_rd_i", false,-1);
    tracep->declBus(c+132,"inport_wr_i", false,-1, 3,0);
    tracep->declBus(c+192,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+131,"inport_write_data_i", false,-1, 31,0);
    tracep->declBit(c+1371,"inport_len_i", false,-1);
    tracep->declBit(c+782,"inport_ack_o", false,-1);
    tracep->declBus(c+1320,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1321,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1322,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1323,"vga_hsync", false,-1);
    tracep->declBit(c+1324,"vga_vsync", false,-1);
    tracep->declBit(c+1325,"vga_valid", false,-1);
    tracep->declBus(c+1458,"h_frontporch", false,-1, 31,0);
    tracep->declBus(c+1459,"h_active", false,-1, 31,0);
    tracep->declBus(c+1460,"h_backporch", false,-1, 31,0);
    tracep->declBus(c+1461,"h_total", false,-1, 31,0);
    tracep->declBus(c+1398,"v_frontporch", false,-1, 31,0);
    tracep->declBus(c+1417,"v_active", false,-1, 31,0);
    tracep->declBus(c+1462,"v_backporch", false,-1, 31,0);
    tracep->declBus(c+1463,"v_total", false,-1, 31,0);
    tracep->declBus(c+709,"x_cnt", false,-1, 9,0);
    tracep->declBus(c+710,"y_cnt", false,-1, 9,0);
    tracep->declBit(c+711,"h_valid", false,-1);
    tracep->declBit(c+712,"v_valid", false,-1);
    tracep->declBus(c+713,"h_addr", false,-1, 9,0);
    tracep->declBus(c+714,"v_addr", false,-1, 9,0);
    tracep->declBus(c+715,"r_addr_i", false,-1, 31,0);
    tracep->declBus(c+716,"vga_data", false,-1, 23,0);
    tracep->pushNamePrefix("vgd_mem_inst ");
    tracep->declBit(c+1306,"clk_i", false,-1);
    tracep->declBit(c+1307,"rst_i", false,-1);
    tracep->declBus(c+192,"w_addr_i", false,-1, 31,0);
    tracep->declBus(c+715,"r_addr_i", false,-1, 31,0);
    tracep->declBus(c+132,"strb_i", false,-1, 3,0);
    tracep->declBit(c+1371,"is_read", false,-1);
    tracep->declBus(c+131,"data_i", false,-1, 31,0);
    tracep->declBus(c+716,"vga_data", false,-1, 23,0);
    tracep->declBit(c+782,"ack", false,-1);
    tracep->declBus(c+210,"w_h_addr", false,-1, 9,0);
    tracep->declBus(c+211,"w_v_addr", false,-1, 8,0);
    tracep->declBit(c+162,"write_enable", false,-1);
    tracep->declBus(c+717,"r_h_addr", false,-1, 9,0);
    tracep->declBus(c+718,"r_v_addr", false,-1, 8,0);
    tracep->declBit(c+782,"ack_o", false,-1);
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+772,"sck", false,-1);
    tracep->declBit(c+1124,"ss", false,-1);
    tracep->declBit(c+1112,"mosi", false,-1);
    tracep->declBit(c+1364,"miso", false,-1);
    tracep->declBus(c+1098,"buffer", false,-1, 7,0);
    tracep->declBus(c+1099,"count", false,-1, 2,0);
    tracep->declBus(c+1100,"state", false,-1, 1,0);
    tracep->declBit(c+1101,"buffer_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+772,"sck", false,-1);
    tracep->declBit(c+997,"ss", false,-1);
    tracep->declBit(c+1112,"mosi", false,-1);
    tracep->declBit(c+1365,"miso", false,-1);
    tracep->declBit(c+997,"reset", false,-1);
    tracep->declBus(c+1092,"state", false,-1, 2,0);
    tracep->declBus(c+1093,"counter", false,-1, 7,0);
    tracep->declBus(c+1094,"cmd", false,-1, 7,0);
    tracep->declBus(c+1095,"addr", false,-1, 23,0);
    tracep->declBus(c+1096,"data", false,-1, 31,0);
    tracep->declBit(c+1097,"ren", false,-1);
    tracep->declBus(c+1366,"rdata", false,-1, 31,0);
    tracep->declBus(c+1367,"raddr", false,-1, 31,0);
    tracep->declBus(c+1368,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+772,"clock", false,-1);
    tracep->declBit(c+1097,"valid", false,-1);
    tracep->declBus(c+1094,"cmd", false,-1, 7,0);
    tracep->declBus(c+1367,"addr", false,-1, 31,0);
    tracep->declBus(c+1366,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+212,"sck", false,-1);
    tracep->declBit(c+213,"ce_n", false,-1);
    tracep->declBus(c+1329,"dio", false,-1, 3,0);
    tracep->declBus(c+761,"state", false,-1, 3,0);
    tracep->declBus(c+762,"inst_buffer", false,-1, 7,0);
    tracep->declBus(c+763,"addr_buffer", false,-1, 23,0);
    tracep->declBus(c+764,"inst_counter", false,-1, 2,0);
    tracep->declBus(c+765,"addr_counter", false,-1, 2,0);
    tracep->declBus(c+766,"wait_counter", false,-1, 2,0);
    tracep->declBus(c+767,"data", false,-1, 7,0);
    tracep->declBit(c+768,"finish", false,-1);
    tracep->declBus(c+769,"dio_out_reg", false,-1, 3,0);
    tracep->declBit(c+770,"dio_en", false,-1);
    tracep->declBit(c+771,"qpi_mode", false,-1);
    tracep->declBit(c+213,"reset", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1330,"clk", false,-1);
    tracep->declBit(c+774,"cke", false,-1);
    tracep->declBit(c+775,"cs", false,-1);
    tracep->declBit(c+776,"ras", false,-1);
    tracep->declBit(c+777,"cas", false,-1);
    tracep->declBit(c+778,"we", false,-1);
    tracep->declBus(c+779,"a", false,-1, 12,0);
    tracep->declBus(c+780,"ba", false,-1, 1,0);
    tracep->declBus(c+1113,"dqm", false,-1, 1,0);
    tracep->declBus(c+1331,"dq", false,-1, 15,0);
    tracep->declBus(c+719,"mode_q", false,-1, 12,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+720+i*1,"row_reg", true,(i+0), 12,0);
    }
    tracep->declBit(c+775,"command_inhibit", false,-1);
    tracep->declBit(c+998,"no_operation", false,-1);
    tracep->declBit(c+999,"active", false,-1);
    tracep->declBit(c+1000,"read", false,-1);
    tracep->declBit(c+1001,"write", false,-1);
    tracep->declBit(c+1002,"burst_terminate", false,-1);
    tracep->declBit(c+1003,"precharge", false,-1);
    tracep->declBit(c+1004,"auto_refresh", false,-1);
    tracep->declBit(c+1005,"load_mode_register", false,-1);
    tracep->declBit(c+1006,"nop", false,-1);
    tracep->declBus(c+1408,"CAS_TIMER_W", false,-1, 31,0);
    tracep->declBus(c+724,"cas_timer_q", false,-1, 2,0);
    tracep->declBit(c+725,"cas_done", false,-1);
    tracep->declBit(c+726,"counting", false,-1);
    tracep->declBit(c+1464,"cas_start", false,-1);
    tracep->declBus(c+1408,"BL_TIMER_W", false,-1, 31,0);
    tracep->declBus(c+727,"bl_timer_q", false,-1, 2,0);
    tracep->declBit(c+728,"bl_valid", false,-1);
    tracep->declBit(c+729,"bl_start_q", false,-1);
    tracep->declBit(c+730,"bl_done", false,-1);
    tracep->declBus(c+1406,"MAX_PIPELINE", false,-1, 31,0);
    tracep->declBus(c+1465,"rd_pip_in_addr_q", false,-1, 12,0);
    tracep->declBit(c+1466,"rd_pip_in_val_q", false,-1);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+731+i*1,"pip_addr_q", true,(i+0), 12,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBit(c+737+i*1,"pip_valid_q", true,(i+0));
    }
    tracep->declBus(c+1008,"data_output", false,-1, 15,0);
    tracep->declBus(c+743,"pipeline_cl", false,-1, 2,0);
    tracep->declBus(c+1009,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBus(c+743,"cl", false,-1, 2,0);
    tracep->declBus(c+744,"select_bank", false,-1, 1,0);
    tracep->declBus(c+745,"select_col", false,-1, 9,0);
    tracep->declBit(c+746,"select_valid", false,-1);
    tracep->declBit(c+1010,"rd_data_valid_q", false,-1);
    tracep->declBus(c+747,"dqm_pipe", false,-1, 3,0);
    tracep->declBus(c+748,"rd_dqm_out_q", false,-1, 1,0);
    tracep->declBit(c+749,"read_state_r", false,-1);
    tracep->declBus(c+1331,"sdram_data", false,-1, 15,0);
    tracep->declBus(c+750,"wr_in_addr_q", false,-1, 12,0);
    tracep->declBit(c+751,"wr_in_val_q", false,-1);
    tracep->declBus(c+752,"mode_val_q", false,-1, 12,0);
    tracep->declBit(c+753,"mode_chg_q", false,-1);
    tracep->declBus(c+754,"acti_val_q", false,-1, 14,0);
    tracep->declBit(c+755,"acti_chg_q", false,-1);
    tracep->declBus(c+1385,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1419,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1446,"STATE_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1442,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1444,"STATE_READ_DATA", false,-1, 3,0);
    tracep->declBus(c+1443,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1445,"STATE_WRITE", false,-1, 3,0);
    tracep->declBus(c+1441,"STATE_WRITE_DATA", false,-1, 3,0);
    tracep->declBus(c+1449,"STATE_MODE_REG", false,-1, 3,0);
    tracep->declBus(c+756,"state_current_q", false,-1, 3,0);
    tracep->declBus(c+1102,"state_next_r", false,-1, 3,0);
    tracep->declBit(c+1369,"valclk", false,-1);
    tracep->declBus(c+757,"prev_addr_q", false,-1, 12,0);
    tracep->declBus(c+1007,"cur_addr_r", false,-1, 12,0);
    tracep->declBus(c+758,"cur_addr_b_r", false,-1, 12,0);
    tracep->declBus(c+1103,"rd_pip_in_addr_r", false,-1, 12,0);
    tracep->declBit(c+1104,"rd_pip_in_val_r", false,-1);
    tracep->declBus(c+1105,"wr_in_addr_r", false,-1, 12,0);
    tracep->declBit(c+1106,"wr_in_val_r", false,-1);
    tracep->declBit(c+1107,"bl_start_r", false,-1);
    tracep->declBit(c+1108,"mode_chg_r", false,-1);
    tracep->declBus(c+1109,"mode_val_r", false,-1, 12,0);
    tracep->declBit(c+1110,"acti_chg_r", false,-1);
    tracep->declBus(c+1111,"acti_val_r", false,-1, 14,0);
    tracep->declBit(c+759,"sig_save_addr", false,-1);
    tracep->pushNamePrefix("decoder ");
    tracep->declBit(c+775,"cs_n", false,-1);
    tracep->declBit(c+776,"ras_n", false,-1);
    tracep->declBit(c+777,"cas_n", false,-1);
    tracep->declBit(c+778,"we_n", false,-1);
    tracep->declBit(c+775,"command_inhibit", false,-1);
    tracep->declBit(c+998,"no_operation", false,-1);
    tracep->declBit(c+999,"active", false,-1);
    tracep->declBit(c+1000,"read", false,-1);
    tracep->declBit(c+1001,"write", false,-1);
    tracep->declBit(c+1002,"burst_terminate", false,-1);
    tracep->declBit(c+1003,"precharge", false,-1);
    tracep->declBit(c+1004,"auto_refresh", false,-1);
    tracep->declBit(c+1005,"load_mode_register", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+760,"i", false,-1, 31,0);
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
    bufp->fullBit(oldp+54,(((((~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                                  & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))) 
                             | (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__state))) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write))));
    bufp->fullIData(oldp+55,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                           : 0U) | 
                                         ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                           : 0U)))),32);
    bufp->fullBit(oldp+56,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+57,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+58,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+60,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+62,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+63,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+65,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+66,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+69,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+70,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+71,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+72,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+73,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+74,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+75,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+76,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+77,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+78,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+79,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+80,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+81,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+82,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+83,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+84,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+85,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+86,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+87,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+88,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+89,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+90,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+91,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+93,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+94,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+95,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+97,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+98,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+99,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+110,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+111,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__byte_enable),4);
    bufp->fullBit(oldp+133,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+134,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+135,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+136,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+137,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+138,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+139,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+143,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_psel));
    bufp->fullBit(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+149,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+152,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+153,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+154,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+156,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+157,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+158,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+159,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__is_read));
    bufp->fullBit(oldp+161,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT____VdfgTmp_hfb738304__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write))));
    bufp->fullBit(oldp+162,((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__byte_enable))));
    bufp->fullBit(oldp+163,((0U == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullBit(oldp+164,((4U == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullBit(oldp+165,((8U == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullBit(oldp+166,((0xcU == (0xfU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w))));
    bufp->fullCData(oldp+167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__state_next_r),2);
    bufp->fullBit(oldp+168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__write_enable_r));
    bufp->fullBit(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__idle_ack_r));
    bufp->fullBit(oldp+170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__is_read));
    bufp->fullBit(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_en));
    bufp->fullBit(oldp+172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+173,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+174,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+175,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+176,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+179,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+180,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+181,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+182,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+183,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+184,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+186,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+189,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+190,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+191,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+192,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__is_xip_access));
    bufp->fullIData(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pwdata),32);
    bufp->fullCData(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pstrb),4);
    bufp->fullCData(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr),5);
    bufp->fullIData(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwdata),32);
    bufp->fullBit(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_penable));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwrite));
    bufp->fullBit(oldp+200,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullBit(oldp+201,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__spi_tx_sel),4);
    bufp->fullBit(oldp+203,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+207,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullSData(oldp+210,((0x3ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 2U))),10);
    bufp->fullSData(oldp+211,((0x1ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 0xcU))),9);
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT___asic_psram_sck));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__psram__DOT__reset));
    bufp->fullBit(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+218,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+222,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+226,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+230,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+231,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+232,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+234,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+235,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+236,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+237,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+238,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+239,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+240,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+241,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+242,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+243,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+244,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+245,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+246,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+247,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+248,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+250,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+254,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+258,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+259,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+260,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+261,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+262,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+265,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+266,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+267,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+268,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+269,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+270,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+271,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+272,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+273,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+274,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+275,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+276,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+277,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+278,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+279,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+280,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+281,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+282,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+283,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+284,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+285,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+286,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+287,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+288,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+289,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+290,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+291,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+292,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+293,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+294,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+295,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+296,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+297,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+298,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+299,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+300,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+301,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+302,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+307,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+308,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+309,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+310,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+311,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+312,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+313,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                              [1U]),2);
    bufp->fullBit(oldp+316,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                   >> 1U))));
    bufp->fullIData(oldp+317,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+321,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data))),32);
    bufp->fullIData(oldp+322,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data))),32);
    bufp->fullCData(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data),8);
    bufp->fullSData(oldp+324,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data),16);
    bufp->fullSData(oldp+325,((0xffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),16);
    bufp->fullCData(oldp+326,((0xffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),8);
    bufp->fullIData(oldp+327,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+345,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullBit(oldp+349,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullBit(oldp+350,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__idle_ack_q));
    bufp->fullIData(oldp+351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_data),32);
    bufp->fullBit(oldp+352,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__idle_ack_q));
    bufp->fullIData(oldp+353,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+354,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+355,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+356,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+358,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+359,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+360,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+361,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+362,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+363,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+364,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+365,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+366,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+367,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+368,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+369,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+370,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+371,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+372,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+373,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+374,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+375,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+377,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+378,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+379,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+382,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+383,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+384,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+385,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+386,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+387,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+391,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullQData(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+407,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+413,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+417,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+426,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+433,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+442,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+443,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+444,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+452,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+454,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+455,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+456,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+457,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+461,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+462,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+464,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+468,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+472,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+482,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+484,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+486,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+488,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+490,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+492,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+494,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+496,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+498,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+501,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+502,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+503,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+506,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+510,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+512,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+514,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+516,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+518,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+522,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+524,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+525,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+526,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+529,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+530,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+532,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+533,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+534,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+536,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+538,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+540,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+541,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+542,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+544,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+545,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+546,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+548,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+549,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+550,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+552,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+554,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+558,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+560,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+562,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+566,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+570,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+572,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+573,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+574,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+575,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+577,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+578,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+582,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+586,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+590,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+594,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+598,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+602,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+606,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullCData(oldp+610,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready),2);
    bufp->fullBit(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+613,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+614,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready) 
                                   >> 1U))));
    bufp->fullCData(oldp+615,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state),2);
    bufp->fullBit(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+617,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+618,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+621,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+622,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+623,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+624,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+625,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+626,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__state),2);
    bufp->fullIData(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__segment_reg_q),32);
    bufp->fullBit(oldp+628,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__accept_o));
    bufp->fullSData(oldp+629,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__gpio_out_light_q),16);
    bufp->fullSData(oldp+630,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__gpio_int_sw_q),16);
    bufp->fullCData(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__state_current_q),2);
    bufp->fullBit(oldp+632,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__write_enable_q));
    bufp->fullCData(oldp+633,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__state),2);
    bufp->fullBit(oldp+634,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__state));
    bufp->fullCData(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__ps2_clk_sync),3);
    bufp->fullCData(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__count),4);
    bufp->fullSData(oldp+637,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__buffer),10);
    bufp->fullCData(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__buffer_out),8);
    bufp->fullBit(oldp+639,((IData)((4U == (6U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__ps2_clk_sync))))));
    bufp->fullBit(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__buffer_out_valid));
    bufp->fullCData(oldp+641,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_data),8);
    bufp->fullBit(oldp+642,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_data_valid));
    bufp->fullCData(oldp+643,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[0]),8);
    bufp->fullCData(oldp+644,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[1]),8);
    bufp->fullCData(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[2]),8);
    bufp->fullCData(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[3]),8);
    bufp->fullCData(oldp+647,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[4]),8);
    bufp->fullCData(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[5]),8);
    bufp->fullCData(oldp+649,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[6]),8);
    bufp->fullCData(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__mem_array[7]),8);
    bufp->fullCData(oldp+651,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__w_ptr),4);
    bufp->fullCData(oldp+652,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_ptr),4);
    bufp->fullCData(oldp+653,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__i),4);
    bufp->fullCData(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__w_ptr_gray_d1),4);
    bufp->fullCData(oldp+655,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__w_ptr_gray_d2),4);
    bufp->fullCData(oldp+656,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_ptr_gray_d1),4);
    bufp->fullCData(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_ptr_gray_d2),4);
    bufp->fullCData(oldp+658,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__w_ptr_gray),4);
    bufp->fullCData(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__r_ptr_gray),4);
    bufp->fullBit(oldp+660,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))));
    bufp->fullBit(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__qpi_ce_n));
    bufp->fullCData(oldp+662,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))
                                ? (1U & (0x35U >> (7U 
                                                   & ((IData)(7U) 
                                                      - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter)))))
                                : 0U)),4);
    bufp->fullCData(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+666,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullBit(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__finish));
    bufp->fullCData(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter),3);
    bufp->fullCData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state),2);
    bufp->fullCData(oldp+670,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state),3);
    bufp->fullBit(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__penable));
    bufp->fullCData(oldp+673,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
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
    bufp->fullBit(oldp+674,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                             | ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                | ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                   | ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                      | (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))))))));
    bufp->fullCData(oldp+675,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+676,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+677,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+679,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+680,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+681,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+682,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+683,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+684,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+685,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+686,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+687,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+688,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+689,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+690,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+691,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+692,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+693,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+694,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+695,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+696,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+697,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+698,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+699,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+700,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+701,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+702,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+704,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+705,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+706,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+707,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+708,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__state),2);
    bufp->fullSData(oldp+709,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__x_cnt),10);
    bufp->fullSData(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__y_cnt),10);
    bufp->fullBit(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__h_valid));
    bufp->fullBit(oldp+712,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__v_valid));
    bufp->fullSData(oldp+713,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__h_valid)
                                ? (0x3ffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__x_cnt) 
                                             - (IData)(0x91U)))
                                : 0U)),10);
    bufp->fullSData(oldp+714,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__v_valid)
                                ? (0x3ffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__y_cnt) 
                                             - (IData)(0x24U)))
                                : 0U)),10);
    bufp->fullIData(oldp+715,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__v_valid)
                                  ? (0x3ffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__y_cnt) 
                                               - (IData)(0x24U)))
                                  : 0U) << 0xaU) | 
                               ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__h_valid)
                                 ? (0x3ffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__x_cnt) 
                                              - (IData)(0x91U)))
                                 : 0U))),32);
    bufp->fullIData(oldp+716,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__vga_data),24);
    bufp->fullSData(oldp+717,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__v_valid)
                                  ? (3U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__y_cnt) 
                                           - (IData)(0x24U)))
                                  : 0U) << 8U) | (0xffU 
                                                  & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__h_valid)
                                                       ? 
                                                      (0x3ffU 
                                                       & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__x_cnt) 
                                                          - (IData)(0x91U)))
                                                       : 0U) 
                                                     >> 2U)))),10);
    bufp->fullSData(oldp+718,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__v_valid)
                                ? (0xffU & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__y_cnt) 
                                             - (IData)(0x24U)) 
                                            >> 2U))
                                : 0U)),9);
    bufp->fullSData(oldp+719,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q),13);
    bufp->fullSData(oldp+720,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[0]),13);
    bufp->fullSData(oldp+721,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[1]),13);
    bufp->fullSData(oldp+722,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[2]),13);
    bufp->fullSData(oldp+723,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row_reg[3]),13);
    bufp->fullCData(oldp+724,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_timer_q),3);
    bufp->fullBit(oldp+725,(((0U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_timer_q)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__counting))));
    bufp->fullBit(oldp+726,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__counting));
    bufp->fullCData(oldp+727,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_timer_q),3);
    bufp->fullBit(oldp+728,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_valid));
    bufp->fullBit(oldp+729,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_start_q));
    bufp->fullBit(oldp+730,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_done));
    bufp->fullSData(oldp+731,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[0]),13);
    bufp->fullSData(oldp+732,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[1]),13);
    bufp->fullSData(oldp+733,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[2]),13);
    bufp->fullSData(oldp+734,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[3]),13);
    bufp->fullSData(oldp+735,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[4]),13);
    bufp->fullSData(oldp+736,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[5]),13);
    bufp->fullBit(oldp+737,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[0]));
    bufp->fullBit(oldp+738,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[1]));
    bufp->fullBit(oldp+739,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[2]));
    bufp->fullBit(oldp+740,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[3]));
    bufp->fullBit(oldp+741,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[4]));
    bufp->fullBit(oldp+742,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[5]));
    bufp->fullCData(oldp+743,((7U & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q) 
                                     >> 4U))),3);
    bufp->fullCData(oldp+744,((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h7c6dd055__0) 
                                     >> 0xbU))),2);
    bufp->fullSData(oldp+745,((0x3ffU & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h7c6dd055__0))),10);
    bufp->fullBit(oldp+746,(((5U >= (7U & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q) 
                                            >> 4U) 
                                           - (IData)(2U)))) 
                             & vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q
                             [(7U & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q) 
                                      >> 4U) - (IData)(2U)))])));
    bufp->fullCData(oldp+747,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__dqm_pipe),4);
    bufp->fullCData(oldp+748,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_dqm_out_q),2);
    bufp->fullBit(oldp+749,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                             | (4U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)))));
    bufp->fullSData(oldp+750,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_addr_q),13);
    bufp->fullBit(oldp+751,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_val_q));
    bufp->fullSData(oldp+752,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_val_q),13);
    bufp->fullBit(oldp+753,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_chg_q));
    bufp->fullSData(oldp+754,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_val_q),15);
    bufp->fullBit(oldp+755,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_chg_q));
    bufp->fullCData(oldp+756,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q),4);
    bufp->fullSData(oldp+757,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__prev_addr_q),13);
    bufp->fullSData(oldp+758,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cur_addr_b_r),13);
    bufp->fullBit(oldp+759,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                             | ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                                | ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                                   | (7U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)))))));
    bufp->fullIData(oldp+760,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+761,(vlSelf->ysyxSoCFull__DOT__psram__DOT__state),4);
    bufp->fullCData(oldp+762,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_buffer),8);
    bufp->fullIData(oldp+763,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_buffer),24);
    bufp->fullCData(oldp+764,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_counter),3);
    bufp->fullCData(oldp+765,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_counter),3);
    bufp->fullCData(oldp+766,(vlSelf->ysyxSoCFull__DOT__psram__DOT__wait_counter),3);
    bufp->fullCData(oldp+767,(vlSelf->ysyxSoCFull__DOT__psram__DOT__data),8);
    bufp->fullBit(oldp+768,(vlSelf->ysyxSoCFull__DOT__psram__DOT__finish));
    bufp->fullCData(oldp+769,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_out_reg),4);
    bufp->fullBit(oldp+770,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_en));
    bufp->fullBit(oldp+771,(vlSelf->ysyxSoCFull__DOT__psram__DOT__qpi_mode));
    bufp->fullBit(oldp+772,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+773,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+774,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+775,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+776,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+777,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+778,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+779,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+780,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullBit(oldp+781,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullBit(oldp+782,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__vga_core_inst__DOT__vgd_mem_inst__DOT__ack_o));
    bufp->fullBit(oldp+783,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+784,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+785,(((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
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
    bufp->fullBit(oldp+786,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+788,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+789,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+790,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+793,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+795,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+796,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+797,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+798,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullCData(oldp+799,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+800,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+801,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+803,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+804,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+805,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+806,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+807,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+808,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+809,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+810,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+811,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+812,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+813,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullBit(oldp+814,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullBit(oldp+815,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready));
    bufp->fullIData(oldp+816,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_prdata),32);
    bufp->fullSData(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+818,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+820,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+824,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+825,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+826,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+827,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+828,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+829,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+830,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+833,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+834,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+836,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+837,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+839,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+840,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+841,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+843,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+844,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+846,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+848,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+850,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+858,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+860,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+861,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+862,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+863,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+864,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+865,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+866,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+867,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+868,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+869,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+870,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+873,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+874,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+875,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+877,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+883,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+884,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+885,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+886,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+887,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+889,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+894,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+900,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+901,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+908,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+920,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+921,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+922,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+923,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+924,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+925,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+928,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+929,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+930,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+931,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+932,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+933,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+936,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+937,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+938,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+939,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+940,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+941,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+942,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+943,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+944,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+945,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+946,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+947,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+948,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+949,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+950,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+951,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+952,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+953,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+954,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+955,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+956,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+957,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+958,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+959,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+960,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+961,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+962,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+963,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+964,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+965,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+966,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+967,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+968,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+969,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+972,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+973,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+975,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+976,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+977,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+978,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+979,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+980,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+981,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+983,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+984,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+985,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+987,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+988,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+989,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+990,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+991,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+992,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+993,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+994,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+995,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+996,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+997,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullBit(oldp+998,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6beba8fe__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullBit(oldp+999,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__active));
    bufp->fullBit(oldp+1000,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__read));
    bufp->fullBit(oldp+1001,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__write));
    bufp->fullBit(oldp+1002,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__burst_terminate));
    bufp->fullBit(oldp+1003,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6818f070__0))));
    bufp->fullBit(oldp+1004,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h84ea0254__0) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullBit(oldp+1005,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__load_mode_register));
    bufp->fullBit(oldp+1006,((((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h84ea0254__0) 
                               | (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6beba8fe__0)) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+1007,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cur_addr_r),13);
    bufp->fullSData(oldp+1008,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_data_valid_q)
                                 ? (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__sdram_data_input_i)
                                 : 0U)),16);
    bufp->fullSData(oldp+1009,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__sdram_data_input_i),16);
    bufp->fullBit(oldp+1010,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_data_valid_q));
    bufp->fullIData(oldp+1011,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+1012,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                               [2U]),32);
    bufp->fullIData(oldp+1013,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                               [1U]),32);
    bufp->fullIData(oldp+1014,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+1015,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+1016,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+1017,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+1018,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+1019,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+1020,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+1021,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+1022,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+1023,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+1024,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+1025,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+1026,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+1027,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+1029,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+1030,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+1031,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+1032,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+1034,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+1038,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+1046,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+1047,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+1048,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+1049,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+1050,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+1051,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[4]),32);
    bufp->fullIData(oldp+1052,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[5]),32);
    bufp->fullIData(oldp+1053,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+1054,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+1055,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+1056,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+1057,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+1058,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+1059,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+1060,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+1061,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+1062,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+1063,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+1064,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+1065,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+1066,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+1067,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+1068,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+1069,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+1070,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+1071,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+1072,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+1073,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+1074,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+1075,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+1076,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+1077,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+1078,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+1079,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+1080,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+1081,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+1082,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+1083,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+1084,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+1085,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+1086,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+1087,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+1088,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+1089,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[4]),32);
    bufp->fullIData(oldp+1090,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[5]),32);
    bufp->fullIData(oldp+1091,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+1092,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+1093,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+1094,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+1095,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+1096,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+1097,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                              & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+1098,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer),8);
    bufp->fullCData(oldp+1099,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count),3);
    bufp->fullCData(oldp+1100,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state),2);
    bufp->fullBit(oldp+1101,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                    >> (7U & ((IData)(7U) 
                                              - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))));
    bufp->fullCData(oldp+1102,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_next_r),4);
    bufp->fullSData(oldp+1103,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_addr_r),13);
    bufp->fullBit(oldp+1104,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_val_r));
    bufp->fullSData(oldp+1105,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_addr_r),13);
    bufp->fullBit(oldp+1106,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_val_r));
    bufp->fullBit(oldp+1107,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_start_r));
    bufp->fullBit(oldp+1108,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_chg_r));
    bufp->fullSData(oldp+1109,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_val_r),13);
    bufp->fullBit(oldp+1110,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_chg_r));
    bufp->fullSData(oldp+1111,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__acti_val_r),15);
    bufp->fullBit(oldp+1112,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullCData(oldp+1113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullBit(oldp+1114,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+1115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+1116,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                              | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullBit(oldp+1117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+1118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+1119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullCData(oldp+1120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullWData(oldp+1121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+1124,(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss));
    bufp->fullCData(oldp+1125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+1126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__arsize_out_reg),3);
    bufp->fullBit(oldp+1127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+1128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+1129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+1130,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullBit(oldp+1131,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullBit(oldp+1132,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+1133,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 0xfU))),5);
    bufp->fullCData(oldp+1134,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 0x14U))),5);
    bufp->fullCData(oldp+1135,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 7U))),5);
    bufp->fullIData(oldp+1136,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+1137,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1138,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1139,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1140,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                 | ((0x33U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | ((0x6fU == (0x7fU 
                                                  & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                       | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+1141,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1142,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+1144,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                      >> 0xcU))),3);
    bufp->fullCData(oldp+1145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+1146,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                    >> 0x1eU))));
    bufp->fullBit(oldp+1147,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1148,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1149,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1150,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+1151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+1152,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+1153,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+1154,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+1155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+1156,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                                << 1U)),2);
    bufp->fullCData(oldp+1157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+1158,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+1159,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U)),2);
    bufp->fullCData(oldp+1160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullCData(oldp+1161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[0]),3);
    bufp->fullCData(oldp+1162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[1]),3);
    bufp->fullCData(oldp+1163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[0]),3);
    bufp->fullCData(oldp+1164,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[1]),3);
    bufp->fullCData(oldp+1165,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+1166,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+1167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+1168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+1169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+1170,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1171,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1172,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1173,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+1174,(((IData)((0x6000U == 
                                         (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                 ? 8U : ((1U & VL_REDXOR_16(
                                                            (0x6000U 
                                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                          ? 9U : 3U))),4);
    bufp->fullCData(oldp+1175,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+1176,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1177,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+1178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+1179,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+1181,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+1182,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+1183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+1184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+1185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+1186,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 | ((0x17U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+1187,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1188,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))));
    bufp->fullCData(oldp+1189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),3);
    bufp->fullSData(oldp+1190,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                >> 0x14U)),12);
    bufp->fullCData(oldp+1191,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),3);
    bufp->fullCData(oldp+1192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+1194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+1195,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    >> 1U))));
    bufp->fullCData(oldp+1196,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : 2U))),3);
    bufp->fullCData(oldp+1197,(((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 1U : ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 2U : 0U))),2);
    bufp->fullCData(oldp+1198,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : ((4U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 2U
                                                   : 0U)))),3);
    bufp->fullCData(oldp+1199,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullWData(oldp+1200,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1209,((0x11830U | ((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullCData(oldp+1210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[0]),6);
    bufp->fullCData(oldp+1211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[1]),6);
    bufp->fullCData(oldp+1212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[2]),6);
    bufp->fullCData(oldp+1213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[3]),6);
    bufp->fullCData(oldp+1214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[0]),4);
    bufp->fullCData(oldp+1215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[1]),4);
    bufp->fullCData(oldp+1216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[2]),4);
    bufp->fullCData(oldp+1217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[3]),4);
    bufp->fullIData(oldp+1218,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullCData(oldp+1219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullIData(oldp+1220,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullCData(oldp+1221,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullIData(oldp+1222,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullCData(oldp+1224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awsize_out_reg),3);
    bufp->fullCData(oldp+1225,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullIData(oldp+1226,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullCData(oldp+1227,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullIData(oldp+1228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1230,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1232,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullCData(oldp+1233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullIData(oldp+1234,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1235,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1236,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1237,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1238,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1239,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1240,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1241,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1242,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1243,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1244,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
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
    bufp->fullBit(oldp+1245,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1246,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1247,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1248,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1250,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1254,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullCData(oldp+1257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+1258,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+1259,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[0]),3);
    bufp->fullCData(oldp+1260,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[1]),3);
    bufp->fullIData(oldp+1261,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1262,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1265,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1266,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullCData(oldp+1267,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+1268,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+1269,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[0]),3);
    bufp->fullCData(oldp+1270,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[1]),3);
    bufp->fullIData(oldp+1271,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1272,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1273,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1274,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1276,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1277,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1278,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1279,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1280,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1281,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+1282,(((0x1fU >= ((((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size)) 
                                             | (0U 
                                                == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size)))
                                             ? (3U 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                             : 0U) 
                                           << 3U)) ? 
                                (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << ((((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size)) 
                                       | (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size)))
                                       ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                       : 0U) << 3U))
                                 : 0U)),32);
    bufp->fullCData(oldp+1283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__wstrb),4);
    bufp->fullIData(oldp+1284,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__aligned_sram)
                                 ? (0xfffffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),32);
    bufp->fullCData(oldp+1285,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awsize),3);
    bufp->fullCData(oldp+1286,((((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size)) 
                                 | (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size)))
                                 ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : 0U)),2);
    bufp->fullBit(oldp+1287,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__aligned_sram));
    bufp->fullCData(oldp+1288,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),2);
    bufp->fullBit(oldp+1289,(((0x10000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x10000fffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__insram));
    bufp->fullBit(oldp+1291,(((0x30000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x3fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1292,(((0x10001000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x10001fffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1293,(((0x80000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x9fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1294,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__insdram));
    bufp->fullCData(oldp+1295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size),2);
    bufp->fullCData(oldp+1296,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
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
    bufp->fullCData(oldp+1297,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux),5);
    bufp->fullCData(oldp+1298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT____Vcellinp__type_mux__key),3);
    bufp->fullCData(oldp+1301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1303,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__lut_out),4);
    bufp->fullBit(oldp+1304,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+1305,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1306,(vlSelf->clock));
    bufp->fullBit(oldp+1307,(vlSelf->reset));
    bufp->fullSData(oldp+1308,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1309,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1310,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1311,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1312,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1313,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1314,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1315,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1316,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1317,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1318,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1319,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1320,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1321,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1322,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1323,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1324,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1325,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1326,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1327,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1328,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
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
    bufp->fullCData(oldp+1329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__din),4);
    bufp->fullBit(oldp+1330,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullSData(oldp+1331,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
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
    bufp->fullIData(oldp+1332,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                 << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullIData(oldp+1333,(((8U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)
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
    bufp->fullBit(oldp+1334,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1335,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullBit(oldp+1336,((1U & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                     ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                     : ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                         ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                         : 0U)))));
    bufp->fullIData(oldp+1337,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+1338,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullCData(oldp+1339,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1340,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1341,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1342,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1343,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
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
    bufp->fullBit(oldp+1344,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1345,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1346,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1347,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullIData(oldp+1348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullBit(oldp+1350,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1351,(((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1352,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state)))));
    bufp->fullBit(oldp+1353,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                     & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready)) 
                                    >> 1U))));
    bufp->fullSData(oldp+1354,((0xffffU & ((2U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                            ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                               [1U] 
                                               >> 0x10U)
                                            : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                           [1U]))),16);
    bufp->fullCData(oldp+1355,((0xffU & ((0U == (3U 
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
    bufp->fullBit(oldp+1356,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__full));
    bufp->fullBit(oldp+1357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lkeyboard__DOT__mps2__DOT__ps2_ctrl_core__DOT__empty));
    bufp->fullBit(oldp+1358,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1359,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state)) 
                              & (IData)(vlSelf->clock))));
    bufp->fullBit(oldp+1360,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1361,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1362,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1363,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullBit(oldp+1364,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
                                    | ((2U != (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state)) 
                                       | ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                          >> (7U & 
                                              ((IData)(7U) 
                                               - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))))));
    bufp->fullBit(oldp+1365,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullIData(oldp+1366,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1367,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1368,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullBit(oldp+1369,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__valclk));
    bufp->fullCData(oldp+1370,(1U),3);
    bufp->fullBit(oldp+1371,(0U));
    bufp->fullBit(oldp+1372,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1373,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1374,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullBit(oldp+1375,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullCData(oldp+1376,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1377,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullBit(oldp+1378,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1379,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1380,(0U),8);
    bufp->fullCData(oldp+1381,(1U),2);
    bufp->fullBit(oldp+1382,(1U));
    bufp->fullBit(oldp+1383,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1384,(0U),32);
    bufp->fullCData(oldp+1385,(0U),4);
    bufp->fullCData(oldp+1386,(0U),3);
    bufp->fullCData(oldp+1387,(0U),2);
    bufp->fullBit(oldp+1388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1391,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1398,(2U),32);
    bufp->fullIData(oldp+1399,(2U),32);
    bufp->fullIData(oldp+1400,(1U),32);
    bufp->fullIData(oldp+1401,(0x20U),32);
    bufp->fullIData(oldp+1402,(0U),32);
    bufp->fullIData(oldp+1403,(0x21U),32);
    bufp->fullIData(oldp+1404,(2U),32);
    bufp->fullIData(oldp+1405,(0x30000000U),32);
    bufp->fullIData(oldp+1406,(6U),32);
    bufp->fullIData(oldp+1407,(0xcU),32);
    bufp->fullIData(oldp+1408,(3U),32);
    __Vtemp_ha129e8f8__0[0U] = 0xfc467895U;
    __Vtemp_ha129e8f8__0[1U] = 0x93414684U;
    __Vtemp_ha129e8f8__0[2U] = 0xc00182U;
    bufp->fullWData(oldp+1409,(__Vtemp_ha129e8f8__0),90);
    bufp->fullIData(oldp+1412,(0xfU),32);
    bufp->fullIData(oldp+1413,(6U),32);
    bufp->fullIData(oldp+1414,(8U),32);
    bufp->fullIData(oldp+1415,(0x10U),32);
    bufp->fullIData(oldp+1416,(4U),32);
    bufp->fullIData(oldp+1417,(0x23U),32);
    bufp->fullIData(oldp+1418,(4U),32);
    bufp->fullCData(oldp+1419,(1U),4);
    bufp->fullCData(oldp+1420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword),4);
    bufp->fullSData(oldp+1421,(0x223aU),15);
    bufp->fullIData(oldp+1422,(5U),32);
    bufp->fullIData(oldp+1423,(3U),32);
    bufp->fullSData(oldp+1424,(0x4d45U),15);
    bufp->fullIData(oldp+1425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__gpio_out_num),32);
    bufp->fullBit(oldp+1426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lgpio__DOT__mgpio__DOT__gpio_urt_core__DOT__ack_q));
    bufp->fullBit(oldp+1427,(0U));
    bufp->fullBit(oldp+1428,(1U));
    bufp->fullCData(oldp+1429,(4U),3);
    bufp->fullCData(oldp+1430,(0x1bU),8);
    bufp->fullCData(oldp+1431,(0xebU),8);
    bufp->fullCData(oldp+1432,(0x38U),8);
    bufp->fullCData(oldp+1433,(0x35U),8);
    bufp->fullIData(oldp+1434,(0x64U),32);
    bufp->fullIData(oldp+1435,(0x18U),32);
    bufp->fullIData(oldp+1436,(9U),32);
    bufp->fullIData(oldp+1437,(0xdU),32);
    bufp->fullIData(oldp+1438,(0x2000U),32);
    bufp->fullIData(oldp+1439,(0x2710U),32);
    bufp->fullIData(oldp+1440,(0x30cU),32);
    bufp->fullCData(oldp+1441,(7U),4);
    bufp->fullCData(oldp+1442,(3U),4);
    bufp->fullCData(oldp+1443,(5U),4);
    bufp->fullCData(oldp+1444,(4U),4);
    bufp->fullCData(oldp+1445,(6U),4);
    bufp->fullCData(oldp+1446,(2U),4);
    bufp->fullSData(oldp+1447,(0x21U),13);
    bufp->fullCData(oldp+1448,(8U),4);
    bufp->fullCData(oldp+1449,(9U),4);
    bufp->fullIData(oldp+1450,(0xaU),32);
    bufp->fullIData(oldp+1451,(0x11U),32);
    bufp->fullIData(oldp+1452,(0x3fffffffU),32);
    bufp->fullCData(oldp+1453,(0xaU),4);
    bufp->fullIData(oldp+1454,(0xbU),32);
    bufp->fullCData(oldp+1455,(2U),3);
    bufp->fullCData(oldp+1456,(3U),3);
    bufp->fullCData(oldp+1457,(5U),3);
    bufp->fullIData(oldp+1458,(0x60U),32);
    bufp->fullIData(oldp+1459,(0x90U),32);
    bufp->fullIData(oldp+1460,(0x310U),32);
    bufp->fullIData(oldp+1461,(0x320U),32);
    bufp->fullIData(oldp+1462,(0x203U),32);
    bufp->fullIData(oldp+1463,(0x20dU),32);
    bufp->fullBit(oldp+1464,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_start));
    bufp->fullSData(oldp+1465,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_addr_q),13);
    bufp->fullBit(oldp+1466,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_val_q));
}
