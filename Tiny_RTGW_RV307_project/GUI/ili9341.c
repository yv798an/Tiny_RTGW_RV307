#include "ili9341.h"
#include "ch32v30x.h"
#include "lvgl.h"


#define LCD_BL_PORT GPIOE
#define LCD_BL_PIN  GPIO_Pin_3


#define LCD_DC_PORT GPIOE
#define LCD_DC_PIN  GPIO_Pin_4


#define LCD_CS_PORT GPIOE
#define LCD_CS_PIN  GPIO_Pin_6

#define LCD_SCK_PORT GPIOB
#define LCD_SCK_PIN  GPIO_Pin_3

#define LCD_MOSI_PORT GPIOB
#define LCD_MOSI_PIN  GPIO_Pin_5

#define CS_LOW()      GPIO_ResetBits(LCD_CS_PORT,LCD_CS_PIN)
#define CS_HIGH()     GPIO_SetBits(LCD_CS_PORT,LCD_CS_PIN)


#define DC_LOW()      GPIO_ResetBits(LCD_DC_PORT,LCD_DC_PIN)
#define DC_HIGH()     GPIO_SetBits(LCD_DC_PORT,LCD_DC_PIN)



#define SCK_LOW()     GPIO_ResetBits(LCD_SCK_PORT,LCD_SCK_PIN)
#define SCK_HIGH()    GPIO_SetBits(LCD_SCK_PORT,LCD_SCK_PIN)


#define MOSI_LOW()    GPIO_ResetBits(LCD_MOSI_PORT,LCD_MOSI_PIN)
#define MOSI_HIGH()   GPIO_SetBits(LCD_MOSI_PORT,LCD_MOSI_PIN)



static void delay_us(uint32_t us)
{
    while(us--)
    {
        __NOP();
        __NOP();
        __NOP();
        __NOP();
    }
}



static void SPI_WriteByte(uint8_t data)
{

    uint8_t i;


    for(i=0;i<8;i++)
    {
        SCK_LOW();

        if(data & 0x80)
            MOSI_HIGH();
        else
            MOSI_LOW();

        data <<=1;
        delay_us(5);
        SCK_HIGH();
        delay_us(5);
    }
    SCK_LOW();
}


static void LCD_Write_Cmd(uint8_t cmd)
{

    CS_LOW();
    DC_LOW();
    SPI_WriteByte(cmd);
    CS_HIGH();

}


static void LCD_Write_Data(uint8_t data)
{

    CS_LOW();
    DC_HIGH();
    SPI_WriteByte(data);
    CS_HIGH();

}



static void LCD_Write_Data16(uint16_t data)
{
    LCD_Write_Data(data>>8);
    LCD_Write_Data(data&0xff);
}


static void LCD_GPIO_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOE,ENABLE);
    GPIO_InitStructure.GPIO_Pin =LCD_SCK_PIN |LCD_MOSI_PIN;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(LCD_SCK_PORT,&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin =LCD_CS_PIN |LCD_DC_PIN |LCD_BL_PIN;
    GPIO_Init(LCD_DC_PORT,&GPIO_InitStructure);

    CS_HIGH();
    DC_HIGH();
    GPIO_SetBits(LCD_BL_PORT,LCD_BL_PIN);
}



static void LCD_Reset(void)
{
    delay_us(100000);
}


void ILI9341_Init(void)
{


    LCD_GPIO_Init();
    LCD_Reset();
    LCD_Write_Cmd(0x01);
    delay_us(120000);
    LCD_Write_Cmd(0xCF);
    LCD_Write_Data(0x00);
    LCD_Write_Data(0xC1);
    LCD_Write_Data(0x30);
    LCD_Write_Cmd(0xED);
    LCD_Write_Data(0x64);
    LCD_Write_Data(0x03);
    LCD_Write_Data(0x12);
    LCD_Write_Data(0x81);
    LCD_Write_Cmd(0xE8);
    LCD_Write_Data(0x85);
    LCD_Write_Data(0x00);
    LCD_Write_Data(0x78);
    LCD_Write_Cmd(0xCB);
    LCD_Write_Data(0x39);
    LCD_Write_Data(0x2C);
    LCD_Write_Data(0x00);
    LCD_Write_Data(0x34);
    LCD_Write_Data(0x02);
    LCD_Write_Cmd(0xF7);
    LCD_Write_Data(0x20);
    LCD_Write_Cmd(0xEA);
    LCD_Write_Data(0x00);
    LCD_Write_Data(0x00);
    LCD_Write_Cmd(0xC0);
    LCD_Write_Data(0x23);
    LCD_Write_Cmd(0xC1);
    LCD_Write_Data(0x10);
    LCD_Write_Cmd(0xC5);
    LCD_Write_Data(0x3e);
    LCD_Write_Data(0x28);
    LCD_Write_Cmd(0xC7);
    LCD_Write_Data(0x86);
    LCD_Write_Cmd(0x3A);
    LCD_Write_Data(0x55);
    LCD_Write_Cmd(0x36);
    LCD_Write_Data(0x40);
    LCD_Write_Cmd(0x11);
    delay_us(120000);
    LCD_Write_Cmd(0x29);

}


void ILI9341_Set_Address(
        uint16_t x1,
        uint16_t y1,
        uint16_t x2,
        uint16_t y2)
{

    LCD_Write_Cmd(0x2A);
    LCD_Write_Data16(x1);
    LCD_Write_Data16(x2);
    LCD_Write_Cmd(0x2B);
    LCD_Write_Data16(y1);
    LCD_Write_Data16(y2);
    LCD_Write_Cmd(0x2C);

}


void ILI9341_Write_LVGL_Buffer(lv_color_t *color_p, uint32_t size)
{
    uint32_t i;
    uint16_t raw_color;

    CS_LOW();
    DC_HIGH();
    
    for(i = 0; i < size; i++)
    {

        raw_color = lv_color_to16(color_p[i]);


        SPI_WriteByte((uint8_t)(raw_color >> 8));

        SPI_WriteByte((uint8_t)(raw_color & 0xFF));
    }
    
    CS_HIGH();
}
