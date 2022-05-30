-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2021.2 (win64) Build 3367213 Tue Oct 19 02:48:09 MDT 2021
-- Date        : Wed Apr  6 21:40:33 2022
-- Host        : CHARLES-PC running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ cgra_test_design_cgra_loader_0_0_sim_netlist.vhdl
-- Design      : cgra_test_design_cgra_loader_0_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff is
  port (
    \q_reg[0]_0\ : out STD_LOGIC;
    btn_s : in STD_LOGIC;
    clk : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff is
begin
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => btn_s,
      Q => \q_reg[0]_0\,
      R => '0'
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_0 is
  port (
    \q_reg[0]_0\ : out STD_LOGIC;
    \q_reg[0]_1\ : in STD_LOGIC;
    clk : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_0 : entity is "dff";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_0;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_0 is
begin
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[0]_1\,
      Q => \q_reg[0]_0\,
      R => '0'
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_1 is
  port (
    button_sync : out STD_LOGIC;
    \q_reg[0]_0\ : in STD_LOGIC;
    clk : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_1 : entity is "dff";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_1;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_1 is
begin
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[0]_0\,
      Q => button_sync,
      R => '0'
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr is
  port (
    D : out STD_LOGIC_VECTOR ( 0 to 0 );
    \q_reg[19]_0\ : in STD_LOGIC;
    clk : in STD_LOGIC;
    Q : in STD_LOGIC_VECTOR ( 1 downto 0 )
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr is
  signal \q[0]_i_3_n_0\ : STD_LOGIC;
  signal \q[1]_i_2__0_n_0\ : STD_LOGIC;
  signal \q[1]_i_3__0_n_0\ : STD_LOGIC;
  signal \q[1]_i_4__0_n_0\ : STD_LOGIC;
  signal \q[1]_i_5_n_0\ : STD_LOGIC;
  signal \q[1]_i_6_n_0\ : STD_LOGIC;
  signal \q[1]_i_7_n_0\ : STD_LOGIC;
  signal \q[1]_i_8_n_0\ : STD_LOGIC;
  signal \q[1]_i_9_n_0\ : STD_LOGIC;
  signal q_reg : STD_LOGIC_VECTOR ( 19 downto 0 );
  signal \q_reg[0]_i_2_n_0\ : STD_LOGIC;
  signal \q_reg[0]_i_2_n_1\ : STD_LOGIC;
  signal \q_reg[0]_i_2_n_2\ : STD_LOGIC;
  signal \q_reg[0]_i_2_n_3\ : STD_LOGIC;
  signal \q_reg[0]_i_2_n_4\ : STD_LOGIC;
  signal \q_reg[0]_i_2_n_5\ : STD_LOGIC;
  signal \q_reg[0]_i_2_n_6\ : STD_LOGIC;
  signal \q_reg[0]_i_2_n_7\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_0\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_1\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_2\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_3\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_4\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_5\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_6\ : STD_LOGIC;
  signal \q_reg[12]_i_1_n_7\ : STD_LOGIC;
  signal \q_reg[16]_i_1_n_1\ : STD_LOGIC;
  signal \q_reg[16]_i_1_n_2\ : STD_LOGIC;
  signal \q_reg[16]_i_1_n_3\ : STD_LOGIC;
  signal \q_reg[16]_i_1_n_4\ : STD_LOGIC;
  signal \q_reg[16]_i_1_n_5\ : STD_LOGIC;
  signal \q_reg[16]_i_1_n_6\ : STD_LOGIC;
  signal \q_reg[16]_i_1_n_7\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_0\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_1\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_2\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_3\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_4\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_5\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_6\ : STD_LOGIC;
  signal \q_reg[4]_i_1_n_7\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_0\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_1\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_2\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_3\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_4\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_5\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_6\ : STD_LOGIC;
  signal \q_reg[8]_i_1_n_7\ : STD_LOGIC;
  signal \NLW_q_reg[16]_i_1_CO_UNCONNECTED\ : STD_LOGIC_VECTOR ( 3 to 3 );
  attribute ADDER_THRESHOLD : integer;
  attribute ADDER_THRESHOLD of \q_reg[0]_i_2\ : label is 11;
  attribute ADDER_THRESHOLD of \q_reg[12]_i_1\ : label is 11;
  attribute ADDER_THRESHOLD of \q_reg[16]_i_1\ : label is 11;
  attribute ADDER_THRESHOLD of \q_reg[4]_i_1\ : label is 11;
  attribute ADDER_THRESHOLD of \q_reg[8]_i_1\ : label is 11;
begin
\q[0]_i_3\: unisim.vcomponents.LUT1
    generic map(
      INIT => X"1"
    )
        port map (
      I0 => q_reg(0),
      O => \q[0]_i_3_n_0\
    );
\q[1]_i_1__0\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"FEEE"
    )
        port map (
      I0 => \q[1]_i_2__0_n_0\,
      I1 => \q[1]_i_3__0_n_0\,
      I2 => Q(1),
      I3 => Q(0),
      O => D(0)
    );
\q[1]_i_2__0\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000000000000080"
    )
        port map (
      I0 => \q[1]_i_4__0_n_0\,
      I1 => \q[1]_i_5_n_0\,
      I2 => \q[1]_i_6_n_0\,
      I3 => q_reg(2),
      I4 => q_reg(1),
      I5 => q_reg(0),
      O => \q[1]_i_2__0_n_0\
    );
\q[1]_i_3__0\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"8000000000000000"
    )
        port map (
      I0 => \q[1]_i_7_n_0\,
      I1 => \q[1]_i_8_n_0\,
      I2 => \q[1]_i_9_n_0\,
      I3 => q_reg(2),
      I4 => q_reg(1),
      I5 => q_reg(0),
      O => \q[1]_i_3__0_n_0\
    );
\q[1]_i_4__0\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000000000000001"
    )
        port map (
      I0 => q_reg(11),
      I1 => q_reg(12),
      I2 => q_reg(9),
      I3 => q_reg(10),
      I4 => q_reg(14),
      I5 => q_reg(13),
      O => \q[1]_i_4__0_n_0\
    );
