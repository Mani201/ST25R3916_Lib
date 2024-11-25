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
