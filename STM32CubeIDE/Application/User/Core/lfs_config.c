/*
 * lfs_config.c
 *
 *  Created on: Jun 7, 2025
 *      Author: hp
 */
#include "lfs_config.h"
#include "xspi_driver.h"
#include "stm32h573i_discovery_ospi.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>

int lfs_init(lfs_t *lfs, struct lfs_config *cfg) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"Init LittleFS...\r\n", 19, HAL_MAX_DELAY);

    BSP_OSPI_NOR_Init_t FlashConfig = {
        .InterfaceMode = BSP_OSPI_NOR_OPI_MODE,
        .TransferRate = BSP_OSPI_NOR_STR_TRANSFER
    };

    if (BSP_OSPI_NOR_Init(0, &FlashConfig) != BSP_ERROR_NONE) {
        HAL_UART_Transmit(&huart1, (uint8_t*)"Erreur BSP_OSPI_NOR_Init\r\n", 27, HAL_MAX_DELAY);
        return -1;
    }

    *cfg = (struct lfs_config){
        .read  = xspi_read,
        .prog  = xspi_write,
        .erase = xspi_erase,
        .sync  = xspi_sync,

        .read_size = 256,
        .prog_size = 256,
        .block_size = 4096,
        .block_count = 16384,
        .cache_size = 256,
        .lookahead_size = 16,
        .block_cycles = 500,
    };

    if (lfs_format(lfs, cfg) != 0) {
        HAL_UART_Transmit(&huart1, (uint8_t*)"Format failed\r\n", 15, HAL_MAX_DELAY);
        return -2;
    }

    if (lfs_mount(lfs, cfg) != 0) {
        HAL_UART_Transmit(&huart1, (uint8_t*)"Mount failed\r\n", 14, HAL_MAX_DELAY);
        return -3;
    }

    HAL_UART_Transmit(&huart1, (uint8_t*)"LittleFS OK\r\n", 13, HAL_MAX_DELAY);
    return 0;
}
