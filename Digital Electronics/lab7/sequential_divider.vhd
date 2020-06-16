----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:33:32 11/02/2018 
-- Design Name: 
-- Module Name:    sequential_divider - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity sequential_divider is
	port( clock : IN std_logic;
			divisor,dividend : IN std_logic_vector(7 downto 0);
			quotient,remainder : OUT std_logic_vector(7 downto 0));
end sequential_divider;

architecture Behavioral of sequential_divider is

	constant zero_8 : unsigned(7 downto 0) :="00000000";
	constant zero_7 : unsigned(6 downto 0) :="0000000";
	
	signal rm : unsigned(15 downto 0) := zero_8 & unsigned(dividend);
	signal d : unsigned(15 downto 0) := "0" & unsigned(divisor) & zero_7;
	signal q : unsigned(7 downto 0) :="00000000";
begin
	
	
	division : process(clock)
		begin
		
		if (clock'event and clock='1') then
		
			loop_div : for i in 0 to 7 loop
			
				if( to_integer(d) < to_integer(rm)) then 
					rm <= rm(15 downto 0) - d(15 downto 0);
					q <= q(6 downto 0) & "1";
				else 
					q<= q(6 downto 0) & "0";
				end if;
				
				d <= "0" & d(15 downto 1);
				
			end loop loop_div;
		
		end if;
		
		quotient<=std_logic_vector(q);
		remainder<=std_logic_vector(rm(7 downto 0));
	end process division;

end Behavioral;

