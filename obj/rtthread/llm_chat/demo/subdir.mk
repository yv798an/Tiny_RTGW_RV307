################################################################################
# MRS Version: 2.4.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rtthread/llm_chat/demo/llm_contory.c 

C_DEPS += \
./rtthread/llm_chat/demo/llm_contory.d 

OBJS += \
./rtthread/llm_chat/demo/llm_contory.o 

DIR_OBJS += \
./rtthread/llm_chat/demo/*.o \

DIR_DEPS += \
./rtthread/llm_chat/demo/*.d \

DIR_EXPANDS += \
./rtthread/llm_chat/demo/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
rtthread/llm_chat/demo/%.o: ../rtthread/llm_chat/demo/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Debug" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/User" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/Peripheral/inc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/drivers" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/include/libc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/core" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/draw" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/extra" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/font" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/hal" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/misc" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/GUI" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/llm_chat" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/llm_chat/config" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/llm_chat/demo" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/llm_chat/ports" -I"d:/WCH_qinheng/project/Tiny_RTGW_RV307/rtthread/llm_chat/resource" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

