
/**
  ******************************************************************************
  * @file           : rfal_platform.h
  * @brief          : Platform header file. Defining platform independent functionality.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#ifdef STM32L053xx
#include "stm32l0xx_hal.h"
#endif

#ifdef STM32L476xx
#include "stm32l4xx_hal.h"
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "main.h"
typedef struct  {
	SPI_HandleTypeDef *nfc_spi;
	GPIO_TypeDef *nfc_cs_port;
	uint16_t nfc_cs_pin;
	GPIO_TypeDef *nfc_irq_port;
	uint16_t nfc_irq_pin;
}nfc_platform;

#include "timer.h"

#include "logger.h"
#include "RTE_Components.h"
#include "nfc_conf.h"


/** @addtogroup X-CUBE-NFC6_Applications
 *  @{
 */

/** @addtogroup PollingTagDetect
 *  @{
 */

/** @defgroup PTD_Platform
 *  @brief Demo functions containing the example code
 * @{
 */

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PTD_Platform_Exported_Macro
 *  @{
 */

extern nfc_platform platform_spi_init;

extern IRQn_Type IRQ_ST25R_EXTI_IRQn;
extern EXTI_HandleTypeDef USR_INT_LINE;
extern uint32_t USR_INT_LINE_NUM;

#define ST25R_INT_PIN            platform_spi_init.nfc_irq_pin    /*!< GPIO pin used for ST25R IRQ                   */
#define ST25R_INT_PORT           platform_spi_init.nfc_irq_port   /*!< GPIO port used for ST25R IRQ port             */


#define platformProtectST25RComm()                do{ globalCommProtectCnt++;                  \
                                                          __DSB();NVIC_DisableIRQ(IRQ_ST25R_EXTI_IRQn); \
                                                          __DSB();                             \
                                                          __ISB();                             \
                                                        }while(0)                                   /*!< Protect unique access to ST25R communication channel - IRQ disable on single thread environment (MCU) ; Mutex lock on a multi thread environment      */
#define platformUnprotectST25RComm()              do{ globalCommProtectCnt--;             \
                                                          if (globalCommProtectCnt == 0U) \
                                                          {                               \
                                                            NVIC_EnableIRQ(IRQ_ST25R_EXTI_IRQn);   \
                                                          }                               \
                                                        }while(0)                                   /*!< Unprotect unique access to ST25R communication channel - IRQ enable on a single thread environment (MCU) ; Mutex unlock on a multi thread environment */

#define platformSPI_INIT(spi,cs_port,cs_pin)	  do{	platform_spi_init.nfc_spi =spi; 		\
														platform_spi_init.nfc_cs_port = port; 	\
														platform_spi_init.nfc_cs_pin = pin; 	\
														}while(0)

#define platformProtectST25RIrqStatus()           platformProtectST25RComm()                /*!< Protect unique access to IRQ status var - IRQ disable on single thread environment (MCU) ; Mutex lock on a multi thread environment */
#define platformUnprotectST25RIrqStatus()         platformUnprotectST25RComm()              /*!< Unprotect the IRQ status var - IRQ enable on a single thread environment (MCU) ; Mutex unlock on a multi thread environment         */

#define platformProtectWorker()                                                                     /* Protect RFAL Worker/Task/Process from concurrent execution on multi thread platforms   */
#define platformUnprotectWorker()                                                                   /* Unprotect RFAL Worker/Task/Process from concurrent execution on multi thread platforms */

#define platformIrqST25RSetCallback( cb )
#define platformIrqST25RPinInitialize()

#define platformLedsInitialize()                                                                    /*!< Initializes the pins used as LEDs to outputs*/

#define platformLedOff( port, pin )                   platformGpioClear(port, pin)                  /*!< Turns the given LED Off                     */
#define platformLedOn( port, pin )                    platformGpioSet(port, pin)                    /*!< Turns the given LED On                      */
#define platformLedToogle( port, pin )                platformGpioToogle(port, pin)                 /*!< Toogle the given LED                        */

#define platformGpioSet( port, pin )                  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET)    /*!< Turns the given GPIO High                   */
#define platformGpioClear( port, pin )                HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET)  /*!< Turns the given GPIO Low                    */
#define platformGpioToogle( port, pin )               HAL_GPIO_TogglePin(port, pin)                 /*!< Toogles the given GPIO                      */
#define platformGpioIsHigh( port, pin )               (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET) /*!< Checks if the given LED is High             */
#define platformGpioIsLow( port, pin )                (!platformGpioIsHigh(port, pin))              /*!< Checks if the given LED is Low              */

#define platformTimerCreate( t )                      timerCalculateTimer(t)                        /*!< Create a timer with the given time (ms)     */
#define platformTimerIsExpired( timer )               timerIsExpired(timer)                         /*!< Checks if the given timer is expired        */
#define platformTimerDestroy( timer )                                                               /*!< Stop and release the given timer            */
#define platformDelay( t )                            HAL_Delay( t )                                /*!< Performs a delay for the given time (ms)    */

#define platformGetSysTick()                          HAL_GetTick()                                 /*!< Get System Tick ( 1 tick = 1 ms)            */

#define platformErrorHandle()                         _Error_Handler(__FILE__,__LINE__)             /*!< Global error handler or trap                */
#define platformSpiSelect()                           platformGpioClear(platform_spi_init.nfc_cs_port, platform_spi_init.nfc_cs_pin)/*!< SPI SS\CS: Chip|Slave Select                */
#define platformSpiDeselect()                         platformGpioSet(platform_spi_init.nfc_cs_port, platform_spi_init.nfc_cs_pin)  /*!< SPI SS\CS: Chip|Slave Deselect              */
#define platformSpiTxRx( txBuf, rxBuf, len )          BSP_NFC0XCOMM_SendRecv(txBuf, rxBuf, len)          /*!< SPI transceive                              */


#define platformLog(...)                              logUsart(__VA_ARGS__)                         /*!< Log  method                                 */

/* Exported functions ------------------------------------------------------- */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_H */

