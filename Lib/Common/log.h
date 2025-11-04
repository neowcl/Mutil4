/**
  * @file    log.h  
  * @brief   This file provides log functions to evaluation board from ChipSea.
  * @author  ChipSea MCU Group
  * @version V1.0.0
  * @date   2022.06.29         
  * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
  * @note
  * <h2><center>&copy; COPYRIGHT 2021 ChipSea</center></h2>
  *
  */
#include <stdio.h>
#include <string.h>
#include "cbm858xm.h"

#define COM_TX_PIN				GPIO_PIN_6
#define COM_RX_PIN				GPIO_PIN_7
/**
 * @brief  Initializes USART1, use for log print. 		
 * @param  None
 * @return None
 */
void log_init(void);
void gpio_pa8_out_init(void);
void gpio_pa8_set(void);
void gpio_pa8_reset(void);
void gpio_pa8_toggle(void);
void gpio_pa6_in_init(void);
void wait_pa6_press(void);

