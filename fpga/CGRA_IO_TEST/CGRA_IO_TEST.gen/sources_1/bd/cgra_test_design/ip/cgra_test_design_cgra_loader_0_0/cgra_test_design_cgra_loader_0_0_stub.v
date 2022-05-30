// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2021.2 (win64) Build 3367213 Tue Oct 19 02:48:09 MDT 2021
// Date        : Wed Apr  6 21:40:33 2022
// Host        : CHARLES-PC running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/CGRA_IO_TEST.gen/sources_1/bd/cgra_test_design/ip/cgra_test_design_cgra_loader_0_0/cgra_test_design_cgra_loader_0_0_stub.v
// Design      : cgra_test_design_cgra_loader_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "cgra_loader,Vivado 2021.2" *)
module cgra_test_design_cgra_loader_0_0(clk, btn_r, btn_s, gpio_out_16, gpio_out_1, io_rst)
/* synthesis syn_black_box black_box_pad_pin="clk,btn_r,btn_s,gpio_out_16[3:0],gpio_out_1,io_rst" */;
  input clk;
  input btn_r;
  input btn_s;
  output [3:0]gpio_out_16;
  output gpio_out_1;
  output io_rst;
endmodule
