----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:32:08 11/23/2018 
-- Design Name: 
-- Module Name:    lc - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity lc is
	port( --direc : in std_logic;
			reset,clk : in std_logic;
			down : inout std_logic_vector(3 downto 0);
			floor : out std_logic_vector(2 downto 0);
			dooropen,doorclose : inout std_logic;
			up : inout std_logic_vector(3 downto 0));

end lc;

architecture Behavioral of lc is
TYPE State_type IS (zero, one, two,three); 
SIGNAL State : State_Type; 
signal direc : std_logic;
begin
	if(reset='1') then
		State <= zero;
		floor <="00";
	end if;
	
	case state is
		when zero =>
		--2s time for travelling bw floors
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
		-----------------------------------
			
			floor<= '00';
			down(0)<='0';
			direc<= '1';
			if(up(0)='1') then
				up(0)='0';
			
				--open gate
				wait until clk'event and clk='0';
				wait until clk'event and clk='1' ;--edit..gate opening time
				wait until(clk'event and clk='0') or (doorclose'event and doorclose='1');
				-----------
			end if;
				if(up = '0000' and down = '0000') then 
					state<=zero;
				else 
					state<=one;
				end if;
					
				
		when one=>
		--2s time for travelling bw floors
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
		-----------------------------------
			floor<='01';

			if(direc='1') then
					if(up(1)='1') then
					up(1)='0';
				--open gate
				wait until clk'event and clk='0';
				wait until clk'event and clk='1' ;--edit..gate opening time
				wait until(clk'event and clk='0') or (doorclose'event and doorclose='1');
				-----------
					end if;
					if(up='0000' and down='0000') then
						state<=one;
					else if(up(3 downto 1)='000'and down(3 downto 1)='000')--change direction if no requests from above 
							direc='0';
							state<=one;
					else
						state<= two;
					end if;
			
			else 
					if(down(1)='1') then
					down(1)='0';
				--open gate
				wait until clk'event and clk='0';
				wait until clk'event and clk='1' ;--edit..gate opening time
				wait until(clk'event and clk='0') or (doorclose'event and doorclose='1');
				-----------
					end if;
					if(up='0000' and down='0000') then
						state<=one;
					else if(up[1:0]='00'and down[1:0]='00')--change direction if no requests from above 
							direc='1';
							state<=one;
					else
						state<= two;
					end if;
					
			end if;

		when two=>
		--2s time for travelling bw floors
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
		-----------------------------------
			floor<='10';

			if(direc='1') then
					if(up(2)='1') then
					up(2)='0';
				--open gate
				wait until clk'event and clk='0';
				wait until clk'event and clk='1' ;--edit..gate opening time
				wait until(clk'event and clk='0') or (doorclose'event and doorclose='1');
				-----------
					end if;
					if(up='0000' and down='0000') then
						state<=two;
					else if(up[3:2]='00'and down[3:2]='00')--change direction if no requests from above 
							direc='0';
							state<=two;
					else
						state<= three;
					end if;
			
			else 
					if(down(2)='1') then
					down(2)='0';
				--open gate
				wait until clk'event and clk='0';
				wait until clk'event and clk='1' ;--edit..gate opening time
				wait until(clk'event and clk='0') or (doorclose'event and doorclose='1');
				-----------
					end if;
					if(up='0000' and down='0000') then
						state<=two;
					else if(up[2:0]='000'and down[2:0]='000')--change direction if no requests from below 
							direc='1';
							state<=two;
					else
						state<= one;
					end if;
					
			end if;

		
		when others =>
		--2s time for travelling bw floors
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
			wait until clk'event and clk='0';
		   wait until clk'event and clk='1';
		-----------------------------------
			floor<= '11';
			direc<= '0';
			if(up(0)='1') then
				up(0)='0';
				--open gate
				wait until clk'event and clk='0';
				wait until clk'event and clk='1' ;--edit..gate opening time
				wait until(clk'event and clk='0') or (doorclose'event and doorclose='1');
				-----------
			end if;
				if(up = '0000' and down = '0000') then 
					state<=three;
				else 
					state<=two;
				end if;
				

end Behavioral;