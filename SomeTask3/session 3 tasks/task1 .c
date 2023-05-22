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
	
	
	 signed char x=30;
	 char i;
	 
	while(1)
	{
		// GREEN
		x=30;
		PORTC = 2;
		while(x>0)
		{
			for(i=0;i<100;i++)
			{
				segement_display_BCD_MUX_on_kit(x);
				
			}	
			x--;
		}
		// FLASHING BLUE
		x=5;
		while(x>=0)
		{
			
			for(i=0;i<100;i++)
			{
				if(x==5 || x==3 || x==1)
				{
					PORTC=4;
				}
				else
				{
					PORTC=0;
				}
				segement_display_BCD_MUX_on_kit(x);
				
			}
			x--;
		}
		// RED
		x=30;
		PORTC = 1;
		while(x>=0)
		{
			for(i=0;i<100;i++)
			{
				segement_display_BCD_MUX_on_kit(x);
				
			}
			x--;
		}
		
		
		
		
	}
	
		
}






















