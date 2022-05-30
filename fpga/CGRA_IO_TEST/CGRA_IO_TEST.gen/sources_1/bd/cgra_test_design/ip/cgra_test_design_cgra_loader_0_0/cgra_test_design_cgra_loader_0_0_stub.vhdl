-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2021.2 (win64) Build 3367213 Tue Oct 19 02:48:09 MDT 2021
-- Date        : Wed Apr  6 21:40:33 2022
-- Host        : CHARLES-PC running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               c:/Users/chess/OneDrive/Documents/Stanford/EE272C/CGRA_IO_TEST/CGRA_IO_TEST.gen/sources_1/bd/cgra_test_design/ip/cgra_test_design_cgra_loader_0_0/cgra_test_design_cgra_loader_0_0_stub.vhdl
-- Design      : cgra_test_design_cgra_loader_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity cgra_test_design_cgra_loader_0_0 is
  Port ( 
    clk : in STD_LOGIC;
    btn_r : in STD_LOGIC;
    btn_s : in STD_LOGIC;
    gpio_out_16 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_out_1 : out STD_LOGIC;
    io_rst : out STD_LOGIC
  );

end cgra_test_design_cgra_loader_0_0;

architecture stub of cgra_test_design_cgra_loader_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk,btn_r,btn_s,gpio_out_16[3:0],gpio_out_1,io_rst";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "cgra_loader,Vivado 2021.2";
begin
end;
