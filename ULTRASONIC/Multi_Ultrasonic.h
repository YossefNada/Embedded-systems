/*
 * Multi_Ultrasonic.h
 *
 * Created: 2/12/2023 3:46:51 PM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef MULTI_ULTRASONIC_H_
#define MULTI_ULTRASONIC_H_

#include "StdTypes.h"
#include "DIO_interface.h"
#include "DIO_cfg.h"

// The ultrasonic sensors need to put together on conesuctive pins with nothing separating between them 

#define  US1   PIND0
#define  US2   PIND1
#define  US3   PIND2
#define  US4   PIND3

typedef   DIO_Pin_type ULTRASONIC_type;

void Multi_Ultrasonic_Init(void);
void Multi_Ultrasonic_Runnable(void);
u16 Multi_Ultrasonic_Getter(ULTRASONIC_type us);



#endif /* MULTI_ULTRASONIC_H_ */