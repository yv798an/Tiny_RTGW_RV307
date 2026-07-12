#ifndef __GUI_DASHBOARD_H
#define __GUI_DASHBOARD_H


#include "lvgl.h"


#undef LCD_W
#undef LCD_H
#define LCD_W 320
#define LCD_H 240


void GUI_dashboard_init(lv_obj_t *parent);


void GUI_dashboard_update(
        float temperature,
        float humidity,
        uint16_t light_adc,
        uint32_t light_mv,
        uint8_t led_state
);



#endif