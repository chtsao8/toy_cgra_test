// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2021.2 (win64) Build 3367213 Tue Oct 19 02:48:09 MDT 2021
// Date        : Wed Apr  6 21:40:33 2022
// Host        : CHARLES-PC running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               c:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/CGRA_IO_TEST.gen/sources_1/bd/cgra_test_design/ip/cgra_test_design_cgra_loader_0_0/cgra_test_design_cgra_loader_0_0_sim_netlist.v
// Design      : cgra_test_design_cgra_loader_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "cgra_test_design_cgra_loader_0_0,cgra_loader,{}" *) (* DowngradeIPIdentifiedWarnings = "yes" *) (* IP_DEFINITION_SOURCE = "module_ref" *) 
(* X_CORE_INFO = "cgra_loader,Vivado 2021.2" *) 
(* NotValidForBitStream *)
module cgra_test_design_cgra_loader_0_0
   (clk,
    btn_r,
    btn_s,
    gpio_out_16,
    gpio_out_1,
    io_rst);
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 clk CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME clk, FREQ_HZ 10000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN /clk_wiz_0_clk_out1, INSERT_VIP 0" *) input clk;
  input btn_r;
  input btn_s;
  output [3:0]gpio_out_16;
  output gpio_out_1;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 io_rst RST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME io_rst, POLARITY ACTIVE_LOW, INSERT_VIP 0" *) output io_rst;

  wire btn_r;
  wire btn_s;
  wire clk;
  wire gpio_out_1;
  wire [3:0]gpio_out_16;

  assign io_rst = btn_r;
  cgra_test_design_cgra_loader_0_0_cgra_loader inst
       (.btn_r(btn_r),
        .btn_s(btn_s),
        .clk(clk),
        .gpio_out_1(gpio_out_1),
        .gpio_out_16(gpio_out_16));
endmodule

(* ORIG_REF_NAME = "brute_force_synchronizer" *) 
module cgra_test_design_cgra_loader_0_0_brute_force_synchronizer
   (button_sync,
    btn_s,
    clk);
  output button_sync;
  input btn_s;
  input clk;

  wire btn_s;
  wire button_sync;
  wire clk;
  wire ff1_n_0;
  wire ff2_n_0;

  cgra_test_design_cgra_loader_0_0_dff ff1
       (.btn_s(btn_s),
        .clk(clk),
        .\q_reg[0]_0 (ff1_n_0));
  cgra_test_design_cgra_loader_0_0_dff_0 ff2
       (.clk(clk),
        .\q_reg[0]_0 (ff2_n_0),
        .\q_reg[0]_1 (ff1_n_0));
  cgra_test_design_cgra_loader_0_0_dff_1 ff3
       (.button_sync(button_sync),
        .clk(clk),
        .\q_reg[0]_0 (ff2_n_0));
endmodule

(* ORIG_REF_NAME = "button_press_unit" *) 
module cgra_test_design_cgra_loader_0_0_button_press_unit
   (last_value,
    Q,
    btn_r,
    clk,
    btn_s);
  output last_value;
  output [0:0]Q;
  input btn_r;
  input clk;
  input btn_s;

  wire [0:0]Q;
  wire btn_r;
  wire btn_s;
  wire button_sync;
  wire clk;
  wire last_value;

  cgra_test_design_cgra_loader_0_0_debouncer debounce
       (.Q(Q),
        .btn_r(btn_r),
        .button_sync(button_sync),
        .clk(clk));
  cgra_test_design_cgra_loader_0_0_one_pulse one_pulse
       (.Q(Q),
        .btn_r(btn_r),
        .clk(clk),
        .last_value(last_value));
  cgra_test_design_cgra_loader_0_0_brute_force_synchronizer sync
       (.btn_s(btn_s),
        .button_sync(button_sync),
        .clk(clk));
endmodule

