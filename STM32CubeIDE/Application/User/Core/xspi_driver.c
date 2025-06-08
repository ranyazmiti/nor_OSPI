#include "xspi_driver.h"
#include "stm32h573i_discovery_ospi.h"
#include "main.h"

#define START_ADDRESS  0  // Point de départ de la mémoire utile

int xspi_read(const struct lfs_config *c, lfs_block_t block,
              lfs_off_t off, void *buffer, lfs_size_t size) {
    uint32_t addr = block * c->block_size + off + START_ADDRESS;

    if (BSP_OSPI_NOR_Read(0, (uint8_t*)buffer, addr, size) != BSP_ERROR_NONE) {
        return -1;
    }
    return 0;
}

int xspi_write(const struct lfs_config *c, lfs_block_t block,
               lfs_off_t off, const void *buffer, lfs_size_t size) {
    uint32_t addr = block * c->block_size + off + START_ADDRESS;

    if (BSP_OSPI_NOR_Write(0, (uint8_t*)buffer, addr, size) != BSP_ERROR_NONE) {
        return -1;
    }
    return 0;
}

int xspi_erase(const struct lfs_config *c, lfs_block_t block) {
    uint32_t addr = block * c->block_size + START_ADDRESS;

    // ✅ Correction : passage du troisième argument (type d'effacement)
    if (BSP_OSPI_NOR_Erase_Block(0, addr, BSP_OSPI_NOR_ERASE_4K) != BSP_ERROR_NONE) {
        return -1;
    }
    HAL_Delay(10);
    return 0;

}

int xspi_sync(const struct lfs_config *c) {
    // ⚠️ Ajoute un délai pour s'assurer que les opérations sont terminées physiquement
    HAL_Delay(10);

    // Optionnel : ajoute une opération de lecture "dummy" pour forcer le vidage du buffer
    uint8_t dummy;
    BSP_OSPI_NOR_Read(0, &dummy, 0, 1);

    return 0;
}
