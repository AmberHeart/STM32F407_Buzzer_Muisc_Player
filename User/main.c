#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "beep.h"
#include "exti.h"
#include "key.h"
#include "adc.h"
#include "pwm.h"

int main()
{	
	u8 i=0;
	u16 color=0;
	// ����adc����pwm������
	u16 adc_value=0;
	u16 light=0;
	
	SysTick_Init(168);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	
	USART1_Init(115200);
	TFTLCD_Init();			//LCD��ʼ��

	LED_Init();
	KEY_Init();
	My_EXTI_Init(); //�жϷ����ʼ��
	
	BEEP_Init();
	ADCx_Init();

	// ���ֲ��Ų���
	play_music();
	
}


