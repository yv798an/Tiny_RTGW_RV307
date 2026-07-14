#include "bsp_i2c1.h"
#include "rtthread.h"

#ifndef GET_INT_SP
#define GET_INT_SP()   asm("csrrw sp,mscratch,sp")
#define FREE_INT_SP()  asm("csrrw sp,mscratch,sp")
#endif

static rt_sem_t i2c_sem = RT_NULL;
static volatile uint8_t i2c_error_flag = 0;

static void I2C_Bus_Recovery(void)
{
    I2C_SoftwareResetCmd(I2C1, ENABLE);
    I2C_SoftwareResetCmd(I2C1, DISABLE);

    I2C_DeInit(I2C1);

    I2C_InitTypeDef I2C_InitStructure;
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_ClockSpeed = 100000;
    I2C_InitStructure.I2C_OwnAddress1 = 0X00;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C1, &I2C_InitStructure);
    I2C_Cmd(I2C1, ENABLE);
}

void I2C1_EV_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void I2C1_EV_IRQHandler(void)
{
    GET_INT_SP();
    rt_interrupt_enter();
    if (i2c_sem) {
        rt_sem_release(i2c_sem);
    }
    rt_interrupt_leave();
    FREE_INT_SP();
}

void I2C1_ER_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void I2C1_ER_IRQHandler(void)
{
    GET_INT_SP();
    rt_interrupt_enter();
    i2c_error_flag = 1;
    (void)I2C1->STAR1;
    if (i2c_sem) {
        rt_sem_release(i2c_sem);
    }
    rt_interrupt_leave();
    FREE_INT_SP();
}

void I2C1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    I2C_InitTypeDef I2C_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

    GPIO_PinRemapConfig(GPIO_Remap_I2C1, DISABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    I2C_DeInit(I2C1);
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_ClockSpeed = 100000;
    I2C_InitStructure.I2C_OwnAddress1 = 0X00;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C1, &I2C_InitStructure);
    I2C_Cmd(I2C1, ENABLE);

    /* Polling mode: the I2C event/error interrupts are intentionally left
       disabled. The helpers below poll the status flags with a timeout,
       which is robust for the low-rate DHT20 access. */
}

static uint8_t I2C_Wait(uint32_t event, uint32_t timeout_ms)
{
    rt_tick_t deadline = rt_tick_get() + rt_tick_from_millisecond(timeout_ms);

    while (!I2C_CheckEvent(I2C1, event)) {
        if ((rt_int32_t)(rt_tick_get() - deadline) >= 0) {
            I2C_Bus_Recovery();
            return 1;
        }
    }
    return 0;
}

static uint8_t I2C_WaitNotBusy(uint32_t timeout_ms)
{
    rt_tick_t deadline = rt_tick_get() + rt_tick_from_millisecond(timeout_ms);

    while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY)) {
        if ((rt_int32_t)(rt_tick_get() - deadline) >= 0) {
            I2C_Bus_Recovery();
            return 1;
        }
    }
    return 0;
}

uint8_t I2C_Write(uint8_t add, uint8_t *data, uint8_t len)
{
    if (I2C_WaitNotBusy(10))
        return 1;

    I2C_GenerateSTART(I2C1, ENABLE);

    if (I2C_Wait(I2C_EVENT_MASTER_MODE_SELECT, 10))
        return 1;

    I2C_Send7bitAddress(I2C1, add << 1, I2C_Direction_Transmitter);

    if (I2C_Wait(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED, 10))
        return 2;

    for (uint8_t i = 0; i < len; i++) {
        I2C_SendData(I2C1, data[i]);
        if (I2C_Wait(I2C_EVENT_MASTER_BYTE_TRANSMITTED, 10))
            return 3;
    }

    I2C_GenerateSTOP(I2C1, ENABLE);
    return 0;
}

uint8_t I2C_Read(uint8_t addr, uint8_t *buf, uint8_t len)
{
    if (I2C_WaitNotBusy(10))
        return 1;

    I2C_GenerateSTART(I2C1, ENABLE);

    if (I2C_Wait(I2C_EVENT_MASTER_MODE_SELECT, 10))
        return 1;

    I2C_Send7bitAddress(I2C1, addr << 1, I2C_Direction_Receiver);

    if (I2C_Wait(I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED, 10))
        return 2;

    for (uint8_t i = 0; i < len; i++) {
        if (i == len - 1) {
            I2C_AcknowledgeConfig(I2C1, DISABLE);
        }

        if (I2C_Wait(I2C_EVENT_MASTER_BYTE_RECEIVED, 10))
            return 3;

        buf[i] = I2C_ReceiveData(I2C1);
    }

    I2C_GenerateSTOP(I2C1, ENABLE);
    I2C_AcknowledgeConfig(I2C1, ENABLE);

    return 0;
}
