/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define buttonC_Pin GPIO_PIN_13
#define buttonC_GPIO_Port GPIOC
#define buttonC_EXTI_IRQn EXTI15_10_IRQn
#define touch8_Pin GPIO_PIN_0
#define touch8_GPIO_Port GPIOC
#define touch8_EXTI_IRQn EXTI0_IRQn
#define touch7_Pin GPIO_PIN_1
#define touch7_GPIO_Port GPIOC
#define touch7_EXTI_IRQn EXTI1_IRQn
#define touch6_Pin GPIO_PIN_2
#define touch6_GPIO_Port GPIOC
#define touch6_EXTI_IRQn EXTI2_IRQn
#define touch5_Pin GPIO_PIN_3
#define touch5_GPIO_Port GPIOC
#define touch5_EXTI_IRQn EXTI3_IRQn
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define buzzer3_Pin GPIO_PIN_7
#define buzzer3_GPIO_Port GPIOA
#define pot_Pin GPIO_PIN_4
#define pot_GPIO_Port GPIOC
#define buzzerRed_Pin GPIO_PIN_5
#define buzzerRed_GPIO_Port GPIOC
#define buttonRed_Pin GPIO_PIN_15
#define buttonRed_GPIO_Port GPIOB
#define buttonRed_EXTI_IRQn EXTI15_10_IRQn
#define touch1_Pin GPIO_PIN_6
#define touch1_GPIO_Port GPIOC
#define touch1_EXTI_IRQn EXTI9_5_IRQn
#define touch3_Pin GPIO_PIN_8
#define touch3_GPIO_Port GPIOC
#define touch3_EXTI_IRQn EXTI9_5_IRQn
#define touch4_Pin GPIO_PIN_9
#define touch4_GPIO_Port GPIOC
#define touch4_EXTI_IRQn EXTI9_5_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define touch2_Pin GPIO_PIN_5
#define touch2_GPIO_Port GPIOB
#define touch2_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
