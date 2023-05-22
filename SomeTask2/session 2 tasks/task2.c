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
		while(!(PIND>>2 &1)|| !(PIND>>3 &1))
		{
			if(!(PIND>>2 & 1))
			{
				if(PORTB==128)
				{
					PORTB=1;
				}
				else
				{
					PORTB=PORTB<<1;
				}
				_delay_ms(200);
				
			}
			else
			{
				if(PORTB==1)
				{
					PORTB=128;
				}
				else
				{
					PORTB=PORTB>>1;	
				}
				_delay_ms(200);
				
			}
		
		
		}
	
	}
}

























/*

DDRC=0x0;
	DDRB=0xff;
	PINC=0;
	int counter=1;
	while(1)
	{
		if(PINC==1 && counter==0)
		{
			PORTB=0xff;
			
		}
		if(PINC==1 && counter)
		{
			PORTB=0;
			
		}
		if(PINC==0)
		{
			if(PORTB==0xff)
				counter=1;
			else
				counter=0;
		}
		
		if(PINC==1)  // bas el moshkela en feh dynamic issue 3alshan el code hy3ml toggle ktter awy wenta lesa btdos
		{  
			PORTB~=PORTB;   // aw momken a3mel toggle bel xor   (Dah momken ye3ml moshkela 3alshan ba2y el port momken yekon mash8ol)
			while(PINC); // polling busy wait mekhlay el processor wa2ef le7ad ma el condition yet8yr
		}
		
		
		char flag=0;
		if(PINC==1)
		{
			if(flag==0)
			{
				PORTB=0xff;
				flag=1;
			}
		}
		else
		{
			flag=1;
		}
		
		
		
	}



*/




























// HOW TO CONNECT 16 LEDS ON JUST 4 PINS WITH EACH OF THEM ACTING individually 
/*
 -->> the minumum number of pins we can use is 4 pins for each of them to act individually 
 -->> we will use a decoder ,the decoder will create 16 possible combinations just for 4 inputs (pins) 
 -->> we will use PORTB 1,2,3,4 pins
 


DDRB=0xff;
while(1)
{
	PORTB=1; //pin 5 is low
	_delay_ms(500);
	for(int i=0;i<3;i++)
	{
		PORTB=PORTB & (~(1<<(i))); // to shut the LED first
		PORTB=PORTB | (1<<(i+1));
		_delay_ms(500);
	}
	
	PORTB=0xfe;
	_delay_ms(500);
	
	for(int i=0;i<3;i++)
	{
		PORTB=PORTB | ((1<<(i))); // to shut the LED first
		PORTB=PORTB & (~(1<<(i+1)));
		
		_delay_ms(500);
	}
	PORTB=0xf7;
	for(int i=3;i>0;i--)
	{
		PORTB=PORTB | ((1<<(i))); // to shut the LED first
		PORTB=PORTB & (~(1<<(i-1)));
		
		_delay_ms(500);
	}
	PORTB=8;
	_delay_ms(500);
	for(int i=3;i>0;i--)
	{
		PORTB=PORTB & (~(1<<(i))); // to shut the LED first
		PORTB=PORTB | ((1<<(i-1)));
		if(PORTB!=1)
		_delay_ms(500);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}




*/
































// SESSION 1
/*
#define CLOCK 4000000

#ifndef CLOCK
#define CLOCK 1000000  // to act as a default value if the user didnot add one
#warning "CAREFULL YOU DIDNOT ADD CLOCK"
#endif


void delay_s (long time)
{
	for(int i=0;i<time*CLOCK;i++)
	{
		
	}
}




DDRB=0xff;// to see if it is either input or output 
	//PORTB=0xff;
	//_delay_ms(1000);
	//PORTB=0x0f;
	PORTB=1;
	_delay_ms(500);
	unsigned char x=1;
	while(1)  // to hold the code working on the micro_controller 
	{
		
		PORTB<<=1;
		_delay_ms(500);
		if(PORTB==0x80)
		{
			while(PORTB!=0)
			{
				PORTB>>=1;
				_delay_ms(500);
			}
			_delay_ms(500);
			PORTB=1;
			_delay_ms(500);
			
			
			PORTB=x;
			_delay_ms(500);
			x=x*2;
			if(x==0)
			{
				x=1;
			}
			
			
			
		}
		
		
	}
	





*/









