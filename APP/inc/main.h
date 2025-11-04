/**
  * @file    afe_timea_trig_ccvadc_test/main.h 
  * @brief   Header for main.c module
  * @author  ChipSea MCU Group
  * @version V1.0.0
  * @date   2022.06.30         
  * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
  * @note 
  * <h2><center>&copy; COPYRIGHT 2021 ChipSea</center></h2>
  *
  */
  
  
#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>
#include "stdint.h"
#include "cbm858xm.h"
#include "log.h"
#include "cbm858xm_i2c.h"
#include "data_flash_value.h"
#include "protect.h"
#include "Power_Modes.h"
#include "AdvancedChargeAlgorithm.h"
#include "soft_timer.h"
#include"SBS_Commands.h"
#include "mode.h"
#include "ram.h"
#include "hdp.h"
#include "afe_cvt.h"
#include "definefile.h"
#include "lifetime.h"
#include "mcu.h"
#include "smbus_protocol.h"
#include "afetimer.h" 
#include "lptm.h"
#include "tim.h"
#include "dataflash.h"
#include "datcalc_spl.h"						// datcalc_spl.c
#include "Calc_Attf.h"
#include "rtc.h"
#include "oscm.h"

#include "UpFlash.h"

#include "cbm858xm_conf.h"
#include "cbm858xm_misc.h"
#include "cbm858xm_spi.h"
#include "cbm858xm_gpio.h"
#include "cbm858xm_usart.h"
#include "cbm858x_afe_transimit.h"
#include "cbm858x_afe_rcc.h"
#include "cbm858x_afe_gcr.h"
#include "cbm858x_afe_gpio.h"
#include "cbm858x_afe_int.h"
#include "cbm858x_afe_timera.h"
#include "cbm858x_afe_dtdrv.h"

#include "cbm858xm_exti.h"
#include "cbm858xm_conf.h"
#include "cbm858xm_syscfg.h"
#include "cbm858x_afe_vadc.h"
#include "cbm858x_afe_cc.h"
#include "cbm858x_afe_int.h"
#include "cbm858x_afe_iwdg.h"
#include "cbm858x_afe_pmu.h"
#include "cbm858xm_gpio.h"
#include "cbm858xm_rcu.h"
#include "cbm858xm_pmu.h"
#include "cbm858xm_rtc.h"
#include "cbm858x_afe_int.h"
#include "cbm858x_afe_wkcp.h"
#include "cbm858x_afe_hdp.h"
#include "cbm858x_afe_cddrv.h"
#include "cbm858x_afe_vadc.h"
#include "cbm858xm_lptim.h"
#include  "trng.h"
#include  "cbm858xm_flash.h"
#include "cbm858xm_fwdt.h"
#include "cbm8580m_int.h"
#define ON  1U
#define OFF 0U
#define I2C_LONG_TIMEOUT         ((uint32_t)(10 * I2C_FLAG_TIMEOUT))

#define NORMAL_WEEK               249

#define OWN_ADDRESS               0x16
#define I2C_TIMING                0x20110203 //24M clock-> I2C 1M
//  #define I2C_TIMING              0x30310309 //24M clock-> I2C 400K
// #define I2C_TIMING              0x70420F13 //24M clock-> I2C 100K

// #ifdef RELEASE_MODE
// #define printf printf//((void)0)
// #else
// #define printf printf
// #endif
#if 1
#define logInfo printf
#else
#define Loginfo(value) ((void)0)

#endif

extern volatile uint8_t write_flag;
extern volatile uint8_t register_addr;
extern volatile uint8_t g_i2cBuffRecv[36];
extern volatile uint8_t iic_rx_cnt;
extern volatile uint8_t iic_tx_cnt;
extern volatile uint16_t ccnt;
extern volatile uint8_t nPos;

typedef struct
{
	unsigned short bit0			:1;	
	unsigned short bit1			:1;
	unsigned short bit2			:1;
	unsigned short bit3			:1;
	unsigned short bit4			:1;
	unsigned short bit5			:1;
	unsigned short bit6			:1;
	unsigned short bit7			:1;
  	unsigned short bit8			:1;	
	unsigned short bit9 		:1;
	unsigned short bit10		:1;
	unsigned short bit11		:1;
	unsigned short bit12		:1;
	unsigned short bit13		:1;
	unsigned short bit14		:1;
	unsigned short bit15		:1;
}_STC_BIT;
#define DEF_BIT15(pdata)	((volatile _STC_BIT*)(pdata))->bit15
#define DEF_BIT14(pdata)	((volatile _STC_BIT*)(pdata))->bit14
#define DEF_BIT13(pdata)	((volatile _STC_BIT*)(pdata))->bit13
#define DEF_BIT12(pdata)	((volatile _STC_BIT*)(pdata))->bit12
#define DEF_BIT11(pdata)	((volatile _STC_BIT*)(pdata))->bit11
#define DEF_BIT10(pdata)	((volatile _STC_BIT*)(pdata))->bit10
#define DEF_BIT9(pdata)	    ((volatile _STC_BIT*)(pdata))->bit9
#define DEF_BIT8(pdata)	    ((volatile _STC_BIT*)(pdata))->bit8
#define DEF_BIT7(pdata)	    ((volatile _STC_BIT*)(pdata))->bit7
#define DEF_BIT6(pdata)	    ((volatile _STC_BIT*)(pdata))->bit6
#define DEF_BIT5(pdata)	    ((volatile _STC_BIT*)(pdata))->bit5
#define DEF_BIT4(pdata)	    ((volatile _STC_BIT*)(pdata))->bit4
#define DEF_BIT3(pdata)	    ((volatile _STC_BIT*)(pdata))->bit3
#define DEF_BIT2(pdata)	    ((volatile _STC_BIT*)(pdata))->bit2
#define DEF_BIT1(pdata)	    ((volatile _STC_BIT*)(pdata))->bit1
#define DEF_BIT0(pdata)	    ((volatile _STC_BIT*)(pdata))->bit0

#define ABS(a)	((a)>0 ?(a) : -(a))				// Macro of calc absolute value

extern uint16_t Periodtime;
extern volatile uint8_t is_pack_falling;
extern void EXTI_Proc();

#endif 
