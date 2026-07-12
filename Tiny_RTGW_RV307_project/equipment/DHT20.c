#include "DHT20.h"
#include "I2C/bsp_i2c1.h"
#include "rtthread.h"


#define DHT20_ADDR 0x38


uint8_t DHT20_Init(void)
{
    rt_thread_mdelay(100);
    return 0;
}




uint8_t DHT20_Read(
        float *temperature,
        float *humidity
)
{

    uint8_t cmd[3];
    uint8_t data[6];
    uint32_t hum;
    uint32_t temp;

    cmd[0]=0xAC;
    cmd[1]=0x33;
    cmd[2]=0x00;

    if(I2C_Write(DHT20_ADDR,cmd,3))
    {
        rt_kprintf("DHT20 write failed\n");
        return 1;
    }

    rt_thread_mdelay(100);

    if(I2C_Read(DHT20_ADDR,data,6))
    {
        rt_kprintf("DHT20 read failed\n");
        return 2;
    }



    if(data[0]&0x80)
    {
        rt_kprintf("DHT20 busy\n");
        return 3;
    }


    hum =
        ((uint32_t)data[1]<<12) |
        ((uint32_t)data[2]<<4) |
        ((uint32_t)data[3]>>4);

    temp =
        (((uint32_t)data[3]&0x0F)<<16) |
        ((uint32_t)data[4]<<8) |
        data[5];


    *humidity =hum*100.0f/1048576.0f;
    *temperature =temp*200.0f/1048576.0f-50;
    return 0;

}