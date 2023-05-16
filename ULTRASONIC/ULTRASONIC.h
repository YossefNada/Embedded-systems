

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "StdTypes.h"
#include "DIO_interface.h"
#include "DIO_cfg.h"

#define  US1   PIND0
#define  US2   PIND1
#define  US3   PIND2
#define  US4   PIND3

typedef   DIO_Pin_type ULTRASONIC_type;

typedef enum{
	ULTRASONIC_1=PIND0,
	ULTRASONIC_2=PIND1,
	ULTRASONIC_3=PIND2,
	ULTRASONIC_4=PIND3,
	}ULTRASONIC_type2;



void ULTRASONIC_Init(void);


u8 ULTRASONIC_GetDistance(ULTRASONIC_type us,u16* pdistance);
u8 ULTRASONIC_GetDistance2(ULTRASONIC_type2 us,u16* pdistance);





#endif /* ULTRASONIC_H_ */