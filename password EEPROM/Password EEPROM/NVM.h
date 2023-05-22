/*
 * NVM.h
 *
 * Created: 12/31/2022 11:54:07 AM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef NVM_H_
#define NVM_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"


u8 NVM_READ (u16 address);
void NVM_WRITE(u16 address,u8 data); // take care that you need to wait for the flag to indicate that it has finished writing the first operation  use void for busy wait or if you were going to use global variable




#endif /* NVM_H_ */