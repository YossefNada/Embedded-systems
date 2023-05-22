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
#include "LCD.h"
#include "KeyPad.h"
#include "Calculator.h"
#include "Converter.h"
#include "ADC.h"
#include "Sensors.h"
#include "TempFilter.h"
#include "FireSystem.h"
#include "EX_Interrupt.h"
#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2
#define BUZZER PINC5
#define RELAY1 PINC4
#define LED_YELLOW PINC2



// A program to try the NVM EEPROM

// the password will be limited to 4 digits
u16 pass=0;

int main(void)
{
	
	
	DIO_Inint();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	NVM_Init();
	NVM_WRITE(2,'z'); // arbitrary variable to indicate first time usage
	// then we will send the default value to the NVM
	pass=NVM_READ(1); // MSB 
	pass=pass<<8;
	pass+=NVM_READ(0); // LSB
	LCD_WriteNumber(pass);
	_delay_ms(1000);
	u8 flag=0,counter=0,key=NO_KEY,answer=0;
	u16 entered_pass=0;
	
	
	while (1)
	{
		entered_pass=0;
		DIO_WritePin(LED_YELLOW,LOW);
		DIO_WritePin(LED_RED,LOW);
		DIO_WritePin(LED_GREEN,LOW);
		counter=0;
		LCD_Clear();
		LCD_SetCursorString(0,0,"Enter password: ");
		LCD_SetCursor(1,0);
		while(counter<4)
		{
			key=KEYPAD_GetKey();
			if(key>='0' && key<='9')
			{
				entered_pass=entered_pass*10+(key-'0');
				LCD_WriteChar(key);
				counter++;
			}
		}
		if(entered_pass==pass)
		{
			flag=0;
			counter=0;
			key=NO_KEY;
			LCD_SetCursorString(1,5,"Correct");
			DIO_WritePin(LED_YELLOW,HIGH);
			_delay_ms(500);
			LCD_Clear();
			LCD_SetCursorString(0,0,"Change password?Y:1//N:2 : ");
			while(key!='1' && key!='2')
			{
				
			
			key=KEYPAD_GetKey();
			if(key=='1')
			{
				entered_pass=0;
				LCD_Clear();
				LCD_SetCursorString(0,0,"Enter password: ");
				LCD_SetCursor(1,0);
				while(counter<4)
				{
					key=KEYPAD_GetKey();
					if(key>='0' && key<='9')
					{
						entered_pass=entered_pass*10+(key-'0');
						LCD_WriteChar(key);
						counter++;
					}
				}
				_delay_ms(200);
				NVM_WRITE(0,(u8)entered_pass);//LSB
				NVM_WRITE(1,(u8)(entered_pass>>8));//MSB
				LCD_Clear();
				LCD_SetCursorString(0,0,"Password changed :)");
				DIO_WritePin(LED_GREEN,HIGH);
				key='1';
				pass=entered_pass;
				_delay_ms(3000);
				
			}
			else if(key=='2')
			{
				LCD_Clear();
				LCD_SetCursorString(0,0,"OK NO CHANGE :(");
				DIO_WritePin(LED_RED,HIGH);
				_delay_ms(3000);
			}
			}
			
		}
		else
		{
			LCD_SetCursorString(0,0,"Wrong pass");
			for(u8 i=0;i<5;i++)
			{
				DIO_WritePin(LED_RED,LOW);
				DIO_WritePin(LED_YELLOW,HIGH);
				DIO_WritePin(LED_GREEN,LOW);
				_delay_ms(100);
				DIO_WritePin(LED_RED,LOW);
				DIO_WritePin(LED_YELLOW,LOW);
				DIO_WritePin(LED_GREEN,HIGH);
				_delay_ms(100);
				DIO_WritePin(LED_RED,HIGH);
				DIO_WritePin(LED_YELLOW,LOW);
				DIO_WritePin(LED_GREEN,LOW);
				_delay_ms(100);
				
			}
			
			flag++;
		}
		if(flag==3)
		{
			LCD_Clear();
			LCD_SetCursorString(0,0,"Banned for 3 SEC");
			_delay_ms(3000);
		}
	
		
	}
}



