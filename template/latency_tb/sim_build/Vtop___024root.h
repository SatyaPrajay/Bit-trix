// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(instr,7,0);
    CData/*0:0*/ top__DOT__clk;
    CData/*0:0*/ top__DOT__rst;
    CData/*7:0*/ top__DOT__instr;
    CData/*3:0*/ top__DOT__opcode;
    CData/*1:0*/ top__DOT__rd;
    CData/*1:0*/ top__DOT__rs1;
    CData/*1:0*/ top__DOT__rs2;
    CData/*7:0*/ top__DOT__reg_out1;
    CData/*7:0*/ top__DOT__reg_out2;
    CData/*7:0*/ top__DOT__write_data;
    CData/*0:0*/ top__DOT__reg_write;
    CData/*7:0*/ top__DOT__ram_out;
    CData/*0:0*/ top__DOT__mem_write;
    CData/*0:0*/ top__DOT__regfile__DOT__clk;
    CData/*0:0*/ top__DOT__regfile__DOT__rst;
    CData/*0:0*/ top__DOT__regfile__DOT__wr_en;
    CData/*1:0*/ top__DOT__regfile__DOT__rd_addr;
    CData/*1:0*/ top__DOT__regfile__DOT__rs1_addr;
    CData/*1:0*/ top__DOT__regfile__DOT__rs2_addr;
    CData/*7:0*/ top__DOT__regfile__DOT__wr_data;
    CData/*7:0*/ top__DOT__regfile__DOT__rs1_data;
    CData/*7:0*/ top__DOT__regfile__DOT__rs2_data;
    CData/*0:0*/ top__DOT__alu__DOT__clk;
    CData/*0:0*/ top__DOT__alu__DOT__rst;
    CData/*3:0*/ top__DOT__alu__DOT__opcode;
    CData/*7:0*/ top__DOT__alu__DOT__a;
    CData/*7:0*/ top__DOT__alu__DOT__b;
    CData/*0:0*/ top__DOT__data_mem__DOT__clk;
    CData/*0:0*/ top__DOT__data_mem__DOT__wr_en;
    CData/*7:0*/ top__DOT__data_mem__DOT__addr;
    CData/*7:0*/ top__DOT__data_mem__DOT__wr_data;
    CData/*7:0*/ top__DOT__data_mem__DOT__rd_data;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ top__DOT__alu_out;
    SData/*15:0*/ top__DOT__alu__DOT__out;
    SData/*15:0*/ top__DOT__alu__DOT__acc;
    SData/*15:0*/ top__DOT__alu__DOT__a_ext;
    SData/*15:0*/ top__DOT__alu__DOT__b_ext;
    VL_OUTW(cycle_count,255,0,8);
    VlWide<8>/*255:0*/ top__DOT__cycle_count;
    IData/*31:0*/ top__DOT__regfile__DOT__i;
    IData/*31:0*/ top__DOT__data_mem__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 4> top__DOT__regfile__DOT__regs;
    VlUnpacked<CData/*7:0*/, 64> top__DOT__data_mem__DOT__mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ top__DOT__alu__DOT__WIDTH = 8U;
    static constexpr IData/*31:0*/ top__DOT__data_mem__DOT__DEPTH = 0x00000040U;
    static constexpr IData/*31:0*/ top__DOT__data_mem__DOT__ADDR_WIDTH = 8U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
