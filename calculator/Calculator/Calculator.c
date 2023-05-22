/*
 * Calculator.c
 *
 * Created: 11/26/2022 6:46:08 PM
 *  Author: SOUQ COMPUTER
 */ 
#include "KeyPad.h"
#include "KeyPad_cfg.h"
#include "LCD.H"
#include "LCD_cfg.h"
#include "StdTypes.h"


void CAL_INIT(void)
{
	/* TYPE YOUR CODE HERE */
}

s32 CAL_GetNum(c8*operation,u8 k)
{

	s32 num=k;
	u8 key=23;

	u8 flag_negative=0,flag_value=0,flag3=0;
	while(key!='*' && key!='/' && key!='+' && key!='-' && key!='c' && key!='=')
	{
		key=KEYPAD_GetKey();
		if((key=='*' || key=='/' || key=='+') && flag3==0) // to prevent ++ ** //// it acts as equal thats how i handeled it
		{
			*operation='=';
			return num;	
		}
		if(key=='-' && flag_negative==0)
		{
			flag_value=1; // indicating this is a negative number
			key=NO_KEY; // to stay in the loop
			LCD_WriteChar('-');
			
		}
		if(key>='0' && key<='9')
		{
			LCD_WriteChar(key);
			flag_negative=1;
			num*=10;
			num+=(key-'0');
			flag3=1;
		}
		
		
	}
	*operation=key;
	if(flag_value==1)
	{
		num=num*-1;
		
	}
	return num;
	
}

