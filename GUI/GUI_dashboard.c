/********************************** (C) COPYRIGHT *******************************
* File Name          : GUI_dashboard.c
* Author             : yvan
* Version            : V1.0.0
* Date               : 2026/06/10
* Description        : Source file for the initial GUI interface of this project
*******************************************************************************/
#include "GUI_dashboard.h"
/* Label对象 */
static lv_obj_t *temp_label;
static lv_obj_t *hum_label;
static lv_obj_t *gas_label;
static lv_obj_t *light_label;

/**
 * @fn GUI_dashboard_init
 * @brief 初始化仪表盘界面。
 *
 * 该函数用于在指定的父级容器中创建并布局仪表盘界面。
 * 界面包含一个全屏背景容器，以及四个用于显示传感器数据的标签：
 * 温度、湿度、空气质量和光强。
 * 
 * @return none
 * @note 调用此函数前，请确保 LVGL 图形库已正确初始化，并且 LCD_W 和 LCD_H 宏已根据实际屏幕分辨率正确定义。
 */
void GUI_dashboard_init(lv_obj_t *parent)
{
    /* 背景容器 */
    lv_obj_t *cont = lv_obj_create(parent);
    lv_obj_set_size(cont, LCD_W, LCD_H);
    lv_obj_center(cont);

    /* 温度标签 */
    temp_label = lv_label_create(cont);
    lv_label_set_text(temp_label, "温度: --℃");
    lv_obj_align(temp_label, LV_ALIGN_TOP_LEFT, 10, 10);

    /* 湿度标签 */
    hum_label = lv_label_create(cont);
    lv_label_set_text(hum_label, "湿度: --%");
    lv_obj_align_to(hum_label, temp_label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);

    /* 空气质量标签 */
    gas_label = lv_label_create(cont);
    lv_label_set_text(gas_label, "空气质量: --");
    lv_obj_align_to(gas_label, hum_label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);

    /* 光强标签 */
    light_label = lv_label_create(cont);
    lv_label_set_text(light_label, "光强: -- Lux");
    lv_obj_align_to(light_label, gas_label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
}

/**
 * @fn GUI_dashboard_update
 * @brief 数据更新
 *
 * @return none
 */
void GUI_dashboard_update(float temp, float hum, int gas, int light)
{
    static char buf[32];

    sprintf(buf, "温度: %.1f℃", temp);
    lv_label_set_text(temp_label, buf);

    sprintf(buf, "湿度: %.1f%%", hum);
    lv_label_set_text(hum_label, buf);

    sprintf(buf, "空气质量: %d", gas);
    lv_label_set_text(gas_label, buf);

    sprintf(buf, "光强: %d Lux", light);
    lv_label_set_text(light_label, buf);
}