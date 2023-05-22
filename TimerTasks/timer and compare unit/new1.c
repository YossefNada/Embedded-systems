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
#include "NVM.h"
#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2
#define BUZZER PINC5
#define RELAY1 PINC4
#define LED_YELLOW PINC2





volatile u16 c=0;

int main(void)
{
	
	
	DIO_Inint();
	LCD_Init();

	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	
	
	//// timer on 
	////Pre_scalar 8  
	//TCCR0=2;
	//TCNT0=0;
	//TIMSK=1;
 	//SET(TCCR0,WGM01);// CTC MODE
 	//SET(TCCR0,COM00); // toggle pin 
 	//SET(TIMSK,0); // interrupt VF
 	//SET(TIMSK,OCIE0); // interrupt of compare unit
	//LCD_SetCursorString(0,0,"TIMER ON");
 	//OCR0=10;
	//u16 reading;	
	
	
	LCD_SetCursorString(0,0,"TIMER ON");
	
	// Turn on CTC mode
	SET(TCCR0,WGM01);
	// Toggle timer pin OC0 (it's operation is now toggling every compare match)
	SET(TCCR0,COM00);
	// set pre_scalar to CLK/8
	SET(TCCR0,CS01);
	// Turn on timer overflow interrupt
	//SET(TIMSK,TOIE0);
	// Turn on timer output compare interrupt
	//SET(TIMSK,OCIE0);
	OCR0=200;
	
	u16 reading;
	
	
	while (1)
	{
		
		LCD_SetCursor(1,0);
		reading = ADC_Read(LM_35);
		LCD_Write_4D(reading);
		OCR0=255-(reading/4);
		LCD_SetCursor(1,8);	
		LCD_Write_4D(OCR0);
		
	}
}

ISR(TIMER0_OVF_vect)
{
	DIO_TogglePin(PINC0);
}
ISR(TIMER0_OC_vect)
{
	DIO_TogglePin(PINC1);
}



//
//
//ISR(TIMER0_OVF_vect)
//{
	//// NO PRESCALING TCCR0=1;
	//// Tick time = 0.125 us Tinterrupt(overflow)= 32 us
	///*
		//--> First  signal :  PINC0 5   KHZ 50% Duty cycle  tON= 100 us tOFF= 100 us
		//--> Second signal :  PINC1 50  KHZ 50% Duty cycle  tON= 10  us tOFF= 10  us
		//--> Third  signal :  PINC2 500 KHZ 50% Duty cycle  tON= 1   us tOFF= 1   us
		//--> Fourth signal :  PINC3 500 KHZ 10% Duty cycle  tON= 0.2 us tOFF= 1.8 us  --> there will be 0.05 error in time which is 25 percent of the ON time (relatively big)
	//*/
	//static u16 c1=0,c2=0;
	//TCNT0=254; // overflow time is 0.25 us which is power consuming and delays all the other tasks
	//c2++;
	//if(c2==7) // OFF time will take 1.75 us
	//{
		//DIO_TogglePin(PINC3);
	//}
	//else if(c2==8) // ON TIME will take 0.25 us
	//{
		//DIO_TogglePin(PINC3);
		//c2=0;
	//}
	//c1++;
	//if(c1%4==0)
	//{
		//DIO_TogglePin(PINC2); // ON TIME and OFF TIME will be 1 us 
	//}
	//if(c1%40==0)
	//{
		//DIO_TogglePin(PINC1);
	//}
	//if(c1%400==0)
	//{
		//DIO_TogglePin(PINC0);
		//c1=0;
	//}
	//
	//
//
	//
//}
//





//ISR(TIMER0_OVF_vect)
//{
	//static u16 counter=0;
	//counter++;
	//TCNT0=6;
	//if(counter%20==0)
	//{
		//DIO_TogglePin(PINC0);
		 //
	//}
	//if(counter%40==0)
	//{
		//DIO_TogglePin(PINC1);
		//
	//}
	//if(counter%100==0)
	//{
		//DIO_TogglePin(PINC2);
	//}
	//if(counter==200)
	//{
		//counter=0;
	//}
//
	//
//}



//ISR(TIMER0_OVF_vect)
//{
	//static u16 c=0;
	//c++;
	//
	//if(c==3906)
	//{
		//TCNT0=192;
		//DIO_TogglePin(PINC0);
		//c=0;
	//}
//}
//ISR(TIMER0_OVF_vect)
//{
	//static u16 c=0;
	//c++;
	//TCNT0=6; // yeb2a kol mara hyb2a overflow 3and 250 mesh 256 we dah sahly 3amlyt el division 
	//if(c==4000)
	//{
		//TCNT0=192;
		//DIO_TogglePin(PINC0);
		//c=0;
	//}
//}

//ISR(TIMER0_OVF_vect)
//{
	//static u16 c=0;
	//c++;
	//TCNT0=6; // yeb2a kol mara hyb2a overflow 3and 250 mesh 256 we dah sahly 3amlyt el division
	//if(c==32)
	//{
		//
		//DIO_WritePin(PINC0,HIGH);
		//
	//}
	//else if(c==40)
	//{
		//DIO_WritePin(PINC0,LOW);
		//c=0;
	//}
//}

//
//ISR(TIMER0_OVF_vect)
//{
	//static u16 flag=0;
//
	//if(flag==0)
	//{
		//TCNT0=236;
		//DIO_WritePin(PINC0,HIGH);
		//flag=1;
		//
	//}
	//else if(flag==1)
	//{
		//TCNT0=176;
		//DIO_WritePin(PINC0,LOW);
		//flag=0;
	//}
//}
