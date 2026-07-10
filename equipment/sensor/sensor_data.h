#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <stdint.h>

typedef struct
{
    float temperature;   // 温度
    float humidity;      // 湿度

    uint16_t light_adc;  // 光照ADC值
    uint32_t light_mv;   // 光照电压

    uint8_t led_state;   // LED状态 0:OFF 1:ON

} sensor_data_t;

void sensor_data_init(void);

void sensor_data_update(sensor_data_t *data);

int sensor_data_get(sensor_data_t *data);

void sensor_data_lock(void);

void sensor_data_unlock(void);

#endif