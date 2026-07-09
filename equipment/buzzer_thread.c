#include "rtthread.h"
#include "Buzzer.h"

/* ¼òµ¥Òô½× */
static const uint32_t melody[] = {
    262, 294, 330, 0
};

void buzzer_thread(void *parameter)
{
    Buzzer_GPIO_Init();
    TIM1_PWM_Init();

    while(1)
    {
        for(int i = 0; i < 4; i++)
        {
            Buzzer_SetFreq(melody[i]);

            if(melody[i] == 0)
                rt_thread_mdelay(500);
            else
                rt_thread_mdelay(300);
        }
    }
}