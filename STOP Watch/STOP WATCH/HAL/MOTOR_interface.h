/*
 * MOTOR_interface.h
 *
 * Created: 11/5/2022 10:45:08 AM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_


#include "StdTypes.h"

typedef enum{
	M1=0,
	M2,
	M3,
	M4
	}MOTOR_type;
	
void MOTOR_Stop(MOTOR_type motor);
void MOTOR_CW(MOTOR_type motor);
void MOTOR_CCW(MOTOR_type motor);
// SPEED FROM 0 TO 100%  
void MOTOR_Speed(MOTOR_type motor,u8 speed);
void MOTOR_Init(void);



#endif /* MOTOR_INTERFACE_H_ */