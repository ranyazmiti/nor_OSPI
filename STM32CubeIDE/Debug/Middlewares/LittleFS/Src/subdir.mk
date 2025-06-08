################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/LittleFS/Src/lfs.c \
../Middlewares/LittleFS/Src/lfs_util.c 

OBJS += \
./Middlewares/LittleFS/Src/lfs.o \
./Middlewares/LittleFS/Src/lfs_util.o 

C_DEPS += \
./Middlewares/LittleFS/Src/lfs.d \
./Middlewares/LittleFS/Src/lfs_util.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LittleFS/Src/%.o Middlewares/LittleFS/Src/%.su Middlewares/LittleFS/Src/%.cyclo: ../Middlewares/LittleFS/Src/%.c Middlewares/LittleFS/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../Core/Inc -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/littlefs-2.10.2/littlefs-2.10.2 -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/Components -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/STM32H573I-DK -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-LittleFS-2f-Src

clean-Middlewares-2f-LittleFS-2f-Src:
	-$(RM) ./Middlewares/LittleFS/Src/lfs.cyclo ./Middlewares/LittleFS/Src/lfs.d ./Middlewares/LittleFS/Src/lfs.o ./Middlewares/LittleFS/Src/lfs.su ./Middlewares/LittleFS/Src/lfs_util.cyclo ./Middlewares/LittleFS/Src/lfs_util.d ./Middlewares/LittleFS/Src/lfs_util.o ./Middlewares/LittleFS/Src/lfs_util.su

.PHONY: clean-Middlewares-2f-LittleFS-2f-Src

