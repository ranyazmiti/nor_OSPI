################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32H573I/Src/resources.c \
../Drivers/BSP/STM32H573I/Src/stm32h5xx_hal_msp.c \
../Drivers/BSP/STM32H573I/Src/system_stm32h5xx.c 

OBJS += \
./Drivers/BSP/STM32H573I/Src/resources.o \
./Drivers/BSP/STM32H573I/Src/stm32h5xx_hal_msp.o \
./Drivers/BSP/STM32H573I/Src/system_stm32h5xx.o 

C_DEPS += \
./Drivers/BSP/STM32H573I/Src/resources.d \
./Drivers/BSP/STM32H573I/Src/stm32h5xx_hal_msp.d \
./Drivers/BSP/STM32H573I/Src/system_stm32h5xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H573I/Src/%.o Drivers/BSP/STM32H573I/Src/%.su Drivers/BSP/STM32H573I/Src/%.cyclo: ../Drivers/BSP/STM32H573I/Src/%.c Drivers/BSP/STM32H573I/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../Core/Inc -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/littlefs-2.10.2/littlefs-2.10.2 -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/STM32CubeIDE/Drivers/BSP/STM32H573I-DK/Inc" -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/STM32CubeIDE/Drivers/BSP/STM32H573I-DK/Src" -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/Components" -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/STM32H573I-DK -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H573I-2f-Src

clean-Drivers-2f-BSP-2f-STM32H573I-2f-Src:
	-$(RM) ./Drivers/BSP/STM32H573I/Src/resources.cyclo ./Drivers/BSP/STM32H573I/Src/resources.d ./Drivers/BSP/STM32H573I/Src/resources.o ./Drivers/BSP/STM32H573I/Src/resources.su ./Drivers/BSP/STM32H573I/Src/stm32h5xx_hal_msp.cyclo ./Drivers/BSP/STM32H573I/Src/stm32h5xx_hal_msp.d ./Drivers/BSP/STM32H573I/Src/stm32h5xx_hal_msp.o ./Drivers/BSP/STM32H573I/Src/stm32h5xx_hal_msp.su ./Drivers/BSP/STM32H573I/Src/system_stm32h5xx.cyclo ./Drivers/BSP/STM32H573I/Src/system_stm32h5xx.d ./Drivers/BSP/STM32H573I/Src/system_stm32h5xx.o ./Drivers/BSP/STM32H573I/Src/system_stm32h5xx.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H573I-2f-Src

