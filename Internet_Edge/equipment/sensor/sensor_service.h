#ifndef __SENSOR_SERVICE_H
#define __SENSOR_SERVICE_H

#include "sensor_data.h"

void sensor_service_thread(void *parameter);

int sensor_set_led_state(uint8_t);

#endif