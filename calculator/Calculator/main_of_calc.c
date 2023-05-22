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



#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2




int main(void)
{
	DIO_Inint();
	LCD_Init();
	KEYPAD_Init();
	CAL_INIT();
	LCD_Signature();
	s32 num1,num2;
	s32 result=0;
	c8 operation;
	u8 flag=0,flag2=0,key=NO_KEY;
	
	

	while (1)
	{
		
		if(flag2==0)
		{
			num1=CAL_GetNum(&operation,0);
			result=num1;
			flag2=1;
		}
		
		
		switch(operation)
		{
			case '+':
					LCD_WriteChar('+');
					
					num2=CAL_GetNum(&operation,0);
					result+=num2;
					break;
			case '*':
					LCD_WriteChar('*');
					num2=CAL_GetNum(&operation,0);
					result*=num2;
					break;
			case '-':
					LCD_WriteChar('-');
					num2=CAL_GetNum(&operation,0);
					result-=num2;
					break;
			case '/':
					LCD_WriteChar('/');
					num2=CAL_GetNum(&operation,0);
					if(num2==0)
					{
						LCD_Clear();
						LCD_SetCursor(0,2);
						LCD_WriteString("MATHS ERROR");
						_delay_ms(500);
						operation='c'; // to clear the screen
					}
					else
					{
						result/=num2;
					}
					break;
			case '=':
					LCD_SetCursor(1,0);
					if(flag==0)
						LCD_WriteNumber(result);
					break;
			case 'c':
					flag2=0;
					LCD_Clear();
					LCD_SetCursor(0,4);
					LCD_WriteString("Cleared");
					_delay_ms(300);
					LCD_Clear();
					break;
		}
		if(operation=='=')
		{
			key=KEYPAD_GetKey();
			if(key=='+' ||key=='-' ||key=='*' ||key=='/')
			{
				operation=key;
				LCD_Clear();
				LCD_SetCursor(0,0);
				LCD_WriteNumber(result);
				
			}
			else if (key=='c')
			{
				operation='c';
			}
			else if((key>='0' && key<='9'))
			{
				
				LCD_Clear();
				LCD_SetCursor(0,0);
				LCD_WriteChar(key);
				num1=CAL_GetNum(&operation,key-'0');
				result=num1;	
			}
			
		}
		
		
		
						
	}
		
}






















