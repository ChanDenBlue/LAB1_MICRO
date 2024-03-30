/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
// Define the LED sequences
/* USER CODE END PFP */
const int digitConfig[][7] = {
        // A, B, C, D, E, F, G, DP
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
    };
void display7SEG(int num) {
	 if (num < 0 || num > 9) {
	        return;
	    }
	 const int *config = digitConfig[num];

	 HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, config[0] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, config[1] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, config[2] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, config[3] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, config[4] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, config[5] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, config[6] ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void display7SEG2(int num) {

	 if (num < 0 || num > 9) {
		        return;
		    }
	 const int *config = digitConfig[num];

	 HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, config[0] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, config[1] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, config[2] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, config[3] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, config[4] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, config[5] ? GPIO_PIN_RESET : GPIO_PIN_SET);
	 HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, config[6] ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int count_red = 9 ;
  int count_yellow = 3;
  int count_green = 5;
  int open_red = 1 ;
  int open_yellow = 0 ;
  int open_green = 0 ;
  ////
  int count_red2 = 9 ;
  int count_yellow2 = 3;
  int count_green2 = 5;
  int open_red2 = 0 ;
  int open_yellow2 = 0 ;
  int open_green2 = 1 ;

  while (1)
  {

	  /// part 1
	  if (open_green == 1 ) {
	  	         HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	  	         HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin | LED3_Pin, GPIO_PIN_SET);
	  	         if (count_green >= 0) {
	  	            display7SEG(count_green) ;
	  	            }
	  	         if (count_green < 0) {
	  	        	open_green = 0 ;
	  	        	open_yellow = 1 ;
	  	        	count_yellow = 3 ;
	  	         }
	  	         count_green--;
	  }
	  if (open_yellow == 1) {
	  	     	 HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin | LED2_Pin, GPIO_PIN_SET);
	  	     	 HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
	  	     	 if (count_yellow >= 0) {
	  	     		 display7SEG(count_yellow) ;
	  	     	 }
	  	     	 if (count_yellow < 0) {
	  	     		 open_yellow = 0 ;
	  	     		 open_red = 1 ;
	  	     		 count_red = 9 ;
	  	         }
	  	     	 count_yellow--;
	  }
	  if (open_red == 1 ) {
	  	         HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin | LED3_Pin, GPIO_PIN_SET);
	  	         HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	  	         display7SEG(count_red);
	  	         if (count_red == 0) {
	  	       	  	      open_red = 0 ;
	  	       	  	      open_green = 1 ;
	  	       	  	      count_green = 5 ;
	  	       	 }
	  	         count_red -- ;
	  }
	  ///// part 2
	  if (open_green2 == 1 ) {
	  	  	         HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
	  	  	         HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin | LED4_Pin, GPIO_PIN_SET);
	  	  	         if (count_green2 >= 0) {
	  	  	            display7SEG2(count_green2) ;
	  	  	            }
	  	  	         if (count_green2 < 0) {
	  	  	        	open_green2 = 0 ;
	  	  	        	open_yellow2 = 1 ;
	  	  	        	count_yellow2 = 3 ;
	  	  	         }
	  	  	         count_green2--;
	  	  }
	  	  if (open_yellow2 == 1) {
	  	  	     	 HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin | LED6_Pin, GPIO_PIN_SET);
	  	  	     	 HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
	  	  	     	 if (count_yellow2 >= 0) {
	  	  	     		 display7SEG2(count_yellow2) ;
	  	  	     	 }
	  	  	     	 if (count_yellow2 < 0) {
	  	  	     		 open_yellow2 = 0 ;
	  	  	     		 open_red2 = 1 ;
	  	  	     		 count_red2 = 9 ;
	  	  	         }
	  	  	     	 count_yellow2--;
	  	  }
	  	  if (open_red2 == 1 ) {
	  	  	         HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin | LED4_Pin, GPIO_PIN_SET);
	  	  	         HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
	  	  	         display7SEG2(count_red2);
	  	  	         if (count_red2 == 0) {
	  	  	       	  	      open_red2 = 0 ;
	  	  	       	  	      open_green2 = 1 ;
	  	  	       	  	      count_green2 = 5 ;
	  	  	       	 }
	  	  	         count_red2 -- ;
	  	  }

	  HAL_Delay(1000);



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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|B3_Pin
                          |B4_Pin|B5_Pin|B6_Pin|B7_Pin
                          |SEG_D_Pin|SEG_E_Pin|SEG_F_Pin|SEG_G_Pin
                          |B1_Pin|B2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin LED4_Pin
                           LED5_Pin LED6_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin B3_Pin
                           B4_Pin B5_Pin B6_Pin B7_Pin
                           SEG_D_Pin SEG_E_Pin SEG_F_Pin SEG_G_Pin
                           B1_Pin B2_Pin */
  GPIO_InitStruct.Pin = SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|B3_Pin
                          |B4_Pin|B5_Pin|B6_Pin|B7_Pin
                          |SEG_D_Pin|SEG_E_Pin|SEG_F_Pin|SEG_G_Pin
                          |B1_Pin|B2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
