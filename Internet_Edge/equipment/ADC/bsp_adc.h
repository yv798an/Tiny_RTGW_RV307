#ifndef __BSP_ADC_H
#define __BSP_ADC_H

#include "ch32v30x.h"
#include <stdint.h>

void ADC1_Init(void);

uint16_t ADC_Read(uint8_t ch);

uint16_t ADC_Read_Avg(uint8_t ch, uint8_t times);

uint16_t ADC_To_mV(uint16_t adc);

#endif