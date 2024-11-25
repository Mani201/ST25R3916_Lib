/**
  ******************************************************************************
  * @file           : nfc_conf.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NFC0XA1_CONF_H__
#define __NFC0XA1_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_exti.h"
#include "RTE_Components.h"
#include "st25r3916_irq.h"
#include "main.h"


#define TEST               7
#define TEST_LINE          EXTI9_5_IRQn

#define TEST_RFAL_CUSTOM

#define RFAL_FEATURE_LISTEN_MODE                    true       /*!< Enable/Disable RFAL support for Listen Mode                               */
#define RFAL_FEATURE_WAKEUP_MODE                    false /*!< Enable/Disable RFAL support for the Wake-Up mode                          */
#define RFAL_FEATURE_LOWPOWER_MODE                  false /*!< Enable/Disable RFAL support for the Low Power mode                        */
#define RFAL_FEATURE_NFCA                           false /*!< Enable/Disable RFAL support for NFC-A (ISO14443A)                         */
#define RFAL_FEATURE_NFCB                           false /*!< Enable/Disable RFAL support for NFC-B (ISO14443B)                         */
#define RFAL_FEATURE_NFCF                           false /*!< Enable/Disable RFAL support for NFC-F (FeliCa)                            */
#define RFAL_FEATURE_NFCV                           true /*!< Enable/Disable RFAL support for NFC-V (ISO15693)                          */
#define RFAL_FEATURE_T1T                            false /*!< Enable/Disable RFAL support for T1T (Topaz)                               */
#define RFAL_FEATURE_T2T                            false /*!< Enable/Disable RFAL support for T2T                                       */
#define RFAL_FEATURE_T4T                            false /*!< Enable/Disable RFAL support for T4T                                       */
#define RFAL_FEATURE_ST25TB                         false /*!< Enable/Disable RFAL support for ST25TB                                    */
#define RFAL_FEATURE_ST25xV                         false  /*!< Enable/Disable RFAL support for  ST25TV/ST25DV                            */
#define RFAL_FEATURE_DYNAMIC_ANALOG_CONFIG          false  /*!< Enable/Disable Analog Configs to be dynamically updated (RAM)             */
#define RFAL_FEATURE_DPO                            false  /*!< Enable/Disable RFAL Dynamic Power Output support                          */
#define RFAL_FEATURE_ISO_DEP                        false /*!< Enable/Disable RFAL support for ISO-DEP (ISO14443-4)                      */
#define RFAL_FEATURE_ISO_DEP_POLL                   false /*!< Enable/Disable RFAL support for Poller mode (PCD) ISO-DEP (ISO14443-4)    */
#define RFAL_FEATURE_ISO_DEP_LISTEN                 false /*!< Enable/Disable RFAL support for Listen mode (PICC) ISO-DEP (ISO14443-4)   */
#define RFAL_FEATURE_NFC_DEP                        false /*!< Enable/Disable RFAL support for NFC-DEP (NFCIP1/P2P)                      */

/*
******************************************************************************
* RFAL FEATURES CONFIGURATION
******************************************************************************
*/

#define RFAL_FEATURE_ISO_DEP_IBLOCK_MAX_LEN 256U  /*!< ISO-DEP I-Block max length. Please use values as defined by rfalIsoDepFSx */
#define RFAL_FEATURE_NFC_RF_BUF_LEN         128U          /*!< RF buffer length used by RFAL NFC layer                                   */
#define RFAL_FEATURE_NFC_DEP_BLOCK_MAX_LEN  254U   /*!< NFC-DEP Block/Payload length. Allowed values: 64, 128, 192, 254           */
#define RFAL_FEATURE_ISO_DEP_APDU_MAX_LEN   512U    /*!< ISO-DEP APDU max length. Please use multiples of I-Block max length       */
#define RFAL_FEATURE_NFC_DEP_PDU_MAX_LEN    512U     /*!< NFC-DEP PDU max length.                                                   */

/*
******************************************************************************
* RFAL CUSTOM SETTINGS
******************************************************************************
  Custom analog configs are used to cope with Automatic Antenna Tuning (AAT)
  that are optimized differently for each board.
*/
#define RFAL_ANALOG_CONFIG_CUSTOM                         /*!< Use Custom Analog Configs when defined                                    */

#define TESTED_VAR_OK_BMP

#define LED_FIELD_Pin 1         /*!< Enable usage of led field pin on the platform      */
#define LED_FIELD_GPIO_Port 1   /*!< Enable usage of led field port on the platform     */
#define USE_LOGGER 1