\q[1]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000000000000001"
    )
        port map (
      I0 => q_reg(5),
      I1 => q_reg(6),
      I2 => q_reg(3),
      I3 => q_reg(4),
      I4 => q_reg(8),
      I5 => q_reg(7),
      O => \q[1]_i_5_n_0\
    );
\q[1]_i_6\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000000100000000"
    )
        port map (
      I0 => q_reg(17),
      I1 => q_reg(18),
      I2 => q_reg(15),
      I3 => q_reg(16),
      I4 => q_reg(19),
      I5 => Q(1),
      O => \q[1]_i_6_n_0\
    );
\q[1]_i_7\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"8000000000000000"
    )
        port map (
      I0 => q_reg(11),
      I1 => q_reg(12),
      I2 => q_reg(9),
      I3 => q_reg(10),
      I4 => q_reg(14),
      I5 => q_reg(13),
      O => \q[1]_i_7_n_0\
    );
\q[1]_i_8\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"8000000000000000"
    )
        port map (
      I0 => q_reg(5),
      I1 => q_reg(6),
      I2 => q_reg(3),
      I3 => q_reg(4),
      I4 => q_reg(8),
      I5 => q_reg(7),
      O => \q[1]_i_8_n_0\
    );
\q[1]_i_9\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"8000000000000000"
    )
        port map (
      I0 => q_reg(17),
      I1 => q_reg(18),
      I2 => q_reg(15),
      I3 => q_reg(16),
      I4 => Q(0),
      I5 => q_reg(19),
      O => \q[1]_i_9_n_0\
    );
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[0]_i_2_n_7\,
      Q => q_reg(0),
      R => \q_reg[19]_0\
    );
\q_reg[0]_i_2\: unisim.vcomponents.CARRY4
     port map (
      CI => '0',
      CO(3) => \q_reg[0]_i_2_n_0\,
      CO(2) => \q_reg[0]_i_2_n_1\,
      CO(1) => \q_reg[0]_i_2_n_2\,
      CO(0) => \q_reg[0]_i_2_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0001",
      O(3) => \q_reg[0]_i_2_n_4\,
      O(2) => \q_reg[0]_i_2_n_5\,
      O(1) => \q_reg[0]_i_2_n_6\,
      O(0) => \q_reg[0]_i_2_n_7\,
      S(3 downto 1) => q_reg(3 downto 1),
      S(0) => \q[0]_i_3_n_0\
    );
