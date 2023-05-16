

#include "StdTypes.h"
#include "DIO_interface.h"
#include "Timers.h"
#include "ULTRASONIC.h"
#define  F_CPU 8000000
#include <util/delay.h>

static volatile u16 t1,t2;
static volatile u8 flag=0;


volatile u32 T1,T2,T3,ton,toff,flag2=0;
volatile u32 counter;


static void f1(void);
static void f2(void);

void ULTRASONIC_Init(void)
{
	Global_Enable();
	
	Timer1_OVF_SetCallBack(f2);
	Timer1_ICU_SetCallBack(f1);
	Timer1_OVF_InterruptEnable();
	Timer1_ICU_InterruptEnable();
}

u8 ULTRASONIC_GetDistance(ULTRASONIC_type us,u16*pdistance)
{
	u16 distance;
	u16 c=0;
	Timer1_InputCaptureEdge(RISING);
	DIO_WritePin(us,HIGH);
	_delay_us(10);
	DIO_WritePin(us,LOW);
	while(flag2==0 && c<23000) // RUNOUT TIME is 23 ms
	{
		c++;
		_delay_us(1);
	}
	if(flag2==1)
	{
		distance=ton/58;
		flag2=0;
		*pdistance=distance;
		//_delay_ms(60); // the sensors needs at least 60 ms before it can read again
		return 1;
	}
	return 0;
	
	
	
	/*
	u16 t,d;
	TCNT1=0;
	flag=0;
	u16 c=0;
	Timer1_InputCaptureEdge(RISING);
	DIO_WritePin(us,HIGH);
	_delay_us(10);
	DIO_WritePin(us,LOW);
	while((flag<2)&&(c<23000))
	{
		c++;
		_delay_us(1);
	}
	if (flag==2)
	{
		t=t2-t1;
		d=t/58;
		*pdistance=d;
		return 1;
		
	}
	
	return 0;
	*/
}

static void f1(void)
{
	static u8 flag3=0;
	if(flag3==0)
	{
		T1=ICR1;
		flag3=1;
		counter=0;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if(flag3==1)
	{
		T2=ICR1;
		flag3=0;
		flag2=1;
		ton=T2-T1+(u32)counter*(u32)65535; // 65535 is the overflow it has to be #define
		Timer1_InputCaptureEdge(RISING);
	}
// 	if (flag==0)
// 	{
// 		t1=ICR1;
// 		Timer1_InputCaptureEdge(FALLING);
// 		flag=1;
// 	}
// 	else if (flag==1)
// 	{
// 		t2=ICR1;
// 		flag=2;
// 	}
}
static void f2(void)
{
	counter++;
}

/*
typedef enum {
	even,
	odd
	}parity_type;

u16 uartframe(u8 data ,parity_type parity)
{
	u16 frame=0;
	u8 data2=data;
	u8 c=0;
	u8 p_bit;
	while(data)
	{
		c+=data&1;
		data>>=1;
	}
	if(c%2==0)&&parity==even)
	{
		p_bit=0;
	}
	
	frame=(u16)data2<<1;
	frame=frame|((u16)p_bit<<9);
	frame=frame|(1<<10);
	return frame;
	
}


/*
u16 get_distance(ULTRASONIC_type us)
{
	
	return arr[us];
}

/*

volatile u32 t1,t2,t3,ton,toff,flag2=0;
volatile u32 c;


void f1(void);
void f2(void);


int main(void)
{
	Global_Enable();
	
	DIO_Inint();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	Timer1_OVF_InterruptEnable();
	Timer1_OVF_SetCallBack(f2);
	
	
	
	
	
	

	
	
	Timer1_ICU_SetCallBack(f1);
	Timer1_ICU_InterruptEnable();
	
	u32 distance=0;
	
	
	
	while (1)
	{
		Timer1_InputCaptureEdge(RISING);
		DIO_WritePin(PIND0,HIGH);
		_delay_us(10);
		DIO_WritePin(PIND0,LOW);
		while(flag2==0)
		{
			
		}
		distance=ton/58;
		flag2=0;
		LCD_SetCursor(1,0);
		LCD_WriteNumber(distance);
		_delay_ms(60);
		
	}
}



void f1 (void)
{
	static u8 flag=0;
	if(flag==0)
	{
		t1=ICR1;
		flag=1;
		c=0;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if(flag==1)
	{
		t2=ICR1;
		flag=0;
		flag2=1;
		ton=t2-t1+(u32)c*65535;
		Timer1_InputCaptureEdge(RISING);
	}
	
	
}
void f2(void)
{
	c++;
}


*/