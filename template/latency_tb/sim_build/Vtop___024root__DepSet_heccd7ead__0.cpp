// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__instr = vlSelfRef.instr;
    vlSelfRef.cycle_count[0U] = vlSelfRef.top__DOT__cycle_count[0U];
    vlSelfRef.cycle_count[1U] = vlSelfRef.top__DOT__cycle_count[1U];
    vlSelfRef.cycle_count[2U] = vlSelfRef.top__DOT__cycle_count[2U];
    vlSelfRef.cycle_count[3U] = vlSelfRef.top__DOT__cycle_count[3U];
    vlSelfRef.cycle_count[4U] = vlSelfRef.top__DOT__cycle_count[4U];
    vlSelfRef.cycle_count[5U] = vlSelfRef.top__DOT__cycle_count[5U];
    vlSelfRef.cycle_count[6U] = vlSelfRef.top__DOT__cycle_count[6U];
    vlSelfRef.cycle_count[7U] = vlSelfRef.top__DOT__cycle_count[7U];
    vlSelfRef.top__DOT__rd = (3U & ((IData)(vlSelfRef.instr) 
                                    >> 2U));
    vlSelfRef.top__DOT__rst = vlSelfRef.rst;
    vlSelfRef.top__DOT__alu_out = vlSelfRef.top__DOT__alu__DOT__out;
    vlSelfRef.top__DOT__ram_out = vlSelfRef.top__DOT__data_mem__DOT__rd_data;
    vlSelfRef.top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.top__DOT__opcode = (0xfU & ((IData)(vlSelfRef.instr) 
                                          >> 4U));
    vlSelfRef.top__DOT__rs1 = (3U & (IData)(vlSelfRef.instr));
    vlSelfRef.top__DOT__regfile__DOT__rd_addr = vlSelfRef.top__DOT__rd;
    vlSelfRef.top__DOT__regfile__DOT__rst = vlSelfRef.top__DOT__rst;
    vlSelfRef.top__DOT__alu__DOT__rst = vlSelfRef.top__DOT__rst;
    vlSelfRef.top__DOT__regfile__DOT__clk = vlSelfRef.top__DOT__clk;
    vlSelfRef.top__DOT__alu__DOT__clk = vlSelfRef.top__DOT__clk;
    vlSelfRef.top__DOT__data_mem__DOT__clk = vlSelfRef.top__DOT__clk;
    vlSelfRef.top__DOT__alu__DOT__opcode = vlSelfRef.top__DOT__opcode;
    vlSelfRef.top__DOT__reg_write = 0U;
    vlSelfRef.top__DOT__mem_write = 0U;
    if ((8U & (IData)(vlSelfRef.top__DOT__opcode))) {
        vlSelfRef.top__DOT__reg_write = 0U;
        vlSelfRef.top__DOT__mem_write = 0U;
    } else if ((4U & (IData)(vlSelfRef.top__DOT__opcode))) {
        if ((2U & (IData)(vlSelfRef.top__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__opcode))) {
                vlSelfRef.top__DOT__reg_write = 0U;
            }
            vlSelfRef.top__DOT__mem_write = (1U & (~ (IData)(vlSelfRef.top__DOT__opcode)));
        } else {
            vlSelfRef.top__DOT__reg_write = 1U;
        }
    } else {
        vlSelfRef.top__DOT__reg_write = 1U;
    }
    vlSelfRef.top__DOT__write_data = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__opcode) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.top__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__opcode) 
                          >> 1U)))) {
                vlSelfRef.top__DOT__write_data = (0xffU 
                                                  & ((1U 
                                                      & (IData)(vlSelfRef.top__DOT__opcode))
                                                      ? (IData)(vlSelfRef.top__DOT__ram_out)
                                                      : (IData)(vlSelfRef.top__DOT__alu_out)));
            }
        } else {
            vlSelfRef.top__DOT__write_data = (0xffU 
                                              & (IData)(vlSelfRef.top__DOT__alu_out));
        }
    }
    vlSelfRef.top__DOT__regfile__DOT__rs1_addr = vlSelfRef.top__DOT__rs1;
    vlSelfRef.top__DOT__regfile__DOT__rs1_data = vlSelfRef.top__DOT__regfile__DOT__regs
        [vlSelfRef.top__DOT__rs1];
    vlSelfRef.top__DOT__rs2 = vlSelfRef.top__DOT__rs1;
    vlSelfRef.top__DOT__regfile__DOT__wr_en = vlSelfRef.top__DOT__reg_write;
    vlSelfRef.top__DOT__data_mem__DOT__wr_en = vlSelfRef.top__DOT__mem_write;
    vlSelfRef.top__DOT__regfile__DOT__wr_data = vlSelfRef.top__DOT__write_data;
    vlSelfRef.top__DOT__alu__DOT__a_ext = vlSelfRef.top__DOT__regfile__DOT__rs1_data;
    vlSelfRef.top__DOT__reg_out1 = vlSelfRef.top__DOT__regfile__DOT__rs1_data;
    vlSelfRef.top__DOT__regfile__DOT__rs2_addr = vlSelfRef.top__DOT__rs2;
    vlSelfRef.top__DOT__regfile__DOT__rs2_data = vlSelfRef.top__DOT__regfile__DOT__regs
        [vlSelfRef.top__DOT__rs2];
    vlSelfRef.top__DOT__alu__DOT__a = vlSelfRef.top__DOT__reg_out1;
    vlSelfRef.top__DOT__data_mem__DOT__wr_data = vlSelfRef.top__DOT__reg_out1;
    vlSelfRef.top__DOT__data_mem__DOT__addr = (0x3fU 
                                               & ((IData)(vlSelfRef.top__DOT__regfile__DOT__rs2_data) 
                                                  >> 0U));
    vlSelfRef.top__DOT__alu__DOT__b_ext = vlSelfRef.top__DOT__regfile__DOT__rs2_data;
    vlSelfRef.top__DOT__reg_out2 = vlSelfRef.top__DOT__regfile__DOT__rs2_data;
    vlSelfRef.top__DOT__alu__DOT__b = vlSelfRef.top__DOT__reg_out2;
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h4e9f510d_0;
extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9e67c271_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __Vdly__top__DOT__alu__DOT__acc;
    __Vdly__top__DOT__alu__DOT__acc = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__regs__v0;
    __VdlySet__top__DOT__regfile__DOT__regs__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__regfile__DOT__regs__v4;
    __VdlyVal__top__DOT__regfile__DOT__regs__v4 = 0;
    CData/*1:0*/ __VdlyDim0__top__DOT__regfile__DOT__regs__v4;
    __VdlyDim0__top__DOT__regfile__DOT__regs__v4 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__regs__v4;
    __VdlySet__top__DOT__regfile__DOT__regs__v4 = 0;
    VlWide<8>/*255:0*/ __Vtemp_2;
    // Body
    __Vdly__top__DOT__alu__DOT__acc = vlSelfRef.top__DOT__alu__DOT__acc;
    __VdlySet__top__DOT__regfile__DOT__regs__v0 = 0U;
    __VdlySet__top__DOT__regfile__DOT__regs__v4 = 0U;
    VL_ADD_W(8, __Vtemp_2, Vtop__ConstPool__CONST_h4e9f510d_0, vlSelfRef.top__DOT__cycle_count);
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__regfile__DOT__i = 1U;
        vlSelfRef.top__DOT__regfile__DOT__i = 2U;
        vlSelfRef.top__DOT__regfile__DOT__i = 3U;
        vlSelfRef.top__DOT__regfile__DOT__i = 4U;
        vlSelfRef.top__DOT__cycle_count[0U] = Vtop__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.top__DOT__cycle_count[1U] = Vtop__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.top__DOT__cycle_count[2U] = Vtop__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.top__DOT__cycle_count[3U] = Vtop__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.top__DOT__cycle_count[4U] = Vtop__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.top__DOT__cycle_count[5U] = Vtop__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.top__DOT__cycle_count[6U] = Vtop__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.top__DOT__cycle_count[7U] = Vtop__ConstPool__CONST_h9e67c271_0[7U];
        __VdlySet__top__DOT__regfile__DOT__regs__v0 = 1U;
        __Vdly__top__DOT__alu__DOT__acc = 0U;
        vlSelfRef.top__DOT__alu__DOT__out = 0U;
    } else {
        vlSelfRef.top__DOT__cycle_count[0U] = __Vtemp_2[0U];
        vlSelfRef.top__DOT__cycle_count[1U] = __Vtemp_2[1U];
        vlSelfRef.top__DOT__cycle_count[2U] = __Vtemp_2[2U];
        vlSelfRef.top__DOT__cycle_count[3U] = __Vtemp_2[3U];
        vlSelfRef.top__DOT__cycle_count[4U] = __Vtemp_2[4U];
        vlSelfRef.top__DOT__cycle_count[5U] = __Vtemp_2[5U];
        vlSelfRef.top__DOT__cycle_count[6U] = __Vtemp_2[6U];
        vlSelfRef.top__DOT__cycle_count[7U] = __Vtemp_2[7U];
        if (vlSelfRef.top__DOT__reg_write) {
            __VdlyVal__top__DOT__regfile__DOT__regs__v4 
                = vlSelfRef.top__DOT__write_data;
            __VdlyDim0__top__DOT__regfile__DOT__regs__v4 
                = vlSelfRef.top__DOT__rd;
            __VdlySet__top__DOT__regfile__DOT__regs__v4 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.top__DOT__opcode))) {
            vlSelfRef.top__DOT__alu__DOT__out = 0U;
        } else if ((4U & (IData)(vlSelfRef.top__DOT__opcode))) {
            vlSelfRef.top__DOT__alu__DOT__out = ((2U 
                                                  & (IData)(vlSelfRef.top__DOT__opcode))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__opcode))
                                                   ? 0U
                                                   : 
                                                  ((0U 
                                                    != (IData)(vlSelfRef.top__DOT__reg_out2))
                                                    ? 
                                                   (0xffffU 
                                                    & VL_DIV_III(16, (IData)(vlSelfRef.top__DOT__alu__DOT__a_ext), (IData)(vlSelfRef.top__DOT__alu__DOT__b_ext)))
                                                    : 0U)));
        } else if ((2U & (IData)(vlSelfRef.top__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__opcode))) {
                __Vdly__top__DOT__alu__DOT__acc = (0xffffU 
                                                   & ((IData)(vlSelfRef.top__DOT__alu__DOT__acc) 
                                                      + 
                                                      ((IData)(vlSelfRef.top__DOT__alu__DOT__a_ext) 
                                                       * (IData)(vlSelfRef.top__DOT__alu__DOT__b_ext))));
                vlSelfRef.top__DOT__alu__DOT__out = vlSelfRef.top__DOT__alu__DOT__acc;
            } else {
                vlSelfRef.top__DOT__alu__DOT__out = 
                    (0xffffU & ((IData)(vlSelfRef.top__DOT__alu__DOT__a_ext) 
                                * (IData)(vlSelfRef.top__DOT__alu__DOT__b_ext)));
            }
        } else {
            vlSelfRef.top__DOT__alu__DOT__out = (0xffffU 
                                                 & ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__opcode))
                                                     ? 
                                                    ((IData)(vlSelfRef.top__DOT__alu__DOT__a_ext) 
                                                     - (IData)(vlSelfRef.top__DOT__alu__DOT__b_ext))
                                                     : 
                                                    ((IData)(vlSelfRef.top__DOT__alu__DOT__a_ext) 
                                                     + (IData)(vlSelfRef.top__DOT__alu__DOT__b_ext))));
        }
    }
    if (__VdlySet__top__DOT__regfile__DOT__regs__v0) {
        vlSelfRef.top__DOT__regfile__DOT__regs[0U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__regs[1U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__regs[2U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__regs[3U] = 0U;
    }
    if (__VdlySet__top__DOT__regfile__DOT__regs__v4) {
        vlSelfRef.top__DOT__regfile__DOT__regs[__VdlyDim0__top__DOT__regfile__DOT__regs__v4] 
            = __VdlyVal__top__DOT__regfile__DOT__regs__v4;
    }
    vlSelfRef.top__DOT__alu__DOT__acc = __Vdly__top__DOT__alu__DOT__acc;
    vlSelfRef.cycle_count[0U] = vlSelfRef.top__DOT__cycle_count[0U];
    vlSelfRef.cycle_count[1U] = vlSelfRef.top__DOT__cycle_count[1U];
    vlSelfRef.cycle_count[2U] = vlSelfRef.top__DOT__cycle_count[2U];
    vlSelfRef.cycle_count[3U] = vlSelfRef.top__DOT__cycle_count[3U];
    vlSelfRef.cycle_count[4U] = vlSelfRef.top__DOT__cycle_count[4U];
    vlSelfRef.cycle_count[5U] = vlSelfRef.top__DOT__cycle_count[5U];
    vlSelfRef.cycle_count[6U] = vlSelfRef.top__DOT__cycle_count[6U];
    vlSelfRef.cycle_count[7U] = vlSelfRef.top__DOT__cycle_count[7U];
    vlSelfRef.top__DOT__regfile__DOT__rs1_data = vlSelfRef.top__DOT__regfile__DOT__regs
        [vlSelfRef.top__DOT__rs1];
    vlSelfRef.top__DOT__alu_out = vlSelfRef.top__DOT__alu__DOT__out;
    vlSelfRef.top__DOT__alu__DOT__a_ext = vlSelfRef.top__DOT__regfile__DOT__rs1_data;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__top__DOT__data_mem__DOT__mem__v0;
    __VdlyVal__top__DOT__data_mem__DOT__mem__v0 = 0;
    CData/*5:0*/ __VdlyDim0__top__DOT__data_mem__DOT__mem__v0;
    __VdlyDim0__top__DOT__data_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__data_mem__DOT__mem__v0;
    __VdlySet__top__DOT__data_mem__DOT__mem__v0 = 0;
    // Body
    __VdlySet__top__DOT__data_mem__DOT__mem__v0 = 0U;
    if (vlSelfRef.top__DOT__mem_write) {
        __VdlyVal__top__DOT__data_mem__DOT__mem__v0 
            = vlSelfRef.top__DOT__reg_out1;
        __VdlyDim0__top__DOT__data_mem__DOT__mem__v0 
            = (0x3fU & (IData)(vlSelfRef.top__DOT__regfile__DOT__rs2_data));
        __VdlySet__top__DOT__data_mem__DOT__mem__v0 = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__mem_write)))) {
        vlSelfRef.top__DOT__data_mem__DOT__rd_data 
            = vlSelfRef.top__DOT__data_mem__DOT__mem
            [(0x3fU & (IData)(vlSelfRef.top__DOT__regfile__DOT__rs2_data))];
    }
    if (__VdlySet__top__DOT__data_mem__DOT__mem__v0) {
        vlSelfRef.top__DOT__data_mem__DOT__mem[__VdlyDim0__top__DOT__data_mem__DOT__mem__v0] 
            = __VdlyVal__top__DOT__data_mem__DOT__mem__v0;
    }
    vlSelfRef.top__DOT__ram_out = vlSelfRef.top__DOT__data_mem__DOT__rd_data;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__reg_out1 = vlSelfRef.top__DOT__regfile__DOT__rs1_data;
    vlSelfRef.top__DOT__regfile__DOT__rs2_data = vlSelfRef.top__DOT__regfile__DOT__regs
        [vlSelfRef.top__DOT__rs2];
    vlSelfRef.top__DOT__alu__DOT__a = vlSelfRef.top__DOT__reg_out1;
    vlSelfRef.top__DOT__data_mem__DOT__wr_data = vlSelfRef.top__DOT__reg_out1;
    vlSelfRef.top__DOT__data_mem__DOT__addr = (0x3fU 
                                               & ((IData)(vlSelfRef.top__DOT__regfile__DOT__rs2_data) 
                                                  >> 0U));
    vlSelfRef.top__DOT__alu__DOT__b_ext = vlSelfRef.top__DOT__regfile__DOT__rs2_data;
    vlSelfRef.top__DOT__reg_out2 = vlSelfRef.top__DOT__regfile__DOT__rs2_data;
    vlSelfRef.top__DOT__alu__DOT__b = vlSelfRef.top__DOT__reg_out2;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__write_data = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__opcode) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.top__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__opcode) 
                          >> 1U)))) {
                vlSelfRef.top__DOT__write_data = (0xffU 
                                                  & ((1U 
                                                      & (IData)(vlSelfRef.top__DOT__opcode))
                                                      ? (IData)(vlSelfRef.top__DOT__ram_out)
                                                      : (IData)(vlSelfRef.top__DOT__alu_out)));
            }
        } else {
            vlSelfRef.top__DOT__write_data = (0xffU 
                                              & (IData)(vlSelfRef.top__DOT__alu_out));
        }
    }
    vlSelfRef.top__DOT__regfile__DOT__wr_data = vlSelfRef.top__DOT__write_data;
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../src/top.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../src/top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../src/top.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
