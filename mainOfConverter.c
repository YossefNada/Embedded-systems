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


#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2




int main(void)
{
	DIO_Inint();
	LCD_Init();
	KEYPAD_Init();
	LCD_Signature();
	_delay_ms(1000);
	Converter_Init();
	Converter_From();
	s32 decimal=0;
	
	/* APP DEFINED VARIABLES */
	u8 keyFrom=NO_KEY,keyTo=NO_KEY;
	
	while (1)
	{
		
		keyFrom=KEYPAD_GetKey();
		switch(keyFrom)
		{
			case NO_KEY :
						break;
			case     '1':
						keyTo=Converter_After_First_Entry();
						// Convert from Decimal to 
						
						switch(keyTo)
						{
							case '1': // from  Dec to Decimal
							Converter_DEC_To_DEC_Layout();
							u8 check=0,checkn=0;
							while(check==0)
							{
								decimal=Converter_GetDecimal(&check,&checkn);
								LCD_SetCursor(1,6);
								if(checkn==1)
								{
									LCD_WriteNumber((~decimal)+1);
									LCD_WriteString("    ");
								}
								else
								{
									
									LCD_WriteNumber(decimal);
									LCD_WriteString("    ");
								}
								
							}
							Converter_From();
							break;
							case '2': // from  Dec to binary
							Converter_DEC_To_BIN_Layout();
							u8 check1=0,checkn1=0;
							while(check1==0)
							{
								
								decimal=Converter_GetDecimal(&check1,&checkn1);
								LCD_SetCursor(1,6);
								if(checkn1==1)
								{
									LCD_WriteBinary((~decimal)+1);
								}
								else
								{
									
									LCD_WriteBinary(decimal);
								}
							}
							Converter_From();
							break;
							case '3': // from  Dec to hex
							Converter_DEC_To_HEX_Layout();
							u8 check2=0,checkn2=0;
							while(check2==0)
							{
								decimal=Converter_GetDecimal(&check2,&checkn2);
								LCD_SetCursor(1,6);
								if(checkn2==1)
								{
									LCD_WriteHEX((~decimal)+1);
								}
								else
								{
									
									LCD_WriteHEX(decimal);
								}
							}
							Converter_From();
							break;
							case 'c':
							Converter_From();
							break;
						}
						
						
						
						
						break;
			case     '2': 
						keyTo=Converter_After_First_Entry();
						s16 num_dec=0;
						u8 check_bin=0,check_binN=0;
						switch(keyTo)
						{
							case '1': // from  BIN to Decimal
							Converter_BIN_To_DEC_Layout();
							while(check_bin==0)
							{
								num_dec=Converter_GetBinary(&check_bin,&check_binN);
								LCD_SetCursor(1,7);
								if(check_binN==1)
								{
									
									if(check_bin!=1)
									{
										LCD_WriteNumber(num_dec);
										LCD_WriteString("    ");
									}
									
								}
								else
								{
									if(check_bin!=1)
									{
										LCD_WriteNumber(num_dec);
										LCD_WriteString("    ");
									}
								}
								
							}
							Converter_From();
							break;
							case '2': // from  BIN to binary
							Converter_BIN_To_BIN_Layout();
							while(check_bin==0)
							{
								num_dec=Converter_GetBinary(&check_bin,&check_binN);
								LCD_SetCursor(1,7);
								if(check_binN==1)
								{
									num_dec*=-1; // to make it positive
									if(check_bin!=1)
									LCD_WriteBinary((~num_dec)+1);
								}
								else
								{
									if(check_bin!=1)
									LCD_WriteBinary(num_dec);
								}
							}
							Converter_From();
							break;
							case '3': // from  BIN to hex
							Converter_BIN_To_HEX_Layout();
							while(check_bin==0)
							{
								num_dec=Converter_GetBinary(&check_bin,&check_binN);
								LCD_SetCursor(1,6);
								
								if(check_binN==1)
								{
									num_dec*=-1; // to make it positive
									if(check_bin!=1)
									LCD_WriteHEX((~num_dec)+1);
								}
								else
								{
									if(check_bin!=1)
									LCD_WriteHEX(num_dec);
								}
							}
							Converter_From();
							break;
							case 'c':
									Converter_From();
									break;
						}
						break;
			case     '3':
						keyTo=Converter_After_First_Entry();
						u8 dec=0,checkhex=0;
						switch(keyTo)
						{
							case '1': // from  HEX to Decimal
							Converter_HEX_To_DEC_Layout();
							LCD_SetCursorString(0,6,"0x00000000");
							while(checkhex==0)
							{
								dec=Converter_GetHex(&checkhex);
								if(checkhex==0)
								{
									LCD_SetCursor(1,6);
									LCD_WriteNumber(dec);
									LCD_WriteString("    ");
								}
							}
							Converter_From();
							
							break;
							case '2': // from  HEX to binary
							Converter_HEX_To_BIN_Layout();
							LCD_SetCursorString(0,6,"0x00000000");
							while(checkhex==0)
							{
								dec=Converter_GetHex(&checkhex);
								if(checkhex==0)
								{
									LCD_SetCursor(1,6);
									LCD_WriteBinary(dec);
									
								}
							}
							Converter_From();
							break;
							case '3': // from  HEX to hex
							Converter_HEX_To_HEX_Layout();
							LCD_SetCursorString(0,6,"0x00000000");
							while(checkhex==0)
							{
								dec=Converter_GetHex(&checkhex);
								if(checkhex==0)
								{
									LCD_SetCursor(1,6);
									LCD_WriteHEX(dec);
								}
							}
							Converter_From();
							break;
							case 'c':
							Converter_From();
							break;
						}
						break;
			case     'c':LCD_Clear();
						Converter_From();
						break;
			default    :LCD_Clear();
					    LCD_SetCursorString(0,0," Enter numbers ");
						LCD_SetCursorString(1,0," From 1 to 3 :)");
						_delay_ms(500);
						Converter_From();
						break;
					
		}	
		
	}
}











