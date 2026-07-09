/********************************** (C) COPYRIGHT *******************************
* File Name          : pin.h
* Author             : yvan
* Version            : V1.0.0
* Date               : 2026/06/10
* Description        : This is the configuration file for all pins in this project
*******************************************************************************/
#define SPI_PORT         GPIOB
#define SPI_SCLK_PIN     GPIO_Pin_3
#define SPI_MOSI_PIN     GPIO_Pin_5

#define ST7796S_CS_PORT   GPIOE 
#define ST7796S_CS_PIN    GPIO_Pin_6

#define ST7796S_DC_PORT   GPIOE
#define ST7796S_DC_PIN    GPIO_Pin_4

#define ST7796S_BL_PORT   GPIOE
#define ST7796S_BL_PIN    GPIO_Pin_3
#define ST7796S_BL_Ctrl(n)  GPIO_WriteBit(ST7796S_BL_PORT, ST7796S_BL_PIN, (BitAction)(n))


