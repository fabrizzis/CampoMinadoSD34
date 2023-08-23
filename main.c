/* USER CODE BEGIN Header */
/**
  **************************
  * @file           : main.c
  * @brief          : Main program body
  **************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  **************************
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
int matriz [4][4] ={{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
char vetor1[3];


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void fimdeJogo();
void acionabuzzer();
void desligabuzzer();
void testeBotao();
void Sorteador();
char linhas();
char colunas();
void jogadaCerta();
void teclado(char *p1);

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
  //fimdeJogo();
//  jogadaCerta();
  while (1)
  {

//acionabuzzer();
//desligabuzzer();
//testeBotao();
 //Sorteador();
teclado(&vetor1[0]);
leteclado();



//jogadaCerta();


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

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);

  /*Configure GPIO pins : PC13 PC14 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB10 PB11
                           PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void fimdeJogo()
{

while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1 && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1 && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == 1 &&  HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 1){

HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
HAL_Delay(200);

HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);
HAL_Delay(200);

HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0);
HAL_Delay(200);

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
HAL_Delay(200);

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
HAL_Delay(200);

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
HAL_Delay(200);

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
HAL_Delay(200);

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
HAL_Delay(200);
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
HAL_Delay(200);

acionabuzzer();
desligabuzzer();



}
}

void acionabuzzer()
{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
		HAL_Delay(3000);

}

void desligabuzzer()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);

}

void testeBotao()
{

	int botao1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
	int botao2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	int botao3 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
	int botao4 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11);

	if(botao1 == 0)
	{

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);

	}





	else if(botao2 == 0)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);
	}




	else if(botao3 == 0)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 1);
	}





	else if(botao4 == 0)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
	}

	else{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
	}









}
void Sorteador()
{
	int linha;
	int coluna;


	for(int i = 0; i <= 3; i++)
	{
		linha = rand()%4;
		coluna = rand()%4;


		if(matriz [linha][coluna] == 0)
		{
			matriz [linha][coluna] = 1;
		}

		else
		{
			i--;

		}
	}

	    matriz[0][0] = 0;
	    matriz[0][1] = 0;
	    matriz[0][2] = 0;
	    matriz[0][3] = 0;
	    matriz[1][0] = 0;
	    matriz[1][1] = 0;
	    matriz[1][2] = 0;
	    matriz[1][3] = 0;
	    matriz[2][0] = 0;
	    matriz[2][1] = 0;
	    matriz[2][2] = 0;
	    matriz[2][3] = 0;
	    matriz[3][0] = 0;
	    matriz[3][1] = 0;
	    matriz[3][2] = 0;
	    matriz[3][3] = 0;

}

void jogadaCerta()
{

	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1 && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1 && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == 1 &&  HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 1){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
	HAL_Delay(100);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);
	HAL_Delay(100);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0);
	HAL_Delay(100);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
	HAL_Delay(100);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_Delay(100);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	HAL_Delay(100);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
	HAL_Delay(100);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_Delay(100);
}
}

char colunas(void)
{

    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 0)
    {
    	return 'A';
    }

    else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0)
    {
    	return 'D';
    }
    else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == 0)
    {
    	return 'B';
    }
    else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 0)
    {
    	return 'C';
    }

    else{
    	return 0;
    }


}

char linhas (void)
{
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12) == 0)
	{
		return '1';
	}

	else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == 0)

	{
		return '2';
	}

	else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0)
	{
		return '3';
	}

	else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0)
	{
		return '4';
	}

	else{
		return 0;
	}

}

void teclado(char *p1)
{

	char x=0;
	char y=0;
	int continua=1;

	while(continua==1)
	{
		x = colunas();

		if(x != 0)
		{
		    *p1 = x;
			p1++;
		}


		y = linhas();

		if(y != 0)
		{
			*p1 = y;
			p1++;
		}



		if(x==0 && y==0)
		{
			continua=0;
		}
	}

}

void leteclado()
{
	  teclado(&vetor1[0]);
	  if(!(vetor1[0]>='A' && vetor1[0]<='C' && vetor1[1]>='1' && vetor1[1]<='4'))
	  {
		  vetor1[0]='X';
		  vetor1[1]='X';
	  }

}







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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
