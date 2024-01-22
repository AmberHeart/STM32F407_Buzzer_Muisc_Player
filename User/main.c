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
	// 测试adc控制pwm呼吸灯
	u16 adc_value=0;
	u16 light=0;
	
	SysTick_Init(168);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	
	USART1_Init(115200);
	TFTLCD_Init();			//LCD初始化

	LED_Init();
	KEY_Init();
	My_EXTI_Init(); //中断服务初始化
	
	BEEP_Init();
	ADCx_Init();

	// 音乐播放部分
	play_music();
	
}


