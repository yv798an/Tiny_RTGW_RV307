#include "sensor_data.h"
#include "rtthread.h"
#include "string.h"

extern struct rt_mailbox gui_mb;

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

void sensor_data_updata(sensor_data_t *data)
{
    if(data == RT_NULL)
    {
        return;
    }

    sensor_data_lock();
    memcpy(&g_sensor_data, data, sizeof(sensor_data_t));
    sensor_data_unlock();

    rt_mb_send_wait(&gui_mb, (rt_ubase_t)&g_sensor_data, 0);

}

int sensor_data_get(sensor_data_t *data)
{
    if(data == RT_NULL)
    {
        return -1;
    }

    sensor_data_lock();
    memcpy(data, &g_sensor_data, sizeof(sensor_data_t));
    sensor_data_unlock();

    return 0;
}