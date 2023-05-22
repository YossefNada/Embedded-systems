/*
 * NVM.c
 *
 * Created: 12/31/2022 1:03:52 PM
 *  Author: SOUQ COMPUTER
 */ 

#include "NVM.h"

/*

we assume that no Flash Boot Loader is present in the software.
If such code is present, the EEPROM write function must also wait for any
ongoing SPM command to finish.

*/


void NVM_Init(void)
{
	
	/*Write any required code here*/
	if(NVM_READ(2)!='z')
	{
		NVM_WRITE(0,0);
		NVM_WRITE(1,0);
	}
	
	
}


u8 NVM_READ(u16 uiAddress)
{
	Global_Disable(); // Any incident interrupts during the following procedures will cause errors so it's important to disable the global interrupt as well as (See boot loader specs)
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	
	Global_Enable();
	
	/* Return data from data register */
	return EEDR;
}


void NVM_WRITE(u16 uiAddress,u8 ucData)
{
	Global_Disable();
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
	Global_Enable();
}