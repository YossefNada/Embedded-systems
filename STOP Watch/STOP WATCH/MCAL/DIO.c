/*
 * DIO.c
 *
 * Created: 10/31/2022 10:34:43 PM
 *  Author: SOUQ COMPUTER
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "DIO_private.h"




static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	
	
	
	switch(status)
	{
		// we employ the offset idea
		case OUTPUT:
		if(pin>=PINA0 && pin<=PINA7)
		{
			SET(DDRA,(pin-PINA0)); // to make the pin output
			CLR(PORTA,(pin-PINA0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PINB0 && pin <=PINB7)
		{
			SET(DDRB,(pin-PINB0)); // to make the pin output
			CLR(PORTB,(pin-PINB0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PINC0 && pin <=PINC7)
		{
			SET(DDRC,(pin-PINC0)); // to make the pin output
			CLR(PORTC,(pin-PINC0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PIND0 && pin <=PIND7)
		{
			SET(DDRD,(pin-PIND0)); // to make the pin output
			CLR(PORTD,(pin-PIND0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		//switch(port)
		//{
			//case  PA:
			//SET(DDRA,pin_num);
			//CLR(PORTA,pin_num); // if there was a pull up resistor it will then give out high voltage so we clear it 
			//break;
			//case  PB:
			//SET(DDRB,pin_num);
			//CLR(PORTB,pin_num); // if there was a pull up resistor it will then give out high voltage so we clear it
			//break;
			//case  PC:
			//SET(DDRC,pin_num);
			//CLR(PORTC,pin_num); // if there was a pull up resistor it will then give out high voltage so we clear it
			//break;
			//case  PD:
			//SET(DDRD,pin_num);
			//CLR(PORTD,pin_num); // if there was a pull up resistor it will then give out high voltage so we clear it
			//break;
		//}
		break;
		
		case INFREE:
		if(pin>=PINA0 && pin<=PINA7)
		{
			CLR(DDRA,(pin-PINA0)); // to make the pin input
			CLR(PORTA,(pin-PINA0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PINB0 && pin <=PINB7)
		{
			CLR(DDRB,(pin-PINB0)); // to make the pin input
			CLR(PORTB,(pin-PINB0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PINC0 && pin <=PINC7)
		{
			CLR(DDRC,(pin-PINC0)); // to make the pin input
			CLR(PORTC,(pin-PINC0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PIND0 && pin <=PIND7)
		{
			CLR(DDRD,(pin-PIND0)); // to make the pin input
			CLR(PORTD,(pin-PIND0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		//switch(port)
		//{
			//case  PA:
			//CLR(DDRA,pin_num); // make it input
			//CLR(PORTA,pin_num); // stop the pull up resistor
			//break;
			//case  PB:
			//CLR(DDRB,pin_num);
			//CLR(PORTB,pin_num); 
			//break;
			//case  PC:
			//CLR(DDRC,pin_num);
			//CLR(PORTC,pin_num); 
			//break;
			//case  PD:
			//CLR(DDRD,pin_num);
			//CLR(PORTD,pin_num); 
			//break;
		//}
		break;
		
		case INPULL:
		if(pin>=PINA0 && pin<=PINA7)
		{
			CLR(DDRA,(pin-PINA0)); // to make the pin input
			SET(PORTA,(pin-PINA0)); // turn on pull up resistor 
		}
		else if(pin>=PINB0 && pin <=PINB7)
		{
			CLR(DDRB,(pin-PINB0)); // to make the pin input
			SET(PORTB,(pin-PINB0)); // turn on pull up resistor
		}
		else if(pin>=PINC0 && pin <=PINC7)
		{
			CLR(DDRC,(pin-PINC0)); // to make the pin input
			SET(PORTC,(pin-PINC0)); // turn on pull up resistor
		}
		else if(pin>=PIND0 && pin <=PIND7)
		{
			CLR(DDRD,(pin-PIND0)); // to make the pin input
			SET(PORTD,(pin-PIND0)); // turn on pull up resistor
		}
		
		//DIO_Port_type port=pin/8; // 3alshan ma a8yrsh fel code dah 7aga (FEkra bardo)
		//u8 pin_num=pin%8;
		//switch(port)
		//{
			//case  PA:
			//CLR(DDRA,pin_num); // make it input
			//SET(PORTA,pin_num);  // turn the pull up resistor on 
			//break;
			//case  PB:
			//CLR(DDRB,pin_num);
			//SET(PORTB,pin_num); 
			//break;
			//case  PC:
			//CLR(DDRC,pin_num);
			//SET(PORTC,pin_num);
			//break;
			//case  PD:
			//CLR(DDRD,pin_num);
			//SET(PORTD,pin_num); 
			//break;
		//}
		break;
	}
	
}

void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
	if(volt==HIGH)
	{
		if(pin>=PINA0 && pin<=PINA7)
		{
			SET(PORTA,(pin-PINA0)); // turn on pull up resistor
		}
		else if(pin>=PINB0 && pin <=PINB7)
		{
			SET(PORTB,(pin-PINB0)); // turn on pull up resistor
		}
		else if(pin>=PINC0 && pin <=PINC7)
		{
			SET(PORTC,(pin-PINC0)); // turn on pull up resistor
		}
		else if(pin>=PIND0 && pin <=PIND7)
		{
			SET(PORTD,(pin-PIND0)); // turn on pull up resistor
		}
		
			//switch(port)
			//{
				//case  PA:
				//SET(PORTA,pin_num);
				//break;
				//case  PB:
				//SET(PORTB,pin_num);
				//break;
				//case  PC:
				//SET(PORTB,pin_num);
				//break;
				//case  PD:
				//SET(PORTD,pin_num);
				//break;
			//}
	}
	else if(volt==LOW)
	{
		if(pin>=PINA0 && pin<=PINA7)
		{
			CLR(PORTA,(pin-PINA0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PINB0 && pin <=PINB7)
		{
			CLR(PORTB,(pin-PINB0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PINC0 && pin <=PINC7)
		{
			CLR(PORTC,(pin-PINC0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		else if(pin>=PIND0 && pin <=PIND7)
		{
			CLR(PORTD,(pin-PIND0)); // if there was a pull up resistor it will then give out high voltage so we clear it
		}
		//switch(port)
		//{
			//case  PA:
			//CLR(PORTA,pin_num);
			//break;
			//case  PB:
			//CLR(PORTB,pin_num);
			//break;
			//case  PC:
			//CLR(PORTB,pin_num);
			//break;
			//case  PD:
			//CLR(PORTD,pin_num);
			//break;
		//}
	}
}

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	//DIO_Port_type port=pin/8; // 3alshan ma a8yrsh fel code dah 7aga (FEkra bardo)
	//u8 pin_num=pin%8;
	DIO_PinVoltage_type status=LOW; // to avoid using (return) many times 
		if(pin>=PINA0 && pin<=PINA7)
		{
			status=READ_BIT(PINA,(pin-PINA0)); // READ(PINA,(pin-PINA0)) mesh PORTA 3alshan keda hatkon bte2ra el el pull up resistor
		}
		else if(pin>=PINB0 && pin <=PINB7)
		{
			status=READ_BIT(PINB,(pin-PINB0));  // we cannot write on PIN only port either it's output or input 
		} 
		else if(pin>=PINC0 && pin <=PINC7)
		{
			status=READ_BIT(PINC,(pin-PINC0));
		}
		else if(pin>=PIND0 && pin <=PIND7)
		{
			status=READ_BIT(PIND,(pin-PIND0));
		}
		return status;
		
		// Haro7 a2ra men el PINA mesh PORTA 3alshan enta asln 3amlha input w bel taly mesh hatro7 te2ra el pull up ya3ne
}		


void DIO_Inint()
{
	DIO_Pin_type i; // I TAKES VALUES FROM 0 TO 32
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinStatusArray[i]);
		
	}
	
	
}

void DIO_TogglePin(DIO_Pin_type pin)  
{
	if(pin>=PINA0 && pin<=PINA7)
	{
		TOGGLE_BIT(PORTA,(pin-PINA0));
	}
	else if(pin>=PINB0 && pin <=PINB7)
	{
		TOGGLE_BIT(PORTB,(pin-PINB0));
	}
	else if(pin>=PINC0 && pin <=PINC7)
	{
		TOGGLE_BIT(PORTC,(pin-PINC0));
	}
	else if(pin>=PIND0 && pin <=PIND7)
	{
		TOGGLE_BIT(PORTD,(pin-PIND0));
	}
}

void DIO_WritePort(DIO_Port_type port,u8 value)
{
	if(port==PA)
	{
		PORTA=value;
	}
	else if(port==PB)
	{
		PORTB=value;
	}
	else if(port==PC)
	{
		PORTC=value;
	}
	else if(port==PD)
	{
		PORTD=value;
	}
	
}
u8 DIO_ReadPort(DIO_Port_type port) // SO WE ARE READING INPUT PINS USE PIN NOT PORT
{
	u8 value=0;
	if(port==PA)
	{
		value=PINA;
	}
	else if(port==PB)
	{
		value=PINB;
	}
	else if(port==PC)
	{
		value=PINC;
	}
	else if(port==PD)
	{
		value=PIND;
	}
	return value;
}