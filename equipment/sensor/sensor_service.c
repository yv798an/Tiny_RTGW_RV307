/********************************** (C) COPYRIGHT *******************************
* File Name          : sensor_service.c
* Author             : yvan
* Version            : V1.0.0
* Description        : Sensor service thread
*******************************************************************************/

#include <rtthread.h>

#include "sensor_service.h"

#include "sensor_data.h"


#include "../DHT20.h"
#include "../I2C/bsp_i2c1.h"
#include "../ADC/bsp_adc.h"

void sensor_service_thread(void *parameter)
{

    float temp = 0;
    float hum = 0;
    uint16_t adc = 0;

    sensor_data_t data;

    rt_memset(&data,0,sizeof(sensor_data_t));
    rt_kprintf("Sensor init\r\n");
    I2C1_Init();
    ADC1_Init();
    DHT20_Init();

    rt_kprintf("Sensor ready\r\n");
    while(1)
    {
        if(
            DHT20_Read(&temp,&hum) == 0
        )
        {
            data.temperature = temp;
            data.humidity = hum;
        }

        adc =ADC_Read_Avg(ADC_Channel_11,10);
        data.light_adc = adc;
        data.light_mv = adc * 3300 / 4095;

        sensor_data_update(&data);
        rt_thread_mdelay(1000);
    }

}

int sensor_set_led_state(uint8_t state)
{
    sensor_data_t data;
    sensor_data_get(&data);
    data.led_state = state;
    sensor_data_update(&data);

    return 0;

}