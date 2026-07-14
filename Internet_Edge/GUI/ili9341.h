#ifndef __ILI9341_H
#define __ILI9341_H


#include "ch32v30x.h"
#include "lvgl.h"

#define ILI9341_BL_PORT GPIOE
#define ILI9341_BL_PIN  GPIO_Pin_3

#define ILI9341_BL_Ctrl(n) \
GPIO_WriteBit(ILI9341_BL_PORT,\
ILI9341_BL_PIN,\
(BitAction)(n))

#define ILI9341_CS_PORT GPIOE
#define ILI9341_CS_PIN  GPIO_Pin_6

#define ILI9341_DC_PORT GPIOE
#define ILI9341_DC_PIN  GPIO_Pin_4

#define SPI_PORT GPIOB
#define SPI_SCLK_PIN GPIO_Pin_3
#define SPI_MOSI_PIN GPIO_Pin_5

#define LCD_WIDTH  320
#define LCD_HEIGHT 240

void ILI9341_Init(void);

void ILI9341_Set_Address(
        uint16_t x1,
        uint16_t y1,
        uint16_t x2,
        uint16_t y2
);

void ILI9341_Write_LVGL_Buffer(
        lv_color_t *color_p,
        uint32_t size
);

#endif