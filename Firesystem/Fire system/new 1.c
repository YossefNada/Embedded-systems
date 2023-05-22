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
#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2
#define BUZZER PINC5
#define RELAY1 PINC4
#define LED_YELLOW PINC3


u16 numm=0;

int main(void)
{
	
	DIO_Inint();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	TEMP_FilterInit();
	FireSystem_Init();
	u16 temp=0;
	u32 password=0,key=NO_KEY,flag=0;
	
	while (1)
	{
		TEMP_FilterRunnable();
		temp=TEMP_FilterGetter();
		if(temp<=45 || (flag==1 && temp<50)) // Status 1
		{
			flag=0;
			LCD_SetCursorString(1,0,"STATUS : FINE");
			DIO_WritePin(LED_RED,LOW);
			DIO_WritePin(BUZZER,LOW);
			DIO_WritePin(RELAY1,LOW);
			DIO_WritePin(LED_YELLOW,LOW);
		}
		else if(temp>50) // status 2 or status 3  --> Apply hystersis
		{
			if(DIO_ReadPin(MQ_6)) // FIRE
			{
				password=0;
				u8 i=0;
				LCD_SetCursorString(1,0,"STATUS : FIRE");
				DIO_WritePin(LED_YELLOW,LOW);
				DIO_WritePin(LED_RED,HIGH);
				DIO_WritePin(BUZZER,HIGH);
				DIO_WritePin(RELAY1,HIGH);
				LCD_SetCursorString(0,0,"                ");
				LCD_SetCursorString(0,0,"PASS: ****");
				while(password!=2356)
				{
					
					TEMP_FilterRunnable();
					temp=TEMP_FilterGetter();
					LCD_SetCursorString(0,11,"T:");
					LCD_WriteNumber(temp);
					key=KEYPAD_GetKey();
					if(key!=NO_KEY && (key>='0' && key<='9'))
					{
						password*=10;
						password+=(key-'0');
						LCD_SetCursor(0,i+6);
						LCD_WriteChar(key);
						i++;
					}
					if(password>2356 || (password>1000 && password!=2356))
					{
						LCD_SetCursorString(0,5,"wrong");
						_delay_ms(1000);
						password=0;
						LCD_SetCursorString(0,0,"PASS: ****");
						i=0;
					}
					
				}
				
				LCD_Clear();
				DIO_WritePin(LED_RED,LOW);
				DIO_WritePin(BUZZER,LOW);
				DIO_WritePin(RELAY1,LOW);
				DIO_WritePin(LED_YELLOW,LOW);
				LCD_SetCursorString(0,0,"Reviewing.....");
				_delay_ms(2000);
				flag=1;
				
			}
			else // JUST HEAT
			{
				DIO_WritePin(LED_RED,LOW);
				DIO_WritePin(BUZZER,LOW);
				DIO_WritePin(RELAY1,LOW);
				LCD_SetCursorString(1,0,"STATUS : HEAT");
				DIO_WritePin(LED_YELLOW,HIGH);
			}
		}
		LCD_SetCursorString(0,0,"TEMP IS :");
		LCD_WriteNumber(temp);
		LCD_WriteString(" C'");
		
		
		
	}
}














///* ISR FUNCTION */ // interrupt service routine
///* Attribute signal */
//
//
//#define ADC_vect __vector_20
//#define ISR(vector) void vector(void) __attribute__((signal));\
					void vector(void)
//
//
//void __vector_5(void) __attribute__((signal)); // 3alshan a3mel push we pop lel registers ely feha el data we ma3ahom el status registers 
//void __vector_5(void)
//{
	//u16 num=ADC_GetReadNoBlock();
	//LCD_WriteNumber(num);
//}
//
//
//
//ISR(ADC_vect)
//{
	//LCD_WriteString("3abdo");
	//numm=ADC_GetRead();
//}
//




