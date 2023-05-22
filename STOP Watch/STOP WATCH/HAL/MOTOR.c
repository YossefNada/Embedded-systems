/*
 * MOTOR.c
 *
 * Created: 11/5/2022 10:44:48 AM
 *  Author: SOUQ COMPUTER
 */ 
#include "StdTypes.h"
#include "MOTOR_interface.h"
#include "DIO_interface.h"
#include "MOTOR_cfg.h"

extern DIO_Pin_type MOTOR_PinArray[10];


void MOTOR_Init(void)
{
	/* DO YOUR CODE HERE */
}




void MOTOR_Stop(MOTOR_type motor)
{
	DIO_WritePin(MOTOR_PinArray[(motor-M1)*2],LOW);
	DIO_WritePin(MOTOR_PinArray[(motor-M1)*2+1],LOW);
	//switch(motor)
		//{
		//case M1:
		//DIO_WritePin(M1_IN1,LOW);
		//DIO_WritePin(M1_IN2,LOW);
		//break;
		//case M2:
		//DIO_WritePin(M2_IN2,LOW);
		//DIO_WritePin(M2_IN1,LOW);
		//break;
		//case M3:
		//DIO_WritePin(M3_IN2,LOW);
		//DIO_WritePin(M3_IN1,LOW);
		//break;
		//case M4:
		//DIO_WritePin(M4_IN1,LOW);
		//DIO_WritePin(M4_IN2,LOW);
		//break;
	    //}

}
void MOTOR_CW(MOTOR_type motor)
{
	DIO_WritePin(MOTOR_PinArray[(motor-M1)*2],HIGH);
	DIO_WritePin(MOTOR_PinArray[(motor-M1)*2+1],LOW);
	//switch(motor)
	//{
		//
	//
	//case M1:
	//DIO_WritePin(M1_IN1,HIGH);
	//DIO_WritePin(M1_IN2,LOW);
	//break;
	//case M2:
	//DIO_WritePin(M2_IN2,LOW);
	//DIO_WritePin(M2_IN1,HIGH);
	//break;
	//case M3:
	//DIO_WritePin(M3_IN2,LOW);
	//DIO_WritePin(M3_IN1,HIGH);
	//break;
	//case M4:
	//DIO_WritePin(M4_IN1,HIGH);
	//DIO_WritePin(M4_IN2,LOW);
	//break;
	//}
}
void MOTOR_CCW(MOTOR_type motor)
{
	DIO_WritePin(MOTOR_PinArray[(motor-M1)*2],LOW);
	DIO_WritePin(MOTOR_PinArray[(motor-M1)*2+1],HIGH);
	//switch(motor)
	//{
	//case M1:
	//DIO_WritePin(M1_IN1,LOW);
	//DIO_WritePin(M1_IN2,HIGH);
	//break;
	//case M2:
	//DIO_WritePin(M2_IN2,HIGH);
	//DIO_WritePin(M2_IN1,LOW);
	//break;
	//case M3:
	//DIO_WritePin(M3_IN2,HIGH);
	//DIO_WritePin(M3_IN1,LOW);
	//break;
	//case M4:
	//DIO_WritePin(M4_IN1,LOW);
	//DIO_WritePin(M4_IN2,HIGH);
	//break;
	//}
}