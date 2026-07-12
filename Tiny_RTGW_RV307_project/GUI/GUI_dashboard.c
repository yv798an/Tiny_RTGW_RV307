#include "GUI_dashboard.h"
#include <stdio.h>

#define CARD_W      150
#define CARD_H      84
#define RIGHT_CARD_W 150
#define RIGHT_CARD_H 56
#define ARC_SIZE    58
#define LEFT_X      6
#define RIGHT_X     162
#define CONTENT_Y   38
#define GAP_Y       4

static lv_obj_t *temp_arc;
static lv_obj_t *temp_label;
static lv_obj_t *hum_arc;
static lv_obj_t *hum_label;
static lv_obj_t *adc_label;
static lv_obj_t *voltage_label;
static lv_obj_t *led_widget;
static lv_obj_t *led_label;

static lv_style_t style_card;
static lv_style_t style_section;

static void card_style_init(void)
{
    lv_style_init(&style_card);
    lv_style_set_bg_color(&style_card, lv_color_hex(0x1A1A2E));
    lv_style_set_bg_opa(&style_card, LV_OPA_COVER);
    lv_style_set_radius(&style_card, 10);
    lv_style_set_pad_all(&style_card, 4);
    lv_style_set_border_width(&style_card, 0);

    lv_style_init(&style_section);
    lv_style_set_bg_color(&style_section, lv_color_hex(0x1A1A2E));
    lv_style_set_bg_opa(&style_section, LV_OPA_COVER);
    lv_style_set_radius(&style_section, 8);
    lv_style_set_pad_all(&style_section, 6);
    lv_style_set_border_width(&style_section, 0);
}

