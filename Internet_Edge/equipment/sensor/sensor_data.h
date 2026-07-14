#ifndef SECSOR_DATA_H
#define SECSOR_DATA_H

#include <stdint.h>

typedef struct 
{
    float temperature;
    float humidity;

    uint16_t light_adc;
    uint32_t light_mv;

    uint8_t led_state;
    
} sensor_data_t;

void sensor_data_init(void);

void sensor_data_updata(sensor_data_t *data);

int sensor_data_get(sensor_data_t *data);

void sensor_data_lock(void);

void sensor_data_unlock(void);

#endif