/********************************** (C) COPYRIGHT *******************************
* File Name          : GUI_init.c
* Author             : yvan
* Version            : V1.0.0
* Date               : 2026/06/10
* Description        : The executable files for all GUI functions called in this project
*******************************************************************************/

#include "GUI_init.h"
#include "lv_port_disp.h"
#include <rtthread.h>

static void lvgl_handler_thread(void *parameter)
{
    while (1)
    {
        lv_timer_handler();
        rt_thread_mdelay(5);
    }
}

void GUI_INIT(void)
{
    lcd_init();

    lv_init();
    lv_port_disp_init();

    lv_obj_t *scr = lv_scr_act();

    GUI_dashboard_init(scr);

    /*
    GUI_monitor_init(scr);
    GUI_chart_init(scr);
    GUI_control_init(scr);
    GUI_setting_init(scr);
    */

    rt_thread_t lvgl_tid = rt_thread_create(
        "lvgl",
        lvgl_handler_thread,
        RT_NULL,
        2048,
        4,
        10
    );
    if (lvgl_tid) rt_thread_startup(lvgl_tid);
}