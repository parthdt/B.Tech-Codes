----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:04:44 11/30/2018 
-- Design Name: 
-- Module Name:    liftcontroller - Behavioral 
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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity liftcontroller is
port ( clock, reset : in std_logic;
				lift_floor,destination_floor : in std_logic_vector(3 downto 0);
				lift_status : out std_logic_vector(3 downto 0));
				
end liftcontroller;

architecture Behavioral of liftcontroller is

type State is (reqUp,reqDown,Idle);
signal st : State;

signal direction : std_logic;
begin

	process(clock)
	
	begin
	
	if( clock = '1' and clock'event) then
						
		case st is 
						
			when reqUp =>
				
				if(
								
			when reqDown =>
						
			when Idle =>
						
			when others = >
			
				direction<='1';		
				st <=Idle;
				
						
					

	
end Behavioral;

