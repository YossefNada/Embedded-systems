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


void segement_display_BCD_MUX_on_kit(char n);

#define LED_RED PINC0
#define LED_GREEN 4
#define LED_BLUE 5

#define LED_PORT PA
#define MOTOR PIND3





int main(void)
{
	DIO_Inint();	
	DIO_WritePin(PINC3,LOW);
	DIO_WritePin(PINC1,HIGH);
	while(1)
	{
		if(!DIO_ReadPin(PINC4))
		{
			DIO_TogglePin(PINC3);
			while(!DIO_ReadPin(PINC4));
		}
		if(!DIO_ReadPin(PINC5)) // this means that the user wants to change direction
		{
			if(DIO_ReadPin(PINC1)) // to prevent both IN1 IN2 from being high at the same time
			{
				DIO_TogglePin(PINC1);
				DIO_TogglePin(PINC2);
			}
			else
			{
				DIO_TogglePin(PINC2);
				DIO_TogglePin(PINC1);
			}
			while(!DIO_ReadPin(PINC5));
		}
	
	}
	
		
}






















