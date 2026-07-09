#include "sensor_data.h"
#include "rtthread.h"
sensor_data_t g_sensor_data = {0};
struct rt_mutex g_sensor_mutex;

void sensor_data_init(void)
{
    rt_mutex_init(&g_sensor_mutex, "sens_mtx", RT_IPC_FLAG_FIFO);
}

void sensor_data_lock(void)
{
    rt_mutex_take(&g_sensor_mutex, RT_WAITING_FOREVER);
}

void sensor_data_unlock(void)
{
    rt_mutex_release(&g_sensor_mutex);
}
