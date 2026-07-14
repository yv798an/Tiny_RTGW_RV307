#include "DHT20.h"
#include "bsp_i2c1.h"
#include "rtthread.h"

#define DHT20_ADDR        0x38
#define DHT20_TICK_MS     10        
#define DHT20_WAIT_MS     80         
#define DHT20_PERIOD_MS   2000        

static rt_timer_t   s_timer;
static DHT20_State  s_state = DHT20_IDLE;
static rt_tick_t    s_start_tick;     
static rt_tick_t    s_idle_tick;      

static float        s_temperature;
static float        s_humidity;
static uint8_t      s_valid;         

static void DHT20_StartMeasure(void)
{
    uint8_t cmd[3] = {0xAC, 0x33, 0x00};

    if (I2C_Write(DHT20_ADDR, cmd, 3)) {
        s_state = DHT20_ERROR;
        return;
    }
    s_start_tick = rt_tick_get();      
    s_state = DHT20_MEASURING;
}


static void DHT20_TimerCallback(void *parameter)
{
    uint8_t  data[6];
    uint32_t hum, temp;

    (void)parameter;

    switch (s_state)
    {
    case DHT20_IDLE:
        if (rt_tick_get() - s_idle_tick >=
            rt_tick_from_millisecond(DHT20_PERIOD_MS))
            DHT20_StartMeasure();
        break;

    case DHT20_MEASURING:
        if (rt_tick_get() - s_start_tick <
            rt_tick_from_millisecond(DHT20_WAIT_MS))
            break;

        if (I2C_Read(DHT20_ADDR, data, 6)) 
        {
            s_state = DHT20_ERROR;
            break;
        }

        if (data[0] & 0x80)         
            break;

        hum  = ((uint32_t)data[1] << 12) |
               ((uint32_t)data[2] << 4)  |
               ((uint32_t)data[3] >> 4);
        temp = (((uint32_t)data[3] & 0x0F) << 16) |
               ((uint32_t)data[4] << 8) | data[5];

        s_humidity    = hum  * 100.0f  / 1048576.0f;
        s_temperature = temp * 200.0f  / 1048576.0f - 50.0f;
        s_valid       = 1;

        s_idle_tick = rt_tick_get();
        s_state = DHT20_IDLE;
        break;

    case DHT20_ERROR:
    default:
        s_idle_tick = rt_tick_get();
        s_state = DHT20_IDLE;
        break;
    }
}

uint8_t DHT20_Init(void)
{
    s_state     = DHT20_IDLE;
    s_valid     = 0;
    s_idle_tick = rt_tick_get() - rt_tick_from_millisecond(DHT20_PERIOD_MS);

    s_timer = rt_timer_create("dht20",
                              DHT20_TimerCallback,
                              RT_NULL,
                              rt_tick_from_millisecond(DHT20_TICK_MS),
                              RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_SOFT_TIMER);
    if (s_timer == RT_NULL)
        return 1;

    rt_timer_start(s_timer);

    return 0;
}

uint8_t DHT20_GetData(float *temperature, float *humidity)
{
    if (!s_valid)
        return 1;

    *temperature = s_temperature;
    *humidity    = s_humidity;

    return 0;
}
