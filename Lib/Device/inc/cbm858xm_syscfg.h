/**
* @file        cbm858xm_syscfg.h
* @brief       This file contains all the functions prototypes for the SYSCFG firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.07
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.07    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_SYSCFG_H__
#define __CBM858xM_SYSCFG_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup SYSCFG
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup SYSCFG_Exported_Types SYSCFG Exported Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup SYSCFG_Exported_Constants SYSCFG Exported Constants
  * @{
  */

/**  
  * @brief SYSCFG VTH pin Sources definition
  */
#define SYSCFG_I2C_FMP_PIN_10           		((uint8_t)0x0A) 	/*!< GPIO PIN10 for fast mode config. */
#define SYSCFG_I2C_FMP_PIN_11           		((uint8_t)0x0B) 	/*!< GPIO PIN11 for fast mode config. */

/*! Checks SYSCFG fast mode pin definition. */
#define SYSCFG_FMP_PIN_CHECK(pin) 			(((pin) == SYSCFG_I2C_FMP_PIN_10) || ((pin) == SYSCFG_I2C_FMP_PIN_11))

#define SYSCFG_I2C_FMP_CAPABLITY_3MA           	((uint8_t)0x00) 	/*!< GPIO FMP capbility 3mA. */
#define SYSCFG_I2C_FMP_CAPABLITY_6MA           	((uint8_t)0x01) 	/*!< GPIO FMP capbility 6mA. */
#define SYSCFG_I2C_FMP_CAPABLITY_9MA           	((uint8_t)0x02) 	/*!< GPIO FMP capbility 9mA. */
#define SYSCFG_I2C_FMP_CAPABLITY_20MA           ((uint8_t)0x03) 	/*!< GPIO FMP capbility 20mA. */

/*! Checks SYSCFG fast mode capbility definition. */
#define SYSCFG_FMP_CAPABLITY_CHECK(cap) 	(((cap) == SYSCFG_I2C_FMP_CAPABLITY_3MA) || ((cap) == SYSCFG_I2C_FMP_CAPABLITY_6MA) ||\
											 ((cap) == SYSCFG_I2C_FMP_CAPABLITY_9MA) || ((cap) == SYSCFG_I2C_FMP_CAPABLITY_20MA))

/** 
  * @brief SYSCFG EXTI Port Sources definition
  */ 
#define SYSCFG_EXTI_PORT_PA					((uint8_t)0x00)		/*!< External interrupt port source from GPIO A. */

/*! Checks SYSCFG EXTI Port Sources definition. */
#define SYSCFG_EXTI_PORT_CHECK(port) 		((port) == SYSCFG_EXTI_PORT_PA)

/**  
  * @brief SYSCFG EXTI pin Sources definition
  */ 
#define SYSCFG_EXTI_PIN_0					((uint8_t)0x00) 	/*!< External interrupt from pin 0. */
#define SYSCFG_EXTI_PIN_1            		((uint8_t)0x01) 	/*!< External interrupt from pin 1. */
#define SYSCFG_EXTI_PIN_2            		((uint8_t)0x02) 	/*!< External interrupt from pin 2. */
#define SYSCFG_EXTI_PIN_3            		((uint8_t)0x03) 	/*!< External interrupt from pin 3. */
#define SYSCFG_EXTI_PIN_4            		((uint8_t)0x04) 	/*!< External interrupt from pin 4. */
#define SYSCFG_EXTI_PIN_5            		((uint8_t)0x05) 	/*!< External interrupt from pin 5. */
#define SYSCFG_EXTI_PIN_6            		((uint8_t)0x06) 	/*!< External interrupt from pin 6. */
#define SYSCFG_EXTI_PIN_7            		((uint8_t)0x07) 	/*!< External interrupt from pin 7. */
#define SYSCFG_EXTI_PIN_8            		((uint8_t)0x08) 	/*!< External interrupt from pin 8. */
#define SYSCFG_EXTI_PIN_9            		((uint8_t)0x09) 	/*!< External interrupt from pin 9. */
#define SYSCFG_EXTI_PIN_10           		((uint8_t)0x0A) 	/*!< External interrupt from pin 10. */
#define SYSCFG_EXTI_PIN_11           		((uint8_t)0x0B) 	/*!< External interrupt from pin 11. */
#define SYSCFG_EXTI_PIN_12           		((uint8_t)0x0C) 	/*!< External interrupt from pin 12. */
#define SYSCFG_EXTI_PIN_13           		((uint8_t)0x0D) 	/*!< External interrupt from pin 13. */
#define SYSCFG_EXTI_PIN_14           		((uint8_t)0x0E) 	/*!< External interrupt from pin 14. */
#define SYSCFG_EXTI_PIN_15           		((uint8_t)0x0F) 	/*!< External interrupt from pin 15. */