void GUI_dashboard_init(lv_obj_t *parent)
{
    card_style_init();

    /* full-screen dark background */
    lv_obj_t *bg = lv_obj_create(parent);
    lv_obj_set_size(bg, LCD_W, LCD_H);
    lv_obj_set_pos(bg, 0, 0);
    lv_obj_set_style_bg_color(bg, lv_color_hex(0x0F0F23), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bg, LV_OPA_COVER, LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bg, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(bg, 0, LV_STATE_DEFAULT);

    /* title bar */
    lv_obj_t *title_bar = lv_obj_create(bg);
    lv_obj_set_size(title_bar, LCD_W, 32);
    lv_obj_set_pos(title_bar, 0, 0);
    lv_obj_set_style_bg_color(title_bar, lv_color_hex(0x16213E), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(title_bar, LV_OPA_COVER, LV_STATE_DEFAULT);
    lv_obj_set_style_radius(title_bar, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(title_bar, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(title_bar, 0, LV_STATE_DEFAULT);

    lv_obj_t *title_label = lv_label_create(title_bar);
    lv_label_set_text(title_label, "SMART GATEWAY");
    lv_obj_set_style_text_color(title_label, lv_color_hex(0xFFFFFF), LV_STATE_DEFAULT);
    lv_obj_center(title_label);

    /* ---- LEFT COLUMN ---- */

    /* temperature card */
    lv_obj_t *card_temp = lv_obj_create(bg);
    lv_obj_set_size(card_temp, CARD_W, CARD_H);
    lv_obj_set_pos(card_temp, LEFT_X, CONTENT_Y);
    lv_obj_add_style(card_temp, &style_card, LV_STATE_DEFAULT);

    lv_obj_t *card_temp_title = lv_label_create(card_temp);
    lv_label_set_text(card_temp_title, "TEMPERATURE");
    lv_obj_set_style_text_color(card_temp_title, lv_color_hex(0x8888AA), LV_STATE_DEFAULT);
    lv_obj_align(card_temp_title, LV_ALIGN_TOP_MID, 0, 0);

    temp_arc = lv_arc_create(card_temp);
    lv_obj_set_size(temp_arc, ARC_SIZE, ARC_SIZE);
    lv_obj_align_to(temp_arc, card_temp_title, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);
    lv_arc_set_range(temp_arc, -20, 60);
    lv_arc_set_value(temp_arc, 0);
    lv_arc_set_bg_angles(temp_arc, 0, 270);
    lv_arc_set_rotation(temp_arc, 135);
    lv_obj_set_style_arc_color(temp_arc, lv_color_hex(0xFF6B35), LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(temp_arc, 4, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(temp_arc, lv_color_hex(0x2A2A4A), LV_PART_MAIN);
    lv_obj_set_style_arc_width(temp_arc, 4, LV_PART_MAIN);
    lv_obj_set_style_arc_width(temp_arc, 0, LV_PART_KNOB);

    temp_label = lv_label_create(card_temp);
    lv_label_set_text(temp_label, "-- C");
    lv_obj_set_style_text_color(temp_label, lv_color_hex(0xFFFFFF), LV_STATE_DEFAULT);
    lv_obj_align_to(temp_label, temp_arc, LV_ALIGN_CENTER, 0, 8);

    /* humidity card */
    lv_obj_t *card_hum = lv_obj_create(bg);
    lv_obj_set_size(card_hum, CARD_W, CARD_H);
    lv_obj_set_pos(card_hum, LEFT_X, CONTENT_Y + CARD_H + GAP_Y);
    lv_obj_add_style(card_hum, &style_card, LV_STATE_DEFAULT);

    lv_obj_t *card_hum_title = lv_label_create(card_hum);
    lv_label_set_text(card_hum_title, "HUMIDITY");
    lv_obj_set_style_text_color(card_hum_title, lv_color_hex(0x8888AA), LV_STATE_DEFAULT);
    lv_obj_align(card_hum_title, LV_ALIGN_TOP_MID, 0, 0);

    hum_arc = lv_arc_create(card_hum);
    lv_obj_set_size(hum_arc, ARC_SIZE, ARC_SIZE);
    lv_obj_align_to(hum_arc, card_hum_title, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);
    lv_arc_set_range(hum_arc, 0, 100);
    lv_arc_set_value(hum_arc, 0);
    lv_arc_set_bg_angles(hum_arc, 0, 270);
    lv_arc_set_rotation(hum_arc, 135);
    lv_obj_set_style_arc_color(hum_arc, lv_color_hex(0x00D4FF), LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(hum_arc, 4, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(hum_arc, lv_color_hex(0x2A2A4A), LV_PART_MAIN);
    lv_obj_set_style_arc_width(hum_arc, 4, LV_PART_MAIN);
    lv_obj_set_style_arc_width(hum_arc, 0, LV_PART_KNOB);

    hum_label = lv_label_create(card_hum);
    lv_label_set_text(hum_label, "-- %%");
    lv_obj_set_style_text_color(hum_label, lv_color_hex(0xFFFFFF), LV_STATE_DEFAULT);
    lv_obj_align_to(hum_label, hum_arc, LV_ALIGN_CENTER, 0, 8);

    /* ---- RIGHT COLUMN ---- */

    /* light ADC card */
    lv_obj_t *card_adc = lv_obj_create(bg);
    lv_obj_set_size(card_adc, RIGHT_CARD_W, RIGHT_CARD_H);
    lv_obj_set_pos(card_adc, RIGHT_X, CONTENT_Y);
    lv_obj_add_style(card_adc, &style_section, LV_STATE_DEFAULT);

    lv_obj_t *adc_title = lv_label_create(card_adc);
    lv_label_set_text(adc_title, "LIGHT ADC");
    lv_obj_set_style_text_color(adc_title, lv_color_hex(0x8888AA), LV_STATE_DEFAULT);
    lv_obj_align(adc_title, LV_ALIGN_TOP_LEFT, 0, 2);

    adc_label = lv_label_create(card_adc);
    lv_label_set_text(adc_label, "--");
    lv_obj_set_style_text_color(adc_label, lv_color_hex(0xFFD700), LV_STATE_DEFAULT);
    lv_obj_align(adc_label, LV_ALIGN_BOTTOM_LEFT, 0, -2);

    /* light voltage card */
    lv_obj_t *card_volt = lv_obj_create(bg);
    lv_obj_set_size(card_volt, RIGHT_CARD_W, RIGHT_CARD_H);
    lv_obj_set_pos(card_volt, RIGHT_X, CONTENT_Y + RIGHT_CARD_H + GAP_Y);
    lv_obj_add_style(card_volt, &style_section, LV_STATE_DEFAULT);

    lv_obj_t *volt_title = lv_label_create(card_volt);
    lv_label_set_text(volt_title, "LIGHT VOLTAGE");
    lv_obj_set_style_text_color(volt_title, lv_color_hex(0x8888AA), LV_STATE_DEFAULT);
    lv_obj_align(volt_title, LV_ALIGN_TOP_LEFT, 0, 2);

    voltage_label = lv_label_create(card_volt);
    lv_label_set_text(voltage_label, "-- mV");
    lv_obj_set_style_text_color(voltage_label, lv_color_hex(0xFFD700), LV_STATE_DEFAULT);
    lv_obj_align(voltage_label, LV_ALIGN_BOTTOM_LEFT, 0, -2);

    /* LED card */
    lv_obj_t *card_led = lv_obj_create(bg);
    lv_obj_set_size(card_led, RIGHT_CARD_W, RIGHT_CARD_H);
    lv_obj_set_pos(card_led, RIGHT_X, CONTENT_Y + (RIGHT_CARD_H + GAP_Y) * 2);
    lv_obj_add_style(card_led, &style_section, LV_STATE_DEFAULT);

    lv_obj_t *led_card_title = lv_label_create(card_led);
    lv_label_set_text(led_card_title, "LED STATUS");
    lv_obj_set_style_text_color(led_card_title, lv_color_hex(0x8888AA), LV_STATE_DEFAULT);
    lv_obj_align(led_card_title, LV_ALIGN_TOP_LEFT, 0, 2);

    led_widget = lv_led_create(card_led);
    lv_obj_set_size(led_widget, 16, 16);
    lv_obj_align(led_widget, LV_ALIGN_LEFT_MID, 6, 2);
    lv_led_set_color(led_widget, lv_color_hex(0x00FF00));
    lv_led_off(led_widget);

    led_label = lv_label_create(card_led);
    lv_label_set_text(led_label, "OFF");
    lv_obj_set_style_text_color(led_label, lv_color_hex(0xAAAAAA), LV_STATE_DEFAULT);
    lv_obj_align_to(led_label, led_widget, LV_ALIGN_OUT_RIGHT_MID, 8, 0);

    /* bottom status bar */
    lv_obj_t *status_bar = lv_obj_create(bg);
    lv_obj_set_size(status_bar, LCD_W, 18);
    lv_obj_set_pos(status_bar, 0, LCD_H - 18);
    lv_obj_set_style_bg_color(status_bar, lv_color_hex(0x16213E), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(status_bar, LV_OPA_COVER, LV_STATE_DEFAULT);
    lv_obj_set_style_radius(status_bar, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(status_bar, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(status_bar, 0, LV_STATE_DEFAULT);

    lv_obj_t *status_label = lv_label_create(status_bar);
    lv_label_set_text(status_label, "RT-Thread | LVGL v8.3 | CH32V307");
    lv_obj_set_style_text_color(status_label, lv_color_hex(0x666688), LV_STATE_DEFAULT);
    lv_obj_center(status_label);
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

    if (temp_arc != NULL) {
        int t = (int)temperature;
        if (t < -20) t = -20;
        if (t > 60)  t = 60;
        lv_arc_set_value(temp_arc, t);
    }
    if (temp_label != NULL) {
        sprintf(buf, "%d C", (int)temperature);
        lv_label_set_text(temp_label, buf);
    }

    if (hum_arc != NULL) {
        int h = (int)humidity;
        if (h < 0)   h = 0;
        if (h > 100) h = 100;
        lv_arc_set_value(hum_arc, h);
    }
    if (hum_label != NULL) {
        sprintf(buf, "%d %%", (int)humidity);
        lv_label_set_text(hum_label, buf);
    }

    if (adc_label != NULL) {
        sprintf(buf, "%d", light_adc);
        lv_label_set_text(adc_label, buf);
    }

    if (voltage_label != NULL) {
        sprintf(buf, "%d mV", (int)light_mv);
        lv_label_set_text(voltage_label, buf);
    }

    if (led_widget != NULL) {
        if (led_state) {
            lv_led_on(led_widget);
        } else {
            lv_led_off(led_widget);
        }
    }
    if (led_label != NULL) {
        lv_label_set_text(led_label, led_state ? "ON" : "OFF");
        lv_obj_set_style_text_color(led_label,
            led_state ? lv_color_hex(0x00FF00) : lv_color_hex(0xAAAAAA),
            LV_STATE_DEFAULT);
    }
}