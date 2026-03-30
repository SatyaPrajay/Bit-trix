// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_top);
    __Vhier.remove(&__Vscope_top, &__Vscope_top__alu);
    __Vhier.remove(&__Vscope_top, &__Vscope_top__data_mem);
    __Vhier.remove(&__Vscope_top, &__Vscope_top__regfile);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(107);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_top.configure(this, name(), "top", "top", "top", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_top__alu.configure(this, name(), "top.alu", "alu", "your_some_unit", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_top__data_mem.configure(this, name(), "top.data_mem", "data_mem", "ram", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_top__regfile.configure(this, name(), "top.regfile", "regfile", "reg_file", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_top);
    __Vhier.add(&__Vscope_top, &__Vscope_top__alu);
    __Vhier.add(&__Vscope_top, &__Vscope_top__data_mem);
    __Vhier.add(&__Vscope_top, &__Vscope_top__regfile);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"cycle_count", &(TOP.cycle_count), false, VLVT_WDATA,VLVD_OUT|VLVF_PUB_RW,0,1 ,255,0);
        __Vscope_TOP.varInsert(__Vfinal,"instr", &(TOP.instr), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_top.varInsert(__Vfinal,"alu_out", &(TOP.top__DOT__alu_out), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_top.varInsert(__Vfinal,"clk", &(TOP.top__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top.varInsert(__Vfinal,"cycle_count", &(TOP.top__DOT__cycle_count), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,255,0);
        __Vscope_top.varInsert(__Vfinal,"instr", &(TOP.top__DOT__instr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top.varInsert(__Vfinal,"mem_write", &(TOP.top__DOT__mem_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top.varInsert(__Vfinal,"opcode", &(TOP.top__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_top.varInsert(__Vfinal,"ram_out", &(TOP.top__DOT__ram_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top.varInsert(__Vfinal,"rd", &(TOP.top__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_top.varInsert(__Vfinal,"reg_out1", &(TOP.top__DOT__reg_out1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top.varInsert(__Vfinal,"reg_out2", &(TOP.top__DOT__reg_out2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top.varInsert(__Vfinal,"reg_write", &(TOP.top__DOT__reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top.varInsert(__Vfinal,"rs1", &(TOP.top__DOT__rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_top.varInsert(__Vfinal,"rs2", &(TOP.top__DOT__rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_top.varInsert(__Vfinal,"rst", &(TOP.top__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top.varInsert(__Vfinal,"write_data", &(TOP.top__DOT__write_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__alu.varInsert(__Vfinal,"WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__alu__DOT__WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top__alu.varInsert(__Vfinal,"a", &(TOP.top__DOT__alu__DOT__a), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__alu.varInsert(__Vfinal,"a_ext", &(TOP.top__DOT__alu__DOT__a_ext), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_top__alu.varInsert(__Vfinal,"acc", &(TOP.top__DOT__alu__DOT__acc), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_top__alu.varInsert(__Vfinal,"b", &(TOP.top__DOT__alu__DOT__b), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__alu.varInsert(__Vfinal,"b_ext", &(TOP.top__DOT__alu__DOT__b_ext), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_top__alu.varInsert(__Vfinal,"clk", &(TOP.top__DOT__alu__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top__alu.varInsert(__Vfinal,"opcode", &(TOP.top__DOT__alu__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_top__alu.varInsert(__Vfinal,"out", &(TOP.top__DOT__alu__DOT__out), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_top__alu.varInsert(__Vfinal,"rst", &(TOP.top__DOT__alu__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__data_mem__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.top__DOT__data_mem__DOT__DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"addr", &(TOP.top__DOT__data_mem__DOT__addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"clk", &(TOP.top__DOT__data_mem__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"i", &(TOP.top__DOT__data_mem__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"mem", &(TOP.top__DOT__data_mem__DOT__mem), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,63 ,7,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"rd_data", &(TOP.top__DOT__data_mem__DOT__rd_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"wr_data", &(TOP.top__DOT__data_mem__DOT__wr_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__data_mem.varInsert(__Vfinal,"wr_en", &(TOP.top__DOT__data_mem__DOT__wr_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"clk", &(TOP.top__DOT__regfile__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"i", &(TOP.top__DOT__regfile__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"rd_addr", &(TOP.top__DOT__regfile__DOT__rd_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"regs", &(TOP.top__DOT__regfile__DOT__regs), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,3 ,7,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"rs1_addr", &(TOP.top__DOT__regfile__DOT__rs1_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"rs1_data", &(TOP.top__DOT__regfile__DOT__rs1_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"rs2_addr", &(TOP.top__DOT__regfile__DOT__rs2_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"rs2_data", &(TOP.top__DOT__regfile__DOT__rs2_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"rst", &(TOP.top__DOT__regfile__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"wr_data", &(TOP.top__DOT__regfile__DOT__wr_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_top__regfile.varInsert(__Vfinal,"wr_en", &(TOP.top__DOT__regfile__DOT__wr_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