\q_reg[10]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[8]_i_1_n_5\,
      Q => q_reg(10),
      R => \q_reg[19]_0\
    );
\q_reg[11]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[8]_i_1_n_4\,
      Q => q_reg(11),
      R => \q_reg[19]_0\
    );
\q_reg[12]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[12]_i_1_n_7\,
      Q => q_reg(12),
      R => \q_reg[19]_0\
    );
\q_reg[12]_i_1\: unisim.vcomponents.CARRY4
     port map (
      CI => \q_reg[8]_i_1_n_0\,
      CO(3) => \q_reg[12]_i_1_n_0\,
      CO(2) => \q_reg[12]_i_1_n_1\,
      CO(1) => \q_reg[12]_i_1_n_2\,
      CO(0) => \q_reg[12]_i_1_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0000",
      O(3) => \q_reg[12]_i_1_n_4\,
      O(2) => \q_reg[12]_i_1_n_5\,
      O(1) => \q_reg[12]_i_1_n_6\,
      O(0) => \q_reg[12]_i_1_n_7\,
      S(3 downto 0) => q_reg(15 downto 12)
    );
\q_reg[13]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[12]_i_1_n_6\,
      Q => q_reg(13),
      R => \q_reg[19]_0\
    );
\q_reg[14]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[12]_i_1_n_5\,
      Q => q_reg(14),
      R => \q_reg[19]_0\
    );
\q_reg[15]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[12]_i_1_n_4\,
      Q => q_reg(15),
      R => \q_reg[19]_0\
    );
\q_reg[16]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[16]_i_1_n_7\,
      Q => q_reg(16),
      R => \q_reg[19]_0\
    );
\q_reg[16]_i_1\: unisim.vcomponents.CARRY4
     port map (
      CI => \q_reg[12]_i_1_n_0\,
      CO(3) => \NLW_q_reg[16]_i_1_CO_UNCONNECTED\(3),
      CO(2) => \q_reg[16]_i_1_n_1\,
      CO(1) => \q_reg[16]_i_1_n_2\,
      CO(0) => \q_reg[16]_i_1_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0000",
      O(3) => \q_reg[16]_i_1_n_4\,
      O(2) => \q_reg[16]_i_1_n_5\,
      O(1) => \q_reg[16]_i_1_n_6\,
      O(0) => \q_reg[16]_i_1_n_7\,
      S(3 downto 0) => q_reg(19 downto 16)
    );
\q_reg[17]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[16]_i_1_n_6\,
      Q => q_reg(17),
      R => \q_reg[19]_0\
    );
\q_reg[18]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[16]_i_1_n_5\,
      Q => q_reg(18),
      R => \q_reg[19]_0\
    );
\q_reg[19]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[16]_i_1_n_4\,
      Q => q_reg(19),
      R => \q_reg[19]_0\
    );
\q_reg[1]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[0]_i_2_n_6\,
      Q => q_reg(1),
      R => \q_reg[19]_0\
    );
\q_reg[2]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[0]_i_2_n_5\,
      Q => q_reg(2),
      R => \q_reg[19]_0\
    );
\q_reg[3]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[0]_i_2_n_4\,
      Q => q_reg(3),
      R => \q_reg[19]_0\
    );
\q_reg[4]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[4]_i_1_n_7\,
      Q => q_reg(4),
      R => \q_reg[19]_0\
    );
\q_reg[4]_i_1\: unisim.vcomponents.CARRY4
     port map (
      CI => \q_reg[0]_i_2_n_0\,
      CO(3) => \q_reg[4]_i_1_n_0\,
      CO(2) => \q_reg[4]_i_1_n_1\,
      CO(1) => \q_reg[4]_i_1_n_2\,
      CO(0) => \q_reg[4]_i_1_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0000",
      O(3) => \q_reg[4]_i_1_n_4\,
      O(2) => \q_reg[4]_i_1_n_5\,
      O(1) => \q_reg[4]_i_1_n_6\,
      O(0) => \q_reg[4]_i_1_n_7\,
      S(3 downto 0) => q_reg(7 downto 4)
    );
