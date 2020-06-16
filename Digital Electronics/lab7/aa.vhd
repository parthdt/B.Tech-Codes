library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.all;


entity divide is
port
(clk: IN Std_logic;
a1 : IN Std_logic_vector(7 downto 0);
b1: IN Std_logic_vector( 7 downto 0);
q1:out std_logic_vector( 7 downto 0);  
r1: out std_logic_vector( 7 downto 0));                                                                                                                
end divide;

architecture Behavioral of divide is

begin

process(clk)
variable qq:std_logic_vector( 7 downto 0):="00000000";
variable rr: std_logic_vector( 15 downto 0);
variable temp: std_logic_vector( 15 downto 0);
variable dr:std_logic_vector( 15 downto 0);
begin
rr(7 downto 0):=a1;
rr(15 downto 8):="00000000";
dr(15):='0';
dr(14 downto 7):=b1;
dr(6 downto 0):="0000000";
for i in 0 to 7 loop
if( dr>rr) then
qq(7 downto 1):=qq(6 downto 0);
qq(0):='0';
else
temp:=rr-dr;
qq(7 downto 1):=qq(6 downto 0);
qq(0):='1';
rr:=temp;
end if;

dr(14 downto 0):=dr(15 downto 1);
dr(15):='0';


end loop;
q1<=qq;
r1<=rr(7 downto 0);


end process;

end Behavioral;
