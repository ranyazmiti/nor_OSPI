################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/mx_wifi/core/checksumutils.c \
../Drivers/BSP/Components/mx_wifi/core/mx_address.c \
../Drivers/BSP/Components/mx_wifi/core/mx_rtos_abs.c \
../Drivers/BSP/Components/mx_wifi/core/mx_wifi_hci.c \
../Drivers/BSP/Components/mx_wifi/core/mx_wifi_ipc.c \
../Drivers/BSP/Components/mx_wifi/core/mx_wifi_slip.c 

OBJS += \
./Drivers/BSP/Components/mx_wifi/core/checksumutils.o \
./Drivers/BSP/Components/mx_wifi/core/mx_address.o \
./Drivers/BSP/Components/mx_wifi/core/mx_rtos_abs.o \
./Drivers/BSP/Components/mx_wifi/core/mx_wifi_hci.o \
./Drivers/BSP/Components/mx_wifi/core/mx_wifi_ipc.o \
./Drivers/BSP/Components/mx_wifi/core/mx_wifi_slip.o 

C_DEPS += \
./Drivers/BSP/Components/mx_wifi/core/checksumutils.d \
./Drivers/BSP/Components/mx_wifi/core/mx_address.d \
./Drivers/BSP/Components/mx_wifi/core/mx_rtos_abs.d \
./Drivers/BSP/Components/mx_wifi/core/mx_wifi_hci.d \
./Drivers/BSP/Components/mx_wifi/core/mx_wifi_ipc.d \
./Drivers/BSP/Components/mx_wifi/core/mx_wifi_slip.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/mx_wifi/core/%.o Drivers/BSP/Components/mx_wifi/core/%.su Drivers/BSP/Components/mx_wifi/core/%.cyclo: ../Drivers/BSP/Components/mx_wifi/core/%.c Drivers/BSP/Components/mx_wifi/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../Core/Inc -IC:/Users/hp/Desktop/pfa/littlefs_OSPI_project/littlefs-2.10.2/littlefs-2.10.2 -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/STM32CubeIDE/Drivers/BSP/STM32H573I-DK/Inc" -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/STM32CubeIDE/Drivers/BSP/STM32H573I-DK/Src" -I"C:/Users/hp/Desktop/pfa/littlefs_OSPI_project/Drivers/BSP/Components" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-core

clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-core:
	-$(RM) ./Drivers/BSP/Components/mx_wifi/core/checksumutils.cyclo ./Drivers/BSP/Components/mx_wifi/core/checksumutils.d ./Drivers/BSP/Components/mx_wifi/core/checksumutils.o ./Drivers/BSP/Components/mx_wifi/core/checksumutils.su ./Drivers/BSP/Components/mx_wifi/core/mx_address.cyclo ./Drivers/BSP/Components/mx_wifi/core/mx_address.d ./Drivers/BSP/Components/mx_wifi/core/mx_address.o ./Drivers/BSP/Components/mx_wifi/core/mx_address.su ./Drivers/BSP/Components/mx_wifi/core/mx_rtos_abs.cyclo ./Drivers/BSP/Components/mx_wifi/core/mx_rtos_abs.d ./Drivers/BSP/Components/mx_wifi/core/mx_rtos_abs.o ./Drivers/BSP/Components/mx_wifi/core/mx_rtos_abs.su ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_hci.cyclo ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_hci.d ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_hci.o ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_hci.su ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_ipc.cyclo ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_ipc.d ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_ipc.o ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_ipc.su ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_slip.cyclo ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_slip.d ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_slip.o ./Drivers/BSP/Components/mx_wifi/core/mx_wifi_slip.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-mx_wifi-2f-core