(* ORIG_REF_NAME = "cgra_loader" *) 
module cgra_test_design_cgra_loader_0_0_cgra_loader
   (gpio_out_16,
    gpio_out_1,
    btn_r,
    clk,
    btn_s);
  output [3:0]gpio_out_16;
  output gpio_out_1;
  input btn_r;
  input clk;
  input btn_s;

  wire btn_r;
  wire btn_s;
  wire button_debounced;
  wire clk;
  wire [3:0]count;
  wire counter_n_4;
  wire en0;
  wire gpio_out_1;
  wire [3:0]gpio_out_16;
  wire \one_pulse/last_value ;

  cgra_test_design_cgra_loader_0_0_dffre counter
       (.btn_r(btn_r),
        .clk(clk),
        .count(count),
        .en0(en0),
        .\q_reg[5]_0 (counter_n_4));
  cgra_test_design_cgra_loader_0_0_button_press_unit start_btn
       (.Q(button_debounced),
        .btn_r(btn_r),
        .btn_s(btn_s),
        .clk(clk),
        .last_value(\one_pulse/last_value ));
  cgra_test_design_cgra_loader_0_0_dffr__parameterized0 state_reg
       (.Q(button_debounced),
        .btn_r(btn_r),
        .clk(clk),
        .count(count),
        .en0(en0),
        .gpio_out_1(gpio_out_1),
        .gpio_out_16(gpio_out_16),
        .last_value(\one_pulse/last_value ),
        .\q_reg[1]_0 (counter_n_4));
endmodule

(* ORIG_REF_NAME = "debouncer" *) 
module cgra_test_design_cgra_loader_0_0_debouncer
   (Q,
    clk,
    button_sync,
    btn_r);
  output [0:0]Q;
  input clk;
  input button_sync;
  input btn_r;

  wire [0:0]Q;
  wire btn_r;
  wire button_sync;
  wire clk;
  wire counter_n_0;
  wire [1:1]current_state_q;
  wire state_n_2;

  cgra_test_design_cgra_loader_0_0_dffr counter
       (.D(counter_n_0),
        .Q({current_state_q,Q}),
        .clk(clk),
        .\q_reg[19]_0 (state_n_2));
  cgra_test_design_cgra_loader_0_0_dffr__parameterized0_2 state
       (.D(counter_n_0),
        .Q({current_state_q,Q}),
        .btn_r(btn_r),
        .button_sync(button_sync),
        .clk(clk),
        .\q_reg[0]_0 (state_n_2));
endmodule

