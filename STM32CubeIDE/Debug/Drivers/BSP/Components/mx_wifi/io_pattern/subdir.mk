################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.c \
../Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_uart.c 

OBJS += \
./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.o \
./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_uart.o 

C_DEPS += \
./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.d \
./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/mx_wifi/io_pattern/%.o Drivers/BSP/Components/mx_wifi/io_pattern/%.su Drivers/BSP/Components/mx_wifi/io_pattern/%.cyclo: ../Drivers/BSP/Components/mx_wifi/io_pattern/%.c Drivers/BSP/Components/mx_wifi/io_pattern/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../Core/Inc -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/littlefs-2.10.2/littlefs-2.10.2 -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/STM32CubeIDE/Drivers/BSP/STM32H573I-DK/Inc" -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/STM32CubeIDE/Drivers/BSP/STM32H573I-DK/Src" -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/Components" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-io_pattern

clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-io_pattern:
	-$(RM) ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.cyclo ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.d ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.o ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_spi.su ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_uart.cyclo ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_uart.d ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_uart.o ./Drivers/BSP/Components/mx_wifi/io_pattern/mx_wifi_uart.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-io_pattern

