#include "beep.h"
#include "SysTick.h"
#include "key.h"
#include "led.h"
#include "adc.h"
#include "usart.h"
#include "pwm.h"
#include "tftlcd.h"
#include "string.h"
#include "chenmoshijin.h"
#include "hetangyuese.h"
#include "hongchenqingge.h"
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))


void BEEP_Init(void ) 
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����	
	RCC_AHB1PeriphClockCmd(BEEP_PORT_RCC,ENABLE); //ʹ�ܶ˿�Fʱ��
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT; //���ģʽ
	GPIO_InitStructure.GPIO_Pin=BEEP_PIN;//�ܽ�����F8
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//�ٶ�Ϊ100M
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//����
	GPIO_Init(BEEP_PORT,&GPIO_InitStructure); //��ʼ���ṹ��
	
	GPIO_ResetBits(BEEP_PORT,BEEP_PIN); //�رշ�����
	
}

u16 volume=50; // ��ȫ�ֱ����ж�������

void Sound(u16 frq)
{
    u32 time;
    if (frq != N)
    {
		if (volume != 0)
		{
			time = 500000 / ((u32)frq);
			BEEP = 1;
			delay_us(time * (float)(volume / 100.0));  // �������������ߵ�ƽʱ��
			BEEP = 0;
			delay_us(time * (2-(float)(volume / 100.0)));  // �������������͵�ƽʱ��
		}
		else
			delay_us(1000);
	}
	else
		delay_us(1000);
}


u8 pause_play=0;
u8 cur_num;
u16 cur_tone;

void pause(void)
{
	pause_play=!pause_play;
}

void turn_left(void)
{
	if (cur_num == 0)
		cur_num = 2;
	else
		cur_num--;
	cur_tone = 0;
}
void turn_right(void)
{
	if (cur_num == 2)
		cur_num = 0;
	else
		cur_num++;
	cur_tone = 0;
}

void replay(void)
{
	cur_tone = 0;
}
// ��������ṹ��,�ع����д��룬��L1����247����L2����262���Դ�����
typedef struct
{
    u8 music[300];
    u8 time[300];
    u8 length;
	char name[20];
} music_t;
u16 tone[] = {N, L1, L2, L3, L4, L5, L6, L7, M1, M2, M3, M4, M5, M6, M7,  H1, H2, H3, H4, H5, H6, H7};
music_t songs[3];

