// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst));
    bufp->chgCData(oldp+2,(vlSelfRef.instr),8);
    bufp->chgWData(oldp+3,(vlSelfRef.cycle_count),256);
    bufp->chgBit(oldp+11,(vlSelfRef.top__DOT__clk));
    bufp->chgBit(oldp+12,(vlSelfRef.top__DOT__rst));
    bufp->chgCData(oldp+13,(vlSelfRef.top__DOT__instr),8);
    bufp->chgWData(oldp+14,(vlSelfRef.top__DOT__cycle_count),256);
    bufp->chgCData(oldp+22,(vlSelfRef.top__DOT__opcode),4);
    bufp->chgCData(oldp+23,(vlSelfRef.top__DOT__rd),2);
    bufp->chgCData(oldp+24,(vlSelfRef.top__DOT__rs1),2);
    bufp->chgCData(oldp+25,(vlSelfRef.top__DOT__rs2),2);
    bufp->chgCData(oldp+26,(vlSelfRef.top__DOT__reg_out1),8);
    bufp->chgCData(oldp+27,(vlSelfRef.top__DOT__reg_out2),8);
    bufp->chgCData(oldp+28,(vlSelfRef.top__DOT__write_data),8);
    bufp->chgBit(oldp+29,(vlSelfRef.top__DOT__reg_write));
    bufp->chgSData(oldp+30,(vlSelfRef.top__DOT__alu_out),16);
    bufp->chgCData(oldp+31,(vlSelfRef.top__DOT__ram_out),8);
    bufp->chgBit(oldp+32,(vlSelfRef.top__DOT__mem_write));
    bufp->chgBit(oldp+33,(vlSelfRef.top__DOT__alu__DOT__clk));
    bufp->chgBit(oldp+34,(vlSelfRef.top__DOT__alu__DOT__rst));
    bufp->chgCData(oldp+35,(vlSelfRef.top__DOT__alu__DOT__opcode),4);
    bufp->chgCData(oldp+36,(vlSelfRef.top__DOT__alu__DOT__a),8);
    bufp->chgCData(oldp+37,(vlSelfRef.top__DOT__alu__DOT__b),8);
    bufp->chgSData(oldp+38,(vlSelfRef.top__DOT__alu__DOT__out),16);
    bufp->chgSData(oldp+39,(vlSelfRef.top__DOT__alu__DOT__acc),16);
    bufp->chgSData(oldp+40,(vlSelfRef.top__DOT__alu__DOT__a_ext),16);
    bufp->chgSData(oldp+41,(vlSelfRef.top__DOT__alu__DOT__b_ext),16);
    bufp->chgBit(oldp+42,(vlSelfRef.top__DOT__data_mem__DOT__clk));
    bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__data_mem__DOT__wr_en));
    bufp->chgCData(oldp+44,(vlSelfRef.top__DOT__data_mem__DOT__addr),8);
    bufp->chgCData(oldp+45,(vlSelfRef.top__DOT__data_mem__DOT__wr_data),8);
    bufp->chgCData(oldp+46,(vlSelfRef.top__DOT__data_mem__DOT__rd_data),8);
    bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__data_mem__DOT__i),32);
    bufp->chgBit(oldp+48,(vlSelfRef.top__DOT__regfile__DOT__clk));
    bufp->chgBit(oldp+49,(vlSelfRef.top__DOT__regfile__DOT__rst));
    bufp->chgBit(oldp+50,(vlSelfRef.top__DOT__regfile__DOT__wr_en));
    bufp->chgCData(oldp+51,(vlSelfRef.top__DOT__regfile__DOT__rd_addr),2);
    bufp->chgCData(oldp+52,(vlSelfRef.top__DOT__regfile__DOT__rs1_addr),2);
    bufp->chgCData(oldp+53,(vlSelfRef.top__DOT__regfile__DOT__rs2_addr),2);
    bufp->chgCData(oldp+54,(vlSelfRef.top__DOT__regfile__DOT__wr_data),8);
    bufp->chgCData(oldp+55,(vlSelfRef.top__DOT__regfile__DOT__rs1_data),8);
    bufp->chgCData(oldp+56,(vlSelfRef.top__DOT__regfile__DOT__rs2_data),8);
    bufp->chgCData(oldp+57,(vlSelfRef.top__DOT__regfile__DOT__regs[0]),8);
    bufp->chgCData(oldp+58,(vlSelfRef.top__DOT__regfile__DOT__regs[1]),8);
    bufp->chgCData(oldp+59,(vlSelfRef.top__DOT__regfile__DOT__regs[2]),8);
    bufp->chgCData(oldp+60,(vlSelfRef.top__DOT__regfile__DOT__regs[3]),8);
    bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__regfile__DOT__i),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
