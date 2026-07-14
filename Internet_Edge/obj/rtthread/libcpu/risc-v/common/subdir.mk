################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rtthread/libcpu/risc-v/common/cpuport.c 

C_DEPS += \
./rtthread/libcpu/risc-v/common/cpuport.d 

S_UPPER_SRCS += \
../rtthread/libcpu/risc-v/common/context_gcc.S \
../rtthread/libcpu/risc-v/common/interrupt_gcc.S 

S_UPPER_DEPS += \
./rtthread/libcpu/risc-v/common/context_gcc.d \
./rtthread/libcpu/risc-v/common/interrupt_gcc.d 

OBJS += \
./rtthread/libcpu/risc-v/common/context_gcc.o \
./rtthread/libcpu/risc-v/common/cpuport.o \
./rtthread/libcpu/risc-v/common/interrupt_gcc.o 

DIR_OBJS += \
./rtthread/libcpu/risc-v/common/*.o \

DIR_DEPS += \
./rtthread/libcpu/risc-v/common/*.d \

DIR_EXPANDS += \
./rtthread/libcpu/risc-v/common/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
rtthread/libcpu/risc-v/common/%.o: ../rtthread/libcpu/risc-v/common/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Internet_Edge/Debug" -I"d:/WCH_qinheng/project/Internet_Edge/Core" -I"d:/WCH_qinheng/project/Internet_Edge/User" -I"d:/WCH_qinheng/project/Internet_Edge/Peripheral/inc" -I"d:/WCH_qinheng/project/Internet_Edge/drivers" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include/libc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/src" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components" -I"d:/WCH_qinheng/project/Internet_Edge/equipment" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ulog" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/TIM" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/I2C" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/DHT20" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ADC" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/sensor" -I"d:/WCH_qinheng/project/Internet_Edge/GUI" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/keypad_encoder" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/stress" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/core" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/arm2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_pxp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_vglite" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sdl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/stm32_dma2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/flex" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/grid" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/bmp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/ffmpeg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/freetype" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/fsdrv" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/gif" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/png" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/qrcode" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/rlottie" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/sjpg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/fragment" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/gridnav" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/imgfont" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/monkey" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/msg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/snapshot" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/basic" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/default" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/mono" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/animimg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/calendar" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/chart" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/colorwheel" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/imgbtn" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/keyboard" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/led" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/list" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/menu" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/meter" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/msgbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/span" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinner" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tabview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tileview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/win" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/font" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/hal" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/misc" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/usart" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

rtthread/libcpu/risc-v/common/%.o: ../rtthread/libcpu/risc-v/common/%.S
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -x assembler-with-cpp -I"d:/WCH_qinheng/project/Internet_Edge/Startup" -I"d:/WCH_qinheng/project/Internet_Edge/drivers" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include/libc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/src" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

