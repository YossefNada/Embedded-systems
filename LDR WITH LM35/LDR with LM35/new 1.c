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
#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2




int main(void)
{
	DIO_Inint();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	u16 num=0;
	u16 temp=0;
	
	
	while (1)
	{
		// Using 1 Kohm resistor for the divider
		num=ADC_ReadVolt(CH_0);
		temp=Sensors_TempRead();
		LCD_SetCursorString(1,0,"Temp = ");
		LCD_WriteNumber(temp/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(temp%10);
		LCD_WriteString(" c");
		LCD_SetCursor(0,0);
		LCD_Write_4D(num);
		if(num>=2300) //0.0248 LDR = 1M -->very dark
		{
			DIO_WritePort(PC,0xff);
			
		} 
		else if(num>=2000) //0.1219 LDR = 200K -->lightly dark
		{
			
			DIO_WritePort(PC,0xfe);
			
		}		
		else if(num>=1800) //4.5454 LDR = 100K --> super bright
		{
			DIO_WritePort(PC,0xfc);
		}
		else if(num>=1500) //0.4545 LDR = 50K--> light rise
		{
			DIO_WritePort(PC,0xf8);
		}
		else if(num>=1200) //1.6667 LDR = 10K--> light
		{
			DIO_WritePort(PC,0xf0);
		}
		else if(num>=1000) //2.5 LDR = 5K -->increasingly bright
		{
			DIO_WritePort(PC,0xe0);
		}
		else if(num>=800) // 3.57 LDR = 2K --> bright
		{
			DIO_WritePort(PC,0xc0);
		}
		else if(num>=600) //4.1667 LDR = 1K  --> very bright
		{
			DIO_WritePort(PC,0x80);
		}
		else if(num>=400) //4.5454 LDR = 0.5K --> super bright
		{
			DIO_WritePort(PC,0x00);
		}
	}
}











