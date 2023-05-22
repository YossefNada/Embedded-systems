/*
 * _7Segment.c
 *
 * Created: 10/30/2022 9:38:27 PM
 *  Author: SOUQ COMPUTER
 */ 

#include "MemMap.h"	
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_interface.h"


/**********************************  7 SEG CONFIGURATION ***********************************/

#define SEGMENT_PORT1 PORTA
#define SEGMENT_PORT2 PORTB


#define BUZZER PINC5
#define LED_RED PINC0
#define LED_GREEN PINC1
#define LED_BLUE PINC2




void segment_display2(char n)
{
	switch (n)
	{
		case 0:
		PORTD=0x3f;
		break;
		
	}
}
void segement_display(char n)  // this method is called look up table 
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
		PORTA=arr[n]<<1;// n/10 lw 2 digits
		//PORTC=arr[n%10]; // 2 7_segment display		
}
void segement_display_BCD(char n)
{
	char n1,n2;
	
	n1=n%10; // first number
	n2=n/10; // 2nd number
	PORTA=n1|(n2<<4);	
}


void segement_display_BCD_HEX(char n)
{
	PORTA=n; // 3ady khales aw bkol basata tesht8l bel remainder w divide 16
	// el decoder beta3t el seven_segment BCD by7wl lel rosmat el HEX
}


void segement_display_BCD_MUX(char n)
{
	// the idea of the multiplexed segment 
	// the pins take high and low values very fast with certain predetermined combinations these combinations are given to for example two different LEDS segments to provide two different numbers 
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; // hastkhdm el array 3alshan el MUX segment mafhash decoder
	char n1=n%10; // first number(units)
	char n2=n/10; // 2nd number(tens)
	
	// 3alshan proteus feh moshkela lazem a2fel el ola el awel abl ma aft7 el tanya
	SET(PORTD,0); // ha2fel el 7segment ely 3ala el shmal (3alshan hya common cathode wana 7atet 3aleha wa7ed)
	PORTC=arr[n1];
	CLR(PORTD,1); // hash8l el 7 segment el tanya
	_delay_ms(10);
	SET(PORTD,1);
	PORTC=arr[n2];
	CLR(PORTD,0);
	_delay_ms(10); // 50 ms is the minimum delay that my eye could spare so that i would see  both of the numbers together
	// ha2fel el ely 3ala el shmal we ab3at el rakm lely 3ala yemen we  ash8l ely 3ala el yemen we ba3den a2fel ely 3ala yemen we ab3at el rakm we ash8l ely 3ala el shmal
	
	
	/******************************************   LW 3AYEZ ASH8L COUNTER BEL MUX   *****************************************/
	/*
	//_delay_ms(300); // en el delay hy5ly segement wa7da bas ely tsht8l tol fatrt el delay hat8lb 3aleha b fkert ta2seem el delay
	for(char i=0;i<15;i++)
	{
		segement_display_BCD_MUX(x);
		_delay_ms(6);
	}
	x++;
	
	
	// we akhly baly bardo lw 3ayez a3mel busy wait
	// momken a3mel decoder 3ala el pins el control fa at7km fel 8 b 3 bits bas 
	*/
	
}


void segement_display_BCD_MUX_on_kit(char n)
{
	// the idea of the multiplexed segment 
	// the pins take high and low values very fast with certain predetermined combinations these combinations are given to for example two different LEDS segments to provide two different numbers 
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; // hastkhdm el array 3alshan el MUX segment mafhash decoder
	char n1=n%10; // first number(units)
	char n2=n/10; // 2nd number(tens)
	
	// 3alshan proteus feh moshkela lazem a2fel el ola el awel abl ma aft7 el tanya
	SET(PORTC,6); // ha2fel el 7segment ely 3ala el shmal (3alshan hya common cathode wana 7atet 3aleha wa7ed)
	PORTA=arr[n1]<<1;
	CLR(PORTC,7); // hash8l el 7 segment el tanya
	_delay_ms(5);
	SET(PORTC,7);
	PORTA=arr[n2]<<1;
	CLR(PORTC,6);
	_delay_ms(5); // 50 ms is the minimum delay that my eye could spare so that i would see  both of the numbers together
	// ha2fel el ely 3ala el shmal we ab3at el rakm lely 3ala yemen we  ash8l ely 3ala el yemen we ba3den a2fel ely 3ala yemen we ab3at el rakm we ash8l ely 3ala el shmal
	
	
	/******************************************   LW 3AYEZ ASH8L COUNTER BEL MUX   *****************************************/
	/*
	//_delay_ms(300); // en el delay hy5ly segement wa7da bas ely tsht8l tol fatrt el delay hat8lb 3aleha b fkert ta2seem el delay
	for(char i=0;i<15;i++)
	{
		segement_display_BCD_MUX(x);
		_delay_ms(6);
	}
	x++;
	
	
	// we akhly baly bardo lw 3ayez a3mel busy wait
	// momken a3mel decoder 3ala el pins el control fa at7km fel 8 b 3 bits bas 
	*/
	
}


void end_of_time(void)
{
	// FLASH ZERO AND THREE LEDS WITH BUZZER
	for(u8 i=0;i<5;i++) // 5 times
	{
		DIO_WritePin(BUZZER,HIGH);
		DIO_WritePin(LED_BLUE,HIGH);
		DIO_WritePin(LED_GREEN,HIGH);
		DIO_WritePin(LED_RED,HIGH);
		for(u8 j=0;j<100;j++)
		{
			segement_display_BCD_MUX_on_kit(0);
		}
		DIO_WritePin(BUZZER,LOW);
		DIO_WritePin(LED_BLUE,LOW);
		DIO_WritePin(LED_GREEN,LOW);
		DIO_WritePin(LED_RED,LOW);
		for(u8 i=0;i<100;i++)
		{
			CLR(PORTC,6); // to shut it down
			CLR(PORTC,7);	
			_delay_ms(10);
		}
		
		
		
	}
}