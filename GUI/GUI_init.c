#include "GUI_init.h"
#include "lv_port_disp.h"
#include "ili9341.h"
#include "GUI_dashboard.h"
#include "../equipment/sensor/sensor_data.h"
#include <rtthread.h>
#include "lvgl.h"


static struct rt_mutex lvgl_mutex;

struct rt_mailbox gui_mb;
static char mb_pool[128];


static void lvgl_handler_thread(void *parameter)
{
    sensor_data_t *p_data;

    while(1)
    {
        if (rt_mb_recv(&gui_mb, (rt_ubase_t *)&p_data, 5) == RT_EOK)
        {
            if (rt_mutex_take(&lvgl_mutex, RT_WAITING_FOREVER) == RT_EOK)
            {
                GUI_dashboard_update(
                    p_data->temperature,
                    p_data->humidity,
                    p_data->light_adc,
                    p_data->light_mv,
                    p_data->led_state
                );
                rt_mutex_release(&lvgl_mutex);
            }
        }

        if (rt_mutex_take(&lvgl_mutex, RT_WAITING_FOREVER) == RT_EOK)
        {
            lv_timer_handler();
            rt_mutex_release(&lvgl_mutex);
        }
        
        rt_thread_mdelay(20);
    }
}


void GUI_INIT(void)
{
    rt_kprintf("\r\n===== GUI INIT START =====\r\n");
    

    ILI9341_Init();
    rt_kprintf("ILI9341 INIT OK\r\n");


    lv_init();
    lv_port_disp_init();
    rt_kprintf("LVGL DISPLAY INIT OK\r\n");


    rt_mutex_init(&lvgl_mutex, "lv_mutex", RT_IPC_FLAG_FIFO);


    rt_mb_init(&gui_mb, "gui_mb", mb_pool, sizeof(mb_pool) / 4, RT_IPC_FLAG_FIFO);

    GUI_dashboard_init(lv_scr_act());
    rt_kprintf("GUI DASHBOARD INIT OK\r\n");


    rt_thread_t lvgl_tid;
    lvgl_tid = rt_thread_create(
        "lvgl",                 
        lvgl_handler_thread,   
        RT_NULL,                
        8192,                   
        4,                      
        10                    
    );

    if(lvgl_tid != RT_NULL)
    {
        rt_thread_startup(lvgl_tid);
    }
    else
    {
        rt_kprintf("LVGL THREAD CREATE FAILED\r\n");
    }

    rt_kprintf("===== GUI INIT DONE =====\r\n");
}
