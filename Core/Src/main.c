/* USER CODE BEGIN Header */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "icache.h"
#include "memorymap.h"
#include "octospi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lfs.h"
#include "lfs_util.h"
#include "xspi_driver.h"
#include "stm32h573i_discovery_ospi.h"
#include "lfs_config.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void blink_led(int times) {
  for (int i = 0; i < times; i++) {
    HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_8); // LD2
    HAL_Delay(500);
    HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_8);
    HAL_Delay(500);
  }
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  MX_GPIO_Init();
  MX_ICACHE_Init();
  MX_OCTOSPI1_Init();
  MX_USART1_UART_Init();

  /* USER CODE BEGIN 2 */
  HAL_UART_Transmit(&huart1, (uint8_t*)"Init done. Starting LittleFS test...\r\n", 38, HAL_MAX_DELAY);
  blink_led(4);

  lfs_t lfs;
  struct lfs_config cfg;

  if (lfs_init(&lfs, &cfg) != 0) {
    Error_Handler();
  }

  lfs_file_t file;
  const char *text = "Hello from LittleFS!\r\n";
  if (lfs_file_open(&lfs, &file, "test.txt", LFS_O_WRONLY | LFS_O_CREAT) < 0) {
    Error_Handler();
  }
  lfs_file_write(&lfs, &file, text, strlen(text));
  lfs_file_close(&lfs, &file);

  char buffer[64] = {0};
  if (lfs_file_open(&lfs, &file, "test.txt", LFS_O_RDONLY) < 0) {
    Error_Handler();
  }
  lfs_file_read(&lfs, &file, buffer, sizeof(buffer));
  lfs_file_close(&lfs, &file);
  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
  blink_led(5);

  lfs_file_t file2;
  const char *text2 = "Test File2!\r\n";
  if (lfs_file_open(&lfs, &file2, "test2.txt", LFS_O_WRONLY | LFS_O_CREAT) < 0) {
    Error_Handler();
  }
  lfs_file_write(&lfs, &file2, text2, strlen(text2));
  lfs_file_close(&lfs, &file2);

  if (lfs_file_open(&lfs, &file2, "test2.txt", LFS_O_RDONLY) < 0) {
    Error_Handler();
  }
  char bufferr[64] = {0};
  lfs_file_read(&lfs, &file2, bufferr, sizeof(bufferr));
  lfs_file_close(&lfs, &file2);
  HAL_UART_Transmit(&huart1, (uint8_t*)bufferr, strlen(bufferr), HAL_MAX_DELAY);
  blink_led(5);

  HAL_UART_Transmit(&huart1, (uint8_t*)"Testing lfs_remove()...\r\n", 26, HAL_MAX_DELAY);

  int err = lfs_remove(&lfs, "test.txt");
  if (err == 0) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"File removed successfully.\r\n", 29, HAL_MAX_DELAY);
  } else if (err == LFS_ERR_NOENT) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"File did not exist (OK).\r\n", 27, HAL_MAX_DELAY);
  } else {
    HAL_UART_Transmit(&huart1, (uint8_t*)"Remove failed!\r\n", 17, HAL_MAX_DELAY);
    blink_led(3);
    Error_Handler();
  }

  const char *msg = "contenu file 2!\r\n";
  err = lfs_file_open(&lfs, &file, "test.txt", LFS_O_WRONLY | LFS_O_CREAT);
  if (err < 0) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"Failed to create file\r\n", 24, HAL_MAX_DELAY);
    Error_Handler();
  }
  lfs_file_write(&lfs, &file, msg, strlen(msg));
  lfs_file_close(&lfs, &file);

  err = lfs_file_open(&lfs, &file, "test.txt", LFS_O_RDONLY);
  if (err < 0) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"Read failed\r\n", 14, HAL_MAX_DELAY);
    Error_Handler();
  }
  char buffer2[64] = {0};
  lfs_file_read(&lfs, &file, buffer2, sizeof(buffer2));
  lfs_file_close(&lfs, &file);
  HAL_UART_Transmit(&huart1, (uint8_t*)"Read content: ", 14, HAL_MAX_DELAY);
  HAL_UART_Transmit(&huart1, (uint8_t*)buffer2, strlen(buffer2), HAL_MAX_DELAY);

  err = lfs_remove(&lfs, "test.txt");
  if (err == 0) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"\r\nFile removed again successfully.\r\n", 35, HAL_MAX_DELAY);
  } else {
    HAL_UART_Transmit(&huart1, (uint8_t*)"\r\nFinal remove failed.\r\n", 24, HAL_MAX_DELAY);
    Error_Handler();
  }

  err = lfs_file_open(&lfs, &file2, "test.txt", LFS_O_RDONLY);
  if (err == LFS_ERR_NOENT) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"Confirmed: file no longer exists.\r\n", 35, HAL_MAX_DELAY);
    blink_led(2);
  } else {
    HAL_UART_Transmit(&huart1, (uint8_t*)"ERROR: File still exists.\r\n", 27, HAL_MAX_DELAY);
    lfs_file_close(&lfs, &file2);
    blink_led(4);
    Error_Handler();
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);
  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_CSI;
  RCC_OscInitStruct.CSIState = RCC_CSI_ON;
  RCC_OscInitStruct.CSICalibrationValue = RCC_CSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_CSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 125;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  __HAL_FLASH_SET_PROGRAM_DELAY(FLASH_PROGRAMMING_DELAY_2);
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
    HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_9);
    HAL_Delay(100);
  }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
