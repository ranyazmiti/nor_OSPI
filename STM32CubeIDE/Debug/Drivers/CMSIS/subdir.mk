################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Core/Src/system_stm32h5xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32h5xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32h5xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32h5xx.o: C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Core/Src/system_stm32h5xx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../Core/Inc -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/littlefs-2.10.2/littlefs-2.10.2 -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/Components -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/STM32H573I-DK -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32h5xx.cyclo ./Drivers/CMSIS/system_stm32h5xx.d ./Drivers/CMSIS/system_stm32h5xx.o ./Drivers/CMSIS/system_stm32h5xx.su

.PHONY: clean-Drivers-2f-CMSIS

