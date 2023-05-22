/*
 * Converter.c
 *
 * Created: 11/27/2022 8:41:31 PM
 *  Author: SOUQ COMPUTER
 */ 
#include "StdTypes.h"
#include "KeyPad.h"
#include "LCD.H"
#include "Converter.h"
#define F_CPU 8000000
#include <util/delay.h>




void Converter_Init(void)
{
	/* Do your code here*/
	LCD_Clear();
	LCD_SetCursor(0,4);
	LCD_WriteChar('c');
	_delay_ms(50);
	LCD_WriteChar('o');
	_delay_ms(50);
	LCD_WriteChar('n');
	_delay_ms(50);
	LCD_WriteChar('v');
	_delay_ms(50);
	LCD_WriteChar('e');
	_delay_ms(50);
	LCD_WriteChar('r');
	_delay_ms(50);
	LCD_WriteChar('t');
	_delay_ms(50);
	LCD_WriteChar('e');
	_delay_ms(50);
	LCD_WriteChar('r');
	_delay_ms(50);
	LCD_SetCursor(1,7);
	LCD_WriteChar('A');
	_delay_ms(50);
	LCD_WriteChar('P');
	_delay_ms(50);
	LCD_WriteChar('P');
	_delay_ms(1000);
}


/*************************************** USER INTERFACING ********************************/

void Converter_From(void) 
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"Convert From: 1-");
	LCD_SetCursorString(1,0,"DEC 2-BIN 3-HEX");
	
	
}

void Converter_To(void)
{
	
	LCD_Clear();
	LCD_SetCursorString(0,0,"Convert To: 1-");
	LCD_SetCursorString(1,0,"DEC 2-BIN 3-HEX");
	
}


/**********************************************   Technical ***************************************/
u8 Converter_After_First_Entry(void)
{
	u8 keyTo=NO_KEY;
	Converter_To();
	while(keyTo!='1' && keyTo!='2' && keyTo!='3' && keyTo!='c')
	{
		keyTo=KEYPAD_GetKey();
		if(keyTo!='1' && keyTo!='2' && keyTo!='3' && keyTo!=NO_KEY && keyTo!='c')
		{
			LCD_Clear();
			LCD_SetCursorString(0,0," Enter numbers ");
			LCD_SetCursorString(1,0," From 1 to 3 :)");
			_delay_ms(500);
			Converter_To();
			
		}
	}
	return keyTo;
	
	
}


// We will get the decimal or binary or hex from the user
// we will convert it to decimal 
// Use LCD_WRITE_HEX AND LCD_WRITE_BINARY


// THE C BUTTON BRINGS YOU BACK TO THE CONVERT FROM PAGE
// Don't Get Out of the Mode until he PRESSES C

