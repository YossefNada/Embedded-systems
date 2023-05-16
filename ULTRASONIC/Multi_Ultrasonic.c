/*
 * Multi_Ultrasonic.c
 *
 * Created: 2/12/2023 3:46:27 PM
 *  Author: SOUQ COMPUTER
 */ 
#include "ULTRASONIC.h"
#include "Multi_Ultrasonic.h"
#include "StdTypes.h"
#include "Timers.h"
#include "Timers_Services.h"


#define NO_OF_US 4

u16 Ultrasonic_array[NO_OF_US]={0,0,0,0};

void Multi_Ultrasonic_Init(void)
{
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	ULTRASONIC_Init();
}
void Multi_Ultrasonic_Runnable(void)
{
	u8 error=1;
	u16 distance=0;
	//ULTRASONIC_type us;
	for(u8 i=0;i<NO_OF_US;i++)
	{
// 		switch(i)
// 		{
// 			case 0: us=US1;
// 					break;
// 			case 1: us=US2;
// 					break;
// 			case 2: us=US3;
// 					break;
// 			case 3: us=US4;
// 					break;
// 		}
		error=ULTRASONIC_GetDistance(US1+i,&distance);
		if(error==1)
		{
			Ultrasonic_array[i]=distance;
		}	
		//_delay_ms(60); // it needs 60 ms between every reading
	}	
}
u16 Multi_Ultrasonic_Getter(ULTRASONIC_type us)
{
	return Ultrasonic_array[us-US1];
}