(* ORIG_REF_NAME = "dff" *) 
module cgra_test_design_cgra_loader_0_0_dff
   (\q_reg[0]_0 ,
    btn_s,
    clk);
  output \q_reg[0]_0 ;
  input btn_s;
  input clk;

  wire btn_s;
  wire clk;
  wire \q_reg[0]_0 ;

  FDRE \q_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(btn_s),
        .Q(\q_reg[0]_0 ),
        .R(1'b0));
endmodule

(* ORIG_REF_NAME = "dff" *) 
module cgra_test_design_cgra_loader_0_0_dff_0
   (\q_reg[0]_0 ,
    \q_reg[0]_1 ,
    clk);
  output \q_reg[0]_0 ;
  input \q_reg[0]_1 ;
  input clk;

  wire clk;
  wire \q_reg[0]_0 ;
  wire \q_reg[0]_1 ;

  FDRE \q_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[0]_1 ),
        .Q(\q_reg[0]_0 ),
        .R(1'b0));
endmodule

(* ORIG_REF_NAME = "dff" *) 
module cgra_test_design_cgra_loader_0_0_dff_1
   (button_sync,
    \q_reg[0]_0 ,
    clk);
  output button_sync;
  input \q_reg[0]_0 ;
  input clk;

  wire button_sync;
  wire clk;
  wire \q_reg[0]_0 ;

  FDRE \q_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[0]_0 ),
        .Q(button_sync),
        .R(1'b0));
endmodule

(* ORIG_REF_NAME = "dffr" *) 
module cgra_test_design_cgra_loader_0_0_dffr
   (D,
    \q_reg[19]_0 ,
    clk,
    Q);
  output [0:0]D;
  input \q_reg[19]_0 ;
  input clk;
  input [1:0]Q;

  wire [0:0]D;
  wire [1:0]Q;
  wire clk;
  wire \q[0]_i_3_n_0 ;
  wire \q[1]_i_2__0_n_0 ;
  wire \q[1]_i_3__0_n_0 ;
  wire \q[1]_i_4__0_n_0 ;
  wire \q[1]_i_5_n_0 ;
  wire \q[1]_i_6_n_0 ;
  wire \q[1]_i_7_n_0 ;
  wire \q[1]_i_8_n_0 ;
  wire \q[1]_i_9_n_0 ;
  wire [19:0]q_reg;
  wire \q_reg[0]_i_2_n_0 ;
  wire \q_reg[0]_i_2_n_1 ;
  wire \q_reg[0]_i_2_n_2 ;
  wire \q_reg[0]_i_2_n_3 ;
  wire \q_reg[0]_i_2_n_4 ;
  wire \q_reg[0]_i_2_n_5 ;
  wire \q_reg[0]_i_2_n_6 ;
  wire \q_reg[0]_i_2_n_7 ;
  wire \q_reg[12]_i_1_n_0 ;
  wire \q_reg[12]_i_1_n_1 ;
  wire \q_reg[12]_i_1_n_2 ;
  wire \q_reg[12]_i_1_n_3 ;
  wire \q_reg[12]_i_1_n_4 ;
  wire \q_reg[12]_i_1_n_5 ;
  wire \q_reg[12]_i_1_n_6 ;
  wire \q_reg[12]_i_1_n_7 ;
  wire \q_reg[16]_i_1_n_1 ;
  wire \q_reg[16]_i_1_n_2 ;
  wire \q_reg[16]_i_1_n_3 ;
  wire \q_reg[16]_i_1_n_4 ;
  wire \q_reg[16]_i_1_n_5 ;
  wire \q_reg[16]_i_1_n_6 ;
  wire \q_reg[16]_i_1_n_7 ;
  wire \q_reg[19]_0 ;
  wire \q_reg[4]_i_1_n_0 ;
  wire \q_reg[4]_i_1_n_1 ;
  wire \q_reg[4]_i_1_n_2 ;
  wire \q_reg[4]_i_1_n_3 ;
  wire \q_reg[4]_i_1_n_4 ;
  wire \q_reg[4]_i_1_n_5 ;
  wire \q_reg[4]_i_1_n_6 ;
  wire \q_reg[4]_i_1_n_7 ;
  wire \q_reg[8]_i_1_n_0 ;
  wire \q_reg[8]_i_1_n_1 ;
  wire \q_reg[8]_i_1_n_2 ;
  wire \q_reg[8]_i_1_n_3 ;
  wire \q_reg[8]_i_1_n_4 ;
  wire \q_reg[8]_i_1_n_5 ;
  wire \q_reg[8]_i_1_n_6 ;
  wire \q_reg[8]_i_1_n_7 ;
  wire [3:3]\NLW_q_reg[16]_i_1_CO_UNCONNECTED ;

  LUT1 #(
    .INIT(2'h1)) 
    \q[0]_i_3 
       (.I0(q_reg[0]),
        .O(\q[0]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'hFEEE)) 
    \q[1]_i_1__0 
       (.I0(\q[1]_i_2__0_n_0 ),
        .I1(\q[1]_i_3__0_n_0 ),
        .I2(Q[1]),
        .I3(Q[0]),
        .O(D));
  LUT6 #(
    .INIT(64'h0000000000000080)) 
    \q[1]_i_2__0 
       (.I0(\q[1]_i_4__0_n_0 ),
        .I1(\q[1]_i_5_n_0 ),
        .I2(\q[1]_i_6_n_0 ),
        .I3(q_reg[2]),
        .I4(q_reg[1]),
        .I5(q_reg[0]),
        .O(\q[1]_i_2__0_n_0 ));
  LUT6 #(
    .INIT(64'h8000000000000000)) 
    \q[1]_i_3__0 
       (.I0(\q[1]_i_7_n_0 ),
        .I1(\q[1]_i_8_n_0 ),
        .I2(\q[1]_i_9_n_0 ),
        .I3(q_reg[2]),
        .I4(q_reg[1]),
        .I5(q_reg[0]),
        .O(\q[1]_i_3__0_n_0 ));
  LUT6 #(
    .INIT(64'h0000000000000001)) 
    \q[1]_i_4__0 
       (.I0(q_reg[11]),
        .I1(q_reg[12]),
        .I2(q_reg[9]),
        .I3(q_reg[10]),
        .I4(q_reg[14]),
        .I5(q_reg[13]),
        .O(\q[1]_i_4__0_n_0 ));
  LUT6 #(
    .INIT(64'h0000000000000001)) 
    \q[1]_i_5 
       (.I0(q_reg[5]),
        .I1(q_reg[6]),
        .I2(q_reg[3]),
        .I3(q_reg[4]),
        .I4(q_reg[8]),
        .I5(q_reg[7]),
        .O(\q[1]_i_5_n_0 ));
  LUT6 #(
    .INIT(64'h0000000100000000)) 
    \q[1]_i_6 
       (.I0(q_reg[17]),
        .I1(q_reg[18]),
        .I2(q_reg[15]),
        .I3(q_reg[16]),
        .I4(q_reg[19]),
        .I5(Q[1]),
        .O(\q[1]_i_6_n_0 ));
  LUT6 #(
    .INIT(64'h8000000000000000)) 
    \q[1]_i_7 
       (.I0(q_reg[11]),
        .I1(q_reg[12]),
        .I2(q_reg[9]),
        .I3(q_reg[10]),
        .I4(q_reg[14]),
        .I5(q_reg[13]),
        .O(\q[1]_i_7_n_0 ));
  LUT6 #(
    .INIT(64'h8000000000000000)) 
    \q[1]_i_8 
       (.I0(q_reg[5]),
        .I1(q_reg[6]),
        .I2(q_reg[3]),
        .I3(q_reg[4]),
        .I4(q_reg[8]),
        .I5(q_reg[7]),
        .O(\q[1]_i_8_n_0 ));
  LUT6 #(
    .INIT(64'h8000000000000000)) 
    \q[1]_i_9 
       (.I0(q_reg[17]),
        .I1(q_reg[18]),
        .I2(q_reg[15]),
        .I3(q_reg[16]),
        .I4(Q[0]),
        .I5(q_reg[19]),
        .O(\q[1]_i_9_n_0 ));
  FDRE \q_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[0]_i_2_n_7 ),
        .Q(q_reg[0]),
        .R(\q_reg[19]_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[0]_i_2 
       (.CI(1'b0),
        .CO({\q_reg[0]_i_2_n_0 ,\q_reg[0]_i_2_n_1 ,\q_reg[0]_i_2_n_2 ,\q_reg[0]_i_2_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b1}),
        .O({\q_reg[0]_i_2_n_4 ,\q_reg[0]_i_2_n_5 ,\q_reg[0]_i_2_n_6 ,\q_reg[0]_i_2_n_7 }),
        .S({q_reg[3:1],\q[0]_i_3_n_0 }));
  FDRE \q_reg[10] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[8]_i_1_n_5 ),
        .Q(q_reg[10]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[11] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[8]_i_1_n_4 ),
        .Q(q_reg[11]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[12] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[12]_i_1_n_7 ),
        .Q(q_reg[12]),
        .R(\q_reg[19]_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[12]_i_1 
       (.CI(\q_reg[8]_i_1_n_0 ),
        .CO({\q_reg[12]_i_1_n_0 ,\q_reg[12]_i_1_n_1 ,\q_reg[12]_i_1_n_2 ,\q_reg[12]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\q_reg[12]_i_1_n_4 ,\q_reg[12]_i_1_n_5 ,\q_reg[12]_i_1_n_6 ,\q_reg[12]_i_1_n_7 }),
        .S(q_reg[15:12]));
  FDRE \q_reg[13] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[12]_i_1_n_6 ),
        .Q(q_reg[13]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[14] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[12]_i_1_n_5 ),
        .Q(q_reg[14]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[15] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[12]_i_1_n_4 ),
        .Q(q_reg[15]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[16] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[16]_i_1_n_7 ),
        .Q(q_reg[16]),
        .R(\q_reg[19]_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[16]_i_1 
       (.CI(\q_reg[12]_i_1_n_0 ),
        .CO({\NLW_q_reg[16]_i_1_CO_UNCONNECTED [3],\q_reg[16]_i_1_n_1 ,\q_reg[16]_i_1_n_2 ,\q_reg[16]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\q_reg[16]_i_1_n_4 ,\q_reg[16]_i_1_n_5 ,\q_reg[16]_i_1_n_6 ,\q_reg[16]_i_1_n_7 }),
        .S(q_reg[19:16]));
  FDRE \q_reg[17] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[16]_i_1_n_6 ),
        .Q(q_reg[17]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[18] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[16]_i_1_n_5 ),
        .Q(q_reg[18]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[19] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[16]_i_1_n_4 ),
        .Q(q_reg[19]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[1] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[0]_i_2_n_6 ),
        .Q(q_reg[1]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[2] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[0]_i_2_n_5 ),
        .Q(q_reg[2]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[3] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[0]_i_2_n_4 ),
        .Q(q_reg[3]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[4] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[4]_i_1_n_7 ),
        .Q(q_reg[4]),
        .R(\q_reg[19]_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[4]_i_1 
       (.CI(\q_reg[0]_i_2_n_0 ),
        .CO({\q_reg[4]_i_1_n_0 ,\q_reg[4]_i_1_n_1 ,\q_reg[4]_i_1_n_2 ,\q_reg[4]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\q_reg[4]_i_1_n_4 ,\q_reg[4]_i_1_n_5 ,\q_reg[4]_i_1_n_6 ,\q_reg[4]_i_1_n_7 }),
        .S(q_reg[7:4]));
  FDRE \q_reg[5] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[4]_i_1_n_6 ),
        .Q(q_reg[5]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[6] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[4]_i_1_n_5 ),
        .Q(q_reg[6]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[7] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[4]_i_1_n_4 ),
        .Q(q_reg[7]),
        .R(\q_reg[19]_0 ));
  FDRE \q_reg[8] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[8]_i_1_n_7 ),
        .Q(q_reg[8]),
        .R(\q_reg[19]_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[8]_i_1 
       (.CI(\q_reg[4]_i_1_n_0 ),
        .CO({\q_reg[8]_i_1_n_0 ,\q_reg[8]_i_1_n_1 ,\q_reg[8]_i_1_n_2 ,\q_reg[8]_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\q_reg[8]_i_1_n_4 ,\q_reg[8]_i_1_n_5 ,\q_reg[8]_i_1_n_6 ,\q_reg[8]_i_1_n_7 }),
        .S(q_reg[11:8]));
  FDRE \q_reg[9] 
       (.C(clk),
        .CE(1'b1),
        .D(\q_reg[8]_i_1_n_6 ),
        .Q(q_reg[9]),
        .R(\q_reg[19]_0 ));
endmodule

(* ORIG_REF_NAME = "dffr" *) 
module cgra_test_design_cgra_loader_0_0_dffr__parameterized0
   (gpio_out_16,
    en0,
    gpio_out_1,
    \q_reg[1]_0 ,
    count,
    last_value,
    Q,
    btn_r,
    clk);
  output [3:0]gpio_out_16;
  output en0;
  output gpio_out_1;
  input \q_reg[1]_0 ;
  input [3:0]count;
  input last_value;
  input [0:0]Q;
  input btn_r;
  input clk;

  wire [0:0]Q;
  wire btn_r;
  wire clk;
  wire [3:0]count;
  wire en0;
  wire gpio_out_1;
  wire [3:0]gpio_out_16;
  wire last_value;
  wire [1:0]next_state;
  wire \q_reg[1]_0 ;
  wire [1:0]state;

  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT3 #(
    .INIT(8'h40)) 
    \gpio_out_16[0]_INST_0 
       (.I0(state[0]),
        .I1(state[1]),
        .I2(count[0]),
        .O(gpio_out_16[0]));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT3 #(
    .INIT(8'h40)) 
    \gpio_out_16[1]_INST_0 
       (.I0(state[0]),
        .I1(state[1]),
        .I2(count[1]),
        .O(gpio_out_16[1]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT3 #(
    .INIT(8'h40)) 
    \gpio_out_16[2]_INST_0 
       (.I0(state[0]),
        .I1(state[1]),
        .I2(count[2]),
        .O(gpio_out_16[2]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT3 #(
    .INIT(8'h40)) 
    \gpio_out_16[3]_INST_0 
       (.I0(state[0]),
        .I1(state[1]),
        .I2(count[3]),
        .O(gpio_out_16[3]));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT2 #(
    .INIT(4'h2)) 
    gpio_out_1_INST_0
       (.I0(state[0]),
        .I1(state[1]),
        .O(gpio_out_1));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT4 #(
    .INIT(16'h0100)) 
    \q[0]_i_1__2 
       (.I0(state[1]),
        .I1(state[0]),
        .I2(last_value),
        .I3(Q),
        .O(next_state[0]));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT2 #(
    .INIT(4'h2)) 
    \q[0]_i_2 
       (.I0(state[1]),
        .I1(state[0]),
        .O(en0));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT3 #(
    .INIT(8'h38)) 
    \q[1]_i_1 
       (.I0(\q_reg[1]_0 ),
        .I1(state[1]),
        .I2(state[0]),
        .O(next_state[1]));
  FDRE \q_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(next_state[0]),
        .Q(state[0]),
        .R(btn_r));
  FDRE \q_reg[1] 
       (.C(clk),
        .CE(1'b1),
        .D(next_state[1]),
        .Q(state[1]),
        .R(btn_r));
endmodule

(* ORIG_REF_NAME = "dffr" *) 
module cgra_test_design_cgra_loader_0_0_dffr__parameterized0_2
   (Q,
    \q_reg[0]_0 ,
    button_sync,
    btn_r,
    D,
    clk);
  output [1:0]Q;
  output \q_reg[0]_0 ;
  input button_sync;
  input btn_r;
  input [0:0]D;
  input clk;

  wire [0:0]D;
  wire [1:0]Q;
  wire btn_r;
  wire button_sync;
  wire clk;
  wire \q[0]_i_1_n_0 ;
  wire \q_reg[0]_0 ;

  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT3 #(
    .INIT(8'h8E)) 
    \q[0]_i_1 
       (.I0(Q[0]),
        .I1(button_sync),
        .I2(Q[1]),
        .O(\q[0]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT4 #(
    .INIT(16'hFFBD)) 
    \q[0]_i_1__0 
       (.I0(Q[0]),
        .I1(button_sync),
        .I2(Q[1]),
        .I3(btn_r),
        .O(\q_reg[0]_0 ));
  FDRE \q_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(\q[0]_i_1_n_0 ),
        .Q(Q[0]),
        .R(btn_r));
  FDRE \q_reg[1] 
       (.C(clk),
        .CE(1'b1),
        .D(D),
        .Q(Q[1]),
        .R(btn_r));
endmodule

(* ORIG_REF_NAME = "dffr" *) 
module cgra_test_design_cgra_loader_0_0_dffr__parameterized1
   (last_value,
    btn_r,
    Q,
    clk);
  output last_value;
  input btn_r;
  input [0:0]Q;
  input clk;

  wire [0:0]Q;
  wire btn_r;
  wire clk;
  wire last_value;

  FDRE \q_reg[0] 
       (.C(clk),
        .CE(1'b1),
        .D(Q),
        .Q(last_value),
        .R(btn_r));
endmodule

(* ORIG_REF_NAME = "dffre" *) 
module cgra_test_design_cgra_loader_0_0_dffre
   (count,
    \q_reg[5]_0 ,
    en0,
    clk,
    btn_r);
  output [3:0]count;
  output \q_reg[5]_0 ;
  input en0;
  input clk;
  input btn_r;

  wire btn_r;
  wire clk;
  wire [3:0]count;
  wire en0;
  wire \q[0]_i_1__1_n_0 ;
  wire \q[0]_i_4_n_0 ;
  wire \q[1]_i_3_n_0 ;
  wire \q[1]_i_4_n_0 ;
  wire [11:4]q_reg;
  wire \q_reg[0]_i_3_n_0 ;
  wire \q_reg[0]_i_3_n_1 ;
  wire \q_reg[0]_i_3_n_2 ;
  wire \q_reg[0]_i_3_n_3 ;
  wire \q_reg[0]_i_3_n_4 ;
  wire \q_reg[0]_i_3_n_5 ;
  wire \q_reg[0]_i_3_n_6 ;
  wire \q_reg[0]_i_3_n_7 ;
  wire \q_reg[4]_i_1__0_n_0 ;
  wire \q_reg[4]_i_1__0_n_1 ;
  wire \q_reg[4]_i_1__0_n_2 ;
  wire \q_reg[4]_i_1__0_n_3 ;
  wire \q_reg[4]_i_1__0_n_4 ;
  wire \q_reg[4]_i_1__0_n_5 ;
  wire \q_reg[4]_i_1__0_n_6 ;
  wire \q_reg[4]_i_1__0_n_7 ;
  wire \q_reg[5]_0 ;
  wire \q_reg[8]_i_1__0_n_1 ;
  wire \q_reg[8]_i_1__0_n_2 ;
  wire \q_reg[8]_i_1__0_n_3 ;
  wire \q_reg[8]_i_1__0_n_4 ;
  wire \q_reg[8]_i_1__0_n_5 ;
  wire \q_reg[8]_i_1__0_n_6 ;
  wire \q_reg[8]_i_1__0_n_7 ;
  wire [3:3]\NLW_q_reg[8]_i_1__0_CO_UNCONNECTED ;

  LUT2 #(
    .INIT(4'hB)) 
    \q[0]_i_1__1 
       (.I0(btn_r),
        .I1(\q_reg[5]_0 ),
        .O(\q[0]_i_1__1_n_0 ));
  LUT1 #(
    .INIT(2'h1)) 
    \q[0]_i_4 
       (.I0(count[0]),
        .O(\q[0]_i_4_n_0 ));
  LUT6 #(
    .INIT(64'hFFFFFFFFBFFFFFFF)) 
    \q[1]_i_2 
       (.I0(\q[1]_i_3_n_0 ),
        .I1(q_reg[5]),
        .I2(q_reg[4]),
        .I3(q_reg[7]),
        .I4(q_reg[6]),
        .I5(\q[1]_i_4_n_0 ),
        .O(\q_reg[5]_0 ));
  LUT4 #(
    .INIT(16'h7FFF)) 
    \q[1]_i_3 
       (.I0(q_reg[9]),
        .I1(q_reg[8]),
        .I2(q_reg[11]),
        .I3(q_reg[10]),
        .O(\q[1]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h7FFF)) 
    \q[1]_i_4 
       (.I0(count[1]),
        .I1(count[0]),
        .I2(count[3]),
        .I3(count[2]),
        .O(\q[1]_i_4_n_0 ));
  FDRE \q_reg[0] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[0]_i_3_n_7 ),
        .Q(count[0]),
        .R(\q[0]_i_1__1_n_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[0]_i_3 
       (.CI(1'b0),
        .CO({\q_reg[0]_i_3_n_0 ,\q_reg[0]_i_3_n_1 ,\q_reg[0]_i_3_n_2 ,\q_reg[0]_i_3_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b1}),
        .O({\q_reg[0]_i_3_n_4 ,\q_reg[0]_i_3_n_5 ,\q_reg[0]_i_3_n_6 ,\q_reg[0]_i_3_n_7 }),
        .S({count[3:1],\q[0]_i_4_n_0 }));
  FDRE \q_reg[10] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[8]_i_1__0_n_5 ),
        .Q(q_reg[10]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[11] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[8]_i_1__0_n_4 ),
        .Q(q_reg[11]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[1] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[0]_i_3_n_6 ),
        .Q(count[1]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[2] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[0]_i_3_n_5 ),
        .Q(count[2]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[3] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[0]_i_3_n_4 ),
        .Q(count[3]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[4] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[4]_i_1__0_n_7 ),
        .Q(q_reg[4]),
        .R(\q[0]_i_1__1_n_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[4]_i_1__0 
       (.CI(\q_reg[0]_i_3_n_0 ),
        .CO({\q_reg[4]_i_1__0_n_0 ,\q_reg[4]_i_1__0_n_1 ,\q_reg[4]_i_1__0_n_2 ,\q_reg[4]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\q_reg[4]_i_1__0_n_4 ,\q_reg[4]_i_1__0_n_5 ,\q_reg[4]_i_1__0_n_6 ,\q_reg[4]_i_1__0_n_7 }),
        .S(q_reg[7:4]));
  FDRE \q_reg[5] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[4]_i_1__0_n_6 ),
        .Q(q_reg[5]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[6] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[4]_i_1__0_n_5 ),
        .Q(q_reg[6]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[7] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[4]_i_1__0_n_4 ),
        .Q(q_reg[7]),
        .R(\q[0]_i_1__1_n_0 ));
  FDRE \q_reg[8] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[8]_i_1__0_n_7 ),
        .Q(q_reg[8]),
        .R(\q[0]_i_1__1_n_0 ));
  (* ADDER_THRESHOLD = "11" *) 
  CARRY4 \q_reg[8]_i_1__0 
       (.CI(\q_reg[4]_i_1__0_n_0 ),
        .CO({\NLW_q_reg[8]_i_1__0_CO_UNCONNECTED [3],\q_reg[8]_i_1__0_n_1 ,\q_reg[8]_i_1__0_n_2 ,\q_reg[8]_i_1__0_n_3 }),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\q_reg[8]_i_1__0_n_4 ,\q_reg[8]_i_1__0_n_5 ,\q_reg[8]_i_1__0_n_6 ,\q_reg[8]_i_1__0_n_7 }),
        .S(q_reg[11:8]));
  FDRE \q_reg[9] 
       (.C(clk),
        .CE(en0),
        .D(\q_reg[8]_i_1__0_n_6 ),
        .Q(q_reg[9]),
        .R(\q[0]_i_1__1_n_0 ));
endmodule

(* ORIG_REF_NAME = "one_pulse" *) 
module cgra_test_design_cgra_loader_0_0_one_pulse
   (last_value,
    btn_r,
    Q,
    clk);
  output last_value;
  input btn_r;
  input [0:0]Q;
  input clk;

  wire [0:0]Q;
  wire btn_r;
  wire clk;
  wire last_value;

  cgra_test_design_cgra_loader_0_0_dffr__parameterized1 last_value_storage
       (.Q(Q),
        .btn_r(btn_r),
        .clk(clk),
        .last_value(last_value));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
