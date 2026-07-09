#ifndef __BUZZER_H
#define __BUZZER_H

#include "ch32v30x.h"

void Buzzer_GPIO_Init(void);
void TIM1_PWM_Init(void);
void Buzzer_SetFreq(uint32_t freq);

#endif