#ifndef __DHT20_H
#define __DHT20_H


#include "ch32v30x.h"


uint8_t DHT20_Init(void);


uint8_t DHT20_Read(
        float *temperature,
        float *humidity
);


#endif