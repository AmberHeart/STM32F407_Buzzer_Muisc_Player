#include "exti.h"
#include "led.h"
#include "SysTick.h"
#include "key.h"
#include "beep.h"

void My_EXTI_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource4);
	
	
	//EXTI0 NVIC ????
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//EXTI0?ùù????
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//????????
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//???????
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ??????
	NVIC_Init(&NVIC_InitStructure);	//?????????????????VIC?????
	
	//EXTI2 NVIC ????
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;//EXTI2?ùù????
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//????????
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =2;		//???????
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ??????
	NVIC_Init(&NVIC_InitStructure);	//?????????????????VIC?????
	
	//EXTI3 NVIC ????
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//EXTI3?ùù????
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//????????
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;		//???????
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ??????
	NVIC_Init(&NVIC_InitStructure);	//?????????????????VIC?????
	
	//EXTI4 NVIC ????
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;//EXTI4?ùù????
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//????????
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//???????
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ??????
	NVIC_Init(&NVIC_InitStructure);	//?????????????????VIC?????
	
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2|EXTI_Line3|EXTI_Line4; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
}

void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0)==1)
	{
		delay_ms(10);
		if(KEY_UP==1)
		{
			replay();
		}	
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}

void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2)==1)
	{
		delay_ms(10);
		if(KEY2==0)
		{	
			turn_left();
		}
		
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}

void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3)==1)
	{
		delay_ms(10);
		if(KEY1==0)
		{	
			pause();
		}
		
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}

void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4)==1)
	{
		delay_ms(10);
		if(KEY0==0)
		{
			turn_right();
		}
		
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}


