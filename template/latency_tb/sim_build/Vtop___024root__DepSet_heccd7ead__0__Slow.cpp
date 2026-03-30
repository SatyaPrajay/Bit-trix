// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__data_mem__DOT__mem[0U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 1U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[1U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 2U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[2U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 3U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[3U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 4U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[4U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 5U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[5U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 6U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[6U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 7U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[7U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 8U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[8U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 9U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[9U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0xaU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0xaU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0xbU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0xbU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0xcU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0xcU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0xdU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0xdU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0xeU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0xeU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0xfU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0xfU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x10U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x10U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x11U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x11U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x12U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x12U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x13U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x13U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x14U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x14U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x15U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x15U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x16U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x16U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x17U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x17U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x18U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x18U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x19U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x19U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x1aU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x1aU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x1bU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x1bU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x1cU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x1cU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x1dU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x1dU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x1eU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x1eU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x1fU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x1fU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x20U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x20U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x21U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x21U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x22U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x22U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x23U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x23U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x24U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x24U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x25U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x25U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x26U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x26U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x27U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x27U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x28U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x28U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x29U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x29U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x2aU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x2aU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x2bU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x2bU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x2cU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x2cU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x2dU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x2dU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x2eU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x2eU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x2fU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x2fU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x30U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x30U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x31U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x31U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x32U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x32U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x33U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x33U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x34U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x34U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x35U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x35U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x36U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x36U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x37U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x37U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x38U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x38U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x39U;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x39U] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x3aU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x3aU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x3bU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x3bU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x3cU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x3cU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x3dU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x3dU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x3eU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x3eU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x3fU;
    vlSelfRef.top__DOT__data_mem__DOT__mem[0x3fU] = 0U;
    vlSelfRef.top__DOT__data_mem__DOT__i = 0x40U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../src/top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->instr = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(256, vlSelf->cycle_count);
    vlSelf->top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__instr = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(256, vlSelf->top__DOT__cycle_count);
    vlSelf->top__DOT__opcode = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__rd = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__rs1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__rs2 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__reg_out1 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__reg_out2 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__write_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__alu_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__ram_out = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__mem_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regfile__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regfile__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regfile__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__regfile__DOT__rd_addr = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__regfile__DOT__rs1_addr = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__regfile__DOT__rs2_addr = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__regfile__DOT__wr_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__regfile__DOT__rs1_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__regfile__DOT__rs2_data = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__regs[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__regfile__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__alu__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__alu__DOT__opcode = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__alu__DOT__a = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__alu__DOT__b = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__alu__DOT__out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__alu__DOT__acc = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__alu__DOT__a_ext = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__alu__DOT__b_ext = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__data_mem__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__data_mem__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__data_mem__DOT__addr = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__data_mem__DOT__wr_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__data_mem__DOT__rd_data = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->top__DOT__data_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__data_mem__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}
