################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c \
../lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.c \
../lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.c \
../lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.c 

C_DEPS += \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d 

OBJS += \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o 

DIR_OBJS += \
./lvgl/demos/benchmark/assets/*.o \

DIR_DEPS += \
./lvgl/demos/benchmark/assets/*.d \

DIR_EXPANDS += \
./lvgl/demos/benchmark/assets/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/benchmark/assets/%.o: ../lvgl/demos/benchmark/assets/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Internet_Edge/Debug" -I"d:/WCH_qinheng/project/Internet_Edge/Core" -I"d:/WCH_qinheng/project/Internet_Edge/User" -I"d:/WCH_qinheng/project/Internet_Edge/Peripheral/inc" -I"d:/WCH_qinheng/project/Internet_Edge/drivers" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include/libc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/src" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components" -I"d:/WCH_qinheng/project/Internet_Edge/equipment" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ulog" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/TIM" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/I2C" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/DHT20" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ADC" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/sensor" -I"d:/WCH_qinheng/project/Internet_Edge/GUI" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/keypad_encoder" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/stress" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/core" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/arm2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_pxp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_vglite" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sdl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/stm32_dma2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/flex" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/grid" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/bmp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/ffmpeg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/freetype" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/fsdrv" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/gif" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/png" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/qrcode" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/rlottie" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/sjpg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/fragment" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/gridnav" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/imgfont" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/monkey" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/msg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/snapshot" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/basic" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/default" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/mono" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/animimg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/calendar" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/chart" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/colorwheel" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/imgbtn" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/keyboard" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/led" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/list" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/menu" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/meter" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/msgbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/span" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinner" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tabview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tileview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/win" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/font" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/hal" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/misc" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/usart" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

