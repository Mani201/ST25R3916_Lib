/*
 * nfc_init.h
 *
 *  Created on: Nov 19, 2024
 *      Author: kwanghyeonkim
 */

#ifndef INC_NFC_INIT_H_
#define INC_NFC_INIT_H_

#include "main.h"
#include "rfal_platform.h"
#include "nfc_conf.h"
#include "rfal_analogConfig.h"

#include "rfal_cd.h"
#include "rfal_chip.h"
#include "rfal_crc.h"
#include "rfal_defConfig.h"
#include "rfal_dpo.h"

#include "rfal_features.h"
#include "rfal_iso15693_2.h"
#include "rfal_isoDep.h"
#include "rfal_nfc.h"
#include "rfal_nfca.h"
#include "rfal_nfcb.h"
#include "rfal_nfcDep.h"
#include "rfal_nfcf.h"
#include "rfal_nfcv.h"
#include "rfal_rf.h"

#include "rfal_st25xv.h"
#include "rfal_utils.h"
#include "st25r3916_aat.h"
#include "st25r3916_com.h"
#include "st25r3916_irq.h"
#include "st25r3916_led.h"
#include "st25r3916.h"
#include "timer.h"

#define QX_3900_TEST

typedef struct{
    SPI_HandleTypeDef    *spi;
    GPIO_TypeDef        *cs_port;
    GPIO_TypeDef        *nfc_irq_port;

    // EXTI_HandleTypeDef (큰 구조체)
    EXTI_HandleTypeDef   HandleType;

    // 32비트 값
    uint32_t             LINENum;

    // 16비트 값들
    uint16_t             cs_pin;
    uint16_t             nfc_irq_pin;

    // IRQn_Type (일반적으로 작은 정수)
    IRQn_Type            IRQn;
}NFC_Lib_Init;

extern IRQn_Type IRQ_ST25R_EXTI_IRQn;
extern EXTI_HandleTypeDef USR_INT_LINE;
extern uint32_t USR_INT_LINE_NUM;


void init_nfc_lib(const NFC_Lib_Init* init_val);
void nfc_Cycle();

#endif /* INC_NFC_INIT_H_ */