\q_reg[5]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[4]_i_1_n_6\,
      Q => q_reg(5),
      R => \q_reg[19]_0\
    );
\q_reg[6]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[4]_i_1_n_5\,
      Q => q_reg(6),
      R => \q_reg[19]_0\
    );
\q_reg[7]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[4]_i_1_n_4\,
      Q => q_reg(7),
      R => \q_reg[19]_0\
    );
\q_reg[8]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[8]_i_1_n_7\,
      Q => q_reg(8),
      R => \q_reg[19]_0\
    );
\q_reg[8]_i_1\: unisim.vcomponents.CARRY4
     port map (
      CI => \q_reg[4]_i_1_n_0\,
      CO(3) => \q_reg[8]_i_1_n_0\,
      CO(2) => \q_reg[8]_i_1_n_1\,
      CO(1) => \q_reg[8]_i_1_n_2\,
      CO(0) => \q_reg[8]_i_1_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0000",
      O(3) => \q_reg[8]_i_1_n_4\,
      O(2) => \q_reg[8]_i_1_n_5\,
      O(1) => \q_reg[8]_i_1_n_6\,
      O(0) => \q_reg[8]_i_1_n_7\,
      S(3 downto 0) => q_reg(11 downto 8)
    );
\q_reg[9]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q_reg[8]_i_1_n_6\,
      Q => q_reg(9),
      R => \q_reg[19]_0\
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0\ is
  port (
    gpio_out_16 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    en0 : out STD_LOGIC;
    gpio_out_1 : out STD_LOGIC;
    \q_reg[1]_0\ : in STD_LOGIC;
    count : in STD_LOGIC_VECTOR ( 3 downto 0 );
    last_value : in STD_LOGIC;
    Q : in STD_LOGIC_VECTOR ( 0 to 0 );
    btn_r : in STD_LOGIC;
    clk : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0\ : entity is "dffr";
end \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0\;

architecture STRUCTURE of \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0\ is
  signal next_state : STD_LOGIC_VECTOR ( 1 downto 0 );
  signal state : STD_LOGIC_VECTOR ( 1 downto 0 );
  attribute SOFT_HLUTNM : string;
  attribute SOFT_HLUTNM of \gpio_out_16[0]_INST_0\ : label is "soft_lutpair3";
  attribute SOFT_HLUTNM of \gpio_out_16[1]_INST_0\ : label is "soft_lutpair3";
  attribute SOFT_HLUTNM of \gpio_out_16[2]_INST_0\ : label is "soft_lutpair2";
  attribute SOFT_HLUTNM of \gpio_out_16[3]_INST_0\ : label is "soft_lutpair2";
  attribute SOFT_HLUTNM of gpio_out_1_INST_0 : label is "soft_lutpair4";
  attribute SOFT_HLUTNM of \q[0]_i_1__2\ : label is "soft_lutpair1";
  attribute SOFT_HLUTNM of \q[0]_i_2\ : label is "soft_lutpair4";
  attribute SOFT_HLUTNM of \q[1]_i_1\ : label is "soft_lutpair1";
begin
\gpio_out_16[0]_INST_0\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"40"
    )
        port map (
      I0 => state(0),
      I1 => state(1),
      I2 => count(0),
      O => gpio_out_16(0)
    );
\gpio_out_16[1]_INST_0\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"40"
    )
        port map (
      I0 => state(0),
      I1 => state(1),
      I2 => count(1),
      O => gpio_out_16(1)
    );
\gpio_out_16[2]_INST_0\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"40"
    )
        port map (
      I0 => state(0),
      I1 => state(1),
      I2 => count(2),
      O => gpio_out_16(2)
    );
\gpio_out_16[3]_INST_0\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"40"
    )
        port map (
      I0 => state(0),
      I1 => state(1),
      I2 => count(3),
      O => gpio_out_16(3)
    );
gpio_out_1_INST_0: unisim.vcomponents.LUT2
    generic map(
      INIT => X"2"
    )
        port map (
      I0 => state(0),
      I1 => state(1),
      O => gpio_out_1
    );
