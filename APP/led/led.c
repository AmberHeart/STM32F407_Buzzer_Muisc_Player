#include "led.h"

/*******************************************************************************
* �� �� ��         : LED_Init
* ��������		   : LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����
	
	RCC_AHB1PeriphClockCmd(LED1_PORT_RCC|LED2_PORT_RCC,ENABLE); //ʹ�ܶ˿�ʱ��
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT; //���ģʽ
	GPIO_InitStructure.GPIO_Pin=LED1_PIN;//�ܽ�����
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//�ٶ�Ϊ100M
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//����
	GPIO_Init(LED1_PORT,&GPIO_InitStructure); //��ʼ���ṹ��
	GPIO_SetBits(LED1_PORT,LED1_PIN);
	
	GPIO_InitStructure.GPIO_Pin=LED2_PIN;//�ܽ�����
	GPIO_Init(LED2_PORT,&GPIO_InitStructure); //��ʼ���ṹ��
	GPIO_SetBits(LED2_PORT,LED2_PIN);
}



