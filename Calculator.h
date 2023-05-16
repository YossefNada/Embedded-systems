/*
 * Calculator.h
 *
 * Created: 11/26/2022 6:46:23 PM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "KeyPad.h"
#include "KeyPad_cfg.h"
#include "LCD.H"
#include "LCD_cfg.h"
#include "StdTypes.h"


void CAL_INIT(void);
s32 CAL_GetNum(c8*operation,u8 k); // is an intial value for the number to start from


#endif /* CALCULATOR_H_ */