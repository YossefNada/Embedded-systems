/*
 * DIO_interface.h
 *
 * Created: 10/31/2022 10:35:07 PM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// what we will provide for the HAL team

// Anything we send to the function is better than #define

typedef enum{
	OUTPUT,
	INFREE, // input and free from pull up resistor
	INPULL
	}DIO_PinStatus_type;
	
// we can write the return type of the function in it's name as a rule 


typedef enum{
	PA,
	PB,
	PC,
	PD
	}DIO_Port_type;

typedef enum{
	LOW=0,
	HIGH
	}DIO_PinVoltage_type;
	
	
	
typedef enum{
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
	}DIO_Pin_type;
		
	
	
extern void DIO_Inint(void); // extern to make it visible that these functions can be used in other files (ABI function)
	


extern void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt);

extern DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin);

extern void DIO_TogglePin(DIO_Pin_type pin);

extern void DIO_WritePort(DIO_Port_type port,u8 value);
extern u8 DIO_ReadPort(DIO_Port_type port);









#endif /* DIO_INTERFACE_H_ */