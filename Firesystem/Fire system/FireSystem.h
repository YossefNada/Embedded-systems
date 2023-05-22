

#ifndef FIRESYSTEM_H_
#define FIRESYSTEM_H_

#include "StdTypes.h"

/*   ---> Documentation

inputs  --> Temp and Smoke sensors, KEYPAD
outputs --> RED,YELLOW LEDs and BUZZER, LCD

status 1 --> temp < 50 Fine
status 1 --> temp < 50 Heat --> Yellow LED
status 1 --> temp > 50 + smoke  --> Red LED and Buzzzer and Motor 
 





*/


void FireSystem_Init(void);















#endif /* FIRESYSTEM_H_ */