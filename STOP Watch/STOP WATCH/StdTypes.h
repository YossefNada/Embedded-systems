/*
 * StdTypes.h
 *
 * Created: 10/30/2022 9:46:29 PM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_





typedef unsigned char u8;
typedef   signed char s8;



typedef unsigned int u16;
typedef   signed int s16;


typedef unsigned long u32;
typedef   signed long s32;

#define NULL_PTR ((void*)0)

typedef enum{
	OK,
	NOK,
	NULL,
	OUT_OF_RANGE
	}ERROR_type;

typedef enum{
	FALSE,
	TRUE
	}bool_type;



#define  MAX_U16  (u16(65535))  // 3alashan lw estkhdmto feh comparison masln yeb2a 3aref el type 3alshan el static analysis tool eny ana ely 3amel el kalam dah
#define  MAX_S16  (s16(32767))  // 3alashan lw estkhdmto feh comparison masln yeb2a 3aref el type 3alshan el static analysis tool eny ana ely 3amel el kalam dah
#define  MIN_S16  (s16(-32768)) // 3alashan lw estkhdmto feh comparison masln yeb2a 3aref el type 3alshan el static analysis tool eny ana ely 3amel el kalam dah
#define  MIN_U16  (u16(0))      // 3alashan lw estkhdmto feh comparison masln yeb2a 3aref el type 3alshan el static analysis tool eny ana ely 3amel el kalam dah 


#define  MAX_U32 (u32(4294967295))

 









































#endif /* STDTYPES_H_ */