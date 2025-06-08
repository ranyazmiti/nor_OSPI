#include "main.h"
#include "icache.h"
#include "memorymap.h"
#include "octospi.h"
#include "usart.h"
#include "gpio.h"
#include "lfs.h"
#include "lfs_util.h"
#include "xspi_driver.h"
#include "stm32h573i_discovery_ospi.h"
#include "lfs_config.h"
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN 0 */
void blink_led(int times) {
 for (int i = 0; i < times; i++) {
   HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_8); // LD2
   HAL_Delay(500);
   HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_8);
   HAL_Delay(500);
 }
}
/* USER CODE END 0 */
int main(void)
{
 /* USER CODE BEGIN 1 */
 /* USER CODE END 1 */
 /* MCU Configuration--------------------------------------------------------*/
 /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
 HAL_Init();
 /* USER CODE BEGIN Init */
 /* USER CODE END Init */
 /* Configure the system clock */
 SystemClock_Config();
 /* USER CODE BEGIN SysInit */
 /* USER CODE END SysInit */
 /* Initialize all configured peripherals */
 MX_GPIO_Init();
 MX_ICACHE_Init();
 MX_OCTOSPI1_Init();
 MX_USART1_UART_Init();
 /* USER CODE BEGIN 2 */
 // ...
 HAL_UART_Transmit(&huart1, (uint8_t*)"Init done. Starting LittleFS test...\r\n", 38, HAL_MAX_DELAY);
 blink_led(4);

 lfs_t lfs;
 struct lfs_config cfg;

 if (lfs_init(&lfs, &cfg) != 0) {
     Error_Handler();
 }


 // Write test.txt
 lfs_file_t file;
 const char *text = "Hello from LittleFS!\r\n";
 if (lfs_file_open(&lfs, &file, "test.txt", LFS_O_WRONLY | LFS_O_CREAT) < 0) {
     Error_Handler();
 }
 lfs_file_write(&lfs, &file, text, strlen(text));
 lfs_file_close(&lfs, &file);
 // Read and display test.txt
 char buffer[64] = {0};
 if (lfs_file_open(&lfs, &file, "test.txt", LFS_O_RDONLY) < 0) {
     Error_Handler();
 }
 lfs_file_read(&lfs, &file, buffer, sizeof(buffer));
 lfs_file_close(&lfs, &file);
 HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
 blink_led(5);

 // Write test.txt
 lfs_file_t file2;
 const char *text2 = "Test File2!\r\n";
 if (lfs_file_open(&lfs, &file2, "test2.txt", LFS_O_WRONLY | LFS_O_CREAT) < 0) {
     Error_Handler();
 }
 lfs_file_write(&lfs, &file2, text2, strlen(text2));
 lfs_file_close(&lfs, &file2);
 // Read and display test.txt

 if (lfs_file_open(&lfs, &file2, "test2.txt", LFS_O_RDONLY) < 0) {
     Error_Handler();
 }
 char bufferr[64] = {0};
 lfs_file_read(&lfs, &file2, bufferr, sizeof(bufferr));
 lfs_file_close(&lfs, &file2);
 HAL_UART_Transmit(&huart1, (uint8_t*)bufferr, strlen(bufferr), HAL_MAX_DELAY);
 blink_led(5);

/* USER CODE END 2 */

HAL_UART_Transmit(&huart1, (uint8_t*)"Testing lfs_remove()...\r\n", 26, HAL_MAX_DELAY);

 // Supprimer si le fichier existe
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

 // Créer un nouveau fichier
 const char *msg = "contenu file 2!\r\n";
 err = lfs_file_open(&lfs, &file, "test.txt", LFS_O_WRONLY | LFS_O_CREAT);
 if (err < 0) {
     HAL_UART_Transmit(&huart1, (uint8_t*)"Failed to create file\r\n", 24, HAL_MAX_DELAY);
     Error_Handler();
 }
 lfs_file_write(&lfs, &file, msg, strlen(msg));
 lfs_file_close(&lfs, &file);

 // Lire pour vérifier que l'écriture a réussi
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

 // Supprimer encore
  err = lfs_remove(&lfs, "test.txt");
 if (err == 0) {
     HAL_UART_Transmit(&huart1, (uint8_t*)"\r\nFile removed again successfully.\r\n", 35, HAL_MAX_DELAY);
 } else {
     HAL_UART_Transmit(&huart1, (uint8_t*)"\r\nFinal remove failed.\r\n", 24, HAL_MAX_DELAY);
     Error_Handler();
 }

 // Vérifier que le fichier n'existe plus
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
 /** Configure the main internal regulator output voltage
 */
 __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
 while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
 /** Initializes the RCC Oscillators according to the specified parameters
 * in the RCC_OscInitTypeDef structure.
 */
 RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
 RCC_OscInitStruct.HSIState = RCC_HSI_ON;
 RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV2;
 RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
 RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
 if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
 {
   Error_Handler();
 }
 /** Initializes the CPU, AHB and APB buses clocks
 */
 RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                             |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                             |RCC_CLOCKTYPE_PCLK3;
 RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
 RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
 RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
 RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
 RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;
 if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
 {
   Error_Handler();
 }
 /** Configure the programming delay
 */
 __HAL_FLASH_SET_PROGRAM_DELAY(FLASH_PROGRAMMING_DELAY_0);
}
/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
 __disable_irq();
 while (1)
 {
   HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_9);
   HAL_Delay(100);
 }
}
