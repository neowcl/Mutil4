/**
  * @file    cbm858xm_int.h
  * @brief   This file contains the headers of the interrupt handlers.
  * @author  ChipSea MCU Group
  * @version V1.0.0
  * @date   2021.11.01         
  * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
  * @note 
  * <h2><center>&copy; COPYRIGHT 2021 ChipSea</center></h2>
  *
  */
  
  
#ifndef __cbm858xm_INT_H__
#define __cbm858xm_INT_H__


#ifdef __cplusplus
 extern "C" {
#endif 

#include "main.h"

extern volatile uint8_t hwd_recovery;
/**
  * @fn void NMI_Handler(void)
  * @brief  This function handles NMI exception.
  * @param  None
  * @return None
  */
void NMI_Handler(void);

/**
  * @fn void HardFault_Handler(void)
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @return None
  */
void HardFault_Handler(void) __attribute__((noreturn));

/**
  * @fn void SVC_Handler(void)
  * @brief  This function handles SVCall exception.
  * @param  None
  * @return None
  */
void SVC_Handler(void);

/**
  * @fn void PendSV_Handler(void)
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @return None
  */
void PendSV_Handler(void);

/**
  * @fn void SysTick_Handler(void)
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @return None
  */
void SysTick_Handler(void);


#ifdef LRC_TIM_MEASURE

 /**
   * @fn void TIM14_IRQHandler(void)
   * @brief  This function handles TIM14  interrupt request.
   * @param  None
   * @return None
   */
void TIM14_IRQHandler(void);
#endif 

/**
  * @fn void EXTI4_15_IRQHandler(void)
  * @brief  This function handles External line 4 to 15 interrupt request.
  * @param  None
  * @return None
  */
void EXTI4_15_IRQHandler(void);

extern volatile uint8_t get_iic_arblo;
extern volatile uint8_t get_iic_buserr;




#ifdef __cplusplus
}
#endif

#endif 