#define NFC06A1_LED1_PIN_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define NFC06A1_LED2_PIN_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define NFC06A1_LED3_PIN_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define NFC06A1_LED4_PIN_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define NFC06A1_LED5_PIN_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define NFC06A1_LED6_PIN_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define NFC06A1_LED1_PIN                  GPIO_PIN_10
#define NFC06A1_LED1_PIN_PORT             GPIOB
#define NFC06A1_LED2_PIN                  GPIO_PIN_4
#define NFC06A1_LED2_PIN_PORT             GPIOB
#define NFC06A1_LED3_PIN                  GPIO_PIN_5
#define NFC06A1_LED3_PIN_PORT             GPIOB
#define NFC06A1_LED4_PIN                  GPIO_PIN_10
#define NFC06A1_LED4_PIN_PORT             GPIOA
#define NFC06A1_LED5_PIN                  GPIO_PIN_0
#define NFC06A1_LED5_PIN_PORT             GPIOA
#define NFC06A1_LED6_PIN                  GPIO_PIN_1
#define NFC06A1_LED6_PIN_PORT             GPIOA

#define NFC06A1_ALLLED_GPIO_CLK_ENABLE() {NFC06A1_LED1_PIN_CLK_ENABLE();NFC06A1_LED2_PIN_CLK_ENABLE();NFC06A1_LED3_PIN_CLK_ENABLE();NFC06A1_LED4_PIN_CLK_ENABLE();NFC06A1_LED5_PIN_CLK_ENABLE();NFC06A1_LED6_PIN_CLK_ENABLE();}
#define NFC06A1_NFCTAG_INSTANCE         (0)
#define NFC06A1_NFCTAG_GPO_PRIORITY     (0)

#ifdef LED_FIELD_Pin
/* Case of ST25R3916 */
#define PLATFORM_LED_FIELD_PIN       GPIO_PIN_1         /*!< GPIO pin used as field LED                        */
#endif

#ifdef LED_FIELD_GPIO_Port
/* Case of ST25R3916 */
#define PLATFORM_LED_FIELD_PORT       GPIOA    /*!< GPIO port used as field LED                       */
#endif

/* Case of ST25R3916 */
#define PLATFORM_LED_A_PIN           GPIO_PIN_5         /*!< GPIO pin used for LED A    */
#define PLATFORM_LED_A_PORT          GPIOB    /*!< GPIO port used for LED A   */
#define PLATFORM_LED_B_PIN           GPIO_PIN_4         /*!< GPIO pin used for LED B    */
#define PLATFORM_LED_B_PORT          GPIOB    /*!< GPIO port used for LED B   */
#define PLATFORM_LED_F_PIN           GPIO_PIN_10         /*!< GPIO pin used for LED F    */
#define PLATFORM_LED_F_PORT          GPIOB    /*!< GPIO port used for LED F   */
#define PLATFORM_LED_V_PIN           GPIO_PIN_10         /*!< GPIO pin used for LED V    */
#define PLATFORM_LED_V_PORT          GPIOA    /*!< GPIO port used for LED V   */
#define PLATFORM_LED_AP2P_PIN        GPIO_PIN_0         /*!< GPIO pin used for LED AP2P */
#define PLATFORM_LED_AP2P_PORT       GPIOA    /*!< GPIO port used for LED AP2P*/

#define BUS_SPI1_NSS_GPIO_PIN           GPIO_PIN_6
#define BUS_SPI1_NSS_GPIO_PORT          GPIOB
#define BUS_SPI1_IRQ_GPIO_PIN           GPIO_PIN_7
#define BUS_SPI1_IRQ_GPIO_PORT          GPIOC

/* Exported constants --------------------------------------------------------*/
/** @defgroup PTD_Platform_Exported_Constants
 *  @{
 */
#define ST25R_SS_PIN             BUS_SPI1_NSS_GPIO_PIN    /*!< GPIO pin used for ST25R SPI SS                */
#define ST25R_SS_PORT            BUS_SPI1_NSS_GPIO_PORT   /*!< GPIO port used for ST25R SPI SS port          */

#define BSP_NFC0XCOMM_Init             BSP_SPI1_Init
#define BSP_NFC0XCOMM_IRQ_Callback     BSP_SPI1_IRQ_Callback

#define BSP_NFC0XCOMM_SequencialSend  BSP_SPI1_SequencialSend
#define BSP_NFC0XCOMM_SequencialRecv  BSP_SPI1_SequencialRecv

void BSP_SPI1_IRQ_Callback(void);

/**
  * @}
  */

/**
  * @}
  */

/*
******************************************************************************
* GLOBAL VARIABLES
******************************************************************************
*/

/* Exported variables --------------------------------------------------------*/
extern SPI_HandleTypeDef hspi1;

extern uint8_t globalCommProtectCnt;
extern EXTI_HandleTypeDef NFC_EXTI;
/* Exported functions ------------------------------------------------------- */
int32_t BSP_NFC0XCOMM_SendRecv(const uint8_t * const pTxData, uint8_t * const pRxData, uint16_t Length);

int32_t BSP_NFC0XCOMM_Init(void);

#define  COMM_HANDLE                                     hspi1

void MX_NFC6_PollingTagDetect_Process(void);
void MX_NFC6_PollingDemo_Init(void);

void _Error_Handler(char * file, int line);

#ifdef __cplusplus
}
#endif

#endif /* __NFC0XA1_CONF_H__*/

