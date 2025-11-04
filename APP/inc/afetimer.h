#ifndef __AFE_TIMEA_H__
#define __AFE_TIMEA_H__

#include "cbm858xm_flash.h"

#ifdef __cplusplus
 extern "C" {
#endif
#include <stdio.h>
#include <stdint.h>
#include "main.h"

void delay_ms(volatile uint32_t value);
void delay_us(uint32_t us);
void exti4_15_PA13_config(void);
void exti4_15_PA11_config(void);
void EXTI4_15_IRQHandler(void);


flash_status_t flash_page_read(uint32_t addr, uint16_t sz, uint8_t *buf);
flash_status_t flash_page_write(uint32_t addr, uint16_t sz, uint8_t *buf);
int8_t fmc_write_flash(uint32_t addr, const uint8_t *data, uint16_t len);
extern uint8_t  Ex_Flag;
#define f_CC_int        DEF_BIT0(&Ex_Flag)
#define f_VADC_int      DEF_BIT1(&Ex_Flag)
#define f_wakeup_int    DEF_BIT2(&Ex_Flag)
#define f_curr_en       DEF_BIT3(&Ex_Flag)
#define f_pres_en       DEF_BIT4(&Ex_Flag)
#define FMC_DATA_FLASH_BASE_ADDR  0x0801A000

#endif