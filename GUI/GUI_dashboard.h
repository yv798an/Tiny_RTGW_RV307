/********************************** (C) COPYRIGHT *******************************
* File Name          : GUI_dashboard.c
* Author             : yvan
* Version            : V1.0.0
* Date               : 2026/06/10
* Description        : Head file for the GUI startup interface of this project
*******************************************************************************/
#ifndef GUI_DASHBOARD_H
#define GUI_DASHBOARD_H

#include "../lvgl/lvgl.h"
#include "lcd.h"
/* 初始化主页仪表盘 */
void GUI_dashboard_init(lv_obj_t *parent);

/* 更新传感器数据显示
 * temp  - 温度，单位 ℃
 * hum   - 湿度，单位 %
 * gas   - 空气质量数值
 * light - 光强，单位 Lux
 */
void GUI_dashboard_update(float temp, float hum, int gas, int light);

#endif /* GUI_DASHBOARD_H */