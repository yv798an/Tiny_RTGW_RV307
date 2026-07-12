################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sdl/lv_draw_sdl.c \
../lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

C_DEPS += \
./lvgl/src/draw/sdl/lv_draw_sdl.d \
./lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./lvgl/src/draw/sdl/lv_draw_sdl_utils.d 

OBJS += \
./lvgl/src/draw/sdl/lv_draw_sdl.o \
./lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

DIR_OBJS += \
./lvgl/src/draw/sdl/*.o \

DIR_DEPS += \
./lvgl/src/draw/sdl/*.d \

DIR_EXPANDS += \
./lvgl/src/draw/sdl/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sdl/%.o: ../lvgl/src/draw/sdl/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Debug" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/User" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Peripheral/inc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/drivers" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include/libc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/draw" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/extra" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/font" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/hal" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/GUI" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