\q[0]_i_1__2\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"0100"
    )
        port map (
      I0 => state(1),
      I1 => state(0),
      I2 => last_value,
      I3 => Q(0),
      O => next_state(0)
    );
\q[0]_i_2\: unisim.vcomponents.LUT2
    generic map(
      INIT => X"2"
    )
        port map (
      I0 => state(1),
      I1 => state(0),
      O => en0
    );
\q[1]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"38"
    )
        port map (
      I0 => \q_reg[1]_0\,
      I1 => state(1),
      I2 => state(0),
      O => next_state(1)
    );
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => next_state(0),
      Q => state(0),
      R => btn_r
    );
\q_reg[1]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => next_state(1),
      Q => state(1),
      R => btn_r
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0_2\ is
  port (
    Q : out STD_LOGIC_VECTOR ( 1 downto 0 );
    \q_reg[0]_0\ : out STD_LOGIC;
    button_sync : in STD_LOGIC;
    btn_r : in STD_LOGIC;
    D : in STD_LOGIC_VECTOR ( 0 to 0 );
    clk : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0_2\ : entity is "dffr";
end \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0_2\;

architecture STRUCTURE of \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0_2\ is
  signal \^q\ : STD_LOGIC_VECTOR ( 1 downto 0 );
  signal \q[0]_i_1_n_0\ : STD_LOGIC;
  attribute SOFT_HLUTNM : string;
  attribute SOFT_HLUTNM of \q[0]_i_1\ : label is "soft_lutpair0";
  attribute SOFT_HLUTNM of \q[0]_i_1__0\ : label is "soft_lutpair0";
begin
  Q(1 downto 0) <= \^q\(1 downto 0);
\q[0]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"8E"
    )
        port map (
      I0 => \^q\(0),
      I1 => button_sync,
      I2 => \^q\(1),
      O => \q[0]_i_1_n_0\
    );
\q[0]_i_1__0\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"FFBD"
    )
        port map (
      I0 => \^q\(0),
      I1 => button_sync,
      I2 => \^q\(1),
      I3 => btn_r,
      O => \q_reg[0]_0\
    );
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => \q[0]_i_1_n_0\,
      Q => \^q\(0),
      R => btn_r
    );
