#include <rtthread.h>

#include "ulog.h"

#include "GUI_init.h"

#include "sensor_data.h"
#include "sensor_service.h"

#include "uart2.h"

int main(void)
{
    rt_thread_t sensor_tid;
    rt_thread_t uart_tid;

    ulog_init();

    sensor_data_init();

    GUI_INIT();

    sensor_tid = rt_thread_create(
        "sensor",
        sensor_service_thread,
        RT_NULL,
        2048,
        12,
        10
    );

    if(sensor_tid != RT_NULL)
    {
        rt_thread_startup(sensor_tid);
    }
    else
    {
        rt_kprintf("SENSOR THREAD CREATE FAILED\r\n");
    }

    uart_tid = rt_thread_create(
        "uart2",
        uart_service_thread,
        RT_NULL,
        2048,
        13,
        10
    );

    if(uart_tid != RT_NULL)
    {
        rt_thread_startup(uart_tid);
    }
    else
    {
        rt_kprintf("UART2 THREAD CREATE FAILED\r\n");
    }

    while(1)
    {
        rt_thread_mdelay(1000);
    }
}