/*! Checks SYSCFG EXTI pin Sources definition. */
#define SYSCFG_EXTI_PIN_CHECK(pin)			(((pin) == SYSCFG_EXTI_PIN_0) || ((pin) == SYSCFG_EXTI_PIN_1)  || \
                                       		((pin) == SYSCFG_EXTI_PIN_2)  ||  ((pin) == SYSCFG_EXTI_PIN_3)  || \
                                       		((pin) == SYSCFG_EXTI_PIN_4)  ||  ((pin) == SYSCFG_EXTI_PIN_5)  || \
                                       		((pin) == SYSCFG_EXTI_PIN_6)  ||  ((pin) == SYSCFG_EXTI_PIN_7)  || \
                                       		((pin) == SYSCFG_EXTI_PIN_8)  ||  ((pin) == SYSCFG_EXTI_PIN_9)  || \
                                       		((pin) == SYSCFG_EXTI_PIN_10) ||  ((pin) == SYSCFG_EXTI_PIN_11) || \
                                       		((pin) == SYSCFG_EXTI_PIN_12) ||  ((pin) == SYSCFG_EXTI_PIN_13) || \
                                       		((pin) == SYSCFG_EXTI_PIN_14) ||  ((pin) == SYSCFG_EXTI_PIN_15))

/** 
  * @brief SYSCFG VTH Port Sources definition
  */
#define SYSCFG_VTH_PORT_PA					((uint8_t)0x00) 	/*!< GPIO PORTA for VTH config. */

/*! Checks SYSCFG VTH Port Sources definition. */
#define SYSCFG_VTH_PORT_CHECK(port) 		((port) == SYSCFG_VTH_PORT_PA)

/**  
  * @brief SYSCFG VTH pin Sources definition
  */
#define SYSCFG_VTH_PIN_10           		((uint8_t)0x0A) 	/*!< GPIO PIN10 for VTH config. */
#define SYSCFG_VTH_PIN_11           		((uint8_t)0x0B) 	/*!< GPIO PIN11 for VTH config. */

/*! Checks SYSCFG VTH pin Sources definition. */
#define SYSCFG_VTH_PIN_CHECK(pin) 			(((pin) == SYSCFG_VTH_PIN_10) || ((pin) == SYSCFG_VTH_PIN_11))
/**  
  * @brief SYSCFG VTH pin Sources definition
  */
#define SYSCFG_GPIO_VTH_VDD					((uint32_t)0x00)	/*!< Threshold voltage is VDD . */
#define SYSCFG_GPIO_VTH_1V8					((uint32_t)0x01)	/*!< Threshold voltage is 1.8V. */
#define SYSCFG_GPIO_VTH_1V2					((uint32_t)0x02)	/*!< Threshold voltage is 1.2V. */

/*! Checks SYSCFG VTH pin Sources definition. */
#define SYSCFG_GPIO_VTH_CHECK(volt) 		(((volt) == SYSCFG_GPIO_VTH_1V8) || ((volt) == SYSCFG_GPIO_VTH_1V2) ||\
											((volt) == SYSCFG_GPIO_VTH_VDD))

/** 
  * @brief SYSCFG Memory Remap definition
  */
#define SYSCFG_MEM_REMAP_FLASH				((uint8_t)0x03)		/*!< Remap system flash memory. */
#define SYSCFG_MEM_REMAP_SYS_MEMORY			((uint8_t)0x00)		/*!< Remap main flash memory. */
#define SYSCFG_MEM_REMAP_SRAM				((uint8_t)0x01)		/*!< Remap embedded SRAM. */

