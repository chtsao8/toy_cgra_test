// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2021.2 (win64) Build 3367213 Tue Oct 19 02:48:09 MDT 2021
// Date        : Wed Apr  6 21:40:32 2022
// Host        : CHARLES-PC running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/CGRA_IO_TEST.gen/sources_1/bd/cgra_test_design/ip/cgra_test_design_clk_wiz_0_0/cgra_test_design_clk_wiz_0_0_stub.v
// Design      : cgra_test_design_clk_wiz_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module cgra_test_design_clk_wiz_0_0(io_clk, internal_clk, resetn, clk_in1)
/* synthesis syn_black_box black_box_pad_pin="io_clk,internal_clk,resetn,clk_in1" */;
  output io_clk;
  output internal_clk;
  input resetn;
  input clk_in1;
endmodule
