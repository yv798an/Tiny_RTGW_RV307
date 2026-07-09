#include "rtthread.h"
#include "sensor_data.h"

#include "../DHT20.h"
#include "../I2C/bsp_i2c1.h"
#include "../ADC/bsp_adc.h"

#include <stdio.h>


sensor_data_t sensor_data;


static void Light_Update(sensor_data_t *data)
{
    uint16_t adc_value;

    /*
     * PC1 -> ADC_IN11
     */
    adc_value = ADC_Read_Avg(
                    ADC_Channel_11,
                    10
                );

    data->light_adc = adc_value;


    data->light_mv =
        (uint32_t)adc_value * 3300 / 4095;
}



static void DHT20_Update(sensor_data_t *data)
{

    float temperature;
    float humidity;

    if(DHT20_Read(
            &temperature,
            &humidity) == 0)
    {

        data->temperature = temperature;

        data->humidity = humidity;

    }
    else
    {

        rt_kprintf(
            "DHT20 read failed!\n"
        );

    }

}


void sensor_thread_entry(void *parameter)
{

    I2C1_Init();


    if(DHT20_Init())
    {
        rt_kprintf(
            "DHT20 init failed!\n"
        );
    }
    else
    {
        rt_kprintf(
            "DHT20 ready\n"
        );
    }


    ADC1_Init();



    while(1)
    {

        DHT20_Update(
            &sensor_data
        );


        Light_Update(
            &sensor_data
        );



        rt_kprintf(
            "$%d,%d,%d,%d#\r\n",

            (int)sensor_data.temperature,

            (int)sensor_data.humidity,

            sensor_data.light_adc,

            sensor_data.light_mv
        );



        rt_thread_mdelay(2000);

    }

}