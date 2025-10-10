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
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+1224,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1225,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1226,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1227,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1228,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1229,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1230,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1231,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1232,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1233,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1234,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1235,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1236,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1237,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1238,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1239,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1240,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1241,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1242,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1243,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+1224,"externalPins_gpio_out", false,-1, 15,0);
    tracep->declBus(c+1225,"externalPins_gpio_in", false,-1, 15,0);
    tracep->declBus(c+1226,"externalPins_gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1227,"externalPins_gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1228,"externalPins_gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1229,"externalPins_gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1230,"externalPins_gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1231,"externalPins_gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1232,"externalPins_gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1233,"externalPins_gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1234,"externalPins_ps2_clk", false,-1);
    tracep->declBit(c+1235,"externalPins_ps2_data", false,-1);
    tracep->declBus(c+1236,"externalPins_vga_r", false,-1, 7,0);
    tracep->declBus(c+1237,"externalPins_vga_g", false,-1, 7,0);
    tracep->declBus(c+1238,"externalPins_vga_b", false,-1, 7,0);
    tracep->declBit(c+1239,"externalPins_vga_hsync", false,-1);
    tracep->declBit(c+1240,"externalPins_vga_vsync", false,-1);
    tracep->declBit(c+1241,"externalPins_vga_valid", false,-1);
    tracep->declBit(c+1242,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+1243,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+701,"spi_sck", false,-1);
    tracep->declBus(c+702,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1244,"spi_mosi", false,-1);
    tracep->declBit(c+1245,"spi_miso", false,-1);
    tracep->declBit(c+1242,"uart_rx", false,-1);
    tracep->declBit(c+1243,"uart_tx", false,-1);
    tracep->declBit(c+194,"psram_sck", false,-1);
    tracep->declBit(c+195,"psram_ce_n", false,-1);
    tracep->declBus(c+1246,"psram_dio", false,-1, 3,0);
    tracep->declBit(c+1247,"sdram_clk", false,-1);
    tracep->declBit(c+703,"sdram_cke", false,-1);
    tracep->declBit(c+704,"sdram_cs", false,-1);
    tracep->declBit(c+705,"sdram_ras", false,-1);
    tracep->declBit(c+706,"sdram_cas", false,-1);
    tracep->declBit(c+707,"sdram_we", false,-1);
    tracep->declBus(c+708,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+709,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+710,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+1248,"sdram_dq", false,-1, 15,0);
    tracep->declBus(c+1224,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1225,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1226,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1227,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1228,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1229,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1230,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1231,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1232,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1233,"gpio_seg_7", false,-1, 7,0);
    tracep->declBit(c+1234,"ps2_clk", false,-1);
    tracep->declBit(c+1235,"ps2_data", false,-1);
    tracep->declBus(c+1236,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1237,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1238,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1239,"vga_hsync", false,-1);
    tracep->declBit(c+1240,"vga_vsync", false,-1);
    tracep->declBit(c+1241,"vga_valid", false,-1);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+124,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+125,"in_psel", false,-1);
    tracep->declBit(c+368,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+196,"in_pready", false,-1);
    tracep->declBus(c+197,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+129,"in_pslverr", false,-1);
    tracep->declBus(c+124,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+125,"out_psel", false,-1);
    tracep->declBit(c+368,"out_penable", false,-1);
    tracep->declBus(c+1284,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"out_pwrite", false,-1);
    tracep->declBus(c+127,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+196,"out_pready", false,-1);
    tracep->declBus(c+197,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+129,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+125,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+368,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+124,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1284,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+196,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+129,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+197,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+130,"auto_anon_out_6_psel", false,-1);
    tracep->declBit(c+44,"auto_anon_out_6_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_out_6_pwrite", false,-1);
    tracep->declBus(c+124,"auto_anon_out_6_paddr", false,-1, 31,0);
    tracep->declBus(c+1284,"auto_anon_out_6_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_out_6_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_out_6_pstrb", false,-1, 3,0);
    tracep->declBit(c+711,"auto_anon_out_6_pready", false,-1);
    tracep->declBit(c+1285,"auto_anon_out_6_pslverr", false,-1);
    tracep->declBus(c+712,"auto_anon_out_6_prdata", false,-1, 31,0);
    tracep->declBit(c+131,"auto_anon_out_5_psel", false,-1);
    tracep->declBit(c+45,"auto_anon_out_5_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_out_5_pwrite", false,-1);
    tracep->declBus(c+132,"auto_anon_out_5_paddr", false,-1, 29,0);
    tracep->declBus(c+1284,"auto_anon_out_5_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_out_5_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_out_5_pstrb", false,-1, 3,0);
    tracep->declBit(c+1286,"auto_anon_out_5_pready", false,-1);
    tracep->declBit(c+1287,"auto_anon_out_5_pslverr", false,-1);
    tracep->declBus(c+1288,"auto_anon_out_5_prdata", false,-1, 31,0);
    tracep->declBit(c+133,"auto_anon_out_4_psel", false,-1);
    tracep->declBit(c+46,"auto_anon_out_4_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_out_4_pwrite", false,-1);
    tracep->declBus(c+134,"auto_anon_out_4_paddr", false,-1, 28,0);
    tracep->declBus(c+1284,"auto_anon_out_4_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_out_4_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_out_4_pstrb", false,-1, 3,0);
    tracep->declBit(c+1289,"auto_anon_out_4_pready", false,-1);
    tracep->declBit(c+1290,"auto_anon_out_4_pslverr", false,-1);
    tracep->declBus(c+1291,"auto_anon_out_4_prdata", false,-1, 31,0);
    tracep->declBit(c+135,"auto_anon_out_3_psel", false,-1);
    tracep->declBit(c+47,"auto_anon_out_3_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_out_3_pwrite", false,-1);
    tracep->declBus(c+134,"auto_anon_out_3_paddr", false,-1, 28,0);
    tracep->declBus(c+1284,"auto_anon_out_3_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_out_3_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_out_3_pstrb", false,-1, 3,0);
    tracep->declBit(c+1292,"auto_anon_out_3_pready", false,-1);
    tracep->declBit(c+1293,"auto_anon_out_3_pslverr", false,-1);
    tracep->declBus(c+1294,"auto_anon_out_3_prdata", false,-1, 31,0);
    tracep->declBit(c+136,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+48,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+124,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+1284,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+1249,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+1285,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+369,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+137,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+138,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+134,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+1284,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+139,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+1285,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+1250,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+140,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+49,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+126,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+132,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+1284,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+1251,"auto_anon_out_0_pready", false,-1);
    tracep->declBit(c+1285,"auto_anon_out_0_pslverr", false,-1);
    tracep->declBus(c+1252,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+141,"sel_0", false,-1);
    tracep->declBit(c+142,"sel_1", false,-1);
    tracep->declBit(c+143,"sel_2", false,-1);
    tracep->declBit(c+144,"sel_3", false,-1);
    tracep->declBit(c+145,"sel_4", false,-1);
    tracep->declBit(c+146,"sel_5", false,-1);
    tracep->declBit(c+147,"sel_6", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+148,"auto_in_awready", false,-1);
    tracep->declBit(c+149,"auto_in_awvalid", false,-1);
    tracep->declBus(c+370,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1135,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+148,"auto_in_wready", false,-1);
    tracep->declBit(c+150,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+198,"auto_in_bready", false,-1);
    tracep->declBit(c+199,"auto_in_bvalid", false,-1);
    tracep->declBus(c+371,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+50,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+151,"auto_in_arready", false,-1);
    tracep->declBit(c+152,"auto_in_arvalid", false,-1);
    tracep->declBus(c+372,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1139,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+200,"auto_in_rready", false,-1);
    tracep->declBit(c+201,"auto_in_rvalid", false,-1);
    tracep->declBus(c+373,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+202,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+50,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+125,"auto_out_psel", false,-1);
    tracep->declBit(c+368,"auto_out_penable", false,-1);
    tracep->declBit(c+126,"auto_out_pwrite", false,-1);
    tracep->declBus(c+124,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+127,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+196,"auto_out_pready", false,-1);
    tracep->declBit(c+129,"auto_out_pslverr", false,-1);
    tracep->declBus(c+197,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+368,"nodeOut_penable", false,-1);
    tracep->declBus(c+374,"state", false,-1, 1,0);
    tracep->declBit(c+151,"accept_read", false,-1);
    tracep->declBit(c+148,"accept_write", false,-1);
    tracep->declBit(c+375,"is_write_r", false,-1);
    tracep->declBit(c+126,"is_write", false,-1);
    tracep->declBus(c+373,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+371,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+376,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+377,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+378,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+379,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+153,"resp", false,-1, 1,0);
    tracep->declBus(c+380,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+50,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+201,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+381,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+199,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4frag ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+382,"auto_in_awready", false,-1);
    tracep->declBit(c+88,"auto_in_awvalid", false,-1);
    tracep->declBus(c+1295,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1140,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1296,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1141,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1142,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+383,"auto_in_wready", false,-1);
    tracep->declBit(c+89,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1143,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1144,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1297,"auto_in_wlast", false,-1);
    tracep->declBit(c+1253,"auto_in_bready", false,-1);
    tracep->declBit(c+203,"auto_in_bvalid", false,-1);
    tracep->declBus(c+204,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+205,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+384,"auto_in_arready", false,-1);
    tracep->declBit(c+90,"auto_in_arvalid", false,-1);
    tracep->declBus(c+1298,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1145,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1299,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1043,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1300,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+91,"auto_in_rready", false,-1);
    tracep->declBit(c+206,"auto_in_rvalid", false,-1);
    tracep->declBus(c+207,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+52,"auto_in_rlast", false,-1);
    tracep->declBit(c+208,"auto_out_awready", false,-1);
    tracep->declBit(c+92,"auto_out_awvalid", false,-1);
    tracep->declBus(c+370,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1135,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+385,"auto_out_awecho_real_last", false,-1);
    tracep->declBit(c+209,"auto_out_wready", false,-1);
    tracep->declBit(c+93,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+94,"auto_out_wlast", false,-1);
    tracep->declBit(c+210,"auto_out_bready", false,-1);
    tracep->declBit(c+211,"auto_out_bvalid", false,-1);
    tracep->declBus(c+204,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+212,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+213,"auto_out_becho_real_last", false,-1);
    tracep->declBit(c+214,"auto_out_arready", false,-1);
    tracep->declBit(c+95,"auto_out_arvalid", false,-1);
    tracep->declBus(c+372,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1139,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+386,"auto_out_arecho_real_last", false,-1);
    tracep->declBit(c+91,"auto_out_rready", false,-1);
    tracep->declBit(c+206,"auto_out_rvalid", false,-1);
    tracep->declBus(c+207,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+53,"auto_out_recho_real_last", false,-1);
    tracep->declBit(c+215,"auto_out_rlast", false,-1);
    tracep->declBit(c+93,"nodeOut_wvalid", false,-1);
    tracep->declBit(c+387,"w_idle", false,-1);
    tracep->declBit(c+216,"in_awready", false,-1);
    tracep->declBit(c+388,"busy", false,-1);
    tracep->declBus(c+389,"r_addr", false,-1, 31,0);
    tracep->declBus(c+390,"r_len", false,-1, 7,0);
    tracep->declBus(c+391,"len", false,-1, 7,0);
    tracep->declBus(c+1146,"addr", false,-1, 31,0);
    tracep->declBit(c+392,"busy_1", false,-1);
    tracep->declBus(c+393,"r_addr_1", false,-1, 31,0);
    tracep->declBus(c+394,"r_len_1", false,-1, 7,0);
    tracep->declBus(c+395,"len_1", false,-1, 7,0);
    tracep->declBus(c+1147,"addr_1", false,-1, 31,0);
    tracep->declBit(c+396,"wbeats_latched", false,-1);
    tracep->declBit(c+92,"nodeOut_awvalid", false,-1);
    tracep->declBit(c+96,"wbeats_valid", false,-1);
    tracep->declBus(c+397,"w_counter", false,-1, 8,0);
    tracep->declBus(c+97,"w_todo", false,-1, 8,0);
    tracep->declBit(c+94,"w_last", false,-1);
    tracep->declBit(c+210,"nodeOut_bready", false,-1);
    tracep->declBus(c+398,"error_0", false,-1, 1,0);
    tracep->declBus(c+399,"error_1", false,-1, 1,0);
    tracep->declBus(c+400,"error_2", false,-1, 1,0);
    tracep->declBus(c+401,"error_3", false,-1, 1,0);
    tracep->declBus(c+402,"error_4", false,-1, 1,0);
    tracep->declBus(c+403,"error_5", false,-1, 1,0);
    tracep->declBus(c+404,"error_6", false,-1, 1,0);
    tracep->declBus(c+405,"error_7", false,-1, 1,0);
    tracep->declBus(c+406,"error_8", false,-1, 1,0);
    tracep->declBus(c+407,"error_9", false,-1, 1,0);
    tracep->declBus(c+408,"error_10", false,-1, 1,0);
    tracep->declBus(c+409,"error_11", false,-1, 1,0);
    tracep->declBus(c+410,"error_12", false,-1, 1,0);
    tracep->declBus(c+411,"error_13", false,-1, 1,0);
    tracep->declBus(c+412,"error_14", false,-1, 1,0);
    tracep->declBus(c+413,"error_15", false,-1, 1,0);
    tracep->pushNamePrefix("deq_q ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+384,"io_enq_ready", false,-1);
    tracep->declBit(c+90,"io_enq_valid", false,-1);
    tracep->declBus(c+1298,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1145,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1299,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1043,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1300,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+217,"io_deq_ready", false,-1);
    tracep->declBit(c+95,"io_deq_valid", false,-1);
    tracep->declBus(c+372,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1148,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+414,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1042,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+415,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+416,"ram", false,-1, 48,0);
    tracep->declBit(c+418,"full", false,-1);
    tracep->declBit(c+95,"io_deq_valid_0", false,-1);
    tracep->declBit(c+218,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("deq_q_1 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+382,"io_enq_ready", false,-1);
    tracep->declBit(c+88,"io_enq_valid", false,-1);
    tracep->declBus(c+1295,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1140,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+1296,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1141,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1142,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+219,"io_deq_ready", false,-1);
    tracep->declBit(c+98,"io_deq_valid", false,-1);
    tracep->declBus(c+370,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+1149,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+419,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+1136,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBus(c+1150,"io_deq_bits_burst", false,-1, 1,0);
    tracep->declQuad(c+420,"ram", false,-1, 48,0);
    tracep->declBit(c+422,"full", false,-1);
    tracep->declBit(c+98,"io_deq_valid_0", false,-1);
    tracep->declBit(c+220,"do_enq", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("in_wdeq_q ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+383,"io_enq_ready", false,-1);
    tracep->declBit(c+89,"io_enq_valid", false,-1);
    tracep->declBus(c+1143,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1144,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+1297,"io_enq_bits_last", false,-1);
    tracep->declBit(c+221,"io_deq_ready", false,-1);
    tracep->declBit(c+99,"io_deq_valid", false,-1);
    tracep->declBus(c+1137,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+1138,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+423,"io_deq_bits_last", false,-1);
    tracep->declQuad(c+424,"ram", false,-1, 36,0);
    tracep->declBit(c+426,"full", false,-1);
    tracep->declBit(c+99,"io_deq_valid_0", false,-1);
    tracep->declBit(c+222,"do_enq", false,-1);
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
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+223,"auto_in_awready", false,-1);
    tracep->declBit(c+154,"auto_in_awvalid", false,-1);
    tracep->declBus(c+370,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1151,"auto_in_awaddr", false,-1, 27,0);
    tracep->declBit(c+1255,"auto_in_wready", false,-1);
    tracep->declBit(c+1256,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+224,"auto_in_bready", false,-1);
    tracep->declBit(c+427,"auto_in_bvalid", false,-1);
    tracep->declBus(c+428,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+429,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+225,"auto_in_arready", false,-1);
    tracep->declBit(c+1257,"auto_in_arvalid", false,-1);
    tracep->declBus(c+372,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1152,"auto_in_araddr", false,-1, 27,0);
    tracep->declBit(c+226,"auto_in_rready", false,-1);
    tracep->declBit(c+430,"auto_in_rvalid", false,-1);
    tracep->declBus(c+431,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+432,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+433,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+225,"nodeIn_arready", false,-1);
    tracep->declBit(c+223,"nodeIn_awready", false,-1);
    tracep->declBit(c+1153,"w_sel0", false,-1);
    tracep->declBit(c+427,"w_full", false,-1);
    tracep->declBus(c+428,"w_id", false,-1, 3,0);
    tracep->declBit(c+434,"r_sel1", false,-1);
    tracep->declBit(c+435,"w_sel1", false,-1);
    tracep->declBit(c+430,"r_full", false,-1);
    tracep->declBus(c+431,"r_id", false,-1, 3,0);
    tracep->declBit(c+227,"ren", false,-1);
    tracep->declBit(c+436,"rdata_REG", false,-1);
    tracep->declBus(c+437,"rdata_r0", false,-1, 7,0);
    tracep->declBus(c+438,"rdata_r1", false,-1, 7,0);
    tracep->declBus(c+439,"rdata_r2", false,-1, 7,0);
    tracep->declBus(c+440,"rdata_r3", false,-1, 7,0);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+1154,"R0_addr", false,-1, 10,0);
    tracep->declBit(c+227,"R0_en", false,-1);
    tracep->declBit(c+1222,"R0_clk", false,-1);
    tracep->declBus(c+441,"R0_data", false,-1, 31,0);
    tracep->declBus(c+1155,"W0_addr", false,-1, 10,0);
    tracep->declBit(c+228,"W0_en", false,-1);
    tracep->declBit(c+1222,"W0_clk", false,-1);
    tracep->declBus(c+1137,"W0_data", false,-1, 31,0);
    tracep->declBus(c+1138,"W0_mask", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+382,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+88,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+1295,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1140,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1296,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+1141,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+1142,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+383,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+89,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1143,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1144,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+1297,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+1253,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+203,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+204,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+205,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+384,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+90,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+1298,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1145,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1299,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+1043,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+1300,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+91,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+206,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+207,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+52,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+382,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+88,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+1295,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+1140,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1296,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1141,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1142,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+383,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+89,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+1143,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1144,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1297,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+1253,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+203,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+204,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+205,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+384,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+90,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+1298,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+1145,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1299,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1043,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1300,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+91,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+206,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+207,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+52,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi4xbar_1 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+229,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+100,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+370,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+1135,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBit(c+209,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+93,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+94,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+210,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+211,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+204,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+212,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+230,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+101,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+372,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+1139,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBit(c+91,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+206,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+207,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+215,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+223,"auto_anon_out_2_awready", false,-1);
    tracep->declBit(c+154,"auto_anon_out_2_awvalid", false,-1);
    tracep->declBus(c+370,"auto_anon_out_2_awid", false,-1, 3,0);
    tracep->declBus(c+1151,"auto_anon_out_2_awaddr", false,-1, 27,0);
    tracep->declBit(c+1255,"auto_anon_out_2_wready", false,-1);
    tracep->declBit(c+1256,"auto_anon_out_2_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_anon_out_2_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_anon_out_2_wstrb", false,-1, 3,0);
    tracep->declBit(c+224,"auto_anon_out_2_bready", false,-1);
    tracep->declBit(c+427,"auto_anon_out_2_bvalid", false,-1);
    tracep->declBus(c+428,"auto_anon_out_2_bid", false,-1, 3,0);
    tracep->declBus(c+429,"auto_anon_out_2_bresp", false,-1, 1,0);
    tracep->declBit(c+225,"auto_anon_out_2_arready", false,-1);
    tracep->declBit(c+1257,"auto_anon_out_2_arvalid", false,-1);
    tracep->declBus(c+372,"auto_anon_out_2_arid", false,-1, 3,0);
    tracep->declBus(c+1152,"auto_anon_out_2_araddr", false,-1, 27,0);
    tracep->declBit(c+226,"auto_anon_out_2_rready", false,-1);
    tracep->declBit(c+430,"auto_anon_out_2_rvalid", false,-1);
    tracep->declBus(c+431,"auto_anon_out_2_rid", false,-1, 3,0);
    tracep->declBus(c+432,"auto_anon_out_2_rdata", false,-1, 31,0);
    tracep->declBus(c+433,"auto_anon_out_2_rresp", false,-1, 1,0);
    tracep->declBit(c+1258,"auto_anon_out_1_awvalid", false,-1);
    tracep->declBit(c+1259,"auto_anon_out_1_wvalid", false,-1);
    tracep->declBit(c+442,"auto_anon_out_1_arready", false,-1);
    tracep->declBit(c+1260,"auto_anon_out_1_arvalid", false,-1);
    tracep->declBus(c+372,"auto_anon_out_1_arid", false,-1, 3,0);
    tracep->declBus(c+1156,"auto_anon_out_1_araddr", false,-1, 29,0);
    tracep->declBit(c+1261,"auto_anon_out_1_rready", false,-1);
    tracep->declBit(c+443,"auto_anon_out_1_rvalid", false,-1);
    tracep->declBus(c+444,"auto_anon_out_1_rid", false,-1, 3,0);
    tracep->declBus(c+445,"auto_anon_out_1_rdata", false,-1, 31,0);
    tracep->declBit(c+148,"auto_anon_out_0_awready", false,-1);
    tracep->declBit(c+149,"auto_anon_out_0_awvalid", false,-1);
    tracep->declBus(c+370,"auto_anon_out_0_awid", false,-1, 3,0);
    tracep->declBus(c+1135,"auto_anon_out_0_awaddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_anon_out_0_awsize", false,-1, 2,0);
    tracep->declBit(c+148,"auto_anon_out_0_wready", false,-1);
    tracep->declBit(c+150,"auto_anon_out_0_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_anon_out_0_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_anon_out_0_wstrb", false,-1, 3,0);
    tracep->declBit(c+198,"auto_anon_out_0_bready", false,-1);
    tracep->declBit(c+199,"auto_anon_out_0_bvalid", false,-1);
    tracep->declBus(c+371,"auto_anon_out_0_bid", false,-1, 3,0);
    tracep->declBus(c+50,"auto_anon_out_0_bresp", false,-1, 1,0);
    tracep->declBit(c+151,"auto_anon_out_0_arready", false,-1);
    tracep->declBit(c+152,"auto_anon_out_0_arvalid", false,-1);
    tracep->declBus(c+372,"auto_anon_out_0_arid", false,-1, 3,0);
    tracep->declBus(c+1139,"auto_anon_out_0_araddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_anon_out_0_arsize", false,-1, 2,0);
    tracep->declBit(c+200,"auto_anon_out_0_rready", false,-1);
    tracep->declBit(c+201,"auto_anon_out_0_rvalid", false,-1);
    tracep->declBus(c+373,"auto_anon_out_0_rid", false,-1, 3,0);
    tracep->declBus(c+202,"auto_anon_out_0_rdata", false,-1, 31,0);
    tracep->declBus(c+50,"auto_anon_out_0_rresp", false,-1, 1,0);
    tracep->declBit(c+211,"in_0_bvalid", false,-1);
    tracep->declBit(c+206,"in_0_rvalid", false,-1);
    tracep->declBit(c+231,"in_0_wready", false,-1);
    tracep->declBit(c+232,"in_0_awready", false,-1);
    tracep->declBit(c+230,"in_0_arready", false,-1);
    tracep->declBit(c+229,"anonIn_awready", false,-1);
    tracep->declBit(c+1157,"requestARIO_0_0", false,-1);
    tracep->declBit(c+1158,"requestARIO_0_1", false,-1);
    tracep->declBit(c+1159,"requestARIO_0_2", false,-1);
    tracep->declBit(c+1160,"requestAWIO_0_0", false,-1);
    tracep->declBit(c+1161,"requestAWIO_0_1", false,-1);
    tracep->declBit(c+1162,"requestAWIO_0_2", false,-1);
    tracep->declBit(c+446,"arFIFOMap_0_count", false,-1);
    tracep->declBit(c+447,"awFIFOMap_0_count", false,-1);
    tracep->declBit(c+448,"arFIFOMap_1_count", false,-1);
    tracep->declBit(c+449,"awFIFOMap_1_count", false,-1);
    tracep->declBit(c+450,"arFIFOMap_2_count", false,-1);
    tracep->declBit(c+451,"awFIFOMap_2_count", false,-1);
    tracep->declBit(c+452,"arFIFOMap_3_count", false,-1);
    tracep->declBit(c+453,"awFIFOMap_3_count", false,-1);
    tracep->declBit(c+454,"arFIFOMap_4_count", false,-1);
    tracep->declBit(c+455,"awFIFOMap_4_count", false,-1);
    tracep->declBit(c+456,"arFIFOMap_5_count", false,-1);
    tracep->declBit(c+457,"awFIFOMap_5_count", false,-1);
    tracep->declBit(c+458,"arFIFOMap_6_count", false,-1);
    tracep->declBit(c+459,"awFIFOMap_6_count", false,-1);
    tracep->declBit(c+460,"arFIFOMap_7_count", false,-1);
    tracep->declBit(c+461,"awFIFOMap_7_count", false,-1);
    tracep->declBit(c+462,"arFIFOMap_8_count", false,-1);
    tracep->declBit(c+463,"awFIFOMap_8_count", false,-1);
    tracep->declBit(c+464,"arFIFOMap_9_count", false,-1);
    tracep->declBit(c+465,"awFIFOMap_9_count", false,-1);
    tracep->declBit(c+466,"arFIFOMap_10_count", false,-1);
    tracep->declBit(c+467,"awFIFOMap_10_count", false,-1);
    tracep->declBit(c+468,"arFIFOMap_11_count", false,-1);
    tracep->declBit(c+469,"awFIFOMap_11_count", false,-1);
    tracep->declBit(c+470,"arFIFOMap_12_count", false,-1);
    tracep->declBit(c+471,"awFIFOMap_12_count", false,-1);
    tracep->declBit(c+472,"arFIFOMap_13_count", false,-1);
    tracep->declBit(c+473,"awFIFOMap_13_count", false,-1);
    tracep->declBit(c+474,"arFIFOMap_14_count", false,-1);
    tracep->declBit(c+475,"awFIFOMap_14_count", false,-1);
    tracep->declBit(c+476,"arFIFOMap_15_count", false,-1);
    tracep->declBit(c+477,"awFIFOMap_15_count", false,-1);
    tracep->declBit(c+478,"latched", false,-1);
    tracep->declBit(c+102,"in_0_awvalid", false,-1);
    tracep->declBit(c+103,"awIn_0_io_enq_valid", false,-1);
    tracep->declBit(c+104,"in_0_wvalid", false,-1);
    tracep->declBit(c+479,"idle_3", false,-1);
    tracep->declBit(c+233,"anyValid", false,-1);
    tracep->declBus(c+234,"readys_valid", false,-1, 2,0);
    tracep->declBus(c+480,"readys_mask", false,-1, 2,0);
    tracep->declBus(c+235,"readys_readys", false,-1, 2,0);
    tracep->declBit(c+236,"prefixOR_1", false,-1);
    tracep->declBit(c+237,"winner_3_1", false,-1);
    tracep->declBit(c+238,"winner_3_2", false,-1);
    tracep->declBit(c+481,"state_3_0", false,-1);
    tracep->declBit(c+482,"state_3_1", false,-1);
    tracep->declBit(c+483,"state_3_2", false,-1);
    tracep->declBit(c+239,"muxState_3_0", false,-1);
    tracep->declBit(c+240,"muxState_3_1", false,-1);
    tracep->declBit(c+241,"muxState_3_2", false,-1);
    tracep->declBit(c+484,"idle_4", false,-1);
    tracep->declBit(c+242,"anyValid_1", false,-1);
    tracep->declBus(c+243,"readys_valid_1", false,-1, 2,0);
    tracep->declBus(c+485,"readys_mask_1", false,-1, 2,0);
    tracep->declBus(c+244,"readys_readys_1", false,-1, 2,0);
    tracep->declBit(c+245,"winner_4_0", false,-1);
    tracep->declBit(c+246,"winner_4_2", false,-1);
    tracep->declBit(c+486,"state_4_0", false,-1);
    tracep->declBit(c+487,"state_4_2", false,-1);
    tracep->declBit(c+247,"muxState_4_0", false,-1);
    tracep->declBit(c+248,"muxState_4_2", false,-1);
    tracep->pushNamePrefix("awIn_0 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+488,"io_enq_ready", false,-1);
    tracep->declBit(c+103,"io_enq_valid", false,-1);
    tracep->declBus(c+1163,"io_enq_bits", false,-1, 2,0);
    tracep->declBit(c+249,"io_deq_ready", false,-1);
    tracep->declBit(c+105,"io_deq_valid", false,-1);
    tracep->declBus(c+1164,"io_deq_bits", false,-1, 2,0);
    tracep->declBit(c+489,"wrap", false,-1);
    tracep->declBit(c+490,"wrap_1", false,-1);
    tracep->declBit(c+491,"maybe_full", false,-1);
    tracep->declBit(c+492,"ptr_match", false,-1);
    tracep->declBit(c+493,"empty", false,-1);
    tracep->declBit(c+494,"full", false,-1);
    tracep->declBit(c+105,"io_deq_valid_0", false,-1);
    tracep->declBit(c+250,"do_deq", false,-1);
    tracep->declBit(c+251,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+490,"R0_addr", false,-1);
    tracep->declBit(c+1301,"R0_en", false,-1);
    tracep->declBit(c+1222,"R0_clk", false,-1);
    tracep->declBus(c+495,"R0_data", false,-1, 2,0);
    tracep->declBit(c+489,"W0_addr", false,-1);
    tracep->declBit(c+251,"W0_en", false,-1);
    tracep->declBit(c+1222,"W0_clk", false,-1);
    tracep->declBus(c+1163,"W0_data", false,-1, 2,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+496+i*1,"Memory", true,(i+0), 2,0);
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
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+208,"auto_in_awready", false,-1);
    tracep->declBit(c+92,"auto_in_awvalid", false,-1);
    tracep->declBus(c+370,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+1135,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+385,"auto_in_awecho_real_last", false,-1);
    tracep->declBit(c+209,"auto_in_wready", false,-1);
    tracep->declBit(c+93,"auto_in_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+94,"auto_in_wlast", false,-1);
    tracep->declBit(c+210,"auto_in_bready", false,-1);
    tracep->declBit(c+211,"auto_in_bvalid", false,-1);
    tracep->declBus(c+204,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+212,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+213,"auto_in_becho_real_last", false,-1);
    tracep->declBit(c+214,"auto_in_arready", false,-1);
    tracep->declBit(c+95,"auto_in_arvalid", false,-1);
    tracep->declBus(c+372,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1139,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+386,"auto_in_arecho_real_last", false,-1);
    tracep->declBit(c+91,"auto_in_rready", false,-1);
    tracep->declBit(c+206,"auto_in_rvalid", false,-1);
    tracep->declBus(c+207,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+53,"auto_in_recho_real_last", false,-1);
    tracep->declBit(c+215,"auto_in_rlast", false,-1);
    tracep->declBit(c+229,"auto_out_awready", false,-1);
    tracep->declBit(c+100,"auto_out_awvalid", false,-1);
    tracep->declBus(c+370,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+1135,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1136,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+209,"auto_out_wready", false,-1);
    tracep->declBit(c+93,"auto_out_wvalid", false,-1);
    tracep->declBus(c+1137,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1138,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+94,"auto_out_wlast", false,-1);
    tracep->declBit(c+210,"auto_out_bready", false,-1);
    tracep->declBit(c+211,"auto_out_bvalid", false,-1);
    tracep->declBus(c+204,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+212,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+230,"auto_out_arready", false,-1);
    tracep->declBit(c+101,"auto_out_arvalid", false,-1);
    tracep->declBus(c+372,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+1139,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1042,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+91,"auto_out_rready", false,-1);
    tracep->declBit(c+206,"auto_out_rvalid", false,-1);
    tracep->declBus(c+207,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_out_rresp", false,-1, 1,0);
    tracep->declBit(c+215,"auto_out_rlast", false,-1);
    tracep->pushNamePrefix("Queue1_BundleMap ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+498,"io_enq_ready", false,-1);
    tracep->declBit(c+54,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+252,"io_deq_ready", false,-1);
    tracep->declBit(c+499,"io_deq_valid", false,-1);
    tracep->declBit(c+500,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+500,"ram_real_last", false,-1);
    tracep->declBit(c+499,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+501,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_1 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+502,"io_enq_ready", false,-1);
    tracep->declBit(c+55,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+253,"io_deq_ready", false,-1);
    tracep->declBit(c+503,"io_deq_valid", false,-1);
    tracep->declBit(c+504,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+504,"ram_real_last", false,-1);
    tracep->declBit(c+503,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+505,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_10 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+506,"io_enq_ready", false,-1);
    tracep->declBit(c+56,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+254,"io_deq_ready", false,-1);
    tracep->declBit(c+507,"io_deq_valid", false,-1);
    tracep->declBit(c+508,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+508,"ram_real_last", false,-1);
    tracep->declBit(c+507,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+509,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_11 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+510,"io_enq_ready", false,-1);
    tracep->declBit(c+57,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+255,"io_deq_ready", false,-1);
    tracep->declBit(c+511,"io_deq_valid", false,-1);
    tracep->declBit(c+512,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+512,"ram_real_last", false,-1);
    tracep->declBit(c+511,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+513,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_12 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+514,"io_enq_ready", false,-1);
    tracep->declBit(c+58,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+256,"io_deq_ready", false,-1);
    tracep->declBit(c+515,"io_deq_valid", false,-1);
    tracep->declBit(c+516,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+516,"ram_real_last", false,-1);
    tracep->declBit(c+515,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+517,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_13 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+518,"io_enq_ready", false,-1);
    tracep->declBit(c+59,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+257,"io_deq_ready", false,-1);
    tracep->declBit(c+519,"io_deq_valid", false,-1);
    tracep->declBit(c+520,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+520,"ram_real_last", false,-1);
    tracep->declBit(c+519,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+521,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_14 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+522,"io_enq_ready", false,-1);
    tracep->declBit(c+60,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+258,"io_deq_ready", false,-1);
    tracep->declBit(c+523,"io_deq_valid", false,-1);
    tracep->declBit(c+524,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+524,"ram_real_last", false,-1);
    tracep->declBit(c+523,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+525,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_15 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+526,"io_enq_ready", false,-1);
    tracep->declBit(c+61,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+259,"io_deq_ready", false,-1);
    tracep->declBit(c+527,"io_deq_valid", false,-1);
    tracep->declBit(c+528,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+528,"ram_real_last", false,-1);
    tracep->declBit(c+527,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+529,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_16 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+530,"io_enq_ready", false,-1);
    tracep->declBit(c+62,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+260,"io_deq_ready", false,-1);
    tracep->declBit(c+531,"io_deq_valid", false,-1);
    tracep->declBit(c+532,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+532,"ram_real_last", false,-1);
    tracep->declBit(c+531,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+533,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_17 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+534,"io_enq_ready", false,-1);
    tracep->declBit(c+63,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+261,"io_deq_ready", false,-1);
    tracep->declBit(c+535,"io_deq_valid", false,-1);
    tracep->declBit(c+536,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+536,"ram_real_last", false,-1);
    tracep->declBit(c+535,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+537,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_18 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+538,"io_enq_ready", false,-1);
    tracep->declBit(c+64,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+262,"io_deq_ready", false,-1);
    tracep->declBit(c+539,"io_deq_valid", false,-1);
    tracep->declBit(c+540,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+540,"ram_real_last", false,-1);
    tracep->declBit(c+539,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+541,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_19 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+542,"io_enq_ready", false,-1);
    tracep->declBit(c+65,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+263,"io_deq_ready", false,-1);
    tracep->declBit(c+543,"io_deq_valid", false,-1);
    tracep->declBit(c+544,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+544,"ram_real_last", false,-1);
    tracep->declBit(c+543,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+545,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_2 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+546,"io_enq_ready", false,-1);
    tracep->declBit(c+66,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+264,"io_deq_ready", false,-1);
    tracep->declBit(c+547,"io_deq_valid", false,-1);
    tracep->declBit(c+548,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+548,"ram_real_last", false,-1);
    tracep->declBit(c+547,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+549,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_20 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+550,"io_enq_ready", false,-1);
    tracep->declBit(c+67,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+265,"io_deq_ready", false,-1);
    tracep->declBit(c+551,"io_deq_valid", false,-1);
    tracep->declBit(c+552,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+552,"ram_real_last", false,-1);
    tracep->declBit(c+551,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+553,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_21 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+554,"io_enq_ready", false,-1);
    tracep->declBit(c+68,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+266,"io_deq_ready", false,-1);
    tracep->declBit(c+555,"io_deq_valid", false,-1);
    tracep->declBit(c+556,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+556,"ram_real_last", false,-1);
    tracep->declBit(c+555,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+557,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_22 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+558,"io_enq_ready", false,-1);
    tracep->declBit(c+69,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+267,"io_deq_ready", false,-1);
    tracep->declBit(c+559,"io_deq_valid", false,-1);
    tracep->declBit(c+560,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+560,"ram_real_last", false,-1);
    tracep->declBit(c+559,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+561,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_23 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+562,"io_enq_ready", false,-1);
    tracep->declBit(c+70,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+268,"io_deq_ready", false,-1);
    tracep->declBit(c+563,"io_deq_valid", false,-1);
    tracep->declBit(c+564,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+564,"ram_real_last", false,-1);
    tracep->declBit(c+563,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+565,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_24 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+566,"io_enq_ready", false,-1);
    tracep->declBit(c+71,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+269,"io_deq_ready", false,-1);
    tracep->declBit(c+567,"io_deq_valid", false,-1);
    tracep->declBit(c+568,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+568,"ram_real_last", false,-1);
    tracep->declBit(c+567,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+569,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_25 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+570,"io_enq_ready", false,-1);
    tracep->declBit(c+72,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+270,"io_deq_ready", false,-1);
    tracep->declBit(c+571,"io_deq_valid", false,-1);
    tracep->declBit(c+572,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+572,"ram_real_last", false,-1);
    tracep->declBit(c+571,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+573,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_26 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+574,"io_enq_ready", false,-1);
    tracep->declBit(c+73,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+271,"io_deq_ready", false,-1);
    tracep->declBit(c+575,"io_deq_valid", false,-1);
    tracep->declBit(c+576,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+576,"ram_real_last", false,-1);
    tracep->declBit(c+575,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+577,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_27 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+578,"io_enq_ready", false,-1);
    tracep->declBit(c+74,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+272,"io_deq_ready", false,-1);
    tracep->declBit(c+579,"io_deq_valid", false,-1);
    tracep->declBit(c+580,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+580,"ram_real_last", false,-1);
    tracep->declBit(c+579,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+581,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_28 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+582,"io_enq_ready", false,-1);
    tracep->declBit(c+75,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+273,"io_deq_ready", false,-1);
    tracep->declBit(c+583,"io_deq_valid", false,-1);
    tracep->declBit(c+584,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+584,"ram_real_last", false,-1);
    tracep->declBit(c+583,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+585,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_29 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+586,"io_enq_ready", false,-1);
    tracep->declBit(c+76,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+274,"io_deq_ready", false,-1);
    tracep->declBit(c+587,"io_deq_valid", false,-1);
    tracep->declBit(c+588,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+588,"ram_real_last", false,-1);
    tracep->declBit(c+587,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+589,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_3 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+590,"io_enq_ready", false,-1);
    tracep->declBit(c+77,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+275,"io_deq_ready", false,-1);
    tracep->declBit(c+591,"io_deq_valid", false,-1);
    tracep->declBit(c+592,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+592,"ram_real_last", false,-1);
    tracep->declBit(c+591,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+593,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_30 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+594,"io_enq_ready", false,-1);
    tracep->declBit(c+78,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+276,"io_deq_ready", false,-1);
    tracep->declBit(c+595,"io_deq_valid", false,-1);
    tracep->declBit(c+596,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+596,"ram_real_last", false,-1);
    tracep->declBit(c+595,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+597,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_31 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+598,"io_enq_ready", false,-1);
    tracep->declBit(c+79,"io_enq_valid", false,-1);
    tracep->declBit(c+385,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+277,"io_deq_ready", false,-1);
    tracep->declBit(c+599,"io_deq_valid", false,-1);
    tracep->declBit(c+600,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+600,"ram_real_last", false,-1);
    tracep->declBit(c+599,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+601,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_4 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+602,"io_enq_ready", false,-1);
    tracep->declBit(c+80,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+278,"io_deq_ready", false,-1);
    tracep->declBit(c+603,"io_deq_valid", false,-1);
    tracep->declBit(c+604,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+604,"ram_real_last", false,-1);
    tracep->declBit(c+603,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+605,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_5 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+606,"io_enq_ready", false,-1);
    tracep->declBit(c+81,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+279,"io_deq_ready", false,-1);
    tracep->declBit(c+607,"io_deq_valid", false,-1);
    tracep->declBit(c+608,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+608,"ram_real_last", false,-1);
    tracep->declBit(c+607,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+609,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_6 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+610,"io_enq_ready", false,-1);
    tracep->declBit(c+82,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+280,"io_deq_ready", false,-1);
    tracep->declBit(c+611,"io_deq_valid", false,-1);
    tracep->declBit(c+612,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+612,"ram_real_last", false,-1);
    tracep->declBit(c+611,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+613,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_7 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+614,"io_enq_ready", false,-1);
    tracep->declBit(c+83,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+281,"io_deq_ready", false,-1);
    tracep->declBit(c+615,"io_deq_valid", false,-1);
    tracep->declBit(c+616,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+616,"ram_real_last", false,-1);
    tracep->declBit(c+615,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+617,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_8 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+618,"io_enq_ready", false,-1);
    tracep->declBit(c+84,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+282,"io_deq_ready", false,-1);
    tracep->declBit(c+619,"io_deq_valid", false,-1);
    tracep->declBit(c+620,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+620,"ram_real_last", false,-1);
    tracep->declBit(c+619,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+621,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Queue1_BundleMap_9 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+622,"io_enq_ready", false,-1);
    tracep->declBit(c+85,"io_enq_valid", false,-1);
    tracep->declBit(c+386,"io_enq_bits_real_last", false,-1);
    tracep->declBit(c+283,"io_deq_ready", false,-1);
    tracep->declBit(c+623,"io_deq_valid", false,-1);
    tracep->declBit(c+624,"io_deq_bits_real_last", false,-1);
    tracep->declBit(c+624,"ram_real_last", false,-1);
    tracep->declBit(c+623,"full", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+625,"do_enq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+106,"reset", false,-1);
    tracep->declBit(c+382,"auto_master_out_awready", false,-1);
    tracep->declBit(c+88,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+1295,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+1140,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+1296,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+1141,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+1142,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+383,"auto_master_out_wready", false,-1);
    tracep->declBit(c+89,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+1143,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+1144,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+1297,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+1253,"auto_master_out_bready", false,-1);
    tracep->declBit(c+203,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+204,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+205,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+384,"auto_master_out_arready", false,-1);
    tracep->declBit(c+90,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+1298,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+1145,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+1299,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+1043,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+1300,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+91,"auto_master_out_rready", false,-1);
    tracep->declBit(c+206,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+207,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+51,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+1254,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+52,"auto_master_out_rlast", false,-1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+106,"reset", false,-1);
    tracep->declBit(c+1285,"io_interrupt", false,-1);
    tracep->declBit(c+382,"io_master_awready", false,-1);
    tracep->declBit(c+88,"io_master_awvalid", false,-1);
    tracep->declBus(c+1140,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+1295,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+1296,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+1141,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+1142,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+383,"io_master_wready", false,-1);
    tracep->declBit(c+89,"io_master_wvalid", false,-1);
    tracep->declBus(c+1143,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+1144,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+1297,"io_master_wlast", false,-1);
    tracep->declBit(c+1253,"io_master_bready", false,-1);
    tracep->declBit(c+203,"io_master_bvalid", false,-1);
    tracep->declBus(c+205,"io_master_bresp", false,-1, 1,0);
    tracep->declBus(c+204,"io_master_bid", false,-1, 3,0);
    tracep->declBit(c+384,"io_master_arready", false,-1);
    tracep->declBit(c+90,"io_master_arvalid", false,-1);
    tracep->declBus(c+1145,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+1298,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+1299,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+1043,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+1300,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+91,"io_master_rready", false,-1);
    tracep->declBit(c+206,"io_master_rvalid", false,-1);
    tracep->declBus(c+1254,"io_master_rresp", false,-1, 1,0);
    tracep->declBus(c+51,"io_master_rdata", false,-1, 31,0);
    tracep->declBit(c+52,"io_master_rlast", false,-1);
    tracep->declBus(c+207,"io_master_rid", false,-1, 3,0);
    tracep->declBit(c+1302,"io_slave_awready", false,-1);
    tracep->declBit(c+1285,"io_slave_awvalid", false,-1);
    tracep->declBus(c+1303,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+1304,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+1299,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+1305,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+1306,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+1307,"io_slave_wready", false,-1);
    tracep->declBit(c+1285,"io_slave_wvalid", false,-1);
    tracep->declBus(c+1303,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+1304,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+1285,"io_slave_wlast", false,-1);
    tracep->declBit(c+1285,"io_slave_bready", false,-1);
    tracep->declBit(c+1308,"io_slave_bvalid", false,-1);
    tracep->declBus(c+1309,"io_slave_bresp", false,-1, 1,0);
    tracep->declBus(c+1310,"io_slave_bid", false,-1, 3,0);
    tracep->declBit(c+1311,"io_slave_arready", false,-1);
    tracep->declBit(c+1285,"io_slave_arvalid", false,-1);
    tracep->declBus(c+1303,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+1304,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+1299,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+1305,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+1306,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+1285,"io_slave_rready", false,-1);
    tracep->declBit(c+1312,"io_slave_rvalid", false,-1);
    tracep->declBus(c+1313,"io_slave_rresp", false,-1, 1,0);
    tracep->declBus(c+1314,"io_slave_rdata", false,-1, 31,0);
    tracep->declBit(c+1315,"io_slave_rlast", false,-1);
    tracep->declBus(c+1316,"io_slave_rid", false,-1, 3,0);
    tracep->declBit(c+1044,"ready_idu_to_ifu", false,-1);
    tracep->declBus(c+1165,"npc", false,-1, 31,0);
    tracep->declBus(c+948,"pcbridge", false,-1, 31,0);
    tracep->declBus(c+1045,"inst", false,-1, 31,0);
    tracep->declBit(c+1046,"ifu_valid", false,-1);
    tracep->declBit(c+1047,"ifu_arvalid", false,-1);
    tracep->declBit(c+1048,"ifu_arready", false,-1);
    tracep->declBus(c+948,"ifu_araddr", false,-1, 31,0);
    tracep->declBit(c+284,"ifu_rvalid", false,-1);
    tracep->declBit(c+1044,"ifu_rready", false,-1);
    tracep->declBus(c+285,"ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+1049,"reg_process", false,-1);
    tracep->declBus(c+1050,"src1", false,-1, 4,0);
    tracep->declBus(c+1051,"src2", false,-1, 4,0);
    tracep->declBus(c+1052,"rd", false,-1, 4,0);
    tracep->declBus(c+1053,"imm", false,-1, 31,0);
    tracep->declBit(c+1054,"ebreaksig", false,-1);
    tracep->declBit(c+1055,"mretsig", false,-1);
    tracep->declBit(c+1056,"ecallsig", false,-1);
    tracep->declBit(c+1057,"regew", false,-1);
    tracep->declBit(c+1058,"memew", false,-1);
    tracep->declBit(c+1059,"memer", false,-1);
    tracep->declBit(c+1060,"muximm", false,-1);
    tracep->declBus(c+1061,"func3", false,-1, 2,0);
    tracep->declBus(c+1062,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1063,"func7", false,-1);
    tracep->declBit(c+1064,"btypebranch", false,-1);
    tracep->declBit(c+1065,"jalsig", false,-1);
    tracep->declBit(c+1066,"jalrsig", false,-1);
    tracep->declBit(c+1067,"auipcsig", false,-1);
    tracep->declBus(c+1068,"aluop", false,-1, 1,0);
    tracep->declBit(c+1069,"csrrw", false,-1);
    tracep->declBit(c+1070,"csrrs", false,-1);
    tracep->declBit(c+1046,"idu_valid", false,-1);
    tracep->declBus(c+1071,"memmask", false,-1, 2,0);
    tracep->declBit(c+1072,"memsextsig", false,-1);
    tracep->declBus(c+286,"regwrite", false,-1, 31,0);
    tracep->declBus(c+1166,"regout1", false,-1, 31,0);
    tracep->declBus(c+1167,"regout2", false,-1, 31,0);
    tracep->declBus(c+949,"mepc", false,-1, 31,0);
    tracep->declBus(c+950,"mtvec", false,-1, 31,0);
    tracep->declBit(c+1044,"ready_exu_to_idu", false,-1);
    tracep->declBus(c+1168,"res", false,-1, 31,0);
    tracep->declBus(c+1169,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1046,"exu_valid", false,-1);
    tracep->declBit(c+1044,"ready_wbu_to_exu", false,-1);
    tracep->declBit(c+1262,"memvalid", false,-1);
    tracep->declBus(c+1073,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1073,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1074,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1075,"rready", false,-1, 1,0);
    tracep->declBus(c+1076,"bready", false,-1, 1,0);
    tracep->declBus(c+86,"bvalid", false,-1, 1,0);
    tracep->declBus(c+287,"rvalid", false,-1, 1,0);
    tracep->declBus(c+626,"awready", false,-1, 1,0);
    tracep->declBus(c+626,"wready", false,-1, 1,0);
    tracep->declBus(c+1077,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1263+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+288+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1170+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1172+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1174+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+290+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1176+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1078+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->pushNamePrefix("arviter0 ");
    tracep->declBus(c+1317,"DEVICE_NUM", false,-1, 31,0);
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+106,"reset", false,-1);
    tracep->declBus(c+1073,"awvalid", false,-1, 1,0);
    tracep->declBus(c+1073,"wvalid", false,-1, 1,0);
    tracep->declBus(c+1074,"arvalid", false,-1, 1,0);
    tracep->declBus(c+1075,"rready", false,-1, 1,0);
    tracep->declBus(c+1076,"bready", false,-1, 1,0);
    tracep->declBus(c+86,"bvalid", false,-1, 1,0);
    tracep->declBus(c+287,"rvalid", false,-1, 1,0);
    tracep->declBus(c+626,"awready", false,-1, 1,0);
    tracep->declBus(c+626,"wready", false,-1, 1,0);
    tracep->declBus(c+1077,"arready", false,-1, 1,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1178+i*1,"araddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1180+i*1,"awaddr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1182+i*1,"wdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1184+i*1,"wstrb", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+292+i*1,"rdata", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+294+i*1,"bresp", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1186+i*1,"awsize", true,(i+0), 2,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1080+i*1,"arsize", true,(i+0), 2,0);
    }
    tracep->declBit(c+88,"awvalid_out", false,-1);
    tracep->declBit(c+89,"wvalid_out", false,-1);
    tracep->declBit(c+90,"arvalid_out", false,-1);
    tracep->declBit(c+91,"rready_out", false,-1);
    tracep->declBit(c+1253,"bready_out", false,-1);
    tracep->declBit(c+203,"bvalid_in", false,-1);
    tracep->declBit(c+206,"rvalid_in", false,-1);
    tracep->declBit(c+383,"awready_in", false,-1);
    tracep->declBit(c+383,"wready_in", false,-1);
    tracep->declBit(c+384,"arready_in", false,-1);
    tracep->declBus(c+1145,"araddr_out", false,-1, 31,0);
    tracep->declBus(c+1140,"awaddr_out", false,-1, 31,0);
    tracep->declBus(c+1143,"wdata_out", false,-1, 31,0);
    tracep->declBus(c+1144,"wstrb_out", false,-1, 3,0);
    tracep->declBus(c+51,"rdata_in", false,-1, 31,0);
    tracep->declBus(c+205,"bresp_in", false,-1, 1,0);
    tracep->declBus(c+1141,"awsize_out", false,-1, 2,0);
    tracep->declBus(c+1043,"arsize_out", false,-1, 2,0);
    tracep->declBit(c+627,"busy", false,-1);
    tracep->declBus(c+628,"giant", false,-1, 1,0);
    tracep->declBus(c+629,"i", false,-1, 31,0);
    tracep->declBus(c+1140,"awaddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1143,"wdata_out_reg", false,-1, 31,0);
    tracep->declBus(c+1145,"araddr_out_reg", false,-1, 31,0);
    tracep->declBus(c+1144,"wstrb_out_reg", false,-1, 3,0);
    tracep->declBus(c+1141,"awsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1043,"arsize_out_reg", false,-1, 2,0);
    tracep->declBus(c+1318,"j", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+1061,"func3", false,-1, 2,0);
    tracep->declBit(c+1064,"btypebranch", false,-1);
    tracep->declBit(c+1063,"func7", false,-1);
    tracep->declBus(c+1068,"aluop", false,-1, 1,0);
    tracep->declBit(c+1066,"jalrsig", false,-1);
    tracep->declBit(c+1065,"jalsig", false,-1);
    tracep->declBus(c+1053,"imm", false,-1, 31,0);
    tracep->declBit(c+1060,"muximm", false,-1);
    tracep->declBus(c+1166,"regout1", false,-1, 31,0);
    tracep->declBus(c+1167,"regout2", false,-1, 31,0);
    tracep->declBus(c+948,"pc", false,-1, 31,0);
    tracep->declBit(c+1067,"auipcsig", false,-1);
    tracep->declBit(c+1055,"mretsig", false,-1);
    tracep->declBit(c+1056,"ecallsig", false,-1);
    tracep->declBus(c+950,"mtvec", false,-1, 31,0);
    tracep->declBus(c+949,"mepc", false,-1, 31,0);
    tracep->declBit(c+1046,"valid_from", false,-1);
    tracep->declBit(c+1044,"ready_from", false,-1);
    tracep->declBus(c+1168,"res", false,-1, 31,0);
    tracep->declBus(c+1165,"npc", false,-1, 31,0);
    tracep->declBus(c+1169,"pcwritereg", false,-1, 31,0);
    tracep->declBit(c+1046,"valid_to", false,-1);
    tracep->declBit(c+1044,"ready_to", false,-1);
    tracep->declBus(c+951,"pcadd4bridge", false,-1, 31,0);
    tracep->declBus(c+1188,"pcaddimmbridge", false,-1, 31,0);
    tracep->declBus(c+1082,"aluopcode", false,-1, 4,0);
    tracep->declBus(c+1189,"aluarg2", false,-1, 31,0);
    tracep->declBit(c+1190,"zero", false,-1);
    tracep->declBit(c+1191,"signal", false,-1);
    tracep->declBit(c+1192,"carry", false,-1);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+1166,"A", false,-1, 31,0);
    tracep->declBus(c+1189,"B", false,-1, 31,0);
    tracep->declBus(c+1082,"op", false,-1, 4,0);
    tracep->declBus(c+1168,"res", false,-1, 31,0);
    tracep->declBit(c+1190,"zero", false,-1);
    tracep->declBit(c+1191,"signal", false,-1);
    tracep->declBit(c+1192,"carry", false,-1);
    tracep->declBit(c+1083,"addsig", false,-1);
    tracep->declBit(c+1084,"logsig", false,-1);
    tracep->declBit(c+1085,"shfsig", false,-1);
    tracep->declBit(c+1086,"sltsig", false,-1);
    tracep->declBit(c+1192,"carry_tmp", false,-1);
    tracep->declBit(c+1087,"type_I", false,-1);
    tracep->declBus(c+1193,"logres", false,-1, 31,0);
    tracep->declBus(c+1194,"addres", false,-1, 31,0);
    tracep->declBit(c+1195,"addzero", false,-1);
    tracep->declBus(c+1196,"shfres", false,-1, 31,0);
    tracep->declBus(c+1197,"sltres", false,-1, 31,0);
    tracep->declBus(c+1166,"A_s", false,-1, 31,0);
    tracep->declBus(c+1189,"B_s", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alucontrol0 ");
    tracep->declBus(c+1061,"func3", false,-1, 2,0);
    tracep->declBit(c+1063,"func7", false,-1);
    tracep->declBus(c+1068,"aluop", false,-1, 1,0);
    tracep->declBit(c+1066,"jalrsig", false,-1);
    tracep->declBus(c+1082,"aluopcode", false,-1, 4,0);
    tracep->declBit(c+1087,"type_I", false,-1);
    tracep->declBit(c+1088,"type_B", false,-1);
    tracep->declBit(c+1089,"type_R", false,-1);
    tracep->declBit(c+1090,"addsig", false,-1);
    tracep->declBus(c+1091,"branchop", false,-1, 3,0);
    tracep->declBus(c+1092,"IRop", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchcontrol0 ");
    tracep->declBit(c+1064,"btypebranch", false,-1);
    tracep->declBus(c+1061,"func3", false,-1, 2,0);
    tracep->declBit(c+1190,"zero", false,-1);
    tracep->declBit(c+1191,"signal", false,-1);
    tracep->declBit(c+1192,"carry", false,-1);
    tracep->declBus(c+1168,"res", false,-1, 31,0);
    tracep->declBus(c+951,"pcadd4", false,-1, 31,0);
    tracep->declBus(c+1188,"pcaddimm", false,-1, 31,0);
    tracep->declBit(c+1065,"jalsig", false,-1);
    tracep->declBit(c+1066,"jalrsig", false,-1);
    tracep->declBit(c+1067,"auipcsig", false,-1);
    tracep->declBit(c+1055,"mretsig", false,-1);
    tracep->declBit(c+1056,"ecallsig", false,-1);
    tracep->declBus(c+950,"mtvec", false,-1, 31,0);
    tracep->declBus(c+949,"mepc", false,-1, 31,0);
    tracep->declBus(c+1165,"npc", false,-1, 31,0);
    tracep->declBus(c+1169,"pcwritereg", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("chosmuximm ");
    tracep->declBus(c+1317,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1319,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1320,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1189,"out", false,-1, 31,0);
    tracep->declBus(c+1060,"key", false,-1, 0,0);
    tracep->declArray(c+1117,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1317,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1319,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1320,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1321,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1189,"out", false,-1, 31,0);
    tracep->declBus(c+1060,"key", false,-1, 0,0);
    tracep->declBus(c+1303,"default_out", false,-1, 31,0);
    tracep->declArray(c+1117,"lut", false,-1, 65,0);
    tracep->declBus(c+1322,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+1120+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1124+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+1198,"lut_out", false,-1, 31,0);
    tracep->declBit(c+1093,"hit", false,-1);
    tracep->declBus(c+1323,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pcadd40 ");
    tracep->declBus(c+948,"pc", false,-1, 31,0);
    tracep->declBus(c+951,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcaddimm0 ");
    tracep->declBus(c+948,"pc", false,-1, 31,0);
    tracep->declBus(c+1053,"imm", false,-1, 31,0);
    tracep->declBus(c+1188,"npc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+1045,"inst", false,-1, 31,0);
    tracep->declBit(c+1046,"valid_from", false,-1);
    tracep->declBit(c+1044,"ready_from", false,-1);
    tracep->declBit(c+1054,"ebreaksig", false,-1);
    tracep->declBit(c+1056,"ecallsig", false,-1);
    tracep->declBit(c+1055,"mretsig", false,-1);
    tracep->declBus(c+1053,"imm", false,-1, 31,0);
    tracep->declBus(c+1061,"func3", false,-1, 2,0);
    tracep->declBit(c+1063,"func7", false,-1);
    tracep->declBus(c+1050,"src1", false,-1, 4,0);
    tracep->declBus(c+1051,"src2", false,-1, 4,0);
    tracep->declBus(c+1052,"rd", false,-1, 4,0);
    tracep->declBit(c+1058,"memew", false,-1);
    tracep->declBus(c+1062,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1059,"memer", false,-1);
    tracep->declBit(c+1057,"regew", false,-1);
    tracep->declBit(c+1060,"muximm", false,-1);
    tracep->declBit(c+1064,"btypebranch", false,-1);
    tracep->declBit(c+1066,"jalrsig", false,-1);
    tracep->declBit(c+1065,"jalsig", false,-1);
    tracep->declBus(c+1068,"aluop", false,-1, 1,0);
    tracep->declBit(c+1067,"auipcsig", false,-1);
    tracep->declBit(c+1069,"csrrw", false,-1);
    tracep->declBit(c+1070,"csrrs", false,-1);
    tracep->declBit(c+1046,"valid_to", false,-1);
    tracep->declBit(c+1044,"ready_to", false,-1);
    tracep->declBus(c+1071,"memmask", false,-1, 2,0);
    tracep->declBit(c+1072,"memsextsig", false,-1);
    tracep->declBit(c+1054,"ebreak", false,-1);
    tracep->declBit(c+1056,"ecall", false,-1);
    tracep->declBit(c+1055,"mret", false,-1);
    tracep->declBus(c+1061,"func3bridge", false,-1, 2,0);
    tracep->declBit(c+1063,"func7bridge", false,-1);
    tracep->declBus(c+1094,"opcode", false,-1, 6,0);
    tracep->pushNamePrefix("decoder0 ");
    tracep->declBus(c+1045,"inst", false,-1, 31,0);
    tracep->declBit(c+1054,"ebreaksig", false,-1);
    tracep->declBit(c+1056,"ecallsig", false,-1);
    tracep->declBit(c+1055,"mretsig", false,-1);
    tracep->declBus(c+1053,"imm", false,-1, 31,0);
    tracep->declBus(c+1094,"opcode", false,-1, 6,0);
    tracep->declBus(c+1061,"func3", false,-1, 2,0);
    tracep->declBit(c+1063,"func7", false,-1);
    tracep->declBus(c+1050,"src1", false,-1, 4,0);
    tracep->declBus(c+1051,"src2", false,-1, 4,0);
    tracep->declBus(c+1052,"rd", false,-1, 4,0);
    tracep->declBus(c+1071,"memmask", false,-1, 2,0);
    tracep->declBit(c+1072,"memsextsig", false,-1);
    tracep->declBit(c+1095,"type_I", false,-1);
    tracep->declBit(c+1096,"type_R", false,-1);
    tracep->declBit(c+1097,"type_U", false,-1);
    tracep->declBit(c+1058,"type_S", false,-1);
    tracep->declBit(c+1065,"type_J", false,-1);
    tracep->declBit(c+1064,"type_B", false,-1);
    tracep->declBus(c+1098,"I_imm", false,-1, 31,0);
    tracep->declBus(c+1099,"U_imm", false,-1, 31,0);
    tracep->declBus(c+1100,"S_imm", false,-1, 31,0);
    tracep->declBus(c+1101,"J_imm", false,-1, 31,0);
    tracep->declBus(c+1102,"B_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maincontrol0 ");
    tracep->declBus(c+1094,"opcode", false,-1, 6,0);
    tracep->declBus(c+1061,"func3", false,-1, 2,0);
    tracep->declBit(c+1063,"func7", false,-1);
    tracep->declBit(c+1054,"ebreaksig", false,-1);
    tracep->declBit(c+1056,"ecallsig", false,-1);
    tracep->declBit(c+1055,"mretsig", false,-1);
    tracep->declBit(c+1058,"memew", false,-1);
    tracep->declBus(c+1062,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1059,"memer", false,-1);
    tracep->declBit(c+1057,"regew", false,-1);
    tracep->declBit(c+1060,"muximm", false,-1);
    tracep->declBit(c+1064,"btypebranch", false,-1);
    tracep->declBit(c+1066,"jalrsig", false,-1);
    tracep->declBit(c+1065,"jalsig", false,-1);
    tracep->declBus(c+1068,"aluop", false,-1, 1,0);
    tracep->declBit(c+1067,"auipcsig", false,-1);
    tracep->declBit(c+1069,"csrrw", false,-1);
    tracep->declBit(c+1070,"csrrs", false,-1);
    tracep->declBit(c+1095,"type_I", false,-1);
    tracep->declBit(c+1096,"type_R", false,-1);
    tracep->declBit(c+1097,"type_U", false,-1);
    tracep->declBit(c+1058,"type_S", false,-1);
    tracep->declBit(c+1065,"type_J", false,-1);
    tracep->declBit(c+1064,"type_B", false,-1);
    tracep->declBit(c+1059,"load", false,-1);
    tracep->declBit(c+1058,"store", false,-1);
    tracep->declBit(c+1103,"regwritepc", false,-1);
    tracep->declBit(c+1059,"regwritemem", false,-1);
    tracep->declBit(c+1104,"luisig", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBus(c+1165,"npc", false,-1, 31,0);
    tracep->declBit(c+1044,"ready", false,-1);
    tracep->declBus(c+948,"pc", false,-1, 31,0);
    tracep->declBus(c+1045,"inst", false,-1, 31,0);
    tracep->declBit(c+1046,"valid", false,-1);
    tracep->declBit(c+1049,"regprocess", false,-1);
    tracep->declBit(c+1047,"arvalid", false,-1);
    tracep->declBit(c+1048,"arready", false,-1);
    tracep->declBus(c+948,"araddr", false,-1, 31,0);
    tracep->declBit(c+284,"rvalid", false,-1);
    tracep->declBit(c+1044,"rready", false,-1);
    tracep->declBus(c+285,"rdata", false,-1, 31,0);
    tracep->declBus(c+948,"pcbridge", false,-1, 31,0);
    tracep->declBit(c+1105,"infetch_ready", false,-1);
    tracep->declBus(c+1106,"state", false,-1, 2,0);
    tracep->declBus(c+1045,"inst_reg", false,-1, 31,0);
    tracep->pushNamePrefix("pcreg0 ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBus(c+1165,"npc", false,-1, 31,0);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBit(c+1105,"ready_from", false,-1);
    tracep->declBus(c+948,"pcout", false,-1, 31,0);
    tracep->declBus(c+1324,"init", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("regfile ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBit(c+1265,"ew", false,-1);
    tracep->declBus(c+1052,"addr", false,-1, 4,0);
    tracep->declBus(c+1050,"src1", false,-1, 4,0);
    tracep->declBus(c+1051,"src2", false,-1, 4,0);
    tracep->declBus(c+1107,"csr", false,-1, 11,0);
    tracep->declBus(c+286,"data", false,-1, 31,0);
    tracep->declBit(c+1069,"csrrw", false,-1);
    tracep->declBit(c+1070,"csrrs", false,-1);
    tracep->declBit(c+1056,"ecallsig", false,-1);
    tracep->declBit(c+1046,"valid", false,-1);
    tracep->declBus(c+1166,"regout1", false,-1, 31,0);
    tracep->declBus(c+1167,"regout2", false,-1, 31,0);
    tracep->declBus(c+949,"mepc", false,-1, 31,0);
    tracep->declBus(c+950,"mtvec", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+952+i*1,"rf", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+984+i*1,"rf_csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1108,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+296,"reg_write_data", false,-1, 31,0);
    tracep->pushNamePrefix("muxcsr ");
    tracep->declBus(c+1325,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1326,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1327,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1108,"out", false,-1, 2,0);
    tracep->declBus(c+1107,"key", false,-1, 11,0);
    tracep->declArray(c+1328,"lut", false,-1, 89,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1325,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1326,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1327,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1321,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1108,"out", false,-1, 2,0);
    tracep->declBus(c+1107,"key", false,-1, 11,0);
    tracep->declBus(c+1305,"default_out", false,-1, 2,0);
    tracep->declArray(c+1328,"lut", false,-1, 89,0);
    tracep->declBus(c+1331,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+3+i*1,"pair_list", true,(i+0), 14,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+9+i*1,"key_list", true,(i+0), 11,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+15+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1109,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1110,"hit", false,-1);
    tracep->declBus(c+1332,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("registers0 ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBit(c+1266,"ew", false,-1);
    tracep->declBit(c+1069,"csrrw", false,-1);
    tracep->declBit(c+1070,"csrrs", false,-1);
    tracep->declBit(c+1056,"ecall", false,-1);
    tracep->declBus(c+1108,"csr_choose", false,-1, 2,0);
    tracep->declBus(c+1052,"addr", false,-1, 4,0);
    tracep->declBus(c+296,"data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+990+i*1,"gr", true,(i+0), 31,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+1022+i*1,"csr", true,(i+0), 31,0);
    }
    tracep->declBus(c+1028,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wbu0 ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBus(c+1168,"res", false,-1, 31,0);
    tracep->declBus(c+1167,"regout2", false,-1, 31,0);
    tracep->declBit(c+1058,"memew", false,-1);
    tracep->declBit(c+1059,"memer", false,-1);
    tracep->declBus(c+1053,"imm", false,-1, 31,0);
    tracep->declBus(c+1169,"pcwritereg", false,-1, 31,0);
    tracep->declBus(c+1062,"muxsig", false,-1, 2,0);
    tracep->declBit(c+1046,"valid_from", false,-1);
    tracep->declBus(c+1071,"memmask", false,-1, 2,0);
    tracep->declBit(c+1072,"memsextsig", false,-1);
    tracep->declBus(c+286,"regwrite", false,-1, 31,0);
    tracep->declBit(c+1044,"ready_to", false,-1);
    tracep->declBit(c+1262,"memvalid", false,-1);
    tracep->declBit(c+1111,"awvalid", false,-1);
    tracep->declBit(c+630,"awready", false,-1);
    tracep->declBus(c+1168,"awaddr", false,-1, 31,0);
    tracep->declBit(c+1111,"wvalid", false,-1);
    tracep->declBit(c+630,"wready", false,-1);
    tracep->declBus(c+1199,"wdata", false,-1, 31,0);
    tracep->declBus(c+1200,"wstrb", false,-1, 3,0);
    tracep->declBit(c+87,"bvalid", false,-1);
    tracep->declBit(c+1058,"bready", false,-1);
    tracep->declBus(c+297,"bresp", false,-1, 1,0);
    tracep->declBit(c+1267,"arvalid", false,-1);
    tracep->declBit(c+1112,"arready", false,-1);
    tracep->declBus(c+1201,"araddr", false,-1, 31,0);
    tracep->declBit(c+298,"rvalid", false,-1);
    tracep->declBit(c+1059,"rready", false,-1);
    tracep->declBus(c+299,"rdata", false,-1, 31,0);
    tracep->declBus(c+1202,"awsize", false,-1, 2,0);
    tracep->declBus(c+1113,"arsize", false,-1, 2,0);
    tracep->declBus(c+1142,"awburst", false,-1, 1,0);
    tracep->declBus(c+631,"state", false,-1, 1,0);
    tracep->declBus(c+300,"memread", false,-1, 31,0);
    tracep->declBus(c+1203,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1114,"access_size_i", false,-1, 1,0);
    tracep->declBit(c+1204,"aligned_sram", false,-1);
    tracep->declBit(c+1268,"ready", false,-1);
    tracep->pushNamePrefix("memreadlen0 ");
    tracep->declBit(c+1204,"is_unalign", false,-1);
    tracep->declBus(c+299,"data", false,-1, 31,0);
    tracep->declBus(c+1071,"memmask", false,-1, 2,0);
    tracep->declBit(c+1072,"memsextsig", false,-1);
    tracep->declBus(c+1205,"addr_offset", false,-1, 1,0);
    tracep->declBus(c+300,"read", false,-1, 31,0);
    tracep->declBus(c+301,"read_u", false,-1, 31,0);
    tracep->declBus(c+302,"read_s", false,-1, 31,0);
    tracep->declBus(c+303,"read_sb", false,-1, 31,0);
    tracep->declBus(c+304,"read_sh", false,-1, 31,0);
    tracep->declBus(c+305,"byte_data", false,-1, 7,0);
    tracep->declBus(c+306,"halfword_data", false,-1, 15,0);
    tracep->declBus(c+1269,"halfword_data_unalign", false,-1, 15,0);
    tracep->declBus(c+1270,"byte_data_unalign", false,-1, 7,0);
    tracep->declBus(c+307,"halfword_data_align", false,-1, 15,0);
    tracep->declBus(c+308,"byte_data_align", false,-1, 7,0);
    tracep->pushNamePrefix("sext0 ");
    tracep->declBus(c+1333,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1320,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+305,"input_number", false,-1, 7,0);
    tracep->declBus(c+303,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sext1 ");
    tracep->declBus(c+1334,"INPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1320,"OUTPUT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+306,"input_number", false,-1, 15,0);
    tracep->declBus(c+304,"output_number", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("muxpc ");
    tracep->declBus(c+1335,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1327,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1320,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+286,"out", false,-1, 31,0);
    tracep->declBus(c+1062,"key", false,-1, 2,0);
    tracep->declBus(c+1321,"default_out", false,-1, 31,0);
    tracep->declArray(c+107,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1335,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1327,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1320,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1319,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+286,"out", false,-1, 31,0);
    tracep->declBus(c+1062,"key", false,-1, 2,0);
    tracep->declBus(c+1321,"default_out", false,-1, 31,0);
    tracep->declArray(c+107,"lut", false,-1, 139,0);
    tracep->declBus(c+1336,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+112+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+21+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+120+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+309,"lut_out", false,-1, 31,0);
    tracep->declBit(c+310,"hit", false,-1);
    tracep->declBus(c+1337,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("strbcontol ");
    tracep->declBus(c+1168,"awaddr", false,-1, 31,0);
    tracep->declBus(c+1071,"wirtelen", false,-1, 2,0);
    tracep->declBus(c+1200,"wstrb", false,-1, 3,0);
    tracep->declBus(c+1202,"awsize", false,-1, 2,0);
    tracep->declBus(c+1203,"wdata_offset", false,-1, 1,0);
    tracep->declBus(c+1142,"awburst", false,-1, 1,0);
    tracep->declBus(c+1317,"device_num", false,-1, 31,0);
    tracep->declBit(c+1206,"inuart", false,-1);
    tracep->declBit(c+1207,"insram", false,-1);
    tracep->declBit(c+1208,"inflash", false,-1);
    tracep->declBit(c+1209,"inspi", false,-1);
    tracep->declBit(c+1210,"inpsram", false,-1);
    tracep->declBus(c+1211,"bus_size", false,-1, 1,0);
    tracep->declBus(c+1115,"awsize_general", false,-1, 2,0);
    tracep->declBus(c+1116,"wstrb_general", false,-1, 3,0);
    tracep->declBus(c+1338,"wstrb_byte", false,-1, 3,0);
    tracep->declBus(c+1339,"wstrb_halfword", false,-1, 3,0);
    tracep->declBus(c+1212,"wstrb_word", false,-1, 3,0);
    tracep->declBus(c+1213,"mux", false,-1, 4,0);
    tracep->pushNamePrefix("len_mux ");
    tracep->declBus(c+1327,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1317,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1327,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1202,"out", false,-1, 2,0);
    tracep->declBus(c+1211,"key", false,-1, 1,0);
    tracep->declBus(c+1115,"default_out", false,-1, 2,0);
    tracep->declBus(c+1340,"lut", false,-1, 14,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1327,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1317,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1327,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1319,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1202,"out", false,-1, 2,0);
    tracep->declBus(c+1211,"key", false,-1, 1,0);
    tracep->declBus(c+1115,"default_out", false,-1, 2,0);
    tracep->declBus(c+1340,"lut", false,-1, 14,0);
    tracep->declBus(c+1341,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+25+i*1,"pair_list", true,(i+0), 4,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+28+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+31+i*1,"data_list", true,(i+0), 2,0);
    }
    tracep->declBus(c+1214,"lut_out", false,-1, 2,0);
    tracep->declBit(c+1215,"hit", false,-1);
    tracep->declBus(c+1342,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("type_mux ");
    tracep->declBus(c+1317,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1317,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1317,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1211,"out", false,-1, 1,0);
    tracep->declBus(c+1216,"key", false,-1, 1,0);
    tracep->declBus(c+1306,"default_out", false,-1, 1,0);
    tracep->declBus(c+1343,"lut", false,-1, 7,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1317,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1317,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1317,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1319,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1211,"out", false,-1, 1,0);
    tracep->declBus(c+1216,"key", false,-1, 1,0);
    tracep->declBus(c+1306,"default_out", false,-1, 1,0);
    tracep->declBus(c+1343,"lut", false,-1, 7,0);
    tracep->declBus(c+1335,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+34+i*1,"pair_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+36+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+38+i*1,"data_list", true,(i+0), 1,0);
    }
    tracep->declBus(c+1217,"lut_out", false,-1, 1,0);
    tracep->declBit(c+1218,"hit", false,-1);
    tracep->declBus(c+1323,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("wstrb_mux ");
    tracep->declBus(c+1335,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1317,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1335,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1200,"out", false,-1, 3,0);
    tracep->declBus(c+1211,"key", false,-1, 1,0);
    tracep->declBus(c+1126,"lut", false,-1, 23,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+1335,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+1317,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+1335,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+1321,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1200,"out", false,-1, 3,0);
    tracep->declBus(c+1211,"key", false,-1, 1,0);
    tracep->declBus(c+1304,"default_out", false,-1, 3,0);
    tracep->declBus(c+1126,"lut", false,-1, 23,0);
    tracep->declBus(c+1325,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1127+i*1,"pair_list", true,(i+0), 5,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+40+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1131+i*1,"data_list", true,(i+0), 3,0);
    }
    tracep->declBus(c+1219,"lut_out", false,-1, 3,0);
    tracep->declBit(c+1220,"hit", false,-1);
    tracep->declBus(c+1337,"i", false,-1, 31,0);
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"io_d", false,-1);
    tracep->declBit(c+632,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"io_d", false,-1);
    tracep->declBit(c+632,"io_q", false,-1);
    tracep->declBit(c+632,"sync_0", false,-1);
    tracep->declBit(c+633,"sync_1", false,-1);
    tracep->declBit(c+634,"sync_2", false,-1);
    tracep->declBit(c+635,"sync_3", false,-1);
    tracep->declBit(c+636,"sync_4", false,-1);
    tracep->declBit(c+637,"sync_5", false,-1);
    tracep->declBit(c+638,"sync_6", false,-1);
    tracep->declBit(c+639,"sync_7", false,-1);
    tracep->declBit(c+640,"sync_8", false,-1);
    tracep->declBit(c+641,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lgpio ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+135,"auto_in_psel", false,-1);
    tracep->declBit(c+47,"auto_in_penable", false,-1);
    tracep->declBit(c+126,"auto_in_pwrite", false,-1);
    tracep->declBus(c+134,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1284,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1292,"auto_in_pready", false,-1);
    tracep->declBit(c+1293,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1294,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1224,"gpio_bundle_out", false,-1, 15,0);
    tracep->declBus(c+1225,"gpio_bundle_in", false,-1, 15,0);
    tracep->declBus(c+1226,"gpio_bundle_seg_0", false,-1, 7,0);
    tracep->declBus(c+1227,"gpio_bundle_seg_1", false,-1, 7,0);
    tracep->declBus(c+1228,"gpio_bundle_seg_2", false,-1, 7,0);
    tracep->declBus(c+1229,"gpio_bundle_seg_3", false,-1, 7,0);
    tracep->declBus(c+1230,"gpio_bundle_seg_4", false,-1, 7,0);
    tracep->declBus(c+1231,"gpio_bundle_seg_5", false,-1, 7,0);
    tracep->declBus(c+1232,"gpio_bundle_seg_6", false,-1, 7,0);
    tracep->declBus(c+1233,"gpio_bundle_seg_7", false,-1, 7,0);
    tracep->pushNamePrefix("mgpio ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+155,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+135,"in_psel", false,-1);
    tracep->declBit(c+47,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1292,"in_pready", false,-1);
    tracep->declBus(c+1294,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1293,"in_pslverr", false,-1);
    tracep->declBus(c+1224,"gpio_out", false,-1, 15,0);
    tracep->declBus(c+1225,"gpio_in", false,-1, 15,0);
    tracep->declBus(c+1226,"gpio_seg_0", false,-1, 7,0);
    tracep->declBus(c+1227,"gpio_seg_1", false,-1, 7,0);
    tracep->declBus(c+1228,"gpio_seg_2", false,-1, 7,0);
    tracep->declBus(c+1229,"gpio_seg_3", false,-1, 7,0);
    tracep->declBus(c+1230,"gpio_seg_4", false,-1, 7,0);
    tracep->declBus(c+1231,"gpio_seg_5", false,-1, 7,0);
    tracep->declBus(c+1232,"gpio_seg_6", false,-1, 7,0);
    tracep->declBus(c+1233,"gpio_seg_7", false,-1, 7,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lkeyboard ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+133,"auto_in_psel", false,-1);
    tracep->declBit(c+46,"auto_in_penable", false,-1);
    tracep->declBit(c+126,"auto_in_pwrite", false,-1);
    tracep->declBus(c+134,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1284,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1289,"auto_in_pready", false,-1);
    tracep->declBit(c+1290,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1291,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1234,"ps2_bundle_clk", false,-1);
    tracep->declBit(c+1235,"ps2_bundle_data", false,-1);
    tracep->pushNamePrefix("mps2 ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+155,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+133,"in_psel", false,-1);
    tracep->declBit(c+46,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1289,"in_pready", false,-1);
    tracep->declBus(c+1291,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1290,"in_pslverr", false,-1);
    tracep->declBit(c+1234,"ps2_clk", false,-1);
    tracep->declBit(c+1235,"ps2_data", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lmrom ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+1258,"auto_in_awvalid", false,-1);
    tracep->declBit(c+1259,"auto_in_wvalid", false,-1);
    tracep->declBit(c+442,"auto_in_arready", false,-1);
    tracep->declBit(c+1260,"auto_in_arvalid", false,-1);
    tracep->declBus(c+372,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+1156,"auto_in_araddr", false,-1, 29,0);
    tracep->declBit(c+1261,"auto_in_rready", false,-1);
    tracep->declBit(c+443,"auto_in_rvalid", false,-1);
    tracep->declBus(c+444,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+445,"auto_in_rdata", false,-1, 31,0);
    tracep->declBit(c+443,"state", false,-1);
    tracep->declBus(c+445,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBus(c+444,"nodeIn_rid_r", false,-1, 3,0);
    tracep->pushNamePrefix("mrom ");
    tracep->declBus(c+1221,"raddr", false,-1, 31,0);
    tracep->declBit(c+156,"ren", false,-1);
    tracep->declBus(c+157,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lpsram ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+136,"auto_in_psel", false,-1);
    tracep->declBit(c+48,"auto_in_penable", false,-1);
    tracep->declBit(c+126,"auto_in_pwrite", false,-1);
    tracep->declBus(c+124,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1284,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1249,"auto_in_pready", false,-1);
    tracep->declBit(c+1285,"auto_in_pslverr", false,-1);
    tracep->declBus(c+369,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+194,"qspi_bundle_sck", false,-1);
    tracep->declBit(c+195,"qspi_bundle_ce_n", false,-1);
    tracep->declBus(c+1246,"qspi_bundle_dio", false,-1, 3,0);
    tracep->pushNamePrefix("mpsram ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+124,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+136,"in_psel", false,-1);
    tracep->declBit(c+48,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1249,"in_pready", false,-1);
    tracep->declBus(c+369,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1285,"in_pslverr", false,-1);
    tracep->declBit(c+194,"qspi_sck", false,-1);
    tracep->declBit(c+195,"qspi_ce_n", false,-1);
    tracep->declBus(c+1246,"qspi_dio", false,-1, 3,0);
    tracep->declBus(c+1246,"din", false,-1, 3,0);
    tracep->declBus(c+311,"dout", false,-1, 3,0);
    tracep->declBus(c+312,"douten", false,-1, 3,0);
    tracep->declBit(c+1271,"ack", false,-1);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+1222,"clk_i", false,-1);
    tracep->declBit(c+1223,"rst_i", false,-1);
    tracep->declBus(c+124,"adr_i", false,-1, 31,0);
    tracep->declBus(c+127,"dat_i", false,-1, 31,0);
    tracep->declBus(c+369,"dat_o", false,-1, 31,0);
    tracep->declBus(c+128,"sel_i", false,-1, 3,0);
    tracep->declBit(c+136,"cyc_i", false,-1);
    tracep->declBit(c+136,"stb_i", false,-1);
    tracep->declBit(c+1271,"ack_o", false,-1);
    tracep->declBit(c+126,"we_i", false,-1);
    tracep->declBit(c+194,"sck", false,-1);
    tracep->declBit(c+195,"ce_n", false,-1);
    tracep->declBus(c+1246,"din", false,-1, 3,0);
    tracep->declBus(c+311,"dout", false,-1, 3,0);
    tracep->declBus(c+312,"douten", false,-1, 3,0);
    tracep->declBus(c+1344,"ST_IDLE", false,-1, 0,0);
    tracep->declBus(c+1345,"ST_WAIT", false,-1, 0,0);
    tracep->declBit(c+713,"mr_sck", false,-1);
    tracep->declBit(c+714,"mr_ce_n", false,-1);
    tracep->declBus(c+1246,"mr_din", false,-1, 3,0);
    tracep->declBus(c+715,"mr_dout", false,-1, 3,0);
    tracep->declBit(c+716,"mr_doe", false,-1);
    tracep->declBit(c+717,"mw_sck", false,-1);
    tracep->declBit(c+718,"mw_ce_n", false,-1);
    tracep->declBus(c+1246,"mw_din", false,-1, 3,0);
    tracep->declBus(c+313,"mw_dout", false,-1, 3,0);
    tracep->declBit(c+719,"mw_doe", false,-1);
    tracep->declBit(c+314,"mr_rd", false,-1);
    tracep->declBit(c+720,"mr_done", false,-1);
    tracep->declBit(c+315,"mw_wr", false,-1);
    tracep->declBit(c+316,"mw_done", false,-1);
    tracep->declBit(c+136,"wb_valid", false,-1);
    tracep->declBit(c+158,"wb_we", false,-1);
    tracep->declBit(c+159,"wb_re", false,-1);
    tracep->declBit(c+721,"state", false,-1);
    tracep->declBit(c+317,"nstate", false,-1);
    tracep->declBus(c+160,"size", false,-1, 2,0);
    tracep->declBus(c+161,"byte0", false,-1, 7,0);
    tracep->declBus(c+162,"byte1", false,-1, 7,0);
    tracep->declBus(c+163,"byte2", false,-1, 7,0);
    tracep->declBus(c+164,"byte3", false,-1, 7,0);
    tracep->declBus(c+165,"wdata", false,-1, 31,0);
    tracep->declBit(c+642,"qpi_valid", false,-1);
    tracep->declBit(c+643,"qpi_ce_n", false,-1);
    tracep->declBus(c+1246,"qpi_din", false,-1, 3,0);
    tracep->declBus(c+644,"qpi_dout", false,-1, 3,0);
    tracep->declBit(c+1272,"qpi_sck", false,-1);
    tracep->declBit(c+642,"qpi_doe", false,-1);
    tracep->pushNamePrefix("MR ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1273,"rst_n", false,-1);
    tracep->declBus(c+166,"addr", false,-1, 23,0);
    tracep->declBit(c+314,"rd", false,-1);
    tracep->declBus(c+1346,"size", false,-1, 2,0);
    tracep->declBit(c+720,"done", false,-1);
    tracep->declBus(c+369,"line", false,-1, 31,0);
    tracep->declBit(c+713,"sck", false,-1);
    tracep->declBit(c+714,"ce_n", false,-1);
    tracep->declBus(c+1246,"din", false,-1, 3,0);
    tracep->declBus(c+715,"dout", false,-1, 3,0);
    tracep->declBit(c+716,"douten", false,-1);
    tracep->declBus(c+1344,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1345,"READ", false,-1, 0,0);
    tracep->declBus(c+1347,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+722,"state", false,-1);
    tracep->declBit(c+318,"nstate", false,-1);
    tracep->declBus(c+723,"counter", false,-1, 7,0);
    tracep->declBus(c+724,"saddr", false,-1, 23,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+645+i*1,"data", true,(i+0), 7,0);
    }
    tracep->declBus(c+1348,"CMD_EBH", false,-1, 7,0);
    tracep->declBus(c+725,"byte_index", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MW ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1273,"rst_n", false,-1);
    tracep->declBus(c+167,"addr", false,-1, 23,0);
    tracep->declBus(c+165,"line", false,-1, 31,0);
    tracep->declBus(c+160,"size", false,-1, 2,0);
    tracep->declBit(c+315,"wr", false,-1);
    tracep->declBit(c+316,"done", false,-1);
    tracep->declBit(c+717,"sck", false,-1);
    tracep->declBit(c+718,"ce_n", false,-1);
    tracep->declBus(c+1246,"din", false,-1, 3,0);
    tracep->declBus(c+313,"dout", false,-1, 3,0);
    tracep->declBit(c+719,"douten", false,-1);
    tracep->declBus(c+1344,"IDLE", false,-1, 0,0);
    tracep->declBus(c+1345,"WRITE", false,-1, 0,0);
    tracep->declBus(c+168,"FINAL_COUNT", false,-1, 7,0);
    tracep->declBit(c+726,"state", false,-1);
    tracep->declBit(c+319,"nstate", false,-1);
    tracep->declBus(c+727,"counter", false,-1, 7,0);
    tracep->declBus(c+728,"saddr", false,-1, 23,0);
    tracep->declBus(c+1349,"CMD_38H", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("QPI ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1223,"rst", false,-1);
    tracep->declBit(c+642,"valid", false,-1);
    tracep->declBit(c+1272,"sck", false,-1);
    tracep->declBit(c+643,"ce_n", false,-1);
    tracep->declBus(c+1246,"din", false,-1, 3,0);
    tracep->declBus(c+644,"dout", false,-1, 3,0);
    tracep->declBit(c+642,"douten", false,-1);
    tracep->declBit(c+649,"finish", false,-1);
    tracep->declBus(c+1350,"H_35", false,-1, 7,0);
    tracep->declBus(c+650,"counter", false,-1, 2,0);
    tracep->declBus(c+651,"state", false,-1, 1,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+130,"auto_in_psel", false,-1);
    tracep->declBit(c+44,"auto_in_penable", false,-1);
    tracep->declBit(c+126,"auto_in_pwrite", false,-1);
    tracep->declBus(c+124,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+1284,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+711,"auto_in_pready", false,-1);
    tracep->declBit(c+1285,"auto_in_pslverr", false,-1);
    tracep->declBus(c+712,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1247,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+703,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+704,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+705,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+706,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+707,"sdram_bundle_we", false,-1);
    tracep->declBus(c+708,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+709,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+710,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+1248,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+124,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+130,"in_psel", false,-1);
    tracep->declBit(c+44,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+711,"in_pready", false,-1);
    tracep->declBus(c+712,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1285,"in_pslverr", false,-1);
    tracep->declBit(c+1247,"sdram_clk", false,-1);
    tracep->declBit(c+703,"sdram_cke", false,-1);
    tracep->declBit(c+704,"sdram_cs", false,-1);
    tracep->declBit(c+705,"sdram_ras", false,-1);
    tracep->declBit(c+706,"sdram_cas", false,-1);
    tracep->declBit(c+707,"sdram_we", false,-1);
    tracep->declBus(c+708,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+709,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+710,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+1248,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+729,"sdram_dout_en", false,-1);
    tracep->declBus(c+730,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+652,"state", false,-1, 1,0);
    tracep->declBit(c+731,"req_accept", false,-1);
    tracep->declBit(c+169,"is_read", false,-1);
    tracep->declBit(c+170,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+1222,"clk_i", false,-1);
    tracep->declBit(c+1223,"rst_i", false,-1);
    tracep->declBus(c+171,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+169,"inport_rd_i", false,-1);
    tracep->declBus(c+1299,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+124,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+127,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+1248,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+731,"inport_accept_o", false,-1);
    tracep->declBit(c+711,"inport_ack_o", false,-1);
    tracep->declBit(c+1285,"inport_error_o", false,-1);
    tracep->declBus(c+712,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+1247,"sdram_clk_o", false,-1);
    tracep->declBit(c+703,"sdram_cke_o", false,-1);
    tracep->declBit(c+704,"sdram_cs_o", false,-1);
    tracep->declBit(c+705,"sdram_ras_o", false,-1);
    tracep->declBit(c+706,"sdram_cas_o", false,-1);
    tracep->declBit(c+707,"sdram_we_o", false,-1);
    tracep->declBus(c+710,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+708,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+709,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+730,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+729,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+1351,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+1352,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+1353,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+1317,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+1317,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+1317,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+1335,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+1354,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+1355,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+1356,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+1357,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1335,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+1358,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+1359,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1360,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+1361,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+1362,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+1363,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1338,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1304,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+1364,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+1335,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+1304,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1338,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+1363,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1359,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+1361,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1360,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+1362,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+1358,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+1365,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+1366,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+1367,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+1367,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+1334,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+1367,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+1317,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1317,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+1325,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+124,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+171,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+169,"ram_rd_w", false,-1);
    tracep->declBit(c+731,"ram_accept_w", false,-1);
    tracep->declBus(c+127,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+712,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+711,"ram_ack_w", false,-1);
    tracep->declBit(c+172,"ram_req_w", false,-1);
    tracep->declBus(c+732,"command_q", false,-1, 3,0);
    tracep->declBus(c+708,"addr_q", false,-1, 12,0);
    tracep->declBus(c+730,"data_q", false,-1, 15,0);
    tracep->declBit(c+733,"data_rd_en_q", false,-1);
    tracep->declBus(c+710,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+703,"cke_q", false,-1);
    tracep->declBus(c+709,"bank_q", false,-1, 1,0);
    tracep->declBus(c+734,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+735,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+1248,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+736,"refresh_q", false,-1);
    tracep->declBus(c+737,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+738+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+742,"state_q", false,-1, 3,0);
    tracep->declBus(c+320,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+321,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+743,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+744,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+173,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+174,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+175,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+1335,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+745,"delay_q", false,-1, 3,0);
    tracep->declBus(c+322,"delay_r", false,-1, 3,0);
    tracep->declBus(c+1368,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+746,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+747,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+748,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+749,"idx", false,-1, 31,0);
    tracep->declBus(c+750,"rd_q", false,-1, 3,0);
    tracep->declBit(c+711,"ack_q", false,-1);
    tracep->declArray(c+751,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+140,"auto_in_psel", false,-1);
    tracep->declBit(c+49,"auto_in_penable", false,-1);
    tracep->declBit(c+126,"auto_in_pwrite", false,-1);
    tracep->declBus(c+132,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1284,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1251,"auto_in_pready", false,-1);
    tracep->declBit(c+1285,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1252,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+701,"spi_bundle_sck", false,-1);
    tracep->declBus(c+702,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+1244,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+1245,"spi_bundle_miso", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+1324,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+1369,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+1333,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+176,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+140,"in_psel", false,-1);
    tracep->declBit(c+49,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1251,"in_pready", false,-1);
    tracep->declBus(c+1252,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1285,"in_pslverr", false,-1);
    tracep->declBit(c+701,"spi_sck", false,-1);
    tracep->declBus(c+702,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+1244,"spi_mosi", false,-1);
    tracep->declBit(c+1245,"spi_miso", false,-1);
    tracep->declBit(c+754,"spi_irq_out", false,-1);
    tracep->declBus(c+653,"state", false,-1, 2,0);
    tracep->declBit(c+654,"penable", false,-1);
    tracep->declBit(c+177,"is_xip_access", false,-1);
    tracep->declBus(c+655,"xip_paddr", false,-1, 4,0);
    tracep->declBus(c+178,"xip_pwdata", false,-1, 31,0);
    tracep->declBus(c+179,"xip_pstrb", false,-1, 3,0);
    tracep->declBit(c+656,"xip_pwirte", false,-1);
    tracep->declBit(c+755,"apb_pready", false,-1);
    tracep->declBus(c+180,"apb_addr", false,-1, 4,0);
    tracep->declBus(c+181,"apb_pwdata", false,-1, 31,0);
    tracep->declBus(c+179,"apb_pstrb", false,-1, 3,0);
    tracep->declBit(c+182,"apb_penable", false,-1);
    tracep->declBit(c+140,"apb_psel", false,-1);
    tracep->declBit(c+183,"apb_pwrite", false,-1);
    tracep->declBus(c+756,"apb_prdata", false,-1, 31,0);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+1319,"Tp", false,-1, 31,0);
    tracep->declBit(c+1222,"wb_clk_i", false,-1);
    tracep->declBit(c+1223,"wb_rst_i", false,-1);
    tracep->declBus(c+180,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+181,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+756,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+179,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+183,"wb_we_i", false,-1);
    tracep->declBit(c+140,"wb_stb_i", false,-1);
    tracep->declBit(c+182,"wb_cyc_i", false,-1);
    tracep->declBit(c+755,"wb_ack_o", false,-1);
    tracep->declBit(c+1285,"wb_err_o", false,-1);
    tracep->declBit(c+754,"wb_int_o", false,-1);
    tracep->declBus(c+702,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+701,"sclk_pad_o", false,-1);
    tracep->declBit(c+1244,"mosi_pad_o", false,-1);
    tracep->declBit(c+1245,"miso_pad_i", false,-1);
    tracep->declBus(c+757,"divider", false,-1, 15,0);
    tracep->declBus(c+758,"ctrl", false,-1, 13,0);
    tracep->declBus(c+759,"ss", false,-1, 7,0);
    tracep->declBus(c+323,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+760,"rx", false,-1, 127,0);
    tracep->declBit(c+764,"rx_negedge", false,-1);
    tracep->declBit(c+765,"tx_negedge", false,-1);
    tracep->declBus(c+766,"char_len", false,-1, 6,0);
    tracep->declBit(c+767,"go", false,-1);
    tracep->declBit(c+768,"lsb", false,-1);
    tracep->declBit(c+769,"ie", false,-1);
    tracep->declBit(c+770,"ass", false,-1);
    tracep->declBit(c+184,"spi_divider_sel", false,-1);
    tracep->declBit(c+185,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+186,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+187,"spi_ss_sel", false,-1);
    tracep->declBit(c+771,"tip", false,-1);
    tracep->declBit(c+772,"pos_edge", false,-1);
    tracep->declBit(c+773,"neg_edge", false,-1);
    tracep->declBit(c+774,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+1319,"Tp", false,-1, 31,0);
    tracep->declBit(c+1222,"clk_in", false,-1);
    tracep->declBit(c+1223,"rst", false,-1);
    tracep->declBit(c+771,"enable", false,-1);
    tracep->declBit(c+767,"go", false,-1);
    tracep->declBit(c+774,"last_clk", false,-1);
    tracep->declBus(c+757,"divider", false,-1, 15,0);
    tracep->declBit(c+701,"clk_out", false,-1);
    tracep->declBit(c+772,"pos_edge", false,-1);
    tracep->declBit(c+773,"neg_edge", false,-1);
    tracep->declBus(c+775,"cnt", false,-1, 15,0);
    tracep->declBit(c+776,"cnt_zero", false,-1);
    tracep->declBit(c+777,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+1319,"Tp", false,-1, 31,0);
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1223,"rst", false,-1);
    tracep->declBus(c+188,"latch", false,-1, 3,0);
    tracep->declBus(c+179,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+766,"len", false,-1, 6,0);
    tracep->declBit(c+768,"lsb", false,-1);
    tracep->declBit(c+767,"go", false,-1);
    tracep->declBit(c+772,"pos_edge", false,-1);
    tracep->declBit(c+773,"neg_edge", false,-1);
    tracep->declBit(c+764,"rx_negedge", false,-1);
    tracep->declBit(c+765,"tx_negedge", false,-1);
    tracep->declBit(c+771,"tip", false,-1);
    tracep->declBit(c+774,"last", false,-1);
    tracep->declBus(c+181,"p_in", false,-1, 31,0);
    tracep->declArray(c+760,"p_out", false,-1, 127,0);
    tracep->declBit(c+701,"s_clk", false,-1);
    tracep->declBit(c+1245,"s_in", false,-1);
    tracep->declBit(c+1244,"s_out", false,-1);
    tracep->declBus(c+778,"cnt", false,-1, 7,0);
    tracep->declArray(c+760,"data", false,-1, 127,0);
    tracep->declBus(c+779,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+780,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+781,"rx_clk", false,-1);
    tracep->declBit(c+782,"tx_clk", false,-1);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+137,"auto_in_psel", false,-1);
    tracep->declBit(c+138,"auto_in_penable", false,-1);
    tracep->declBit(c+126,"auto_in_pwrite", false,-1);
    tracep->declBus(c+134,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+1284,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+139,"auto_in_pready", false,-1);
    tracep->declBit(c+1285,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1250,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+1242,"uart_rx", false,-1);
    tracep->declBit(c+1243,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+137,"in_psel", false,-1);
    tracep->declBit(c+138,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+139,"in_pready", false,-1);
    tracep->declBit(c+1285,"in_pslverr", false,-1);
    tracep->declBus(c+155,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+1250,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1242,"uart_rx", false,-1);
    tracep->declBit(c+1243,"uart_tx", false,-1);
    tracep->declBit(c+783,"rtsn", false,-1);
    tracep->declBit(c+1285,"ctsn", false,-1);
    tracep->declBit(c+784,"dtr_pad_o", false,-1);
    tracep->declBit(c+1285,"dsr_pad_i", false,-1);
    tracep->declBit(c+1285,"ri_pad_i", false,-1);
    tracep->declBit(c+1285,"dcd_pad_i", false,-1);
    tracep->declBit(c+785,"interrupt", false,-1);
    tracep->declBit(c+189,"reg_we", false,-1);
    tracep->declBit(c+190,"reg_re", false,-1);
    tracep->declBus(c+191,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+192,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+657,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+324,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+786,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1223,"wb_rst_i", false,-1);
    tracep->declBus(c+191,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+193,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+324,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+189,"wb_we_i", false,-1);
    tracep->declBit(c+190,"wb_re_i", false,-1);
    tracep->declBit(c+1243,"stx_pad_o", false,-1);
    tracep->declBit(c+1242,"srx_pad_i", false,-1);
    tracep->declBus(c+1365,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+786,"rts_pad_o", false,-1);
    tracep->declBit(c+784,"dtr_pad_o", false,-1);
    tracep->declBit(c+785,"int_o", false,-1);
    tracep->declBit(c+787,"enable", false,-1);
    tracep->declBit(c+788,"srx_pad", false,-1);
    tracep->declBus(c+789,"ier", false,-1, 3,0);
    tracep->declBus(c+790,"iir", false,-1, 3,0);
    tracep->declBus(c+791,"fcr", false,-1, 1,0);
    tracep->declBus(c+792,"mcr", false,-1, 4,0);
    tracep->declBus(c+793,"lcr", false,-1, 7,0);
    tracep->declBus(c+794,"msr", false,-1, 7,0);
    tracep->declBus(c+795,"dl", false,-1, 15,0);
    tracep->declBus(c+796,"scratch", false,-1, 7,0);
    tracep->declBit(c+797,"start_dlc", false,-1);
    tracep->declBit(c+798,"lsr_mask_d", false,-1);
    tracep->declBit(c+799,"msi_reset", false,-1);
    tracep->declBus(c+800,"dlc", false,-1, 15,0);
    tracep->declBus(c+801,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+802,"rx_reset", false,-1);
    tracep->declBit(c+803,"tx_reset", false,-1);
    tracep->declBit(c+804,"dlab", false,-1);
    tracep->declBit(c+1301,"cts_pad_i", false,-1);
    tracep->declBit(c+1285,"dsr_pad_i", false,-1);
    tracep->declBit(c+1285,"ri_pad_i", false,-1);
    tracep->declBit(c+1285,"dcd_pad_i", false,-1);
    tracep->declBit(c+805,"loopback", false,-1);
    tracep->declBit(c+1285,"cts", false,-1);
    tracep->declBit(c+1301,"dsr", false,-1);
    tracep->declBit(c+1301,"ri", false,-1);
    tracep->declBit(c+1301,"dcd", false,-1);
    tracep->declBit(c+806,"cts_c", false,-1);
    tracep->declBit(c+807,"dsr_c", false,-1);
    tracep->declBit(c+808,"ri_c", false,-1);
    tracep->declBit(c+809,"dcd_c", false,-1);
    tracep->declBus(c+810,"lsr", false,-1, 7,0);
    tracep->declBit(c+811,"lsr0", false,-1);
    tracep->declBit(c+812,"lsr1", false,-1);
    tracep->declBit(c+813,"lsr2", false,-1);
    tracep->declBit(c+814,"lsr3", false,-1);
    tracep->declBit(c+815,"lsr4", false,-1);
    tracep->declBit(c+816,"lsr5", false,-1);
    tracep->declBit(c+817,"lsr6", false,-1);
    tracep->declBit(c+818,"lsr7", false,-1);
    tracep->declBit(c+819,"lsr0r", false,-1);
    tracep->declBit(c+820,"lsr1r", false,-1);
    tracep->declBit(c+821,"lsr2r", false,-1);
    tracep->declBit(c+822,"lsr3r", false,-1);
    tracep->declBit(c+823,"lsr4r", false,-1);
    tracep->declBit(c+824,"lsr5r", false,-1);
    tracep->declBit(c+825,"lsr6r", false,-1);
    tracep->declBit(c+826,"lsr7r", false,-1);
    tracep->declBit(c+325,"lsr_mask", false,-1);
    tracep->declBit(c+827,"rls_int", false,-1);
    tracep->declBit(c+828,"rda_int", false,-1);
    tracep->declBit(c+829,"ti_int", false,-1);
    tracep->declBit(c+830,"thre_int", false,-1);
    tracep->declBit(c+831,"ms_int", false,-1);
    tracep->declBit(c+832,"tf_push", false,-1);
    tracep->declBit(c+833,"rf_pop", false,-1);
    tracep->declBus(c+1274,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+834,"rf_error_bit", false,-1);
    tracep->declBit(c+812,"rf_overrun", false,-1);
    tracep->declBit(c+835,"rf_push_pulse", false,-1);
    tracep->declBus(c+836,"rf_count", false,-1, 4,0);
    tracep->declBus(c+837,"tf_count", false,-1, 4,0);
    tracep->declBus(c+838,"tstate", false,-1, 2,0);
    tracep->declBus(c+839,"rstate", false,-1, 3,0);
    tracep->declBus(c+840,"counter_t", false,-1, 9,0);
    tracep->declBit(c+841,"thre_set_en", false,-1);
    tracep->declBus(c+842,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+843,"block_value", false,-1, 7,0);
    tracep->declBit(c+844,"serial_out", false,-1);
    tracep->declBit(c+845,"serial_in", false,-1);
    tracep->declBit(c+326,"lsr_mask_condition", false,-1);
    tracep->declBit(c+327,"iir_read", false,-1);
    tracep->declBit(c+328,"msr_read", false,-1);
    tracep->declBit(c+329,"fifo_read", false,-1);
    tracep->declBit(c+330,"fifo_write", false,-1);
    tracep->declBus(c+846,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+847,"lsr0_d", false,-1);
    tracep->declBit(c+848,"lsr1_d", false,-1);
    tracep->declBit(c+849,"lsr2_d", false,-1);
    tracep->declBit(c+850,"lsr3_d", false,-1);
    tracep->declBit(c+851,"lsr4_d", false,-1);
    tracep->declBit(c+852,"lsr5_d", false,-1);
    tracep->declBit(c+853,"lsr6_d", false,-1);
    tracep->declBit(c+854,"lsr7_d", false,-1);
    tracep->declBit(c+855,"rls_int_d", false,-1);
    tracep->declBit(c+856,"thre_int_d", false,-1);
    tracep->declBit(c+857,"ms_int_d", false,-1);
    tracep->declBit(c+858,"ti_int_d", false,-1);
    tracep->declBit(c+859,"rda_int_d", false,-1);
    tracep->declBit(c+860,"rls_int_rise", false,-1);
    tracep->declBit(c+861,"thre_int_rise", false,-1);
    tracep->declBit(c+862,"ms_int_rise", false,-1);
    tracep->declBit(c+863,"ti_int_rise", false,-1);
    tracep->declBit(c+864,"rda_int_rise", false,-1);
    tracep->declBit(c+865,"rls_int_pnd", false,-1);
    tracep->declBit(c+866,"rda_int_pnd", false,-1);
    tracep->declBit(c+867,"thre_int_pnd", false,-1);
    tracep->declBit(c+868,"ms_int_pnd", false,-1);
    tracep->declBit(c+869,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+1319,"Tp", false,-1, 31,0);
    tracep->declBus(c+1319,"width", false,-1, 31,0);
    tracep->declBus(c+1345,"init_value", false,-1, 0,0);
    tracep->declBit(c+1223,"rst_i", false,-1);
    tracep->declBit(c+1222,"clk_i", false,-1);
    tracep->declBit(c+1285,"stage1_rst_i", false,-1);
    tracep->declBit(c+1301,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+1242,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+788,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+870,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1223,"wb_rst_i", false,-1);
    tracep->declBus(c+793,"lcr", false,-1, 7,0);
    tracep->declBit(c+833,"rf_pop", false,-1);
    tracep->declBit(c+845,"srx_pad_i", false,-1);
    tracep->declBit(c+787,"enable", false,-1);
    tracep->declBit(c+802,"rx_reset", false,-1);
    tracep->declBit(c+325,"lsr_mask", false,-1);
    tracep->declBus(c+840,"counter_t", false,-1, 9,0);
    tracep->declBus(c+836,"rf_count", false,-1, 4,0);
    tracep->declBus(c+1274,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+812,"rf_overrun", false,-1);
    tracep->declBit(c+834,"rf_error_bit", false,-1);
    tracep->declBus(c+839,"rstate", false,-1, 3,0);
    tracep->declBit(c+835,"rf_push_pulse", false,-1);
    tracep->declBus(c+871,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+872,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+873,"rshift", false,-1, 7,0);
    tracep->declBit(c+874,"rparity", false,-1);
    tracep->declBit(c+875,"rparity_error", false,-1);
    tracep->declBit(c+876,"rframing_error", false,-1);
    tracep->declBit(c+877,"rbit_in", false,-1);
    tracep->declBit(c+878,"rparity_xor", false,-1);
    tracep->declBus(c+879,"counter_b", false,-1, 7,0);
    tracep->declBit(c+880,"rf_push_q", false,-1);
    tracep->declBus(c+881,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+882,"rf_push", false,-1);
    tracep->declBit(c+883,"break_error", false,-1);
    tracep->declBit(c+884,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+885,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+886,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+887,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+1304,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+1338,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+1363,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+1359,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+1361,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+1360,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+1362,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+1358,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+1365,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+1366,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+1370,"sr_push", false,-1, 3,0);
    tracep->declBus(c+888,"toc_value", false,-1, 9,0);
    tracep->declBus(c+889,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+1371,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1334,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1335,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1341,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1223,"wb_rst_i", false,-1);
    tracep->declBit(c+835,"push", false,-1);
    tracep->declBit(c+833,"pop", false,-1);
    tracep->declBus(c+881,"data_in", false,-1, 10,0);
    tracep->declBit(c+802,"fifo_reset", false,-1);
    tracep->declBit(c+325,"reset_status", false,-1);
    tracep->declBus(c+1274,"data_out", false,-1, 10,0);
    tracep->declBit(c+812,"overrun", false,-1);
    tracep->declBus(c+836,"count", false,-1, 4,0);
    tracep->declBit(c+834,"error_bit", false,-1);
    tracep->declBus(c+1275,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+890+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+906,"top", false,-1, 3,0);
    tracep->declBus(c+907,"bottom", false,-1, 3,0);
    tracep->declBus(c+908,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+909,"word0", false,-1, 2,0);
    tracep->declBus(c+910,"word1", false,-1, 2,0);
    tracep->declBus(c+911,"word2", false,-1, 2,0);
    tracep->declBus(c+912,"word3", false,-1, 2,0);
    tracep->declBus(c+913,"word4", false,-1, 2,0);
    tracep->declBus(c+914,"word5", false,-1, 2,0);
    tracep->declBus(c+915,"word6", false,-1, 2,0);
    tracep->declBus(c+916,"word7", false,-1, 2,0);
    tracep->declBus(c+917,"word8", false,-1, 2,0);
    tracep->declBus(c+918,"word9", false,-1, 2,0);
    tracep->declBus(c+919,"word10", false,-1, 2,0);
    tracep->declBus(c+920,"word11", false,-1, 2,0);
    tracep->declBus(c+921,"word12", false,-1, 2,0);
    tracep->declBus(c+922,"word13", false,-1, 2,0);
    tracep->declBus(c+923,"word14", false,-1, 2,0);
    tracep->declBus(c+924,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+1335,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1333,"data_width", false,-1, 31,0);
    tracep->declBus(c+1334,"depth", false,-1, 31,0);
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+835,"we", false,-1);
    tracep->declBus(c+906,"a", false,-1, 3,0);
    tracep->declBus(c+907,"dpra", false,-1, 3,0);
    tracep->declBus(c+925,"di", false,-1, 7,0);
    tracep->declBus(c+1275,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+658+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1223,"wb_rst_i", false,-1);
    tracep->declBus(c+793,"lcr", false,-1, 7,0);
    tracep->declBit(c+832,"tf_push", false,-1);
    tracep->declBus(c+193,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+787,"enable", false,-1);
    tracep->declBit(c+803,"tx_reset", false,-1);
    tracep->declBit(c+325,"lsr_mask", false,-1);
    tracep->declBit(c+844,"stx_pad_o", false,-1);
    tracep->declBus(c+838,"tstate", false,-1, 2,0);
    tracep->declBus(c+837,"tf_count", false,-1, 4,0);
    tracep->declBus(c+926,"counter", false,-1, 4,0);
    tracep->declBus(c+927,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+928,"shift_out", false,-1, 6,0);
    tracep->declBit(c+929,"stx_o_tmp", false,-1);
    tracep->declBit(c+930,"parity_xor", false,-1);
    tracep->declBit(c+931,"tf_pop", false,-1);
    tracep->declBit(c+932,"bit_out", false,-1);
    tracep->declBus(c+193,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+1276,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+933,"tf_overrun", false,-1);
    tracep->declBus(c+1305,"s_idle", false,-1, 2,0);
    tracep->declBus(c+1284,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+1372,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+1373,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+1346,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+1374,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+1333,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+1334,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+1335,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+1341,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+1223,"wb_rst_i", false,-1);
    tracep->declBit(c+832,"push", false,-1);
    tracep->declBit(c+931,"pop", false,-1);
    tracep->declBus(c+193,"data_in", false,-1, 7,0);
    tracep->declBit(c+803,"fifo_reset", false,-1);
    tracep->declBit(c+325,"reset_status", false,-1);
    tracep->declBus(c+1276,"data_out", false,-1, 7,0);
    tracep->declBit(c+933,"overrun", false,-1);
    tracep->declBus(c+837,"count", false,-1, 4,0);
    tracep->declBus(c+934,"top", false,-1, 3,0);
    tracep->declBus(c+935,"bottom", false,-1, 3,0);
    tracep->declBus(c+936,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+1335,"addr_width", false,-1, 31,0);
    tracep->declBus(c+1333,"data_width", false,-1, 31,0);
    tracep->declBus(c+1334,"depth", false,-1, 31,0);
    tracep->declBit(c+1222,"clk", false,-1);
    tracep->declBit(c+832,"we", false,-1);
    tracep->declBus(c+934,"a", false,-1, 3,0);
    tracep->declBus(c+935,"dpra", false,-1, 3,0);
    tracep->declBus(c+193,"di", false,-1, 7,0);
    tracep->declBus(c+1276,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+674+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(6);
    tracep->pushNamePrefix("lvga ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBit(c+131,"auto_in_psel", false,-1);
    tracep->declBit(c+45,"auto_in_penable", false,-1);
    tracep->declBit(c+126,"auto_in_pwrite", false,-1);
    tracep->declBus(c+132,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+1284,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+127,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1286,"auto_in_pready", false,-1);
    tracep->declBit(c+1287,"auto_in_pslverr", false,-1);
    tracep->declBus(c+1288,"auto_in_prdata", false,-1, 31,0);
    tracep->declBus(c+1236,"vga_bundle_r", false,-1, 7,0);
    tracep->declBus(c+1237,"vga_bundle_g", false,-1, 7,0);
    tracep->declBus(c+1238,"vga_bundle_b", false,-1, 7,0);
    tracep->declBit(c+1239,"vga_bundle_hsync", false,-1);
    tracep->declBit(c+1240,"vga_bundle_vsync", false,-1);
    tracep->declBit(c+1241,"vga_bundle_valid", false,-1);
    tracep->pushNamePrefix("mvga ");
    tracep->declBit(c+1222,"clock", false,-1);
    tracep->declBit(c+1223,"reset", false,-1);
    tracep->declBus(c+176,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+131,"in_psel", false,-1);
    tracep->declBit(c+45,"in_penable", false,-1);
    tracep->declBus(c+1284,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+126,"in_pwrite", false,-1);
    tracep->declBus(c+127,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+128,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+1286,"in_pready", false,-1);
    tracep->declBus(c+1288,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+1287,"in_pslverr", false,-1);
    tracep->declBus(c+1236,"vga_r", false,-1, 7,0);
    tracep->declBus(c+1237,"vga_g", false,-1, 7,0);
    tracep->declBus(c+1238,"vga_b", false,-1, 7,0);
    tracep->declBit(c+1239,"vga_hsync", false,-1);
    tracep->declBit(c+1240,"vga_vsync", false,-1);
    tracep->declBit(c+1241,"vga_valid", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+701,"sck", false,-1);
    tracep->declBit(c+1277,"ss", false,-1);
    tracep->declBit(c+1244,"mosi", false,-1);
    tracep->declBit(c+1278,"miso", false,-1);
    tracep->declBus(c+1035,"buffer", false,-1, 7,0);
    tracep->declBus(c+1036,"count", false,-1, 2,0);
    tracep->declBus(c+1037,"state", false,-1, 1,0);
    tracep->declBit(c+1038,"buffer_out", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+701,"sck", false,-1);
    tracep->declBit(c+937,"ss", false,-1);
    tracep->declBit(c+1244,"mosi", false,-1);
    tracep->declBit(c+1279,"miso", false,-1);
    tracep->declBit(c+937,"reset", false,-1);
    tracep->declBus(c+1029,"state", false,-1, 2,0);
    tracep->declBus(c+1030,"counter", false,-1, 7,0);
    tracep->declBus(c+1031,"cmd", false,-1, 7,0);
    tracep->declBus(c+1032,"addr", false,-1, 23,0);
    tracep->declBus(c+1033,"data", false,-1, 31,0);
    tracep->declBit(c+1034,"ren", false,-1);
    tracep->declBus(c+1280,"rdata", false,-1, 31,0);
    tracep->declBus(c+1281,"raddr", false,-1, 31,0);
    tracep->declBus(c+1282,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+701,"clock", false,-1);
    tracep->declBit(c+1034,"valid", false,-1);
    tracep->declBus(c+1031,"cmd", false,-1, 7,0);
    tracep->declBus(c+1281,"addr", false,-1, 31,0);
    tracep->declBus(c+1280,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("psram ");
    tracep->declBit(c+194,"sck", false,-1);
    tracep->declBit(c+195,"ce_n", false,-1);
    tracep->declBus(c+1246,"dio", false,-1, 3,0);
    tracep->declBus(c+690,"state", false,-1, 3,0);
    tracep->declBus(c+691,"inst_buffer", false,-1, 7,0);
    tracep->declBus(c+692,"addr_buffer", false,-1, 23,0);
    tracep->declBus(c+693,"inst_counter", false,-1, 2,0);
    tracep->declBus(c+694,"addr_counter", false,-1, 2,0);
    tracep->declBus(c+695,"wait_counter", false,-1, 2,0);
    tracep->declBus(c+696,"data", false,-1, 7,0);
    tracep->declBit(c+697,"finish", false,-1);
    tracep->declBus(c+698,"dio_out_reg", false,-1, 3,0);
    tracep->declBit(c+699,"dio_en", false,-1);
    tracep->declBit(c+700,"qpi_mode", false,-1);
    tracep->declBit(c+195,"reset", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+1247,"clk", false,-1);
    tracep->declBit(c+703,"cke", false,-1);
    tracep->declBit(c+704,"cs", false,-1);
    tracep->declBit(c+705,"ras", false,-1);
    tracep->declBit(c+706,"cas", false,-1);
    tracep->declBit(c+707,"we", false,-1);
    tracep->declBus(c+708,"a", false,-1, 12,0);
    tracep->declBus(c+709,"ba", false,-1, 1,0);
    tracep->declBus(c+710,"dqm", false,-1, 1,0);
    tracep->declBus(c+1248,"dq", false,-1, 15,0);
    tracep->declBus(c+1375,"mode_q", false,-1, 12,0);
    tracep->declBus(c+1376,"row", false,-1, 12,0);
    tracep->declBit(c+704,"command_inhibit", false,-1);
    tracep->declBit(c+938,"no_operation", false,-1);
    tracep->declBit(c+939,"active", false,-1);
    tracep->declBit(c+940,"read", false,-1);
    tracep->declBit(c+941,"write", false,-1);
    tracep->declBit(c+942,"burst_terminate", false,-1);
    tracep->declBit(c+943,"precharge", false,-1);
    tracep->declBit(c+944,"auto_refresh", false,-1);
    tracep->declBit(c+945,"load_mode_register", false,-1);
    tracep->declBit(c+946,"nop", false,-1);
    tracep->declBus(c+1327,"CAS_TIMER_W", false,-1, 31,0);
    tracep->declBus(c+331,"cas_timer_q", false,-1, 2,0);
    tracep->declBit(c+332,"cas_done", false,-1);
    tracep->declBit(c+333,"counting", false,-1);
    tracep->declBit(c+1377,"cas_start", false,-1);
    tracep->declBus(c+1327,"BL_TIMER_W", false,-1, 31,0);
    tracep->declBus(c+334,"bl_timer_q", false,-1, 2,0);
    tracep->declBit(c+335,"bl_valid", false,-1);
    tracep->declBit(c+1378,"bl_start", false,-1);
    tracep->declBit(c+336,"bl_done", false,-1);
    tracep->declBus(c+1325,"MAX_PIPELINE", false,-1, 31,0);
    tracep->declBus(c+337,"rd_pip_in_addr_q", false,-1, 12,0);
    tracep->declBit(c+338,"rd_pip_in_val_q", false,-1);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+339+i*1,"pip_addr_q", true,(i+0), 12,0);
    }
    for (int i = 0; i < 6; ++i) {
        tracep->declBit(c+345+i*1,"pip_valid_q", true,(i+0));
    }
    tracep->declBus(c+351,"data_output", false,-1, 15,0);
    tracep->declBus(c+1379,"pipeline_cl", false,-1, 2,0);
    tracep->declBus(c+352,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBus(c+1379,"cl", false,-1, 2,0);
    tracep->declBus(c+353,"select_bank", false,-1, 1,0);
    tracep->declBus(c+354,"select_col", false,-1, 9,0);
    tracep->declBit(c+355,"select_valid", false,-1);
    tracep->declBus(c+356,"dqm_pipe", false,-1, 3,0);
    tracep->declBus(c+357,"rd_dqm_out_q", false,-1, 1,0);
    tracep->declBit(c+358,"read_state_r", false,-1);
    tracep->declBus(c+1248,"sdram_data", false,-1, 15,0);
    tracep->declBus(c+359,"wr_in_addr_q", false,-1, 12,0);
    tracep->declBit(c+360,"wr_in_val_q", false,-1);
    tracep->declBus(c+1304,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+1338,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+1363,"STATE_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+1359,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+1361,"STATE_READ_DATA", false,-1, 3,0);
    tracep->declBus(c+1362,"STATE_WRITE", false,-1, 3,0);
    tracep->declBus(c+1358,"STATE_WRITE_DATA", false,-1, 3,0);
    tracep->declBus(c+1366,"STATE_MODE_REG", false,-1, 3,0);
    tracep->declBus(c+361,"state_current_q", false,-1, 3,0);
    tracep->declBus(c+1039,"state_next_r", false,-1, 3,0);
    tracep->declBit(c+1283,"valclk", false,-1);
    tracep->declBus(c+362,"prev_addr_q", false,-1, 12,0);
    tracep->declBus(c+947,"cur_addr_r", false,-1, 12,0);
    tracep->declBus(c+363,"cur_addr_b_r", false,-1, 12,0);
    tracep->declBus(c+1040,"rd_pip_in_addr_r", false,-1, 12,0);
    tracep->declBit(c+364,"rd_pip_in_val_r", false,-1);
    tracep->declBus(c+1041,"wr_in_addr_r", false,-1, 12,0);
    tracep->declBit(c+365,"wr_in_val_r", false,-1);
    tracep->declBit(c+366,"sig_save_addr_direct", false,-1);
    tracep->declBit(c+366,"sig_save_addr_inc", false,-1);
    tracep->pushNamePrefix("decoder ");
    tracep->declBit(c+704,"cs_n", false,-1);
    tracep->declBit(c+705,"ras_n", false,-1);
    tracep->declBit(c+706,"cas_n", false,-1);
    tracep->declBit(c+707,"we_n", false,-1);
    tracep->declBit(c+704,"command_inhibit", false,-1);
    tracep->declBit(c+938,"no_operation", false,-1);
    tracep->declBit(c+939,"active", false,-1);
    tracep->declBit(c+940,"read", false,-1);
    tracep->declBit(c+941,"write", false,-1);
    tracep->declBit(c+942,"burst_terminate", false,-1);
    tracep->declBit(c+943,"precharge", false,-1);
    tracep->declBit(c+944,"auto_refresh", false,-1);
    tracep->declBit(c+945,"load_mode_register", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+367,"i", false,-1, 31,0);
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
    bufp->fullIData(oldp+51,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata
                                : 0U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r
                                           : 0U) | 
                                         ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                           ? vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata
                                           : 0U)))),32);
    bufp->fullBit(oldp+52,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+53,((1U & ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last) 
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
    bufp->fullBit(oldp+54,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+55,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+56,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+57,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+58,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+60,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+62,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+63,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+65,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+66,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+68,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+69,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+70,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+71,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+72,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+73,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+74,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+75,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+76,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+77,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+78,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+79,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
                            & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)))));
    bufp->fullBit(oldp+80,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+81,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+82,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+83,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+84,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullBit(oldp+85,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
                            & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)))));
    bufp->fullCData(oldp+86,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                              & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid))))),2);
    bufp->fullBit(oldp+87,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant) 
                                   & (- (IData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid)))) 
                                  >> 1U))));
    bufp->fullBit(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awvalid));
    bufp->fullBit(oldp+89,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wvalid));
    bufp->fullBit(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arvalid));
    bufp->fullBit(oldp+91,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready));
    bufp->fullBit(oldp+92,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid));
    bufp->fullBit(oldp+93,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid));
    bufp->fullBit(oldp+94,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))));
    bufp->fullBit(oldp+95,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid));
    bufp->fullSData(oldp+97,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo),9);
    bufp->fullBit(oldp+98,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+99,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+100,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_awvalid));
    bufp->fullBit(oldp+101,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid));
    bufp->fullBit(oldp+102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid));
    bufp->fullBit(oldp+103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid));
    bufp->fullBit(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid));
    bufp->fullBit(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__io_deq_valid_0));
    bufp->fullBit(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
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
    bufp->fullWData(oldp+107,(__Vtemp_h3a4ae3bd__0),140);
    bufp->fullQData(oldp+112,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullIData(oldp+120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr));
    bufp->fullBit(oldp+130,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+131,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+132,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+133,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullIData(oldp+134,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+135,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+136,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel));
    bufp->fullBit(oldp+137,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+138,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullBit(oldp+139,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullBit(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_psel));
    bufp->fullBit(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullBit(oldp+144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_3));
    bufp->fullBit(oldp+145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_4));
    bufp->fullBit(oldp+146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_5));
    bufp->fullBit(oldp+147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_6));
    bufp->fullBit(oldp+148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+149,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid));
    bufp->fullBit(oldp+150,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid));
    bufp->fullBit(oldp+151,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+152,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid));
    bufp->fullCData(oldp+153,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                               << 1U)),2);
    bufp->fullBit(oldp+154,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid));
    bufp->fullIData(oldp+155,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+156,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T));
    bufp->fullIData(oldp+157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata),32);
    bufp->fullBit(oldp+158,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we));
    bufp->fullBit(oldp+159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_re));
    bufp->fullCData(oldp+160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size),3);
    bufp->fullCData(oldp+161,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0),8);
    bufp->fullCData(oldp+162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1),8);
    bufp->fullCData(oldp+163,((0xffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+164,((vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w 
                               >> 0x18U)),8);
    bufp->fullIData(oldp+165,(((0xffff0000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w) 
                               | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte1) 
                                   << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__byte0)))),32);
    bufp->fullIData(oldp+166,((0xfffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullIData(oldp+167,((0xffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),24);
    bufp->fullCData(oldp+168,((0xffU & ((IData)(0xdU) 
                                        + ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__size) 
                                           << 1U)))),8);
    bufp->fullBit(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_rd_w));
    bufp->fullBit(oldp+170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+173,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+174,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+175,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+176,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullBit(oldp+177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__is_xip_access));
    bufp->fullIData(oldp+178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pwdata),32);
    bufp->fullCData(oldp+179,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__xip_pstrb),4);
    bufp->fullCData(oldp+180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr),5);
    bufp->fullIData(oldp+181,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwdata),32);
    bufp->fullBit(oldp+182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_penable));
    bufp->fullBit(oldp+183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pwrite));
    bufp->fullBit(oldp+184,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x14U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullBit(oldp+185,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x10U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+186,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__spi_tx_sel),4);
    bufp->fullBit(oldp+187,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (0x18U == (0x1cU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_addr))))));
    bufp->fullCData(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullBit(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+190,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullCData(oldp+191,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in),8);
    bufp->fullBit(oldp+194,(vlSelf->ysyxSoCFull__DOT___asic_psram_sck));
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__psram__DOT__reset));
    bufp->fullBit(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready));
    bufp->fullBit(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullIData(oldp+202,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_in_rdata),32);
    bufp->fullBit(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bvalid));
    bufp->fullCData(oldp+204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9),4);
    bufp->fullCData(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bresp),2);
    bufp->fullBit(oldp+206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid));
    bufp->fullCData(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20),4);
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready));
    bufp->fullBit(oldp+210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
    bufp->fullCData(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp),2);
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last));
    bufp->fullBit(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready));
    bufp->fullBit(oldp+215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5));
    bufp->fullBit(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready));
    bufp->fullBit(oldp+217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready));
    bufp->fullBit(oldp+218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq));
    bufp->fullBit(oldp+219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready));
    bufp->fullBit(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq));
    bufp->fullBit(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready));
    bufp->fullBit(oldp+222,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_awready));
    bufp->fullBit(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready));
    bufp->fullBit(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__nodeIn_arready));
    bufp->fullBit(oldp+226,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready));
    bufp->fullBit(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren));
    bufp->fullBit(oldp+228,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en));
    bufp->fullBit(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anonIn_awready));
    bufp->fullBit(oldp+230,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_arready));
    bufp->fullBit(oldp+231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wready));
    bufp->fullBit(oldp+232,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready));
    bufp->fullBit(oldp+233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid));
    bufp->fullCData(oldp+234,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid),3);
    bufp->fullCData(oldp+235,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys),3);
    bufp->fullBit(oldp+236,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1));
    bufp->fullBit(oldp+237,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1));
    bufp->fullBit(oldp+238,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2));
    bufp->fullBit(oldp+239,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0));
    bufp->fullBit(oldp+240,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_1));
    bufp->fullBit(oldp+241,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2));
    bufp->fullBit(oldp+242,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1));
    bufp->fullCData(oldp+243,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1),3);
    bufp->fullCData(oldp+244,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1),3);
    bufp->fullBit(oldp+245,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0));
    bufp->fullBit(oldp+246,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2));
    bufp->fullBit(oldp+247,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_0));
    bufp->fullBit(oldp+248,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_4_2));
    bufp->fullBit(oldp+249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_deq_ready));
    bufp->fullBit(oldp+250,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq));
    bufp->fullBit(oldp+251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq));
    bufp->fullBit(oldp+252,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+253,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+254,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+255,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+256,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+257,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+258,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+259,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+260,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+261,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+262,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+263,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+264,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+265,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+266,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+267,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+268,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+269,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+270,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+271,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xaU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+272,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xbU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+273,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xcU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+274,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xdU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+275,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+276,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xeU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+277,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                             & (0xfU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_bT_9)))));
    bufp->fullBit(oldp+278,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+279,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+280,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+281,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+282,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+283,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                             & ((9U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_20)) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___in_0_rT_5)))));
    bufp->fullBit(oldp+284,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid))));
    bufp->fullIData(oldp+285,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [0U]),32);
    bufp->fullIData(oldp+286,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regwrite),32);
    bufp->fullCData(oldp+287,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid),2);
    bufp->fullIData(oldp+288,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[0]),32);
    bufp->fullIData(oldp+289,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata[1]),32);
    bufp->fullCData(oldp+290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[0]),2);
    bufp->fullCData(oldp+291,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp[1]),2);
    bufp->fullIData(oldp+292,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[0]),32);
    bufp->fullIData(oldp+293,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__rdata[1]),32);
    bufp->fullCData(oldp+294,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[0]),2);
    bufp->fullCData(oldp+295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__arviter0__bresp[1]),2);
    bufp->fullIData(oldp+296,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__reg_write_data),32);
    bufp->fullCData(oldp+297,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bresp
                              [1U]),2);
    bufp->fullBit(oldp+298,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                   >> 1U))));
    bufp->fullIData(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                              [1U]),32);
    bufp->fullIData(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memread),32);
    bufp->fullIData(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_u),32);
    bufp->fullIData(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__read_s),32);
    bufp->fullIData(oldp+303,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data))),32);
    bufp->fullIData(oldp+304,((((- (IData)((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data))),32);
    bufp->fullCData(oldp+305,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__byte_data),8);
    bufp->fullSData(oldp+306,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__memreadlen0__DOT__halfword_data),16);
    bufp->fullSData(oldp+307,((0xffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),16);
    bufp->fullCData(oldp+308,((0xffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                               [1U])),8);
    bufp->fullIData(oldp+309,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+310,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+311,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__dout),4);
    bufp->fullCData(oldp+312,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__douten),4);
    bufp->fullCData(oldp+313,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_dout),4);
    bufp->fullBit(oldp+314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_rd));
    bufp->fullBit(oldp+315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_wr));
    bufp->fullBit(oldp+316,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done));
    bufp->fullBit(oldp+317,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__nstate));
    bufp->fullBit(oldp+318,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__nstate));
    bufp->fullBit(oldp+319,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__nstate));
    bufp->fullCData(oldp+320,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+321,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+322,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullIData(oldp+323,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+324,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullBit(oldp+325,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+326,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+327,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullCData(oldp+331,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_timer_q),3);
    bufp->fullBit(oldp+332,(((0U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_timer_q)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__counting))));
    bufp->fullBit(oldp+333,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__counting));
    bufp->fullCData(oldp+334,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_timer_q),3);
    bufp->fullBit(oldp+335,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_valid));
    bufp->fullBit(oldp+336,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_done));
    bufp->fullSData(oldp+337,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_addr_q),13);
    bufp->fullBit(oldp+338,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_val_q));
    bufp->fullSData(oldp+339,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[0]),13);
    bufp->fullSData(oldp+340,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[1]),13);
    bufp->fullSData(oldp+341,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[2]),13);
    bufp->fullSData(oldp+342,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[3]),13);
    bufp->fullSData(oldp+343,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[4]),13);
    bufp->fullSData(oldp+344,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_addr_q[5]),13);
    bufp->fullBit(oldp+345,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[0]));
    bufp->fullBit(oldp+346,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[1]));
    bufp->fullBit(oldp+347,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[2]));
    bufp->fullBit(oldp+348,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[3]));
    bufp->fullBit(oldp+349,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[4]));
    bufp->fullBit(oldp+350,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__pip_valid_q[5]));
    bufp->fullSData(oldp+351,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__select_valid)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__sdram_data_input_i)
                                : 0U)),16);
    bufp->fullSData(oldp+352,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__sdram_data_input_i),16);
    bufp->fullCData(oldp+353,((3U & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h13016ac7__0) 
                                     >> 0xbU))),2);
    bufp->fullSData(oldp+354,((0x3ffU & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h13016ac7__0))),10);
    bufp->fullBit(oldp+355,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__select_valid));
    bufp->fullCData(oldp+356,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__dqm_pipe),4);
    bufp->fullCData(oldp+357,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_dqm_out_q),2);
    bufp->fullBit(oldp+358,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)) 
                             | (4U == (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q)))));
    bufp->fullSData(oldp+359,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_addr_q),13);
    bufp->fullBit(oldp+360,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_val_q));
    bufp->fullCData(oldp+361,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_current_q),4);
    bufp->fullSData(oldp+362,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__prev_addr_q),13);
    bufp->fullSData(oldp+363,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cur_addr_b_r),13);
    bufp->fullBit(oldp+364,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_val_r));
    bufp->fullBit(oldp+365,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_val_r));
    bufp->fullBit(oldp+366,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__sig_save_addr_direct));
    bufp->fullIData(oldp+367,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+368,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullIData(oldp+369,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                [3U] << 0x18U) | ((
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                                     [0U])))),32);
    bufp->fullCData(oldp+370,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid),4);
    bufp->fullCData(oldp+371,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+372,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid),4);
    bufp->fullCData(oldp+373,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+374,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+375,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+377,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+378,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+379,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+382,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full)))));
    bufp->fullBit(oldp+383,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+384,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)))));
    bufp->fullBit(oldp+385,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))))));
    bufp->fullBit(oldp+386,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))))));
    bufp->fullBit(oldp+387,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))));
    bufp->fullBit(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy));
    bufp->fullIData(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr),32);
    bufp->fullCData(oldp+390,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len),8);
    bufp->fullCData(oldp+391,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len),8);
    bufp->fullBit(oldp+392,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1));
    bufp->fullIData(oldp+393,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1),32);
    bufp->fullCData(oldp+394,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1),8);
    bufp->fullCData(oldp+395,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1),8);
    bufp->fullBit(oldp+396,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    bufp->fullSData(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter),9);
    bufp->fullCData(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0),2);
    bufp->fullCData(oldp+399,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1),2);
    bufp->fullCData(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2),2);
    bufp->fullCData(oldp+401,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3),2);
    bufp->fullCData(oldp+402,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4),2);
    bufp->fullCData(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5),2);
    bufp->fullCData(oldp+404,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6),2);
    bufp->fullCData(oldp+405,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7),2);
    bufp->fullCData(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8),2);
    bufp->fullCData(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9),2);
    bufp->fullCData(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10),2);
    bufp->fullCData(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11),2);
    bufp->fullCData(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12),2);
    bufp->fullCData(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13),2);
    bufp->fullCData(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14),2);
    bufp->fullCData(oldp+413,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15),2);
    bufp->fullCData(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len),8);
    bufp->fullCData(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst),2);
    bufp->fullQData(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram),49);
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full));
    bufp->fullCData(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len),8);
    bufp->fullQData(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram),49);
    bufp->fullBit(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full));
    bufp->fullBit(oldp+423,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)
                                    ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                               >> 0x24U))
                                    : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast)))));
    bufp->fullQData(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram),37);
    bufp->fullBit(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full));
    bufp->fullBit(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full));
    bufp->fullCData(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id),4);
    bufp->fullCData(oldp+429,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full));
    bufp->fullCData(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id),4);
    bufp->fullIData(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4ram_auto_in_rdata),32);
    bufp->fullCData(oldp+433,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                ? 0U : 3U)),2);
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1));
    bufp->fullBit(oldp+435,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1));
    bufp->fullBit(oldp+436,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG));
    bufp->fullCData(oldp+437,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0),8);
    bufp->fullCData(oldp+438,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1),8);
    bufp->fullCData(oldp+439,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2),8);
    bufp->fullCData(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3),8);
    bufp->fullIData(oldp+441,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data),32);
    bufp->fullBit(oldp+442,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))));
    bufp->fullBit(oldp+443,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state));
    bufp->fullCData(oldp+444,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r),4);
    bufp->fullIData(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count));
    bufp->fullBit(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count));
    bufp->fullBit(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count));
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count));
    bufp->fullBit(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count));
    bufp->fullBit(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count));
    bufp->fullBit(oldp+452,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count));
    bufp->fullBit(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count));
    bufp->fullBit(oldp+454,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count));
    bufp->fullBit(oldp+455,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count));
    bufp->fullBit(oldp+456,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count));
    bufp->fullBit(oldp+457,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count));
    bufp->fullBit(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count));
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count));
    bufp->fullBit(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count));
    bufp->fullBit(oldp+461,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count));
    bufp->fullBit(oldp+462,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count));
    bufp->fullBit(oldp+463,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count));
    bufp->fullBit(oldp+464,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count));
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count));
    bufp->fullBit(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count));
    bufp->fullBit(oldp+468,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count));
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count));
    bufp->fullBit(oldp+472,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count));
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count));
    bufp->fullBit(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count));
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched));
    bufp->fullBit(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3));
    bufp->fullCData(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask),3);
    bufp->fullBit(oldp+481,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0));
    bufp->fullBit(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1));
    bufp->fullBit(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2));
    bufp->fullBit(oldp+484,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4));
    bufp->fullCData(oldp+485,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1),3);
    bufp->fullBit(oldp+486,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0));
    bufp->fullBit(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2));
    bufp->fullBit(oldp+488,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)))));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap));
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    bufp->fullBit(oldp+491,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    bufp->fullBit(oldp+492,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty));
    bufp->fullBit(oldp+494,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full));
    bufp->fullCData(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1]),3);
    bufp->fullCData(oldp+496,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[0]),3);
    bufp->fullCData(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[1]),3);
    bufp->fullBit(oldp+498,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    bufp->fullBit(oldp+499,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full));
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last));
    bufp->fullBit(oldp+501,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+502,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))));
    bufp->fullBit(oldp+503,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full));
    bufp->fullBit(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last));
    bufp->fullBit(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+506,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))));
    bufp->fullBit(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full));
    bufp->fullBit(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last));
    bufp->fullBit(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+510,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))));
    bufp->fullBit(oldp+511,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full));
    bufp->fullBit(oldp+512,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last));
    bufp->fullBit(oldp+513,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+514,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))));
    bufp->fullBit(oldp+515,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full));
    bufp->fullBit(oldp+516,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last));
    bufp->fullBit(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+518,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full));
    bufp->fullBit(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last));
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+522,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))));
    bufp->fullBit(oldp+523,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full));
    bufp->fullBit(oldp+524,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last));
    bufp->fullBit(oldp+525,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+526,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))));
    bufp->fullBit(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full));
    bufp->fullBit(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last));
    bufp->fullBit(oldp+529,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+530,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    bufp->fullBit(oldp+531,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full));
    bufp->fullBit(oldp+532,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last));
    bufp->fullBit(oldp+533,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+534,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))));
    bufp->fullBit(oldp+535,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full));
    bufp->fullBit(oldp+536,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last));
    bufp->fullBit(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+538,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))));
    bufp->fullBit(oldp+539,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full));
    bufp->fullBit(oldp+540,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last));
    bufp->fullBit(oldp+541,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+542,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))));
    bufp->fullBit(oldp+543,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full));
    bufp->fullBit(oldp+544,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last));
    bufp->fullBit(oldp+545,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+546,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))));
    bufp->fullBit(oldp+547,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full));
    bufp->fullBit(oldp+548,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last));
    bufp->fullBit(oldp+549,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+550,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))));
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full));
    bufp->fullBit(oldp+552,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+554,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))));
    bufp->fullBit(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full));
    bufp->fullBit(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last));
    bufp->fullBit(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+558,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))));
    bufp->fullBit(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full));
    bufp->fullBit(oldp+560,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last));
    bufp->fullBit(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+562,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))));
    bufp->fullBit(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full));
    bufp->fullBit(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last));
    bufp->fullBit(oldp+565,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+566,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))));
    bufp->fullBit(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full));
    bufp->fullBit(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last));
    bufp->fullBit(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+570,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))));
    bufp->fullBit(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full));
    bufp->fullBit(oldp+572,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last));
    bufp->fullBit(oldp+573,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+574,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))));
    bufp->fullBit(oldp+575,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full));
    bufp->fullBit(oldp+576,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last));
    bufp->fullBit(oldp+577,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+578,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))));
    bufp->fullBit(oldp+579,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full));
    bufp->fullBit(oldp+580,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last));
    bufp->fullBit(oldp+581,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+582,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))));
    bufp->fullBit(oldp+583,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full));
    bufp->fullBit(oldp+584,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last));
    bufp->fullBit(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+586,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))));
    bufp->fullBit(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full));
    bufp->fullBit(oldp+588,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last));
    bufp->fullBit(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+590,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))));
    bufp->fullBit(oldp+591,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full));
    bufp->fullBit(oldp+592,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last));
    bufp->fullBit(oldp+593,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+594,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))));
    bufp->fullBit(oldp+595,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full));
    bufp->fullBit(oldp+596,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last));
    bufp->fullBit(oldp+597,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+598,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))));
    bufp->fullBit(oldp+599,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full));
    bufp->fullBit(oldp+600,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last));
    bufp->fullBit(oldp+601,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+602,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))));
    bufp->fullBit(oldp+603,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full));
    bufp->fullBit(oldp+604,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last));
    bufp->fullBit(oldp+605,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+606,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))));
    bufp->fullBit(oldp+607,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full));
    bufp->fullBit(oldp+608,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last));
    bufp->fullBit(oldp+609,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+610,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))));
    bufp->fullBit(oldp+611,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full));
    bufp->fullBit(oldp+612,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last));
    bufp->fullBit(oldp+613,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+614,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))));
    bufp->fullBit(oldp+615,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full));
    bufp->fullBit(oldp+616,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last));
    bufp->fullBit(oldp+617,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+618,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))));
    bufp->fullBit(oldp+619,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full));
    bufp->fullBit(oldp+620,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last));
    bufp->fullBit(oldp+621,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullBit(oldp+622,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))));
    bufp->fullBit(oldp+623,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full));
    bufp->fullBit(oldp+624,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last));
    bufp->fullBit(oldp+625,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq));
    bufp->fullCData(oldp+626,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready),2);
    bufp->fullBit(oldp+627,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__busy));
    bufp->fullCData(oldp+628,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant),2);
    bufp->fullIData(oldp+629,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__i),32);
    bufp->fullBit(oldp+630,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready) 
                                   >> 1U))));
    bufp->fullCData(oldp+631,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state),2);
    bufp->fullBit(oldp+632,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+633,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+634,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+635,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+636,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+637,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+638,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+639,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+640,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+641,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullBit(oldp+642,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))));
    bufp->fullBit(oldp+643,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__qpi_ce_n));
    bufp->fullCData(oldp+644,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state))
                                ? (1U & (0x35U >> (7U 
                                                   & ((IData)(7U) 
                                                      - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter)))))
                                : 0U)),4);
    bufp->fullCData(oldp+645,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[0]),8);
    bufp->fullCData(oldp+646,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[1]),8);
    bufp->fullCData(oldp+647,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[2]),8);
    bufp->fullCData(oldp+648,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data[3]),8);
    bufp->fullBit(oldp+649,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__finish));
    bufp->fullCData(oldp+650,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__counter),3);
    bufp->fullCData(oldp+651,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state),2);
    bufp->fullCData(oldp+652,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+653,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state),3);
    bufp->fullBit(oldp+654,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__penable));
    bufp->fullCData(oldp+655,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
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
    bufp->fullBit(oldp+656,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                             | ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                | ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                   | ((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state)) 
                                      | (7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))))))));
    bufp->fullCData(oldp+657,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+658,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+659,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+660,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+661,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+662,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+663,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+664,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+665,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+666,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+667,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+668,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+669,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+670,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+671,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+672,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+673,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+674,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+675,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+676,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+677,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+678,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+679,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+680,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+681,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+682,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+683,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+684,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+685,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+686,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+687,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+688,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+689,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+690,(vlSelf->ysyxSoCFull__DOT__psram__DOT__state),4);
    bufp->fullCData(oldp+691,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_buffer),8);
    bufp->fullIData(oldp+692,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_buffer),24);
    bufp->fullCData(oldp+693,(vlSelf->ysyxSoCFull__DOT__psram__DOT__inst_counter),3);
    bufp->fullCData(oldp+694,(vlSelf->ysyxSoCFull__DOT__psram__DOT__addr_counter),3);
    bufp->fullCData(oldp+695,(vlSelf->ysyxSoCFull__DOT__psram__DOT__wait_counter),3);
    bufp->fullCData(oldp+696,(vlSelf->ysyxSoCFull__DOT__psram__DOT__data),8);
    bufp->fullBit(oldp+697,(vlSelf->ysyxSoCFull__DOT__psram__DOT__finish));
    bufp->fullCData(oldp+698,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_out_reg),4);
    bufp->fullBit(oldp+699,(vlSelf->ysyxSoCFull__DOT__psram__DOT__dio_en));
    bufp->fullBit(oldp+700,(vlSelf->ysyxSoCFull__DOT__psram__DOT__qpi_mode));
    bufp->fullBit(oldp+701,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+702,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+703,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+704,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+705,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+706,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+707,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+708,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+709,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+710,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullBit(oldp+711,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullIData(oldp+712,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                                << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+713,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck));
    bufp->fullBit(oldp+714,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_ce_n));
    bufp->fullCData(oldp+715,(((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))
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
    bufp->fullBit(oldp+716,((0xeU > (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+717,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_sck));
    bufp->fullBit(oldp+718,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n));
    bufp->fullBit(oldp+719,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_ce_n)))));
    bufp->fullBit(oldp+720,((0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))));
    bufp->fullBit(oldp+721,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__state));
    bufp->fullBit(oldp+722,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__state));
    bufp->fullCData(oldp+723,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter),8);
    bufp->fullIData(oldp+724,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__saddr),24);
    bufp->fullCData(oldp+725,((3U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                                      >> 1U) - (IData)(2U)))),2);
    bufp->fullBit(oldp+726,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__state));
    bufp->fullCData(oldp+727,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__counter),8);
    bufp->fullIData(oldp+728,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MW__DOT__saddr),24);
    bufp->fullBit(oldp+729,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+730,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+731,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+732,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullBit(oldp+733,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+734,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullCData(oldp+735,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullBit(oldp+736,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+737,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+738,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+739,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+740,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+741,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+742,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullCData(oldp+743,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+744,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+745,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullIData(oldp+746,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullSData(oldp+747,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+748,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+749,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullCData(oldp+750,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+751,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+754,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__spi_irq_out));
    bufp->fullBit(oldp+755,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready));
    bufp->fullIData(oldp+756,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_prdata),32);
    bufp->fullSData(oldp+757,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+758,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullCData(oldp+759,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+760,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+764,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+765,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+766,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+767,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+768,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+769,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+770,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+771,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+772,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+773,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+774,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+775,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+776,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+777,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+778,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+779,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+780,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+781,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+782,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+783,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                      >> 1U)))));
    bufp->fullBit(oldp+784,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+785,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+786,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 1U))));
    bufp->fullBit(oldp+787,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullBit(oldp+788,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+789,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+790,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+791,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+792,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+793,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullCData(oldp+794,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullSData(oldp+795,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullCData(oldp+796,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+797,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+798,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+799,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullSData(oldp+800,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullCData(oldp+801,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+802,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+803,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+804,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+805,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                   >> 4U))));
    bufp->fullBit(oldp+806,((IData)((0x10U != (0x12U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+807,((IData)((0x11U == (0x11U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+808,((IData)((0x14U == (0x14U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+809,((IData)((0x18U == (0x18U 
                                               & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+810,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
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
    bufp->fullBit(oldp+811,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+812,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+813,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 1U))));
    bufp->fullBit(oldp+814,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+815,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                   >> 2U))));
    bufp->fullBit(oldp+816,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+817,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+818,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+819,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+820,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+821,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+822,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+823,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+824,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+825,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+826,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+827,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+828,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+829,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+830,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+831,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+832,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+833,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+834,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
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
    bufp->fullBit(oldp+835,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+836,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullCData(oldp+837,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+838,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+839,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullSData(oldp+840,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+841,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+842,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+843,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+844,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+845,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+846,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+847,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+848,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+849,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+850,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+851,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+852,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+853,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+854,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+855,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+856,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+857,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+858,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+859,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+860,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+861,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+862,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+863,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+864,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+865,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+866,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+867,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+868,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+869,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+870,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullCData(oldp+871,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+872,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+873,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+874,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+875,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+876,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+877,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+878,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+879,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullBit(oldp+880,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullSData(oldp+881,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+882,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+883,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+884,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+885,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+886,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+887,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+888,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+889,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+890,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+891,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+892,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+893,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+894,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+895,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+896,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+897,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+898,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+899,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+900,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+901,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+902,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+903,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+904,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+905,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+906,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+907,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+908,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+909,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+910,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+911,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+912,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+913,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+914,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+915,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+916,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+917,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+918,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+919,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+920,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+921,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+922,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+923,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+924,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullCData(oldp+925,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+926,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+927,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+928,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+929,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+930,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+931,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+932,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullBit(oldp+933,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullCData(oldp+934,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+935,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+936,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+937,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullBit(oldp+938,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6beba8fe__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullBit(oldp+939,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6818f070__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullBit(oldp+940,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__read));
    bufp->fullBit(oldp+941,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__write));
    bufp->fullBit(oldp+942,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__burst_terminate));
    bufp->fullBit(oldp+943,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6818f070__0))));
    bufp->fullBit(oldp+944,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h84ea0254__0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullBit(oldp+945,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h84ea0254__0))));
    bufp->fullBit(oldp+946,((((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6beba8fe__0) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)) 
                             | (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h84ea0254__0) 
                                 & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)) 
                                | ((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)) 
                                   & (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__decoder__DOT____VdfgTmp_h6818f070__0))))));
    bufp->fullSData(oldp+947,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cur_addr_r),13);
    bufp->fullIData(oldp+948,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge),32);
    bufp->fullIData(oldp+949,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [2U]),32);
    bufp->fullIData(oldp+950,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr
                              [1U]),32);
    bufp->fullIData(oldp+951,(((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__pcbridge)),32);
    bufp->fullIData(oldp+952,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+953,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+954,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+955,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+956,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+957,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+958,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+959,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+960,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+961,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+962,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+963,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+964,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+965,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+966,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+967,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+968,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+969,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+970,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+971,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+972,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+973,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+974,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+975,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+976,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+977,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+978,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+979,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+980,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+981,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+982,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+983,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[31]),32);
    bufp->fullIData(oldp+984,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[0]),32);
    bufp->fullIData(oldp+985,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[1]),32);
    bufp->fullIData(oldp+986,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[2]),32);
    bufp->fullIData(oldp+987,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[3]),32);
    bufp->fullIData(oldp+988,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[4]),32);
    bufp->fullIData(oldp+989,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf_csr[5]),32);
    bufp->fullIData(oldp+990,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[0]),32);
    bufp->fullIData(oldp+991,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[1]),32);
    bufp->fullIData(oldp+992,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[2]),32);
    bufp->fullIData(oldp+993,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[3]),32);
    bufp->fullIData(oldp+994,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[4]),32);
    bufp->fullIData(oldp+995,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[5]),32);
    bufp->fullIData(oldp+996,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[6]),32);
    bufp->fullIData(oldp+997,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[7]),32);
    bufp->fullIData(oldp+998,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[8]),32);
    bufp->fullIData(oldp+999,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[9]),32);
    bufp->fullIData(oldp+1000,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[10]),32);
    bufp->fullIData(oldp+1001,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[11]),32);
    bufp->fullIData(oldp+1002,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[12]),32);
    bufp->fullIData(oldp+1003,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[13]),32);
    bufp->fullIData(oldp+1004,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[14]),32);
    bufp->fullIData(oldp+1005,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[15]),32);
    bufp->fullIData(oldp+1006,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[16]),32);
    bufp->fullIData(oldp+1007,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[17]),32);
    bufp->fullIData(oldp+1008,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[18]),32);
    bufp->fullIData(oldp+1009,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[19]),32);
    bufp->fullIData(oldp+1010,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[20]),32);
    bufp->fullIData(oldp+1011,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[21]),32);
    bufp->fullIData(oldp+1012,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[22]),32);
    bufp->fullIData(oldp+1013,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[23]),32);
    bufp->fullIData(oldp+1014,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[24]),32);
    bufp->fullIData(oldp+1015,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[25]),32);
    bufp->fullIData(oldp+1016,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[26]),32);
    bufp->fullIData(oldp+1017,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[27]),32);
    bufp->fullIData(oldp+1018,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[28]),32);
    bufp->fullIData(oldp+1019,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[29]),32);
    bufp->fullIData(oldp+1020,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[30]),32);
    bufp->fullIData(oldp+1021,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__gr[31]),32);
    bufp->fullIData(oldp+1022,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[0]),32);
    bufp->fullIData(oldp+1023,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[1]),32);
    bufp->fullIData(oldp+1024,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[2]),32);
    bufp->fullIData(oldp+1025,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[3]),32);
    bufp->fullIData(oldp+1026,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[4]),32);
    bufp->fullIData(oldp+1027,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT____Vcellout__registers0__csr[5]),32);
    bufp->fullIData(oldp+1028,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__registers0__DOT__i),32);
    bufp->fullCData(oldp+1029,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+1030,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+1031,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+1032,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+1033,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+1034,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                              & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullCData(oldp+1035,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer),8);
    bufp->fullCData(oldp+1036,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count),3);
    bufp->fullCData(oldp+1037,(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state),2);
    bufp->fullBit(oldp+1038,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                    >> (7U & ((IData)(7U) 
                                              - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))));
    bufp->fullCData(oldp+1039,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__state_next_r),4);
    bufp->fullSData(oldp+1040,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rd_pip_in_addr_r),13);
    bufp->fullSData(oldp+1041,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__wr_in_addr_r),13);
    bufp->fullCData(oldp+1042,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+1043,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__arsize_out_reg),3);
    bufp->fullBit(oldp+1044,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu));
    bufp->fullIData(oldp+1045,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg),32);
    bufp->fullBit(oldp+1046,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid));
    bufp->fullBit(oldp+1047,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullBit(oldp+1048,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready))));
    bufp->fullBit(oldp+1049,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state))));
    bufp->fullCData(oldp+1050,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 0xfU))),5);
    bufp->fullCData(oldp+1051,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 0x14U))),5);
    bufp->fullCData(oldp+1052,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                         >> 7U))),5);
    bufp->fullIData(oldp+1053,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+1054,((0x100073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1055,((0x30200073U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1056,((0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)));
    bufp->fullBit(oldp+1057,(((3U != (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I) 
                                 | ((0x33U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | ((0x6fU == (0x7fU 
                                                  & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                       | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U)))))));
    bufp->fullBit(oldp+1058,((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1059,((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1060,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muximm));
    bufp->fullCData(oldp+1061,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                      >> 0xcU))),3);
    bufp->fullCData(oldp+1062,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__muxsig),3);
    bufp->fullBit(oldp+1063,((1U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                    >> 0x1eU))));
    bufp->fullBit(oldp+1064,((0x63U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1065,((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1066,((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1067,((0x17U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullCData(oldp+1068,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop),2);
    bufp->fullBit(oldp+1069,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrw));
    bufp->fullBit(oldp+1070,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csrrs));
    bufp->fullCData(oldp+1071,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask),3);
    bufp->fullBit(oldp+1072,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memsextsig));
    bufp->fullCData(oldp+1073,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid) 
                                << 1U)),2);
    bufp->fullCData(oldp+1074,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arvalid),2);
    bufp->fullCData(oldp+1075,((((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 << 1U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))),2);
    bufp->fullCData(oldp+1076,(((0x23U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                << 1U)),2);
    bufp->fullCData(oldp+1077,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready),2);
    bufp->fullCData(oldp+1078,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[0]),3);
    bufp->fullCData(oldp+1079,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arsize[1]),3);
    bufp->fullCData(oldp+1080,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[0]),3);
    bufp->fullCData(oldp+1081,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__arsize[1]),3);
    bufp->fullCData(oldp+1082,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluopcode),5);
    bufp->fullBit(oldp+1083,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0)))));
    bufp->fullBit(oldp+1084,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logsig));
    bufp->fullBit(oldp+1085,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfsig));
    bufp->fullBit(oldp+1086,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltsig));
    bufp->fullBit(oldp+1087,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1088,((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1089,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullBit(oldp+1090,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__aluop))));
    bufp->fullCData(oldp+1091,(((IData)((0x6000U == 
                                         (0x6000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                 ? 8U : ((1U & VL_REDXOR_16(
                                                            (0x6000U 
                                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)))
                                          ? 9U : 3U))),4);
    bufp->fullCData(oldp+1092,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alucontrol0__DOT__IRop),4);
    bufp->fullBit(oldp+1093,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1094,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),7);
    bufp->fullBit(oldp+1095,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_I));
    bufp->fullBit(oldp+1096,((0x33U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1097,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__maincontrol0__DOT__type_U));
    bufp->fullIData(oldp+1098,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__I_imm),32);
    bufp->fullIData(oldp+1099,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+1100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__S_imm),32);
    bufp->fullIData(oldp+1101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__J_imm),32);
    bufp->fullIData(oldp+1102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu0__DOT__decoder0__DOT__B_imm),32);
    bufp->fullBit(oldp+1103,(((0x67U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              | ((0x6fU == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                 | ((0x17U == (0x7fU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                    | (0x73U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))))));
    bufp->fullBit(oldp+1104,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+1105,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_valid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ready_idu_to_ifu))));
    bufp->fullCData(oldp+1106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state),3);
    bufp->fullSData(oldp+1107,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg 
                                >> 0x14U)),12);
    bufp->fullCData(oldp+1108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__csr_choose),3);
    bufp->fullCData(oldp+1109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+1111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awvalid));
    bufp->fullBit(oldp+1112,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                    >> 1U))));
    bufp->fullCData(oldp+1113,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : 2U))),3);
    bufp->fullCData(oldp+1114,(((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 1U : ((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 2U : 0U))),2);
    bufp->fullCData(oldp+1115,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                 ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                          ? 1U : ((4U 
                                                   == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
                                                   ? 2U
                                                   : 0U)))),3);
    bufp->fullCData(oldp+1116,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullWData(oldp+1117,(__Vtemp_h49f7fb6a__0),66);
    bufp->fullQData(oldp+1120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+1122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+1124,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+1125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+1126,((0x11830U | ((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__memmask))
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
    bufp->fullCData(oldp+1127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[0]),6);
    bufp->fullCData(oldp+1128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[1]),6);
    bufp->fullCData(oldp+1129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[2]),6);
    bufp->fullCData(oldp+1130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__pair_list[3]),6);
    bufp->fullCData(oldp+1131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[0]),4);
    bufp->fullCData(oldp+1132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[1]),4);
    bufp->fullCData(oldp+1133,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[2]),4);
    bufp->fullCData(oldp+1134,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__data_list[3]),4);
    bufp->fullIData(oldp+1135,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr),32);
    bufp->fullCData(oldp+1136,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size),3);
    bufp->fullIData(oldp+1137,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata),32);
    bufp->fullCData(oldp+1138,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb),4);
    bufp->fullIData(oldp+1139,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr),32);
    bufp->fullIData(oldp+1140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awaddr_out_reg),32);
    bufp->fullCData(oldp+1141,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__awsize_out_reg),3);
    bufp->fullCData(oldp+1142,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awburst),2);
    bufp->fullIData(oldp+1143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wdata_out_reg),32);
    bufp->fullCData(oldp+1144,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__wstrb_out_reg),4);
    bufp->fullIData(oldp+1145,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__araddr_out_reg),32);
    bufp->fullIData(oldp+1146,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr),32);
    bufp->fullIData(oldp+1147,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1),32);
    bufp->fullIData(oldp+1148,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr),32);
    bufp->fullIData(oldp+1149,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr),32);
    bufp->fullCData(oldp+1150,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst),2);
    bufp->fullIData(oldp+1151,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr)),28);
    bufp->fullIData(oldp+1152,((0xfffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),28);
    bufp->fullBit(oldp+1153,((0x7800U == (0x7fffU & 
                                          (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                           >> 0xdU)))));
    bufp->fullSData(oldp+1154,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                          >> 2U))),11);
    bufp->fullSData(oldp+1155,((0x7ffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1156,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),30);
    bufp->fullBit(oldp+1157,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_0));
    bufp->fullBit(oldp+1158,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1));
    bufp->fullBit(oldp+1159,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2));
    bufp->fullBit(oldp+1160,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_0));
    bufp->fullBit(oldp+1161,((0U == ((0x10U & (vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
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
    bufp->fullBit(oldp+1162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestAWIO_0_2));
    bufp->fullCData(oldp+1163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits),3);
    bufp->fullCData(oldp+1164,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits),3);
    bufp->fullIData(oldp+1165,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc),32);
    bufp->fullIData(oldp+1166,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout1),32);
    bufp->fullIData(oldp+1167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2),32);
    bufp->fullIData(oldp+1168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res),32);
    bufp->fullIData(oldp+1169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pcwritereg),32);
    bufp->fullIData(oldp+1170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[0]),32);
    bufp->fullIData(oldp+1171,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awaddr[1]),32);
    bufp->fullIData(oldp+1172,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[0]),32);
    bufp->fullIData(oldp+1173,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wdata[1]),32);
    bufp->fullCData(oldp+1174,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[0]),4);
    bufp->fullCData(oldp+1175,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wstrb[1]),4);
    bufp->fullCData(oldp+1176,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[0]),3);
    bufp->fullCData(oldp+1177,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awsize[1]),3);
    bufp->fullIData(oldp+1178,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[0]),32);
    bufp->fullIData(oldp+1179,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__araddr[1]),32);
    bufp->fullIData(oldp+1180,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[0]),32);
    bufp->fullIData(oldp+1181,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awaddr[1]),32);
    bufp->fullIData(oldp+1182,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[0]),32);
    bufp->fullIData(oldp+1183,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wdata[1]),32);
    bufp->fullCData(oldp+1184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[0]),4);
    bufp->fullCData(oldp+1185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__wstrb[1]),4);
    bufp->fullCData(oldp+1186,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[0]),3);
    bufp->fullCData(oldp+1187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellinp__arviter0__awsize[1]),3);
    bufp->fullIData(oldp+1188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__pcaddimmbridge),32);
    bufp->fullIData(oldp+1189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__aluarg2),32);
    bufp->fullBit(oldp+1190,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)));
    bufp->fullBit(oldp+1191,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res 
                              >> 0x1fU)));
    bufp->fullBit(oldp+1192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__carry_tmp));
    bufp->fullIData(oldp+1193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__logres),32);
    bufp->fullIData(oldp+1194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres),32);
    bufp->fullBit(oldp+1195,((0U == vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__addres)));
    bufp->fullIData(oldp+1196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__shfres),32);
    bufp->fullIData(oldp+1197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__alu0__DOT__sltres),32);
    bufp->fullIData(oldp+1198,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+1199,(((0x1fU >= (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                             ? (3U 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                             : 0U) 
                                           << 3U)) ? 
                                (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regout2 
                                 << (((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                       ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                       : 0U) << 3U))
                                 : 0U)),32);
    bufp->fullCData(oldp+1200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__wstrb),4);
    bufp->fullIData(oldp+1201,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__aligned_sram)
                                 ? (0xfffffffcU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),32);
    bufp->fullCData(oldp+1202,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT____Vcellout__wbu0__awsize),3);
    bufp->fullCData(oldp+1203,(((3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size))
                                 ? (3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                 : 0U)),2);
    bufp->fullBit(oldp+1204,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__aligned_sram));
    bufp->fullCData(oldp+1205,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)),2);
    bufp->fullBit(oldp+1206,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__inuart));
    bufp->fullBit(oldp+1207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__insram));
    bufp->fullBit(oldp+1208,(((0x30000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x3fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1209,(((0x10001000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x10001fffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullBit(oldp+1210,(((0x80000000U <= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res) 
                              & (0x9fffffffU >= vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res))));
    bufp->fullCData(oldp+1211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__bus_size),2);
    bufp->fullCData(oldp+1212,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux))
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
    bufp->fullCData(oldp+1213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__mux),5);
    bufp->fullCData(oldp+1214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__lut_out),3);
    bufp->fullBit(oldp+1215,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__len_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT____Vcellinp__type_mux__key),2);
    bufp->fullCData(oldp+1217,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__lut_out),2);
    bufp->fullBit(oldp+1218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__type_mux__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+1219,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__lut_out),4);
    bufp->fullBit(oldp+1220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_mux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+1221,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr)),32);
    bufp->fullBit(oldp+1222,(vlSelf->clock));
    bufp->fullBit(oldp+1223,(vlSelf->reset));
    bufp->fullSData(oldp+1224,(vlSelf->externalPins_gpio_out),16);
    bufp->fullSData(oldp+1225,(vlSelf->externalPins_gpio_in),16);
    bufp->fullCData(oldp+1226,(vlSelf->externalPins_gpio_seg_0),8);
    bufp->fullCData(oldp+1227,(vlSelf->externalPins_gpio_seg_1),8);
    bufp->fullCData(oldp+1228,(vlSelf->externalPins_gpio_seg_2),8);
    bufp->fullCData(oldp+1229,(vlSelf->externalPins_gpio_seg_3),8);
    bufp->fullCData(oldp+1230,(vlSelf->externalPins_gpio_seg_4),8);
    bufp->fullCData(oldp+1231,(vlSelf->externalPins_gpio_seg_5),8);
    bufp->fullCData(oldp+1232,(vlSelf->externalPins_gpio_seg_6),8);
    bufp->fullCData(oldp+1233,(vlSelf->externalPins_gpio_seg_7),8);
    bufp->fullBit(oldp+1234,(vlSelf->externalPins_ps2_clk));
    bufp->fullBit(oldp+1235,(vlSelf->externalPins_ps2_data));
    bufp->fullCData(oldp+1236,(vlSelf->externalPins_vga_r),8);
    bufp->fullCData(oldp+1237,(vlSelf->externalPins_vga_g),8);
    bufp->fullCData(oldp+1238,(vlSelf->externalPins_vga_b),8);
    bufp->fullBit(oldp+1239,(vlSelf->externalPins_vga_hsync));
    bufp->fullBit(oldp+1240,(vlSelf->externalPins_vga_vsync));
    bufp->fullBit(oldp+1241,(vlSelf->externalPins_vga_valid));
    bufp->fullBit(oldp+1242,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+1243,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+1244,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+1245,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
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
    bufp->fullCData(oldp+1246,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__din),4);
    bufp->fullBit(oldp+1247,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullSData(oldp+1248,((((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)
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
                                     & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h3fc29f95__0)
                                         ? 0xffU : 0U)) 
                                    | ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__dq__out__strong__out1) 
                                       & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h636ffa80__0)
                                            ? 0xffU
                                            : 0U) << 8U))) 
                                   & (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h3fc29f95__0)
                                        ? 0xffU : 0U) 
                                      | (((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT____VdfgTmp_h636ffa80__0)
                                           ? 0xffU : 0U) 
                                         << 8U))))),16);
    bufp->fullBit(oldp+1249,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                                : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_2_psel))));
    bufp->fullIData(oldp+1250,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                 ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                     << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                   << 0x10U) 
                                                  | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                      << 8U) 
                                                     | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                 : 0U)),32);
    bufp->fullBit(oldp+1251,((1U & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                     ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                     : ((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__state))
                                         ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__apb_pready)
                                         : 0U)))));
    bufp->fullIData(oldp+1252,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lspi_auto_in_prdata),32);
    bufp->fullBit(oldp+1253,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset)) 
                              & (0U != (((0x23U == 
                                          (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                                         << 1U) & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arviter0__DOT__giant))))));
    bufp->fullCData(oldp+1254,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_0)
                                  ? ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                      ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
                                         << 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r))
                                  : 0U) | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__muxState_3_2)
                                            ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1)
                                                ? 0U
                                                : 3U)
                                            : 0U))),2);
    bufp->fullBit(oldp+1255,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_awvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____VdfgTmp_h8d807e6f__0))));
    bufp->fullBit(oldp+1256,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 2U))));
    bufp->fullBit(oldp+1257,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_2))));
    bufp->fullBit(oldp+1258,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
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
    bufp->fullBit(oldp+1259,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                                 >> 1U))));
    bufp->fullBit(oldp+1260,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_out_arvalid) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__requestARIO_0_1))));
    bufp->fullBit(oldp+1261,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                  ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                     >> 1U) : (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1)))));
    bufp->fullBit(oldp+1262,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rvalid) 
                                 >> 1U))));
    bufp->fullIData(oldp+1263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[0]),32);
    bufp->fullIData(oldp+1264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__araddr[1]),32);
    bufp->fullBit(oldp+1265,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1266,(((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__state)) 
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
    bufp->fullBit(oldp+1267,(((3U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu0__DOT__inst_reg)) 
                              & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__state)))));
    bufp->fullBit(oldp+1268,((1U & (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arready) 
                                     & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__awready)) 
                                    >> 1U))));
    bufp->fullSData(oldp+1269,((0xffffU & ((2U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__res)
                                            ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                               [1U] 
                                               >> 0x10U)
                                            : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rdata
                                           [1U]))),16);
    bufp->fullCData(oldp+1270,((0xffU & ((0U == (3U 
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
    bufp->fullBit(oldp+1271,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__wb_we)
                               ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mw_done)
                               : (0x1cU == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)))));
    bufp->fullBit(oldp+1272,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__QPI__DOT__state)) 
                              & (IData)(vlSelf->clock))));
    bufp->fullBit(oldp+1273,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullSData(oldp+1274,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                 [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                 << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+1275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullCData(oldp+1276,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullBit(oldp+1277,(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss));
    bufp->fullBit(oldp+1278,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
                                    | ((2U != (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__state)) 
                                       | ((IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__buffer) 
                                          >> (7U & 
                                              ((IData)(7U) 
                                               - (IData)(vlSelf->ysyxSoCFull__DOT__bitrev__DOT__count)))))))));
    bufp->fullBit(oldp+1279,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                    | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                         & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                         ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                         : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                       >> 0x1fU)))));
    bufp->fullIData(oldp+1280,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+1281,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                              << 1U)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+1282,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullBit(oldp+1283,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__valclk));
    bufp->fullCData(oldp+1284,(1U),3);
    bufp->fullBit(oldp+1285,(0U));
    bufp->fullBit(oldp+1286,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pready));
    bufp->fullBit(oldp+1287,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_pslverr));
    bufp->fullIData(oldp+1288,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lvga_auto_in_prdata),32);
    bufp->fullBit(oldp+1289,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pready));
    bufp->fullBit(oldp+1290,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_pslverr));
    bufp->fullIData(oldp+1291,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lkeyboard_auto_in_prdata),32);
    bufp->fullBit(oldp+1292,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pready));
    bufp->fullBit(oldp+1293,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_pslverr));
    bufp->fullIData(oldp+1294,(vlSelf->ysyxSoCFull__DOT__asic__DOT___lgpio_auto_in_prdata),32);
    bufp->fullCData(oldp+1295,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awid),4);
    bufp->fullCData(oldp+1296,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_awlen),8);
    bufp->fullBit(oldp+1297,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_wlast));
    bufp->fullCData(oldp+1298,(vlSelf->ysyxSoCFull__DOT__asic__DOT___cpu_auto_master_out_arid),4);
    bufp->fullCData(oldp+1299,(0U),8);
    bufp->fullCData(oldp+1300,(1U),2);
    bufp->fullBit(oldp+1301,(1U));
    bufp->fullBit(oldp+1302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_awready));
    bufp->fullIData(oldp+1303,(0U),32);
    bufp->fullCData(oldp+1304,(0U),4);
    bufp->fullCData(oldp+1305,(0U),3);
    bufp->fullCData(oldp+1306,(0U),2);
    bufp->fullBit(oldp+1307,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_wready));
    bufp->fullBit(oldp+1308,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bvalid));
    bufp->fullCData(oldp+1309,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bresp),2);
    bufp->fullCData(oldp+1310,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_bid),4);
    bufp->fullBit(oldp+1311,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_arready));
    bufp->fullBit(oldp+1312,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rvalid));
    bufp->fullCData(oldp+1313,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rresp),2);
    bufp->fullIData(oldp+1314,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rdata),32);
    bufp->fullBit(oldp+1315,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rlast));
    bufp->fullCData(oldp+1316,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__io_slave_rid),4);
    bufp->fullIData(oldp+1317,(2U),32);
    bufp->fullIData(oldp+1318,(2U),32);
    bufp->fullIData(oldp+1319,(1U),32);
    bufp->fullIData(oldp+1320,(0x20U),32);
    bufp->fullIData(oldp+1321,(0U),32);
    bufp->fullIData(oldp+1322,(0x21U),32);
    bufp->fullIData(oldp+1323,(2U),32);
    bufp->fullIData(oldp+1324,(0x30000000U),32);
    bufp->fullIData(oldp+1325,(6U),32);
    bufp->fullIData(oldp+1326,(0xcU),32);
    bufp->fullIData(oldp+1327,(3U),32);
    __Vtemp_ha129e8f8__0[0U] = 0xfc467895U;
    __Vtemp_ha129e8f8__0[1U] = 0x93414684U;
    __Vtemp_ha129e8f8__0[2U] = 0xc00182U;
    bufp->fullWData(oldp+1328,(__Vtemp_ha129e8f8__0),90);
    bufp->fullIData(oldp+1331,(0xfU),32);
    bufp->fullIData(oldp+1332,(6U),32);
    bufp->fullIData(oldp+1333,(8U),32);
    bufp->fullIData(oldp+1334,(0x10U),32);
    bufp->fullIData(oldp+1335,(4U),32);
    bufp->fullIData(oldp+1336,(0x23U),32);
    bufp->fullIData(oldp+1337,(4U),32);
    bufp->fullCData(oldp+1338,(1U),4);
    bufp->fullCData(oldp+1339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu0__DOT__strbcontol__DOT__wstrb_halfword),4);
    bufp->fullSData(oldp+1340,(0x223aU),15);
    bufp->fullIData(oldp+1341,(5U),32);
    bufp->fullIData(oldp+1342,(3U),32);
    bufp->fullCData(oldp+1343,(0xb5U),8);
    bufp->fullBit(oldp+1344,(0U));
    bufp->fullBit(oldp+1345,(1U));
    bufp->fullCData(oldp+1346,(4U),3);
    bufp->fullCData(oldp+1347,(0x1bU),8);
    bufp->fullCData(oldp+1348,(0xebU),8);
    bufp->fullCData(oldp+1349,(0x38U),8);
    bufp->fullCData(oldp+1350,(0x35U),8);
    bufp->fullIData(oldp+1351,(0x64U),32);
    bufp->fullIData(oldp+1352,(0x18U),32);
    bufp->fullIData(oldp+1353,(9U),32);
    bufp->fullIData(oldp+1354,(0xdU),32);
    bufp->fullIData(oldp+1355,(0x2000U),32);
    bufp->fullIData(oldp+1356,(0x2710U),32);
    bufp->fullIData(oldp+1357,(0x30cU),32);
    bufp->fullCData(oldp+1358,(7U),4);
    bufp->fullCData(oldp+1359,(3U),4);
    bufp->fullCData(oldp+1360,(5U),4);
    bufp->fullCData(oldp+1361,(4U),4);
    bufp->fullCData(oldp+1362,(6U),4);
    bufp->fullCData(oldp+1363,(2U),4);
    bufp->fullSData(oldp+1364,(0x21U),13);
    bufp->fullCData(oldp+1365,(8U),4);
    bufp->fullCData(oldp+1366,(9U),4);
    bufp->fullIData(oldp+1367,(0xaU),32);
    bufp->fullIData(oldp+1368,(0x11U),32);
    bufp->fullIData(oldp+1369,(0x3fffffffU),32);
    bufp->fullCData(oldp+1370,(0xaU),4);
    bufp->fullIData(oldp+1371,(0xbU),32);
    bufp->fullCData(oldp+1372,(2U),3);
    bufp->fullCData(oldp+1373,(3U),3);
    bufp->fullCData(oldp+1374,(5U),3);
    bufp->fullSData(oldp+1375,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q),13);
    bufp->fullSData(oldp+1376,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__row),13);
    bufp->fullBit(oldp+1377,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__cas_start));
    bufp->fullBit(oldp+1378,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__bl_start));
    bufp->fullCData(oldp+1379,((7U & ((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode_q) 
                                      >> 4U))),3);
}
