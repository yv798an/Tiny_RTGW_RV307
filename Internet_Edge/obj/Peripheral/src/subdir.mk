################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/ch32v30x_adc.c \
../Peripheral/src/ch32v30x_bkp.c \
../Peripheral/src/ch32v30x_can.c \
../Peripheral/src/ch32v30x_crc.c \
../Peripheral/src/ch32v30x_dac.c \
../Peripheral/src/ch32v30x_dbgmcu.c \
../Peripheral/src/ch32v30x_dma.c \
../Peripheral/src/ch32v30x_dvp.c \
../Peripheral/src/ch32v30x_eth.c \
../Peripheral/src/ch32v30x_exti.c \
../Peripheral/src/ch32v30x_flash.c \
../Peripheral/src/ch32v30x_fsmc.c \
../Peripheral/src/ch32v30x_gpio.c \
../Peripheral/src/ch32v30x_i2c.c \
../Peripheral/src/ch32v30x_iwdg.c \
../Peripheral/src/ch32v30x_misc.c \
../Peripheral/src/ch32v30x_opa.c \
../Peripheral/src/ch32v30x_pwr.c \
../Peripheral/src/ch32v30x_rcc.c \
../Peripheral/src/ch32v30x_rng.c \
../Peripheral/src/ch32v30x_rtc.c \
../Peripheral/src/ch32v30x_sdio.c \
../Peripheral/src/ch32v30x_spi.c \
../Peripheral/src/ch32v30x_tim.c \
../Peripheral/src/ch32v30x_usart.c \
../Peripheral/src/ch32v30x_wwdg.c 

C_DEPS += \
./Peripheral/src/ch32v30x_adc.d \
./Peripheral/src/ch32v30x_bkp.d \
./Peripheral/src/ch32v30x_can.d \
./Peripheral/src/ch32v30x_crc.d \
./Peripheral/src/ch32v30x_dac.d \
./Peripheral/src/ch32v30x_dbgmcu.d \
./Peripheral/src/ch32v30x_dma.d \
./Peripheral/src/ch32v30x_dvp.d \
./Peripheral/src/ch32v30x_eth.d \
./Peripheral/src/ch32v30x_exti.d \
./Peripheral/src/ch32v30x_flash.d \
./Peripheral/src/ch32v30x_fsmc.d \
./Peripheral/src/ch32v30x_gpio.d \
./Peripheral/src/ch32v30x_i2c.d \
./Peripheral/src/ch32v30x_iwdg.d \
./Peripheral/src/ch32v30x_misc.d \
./Peripheral/src/ch32v30x_opa.d \
./Peripheral/src/ch32v30x_pwr.d \
./Peripheral/src/ch32v30x_rcc.d \
./Peripheral/src/ch32v30x_rng.d \
./Peripheral/src/ch32v30x_rtc.d \
./Peripheral/src/ch32v30x_sdio.d \
./Peripheral/src/ch32v30x_spi.d \
./Peripheral/src/ch32v30x_tim.d \
./Peripheral/src/ch32v30x_usart.d \
./Peripheral/src/ch32v30x_wwdg.d 

OBJS += \
./Peripheral/src/ch32v30x_adc.o \
./Peripheral/src/ch32v30x_bkp.o \
./Peripheral/src/ch32v30x_can.o \
./Peripheral/src/ch32v30x_crc.o \
./Peripheral/src/ch32v30x_dac.o \
./Peripheral/src/ch32v30x_dbgmcu.o \
./Peripheral/src/ch32v30x_dma.o \
./Peripheral/src/ch32v30x_dvp.o \
./Peripheral/src/ch32v30x_eth.o \
./Peripheral/src/ch32v30x_exti.o \
./Peripheral/src/ch32v30x_flash.o \
./Peripheral/src/ch32v30x_fsmc.o \
./Peripheral/src/ch32v30x_gpio.o \
./Peripheral/src/ch32v30x_i2c.o \
./Peripheral/src/ch32v30x_iwdg.o \
./Peripheral/src/ch32v30x_misc.o \
./Peripheral/src/ch32v30x_opa.o \
./Peripheral/src/ch32v30x_pwr.o \
./Peripheral/src/ch32v30x_rcc.o \
./Peripheral/src/ch32v30x_rng.o \
./Peripheral/src/ch32v30x_rtc.o \
./Peripheral/src/ch32v30x_sdio.o \
./Peripheral/src/ch32v30x_spi.o \
./Peripheral/src/ch32v30x_tim.o \
./Peripheral/src/ch32v30x_usart.o \
./Peripheral/src/ch32v30x_wwdg.o 

DIR_OBJS += \
./Peripheral/src/*.o \

DIR_DEPS += \
./Peripheral/src/*.d \

DIR_EXPANDS += \
./Peripheral/src/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/%.o: ../Peripheral/src/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Internet_Edge/Debug" -I"d:/WCH_qinheng/project/Internet_Edge/Core" -I"d:/WCH_qinheng/project/Internet_Edge/User" -I"d:/WCH_qinheng/project/Internet_Edge/Peripheral/inc" -I"d:/WCH_qinheng/project/Internet_Edge/drivers" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include/libc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/src" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components" -I"d:/WCH_qinheng/project/Internet_Edge/equipment" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ulog" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/TIM" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/I2C" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/DHT20" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ADC" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/sensor" -I"d:/WCH_qinheng/project/Internet_Edge/GUI" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/keypad_encoder" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/stress" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/core" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/arm2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_pxp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_vglite" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sdl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/stm32_dma2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/flex" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/grid" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/bmp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/ffmpeg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/freetype" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/fsdrv" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/gif" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/png" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/qrcode" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/rlottie" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/sjpg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/fragment" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/gridnav" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/imgfont" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/monkey" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/msg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/snapshot" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/basic" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/default" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/mono" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/animimg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/calendar" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/chart" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/colorwheel" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/imgbtn" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/keyboard" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/led" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/list" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/menu" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/meter" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/msgbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/span" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinner" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tabview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tileview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/win" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/font" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/hal" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/misc" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/usart" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

