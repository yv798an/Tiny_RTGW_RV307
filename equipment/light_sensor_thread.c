#include "rtthread.h"

#include "ADC/bsp_adc.h"

void light_sensor_thread(void *parameter)
{

    uint16_t adc_value;

    uint32_t voltage;

    /*
        ADC初始化只做一次
    */

    ADC1_Init();

    while(1)
    {

        adc_value =
            ADC_Read_Avg(
                ADC_Channel_11,
                10
            );

        voltage =
            adc_value * 3300 / 4095;

        rt_kprintf(
            "Light ADC=%d Voltage=%dmV\r\n",
            adc_value,
            voltage
        );

        rt_thread_mdelay(1000);

    }

}