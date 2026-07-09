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
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Debug" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/User" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Peripheral/inc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/drivers" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include/libc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/draw" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/extra" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/font" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/hal" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/GUI" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

