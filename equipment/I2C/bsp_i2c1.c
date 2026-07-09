#include "bsp_i2c1.h"
#include "rtthread.h"


static uint8_t I2C_Wait(
        uint32_t event,
        uint32_t timeout
)
{
    while(!I2C_CheckEvent(I2C1,event))
    {
        if(timeout-- == 0)
        {
            return 1;
        }
    }

    return 0;
}



void I2C1_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;
    I2C_InitTypeDef I2C_InitStructure;


    /*
     * GPIOB + AFIO
     */
    RCC_APB2PeriphClockCmd(
            RCC_APB2Periph_GPIOB |
            RCC_APB2Periph_AFIO,
            ENABLE
    );


    /*
     * I2C1时钟
     */
    RCC_APB1PeriphClockCmd(
            RCC_APB1Periph_I2C1,
            ENABLE
    );



    /*
     * I2C1默认映射
     *
     * PB6 -> SCL
     * PB7 -> SDA
     */
    GPIO_PinRemapConfig(
            GPIO_Remap_I2C1,
            DISABLE
    );



    GPIO_InitStructure.GPIO_Pin =
            GPIO_Pin_6 |
            GPIO_Pin_7;


    GPIO_InitStructure.GPIO_Mode =
            GPIO_Mode_AF_OD;


    GPIO_InitStructure.GPIO_Speed =
            GPIO_Speed_50MHz;


    GPIO_Init(
            GPIOB,
            &GPIO_InitStructure
    );



    I2C_DeInit(I2C1);



    I2C_InitStructure.I2C_Mode =
            I2C_Mode_I2C;


    I2C_InitStructure.I2C_DutyCycle =
            I2C_DutyCycle_2;


    I2C_InitStructure.I2C_ClockSpeed =
            100000;



    I2C_InitStructure.I2C_OwnAddress1 =
            0x00;


    I2C_InitStructure.I2C_Ack =
            I2C_Ack_Enable;


    I2C_InitStructure.I2C_AcknowledgedAddress =
            I2C_AcknowledgedAddress_7bit;



    I2C_Init(
            I2C1,
            &I2C_InitStructure
    );



    I2C_Cmd(
            I2C1,
            ENABLE
    );


}




/*
 * I2C写
 *
 * addr传入7bit地址
 * 例如DHT20:
 * 0x38
 *
 */
uint8_t I2C_Write(
        uint8_t addr,
        uint8_t *data,
        uint8_t len
)
{

    while(
        I2C_GetFlagStatus(
                I2C1,
                I2C_FLAG_BUSY
        )
    );



    I2C_GenerateSTART(
            I2C1,
            ENABLE
    );



    if(I2C_Wait(
            I2C_EVENT_MASTER_MODE_SELECT,
            100000))
    {
        return 1;
    }



    /*
     * 关键修改
     *
     * 7bit地址转8bit
     */
    I2C_Send7bitAddress(
            I2C1,
            addr << 1,
            I2C_Direction_Transmitter
    );



    if(I2C_Wait(
            I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED,
            100000))
    {

        I2C_GenerateSTOP(
                I2C1,
                ENABLE
        );

        return 2;
    }



    for(uint8_t i=0;i<len;i++)
    {

        I2C_SendData(
                I2C1,
                data[i]
        );


        if(I2C_Wait(
                I2C_EVENT_MASTER_BYTE_TRANSMITTED,
                100000))
        {

            I2C_GenerateSTOP(
                    I2C1,
                    ENABLE
            );

            return 3;
        }

    }



    I2C_GenerateSTOP(
            I2C1,
            ENABLE
    );


    return 0;

}







/*
 * I2C读
 *
 */
uint8_t I2C_Read(
        uint8_t addr,
        uint8_t *buf,
        uint8_t len
)
{

    while(
        I2C_GetFlagStatus(
                I2C1,
                I2C_FLAG_BUSY
        )
    );



    I2C_GenerateSTART(
            I2C1,
            ENABLE
    );



    if(I2C_Wait(
            I2C_EVENT_MASTER_MODE_SELECT,
            100000))
    {
        return 1;
    }



    /*
     * 关键修改
     */
    I2C_Send7bitAddress(
            I2C1,
            addr << 1,
            I2C_Direction_Receiver
    );



    if(I2C_Wait(
            I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED,
            100000))
    {

        I2C_GenerateSTOP(
                I2C1,
                ENABLE
        );

        return 2;
    }




    for(uint8_t i=0;i<len;i++)
    {


        if(i == len-1)
        {

            I2C_AcknowledgeConfig(
                    I2C1,
                    DISABLE
            );

        }



        if(I2C_Wait(
                I2C_EVENT_MASTER_BYTE_RECEIVED,
                100000))
        {

            return 3;

        }



        buf[i] =
            I2C_ReceiveData(I2C1);

    }




    I2C_GenerateSTOP(
            I2C1,
            ENABLE
    );



    I2C_AcknowledgeConfig(
            I2C1,
            ENABLE
    );



    return 0;

}