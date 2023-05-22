/*
 * DIO_cfg.c
 *
 * Created: 10/31/2022 10:36:16 PM
 */ 



#include "StdTypes.h"
#include "DIO_interface.h"




const DIO_PinStatus_type PinStatusArray[TOTAL_PINS]={   // const hykhleh yeero7 el RO.DATA we bel taly ma7adesh hy3rf ybwzo fey ay 7eta tanya
	OUTPUT, /* PORT A PIN 0*/
	OUTPUT, /* PORT A PIN 1*/
	OUTPUT, /* PORT A PIN 2*/
	OUTPUT, /* PORT A PIN 3*/
	OUTPUT, /* PORT A PIN 4*/
	OUTPUT, /* PORT A PIN 5*/
	OUTPUT, /* PORT A PIN 6*/
	OUTPUT, /* PORT A PIN 7*/
	OUTPUT, /* PORT B PIN 0*/
	INPULL, /* PORT B PIN 1*/
	INFREE, /* PORT B PIN 2*/
	OUTPUT, /* PORT B PIN 3*/
	INPULL, /* PORT B PIN 4*/
	INFREE, /* PORT B PIN 5*/
	OUTPUT, /* PORT B PIN 6*/
	INPULL, /* PORT B PIN 7*/
	OUTPUT, /* PORT C PIN 0*/
	OUTPUT, /* PORT C PIN 1*/
	OUTPUT, /* PORT C PIN 2*/
	OUTPUT, /* PORT C PIN 3*/
	OUTPUT, /* PORT C PIN 4*/
	OUTPUT, /* PORT C PIN 5*/
	OUTPUT, /* PORT C PIN 6*/
	OUTPUT, /* PORT C PIN 7*/
	OUTPUT, /* PORT D PIN 0*/
	INPULL, /* PORT D PIN 1*/
	INPULL, /* PORT D PIN 2*/
	INPULL, /* PORT D PIN 3*/
	INPULL, /* PORT D PIN 4*/
	INFREE, /* PORT D PIN 5*/
	OUTPUT, /* PORT D PIN 6*/
	INPULL, /* PORT D PIN 7*/
	
	
};
