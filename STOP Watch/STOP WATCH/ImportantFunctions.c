/*
 * ImportantFunctions.c
 *
 * Created: 10/30/2022 10:04:00 PM
 *  Author: SOUQ COMPUTER
 */ 



void set_bit(volatile unsigned char * p,char bit) // you will send the address of the port
{
	*p |= 1<<bit;
}