/*! Checks SYSCFG Memory Remap definition. */
#define SYSCFG_MEM_REMAP_CHECK(flag) 		(((flag) == SYSCFG_MEM_REMAP_FLASH) || ((flag) == SYSCFG_MEM_REMAP_SYS_MEMORY) || \
                                      		((flag) == SYSCFG_MEM_REMAP_SRAM))
/** 
  * @brief SYSCFG Trng definition
  */
#define SYSCFG_TRNG_KEY_VALUE      	        0xBC430000 		    /*!< Trng key. */
#define SYSCFG_TRNG_SYSCLK            	    0x00000004			/*!< System clock. */
#define SYSCFG_TRNG_ROCLK            	    0x00000000			/*!< Ro clock. */

/*! Checks SYSCFG Trng definition. */
#define SYSCFG_TRNG_CLOCK_CHECK(clock) 		(((clock) == SYSCFG_TRNG_SYSCLK) || ((clock) == SYSCFG_TRNG_ROCLK)
/** 
  * @brief SYSCFG AFE definition
  */
#define SYSCFG_AFE_KEY_VALUE      	        0x13FD0000 		    /*!< AFE key. */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup SYSCFG_Exported_Functions SYSCFG Exported Functions
  * @{
  */

/**
  * @brief  Deinitializes the SYSCFG registers to their default reset values.
  * @param  None.
  * @note   MEM_REMAP and ERRLOCK are not affected by APB reset.
  * @return None.
  */
#define __SYSCFG_DEF_INIT()					syscfg_def_init()	

/**
  * @brief  Connect the selected parameter to the TIM1 break.
  * @param  VALUE: Selects the configuration to be connected to TIM1 break. It can be 
  *          @arg SYSCFG_ERRLOCK_LVD_TIMBRK_LOCK (Connects the LVD event to TIM1 break enable)
  *          @arg SYSCFG_ERRLOCK_SRAM_PRTY_TIMBRK_LOCK(Connects the SRAM_PARITY error signal to TIM1 break enable)
  *          @arg SYSCFG_ERRLOCK_LOCKUP_TIMBRK_LOCK(Connects Lockup output of CortexM0 to TIM1 break enable)
  * @note   The selected configuration is locked and can be unlocked by system reset
  * @return None.
  */
#define __SYSCFG_TIME_BREAK_SET(VALUE)		(SYSCFG->ERRLOCK |= VALUE)

/**
  * @brief  Enables the specified function of SYSCFG.
  * @param  FUNC: Specifies the function to enable. 
  *			It can be any combination of the following values:
  *          @arg SYSCFG_RMAPCFG_USART1RX_DMA_CHRMAP: Remap USART1 Rx DMA from channel 3 to channel 5.
  *          @arg SYSCFG_RMAPCFG_USART1TX_DMA_CHRMAP: Remap USART1 Tx DMA from channel 2 to channel 4.
  * @return None.
  */
#define __SYSCFG_FUNC_ENABLE(FUNC)			(SYSCFG->RMAPCFG |= FUNC)

/**
  * @brief  Disables the specified function of SYSCFG.
  * @param  FUNC: Specifies the function to disable. 
  *			It can be any combination of the following values: 
  *			It can be any combination of the following values:
  *          @arg SYSCFG_RMAPCFG_USART1RX_DMA_CHRMAP: Remap USART1 Rx DMA from channel 3 to channel 5
  *          @arg SYSCFG_RMAPCFG_USART1TX_DMA_CHRMAP: Remap USART1 Tx DMA from channel 2 to channel 4
  * @return None.
  */
#define __SYSCFG_FUNC_DISABLE(FUNC)			(SYSCFG->RMAPCFG &= ~(FUNC))

/**
  * @brief   Checks whether the specified SYSCFG flag is set or not.
  * @param   FLAG: Specifies the SYSCFG flag to check. It can be
  *          @arg SYSCFG_ERRLOCK_SRAM_PRTY_ERR(SRAM parity error flag)
  * @return  state SET or RESET.
  */
#define __SYSCFG_FLAG_STATUS_GET(FLAG)		((SYSCFG->ERRLOCK & (FLAG)) ? SET : RESET)

/**
  * @brief  Clears the selected SYSCFG flag.
  * @param  FLAG: Selects the flag to be cleared, it can be 
  *          @arg SYSCFG_ERRLOCK_SRAM_PRTY_ERR(SRAM parity error flag)
  * @return None.
  */
#define __SYSCFG_FLAG_CLEAR(FLAG)			(SYSCFG->ERRLOCK |= FLAG)

/**
  * @brief  Set trng reg key.
  * @param  VALUE: Trng reg key, it can be 
  *          @arg SYSCFG_TRNG_KEY_VALUE
  * @return None.
  */
#define __SYSCFG_TRNG_KEY_WRITE(VALUE)		do{ \
												(SYSCFG->TRNG &= ~SYSCFG_TRNG_KEY);\
											    (SYSCFG->TRNG |= (VALUE));\
											  } while(0U)
