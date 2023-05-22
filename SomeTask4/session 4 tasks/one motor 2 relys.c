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
	DIO_WritePin(PINC0,HIGH);
	
	
	 DIO_WritePin(PINC0,LOW);
	 DIO_WritePin(PINC1,LOW);
	while(1)
	{
		if(!DIO_ReadPin(PINC2))
		{
			DIO_WritePin(PINC0,LOW);
			DIO_WritePin(PINC1,HIGH);
			while(!DIO_ReadPin(PINC2));
		}
		if(!DIO_ReadPin(PINC3))
		{
			DIO_WritePin(PINC0,HIGH);
			DIO_WritePin(PINC1,LOW);
			while(!DIO_ReadPin(PINC3));
		}
		if(!DIO_ReadPin(PINC4))
		{
			DIO_WritePin(PINC0,LOW);
			DIO_WritePin(PINC1,LOW);
			while(!DIO_ReadPin(PINC4));
		}
		
	}
	
		
}






















