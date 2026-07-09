#include "rtthread.h"
#include "bsp_i2c1.h"


void I2C_Scan(void)
{
    uint8_t addr;


    rt_kprintf("I2C Scan Start...\n");


    for(addr = 1; addr < 127; addr++)
    {

        /*
         * 发送地址，不发送数据
         */

        if(I2C_Write(addr, RT_NULL, 0) == 0)
        {
            rt_kprintf(
                "Found device: 0x%02X\n",
                addr
            );
        }

    }


    rt_kprintf("I2C Scan Done\n");
}