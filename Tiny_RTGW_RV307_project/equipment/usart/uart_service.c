#include <rtthread.h>
#include <rtdevice.h>
#include <string.h>

#include "uart_service.h"

#include "../sensor/sensor_service.h"
#include "../sensor/sensor_data.h"

#include "ch32v30x.h"

#define UART_NAME "uart2"

#define LED_PORT GPIOD
#define LED_PIN  GPIO_Pin_9

static rt_device_t uart_dev;

static void led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
    GPIO_InitStructure.GPIO_Pin =LED_PIN;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
    GPIO_ResetBits(LED_PORT,LED_PIN);

}

void uart_service_thread(void *parameter)
{

    sensor_data_t data;

    char tx_buf[64];
    char rx_buf[32];

    led_init();

    uart_dev =rt_device_find(UART_NAME);

    if(uart_dev == RT_NULL)
    {
        rt_kprintf("uart2 find failed\r\n");
        return;
    }

    rt_device_open(
        uart_dev,

        RT_DEVICE_FLAG_RDWR |
        RT_DEVICE_FLAG_INT_RX
    );

    rt_kprintf("UART2 service ready\r\n");

    uint32_t tick = 0;

    while(1)
    {

        rt_memset(
            rx_buf,
            0,
            sizeof(rx_buf)
        );

        int len =
        rt_device_read(
            uart_dev,
            0,
            rx_buf,
            sizeof(rx_buf)-1
        );

        if(len > 0)
        {

            if(strstr(rx_buf,"ON"))
            {
                GPIO_SetBits(LED_PORT,LED_PIN);
                sensor_set_led_state(1);
                rt_kprintf( "LED ON\r\n");
            }

            else if(strstr(rx_buf,"OFF"))
            {

                GPIO_ResetBits(LED_PORT,LED_PIN);
                sensor_set_led_state(0);
                rt_kprintf("LED OFF\r\n");
            }

            else
            {
                rt_kprintf("UART2 RX:%s\r\n",rx_buf);
            }
        }

        tick++;

        if(tick >= 50)
        {
            tick = 0;
            if(sensor_data_get(&data)==0)
            {
                rt_snprintf(
                    tx_buf,
                    sizeof(tx_buf),
                    "$%d,%d,%d,%d,%d#\r\n",
                    (int)data.temperature,
                    (int)data.humidity,
                    data.light_adc,
                    data.light_mv,
                    data.led_state
                );

                rt_device_write(
                    uart_dev,
                    0,
                    tx_buf,
                    rt_strlen(tx_buf)
                );
                rt_kprintf(
                    "TX:%s",
                    tx_buf
                );
            }

        }

        rt_thread_mdelay(20);

    }

}
