#include "lcd.h"
#include "ch32v30x.h"

static void SPI3_Write(uint8_t data)
{
    SPI_I2S_SendData(SPI3, data);
    while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE) == RESET);
}

static void SPI3_Write16(uint16_t data)
{
    SPI3_Write(data >> 8);
    SPI3_Write(data & 0xFF);
}

static void LCD_WR_REG(uint8_t cmd)
{
    GPIO_ResetBits(GPIOE, GPIO_Pin_6);
    GPIO_ResetBits(GPIOE, GPIO_Pin_4);
    SPI3_Write(cmd);
    GPIO_SetBits(GPIOE, GPIO_Pin_6);
}

static void LCD_WR_DATA(uint8_t data)
{
    GPIO_ResetBits(GPIOE, GPIO_Pin_6);
    GPIO_SetBits(GPIOE, GPIO_Pin_4);
    SPI3_Write(data);
    GPIO_SetBits(GPIOE, GPIO_Pin_6);
}

static void LCD_WR_DATA16(uint16_t data)
{
    GPIO_ResetBits(GPIOE, GPIO_Pin_6);
    GPIO_SetBits(GPIOE, GPIO_Pin_4);
    SPI3_Write16(data);
    GPIO_SetBits(GPIOE, GPIO_Pin_6);
}

static void LCD_WriteReg(uint8_t reg, uint8_t val)
{
    LCD_WR_REG(reg);
    LCD_WR_DATA(val);
}

static void LCD_SetWindow(u16 x1, u16 y1, u16 x2, u16 y2)
{
    LCD_WR_REG(0x2A);
    LCD_WR_DATA(x1 >> 8);
    LCD_WR_DATA(x1 & 0xFF);
    LCD_WR_DATA(x2 >> 8);
    LCD_WR_DATA(x2 & 0xFF);

    LCD_WR_REG(0x2B);
    LCD_WR_DATA(y1 >> 8);
    LCD_WR_DATA(y1 & 0xFF);
    LCD_WR_DATA(y2 >> 8);
    LCD_WR_DATA(y2 & 0xFF);

    LCD_WR_REG(0x2C);
}

static void LCD_SPI_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    SPI_InitTypeDef  SPI_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_SetBits(GPIOE, GPIO_Pin_3);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_SetBits(GPIOE, GPIO_Pin_6);

    SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial = 7;
    SPI_Init(SPI3, &SPI_InitStructure);

    SPI_Cmd(SPI3, ENABLE);
}

static void LCD_Reset(void)
{
    GPIO_ResetBits(GPIOE, GPIO_Pin_3);
    delay_ms(100);
    GPIO_SetBits(GPIOE, GPIO_Pin_3);
    delay_ms(50);
}

void lcd_init(void)
{
    LCD_SPI_Init();
    LCD_Reset();

    LCD_WR_REG(0x01);
    delay_ms(120);

    LCD_WriteReg(0x11, 0x00);
    delay_ms(120);

    LCD_WriteReg(0x36, 0x00);

    LCD_WriteReg(0x3A, 0x55);

    LCD_WriteReg(0xB2, 0x0C);
    LCD_WriteReg(0xB2, 0x0C);
    LCD_WriteReg(0xB2, 0x00);
    LCD_WriteReg(0xB2, 0x33);
    LCD_WriteReg(0xB2, 0x33);

    LCD_WriteReg(0xB7, 0x35);

    LCD_WriteReg(0xBB, 0x28);

    LCD_WriteReg(0xC0, 0x2C);

    LCD_WriteReg(0xC2, 0x01);

    LCD_WriteReg(0xC3, 0x0B);

    LCD_WriteReg(0xC4, 0x20);

    LCD_WriteReg(0xC6, 0x0F);

    LCD_WriteReg(0xD0, 0xA4);
    LCD_WriteReg(0xD0, 0xA1);

    LCD_WR_REG(0xE0);
    LCD_WR_DATA(0xD0);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x02);
    LCD_WR_DATA(0x07);
    LCD_WR_DATA(0x0B);
    LCD_WR_DATA(0x1A);
    LCD_WR_DATA(0x31);
    LCD_WR_DATA(0x54);
    LCD_WR_DATA(0x40);
    LCD_WR_DATA(0x29);
    LCD_WR_DATA(0x12);
    LCD_WR_DATA(0x12);
    LCD_WR_DATA(0x12);
    LCD_WR_DATA(0x17);

    LCD_WR_REG(0xE1);
    LCD_WR_DATA(0xD0);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x02);
    LCD_WR_DATA(0x07);
    LCD_WR_DATA(0x05);
    LCD_WR_DATA(0x25);
    LCD_WR_DATA(0x2D);
    LCD_WR_DATA(0x44);
    LCD_WR_DATA(0x45);
    LCD_WR_DATA(0x1C);
    LCD_WR_DATA(0x18);
    LCD_WR_DATA(0x16);
    LCD_WR_DATA(0x1C);
    LCD_WR_DATA(0x1D);

    LCD_WR_REG(0x21);

    LCD_WR_REG(0x29);
    delay_ms(50);

    LCD_WriteReg(0x36, 0x00);

    lcd_clear(BLACK);
}

