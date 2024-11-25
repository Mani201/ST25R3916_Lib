/*
 * nfc_init.c
 *
 *  Created on: Nov 19, 2024
 *      Author: kwanghyeonkim
 */
#include "nfc_init.h"
#include "demo.h"


extern nfc_platform platform_spi_init;

EXTI_HandleTypeDef NFC_EXTI;
uint8_t globalCommProtectCnt;


void init_nfc_lib(const NFC_Lib_Init* init_val){
	globalCommProtectCnt = 0;

	myprintf(5, "=== Init Values at Function Entry ===\n");
	myprintf(5, "IRQn: %d\n", init_val->IRQn);
	myprintf(5, "LINENum: 0x%lX\n", init_val->LINENum);
	myprintf(5, "CS Port: %p\n", (void*)init_val->cs_port);
	myprintf(5, "CS Pin: 0x%X\n", init_val->cs_pin);
	myprintf(5, "IRQ Port: %p\n", (void*)init_val->nfc_irq_port);
	myprintf(5, "IRQ Pin: 0x%X\n", init_val->nfc_irq_pin);


	platform_spi_init.nfc_spi = init_val->spi;
	platform_spi_init.nfc_cs_port = init_val->cs_port;
	platform_spi_init.nfc_cs_pin = init_val->cs_pin;
	platform_spi_init.nfc_irq_port = init_val->nfc_irq_port;
	platform_spi_init.nfc_irq_pin = init_val->nfc_irq_pin;

	IRQ_ST25R_EXTI_IRQn = init_val->IRQn;
	USR_INT_LINE = init_val->HandleType;
	USR_INT_LINE_NUM = init_val->LINENum;

	USR_INT_LINE.Line = USR_INT_LINE_NUM;
	USR_INT_LINE.PendingCallback = st25r3916Isr;

	NFC_EXTI = USR_INT_LINE;
	/* Configure interrupt callback */
	(void)HAL_EXTI_GetHandle(&NFC_EXTI, NFC_EXTI.Line);
	//(void)HAL_EXTI_RegisterCallback(&USR_INT_LINE, HAL_EXTI_COMMON_CB_ID, BSP_NFC0XCOMM_IRQ_Callback);
	demoIni();
	myprintf(5,"NFC_INIT_SUCCESS!!!\r\n");
}
void nfc_Cycle(){
	demoCycle();
}