/**
  * @brief  Deinitializes the SYSCFG registers to their default reset values.
  * @param  None.
  * @note   MEM_REMAP and ERRLOCK are not affected by APB reset.
  * @return None.
  */
void syscfg_def_init(void);

/**
  * @brief  Set the memory mapping at address 0x00000000.
  * @param  value: Selects the memory remapping, it can be:
  *          @arg SYSCFG_MEM_REMAP_FLASH(Main Flash memory mapped at 0x00000000)
  *          @arg SYSCFG_MEM_REMAP_SYS_MEMORY(System Flash memory mapped at 0x00000000)
  *          @arg SYSCFG_MEM_REMAP_SRAM(Embedded SRAM mapped at 0x00000000)
  * @return None.
  */
void syscfg_memory_remap_set(uint32_t value);

/**
  * @brief	forbid ram boot.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_forbid_ram_boot_enable(enable_state_t status);

/**
  * @brief  Congig the fast driver capability on specific pin.
  * @param  pin: Specifies the fast mode driver pin.
  *			It can be one of the following values: 
  *          @arg SYSCFG_I2C_FMP_PIN_10: Configure fast mode for PA10.
  *          @arg SYSCFG_I2C_FMP_PIN_11: Configure fast mode for PA11.

  * @param  pin: Specifies the fast mode capbility.
  *			It can be one of the following values: 
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_3MA: Configure standard mode 3mA driving capability.
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_6MA: Configure fast mode 6mA driving capability.
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_9MA: Configure fast mode 9mA driving capability.
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_20MA: Configure fast mode 20mA driving capability.
  * @return None.
  */
void syscfg_fast_mode_config(uint8_t pin, uint32_t capbility);

/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  port: Selects the GPIO port to be used as source for EXTI lines. It can be one of following values:
  *                 @arg SYSCFG_EXTI_PORT_PA
  * @param  pin: specifies the EXTI line to be configured. 
  *              It can be a value between SYSCFG_EXTI_PIN_0 ~ SYSCFG_EXTI_PIN_15
  * @return None.
  */
void syscfg_exti_line_config(uint8_t port, uint8_t pin);

/**
  * @brief	Configures the GPIO threshold voltage.
  * @param	port: Specifies the GPIO port to configure. 				   
  * @param	pin: Specifies the GPIO pin to configure.
  * @param	volt: Specifies the threshold voltage to configure. 
  * 		It can be one of the following values:
  *          @arg SYSCFG_GPIO_VTH_VDD (Set threshold voltage is VDD).
  *          @arg SYSCFG_GPIO_VTH_1V8 (Set threshold voltage is 1.8V).
  *          @arg SYSCFG_GPIO_VTH_1V2 (Set threshold voltage is 1.2V).
  * @return None.
  */
void syscfg_gpio_vth_config(uint8_t port, uint8_t pin, uint32_t volt);

/**
  * @brief  Configures the trng clock.
  * @param  clock: Specifies the clock select. 
  *			It can be one of the following values:
  *          @arg SYSCFG_TRNG_SYSCLK
  *          @arg SYSCFG_TRNG_ROCLK
  * @return None.
  */
void syscfg_trng_clock_select(uint32_t clock);

/**
  * @brief	Trng bypass enable.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_trng_bypass_enable(enable_state_t status);

/**
  * @brief	AFE charge mos enable.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_afe_con_enable(enable_state_t status);

/**
  * @brief	AFE discharge mos enable.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_afe_don_enable(enable_state_t status);

/**
  * @brief	AFE reset.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_afe_rst_enable(enable_state_t status);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_syscfg.h */


/**
  * @}
  */

/**
  * @}
  */
 