void songs_init()
{
	u8 i =0;
	//�쳾���
	u8 music_arr[]={5,5,6,8,7,6,5,6,0,0,//����
                5,5,6,8,7,6,5,3,0,0,
                2,2,3,5,3,5,6,3,2,1,
                6,6,5,6,5,3,6,5,0,0,

                5,5,6,8,7,6,5,6,0,0,
                5,5,6,8,7,6,5,3,0,0,
                2,2,3,5,3,5,6,3,2,1,
                6,6,5,6,5,3,6,1,	

                0,8,9,10,10,9,8,10,9,8,6,
                0,6,8,9,9,8,6,9,8,6,5,
                0,2,3,5,5,3,5,5,6,8,7,6,
                6,10,9,9,8,6,5,6,8};	
	u8 time_arr[] = {2,4,2,2,2,2,2,8,4, 4, //ʱ��
                2,4,2,2,2,2,2,8,4, 4, 
                2,4,2,4,2,2,4,2,2,8,
                2,4,2,2,2,2,2,8,4 ,4, 

                2,4,2,2,2,2,2,8,4, 4, 
                2,4,2,2,2,2,2,8,4, 4, 
                2,4,2,4,2,2,4,2,2,8,
                2,4,2,2,2,2,2,8,

                4, 2,2,2, 4, 2,2,2, 2,2,8,
                4, 2,2,2,4,2,2,2,2,2,8,
                4, 2,2,2,4,2,2,5,2,6,2,4,
                2,2 ,2,4,2,4,2,2,12};	
	//������ɫ
	u8 music_arr1[]={
	8,12,6,5,6,
	8,8,9,10,
	9,9,8,9,9,12,
	12,10,10,9,10,
	8,8,6,5,12,
	10,9,10,9,8,
	9,9,8,9,9,10,
	9,8,6,9,8,
	8,8,6,5,6,
	8,8,9,10,
	9,9,8,9,9,12,
	12,10,10,9,10,
	8,8,8,6,5,12,
	10,9,10,9,8,
	9,9,8,9,9,10,
	9,8,6,9,8,
	10,12,12,12,12,
	13,12,10,9,8,
	13,15,13,10,9,8,6,
	9,9,10,10,9,
	10,12,12,12,12,
	13,12,10,9,8,
	6,8,6,5,9,10,
	8,0
	};

	u8 time_arr1[]={
	2,4,2,4,4,
	4,2,2,8,
	2,4,2,4,2,2,
	2,2,2,2,8,
	2,4,2,4,4,
	2,2,2,2,8,
	2,4,2,2,4,2,
	2,2,2,2,8,
	2,4,2,4,4,
	2,4,2,8,
	2,4,2,4,2,2,
	2,2,2,2,8,
	2,2,2,2,4,4,
	2,2,2,2,8,
	2,4,2,2,4,2,
	2,2,2,2,8,
	2,4,2,4,4,
	2,2,2,2,8,
	2,2,2,2,2,2,2,2,
	4,2,2,2,6,
	2,4,2,4,4,
	2,2,2,2,8,
	2,2,2,2,4,4,
	12,4
	};

	// ��Ĭ�ǽ�
	u8 music_arr2[]={
	10,12,12,13,12,12,10,9,
	10,10,10,9,8,8,
	13,15,15,16,15,15,13,12,10,
	12,
	13,15,15,16,15,15,13,12,10,
	12,12,12,13,10,10,12,10,
	
	9,13,12,10,9,10,
	12,
	
	10,12,12,13,12,12,10,9,
	10,10,10,9,8,8,
	13,15,15,16,15,15,13,12,10,
	12,
	13,15,15,16,15,15,13,12,10,
	12,12,12,13,10,10,12,10,

	9,13,12,10,9,
	8,
	15,15,16,17,17,17,16,15,
	13,15,15,13,12,12,
	13,15,15,16,15,15,13,12,10,
	12,
	13,15,15,16,15,
	13,12,12,13,10,10,12,10,
	9,10,9,9,10,11,
	12,
	10,12,12,13,12,12,10,9,
	10,10,10,9,8,8,
	13,15,15,16,15,15,13,12,10,
	12,
	13,15,15,16,15,15,13,12,10,
	12,12,12,13,10,10,12,10,
	9,9,13,12,10,9,
	8
	};
	u8 time_arr2[]={
	2,2,2,1,1,4,1,3,
	2,2,2,1,1,8,
	2,2,2,1,1,4,2,2,2,
	16,
	2,2,2,1,1,4,2,2,2,
	2,2,2,1,1,4,2,2,
	
	6,2,4,2,2,2,
	16,

	2,2,2,1,1,4,1,3,
	2,2,2,1,1,8,
	2,2,2,1,1,4,2,2,2,
	16,
	2,2,2,1,1,4,2,2,2,
	2,2,2,1,1,4,2,2,

	6,2,4,2,2,
	16,
	4,2,1,1,3,1,1,3,
	2,2,2,1,1,8,
	2,2,2,1,1,4,2,2,2,
	16,
	6,2,2,2,4,
	2,2,2,1,1,4,2,2,
	6,2,4,2,2,2,
	16,
	2,2,2,1,1,4,1,3,
	2,2,2,1,1,8,
	2,2,2,1,1,4,2,2,2,
	16,
	2,2,2,1,1,4,2,2,2,
	2,2,2,1,1,4,2,2,
	2,4,2,2,4,2,
	16
	};

	strcpy(songs[0].name,"�쳾���");
	strcpy(songs[1].name,"������ɫ");
	strcpy(songs[2].name,"��Ĭ�ǽ�");
	for(cur_num=0;cur_num<3;cur_num++)
	{
		printf("����%d:%s��ʼ����...\r\n",cur_num,songs[cur_num].name);
		if (cur_num == 0)
		{
			for (i = 0; i < ARRAY_SIZE(music_arr); i++)
			{
				songs[0].music[i] = music_arr[i];
				songs[0].time[i] = time_arr[i];
			}
			songs[0].length = ARRAY_SIZE(music_arr);
		}
		else if (cur_num == 1)
		{
			songs[cur_num].length = ARRAY_SIZE(music_arr1);
			for(i=0;i<songs[cur_num].length;i++)
			{
				songs[cur_num].music[i] = music_arr1[i];
				songs[cur_num].time[i] = time_arr1[i];
			}
		}
		else if (cur_num == 2)
		{
			songs[cur_num].length = ARRAY_SIZE(music_arr2);
			for(i=0;i<songs[cur_num].length;i++)
			{
				songs[cur_num].music[i] = music_arr2[i];
				songs[cur_num].time[i] = time_arr2[i];
			}
		}
		printf("��������Ϊ��%d\r\n",songs[cur_num].length);
		printf("����%d:%s��ʼ���ɹ�!\r\n",cur_num,songs[cur_num].name);
	}
	cur_num = 0;
	//LCD_ShowString(50,10,tftlcd_data.width,tftlcd_data.height,12,"������ʼ���ɹ�!");
}


