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

	 
	while(1)
	{
		if(!READ_BIT(PIND,2)) // increment
		{
			if(x==99)
			{
				x=0;
			}
			else
			{
				x++;	
			}
		
			while(!READ_BIT(PIND,2))
			{
				segement_display_BCD_MUX_on_kit(x);
			}
			
		}
		if(!READ_BIT(PIND,3)) // increment
		{
			if(x==0)
			{
				x=99;
			}
			else
			{
				x--;	
			}
			
			while(!READ_BIT(PIND,3))
			{
				segement_display_BCD_MUX_on_kit(x);
			}
		}
		segement_display_BCD_MUX_on_kit(x);
		
		
		
	}
	
		
}






