\q_reg[1]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => D(0),
      Q => \^q\(1),
      R => btn_r
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized1\ is
  port (
    last_value : out STD_LOGIC;
    btn_r : in STD_LOGIC;
    Q : in STD_LOGIC_VECTOR ( 0 to 0 );
    clk : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized1\ : entity is "dffr";
end \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized1\;

architecture STRUCTURE of \decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized1\ is
begin
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => '1',
      D => Q(0),
      Q => last_value,
      R => btn_r
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffre is
  port (
    count : out STD_LOGIC_VECTOR ( 3 downto 0 );
    \q_reg[5]_0\ : out STD_LOGIC;
    en0 : in STD_LOGIC;
    clk : in STD_LOGIC;
    btn_r : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffre;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffre is
  signal \^count\ : STD_LOGIC_VECTOR ( 3 downto 0 );
  signal \q[0]_i_1__1_n_0\ : STD_LOGIC;
  signal \q[0]_i_4_n_0\ : STD_LOGIC;
  signal \q[1]_i_3_n_0\ : STD_LOGIC;
  signal \q[1]_i_4_n_0\ : STD_LOGIC;
  signal q_reg : STD_LOGIC_VECTOR ( 11 downto 4 );
  signal \q_reg[0]_i_3_n_0\ : STD_LOGIC;
  signal \q_reg[0]_i_3_n_1\ : STD_LOGIC;
  signal \q_reg[0]_i_3_n_2\ : STD_LOGIC;
  signal \q_reg[0]_i_3_n_3\ : STD_LOGIC;
  signal \q_reg[0]_i_3_n_4\ : STD_LOGIC;
  signal \q_reg[0]_i_3_n_5\ : STD_LOGIC;
  signal \q_reg[0]_i_3_n_6\ : STD_LOGIC;
  signal \q_reg[0]_i_3_n_7\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_0\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_1\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_2\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_3\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_4\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_5\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_6\ : STD_LOGIC;
  signal \q_reg[4]_i_1__0_n_7\ : STD_LOGIC;
  signal \^q_reg[5]_0\ : STD_LOGIC;
  signal \q_reg[8]_i_1__0_n_1\ : STD_LOGIC;
  signal \q_reg[8]_i_1__0_n_2\ : STD_LOGIC;
  signal \q_reg[8]_i_1__0_n_3\ : STD_LOGIC;
  signal \q_reg[8]_i_1__0_n_4\ : STD_LOGIC;
  signal \q_reg[8]_i_1__0_n_5\ : STD_LOGIC;
  signal \q_reg[8]_i_1__0_n_6\ : STD_LOGIC;
  signal \q_reg[8]_i_1__0_n_7\ : STD_LOGIC;
  signal \NLW_q_reg[8]_i_1__0_CO_UNCONNECTED\ : STD_LOGIC_VECTOR ( 3 to 3 );
  attribute ADDER_THRESHOLD : integer;
  attribute ADDER_THRESHOLD of \q_reg[0]_i_3\ : label is 11;
  attribute ADDER_THRESHOLD of \q_reg[4]_i_1__0\ : label is 11;
  attribute ADDER_THRESHOLD of \q_reg[8]_i_1__0\ : label is 11;
begin
  count(3 downto 0) <= \^count\(3 downto 0);
  \q_reg[5]_0\ <= \^q_reg[5]_0\;
\q[0]_i_1__1\: unisim.vcomponents.LUT2
    generic map(
      INIT => X"B"
    )
        port map (
      I0 => btn_r,
      I1 => \^q_reg[5]_0\,
      O => \q[0]_i_1__1_n_0\
    );
\q[0]_i_4\: unisim.vcomponents.LUT1
    generic map(
      INIT => X"1"
    )
        port map (
      I0 => \^count\(0),
      O => \q[0]_i_4_n_0\
    );
\q[1]_i_2\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFFFFFBFFFFFFF"
    )
        port map (
      I0 => \q[1]_i_3_n_0\,
      I1 => q_reg(5),
      I2 => q_reg(4),
      I3 => q_reg(7),
      I4 => q_reg(6),
      I5 => \q[1]_i_4_n_0\,
      O => \^q_reg[5]_0\
    );
\q[1]_i_3\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"7FFF"
    )
        port map (
      I0 => q_reg(9),
      I1 => q_reg(8),
      I2 => q_reg(11),
      I3 => q_reg(10),
      O => \q[1]_i_3_n_0\
    );
\q[1]_i_4\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"7FFF"
    )
        port map (
      I0 => \^count\(1),
      I1 => \^count\(0),
      I2 => \^count\(3),
      I3 => \^count\(2),
      O => \q[1]_i_4_n_0\
    );
\q_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[0]_i_3_n_7\,
      Q => \^count\(0),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[0]_i_3\: unisim.vcomponents.CARRY4
     port map (
      CI => '0',
      CO(3) => \q_reg[0]_i_3_n_0\,
      CO(2) => \q_reg[0]_i_3_n_1\,
      CO(1) => \q_reg[0]_i_3_n_2\,
      CO(0) => \q_reg[0]_i_3_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0001",
      O(3) => \q_reg[0]_i_3_n_4\,
      O(2) => \q_reg[0]_i_3_n_5\,
      O(1) => \q_reg[0]_i_3_n_6\,
      O(0) => \q_reg[0]_i_3_n_7\,
      S(3 downto 1) => \^count\(3 downto 1),
      S(0) => \q[0]_i_4_n_0\
    );
\q_reg[10]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[8]_i_1__0_n_5\,
      Q => q_reg(10),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[11]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[8]_i_1__0_n_4\,
      Q => q_reg(11),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[1]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[0]_i_3_n_6\,
      Q => \^count\(1),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[2]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[0]_i_3_n_5\,
      Q => \^count\(2),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[3]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[0]_i_3_n_4\,
      Q => \^count\(3),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[4]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[4]_i_1__0_n_7\,
      Q => q_reg(4),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[4]_i_1__0\: unisim.vcomponents.CARRY4
     port map (
      CI => \q_reg[0]_i_3_n_0\,
      CO(3) => \q_reg[4]_i_1__0_n_0\,
      CO(2) => \q_reg[4]_i_1__0_n_1\,
      CO(1) => \q_reg[4]_i_1__0_n_2\,
      CO(0) => \q_reg[4]_i_1__0_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0000",
      O(3) => \q_reg[4]_i_1__0_n_4\,
      O(2) => \q_reg[4]_i_1__0_n_5\,
      O(1) => \q_reg[4]_i_1__0_n_6\,
      O(0) => \q_reg[4]_i_1__0_n_7\,
      S(3 downto 0) => q_reg(7 downto 4)
    );
