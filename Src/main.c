/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

uint16_t notes[89] = {
		NOTE_B0,	// 0
		NOTE_C1,	// 1
		NOTE_CS1,	// 2
		NOTE_D1,	// 3
		NOTE_DS1,	// 4
		NOTE_E1,	// 5
		NOTE_F1,	// 6
		NOTE_FS1,	// 7
		NOTE_G1,	// 8
		NOTE_GS1,	// 9
		NOTE_A1,	// 10
		NOTE_AS1,	// 11
		NOTE_B1,	// 12
		NOTE_C2,	// 13
		NOTE_CS2,	// 14
		NOTE_D2,	// 15
		NOTE_DS2,	// 16
		NOTE_E2,	// 17
		NOTE_F2,	// 18
		NOTE_FS2,	// 19
		NOTE_G2,	// 20
		NOTE_GS2,	// 21
		NOTE_A2,	// 22
		NOTE_AS2,	// 23
		NOTE_B2,	// 24
		NOTE_C3,	// 25
		NOTE_CS3,	// 26
		NOTE_D3,	// 27
		NOTE_DS3,	// 28
		NOTE_E3,	// 29
		NOTE_F3,	// 30
		NOTE_FS3,	// 31
		NOTE_G3,	// 32
		NOTE_GS3,	// 33
		NOTE_A3,	// 34
		NOTE_AS3,	// 35
		NOTE_B3,	// 36
		NOTE_C4,	// 37
		NOTE_CS4,	// 38
		NOTE_D4,	// 39
		NOTE_DS4,	// 40
		NOTE_E4,	// 41
		NOTE_F4,	// 42
		NOTE_FS4,	// 43
		NOTE_G4,	// 44
		NOTE_GS4,	// 45
		NOTE_A4,	// 46
		NOTE_AS4,	// 47
		NOTE_B4,	// 48
		NOTE_C5,	// 49
		NOTE_CS5,	// 50
		NOTE_D5,	// 51
		NOTE_DS5,	// 52
		NOTE_E5,	// 53
		NOTE_F5,	// 54
		NOTE_FS5,	// 55
		NOTE_G5,	// 56
		NOTE_GS5,	// 57
		NOTE_A5,	// 58
		NOTE_AS5,	// 59
		NOTE_B5,	// 60
		NOTE_C6,	// 61
		NOTE_CS6,	// 62
		NOTE_D6,	// 63
		NOTE_DS6,	// 64
		NOTE_E6,	// 65
		NOTE_F6,	// 66
		NOTE_FS6,	// 67
		NOTE_G6,	// 68
		NOTE_GS6,	// 69
		NOTE_A6,	// 70
		NOTE_AS6,	// 71
		NOTE_B6,	// 72
		NOTE_C7,	// 73
		NOTE_CS7,	// 74
		NOTE_D7,	// 75
		NOTE_DS7,	// 76
		NOTE_E7,	// 77
		NOTE_F7,	// 78
		NOTE_FS7,	// 79
		NOTE_G7,	// 80
		NOTE_GS7,	// 81
		NOTE_A7,	// 82
		NOTE_AS7,	// 83
		NOTE_B7,	// 84
		NOTE_C8,	// 85
		NOTE_CS8,	// 86
		NOTE_D8,	// 87
		NOTE_DS8	// 88
};

//variables for notes (for main timer)
const uint8_t baseNote = 44;
volatile uint8_t currentNote = 44;

//convert frequency in Hz to ARR value
uint16_t freq2arr(uint32_t freq){
	return 1000000/freq;
}

//set frequency to chosen timer
void setFreq(uint32_t freq, TIM_HandleTypeDef* htim, TIM_TypeDef* t){
	uint16_t f = freq2arr(freq);
	setArr(f, t);
	__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_1, 0.5*f);
}

//set ARR of chosen timer
void setArr(uint32_t arr, TIM_TypeDef* t){
	t->ARR=arr;
}

//turn main buzzer on
void toneOn(){
	HAL_GPIO_WritePin(buzzer3_GPIO_Port, buzzer3_Pin, GPIO_PIN_SET);
}

//turn main buzzer off
void toneOff(){
	HAL_GPIO_WritePin(buzzer3_GPIO_Port, buzzer3_Pin, GPIO_PIN_RESET);
}

//method for playing defined sequence of notes
void playSequence(uint8_t note){
	uint8_t time = 200;
	setFreq(notes[note],&htim3, TIM3);
	toneOn();
	HAL_Delay(time);
	toneOff();
	HAL_Delay(time);

	uint8_t diff = note -  baseNote ;
	uint8_t k = 4;
	if(diff==2||diff==4||diff==9||diff==11){
		k=3;
	}

	setFreq(notes[note+k],&htim3, TIM3);
	toneOn();
	HAL_Delay(time);
	toneOff();
	HAL_Delay(time);

	setFreq(notes[note+7],&htim3, TIM3);
	toneOn();
	HAL_Delay(time);
	toneOff();
	HAL_Delay(time);

	setFreq(notes[note+12],&htim3, TIM3);
	toneOn();
	HAL_Delay(time);
	toneOff();
	HAL_Delay(time);
}

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

