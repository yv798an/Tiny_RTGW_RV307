#include "bsp_i2c1.h"
#include "bsp_i2c1_safe.h"

static rt_mutex_t i2c_mutex;

void i2c1_safe_init(void)
{
    I2C1_Init();
    i2c_mutex = rt_mutex_create("i2c1", RT_IPC_FLAG_FIFO);
}

uint8_t i2c1_write_safe(uint8_t addr, uint8_t *data, uint8_t len)
{
    rt_mutex_take(i2c_mutex, RT_WAITING_FOREVER);
    uint8_t ret = I2C_Write(addr, data, len);
    rt_mutex_release(i2c_mutex);

    return ret;
}

uint8_t i2c1_read_safe(uint8_t addr, uint8_t *buf, uint8_t len)
{
    rt_mutex_take(i2c_mutex, RT_WAITING_FOREVER);
    uint8_t ret = I2C_Read(addr, buf, len);
    rt_mutex_release(i2c_mutex);

    return ret;
}