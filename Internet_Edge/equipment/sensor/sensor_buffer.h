#ifndef SENSOR_BUFFER_H
#define SENSOR_BUFFER_H 

#include "sensor_data.h"

void sensor_buffer_init(void);

void sensor_buffer_write(sensor_data_t *data);
void sensor_buffer_read(sensor_data_t *out);

#endif