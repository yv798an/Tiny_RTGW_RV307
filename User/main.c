#include <rtthread.h>
#include <rtdevice.h>
#include "../equipment/sensor/sensor_data.h"
#include "GUI_init.h"
/*
 * sensor线程入口
 */
extern void sensor_service_thread(void *parameter);
/*
 * uart发送线程入口
 */
extern void uart_service_thread(void *parameter);


int main(void)
{

    rt_thread_t sensor_tid;
    rt_thread_t uart_tid;

    rt_kprintf("\n");
    rt_kprintf("====================\n");
    rt_kprintf("Smart Gateway Start\n");
    rt_kprintf("====================\n");

    sensor_data_init();

    /*
     * 创建传感器采集线程
     *
     * 功能：
     * DHT20读取
     * ADC读取
     * 更新sensor_data
     *
     */
    sensor_tid = rt_thread_create(
            "sensor",
            sensor_service_thread,
            RT_NULL,
            2048,       // 栈大小
            10,         // 优先级
            10          // 时间片
    );

    if(sensor_tid != RT_NULL)
    {
        rt_thread_startup(sensor_tid);
    }
    else
    {
        rt_kprintf(
            "sensor thread create failed!\r\n"
        );

    }

    /*
     * 创建UART发送线程
     *
     * 功能：
     * 从sensor_service获取数据
     * 通过UART2发送给ESP32-C6
     *
     */
    uart_tid = rt_thread_create(
            "uart_tx",
            uart_service_thread,
            RT_NULL,
            2048,
            12,
            10
    );

    if(uart_tid != RT_NULL)
    {
        rt_thread_startup(uart_tid);
    }
    else
    {
        rt_kprintf(
            "uart thread create failed!\r\n"
        );
    }

    GUI_INIT();

    return 0;
}