void play_music(void)
{
	u32 yanshi;
	u16 e;
	u16 adc_value;
	u16 last_volume;
	u8 last_num;
	// u16 last_tone;
	songs_init();

	yanshi = 10;
	// ������Ϣ��ʾ���� LCD��Ļ�ֱ���320*480
	LCD_Clear(WHITE);
	LCD_ShowString(80,10,tftlcd_data.width,tftlcd_data.height,16,"STM32F407 Music Player");
	LCD_ShowString(200,30,tftlcd_data.width,tftlcd_data.height,12,"By AmberHeart");
	LCD_ShowFontHZ(10,60, "���ڲ���");
	// ���ƽ���������ڲ���ѭ���и��½�����
	LCD_ShowFontHZ(10,350, "����");
	LCD_DrawRectangle(10, 385, 310, 405);
	LCD_Fill(11, 386, 309, 404, WHITE);
	// �������������
	LCD_ShowFontHZ(10,410, "����");
	LCD_DrawRectangle(10, 445, 310, 455);
	while(1)
	{
		last_num = cur_num;
		if (cur_num == 0){
			LCD_ShowFontHZ(100,90, "�쳾���");
			LCD_ShowPicture(65, 140, 191, 191, (u8 *)gImage_hongchenqingge);
			delay_ms(300);
		}
		else if (cur_num == 1){
			LCD_ShowFontHZ(100,90, "������ɫ");
			LCD_ShowPicture(65, 140, 191, 192, (u8 *)gImage_hetangyuese);
			delay_ms(300);
		}
		else if (cur_num == 2){
			LCD_ShowFontHZ(100,90, "��Ĭ�ǽ�");
			LCD_ShowPicture(65, 140, 193, 192, (u8 *)gImage_chenmoshijin);
			delay_ms(300);
		}
		LCD_Fill(11, 446, 11+volume*298/100, 454, GREEN);
		// ���Ÿ�������
		for(cur_tone=0;cur_tone<songs[cur_num].length;cur_tone++)
		{	
			// ���¸�����Ϣ
			if (cur_num != last_num)
			{
				if (cur_num == 0){
					LCD_ShowFontHZ(100,90, "�쳾���");
					LCD_ShowPicture(65, 140, 191, 191, (u8 *)gImage_hongchenqingge);
					delay_ms(300);
				}
				else if (cur_num == 1){
					LCD_ShowFontHZ(100,90, "������ɫ");
					LCD_ShowPicture(65, 140, 191, 192, (u8 *)gImage_hetangyuese);
					delay_ms(300);
				}
				else if (cur_num == 2){
					LCD_ShowFontHZ(100,90, "��Ĭ�ǽ�");
					LCD_ShowPicture(65, 140, 193, 192, (u8 *)gImage_chenmoshijin);
					delay_ms(300);
				}
				last_num = cur_num;
			}
			// ���½�����
			if (cur_tone <= 1){
				// ����ս�����
				LCD_Fill(11, 386, 309, 404, WHITE);
				// ����������
				LCD_Fill(11, 386, 11+cur_tone*298/songs[cur_num].length, 404, BLUE);
			}
			else
				// ��������
				LCD_Fill(11, 386, 11+cur_tone*298/songs[cur_num].length, 404, BLUE);
			// ��ͣ����
			while(pause_play)
			{
				LED1=0;
				LED2=1; // ��Ƴ���
				// ��ͣ��ʱ��ҲҪ����������
				adc_value = Get_ADC_Value(ADC_Channel_5,10);
				last_volume = volume;
				volume = (float)adc_value/4096 * 100;
				// ����������, ����adc����������+-3���ڵĶ���
				if (volume > last_volume+2 || volume < last_volume-2)
				{
					// �����������
					LCD_Fill(11, 446, 309, 454, WHITE);
					// �����������
					LCD_Fill(11, 446, 11+volume*298/100, 454, GREEN);
				}
			}
			LED2=0;
			LED1=1;
			// printf("cur")
			// ��ȡADCֵ����������
			adc_value = Get_ADC_Value(ADC_Channel_5,10);
			last_volume = volume;
			volume = (float)adc_value/4096 * 100;
			printf("adc_value=%d, volume=%d\r\n",adc_value,volume);
			// ����������, ����adc����������+-3���ڵĶ���
			if (volume > last_volume+2 || volume < last_volume-2)
			{
				// �����������
				LCD_Fill(11, 446, 309, 454, WHITE);
				// �����������
				LCD_Fill(11, 446, 11+volume*298/100, 454, GREEN);
			}
			
			printf("cur_tone=%d, cur_num=%d, music=%d, time=%d\r\n",cur_tone,cur_num,songs[cur_num].music[cur_tone],songs[cur_num].time[cur_tone]);
			for(e=0;e<((u16)songs[cur_num].time[cur_tone])*tone[songs[cur_num].music[cur_tone]]/yanshi;e++){
				// ����������
				Sound((u32)tone[songs[cur_num].music[cur_tone]]);
			}
			// last_tone = cur_tone;
		}
		turn_right();
	}
}


