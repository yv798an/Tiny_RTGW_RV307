#include "bsp_adc.h"
#include "rtthread.h"


void ADC1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    ADC_InitTypeDef ADC_InitStructure = {0};


    /*
        PC1 -> ADC_IN11
    */

    RCC_APB2PeriphClockCmd(
        RCC_APB2Periph_GPIOC |
        RCC_APB2Periph_ADC1,
        ENABLE
    );


    RCC_ADCCLKConfig(RCC_PCLK2_Div8);



    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;

    GPIO_InitStructure.GPIO_Mode =
        GPIO_Mode_AIN;

    GPIO_Init(GPIOC,
              &GPIO_InitStructure);



    ADC_InitStructure.ADC_Mode =
        ADC_Mode_Independent;


    ADC_InitStructure.ADC_ScanConvMode =
        DISABLE;


    ADC_InitStructure.ADC_ContinuousConvMode =
        DISABLE;


    ADC_InitStructure.ADC_ExternalTrigConv =
        ADC_ExternalTrigConv_None;


    ADC_InitStructure.ADC_DataAlign =
        ADC_DataAlign_Right;


    ADC_InitStructure.ADC_NbrOfChannel =
        1;



    ADC_Init(
        ADC1,
        &ADC_InitStructure
    );


    ADC_Cmd(
        ADC1,
        ENABLE
    );



    /*
        校准
    */

    ADC_ResetCalibration(ADC1);

    while(
        ADC_GetResetCalibrationStatus(ADC1)
    );



    ADC_StartCalibration(ADC1);


    while(
        ADC_GetCalibrationStatus(ADC1)
    );

}



/*
    单次ADC读取
*/

uint16_t ADC_Read(uint8_t ch)
{
    uint32_t timeout = 100000;



    ADC_RegularChannelConfig(
        ADC1,
        ch,
        1,
        ADC_SampleTime_239Cycles5
    );



    ADC_SoftwareStartConvCmd(
        ADC1,
        ENABLE
    );



    while(
        !ADC_GetFlagStatus(
            ADC1,
            ADC_FLAG_EOC
        )
    )
    {

        if(--timeout == 0)
        {
            return 0;
        }

    }



    return ADC_GetConversionValue(
        ADC1
    );
}



/*
    多次平均
*/

uint16_t ADC_Read_Avg(
        uint8_t ch,
        uint8_t times
)
{
    uint32_t sum = 0;


    for(uint8_t i=0;i<times;i++)
    {

        sum += ADC_Read(ch);


        /*
            RTOS延时
        */

        rt_thread_mdelay(5);

    }


    return sum / times;
}