void lcd_clear(u16 color)
{
    u32 i;
    LCD_SetWindow(0, 0, LCD_W - 1, LCD_H - 1);
    for (i = 0; i < (u32)LCD_W * LCD_H; i++) {
        LCD_WR_DATA16(color);
    }
}

void lcd_set_color(u16 back, u16 fore)
{
    (void)back;
    (void)fore;
}

void lcd_address_set(u16 x1, u16 y1, u16 x2, u16 y2)
{
    LCD_SetWindow(x1, y1, x2, y2);
}

void lcd_draw_point_color(u16 x, u16 y, u16 color)
{
    LCD_SetWindow(x, y, x, y);
    LCD_WR_DATA16(color);
}

void lcd_draw_point(u16 x, u16 y)
{
    lcd_draw_point_color(x, y, WHITE);
}

void lcd_fill(u16 x_start, u16 y_start, u16 x_end, u16 y_end, u16 color)
{
    u16 i, j;
    for (i = y_start; i <= y_end; i++) {
        for (j = x_start; j <= x_end; j++) {
            LCD_SetWindow(j, i, j, i);
            LCD_WR_DATA16(color);
        }
    }
}

void lcd_draw_circle(u16 x0, u16 y0, u8 r)
{
    int a = 0, b = r, di = 3 - (r << 1);
    while (a <= b) {
        lcd_draw_point(x0 + a, y0 - b);
        lcd_draw_point(x0 + b, y0 - a);
        lcd_draw_point(x0 + b, y0 + a);
        lcd_draw_point(x0 + a, y0 + b);
        lcd_draw_point(x0 - a, y0 + b);
        lcd_draw_point(x0 - b, y0 + a);
        lcd_draw_point(x0 - b, y0 - a);
        lcd_draw_point(x0 - a, y0 - b);
        a++;
        if (di < 0) di += 4 * a + 6;
        else { di += 10 + 4 * (a - b); b--; }
    }
}

void lcd_draw_line(u16 x1, u16 y1, u16 x2, u16 y2)
{
    u16 t;
    int xerr = 0, yerr = 0, delta_x, delta_y, distance;
    int incx, incy;
    u16 row, col;
    delta_x = (int)x2 - (int)x1;
    delta_y = (int)y2 - (int)y1;
    row = x1;
    col = y1;
    if (delta_x > 0) incx = 1;
    else if (delta_x == 0) incx = 0;
    else { incx = -1; delta_x = -delta_x; }
    if (delta_y > 0) incy = 1;
    else if (delta_y == 0) incy = 0;
    else { incy = -1; delta_y = -delta_y; }
    distance = (delta_x > delta_y) ? delta_x : delta_y;
    for (t = 0; t <= distance + 1; t++) {
        lcd_draw_point(row, col);
        xerr += delta_x;
        yerr += delta_y;
        if (xerr > distance) { xerr -= distance; row += incx; }
        if (yerr > distance) { yerr -= distance; col += incy; }
    }
}

void lcd_draw_rectangle(u16 x1, u16 y1, u16 x2, u16 y2)
{
    lcd_draw_line(x1, y1, x2, y1);
    lcd_draw_line(x1, y1, x1, y2);
    lcd_draw_line(x1, y2, x2, y2);
    lcd_draw_line(x2, y1, x2, y2);
}

void lcd_show_num(u16 x, u16 y, u32 num, u8 len, u32 size)
{
    (void)x; (void)y; (void)num; (void)len; (void)size;
}

void lcd_show_string(u16 x, u16 y, u32 size, const char *fmt, ...)
{
    (void)x; (void)y; (void)size; (void)fmt;
}

void lcd_show_image(u16 x, u16 y, u16 length, u16 wide, const u8 *p)
{
    u16 i, j;
    for (i = 0; i < wide; i++) {
        for (j = 0; j < length; j++) {
            lcd_draw_point_color(x + j, y + i, ((u16)p[0] << 8) | p[1]);
            p += 2;
        }
    }
}

void LCD_SetBrightness(u8 brightness)
{
    (void)brightness;
}

void lcd_enter_sleep(void) {}
void lcd_exit_sleep(void) {}
void lcd_display_on(void) {}
void lcd_display_off(void) {}
