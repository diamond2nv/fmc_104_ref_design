-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1 (lin64) Build 2552052 Fri May 24 14:47:09 MDT 2019
-- Date        : Wed Oct 16 17:31:19 2019
-- Host        : ukaea-fpga running 64-bit KDE neon User Edition 5.16
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ MercuryZX1_vio_0_0_stub.vhdl
-- Design      : MercuryZX1_vio_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z030fbg676-2
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  Port ( 
    clk : in STD_LOGIC;
    probe_in0 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in1 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in2 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in3 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in4 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in5 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in6 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in7 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in8 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    probe_in9 : in STD_LOGIC_VECTOR ( 11 downto 0 );
    probe_out0 : out STD_LOGIC_VECTOR ( 0 to 0 )
  );

end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk,probe_in0[31:0],probe_in1[31:0],probe_in2[31:0],probe_in3[31:0],probe_in4[31:0],probe_in5[31:0],probe_in6[31:0],probe_in7[31:0],probe_in8[31:0],probe_in9[11:0],probe_out0[0:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "vio,Vivado 2019.1";
begin
end;