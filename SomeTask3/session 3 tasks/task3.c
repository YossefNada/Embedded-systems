/*
 * WorkProject.c
 *
 * Created: 10/22/2022 3:12:07 PM
 * Author : SOUQ COMPUTER
 */ 
#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"



void segement_display_BCD_MUX_on_kit(char n);







int main(void)
{
	
	
	DDRC=0xff;
	DDRA=0xff;
	DDRD=0;
	PORTD=0xff; // for the pull up resistor 
	
	
	
	u8 x=0;
	u8 i;
	 
	while(1)
	{
	
		
			while(!READ_BIT(PIND,2))
			{
				
				if(x==99)
				{
					x=0;
				}
				else
				{
					x++;
				}
				for(i=0;i<30;i++)
				{
					segement_display_BCD_MUX_on_kit(x); // there is a delay here about 10 ms
					
				}
			}
	
		
			while(!READ_BIT(PIND,3))
			{
				if(x==0)
				{
					x=99;
				}
				else
				{
					x--;
				}
				for(i=0;i<30;i++)
				{
					segement_display_BCD_MUX_on_kit(x); // there is a delay here about 10 ms
					
				}
			}
		
		segement_display_BCD_MUX_on_kit(x);
		
		
		
	}
	
		
}






















