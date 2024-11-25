/**
  ******************************************************************************
  * @file           : nfc_conf.c
  * @brief          : This file contains definitions for the NFC6/8 components bus interfaces
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

#include "stm32f7xx_hal.h"
#include "nfc_conf.h"

/* Private variables ---------------------------------------------------------*/
IRQn_Type IRQ_ST25R_EXTI_IRQn;
EXTI_HandleTypeDef USR_INT_LINE;
uint32_t USR_INT_LINE_NUM;

nfc_platform platform_spi_init = {
    .nfc_spi = NULL,        // 초기값 설정
    .nfc_cs_port = NULL,    // 초기값 설정
    .nfc_cs_pin = 0,         // 초기값 설정
	.nfc_irq_port = 0,         // 초기값 설정
	.nfc_irq_pin = 0,         // 초기값 설정
};

extern nfc_platform platform_spi_init;
/* Private user code ---------------------------------------------------------*/
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
int32_t BSP_NFC0XCOMM_SendRecv(const uint8_t * const pTxData, uint8_t * const pRxData, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_ERROR;

  if((pTxData != NULL) && (pRxData != NULL))
  {
    status = HAL_SPI_TransmitReceive(platform_spi_init.nfc_spi, (uint8_t *)pTxData, (uint8_t *)pRxData, Length, 2000);
  }
  else if ((pTxData != NULL) && (pRxData == NULL))
  {
    status = HAL_SPI_Transmit(platform_spi_init.nfc_spi, (uint8_t *)pTxData, Length, 2000);
  }
  else if ((pTxData == NULL) && (pRxData != NULL))
  {
    status = HAL_SPI_Receive(platform_spi_init.nfc_spi, (uint8_t *)pRxData, Length, 2000);
  }
  else
  {

  }

  /* Check the communication status */
  if (status != HAL_OK)
  {
    /* Execute user timeout callback */

  }

  return 0;
}


