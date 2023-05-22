/*
 * WorkProject.c
 *
 * Created: 10/22/2022 3:12:07 PM
 * Author : SOUQ COMPUTER
 */ 

#define DDRA (*(volatile unsigned char*)0x3A)
#define PORTA (*(volatile unsigned char*)0x3B)
#define PINA (*(volatile unsigned char*)0x39)

#define DDRC (*(volatile unsigned char*)0x35)
#define PORTC (*(volatile unsigned char*)0x34)
#define PINC (*(volatile unsigned char*)0x33)

#define DDRB (*(volatile unsigned char*)0x37)
#define PORTB (*(volatile unsigned char*)0x38)
#define PINB (*(volatile unsigned char*)0x36)

#define DDRD (*(volatile unsigned char*)0x31)
#define PORTD (*(volatile unsigned char*)0x32)
#define PIND (*(volatile unsigned char*)0x30)



#define F_CPU 8000000
#include <util/delay.h>








int main(void)
{
	
	DDRD=0; // put pins D to input 
	PORTD=0xff; // to use the pull up
	DDRB=0xff;
	PORTB=1;
	while(1)
	{
		if((PIND>>2 & 1) == 0) // ba3mel shift lel register nafso 3alshan ya2ema yerg3 sefr ya wa7ed
		{
			if(PORTB==128)
			{
				PORTB=1;
			}
			else
			{
				PORTB=PORTB<<1;
			}
			
			while((PIND>>2 & 1)==0);
		}
		if((PIND>>3 & 1) == 0)
		{
			if(PORTB==1)
			{
				PORTB=128;
			}
			else
			{
				PORTB=PORTB>>1;
			}
			
			while((PIND>>3 & 1) == 0);
		}
	}
	
	
	
	
	
}











