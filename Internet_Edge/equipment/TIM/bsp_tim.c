#include "bsp_tim.h"


void TIM3_ADC_Trigger_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    TIM_TimeBaseStructure.TIM_Prescaler =7199;
    TIM_TimeBaseStructure.TIM_Period =99;
    TIM_TimeBaseStructure.TIM_CounterMode =TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
    TIM_SelectOutputTrigger(TIM3,TIM_TRGOSource_Update);
    TIM_Cmd(TIM3,ENABLE);

}