s32 Converter_GetDecimal(u8*check,u8*checkn)
{
	LCD_SetCursor(0,6);
	/* ONLY NUMBERS SHOULD BE ACTIVE*/
	s32 num=0;
	u8 key=23;
	*checkn=0; // 3alshan masln lw el rakm ely 2ablo saleb we ba3do mogab maykhodsh nafs el 1 we hwa mesh saleb

	u8 flag_negative=0,flag3=0;
	while(key!='=' && key!='c')
	{
		key=KEYPAD_GetKey();
		if(key=='-' && flag_negative==0)
		{
			LCD_SetCursorString(0,6,"        ");
			LCD_SetCursor(0,6);
			*checkn=1; // indicating this is a negative number
			key=NO_KEY; // to stay in the loop
			LCD_WriteChar('-');
			
		}
		if(key>='0' && key<='9')
		{
			if(flag3==0 && *checkn!=1)
			{
				LCD_SetCursorString(0,6,"        ");
				LCD_SetCursor(0,6);
			}
			LCD_WriteChar(key);
			flag_negative=1;
			num*=10;
			num+=(key-'0');
			flag3=1;
		}
		if(key=='c')
		{
			*check=1;
		}
		
		
	}
	return num;
	
	
	
	
	
	
	
	
	
}
s16 Converter_GetBinary(u8*check,u8*checkn)
{
	/* ONLY 1 AND 0 BUTTONS SHOULD BE ACTIVE */
	
	u8 str[8]={'0','0','0','0','0','0','0','0'};//initialize all to zeros
	s8 i=7;
	s16 num=0;
	u8 key=NO_KEY,flag=0;
	*checkn=0; // 3alshan masln lw el rakm ely 2ablo saleb we ba3do mogab maykhodsh nafs el 1 we hwa mesh saleb
	
	while(key!='=' && i>=0 && key!='c')
	{
		key=KEYPAD_GetKey();
		if(key=='0' || key=='1')
		{
			if(flag==0)
			{
				LCD_SetCursorString(0,7,"         ");
			}
			str[i]=key;
			i--;
			LCD_SetCursor(0,i+8);
			LCD_WriteChar(key);
			flag=1;
		}
		if(key=='c')
		{
			*check=1;
		}
	}
	
	while(i>=0 && *check==0)
	{
		LCD_SetCursor(0,i+7);
		LCD_WriteChar(str[i]);
		i--;
	}
	if(str[0]=='1')
	{
		*checkn=1;
		for(s8 j=7;j>=0;j--)
		{
			if(j!=0)
			{
				num+=(str[j]-'0')*power(2,7-j);	
			}
			else
			{
				num=num-128;
			}
			
		}
	}
	else
	{
		
		for(s8 k=7;k>=0;k--)
		{
			num+=(str[k]-'0')*power(2,7-k);
		}	
	}
	
	return num;	
	
	
	
	
	
}
u8 Converter_GetHex(u8*check)
{
	/* USE ONE BUTTON TO SHIFT BETWEEN LETTERS AND THEN PRESS ENTER TO LOCK IN */
	// 8 bit representation available 
	u8 lsb=0,msb=0,i=0,flag=0;
	u8 array[6]={'a','b','c','d','e','f'};
	u8 key=NO_KEY,num=0;
	while(key!='=' && key!='c' && msb==0)
	{
		key=KEYPAD_GetKey();
		if(key>='0' && key<='9')
		{
			if(flag==0)
			{
				LCD_SetCursorString(0,6,"0x00000000");
				LCD_SetCursor(0,15);
				LCD_WriteChar(key);
				lsb=key-'0';
				flag=1;
			}
			else
			{
				LCD_SetCursor(0,14);
				LCD_WriteChar(key);
				msb=key-'0';
			}
		}
		if(key=='/')
		{
			if(flag==0)
				LCD_SetCursorString(0,6,"0x00000000");
			while(key!='*' && key!='c')
			{
				if(flag==0)
				{
					
					LCD_SetCursor(0,15);
					LCD_WriteChar(array[i]);
					lsb=(array[i]-'a')+10;
				}
				else
				{
					LCD_SetCursor(0,14);
					LCD_WriteChar(array[i]);
					msb=(array[i]-'a')+10;
				}
				key=KEYPAD_GetKey();
				if(key=='*')
				{
					flag=1;
				}
				if(key=='/')
				{
					i++;
				}
				if(i==6)
				{
					i=0;
				}
			}
		}
		
		if(key=='c')
		{
			*check=1;
		}
	}
	
	
	num=lsb*1+msb*16;
	return num;
	
	
	
	
	
	
}
/*************************************   Layout  ********************************/

void Converter_DEC_To_DEC_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"DEC:");
	LCD_SetCursorString(1,0,"DEC:");
}
void Converter_BIN_To_BIN_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"BIN:");
	LCD_SetCursorString(1,0,"BIN:");
}
void Converter_HEX_To_HEX_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"HEX:");
	LCD_SetCursorString(1,0,"HEX:");
}
void Converter_DEC_To_BIN_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"DEC:");
	LCD_SetCursorString(1,0,"BIN:");
}
void Converter_DEC_To_HEX_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"DEC:");
	LCD_SetCursorString(1,0,"HEX:");
}
void Converter_BIN_To_DEC_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"BIN:");
	LCD_SetCursorString(1,0,"DEC:");
}
void Converter_HEX_To_DEC_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"HEX:");
	LCD_SetCursorString(1,0,"DEC:");
}
void Converter_BIN_To_HEX_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"BIN:");
	LCD_SetCursorString(1,0,"HEX:");
}
void Converter_HEX_To_BIN_Layout(void)
{
	LCD_Clear();
	LCD_SetCursorString(0,0,"HEX:");
	LCD_SetCursorString(1,0,"BIN:");
}