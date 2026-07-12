/********************************** (C) COPYRIGHT *******************************
* File Name          : sensor_data.c
* Description        : 优化后的安全传感器数据中心（引入邮箱异步推流）
*******************************************************************************/

#include "sensor_data.h"
#include "rtthread.h"
#include "string.h"

/* 引入 GUI_init 中定义的全局邮箱句柄，用于向 UI 线程安全投递数据指针 */
extern struct rt_mailbox gui_mb;

sensor_data_t g_sensor_data = {0};
struct rt_mutex g_sensor_mutex;

/**
 * @brief 传感器数据中心初始化
 */
void sensor_data_init(void)
{
    rt_mutex_init(&g_sensor_mutex, "sens_mtx", RT_IPC_FLAG_FIFO);
}

/**
 * @brief 传感器数据上锁（内部保留）
 */
void sensor_data_lock(void)
{
    rt_mutex_take(&g_sensor_mutex, RT_WAITING_FOREVER);
}

/**
 * @brief 传感器数据解锁（内部保留）
 */
void sensor_data_unlock(void)
{
    rt_mutex_release(&g_sensor_mutex);
}

/**
 * @brief 更新传感器全局数据（由你的传感器采集线程/中端/驱动调用）
 * @param data 指向新采集到的传感器数据结构体
 */
void sensor_data_update(sensor_data_t *data)
{
    if(data == RT_NULL)
        return;

    /* 1. 正常的互斥锁拷贝，保护全局变量 g_sensor_data */
    sensor_data_lock();
    memcpy(&g_sensor_data, data, sizeof(sensor_data_t));
    sensor_data_unlock();

    /* 2. 【核心新增】当数据中心更新后，立刻将全局数据的地址通过邮箱“推”给 LVGL 线程
     * 使用 RT_WAITING_NO (0) 代表非阻塞发送。
     * 就算 LVGL 线程因为刷图太忙没来得及收，这里也绝不卡死，直接覆盖，极其安全。
     */
    rt_mb_send_wait(&gui_mb, (rt_ubase_t)&g_sensor_data, 0);
}

/**
 * @brief 获取当前最新的传感器数据（保留此接口供 UI 以外的其他普通线程调用）
 * @param data 接收数据的结构体指针
 * @return int 0:成功, -1:空指针
 */
int sensor_data_get(sensor_data_t *data)
{
    if(data == RT_NULL)
        return -1;

    /* 注意：修改后的新 GUI 架构中，LVGL 线程已经不再调用此函数，彻底规避了死锁 */
    sensor_data_lock();
    memcpy(data, &g_sensor_data, sizeof(sensor_data_t));
    sensor_data_unlock();

    return 0;
}
