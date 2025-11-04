/**
  * @file    log.c  
  * @brief   This file provides log functions to evaluation board from ChipSea.
  * @author  ChipSea MCU Group
  * @version V1.0.0
  * @date   2022.06.29         
  * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
  * @note
  * <h2><center>&copy; COPYRIGHT 2021 ChipSea</center></h2>
  *
  */

#include "log.h"
#include "cbm858xm_rcu.h"
#include "cbm858xm_gpio.h"
#include "cbm858xm_exti.h"
#include "cbm858xm_usart.h"



/**
 * @brief  Initializes USART1, use for log print. 		
 * @param  None
 * @return None
 */
void log_init(void)
{
	usart_config_t usart_config_struct = {0};
    __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);
//    __RCU_APB2_CLK_ENABLE(RCU_APB2_PERI_USART1);
    __RCU_APB1_CLK_ENABLE(RCU_APB1_PERI_USART2);

	// GPIO MF Config
    gpio_mf_config(GPIOA, COM_TX_PIN, GPIO_MF_SEL1); //PA6
    gpio_mf_config(GPIOA, COM_RX_PIN, GPIO_MF_SEL1); //PA7
	  gpio_mode_set(GPIOA, COM_TX_PIN|COM_RX_PIN, GPIO_MODE_MF_PP_PU(GPIO_SPEED_MEDIUM));

    // USART Config	
    __USART_DEF_INIT(USART2);
    usart_config_struct.baud_rate = 115200;
    usart_config_struct.data_width = USART_DATA_WIDTH_8;
    usart_config_struct.stop_bits = USART_STOP_BIT_1;
    usart_config_struct.parity = USART_PARITY_NO;
    usart_config_struct.flow_control = USART_FLOW_CONTROL_NONE;
    usart_config_struct.usart_mode = USART_MODE_RX | USART_MODE_TX;
    usart_init(USART2, &usart_config_struct);

    __USART_ENABLE(USART2);	

}

/**
 * @brief  Initializes PA8, use for output debug. 		
 * @param  None
 * @return None
 */
void gpio_pa8_out_init(void)
{
    __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);
    
    gpio_mode_set(GPIOA, GPIO_PIN_8, GPIO_MODE_OUT_PP(GPIO_SPEED_HIGH));
    __GPIO_PIN_RESET(GPIOA, GPIO_PIN_8);
    
}

/**
  * @brief  Set PA8, use for output 1. 
  * @param  None 
  * @return None
  */
void gpio_pa8_set(void)
{
	__GPIO_PIN_SET(GPIOA, GPIO_PIN_8);
}

/**
  * @brief  @brief  Set PA8, use for output 0. 
  * @param  None
  * @return None
  */
void gpio_pa8_reset(void)
{
	__GPIO_PIN_RESET(GPIOA, GPIO_PIN_8);
}

/**
  * @brief  Toggles the PA8,for debug.
  * @param  None
  * @return None
  */
void gpio_pa8_toggle(void)
{	
	GPIOA->DO ^= GPIO_PIN_8;
}

/**
 * @brief  Initializes PA6, use for input debug. 		
 * @param  None
 * @return None
 */
void gpio_pa6_in_init(void)
{
    __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);
    gpio_mode_set(GPIOA, GPIO_PIN_6, GPIO_MODE_IN_FLOAT);
}

/**
  * @brief  Waiting pa6 set, then reset, simulate key.
  * @param  None
  * @return None
  */
void wait_pa6_press(void)
{
    /* waiting for low level. */
	while(__GPIO_INPUT_PIN_GET(GPIOA, GPIO_PIN_6)!= RESET);
    /* waiting for low level.. */
	while(__GPIO_INPUT_PIN_GET(GPIOA, GPIO_PIN_6)!= SET);
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
int fputc(int ch, FILE *f)
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
    __USART_DATA_SEND(USART2, (uint8_t) ch);
    while(__USART_FLAG_STATUS_GET(USART2, TXE) == RESET);
    return ch;
}

