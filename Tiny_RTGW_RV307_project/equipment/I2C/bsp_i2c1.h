#ifndef __BSP_I2C1_H
#define __BSP_I2C1_H

#include "ch32v30x.h"
#include "rtthread.h"


void I2C1_Init(void);


uint8_t I2C_Write(
        uint8_t addr,
        uint8_t *data,
        uint8_t len
);


uint8_t I2C_Read(
        uint8_t addr,
        uint8_t *buf,
        uint8_t len
);


#endif