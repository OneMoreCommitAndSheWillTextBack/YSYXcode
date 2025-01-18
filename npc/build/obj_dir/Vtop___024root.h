// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;
class Vtop___024unit;


class Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ top__DOT__ready_idu_to_ifu;
        CData/*0:0*/ top__DOT__muximm;
        CData/*2:0*/ top__DOT__muxsig;
        CData/*1:0*/ top__DOT__aluop;
        CData/*0:0*/ top__DOT__csrrw;
        CData/*0:0*/ top__DOT__csrrs;
        CData/*2:0*/ top__DOT__memmask;
        CData/*0:0*/ top__DOT__memsextsig;
        CData/*0:0*/ top__DOT__idu0__DOT__decoder0__DOT__type_I;
        CData/*0:0*/ top__DOT__idu0__DOT__decoder0__DOT__type_U;
        CData/*1:0*/ top__DOT__regfile__DOT__csr_choose;
        CData/*0:0*/ top__DOT__regfile__DOT____Vcellinp__registers0__ew;
        CData/*1:0*/ top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit;
        CData/*4:0*/ top__DOT__exu0__DOT__aluopcode;
        CData/*3:0*/ top__DOT__exu0__DOT__alucontrol0__DOT__IRop;
        CData/*0:0*/ top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__exu0__DOT__alu0__DOT__logsig;
        CData/*0:0*/ top__DOT__exu0__DOT__alu0__DOT__shfsig;
        CData/*0:0*/ top__DOT__exu0__DOT__alu0__DOT__sltsig;
        CData/*0:0*/ top__DOT__exu0__DOT__alu0__DOT__carry_tmp;
        CData/*0:0*/ top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0;
        CData/*0:0*/ top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0;
        CData/*0:0*/ top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit;
        CData/*1:0*/ top__DOT__data0__DOT__arvalid_in;
        CData/*1:0*/ top__DOT__data0__DOT__rvalid_out;
        CData/*0:0*/ top__DOT__data0__DOT__awvalid_sram;
        CData/*0:0*/ top__DOT__data0__DOT__wvalid_sram;
        CData/*0:0*/ top__DOT__data0__DOT__arvalid_sram;
        CData/*0:0*/ top__DOT__data0__DOT__bvalid_sram;
        CData/*0:0*/ top__DOT__data0__DOT__arviter0__DOT__busy;
        CData/*1:0*/ top__DOT__data0__DOT__arviter0__DOT__giant;
        CData/*3:0*/ top__DOT__data0__DOT__arviter0__DOT__wstrb_out_reg;
        CData/*1:0*/ top__DOT__data0__DOT__mem0__DOT__state;
        CData/*0:0*/ top__DOT__data0__DOT__mem0__DOT__busy;
        CData/*3:0*/ top__DOT__data0__DOT__mem0__DOT__random_count;
        CData/*2:0*/ top__DOT__data0__DOT__mem0__DOT__memmask;
        CData/*7:0*/ top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__random_num;
        CData/*0:0*/ top__DOT__data0__DOT__mem0__DOT__lsfr0__DOT__feedback;
        CData/*2:0*/ top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__lut_out;
        CData/*0:0*/ top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__hit;
        CData/*3:0*/ __VdfgTmp_he79674ea__0;
        CData/*5:0*/ __Vtableidx1;
        CData/*1:0*/ __Vdly__top__DOT__data0__DOT__mem0__DOT__state;
        CData/*3:0*/ __Vdly__top__DOT__data0__DOT__mem0__DOT__random_count;
        CData/*0:0*/ __Vtrigrprev__TOP__clk;
        CData/*0:0*/ __Vtrigrprev__TOP__top__DOT__ready_idu_to_ifu;
        CData/*0:0*/ __Vtrigrprev__TOP__rst;
        CData/*1:0*/ __Vtrigrprev__TOP__top__DOT__data0__DOT__mem0__DOT__state;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ top__DOT__npc;
        IData/*31:0*/ top__DOT__imm;
        IData/*31:0*/ top__DOT__regwrite;
        IData/*31:0*/ top__DOT__regout1;
        IData/*31:0*/ top__DOT__regout2;
        IData/*31:0*/ top__DOT__res;
        IData/*31:0*/ top__DOT__pcwritereg;
        IData/*31:0*/ top__DOT__ifu0__DOT__pcbridge;
        IData/*31:0*/ top__DOT__ifu0__DOT__inst_reg;
        IData/*31:0*/ top__DOT__idu0__DOT__decoder0__DOT__I_imm;
        IData/*31:0*/ top__DOT__idu0__DOT__decoder0__DOT__S_imm;
    };
    struct {
        IData/*31:0*/ top__DOT__idu0__DOT__decoder0__DOT__J_imm;
        IData/*31:0*/ top__DOT__idu0__DOT__decoder0__DOT__B_imm;
        IData/*31:0*/ top__DOT__regfile__DOT__reg_write_data;
        IData/*31:0*/ top__DOT__regfile__DOT__registers0__DOT__i;
        IData/*31:0*/ top__DOT__regfile__DOT__registers0__DOT__tmp;
        IData/*31:0*/ top__DOT__exu0__DOT__pcaddimmbridge;
        IData/*31:0*/ top__DOT__exu0__DOT__aluarg2;
        IData/*31:0*/ top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT__logres;
        IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT__addres;
        IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT__shfres;
        IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT__sltres;
        IData/*31:0*/ top__DOT__wbu0__DOT__memread;
        IData/*31:0*/ top__DOT__wbu0__DOT__memreadlen0__DOT__read_u;
        IData/*31:0*/ top__DOT__wbu0__DOT__memreadlen0__DOT__read_s;
        IData/*31:0*/ top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__data0__DOT__arviter0__DOT__i;
        IData/*31:0*/ top__DOT__data0__DOT__arviter0__DOT__awaddr_out_reg;
        IData/*31:0*/ top__DOT__data0__DOT__arviter0__DOT__wdata_out_reg;
        IData/*31:0*/ top__DOT__data0__DOT__arviter0__DOT__araddr_out_reg;
        IData/*31:0*/ top__DOT__data0__DOT__mem0__DOT__rdatareg;
        IData/*31:0*/ __Vfunc_guest_read__8__Vfuncout;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__araddr;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__rdata;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__awaddr;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__wdata;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__wstrb;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__bresp;
        VlUnpacked<CData/*0:0*/, 2> top__DOT____Vcellout__data0__bresp;
        VlUnpacked<CData/*3:0*/, 2> top__DOT____Vcellinp__data0__wstrb;
        VlUnpacked<IData/*31:0*/, 2> top__DOT____Vcellinp__data0__wdata;
        VlUnpacked<IData/*31:0*/, 2> top__DOT____Vcellinp__data0__awaddr;
        VlUnpacked<IData/*31:0*/, 2> top__DOT____Vcellout__data0__rdata;
        VlUnpacked<IData/*31:0*/, 2> top__DOT____Vcellinp__data0__araddr;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__rf;
        VlUnpacked<IData/*31:0*/, 4> top__DOT__regfile__DOT__rf_csr;
        VlUnpacked<IData/*31:0*/, 4> top__DOT__regfile__DOT____Vcellout__registers0__csr;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT____Vcellout__registers0__gr;
        VlUnpacked<SData/*13:0*/, 4> top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list;
        VlUnpacked<SData/*11:0*/, 4> top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*1:0*/, 4> top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*32:0*/, 2> top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*34:0*/, 4> top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*2:0*/, 4> top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 4> top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__data0__DOT____Vcellout__arviter0__bresp;
        VlUnpacked<CData/*3:0*/, 2> top__DOT__data0__DOT____Vcellinp__arviter0__wstrb;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__data0__DOT____Vcellout__arviter0__rdata;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__data0__DOT____Vcellinp__arviter0__wdata;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__data0__DOT____Vcellinp__arviter0__awaddr;
        VlUnpacked<IData/*31:0*/, 2> top__DOT__data0__DOT____Vcellinp__arviter0__araddr;
        VlUnpacked<CData/*6:0*/, 4> top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 4> top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__key_list;
        VlUnpacked<CData/*2:0*/, 4> top__DOT__data0__DOT__mem0__DOT__muxpc__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
