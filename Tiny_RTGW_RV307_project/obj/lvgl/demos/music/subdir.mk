################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/music/lv_demo_music.c \
../lvgl/demos/music/lv_demo_music_list.c \
../lvgl/demos/music/lv_demo_music_main.c 

C_DEPS += \
./lvgl/demos/music/lv_demo_music.d \
./lvgl/demos/music/lv_demo_music_list.d \
./lvgl/demos/music/lv_demo_music_main.d 

OBJS += \
./lvgl/demos/music/lv_demo_music.o \
./lvgl/demos/music/lv_demo_music_list.o \
./lvgl/demos/music/lv_demo_music_main.o 

DIR_OBJS += \
./lvgl/demos/music/*.o \

DIR_DEPS += \
./lvgl/demos/music/*.d \

DIR_EXPANDS += \
./lvgl/demos/music/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/music/%.o: ../lvgl/demos/music/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Debug" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/User" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Peripheral/inc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/drivers" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include/libc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/draw" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/extra" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/font" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/hal" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/GUI" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

