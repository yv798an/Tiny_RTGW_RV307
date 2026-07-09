#include <rtthread.h>
#include "sensor_service.h"

#include "../DHT20.h"
#include "../I2C/bsp_i2c1.h"
#include "../ADC/bsp_adc.h"

static sensor_data_t sensor_data =
{
    0
};

static rt_mutex_t sensor_mutex;

void sensor_service_thread(void *parameter)
{

    float temp;
    float hum;

    uint16_t adc;

    /*
        创建互斥锁
    */

    sensor_mutex =
        rt_mutex_create(
            "sensor",
            RT_IPC_FLAG_FIFO
        );


    if(sensor_mutex == RT_NULL)
    {
        rt_kprintf(
            "sensor mutex create failed\r\n"
        );

        return;
    }

    rt_kprintf(
        "Sensor init\r\n"
    );

    I2C1_Init();

    ADC1_Init();

    DHT20_Init();

    rt_kprintf(
        "Sensor ready\r\n"
    );

    while(1)
    {

        /*
            读取DHT20
        */

        if(
            DHT20_Read(
                &temp,
                &hum
            )
            ==0
        )
        {

            rt_mutex_take(
                sensor_mutex,
                RT_WAITING_FOREVER
            );

            sensor_data.temperature =temp;
            sensor_data.humidity =hum;
            rt_mutex_release(
                sensor_mutex
            );

        }

        /*
            ADC读取
        */

        adc =
            ADC_Read_Avg(
                ADC_Channel_11,
                10
            );

        rt_mutex_take(
            sensor_mutex,
            RT_WAITING_FOREVER
        );

        sensor_data.light_adc =
            adc;


        sensor_data.light_mv =
            adc * 3300 /4095;



        rt_mutex_release(
            sensor_mutex
        );

        rt_thread_mdelay(1000);

    }

}


/*
    对外提供安全读取接口

*/

int sensor_get_data(sensor_data_t *data)
{

    if(data==RT_NULL)
    {
        return -1;
    }

    if(sensor_mutex==RT_NULL)
    {
        return -2;
    }

    rt_mutex_take(
        sensor_mutex,
        RT_WAITING_FOREVER
    );

    *data =
        sensor_data;

    rt_mutex_release(
        sensor_mutex
    );
    
    return 0;

}

int sensor_set_led_state(uint8_t state)
{

    if(sensor_mutex == RT_NULL)
    {
        return -1;
    }
    rt_mutex_take(sensor_mutex,RT_WAITING_FOREVER);
    sensor_data.led_state = state;
    rt_mutex_release(sensor_mutex);

    return 0;
}