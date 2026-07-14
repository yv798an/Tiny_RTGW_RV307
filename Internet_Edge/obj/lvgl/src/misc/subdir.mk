################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/misc/lv_anim.c \
../lvgl/src/misc/lv_anim_timeline.c \
../lvgl/src/misc/lv_area.c \
../lvgl/src/misc/lv_async.c \
../lvgl/src/misc/lv_bidi.c \
../lvgl/src/misc/lv_color.c \
../lvgl/src/misc/lv_fs.c \
../lvgl/src/misc/lv_gc.c \
../lvgl/src/misc/lv_ll.c \
../lvgl/src/misc/lv_log.c \
../lvgl/src/misc/lv_lru.c \
../lvgl/src/misc/lv_math.c \
../lvgl/src/misc/lv_mem.c \
../lvgl/src/misc/lv_printf.c \
../lvgl/src/misc/lv_style.c \
../lvgl/src/misc/lv_style_gen.c \
../lvgl/src/misc/lv_templ.c \
../lvgl/src/misc/lv_timer.c \
../lvgl/src/misc/lv_tlsf.c \
../lvgl/src/misc/lv_txt.c \
../lvgl/src/misc/lv_txt_ap.c \
../lvgl/src/misc/lv_utils.c 

C_DEPS += \
./lvgl/src/misc/lv_anim.d \
./lvgl/src/misc/lv_anim_timeline.d \
./lvgl/src/misc/lv_area.d \
./lvgl/src/misc/lv_async.d \
./lvgl/src/misc/lv_bidi.d \
./lvgl/src/misc/lv_color.d \
./lvgl/src/misc/lv_fs.d \
./lvgl/src/misc/lv_gc.d \
./lvgl/src/misc/lv_ll.d \
./lvgl/src/misc/lv_log.d \
./lvgl/src/misc/lv_lru.d \
./lvgl/src/misc/lv_math.d \
./lvgl/src/misc/lv_mem.d \
./lvgl/src/misc/lv_printf.d \
./lvgl/src/misc/lv_style.d \
./lvgl/src/misc/lv_style_gen.d \
./lvgl/src/misc/lv_templ.d \
./lvgl/src/misc/lv_timer.d \
./lvgl/src/misc/lv_tlsf.d \
./lvgl/src/misc/lv_txt.d \
./lvgl/src/misc/lv_txt_ap.d \
./lvgl/src/misc/lv_utils.d 

OBJS += \
./lvgl/src/misc/lv_anim.o \
./lvgl/src/misc/lv_anim_timeline.o \
./lvgl/src/misc/lv_area.o \
./lvgl/src/misc/lv_async.o \
./lvgl/src/misc/lv_bidi.o \
./lvgl/src/misc/lv_color.o \
./lvgl/src/misc/lv_fs.o \
./lvgl/src/misc/lv_gc.o \
./lvgl/src/misc/lv_ll.o \
./lvgl/src/misc/lv_log.o \
./lvgl/src/misc/lv_lru.o \
./lvgl/src/misc/lv_math.o \
./lvgl/src/misc/lv_mem.o \
./lvgl/src/misc/lv_printf.o \
./lvgl/src/misc/lv_style.o \
./lvgl/src/misc/lv_style_gen.o \
./lvgl/src/misc/lv_templ.o \
./lvgl/src/misc/lv_timer.o \
./lvgl/src/misc/lv_tlsf.o \
./lvgl/src/misc/lv_txt.o \
./lvgl/src/misc/lv_txt_ap.o \
./lvgl/src/misc/lv_utils.o 

DIR_OBJS += \
./lvgl/src/misc/*.o \

DIR_DEPS += \
./lvgl/src/misc/*.d \

DIR_EXPANDS += \
./lvgl/src/misc/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/misc/%.o: ../lvgl/src/misc/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"d:/WCH_qinheng/project/Internet_Edge/Debug" -I"d:/WCH_qinheng/project/Internet_Edge/Core" -I"d:/WCH_qinheng/project/Internet_Edge/User" -I"d:/WCH_qinheng/project/Internet_Edge/Peripheral/inc" -I"d:/WCH_qinheng/project/Internet_Edge/drivers" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/include/libc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/libcpu/risc-v/common" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/src" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/include" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/misc" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/drivers/serial" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components/finsh" -I"d:/WCH_qinheng/project/Internet_Edge/rtthread/components" -I"d:/WCH_qinheng/project/Internet_Edge/equipment" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ulog" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/TIM" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/I2C" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/DHT20" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/ADC" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/sensor" -I"d:/WCH_qinheng/project/Internet_Edge/GUI" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/benchmark/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/keypad_encoder" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/music/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/stress" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/demos/widgets/assets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/examples/porting" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/core" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/arm2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_pxp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/nxp_vglite" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sdl" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/stm32_dma2d" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/draw/sw" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/flex" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/layouts/grid" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/bmp" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/ffmpeg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/freetype" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/fsdrv" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/gif" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/png" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/qrcode" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/rlottie" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/libs/sjpg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/fragment" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/gridnav" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/imgfont" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/monkey" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/msg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/others/snapshot" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/basic" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/default" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/themes/mono" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/animimg" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/calendar" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/chart" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/colorwheel" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/imgbtn" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/keyboard" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/led" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/list" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/menu" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/meter" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/msgbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/span" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinbox" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/spinner" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tabview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/tileview" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/extra/widgets/win" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/font" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/hal" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/misc" -I"d:/WCH_qinheng/project/Internet_Edge/lvgl/src/widgets" -I"d:/WCH_qinheng/project/Internet_Edge/equipment/usart" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

