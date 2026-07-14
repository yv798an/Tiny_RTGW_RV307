#ifndef __BSP_I2C1_SAFE_H
#define __BSP_I2C1_SAFE_H

#include <rtthread.h>
#include <stdint.h>

void i2c1_safe_init(void);

uint8_t i2c1_write_safe(uint8_t addr, uint8_t *data, uint8_t len);
uint8_t i2c1_read_safe(uint8_t addr, uint8_t *buf, uint8_t len);


#endif