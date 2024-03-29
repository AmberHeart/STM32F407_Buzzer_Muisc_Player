#include "pwm.h"

/*******************************************************************************
* ?? ?? ??         : TIM14_CH1_PWM_Init
* ????????		   : TIM14???1 PWM?????????
* ??    ??         : per:??????
					 psc:??????
* ??    ??         : ??
*******************************************************************************/
void TIM14_CH1_PWM_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);//???TIM14???
	
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource10,GPIO_AF_TIM14);//??????
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF; //?????????
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//???????
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//????100M
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//???????
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//????
	GPIO_Init(GPIOF,&GPIO_InitStructure); //?????????
	
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //???????
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //??????
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //?????????????
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM14,&TIM_OCInitStructure); //?????????1?????
	
	TIM_OC1PreloadConfig(TIM14,TIM_OCPreload_Enable); //???TIMx?? CCR1 ???????????
	TIM_ARRPreloadConfig(TIM14,ENABLE);//???????????
	
	TIM_Cmd(TIM14,ENABLE); //???????
		
}

void TIM13_CH1_PWM_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13,ENABLE);//??1???TIM13???????
	
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource8,GPIO_AF_TIM13);//1????????
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF; //???????3?????
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;//1??????????
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//???????a100M
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//??????????3?
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//?????-
	GPIO_Init(GPIOF,&GPIO_InitStructure); //3??????????11???
	
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //???????????????
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //??????????y
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //????????????????y????
	TIM_TimeBaseInit(TIM13,&TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM13,&TIM_OCInitStructure); //???3??????????????13???????
	
	TIM_OC1PreloadConfig(TIM13,TIM_OCPreload_Enable); //??1???TIMx??? CCR1 ??????????????????????
	TIM_ARRPreloadConfig(TIM13,ENABLE);//??1???????????????????
	
	TIM_Cmd(TIM13,ENABLE); //??1?????????????
		
}

