#ifndef  __DHT20_H
#define  __DHT20_H

#include "ch32v30x.h"

typedef enum {
    DHT20_IDLE = 0,     
    DHT20_MEASURING,    
    DHT20_DONE,         
    DHT20_ERROR         
} DHT20_State;

uint8_t     DHT20_Init(void);

uint8_t     DHT20_GetData(float *temperature, float *humidity);

#endif