//define enabling the main buzzer
bool work = false;

//define enabling second buzzer
bool work2 = false;

//additional variable declarations
uint8_t message[24];
uint16_t mlen;
uint32_t adcResult = 0;
uint32_t time1 = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  MX_ADC1_Init();
  MX_TIM4_Init();
  MX_TIM1_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */

 	//start PWM on timers
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_1);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim4);

  //initialize main timer
  setFreq(notes[currentNote], &htim3,TIM3);

  //initialize random number generation
  srand(time(0));

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //if main buzzer should play - play the sequence
	  if(work){
		  playSequence(currentNote);
	  }
	  else{
		  toneOff();
	  }

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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	//blue embedded button
	if(GPIO_Pin==buttonC_Pin){
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		work=!work;

    //red button
	}else if(GPIO_Pin==buttonRed_Pin && HAL_GPIO_ReadPin(buttonRed_GPIO_Port, buttonRed_Pin)== GPIO_PIN_SET){
		  uint32_t time2 = HAL_GetTick();
		  if ((time2 - time1)>200)
			  work2=!work2;
		  time1 = time2;
	}

	//touchpads
	else if(GPIO_Pin==touch1_Pin&&HAL_GPIO_ReadPin(touch1_GPIO_Port, touch1_Pin)== GPIO_PIN_SET){
		currentNote = baseNote; //c
		}

	else if(GPIO_Pin==touch2_Pin&&HAL_GPIO_ReadPin(touch2_GPIO_Port, touch2_Pin)== GPIO_PIN_SET){
		currentNote = baseNote + 2; //d
		}

	else if(GPIO_Pin==touch3_Pin&&HAL_GPIO_ReadPin(touch3_GPIO_Port, touch3_Pin)== GPIO_PIN_SET){
		currentNote = baseNote + 4; //e
		}

	else if(GPIO_Pin==touch4_Pin&&HAL_GPIO_ReadPin(touch4_GPIO_Port, touch4_Pin)== GPIO_PIN_SET){
		currentNote = baseNote + 5; //f
		}

	else if(GPIO_Pin==touch5_Pin&&HAL_GPIO_ReadPin(touch5_GPIO_Port, touch5_Pin)== GPIO_PIN_SET){
		currentNote = baseNote + 7; //g
		}

	else if(GPIO_Pin==touch6_Pin&&HAL_GPIO_ReadPin(touch6_GPIO_Port, touch6_Pin)== GPIO_PIN_SET){
		currentNote = baseNote + 9; //a
		}

	else if(GPIO_Pin==touch7_Pin&&HAL_GPIO_ReadPin(touch7_GPIO_Port, touch7_Pin)== GPIO_PIN_SET){
		currentNote = baseNote + 11; //b
		}

	else if(GPIO_Pin==touch8_Pin&&HAL_GPIO_ReadPin(touch8_GPIO_Port, touch8_Pin)== GPIO_PIN_SET){
		currentNote = baseNote + 12; //c
		}

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	//send data via UART
	if(htim->Instance == TIM2){
		if(work){
			uint8_t num = rand() % 5;
			uint8_t m[24];
			snprintf(m, 24, "\r     current note: %d",currentNote);
			m[num+1] = '~';
			mlen = sprintf(message, m);
			HAL_UART_Transmit_DMA(&huart2, message, mlen);
		}else{
			uint8_t m[24];
			snprintf(m, 24, "\r     current note: %d",currentNote);
			m[3] = 'x';
			mlen = sprintf(message, m);
			HAL_UART_Transmit_DMA(&huart2, message, mlen);
		}
	}

	//read analog data and enable second buzzer
	if(htim->Instance == TIM4){
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 100);
		float val = (float)HAL_ADC_GetValue(&hadc1)/4095.0;
		if (val == 1){
		    val = 0.99;
		}
		adcResult = (uint32_t)(val*13) + baseNote;
		HAL_ADC_Stop(&hadc1);
		setFreq(notes[adcResult],&htim5, TIM5);

		if(work2){
			HAL_GPIO_WritePin(buzzerRed_GPIO_Port, buzzerRed_Pin, GPIO_PIN_SET);
		}else{
			HAL_GPIO_WritePin(buzzerRed_GPIO_Port, buzzerRed_Pin, GPIO_PIN_RESET);
		}
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
