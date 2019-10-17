-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1 (lin64) Build 2552052 Fri May 24 14:47:09 MDT 2019
-- Date        : Wed Oct 16 17:13:10 2019
-- Host        : ukaea-fpga running 64-bit KDE neon User Edition 5.16
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ MercuryZX1_labtools_fmeter_0_0_stub.vhdl
-- Design      : MercuryZX1_labtools_fmeter_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z030fbg676-2
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  Port ( 
    refclk : in STD_LOGIC;
    fin : in STD_LOGIC_VECTOR ( 8 downto 0 );
    F0 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F1 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F2 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F3 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F4 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F5 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F6 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F7 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    F8 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    update : out STD_LOGIC
  );

end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "refclk,fin[8:0],F0[31:0],F1[31:0],F2[31:0],F3[31:0],F4[31:0],F5[31:0],F6[31:0],F7[31:0],F8[31:0],update";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "labtools_fmeter,Vivado 2019.1";
begin
end;