// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__i = 4U;
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[0U] = 4U;
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[1U] = 2U;
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[2U] = 1U;
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[3U] = 0U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[0U] = 8U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[1U] = 4U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[2U] = 2U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[3U] = 1U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[0U] = 4U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[1U] = 3U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[2U] = 2U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[3U] = 1U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[0U] = 0x44U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[1U] = 0x23U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[2U] = 0x12U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[3U] = 9U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[0U] = 0x342U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[1U] = 0x341U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[2U] = 0x305U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[3U] = 0x300U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[0U] = 3U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[1U] = 2U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[2U] = 1U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[3U] = 0U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[0U] = 0xd0bU;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[1U] = 0xd06U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[2U] = 0xc15U;
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[3U] = 0xc00U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[0U] = 8U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[1U] = 4U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[2U] = 2U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[3U] = 1U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[0U] = 4U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[1U] = 3U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[2U] = 2U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[3U] = 1U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[0U] = 0x44U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[1U] = 0x23U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[2U] = 0x12U;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[3U] = 9U;
    vlSelf->top__DOT__ifu0__DOT__pcbridge = 0x80000000U;
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num = 0xaaU;
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num = 0xaaU;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/ysyx/project/ysyx-workbench/npc/vsrc/top.v", 4, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ready_idu_to_ifu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__npc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ifu_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__muximm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__muxsig = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__aluop = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__csrrw = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__csrrs = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__memmask = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__memsextsig = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regwrite = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regout1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regout2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__res = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pcwritereg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ifu0__DOT__pcbridge = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ifu0__DOT__rready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ifu0__DOT__arvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ifu0__DOT__rvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ifu0__DOT__bvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__random_count = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__memmask = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__rdatareg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__random_num = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__lsfr0__DOT__feedback = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(7);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(3);
    }
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ifu0__DOT__infetch__DOT__muxpc__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_I = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__type_U = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__I_imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__S_imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__J_imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu0__DOT__decoder0__DOT__B_imm = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__rf_csr[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regfile__DOT__csr_choose = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__regfile__DOT__reg_write_data = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__csr[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT____Vcellout__registers0__gr[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regfile__DOT____Vcellinp__registers0__ew = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(14);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(12);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__regfile__DOT__muxcsr__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regfile__DOT__registers0__DOT__tmp = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__pcaddimmbridge = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__aluopcode = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__exu0__DOT__aluarg2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__alucontrol0__DOT__IRop = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__chosmuximm__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__logsig = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfsig = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltsig = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__carry_tmp = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__logres = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__addres = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__shfres = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__sltres = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgTmp_h1dc29214__0 = 0;
    vlSelf->top__DOT__exu0__DOT__branchcontrol0__DOT____VdfgTmp_h47a8aa33__0 = 0;
    vlSelf->top__DOT__wbu0__DOT__memread = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wbu0__DOT__wstrb = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__wbu0__DOT__bvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wbu0__DOT__rvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__random_count = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__memmask = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__rdatareg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__random_num = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__lsfr0__DOT__feedback = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_I(7);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(3);
    }
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__wbu0__DOT__mem__DOT__muxpc__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_u = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wbu0__DOT__memreadlen0__DOT__read_s = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(35);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__wbu0__DOT__muxpc__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->__VdfgTmp_hdd31f885__0 = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vdly__top__DOT__ifu0__DOT__pcbridge = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
