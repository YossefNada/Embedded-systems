
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




// HOW TO CONNECT 16 LEDS ON JUST 4 PINS WITH EACH OF THEM ACTING individually 
/*
 -->> the minumum number of pins we can use is 4 pins for each of them to act individually 
 -->> we will use a decoder ,the decoder will create 16 possible combinations just for 4 inputs (pins) 
 -->> we will use PORTB 1,2,3,4 pins
 
*/
int main(void)
{
	DDRB=0x0f;
	PORTB=0;
	_delay_ms(200);
	while(1)
	{
		PORTB++;
		_delay_ms(200);
		if((PORTB+1)==16)
		{
			for(int i=16;i>0;i--)
			{
				PORTB--;
				_delay_ms(200);
				if(PORTB==0)
					break;
			}

		}
		
		
	
	}
	
	
	
	
	
}
















































































/*
 * WorkProject.c
 *
 * Created: 10/22/2022 3:12:07 PM
 * Author : SOUQ COMPUTER
 */ 
/*
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




// HOW TO CONNECT 16 LEDS ON JUST 4 PINS WITH EACH OF THEM ACTING individually 
/*
 -->> the minumum number of pins we can use is 4 pins for each of them to act individually 
 -->> we will use a decoder ,the decoder will create 16 possible combinations just for 4 inputs (pins) 
 -->> we will use PORTB 1,2,3,4 pins
 
*/
/*
int main(void)
{
	DDRB=0xff;
	PORTB=0;
	_delay_ms(500);
	while(1)
	{
		PORTB++;
		_delay_ms(500);
		if(PORTB==16)
		{
			PORTB=1;
			_delay_ms(500);
		}
		
		
	
	}
	
	
	
	
	
}


*/