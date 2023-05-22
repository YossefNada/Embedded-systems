/*
 * MOTOR_cfg.c
 *
 * Created: 11/5/2022 11:21:57 AM
 *  Author: SOUQ COMPUTER
 */ 
#include "MOTOR_cfg.h"
#include "MOTOR_interface.h"
#include "StdTypes.h"
#include "DIO_interface.h"

// we will create an array of pins
// MAX NUMBER OF MOTORS 5 
DIO_Pin_type MOTOR_PinArray[10]={
	PINC1,  // M1_IN1
	PINC2,	// M1_IN2
	PINC2,  // M2_IN1
	PINC3,	// M2_IN2
	PINC4,  // M3_IN1
	PINC5,	// M3_IN2
	PINC6,  // M4_IN1
	PINC7,	// M4_IN2
	PIND0,  // M5_IN1
	PIND3,	// M5_IN2
};