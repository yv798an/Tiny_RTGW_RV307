#include "sensor_buffer.h"
#include <rtthread.h>
#include <string.h>

static sensor_data_t g_data;
static rt_mutex_t data_mutex;

void sensor_buffer_init(void)
{
    memset(&g_data, 0, sizeof(g_data));
    data_mutex = rt_mutex_create("sensor", RT_IPC_FLAG_FIFO);
}

void sensor_buffer_write(sensor_data_t *data)
{
    rt_mutex_take(data_mutex, RT_WAITING_FOREVER);
    memcpy(&g_data, data, sizeof(sensor_data_t));
    rt_mutex_release(data_mutex);
}

void sensor_buffer_read(sensor_data_t *out)
{
    rt_mutex_take(data_mutex, RT_WAITING_FOREVER);
    memcpy(out, &g_data, sizeof(sensor_data_t));
    rt_mutex_release(data_mutex);
}