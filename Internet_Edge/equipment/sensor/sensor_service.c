#include <rtthread.h>

#include "sensor_service.h"
#include "sensor_data.h"

#include "DHT20.h"
#include "bsp_i2c1.h"
#include "bsp_adc.h"
#include "bsp_tim.h"

void sensor_service_thread(void *parameter)
{
    float temp = 0;
    float hum = 0;

    uint16_t adc = 0;

    sensor_data_t data;

    rt_memset(&data, 0, sizeof(sensor_data_t));
    rt_kprintf("Sensor init\r\n");
    I2C1_Init();
    ADC1_Init();
    TIM3_ADC_Trigger_Init();
    DHT20_Init();

    rt_kprintf("Sensor ready\r\n");

    while(1)
    {
        if(DHT20_GetData(&temp, &hum) == 0)
        {
            data.temperature = temp;
            data.humidity = hum;
        }

        adc = ADC_Read_Avg(ADC_Channel_11, 10);
        data.light_adc = adc;
        data.light_mv = ADC_To_mV(adc);

        {
            sensor_data_t tmp;
            if(sensor_data_get(&tmp) == 0)
            {
                data.led_state = tmp.led_state;
            }
        }

        sensor_data_updata(&data);
        rt_thread_mdelay(1000);
    }

}

int sensor_set_led_state(uint8_t state)
{
    sensor_data_t data;
    sensor_data_get(&data);
    data.led_state = state;
    sensor_data_updata(&data);

    return 0;
}