#include "bsp_adc.h"
#include "rtthread.h"
#include "ulog.h"

#ifndef GET_INT_SP
#define GET_INT_SP()   asm("csrrw sp,mscratch,sp")
#define FREE_INT_SP()  asm("csrrw sp,mscratch,sp")
#endif

static volatile uint16_t adc_value = 0;

void ADC1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    ADC_InitTypeDef ADC_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_ADC1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T3_TRGO;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;

    ADC_Init(ADC1, &ADC_InitStructure);

    ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_239Cycles5);

    ADC_ExternalTrigConvCmd(ADC1, ENABLE);

    ADC_Cmd(ADC1, ENABLE);
    ADC_ResetCalibration(ADC1);

    while(ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);

    while(ADC_GetCalibrationStatus(ADC1));

    ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    ULOG_INFO("ADC1 init OK, TIM3 trigger at 100Hz");
}

void ADC1_2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void ADC1_2_IRQHandler(void)
{
    GET_INT_SP();
    rt_interrupt_enter();
    if(ADC_GetITStatus(ADC1, ADC_IT_EOC))
    {
        ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);
        adc_value = ADC_GetConversionValue(ADC1);
    }
    rt_interrupt_leave();
    FREE_INT_SP();
}

uint16_t ADC_Read(uint8_t ch)
{
    (void)ch;
    return adc_value;
}

uint16_t ADC_Read_Avg(uint8_t ch, uint8_t times)
{
    uint32_t sum = 0;

    for(uint8_t i = 0; i < times; i++)
    {
        sum += ADC_Read(ch);
    }

    return sum / times;
}

uint16_t ADC_To_mV(uint16_t adc)
{
    return (uint16_t)((uint32_t)adc * 3300 / 4095);
}