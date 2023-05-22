/*
 * DIO_private.h
 *
 * Created: 10/31/2022 10:35:39 PM
 *  Author: SOUQ COMPUTER
 */ 

// FILE NO ONE WILL USE BUT ME THE DEVELOPER


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#define CTOK 273

extern const DIO_PinStatus_type PinStatusArray[TOTAL_PINS]; // ACCORDING TO SECURITY RULES NO GLOBAL ARRAY SHOULD BE WANDERING AROUND  
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status); 


#endif /* DIO_PRIVATE_H_ */