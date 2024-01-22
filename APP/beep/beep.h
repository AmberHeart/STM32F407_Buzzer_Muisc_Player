#ifndef _beep_H
#define _beep_H

#include "system.h"

#define BEEP_PORT 			GPIOF   
#define BEEP_PIN 			GPIO_Pin_8
#define BEEP_PORT_RCC		RCC_AHB1Periph_GPIOF

#define BEEP PFout(8)

// 定义低音频率
#define L1 262
#define L2 294
#define L3 330
#define L4 349
#define L5 392
#define L6 440
#define L7 494
// 定义中音
#define M1 523
#define M2 587
#define M3 659
#define M4 698
#define M5 784
#define M6 880
#define M7 988
// 定义高音
#define H1 1047
#define H2 1175
#define H3 1319
#define H4 1397
#define H5 1568
#define H6 1760
#define H7 1976
// 定义不发音
#define N 0

extern u8 pause_play;
extern u8 cur_num;
extern u16 i;

void BEEP_Init(void);
void Sound(u16 frq);
void Sound2(u16 time);
void play_music(void);
void play_successful(void);
void play_failed(void);
void pause(void);
void turn_left(void);
void turn_right(void);
void replay(void);

#endif


