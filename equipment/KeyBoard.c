#include "KeyBoard.h"
#include "rtthread.h"
#include <stdio.h>

/* ================= 键值映射 ================= */
static const char keymap[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

/* ================= 行控制 ================= */
static void Row_Set(uint8_t row)
{
    GPIO_SetBits(GPIOD, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);

    switch(row)
    {
        case 0: GPIO_ResetBits(GPIOD, GPIO_Pin_0); break;
        case 1: GPIO_ResetBits(GPIOD, GPIO_Pin_1); break;
        case 2: GPIO_ResetBits(GPIOD, GPIO_Pin_2); break;
        case 3: GPIO_ResetBits(GPIOD, GPIO_Pin_3); break;
    }
}

/* ================= 初始化 ================= */
void Keypad_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* 行 PD0~PD3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    /* 列 PD4~PD7 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_SetBits(GPIOD, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
}

/* ================= 扫描函数 ================= */
char Key_Scan(void)
{
    for(int row = 0; row < 4; row++)
    {
        Row_Set(row);
        rt_thread_mdelay(5);

        for(int col = 0; col < 4; col++)
        {
            uint16_t pin = (GPIO_Pin_4 << col);

            if(GPIO_ReadInputDataBit(GPIOD, pin) == 0)
            {
                rt_thread_mdelay(10);

                if(GPIO_ReadInputDataBit(GPIOD, pin) == 0)
                {
                    while(GPIO_ReadInputDataBit(GPIOD, pin) == 0);
                    return keymap[row][col];
                }
            }
        }
    }
    return 0;
}

/* ================= RT-Thread任务 ================= */
void Keypad_Task(void *parameter)
{
    while(1)
    {
        char key = Key_Scan();

        if(key)
        {
            rt_kprintf("KEY: %c\r\n", key);
        }

        rt_thread_mdelay(20);
    }
}