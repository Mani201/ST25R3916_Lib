# ST25R3916/B NFC Library

<div align="center">
  <h3>Easy-to-use NFC reader library for STM32 microcontrollers</h3>
</div>

## 📝 Overview
This library is a wrapper that enables easy use of the ST25R3916 NFC reader chip with STM32 microcontrollers. It has been user-friendly reconstructed based on ST's RFAL (RF Abstraction Layer) library.

## ✨ Features

### Supported NFC Protocols
- ISO/IEC 14443A (NFC-A)
- ISO/IEC 14443B (NFC-B)
- ISO/IEC 15693 (NFC-V)
- FeliCa (NFC-F)
- ISO-DEP (ISO 14443-4)
- NFC-DEP (P2P)
- ST25xV dedicated features

### Key Functions
- Automatic Antenna Tuning (AAT)
- CRC calculation
- Analog configuration management
- Timer management
- Interrupt-based event handling

## 🔧 Requirements

### Hardware
- STM32 microcontroller
- ST25R3916 NFC reader module
- SPI interface
- IRQ and CS pin connections

### Dependencies
- STM32 HAL drivers
- ST25R3916 RFAL library
- rfal_platform.h
- rfal_nfc.h
- rfal_rf.h
- Other RFAL related headers

## 📦 Installation & Setup

### Initialization Structure

typedef struct {
    /* SPI Configuration */
    SPI_HandleTypeDef    *spi;               // SPI communication handler
    
    /* GPIO Configuration */
    GPIO_TypeDef        *cs_port;            // Chip Select GPIO port
    GPIO_TypeDef        *nfc_irq_port;       // Interrupt GPIO port
    uint16_t            cs_pin;              // Chip Select pin number
    uint16_t            nfc_irq_pin;         // Interrupt pin number
    
    /* Interrupt Configuration */
    EXTI_HandleTypeDef   HandleType;         // External interrupt handler
    uint32_t            LINENum;             // External interrupt line number
    IRQn_Type           IRQn;                // Interrupt number
} NFC_Lib_Init;

## 🚀 Usage

### 1. Include required header file

/* Include NFC initialization header */
#include "nfc_init.h"

### 2. Initialize structure setup

/* Initialize NFC configuration structure */
NFC_Lib_Init main_nfc_init = {
    /* SPI Configuration */
    .spi            = &hspi3,
    
    /* GPIO Configuration */
    .cs_port        = RFID_SDA_GPIO_Port,
    .cs_pin         = RFID_SDA_Pin,
    .nfc_irq_port   = RFID_IRQ_GPIO_Port,
    .nfc_irq_pin    = RFID_IRQ_Pin,
    
    /* Interrupt Configuration */
    .IRQn           = EXTI1_IRQn,
    .LINENum        = EXTI_LINE_1
};
### 3. Library initialization and execution

/* Initialize NFC library */
init_nfc_lib(&main_nfc_init);

/* Main processing loop */
while(1) {
    nfc_Cycle();    // Process NFC operations
}

### 4. ST25R3916/3916B switching method

/* NFC_lib/RTE_Components.h */

/* Feature Configuration */
#define USE_NFC06A1
#define LIB_RFAL_CUSTOM
#define USE_SPI
#define NFC06A1_POLLING_TAG_DETECT
#define USE_RFAL_FEATURE_LISTEN_MODE
#define USE_RFAL_FEATURE_NFCV

/* Chip Selection */
#ifndef ST25R3916      // ST25R3916 Configuration
    #define ST25R3916
#endif

#ifndef ST25R3916B     // ST25R3916B Configuration
    #define ST25R3916B
#endif

## 📚 API Reference

### Main Functions
- `init_nfc_lib()`: NFC library initialization
- `nfc_Cycle()`: NFC Demo program
- All RFAL library functions available

## ⚠️ Important Notes

### Hardware Setup
- SPI configuration must be completed
- External interrupt setup must be correct

### Software Setup
- All RFAL related settings must be properly configured in nfc_conf.h
- Check interrupt priority settings

## 📫 Contact

- Developer: Acsis
- Email: Yang249221@gmail.com

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
