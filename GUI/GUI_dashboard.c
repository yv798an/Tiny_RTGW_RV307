#include "GUI_dashboard.h"
#include <stdio.h>


static lv_obj_t *temp_label;
static lv_obj_t *hum_label;
static lv_obj_t *adc_label;
static lv_obj_t *voltage_label;
static lv_obj_t *led_label;


void GUI_dashboard_init(lv_obj_t *parent)
{


    lv_obj_t *cont;

    cont = lv_obj_create(parent);
    lv_obj_set_size(cont,LCD_W,LCD_H);
    lv_obj_center(cont);

    temp_label = lv_label_create(cont);


    lv_label_set_text(temp_label,"Temperature: --");

    lv_obj_align(temp_label,LV_ALIGN_TOP_LEFT,10,10);
    hum_label = lv_label_create(cont);

    lv_label_set_text(hum_label,"Humidity: --");

    lv_obj_align_to(hum_label,temp_label,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);

    adc_label = lv_label_create(cont);

    lv_label_set_text(adc_label,"Light ADC: --");

    lv_obj_align_to(adc_label,hum_label,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);

    voltage_label = lv_label_create(cont);


    lv_label_set_text(voltage_label,"Light Voltage: --");
    lv_obj_align_to(voltage_label,adc_label,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);

    led_label = lv_label_create(cont);

    lv_label_set_text(led_label,"LED: OFF");

    lv_obj_align_to(led_label,voltage_label,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);

}




void GUI_dashboard_update(
        float temperature,
        float humidity,
        uint16_t light_adc,
        uint32_t light_mv,
        uint8_t led_state
)
{

    char buf[64];

    if(temp_label != NULL)
    {
        sprintf(buf,"Temperature: %d C",(int)temperature);
        lv_label_set_text(temp_label,buf);
    }

    if(hum_label != NULL)
    {
        sprintf(buf,"Humidity: %d %% ", (int)humidity);
        lv_label_set_text(hum_label,buf);
    }

    if(adc_label != NULL)
    {

        sprintf(buf,"Light ADC: %d",light_adc);
        lv_label_set_text(adc_label,buf);
    }

    if(voltage_label != NULL)
    {

        sprintf(buf,"Light Voltage: %d mV",light_mv);
        lv_label_set_text(voltage_label,buf);
    }
    if(led_label != NULL)
    {

        if(led_state)
        {
            lv_label_set_text(
                led_label,
                "LED: ON"
            );
        }
        else
        {
            lv_label_set_text(
                led_label,
                "LED: OFF"
            );
        }
    }

}