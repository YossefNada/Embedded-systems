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
	DDRB=0xff; // to set all of the pins to output 
	while(1)
	{
		
		for(int i=0;i<5;i++)
		{
			for(int k=0;k<2;k++)
			{
				PORTB=0xff;
				_delay_ms(250);
				PORTB=0;
				_delay_ms(250);
			}
		}
		for(int i=0;i<5;i++)
		{
			for(int k=0;k<2;k++) // might be less code size than the third and the last one 
			{
				PORTB=0x0f;
				_delay_ms(250);
				PORTB=0xf0;
				_delay_ms(250);
				
			}
		}
		for(int i=0;i<5;i++)
		{
			
			PORTB=0b00110011;
			_delay_ms(250);
			PORTB=0b11001100;
			_delay_ms(250);
			PORTB=0b00110011;
			_delay_ms(250);
			PORTB=0b11001100;
			_delay_ms(250);
		}
		for(int i=0;i<5;i++)
		{
			
			PORTB=0x55;
			_delay_ms(250);
			PORTB=0xaa;
			_delay_ms(250);
			PORTB=0x55;
			_delay_ms(250);
			PORTB=0xaa;
			_delay_ms(250);
		}
		
		
		
		
		
	}
    
	
	
	
	
}