\q_reg[5]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[4]_i_1__0_n_6\,
      Q => q_reg(5),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[6]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[4]_i_1__0_n_5\,
      Q => q_reg(6),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[7]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[4]_i_1__0_n_4\,
      Q => q_reg(7),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[8]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[8]_i_1__0_n_7\,
      Q => q_reg(8),
      R => \q[0]_i_1__1_n_0\
    );
\q_reg[8]_i_1__0\: unisim.vcomponents.CARRY4
     port map (
      CI => \q_reg[4]_i_1__0_n_0\,
      CO(3) => \NLW_q_reg[8]_i_1__0_CO_UNCONNECTED\(3),
      CO(2) => \q_reg[8]_i_1__0_n_1\,
      CO(1) => \q_reg[8]_i_1__0_n_2\,
      CO(0) => \q_reg[8]_i_1__0_n_3\,
      CYINIT => '0',
      DI(3 downto 0) => B"0000",
      O(3) => \q_reg[8]_i_1__0_n_4\,
      O(2) => \q_reg[8]_i_1__0_n_5\,
      O(1) => \q_reg[8]_i_1__0_n_6\,
      O(0) => \q_reg[8]_i_1__0_n_7\,
      S(3 downto 0) => q_reg(11 downto 8)
    );
\q_reg[9]\: unisim.vcomponents.FDRE
     port map (
      C => clk,
      CE => en0,
      D => \q_reg[8]_i_1__0_n_6\,
      Q => q_reg(9),
      R => \q[0]_i_1__1_n_0\
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_brute_force_synchronizer is
  port (
    button_sync : out STD_LOGIC;
    btn_s : in STD_LOGIC;
    clk : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_brute_force_synchronizer;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_brute_force_synchronizer is
  signal ff1_n_0 : STD_LOGIC;
  signal ff2_n_0 : STD_LOGIC;
begin
ff1: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff
     port map (
      btn_s => btn_s,
      clk => clk,
      \q_reg[0]_0\ => ff1_n_0
    );
ff2: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_0
     port map (
      clk => clk,
      \q_reg[0]_0\ => ff2_n_0,
      \q_reg[0]_1\ => ff1_n_0
    );
ff3: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dff_1
     port map (
      button_sync => button_sync,
      clk => clk,
      \q_reg[0]_0\ => ff2_n_0
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_debouncer is
  port (
    Q : out STD_LOGIC_VECTOR ( 0 to 0 );
    clk : in STD_LOGIC;
    button_sync : in STD_LOGIC;
    btn_r : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_debouncer;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_debouncer is
  signal \^q\ : STD_LOGIC_VECTOR ( 0 to 0 );
  signal counter_n_0 : STD_LOGIC;
  signal current_state_q : STD_LOGIC_VECTOR ( 1 to 1 );
  signal state_n_2 : STD_LOGIC;
begin
  Q(0) <= \^q\(0);
counter: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr
     port map (
      D(0) => counter_n_0,
      Q(1) => current_state_q(1),
      Q(0) => \^q\(0),
      clk => clk,
      \q_reg[19]_0\ => state_n_2
    );
state: entity work.\decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0_2\
     port map (
      D(0) => counter_n_0,
      Q(1) => current_state_q(1),
      Q(0) => \^q\(0),
      btn_r => btn_r,
      button_sync => button_sync,
      clk => clk,
      \q_reg[0]_0\ => state_n_2
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_one_pulse is
  port (
    last_value : out STD_LOGIC;
    btn_r : in STD_LOGIC;
    Q : in STD_LOGIC_VECTOR ( 0 to 0 );
    clk : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_one_pulse;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_one_pulse is
begin
last_value_storage: entity work.\decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized1\
     port map (
      Q(0) => Q(0),
      btn_r => btn_r,
      clk => clk,
      last_value => last_value
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_button_press_unit is
  port (
    last_value : out STD_LOGIC;
    Q : out STD_LOGIC_VECTOR ( 0 to 0 );
    btn_r : in STD_LOGIC;
    clk : in STD_LOGIC;
    btn_s : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_button_press_unit;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_button_press_unit is
  signal \^q\ : STD_LOGIC_VECTOR ( 0 to 0 );
  signal button_sync : STD_LOGIC;
begin
  Q(0) <= \^q\(0);
debounce: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_debouncer
     port map (
      Q(0) => \^q\(0),
      btn_r => btn_r,
      button_sync => button_sync,
      clk => clk
    );
one_pulse: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_one_pulse
     port map (
      Q(0) => \^q\(0),
      btn_r => btn_r,
      clk => clk,
      last_value => last_value
    );
sync: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_brute_force_synchronizer
     port map (
      btn_s => btn_s,
      button_sync => button_sync,
      clk => clk
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_cgra_loader is
  port (
    gpio_out_16 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_out_1 : out STD_LOGIC;
    btn_r : in STD_LOGIC;
    clk : in STD_LOGIC;
    btn_s : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_cgra_loader;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_cgra_loader is
  signal button_debounced : STD_LOGIC;
  signal count : STD_LOGIC_VECTOR ( 3 downto 0 );
  signal counter_n_4 : STD_LOGIC;
  signal en0 : STD_LOGIC;
  signal \one_pulse/last_value\ : STD_LOGIC;
begin
counter: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffre
     port map (
      btn_r => btn_r,
      clk => clk,
      count(3 downto 0) => count(3 downto 0),
      en0 => en0,
      \q_reg[5]_0\ => counter_n_4
    );
start_btn: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_button_press_unit
     port map (
      Q(0) => button_debounced,
      btn_r => btn_r,
      btn_s => btn_s,
      clk => clk,
      last_value => \one_pulse/last_value\
    );
state_reg: entity work.\decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dffr__parameterized0\
     port map (
      Q(0) => button_debounced,
      btn_r => btn_r,
      clk => clk,
      count(3 downto 0) => count(3 downto 0),
      en0 => en0,
      gpio_out_1 => gpio_out_1,
      gpio_out_16(3 downto 0) => gpio_out_16(3 downto 0),
      last_value => \one_pulse/last_value\,
      \q_reg[1]_0\ => counter_n_4
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  port (
    clk : in STD_LOGIC;
    btn_r : in STD_LOGIC;
    btn_s : in STD_LOGIC;
    gpio_out_16 : out STD_LOGIC_VECTOR ( 3 downto 0 );
    gpio_out_1 : out STD_LOGIC;
    io_rst : out STD_LOGIC
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "cgra_test_design_cgra_loader_0_0,cgra_loader,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "module_ref";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "cgra_loader,Vivado 2021.2";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  signal \^btn_r\ : STD_LOGIC;
  attribute X_INTERFACE_INFO : string;
  attribute X_INTERFACE_INFO of clk : signal is "xilinx.com:signal:clock:1.0 clk CLK";
  attribute X_INTERFACE_PARAMETER : string;
  attribute X_INTERFACE_PARAMETER of clk : signal is "XIL_INTERFACENAME clk, FREQ_HZ 10000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN /clk_wiz_0_clk_out1, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of io_rst : signal is "xilinx.com:signal:reset:1.0 io_rst RST";
  attribute X_INTERFACE_PARAMETER of io_rst : signal is "XIL_INTERFACENAME io_rst, POLARITY ACTIVE_LOW, INSERT_VIP 0";
begin
  \^btn_r\ <= btn_r;
  io_rst <= \^btn_r\;
inst: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_cgra_loader
     port map (
      btn_r => \^btn_r\,
      btn_s => btn_s,
      clk => clk,
      gpio_out_1 => gpio_out_1,
      gpio_out_16(3 downto 0) => gpio_out_16(3 downto 0)
    );
end STRUCTURE;
