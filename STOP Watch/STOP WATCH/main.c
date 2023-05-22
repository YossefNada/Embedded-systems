/*
 * WorkProject.c
 *
 * Created: 10/22/2022 3:12:07 PM
 * Author : SOUQ COMPUTER
 */ 
#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_interface.h"
#include "MOTOR_interface.h"


#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2

#define LED_PORT PA
#define MOTOR PIND3


//----------------------------- BUTTONS ARE ACTIVE LOW -----------------------------------//
#define PAUSE PIND2
#define RESUME PIND2
#define INCREMENT PIND2

#define RESET PIND3
#define DECREMENT PIND3

#define MODE PIND4



/*
---> 1 BUTTON    RESUME/PAUSE
---> 1 BUTTON	 RESET
---> 1 BUTTON    MODE _ if mode is pressed _ the first button becomes INCREMENT and the second button becomes DECREMENT

*/








void segement_display_BCD_MUX_on_kit(char n);
void end_of_time(void);



int main(void)
{
	DIO_Inint(); // Define pins -->  which is output and which is input 
	u8 TIME=30;
	u8 time_length=30;
	u8 flag_for_pause_resume=0; //  ZERO indicating PAUSE
	u8 flag_mode=0;
	u8 right=0,left=3;
	
	while(1)
	{
		if(!DIO_ReadPin(RESUME))
		{
			flag_for_pause_resume=1;
			while(!DIO_ReadPin(RESUME))
			{
				segement_display_BCD_MUX_on_kit(time_length);
			}
			
			while(flag_for_pause_resume==1)
			{
				for(u8 i=0;i<90;i++)
				{
					segement_display_BCD_MUX_on_kit(time_length);
					if(!DIO_ReadPin(PAUSE)) // if PAUSE is pressed
					{
						flag_for_pause_resume=0;
					}
					
				}
				if(flag_for_pause_resume==0)
				{
					break;
				}
				if(time_length==0) // Reached ZERO
				{
					end_of_time();
					break;
				}
				time_length--;
			}
			while (!DIO_ReadPin(RESUME)); // BUSY WAIT	
		}
		if(!DIO_ReadPin(RESET)) // The Watch Must Be PAUSED
		{
			time_length=TIME;
			for(u8 i=0;i<100;i++)
			{
				segement_display_BCD_MUX_on_kit(time_length);
			}
			while(!DIO_ReadPin(RESET));
		}
		while((!DIO_ReadPin(MODE)) || flag_mode==1)
		{
			right=TIME-(TIME/10)*10;
			left=TIME/10;
			flag_mode=1;
			while(!DIO_ReadPin(MODE))
			{
				segement_display_BCD_MUX_on_kit(TIME);
			}
			if(!DIO_ReadPin(RESUME)) // LEFT SEGMENT
			{
				while(!DIO_ReadPin(RESUME))
				{
					segement_display_BCD_MUX_on_kit(TIME);
				}
				if(left==9)
				{
					left=0;
				}
				else
				{
					left+=1;
				}
				TIME=left*10+right;
				
				
			}
			if(!DIO_ReadPin(RESET))	// RIGHT SEGMENT
			{
				while(!DIO_ReadPin(RESET))
				{
					segement_display_BCD_MUX_on_kit(TIME);
				}
				if(right==9)
				{
					right=0;
				}
				else
				{
					right+=1;
				}	
			}
			segement_display_BCD_MUX_on_kit(TIME);
			TIME=left*10+right;
			time_length=TIME;
			if(!DIO_ReadPin(MODE))
			{
				flag_mode=0;
				while(!DIO_ReadPin(MODE))
				{
					segement_display_BCD_MUX_on_kit(TIME);
				}
			}
		}
		
		
		segement_display_BCD_MUX_on_kit(time_length);
		
	
		
	}
	
		
}






















